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

int speed = 0;

bool setUGV_state(ugv_status s1){   
    if(s1 == current_state)
        return false;
    prev_state = current_state;
    current_state = s1;
    displayUGV_status(s1);
    return true;
}

void increaseSpeed(){
    speed = speed > 2 ? speed : speed + 2;
    displaySpeed(speed);
}
void decreaseSpeed(){
    speed = speed == 0 ? speed : speed - 1;
    displaySpeed(speed);
}
