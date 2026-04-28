#pragma once
/**
 * @file message_sender.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * MAVLink messages are packed and placed into the char buffer based on input parameters required for the given message.
 */

#include"message_structs.h"
#include "definitions.h"
#include "timer.hpp"

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

/**
 * pack data and write MAVLink packets to buffer.
 * all functions return the length of the packet, which is meant to be used when writing buffer to serial channel
 */
class message_sender{
    struct HC_ATLAS_ARM_DISARM_CMD arm_disarm_cmd;
    struct HC_ATLAS_HEARTBEAT_BC heartbeat;
    struct HC_ATLAS_MANUAL_CONTROL_BC manual_control;
    struct HC_ATLAS_TIMESYNC_REQ timesync;

    uint8_t* buf;
    mavlink_message_t*msg;

public:
    /// @brief constructor for message sender holds message and buffer pointers.
    /// @param buffer required to be sent by packet handler over UART
    /// @param message struct contains packed MAVLink message
    message_sender(uint8_t* buffer, mavlink_message_t* message): msg(message), buf(buffer) {
    }

    /// @brief pack an arm/disarm command into buffer
    /// @param state can be disarm(0), or arm(1)
    /// @return length of buffer
    int buffer_arm_disarm_cmd(bool state);

    /// @brief send heartbeat to buffer; heartbeat from hand controller is used to invoke ATLAS' radio to send RADIO_STATUS packets
    /// @return length of buffer
    int buffer_heartbeat();

    /// @brief send manual control packet to buffer
    /// @param x normalized input for thumbstick along X direction (forward - backward)
    /// @param y normalized input for thumbstick along Y direction (left - right)
    /// @param extra_feature_1_press whether button A is pressed or not
    /// @param extra_feature_1_long_press whether button A is long pressed
    /// @param extra_feature_2_press whether button B is pressed or not
    /// @param extra_feature_2_long_press whether button B is long pressed
    /// @param dirTog enum value for the current position of direction toggle switch
    /// @param spdTog enum value for the current position of speed toggle switch
    /// @return length of buffer
    int buffer_manual_control(
        int x, 
        int y, 
        bool extra_feature_1_press, 
        bool extra_feature_1_long_press, 
        bool extra_feature_2_press, 
        bool extra_feature_2_long_press, 
        directionToggle dirTog, 
        speedToggle spdTog
    );
    int buffer_timesync();
};