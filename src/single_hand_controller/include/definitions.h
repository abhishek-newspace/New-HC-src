/**
 * @file definitions.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * All definitions, used within every header file is included here. 
 */
#pragma once
#include "Arduino.h"

/// @brief signing key used to sign packets [meant to be changed on deployment]
unsigned char const signing_key[32] = {0x2d,0x3d,0x67,0xb6,0xa9,0x92,0x1b,0x1a,0xb0,0x93,0x11,0x73,0xe2,0xda,0x1c,0xee,0x26,0x3,0x53,0x39,0x23,0xb4,0x58,0x19,0xe4,0xa6,0x9c,0x92,0x5b,0x45,0x96,0x45};

// MAVLink system ID, and Component ID for scout
#define SCOUT_ID 1
#define ATLAS_COMP_ID 191

// MAVLink system ID, and Component ID for single hand controller
#define HC_ID 2
#define HC_COMP_ID 1

// unique identifier placed within heartbeat packets sent from scout, used to identify scout.
#define SCOUT_HEARTBEAT_IDENTIFIER 1191


/**
 * naming convention ->
 * SECONDS => seconds
 * US => microseconds
 * MS => milliseconds
 * 
 * SECONDS_US_count => conversion of count seconds to microseconds
 * SECONDS_MS_count => conversion of count seconds to milliseconds
 * MS_count => count milliseconds
 */
#define SECONDS_US_10 10000000 /// 10 seconds to microseconds
#define SECONDS_US_3 3000000 /// 3 seconds to microseconds
#define SECONDS_US_2 2000000 /// 2 seconds to microseconds
#define SECONDS_US_1 1000000 /// 1 seconds to microseconds

#define SECONDS_MS_10 10000 /// 10 seconds to milliseconds
#define SECONDS_MS_3 3000 /// 3 seconds to milliseconds
#define SECONDS_MS_2 2000 /// 2 seconds to milliseconds
#define SECONDS_MS_1 1000 /// 1 seconds to milliseconds

#define MS_200 200  // 200 milliseconds
#define MS_20 20    // 20 milliseconds
#define MS_10 10    // 10 milliseconds





// all durations to be defined in microseconds
#define HEARTBEAT_TIMEOUT       SECONDS_MS_3   // left to be in milliseconds due to limitation of micros() function that resets every 70 minutes 
#define TIMESYNC_MSG_WAIT       SECONDS_MS_10  // left to be in milliseconds due to limitation of micros() function that resets every 70 minutes 
#define MANUAL_CONTROL_MSG_WAIT MS_10

#define OFP_LOOP_TIME           MS_20 

#define LONG_PRESS_DURATION     SECONDS_MS_2
#define BUTTON_PRESS_COOLDOWN   MS_200
#define TOGGLE_DEBOUNCE_DURATION SECONDS_US_1

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

// can be used when invoking an arm_disarm command long message
#define STATE_DISARM 0
#define STATE_ARM 1

/// @brief current UGV status
enum ugv_status{
    disconnected, 
    active, 
    standby, 
    unknown};

/// @brief directions within hand controller
enum directionToggle{
    neutral,
    forward,
    reverse
};

/// @brief  speeds within hand controller.
enum speedToggle{
    low,
    mid,
    high
};

/// @brief button press state
enum buttonPress{
    not_pressed = 0,
    short_pressed = 1,
    long_pressed = 3
};

// baud rates; used in setupFunctions.h
#define BAUD_RATE 115200
#define LCD_DISPLAY_BAUD_RATE 9600

// if the code is not meant to be deployed on the prototype hand controller, then comment out this line
#define PROTOTYPE

// if the code is not meant to operate in debug mode (prints out info on serial communication), comment out this line
#define _DEBUG_

// ONLY use this when testing features
#define TESTING

#define TIME_REQ


#ifdef TESTING
#define IF_TESTING(CODE) CODE
#else
#define IF_TESTING(CODE)
#endif

#ifdef PROTOTYPE
#define IF_PROTOTYPE(CODE) CODE
#else
#define IF_PROTOTYPE(CODE)
#endif


#ifdef _DEBUG_
#define DEBUG(CODE) CODE
#define IF_DEBUG(CODE) CODE
#else
#define DEBUG(CODE)
#define IF_DEBUG(CODE)
#endif

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
