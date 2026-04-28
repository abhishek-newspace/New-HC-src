/**
 * @file IOhandler.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of IOhandler library
 * Defines functions and variables used in IOhandler.h
 */
#include "include/IOhandler.hpp"

struct buttons user_input;
int drift_x;
int drift_y;


#ifndef Arduino_h
unsigned long int micros(){
    return 0;
}
bool digitalRead(int k){
    return 1;
}

int analogRead(int pin){
    return 0;
}

#endif


void getXY_raw(struct thumbstickControl *control){

    int* x = &control->X;
    int* y = &control->Y;
    float xsum = 0, ysum = 0;

    for(int i = 0; i < FILTER_SAMPLES; i++){
        xsum += analogRead(XPIN);
        ysum += analogRead(YPIN);
    }
    control->X = xsum / FILTER_SAMPLES;
    control->Y = ysum / FILTER_SAMPLES;
}

void getXY(struct thumbstickControl *control){

    getXY_raw(control);

    int* x = &control->X;
    int* y = &control->Y;

    *x = *x < drift_x ? 
            ((*x  - drift_x)/ (float)drift_x) * XY_NORMALIZED_MAX 
            : ((*x - drift_x) / (float)(ANALOG_OUTPUT_MAX - drift_x)) * XY_NORMALIZED_MAX;

    *y = *y < drift_y ? 
            ((*y  - drift_y)/ (float)drift_y) * XY_NORMALIZED_MAX 
            : ((*y - drift_y) / (float)(ANALOG_OUTPUT_MAX - drift_y)) * XY_NORMALIZED_MAX;
}

void checkUserInput()
{
    static unsigned long int last_input_checked_at = micros();
    
    user_input.arm_disarm = !digitalRead(BUTTON_ARM_DISARM);
    
    if(user_input.arm_disarm){
        user_input.arm_disarm_press_duration += micros() - last_input_checked_at;
        if(user_input.arm_disarm_press_duration > LONG_PRESS_DURATION)
            user_input.arm_disarm_long = 1;
    }
    else{
        user_input.arm_disarm_press_duration = 0;
        user_input.arm_disarm_long = 0;
    }

    user_input.decreaseSpeed = !digitalRead(BUTTON_DEC_SPEED);
    user_input.increaseSpeed = !digitalRead(BUTTON_INC_SPEED);
    user_input.neutral = !digitalRead(BUTTON_NEUTRAL);
    user_input.toggle_forward = !digitalRead(TOGGLE_FORWARD); // not working; always going to be 1
    user_input.toggle_reverse = !digitalRead(TOGGLE_REVERSE);
    // IF_DEBUG(Serial.println(user_input.toggle_forward)); 
    

    last_input_checked_at = micros();
}