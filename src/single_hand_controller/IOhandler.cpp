/**
 * @file IOhandler.cpp
 * @version 0.4
 * @author Abhishek
 * @date 23/09/2026
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
 *
 * @date 17/07/2026
 * @author Abhishek
 * - fixed updateLongPressButtonValues(): hold timer no longer gated by cooldown
 *   (cooldown only after release) so LONG_PRESS_DURATION (~500 ms) is respected
 *
 * @date 29/07/2026
 * @author Abhishek
 * - swapped controls: pins 4/5 toggle = e-stop (engage / disengage / centre N/A)
 * - pin 3 momentary = drive-limit cycle Low→Mid→High→Low (one-shot TX via speed_limit_press)
 *
 * @date 30/07/2026
 * @author Abhishek
 * - cycleSpeedLimit() sets speed_limit_press for single OFP send (not continuous)
 *
 * @date 08/09/2026
 * - pin 3 speed-limit: 3 s continuous hold (SPEED_LIMIT_HOLD_MS) before cycle fires
 *
 * @date 23/09/2026
 * @author Abhishek
 * - Teensy pin map: single e-stop, independent light toggles, drive/speed/arm buttons
 * - DEBUG_BUTTONS: Serial edge logs for all digital inputs
 * - joystick: 12-bit ADC samples downscaled >>2 for existing 10-bit control math
 */
#include "include/IOhandler.hpp"


extern bool turnOnHeadlight;
extern bool turnOnFoglight;
extern bool turnOnRearlight;
extern bool turnOffLight;
extern bool light_cmd_pending;
extern int required_speed;
extern bool speed_limit_press;
extern bool switchMode;
extern bool arm_press;
extern bool disarm_press;
extern bool estop_toggled;
extern bool estop_clear_request;

/** Local light latch state (independent toggles on Teensy HC). */
static bool light_head_on = false;
static bool light_fog_on  = false;
static bool light_rear_on = false;

void engageEstop(){
    estop_toggled = true;
    estop_clear_request = false;
    IF_DEBUG_BUTTONS(Serial.println(F("[BTN] E-Stop ENGAGE request"));)
}

void disengageEstop(){
    estop_toggled = false;
    estop_clear_request = true;
    IF_DEBUG_BUTTONS(Serial.println(F("[BTN] E-Stop DISENGAGE request"));)
}

void toggleEstop(){
    engageEstop();
}

void untoggleEstop(){
    estop_toggled = false;
}

static void requestLightSend(){
    turnOnHeadlight = light_head_on;
    turnOnFoglight  = light_fog_on;
    turnOnRearlight = light_rear_on;
    turnOffLight = !(light_head_on || light_fog_on || light_rear_on);
    light_cmd_pending = true;
}

void toggleHeadlights(){
    light_head_on = !light_head_on;
    requestLightSend();
    IF_DEBUG_BUTTONS(Serial.print(F("[BTN] Headlights -> "));)
    IF_DEBUG_BUTTONS(Serial.println(light_head_on ? F("ON") : F("OFF"));)
}

void toggleFoglights(){
    light_fog_on = !light_fog_on;
    requestLightSend();
    IF_DEBUG_BUTTONS(Serial.print(F("[BTN] Foglights -> "));)
    IF_DEBUG_BUTTONS(Serial.println(light_fog_on ? F("ON") : F("OFF"));)
}

void toggleRearlights(){
    light_rear_on = !light_rear_on;
    requestLightSend();
    IF_DEBUG_BUTTONS(Serial.print(F("[BTN] Rearlights -> "));)
    IF_DEBUG_BUTTONS(Serial.println(light_rear_on ? F("ON") : F("OFF"));)
}

/* Legacy helpers (kept for older packet paths). */
void turnOnHeadlights(){
    light_head_on = true;
    light_fog_on = false;
    light_rear_on = true;
    requestLightSend();
}
void turnOffLights(){
    light_head_on = false;
    light_fog_on = false;
    light_rear_on = false;
    requestLightSend();
}
void turnOnFoglights(){
    light_fog_on = true;
    light_head_on = false;
    light_rear_on = false;
    requestLightSend();
}

