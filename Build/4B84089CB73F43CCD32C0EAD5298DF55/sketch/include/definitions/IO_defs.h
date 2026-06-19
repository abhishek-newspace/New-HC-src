#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/definitions/IO_defs.h"
/**
 * @file IO_defs.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 20/05/2026
 * 
 * Input and output pins, and other I/O related definitions
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
