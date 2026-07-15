/**
 * @file setupFunctions.cpp
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
 * 
 * Part of set up functions library; used within the setup() function of single_hand_controller.ino.
 * Defines variables and functions used in setupFunctions.h.
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - configure HC_BATTERY_ADC_PIN and optional HC_BATT_STATUS_LED_PIN in setupIO()
*/
#include "include/setupFunctions.h"


extern int drift_x, drift_y;

void setupIO(){
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(XPIN, INPUT);
    pinMode(YPIN, INPUT);
#ifdef HC_BATTERY_ADC_PIN
    pinMode(HC_BATTERY_ADC_PIN, INPUT);
#endif
#ifdef HC_BATT_STATUS_LED_PIN
    pinMode(HC_BATT_STATUS_LED_PIN, OUTPUT);
    digitalWrite(HC_BATT_STATUS_LED_PIN, LOW);
#endif
}

void initState()
{
    setUGV_state(disconnected);
}
bool identifyControllerDrift()
{
    thumbstickControl inputXY;
    getXY_raw(&inputXY);

    drift_x = inputXY.X;
    drift_y = inputXY.Y;

    if(drift_x > XY_UPPER_LIMIT || drift_x < XY_LOWER_LIMIT){
        IF_DEBUG(Serial.print("X : ");)
        IF_DEBUG(Serial.println(drift_x);)
        return false;
    }
    if(drift_y > XY_UPPER_LIMIT || drift_y < XY_LOWER_LIMIT){
        IF_DEBUG(Serial.print("Y : ");)
        IF_DEBUG(Serial.println(drift_y);)
        return false;
    }

    return true;
}

bool initMAVLink(){
    initiateSerialComm();
#ifdef RADIO_SIMULATION_TESTING
    // No local RFD in USB-rig mode — mark radio path as up so UI/link logic can proceed.
    connectRadio();
    IF_DEBUG(Serial.println("RADIO_SIMULATION_TESTING: MAVLink on USB Serial @ 115200");)
#endif
    return setupSigning();
}

void setupDisplay(){
    initDisplayComm();

    clear_display();
    setFont1();
    #ifdef RELEASE
    displayLogo();
    displayInvertedLogo();
    #endif
    displayDriveMode(speed);
    displayBasic();
}
