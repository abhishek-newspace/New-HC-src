#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/IOhandler.cpp"
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


extern bool turnOnHeadlight;
extern bool turnOnFoglight;
extern int required_speed;
extern bool switchMode;
extern bool arm_press;
extern bool disarm_press;

void enableHeadlight(){
    turnOnHeadlight = true;
}

void enabledFoglight(){
    turnOnFoglight = true;
}

void enableSwitchMode(){
    switchMode = true;
}

void enableArm(){
    static long unsigned last_assigned_at = 0;
    if(millis() - last_assigned_at > RESEND_DELAY){
        arm_press = true;
       last_assigned_at = millis();
    }
}

void enableDisarm(){
    static long unsigned last_assigned_at = 0;
    if(millis() - last_assigned_at > RESEND_DELAY){
        disarm_press = true;
        last_assigned_at = millis();
    }
}

void set_speed_low(){
    required_speed = 1;
}

void set_speed_mid(){
    required_speed = 2;
}

void set_speed_high(){
    required_speed = 3;
}




button  b_headlight = {
        BUTTON_HEADLIGHTS,     // uint8_t pin;                
        0,                  // buttonPress press_state;
        enableHeadlight,            // void (*press_callback)(void);        
        0                   // uint32_t cooldown;
    },
    b_foglight = {
        BUTTON_FOGLIGHTS,    // uint8_t pin;
        0,                   // buttonPress press_state;
        enabledFoglight,           // void (*press_callback)(void);
        0                    // uint32_t cooldown;
    },
    b_mode_switch = {
        BUTTON_TORQUE_MODE,
        0,
        enableSwitchMode,
        0
    };

toggle t_arm_disarm = {
    TOGGLE_ARM,
    0,
    enableDisarm,
    enableArm
};
two_pos_toggle tt_speed_toggle = {
        TOGGLE_HIGH_SPEED,
        TOGGLE_LOW_SPEED,
        0,
        set_speed_low,
        set_speed_mid,
        set_speed_high
    };


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

    float* x = &control->X;
    float* y = &control->Y;
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

    float* x = &control->X;
    float* y = &control->Y;

    *x = (*x < XY_LOWER_LIMIT) ? (*x - XY_LOWER_LIMIT) : ((*x > XY_UPPER_LIMIT) ? (*x - XY_UPPER_LIMIT) : 0);
    *x *= -10;
    *y = (*y < XY_LOWER_LIMIT) ? (*y - XY_LOWER_LIMIT) : ((*y > XY_UPPER_LIMIT) ? (*y - XY_UPPER_LIMIT) : 0);
    *y *= 10;

    IF_TESTING_JOYSTICK(Serial.print(*x);)
    IF_TESTING_JOYSTICK(Serial.print(",");)
    IF_TESTING_JOYSTICK(Serial.print(*y);)    
    IF_TESTING_JOYSTICK(Serial.print("\t");)
}
 /**
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
    else{
        b1->cooldown = max(0, b1->cooldown - ms_since_last_check);
        b1->press_state = 0;
    }
    

    
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
            if(b1->pressed_for >= LONG_PRESS_DURATION){
                b1->press_state = long_pressed;
                b1->cooldown = BUTTON_PRESS_COOLDOWN;
                if(b1->long_press_callback != nullptr)
                    b1->long_press_callback();
            }
        }
        else{
            b1->press_state = short_pressed;
        }
    }
    else if(!digitalRead(b1->pin)){
        b1->cooldown = BUTTON_PRESS_COOLDOWN;
    }
    else{
        if(b1->press_state == short_pressed){
            b1->cooldown = BUTTON_PRESS_COOLDOWN;
            if(b1->short_press_callback != nullptr)
                b1->short_press_callback();
        }
        b1->press_state = not_pressed;
        b1->pressed_for = 0;
        
    }
    //IF_DEBUG(Serial.println(b1->press_state));
    return;
    
    buttonPress prevState = b1->press_state;

    b1->press_state = (int)!digitalRead(b1->pin);
    b1->cooldown = max(0, b1->cooldown - ms_since_last_check);

    if(b1->press_state && b1->cooldown > 0){
        b1->press_state = 0;
        return;
    }

    if(b1->press_state && b1->pressed_for > LONG_PRESS_DURATION){
        //IF_DEBUG(Serial.println("long pressed!");)
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
    if(!digitalRead(t1->pin)){    // currently read 1
        t1->state = 1;
        t1->pos_1_callback();
    }
    else{
        t1->state = 0;
        t1->pos_0_callback();
    
    }
}

void updateTwoPosToggleValues(struct two_pos_toggle *t1, int32_t ms_since_last_check){
    if(!digitalRead(t1->pin_pos0)){    // currently read 1
        t1->state = 0;
        t1->pos_0_callback();
    }
    else if(!digitalRead(t1->pin_pos2)){
        t1->state = 2;
        t1->pos_2_callback();
    }
    else{
        t1->state = 1;
        t1->pos_1_callback();
    }
}



void checkUserInput()
{
    
    // #ifdef TESTING_JOYSTICK
    // for(int i = 2; i < 8; i++){
    //     Serial.print(digitalRead(i));
    // }
    // Serial.println("");
    // #endif

    static unsigned long int last_input_checked_at = millis();

    int32_t ms_since_last_check = millis() - last_input_checked_at;
    
    updateButtonValues(&b_headlight, ms_since_last_check);
    updateButtonValues(&b_foglight, ms_since_last_check);
    updateButtonValues(&b_mode_switch, ms_since_last_check);
    updateToggleValues(&t_arm_disarm, ms_since_last_check);
    updateTwoPosToggleValues(&tt_speed_toggle, ms_since_last_check);

    last_input_checked_at = millis();
}