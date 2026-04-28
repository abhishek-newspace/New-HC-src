/**
 * @file setupFunctions.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * @brief Defines all functions required during setup phase of hand controller
 */
#pragma once
#include "mavlink/common/mavlink.h"
#include "definitions.h"
#include "displayHandler.hpp"
#include "IOhandler.hpp"
#include "stateHandler.hpp"
#include "packetHandler.h"



/// @brief set up microcontroller for all input and output
void setupIO();

/// @brief set initial values for states
void initState();


/// @brief set up the LCD display (clearing the screen, and displaying necessary startup items)
void setupDisplay();

/// @brief obtain the deviation of the thumbstick's neutral position from its expected central position
/// @return true when the deviation is within permissible limits.
bool identifyControllerDrift();

/// @brief set a default UGV state
/// @param s1 enum value indicating the current UGV state.
void initUGV_state(ugv_status s1);

/// @brief initialize variables required for signing and sending MAVLink packets
/// @return true when initialization is done correctly, false in case of a nullpointer error.
bool initMAVLink();