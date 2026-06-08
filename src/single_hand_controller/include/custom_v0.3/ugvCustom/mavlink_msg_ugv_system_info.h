#pragma once
// MESSAGE UGV_SYSTEM_INFO PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO 50001


typedef struct __mavlink_ugv_system_info_t {
 uint8_t ts1_hour; /*<  no_definition*/
 uint8_t ts1_minute; /*<  no_definition*/
 uint8_t ts1_second; /*<  no_definition*/
 uint8_t subsystem_health_1; /*<  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        */
 uint8_t subsystem_health_2; /*<  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      */
 uint8_t subsystem_health_3; /*<  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      */
 uint8_t subsystem_health_4; /*<  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      */
 uint8_t ts2_hour; /*<  no_definition*/
 uint8_t ts2_minute; /*<  no_definition*/
 uint8_t ts2_second; /*<  no_definition*/
 uint8_t battery_soc; /*<  
          soc percentage of remaining battery
      */
 uint8_t main_mode; /*<  
        Current active main mode.
      */
 uint8_t sub_mode; /*<  
        Current active sub mode.
      */
 uint8_t speed_mode; /*<  
        Current active speed mode.
      */
 uint8_t drive_mode; /*<  
        Current active drive mode.
      */
 uint8_t arm_mode; /*<  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      */
 uint8_t intended_main_mode; /*<  
        Last main mode commanded by GCS.
      */
 uint8_t intended_sub_mode; /*<  
        Last sub mode commanded by GCS.
      */
 uint8_t intended_speed_mode; /*<  
        Last speed mode commanded by GCS.
      */
 uint8_t intended_drive_mode; /*<  
        Last drive mode commanded by GCS.
      */
 uint8_t intended_arm_mode; /*<  
        Last arm mode commanded by GCS.
      */
 uint8_t mode_change_reason; /*<  
        Reason for last mode transition.
      */
 uint8_t ts3_hour; /*<  no_definition*/
 uint8_t ts3_minute; /*<  no_definition*/
 uint8_t ts3_second; /*<  no_definition*/
 uint8_t rear_left_motor_faults; /*<  
        Rear Left Motor Faults
      */
 uint8_t rear_right_motor_faults; /*<  
        Rear Right Motor Faults
      */
 uint8_t front_left_motor_faults; /*<  
        Front Left Motor Faults
      */
 uint8_t front_right_motor_faults; /*<  
        Front Right Motor Faults
      */
 uint8_t rear_mc_faults; /*<  
        Rear Motor Controller Faults
      */
 uint8_t front_mc_faults; /*<  
        Front Motor Controller Faults
      */
 uint8_t rear_mc_voltage; /*<  Left Motor Controller Voltage (Unit: 0.1 V)*/
 uint8_t front_mc_voltage; /*<  Right Motor Controller Voltage (Unit: 0.1 V)*/
 uint8_t rear_mc_temperature; /*<  Left Motor Controller Temperature (Unit: 1 Degree Celsius)*/
 uint8_t front_mc_temperature; /*<  Right Motor Controller Temperature (Unit: 1 Degree Celsius)*/
 uint8_t light_status; /*<  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      */
 uint8_t pdu_channel_status; /*<  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      */
} mavlink_ugv_system_info_t;

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN 37
#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN 37
#define MAVLINK_MSG_ID_50001_LEN 37
#define MAVLINK_MSG_ID_50001_MIN_LEN 37

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC 128
#define MAVLINK_MSG_ID_50001_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    50001, \
    "UGV_SYSTEM_INFO", \
    37, \
    {  { "ts1_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_system_info_t, ts1_hour) }, \
         { "ts1_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ugv_system_info_t, ts1_minute) }, \
         { "ts1_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_ugv_system_info_t, ts1_second) }, \
         { "subsystem_health_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_ugv_system_info_t, subsystem_health_1) }, \
         { "subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ugv_system_info_t, subsystem_health_2) }, \
         { "subsystem_health_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ugv_system_info_t, subsystem_health_3) }, \
         { "subsystem_health_4", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ugv_system_info_t, subsystem_health_4) }, \
         { "ts2_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_ugv_system_info_t, ts2_hour) }, \
         { "ts2_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ugv_system_info_t, ts2_minute) }, \
         { "ts2_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ugv_system_info_t, ts2_second) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_ugv_system_info_t, main_mode) }, \
         { "sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ugv_system_info_t, sub_mode) }, \
         { "speed_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ugv_system_info_t, speed_mode) }, \
         { "drive_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_ugv_system_info_t, drive_mode) }, \
         { "arm_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_ugv_system_info_t, arm_mode) }, \
         { "intended_main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_ugv_system_info_t, intended_main_mode) }, \
         { "intended_sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_ugv_system_info_t, intended_sub_mode) }, \
         { "intended_speed_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_ugv_system_info_t, intended_speed_mode) }, \
         { "intended_drive_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_ugv_system_info_t, intended_drive_mode) }, \
         { "intended_arm_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_ugv_system_info_t, intended_arm_mode) }, \
         { "mode_change_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_ugv_system_info_t, mode_change_reason) }, \
         { "ts3_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_ugv_system_info_t, ts3_hour) }, \
         { "ts3_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_ugv_system_info_t, ts3_minute) }, \
         { "ts3_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_ugv_system_info_t, ts3_second) }, \
         { "rear_left_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_ugv_system_info_t, rear_left_motor_faults) }, \
         { "rear_right_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_ugv_system_info_t, rear_right_motor_faults) }, \
         { "front_left_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_ugv_system_info_t, front_left_motor_faults) }, \
         { "front_right_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_ugv_system_info_t, front_right_motor_faults) }, \
         { "rear_mc_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_ugv_system_info_t, rear_mc_faults) }, \
         { "front_mc_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_ugv_system_info_t, front_mc_faults) }, \
         { "rear_mc_voltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_ugv_system_info_t, rear_mc_voltage) }, \
         { "front_mc_voltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_ugv_system_info_t, front_mc_voltage) }, \
         { "rear_mc_temperature", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_ugv_system_info_t, rear_mc_temperature) }, \
         { "front_mc_temperature", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_ugv_system_info_t, front_mc_temperature) }, \
         { "light_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_ugv_system_info_t, light_status) }, \
         { "pdu_channel_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_ugv_system_info_t, pdu_channel_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    "UGV_SYSTEM_INFO", \
    37, \
    {  { "ts1_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_system_info_t, ts1_hour) }, \
         { "ts1_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ugv_system_info_t, ts1_minute) }, \
         { "ts1_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_ugv_system_info_t, ts1_second) }, \
         { "subsystem_health_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_ugv_system_info_t, subsystem_health_1) }, \
         { "subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ugv_system_info_t, subsystem_health_2) }, \
         { "subsystem_health_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ugv_system_info_t, subsystem_health_3) }, \
         { "subsystem_health_4", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ugv_system_info_t, subsystem_health_4) }, \
         { "ts2_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_ugv_system_info_t, ts2_hour) }, \
         { "ts2_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ugv_system_info_t, ts2_minute) }, \
         { "ts2_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ugv_system_info_t, ts2_second) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_ugv_system_info_t, main_mode) }, \
         { "sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ugv_system_info_t, sub_mode) }, \
         { "speed_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ugv_system_info_t, speed_mode) }, \
         { "drive_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_ugv_system_info_t, drive_mode) }, \
         { "arm_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_ugv_system_info_t, arm_mode) }, \
         { "intended_main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_ugv_system_info_t, intended_main_mode) }, \
         { "intended_sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_ugv_system_info_t, intended_sub_mode) }, \
         { "intended_speed_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_ugv_system_info_t, intended_speed_mode) }, \
         { "intended_drive_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_ugv_system_info_t, intended_drive_mode) }, \
         { "intended_arm_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_ugv_system_info_t, intended_arm_mode) }, \
         { "mode_change_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_ugv_system_info_t, mode_change_reason) }, \
         { "ts3_hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_ugv_system_info_t, ts3_hour) }, \
         { "ts3_minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_ugv_system_info_t, ts3_minute) }, \
         { "ts3_second", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_ugv_system_info_t, ts3_second) }, \
         { "rear_left_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_ugv_system_info_t, rear_left_motor_faults) }, \
         { "rear_right_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_ugv_system_info_t, rear_right_motor_faults) }, \
         { "front_left_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_ugv_system_info_t, front_left_motor_faults) }, \
         { "front_right_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_ugv_system_info_t, front_right_motor_faults) }, \
         { "rear_mc_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_ugv_system_info_t, rear_mc_faults) }, \
         { "front_mc_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_ugv_system_info_t, front_mc_faults) }, \
         { "rear_mc_voltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_ugv_system_info_t, rear_mc_voltage) }, \
         { "front_mc_voltage", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_ugv_system_info_t, front_mc_voltage) }, \
         { "rear_mc_temperature", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_ugv_system_info_t, rear_mc_temperature) }, \
         { "front_mc_temperature", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_ugv_system_info_t, front_mc_temperature) }, \
         { "light_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_ugv_system_info_t, light_status) }, \
         { "pdu_channel_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_ugv_system_info_t, pdu_channel_status) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ts1_hour  no_definition
 * @param ts1_minute  no_definition
 * @param ts1_second  no_definition
 * @param subsystem_health_1  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        
 * @param subsystem_health_2  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      
 * @param subsystem_health_3  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      
 * @param subsystem_health_4  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      
 * @param ts2_hour  no_definition
 * @param ts2_minute  no_definition
 * @param ts2_second  no_definition
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param speed_mode  
        Current active speed mode.
      
 * @param drive_mode  
        Current active drive mode.
      
 * @param arm_mode  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param intended_speed_mode  
        Last speed mode commanded by GCS.
      
 * @param intended_drive_mode  
        Last drive mode commanded by GCS.
      
 * @param intended_arm_mode  
        Last arm mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @param ts3_hour  no_definition
 * @param ts3_minute  no_definition
 * @param ts3_second  no_definition
 * @param rear_left_motor_faults  
        Rear Left Motor Faults
      
 * @param rear_right_motor_faults  
        Rear Right Motor Faults
      
 * @param front_left_motor_faults  
        Front Left Motor Faults
      
 * @param front_right_motor_faults  
        Front Right Motor Faults
      
 * @param rear_mc_faults  
        Rear Motor Controller Faults
      
 * @param front_mc_faults  
        Front Motor Controller Faults
      
 * @param rear_mc_voltage  Left Motor Controller Voltage (Unit: 0.1 V)
 * @param front_mc_voltage  Right Motor Controller Voltage (Unit: 0.1 V)
 * @param rear_mc_temperature  Left Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param front_mc_temperature  Right Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param light_status  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      
 * @param pdu_channel_status  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ts1_hour, uint8_t ts1_minute, uint8_t ts1_second, uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t ts2_hour, uint8_t ts2_minute, uint8_t ts2_second, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t speed_mode, uint8_t drive_mode, uint8_t arm_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t intended_speed_mode, uint8_t intended_drive_mode, uint8_t intended_arm_mode, uint8_t mode_change_reason, uint8_t ts3_hour, uint8_t ts3_minute, uint8_t ts3_second, uint8_t rear_left_motor_faults, uint8_t rear_right_motor_faults, uint8_t front_left_motor_faults, uint8_t front_right_motor_faults, uint8_t rear_mc_faults, uint8_t front_mc_faults, uint8_t rear_mc_voltage, uint8_t front_mc_voltage, uint8_t rear_mc_temperature, uint8_t front_mc_temperature, uint8_t light_status, uint8_t pdu_channel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, ts1_hour);
    _mav_put_uint8_t(buf, 1, ts1_minute);
    _mav_put_uint8_t(buf, 2, ts1_second);
    _mav_put_uint8_t(buf, 3, subsystem_health_1);
    _mav_put_uint8_t(buf, 4, subsystem_health_2);
    _mav_put_uint8_t(buf, 5, subsystem_health_3);
    _mav_put_uint8_t(buf, 6, subsystem_health_4);
    _mav_put_uint8_t(buf, 7, ts2_hour);
    _mav_put_uint8_t(buf, 8, ts2_minute);
    _mav_put_uint8_t(buf, 9, ts2_second);
    _mav_put_uint8_t(buf, 10, battery_soc);
    _mav_put_uint8_t(buf, 11, main_mode);
    _mav_put_uint8_t(buf, 12, sub_mode);
    _mav_put_uint8_t(buf, 13, speed_mode);
    _mav_put_uint8_t(buf, 14, drive_mode);
    _mav_put_uint8_t(buf, 15, arm_mode);
    _mav_put_uint8_t(buf, 16, intended_main_mode);
    _mav_put_uint8_t(buf, 17, intended_sub_mode);
    _mav_put_uint8_t(buf, 18, intended_speed_mode);
    _mav_put_uint8_t(buf, 19, intended_drive_mode);
    _mav_put_uint8_t(buf, 20, intended_arm_mode);
    _mav_put_uint8_t(buf, 21, mode_change_reason);
    _mav_put_uint8_t(buf, 22, ts3_hour);
    _mav_put_uint8_t(buf, 23, ts3_minute);
    _mav_put_uint8_t(buf, 24, ts3_second);
    _mav_put_uint8_t(buf, 25, rear_left_motor_faults);
    _mav_put_uint8_t(buf, 26, rear_right_motor_faults);
    _mav_put_uint8_t(buf, 27, front_left_motor_faults);
    _mav_put_uint8_t(buf, 28, front_right_motor_faults);
    _mav_put_uint8_t(buf, 29, rear_mc_faults);
    _mav_put_uint8_t(buf, 30, front_mc_faults);
    _mav_put_uint8_t(buf, 31, rear_mc_voltage);
    _mav_put_uint8_t(buf, 32, front_mc_voltage);
    _mav_put_uint8_t(buf, 33, rear_mc_temperature);
    _mav_put_uint8_t(buf, 34, front_mc_temperature);
    _mav_put_uint8_t(buf, 35, light_status);
    _mav_put_uint8_t(buf, 36, pdu_channel_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ts1_hour = ts1_hour;
    packet.ts1_minute = ts1_minute;
    packet.ts1_second = ts1_second;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.ts2_hour = ts2_hour;
    packet.ts2_minute = ts2_minute;
    packet.ts2_second = ts2_second;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.speed_mode = speed_mode;
    packet.drive_mode = drive_mode;
    packet.arm_mode = arm_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.intended_speed_mode = intended_speed_mode;
    packet.intended_drive_mode = intended_drive_mode;
    packet.intended_arm_mode = intended_arm_mode;
    packet.mode_change_reason = mode_change_reason;
    packet.ts3_hour = ts3_hour;
    packet.ts3_minute = ts3_minute;
    packet.ts3_second = ts3_second;
    packet.rear_left_motor_faults = rear_left_motor_faults;
    packet.rear_right_motor_faults = rear_right_motor_faults;
    packet.front_left_motor_faults = front_left_motor_faults;
    packet.front_right_motor_faults = front_right_motor_faults;
    packet.rear_mc_faults = rear_mc_faults;
    packet.front_mc_faults = front_mc_faults;
    packet.rear_mc_voltage = rear_mc_voltage;
    packet.front_mc_voltage = front_mc_voltage;
    packet.rear_mc_temperature = rear_mc_temperature;
    packet.front_mc_temperature = front_mc_temperature;
    packet.light_status = light_status;
    packet.pdu_channel_status = pdu_channel_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
}

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param ts1_hour  no_definition
 * @param ts1_minute  no_definition
 * @param ts1_second  no_definition
 * @param subsystem_health_1  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        
 * @param subsystem_health_2  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      
 * @param subsystem_health_3  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      
 * @param subsystem_health_4  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      
 * @param ts2_hour  no_definition
 * @param ts2_minute  no_definition
 * @param ts2_second  no_definition
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param speed_mode  
        Current active speed mode.
      
 * @param drive_mode  
        Current active drive mode.
      
 * @param arm_mode  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param intended_speed_mode  
        Last speed mode commanded by GCS.
      
 * @param intended_drive_mode  
        Last drive mode commanded by GCS.
      
 * @param intended_arm_mode  
        Last arm mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @param ts3_hour  no_definition
 * @param ts3_minute  no_definition
 * @param ts3_second  no_definition
 * @param rear_left_motor_faults  
        Rear Left Motor Faults
      
 * @param rear_right_motor_faults  
        Rear Right Motor Faults
      
 * @param front_left_motor_faults  
        Front Left Motor Faults
      
 * @param front_right_motor_faults  
        Front Right Motor Faults
      
 * @param rear_mc_faults  
        Rear Motor Controller Faults
      
 * @param front_mc_faults  
        Front Motor Controller Faults
      
 * @param rear_mc_voltage  Left Motor Controller Voltage (Unit: 0.1 V)
 * @param front_mc_voltage  Right Motor Controller Voltage (Unit: 0.1 V)
 * @param rear_mc_temperature  Left Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param front_mc_temperature  Right Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param light_status  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      
 * @param pdu_channel_status  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t ts1_hour, uint8_t ts1_minute, uint8_t ts1_second, uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t ts2_hour, uint8_t ts2_minute, uint8_t ts2_second, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t speed_mode, uint8_t drive_mode, uint8_t arm_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t intended_speed_mode, uint8_t intended_drive_mode, uint8_t intended_arm_mode, uint8_t mode_change_reason, uint8_t ts3_hour, uint8_t ts3_minute, uint8_t ts3_second, uint8_t rear_left_motor_faults, uint8_t rear_right_motor_faults, uint8_t front_left_motor_faults, uint8_t front_right_motor_faults, uint8_t rear_mc_faults, uint8_t front_mc_faults, uint8_t rear_mc_voltage, uint8_t front_mc_voltage, uint8_t rear_mc_temperature, uint8_t front_mc_temperature, uint8_t light_status, uint8_t pdu_channel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, ts1_hour);
    _mav_put_uint8_t(buf, 1, ts1_minute);
    _mav_put_uint8_t(buf, 2, ts1_second);
    _mav_put_uint8_t(buf, 3, subsystem_health_1);
    _mav_put_uint8_t(buf, 4, subsystem_health_2);
    _mav_put_uint8_t(buf, 5, subsystem_health_3);
    _mav_put_uint8_t(buf, 6, subsystem_health_4);
    _mav_put_uint8_t(buf, 7, ts2_hour);
    _mav_put_uint8_t(buf, 8, ts2_minute);
    _mav_put_uint8_t(buf, 9, ts2_second);
    _mav_put_uint8_t(buf, 10, battery_soc);
    _mav_put_uint8_t(buf, 11, main_mode);
    _mav_put_uint8_t(buf, 12, sub_mode);
    _mav_put_uint8_t(buf, 13, speed_mode);
    _mav_put_uint8_t(buf, 14, drive_mode);
    _mav_put_uint8_t(buf, 15, arm_mode);
    _mav_put_uint8_t(buf, 16, intended_main_mode);
    _mav_put_uint8_t(buf, 17, intended_sub_mode);
    _mav_put_uint8_t(buf, 18, intended_speed_mode);
    _mav_put_uint8_t(buf, 19, intended_drive_mode);
    _mav_put_uint8_t(buf, 20, intended_arm_mode);
    _mav_put_uint8_t(buf, 21, mode_change_reason);
    _mav_put_uint8_t(buf, 22, ts3_hour);
    _mav_put_uint8_t(buf, 23, ts3_minute);
    _mav_put_uint8_t(buf, 24, ts3_second);
    _mav_put_uint8_t(buf, 25, rear_left_motor_faults);
    _mav_put_uint8_t(buf, 26, rear_right_motor_faults);
    _mav_put_uint8_t(buf, 27, front_left_motor_faults);
    _mav_put_uint8_t(buf, 28, front_right_motor_faults);
    _mav_put_uint8_t(buf, 29, rear_mc_faults);
    _mav_put_uint8_t(buf, 30, front_mc_faults);
    _mav_put_uint8_t(buf, 31, rear_mc_voltage);
    _mav_put_uint8_t(buf, 32, front_mc_voltage);
    _mav_put_uint8_t(buf, 33, rear_mc_temperature);
    _mav_put_uint8_t(buf, 34, front_mc_temperature);
    _mav_put_uint8_t(buf, 35, light_status);
    _mav_put_uint8_t(buf, 36, pdu_channel_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ts1_hour = ts1_hour;
    packet.ts1_minute = ts1_minute;
    packet.ts1_second = ts1_second;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.ts2_hour = ts2_hour;
    packet.ts2_minute = ts2_minute;
    packet.ts2_second = ts2_second;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.speed_mode = speed_mode;
    packet.drive_mode = drive_mode;
    packet.arm_mode = arm_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.intended_speed_mode = intended_speed_mode;
    packet.intended_drive_mode = intended_drive_mode;
    packet.intended_arm_mode = intended_arm_mode;
    packet.mode_change_reason = mode_change_reason;
    packet.ts3_hour = ts3_hour;
    packet.ts3_minute = ts3_minute;
    packet.ts3_second = ts3_second;
    packet.rear_left_motor_faults = rear_left_motor_faults;
    packet.rear_right_motor_faults = rear_right_motor_faults;
    packet.front_left_motor_faults = front_left_motor_faults;
    packet.front_right_motor_faults = front_right_motor_faults;
    packet.rear_mc_faults = rear_mc_faults;
    packet.front_mc_faults = front_mc_faults;
    packet.rear_mc_voltage = rear_mc_voltage;
    packet.front_mc_voltage = front_mc_voltage;
    packet.rear_mc_temperature = rear_mc_temperature;
    packet.front_mc_temperature = front_mc_temperature;
    packet.light_status = light_status;
    packet.pdu_channel_status = pdu_channel_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif
}

