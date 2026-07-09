/** @file
 *  @brief MAVLink comm protocol generated from ugvcustom.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_UGVCUSTOM_H
#define MAVLINK_UGVCUSTOM_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_UGVCUSTOM.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_UGVCUSTOM_XML_HASH -8900407254048203717

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 50, 9, 9, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {24, 24, 30, 30, 0, 0, 0}, {30, 39, 28, 28, 0, 0, 0}, {69, 243, 11, 30, 1, 10, 0}, {76, 152, 33, 33, 3, 30, 31}, {109, 185, 9, 9, 0, 0, 0}, {111, 198, 18, 18, 3, 16, 17}, {50001, 88, 55, 55, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_UGVCUSTOM

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_timesync.h"
#include "./mavlink_msg_command_long.h"
#include "./mavlink_msg_manual_control.h"
#include "./mavlink_msg_radio_status.h"
#include "./mavlink_msg_ugv_system_info.h"
#include "./mavlink_msg_system_time.h"
#include "./mavlink_msg_gps_raw_int.h"
#include "./mavlink_msg_attitude.h"

// base include



#if MAVLINK_UGVCUSTOM_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SYSTEM_TIME, MAVLINK_MESSAGE_INFO_GPS_RAW_INT, MAVLINK_MESSAGE_INFO_ATTITUDE, MAVLINK_MESSAGE_INFO_MANUAL_CONTROL, MAVLINK_MESSAGE_INFO_COMMAND_LONG, MAVLINK_MESSAGE_INFO_RADIO_STATUS, MAVLINK_MESSAGE_INFO_TIMESYNC, MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO}
# define MAVLINK_MESSAGE_NAMES {{ "ATTITUDE", 30 }, { "COMMAND_LONG", 76 }, { "GPS_RAW_INT", 24 }, { "HEARTBEAT", 0 }, { "MANUAL_CONTROL", 69 }, { "RADIO_STATUS", 109 }, { "SYSTEM_TIME", 2 }, { "TIMESYNC", 111 }, { "UGV_SYSTEM_INFO", 50001 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_UGVCUSTOM_H
