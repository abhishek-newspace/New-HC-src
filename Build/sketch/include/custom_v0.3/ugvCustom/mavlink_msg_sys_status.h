#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvCustom/mavlink_msg_sys_status.h"
#pragma once
// MESSAGE SYS_STATUS PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_SYS_STATUS 1


typedef struct __mavlink_sys_status_t {
 uint16_t voltage_battery; /*< [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot*/
 uint16_t drop_rate_comm; /*< [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)*/
 int8_t battery_remaining; /*< [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot*/
} mavlink_sys_status_t;

#define MAVLINK_MSG_ID_SYS_STATUS_LEN 5
#define MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN 5
#define MAVLINK_MSG_ID_1_LEN 5
#define MAVLINK_MSG_ID_1_MIN_LEN 5

#define MAVLINK_MSG_ID_SYS_STATUS_CRC 3
#define MAVLINK_MSG_ID_1_CRC 3



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYS_STATUS { \
    1, \
    "SYS_STATUS", \
    3, \
    {  { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sys_status_t, voltage_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_sys_status_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_sys_status_t, drop_rate_comm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYS_STATUS { \
    "SYS_STATUS", \
    3, \
    {  { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sys_status_t, voltage_battery) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_sys_status_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_sys_status_t, drop_rate_comm) }, \
         } \
}
#endif

/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot
 * @param drop_rate_comm [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t voltage_battery, int8_t battery_remaining, uint16_t drop_rate_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, voltage_battery);
    _mav_put_uint16_t(buf, 2, drop_rate_comm);
    _mav_put_int8_t(buf, 4, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#else
    mavlink_sys_status_t packet;
    packet.voltage_battery = voltage_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
}

/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot
 * @param drop_rate_comm [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t voltage_battery, int8_t battery_remaining, uint16_t drop_rate_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, voltage_battery);
    _mav_put_uint16_t(buf, 2, drop_rate_comm);
    _mav_put_int8_t(buf, 4, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#else
    mavlink_sys_status_t packet;
    packet.voltage_battery = voltage_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif
}

/**
 * @brief Pack a sys_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot
 * @param drop_rate_comm [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t voltage_battery,int8_t battery_remaining,uint16_t drop_rate_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, voltage_battery);
    _mav_put_uint16_t(buf, 2, drop_rate_comm);
    _mav_put_int8_t(buf, 4, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#else
    mavlink_sys_status_t packet;
    packet.voltage_battery = voltage_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
}

/**
 * @brief Encode a sys_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{
    return mavlink_msg_sys_status_pack(system_id, component_id, msg, sys_status->voltage_battery, sys_status->battery_remaining, sys_status->drop_rate_comm);
}

/**
 * @brief Encode a sys_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{
    return mavlink_msg_sys_status_pack_chan(system_id, component_id, chan, msg, sys_status->voltage_battery, sys_status->battery_remaining, sys_status->drop_rate_comm);
}

/**
 * @brief Encode a sys_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{
    return mavlink_msg_sys_status_pack_status(system_id, component_id, _status, msg,  sys_status->voltage_battery, sys_status->battery_remaining, sys_status->drop_rate_comm);
}

/**
 * @brief Send a sys_status message
 * @param chan MAVLink channel to send the message
 *
 * @param voltage_battery [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot
 * @param battery_remaining [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot
 * @param drop_rate_comm [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sys_status_send(mavlink_channel_t chan, uint16_t voltage_battery, int8_t battery_remaining, uint16_t drop_rate_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYS_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, voltage_battery);
    _mav_put_uint16_t(buf, 2, drop_rate_comm);
    _mav_put_int8_t(buf, 4, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_STATUS, buf, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#else
    mavlink_sys_status_t packet;
    packet.voltage_battery = voltage_battery;
    packet.drop_rate_comm = drop_rate_comm;
    packet.battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#endif
}

/**
 * @brief Send a sys_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sys_status_send_struct(mavlink_channel_t chan, const mavlink_sys_status_t* sys_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sys_status_send(chan, sys_status->voltage_battery, sys_status->battery_remaining, sys_status->drop_rate_comm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_STATUS, (const char *)sys_status, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYS_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sys_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t voltage_battery, int8_t battery_remaining, uint16_t drop_rate_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, voltage_battery);
    _mav_put_uint16_t(buf, 2, drop_rate_comm);
    _mav_put_int8_t(buf, 4, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_STATUS, buf, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#else
    mavlink_sys_status_t *packet = (mavlink_sys_status_t *)msgbuf;
    packet->voltage_battery = voltage_battery;
    packet->drop_rate_comm = drop_rate_comm;
    packet->battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYS_STATUS, (const char *)packet, MAVLINK_MSG_ID_SYS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYS_STATUS_LEN, MAVLINK_MSG_ID_SYS_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SYS_STATUS UNPACKING


/**
 * @brief Get field voltage_battery from sys_status message
 *
 * @return [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot
 */
static inline uint16_t mavlink_msg_sys_status_get_voltage_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field battery_remaining from sys_status message
 *
 * @return [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot
 */
static inline int8_t mavlink_msg_sys_status_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  4);
}

/**
 * @brief Get field drop_rate_comm from sys_status message
 *
 * @return [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
 */
static inline uint16_t mavlink_msg_sys_status_get_drop_rate_comm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a sys_status message into a struct
 *
 * @param msg The message to decode
 * @param sys_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sys_status_decode(const mavlink_message_t* msg, mavlink_sys_status_t* sys_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sys_status->voltage_battery = mavlink_msg_sys_status_get_voltage_battery(msg);
    sys_status->drop_rate_comm = mavlink_msg_sys_status_get_drop_rate_comm(msg);
    sys_status->battery_remaining = mavlink_msg_sys_status_get_battery_remaining(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SYS_STATUS_LEN;
        memset(sys_status, 0, MAVLINK_MSG_ID_SYS_STATUS_LEN);
    memcpy(sys_status, _MAV_PAYLOAD(msg), len);
#endif
}
