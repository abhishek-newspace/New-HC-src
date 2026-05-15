#pragma once
// MESSAGE UGV_SYSTEM_INFO PACKING

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO 50001


typedef struct __mavlink_ugv_system_info_t {
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
 uint8_t battery_soc; /*<  
          soc percentage of remaining battery
      */
 uint8_t main_mode; /*<  
        Current active main mode.
      */
 uint8_t sub_mode; /*<  
        Current active sub mode.
      */
 uint8_t intended_main_mode; /*<  
        Last main mode commanded by GCS.
      */
 uint8_t intended_sub_mode; /*<  
        Last sub mode commanded by GCS.
      */
 uint8_t mode_change_reason; /*<  
        Reason for last mode transition.
      */
} mavlink_ugv_system_info_t;

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN 10
#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN 10
#define MAVLINK_MSG_ID_50001_LEN 10
#define MAVLINK_MSG_ID_50001_MIN_LEN 10

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC 66
#define MAVLINK_MSG_ID_50001_CRC 66



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    50001, \
    "UGV_SYSTEM_INFO", \
    10, \
    {  { "subsystem_health_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_system_info_t, subsystem_health_1) }, \
         { "subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ugv_system_info_t, subsystem_health_2) }, \
         { "subsystem_health_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_ugv_system_info_t, subsystem_health_3) }, \
         { "subsystem_health_4", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_ugv_system_info_t, subsystem_health_4) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ugv_system_info_t, main_mode) }, \
         { "sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ugv_system_info_t, sub_mode) }, \
         { "intended_main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_ugv_system_info_t, intended_main_mode) }, \
         { "intended_sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ugv_system_info_t, intended_sub_mode) }, \
         { "mode_change_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ugv_system_info_t, mode_change_reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    "UGV_SYSTEM_INFO", \
    10, \
    {  { "subsystem_health_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ugv_system_info_t, subsystem_health_1) }, \
         { "subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ugv_system_info_t, subsystem_health_2) }, \
         { "subsystem_health_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_ugv_system_info_t, subsystem_health_3) }, \
         { "subsystem_health_4", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_ugv_system_info_t, subsystem_health_4) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ugv_system_info_t, main_mode) }, \
         { "sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ugv_system_info_t, sub_mode) }, \
         { "intended_main_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_ugv_system_info_t, intended_main_mode) }, \
         { "intended_sub_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ugv_system_info_t, intended_sub_mode) }, \
         { "mode_change_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ugv_system_info_t, mode_change_reason) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
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
      
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t mode_change_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, subsystem_health_1);
    _mav_put_uint8_t(buf, 1, subsystem_health_2);
    _mav_put_uint8_t(buf, 2, subsystem_health_3);
    _mav_put_uint8_t(buf, 3, subsystem_health_4);
    _mav_put_uint8_t(buf, 4, battery_soc);
    _mav_put_uint8_t(buf, 5, main_mode);
    _mav_put_uint8_t(buf, 6, sub_mode);
    _mav_put_uint8_t(buf, 7, intended_main_mode);
    _mav_put_uint8_t(buf, 8, intended_sub_mode);
    _mav_put_uint8_t(buf, 9, mode_change_reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.mode_change_reason = mode_change_reason;

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
      
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t mode_change_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, subsystem_health_1);
    _mav_put_uint8_t(buf, 1, subsystem_health_2);
    _mav_put_uint8_t(buf, 2, subsystem_health_3);
    _mav_put_uint8_t(buf, 3, subsystem_health_4);
    _mav_put_uint8_t(buf, 4, battery_soc);
    _mav_put_uint8_t(buf, 5, main_mode);
    _mav_put_uint8_t(buf, 6, sub_mode);
    _mav_put_uint8_t(buf, 7, intended_main_mode);
    _mav_put_uint8_t(buf, 8, intended_sub_mode);
    _mav_put_uint8_t(buf, 9, mode_change_reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.mode_change_reason = mode_change_reason;

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
      
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t subsystem_health_1,uint8_t subsystem_health_2,uint8_t subsystem_health_3,uint8_t subsystem_health_4,uint8_t battery_soc,uint8_t main_mode,uint8_t sub_mode,uint8_t intended_main_mode,uint8_t intended_sub_mode,uint8_t mode_change_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, subsystem_health_1);
    _mav_put_uint8_t(buf, 1, subsystem_health_2);
    _mav_put_uint8_t(buf, 2, subsystem_health_3);
    _mav_put_uint8_t(buf, 3, subsystem_health_4);
    _mav_put_uint8_t(buf, 4, battery_soc);
    _mav_put_uint8_t(buf, 5, main_mode);
    _mav_put_uint8_t(buf, 6, sub_mode);
    _mav_put_uint8_t(buf, 7, intended_main_mode);
    _mav_put_uint8_t(buf, 8, intended_sub_mode);
    _mav_put_uint8_t(buf, 9, mode_change_reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.mode_change_reason = mode_change_reason;

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
    return mavlink_msg_ugv_system_info_pack(system_id, component_id, msg, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->mode_change_reason);
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
    return mavlink_msg_ugv_system_info_pack_chan(system_id, component_id, chan, msg, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->mode_change_reason);
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
    return mavlink_msg_ugv_system_info_pack_status(system_id, component_id, _status, msg,  ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->mode_change_reason);
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 *
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
      
 * @param battery_soc  
          soc percentage of remaining battery
      
 * @param main_mode  
        Current active main mode.
      
 * @param sub_mode  
        Current active sub mode.
      
 * @param intended_main_mode  
        Last main mode commanded by GCS.
      
 * @param intended_sub_mode  
        Last sub mode commanded by GCS.
      
 * @param mode_change_reason  
        Reason for last mode transition.
      
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_system_info_send(mavlink_channel_t chan, uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t mode_change_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint8_t(buf, 0, subsystem_health_1);
    _mav_put_uint8_t(buf, 1, subsystem_health_2);
    _mav_put_uint8_t(buf, 2, subsystem_health_3);
    _mav_put_uint8_t(buf, 3, subsystem_health_4);
    _mav_put_uint8_t(buf, 4, battery_soc);
    _mav_put_uint8_t(buf, 5, main_mode);
    _mav_put_uint8_t(buf, 6, sub_mode);
    _mav_put_uint8_t(buf, 7, intended_main_mode);
    _mav_put_uint8_t(buf, 8, intended_sub_mode);
    _mav_put_uint8_t(buf, 9, mode_change_reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t packet;
    packet.subsystem_health_1 = subsystem_health_1;
    packet.subsystem_health_2 = subsystem_health_2;
    packet.subsystem_health_3 = subsystem_health_3;
    packet.subsystem_health_4 = subsystem_health_4;
    packet.battery_soc = battery_soc;
    packet.main_mode = main_mode;
    packet.sub_mode = sub_mode;
    packet.intended_main_mode = intended_main_mode;
    packet.intended_sub_mode = intended_sub_mode;
    packet.mode_change_reason = mode_change_reason;

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
    mavlink_msg_ugv_system_info_send(chan, ugv_system_info->subsystem_health_1, ugv_system_info->subsystem_health_2, ugv_system_info->subsystem_health_3, ugv_system_info->subsystem_health_4, ugv_system_info->battery_soc, ugv_system_info->main_mode, ugv_system_info->sub_mode, ugv_system_info->intended_main_mode, ugv_system_info->intended_sub_mode, ugv_system_info->mode_change_reason);
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
static inline void mavlink_msg_ugv_system_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t subsystem_health_1, uint8_t subsystem_health_2, uint8_t subsystem_health_3, uint8_t subsystem_health_4, uint8_t battery_soc, uint8_t main_mode, uint8_t sub_mode, uint8_t intended_main_mode, uint8_t intended_sub_mode, uint8_t mode_change_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, subsystem_health_1);
    _mav_put_uint8_t(buf, 1, subsystem_health_2);
    _mav_put_uint8_t(buf, 2, subsystem_health_3);
    _mav_put_uint8_t(buf, 3, subsystem_health_4);
    _mav_put_uint8_t(buf, 4, battery_soc);
    _mav_put_uint8_t(buf, 5, main_mode);
    _mav_put_uint8_t(buf, 6, sub_mode);
    _mav_put_uint8_t(buf, 7, intended_main_mode);
    _mav_put_uint8_t(buf, 8, intended_sub_mode);
    _mav_put_uint8_t(buf, 9, mode_change_reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t *packet = (mavlink_ugv_system_info_t *)msgbuf;
    packet->subsystem_health_1 = subsystem_health_1;
    packet->subsystem_health_2 = subsystem_health_2;
    packet->subsystem_health_3 = subsystem_health_3;
    packet->subsystem_health_4 = subsystem_health_4;
    packet->battery_soc = battery_soc;
    packet->main_mode = main_mode;
    packet->sub_mode = sub_mode;
    packet->intended_main_mode = intended_main_mode;
    packet->intended_sub_mode = intended_sub_mode;
    packet->mode_change_reason = mode_change_reason;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_SYSTEM_INFO UNPACKING


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
    return _MAV_RETURN_uint8_t(msg,  0);
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
    return _MAV_RETURN_uint8_t(msg,  1);
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
    return _MAV_RETURN_uint8_t(msg,  2);
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
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field battery_soc from ugv_system_info message
 *
 * @return  
          soc percentage of remaining battery
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_battery_soc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field main_mode from ugv_system_info message
 *
 * @return  
        Current active main mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_main_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field sub_mode from ugv_system_info message
 *
 * @return  
        Current active sub mode.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_sub_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field intended_main_mode from ugv_system_info message
 *
 * @return  
        Last main mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_main_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field intended_sub_mode from ugv_system_info message
 *
 * @return  
        Last sub mode commanded by GCS.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_intended_sub_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field mode_change_reason from ugv_system_info message
 *
 * @return  
        Reason for last mode transition.
      
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_mode_change_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
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
    ugv_system_info->subsystem_health_1 = mavlink_msg_ugv_system_info_get_subsystem_health_1(msg);
    ugv_system_info->subsystem_health_2 = mavlink_msg_ugv_system_info_get_subsystem_health_2(msg);
    ugv_system_info->subsystem_health_3 = mavlink_msg_ugv_system_info_get_subsystem_health_3(msg);
    ugv_system_info->subsystem_health_4 = mavlink_msg_ugv_system_info_get_subsystem_health_4(msg);
    ugv_system_info->battery_soc = mavlink_msg_ugv_system_info_get_battery_soc(msg);
    ugv_system_info->main_mode = mavlink_msg_ugv_system_info_get_main_mode(msg);
    ugv_system_info->sub_mode = mavlink_msg_ugv_system_info_get_sub_mode(msg);
    ugv_system_info->intended_main_mode = mavlink_msg_ugv_system_info_get_intended_main_mode(msg);
    ugv_system_info->intended_sub_mode = mavlink_msg_ugv_system_info_get_intended_sub_mode(msg);
    ugv_system_info->mode_change_reason = mavlink_msg_ugv_system_info_get_mode_change_reason(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN? msg->len : MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN;
        memset(ugv_system_info, 0, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
    memcpy(ugv_system_info, _MAV_PAYLOAD(msg), len);
#endif
}
