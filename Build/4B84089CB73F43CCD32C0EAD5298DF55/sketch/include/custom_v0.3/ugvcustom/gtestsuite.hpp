#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/gtestsuite.hpp"
/** @file
 *  @brief MAVLink comm testsuite protocol generated from ugvcustom.xml
 *  @see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "ugvcustom.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(ugvcustom, HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::ugvcustom::msg::HEARTBEAT packet1{};
    mavlink::ugvcustom::msg::HEARTBEAT packet2{};

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
TEST(ugvcustom_interop, HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_heartbeat_t packet_c {
         963497464, 17, 84, 151, 218, 2
    };

    mavlink::ugvcustom::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::ugvcustom::msg::HEARTBEAT packet2{};

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

TEST(ugvcustom, TIMESYNC)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::TIMESYNC packet_in{};
    packet_in.tc1 = 93372036854775807LL;
    packet_in.ts1 = 170LL;
    packet_in.target_system = 53;
    packet_in.target_component = 120;

    mavlink::ugvcustom::msg::TIMESYNC packet1{};
    mavlink::ugvcustom::msg::TIMESYNC packet2{};

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
TEST(ugvcustom_interop, TIMESYNC)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_timesync_t packet_c {
         93372036854775807LL, 170LL, 53, 120
    };

    mavlink::ugvcustom::msg::TIMESYNC packet_in{};
    packet_in.tc1 = 93372036854775807LL;
    packet_in.ts1 = 170LL;
    packet_in.target_system = 53;
    packet_in.target_component = 120;

    mavlink::ugvcustom::msg::TIMESYNC packet2{};

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

TEST(ugvcustom, COMMAND_LONG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::COMMAND_LONG packet_in{};
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

    mavlink::ugvcustom::msg::COMMAND_LONG packet1{};
    mavlink::ugvcustom::msg::COMMAND_LONG packet2{};

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
TEST(ugvcustom_interop, COMMAND_LONG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_command_long_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 18691, 223, 34, 101
    };

    mavlink::ugvcustom::msg::COMMAND_LONG packet_in{};
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

    mavlink::ugvcustom::msg::COMMAND_LONG packet2{};

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

TEST(ugvcustom, MANUAL_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::MANUAL_CONTROL packet_in{};
    packet_in.target = 163;
    packet_in.x = 17235;
    packet_in.y = 17339;
    packet_in.z = 17443;
    packet_in.r = 17547;
    packet_in.buttons = 17651;
    packet_in.buttons2 = 17807;
    packet_in.enabled_extensions = 108;
    packet_in.s = 17963;
    packet_in.t = 18067;
    packet_in.aux1 = 18171;
    packet_in.aux2 = 18275;
    packet_in.aux3 = 18379;
    packet_in.aux4 = 18483;
    packet_in.aux5 = 18587;
    packet_in.aux6 = 18691;

    mavlink::ugvcustom::msg::MANUAL_CONTROL packet1{};
    mavlink::ugvcustom::msg::MANUAL_CONTROL packet2{};

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
    EXPECT_EQ(packet1.buttons, packet2.buttons);
    EXPECT_EQ(packet1.buttons2, packet2.buttons2);
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
TEST(ugvcustom_interop, MANUAL_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_manual_control_t packet_c {
         17235, 17339, 17443, 17547, 17651, 163, 17807, 108, 17963, 18067, 18171, 18275, 18379, 18483, 18587, 18691
    };

    mavlink::ugvcustom::msg::MANUAL_CONTROL packet_in{};
    packet_in.target = 163;
    packet_in.x = 17235;
    packet_in.y = 17339;
    packet_in.z = 17443;
    packet_in.r = 17547;
    packet_in.buttons = 17651;
    packet_in.buttons2 = 17807;
    packet_in.enabled_extensions = 108;
    packet_in.s = 17963;
    packet_in.t = 18067;
    packet_in.aux1 = 18171;
    packet_in.aux2 = 18275;
    packet_in.aux3 = 18379;
    packet_in.aux4 = 18483;
    packet_in.aux5 = 18587;
    packet_in.aux6 = 18691;

    mavlink::ugvcustom::msg::MANUAL_CONTROL packet2{};

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
    EXPECT_EQ(packet_in.buttons, packet2.buttons);
    EXPECT_EQ(packet_in.buttons2, packet2.buttons2);
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

TEST(ugvcustom, RADIO_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::RADIO_STATUS packet_in{};
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;

    mavlink::ugvcustom::msg::RADIO_STATUS packet1{};
    mavlink::ugvcustom::msg::RADIO_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet1.fixed, packet2.fixed);
    EXPECT_EQ(packet1.rssi, packet2.rssi);
    EXPECT_EQ(packet1.remrssi, packet2.remrssi);
    EXPECT_EQ(packet1.txbuf, packet2.txbuf);
    EXPECT_EQ(packet1.noise, packet2.noise);
    EXPECT_EQ(packet1.remnoise, packet2.remnoise);
}

#ifdef TEST_INTEROP
TEST(ugvcustom_interop, RADIO_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_radio_status_t packet_c {
         17235, 17339, 17, 84, 151, 218, 29
    };

    mavlink::ugvcustom::msg::RADIO_STATUS packet_in{};
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;

    mavlink::ugvcustom::msg::RADIO_STATUS packet2{};

    mavlink_msg_radio_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet_in.fixed, packet2.fixed);
    EXPECT_EQ(packet_in.rssi, packet2.rssi);
    EXPECT_EQ(packet_in.remrssi, packet2.remrssi);
    EXPECT_EQ(packet_in.txbuf, packet2.txbuf);
    EXPECT_EQ(packet_in.noise, packet2.noise);
    EXPECT_EQ(packet_in.remnoise, packet2.remnoise);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvcustom, UGV_SYSTEM_INFO)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::UGV_SYSTEM_INFO packet_in{};
    packet_in.vcu_status = 137;
    packet_in.battery_soc = 18483;
    packet_in.comp_mode1 = 18587;
    packet_in.comp_mode2 = 204;
    packet_in.sensor_subsystem_health_1 = 18691;
    packet_in.sensor_subsystem_health_2 = 15;
    packet_in.sensor_subsystem_health_3 = 963497464;
    packet_in.sensor_subsystem_health_4 = 18795;
    packet_in.vcu_subsystem_status = 963497672;
    packet_in.comp_subsystem_status = 18899;
    packet_in.vcu_subsystem_power_state1 = 963497880;
    packet_in.vcu_power_subsystem_state2 = 82;
    packet_in.motor_faults = 963498088;
    packet_in.validity_motor_faults = 149;
    packet_in.mc_faults_1 = 19003;
    packet_in.mc_faults_2 = 216;
    packet_in.contactor_fault = 27;
    packet_in.pdu_fault = 94;
    packet_in.power_subsystem_faults1 = 19107;
    packet_in.power_subsystem_faults2 = 161;
    packet_in.vcu_interface_health = 19211;
    packet_in.sec_comp_status = 19315;
    packet_in.comp_interface_health1 = 228;
    packet_in.comp_interface_health2 = 19419;
    packet_in.home_location = 39;
    packet_in.lat = 963498296;
    packet_in.lon = 963498504;

    mavlink::ugvcustom::msg::UGV_SYSTEM_INFO packet1{};
    mavlink::ugvcustom::msg::UGV_SYSTEM_INFO packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.vcu_status, packet2.vcu_status);
    EXPECT_EQ(packet1.battery_soc, packet2.battery_soc);
    EXPECT_EQ(packet1.comp_mode1, packet2.comp_mode1);
    EXPECT_EQ(packet1.comp_mode2, packet2.comp_mode2);
    EXPECT_EQ(packet1.sensor_subsystem_health_1, packet2.sensor_subsystem_health_1);
    EXPECT_EQ(packet1.sensor_subsystem_health_2, packet2.sensor_subsystem_health_2);
    EXPECT_EQ(packet1.sensor_subsystem_health_3, packet2.sensor_subsystem_health_3);
    EXPECT_EQ(packet1.sensor_subsystem_health_4, packet2.sensor_subsystem_health_4);
    EXPECT_EQ(packet1.vcu_subsystem_status, packet2.vcu_subsystem_status);
    EXPECT_EQ(packet1.comp_subsystem_status, packet2.comp_subsystem_status);
    EXPECT_EQ(packet1.vcu_subsystem_power_state1, packet2.vcu_subsystem_power_state1);
    EXPECT_EQ(packet1.vcu_power_subsystem_state2, packet2.vcu_power_subsystem_state2);
    EXPECT_EQ(packet1.motor_faults, packet2.motor_faults);
    EXPECT_EQ(packet1.validity_motor_faults, packet2.validity_motor_faults);
    EXPECT_EQ(packet1.mc_faults_1, packet2.mc_faults_1);
    EXPECT_EQ(packet1.mc_faults_2, packet2.mc_faults_2);
    EXPECT_EQ(packet1.contactor_fault, packet2.contactor_fault);
    EXPECT_EQ(packet1.pdu_fault, packet2.pdu_fault);
    EXPECT_EQ(packet1.power_subsystem_faults1, packet2.power_subsystem_faults1);
    EXPECT_EQ(packet1.power_subsystem_faults2, packet2.power_subsystem_faults2);
    EXPECT_EQ(packet1.vcu_interface_health, packet2.vcu_interface_health);
    EXPECT_EQ(packet1.sec_comp_status, packet2.sec_comp_status);
    EXPECT_EQ(packet1.comp_interface_health1, packet2.comp_interface_health1);
    EXPECT_EQ(packet1.comp_interface_health2, packet2.comp_interface_health2);
    EXPECT_EQ(packet1.home_location, packet2.home_location);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lon, packet2.lon);
}

#ifdef TEST_INTEROP
TEST(ugvcustom_interop, UGV_SYSTEM_INFO)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ugv_system_info_t packet_c {
         963497464, 963497672, 963497880, 963498088, 963498296, 963498504, 18483, 18587, 18691, 18795, 18899, 19003, 19107, 19211, 19315, 19419, 137, 204, 15, 82, 149, 216, 27, 94, 161, 228, 39
    };

    mavlink::ugvcustom::msg::UGV_SYSTEM_INFO packet_in{};
    packet_in.vcu_status = 137;
    packet_in.battery_soc = 18483;
    packet_in.comp_mode1 = 18587;
    packet_in.comp_mode2 = 204;
    packet_in.sensor_subsystem_health_1 = 18691;
    packet_in.sensor_subsystem_health_2 = 15;
    packet_in.sensor_subsystem_health_3 = 963497464;
    packet_in.sensor_subsystem_health_4 = 18795;
    packet_in.vcu_subsystem_status = 963497672;
    packet_in.comp_subsystem_status = 18899;
    packet_in.vcu_subsystem_power_state1 = 963497880;
    packet_in.vcu_power_subsystem_state2 = 82;
    packet_in.motor_faults = 963498088;
    packet_in.validity_motor_faults = 149;
    packet_in.mc_faults_1 = 19003;
    packet_in.mc_faults_2 = 216;
    packet_in.contactor_fault = 27;
    packet_in.pdu_fault = 94;
    packet_in.power_subsystem_faults1 = 19107;
    packet_in.power_subsystem_faults2 = 161;
    packet_in.vcu_interface_health = 19211;
    packet_in.sec_comp_status = 19315;
    packet_in.comp_interface_health1 = 228;
    packet_in.comp_interface_health2 = 19419;
    packet_in.home_location = 39;
    packet_in.lat = 963498296;
    packet_in.lon = 963498504;

    mavlink::ugvcustom::msg::UGV_SYSTEM_INFO packet2{};

    mavlink_msg_ugv_system_info_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.vcu_status, packet2.vcu_status);
    EXPECT_EQ(packet_in.battery_soc, packet2.battery_soc);
    EXPECT_EQ(packet_in.comp_mode1, packet2.comp_mode1);
    EXPECT_EQ(packet_in.comp_mode2, packet2.comp_mode2);
    EXPECT_EQ(packet_in.sensor_subsystem_health_1, packet2.sensor_subsystem_health_1);
    EXPECT_EQ(packet_in.sensor_subsystem_health_2, packet2.sensor_subsystem_health_2);
    EXPECT_EQ(packet_in.sensor_subsystem_health_3, packet2.sensor_subsystem_health_3);
    EXPECT_EQ(packet_in.sensor_subsystem_health_4, packet2.sensor_subsystem_health_4);
    EXPECT_EQ(packet_in.vcu_subsystem_status, packet2.vcu_subsystem_status);
    EXPECT_EQ(packet_in.comp_subsystem_status, packet2.comp_subsystem_status);
    EXPECT_EQ(packet_in.vcu_subsystem_power_state1, packet2.vcu_subsystem_power_state1);
    EXPECT_EQ(packet_in.vcu_power_subsystem_state2, packet2.vcu_power_subsystem_state2);
    EXPECT_EQ(packet_in.motor_faults, packet2.motor_faults);
    EXPECT_EQ(packet_in.validity_motor_faults, packet2.validity_motor_faults);
    EXPECT_EQ(packet_in.mc_faults_1, packet2.mc_faults_1);
    EXPECT_EQ(packet_in.mc_faults_2, packet2.mc_faults_2);
    EXPECT_EQ(packet_in.contactor_fault, packet2.contactor_fault);
    EXPECT_EQ(packet_in.pdu_fault, packet2.pdu_fault);
    EXPECT_EQ(packet_in.power_subsystem_faults1, packet2.power_subsystem_faults1);
    EXPECT_EQ(packet_in.power_subsystem_faults2, packet2.power_subsystem_faults2);
    EXPECT_EQ(packet_in.vcu_interface_health, packet2.vcu_interface_health);
    EXPECT_EQ(packet_in.sec_comp_status, packet2.sec_comp_status);
    EXPECT_EQ(packet_in.comp_interface_health1, packet2.comp_interface_health1);
    EXPECT_EQ(packet_in.comp_interface_health2, packet2.comp_interface_health2);
    EXPECT_EQ(packet_in.home_location, packet2.home_location);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lon, packet2.lon);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvcustom, SYSTEM_TIME)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::SYSTEM_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.time_boot_ms = 963497880;

    mavlink::ugvcustom::msg::SYSTEM_TIME packet1{};
    mavlink::ugvcustom::msg::SYSTEM_TIME packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
}

#ifdef TEST_INTEROP
TEST(ugvcustom_interop, SYSTEM_TIME)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_system_time_t packet_c {
         93372036854775807ULL, 963497880
    };

    mavlink::ugvcustom::msg::SYSTEM_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.time_boot_ms = 963497880;

    mavlink::ugvcustom::msg::SYSTEM_TIME packet2{};

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

TEST(ugvcustom, GPS_RAW_INT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::GPS_RAW_INT packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.lat = 963497880;
    packet_in.lon = 963498088;
    packet_in.alt = 963498296;
    packet_in.eph = 18275;
    packet_in.epv = 18379;
    packet_in.vel = 18483;
    packet_in.cog = 18587;
    packet_in.fix_type = 89;
    packet_in.satellites_visible = 156;

    mavlink::ugvcustom::msg::GPS_RAW_INT packet1{};
    mavlink::ugvcustom::msg::GPS_RAW_INT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lon, packet2.lon);
    EXPECT_EQ(packet1.alt, packet2.alt);
    EXPECT_EQ(packet1.eph, packet2.eph);
    EXPECT_EQ(packet1.epv, packet2.epv);
    EXPECT_EQ(packet1.vel, packet2.vel);
    EXPECT_EQ(packet1.cog, packet2.cog);
    EXPECT_EQ(packet1.fix_type, packet2.fix_type);
    EXPECT_EQ(packet1.satellites_visible, packet2.satellites_visible);
}

#ifdef TEST_INTEROP
TEST(ugvcustom_interop, GPS_RAW_INT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gps_raw_int_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 963498296, 18275, 18379, 18483, 18587, 89, 156
    };

    mavlink::ugvcustom::msg::GPS_RAW_INT packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.lat = 963497880;
    packet_in.lon = 963498088;
    packet_in.alt = 963498296;
    packet_in.eph = 18275;
    packet_in.epv = 18379;
    packet_in.vel = 18483;
    packet_in.cog = 18587;
    packet_in.fix_type = 89;
    packet_in.satellites_visible = 156;

    mavlink::ugvcustom::msg::GPS_RAW_INT packet2{};

    mavlink_msg_gps_raw_int_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lon, packet2.lon);
    EXPECT_EQ(packet_in.alt, packet2.alt);
    EXPECT_EQ(packet_in.eph, packet2.eph);
    EXPECT_EQ(packet_in.epv, packet2.epv);
    EXPECT_EQ(packet_in.vel, packet2.vel);
    EXPECT_EQ(packet_in.cog, packet2.cog);
    EXPECT_EQ(packet_in.fix_type, packet2.fix_type);
    EXPECT_EQ(packet_in.satellites_visible, packet2.satellites_visible);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ugvcustom, ATTITUDE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ugvcustom::msg::ATTITUDE packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.rollspeed = 129.0;
    packet_in.pitchspeed = 157.0;
    packet_in.yawspeed = 185.0;

    mavlink::ugvcustom::msg::ATTITUDE packet1{};
    mavlink::ugvcustom::msg::ATTITUDE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet1.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet1.yawspeed, packet2.yawspeed);
}

#ifdef TEST_INTEROP
TEST(ugvcustom_interop, ATTITUDE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::ugvcustom::msg::ATTITUDE packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.rollspeed = 129.0;
    packet_in.pitchspeed = 157.0;
    packet_in.yawspeed = 185.0;

    mavlink::ugvcustom::msg::ATTITUDE packet2{};

    mavlink_msg_attitude_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet_in.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet_in.yawspeed, packet2.yawspeed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
