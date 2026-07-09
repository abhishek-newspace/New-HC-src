#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/ugvcustom.hpp"
/** @file
 *  @brief MAVLink comm protocol generated from ugvcustom.xml
 *  @see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace ugvcustom {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 9> MESSAGE_ENTRIES {{ {0, 50, 9, 9, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {24, 24, 30, 30, 0, 0, 0}, {30, 39, 28, 28, 0, 0, 0}, {69, 243, 11, 30, 1, 10, 0}, {76, 152, 33, 33, 3, 30, 31}, {109, 185, 9, 9, 0, 0, 0}, {111, 198, 18, 18, 3, 16, 17}, {50001, 88, 55, 55, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS




} // namespace ugvcustom
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.hpp"
#include "./mavlink_msg_timesync.hpp"
#include "./mavlink_msg_command_long.hpp"
#include "./mavlink_msg_manual_control.hpp"
#include "./mavlink_msg_radio_status.hpp"
#include "./mavlink_msg_ugv_system_info.hpp"
#include "./mavlink_msg_system_time.hpp"
#include "./mavlink_msg_gps_raw_int.hpp"
#include "./mavlink_msg_attitude.hpp"

// base include

