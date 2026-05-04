/**
 * @file stateHandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Handling of states within the hand controller is performed within the stateHandler.
 * 
 * currently handles states for ugv state, and speed
 * <h2>changes</h2>
 * renamed increaseSpeed to inc_speed due to name collision with that in buttons struct within IOhandler
 * renamed decreaseSpeed to dec_speed due to name collision with that in buttons struct within IOhandler
 * 
 * @date 04/05/2026
 * - added function declarations for functions to change directions, and get current speed, and direction
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

/**
 * returns the current UGV state
 */
ugv_status getUGV_state();

/// @brief get current UGV speed
/// @return current UGV speed
speedToggle getUGV_speed();

/// @brief get current UGV direction
/// @return current UGV direction
directionToggle getUGV_dir();

/**
 * check whether the UGV is connected or not
 * \returns true when UGV is not in disconnected state.
 */
bool isUGV_connected();

/// @brief used only within prototype version, to increase speed
void inc_Speed();

/// @brief used only within prototype version, to decrease speed
void dec_Speed();

/// @brief used only within prototype version to set speed to neutral
void setNeutral();

/// @brief switch current direction to forward (if not in neutral)
void dir_forward();

/// @brief switch current direction to reverse (if not in neutral)
void dir_reverse();