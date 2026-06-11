/**
 * @file enum_defs.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 20/05/2026
 * 
 * list of enums defined
 */
#pragma once


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

enum driveMode{
    speed = 0,
    torque = 1
};
