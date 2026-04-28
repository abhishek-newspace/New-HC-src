/**
 * @file IOhandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * Any interfacing with input/output pins of the microcontroller is taken care of, within this header file, except handling display output, which is done by the displayHandler
 * 
 * <h2>Changes</h2>
 * @date 28/04/2026
 * - Modified struct to inclued cooldown period, so that when the button is pressed and released, the next press is only registered after the cooldown period
 * - modified struct to include callback functions to increase, decrease and set speed to neutral
 */
#pragma once
#include "definitions.h"
#include "mavlink/common/mavlink.h"
#include "stateHandler.hpp"

#define SPEED_HIGH
#define SPEED_MID

#define DIR_FORWARD
#define DIR_REVERSE

/// @brief thumbstick control is used within this library
struct thumbstickControl{
    int X, Y;
};

/**
 * @brief update user input struct
 * @details user input struct is defined in IOhandler.cpp. declare it in the file where it is required as `extern struct buttons user_input` and access the variables in it to obtain updated user input
 */
void checkUserInput();

/// @brief get thumbstick's raw position (0 to 1023)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY_raw(struct thumbstickControl *control);

/// @brief get thumbstick's normalized position (-100 to 100)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY(struct thumbstickControl *control);

/// @brief whether arm/disarm button is pressed or not
/// @return true when arm/disarm button is pressed
bool arm_pressed();

// struct holds current state of button
IF_PROTOTYPE(
    struct buttons{
        uint8_t increaseSpeed = 0;
        uint8_t decreaseSpeed = 0;
        uint8_t neutral = 0;
        uint8_t arm_disarm = 0;
        uint8_t arm_disarm_long = 0;
        
        int32_t increaseSpeed_cooldown = 0;
        int32_t decreaseSpeed_cooldown = 0;
        int32_t neutral_cooldown = 0;
        int32_t arm_disarm_cooldown = 0;

        uint32_t arm_disarm_press_duration = 0;
        
        void (*neutral_callback)(void) = setNeutral;
        void (*increaseSpeed_callback)(void) = inc_Speed;
        void (*decreaseSpeed_callback)(void) = dec_Speed;

        uint8_t toggle_forward = 0;
        uint8_t toggle_reverse = 0;
    };
) // IF_PROTOTYPE