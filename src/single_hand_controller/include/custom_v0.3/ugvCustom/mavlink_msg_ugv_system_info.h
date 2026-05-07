#pragma once
// MESSAGE UGV_SYSTEM_INFO PACKING

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO 50001


typedef struct __mavlink_ugv_system_info_t {
 uint32_t ugv_subsystem_present; /*<  subsystem present*/
 uint32_t ugv_subsystem_enabled; /*<  subsystem enabled*/
 uint32_t ugv_subsystem_health; /*<  subsystem health*/
 uint16_t compute_load; /*<  Compute load (d%)*/
 uint16_t main_voltage; /*<  System Voltage (mV)*/
 int16_t main_current; /*<  System Current (cA)*/
 uint16_t pdu_12v_voltage; /*<  PDU 12V Voltage (mV)*/
 uint16_t drop_rate_comm; /*<  Drop Rate (c%)*/
 uint16_t vcu_fault_errors; /*<  VCU Fault Errors Count*/
 uint16_t front_motor_errors; /*<  Front Motor Errors Count*/
 uint16_t rear_motor_errors; /*<  Rear Motor Errors Count*/
 uint16_t sensor_bus_errors; /*<  Sensor Bus Errors Count*/
 int8_t battery_remaining; /*<  Remaining Battery (%)*/
} mavlink_ugv_system_info_t;

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN 31
#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN 31
#define MAVLINK_MSG_ID_50001_LEN 31
#define MAVLINK_MSG_ID_50001_MIN_LEN 31

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC 182
#define MAVLINK_MSG_ID_50001_CRC 182



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    50001, \
    "UGV_SYSTEM_INFO", \
    13, \
    {  { "ugv_subsystem_present", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_present) }, \
         { "ugv_subsystem_enabled", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_enabled) }, \
         { "ugv_subsystem_health", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_health) }, \
         { "compute_load", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ugv_system_info_t, compute_load) }, \
         { "main_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_ugv_system_info_t, main_voltage) }, \
         { "main_current", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ugv_system_info_t, main_current) }, \
         { "pdu_12v_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_ugv_system_info_t, pdu_12v_voltage) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 30, offsetof(mavlink_ugv_system_info_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_ugv_system_info_t, drop_rate_comm) }, \
         { "vcu_fault_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_ugv_system_info_t, vcu_fault_errors) }, \
         { "front_motor_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_ugv_system_info_t, front_motor_errors) }, \
         { "rear_motor_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ugv_system_info_t, rear_motor_errors) }, \
         { "sensor_bus_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_ugv_system_info_t, sensor_bus_errors) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    "UGV_SYSTEM_INFO", \
    13, \
    {  { "ugv_subsystem_present", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_present) }, \
         { "ugv_subsystem_enabled", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_enabled) }, \
         { "ugv_subsystem_health", "0x%04x", MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ugv_system_info_t, ugv_subsystem_health) }, \
         { "compute_load", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_ugv_system_info_t, compute_load) }, \
         { "main_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_ugv_system_info_t, main_voltage) }, \
         { "main_current", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ugv_system_info_t, main_current) }, \
         { "pdu_12v_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_ugv_system_info_t, pdu_12v_voltage) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 30, offsetof(mavlink_ugv_system_info_t, battery_remaining) }, \
         { "drop_rate_comm", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_ugv_system_info_t, drop_rate_comm) }, \
         { "vcu_fault_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_ugv_system_info_t, vcu_fault_errors) }, \
         { "front_motor_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_ugv_system_info_t, front_motor_errors) }, \
         { "rear_motor_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ugv_system_info_t, rear_motor_errors) }, \
         { "sensor_bus_errors", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_ugv_system_info_t, sensor_bus_errors) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ugv_subsystem_present  subsystem present
 * @param ugv_subsystem_enabled  subsystem enabled
 * @param ugv_subsystem_health  subsystem health
 * @param compute_load  Compute load (d%)
 * @param main_voltage  System Voltage (mV)
 * @param main_current  System Current (cA)
 * @param pdu_12v_voltage  PDU 12V Voltage (mV)
 * @param battery_remaining  Remaining Battery (%)
 * @param drop_rate_comm  Drop Rate (c%)
 * @param vcu_fault_errors  VCU Fault Errors Count
 * @param front_motor_errors  Front Motor Errors Count
 * @param rear_motor_errors  Rear Motor Errors Count
 * @param sensor_bus_errors  Sensor Bus Errors Count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t ugv_subsystem_present, uint32_t ugv_subsystem_enabled, uint32_t ugv_subsystem_health, uint16_t compute_load, uint16_t main_voltage, int16_t main_current, uint16_t pdu_12v_voltage, int8_t battery_remaining, uint16_t drop_rate_comm, uint16_t vcu_fault_errors, uint16_t front_motor_errors, uint16_t rear_motor_errors, uint16_t sensor_bus_errors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, ugv_subsystem_present);
    _mav_put_uint32_t(buf, 4, ugv_subsystem_enabled);
    _mav_put_uint32_t(buf, 8, ugv_subsystem_health);
    _mav_put_uint16_t(buf, 12, compute_load);
    _mav_put_uint16_t(buf, 14, main_voltage);
    _mav_put_int16_t(buf, 16, main_current);
    _mav_put_uint16_t(buf, 18, pdu_12v_voltage);
    _mav_put_uint16_t(buf, 20, drop_rate_comm);
    _mav_put_uint16_t(buf, 22, vcu_fault_errors);
    _mav_put_uint16_t(buf, 24, front_motor_errors);
    _mav_put_uint16_t(buf, 26, rear_motor_errors);
    _mav_put_uint16_t(buf, 28, sensor_bus_errors);
    _mav_put_int8_t(buf, 30, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ugv_subsystem_present = ugv_subsystem_present;
    packet.ugv_subsystem_enabled = ugv_subsystem_enabled;
    packet.ugv_subsystem_health = ugv_subsystem_health;
    packet.compute_load = compute_load;
    packet.main_voltage = main_voltage;
    packet.main_current = main_current;
    packet.pdu_12v_voltage = pdu_12v_voltage;
    packet.drop_rate_comm = drop_rate_comm;
    packet.vcu_fault_errors = vcu_fault_errors;
    packet.front_motor_errors = front_motor_errors;
    packet.rear_motor_errors = rear_motor_errors;
    packet.sensor_bus_errors = sensor_bus_errors;
    packet.battery_remaining = battery_remaining;

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
 * @param ugv_subsystem_present  subsystem present
 * @param ugv_subsystem_enabled  subsystem enabled
 * @param ugv_subsystem_health  subsystem health
 * @param compute_load  Compute load (d%)
 * @param main_voltage  System Voltage (mV)
 * @param main_current  System Current (cA)
 * @param pdu_12v_voltage  PDU 12V Voltage (mV)
 * @param battery_remaining  Remaining Battery (%)
 * @param drop_rate_comm  Drop Rate (c%)
 * @param vcu_fault_errors  VCU Fault Errors Count
 * @param front_motor_errors  Front Motor Errors Count
 * @param rear_motor_errors  Rear Motor Errors Count
 * @param sensor_bus_errors  Sensor Bus Errors Count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t ugv_subsystem_present, uint32_t ugv_subsystem_enabled, uint32_t ugv_subsystem_health, uint16_t compute_load, uint16_t main_voltage, int16_t main_current, uint16_t pdu_12v_voltage, int8_t battery_remaining, uint16_t drop_rate_comm, uint16_t vcu_fault_errors, uint16_t front_motor_errors, uint16_t rear_motor_errors, uint16_t sensor_bus_errors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, ugv_subsystem_present);
    _mav_put_uint32_t(buf, 4, ugv_subsystem_enabled);
    _mav_put_uint32_t(buf, 8, ugv_subsystem_health);
    _mav_put_uint16_t(buf, 12, compute_load);
    _mav_put_uint16_t(buf, 14, main_voltage);
    _mav_put_int16_t(buf, 16, main_current);
    _mav_put_uint16_t(buf, 18, pdu_12v_voltage);
    _mav_put_uint16_t(buf, 20, drop_rate_comm);
    _mav_put_uint16_t(buf, 22, vcu_fault_errors);
    _mav_put_uint16_t(buf, 24, front_motor_errors);
    _mav_put_uint16_t(buf, 26, rear_motor_errors);
    _mav_put_uint16_t(buf, 28, sensor_bus_errors);
    _mav_put_int8_t(buf, 30, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ugv_subsystem_present = ugv_subsystem_present;
    packet.ugv_subsystem_enabled = ugv_subsystem_enabled;
    packet.ugv_subsystem_health = ugv_subsystem_health;
    packet.compute_load = compute_load;
    packet.main_voltage = main_voltage;
    packet.main_current = main_current;
    packet.pdu_12v_voltage = pdu_12v_voltage;
    packet.drop_rate_comm = drop_rate_comm;
    packet.vcu_fault_errors = vcu_fault_errors;
    packet.front_motor_errors = front_motor_errors;
    packet.rear_motor_errors = rear_motor_errors;
    packet.sensor_bus_errors = sensor_bus_errors;
    packet.battery_remaining = battery_remaining;

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
 * @param ugv_subsystem_present  subsystem present
 * @param ugv_subsystem_enabled  subsystem enabled
 * @param ugv_subsystem_health  subsystem health
 * @param compute_load  Compute load (d%)
 * @param main_voltage  System Voltage (mV)
 * @param main_current  System Current (cA)
 * @param pdu_12v_voltage  PDU 12V Voltage (mV)
 * @param battery_remaining  Remaining Battery (%)
 * @param drop_rate_comm  Drop Rate (c%)
 * @param vcu_fault_errors  VCU Fault Errors Count
 * @param front_motor_errors  Front Motor Errors Count
 * @param rear_motor_errors  Rear Motor Errors Count
 * @param sensor_bus_errors  Sensor Bus Errors Count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t ugv_subsystem_present,uint32_t ugv_subsystem_enabled,uint32_t ugv_subsystem_health,uint16_t compute_load,uint16_t main_voltage,int16_t main_current,uint16_t pdu_12v_voltage,int8_t battery_remaining,uint16_t drop_rate_comm,uint16_t vcu_fault_errors,uint16_t front_motor_errors,uint16_t rear_motor_errors,uint16_t sensor_bus_errors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, ugv_subsystem_present);
    _mav_put_uint32_t(buf, 4, ugv_subsystem_enabled);
    _mav_put_uint32_t(buf, 8, ugv_subsystem_health);
    _mav_put_uint16_t(buf, 12, compute_load);
    _mav_put_uint16_t(buf, 14, main_voltage);
    _mav_put_int16_t(buf, 16, main_current);
    _mav_put_uint16_t(buf, 18, pdu_12v_voltage);
    _mav_put_uint16_t(buf, 20, drop_rate_comm);
    _mav_put_uint16_t(buf, 22, vcu_fault_errors);
    _mav_put_uint16_t(buf, 24, front_motor_errors);
    _mav_put_uint16_t(buf, 26, rear_motor_errors);
    _mav_put_uint16_t(buf, 28, sensor_bus_errors);
    _mav_put_int8_t(buf, 30, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.ugv_subsystem_present = ugv_subsystem_present;
    packet.ugv_subsystem_enabled = ugv_subsystem_enabled;
    packet.ugv_subsystem_health = ugv_subsystem_health;
    packet.compute_load = compute_load;
    packet.main_voltage = main_voltage;
    packet.main_current = main_current;
    packet.pdu_12v_voltage = pdu_12v_voltage;
    packet.drop_rate_comm = drop_rate_comm;
    packet.vcu_fault_errors = vcu_fault_errors;
    packet.front_motor_errors = front_motor_errors;
    packet.rear_motor_errors = rear_motor_errors;
    packet.sensor_bus_errors = sensor_bus_errors;
    packet.battery_remaining = battery_remaining;

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
    return mavlink_msg_ugv_system_info_pack(system_id, component_id, msg, ugv_system_info->ugv_subsystem_present, ugv_system_info->ugv_subsystem_enabled, ugv_system_info->ugv_subsystem_health, ugv_system_info->compute_load, ugv_system_info->main_voltage, ugv_system_info->main_current, ugv_system_info->pdu_12v_voltage, ugv_system_info->battery_remaining, ugv_system_info->drop_rate_comm, ugv_system_info->vcu_fault_errors, ugv_system_info->front_motor_errors, ugv_system_info->rear_motor_errors, ugv_system_info->sensor_bus_errors);
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
    return mavlink_msg_ugv_system_info_pack_chan(system_id, component_id, chan, msg, ugv_system_info->ugv_subsystem_present, ugv_system_info->ugv_subsystem_enabled, ugv_system_info->ugv_subsystem_health, ugv_system_info->compute_load, ugv_system_info->main_voltage, ugv_system_info->main_current, ugv_system_info->pdu_12v_voltage, ugv_system_info->battery_remaining, ugv_system_info->drop_rate_comm, ugv_system_info->vcu_fault_errors, ugv_system_info->front_motor_errors, ugv_system_info->rear_motor_errors, ugv_system_info->sensor_bus_errors);
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
    return mavlink_msg_ugv_system_info_pack_status(system_id, component_id, _status, msg,  ugv_system_info->ugv_subsystem_present, ugv_system_info->ugv_subsystem_enabled, ugv_system_info->ugv_subsystem_health, ugv_system_info->compute_load, ugv_system_info->main_voltage, ugv_system_info->main_current, ugv_system_info->pdu_12v_voltage, ugv_system_info->battery_remaining, ugv_system_info->drop_rate_comm, ugv_system_info->vcu_fault_errors, ugv_system_info->front_motor_errors, ugv_system_info->rear_motor_errors, ugv_system_info->sensor_bus_errors);
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 *
 * @param ugv_subsystem_present  subsystem present
 * @param ugv_subsystem_enabled  subsystem enabled
 * @param ugv_subsystem_health  subsystem health
 * @param compute_load  Compute load (d%)
 * @param main_voltage  System Voltage (mV)
 * @param main_current  System Current (cA)
 * @param pdu_12v_voltage  PDU 12V Voltage (mV)
 * @param battery_remaining  Remaining Battery (%)
 * @param drop_rate_comm  Drop Rate (c%)
 * @param vcu_fault_errors  VCU Fault Errors Count
 * @param front_motor_errors  Front Motor Errors Count
 * @param rear_motor_errors  Rear Motor Errors Count
 * @param sensor_bus_errors  Sensor Bus Errors Count
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_system_info_send(mavlink_channel_t chan, uint32_t ugv_subsystem_present, uint32_t ugv_subsystem_enabled, uint32_t ugv_subsystem_health, uint16_t compute_load, uint16_t main_voltage, int16_t main_current, uint16_t pdu_12v_voltage, int8_t battery_remaining, uint16_t drop_rate_comm, uint16_t vcu_fault_errors, uint16_t front_motor_errors, uint16_t rear_motor_errors, uint16_t sensor_bus_errors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, ugv_subsystem_present);
    _mav_put_uint32_t(buf, 4, ugv_subsystem_enabled);
    _mav_put_uint32_t(buf, 8, ugv_subsystem_health);
    _mav_put_uint16_t(buf, 12, compute_load);
    _mav_put_uint16_t(buf, 14, main_voltage);
    _mav_put_int16_t(buf, 16, main_current);
    _mav_put_uint16_t(buf, 18, pdu_12v_voltage);
    _mav_put_uint16_t(buf, 20, drop_rate_comm);
    _mav_put_uint16_t(buf, 22, vcu_fault_errors);
    _mav_put_uint16_t(buf, 24, front_motor_errors);
    _mav_put_uint16_t(buf, 26, rear_motor_errors);
    _mav_put_uint16_t(buf, 28, sensor_bus_errors);
    _mav_put_int8_t(buf, 30, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t packet;
    packet.ugv_subsystem_present = ugv_subsystem_present;
    packet.ugv_subsystem_enabled = ugv_subsystem_enabled;
    packet.ugv_subsystem_health = ugv_subsystem_health;
    packet.compute_load = compute_load;
    packet.main_voltage = main_voltage;
    packet.main_current = main_current;
    packet.pdu_12v_voltage = pdu_12v_voltage;
    packet.drop_rate_comm = drop_rate_comm;
    packet.vcu_fault_errors = vcu_fault_errors;
    packet.front_motor_errors = front_motor_errors;
    packet.rear_motor_errors = rear_motor_errors;
    packet.sensor_bus_errors = sensor_bus_errors;
    packet.battery_remaining = battery_remaining;

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
    mavlink_msg_ugv_system_info_send(chan, ugv_system_info->ugv_subsystem_present, ugv_system_info->ugv_subsystem_enabled, ugv_system_info->ugv_subsystem_health, ugv_system_info->compute_load, ugv_system_info->main_voltage, ugv_system_info->main_current, ugv_system_info->pdu_12v_voltage, ugv_system_info->battery_remaining, ugv_system_info->drop_rate_comm, ugv_system_info->vcu_fault_errors, ugv_system_info->front_motor_errors, ugv_system_info->rear_motor_errors, ugv_system_info->sensor_bus_errors);
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
static inline void mavlink_msg_ugv_system_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t ugv_subsystem_present, uint32_t ugv_subsystem_enabled, uint32_t ugv_subsystem_health, uint16_t compute_load, uint16_t main_voltage, int16_t main_current, uint16_t pdu_12v_voltage, int8_t battery_remaining, uint16_t drop_rate_comm, uint16_t vcu_fault_errors, uint16_t front_motor_errors, uint16_t rear_motor_errors, uint16_t sensor_bus_errors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, ugv_subsystem_present);
    _mav_put_uint32_t(buf, 4, ugv_subsystem_enabled);
    _mav_put_uint32_t(buf, 8, ugv_subsystem_health);
    _mav_put_uint16_t(buf, 12, compute_load);
    _mav_put_uint16_t(buf, 14, main_voltage);
    _mav_put_int16_t(buf, 16, main_current);
    _mav_put_uint16_t(buf, 18, pdu_12v_voltage);
    _mav_put_uint16_t(buf, 20, drop_rate_comm);
    _mav_put_uint16_t(buf, 22, vcu_fault_errors);
    _mav_put_uint16_t(buf, 24, front_motor_errors);
    _mav_put_uint16_t(buf, 26, rear_motor_errors);
    _mav_put_uint16_t(buf, 28, sensor_bus_errors);
    _mav_put_int8_t(buf, 30, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t *packet = (mavlink_ugv_system_info_t *)msgbuf;
    packet->ugv_subsystem_present = ugv_subsystem_present;
    packet->ugv_subsystem_enabled = ugv_subsystem_enabled;
    packet->ugv_subsystem_health = ugv_subsystem_health;
    packet->compute_load = compute_load;
    packet->main_voltage = main_voltage;
    packet->main_current = main_current;
    packet->pdu_12v_voltage = pdu_12v_voltage;
    packet->drop_rate_comm = drop_rate_comm;
    packet->vcu_fault_errors = vcu_fault_errors;
    packet->front_motor_errors = front_motor_errors;
    packet->rear_motor_errors = rear_motor_errors;
    packet->sensor_bus_errors = sensor_bus_errors;
    packet->battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_SYSTEM_INFO UNPACKING


/**
 * @brief Get field ugv_subsystem_present from ugv_system_info message
 *
 * @return  subsystem present
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_ugv_subsystem_present(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field ugv_subsystem_enabled from ugv_system_info message
 *
 * @return  subsystem enabled
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_ugv_subsystem_enabled(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field ugv_subsystem_health from ugv_system_info message
 *
 * @return  subsystem health
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_ugv_subsystem_health(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field compute_load from ugv_system_info message
 *
 * @return  Compute load (d%)
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_compute_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field main_voltage from ugv_system_info message
 *
 * @return  System Voltage (mV)
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_main_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field main_current from ugv_system_info message
 *
 * @return  System Current (cA)
 */
static inline int16_t mavlink_msg_ugv_system_info_get_main_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field pdu_12v_voltage from ugv_system_info message
 *
 * @return  PDU 12V Voltage (mV)
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_pdu_12v_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field battery_remaining from ugv_system_info message
 *
 * @return  Remaining Battery (%)
 */
static inline int8_t mavlink_msg_ugv_system_info_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  30);
}

