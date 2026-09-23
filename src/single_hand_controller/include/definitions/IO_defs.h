/**
 * @file IO_defs.h
 * @version 0.5
 * @author Abhishek
 * @date 23/09/2026
 *
 * Teensy 4.1 HC pin map — matched to physical bring-up (“MASTER CONTROLLER TEST”).
 *
 * <h2>Changes</h2>
 * @date 23/09/2026
 * - Teensy pin map from verified hardware test sketch
 * - E-Stop: maintained latch (stays until moved up); NC logic HIGH = triggered
 * - RGB LEDs: common-anode (HIGH=off); Arm LED: active-HIGH
 * - Joystick 12-bit ADC on pins 14/15 (A0/A1)
 */
#pragma once
#include "Arduino.h"


/* LCD (unused when HC_NO_DISPLAY) */
#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5
#define TFT_SDI A2
#define TFT_CLK A7
#define TFT_LED A9
#define TFT_BRIGHTNESS 200


/* ========================================================================== */
/* Analog — joystick (12-bit via analogReadResolution(12))                    */
/* ========================================================================== */
#define JOY_X_PIN  14   /* A0 — Steering / Roll */
#define JOY_Y_PIN  15   /* A1 — Throttle / Pitch */
#define XPIN       JOY_X_PIN
#define YPIN       JOY_Y_PIN


/* ========================================================================== */
/* Digital inputs (INPUT_PULLUP)                                              */
/* ========================================================================== */
/**
 * E-Stop (pin 2) — maintained / latching switch (stays until operator moves it up).
 * NC wiring (verified on hardware): HIGH = open / TRIGGERED, LOW = closed / OK.
 */
#define ESTOP_PIN             2
#define BUTTON_ESTOP          ESTOP_PIN
#define ESTOP_TRIGGERED_LEVEL HIGH

#define ARM_BUTTON_PIN       28
#define BUTTON_ARM           ARM_BUTTON_PIN

/**
 * Momentary buttons (pressed = LOW). Same order as LED groups 1..5 in the
 * hardware test sketch.
 *   12 → LED1 (connectivity)   — headlights toggle
 *   24 → LED2 (HC battery)     — foglights toggle
 *   25 → LED3 (UGV status)     — rearlights toggle
 *   26 → LED4 (drive mode)     — drive mode switch
 *   27 → LED5 (speed limit)    — speed-limit cycle (hold 3 s)
 */
#define NUM_LED_BUTTONS       5
#define BUTTON_HEADLIGHTS    24
#define BUTTON_FOGLIGHTS     12
#define BUTTON_REARLIGHTS    25
#define BUTTON_DRIVE_MODE    27
#define BUTTON_SPEED_LIMIT   26
#define BUTTON_TORQUE_MODE   BUTTON_DRIVE_MODE


/* ========================================================================== */
/* Digital outputs — Arm LED + 5× RGB (common anode)                          */
/* ========================================================================== */
#define ARM_LED_PIN          18   /* active-HIGH: HIGH=ON, LOW=OFF */

#define NUM_RGB_LEDS          5

/* LED 1 — Connectivity link status */
#define RGB_1_R_PIN            3
#define RGB_1_G_PIN            4
#define RGB_1_B_PIN            5

/* LED 2 — Local HC battery status */
#define RGB_2_R_PIN            6
#define RGB_2_G_PIN            7
#define RGB_2_B_PIN            8

/* LED 3 — Vehicle (UGV) status */
#define RGB_3_R_PIN            9
#define RGB_3_G_PIN           10
#define RGB_3_B_PIN           29

/* LED 4 — Drive mode indicator */
#define RGB_4_R_PIN           36
#define RGB_4_G_PIN           37
#define RGB_4_B_PIN           38

/* LED 5 — Speed limit level indicator */
#define RGB_5_R_PIN           21
#define RGB_5_G_PIN           22
#define RGB_5_B_PIN           23

/** Common-anode RGB: HIGH = Off, LOW = On */
#define RGB_LED_OFF  HIGH
#define RGB_LED_ON   LOW

/** Arm status LED levels */
#define ARM_LED_ON   HIGH
#define ARM_LED_OFF  LOW

/**
 * Button pin list (index 0..4) — matches ledPins[][] below / hardware test.
 */
static const int HC_BUTTON_PINS[NUM_LED_BUTTONS] = {
    BUTTON_HEADLIGHTS,   
    BUTTON_FOGLIGHTS,    
    BUTTON_REARLIGHTS,   
    BUTTON_DRIVE_MODE,   
    BUTTON_SPEED_LIMIT   
};




/* Optional tactile / HC battery ADC — not on this Teensy revision */
// #define TACTILE_PIN <pin>
#define HC_BATTERY_ADC_PIN A6
#define HC_BATT_ADC_EMPTY  1205
#define HC_BATT_ADC_FULL   1783
#define HC_BATT_NO_SENSE_RAW_MAX  0
#define HC_BATT_BENCH_SOC_WHEN_NO_SENSE  85
// #define HC_BATT_STATUS_LED_PIN <pin>


/* Joystick: Teensy 12-bit samples scaled to 10-bit control math in getXY_raw() */
#define XY_NORMALIZED_MAX 4800
#define ANALOG_OUTPUT_MAX 1023
#define ANALOG_RAW_MAX_12BIT 4095
#define XY_UPPER_LIMIT 544
#define XY_LOWER_LIMIT 480
#define FILTER_SAMPLES 10
