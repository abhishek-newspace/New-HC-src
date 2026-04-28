/**
 * @file single_hand_controller.ino
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Main source file for the single hand controller for scout project.
 * The code structure is that of a standard Arduino source file format, 
 * where the setup() function is meant to run once on startup of the microcontroller, 
 * followed by loop() function running infinitely till a reset is triggered on the microcontroller.
*/
#include "include/includes.h"

void setup(){
    setupIO();
    setupDisplay();
    
    if(!initMAVLink()){
        displayError("continue without packet signing", 1);
    }
    
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


void loop(){
    
    if(heartbeat_timed_out()){
        setUGV_state((ugv_status)disconnected);
        
        while(heartbeat_timed_out()){
            IF_TESTING(checkUserInput());
            handlePacketReceived();
            IF_TESTING(delay(500));
        }
        

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
    IF_DEBUG(Serial.println("Entered OFP"));
    
    while(true){
        startOFPTimer();

        if(timeup(TIMESYNC_MSG_WAIT)){
            sendTimesyncRequest();
            resetTimer();
        }

        sendManualControl();

        handlePacketReceived();

        if(heartbeat_timed_out()){
            setUGV_state((ugv_status)disconnected);
            break;
        }

        end_OFP_timer(OFP_LOOP_TIME);
    }
}