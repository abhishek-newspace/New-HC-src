/** @file
 *    @brief MAVLink comm protocol testsuite generated from ugvcustom.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef UGVCUSTOM_TESTSUITE_H
#define UGVCUSTOM_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_ugvcustom(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_ugvcustom(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_heartbeat_t packet_in = {
        963497464,17,84,151,218,2
    };
    mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.custom_mode = packet_in.custom_mode;
        packet1.type = packet_in.type;
        packet1.autopilot = packet_in.autopilot;
        packet1.base_mode = packet_in.base_mode;
        packet1.system_status = packet_in.system_status;
        packet1.mavlink_version = packet_in.mavlink_version;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_timesync(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TIMESYNC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_timesync_t packet_in = {
        93372036854775807LL,93372036854776311LL,53,120
    };
    mavlink_timesync_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tc1 = packet_in.tc1;
        packet1.ts1 = packet_in.ts1;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TIMESYNC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TIMESYNC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_timesync_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_timesync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_timesync_pack(system_id, component_id, &msg , packet1.tc1 , packet1.ts1 , packet1.target_system , packet1.target_component );
    mavlink_msg_timesync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_timesync_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tc1 , packet1.ts1 , packet1.target_system , packet1.target_component );
    mavlink_msg_timesync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_timesync_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_timesync_send(MAVLINK_COMM_1 , packet1.tc1 , packet1.ts1 , packet1.target_system , packet1.target_component );
    mavlink_msg_timesync_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TIMESYNC") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TIMESYNC) != NULL);
#endif
}

static void mavlink_test_command_long(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COMMAND_LONG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_command_long_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,18691,223,34,101
    };
    mavlink_command_long_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.param5 = packet_in.param5;
        packet1.param6 = packet_in.param6;
        packet1.param7 = packet_in.param7;
        packet1.command = packet_in.command;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.confirmation = packet_in.confirmation;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_command_long_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_command_long_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_command_long_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_command_long_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_command_long_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_command_long_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_command_long_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_command_long_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.command , packet1.confirmation , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_command_long_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("COMMAND_LONG") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_COMMAND_LONG) != NULL);
#endif
}

static void mavlink_test_manual_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MANUAL_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_manual_control_t packet_in = {
        17235,17339,17443,17547,17651,163,17807,108,17963,18067,18171,18275,18379,18483,18587,18691
    };
    mavlink_manual_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.r = packet_in.r;
        packet1.buttons = packet_in.buttons;
        packet1.target = packet_in.target;
        packet1.buttons2 = packet_in.buttons2;
        packet1.enabled_extensions = packet_in.enabled_extensions;
        packet1.s = packet_in.s;
        packet1.t = packet_in.t;
        packet1.aux1 = packet_in.aux1;
        packet1.aux2 = packet_in.aux2;
        packet1.aux3 = packet_in.aux3;
        packet1.aux4 = packet_in.aux4;
        packet1.aux5 = packet_in.aux5;
        packet1.aux6 = packet_in.aux6;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_manual_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_manual_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_manual_control_pack(system_id, component_id, &msg , packet1.target , packet1.x , packet1.y , packet1.z , packet1.r , packet1.buttons , packet1.buttons2 , packet1.enabled_extensions , packet1.s , packet1.t , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.aux5 , packet1.aux6 );
    mavlink_msg_manual_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_manual_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target , packet1.x , packet1.y , packet1.z , packet1.r , packet1.buttons , packet1.buttons2 , packet1.enabled_extensions , packet1.s , packet1.t , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.aux5 , packet1.aux6 );
    mavlink_msg_manual_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_manual_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_manual_control_send(MAVLINK_COMM_1 , packet1.target , packet1.x , packet1.y , packet1.z , packet1.r , packet1.buttons , packet1.buttons2 , packet1.enabled_extensions , packet1.s , packet1.t , packet1.aux1 , packet1.aux2 , packet1.aux3 , packet1.aux4 , packet1.aux5 , packet1.aux6 );
    mavlink_msg_manual_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MANUAL_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MANUAL_CONTROL) != NULL);
#endif
}

static void mavlink_test_radio_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIO_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radio_status_t packet_in = {
        17235,17339,17,84,151,218,29
    };
    mavlink_radio_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rxerrors = packet_in.rxerrors;
        packet1.fixed = packet_in.fixed;
        packet1.rssi = packet_in.rssi;
        packet1.remrssi = packet_in.remrssi;
        packet1.txbuf = packet_in.txbuf;
        packet1.noise = packet_in.noise;
        packet1.remnoise = packet_in.remnoise;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_pack(system_id, component_id, &msg , packet1.rxerrors , packet1.fixed , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise );
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rxerrors , packet1.fixed , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise );
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radio_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_send(MAVLINK_COMM_1 , packet1.rxerrors , packet1.fixed , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise );
    mavlink_msg_radio_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIO_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIO_STATUS) != NULL);
#endif
}

static void mavlink_test_ugv_system_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_UGV_SYSTEM_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ugv_system_info_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,18483,18587,18691,18795,18899,19003,19107,19211,19315,19419,137,204,15,82,149,216,27,94,161,228,39
    };
    mavlink_ugv_system_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sensor_subsystem_health_3 = packet_in.sensor_subsystem_health_3;
        packet1.vcu_subsystem_status = packet_in.vcu_subsystem_status;
        packet1.vcu_subsystem_power_state1 = packet_in.vcu_subsystem_power_state1;
        packet1.motor_faults = packet_in.motor_faults;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.battery_soc = packet_in.battery_soc;
        packet1.comp_mode1 = packet_in.comp_mode1;
        packet1.sensor_subsystem_health_1 = packet_in.sensor_subsystem_health_1;
        packet1.sensor_subsystem_health_4 = packet_in.sensor_subsystem_health_4;
        packet1.comp_subsystem_status = packet_in.comp_subsystem_status;
        packet1.mc_faults_1 = packet_in.mc_faults_1;
        packet1.power_subsystem_faults1 = packet_in.power_subsystem_faults1;
        packet1.vcu_interface_health = packet_in.vcu_interface_health;
        packet1.sec_comp_status = packet_in.sec_comp_status;
        packet1.comp_interface_health2 = packet_in.comp_interface_health2;
        packet1.vcu_status = packet_in.vcu_status;
        packet1.comp_mode2 = packet_in.comp_mode2;
        packet1.sensor_subsystem_health_2 = packet_in.sensor_subsystem_health_2;
        packet1.vcu_power_subsystem_state2 = packet_in.vcu_power_subsystem_state2;
        packet1.validity_motor_faults = packet_in.validity_motor_faults;
        packet1.mc_faults_2 = packet_in.mc_faults_2;
        packet1.contactor_fault = packet_in.contactor_fault;
        packet1.pdu_fault = packet_in.pdu_fault;
        packet1.power_subsystem_faults2 = packet_in.power_subsystem_faults2;
        packet1.comp_interface_health1 = packet_in.comp_interface_health1;
        packet1.home_location = packet_in.home_location;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ugv_system_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ugv_system_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ugv_system_info_pack(system_id, component_id, &msg , packet1.vcu_status , packet1.battery_soc , packet1.comp_mode1 , packet1.comp_mode2 , packet1.sensor_subsystem_health_1 , packet1.sensor_subsystem_health_2 , packet1.sensor_subsystem_health_3 , packet1.sensor_subsystem_health_4 , packet1.vcu_subsystem_status , packet1.comp_subsystem_status , packet1.vcu_subsystem_power_state1 , packet1.vcu_power_subsystem_state2 , packet1.motor_faults , packet1.validity_motor_faults , packet1.mc_faults_1 , packet1.mc_faults_2 , packet1.contactor_fault , packet1.pdu_fault , packet1.power_subsystem_faults1 , packet1.power_subsystem_faults2 , packet1.vcu_interface_health , packet1.sec_comp_status , packet1.comp_interface_health1 , packet1.comp_interface_health2 , packet1.home_location , packet1.lat , packet1.lon );
    mavlink_msg_ugv_system_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ugv_system_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vcu_status , packet1.battery_soc , packet1.comp_mode1 , packet1.comp_mode2 , packet1.sensor_subsystem_health_1 , packet1.sensor_subsystem_health_2 , packet1.sensor_subsystem_health_3 , packet1.sensor_subsystem_health_4 , packet1.vcu_subsystem_status , packet1.comp_subsystem_status , packet1.vcu_subsystem_power_state1 , packet1.vcu_power_subsystem_state2 , packet1.motor_faults , packet1.validity_motor_faults , packet1.mc_faults_1 , packet1.mc_faults_2 , packet1.contactor_fault , packet1.pdu_fault , packet1.power_subsystem_faults1 , packet1.power_subsystem_faults2 , packet1.vcu_interface_health , packet1.sec_comp_status , packet1.comp_interface_health1 , packet1.comp_interface_health2 , packet1.home_location , packet1.lat , packet1.lon );
    mavlink_msg_ugv_system_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ugv_system_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ugv_system_info_send(MAVLINK_COMM_1 , packet1.vcu_status , packet1.battery_soc , packet1.comp_mode1 , packet1.comp_mode2 , packet1.sensor_subsystem_health_1 , packet1.sensor_subsystem_health_2 , packet1.sensor_subsystem_health_3 , packet1.sensor_subsystem_health_4 , packet1.vcu_subsystem_status , packet1.comp_subsystem_status , packet1.vcu_subsystem_power_state1 , packet1.vcu_power_subsystem_state2 , packet1.motor_faults , packet1.validity_motor_faults , packet1.mc_faults_1 , packet1.mc_faults_2 , packet1.contactor_fault , packet1.pdu_fault , packet1.power_subsystem_faults1 , packet1.power_subsystem_faults2 , packet1.vcu_interface_health , packet1.sec_comp_status , packet1.comp_interface_health1 , packet1.comp_interface_health2 , packet1.home_location , packet1.lat , packet1.lon );
    mavlink_msg_ugv_system_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("UGV_SYSTEM_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_UGV_SYSTEM_INFO) != NULL);
#endif
}

static void mavlink_test_system_time(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SYSTEM_TIME >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_system_time_t packet_in = {
        93372036854775807ULL,963497880
    };
    mavlink_system_time_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_unix_usec = packet_in.time_unix_usec;
        packet1.time_boot_ms = packet_in.time_boot_ms;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_time_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_system_time_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_time_pack(system_id, component_id, &msg , packet1.time_unix_usec , packet1.time_boot_ms );
    mavlink_msg_system_time_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_time_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_unix_usec , packet1.time_boot_ms );
    mavlink_msg_system_time_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_system_time_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_time_send(MAVLINK_COMM_1 , packet1.time_unix_usec , packet1.time_boot_ms );
    mavlink_msg_system_time_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SYSTEM_TIME") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SYSTEM_TIME) != NULL);
#endif
}

static void mavlink_test_gps_raw_int(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS_RAW_INT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gps_raw_int_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,18275,18379,18483,18587,89,156
    };
    mavlink_gps_raw_int_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.eph = packet_in.eph;
        packet1.epv = packet_in.epv;
        packet1.vel = packet_in.vel;
        packet1.cog = packet_in.cog;
        packet1.fix_type = packet_in.fix_type;
        packet1.satellites_visible = packet_in.satellites_visible;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_raw_int_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gps_raw_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_raw_int_pack(system_id, component_id, &msg , packet1.time_usec , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.cog , packet1.fix_type , packet1.satellites_visible );
    mavlink_msg_gps_raw_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_raw_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.cog , packet1.fix_type , packet1.satellites_visible );
    mavlink_msg_gps_raw_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gps_raw_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_raw_int_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.lat , packet1.lon , packet1.alt , packet1.eph , packet1.epv , packet1.vel , packet1.cog , packet1.fix_type , packet1.satellites_visible );
    mavlink_msg_gps_raw_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GPS_RAW_INT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GPS_RAW_INT) != NULL);
#endif
}

static void mavlink_test_attitude(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ATTITUDE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_attitude_t packet_in = {
        963497464,45.0,73.0,101.0,129.0,157.0,185.0
    };
    mavlink_attitude_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.rollspeed = packet_in.rollspeed;
        packet1.pitchspeed = packet_in.pitchspeed;
        packet1.yawspeed = packet_in.yawspeed;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ATTITUDE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ATTITUDE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_attitude_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_attitude_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
    mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_attitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
    mavlink_msg_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_attitude_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.rollspeed , packet1.pitchspeed , packet1.yawspeed );
    mavlink_msg_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ATTITUDE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ATTITUDE) != NULL);
#endif
}

static void mavlink_test_ugvcustom(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat(system_id, component_id, last_msg);
    mavlink_test_timesync(system_id, component_id, last_msg);
    mavlink_test_command_long(system_id, component_id, last_msg);
    mavlink_test_manual_control(system_id, component_id, last_msg);
    mavlink_test_radio_status(system_id, component_id, last_msg);
    mavlink_test_ugv_system_info(system_id, component_id, last_msg);
    mavlink_test_system_time(system_id, component_id, last_msg);
    mavlink_test_gps_raw_int(system_id, component_id, last_msg);
    mavlink_test_attitude(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // UGVCUSTOM_TESTSUITE_H
