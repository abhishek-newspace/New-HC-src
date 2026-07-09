#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/packet_receiver.hpp"
/**
 * @file packet_receiver.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * @brief Process all received messages, through MAVLink
 */
#pragma once
#include "definitions.h"
#include "message_structs.h"
#include "stateHandler.hpp"
#include "displayHandler.hpp"
#include "timer.hpp"

/// @brief Methods within this class is meant to be invoked by the packet handler class, in order to process all received packets
class packet_receiver{
    static struct ATLAS_HC_HEARTBEAT_BC heartbeat;
    static struct ATLAS_HC_TIMESYNC_RESP timesync;
    static struct HC_RADIO_STATUS radio_status;
#ifndef DEPRECATED_REV_1
    static struct ATLAS_HC_SYS_STAT sys_status;
    static struct ATLAS_HC_ARM_DISARM_ACK ack;
#endif

public:

    /// @brief process timesync message; allows for accurate time synchronization on sending/receiving further signed packets
    /// @param msg received message
    static void receive_timesync(mavlink_message_t *msg);

    /// @brief process radio status message to display signal strength on user display 
    /// @param msg received message
    static void receive_radio_status(mavlink_message_t *msg);
    
#ifndef DEPRECATED_REV_1
    /// @brief process sys_status message to display battery percentage on user display
    /// @param msg received message
    static void receive_sys_status(mavlink_message_t *msg);

    /// @brief receive acknowledgement for all command long messages sent from device; includes accepted/rejected status using which the hand controller knows whether the packet is accepted or rejected
    /// @param msg received message
    static void receive_ack(mavlink_message_t *msg);
#endif

    /// @brief receives and validates heartbeat messages received from scout, based on which the last_heartbeat_received_at variable is updated
    /// @param msg received message
    static void receive_heartbeat(mavlink_message_t *msg);
};

/// @brief check whether first time synchronization is performed or not.
bool receivedFirstTimesync();

bool receivedRadioStatus();

