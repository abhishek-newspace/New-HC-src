/**
 * @file stateHandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Handling of states within the hand controller is performed within the stateHandler.
 * 
 * currently handles states for ugv state, and speed
 */
#pragma once
#include"displayHandler.hpp"
#include "definitions.h"

/**
 * set the current UGV state. 
 * \returns true when current UGV state is updated to a new value.
 * \returns false when current UGV state is same as previous
 */
bool setUGV_state(ugv_status s1);

/// @brief used only within prototype version, to increase speed
void increaseSpeed();

/// @brief used only within prototype version, to decrease speed
void decreaseSpeed();