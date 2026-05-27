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
    static struct ATLAS_HC_SYS_STAT sys_status;
    static struct ATLAS_HC_ARM_DISARM_ACK ack;
public:

    /// @brief process timesync message; allows for accurate time synchronization on sending/receiving further signed packets
    /// @param msg received message
    static void receive_timesync(mavlink_message_t *msg);

    /// @brief process radio status message to display signal strength on user display 
    /// @param msg received message
    static void receive_radio_status(mavlink_message_t *msg);

    /// @brief process sys_status message to display battery percentage on user display
    /// @param msg received message
    static void receive_sys_status(mavlink_message_t *msg);

    /// @brief receive acknowledgement for all command long messages sent from device; includes accepted/rejected status using which the hand controller knows whether the packet is accepted or rejected
    /// @param msg received message
    static void receive_ack(mavlink_message_t *msg);

    /// @brief receives and validates heartbeat messages received from scout, based on which the last_heartbeat_received_at variable is updated
    /// @param msg received message
    static void receive_heartbeat(mavlink_message_t *msg);
};

/// @brief check whether first time synchronization is performed or not.
bool receivedFirstTimesync();

/// @brief check whether an arm/disarm message is currently being sent
/// @return true when an arm/disarm message is currently being sent (arm_disarm_count > 0)
bool is_arm_disarm_sending();

/// @brief reset arm_disarm_count to 0; so that no arm/disarm messages will be sent
void reset_arm_disarm_sending();

/// @brief set arm_disarm_count to number of times arm/disarm command needs to be resent
void init_arm_disarm_sending();

/// @brief decrement arm_disarm_count, to be called everytime an arm/disarm command is sent.
void dec_arm_disarm_sending();
