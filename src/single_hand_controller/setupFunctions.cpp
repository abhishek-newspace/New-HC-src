/**
 * @file setupFunctions.cpp
 * @version 0.4
 * @author Abhishek
 * @date 23/09/2026
 * 
 * Part of set up functions library; used within the setup() function of single_hand_controller.ino.
 * Defines variables and functions used in setupFunctions.h.
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - configure HC_BATTERY_ADC_PIN and optional HC_BATT_STATUS_LED_PIN in setupIO()
 *
 * @date 21/08/2026
 * @author Abhishek
 * - setupDisplay(): backlight-gated startup (optional static NS logo, then main UI; no wipe animation)
 *
 * @date 22/09/2026
 * - setupDisplay() early-returns when HC_NO_DISPLAY (headless HC)
 *
 * @date 23/09/2026
 * - Teensy pin map: INPUT_PULLUP buttons, 12-bit ADC, Arm/RGB LED init (off)
 * - DEBUG_BUTTONS: USB Serial.begin for button bring-up logs
 */
#include "include/setupFunctions.h"


extern int drift_x, drift_y;

static void setupStatusLeds()
{
    pinMode(ARM_LED_PIN, OUTPUT);
    digitalWrite(ARM_LED_PIN, ARM_LED_OFF);

    for(int i = 0; i < NUM_RGB_LEDS; i++){
        for(int j = 0; j < 3; j++){
            pinMode(HC_LED_PINS[i][j], OUTPUT);
            digitalWrite(HC_LED_PINS[i][j], RGB_LED_OFF);  /* common anode */
        }
    }
}

void setupIO(){
#if defined(DEBUG_BUTTONS) || defined(_DEBUG_) || defined(HC_LINK_STATUS_LOG)
    /* USB Serial for Monitor logs — safe while MAVLink stays on Serial1 (UHF). */
    Serial.begin(BAUD_RATE);
    delay(200);
#endif
#ifdef DEBUG_BUTTONS
    Serial.println(F("HC Teensy IO — pin map from HW test (E-Stop NC: HIGH=triggered)"));
#endif
#ifdef HC_LINK_STATUS_LOG
    Serial.println(F("[HC] link log USB@115200 MAVLink=Serial1 (pins 0/1)"));
#endif

#if defined(__IMXRT1062__) || defined(__MK64FX512__) || defined(__MK66FX1M0__) || defined(__MK20DX256__)
    analogReadResolution(12);
#endif

    pinMode(ESTOP_PIN, INPUT_PULLUP);
    pinMode(ARM_BUTTON_PIN, INPUT_PULLUP);

    for(int i = 0; i < NUM_LED_BUTTONS; i++){
        pinMode(HC_BUTTON_PINS[i], INPUT_PULLUP);
    }

    pinMode(JOY_X_PIN, INPUT);
    pinMode(JOY_Y_PIN, INPUT);

    setupStatusLeds();

#ifdef HC_BATTERY_ADC_PIN
    pinMode(HC_BATTERY_ADC_PIN, INPUT);
#endif
#ifdef HC_BATT_STATUS_LED_PIN
    pinMode(HC_BATT_STATUS_LED_PIN, OUTPUT);
    digitalWrite(HC_BATT_STATUS_LED_PIN, LOW);
#endif
}

void initState()
{
    setUGV_state(disconnected);
}
bool identifyControllerDrift()
{
    thumbstickControl inputXY;
    getXY_raw(&inputXY);

    drift_x = inputXY.X;
    drift_y = inputXY.Y;

    if(drift_x > XY_UPPER_LIMIT || drift_x < XY_LOWER_LIMIT){
        IF_DEBUG(Serial.print("X : ");)
        IF_DEBUG(Serial.println(drift_x);)
        return false;
    }
    if(drift_y > XY_UPPER_LIMIT || drift_y < XY_LOWER_LIMIT){
        IF_DEBUG(Serial.print("Y : ");)
        IF_DEBUG(Serial.println(drift_y);)
        return false;
    }

    return true;
}

bool initMAVLink(){
    initiateSerialComm();
#ifdef RADIO_SIMULATION_TESTING
    // No local RFD in USB-rig mode — mark radio path as up so UI/link logic can proceed.
    connectRadio();
    IF_DEBUG(Serial.println("RADIO_SIMULATION_TESTING: MAVLink on USB Serial @ 115200");)
#endif
    return setupSigning();
}

void setupDisplay(){
#ifdef HC_NO_DISPLAY
    /* Headless HC: no TFT present — skip init so display pins are never driven. */
    return;
#endif
    initDisplayComm();

    // Paint off-screen (BL off) so soft-SPI wipe is never visible — same for USB or radio builds.
    setDisplayBacklight(false);
#ifdef ENABLE_STARTUP_LOGO
    showStartupLogo();
#else
    clear_display();
#endif
    setFont1();
    displayDriveMode(speed);
    displayBasic();
    setDisplayBacklight(true);
}
