/**
 * @file IO_defs.h
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
 * 
 * Input and output pins, and other I/O related definitions
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - HC_BATTERY_ADC_PIN (A6) and EMPTY/FULL ADC calibration for SRS §3.2.3.3
 * - optional TACTILE_PIN / HC_BATT_STATUS_LED_PIN hooks
 * - bench no-sense placeholder (HC_BATT_NO_SENSE_RAW_MAX; 0 = disabled)
 */
#pragma once
#include "Arduino.h"


// LCD Pin configurations
#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A7  // SCK
#define TFT_LED A9   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)


// Thumbstick control
#define XPIN A0
#define YPIN A1

#define TOGGLE_HIGH_SPEED 4
#define TOGGLE_LOW_SPEED 5
#define BUTTON_HEADLIGHTS 3
#define BUTTON_FOGLIGHTS 2
#define BUTTON_TORQUE_MODE 7
#define TOGGLE_ARM 6
#define TOGGLE_ESTOP 8

/**
 * Optional tactile / haptic pin for SRS §3.2.4 (UGV low-battery alert).
 * This remote revision does not wire a buzzer/vibrator — leave undefined.
 * When hardware is available, define e.g. `#define TACTILE_PIN 9` and wire OUTPUT.
 */
// #define TACTILE_PIN <pin>

/**
 * SRS §3.2.3.3 — HC pack voltage sense (local UI only; never sent on MAVLink).
 * Wire pack (via divider) to this ADC. Calibrate EMPTY/FULL raw counts for 0%/100%.
 * A6 is free of joystick (A0/A1) and TFT (A2–A5, A7, A9) on the current board map.
 *
 * USB power alone does NOT feed A6 — without a divider the pin floats near 0 and
 * SoC would read empty. Bench mode below shows ~full when no sense voltage is present.
 */
#define HC_BATTERY_ADC_PIN A6
/** Raw ADC (~0–1023 @ 5 V AREF) at empty / full after the divider. Tune on hardware. */
#define HC_BATT_ADC_EMPTY  0
#define HC_BATT_ADC_FULL   1023
/**
 * If average ADC is below this, treat as “no sense HW / floating pin” and show a
 * bench placeholder SoC so the HC gauge is visible while powered from USB only.
 * When a real divider is wired, raise EMPTY/FULL and set this to 0 to disable.
 */
/** Set to 0 to always use ADC mapping (no USB bench placeholder). */
#define HC_BATT_NO_SENSE_RAW_MAX  0
#define HC_BATT_BENCH_SOC_WHEN_NO_SENSE  85

/**
 * Optional discrete status LED pin (HIGH=on). If undefined, status is drawn on the TFT
 * as a coloured block (same approach as the connectivity LED).
 */
// #define HC_BATT_STATUS_LED_PIN <pin>


// used in IOhandler to convert from raw thumbstick control input to normalized value that is sent to atlas
#define XY_NORMALIZED_MAX 4800
#define ANALOG_OUTPUT_MAX 1023

/**
 * 512 is the midpoint of 0 to 1023 hence, 50 units towards either side is allowed
 */
#define XY_UPPER_LIMIT 544 // 512 + 32 = 544
#define XY_LOWER_LIMIT 480 // 512 - 32 = 480


// number of samples to be considered for filtering any analog signal taken from analog input
#define FILTER_SAMPLES 10
