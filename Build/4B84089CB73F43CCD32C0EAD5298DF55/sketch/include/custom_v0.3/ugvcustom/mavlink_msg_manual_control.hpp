#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_manual_control.hpp"
// MESSAGE MANUAL_CONTROL support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief MANUAL_CONTROL message
 *
 * Locomotion interface routing joystick user input vectors down to the drivetrain.
 */
struct MANUAL_CONTROL : mavlink::Message {
    static constexpr msgid_t MSG_ID = 69;
    static constexpr size_t LENGTH = 30;
    static constexpr size_t MIN_LENGTH = 11;
    static constexpr uint8_t CRC_EXTRA = 243;
    static constexpr auto NAME = "MANUAL_CONTROL";


    uint8_t target; /*<  Bytes: 10. Target routing destination system verification code. Value expected: 1 (UGV). */
    int16_t x; /*<  Bytes: 11-12. Scaled forward and reverse velocity coordinate. HC range: -4800 to 4790 (ADC offset multiplied by 10). GCS range: -32767 to 32767. Mechanical center deadzone returns 0. */
    int16_t y; /*<  Bytes: 13-14. Scaled port and starboard displacement lateral coordinate. HC range: -4800 to 4790. GCS range: -32767 to 32767. Mechanical center deadzone returns 0. */
    int16_t z; /*<  Bytes: 15-16. Z-axis input elevation parameters placeholder. Hardcoded constant value: 32767 (Disabled). */
    int16_t r; /*<  Bytes: 17-18. Rotational direction yaw modifier. Hardcoded constant value: 32767 (Disabled). */
    uint16_t buttons; /*<  Bytes: 19-20. 16-bit physical interface key buttons allocation bitmask panel. */
    uint16_t buttons2; /*<  Bytes: 21-22. Extended layout joystick button checks register payload space (Not used, hardcoded to 0). */
    uint8_t enabled_extensions; /*<  Bytes: 23. Active payload field extensions indicator status byte (Not used, hardcoded to 0). */
    int16_t s; /*<  Bytes: 24-25. Pitch axis framework extension parameter (Not used, hardcoded to 0). */
    int16_t t; /*<  Bytes: 26-27. Roll axis framework extension parameter (Not used, hardcoded to 0). */
    int16_t aux1; /*<  Bytes: 28-29. Auxiliary component parameter input pipeline 1 (Not used, hardcoded to 0). */
    int16_t aux2; /*<  Bytes: 30-31. Auxiliary component parameter input pipeline 2 (Not used, hardcoded to 0). */
    int16_t aux3; /*<  Bytes: 32-33. Auxiliary component parameter input pipeline 3 (Not used, hardcoded to 0). */
    int16_t aux4; /*<  Bytes: 34-35. Auxiliary component parameter input pipeline 4 (Not used, hardcoded to 0). */
    int16_t aux5; /*<  Bytes: 36-37. Auxiliary component parameter input pipeline 5 (Not used, hardcoded to 0). */
    int16_t aux6; /*<  Bytes: 38-39. Auxiliary component parameter input pipeline 6 (Not used, hardcoded to 0). */


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
        ss << "  target: " << +target << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;
        ss << "  r: " << r << std::endl;
        ss << "  buttons: " << buttons << std::endl;
        ss << "  buttons2: " << buttons2 << std::endl;
        ss << "  enabled_extensions: " << +enabled_extensions << std::endl;
        ss << "  s: " << s << std::endl;
        ss << "  t: " << t << std::endl;
        ss << "  aux1: " << aux1 << std::endl;
        ss << "  aux2: " << aux2 << std::endl;
        ss << "  aux3: " << aux3 << std::endl;
        ss << "  aux4: " << aux4 << std::endl;
        ss << "  aux5: " << aux5 << std::endl;
        ss << "  aux6: " << aux6 << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << x;                             // offset: 0
        map << y;                             // offset: 2
        map << z;                             // offset: 4
        map << r;                             // offset: 6
        map << buttons;                       // offset: 8
        map << target;                        // offset: 10
        map << buttons2;                      // offset: 11
        map << enabled_extensions;            // offset: 13
        map << s;                             // offset: 14
        map << t;                             // offset: 16
        map << aux1;                          // offset: 18
        map << aux2;                          // offset: 20
        map << aux3;                          // offset: 22
        map << aux4;                          // offset: 24
        map << aux5;                          // offset: 26
        map << aux6;                          // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> x;                             // offset: 0
        map >> y;                             // offset: 2
        map >> z;                             // offset: 4
        map >> r;                             // offset: 6
        map >> buttons;                       // offset: 8
        map >> target;                        // offset: 10
        map >> buttons2;                      // offset: 11
        map >> enabled_extensions;            // offset: 13
        map >> s;                             // offset: 14
        map >> t;                             // offset: 16
        map >> aux1;                          // offset: 18
        map >> aux2;                          // offset: 20
        map >> aux3;                          // offset: 22
        map >> aux4;                          // offset: 24
        map >> aux5;                          // offset: 26
        map >> aux6;                          // offset: 28
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