void enableSwitchMode(){
    switchMode = true;
    IF_DEBUG_BUTTONS(Serial.println(F("[BTN] Drive mode switch pressed"));)
}

void enableArm(){
    static long unsigned last_assigned_at = 0;
    if(millis() - last_assigned_at > RESEND_DELAY){
        arm_press = true;
        last_assigned_at = millis();
        IF_DEBUG_BUTTONS(Serial.println(F("[BTN] Arm HOLD -> ARM request"));)
    }
}

void enableDisarm(){
    static long unsigned last_assigned_at = 0;
    if(millis() - last_assigned_at > RESEND_DELAY){
        disarm_press = true;
        last_assigned_at = millis();
        IF_DEBUG_BUTTONS(Serial.println(F("[BTN] Arm TAP -> DISARM request"));)
    }
}

/**
 * Speed-limit button: after SPEED_LIMIT_HOLD_MS continuous hold → send next limit
 * relative to UGV HEARTBEAT status (not last TX): Low→Mid, Mid→High, High→Low.
 * Unknown → Low. Release before hold completes: no TX.
 */
void cycleSpeedLimit(){
    const int current = (int)getUGV_speed();
    if(current < 1 || current > 3)
        required_speed = 1;
    else
        required_speed = (current % 3) + 1;
    speed_limit_press = true;
    IF_DEBUG_BUTTONS(Serial.print(F("[BTN] Speed limit HOLD -> level "));)
    IF_DEBUG_BUTTONS(Serial.println(required_speed);)
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


/** Hold to Arm / Tap to Disarm (pin 28). */
long_press_button b_arm_disarm = {
    BUTTON_ARM,
    0,
    enableDisarm,      /* short press / tap */
    enableArm,         /* long press / hold */
    0,
    0,
    LONG_PRESS_DURATION
};

/** Pin 27: hold SPEED_LIMIT_HOLD_MS (3 s) to cycle speed limit Low→Mid→High. */
long_press_button b_speed_limit = {
    BUTTON_SPEED_LIMIT,
    0,
    nullptr,           /* short press: ignore */
    cycleSpeedLimit,   /* long press only */
    0,
    0,
    SPEED_LIMIT_HOLD_MS
};

button b_mode_switch = {
        BUTTON_DRIVE_MODE,
        0,
        enableSwitchMode,
        0
    };

button b_headlights = {
        BUTTON_HEADLIGHTS,
        0,
        toggleHeadlights,
        0
    };

button b_foglights = {
        BUTTON_FOGLIGHTS,
        0,
        toggleFoglights,
        0
    };

button b_rearlights = {
        BUTTON_REARLIGHTS,
        0,
        toggleRearlights,
        0
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

    float xsum = 0, ysum = 0;

    for(int i = 0; i < FILTER_SAMPLES; i++){
        xsum += analogRead(XPIN);
        ysum += analogRead(YPIN);
    }
#if defined(__IMXRT1062__) || defined(__MK64FX512__) || defined(__MK66FX1M0__) || defined(__MK20DX256__)
    /* Teensy 12-bit → historical 10-bit scale used by deadband / normalize math */
    control->X = (xsum / FILTER_SAMPLES) * (1023.0f / (float)ANALOG_RAW_MAX_12BIT);
    control->Y = (ysum / FILTER_SAMPLES) * (1023.0f / (float)ANALOG_RAW_MAX_12BIT);
#else
    control->X = xsum / FILTER_SAMPLES;
    control->Y = ysum / FILTER_SAMPLES;
#endif
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
        b1->cooldown = max(0, b1->cooldown - ms_since_last_check);
        b1->press_state = 0;
    }
}

