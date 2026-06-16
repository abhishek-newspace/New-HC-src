#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/timer.cpp"
/**
 * @file timer.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of timer library; Meant to be used only within the main source file to time intervals between 2 events.
 * Defines variables and functions used in setupFunctions.h.
*/
#include "include/timer.hpp"

void timer::startTimer(){
    current_time = millis();
}

//! check whether the given amount of time (in ms) is completed or not
bool timer::timeup(unsigned long int time_ms){
    return (millis() - current_time >= time_ms);
}

bool timer::timeup()
{
    if(timeup(duration)){
        resetTimer();
        return true;
    }
    else
        return false;

}

void timer::resetTimer(){ 
    current_time = millis();
}
