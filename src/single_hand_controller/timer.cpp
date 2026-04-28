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

long unsigned int current_time = 0;
long unsigned int OFP_timer = 0;

void startTimer(){
    current_time = millis();
}

//! check whether the given amount of time (in ms) is completed or not
bool timeup(unsigned long int time_ms){
    return (millis() - current_time >= time_ms);
}


void resetTimer(){
    current_time = millis();
}

void startOFPTimer(){
    OFP_timer = micros();
}

void end_OFP_timer(unsigned long int time_limit){
    while(micros() - OFP_timer < time_limit)
        checkUserInput();
}
