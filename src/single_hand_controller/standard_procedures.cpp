/**
 * @file standard_procedures.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 28/04/2026
 * @brief definitions of set of functions to represent phases within the main control loop of the microcontroller in the hand controller.
 */

#include "include/standard_procedures.hpp"


/**
 * Before connectivity is established, the current state of the UGV is "disconnected"
 * The hand controller continuously checks for incoming heartbeat packets.
 * Once a valid heartbeat is received, heartbeat_timed_out() function will return false, hence exiting the connectivity phase
 */
void establish_connectivity()
{

    setUGV_state((ugv_status)disconnected);
    
    while(heartbeat_timed_out()){
        IF_TESTING(checkUserInput());
        handlePacketReceived();
        IF_TESTING(delay(20));
    }

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

    startTimer();
    sendTimesyncRequest();
    IF_DEBUG(Serial.println("Entered time sync"));
    displayInfo("syncing ...");
    do{
        if(timeup(SECONDS_MS_1)){
            sendTimesyncRequest();
            resetTimer();
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

    if(timeup(TIMESYNC_MSG_WAIT)){
        sendTimesyncRequest();
        resetTimer();
    }

    sendManualControl();

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
}
