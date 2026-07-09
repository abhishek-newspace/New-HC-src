/**
 * @file standard_procedures.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 28/04/2026
 * @brief definitions of set of functions to represent phases within the main control loop of the microcontroller in the hand controller.
 * 
 * <h2>changes</h2>
 * @date 06/05/2026
 * - added included arm/disarm commands, based on reviewed OFP cycle
 * - added heartbeat being sent from hand controller
 * - created an object for timesync timing
 */

#include "include/standard_procedures.hpp"


periodicActions periodic_actions;

timer timesync_timer;

timer update_screen_timer;

bool currentlySendingArm = false;
extern int arm_send_count;
bool arm_disarm_error = false;

bool turnOnHeadlight = false;
bool turnOnFoglight = false;
int required_speed = 0;
bool switchMode = false;
bool arm_press = false;
bool disarm_press = false;
bool estop_toggled = false;

int hb_count = 0;
long unsigned int OFP_timer = 0;
uint32_t startup_time = 0;

uint32_t init_time;



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


inline bool speedChangeCondition(){
    static unsigned long last_change_at = 0;
    if(required_speed != getUGV_speed() && millis() - last_change_at > RESEND_DELAY){
        last_change_at = millis();
        return true;
    }
    else{
        return false;
    }
}

inline bool startArmCondition(){
    return arm_press && getUGV_state() == standby;
}

inline bool startDisarmCondition(){
    return disarm_press && getUGV_state() == active;
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


        if(!receivedRadioStatus() && micros() - startup_time > SECONDS_MS_5){
           displayError("Radio communication failure", RADIO_COMM_FAILURE);
    }
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

    sendTimesyncRequest();
    int tsID = periodic_actions.addPeriodicAction(sendTimesyncRequest,SECONDS_MS_1,receivedFirstTimesync);
    unsigned long long t1 = millis();
    IF_DEBUG(Serial.println("Entered time sync"));
    displayInfo("syncing ...");
    do{
        handlePacketReceived();
        if(heartbeat_timed_out()){
            clearInfo();
            setUGV_state((ugv_status)disconnected);
            return;
        }
        periodic_actions.performPeriodicActions();
    }while(!receivedFirstTimesync() && millis() - t1 < 10000);
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
    
    startup_time = micros();
    periodic_actions.reset();
    
    #ifndef TESTING
    periodic_actions.addPeriodicAction(sendHeartbeat,SECONDS_MS_1);   // send a heartbeat every 1 second
    periodic_actions.addPeriodicAction(updateDisplay,SECONDS_MS_2);
   
    establish_connectivity();

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

    #ifndef TESTING
    if(heartbeat_timed_out()){
        setUGV_state((ugv_status)disconnected);
        return;
    }
    #endif

    if(getUGV_state() == active)
        sendManualControl();
#ifdef TESTING
    else
        delay(5);
#endif

    if(startArmCondition()){
        IF_DEBUG(Serial.println("ARM BUTTON PRESSED"));
        displayInfo("arming ...");
        sendArmCommand();
        arm_press = false;
        disarm_press = false;
    }
    else if(startDisarmCondition()){
        IF_DEBUG(Serial.println("DISARM BUTTON PRESSED"));
        displayInfo("disarming ...");
        sendDisarmCommand();
        arm_press = false;
        disarm_press = false;
    }
    else if(!estop_toggled){
        displayInfo("e-stop engaged");
        if(getEmergencyMode() != engaged)
            sendEstopRequest(0);
    }
    else{
        if(getEmergencyMode() == engaged)
            sendEstopRequest(1);
    }
    if(turnHeadlightCondition()){
        sendHeadlight();
        turnOnHeadlight = false;
    }
    if(turnFogLightCondition()){
        sendFogBrakeLight();
        turnOnFoglight = false;
    }
    if(speedChangeCondition()){
        sendSpeedChangeRequest(required_speed);
    }
    if(switchModeCondition()){
        sendModeChangeRequest();
        switchMode = false;
    }
    handlePacketReceived();
    periodic_actions.performPeriodicActions();

    end_OFP_timer(OFP_LOOP_TIME);
}