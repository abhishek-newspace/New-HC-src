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
 * <h2>changes</h2>
 * @date 04/05/2026
 * - added function defintitions for functions to change directions, and get current speed, and direction
 * 
*/
#include "include/stateHandler.hpp"

ugv_status current_state = unknown;
ugv_status prev_state = unknown;

directionToggle current_dir = neutral,    /// inicates current direction state regardless of toggle switch (includes neutral state for toggle switch)
                set_dir = forward;        /// indicates direction state that is set by the toggle switch
speedToggle current_spd = low;

int speed = 0;

// setter functions
bool setUGV_state(ugv_status s1){   
    if(s1 == current_state)
        return false;
    prev_state = current_state;
    current_state = s1;
    displayUGV_status(s1);
    return true;
}



// getter functions

ugv_status getUGV_state(){
    return current_state;
}

speedToggle getUGV_speed(){
    return current_spd;
}

directionToggle getUGV_dir(){
    return current_dir;
}

bool isUGV_connected(){
    return current_state != disconnected;
}


// internally used functions

void inc_Speed(){
    IF_DEBUG(Serial.println("increase speed called!"));
    speed = speed > 2 ? speed : speed + 1;
    current_spd = (speedToggle)(speed - 1);
    displaySpeed(speed);
    current_dir = set_dir;
    displayDirection(current_dir);
}
void dec_Speed(){
    IF_DEBUG(Serial.println("decrease speed called!"));
    speed = speed == 0 ? speed : speed - 1;
    if(speed > 0){
        current_spd = (speedToggle)(speed - 1);
    }
    else{
        current_spd = 0;
        current_dir = neutral;
    }
    displaySpeed(speed);
    displayDirection(current_dir);
}

void setNeutral(){
    speed = 0;
    IF_DEBUG(Serial.println("set neutral called!"));
    displaySpeed(speed);
    current_dir = neutral;
    displayDirection(current_dir);
}

void dir_reverse(){
    IF_DEBUG(Serial.println("------------------dir reverse"));
    if(speed > 0){
        current_dir = reverse;
        set_dir = reverse;
        displayDirection(current_dir);
    }
    else
        set_dir = reverse;
}

void dir_forward(){
    IF_DEBUG(Serial.println("+++++++++++++++++++dir forward"));
    if(speed > 0){
        current_dir = forward;
        set_dir = forward;
        displayDirection(current_dir);
    }
    else
        set_dir = forward;
}