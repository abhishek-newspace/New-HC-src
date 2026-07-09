// MESSAGE GPS_RAW_INT support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief GPS_RAW_INT message
 *
 * Unfiltered hardware localization metrics streaming direct from the tracking receiver module.
 */
struct GPS_RAW_INT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 24;
    static constexpr size_t LENGTH = 30;
    static constexpr size_t MIN_LENGTH = 30;
    static constexpr uint8_t CRC_EXTRA = 24;
    static constexpr auto NAME = "GPS_RAW_INT";


    uint64_t time_usec; /*<  Bytes: 10-17. Microsecond precision master system navigation clock tracking loop snapshot. Returns absolute Unix Epoch time tracking parameters or time baseline directly since system initialization boot up. */
    int32_t lat; /*<  Bytes: 18-21. Latitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -900000000 to 900000000. */
    int32_t lon; /*<  Bytes: 22-25. Longitude coordinate (WGS84). Returns true vehicle coordinates scaled directly into integer values format via mathematical factor degrees multiplied by 1E7. Expected execution boundaries range: -1800000000 to 1800000000. */
    int32_t alt; /*<  Bytes: 26-29. Altitude parameter calculated above Mean Sea Level (MSL). Expression value: returns physical distance unit value measured directly in millimeters. */
    uint16_t eph; /*<  Bytes: 30-31. Horizontal position dilution of precision (HDOP) uncertainty index parameter. Expression value: true uncertainty value multiplied by a factor constant of 100. Unknown error status value fallback returns 65535. */
    uint16_t epv; /*<  Bytes: 32-33. Vertical position dilution of precision (VDOP) uncertainty index parameter. Expression value: true uncertainty multiplied by 100 (Not used by Compute, defaults to constant 65535 Unknown fallback status). */
    uint16_t vel; /*<  Bytes: 34-35. Ground speed velocity tracking calculated by navigation hardware. Expression value: target tracking metrics returning metric values measured in centimeters per second (cm/s). Unknown status value returns 65535. */
    uint16_t cog; /*<  Bytes: 36-37. Course over ground vehicle locomotion heading path alignment tracker orientation angle. Expected parameters range: 0 to 35999 centidegrees. Out of boundaries return 36000-65534, Unknown status returns 65535. */
    uint8_t fix_type; /*<  Byte: 38. Fix quality mapping index value. Mapped as: 0: GPS_FIX_TYPE_NO_GPS, 1: GPS_FIX_TYPE_NO_FIX, 2: GPS_FIX_TYPE_3D_FIX, 3: GPS_FIX_TYPE_2D_FIX, 4: GPS_FIX_TYPE_DGPS, 5: GPS_FIX_TYPE_RTK_FLOAT, 6: GPS_FIX_TYPE_RTK_FIXED. 7-255 are Invalid. */
    uint8_t satellites_visible; /*<  Byte: 39. Total count tracking active positioning space vehicle elements locked in the tracking process loop. Returns true sat counter value tracking elements inside space arrays 0-254. Unknown status returns 255. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_usec: " << time_usec << std::endl;
        ss << "  lat: " << lat << std::endl;
        ss << "  lon: " << lon << std::endl;
        ss << "  alt: " << alt << std::endl;
        ss << "  eph: " << eph << std::endl;
        ss << "  epv: " << epv << std::endl;
        ss << "  vel: " << vel << std::endl;
        ss << "  cog: " << cog << std::endl;
        ss << "  fix_type: " << +fix_type << std::endl;
        ss << "  satellites_visible: " << +satellites_visible << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << lat;                           // offset: 8
        map << lon;                           // offset: 12
        map << alt;                           // offset: 16
        map << eph;                           // offset: 20
        map << epv;                           // offset: 22
        map << vel;                           // offset: 24
        map << cog;                           // offset: 26
        map << fix_type;                      // offset: 28
        map << satellites_visible;            // offset: 29
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> lat;                           // offset: 8
        map >> lon;                           // offset: 12
        map >> alt;                           // offset: 16
        map >> eph;                           // offset: 20
        map >> epv;                           // offset: 22
        map >> vel;                           // offset: 24
        map >> cog;                           // offset: 26
        map >> fix_type;                      // offset: 28
        map >> satellites_visible;            // offset: 29
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
