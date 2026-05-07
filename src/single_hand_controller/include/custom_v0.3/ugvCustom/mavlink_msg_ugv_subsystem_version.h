#pragma once
// MESSAGE UGV_SUBSYSTEM_VERSION PACKING

#define MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION 50003


typedef struct __mavlink_ugv_subsystem_version_t {
 uint8_t type; /*<  Type of the subsystem software.*/
 char component1_sw[4]; /*<  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component1_checksum[32]; /*<  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component2_sw[4]; /*<  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component2_checksum[32]; /*<  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component3_sw[4]; /*<  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component3_checksum[32]; /*<  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component4_sw[4]; /*<  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component4_checksum[32]; /*<  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component5_sw[4]; /*<  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
 char component5_checksum[32]; /*<  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.*/
} mavlink_ugv_subsystem_version_t;

#define MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN 181
#define MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN 181
#define MAVLINK_MSG_ID_50003_LEN 181
#define MAVLINK_MSG_ID_50003_MIN_LEN 181

#define MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC 78
#define MAVLINK_MSG_ID_50003_CRC 78

#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT1_SW_LEN 4
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT1_CHECKSUM_LEN 32
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT2_SW_LEN 4
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT2_CHECKSUM_LEN 32
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT3_SW_LEN 4
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT3_CHECKSUM_LEN 32
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT4_SW_LEN 4
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT4_CHECKSUM_LEN 32
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT5_SW_LEN 4
#define MAVLINK_MSG_UGV_SUBSYSTEM_VERSION_FIELD_COMPONENT5_CHECKSUM_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_SUBSYSTEM_VERSION { \
    50003, \
    "UGV_SUBSYSTEM_VERSION", \
    11, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_subsystem_version_t, type) }, \
         { "component1_sw", NULL, MAVLINK_TYPE_CHAR, 4, 1, offsetof(mavlink_ugv_subsystem_version_t, component1_sw) }, \
         { "component1_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 5, offsetof(mavlink_ugv_subsystem_version_t, component1_checksum) }, \
         { "component2_sw", NULL, MAVLINK_TYPE_CHAR, 4, 37, offsetof(mavlink_ugv_subsystem_version_t, component2_sw) }, \
         { "component2_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 41, offsetof(mavlink_ugv_subsystem_version_t, component2_checksum) }, \
         { "component3_sw", NULL, MAVLINK_TYPE_CHAR, 4, 73, offsetof(mavlink_ugv_subsystem_version_t, component3_sw) }, \
         { "component3_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 77, offsetof(mavlink_ugv_subsystem_version_t, component3_checksum) }, \
         { "component4_sw", NULL, MAVLINK_TYPE_CHAR, 4, 109, offsetof(mavlink_ugv_subsystem_version_t, component4_sw) }, \
         { "component4_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 113, offsetof(mavlink_ugv_subsystem_version_t, component4_checksum) }, \
         { "component5_sw", NULL, MAVLINK_TYPE_CHAR, 4, 145, offsetof(mavlink_ugv_subsystem_version_t, component5_sw) }, \
         { "component5_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 149, offsetof(mavlink_ugv_subsystem_version_t, component5_checksum) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_SUBSYSTEM_VERSION { \
    "UGV_SUBSYSTEM_VERSION", \
    11, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_subsystem_version_t, type) }, \
         { "component1_sw", NULL, MAVLINK_TYPE_CHAR, 4, 1, offsetof(mavlink_ugv_subsystem_version_t, component1_sw) }, \
         { "component1_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 5, offsetof(mavlink_ugv_subsystem_version_t, component1_checksum) }, \
         { "component2_sw", NULL, MAVLINK_TYPE_CHAR, 4, 37, offsetof(mavlink_ugv_subsystem_version_t, component2_sw) }, \
         { "component2_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 41, offsetof(mavlink_ugv_subsystem_version_t, component2_checksum) }, \
         { "component3_sw", NULL, MAVLINK_TYPE_CHAR, 4, 73, offsetof(mavlink_ugv_subsystem_version_t, component3_sw) }, \
         { "component3_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 77, offsetof(mavlink_ugv_subsystem_version_t, component3_checksum) }, \
         { "component4_sw", NULL, MAVLINK_TYPE_CHAR, 4, 109, offsetof(mavlink_ugv_subsystem_version_t, component4_sw) }, \
         { "component4_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 113, offsetof(mavlink_ugv_subsystem_version_t, component4_checksum) }, \
         { "component5_sw", NULL, MAVLINK_TYPE_CHAR, 4, 145, offsetof(mavlink_ugv_subsystem_version_t, component5_sw) }, \
         { "component5_checksum", NULL, MAVLINK_TYPE_CHAR, 32, 149, offsetof(mavlink_ugv_subsystem_version_t, component5_checksum) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_subsystem_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Type of the subsystem software.
 * @param component1_sw  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component1_checksum  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_sw  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_checksum  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_sw  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_checksum  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_sw  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_checksum  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_sw  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_checksum  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, const char *component1_sw, const char *component1_checksum, const char *component2_sw, const char *component2_checksum, const char *component3_sw, const char *component3_checksum, const char *component4_sw, const char *component4_checksum, const char *component5_sw, const char *component5_checksum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_char_array(buf, 1, component1_sw, 4);
    _mav_put_char_array(buf, 5, component1_checksum, 32);
    _mav_put_char_array(buf, 37, component2_sw, 4);
    _mav_put_char_array(buf, 41, component2_checksum, 32);
    _mav_put_char_array(buf, 73, component3_sw, 4);
    _mav_put_char_array(buf, 77, component3_checksum, 32);
    _mav_put_char_array(buf, 109, component4_sw, 4);
    _mav_put_char_array(buf, 113, component4_checksum, 32);
    _mav_put_char_array(buf, 145, component5_sw, 4);
    _mav_put_char_array(buf, 149, component5_checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#else
    mavlink_ugv_subsystem_version_t packet;
    packet.type = type;
    mav_array_memcpy(packet.component1_sw, component1_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component1_checksum, component1_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component2_sw, component2_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component2_checksum, component2_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component3_sw, component3_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component3_checksum, component3_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component4_sw, component4_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component4_checksum, component4_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component5_sw, component5_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component5_checksum, component5_checksum, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
}

/**
 * @brief Pack a ugv_subsystem_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Type of the subsystem software.
 * @param component1_sw  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component1_checksum  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_sw  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_checksum  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_sw  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_checksum  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_sw  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_checksum  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_sw  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_checksum  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t type, const char *component1_sw, const char *component1_checksum, const char *component2_sw, const char *component2_checksum, const char *component3_sw, const char *component3_checksum, const char *component4_sw, const char *component4_checksum, const char *component5_sw, const char *component5_checksum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_char_array(buf, 1, component1_sw, 4);
    _mav_put_char_array(buf, 5, component1_checksum, 32);
    _mav_put_char_array(buf, 37, component2_sw, 4);
    _mav_put_char_array(buf, 41, component2_checksum, 32);
    _mav_put_char_array(buf, 73, component3_sw, 4);
    _mav_put_char_array(buf, 77, component3_checksum, 32);
    _mav_put_char_array(buf, 109, component4_sw, 4);
    _mav_put_char_array(buf, 113, component4_checksum, 32);
    _mav_put_char_array(buf, 145, component5_sw, 4);
    _mav_put_char_array(buf, 149, component5_checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#else
    mavlink_ugv_subsystem_version_t packet;
    packet.type = type;
    mav_array_memcpy(packet.component1_sw, component1_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component1_checksum, component1_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component2_sw, component2_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component2_checksum, component2_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component3_sw, component3_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component3_checksum, component3_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component4_sw, component4_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component4_checksum, component4_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component5_sw, component5_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component5_checksum, component5_checksum, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#endif
}

/**
 * @brief Pack a ugv_subsystem_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  Type of the subsystem software.
 * @param component1_sw  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component1_checksum  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_sw  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_checksum  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_sw  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_checksum  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_sw  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_checksum  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_sw  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_checksum  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,const char *component1_sw,const char *component1_checksum,const char *component2_sw,const char *component2_checksum,const char *component3_sw,const char *component3_checksum,const char *component4_sw,const char *component4_checksum,const char *component5_sw,const char *component5_checksum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_char_array(buf, 1, component1_sw, 4);
    _mav_put_char_array(buf, 5, component1_checksum, 32);
    _mav_put_char_array(buf, 37, component2_sw, 4);
    _mav_put_char_array(buf, 41, component2_checksum, 32);
    _mav_put_char_array(buf, 73, component3_sw, 4);
    _mav_put_char_array(buf, 77, component3_checksum, 32);
    _mav_put_char_array(buf, 109, component4_sw, 4);
    _mav_put_char_array(buf, 113, component4_checksum, 32);
    _mav_put_char_array(buf, 145, component5_sw, 4);
    _mav_put_char_array(buf, 149, component5_checksum, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#else
    mavlink_ugv_subsystem_version_t packet;
    packet.type = type;
    mav_array_memcpy(packet.component1_sw, component1_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component1_checksum, component1_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component2_sw, component2_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component2_checksum, component2_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component3_sw, component3_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component3_checksum, component3_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component4_sw, component4_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component4_checksum, component4_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component5_sw, component5_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component5_checksum, component5_checksum, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
}

/**
 * @brief Encode a ugv_subsystem_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ugv_subsystem_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ugv_subsystem_version_t* ugv_subsystem_version)
{
    return mavlink_msg_ugv_subsystem_version_pack(system_id, component_id, msg, ugv_subsystem_version->type, ugv_subsystem_version->component1_sw, ugv_subsystem_version->component1_checksum, ugv_subsystem_version->component2_sw, ugv_subsystem_version->component2_checksum, ugv_subsystem_version->component3_sw, ugv_subsystem_version->component3_checksum, ugv_subsystem_version->component4_sw, ugv_subsystem_version->component4_checksum, ugv_subsystem_version->component5_sw, ugv_subsystem_version->component5_checksum);
}

/**
 * @brief Encode a ugv_subsystem_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ugv_subsystem_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ugv_subsystem_version_t* ugv_subsystem_version)
{
    return mavlink_msg_ugv_subsystem_version_pack_chan(system_id, component_id, chan, msg, ugv_subsystem_version->type, ugv_subsystem_version->component1_sw, ugv_subsystem_version->component1_checksum, ugv_subsystem_version->component2_sw, ugv_subsystem_version->component2_checksum, ugv_subsystem_version->component3_sw, ugv_subsystem_version->component3_checksum, ugv_subsystem_version->component4_sw, ugv_subsystem_version->component4_checksum, ugv_subsystem_version->component5_sw, ugv_subsystem_version->component5_checksum);
}

/**
 * @brief Encode a ugv_subsystem_version struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ugv_subsystem_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ugv_subsystem_version_t* ugv_subsystem_version)
{
    return mavlink_msg_ugv_subsystem_version_pack_status(system_id, component_id, _status, msg,  ugv_subsystem_version->type, ugv_subsystem_version->component1_sw, ugv_subsystem_version->component1_checksum, ugv_subsystem_version->component2_sw, ugv_subsystem_version->component2_checksum, ugv_subsystem_version->component3_sw, ugv_subsystem_version->component3_checksum, ugv_subsystem_version->component4_sw, ugv_subsystem_version->component4_checksum, ugv_subsystem_version->component5_sw, ugv_subsystem_version->component5_checksum);
}

/**
 * @brief Send a ugv_subsystem_version message
 * @param chan MAVLink channel to send the message
 *
 * @param type  Type of the subsystem software.
 * @param component1_sw  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component1_checksum  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_sw  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component2_checksum  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_sw  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component3_checksum  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_sw  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component4_checksum  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_sw  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 * @param component5_checksum  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_subsystem_version_send(mavlink_channel_t chan, uint8_t type, const char *component1_sw, const char *component1_checksum, const char *component2_sw, const char *component2_checksum, const char *component3_sw, const char *component3_checksum, const char *component4_sw, const char *component4_checksum, const char *component5_sw, const char *component5_checksum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_char_array(buf, 1, component1_sw, 4);
    _mav_put_char_array(buf, 5, component1_checksum, 32);
    _mav_put_char_array(buf, 37, component2_sw, 4);
    _mav_put_char_array(buf, 41, component2_checksum, 32);
    _mav_put_char_array(buf, 73, component3_sw, 4);
    _mav_put_char_array(buf, 77, component3_checksum, 32);
    _mav_put_char_array(buf, 109, component4_sw, 4);
    _mav_put_char_array(buf, 113, component4_checksum, 32);
    _mav_put_char_array(buf, 145, component5_sw, 4);
    _mav_put_char_array(buf, 149, component5_checksum, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION, buf, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#else
    mavlink_ugv_subsystem_version_t packet;
    packet.type = type;
    mav_array_memcpy(packet.component1_sw, component1_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component1_checksum, component1_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component2_sw, component2_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component2_checksum, component2_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component3_sw, component3_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component3_checksum, component3_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component4_sw, component4_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component4_checksum, component4_checksum, sizeof(char)*32);
    mav_array_memcpy(packet.component5_sw, component5_sw, sizeof(char)*4);
    mav_array_memcpy(packet.component5_checksum, component5_checksum, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION, (const char *)&packet, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#endif
}

/**
 * @brief Send a ugv_subsystem_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ugv_subsystem_version_send_struct(mavlink_channel_t chan, const mavlink_ugv_subsystem_version_t* ugv_subsystem_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ugv_subsystem_version_send(chan, ugv_subsystem_version->type, ugv_subsystem_version->component1_sw, ugv_subsystem_version->component1_checksum, ugv_subsystem_version->component2_sw, ugv_subsystem_version->component2_checksum, ugv_subsystem_version->component3_sw, ugv_subsystem_version->component3_checksum, ugv_subsystem_version->component4_sw, ugv_subsystem_version->component4_checksum, ugv_subsystem_version->component5_sw, ugv_subsystem_version->component5_checksum);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION, (const char *)ugv_subsystem_version, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ugv_subsystem_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, const char *component1_sw, const char *component1_checksum, const char *component2_sw, const char *component2_checksum, const char *component3_sw, const char *component3_checksum, const char *component4_sw, const char *component4_checksum, const char *component5_sw, const char *component5_checksum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_char_array(buf, 1, component1_sw, 4);
    _mav_put_char_array(buf, 5, component1_checksum, 32);
    _mav_put_char_array(buf, 37, component2_sw, 4);
    _mav_put_char_array(buf, 41, component2_checksum, 32);
    _mav_put_char_array(buf, 73, component3_sw, 4);
    _mav_put_char_array(buf, 77, component3_checksum, 32);
    _mav_put_char_array(buf, 109, component4_sw, 4);
    _mav_put_char_array(buf, 113, component4_checksum, 32);
    _mav_put_char_array(buf, 145, component5_sw, 4);
    _mav_put_char_array(buf, 149, component5_checksum, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION, buf, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#else
    mavlink_ugv_subsystem_version_t *packet = (mavlink_ugv_subsystem_version_t *)msgbuf;
    packet->type = type;
    mav_array_memcpy(packet->component1_sw, component1_sw, sizeof(char)*4);
    mav_array_memcpy(packet->component1_checksum, component1_checksum, sizeof(char)*32);
    mav_array_memcpy(packet->component2_sw, component2_sw, sizeof(char)*4);
    mav_array_memcpy(packet->component2_checksum, component2_checksum, sizeof(char)*32);
    mav_array_memcpy(packet->component3_sw, component3_sw, sizeof(char)*4);
    mav_array_memcpy(packet->component3_checksum, component3_checksum, sizeof(char)*32);
    mav_array_memcpy(packet->component4_sw, component4_sw, sizeof(char)*4);
    mav_array_memcpy(packet->component4_checksum, component4_checksum, sizeof(char)*32);
    mav_array_memcpy(packet->component5_sw, component5_sw, sizeof(char)*4);
    mav_array_memcpy(packet->component5_checksum, component5_checksum, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION, (const char *)packet, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_MIN_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_SUBSYSTEM_VERSION UNPACKING


/**
 * @brief Get field type from ugv_subsystem_version message
 *
 * @return  Type of the subsystem software.
 */
static inline uint8_t mavlink_msg_ugv_subsystem_version_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field component1_sw from ugv_subsystem_version message
 *
 * @return  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component1_sw(const mavlink_message_t* msg, char *component1_sw)
{
    return _MAV_RETURN_char_array(msg, component1_sw, 4,  1);
}

/**
 * @brief Get field component1_checksum from ugv_subsystem_version message
 *
 * @return  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component1_checksum(const mavlink_message_t* msg, char *component1_checksum)
{
    return _MAV_RETURN_char_array(msg, component1_checksum, 32,  5);
}

/**
 * @brief Get field component2_sw from ugv_subsystem_version message
 *
 * @return  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component2_sw(const mavlink_message_t* msg, char *component2_sw)
{
    return _MAV_RETURN_char_array(msg, component2_sw, 4,  37);
}

/**
 * @brief Get field component2_checksum from ugv_subsystem_version message
 *
 * @return  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component2_checksum(const mavlink_message_t* msg, char *component2_checksum)
{
    return _MAV_RETURN_char_array(msg, component2_checksum, 32,  41);
}

/**
 * @brief Get field component3_sw from ugv_subsystem_version message
 *
 * @return  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component3_sw(const mavlink_message_t* msg, char *component3_sw)
{
    return _MAV_RETURN_char_array(msg, component3_sw, 4,  73);
}

/**
 * @brief Get field component3_checksum from ugv_subsystem_version message
 *
 * @return  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component3_checksum(const mavlink_message_t* msg, char *component3_checksum)
{
    return _MAV_RETURN_char_array(msg, component3_checksum, 32,  77);
}

/**
 * @brief Get field component4_sw from ugv_subsystem_version message
 *
 * @return  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component4_sw(const mavlink_message_t* msg, char *component4_sw)
{
    return _MAV_RETURN_char_array(msg, component4_sw, 4,  109);
}

/**
 * @brief Get field component4_checksum from ugv_subsystem_version message
 *
 * @return  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component4_checksum(const mavlink_message_t* msg, char *component4_checksum)
{
    return _MAV_RETURN_char_array(msg, component4_checksum, 32,  113);
}

/**
 * @brief Get field component5_sw from ugv_subsystem_version message
 *
 * @return  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component5_sw(const mavlink_message_t* msg, char *component5_sw)
{
    return _MAV_RETURN_char_array(msg, component5_sw, 4,  145);
}

/**
 * @brief Get field component5_checksum from ugv_subsystem_version message
 *
 * @return  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros.
 */
static inline uint16_t mavlink_msg_ugv_subsystem_version_get_component5_checksum(const mavlink_message_t* msg, char *component5_checksum)
{
    return _MAV_RETURN_char_array(msg, component5_checksum, 32,  149);
}

/**
 * @brief Decode a ugv_subsystem_version message into a struct
 *
 * @param msg The message to decode
 * @param ugv_subsystem_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_ugv_subsystem_version_decode(const mavlink_message_t* msg, mavlink_ugv_subsystem_version_t* ugv_subsystem_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ugv_subsystem_version->type = mavlink_msg_ugv_subsystem_version_get_type(msg);
    mavlink_msg_ugv_subsystem_version_get_component1_sw(msg, ugv_subsystem_version->component1_sw);
    mavlink_msg_ugv_subsystem_version_get_component1_checksum(msg, ugv_subsystem_version->component1_checksum);
    mavlink_msg_ugv_subsystem_version_get_component2_sw(msg, ugv_subsystem_version->component2_sw);
    mavlink_msg_ugv_subsystem_version_get_component2_checksum(msg, ugv_subsystem_version->component2_checksum);
    mavlink_msg_ugv_subsystem_version_get_component3_sw(msg, ugv_subsystem_version->component3_sw);
    mavlink_msg_ugv_subsystem_version_get_component3_checksum(msg, ugv_subsystem_version->component3_checksum);
    mavlink_msg_ugv_subsystem_version_get_component4_sw(msg, ugv_subsystem_version->component4_sw);
    mavlink_msg_ugv_subsystem_version_get_component4_checksum(msg, ugv_subsystem_version->component4_checksum);
    mavlink_msg_ugv_subsystem_version_get_component5_sw(msg, ugv_subsystem_version->component5_sw);
    mavlink_msg_ugv_subsystem_version_get_component5_checksum(msg, ugv_subsystem_version->component5_checksum);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN? msg->len : MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN;
        memset(ugv_subsystem_version, 0, MAVLINK_MSG_ID_UGV_SUBSYSTEM_VERSION_LEN);
    memcpy(ugv_subsystem_version, _MAV_PAYLOAD(msg), len);
#endif
}
