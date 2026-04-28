/**
 * @file IOhandler.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of IOhandler library
 * Defines functions and variables used in IOhandler.h
 * 
 * <H2>Changes </h2>
 * @date 28/04/2026
 * - added a cooldown period for button presses
 * - added callback function for action to be performed when buttons like increaseSpeed, decreaseSpeed, Neutral is pressed
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


bool debounceAndInput(int buttonNumber){
  int is_true = 0;
  for(int i = 0; i < 50; i++){
    if(digitalRead(buttonNumber))
      is_true++;
    else
      is_true--;
  }
  return is_true > 0;
}

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

bool arm_pressed()
{
    return user_input.arm_disarm > 0;
}
void checkUserInput()
{
    static unsigned long int last_input_checked_at = millis();

    int32_t ms_since_last_check = millis() - last_input_checked_at;
    

    // update cooldown

    user_input.arm_disarm_cooldown = user_input.arm_disarm_cooldown > 0 ? max(user_input.arm_disarm_cooldown - ms_since_last_check, 0) : 0;
    user_input.decreaseSpeed_cooldown = user_input.decreaseSpeed_cooldown > 0 ? max(user_input.decreaseSpeed_cooldown - ms_since_last_check, 0) : 0;
    user_input.increaseSpeed_cooldown = user_input.increaseSpeed_cooldown > 0 ? max(user_input.increaseSpeed_cooldown - ms_since_last_check, 0) : 0;
    user_input.neutral_cooldown = user_input.neutral_cooldown > 0 ? max(user_input.neutral_cooldown - ms_since_last_check, 0) : 0;


    // check current button state 

    user_input.arm_disarm = !digitalRead(BUTTON_ARM_DISARM) && user_input.arm_disarm_cooldown;
    
    if(user_input.arm_disarm){
        user_input.arm_disarm_press_duration += ms_since_last_check;
        if(user_input.arm_disarm_press_duration > LONG_PRESS_DURATION)
            user_input.arm_disarm_long = 1;
    }
    else{
        user_input.arm_disarm_press_duration = 0;
        user_input.arm_disarm_long = 0;
    }

    user_input.decreaseSpeed = !digitalRead(BUTTON_DEC_SPEED) && !user_input.decreaseSpeed_cooldown;
    user_input.increaseSpeed = !digitalRead(BUTTON_INC_SPEED) && !user_input.increaseSpeed_cooldown;
    user_input.neutral = !digitalRead(BUTTON_NEUTRAL) && !user_input.neutral_cooldown;
    // user_input.toggle_forward = !digitalRead(TOGGLE_FORWARD); // not working; always going to be 1
    user_input.toggle_reverse =  !debounceAndInput(TOGGLE_REVERSE);
    

    // update cooldown

    user_input.arm_disarm_cooldown = user_input.arm_disarm ? BUTTON_PRESS_COOLDOWN : user_input.arm_disarm_cooldown;
    user_input.decreaseSpeed_cooldown = user_input.decreaseSpeed ? BUTTON_PRESS_COOLDOWN : user_input.decreaseSpeed_cooldown;
    user_input.increaseSpeed_cooldown = user_input.increaseSpeed ? BUTTON_PRESS_COOLDOWN : user_input.increaseSpeed_cooldown;
    user_input.neutral_cooldown = user_input.neutral ? BUTTON_PRESS_COOLDOWN : user_input.neutral_cooldown;


    // calling callback functions when necessary

    if(user_input.decreaseSpeed){
        IF_DEBUG(Serial.println("decrease speed called"));
        user_input.decreaseSpeed_callback();
    }
    if(user_input.increaseSpeed){
        IF_DEBUG(Serial.println("increase speed called"));
        user_input.increaseSpeed_callback();
    }
    if(user_input.neutral){
        IF_DEBUG(Serial.println("neutral called"));
        user_input.neutral_callback();
    }    
    displayDirection(!user_input.toggle_reverse);
    
    last_input_checked_at = millis();
}