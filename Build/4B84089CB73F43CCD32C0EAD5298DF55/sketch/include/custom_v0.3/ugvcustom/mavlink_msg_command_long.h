#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_command_long.h"
#pragma once
// MESSAGE COMMAND_LONG PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_COMMAND_LONG 76


typedef struct __mavlink_command_long_t {
 float param1; /*<  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.*/
 float param2; /*<  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.*/
 float param3; /*<  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.*/
 float param4; /*<  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.*/
 float param5; /*<  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.*/
 float param6; /*<  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.*/
 float param7; /*<  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.*/
 uint16_t command; /*<  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).*/
 uint8_t target_system; /*<  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).*/
 uint8_t target_component; /*<  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).*/
 uint8_t confirmation; /*<  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.*/
} mavlink_command_long_t;

#define MAVLINK_MSG_ID_COMMAND_LONG_LEN 33
#define MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN 33
#define MAVLINK_MSG_ID_76_LEN 33
#define MAVLINK_MSG_ID_76_MIN_LEN 33

#define MAVLINK_MSG_ID_COMMAND_LONG_CRC 152
#define MAVLINK_MSG_ID_76_CRC 152



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG { \
    76, \
    "COMMAND_LONG", \
    11, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long_t, target_component) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long_t, command) }, \
         { "confirmation", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_command_long_t, confirmation) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long_t, param7) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG { \
    "COMMAND_LONG", \
    11, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long_t, target_component) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long_t, command) }, \
         { "confirmation", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_command_long_t, confirmation) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long_t, param7) }, \
         } \
}
#endif

/**
 * @brief Pack a command_long message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).
 * @param target_component  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).
 * @param command  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).
 * @param confirmation  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.
 * @param param1  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.
 * @param param2  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.
 * @param param3  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.
 * @param param4  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.
 * @param param5  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.
 * @param param6  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.
 * @param param7  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
}

/**
 * @brief Pack a command_long message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).
 * @param target_component  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).
 * @param command  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).
 * @param confirmation  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.
 * @param param1  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.
 * @param param2  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.
 * @param param3  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.
 * @param param4  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.
 * @param param5  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.
 * @param param6  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.
 * @param param7  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif
}

/**
 * @brief Pack a command_long message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).
 * @param target_component  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).
 * @param command  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).
 * @param confirmation  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.
 * @param param1  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.
 * @param param2  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.
 * @param param3  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.
 * @param param4  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.
 * @param param5  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.
 * @param param6  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.
 * @param param7  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t command,uint8_t confirmation,float param1,float param2,float param3,float param4,float param5,float param6,float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
}

/**
 * @brief Encode a command_long struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_long_t* command_long)
{
    return mavlink_msg_command_long_pack(system_id, component_id, msg, command_long->target_system, command_long->target_component, command_long->command, command_long->confirmation, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
}

/**
 * @brief Encode a command_long struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_long_t* command_long)
{
    return mavlink_msg_command_long_pack_chan(system_id, component_id, chan, msg, command_long->target_system, command_long->target_component, command_long->command, command_long->confirmation, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
}

/**
 * @brief Encode a command_long struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param command_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_command_long_t* command_long)
{
    return mavlink_msg_command_long_pack_status(system_id, component_id, _status, msg,  command_long->target_system, command_long->target_component, command_long->command, command_long->confirmation, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
}

/**
 * @brief Send a command_long message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).
 * @param target_component  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).
 * @param command  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).
 * @param confirmation  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.
 * @param param1  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.
 * @param param2  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.
 * @param param3  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.
 * @param param4  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.
 * @param param5  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.
 * @param param6  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.
 * @param param7  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_long_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, buf, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}

/**
 * @brief Send a command_long message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_long_send_struct(mavlink_channel_t chan, const mavlink_command_long_t* command_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_long_send(chan, command_long->target_system, command_long->target_component, command_long->command, command_long->confirmation, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)command_long, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_LONG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_long_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, buf, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#else
    mavlink_command_long_t *packet = (mavlink_command_long_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->param5 = param5;
    packet->param6 = param6;
    packet->param7 = param7;
    packet->command = command;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->confirmation = confirmation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)packet, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND_LONG UNPACKING


/**
 * @brief Get field target_system from command_long message
 *
 * @return  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV).
 */
static inline uint8_t mavlink_msg_command_long_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field target_component from command_long message
 *
 * @return  Bytes: 11. Component destination routing index. Value expected: 191 (Compute).
 */
static inline uint8_t mavlink_msg_command_long_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field command from command_long message
 *
 * @return  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY).
 */
static inline uint16_t mavlink_msg_command_long_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field confirmation from command_long message
 *
 * @return  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts.
 */
static inline uint8_t mavlink_msg_command_long_get_confirmation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field param1 from command_long message
 *
 * @return  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules.
 */
static inline float mavlink_msg_command_long_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from command_long message
 *
 * @return  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status.
 */
static inline float mavlink_msg_command_long_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from command_long message
 *
 * @return  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control.
 */
static inline float mavlink_msg_command_long_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from command_long message
 *
 * @return  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use.
 */
static inline float mavlink_msg_command_long_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field param5 from command_long message
 *
 * @return  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands.
 */
static inline float mavlink_msg_command_long_get_param5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field param6 from command_long message
 *
 * @return  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands.
 */
static inline float mavlink_msg_command_long_get_param6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field param7 from command_long message
 *
 * @return  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands.
 */
static inline float mavlink_msg_command_long_get_param7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a command_long message into a struct
 *
 * @param msg The message to decode
 * @param command_long C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_long_decode(const mavlink_message_t* msg, mavlink_command_long_t* command_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command_long->param1 = mavlink_msg_command_long_get_param1(msg);
    command_long->param2 = mavlink_msg_command_long_get_param2(msg);
    command_long->param3 = mavlink_msg_command_long_get_param3(msg);
    command_long->param4 = mavlink_msg_command_long_get_param4(msg);
    command_long->param5 = mavlink_msg_command_long_get_param5(msg);
    command_long->param6 = mavlink_msg_command_long_get_param6(msg);
    command_long->param7 = mavlink_msg_command_long_get_param7(msg);
    command_long->command = mavlink_msg_command_long_get_command(msg);
    command_long->target_system = mavlink_msg_command_long_get_target_system(msg);
    command_long->target_component = mavlink_msg_command_long_get_target_component(msg);
    command_long->confirmation = mavlink_msg_command_long_get_confirmation(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_LONG_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_LONG_LEN;
        memset(command_long, 0, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
    memcpy(command_long, _MAV_PAYLOAD(msg), len);
#endif
}
