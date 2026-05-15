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

int hb_count = 0;
long unsigned int OFP_timer = 0;

uint32_t init_time;

void initiateController(){
    if(!identifyControllerDrift()){
        IF_DEBUG(Serial.println("didn't calibrate drift");)

        displayInfo("Please leave joystick at center");
        delay(SECONDS_MS_3);
        clearInfo();

        if(!identifyControllerDrift()){
            IF_DEBUG(Serial.println("Error 0x002; Joystick cannot be calibrated correctly!");)
            displayError("Joystick cannot be calibrated correctly!", 2);
            while(!identifyControllerDrift()){
                delay(SECONDS_MS_1);
            }
            clearError();
        }
    }
    IF_DEBUG(Serial.println("completed controller calibration");)
}



void run_wakeup_seq(){
    periodic_actions.reset();
    periodic_actions.addPeriodicAction(sendHeartbeat,SECONDS_MS_1);   // send a heartbeat every 1 second
    establish_connectivity();
    periodic_actions.addPeriodicAction(updateDisplay,SECONDS_MS_1);
    time_synchronize();
    sendComponentVersion();
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

    int tsID = periodic_actions.addPeriodicAction(sendTimesyncRequest,SECONDS_MS_1,receivedFirstTimesync);
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
    }while(!receivedFirstTimesync());
    periodic_actions.stopPeriodicAction(tsID);
    periodic_actions.addPeriodicAction(sendTimesyncRequest,TIMESYNC_MSG_WAIT);
}

void startOFPTimer(){
    OFP_timer = micros();
}

/// @brief waits until time_limit microseconds are completed since beginning of OFP timer
/// @param time_limit number of microseconds the OFP loop is meant to last for
void end_OFP_timer(unsigned long int time_limit){
    do{
        checkUserInput();
    }while(micros() - OFP_timer < time_limit);
}


bool startArmConditionSatisfied(){
    return arm_pressed() && getUGV_state() == standby && get_requests_sent() == 0;
}

bool startDisarmConditionSatisfied(){
    return arm_long_pressed() && getUGV_state() == active && get_requests_sent() == 0;
}

bool stopArmDisarmResendCondition(){
    return get_requests_sent == 0;
}

void resendArmCommand(){
    sendArmCommand();
    inc_requests_sent();
}

void resendDisarmCommand(){
    sendDisarmCommand();
    inc_requests_sent();
}

void run_OFP_cycle()
{
    startOFPTimer();

    if(heartbeat_timed_out()){
        setUGV_state((ugv_status)disconnected);
        return;
    }

    if(getUGV_state() == active)
        sendManualControl();

    if(startArmConditionSatisfied()){
        IF_DEBUG(Serial.println("ARM BUTTON PRESSED"));
        displayInfo("arming ...");
        periodic_actions.addPeriodicAction(resendArmCommand,ARM_DISARM_RESEND_DELAY,stopArmDisarmResendCondition);
    }
    else if(startDisarmConditionSatisfied()){
        IF_DEBUG(Serial.println("DISARM BUTTON PRESSED"));
        displayInfo("disarming ...");
        periodic_actions.addPeriodicAction(resendDisarmCommand,ARM_DISARM_RESEND_DELAY,stopArmDisarmResendCondition);
    }

    if(get_requests_sent() >= 4){
        clearInfo();
        displayError((get_arm_start() ? String("disarm") : String("arm") + String(" request failed")),3);
        resetArmDisarm();
    }

    handlePacketReceived();
    periodic_actions.performPeriodicActions();

    end_OFP_timer(OFP_LOOP_TIME);
}