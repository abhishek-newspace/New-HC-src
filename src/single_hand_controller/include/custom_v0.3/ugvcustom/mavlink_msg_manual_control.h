#pragma once
// MESSAGE MANUAL_CONTROL PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_MANUAL_CONTROL 69

MAVPACKED(
typedef struct __mavlink_manual_control_t {
 int16_t x; /*<  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.*/
 int16_t y; /*<  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.*/
 int16_t z; /*<  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).*/
 int16_t r; /*<  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).*/
 uint16_t buttons; /*<  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.*/
 uint8_t target; /*<  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).*/
 uint16_t buttons2; /*<  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).*/
 uint8_t enabled_extensions; /*<  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).*/
 int16_t s; /*<  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).*/
 int16_t t; /*<  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).*/
 int16_t aux1; /*<  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).*/
 int16_t aux2; /*<  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).*/
 int16_t aux3; /*<  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).*/
 int16_t aux4; /*<  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).*/
 int16_t aux5; /*<  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).*/
 int16_t aux6; /*<  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).*/
}) mavlink_manual_control_t;

#define MAVLINK_MSG_ID_MANUAL_CONTROL_LEN 30
#define MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN 11
#define MAVLINK_MSG_ID_69_LEN 30
#define MAVLINK_MSG_ID_69_MIN_LEN 11

#define MAVLINK_MSG_ID_MANUAL_CONTROL_CRC 243
#define MAVLINK_MSG_ID_69_CRC 243



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MANUAL_CONTROL { \
    69, \
    "MANUAL_CONTROL", \
    16, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_manual_control_t, target) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_manual_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_manual_control_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_manual_control_t, z) }, \
         { "r", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_manual_control_t, r) }, \
         { "buttons", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_manual_control_t, buttons) }, \
         { "buttons2", NULL, MAVLINK_TYPE_UINT16_T, 0, 11, offsetof(mavlink_manual_control_t, buttons2) }, \
         { "enabled_extensions", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_manual_control_t, enabled_extensions) }, \
         { "s", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_manual_control_t, s) }, \
         { "t", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_manual_control_t, t) }, \
         { "aux1", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_manual_control_t, aux1) }, \
         { "aux2", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_manual_control_t, aux2) }, \
         { "aux3", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_manual_control_t, aux3) }, \
         { "aux4", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_manual_control_t, aux4) }, \
         { "aux5", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_manual_control_t, aux5) }, \
         { "aux6", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_manual_control_t, aux6) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MANUAL_CONTROL { \
    "MANUAL_CONTROL", \
    16, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_manual_control_t, target) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_manual_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_manual_control_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_manual_control_t, z) }, \
         { "r", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_manual_control_t, r) }, \
         { "buttons", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_manual_control_t, buttons) }, \
         { "buttons2", NULL, MAVLINK_TYPE_UINT16_T, 0, 11, offsetof(mavlink_manual_control_t, buttons2) }, \
         { "enabled_extensions", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_manual_control_t, enabled_extensions) }, \
         { "s", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_manual_control_t, s) }, \
         { "t", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_manual_control_t, t) }, \
         { "aux1", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_manual_control_t, aux1) }, \
         { "aux2", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_manual_control_t, aux2) }, \
         { "aux3", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_manual_control_t, aux3) }, \
         { "aux4", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_manual_control_t, aux4) }, \
         { "aux5", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_manual_control_t, aux5) }, \
         { "aux6", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_manual_control_t, aux6) }, \
         } \
}
#endif

