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
