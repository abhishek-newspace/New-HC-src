#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/stateHandler.hpp"
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


// gettr functions
bool headlight_off();
bool foglight_off();
void setHeadlighState(bool state);
void setFoglightState(bool state);

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

/**
 * check whether the UGV is connected or not
 * \returns true when UGV is not in disconnected state.
 */
bool isUGV_connected();

void setUGV_speed(int speed);

/// @brief used only within prototype version, to increase speed
void inc_Speed();


/// @brief Get the next speed when to be increased.
/// @return get the current speed that should appear when speed is increased
int get_inc_speed();

/// @brief switch between drive modes
void switchDriveMode(int driveMode);

/// @brief gets the current drive mode, default mode is speed mode, on controller startup
/// @return current drive mode
int getDriveMode();

/// @brief get the next drive mode when it needs to be increased
/// @return next drive mode
int get_inc_driveMode();

/// @brief switch to the given connectivity status
/// @param status status to which it needs to be switched to
void switch_conn_stat(connectivity_status status);

/// @brief get the current connectivity status
/// @return the current connnectivity status
connectivity_status get_conn_stat();

/// @brief switch to the specified emergency mode and display accordingly
/// @param mode 
void switchEmergencyMode(int mode);

/// @brief get the currently set emergency mode
/// @return current emergency mode that is set
estopMode getEmergencyMode();