/**
 * @brief Pack a manual_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).
 * @param x  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param y  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param z  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).
 * @param r  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).
 * @param buttons  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.
 * @param buttons2  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).
 * @param enabled_extensions  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).
 * @param s  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).
 * @param t  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).
 * @param aux1  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).
 * @param aux2  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).
 * @param aux3  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).
 * @param aux4  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).
 * @param aux5  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).
 * @param aux6  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons, uint16_t buttons2, uint8_t enabled_extensions, int16_t s, int16_t t, int16_t aux1, int16_t aux2, int16_t aux3, int16_t aux4, int16_t aux5, int16_t aux6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x);
    _mav_put_int16_t(buf, 2, y);
    _mav_put_int16_t(buf, 4, z);
    _mav_put_int16_t(buf, 6, r);
    _mav_put_uint16_t(buf, 8, buttons);
    _mav_put_uint8_t(buf, 10, target);
    _mav_put_uint16_t(buf, 11, buttons2);
    _mav_put_uint8_t(buf, 13, enabled_extensions);
    _mav_put_int16_t(buf, 14, s);
    _mav_put_int16_t(buf, 16, t);
    _mav_put_int16_t(buf, 18, aux1);
    _mav_put_int16_t(buf, 20, aux2);
    _mav_put_int16_t(buf, 22, aux3);
    _mav_put_int16_t(buf, 24, aux4);
    _mav_put_int16_t(buf, 26, aux5);
    _mav_put_int16_t(buf, 28, aux6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#else
    mavlink_manual_control_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.r = r;
    packet.buttons = buttons;
    packet.target = target;
    packet.buttons2 = buttons2;
    packet.enabled_extensions = enabled_extensions;
    packet.s = s;
    packet.t = t;
    packet.aux1 = aux1;
    packet.aux2 = aux2;
    packet.aux3 = aux3;
    packet.aux4 = aux4;
    packet.aux5 = aux5;
    packet.aux6 = aux6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
}

/**
 * @brief Pack a manual_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).
 * @param x  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param y  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param z  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).
 * @param r  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).
 * @param buttons  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.
 * @param buttons2  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).
 * @param enabled_extensions  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).
 * @param s  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).
 * @param t  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).
 * @param aux1  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).
 * @param aux2  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).
 * @param aux3  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).
 * @param aux4  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).
 * @param aux5  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).
 * @param aux6  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_control_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons, uint16_t buttons2, uint8_t enabled_extensions, int16_t s, int16_t t, int16_t aux1, int16_t aux2, int16_t aux3, int16_t aux4, int16_t aux5, int16_t aux6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x);
    _mav_put_int16_t(buf, 2, y);
    _mav_put_int16_t(buf, 4, z);
    _mav_put_int16_t(buf, 6, r);
    _mav_put_uint16_t(buf, 8, buttons);
    _mav_put_uint8_t(buf, 10, target);
    _mav_put_uint16_t(buf, 11, buttons2);
    _mav_put_uint8_t(buf, 13, enabled_extensions);
    _mav_put_int16_t(buf, 14, s);
    _mav_put_int16_t(buf, 16, t);
    _mav_put_int16_t(buf, 18, aux1);
    _mav_put_int16_t(buf, 20, aux2);
    _mav_put_int16_t(buf, 22, aux3);
    _mav_put_int16_t(buf, 24, aux4);
    _mav_put_int16_t(buf, 26, aux5);
    _mav_put_int16_t(buf, 28, aux6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#else
    mavlink_manual_control_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.r = r;
    packet.buttons = buttons;
    packet.target = target;
    packet.buttons2 = buttons2;
    packet.enabled_extensions = enabled_extensions;
    packet.s = s;
    packet.t = t;
    packet.aux1 = aux1;
    packet.aux2 = aux2;
    packet.aux3 = aux3;
    packet.aux4 = aux4;
    packet.aux5 = aux5;
    packet.aux6 = aux6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a manual_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).
 * @param x  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param y  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param z  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).
 * @param r  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).
 * @param buttons  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.
 * @param buttons2  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).
 * @param enabled_extensions  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).
 * @param s  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).
 * @param t  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).
 * @param aux1  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).
 * @param aux2  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).
 * @param aux3  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).
 * @param aux4  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).
 * @param aux5  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).
 * @param aux6  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target,int16_t x,int16_t y,int16_t z,int16_t r,uint16_t buttons,uint16_t buttons2,uint8_t enabled_extensions,int16_t s,int16_t t,int16_t aux1,int16_t aux2,int16_t aux3,int16_t aux4,int16_t aux5,int16_t aux6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x);
    _mav_put_int16_t(buf, 2, y);
    _mav_put_int16_t(buf, 4, z);
    _mav_put_int16_t(buf, 6, r);
    _mav_put_uint16_t(buf, 8, buttons);
    _mav_put_uint8_t(buf, 10, target);
    _mav_put_uint16_t(buf, 11, buttons2);
    _mav_put_uint8_t(buf, 13, enabled_extensions);
    _mav_put_int16_t(buf, 14, s);
    _mav_put_int16_t(buf, 16, t);
    _mav_put_int16_t(buf, 18, aux1);
    _mav_put_int16_t(buf, 20, aux2);
    _mav_put_int16_t(buf, 22, aux3);
    _mav_put_int16_t(buf, 24, aux4);
    _mav_put_int16_t(buf, 26, aux5);
    _mav_put_int16_t(buf, 28, aux6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#else
    mavlink_manual_control_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.r = r;
    packet.buttons = buttons;
    packet.target = target;
    packet.buttons2 = buttons2;
    packet.enabled_extensions = enabled_extensions;
    packet.s = s;
    packet.t = t;
    packet.aux1 = aux1;
    packet.aux2 = aux2;
    packet.aux3 = aux3;
    packet.aux4 = aux4;
    packet.aux5 = aux5;
    packet.aux6 = aux6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
}

/**
 * @brief Encode a manual_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param manual_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_manual_control_t* manual_control)
{
    return mavlink_msg_manual_control_pack(system_id, component_id, msg, manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons, manual_control->buttons2, manual_control->enabled_extensions, manual_control->s, manual_control->t, manual_control->aux1, manual_control->aux2, manual_control->aux3, manual_control->aux4, manual_control->aux5, manual_control->aux6);
}

/**
 * @brief Encode a manual_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param manual_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_manual_control_t* manual_control)
{
    return mavlink_msg_manual_control_pack_chan(system_id, component_id, chan, msg, manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons, manual_control->buttons2, manual_control->enabled_extensions, manual_control->s, manual_control->t, manual_control->aux1, manual_control->aux2, manual_control->aux3, manual_control->aux4, manual_control->aux5, manual_control->aux6);
}

/**
 * @brief Encode a manual_control struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param manual_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_control_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_manual_control_t* manual_control)
{
    return mavlink_msg_manual_control_pack_status(system_id, component_id, _status, msg,  manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons, manual_control->buttons2, manual_control->enabled_extensions, manual_control->s, manual_control->t, manual_control->aux1, manual_control->aux2, manual_control->aux3, manual_control->aux4, manual_control->aux5, manual_control->aux6);
}

/**
 * @brief Send a manual_control message
 * @param chan MAVLink channel to send the message
 *
 * @param target  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).
 * @param x  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param y  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 * @param z  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).
 * @param r  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).
 * @param buttons  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.
 * @param buttons2  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).
 * @param enabled_extensions  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).
 * @param s  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).
 * @param t  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).
 * @param aux1  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).
 * @param aux2  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).
 * @param aux3  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).
 * @param aux4  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).
 * @param aux5  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).
 * @param aux6  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_manual_control_send(mavlink_channel_t chan, uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons, uint16_t buttons2, uint8_t enabled_extensions, int16_t s, int16_t t, int16_t aux1, int16_t aux2, int16_t aux3, int16_t aux4, int16_t aux5, int16_t aux6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x);
    _mav_put_int16_t(buf, 2, y);
    _mav_put_int16_t(buf, 4, z);
    _mav_put_int16_t(buf, 6, r);
    _mav_put_uint16_t(buf, 8, buttons);
    _mav_put_uint8_t(buf, 10, target);
    _mav_put_uint16_t(buf, 11, buttons2);
    _mav_put_uint8_t(buf, 13, enabled_extensions);
    _mav_put_int16_t(buf, 14, s);
    _mav_put_int16_t(buf, 16, t);
    _mav_put_int16_t(buf, 18, aux1);
    _mav_put_int16_t(buf, 20, aux2);
    _mav_put_int16_t(buf, 22, aux3);
    _mav_put_int16_t(buf, 24, aux4);
    _mav_put_int16_t(buf, 26, aux5);
    _mav_put_int16_t(buf, 28, aux6);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_CONTROL, buf, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#else
    mavlink_manual_control_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.r = r;
    packet.buttons = buttons;
    packet.target = target;
    packet.buttons2 = buttons2;
    packet.enabled_extensions = enabled_extensions;
    packet.s = s;
    packet.t = t;
    packet.aux1 = aux1;
    packet.aux2 = aux2;
    packet.aux3 = aux3;
    packet.aux4 = aux4;
    packet.aux5 = aux5;
    packet.aux6 = aux6;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#endif
}

/**
 * @brief Send a manual_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_manual_control_send_struct(mavlink_channel_t chan, const mavlink_manual_control_t* manual_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_manual_control_send(chan, manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons, manual_control->buttons2, manual_control->enabled_extensions, manual_control->s, manual_control->t, manual_control->aux1, manual_control->aux2, manual_control->aux3, manual_control->aux4, manual_control->aux5, manual_control->aux6);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_CONTROL, (const char *)manual_control, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_MANUAL_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_manual_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons, uint16_t buttons2, uint8_t enabled_extensions, int16_t s, int16_t t, int16_t aux1, int16_t aux2, int16_t aux3, int16_t aux4, int16_t aux5, int16_t aux6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, x);
    _mav_put_int16_t(buf, 2, y);
    _mav_put_int16_t(buf, 4, z);
    _mav_put_int16_t(buf, 6, r);
    _mav_put_uint16_t(buf, 8, buttons);
    _mav_put_uint8_t(buf, 10, target);
    _mav_put_uint16_t(buf, 11, buttons2);
    _mav_put_uint8_t(buf, 13, enabled_extensions);
    _mav_put_int16_t(buf, 14, s);
    _mav_put_int16_t(buf, 16, t);
    _mav_put_int16_t(buf, 18, aux1);
    _mav_put_int16_t(buf, 20, aux2);
    _mav_put_int16_t(buf, 22, aux3);
    _mav_put_int16_t(buf, 24, aux4);
    _mav_put_int16_t(buf, 26, aux5);
    _mav_put_int16_t(buf, 28, aux6);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_CONTROL, buf, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#else
    mavlink_manual_control_t *packet = (mavlink_manual_control_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->r = r;
    packet->buttons = buttons;
    packet->target = target;
    packet->buttons2 = buttons2;
    packet->enabled_extensions = enabled_extensions;
    packet->s = s;
    packet->t = t;
    packet->aux1 = aux1;
    packet->aux2 = aux2;
    packet->aux3 = aux3;
    packet->aux4 = aux4;
    packet->aux5 = aux5;
    packet->aux6 = aux6;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_CONTROL, (const char *)packet, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE MANUAL_CONTROL UNPACKING


/**
 * @brief Get field target from manual_control message
 *
 * @return  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV).
 */
