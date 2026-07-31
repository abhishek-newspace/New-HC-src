/**
 * @file standard_procedures.cpp
 * @version 0.3
 * @author Abhishek
 * @date 15/07/2026
 * @brief definitions of set of functions to represent phases within the main control loop of the microcontroller in the hand controller.
 *
 * <h2>changes</h2>
 * @date 06/05/2026
 * - added included arm/disarm commands, based on reviewed OFP cycle
 * - added heartbeat being sent from hand controller
 * - created an object for timesync timing
 *
 * @date 14/07/2026
 * - SRS production polish (no HW remapping):
 *   periodic e-stop retransmit (§3.3.1), periodic light retransmit (§3.2.9),
 *   3 s state-request timeout / fail visibility (§3.2.5–3.2.7) via heartbeat feedback.
 *
 * @date 15/07/2026
 * - pending-request timeout helpers; arm wait uses Atlas HEARTBEAT arm field
 * - lights: one LIGHT_CONTROL per toggle edge (pins 6/8); no periodic retransmit
 * - e-stop: pins 4/5 toggle (engage / disengage / centre N/A); TX gated by HEARTBEAT
 * - speed limit: pin 3 momentary — one TX per click (Low→Mid→High); no hold/retransmit
 *
 * @date 29/07/2026
 * @author Abhishek
 * - swapped e-stop ↔ speed-limit physical controls (toggle vs momentary)
 *
 * @date 30/07/2026
 * @author Abhishek
 * - speed limit momentary: one-shot send per click (removed toggle-style 3 s retransmit)
 */

#include "include/standard_procedures.hpp"


periodicActions periodic_actions;

timer timesync_timer;

timer update_screen_timer;

bool currentlySendingArm = false;
bool arm_disarm_error = false;
bool turnOnHeadlight = false;
bool turnOnFoglight = false;
bool turnOffLight = false;
int required_speed = 0;
bool speed_limit_press = false;  /* one-shot: momentary pin 3 — send once per click */
bool switchMode = false;
bool arm_press = false;
//bool disarm_press = false;
bool estop_toggled = false;
bool estop_clear_request = false;

int hb_count = 0;
long unsigned int OFP_timer = 0;
uint32_t startup_time = 0;

uint32_t init_time;

/* -------------------------------------------------------------------------- */
/* Pending operator requests (fail visibility without COMMAND_ACK dialect)     */
/* Atlas confirms via HEARTBEAT custom_mode; if not within STATE_REQUEST_TIMEOUT */
/* we surface ARM_DISARM_FAIL / info for the operator.                         */
/* -------------------------------------------------------------------------- */
enum pending_request_t {
    PENDING_NONE = 0,
    PENDING_ARM,
    PENDING_DISARM,
    PENDING_SPEED,
    PENDING_DRIVE_MODE
};

static pending_request_t pending_request = PENDING_NONE;
static unsigned long pending_since_ms = 0;
static int pending_expected_speed = 0;      ///< 1..3 when PENDING_SPEED
static int pending_expected_drive_mode = 0; ///< 0..2 (enum driveMode) when PENDING_DRIVE_MODE

static void clearPendingRequest(){
    pending_request = PENDING_NONE;
    pending_since_ms = 0;
}

static void startPendingRequest(pending_request_t kind){
    pending_request = kind;
    pending_since_ms = millis();
}

/**
 * Clear pending state when HEARTBEAT confirms the requested transition,
 * or raise a failure after STATE_REQUEST_TIMEOUT_MS.
 */
static void evaluatePendingRequests(){
    if(pending_request == PENDING_NONE)
        return;

    bool satisfied = false;
    switch(pending_request){
        case PENDING_ARM:
            satisfied = (getUGV_state() == active);
            break;
        case PENDING_DISARM:
            satisfied = (getUGV_state() == standby);
            break;
        case PENDING_SPEED:
            satisfied = (getUGV_speed() == pending_expected_speed);
            break;
        case PENDING_DRIVE_MODE:
            satisfied = (getDriveMode() == pending_expected_drive_mode);
            break;
        default:
            break;
    }

    if(satisfied){
        if(getErrorCodeDisplayed() == ARM_DISARM_FAIL)
            clearError();
        clearInfo();
        clearPendingRequest();
        return;
    }

    if(millis() - pending_since_ms < STATE_REQUEST_TIMEOUT_MS)
        return;

    // Timed out waiting for UGV-reported confirmation.
    switch(pending_request){
        case PENDING_ARM:
        case PENDING_DISARM:
            displayError("Arm/Disarm request failed", ARM_DISARM_FAIL);
            break;
        case PENDING_SPEED:
            displayInfo("Speed limit request timed out");
            // Momentary switch: no auto-retry; next click sends the next limit.
            break;
        case PENDING_DRIVE_MODE:
            displayInfo("Drive mode request timed out");
            break;
        default:
            break;
    }
    clearPendingRequest();
}



