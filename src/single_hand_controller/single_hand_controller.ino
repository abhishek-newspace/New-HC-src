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
 * 
 * <h2>Changes</h2>
 * @date 28/04/2026
 * modularized code within void loop()
*/
#include "include/standard_procedures.hpp"

void setup(){
    setupIO();
    // setupDisplay();
    setupLEDs();
    if(!initMAVLink()){
        displayError("continue without packet signing", SIGNING_FAIL);
    }

    // 3 consecutive heartbeats to ensure radio status reception
    sendHeartbeat();
    sendHeartbeat();
    sendHeartbeat();
}


void loop(){
    #ifdef GET_RADIO_CONFIG
        performConfig();
        while(true);
    #endif
    #ifdef TESTING_JOYSTICK
    thumbstickControl c1;
    uint32_t t1 = micros();
    getXY(&c1);
    Serial.print(micros() - t1);
    Serial.println("micro sec");

    while(true){
        getXY(&c1);
        checkUserInput();
        Serial.println("");
    }
    #endif

#ifdef DEBUG_BUTTONS
    /* Poll inputs even before UGV link so Serial Monitor shows button edges. */
    checkUserInput();
    updateLEDs();
#endif

    if(heartbeat_timed_out()){
        run_wakeup_seq();
    }

    if(!isUGV_connected())
        return;

    IF_DEBUG(Serial.println("Entered OFP"));
    
    while(true){
        run_OFP_cycle();

#ifndef TESTING
        if(!isUGV_connected())
            return;
#endif
    }
}