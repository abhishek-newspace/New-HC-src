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
 * 
 * @date 04/05/2026
 * - separated single button struct into multiple button structs for better modularity
 * 
 * @date 06/05/2026
 * added function to check for long press
 */
#include "include/IOhandler.hpp"


int drift_x;
int drift_y;


button  b_neutral = {
            BUTTON_NEUTRAL,     // uint8_t pin;                
            0,                  // buttonPress press_state;
            setNeutral,            // void (*press_callback)(void);        
            0                   // uint32_t cooldown;
        },
        b_inc_speed = {
            BUTTON_INC_SPEED,    // uint8_t pin; 
            0,                   // buttonPress press_state; 
            inc_Speed,           // void (*press_callback)(void); 
            0                    // uint32_t cooldown;
        },
        b_dec_speed = {
            BUTTON_DEC_SPEED,    // uint8_t pin;
            0,                   // buttonPress press_state;
            dec_Speed,           // void (*press_callback)(void);
            0                    // uint32_t cooldown;
        };

long_press_button b_arm_disarm = {
    BUTTON_ARM_DISARM, 
    0, 
    nullptr, 
    nullptr, 
    0, 
    0
};
struct toggle dir_toggle = {
    TOGGLE_REVERSE,
    forward,
    0,
    dir_reverse,
    dir_forward
};


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
    return b_arm_disarm.press_state > 0;
}

bool arm_long_pressed()
{
    return b_arm_disarm.press_state == long_pressed;
} /**
   * update the struct values for a normal button
   */
void updateButtonValues(struct button *b1, int32_t ms_since_last_check){

    // IF_DEBUG(Serial.println("ARM BUTTON CHECK"));
    b1->press_state = (uint8_t)!digitalRead(b1->pin);
    if(b1->press_state && b1->cooldown == 0){
        
        if(b1->press_callback != nullptr)
            b1->press_callback();

        b1->cooldown = BUTTON_PRESS_COOLDOWN;
    }
    else
        b1->cooldown = max(0, b1->cooldown - ms_since_last_check);

    // IF_DEBUG(Serial.println(b1->cooldown);)
}

/**
 * update the struct values for a long press button
 */
void updateLongPressButtonValues(struct long_press_button *b1, int32_t ms_since_last_check){
    b1->cooldown = max(0, b1->cooldown - ms_since_last_check);
    if(!(digitalRead(b1->pin)) && b1->cooldown == 0){
        if(b1->press_state){
            b1->pressed_for += ms_since_last_check;
            if(b1->pressed_for >= LONG_PRESS_DURATION)
                b1->press_state = long_pressed;
        }
        else{
            b1->press_state = short_pressed;
        }
    }
    else{
        if(b1->press_state == long_pressed){
            b1->cooldown = BUTTON_PRESS_COOLDOWN;
            if(b1->long_press_callback != nullptr)
                b1->long_press_callback();
        }
        else if(b1->press_state == short_pressed){
            b1->cooldown = BUTTON_PRESS_COOLDOWN;
            if(b1->short_press_callback != nullptr)
                b1->short_press_callback();
        }
        b1->press_state = not_pressed;
        b1->pressed_for = 0;
        
    }
    IF_DEBUG(Serial.println(b1->press_state));
    return;
    
    buttonPress prevState = b1->press_state;

    b1->press_state = (int)!digitalRead(b1->pin);
    b1->cooldown = max(0, b1->cooldown - ms_since_last_check);

    if(b1->press_state && b1->cooldown > 0){
        b1->press_state = 0;
        return;
    }

    if(b1->press_state && b1->pressed_for > LONG_PRESS_DURATION){
        IF_DEBUG(Serial.println("long pressed!");)
        b1->press_state = long_pressed;
    }

    else if(b1->press_state && prevState)
        b1->pressed_for += ms_since_last_check;

    else if(b1->press_state == not_pressed && prevState){
        if(prevState == long_pressed && b1->long_press_callback != nullptr){
            b1->long_press_callback();
        }
        else if(prevState == short_pressed && b1->short_press_callback != nullptr){
            b1->short_press_callback();
        }
        b1->cooldown = BUTTON_PRESS_COOLDOWN;
    }
}

void updateToggleValues(struct toggle *t1, int32_t ms_since_last_check){
    if(digitalRead(t1->pin)){    // currently read 1
        // IF_DEBUG(Serial.println("currently FORWARD"));

        if(!t1->state){  // currently read 1 but previously was 0
            if(t1->toggled_at > 0 && (micros() - t1->toggled_at) > TOGGLE_DEBOUNCE_DURATION){

                t1->state = 1;
                t1->toggled_at = 0;
                t1->pos_1_callback();
            }
            else if(t1->toggled_at == 0){    
                t1->toggled_at = micros();
            }
        }
        else{   // currently read 1 and previously also 1
            t1->toggled_at = 0;
        }
    }
    else{
        // IF_DEBUG(Serial.println("currently REVERSE"));
        
        if(!t1->state){   // currently read 0 and previously was also 0
            t1->toggled_at = 0;
        }
        else if(t1->state){   // currently read 0 but previously was 1
            t1->state = 0;
            t1->pos_0_callback();
        }
        
    }
}




void checkUserInput()
{
    static unsigned long int last_input_checked_at = millis();

    int32_t ms_since_last_check = millis() - last_input_checked_at;
    
    updateButtonValues(&b_neutral, ms_since_last_check);
    updateButtonValues(&b_inc_speed, ms_since_last_check);
    updateButtonValues(&b_dec_speed, ms_since_last_check);
    updateLongPressButtonValues(&b_arm_disarm, ms_since_last_check);
    updateToggleValues(&dir_toggle,ms_since_last_check);

    last_input_checked_at = millis();
}