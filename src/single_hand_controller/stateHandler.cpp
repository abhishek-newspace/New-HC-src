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
speedToggle current_spd;
driveMode current_mode = speed;
connectivity_status conn_stat = all_disconnected;


bool headlight_state = 0;

bool fog_brake_state = 0;


void switch_conn_stat(connectivity_status status){
    conn_stat = status;
}
connectivity_status get_conn_stat(){
    return conn_stat;
}

int getDriveMode(){
    return current_mode;
}

int get_inc_driveMode(){
    return (current_mode + 1) % 3;
}

void switchDriveMode(){
    current_mode = (current_mode + 1) % 3;
    displayDriveMode(current_mode);
    
    
}

// gettr functions
bool headlight_off(){
    return headlight_state == 0;
}
bool foglight_off(){
    return fog_brake_state == 0;
}

// setter functions
void setHeadlighState(bool state){
    headlight_state = state;
}

void setFoglightState(bool state){
    
    fog_brake_state = state;
}

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
    return current_spd + 1;
}

void setUGV_speed(int speed){
    current_spd = (speedToggle)(speed - 1);
    displaySpeed(current_spd);
}


bool isUGV_connected(){
    return current_state != disconnected;
}


// internally used functions

void inc_Speed(){
    IF_DEBUG(Serial.println("increase speed called!"));
    current_spd = (current_spd + 1) % 3;
    setUGV_speed(current_spd + 1);
    // speed = speed > 2 ? speed : speed + 1;
    // current_spd = (speedToggle)(speed - 1);
    // displaySpeed(speed);
    // current_dir = set_dir;
    // displayDirection(current_dir);
}
int get_inc_speed(){
    return (current_spd + 1) % 3;
}