inline bool isUGVdisconnected(){
    return getUGV_state() == disconnected;
}


inline bool switchModeCondition(){
    return switchMode;
}

inline bool turnHeadlightCondition(){
    return turnOnHeadlight;
}

inline bool turnFogLightCondition(){
    return turnOnFoglight;
}

inline bool turnOffLightsCondition(){
    return turnOffLight;
}


inline bool speedChangeCondition(){
    /* Momentary pin 3: one TX per click (not continuous like the old HI/MID/LO toggle). */
    return speed_limit_press;
}

inline bool startArmCondition(){
    return arm_press && getUGV_state() == standby;
}

inline bool startDisarmCondition(){
    return arm_press && getUGV_state() == active;
}


void initiateController(){
    if(!identifyControllerDrift()){
        IF_DEBUG(Serial.println("didn't calibrate drift");)

        displayInfo("Please leave joystick at center");
        delay(SECONDS_MS_3);
        clearInfo();

        if(!identifyControllerDrift()){
            IF_DEBUG(Serial.println("Error 0x002; Joystick cannot be calibrated correctly!");)
            displayError("Joystick cannot be calibrated correctly!", JOYSTICK_CALIBRATION);
            while(!identifyControllerDrift()){
                delay(SECONDS_MS_1);
            }
            clearError();
        }
    }
    IF_DEBUG(Serial.println("completed controller calibration");)
}


/**
 * Before connectivity is established, the current state of the UGV is "disconnected"
 * The hand controller continuously checks for incoming heartbeat packets.
 * Once a valid heartbeat is received, heartbeat_timed_out() function will return false, hence exiting the connectivity phase
 */
void establish_connectivity()
{

    setUGV_state((ugv_status)disconnected);
    
    while(heartbeat_timed_out()){
        handlePacketReceived();
        periodic_actions.performPeriodicActions();


        // Local RFD injects RADIO_STATUS — skip that check in USB simulation (no radio on rig).
#ifndef RADIO_SIMULATION_TESTING
        if(!receivedRadioStatus() && millis() - startup_time > SECONDS_MS_5){
           static bool err5_logged = false;
           if(!err5_logged){
               IF_DEBUG(Serial.println("ERROR 5: no RADIO_STATUS on Serial3");)
               IF_DEBUG(Serial.println("Check: 1) radio POWER  2) Mega14->RadioRX Mega15<-RadioTX GND  3) baud 115200");)
               err5_logged = true;
           }
           displayError("Radio communication failure", RADIO_COMM_FAILURE);
        }
#endif
    }
    hb_count = 0;
}


/**
 * A MAVLink Timesync request packet is sent immediately on entering this phase.
 * Ideally, within 1 second of sending the packet, the hand controller is to receive a response.
 * However, in case the response does not arrive, a timesync packet will be sent every 1 second.
 * All incoming packets are handled; as a heartbeat is expected to ensure connectivity.
 * In case of no heartbeat being received, then it is understood that connection has been lost. Hence the "syncing ..." message is erased from screen and exitted
 */
void time_synchronize()
{
    resetTimesync();
    sendTimesyncRequest();
    int tsID = periodic_actions.addPeriodicAction(sendTimesyncRequest,SECONDS_MS_1);
    unsigned long long t1 = millis();
    IF_DEBUG(Serial.println("Entered time sync"));
    displayInfo("syncing ...");
    do{
        handlePacketReceived();
        #ifndef TESTING_TIMESYNC
        if(heartbeat_timed_out()){
            clearInfo();
            setUGV_state((ugv_status)disconnected);
            return;
        }
        #endif
        periodic_actions.performPeriodicActions();
    }while(!receivedFirstTimesync() IF_DEBUG(&& millis() - t1 < SECONDS_MS_10));
    clearInfo();
    if(!receivedFirstTimesync()){
        displayError("Failed Time Synchronization",TIME_SYNCHRONIZE_FAILED);
    }
    periodic_actions.stopPeriodicAction(tsID);
}

void startOFPTimer(){
    OFP_timer = millis();   
}

/// @brief waits until time_limit microseconds are completed since beginning of OFP timer
/// @param time_limit number of microseconds the OFP loop is meant to last for
void end_OFP_timer(unsigned long int time_limit){
    IF_DEBUG(Serial.println(millis() - OFP_timer);)
    do{
        checkUserInput();
    }while(millis() - OFP_timer < time_limit);
}

/**
 * current wakeup sequence - 
 * send 3 consecutive heartbeats (to ensure radio status will be received)
 */
