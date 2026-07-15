/**
 * @file IOhandler.cpp
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
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
 *
 * @date 15/07/2026
 * - added readHcBatterySoc() for SRS §3.2.3.3 local HC pack ADC SoC (0–100)
 * - optional bench placeholder when sense pin is floating (HC_BATT_NO_SENSE_RAW_MAX)
 * - updateLightToggleEdge(): light toggle pins 6/8 — send only on position change
 * - e-stop pin 3: long-press latch (engage continuous / disengage once)
 */
#include "include/IOhandler.hpp"


extern bool turnOnHeadlight;
extern bool turnOnFoglight;
extern bool turnOffLight;
extern int required_speed;
extern bool switchMode;
extern bool arm_press;
extern bool disarm_press;
extern bool estop_toggled;
extern bool estop_clear_request;

/** Long-press pin 3: first engage (continuous TX), second disengage (one-shot clear). */
void latchEstopToggle(){
    static unsigned long last_toggle_ms = 0;
    if(millis() - last_toggle_ms < RESEND_DELAY)
        return;
    last_toggle_ms = millis();

    if(estop_toggled){
        estop_toggled = false;
        estop_clear_request = true;
    }
    else{
        estop_toggled = true;
        estop_clear_request = false;
    }
}

void toggleEstop(){
    estop_toggled = true;
}

void untoggleEstop(){
    estop_toggled = false;
}

void turnOnHeadlights(){
    turnOnHeadlight = true;
    turnOffLight = false;
    turnOnFoglight = false;
}
void turnOffLights(){
    turnOffLight = true;
    turnOnHeadlight = false;
    turnOnFoglight = false;
}
void turnOnFoglights(){
    turnOnFoglight = true;
    turnOffLight = false;
    turnOnHeadlight = false;
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



long_press_button b_arm_disarm = {
    BUTTON_ARM,
    0,
    nullptr,
    enableArm,
    0,
    0
};

/** Pin 3 e-stop: long-press toggles engage / disengage (short press ignored). */
long_press_button b_e_stop = {
    BUTTON_ESTOP,
    0,
    nullptr,
    latchEstopToggle,
    0,
    0
};

button b_mode_switch = {
        BUTTON_TORQUE_MODE,
        0,
        enableSwitchMode,
        0
    };


two_pos_toggle tt_speed_toggle = {
        TOGGLE_HIGH_SPEED,
        TOGGLE_LOW_SPEED,
        0,
        set_speed_low,
        set_speed_mid,
        set_speed_high
    },
    tt_light_toggle = {
        TOGGLE_FOGLIGHTS,
        TOGGLE_LIGHTS_OFF,
        0,
        turnOffLights,
        turnOnHeadlights,
        turnOnFoglights
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
    if(b1->press_state && b1->cooldown <= 0){
        if(b1->press_callback != nullptr)
            b1->press_callback();

        b1->cooldown = BUTTON_PRESS_COOLDOWN;
    }
    else if(b1->press_state){
        b1->cooldown = BUTTON_PRESS_COOLDOWN;
    }
    else{
        // if(b1->cooldown > 0){
        //     IF_DEBUG(Serial.println(b1->cooldown - ms_since_last_check));
        // }
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
    if(!(digitalRead(b1->pin)) && b1->cooldown > 0){
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

/** Logical light positions stored in tt_light_toggle.state (not raw pin indices). */
#define LIGHT_POS_OFF  0
#define LIGHT_POS_HEAD 1
#define LIGHT_POS_FOG  2

static uint8_t readLightTogglePosition(const struct two_pos_toggle *t1){
    if(!digitalRead(t1->pin_pos0))   /* pin 6 active → OFF → 0,0,0 */
        return LIGHT_POS_OFF;
    if(!digitalRead(t1->pin_pos2))   /* pin 8 active → FOG */
        return LIGHT_POS_FOG;
    return LIGHT_POS_HEAD;           /* centre, both HIGH → HEAD + REAR */
}

void updateLightToggleEdge(struct two_pos_toggle *t1, int32_t ms_since_last_check){
    (void)ms_since_last_check;

    const uint8_t new_state = readLightTogglePosition(t1);
    if(new_state == t1->state)
        return;

    t1->state = new_state;
    switch(new_state){
        case LIGHT_POS_OFF:
            turnOffLights();
            break;
        case LIGHT_POS_HEAD:
            turnOnHeadlights();
            break;
        case LIGHT_POS_FOG:
            turnOnFoglights();
            break;
    }
}



void checkUserInput()
{
    static bool light_toggle_synced = false;
    if(!light_toggle_synced){
        tt_light_toggle.state = readLightTogglePosition(&tt_light_toggle);
        light_toggle_synced = true;
    }

    // #ifdef TESTING_JOYSTICK
    // for(int i = 2; i < 8; i++){
    //     Serial.print(digitalRead(i));
    // }
    // Serial.println("");
    // #endif

    static unsigned long int last_input_checked_at = millis();

    int32_t ms_since_last_check = millis() - last_input_checked_at;
    updateLongPressButtonValues(&b_arm_disarm, ms_since_last_check);
    updateLongPressButtonValues(&b_e_stop, ms_since_last_check);
    updateButtonValues(&b_mode_switch, ms_since_last_check);
    updateTwoPosToggleValues(&tt_speed_toggle, ms_since_last_check);
    updateLightToggleEdge(&tt_light_toggle, ms_since_last_check);

    last_input_checked_at = millis();
}

uint8_t readHcBatterySoc()
{
#ifdef HC_BATTERY_ADC_PIN
    long sum = 0;
    for(int i = 0; i < FILTER_SAMPLES; i++){
        sum += analogRead(HC_BATTERY_ADC_PIN);
    }
    int raw = (int)(sum / FILTER_SAMPLES);

    IF_DEBUG(Serial.print("HC batt ADC raw=");)
    IF_DEBUG(Serial.println(raw);)

#if HC_BATT_NO_SENSE_RAW_MAX > 0
    /* Floating / unwired sense pin while USB-powered — show placeholder SoC for UI bring-up. */
    if(raw <= HC_BATT_NO_SENSE_RAW_MAX){
        return (uint8_t)HC_BATT_BENCH_SOC_WHEN_NO_SENSE;
    }
#endif

    int empty = HC_BATT_ADC_EMPTY;
    int full  = HC_BATT_ADC_FULL;
    if(full <= empty){
        return 0;
    }
    if(raw <= empty){
        return 0;
    }
    if(raw >= full){
        return 100;
    }
    return (uint8_t)(((long)(raw - empty) * 100L) / (full - empty));
#else
    return (uint8_t)HC_BATT_BENCH_SOC_WHEN_NO_SENSE;
#endif
}