/**
 * @file stateHandler.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of stateHandler library.
 * Defines variables and functions used in stateHandler.hpp.
 * 
 * currently maintains - 
 * 1. state for current_UGV_state (active, standby, and disconnected); and the previous UGV state
 * 2. speed, since the single hand controller prototype doesn't have a tristate speed toggle that maintains state by itself
 * 
*/
#include "include/stateHandler.hpp"

ugv_status current_state = unknown;
ugv_status prev_state = unknown;

directionToggle current_dir, prev_dir;
speedToggle current_spd, prev_spd;

int speed = 0;

bool setUGV_state(ugv_status s1){   
    if(s1 == current_state)
        return false;
    prev_state = current_state;
    current_state = s1;
    displayUGV_status(s1);
    return true;
}

ugv_status getUGV_state(){
    return current_state;
}


bool isUGV_connected(){
    return current_state != disconnected;
}


void inc_Speed(){
    speed = speed > 2 ? speed : speed + 1;
    displaySpeed(speed);
}
void dec_Speed(){
    speed = speed == 0 ? speed : speed - 1;
    displaySpeed(speed);
}

void setNeutral(){
    speed = 0;
    IF_DEBUG(Serial.println("set neutral called!"));
    displaySpeed(speed);
}