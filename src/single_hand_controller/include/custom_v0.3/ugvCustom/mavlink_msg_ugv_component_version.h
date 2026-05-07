#pragma once
// MESSAGE UGV_COMPONENT_VERSION PACKING

#define MAVLINK_MSG_ID_UGV_COMPONENT_VERSION 50002


typedef struct __mavlink_ugv_component_version_t {
 uint32_t software_version; /*<  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 uint8_t checksum[32]; /*<  SHA 256 Checksum of the build*/
 uint8_t target_system; /*<  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.*/
 uint8_t target_component; /*<  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.*/
} mavlink_ugv_component_version_t;

#define MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN 38
#define MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN 38
#define MAVLINK_MSG_ID_50002_LEN 38
#define MAVLINK_MSG_ID_50002_MIN_LEN 38

#define MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC 161
#define MAVLINK_MSG_ID_50002_CRC 161

#define MAVLINK_MSG_UGV_COMPONENT_VERSION_FIELD_CHECKSUM_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_COMPONENT_VERSION { \
    50002, \
    "UGV_COMPONENT_VERSION", \
    4, \
    {  { "software_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_component_version_t, software_version) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 32, 4, offsetof(mavlink_ugv_component_version_t, checksum) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_ugv_component_version_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_ugv_component_version_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_COMPONENT_VERSION { \
    "UGV_COMPONENT_VERSION", \
    4, \
    {  { "software_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_component_version_t, software_version) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 32, 4, offsetof(mavlink_ugv_component_version_t, checksum) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_ugv_component_version_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_ugv_component_version_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_component_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param software_version  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param checksum  SHA 256 Checksum of the build
 * @param target_system  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.
 * @param target_component  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_component_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t software_version, const uint8_t *checksum, uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, software_version);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t_array(buf, 4, checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#else
    mavlink_ugv_component_version_t packet;
    packet.software_version = software_version;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.checksum, checksum, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_COMPONENT_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
}

/**
 * @brief Pack a ugv_component_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param software_version  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param checksum  SHA 256 Checksum of the build
 * @param target_system  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.
 * @param target_component  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_component_version_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t software_version, const uint8_t *checksum, uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, software_version);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t_array(buf, 4, checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#else
    mavlink_ugv_component_version_t packet;
    packet.software_version = software_version;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.checksum, checksum, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_COMPONENT_VERSION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#endif
}

/**
 * @brief Pack a ugv_component_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param software_version  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param checksum  SHA 256 Checksum of the build
 * @param target_system  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.
 * @param target_component  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_component_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t software_version,const uint8_t *checksum,uint8_t target_system,uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, software_version);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t_array(buf, 4, checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#else
    mavlink_ugv_component_version_t packet;
    packet.software_version = software_version;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.checksum, checksum, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_COMPONENT_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
}

/**
 * @brief Encode a ugv_component_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ugv_component_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_component_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ugv_component_version_t* ugv_component_version)
{
    return mavlink_msg_ugv_component_version_pack(system_id, component_id, msg, ugv_component_version->software_version, ugv_component_version->checksum, ugv_component_version->target_system, ugv_component_version->target_component);
}

/**
 * @brief Encode a ugv_component_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ugv_component_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_component_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ugv_component_version_t* ugv_component_version)
{
    return mavlink_msg_ugv_component_version_pack_chan(system_id, component_id, chan, msg, ugv_component_version->software_version, ugv_component_version->checksum, ugv_component_version->target_system, ugv_component_version->target_component);
}

/**
 * @brief Encode a ugv_component_version struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ugv_component_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_component_version_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ugv_component_version_t* ugv_component_version)
{
    return mavlink_msg_ugv_component_version_pack_status(system_id, component_id, _status, msg,  ugv_component_version->software_version, ugv_component_version->checksum, ugv_component_version->target_system, ugv_component_version->target_component);
}

/**
 * @brief Send a ugv_component_version message
 * @param chan MAVLink channel to send the message
 *
 * @param software_version  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param checksum  SHA 256 Checksum of the build
 * @param target_system  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.
 * @param target_component  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_component_version_send(mavlink_channel_t chan, uint32_t software_version, const uint8_t *checksum, uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, software_version);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t_array(buf, 4, checksum, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION, buf, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#else
    mavlink_ugv_component_version_t packet;
    packet.software_version = software_version;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.checksum, checksum, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION, (const char *)&packet, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#endif
}

/**
 * @brief Send a ugv_component_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ugv_component_version_send_struct(mavlink_channel_t chan, const mavlink_ugv_component_version_t* ugv_component_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ugv_component_version_send(chan, ugv_component_version->software_version, ugv_component_version->checksum, ugv_component_version->target_system, ugv_component_version->target_component);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION, (const char *)ugv_component_version, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ugv_component_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t software_version, const uint8_t *checksum, uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, software_version);
    _mav_put_uint8_t(buf, 36, target_system);
    _mav_put_uint8_t(buf, 37, target_component);
    _mav_put_uint8_t_array(buf, 4, checksum, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION, buf, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#else
    mavlink_ugv_component_version_t *packet = (mavlink_ugv_component_version_t *)msgbuf;
    packet->software_version = software_version;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->checksum, checksum, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION, (const char *)packet, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_COMPONENT_VERSION UNPACKING


/**
 * @brief Get field software_version from ugv_component_version message
 *
 * @return  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint32_t mavlink_msg_ugv_component_version_get_software_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field checksum from ugv_component_version message
 *
 * @return  SHA 256 Checksum of the build
 */
static inline uint16_t mavlink_msg_ugv_component_version_get_checksum(const mavlink_message_t* msg, uint8_t *checksum)
{
    return _MAV_RETURN_uint8_t_array(msg, checksum, 32,  4);
}

/**
 * @brief Get field target_system from ugv_component_version message
 *
 * @return  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component.
 */
static inline uint8_t mavlink_msg_ugv_component_version_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field target_component from ugv_component_version message
 *
 * @return  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component.
 */
static inline uint8_t mavlink_msg_ugv_component_version_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Decode a ugv_component_version message into a struct
 *
 * @param msg The message to decode
 * @param ugv_component_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_ugv_component_version_decode(const mavlink_message_t* msg, mavlink_ugv_component_version_t* ugv_component_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ugv_component_version->software_version = mavlink_msg_ugv_component_version_get_software_version(msg);
    mavlink_msg_ugv_component_version_get_checksum(msg, ugv_component_version->checksum);
    ugv_component_version->target_system = mavlink_msg_ugv_component_version_get_target_system(msg);
    ugv_component_version->target_component = mavlink_msg_ugv_component_version_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN? msg->len : MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN;
        memset(ugv_component_version, 0, MAVLINK_MSG_ID_UGV_COMPONENT_VERSION_LEN);
    memcpy(ugv_component_version, _MAV_PAYLOAD(msg), len);
#endif
}
