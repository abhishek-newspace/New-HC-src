/**
 * @file IOhandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * Any interfacing with input/output pins of the microcontroller is taken care of, within this header file, except handling display output, which is done by the displayHandler
 */
#pragma once
#include "definitions.h"
#include "mavlink/common/mavlink.h"

#define SPEED_HIGH
#define SPEED_MID

#define DIR_FORWARD
#define DIR_REVERSE

/// @brief thumbstick control is used within this library
struct thumbstickControl{
    int X, Y;
};

//! update user input 
void checkUserInput();

/// @brief get thumbstick's raw position (0 to 1023)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY_raw(struct thumbstickControl *control);

/// @brief get thumbstick's normalized position (-100 to 100)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY(struct thumbstickControl *control);


// struct holds current state of button
IF_PROTOTYPE(
    struct buttons{
        uint8_t increaseSpeed = 0;
        uint8_t decreaseSpeed = 0;
        uint8_t neutral = 0;
        uint8_t arm_disarm = 0;
        uint8_t arm_disarm_long = 0;

        uint32_t arm_disarm_press_duration = 0;

        uint8_t toggle_forward = 0;
        uint8_t toggle_reverse = 0;
    };
) // IF_PROTOTYPE