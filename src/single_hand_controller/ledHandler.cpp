#include "include/ledHandler.hpp"
#include "include/displayHandler.hpp" // Includes function declarations for connectRadio, setRSSI, etc.

extern bool radioConnected;
extern bool timesync_received;
extern uint8_t ugv_battery_soc;
extern int16_t RSSI;
extern uint16_t remRSSI;

// Pin Mapping Array {RED, GREEN, BLUE} for each LED
static const uint8_t rgbPins[NUM_RGB_LEDS][3] = {
    {RGB_1_R_PIN, RGB_1_G_PIN, RGB_1_B_PIN},
    {RGB_2_R_PIN, RGB_2_G_PIN, RGB_2_B_PIN},
    {RGB_3_R_PIN, RGB_3_G_PIN, RGB_3_B_PIN},
    {RGB_4_R_PIN, RGB_4_G_PIN, RGB_4_B_PIN},
    {RGB_5_R_PIN, RGB_5_G_PIN, RGB_5_B_PIN}
};

void setupLEDs() {
#ifdef ARM_LED_PIN
    pinMode(ARM_LED_PIN, OUTPUT);
    digitalWrite(ARM_LED_PIN, LOW);
#endif

    // Common Anode setup: HIGH = OFF
    for (int i = 0; i < NUM_RGB_LEDS; i++) {
        for (int j = 0; j < 3; j++) {
            pinMode(rgbPins[i][j], OUTPUT);
            digitalWrite(rgbPins[i][j], HIGH);
        }
    }
}

void setArmLED(bool state) {
#ifdef ARM_LED_PIN
    digitalWrite(ARM_LED_PIN, state ? HIGH : LOW);
#endif
}

void setRGBColor(uint8_t ledIndex, RGBColor color) {
    if (ledIndex >= NUM_RGB_LEDS) return;

    // Common Anode Logic: LOW = ON, HIGH = OFF
    switch (color) {
        case COLOR_RED:
            digitalWrite(rgbPins[ledIndex][0], LOW);
            digitalWrite(rgbPins[ledIndex][1], HIGH);
            digitalWrite(rgbPins[ledIndex][2], HIGH);
            break;
        case COLOR_GREEN:
            digitalWrite(rgbPins[ledIndex][0], HIGH);
            digitalWrite(rgbPins[ledIndex][1], LOW);
            digitalWrite(rgbPins[ledIndex][2], HIGH);
            break;
        case COLOR_BLUE:
            digitalWrite(rgbPins[ledIndex][0], HIGH);
            digitalWrite(rgbPins[ledIndex][1], HIGH);
            digitalWrite(rgbPins[ledIndex][2], LOW);
            break;
        case COLOR_CYAN:
            digitalWrite(rgbPins[ledIndex][0], HIGH);
            digitalWrite(rgbPins[ledIndex][1], LOW);
            digitalWrite(rgbPins[ledIndex][2], LOW);
            break;
        case COLOR_OFF:
        default:
            digitalWrite(rgbPins[ledIndex][0], HIGH);
            digitalWrite(rgbPins[ledIndex][1], HIGH);
            digitalWrite(rgbPins[ledIndex][2], HIGH);
            break;
    }
}


void updateLEDs() {
#ifdef DEBUG_BUTTONS
    // =========================================================================
    // HARDCODED DEBUG MODE: Mirror button states directly to LEDs for testing
    // =========================================================================

    // 0. ARM Button (Pin 28) -> Arm Status LED (Pin 18)
    // Momentary LOW when pressed (INPUT_PULLUP)
    bool armPressed = !digitalRead(ARM_BUTTON_PIN);
    setArmLED(armPressed);

    // 1. Headlights Button -> LED 1 (Connectivity group)
    // Red when pressed, Off when released
    if (!digitalRead(BUTTON_HEADLIGHTS)) {
        setRGBColor(0, COLOR_RED);
    } else {
        setRGBColor(0, COLOR_OFF);
    }

    // 2. Foglights Button -> LED 2 (HC Battery group)
    // Green when pressed, Off when released
    if (!digitalRead(BUTTON_FOGLIGHTS)) {
        setRGBColor(1, COLOR_GREEN);
    } else {
        setRGBColor(1, COLOR_OFF);
    }

    // 3. Rearlights Button -> LED 3 (UGV Status group)
    // Blue when pressed, Off when released
    if (!digitalRead(BUTTON_REARLIGHTS)) {
        setRGBColor(2, COLOR_BLUE);
    } else {
        setRGBColor(2, COLOR_OFF);
    }

    // 4. Drive Mode Button -> LED 4 (Drive Mode group)
    // Cyan when pressed, Off when released
    if (!digitalRead(BUTTON_DRIVE_MODE)) {
        setRGBColor(3, COLOR_CYAN);
    } else {
        setRGBColor(3, COLOR_OFF);
    }

    // 5. Speed Limit Button -> LED 5 (Speed Limit group)
    // White when pressed, Off when released
    if (!digitalRead(BUTTON_SPEED_LIMIT)) {
        setRGBColor(4, COLOR_CYAN);
    } else {
        setRGBColor(4, COLOR_OFF);
    }

#else
    // =========================================================================
    // PRODUCTION MODE: Standard telemetry & state handling
    // =========================================================================

    // 0. ARM Status
    ugv_status ugv_state = getUGV_state();
    setArmLED(ugv_state == active);

    // 1. Connectivity LED (LED 1)
    if (get_conn_stat() == all_disconnected || !radioConnected) {
        setRGBColor(0, COLOR_RED);
    } else {
        setRGBColor(0, COLOR_GREEN);
    }

    // 2. Hand Controller Battery LED (LED 2)
    uint8_t hc_soc = readHcBatterySoc();
    if (hc_soc > 50) setRGBColor(1, COLOR_GREEN);
    else if (hc_soc > 20) setRGBColor(1, COLOR_CYAN);
    else setRGBColor(1, COLOR_RED);

    // 3. UGV Status LED (LED 3)
    switch (ugv_state) {
        case active: setRGBColor(2, COLOR_GREEN); break;
        case standby: setRGBColor(2, COLOR_CYAN); break;
        default: setRGBColor(2, COLOR_RED); break;
    }

    // 4. Drive Mode LED (LED 4 - Green, Blue, Cyan)
    int mode = getDriveMode();
    if (mode == 0) setRGBColor(3, COLOR_GREEN);
    else if (mode == 1) setRGBColor(3, COLOR_BLUE);
    else setRGBColor(3, COLOR_CYAN);

    // 5. Speed Limit LED (LED 5)
    speedToggle speed = getUGV_speed();
    if (speed == 1) setRGBColor(4, COLOR_GREEN);
    else if (speed == 2) setRGBColor(4, COLOR_BLUE);
    else setRGBColor(4, COLOR_RED);
#endif
}