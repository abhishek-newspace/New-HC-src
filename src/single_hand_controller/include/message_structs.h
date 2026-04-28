/**
 * @file message_structs.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * @brief This header file is part of the Single Hand Controller for Scout project; Defines all message structs being sent and received by the Single Hand Controller.
 */
#pragma once
#include "definitions.h"
#include "mavlink/common/mavlink.h"

// commands sent from hand controller
// empty fields within structs need to be filled with appropriate values

struct HC_ATLAS_HEARTBEAT_BC{
    uint8_t sys_id = HC_ID;
    uint8_t comp_id = HC_COMP_ID;
};

struct HC_ATLAS_TIMESYNC_REQ{
    int64_t tc1 = 0;
    int64_t ts1;
    uint8_t target_sys = SCOUT_ID;
    uint8_t target_comp = ATLAS_COMP_ID;
};

struct HC_ATLAS_MANUAL_CONTROL_BC{
    uint8_t target = SCOUT_ID;
    int16_t x,y;
    uint16_t Push_buttons = 0;
    uint16_t Tristate_Toggle_switches = 0;
};

struct HC_ATLAS_ARM_DISARM_CMD{
    uint8_t target_system = SCOUT_ID;
    uint8_t target_component = ATLAS_COMP_ID;
    uint16_t command = MAV_CMD_COMPONENT_ARM_DISARM;
    uint8_t confirmation = 0;
    float param1;
};


// commands received from atlas

// heartbeat is rejected in case parameters don't match
struct ATLAS_HC_HEARTBEAT_BC{
    uint8_t sys_id = SCOUT_ID;
    uint8_t comp_id = ATLAS_COMP_ID;
    uint8_t type = MAV_TYPE_ONBOARD_CONTROLLER;
    uint8_t autopilot = MAV_AUTOPILOT_GENERIC;
    uint8_t sys_status;
    uint32_t custom_mode = SCOUT_HEARTBEAT_IDENTIFIER;
};

struct ATLAS_HC_TIMESYNC_RESP{
    uint64_t tc1;
    uint64_t ts1;
    uint8_t target_sys = HC_ID;
    uint8_t target_comp = HC_COMP_ID;
};


struct HC_RADIO_STATUS{
    uint8_t rssi,
        remrssi,
        txbuf,
        noise,
        remnoise;
    uint16_t rxerrors,
        fixed;
};

struct ATLAS_HC_SYS_STAT{
    uint16_t voltage_battery;
    int8_t battery_remaining;
    uint16_t drop_rate_comm;
};

struct ATLAS_HC_ARM_DISARM_ACK{
    uint8_t command;
    uint8_t result;
    uint8_t target_system = HC_ID;
    uint8_t target_component = HC_COMP_ID;
};