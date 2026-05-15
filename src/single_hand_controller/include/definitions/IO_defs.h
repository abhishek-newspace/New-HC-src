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

// Button input pins
#define BUTTON_NEUTRAL 2
#define BUTTON_INC_SPEED 3
#define BUTTON_DEC_SPEED 5
#define BUTTON_ARM_DISARM 4

// toggle input pins
#define TOGGLE_FORWARD 7
#define TOGGLE_REVERSE 10



// used in IOhandler to convert from raw thumbstick control input to normalized value that is sent to atlas
#define XY_NORMALIZED_MAX 100
#define ANALOG_OUTPUT_MAX 1023

/**
 * 512 is the midpoint of 0 to 1023 hence, 50 units towards either side is allowed
 */
#define XY_UPPER_LIMIT 562 // 512 + 50 = 562
#define XY_LOWER_LIMIT 462 // 512 - 50 = 462


// number of samples to be considered for filtering any analog signal taken from analog input
#define FILTER_SAMPLES 10
