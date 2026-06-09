#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvCustom/gtestsuite.hpp"
/** @file
 *  @brief MAVLink comm testsuite protocol generated from ugvCustom.xml
 *  @see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "ugvCustom.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(ugvCustom, HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::ugvCustom::msg::HEARTBEAT packet1{};
    mavlink::ugvCustom::msg::HEARTBEAT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.autopilot, packet2.autopilot);
    EXPECT_EQ(packet1.base_mode, packet2.base_mode);
    EXPECT_EQ(packet1.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet1.system_status, packet2.system_status);
    EXPECT_EQ(packet1.mavlink_version, packet2.mavlink_version);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_heartbeat_t packet_c {
         963497464, 17, 84, 151, 218, 2
    };

    mavlink::ugvCustom::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::ugvCustom::msg::HEARTBEAT packet2{};

    mavlink_msg_heartbeat_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.autopilot, packet2.autopilot);
    EXPECT_EQ(packet_in.base_mode, packet2.base_mode);
    EXPECT_EQ(packet_in.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet_in.system_status, packet2.system_status);
    EXPECT_EQ(packet_in.mavlink_version, packet2.mavlink_version);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, TIMESYNC)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::TIMESYNC packet_in{};
    packet_in.tc1 = 93372036854775807LL;
    packet_in.ts1 = 170LL;
    packet_in.target_system = 53;
    packet_in.target_component = 120;

    mavlink::ugvCustom::msg::TIMESYNC packet1{};
    mavlink::ugvCustom::msg::TIMESYNC packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.tc1, packet2.tc1);
    EXPECT_EQ(packet1.ts1, packet2.ts1);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, TIMESYNC)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_timesync_t packet_c {
         93372036854775807LL, 170LL, 53, 120
    };

    mavlink::ugvCustom::msg::TIMESYNC packet_in{};
    packet_in.tc1 = 93372036854775807LL;
    packet_in.ts1 = 170LL;
    packet_in.target_system = 53;
    packet_in.target_component = 120;

    mavlink::ugvCustom::msg::TIMESYNC packet2{};

    mavlink_msg_timesync_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.tc1, packet2.tc1);
    EXPECT_EQ(packet_in.ts1, packet2.ts1);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, COMMAND_LONG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::COMMAND_LONG packet_in{};
    packet_in.target_system = 223;
    packet_in.target_component = 34;
    packet_in.command = 18691;
    packet_in.confirmation = 101;
    packet_in.param1 = 17.0;
    packet_in.param2 = 45.0;
    packet_in.param3 = 73.0;
    packet_in.param4 = 101.0;
    packet_in.param5 = 129.0;
    packet_in.param6 = 157.0;
    packet_in.param7 = 185.0;

    mavlink::ugvCustom::msg::COMMAND_LONG packet1{};
    mavlink::ugvCustom::msg::COMMAND_LONG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.command, packet2.command);
    EXPECT_EQ(packet1.confirmation, packet2.confirmation);
    EXPECT_EQ(packet1.param1, packet2.param1);
    EXPECT_EQ(packet1.param2, packet2.param2);
    EXPECT_EQ(packet1.param3, packet2.param3);
    EXPECT_EQ(packet1.param4, packet2.param4);
    EXPECT_EQ(packet1.param5, packet2.param5);
    EXPECT_EQ(packet1.param6, packet2.param6);
    EXPECT_EQ(packet1.param7, packet2.param7);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, COMMAND_LONG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_command_long_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 18691, 223, 34, 101
    };

    mavlink::ugvCustom::msg::COMMAND_LONG packet_in{};
    packet_in.target_system = 223;
    packet_in.target_component = 34;
    packet_in.command = 18691;
    packet_in.confirmation = 101;
    packet_in.param1 = 17.0;
    packet_in.param2 = 45.0;
    packet_in.param3 = 73.0;
    packet_in.param4 = 101.0;
    packet_in.param5 = 129.0;
    packet_in.param6 = 157.0;
    packet_in.param7 = 185.0;

    mavlink::ugvCustom::msg::COMMAND_LONG packet2{};

    mavlink_msg_command_long_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.command, packet2.command);
    EXPECT_EQ(packet_in.confirmation, packet2.confirmation);
    EXPECT_EQ(packet_in.param1, packet2.param1);
    EXPECT_EQ(packet_in.param2, packet2.param2);
    EXPECT_EQ(packet_in.param3, packet2.param3);
    EXPECT_EQ(packet_in.param4, packet2.param4);
    EXPECT_EQ(packet_in.param5, packet2.param5);
    EXPECT_EQ(packet_in.param6, packet2.param6);
    EXPECT_EQ(packet_in.param7, packet2.param7);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, COMMAND_ACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::COMMAND_ACK packet_in{};
    packet_in.command = 17235;
    packet_in.result = 139;
    packet_in.progress = 206;
    packet_in.result_param2 = 963497672;
    packet_in.target_system = 29;
    packet_in.target_component = 96;

    mavlink::ugvCustom::msg::COMMAND_ACK packet1{};
    mavlink::ugvCustom::msg::COMMAND_ACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.command, packet2.command);
    EXPECT_EQ(packet1.result, packet2.result);
    EXPECT_EQ(packet1.progress, packet2.progress);
    EXPECT_EQ(packet1.result_param2, packet2.result_param2);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, COMMAND_ACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_command_ack_t packet_c {
         17235, 139, 206, 963497672, 29, 96
    };

    mavlink::ugvCustom::msg::COMMAND_ACK packet_in{};
    packet_in.command = 17235;
    packet_in.result = 139;
    packet_in.progress = 206;
    packet_in.result_param2 = 963497672;
    packet_in.target_system = 29;
    packet_in.target_component = 96;

    mavlink::ugvCustom::msg::COMMAND_ACK packet2{};

    mavlink_msg_command_ack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.command, packet2.command);
    EXPECT_EQ(packet_in.result, packet2.result);
    EXPECT_EQ(packet_in.progress, packet2.progress);
    EXPECT_EQ(packet_in.result_param2, packet2.result_param2);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, MANUAL_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::MANUAL_CONTROL packet_in{};
    packet_in.target = 163;
    packet_in.x = 17235;
    packet_in.y = 17339;
    packet_in.z = 17443;
    packet_in.r = 17547;
    packet_in.push_buttons = 17651;
    packet_in.enabled_extensions = 230;
    packet_in.s = 17859;
    packet_in.t = 17963;
    packet_in.aux1 = 18067;
    packet_in.aux2 = 18171;
    packet_in.aux3 = 18275;
    packet_in.aux4 = 18379;
    packet_in.aux5 = 18483;
    packet_in.aux6 = 18587;

    mavlink::ugvCustom::msg::MANUAL_CONTROL packet1{};
    mavlink::ugvCustom::msg::MANUAL_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target, packet2.target);
    EXPECT_EQ(packet1.x, packet2.x);
    EXPECT_EQ(packet1.y, packet2.y);
    EXPECT_EQ(packet1.z, packet2.z);
    EXPECT_EQ(packet1.r, packet2.r);
    EXPECT_EQ(packet1.push_buttons, packet2.push_buttons);
    EXPECT_EQ(packet1.enabled_extensions, packet2.enabled_extensions);
    EXPECT_EQ(packet1.s, packet2.s);
    EXPECT_EQ(packet1.t, packet2.t);
    EXPECT_EQ(packet1.aux1, packet2.aux1);
    EXPECT_EQ(packet1.aux2, packet2.aux2);
    EXPECT_EQ(packet1.aux3, packet2.aux3);
    EXPECT_EQ(packet1.aux4, packet2.aux4);
    EXPECT_EQ(packet1.aux5, packet2.aux5);
    EXPECT_EQ(packet1.aux6, packet2.aux6);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, MANUAL_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_manual_control_t packet_c {
         17235, 17339, 17443, 17547, 17651, 163, 230, 17859, 17963, 18067, 18171, 18275, 18379, 18483, 18587
    };

    mavlink::ugvCustom::msg::MANUAL_CONTROL packet_in{};
    packet_in.target = 163;
    packet_in.x = 17235;
    packet_in.y = 17339;
    packet_in.z = 17443;
    packet_in.r = 17547;
    packet_in.push_buttons = 17651;
    packet_in.enabled_extensions = 230;
    packet_in.s = 17859;
    packet_in.t = 17963;
    packet_in.aux1 = 18067;
    packet_in.aux2 = 18171;
    packet_in.aux3 = 18275;
    packet_in.aux4 = 18379;
    packet_in.aux5 = 18483;
    packet_in.aux6 = 18587;

    mavlink::ugvCustom::msg::MANUAL_CONTROL packet2{};

    mavlink_msg_manual_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target, packet2.target);
    EXPECT_EQ(packet_in.x, packet2.x);
    EXPECT_EQ(packet_in.y, packet2.y);
    EXPECT_EQ(packet_in.z, packet2.z);
    EXPECT_EQ(packet_in.r, packet2.r);
    EXPECT_EQ(packet_in.push_buttons, packet2.push_buttons);
    EXPECT_EQ(packet_in.enabled_extensions, packet2.enabled_extensions);
    EXPECT_EQ(packet_in.s, packet2.s);
    EXPECT_EQ(packet_in.t, packet2.t);
    EXPECT_EQ(packet_in.aux1, packet2.aux1);
    EXPECT_EQ(packet_in.aux2, packet2.aux2);
    EXPECT_EQ(packet_in.aux3, packet2.aux3);
    EXPECT_EQ(packet_in.aux4, packet2.aux4);
    EXPECT_EQ(packet_in.aux5, packet2.aux5);
    EXPECT_EQ(packet_in.aux6, packet2.aux6);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, RADIO_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::RADIO_STATUS packet_in{};
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;

    mavlink::ugvCustom::msg::RADIO_STATUS packet1{};
    mavlink::ugvCustom::msg::RADIO_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rssi, packet2.rssi);
    EXPECT_EQ(packet1.remrssi, packet2.remrssi);
    EXPECT_EQ(packet1.txbuf, packet2.txbuf);
    EXPECT_EQ(packet1.noise, packet2.noise);
    EXPECT_EQ(packet1.remnoise, packet2.remnoise);
    EXPECT_EQ(packet1.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet1.fixed, packet2.fixed);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, RADIO_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_radio_status_t packet_c {
         17235, 17339, 17, 84, 151, 218, 29
    };

    mavlink::ugvCustom::msg::RADIO_STATUS packet_in{};
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;

    mavlink::ugvCustom::msg::RADIO_STATUS packet2{};

    mavlink_msg_radio_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rssi, packet2.rssi);
    EXPECT_EQ(packet_in.remrssi, packet2.remrssi);
    EXPECT_EQ(packet_in.txbuf, packet2.txbuf);
    EXPECT_EQ(packet_in.noise, packet2.noise);
    EXPECT_EQ(packet_in.remnoise, packet2.remnoise);
    EXPECT_EQ(packet_in.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet_in.fixed, packet2.fixed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, SYS_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::SYS_STATUS packet_in{};
    packet_in.voltage_battery = 17235;
    packet_in.battery_remaining = 17;
    packet_in.drop_rate_comm = 17339;

    mavlink::ugvCustom::msg::SYS_STATUS packet1{};
    mavlink::ugvCustom::msg::SYS_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.voltage_battery, packet2.voltage_battery);
    EXPECT_EQ(packet1.battery_remaining, packet2.battery_remaining);
    EXPECT_EQ(packet1.drop_rate_comm, packet2.drop_rate_comm);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, SYS_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sys_status_t packet_c {
         17235, 17339, 17
    };

    mavlink::ugvCustom::msg::SYS_STATUS packet_in{};
    packet_in.voltage_battery = 17235;
    packet_in.battery_remaining = 17;
    packet_in.drop_rate_comm = 17339;

    mavlink::ugvCustom::msg::SYS_STATUS packet2{};

    mavlink_msg_sys_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.voltage_battery, packet2.voltage_battery);
    EXPECT_EQ(packet_in.battery_remaining, packet2.battery_remaining);
    EXPECT_EQ(packet_in.drop_rate_comm, packet2.drop_rate_comm);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, SYSTEM_TIME)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::SYSTEM_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.time_boot_ms = 963497880;

    mavlink::ugvCustom::msg::SYSTEM_TIME packet1{};
    mavlink::ugvCustom::msg::SYSTEM_TIME packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, SYSTEM_TIME)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_system_time_t packet_c {
         93372036854775807ULL, 963497880
    };

    mavlink::ugvCustom::msg::SYSTEM_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.time_boot_ms = 963497880;

    mavlink::ugvCustom::msg::SYSTEM_TIME packet2{};

    mavlink_msg_system_time_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, UGV_SYSTEM_INFO)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::UGV_SYSTEM_INFO packet_in{};
    packet_in.ts1_hour = 5;
    packet_in.ts1_minute = 72;
    packet_in.ts1_second = 139;
    packet_in.subsystem_health_1 = 206;
    packet_in.subsystem_health_2 = 17;
    packet_in.subsystem_health_3 = 84;
    packet_in.subsystem_health_4 = 151;
    packet_in.ts2_hour = 218;
    packet_in.ts2_minute = 29;
    packet_in.ts2_second = 96;
    packet_in.battery_soc = 163;
    packet_in.main_mode = 230;
    packet_in.sub_mode = 41;
    packet_in.speed_mode = 108;
    packet_in.drive_mode = 175;
    packet_in.arm_mode = 242;
    packet_in.intended_main_mode = 53;
    packet_in.intended_sub_mode = 120;
    packet_in.intended_speed_mode = 187;
    packet_in.intended_drive_mode = 254;
    packet_in.intended_arm_mode = 65;
    packet_in.mode_change_reason = 132;
    packet_in.ts3_hour = 199;
    packet_in.ts3_minute = 10;
    packet_in.ts3_second = 77;
    packet_in.rear_left_motor_faults = 144;
    packet_in.rear_right_motor_faults = 211;
    packet_in.front_left_motor_faults = 22;
    packet_in.front_right_motor_faults = 89;
    packet_in.rear_mc_faults = 156;
    packet_in.front_mc_faults = 223;
    packet_in.rear_mc_voltage = 34;
    packet_in.front_mc_voltage = 101;
    packet_in.rear_mc_temperature = 168;
    packet_in.front_mc_temperature = 235;
    packet_in.light_status = 46;
    packet_in.pdu_channel_status = 113;

    mavlink::ugvCustom::msg::UGV_SYSTEM_INFO packet1{};
    mavlink::ugvCustom::msg::UGV_SYSTEM_INFO packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ts1_hour, packet2.ts1_hour);
    EXPECT_EQ(packet1.ts1_minute, packet2.ts1_minute);
    EXPECT_EQ(packet1.ts1_second, packet2.ts1_second);
    EXPECT_EQ(packet1.subsystem_health_1, packet2.subsystem_health_1);
    EXPECT_EQ(packet1.subsystem_health_2, packet2.subsystem_health_2);
    EXPECT_EQ(packet1.subsystem_health_3, packet2.subsystem_health_3);
    EXPECT_EQ(packet1.subsystem_health_4, packet2.subsystem_health_4);
    EXPECT_EQ(packet1.ts2_hour, packet2.ts2_hour);
    EXPECT_EQ(packet1.ts2_minute, packet2.ts2_minute);
    EXPECT_EQ(packet1.ts2_second, packet2.ts2_second);
    EXPECT_EQ(packet1.battery_soc, packet2.battery_soc);
    EXPECT_EQ(packet1.main_mode, packet2.main_mode);
    EXPECT_EQ(packet1.sub_mode, packet2.sub_mode);
    EXPECT_EQ(packet1.speed_mode, packet2.speed_mode);
    EXPECT_EQ(packet1.drive_mode, packet2.drive_mode);
    EXPECT_EQ(packet1.arm_mode, packet2.arm_mode);
    EXPECT_EQ(packet1.intended_main_mode, packet2.intended_main_mode);
    EXPECT_EQ(packet1.intended_sub_mode, packet2.intended_sub_mode);
    EXPECT_EQ(packet1.intended_speed_mode, packet2.intended_speed_mode);
    EXPECT_EQ(packet1.intended_drive_mode, packet2.intended_drive_mode);
    EXPECT_EQ(packet1.intended_arm_mode, packet2.intended_arm_mode);
    EXPECT_EQ(packet1.mode_change_reason, packet2.mode_change_reason);
    EXPECT_EQ(packet1.ts3_hour, packet2.ts3_hour);
    EXPECT_EQ(packet1.ts3_minute, packet2.ts3_minute);
    EXPECT_EQ(packet1.ts3_second, packet2.ts3_second);
    EXPECT_EQ(packet1.rear_left_motor_faults, packet2.rear_left_motor_faults);
    EXPECT_EQ(packet1.rear_right_motor_faults, packet2.rear_right_motor_faults);
    EXPECT_EQ(packet1.front_left_motor_faults, packet2.front_left_motor_faults);
    EXPECT_EQ(packet1.front_right_motor_faults, packet2.front_right_motor_faults);
    EXPECT_EQ(packet1.rear_mc_faults, packet2.rear_mc_faults);
    EXPECT_EQ(packet1.front_mc_faults, packet2.front_mc_faults);
    EXPECT_EQ(packet1.rear_mc_voltage, packet2.rear_mc_voltage);
    EXPECT_EQ(packet1.front_mc_voltage, packet2.front_mc_voltage);
    EXPECT_EQ(packet1.rear_mc_temperature, packet2.rear_mc_temperature);
    EXPECT_EQ(packet1.front_mc_temperature, packet2.front_mc_temperature);
    EXPECT_EQ(packet1.light_status, packet2.light_status);
    EXPECT_EQ(packet1.pdu_channel_status, packet2.pdu_channel_status);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, UGV_SYSTEM_INFO)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ugv_system_info_t packet_c {
         5, 72, 139, 206, 17, 84, 151, 218, 29, 96, 163, 230, 41, 108, 175, 242, 53, 120, 187, 254, 65, 132, 199, 10, 77, 144, 211, 22, 89, 156, 223, 34, 101, 168, 235, 46, 113
    };

    mavlink::ugvCustom::msg::UGV_SYSTEM_INFO packet_in{};
    packet_in.ts1_hour = 5;
    packet_in.ts1_minute = 72;
    packet_in.ts1_second = 139;
    packet_in.subsystem_health_1 = 206;
    packet_in.subsystem_health_2 = 17;
    packet_in.subsystem_health_3 = 84;
    packet_in.subsystem_health_4 = 151;
    packet_in.ts2_hour = 218;
    packet_in.ts2_minute = 29;
    packet_in.ts2_second = 96;
    packet_in.battery_soc = 163;
    packet_in.main_mode = 230;
    packet_in.sub_mode = 41;
    packet_in.speed_mode = 108;
    packet_in.drive_mode = 175;
    packet_in.arm_mode = 242;
    packet_in.intended_main_mode = 53;
    packet_in.intended_sub_mode = 120;
    packet_in.intended_speed_mode = 187;
    packet_in.intended_drive_mode = 254;
    packet_in.intended_arm_mode = 65;
    packet_in.mode_change_reason = 132;
    packet_in.ts3_hour = 199;
    packet_in.ts3_minute = 10;
    packet_in.ts3_second = 77;
    packet_in.rear_left_motor_faults = 144;
    packet_in.rear_right_motor_faults = 211;
    packet_in.front_left_motor_faults = 22;
    packet_in.front_right_motor_faults = 89;
    packet_in.rear_mc_faults = 156;
    packet_in.front_mc_faults = 223;
    packet_in.rear_mc_voltage = 34;
    packet_in.front_mc_voltage = 101;
    packet_in.rear_mc_temperature = 168;
    packet_in.front_mc_temperature = 235;
    packet_in.light_status = 46;
    packet_in.pdu_channel_status = 113;

    mavlink::ugvCustom::msg::UGV_SYSTEM_INFO packet2{};

    mavlink_msg_ugv_system_info_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ts1_hour, packet2.ts1_hour);
    EXPECT_EQ(packet_in.ts1_minute, packet2.ts1_minute);
    EXPECT_EQ(packet_in.ts1_second, packet2.ts1_second);
    EXPECT_EQ(packet_in.subsystem_health_1, packet2.subsystem_health_1);
    EXPECT_EQ(packet_in.subsystem_health_2, packet2.subsystem_health_2);
    EXPECT_EQ(packet_in.subsystem_health_3, packet2.subsystem_health_3);
    EXPECT_EQ(packet_in.subsystem_health_4, packet2.subsystem_health_4);
    EXPECT_EQ(packet_in.ts2_hour, packet2.ts2_hour);
    EXPECT_EQ(packet_in.ts2_minute, packet2.ts2_minute);
    EXPECT_EQ(packet_in.ts2_second, packet2.ts2_second);
    EXPECT_EQ(packet_in.battery_soc, packet2.battery_soc);
    EXPECT_EQ(packet_in.main_mode, packet2.main_mode);
    EXPECT_EQ(packet_in.sub_mode, packet2.sub_mode);
    EXPECT_EQ(packet_in.speed_mode, packet2.speed_mode);
    EXPECT_EQ(packet_in.drive_mode, packet2.drive_mode);
    EXPECT_EQ(packet_in.arm_mode, packet2.arm_mode);
    EXPECT_EQ(packet_in.intended_main_mode, packet2.intended_main_mode);
    EXPECT_EQ(packet_in.intended_sub_mode, packet2.intended_sub_mode);
    EXPECT_EQ(packet_in.intended_speed_mode, packet2.intended_speed_mode);
    EXPECT_EQ(packet_in.intended_drive_mode, packet2.intended_drive_mode);
    EXPECT_EQ(packet_in.intended_arm_mode, packet2.intended_arm_mode);
    EXPECT_EQ(packet_in.mode_change_reason, packet2.mode_change_reason);
    EXPECT_EQ(packet_in.ts3_hour, packet2.ts3_hour);
    EXPECT_EQ(packet_in.ts3_minute, packet2.ts3_minute);
    EXPECT_EQ(packet_in.ts3_second, packet2.ts3_second);
    EXPECT_EQ(packet_in.rear_left_motor_faults, packet2.rear_left_motor_faults);
    EXPECT_EQ(packet_in.rear_right_motor_faults, packet2.rear_right_motor_faults);
    EXPECT_EQ(packet_in.front_left_motor_faults, packet2.front_left_motor_faults);
    EXPECT_EQ(packet_in.front_right_motor_faults, packet2.front_right_motor_faults);
    EXPECT_EQ(packet_in.rear_mc_faults, packet2.rear_mc_faults);
    EXPECT_EQ(packet_in.front_mc_faults, packet2.front_mc_faults);
    EXPECT_EQ(packet_in.rear_mc_voltage, packet2.rear_mc_voltage);
    EXPECT_EQ(packet_in.front_mc_voltage, packet2.front_mc_voltage);
    EXPECT_EQ(packet_in.rear_mc_temperature, packet2.rear_mc_temperature);
    EXPECT_EQ(packet_in.front_mc_temperature, packet2.front_mc_temperature);
    EXPECT_EQ(packet_in.light_status, packet2.light_status);
    EXPECT_EQ(packet_in.pdu_channel_status, packet2.pdu_channel_status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, UGV_COMPONENT_VERSION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::UGV_COMPONENT_VERSION packet_in{};
    packet_in.software_version = 963497464;
    packet_in.checksum = {{ 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 }};
    packet_in.target_system = 113;
    packet_in.target_component = 180;

    mavlink::ugvCustom::msg::UGV_COMPONENT_VERSION packet1{};
    mavlink::ugvCustom::msg::UGV_COMPONENT_VERSION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.software_version, packet2.software_version);
    EXPECT_EQ(packet1.checksum, packet2.checksum);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, UGV_COMPONENT_VERSION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ugv_component_version_t packet_c {
         963497464, { 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 }, 113, 180
    };

    mavlink::ugvCustom::msg::UGV_COMPONENT_VERSION packet_in{};
    packet_in.software_version = 963497464;
    packet_in.checksum = {{ 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 }};
    packet_in.target_system = 113;
    packet_in.target_component = 180;

    mavlink::ugvCustom::msg::UGV_COMPONENT_VERSION packet2{};

    mavlink_msg_ugv_component_version_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.software_version, packet2.software_version);
    EXPECT_EQ(packet_in.checksum, packet2.checksum);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvCustom, UGV_SUBSYSTEM_VERSION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvCustom::msg::UGV_SUBSYSTEM_VERSION packet_in{};
    packet_in.type = 65;
    packet_in.component1_sw = 963497464;
    packet_in.component1_checksum = {{ 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163 }};
    packet_in.component2_sw = 963497672;
    packet_in.component2_checksum = {{ 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3 }};
    packet_in.component3_sw = 963497880;
    packet_in.component3_checksum = {{ 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 }};
    packet_in.component4_sw = 963498088;
    packet_in.component4_checksum = {{ 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 }};
    packet_in.component5_sw = 963498296;
    packet_in.component5_checksum = {{ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 }};

    mavlink::ugvCustom::msg::UGV_SUBSYSTEM_VERSION packet1{};
    mavlink::ugvCustom::msg::UGV_SUBSYSTEM_VERSION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.component1_sw, packet2.component1_sw);
    EXPECT_EQ(packet1.component1_checksum, packet2.component1_checksum);
    EXPECT_EQ(packet1.component2_sw, packet2.component2_sw);
    EXPECT_EQ(packet1.component2_checksum, packet2.component2_checksum);
    EXPECT_EQ(packet1.component3_sw, packet2.component3_sw);
    EXPECT_EQ(packet1.component3_checksum, packet2.component3_checksum);
    EXPECT_EQ(packet1.component4_sw, packet2.component4_sw);
    EXPECT_EQ(packet1.component4_checksum, packet2.component4_checksum);
    EXPECT_EQ(packet1.component5_sw, packet2.component5_sw);
    EXPECT_EQ(packet1.component5_checksum, packet2.component5_checksum);
}

#ifdef TEST_INTEROP
TEST(ugvCustom_interop, UGV_SUBSYSTEM_VERSION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ugv_subsystem_version_t packet_c {
         963497464, 963497672, 963497880, 963498088, 963498296, 65, { 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163 }, { 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3 }, { 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 }, { 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 }, { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 }
    };

    mavlink::ugvCustom::msg::UGV_SUBSYSTEM_VERSION packet_in{};
    packet_in.type = 65;
    packet_in.component1_sw = 963497464;
    packet_in.component1_checksum = {{ 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163 }};
    packet_in.component2_sw = 963497672;
    packet_in.component2_checksum = {{ 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3 }};
    packet_in.component3_sw = 963497880;
    packet_in.component3_checksum = {{ 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 }};
    packet_in.component4_sw = 963498088;
    packet_in.component4_checksum = {{ 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 }};
    packet_in.component5_sw = 963498296;
    packet_in.component5_checksum = {{ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 }};

    mavlink::ugvCustom::msg::UGV_SUBSYSTEM_VERSION packet2{};

    mavlink_msg_ugv_subsystem_version_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.component1_sw, packet2.component1_sw);
    EXPECT_EQ(packet_in.component1_checksum, packet2.component1_checksum);
    EXPECT_EQ(packet_in.component2_sw, packet2.component2_sw);
    EXPECT_EQ(packet_in.component2_checksum, packet2.component2_checksum);
    EXPECT_EQ(packet_in.component3_sw, packet2.component3_sw);
    EXPECT_EQ(packet_in.component3_checksum, packet2.component3_checksum);
    EXPECT_EQ(packet_in.component4_sw, packet2.component4_sw);
    EXPECT_EQ(packet_in.component4_checksum, packet2.component4_checksum);
    EXPECT_EQ(packet_in.component5_sw, packet2.component5_sw);
    EXPECT_EQ(packet_in.component5_checksum, packet2.component5_checksum);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