/**
 * @brief Pack a ugv_system_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ts1_hour  no_definition
 * @param ts1_minute  no_definition
 * @param ts1_second  no_definition
 * @param subsystem_health_1  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        
 * @param subsystem_health_2  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      
 * @param subsystem_health_3  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      
 * @param subsystem_health_4  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      
 * @param ts2_hour  no_definition
 * @param ts2_minute  no_definition
 * @param ts2_second  no_definition
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param speed_mode  
        Current active speed mode.
      
 * @param drive_mode  
        Current active drive mode.
      
 * @param arm_mode  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param intended_speed_mode  
        Last speed mode commanded by GCS.
      
 * @param intended_drive_mode  
        Last drive mode commanded by GCS.
      
 * @param intended_arm_mode  
        Last arm mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @param ts3_hour  no_definition
 * @param ts3_minute  no_definition
 * @param ts3_second  no_definition
 * @param rear_left_motor_faults  
        Rear Left Motor Faults
      
 * @param rear_right_motor_faults  
        Rear Right Motor Faults
      
 * @param front_left_motor_faults  
        Front Left Motor Faults
      
 * @param front_right_motor_faults  
        Front Right Motor Faults
      
 * @param rear_mc_faults  
        Rear Motor Controller Faults
      
 * @param front_mc_faults  
        Front Motor Controller Faults
      
 * @param rear_mc_voltage  Left Motor Controller Voltage (Unit: 0.1 V)
 * @param front_mc_voltage  Right Motor Controller Voltage (Unit: 0.1 V)
 * @param rear_mc_temperature  Left Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param front_mc_temperature  Right Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param light_status  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      
 * @param pdu_channel_status  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ts1_hour,uint8_t ts1_minute,uint8_t ts1_second,uint8_t subsystem_health_1,uint8_t subsystem_health_2,uint8_t subsystem_health_3,uint8_t subsystem_health_4,uint8_t ts2_hour,uint8_t ts2_minute,uint8_t ts2_second,uint8_t battery_soc,uint8_t main_mode,uint8_t sub_mode,uint8_t speed_mode,uint8_t drive_mode,uint8_t arm_mode,uint8_t intended_main_mode,uint8_t intended_sub_mode,uint8_t intended_speed_mode,uint8_t intended_drive_mode,uint8_t intended_arm_mode,uint8_t mode_change_reason,uint8_t ts3_hour,uint8_t ts3_minute,uint8_t ts3_second,uint8_t rear_left_motor_faults,uint8_t rear_right_motor_faults,uint8_t front_left_motor_faults,uint8_t front_right_motor_faults,uint8_t rear_mc_faults,uint8_t front_mc_faults,uint8_t rear_mc_voltage,uint8_t front_mc_voltage,uint8_t rear_mc_temperature,uint8_t front_mc_temperature,uint8_t light_status,uint8_t pdu_channel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, ts1_hour);
    _mav_put_uint8_t(buf, 1, ts1_minute);
    _mav_put_uint8_t(buf, 2, ts1_second);
    _mav_put_uint8_t(buf, 3, subsystem_health_1);
    _mav_put_uint8_t(buf, 4, subsystem_health_2);
    _mav_put_uint8_t(buf, 5, subsystem_health_3);
    _mav_put_uint8_t(buf, 6, subsystem_health_4);
    _mav_put_uint8_t(buf, 7, ts2_hour);
    _mav_put_uint8_t(buf, 8, ts2_minute);
    _mav_put_uint8_t(buf, 9, ts2_second);
    _mav_put_uint8_t(buf, 10, battery_soc);
    _mav_put_uint8_t(buf, 11, main_mode);
    _mav_put_uint8_t(buf, 12, sub_mode);
    _mav_put_uint8_t(buf, 13, speed_mode);
    _mav_put_uint8_t(buf, 14, drive_mode);
    _mav_put_uint8_t(buf, 15, arm_mode);
    _mav_put_uint8_t(buf, 16, intended_main_mode);
    _mav_put_uint8_t(buf, 17, intended_sub_mode);
    _mav_put_uint8_t(buf, 18, intended_speed_mode);
    _mav_put_uint8_t(buf, 19, intended_drive_mode);
    _mav_put_uint8_t(buf, 20, intended_arm_mode);
    _mav_put_uint8_t(buf, 21, mode_change_reason);
    _mav_put_uint8_t(buf, 22, ts3_hour);
    _mav_put_uint8_t(buf, 23, ts3_minute);
    _mav_put_uint8_t(buf, 24, ts3_second);
    _mav_put_uint8_t(buf, 25, rear_left_motor_faults);
    _mav_put_uint8_t(buf, 26, rear_right_motor_faults);
    _mav_put_uint8_t(buf, 27, front_left_motor_faults);
    _mav_put_uint8_t(buf, 28, front_right_motor_faults);
    _mav_put_uint8_t(buf, 29, rear_mc_faults);
    _mav_put_uint8_t(buf, 30, front_mc_faults);
    _mav_put_uint8_t(buf, 31, rear_mc_voltage);
    _mav_put_uint8_t(buf, 32, front_mc_voltage);
    _mav_put_uint8_t(buf, 33, rear_mc_temperature);
    _mav_put_uint8_t(buf, 34, front_mc_temperature);
    _mav_put_uint8_t(buf, 35, light_status);
    _mav_put_uint8_t(buf, 36, pdu_channel_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ts1_hour = ts1_hour;
    packet.ts1_minute = ts1_minute;
    packet.ts1_second = ts1_second;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.ts2_hour = ts2_hour;
    packet.ts2_minute = ts2_minute;
    packet.ts2_second = ts2_second;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.speed_mode = speed_mode;
    packet.drive_mode = drive_mode;
    packet.arm_mode = arm_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.intended_speed_mode = intended_speed_mode;
    packet.intended_drive_mode = intended_drive_mode;
    packet.intended_arm_mode = intended_arm_mode;
    packet.mode_change_reason = mode_change_reason;
    packet.ts3_hour = ts3_hour;
    packet.ts3_minute = ts3_minute;
    packet.ts3_second = ts3_second;
    packet.rear_left_motor_faults = rear_left_motor_faults;
    packet.rear_right_motor_faults = rear_right_motor_faults;
    packet.front_left_motor_faults = front_left_motor_faults;
    packet.front_right_motor_faults = front_right_motor_faults;
    packet.rear_mc_faults = rear_mc_faults;
    packet.front_mc_faults = front_mc_faults;
    packet.rear_mc_voltage = rear_mc_voltage;
    packet.front_mc_voltage = front_mc_voltage;
    packet.rear_mc_temperature = rear_mc_temperature;
    packet.front_mc_temperature = front_mc_temperature;
    packet.light_status = light_status;
    packet.pdu_channel_status = pdu_channel_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
}

/**
 * @brief Encode a ugv_system_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack(system_id, component_id, msg, ugv_system_info->ts1_hour, ugv_system_info->ts1_minute, ugv_system_info->ts1_second, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->ts2_hour, ugv_system_info->ts2_minute, ugv_system_info->ts2_second, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->speed_mode, ugv_system_info->drive_mode, ugv_system_info->arm_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->intended_speed_mode, ugv_system_info->intended_drive_mode, ugv_system_info->intended_arm_mode, ugv_system_info->mode_change_reason, ugv_system_info->ts3_hour, ugv_system_info->ts3_minute, ugv_system_info->ts3_second, ugv_system_info->rear_left_motor_faults, ugv_system_info->rear_right_motor_faults, ugv_system_info->front_left_motor_faults, ugv_system_info->front_right_motor_faults, ugv_system_info->rear_mc_faults, ugv_system_info->front_mc_faults, ugv_system_info->rear_mc_voltage, ugv_system_info->front_mc_voltage, ugv_system_info->rear_mc_temperature, ugv_system_info->front_mc_temperature, ugv_system_info->light_status, ugv_system_info->pdu_channel_status);
}

/**
 * @brief Encode a ugv_system_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack_chan(system_id, component_id, chan, msg, ugv_system_info->ts1_hour, ugv_system_info->ts1_minute, ugv_system_info->ts1_second, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->ts2_hour, ugv_system_info->ts2_minute, ugv_system_info->ts2_second, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->speed_mode, ugv_system_info->drive_mode, ugv_system_info->arm_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->intended_speed_mode, ugv_system_info->intended_drive_mode, ugv_system_info->intended_arm_mode, ugv_system_info->mode_change_reason, ugv_system_info->ts3_hour, ugv_system_info->ts3_minute, ugv_system_info->ts3_second, ugv_system_info->rear_left_motor_faults, ugv_system_info->rear_right_motor_faults, ugv_system_info->front_left_motor_faults, ugv_system_info->front_right_motor_faults, ugv_system_info->rear_mc_faults, ugv_system_info->front_mc_faults, ugv_system_info->rear_mc_voltage, ugv_system_info->front_mc_voltage, ugv_system_info->rear_mc_temperature, ugv_system_info->front_mc_temperature, ugv_system_info->light_status, ugv_system_info->pdu_channel_status);
}

/**
 * @brief Encode a ugv_system_info struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack_status(system_id, component_id, _status, msg,  ugv_system_info->ts1_hour, ugv_system_info->ts1_minute, ugv_system_info->ts1_second, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->ts2_hour, ugv_system_info->ts2_minute, ugv_system_info->ts2_second, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->speed_mode, ugv_system_info->drive_mode, ugv_system_info->arm_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->intended_speed_mode, ugv_system_info->intended_drive_mode, ugv_system_info->intended_arm_mode, ugv_system_info->mode_change_reason, ugv_system_info->ts3_hour, ugv_system_info->ts3_minute, ugv_system_info->ts3_second, ugv_system_info->rear_left_motor_faults, ugv_system_info->rear_right_motor_faults, ugv_system_info->front_left_motor_faults, ugv_system_info->front_right_motor_faults, ugv_system_info->rear_mc_faults, ugv_system_info->front_mc_faults, ugv_system_info->rear_mc_voltage, ugv_system_info->front_mc_voltage, ugv_system_info->rear_mc_temperature, ugv_system_info->front_mc_temperature, ugv_system_info->light_status, ugv_system_info->pdu_channel_status);
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 *
 * @param ts1_hour  no_definition
 * @param ts1_minute  no_definition
 * @param ts1_second  no_definition
 * @param subsystem_health_1  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        
 * @param subsystem_health_2  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      
 * @param subsystem_health_3  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      
 * @param subsystem_health_4  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      
 * @param ts2_hour  no_definition
 * @param ts2_minute  no_definition
 * @param ts2_second  no_definition
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param speed_mode  
        Current active speed mode.
      
 * @param drive_mode  
        Current active drive mode.
      
 * @param arm_mode  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param intended_speed_mode  
        Last speed mode commanded by GCS.
      
 * @param intended_drive_mode  
        Last drive mode commanded by GCS.
      
 * @param intended_arm_mode  
        Last arm mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @param ts3_hour  no_definition
 * @param ts3_minute  no_definition
 * @param ts3_second  no_definition
 * @param rear_left_motor_faults  
        Rear Left Motor Faults
      
 * @param rear_right_motor_faults  
        Rear Right Motor Faults
      
 * @param front_left_motor_faults  
        Front Left Motor Faults
      
 * @param front_right_motor_faults  
        Front Right Motor Faults
      
 * @param rear_mc_faults  
        Rear Motor Controller Faults
      
 * @param front_mc_faults  
        Front Motor Controller Faults
      
 * @param rear_mc_voltage  Left Motor Controller Voltage (Unit: 0.1 V)
 * @param front_mc_voltage  Right Motor Controller Voltage (Unit: 0.1 V)
 * @param rear_mc_temperature  Left Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param front_mc_temperature  Right Motor Controller Temperature (Unit: 1 Degree Celsius)
 * @param light_status  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      
 * @param pdu_channel_status  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_system_info_send(mavlink_channel_t chan, uint8_t ts1_hour, uint8_t ts1_minute, uint8_t ts1_second, uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t ts2_hour, uint8_t ts2_minute, uint8_t ts2_second, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t speed_mode, uint8_t drive_mode, uint8_t arm_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t intended_speed_mode, uint8_t intended_drive_mode, uint8_t intended_arm_mode, uint8_t mode_change_reason, uint8_t ts3_hour, uint8_t ts3_minute, uint8_t ts3_second, uint8_t rear_left_motor_faults, uint8_t rear_right_motor_faults, uint8_t front_left_motor_faults, uint8_t front_right_motor_faults, uint8_t rear_mc_faults, uint8_t front_mc_faults, uint8_t rear_mc_voltage, uint8_t front_mc_voltage, uint8_t rear_mc_temperature, uint8_t front_mc_temperature, uint8_t light_status, uint8_t pdu_channel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, ts1_hour);
    _mav_put_uint8_t(buf, 1, ts1_minute);
    _mav_put_uint8_t(buf, 2, ts1_second);
    _mav_put_uint8_t(buf, 3, subsystem_health_1);
    _mav_put_uint8_t(buf, 4, subsystem_health_2);
    _mav_put_uint8_t(buf, 5, subsystem_health_3);
    _mav_put_uint8_t(buf, 6, subsystem_health_4);
    _mav_put_uint8_t(buf, 7, ts2_hour);
    _mav_put_uint8_t(buf, 8, ts2_minute);
    _mav_put_uint8_t(buf, 9, ts2_second);
    _mav_put_uint8_t(buf, 10, battery_soc);
    _mav_put_uint8_t(buf, 11, main_mode);
    _mav_put_uint8_t(buf, 12, sub_mode);
    _mav_put_uint8_t(buf, 13, speed_mode);
    _mav_put_uint8_t(buf, 14, drive_mode);
    _mav_put_uint8_t(buf, 15, arm_mode);
    _mav_put_uint8_t(buf, 16, intended_main_mode);
    _mav_put_uint8_t(buf, 17, intended_sub_mode);
    _mav_put_uint8_t(buf, 18, intended_speed_mode);
    _mav_put_uint8_t(buf, 19, intended_drive_mode);
    _mav_put_uint8_t(buf, 20, intended_arm_mode);
    _mav_put_uint8_t(buf, 21, mode_change_reason);
    _mav_put_uint8_t(buf, 22, ts3_hour);
    _mav_put_uint8_t(buf, 23, ts3_minute);
    _mav_put_uint8_t(buf, 24, ts3_second);
    _mav_put_uint8_t(buf, 25, rear_left_motor_faults);
    _mav_put_uint8_t(buf, 26, rear_right_motor_faults);
    _mav_put_uint8_t(buf, 27, front_left_motor_faults);
    _mav_put_uint8_t(buf, 28, front_right_motor_faults);
    _mav_put_uint8_t(buf, 29, rear_mc_faults);
    _mav_put_uint8_t(buf, 30, front_mc_faults);
    _mav_put_uint8_t(buf, 31, rear_mc_voltage);
    _mav_put_uint8_t(buf, 32, front_mc_voltage);
    _mav_put_uint8_t(buf, 33, rear_mc_temperature);
    _mav_put_uint8_t(buf, 34, front_mc_temperature);
    _mav_put_uint8_t(buf, 35, light_status);
    _mav_put_uint8_t(buf, 36, pdu_channel_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t packet;
    packet.ts1_hour = ts1_hour;
    packet.ts1_minute = ts1_minute;
    packet.ts1_second = ts1_second;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.ts2_hour = ts2_hour;
    packet.ts2_minute = ts2_minute;
    packet.ts2_second = ts2_second;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.speed_mode = speed_mode;
    packet.drive_mode = drive_mode;
    packet.arm_mode = arm_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.intended_speed_mode = intended_speed_mode;
    packet.intended_drive_mode = intended_drive_mode;
    packet.intended_arm_mode = intended_arm_mode;
    packet.mode_change_reason = mode_change_reason;
    packet.ts3_hour = ts3_hour;
    packet.ts3_minute = ts3_minute;
    packet.ts3_second = ts3_second;
    packet.rear_left_motor_faults = rear_left_motor_faults;
    packet.rear_right_motor_faults = rear_right_motor_faults;
    packet.front_left_motor_faults = front_left_motor_faults;
    packet.front_right_motor_faults = front_right_motor_faults;
    packet.rear_mc_faults = rear_mc_faults;
    packet.front_mc_faults = front_mc_faults;
    packet.rear_mc_voltage = rear_mc_voltage;
    packet.front_mc_voltage = front_mc_voltage;
    packet.rear_mc_temperature = rear_mc_temperature;
    packet.front_mc_temperature = front_mc_temperature;
    packet.light_status = light_status;
    packet.pdu_channel_status = pdu_channel_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)&packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ugv_system_info_send_struct(mavlink_channel_t chan, const mavlink_ugv_system_info_t* ugv_system_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ugv_system_info_send(chan, ugv_system_info->ts1_hour, ugv_system_info->ts1_minute, ugv_system_info->ts1_second, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->ts2_hour, ugv_system_info->ts2_minute, ugv_system_info->ts2_second, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->speed_mode, ugv_system_info->drive_mode, ugv_system_info->arm_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->intended_speed_mode, ugv_system_info->intended_drive_mode, ugv_system_info->intended_arm_mode, ugv_system_info->mode_change_reason, ugv_system_info->ts3_hour, ugv_system_info->ts3_minute, ugv_system_info->ts3_second, ugv_system_info->rear_left_motor_faults, ugv_system_info->rear_right_motor_faults, ugv_system_info->front_left_motor_faults, ugv_system_info->front_right_motor_faults, ugv_system_info->rear_mc_faults, ugv_system_info->front_mc_faults, ugv_system_info->rear_mc_voltage, ugv_system_info->front_mc_voltage, ugv_system_info->rear_mc_temperature, ugv_system_info->front_mc_temperature, ugv_system_info->light_status, ugv_system_info->pdu_channel_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)ugv_system_info, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ugv_system_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ts1_hour, uint8_t ts1_minute, uint8_t ts1_second, uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t ts2_hour, uint8_t ts2_minute, uint8_t ts2_second, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t speed_mode, uint8_t drive_mode, uint8_t arm_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t intended_speed_mode, uint8_t intended_drive_mode, uint8_t intended_arm_mode, uint8_t mode_change_reason, uint8_t ts3_hour, uint8_t ts3_minute, uint8_t ts3_second, uint8_t rear_left_motor_faults, uint8_t rear_right_motor_faults, uint8_t front_left_motor_faults, uint8_t front_right_motor_faults, uint8_t rear_mc_faults, uint8_t front_mc_faults, uint8_t rear_mc_voltage, uint8_t front_mc_voltage, uint8_t rear_mc_temperature, uint8_t front_mc_temperature, uint8_t light_status, uint8_t pdu_channel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, ts1_hour);
    _mav_put_uint8_t(buf, 1, ts1_minute);
    _mav_put_uint8_t(buf, 2, ts1_second);
    _mav_put_uint8_t(buf, 3, subsystem_health_1);
    _mav_put_uint8_t(buf, 4, subsystem_health_2);
    _mav_put_uint8_t(buf, 5, subsystem_health_3);
    _mav_put_uint8_t(buf, 6, subsystem_health_4);
    _mav_put_uint8_t(buf, 7, ts2_hour);
    _mav_put_uint8_t(buf, 8, ts2_minute);
    _mav_put_uint8_t(buf, 9, ts2_second);
    _mav_put_uint8_t(buf, 10, battery_soc);
    _mav_put_uint8_t(buf, 11, main_mode);
    _mav_put_uint8_t(buf, 12, sub_mode);
    _mav_put_uint8_t(buf, 13, speed_mode);
    _mav_put_uint8_t(buf, 14, drive_mode);
    _mav_put_uint8_t(buf, 15, arm_mode);
    _mav_put_uint8_t(buf, 16, intended_main_mode);
    _mav_put_uint8_t(buf, 17, intended_sub_mode);
    _mav_put_uint8_t(buf, 18, intended_speed_mode);
    _mav_put_uint8_t(buf, 19, intended_drive_mode);
    _mav_put_uint8_t(buf, 20, intended_arm_mode);
    _mav_put_uint8_t(buf, 21, mode_change_reason);
    _mav_put_uint8_t(buf, 22, ts3_hour);
    _mav_put_uint8_t(buf, 23, ts3_minute);
    _mav_put_uint8_t(buf, 24, ts3_second);
    _mav_put_uint8_t(buf, 25, rear_left_motor_faults);
    _mav_put_uint8_t(buf, 26, rear_right_motor_faults);
    _mav_put_uint8_t(buf, 27, front_left_motor_faults);
    _mav_put_uint8_t(buf, 28, front_right_motor_faults);
    _mav_put_uint8_t(buf, 29, rear_mc_faults);
    _mav_put_uint8_t(buf, 30, front_mc_faults);
    _mav_put_uint8_t(buf, 31, rear_mc_voltage);
    _mav_put_uint8_t(buf, 32, front_mc_voltage);
    _mav_put_uint8_t(buf, 33, rear_mc_temperature);
    _mav_put_uint8_t(buf, 34, front_mc_temperature);
    _mav_put_uint8_t(buf, 35, light_status);
    _mav_put_uint8_t(buf, 36, pdu_channel_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t *packet = (mavlink_ugv_system_info_t *)msgbuf;
    packet->ts1_hour = ts1_hour;
    packet->ts1_minute = ts1_minute;
    packet->ts1_second = ts1_second;
    packet->subsystem_health_1 = subsystem_health_1;
    packet->subsystem_health_2 = subsystem_health_2;
    packet->subsystem_health_3 = subsystem_health_3;
    packet->subsystem_health_4 = subsystem_health_4;
    packet->ts2_hour = ts2_hour;
    packet->ts2_minute = ts2_minute;
    packet->ts2_second = ts2_second;
    packet->battery_soc = battery_soc;
    packet->main_mode = main_mode;
    packet->sub_mode = sub_mode;
    packet->speed_mode = speed_mode;
    packet->drive_mode = drive_mode;
    packet->arm_mode = arm_mode;
    packet->intended_main_mode = intended_main_mode;
    packet->intended_sub_mode = intended_sub_mode;
    packet->intended_speed_mode = intended_speed_mode;
    packet->intended_drive_mode = intended_drive_mode;
    packet->intended_arm_mode = intended_arm_mode;
    packet->mode_change_reason = mode_change_reason;
    packet->ts3_hour = ts3_hour;
    packet->ts3_minute = ts3_minute;
    packet->ts3_second = ts3_second;
    packet->rear_left_motor_faults = rear_left_motor_faults;
    packet->rear_right_motor_faults = rear_right_motor_faults;
    packet->front_left_motor_faults = front_left_motor_faults;
    packet->front_right_motor_faults = front_right_motor_faults;
    packet->rear_mc_faults = rear_mc_faults;
    packet->front_mc_faults = front_mc_faults;
    packet->rear_mc_voltage = rear_mc_voltage;
    packet->front_mc_voltage = front_mc_voltage;
    packet->rear_mc_temperature = rear_mc_temperature;
    packet->front_mc_temperature = front_mc_temperature;
    packet->light_status = light_status;
    packet->pdu_channel_status = pdu_channel_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_SYSTEM_INFO UNPACKING


/**
 * @brief Get field ts1_hour from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts1_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ts1_minute from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts1_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field ts1_second from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts1_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field subsystem_health_1 from ugv_system_info message
 *
 * @return  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
        
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_subsystem_health_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field subsystem_health_2 from ugv_system_info message
 *
 * @return  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_subsystem_health_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field subsystem_health_3 from ugv_system_info message
 *
 * @return  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_subsystem_health_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field subsystem_health_4 from ugv_system_info message
 *
 * @return  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_subsystem_health_4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field ts2_hour from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts2_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field ts2_minute from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts2_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ts2_second from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts2_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field battery_soc from ugv_system_info message
 *
 * @return  
          soc percentage of remaining battery
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_battery_soc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field main_mode from ugv_system_info message
 *
 * @return  
        Current active main mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_main_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field sub_mode from ugv_system_info message
 *
 * @return  
        Current active sub mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_sub_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field speed_mode from ugv_system_info message
 *
 * @return  
        Current active speed mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_speed_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field drive_mode from ugv_system_info message
 *
 * @return  
        Current active drive mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_drive_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field arm_mode from ugv_system_info message
 *
 * @return  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_arm_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field intended_main_mode from ugv_system_info message
 *
 * @return  
        Last main mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_main_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field intended_sub_mode from ugv_system_info message
 *
 * @return  
        Last sub mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_sub_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field intended_speed_mode from ugv_system_info message
 *
 * @return  
        Last speed mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_speed_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field intended_drive_mode from ugv_system_info message
 *
 * @return  
        Last drive mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_drive_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field intended_arm_mode from ugv_system_info message
 *
 * @return  
        Last arm mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_arm_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field mode_change_reason from ugv_system_info message
 *
 * @return  
        Reason for last mode transition.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_mode_change_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field ts3_hour from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts3_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field ts3_minute from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts3_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field ts3_second from ugv_system_info message
 *
 * @return  no_definition
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_ts3_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field rear_left_motor_faults from ugv_system_info message
 *
 * @return  
        Rear Left Motor Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_rear_left_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field rear_right_motor_faults from ugv_system_info message
 *
 * @return  
        Rear Right Motor Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_rear_right_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field front_left_motor_faults from ugv_system_info message
 *
 * @return  
        Front Left Motor Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_front_left_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field front_right_motor_faults from ugv_system_info message
 *
 * @return  
        Front Right Motor Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_front_right_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field rear_mc_faults from ugv_system_info message
 *
 * @return  
        Rear Motor Controller Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_rear_mc_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field front_mc_faults from ugv_system_info message
 *
 * @return  
        Front Motor Controller Faults
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_front_mc_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field rear_mc_voltage from ugv_system_info message
 *
 * @return  Left Motor Controller Voltage (Unit: 0.1 V)
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_rear_mc_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field front_mc_voltage from ugv_system_info message
 *
 * @return  Right Motor Controller Voltage (Unit: 0.1 V)
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_front_mc_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field rear_mc_temperature from ugv_system_info message
 *
 * @return  Left Motor Controller Temperature (Unit: 1 Degree Celsius)
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_rear_mc_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field front_mc_temperature from ugv_system_info message
 *
 * @return  Right Motor Controller Temperature (Unit: 1 Degree Celsius)
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_front_mc_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field light_status from ugv_system_info message
 *
 * @return  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_light_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field pdu_channel_status from ugv_system_info message
 *
 * @return  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_pdu_channel_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a ugv_system_info message into a struct
 *
 * @param msg The message to decode
 * @param ugv_system_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_ugv_system_info_decode(const mavlink_message_t* msg, mavlink_ugv_system_info_t* ugv_system_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ugv_system_info->ts1_hour = mavlink_msg_ugv_system_info_get_ts1_hour(msg);
    ugv_system_info->ts1_minute = mavlink_msg_ugv_system_info_get_ts1_minute(msg);
    ugv_system_info->ts1_second = mavlink_msg_ugv_system_info_get_ts1_second(msg);
    ugv_system_info->subsystem_health_1 = mavlink_msg_ugv_system_info_get_subsystem_health_1(msg);
    ugv_system_info->subsystem_health_2 = mavlink_msg_ugv_system_info_get_subsystem_health_2(msg);
    ugv_system_info->subsystem_health_3 = mavlink_msg_ugv_system_info_get_subsystem_health_3(msg);
    ugv_system_info->subsystem_health_4 = mavlink_msg_ugv_system_info_get_subsystem_health_4(msg);
    ugv_system_info->ts2_hour = mavlink_msg_ugv_system_info_get_ts2_hour(msg);
    ugv_system_info->ts2_minute = mavlink_msg_ugv_system_info_get_ts2_minute(msg);
    ugv_system_info->ts2_second = mavlink_msg_ugv_system_info_get_ts2_second(msg);
    ugv_system_info->battery_soc = mavlink_msg_ugv_system_info_get_battery_soc(msg);
    ugv_system_info->main_mode = mavlink_msg_ugv_system_info_get_main_mode(msg);
    ugv_system_info->sub_mode = mavlink_msg_ugv_system_info_get_sub_mode(msg);
    ugv_system_info->speed_mode = mavlink_msg_ugv_system_info_get_speed_mode(msg);
    ugv_system_info->drive_mode = mavlink_msg_ugv_system_info_get_drive_mode(msg);
    ugv_system_info->arm_mode = mavlink_msg_ugv_system_info_get_arm_mode(msg);
    ugv_system_info->intended_main_mode = mavlink_msg_ugv_system_info_get_intended_main_mode(msg);
    ugv_system_info->intended_sub_mode = mavlink_msg_ugv_system_info_get_intended_sub_mode(msg);
    ugv_system_info->intended_speed_mode = mavlink_msg_ugv_system_info_get_intended_speed_mode(msg);
    ugv_system_info->intended_drive_mode = mavlink_msg_ugv_system_info_get_intended_drive_mode(msg);
    ugv_system_info->intended_arm_mode = mavlink_msg_ugv_system_info_get_intended_arm_mode(msg);
    ugv_system_info->mode_change_reason = mavlink_msg_ugv_system_info_get_mode_change_reason(msg);
    ugv_system_info->ts3_hour = mavlink_msg_ugv_system_info_get_ts3_hour(msg);
    ugv_system_info->ts3_minute = mavlink_msg_ugv_system_info_get_ts3_minute(msg);
    ugv_system_info->ts3_second = mavlink_msg_ugv_system_info_get_ts3_second(msg);
    ugv_system_info->rear_left_motor_faults = mavlink_msg_ugv_system_info_get_rear_left_motor_faults(msg);
    ugv_system_info->rear_right_motor_faults = mavlink_msg_ugv_system_info_get_rear_right_motor_faults(msg);
    ugv_system_info->front_left_motor_faults = mavlink_msg_ugv_system_info_get_front_left_motor_faults(msg);
    ugv_system_info->front_right_motor_faults = mavlink_msg_ugv_system_info_get_front_right_motor_faults(msg);
    ugv_system_info->rear_mc_faults = mavlink_msg_ugv_system_info_get_rear_mc_faults(msg);
    ugv_system_info->front_mc_faults = mavlink_msg_ugv_system_info_get_front_mc_faults(msg);
    ugv_system_info->rear_mc_voltage = mavlink_msg_ugv_system_info_get_rear_mc_voltage(msg);
    ugv_system_info->front_mc_voltage = mavlink_msg_ugv_system_info_get_front_mc_voltage(msg);
    ugv_system_info->rear_mc_temperature = mavlink_msg_ugv_system_info_get_rear_mc_temperature(msg);
    ugv_system_info->front_mc_temperature = mavlink_msg_ugv_system_info_get_front_mc_temperature(msg);
    ugv_system_info->light_status = mavlink_msg_ugv_system_info_get_light_status(msg);
    ugv_system_info->pdu_channel_status = mavlink_msg_ugv_system_info_get_pdu_channel_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN? msg->len : MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN;
        memset(ugv_system_info, 0, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
    memcpy(ugv_system_info, _MAV_PAYLOAD(msg), len);
#endif
}