static inline uint8_t mavlink_msg_manual_control_get_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field x from manual_control message
 *
 * @return  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 */
static inline int16_t mavlink_msg_manual_control_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field y from manual_control message
 *
 * @return  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0.
 */
static inline int16_t mavlink_msg_manual_control_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field z from manual_control message
 *
 * @return  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled).
 */
static inline int16_t mavlink_msg_manual_control_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field r from manual_control message
 *
 * @return  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled).
 */
static inline int16_t mavlink_msg_manual_control_get_r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field buttons from manual_control message
 *
 * @return  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel.
 */
static inline uint16_t mavlink_msg_manual_control_get_buttons(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field buttons2 from manual_control message
 *
 * @return  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0).
 */
static inline uint16_t mavlink_msg_manual_control_get_buttons2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  11);
}

/**
 * @brief Get field enabled_extensions from manual_control message
 *
 * @return  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0).
 */
static inline uint8_t mavlink_msg_manual_control_get_enabled_extensions(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field s from manual_control message
 *
 * @return  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field t from manual_control message
 *
 * @return  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_t(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field aux1 from manual_control message
 *
 * @return  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field aux2 from manual_control message
 *
 * @return  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field aux3 from manual_control message
 *
 * @return  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field aux4 from manual_control message
 *
 * @return  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field aux5 from manual_control message
 *
 * @return  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field aux6 from manual_control message
 *
 * @return  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0).
 */
static inline int16_t mavlink_msg_manual_control_get_aux6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Decode a manual_control message into a struct
 *
 * @param msg The message to decode
 * @param manual_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_manual_control_decode(const mavlink_message_t* msg, mavlink_manual_control_t* manual_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    manual_control->x = mavlink_msg_manual_control_get_x(msg);
    manual_control->y = mavlink_msg_manual_control_get_y(msg);
    manual_control->z = mavlink_msg_manual_control_get_z(msg);
    manual_control->r = mavlink_msg_manual_control_get_r(msg);
    manual_control->buttons = mavlink_msg_manual_control_get_buttons(msg);
    manual_control->target = mavlink_msg_manual_control_get_target(msg);
    manual_control->buttons2 = mavlink_msg_manual_control_get_buttons2(msg);
    manual_control->enabled_extensions = mavlink_msg_manual_control_get_enabled_extensions(msg);
    manual_control->s = mavlink_msg_manual_control_get_s(msg);
    manual_control->t = mavlink_msg_manual_control_get_t(msg);
    manual_control->aux1 = mavlink_msg_manual_control_get_aux1(msg);
    manual_control->aux2 = mavlink_msg_manual_control_get_aux2(msg);
    manual_control->aux3 = mavlink_msg_manual_control_get_aux3(msg);
    manual_control->aux4 = mavlink_msg_manual_control_get_aux4(msg);
    manual_control->aux5 = mavlink_msg_manual_control_get_aux5(msg);
    manual_control->aux6 = mavlink_msg_manual_control_get_aux6(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MANUAL_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_MANUAL_CONTROL_LEN;
        memset(manual_control, 0, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
    memcpy(manual_control, _MAV_PAYLOAD(msg), len);
#endif
}
