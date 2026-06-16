#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/setupFunctions.cpp"
/**
 * @file setupFunctions.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of set up functions library; used within the setup() function of single_hand_controller.ino.
 * Defines variables and functions used in setupFunctions.h.
*/
#include "include/setupFunctions.h"


extern int drift_x, drift_y;

void setupIO(){
    pinMode(BUTTON_NEUTRAL, INPUT);
    pinMode(BUTTON_INC_SPEED, INPUT);
    pinMode(BUTTON_DEC_SPEED, INPUT);
    pinMode(BUTTON_ARM_DISARM, INPUT);
    pinMode(TOGGLE_FORWARD, INPUT);
    pinMode(TOGGLE_REVERSE, INPUT);
    pinMode(XPIN, INPUT);
    pinMode(YPIN, INPUT);
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
    return setupSigning();
}

void setupDisplay(){
    initDisplayComm();
    clear_display();
    setFont1();
    displayLogo();
    displayInvertedLogo();
    displayDriveMode(speed);
    displayBasic();
}