/**
 * update the struct values for a long press button.
 * Hold timer uses b1->long_press_ms (e.g. LONG_PRESS_DURATION / SPEED_LIMIT_HOLD_MS).
 * Cooldown only blocks a new press after release — it must not gate pressed_for
 * accumulation.
 */
void updateLongPressButtonValues(struct long_press_button *b1, int32_t ms_since_last_check){
    b1->cooldown = max(0, b1->cooldown - ms_since_last_check);
    const bool pressed = !digitalRead(b1->pin);
    const uint32_t hold_ms =
        (b1->long_press_ms != 0) ? b1->long_press_ms : (uint32_t)LONG_PRESS_DURATION;

    if(pressed){
        if(b1->cooldown > 0 && b1->press_state == not_pressed){
            return;
        }

        if(b1->press_state == not_pressed){
            b1->press_state = short_pressed;
            b1->pressed_for = 0;
        }
        else if(b1->press_state == short_pressed){
            b1->pressed_for += ms_since_last_check;
            if(b1->pressed_for >= hold_ms){
                b1->press_state = long_pressed;
                if(b1->long_press_callback != nullptr)
                    b1->long_press_callback();
            }
        }
        /* long_pressed: hold until release; do not re-fire */
    }
    else{
        if(b1->press_state == short_pressed){
            if(b1->short_press_callback != nullptr)
                b1->short_press_callback();
        }
        if(b1->press_state != not_pressed)
            b1->cooldown = BUTTON_PRESS_COOLDOWN;
        b1->press_state = not_pressed;
        b1->pressed_for = 0;
    }
}

void updateToggleValues(struct toggle *t1, int32_t ms_since_last_check){
    (void)ms_since_last_check;
    if(!digitalRead(t1->pin)){
        t1->state = 1;
        t1->pos_1_callback();
    }
    else{
        t1->state = 0;
        t1->pos_0_callback();
    }
}