void run_wakeup_seq(){
    IF_DEBUG(Serial.println("running wakeup sequence");)
    startup_time = millis();   // paired with SECONDS_MS_5 check in establish_connectivity()
    periodic_actions.reset();
    clearPendingRequest();
    
    #ifndef TESTING
    periodic_actions.addPeriodicAction(sendHeartbeat,SECONDS_MS_1);   // send a heartbeat every 1 second
    periodic_actions.addPeriodicAction(updateDisplay,SECONDS_MS_2);
   
   #ifndef TESTING_TIMESYNC
    establish_connectivity();
#endif
    time_synchronize();

    #endif
    setFoglightState(0);
    setHeadlighState(0);

#ifndef DEPRECATED_REV_1
    sendComponentVersion();
#endif

    periodic_actions.reset();
    periodic_actions.addPeriodicAction(sendHeartbeat,SECONDS_MS_1);
    periodic_actions.addPeriodicAction(updateDisplay,SECONDS_MS_2);
    periodic_actions.addPeriodicAction(sendTimesyncRequest,TIMESYNC_MSG_WAIT,isUGVdisconnected);


    IF_TESTING(setUGV_state(active);)
}



void run_OFP_cycle()
{
    startOFPTimer();

    // Sample toggles/buttons at the start of the cycle so this OFP sees current positions.
    checkUserInput();

    #ifndef TESTING
    if(heartbeat_timed_out()){
        setUGV_state((ugv_status)disconnected);
        clearPendingRequest();
        return;
    }
    #endif

    if(getUGV_state() == active)
        sendManualControl();
#ifdef TESTING
    else
        delay(5);
#endif

    /*
     * Operator requests — same priority chain as original OFP:
     * arm / disarm XOR e-stop (else-if), then lights / speed / drive-mode independently.
     * Pin map: arm=2, speed-limit cycle=3, e-stop toggle=4/5, lights=6/8, drive-mode=7.
     */
    if(startArmCondition()){
        IF_DEBUG(Serial.println("ARM BUTTON PRESSED"));
        displayInfo("arming ...");
        sendArmCommand();
        startPendingRequest(PENDING_ARM);
        arm_press = false;
    }
    else if(startDisarmCondition()){
        IF_DEBUG(Serial.println("DISARM BUTTON PRESSED"));
        displayInfo("disarming ...");
        sendDisarmCommand();
        startPendingRequest(PENDING_DISARM);
        arm_press = false;
    }
    if(estop_toggled){
        /*
         * Operator wants engage: retransmit REMOTE_EMERGENCY (param1=2) until
         * COMP_HEARTBEAT custom_mode reports engaged (ICD §4.2.5.1: 2 → getEmergencyMode()).
         * Stop TX once engaged — same idea as the old toggle path.
         */
        static unsigned long last_estop_tx_ms = 0;
        if(getEmergencyMode() != engaged){
            if(last_estop_tx_ms == 0
                || (millis() - last_estop_tx_ms >= ESTOP_RETRANSMIT_MS)){
                IF_DEBUG(displayInfo("e-stop engage TX");)
                sendEstopRequest(true);
                last_estop_tx_ms = millis();
            }
        }
        else{
            last_estop_tx_ms = 0;  /* ready for a future engage cycle */
        }
    }
    else if(estop_clear_request){
        /*
         * Operator wants clear: retransmit clear until HEARTBEAT reports not engaged
         * (disengaged/disabled). Then stop — no continuous clear after confirm.
         */
        static unsigned long last_estop_clear_ms = 0;
        if(getEmergencyMode() == engaged){
            if(last_estop_clear_ms == 0
                || (millis() - last_estop_clear_ms >= ESTOP_RETRANSMIT_MS)){
                IF_DEBUG(displayInfo("e-stop clear TX");)
                sendEstopRequest(false);
                last_estop_clear_ms = millis();
            }
        }
        else{
            estop_clear_request = false;
            last_estop_clear_ms = 0;
            IF_DEBUG(displayInfo("e-stop cleared");)
        }
    }

    if(turnOffLightsCondition()){
        sendLightToggleState(0);
        turnOffLight = false;
    }
    else if(turnHeadlightCondition()){
        sendLightToggleState(1);
        turnOnHeadlight = false;
    }
    else if(turnFogLightCondition()){
        sendLightToggleState(2);
        turnOnFoglight = false;
    }

    /* Speed limit (pin 3 momentary): one COMMAND per click, Low→Mid→High cycle. */
    if(speedChangeCondition()){
        sendSpeedChangeRequest(required_speed);
        pending_expected_speed = required_speed;
        startPendingRequest(PENDING_SPEED);
        displayInfo("setting speed limit ...");
        speed_limit_press = false;
    }

    /* Drive mode cycle button */
    if(switchModeCondition()){
        IF_DEBUG(Serial.println("requesting drive mode"));
        pending_expected_drive_mode = get_inc_driveMode();
        sendModeChangeRequest();
        startPendingRequest(PENDING_DRIVE_MODE);
        displayInfo("setting drive mode ...");
        switchMode = false;
    }

    handlePacketReceived();
    evaluatePendingRequests();
    periodic_actions.performPeriodicActions();

    end_OFP_timer(OFP_LOOP_TIME);
}
