#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_gps_raw_int.h"
#pragma once
// MESSAGE GPS_RAW_INT PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_GPS_RAW_INT 24


typedef struct __mavlink_gps_raw_int_t {
 uint64_t time_usec; /*<  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.*/
 int32_t lat; /*<  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.*/
 int32_t lon; /*<  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.*/
 int32_t alt; /*<  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.*/
 uint16_t eph; /*<  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.*/
 uint16_t epv; /*<  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).*/
 uint16_t vel; /*<  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.*/
 uint16_t cog; /*<  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.*/
 uint8_t fix_type; /*<  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.*/
 uint8_t satellites_visible; /*<  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.*/
} mavlink_gps_raw_int_t;

#define MAVLINK_MSG_ID_GPS_RAW_INT_LEN 30
#define MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN 30
#define MAVLINK_MSG_ID_24_LEN 30
#define MAVLINK_MSG_ID_24_MIN_LEN 30

#define MAVLINK_MSG_ID_GPS_RAW_INT_CRC 24
#define MAVLINK_MSG_ID_24_CRC 24



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    24, \
    "GPS_RAW_INT", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    "GPS_RAW_INT", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.
 * @param lat  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.
 * @param lon  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.
 * @param alt  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.
 * @param eph  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.
 * @param epv  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).
 * @param vel  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.
 * @param cog  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.
 * @param fix_type  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.
 * @param satellites_visible  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t fix_type, uint8_t satellites_visible)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_RAW_INT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint16_t(buf, 20, eph);
    _mav_put_uint16_t(buf, 22, epv);
    _mav_put_uint16_t(buf, 24, vel);
    _mav_put_uint16_t(buf, 26, cog);
    _mav_put_uint8_t(buf, 28, fix_type);
    _mav_put_uint8_t(buf, 29, satellites_visible);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#else
    mavlink_gps_raw_int_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.eph = eph;
    packet.epv = epv;
    packet.vel = vel;
    packet.cog = cog;
    packet.fix_type = fix_type;
    packet.satellites_visible = satellites_visible;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
}

/**
 * @brief Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.
 * @param lat  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.
 * @param lon  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.
 * @param alt  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.
 * @param eph  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.
 * @param epv  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).
 * @param vel  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.
 * @param cog  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.
 * @param fix_type  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.
 * @param satellites_visible  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t fix_type, uint8_t satellites_visible)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_RAW_INT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint16_t(buf, 20, eph);
    _mav_put_uint16_t(buf, 22, epv);
    _mav_put_uint16_t(buf, 24, vel);
    _mav_put_uint16_t(buf, 26, cog);
    _mav_put_uint8_t(buf, 28, fix_type);
    _mav_put_uint8_t(buf, 29, satellites_visible);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#else
    mavlink_gps_raw_int_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.eph = eph;
    packet.epv = epv;
    packet.vel = vel;
    packet.cog = cog;
    packet.fix_type = fix_type;
    packet.satellites_visible = satellites_visible;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#endif
}

/**
 * @brief Pack a gps_raw_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.
 * @param lat  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.
 * @param lon  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.
 * @param alt  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.
 * @param eph  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.
 * @param epv  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).
 * @param vel  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.
 * @param cog  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.
 * @param fix_type  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.
 * @param satellites_visible  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,int32_t lat,int32_t lon,int32_t alt,uint16_t eph,uint16_t epv,uint16_t vel,uint16_t cog,uint8_t fix_type,uint8_t satellites_visible)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_RAW_INT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint16_t(buf, 20, eph);
    _mav_put_uint16_t(buf, 22, epv);
    _mav_put_uint16_t(buf, 24, vel);
    _mav_put_uint16_t(buf, 26, cog);
    _mav_put_uint8_t(buf, 28, fix_type);
    _mav_put_uint8_t(buf, 29, satellites_visible);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#else
    mavlink_gps_raw_int_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.eph = eph;
    packet.epv = epv;
    packet.vel = vel;
    packet.cog = cog;
    packet.fix_type = fix_type;
    packet.satellites_visible = satellites_visible;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
}

/**
 * @brief Encode a gps_raw_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
    return mavlink_msg_gps_raw_int_pack(system_id, component_id, msg, gps_raw_int->time_usec, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->fix_type, gps_raw_int->satellites_visible);
}

/**
 * @brief Encode a gps_raw_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
    return mavlink_msg_gps_raw_int_pack_chan(system_id, component_id, chan, msg, gps_raw_int->time_usec, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->fix_type, gps_raw_int->satellites_visible);
}

/**
 * @brief Encode a gps_raw_int struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
    return mavlink_msg_gps_raw_int_pack_status(system_id, component_id, _status, msg,  gps_raw_int->time_usec, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->fix_type, gps_raw_int->satellites_visible);
}

/**
 * @brief Send a gps_raw_int message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.
 * @param lat  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.
 * @param lon  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.
 * @param alt  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.
 * @param eph  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.
 * @param epv  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).
 * @param vel  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.
 * @param cog  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.
 * @param fix_type  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.
 * @param satellites_visible  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_raw_int_send(mavlink_channel_t chan, uint64_t time_usec, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t fix_type, uint8_t satellites_visible)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_RAW_INT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint16_t(buf, 20, eph);
    _mav_put_uint16_t(buf, 22, epv);
    _mav_put_uint16_t(buf, 24, vel);
    _mav_put_uint16_t(buf, 26, cog);
    _mav_put_uint8_t(buf, 28, fix_type);
    _mav_put_uint8_t(buf, 29, satellites_visible);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW_INT, buf, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#else
    mavlink_gps_raw_int_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.eph = eph;
    packet.epv = epv;
    packet.vel = vel;
    packet.cog = cog;
    packet.fix_type = fix_type;
    packet.satellites_visible = satellites_visible;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW_INT, (const char *)&packet, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#endif
}

/**
 * @brief Send a gps_raw_int message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_raw_int_send_struct(mavlink_channel_t chan, const mavlink_gps_raw_int_t* gps_raw_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_raw_int_send(chan, gps_raw_int->time_usec, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->fix_type, gps_raw_int->satellites_visible);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW_INT, (const char *)gps_raw_int, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_RAW_INT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_raw_int_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t fix_type, uint8_t satellites_visible)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_uint16_t(buf, 20, eph);
    _mav_put_uint16_t(buf, 22, epv);
    _mav_put_uint16_t(buf, 24, vel);
    _mav_put_uint16_t(buf, 26, cog);
    _mav_put_uint8_t(buf, 28, fix_type);
    _mav_put_uint8_t(buf, 29, satellites_visible);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW_INT, buf, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#else
    mavlink_gps_raw_int_t *packet = (mavlink_gps_raw_int_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->eph = eph;
    packet->epv = epv;
    packet->vel = vel;
    packet->cog = cog;
    packet->fix_type = fix_type;
    packet->satellites_visible = satellites_visible;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RAW_INT, (const char *)packet, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_RAW_INT UNPACKING


/**
 * @brief Get field time_usec from gps_raw_int message
 *
 * @return  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up.
 */