/**
 * @brief Get field drop_rate_comm from ugv_system_info message
 *
 * @return  Drop Rate (c%)
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_drop_rate_comm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field vcu_fault_errors from ugv_system_info message
 *
 * @return  VCU Fault Errors Count
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_vcu_fault_errors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field front_motor_errors from ugv_system_info message
 *
 * @return  Front Motor Errors Count
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_front_motor_errors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field rear_motor_errors from ugv_system_info message
 *
 * @return  Rear Motor Errors Count
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_rear_motor_errors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field sensor_bus_errors from ugv_system_info message
 *
 * @return  Sensor Bus Errors Count
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_sensor_bus_errors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
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
    ugv_system_info->ugv_subsystem_present = mavlink_msg_ugv_system_info_get_ugv_subsystem_present(msg);
    ugv_system_info->ugv_subsystem_enabled = mavlink_msg_ugv_system_info_get_ugv_subsystem_enabled(msg);
    ugv_system_info->ugv_subsystem_health = mavlink_msg_ugv_system_info_get_ugv_subsystem_health(msg);
    ugv_system_info->compute_load = mavlink_msg_ugv_system_info_get_compute_load(msg);
    ugv_system_info->main_voltage = mavlink_msg_ugv_system_info_get_main_voltage(msg);
    ugv_system_info->main_current = mavlink_msg_ugv_system_info_get_main_current(msg);
    ugv_system_info->pdu_12v_voltage = mavlink_msg_ugv_system_info_get_pdu_12v_voltage(msg);
    ugv_system_info->drop_rate_comm = mavlink_msg_ugv_system_info_get_drop_rate_comm(msg);
    ugv_system_info->vcu_fault_errors = mavlink_msg_ugv_system_info_get_vcu_fault_errors(msg);
    ugv_system_info->front_motor_errors = mavlink_msg_ugv_system_info_get_front_motor_errors(msg);
    ugv_system_info->rear_motor_errors = mavlink_msg_ugv_system_info_get_rear_motor_errors(msg);
    ugv_system_info->sensor_bus_errors = mavlink_msg_ugv_system_info_get_sensor_bus_errors(msg);
    ugv_system_info->battery_remaining = mavlink_msg_ugv_system_info_get_battery_remaining(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN? msg->len : MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN;
        memset(ugv_system_info, 0, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
    memcpy(ugv_system_info, _MAV_PAYLOAD(msg), len);
#endif
}
