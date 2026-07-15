/**
 * @file enum_defs.h
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
 * 
 * list of enums defined
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - documented connectivity_status LED colour mapping (SRS §3.2.2)
 */
#pragma once


/// @brief current UGV status
enum ugv_status{
    disconnected, 
    active, 
    standby, 
    unknown};

/**
 * Connectivity LED status (SRS §3.2.2 Helios HC).
 *   all_disconnected     -> Red    (UGV not connected — required)
 *   low_connectivity     -> Yellow (connected but RSSI below threshold)
 *   connected            -> Green
 *   comm_fault           -> Blue   (timesync fault)
 *   only_radio_connected -> treated as Red in UI (not connected to UGV)
 */
enum connectivity_status{
    all_disconnected,
    only_radio_connected,
    low_connectivity,
    connected,
    comm_fault,
    conn_invalid
};

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
    torque = 1,
    torque_sl = 2
};

enum estopMode{
    disengaged = 0,
    engaged = 1,
    disabled = 2
};