void updateTwoPosToggleValues(struct two_pos_toggle *t1, int32_t ms_since_last_check){
    (void)ms_since_last_check;
    if(!digitalRead(t1->pin_pos0)){
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

/**
 * E-Stop (pin 2) — maintained latch (stays until moved up).
 * NC logic (HW test): HIGH = TRIGGERED / engage, LOW = OK / disengage.
 * Edge-triggered TX requests; boot position synced without firing.
 */
void updateEstopSwitchEdge(int32_t ms_since_last_check){
    (void)ms_since_last_check;
    static bool synced = false;
    static uint8_t last_raw = LOW;  /* closed / OK when pull-up + NC closed */

    const uint8_t raw = digitalRead(ESTOP_PIN) ? HIGH : LOW;
    const bool triggered = (raw == ESTOP_TRIGGERED_LEVEL);

    if(!synced){
        last_raw = raw;
        synced = true;
        IF_DEBUG_BUTTONS(
            Serial.print(F("[BTN] E-Stop boot: "));
            Serial.println(triggered ? F("TRIGGERED (HIGH)") : F("OK (LOW)"));
        )
        return;
    }

    if(raw == last_raw)
        return;

    last_raw = raw;
    if(triggered)
        engageEstop();
    else
        disengageEstop();
}

/** Legacy stubs — 3-pos light/e-stop toggles removed on Teensy HC. */
void updateLightToggleEdge(struct two_pos_toggle *t1, int32_t ms_since_last_check){
    (void)t1;
    (void)ms_since_last_check;
}

void updateEstopToggleEdge(struct two_pos_toggle *t1, int32_t ms_since_last_check){
    (void)t1;
    updateEstopSwitchEdge(ms_since_last_check);
}

#ifdef DEBUG_BUTTONS
/** Print every digital input HIGH/LOW each poll (~50 ms so Serial stays readable). */
static void debugPrintAllButtonStates(){
    static unsigned long last_print_ms = 0;
    if(millis() - last_print_ms < 50)
        return;
    last_print_ms = millis();

    Serial.print(F("[IO] ESTOP(2)="));
    Serial.print(digitalRead(ESTOP_PIN) ? F("HIGH") : F("LOW"));
    Serial.print(F(" ARM(28)="));
    Serial.print(digitalRead(ARM_BUTTON_PIN) ? F("HIGH") : F("LOW"));
    Serial.print(F(" HEAD(12)="));
    Serial.print(digitalRead(BUTTON_HEADLIGHTS) ? F("HIGH") : F("LOW"));
    Serial.print(F(" FOG(24)="));
    Serial.print(digitalRead(BUTTON_FOGLIGHTS) ? F("HIGH") : F("LOW"));
    Serial.print(F(" REAR(25)="));
    Serial.print(digitalRead(BUTTON_REARLIGHTS) ? F("HIGH") : F("LOW"));
    Serial.print(F(" DRIVE(26)="));
    Serial.print(digitalRead(BUTTON_DRIVE_MODE) ? F("HIGH") : F("LOW"));
    Serial.print(F(" SPEED(27)="));
    Serial.println(digitalRead(BUTTON_SPEED_LIMIT) ? F("HIGH") : F("LOW"));
}

/** Raw pin edge dump so you can confirm wiring even if callbacks do not fire. */
static void debugLogRawInputEdges(){
    static bool init = false;
    static uint8_t prev_estop = 0;
    static uint8_t prev_arm = 0;
    static uint8_t prev_btns[NUM_LED_BUTTONS];

    const uint8_t estop = digitalRead(ESTOP_PIN) ? 1 : 0;
    const uint8_t arm = digitalRead(ARM_BUTTON_PIN) ? 1 : 0;

    if(!init){
        prev_estop = estop;
        prev_arm = arm;
        for(int i = 0; i < NUM_LED_BUTTONS; i++)
            prev_btns[i] = digitalRead(HC_BUTTON_PINS[i]) ? 1 : 0;
        init = true;
        return;
    }

    if(estop != prev_estop){
        Serial.print(F("[PIN] E-Stop pin 2 -> "));
        Serial.println(estop ? F("HIGH (TRIGGERED)") : F("LOW (OK)"));
        prev_estop = estop;
    }
    if(arm != prev_arm){
        Serial.print(F("[PIN] Arm/Disarm pin 28 -> "));
        Serial.println(arm ? F("HIGH (released)") : F("LOW (pressed)"));
        prev_arm = arm;
    }

    const char* names[NUM_LED_BUTTONS] = {
        "Headlights/LED1", "Foglights/LED2", "Rearlights/LED3",
        "DriveMode/LED4", "SpeedLimit/LED5"
    };
    for(int i = 0; i < NUM_LED_BUTTONS; i++){
        const uint8_t now = digitalRead(HC_BUTTON_PINS[i]) ? 1 : 0;
        if(now != prev_btns[i]){
            Serial.print(F("[PIN] "));
            Serial.print(names[i]);
            Serial.print(F(" pin "));
            Serial.print(HC_BUTTON_PINS[i]);
            Serial.print(F(" -> "));
            Serial.println(now ? F("HIGH (released)") : F("LOW (pressed)"));
            prev_btns[i] = now;
        }
    }
}
#endif

void checkUserInput()
{
    static unsigned long int last_input_checked_at = millis();

    int32_t ms_since_last_check = (int32_t)(millis() - last_input_checked_at);

    IF_DEBUG_BUTTONS(debugPrintAllButtonStates();)
    IF_DEBUG_BUTTONS(debugLogRawInputEdges();)

    updateLongPressButtonValues(&b_arm_disarm, ms_since_last_check);
    updateLongPressButtonValues(&b_speed_limit, ms_since_last_check);
    updateButtonValues(&b_mode_switch, ms_since_last_check);
    updateButtonValues(&b_headlights, ms_since_last_check);
    updateButtonValues(&b_foglights, ms_since_last_check);
    updateButtonValues(&b_rearlights, ms_since_last_check);
    updateEstopSwitchEdge(ms_since_last_check);

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