static inline uint64_t mavlink_msg_gps_raw_int_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lat from gps_raw_int message
 *
 * @return  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000.
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from gps_raw_int message
 *
 * @return  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000.
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from gps_raw_int message
 *
 * @return  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters.
 */
static inline int32_t mavlink_msg_gps_raw_int_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field eph from gps_raw_int message
 *
 * @return  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535.
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_eph(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field epv from gps_raw_int message
 *
 * @return  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status).
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_epv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field vel from gps_raw_int message
 *
 * @return  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535.
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_vel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field cog from gps_raw_int message
 *
 * @return  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535.
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_cog(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field fix_type from gps_raw_int message
 *
 * @return  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid.
 */
static inline uint8_t mavlink_msg_gps_raw_int_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field satellites_visible from gps_raw_int message
 *
 * @return  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255.
 */
static inline uint8_t mavlink_msg_gps_raw_int_get_satellites_visible(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Decode a gps_raw_int message into a struct
 *
 * @param msg The message to decode
 * @param gps_raw_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_raw_int_decode(const mavlink_message_t* msg, mavlink_gps_raw_int_t* gps_raw_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gps_raw_int->time_usec = mavlink_msg_gps_raw_int_get_time_usec(msg);
    gps_raw_int->lat = mavlink_msg_gps_raw_int_get_lat(msg);
    gps_raw_int->lon = mavlink_msg_gps_raw_int_get_lon(msg);
    gps_raw_int->alt = mavlink_msg_gps_raw_int_get_alt(msg);
    gps_raw_int->eph = mavlink_msg_gps_raw_int_get_eph(msg);
    gps_raw_int->epv = mavlink_msg_gps_raw_int_get_epv(msg);
    gps_raw_int->vel = mavlink_msg_gps_raw_int_get_vel(msg);
    gps_raw_int->cog = mavlink_msg_gps_raw_int_get_cog(msg);
    gps_raw_int->fix_type = mavlink_msg_gps_raw_int_get_fix_type(msg);
    gps_raw_int->satellites_visible = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_RAW_INT_LEN? msg->len : MAVLINK_MSG_ID_GPS_RAW_INT_LEN;
        memset(gps_raw_int, 0, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
    memcpy(gps_raw_int, _MAV_PAYLOAD(msg), len);
#endif
}
