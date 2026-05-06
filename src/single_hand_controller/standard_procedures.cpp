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


timer timesync_timer;

uint32_t arm_start = 0, disarm_start = 0;
int requests_sent = 0;

int hb_count = 0;

/**
 * Before connectivity is established, the current state of the UGV is "disconnected"
 * The hand controller continuously checks for incoming heartbeat packets.
 * Once a valid heartbeat is received, heartbeat_timed_out() function will return false, hence exiting the connectivity phase
 */
void establish_connectivity()
{

    setUGV_state((ugv_status)disconnected);
    
    while(heartbeat_timed_out()){
        // IF_TESTING(checkUserInput());
        handlePacketReceived();
        // IF_TESTING(delay(20));
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

    timesync_timer.startTimer();
    sendTimesyncRequest();
    IF_DEBUG(Serial.println("Entered time sync"));
    displayInfo("syncing ...");
    do{
        if(timesync_timer.timeup(SECONDS_MS_1)){
            sendTimesyncRequest();
            timesync_timer.resetTimer();
        }
        handlePacketReceived();
        if(heartbeat_timed_out()){
            clearInfo();
            setUGV_state((ugv_status)disconnected);
            return;
        }
    }while(!receivedFirstTimesync());

}

void run_OFP_cycle()
{
    startOFPTimer();

    if(heartbeat_timed_out()){
        setUGV_state((ugv_status)disconnected);
        return;
    }

    if(timesync_timer.timeup(TIMESYNC_MSG_WAIT)){
        sendTimesyncRequest();
        hb_count = 0;
        timesync_timer.resetTimer();
    }

    if(timesync_timer.timeup(hb_count * SECONDS_MS_1)){
        hb_count++;
        sendHeartbeat();
    }

    sendManualControl();

    if(arm_pressed() && getUGV_state() == standby){
        displayInfo("arming ...");
        requests_sent = 1;
        arm_start = micros();
        sendArmCommand();   // needs to be defined
    }
    else if(arm_long_pressed() && getUGV_state() == active){
        displayInfo("disarming ...");
        requests_sent = 1;
        disarm_start = micros();
        sendDisarmCommand();    // needs to be defined
    }

    if(arm_start && micros() - arm_start > requests_sent * SECONDS_US_1){
        sendArmCommand();
        requests_sent++;
    }
    else if(disarm_start && micros() - disarm_start > requests_sent * SECONDS_US_1){
        sendDisarmCommand();
        requests_sent++;
    }

    if(requests_sent >= 4){
        displayError(arm_start ? String("disarm") : String("arm") + String(" request failed"),3);
        arm_start = 0;
        disarm_start = 0;
        requests_sent = 0;
    }

    handlePacketReceived();

    end_OFP_timer(OFP_LOOP_TIME);
}

void initiateController()
{

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
