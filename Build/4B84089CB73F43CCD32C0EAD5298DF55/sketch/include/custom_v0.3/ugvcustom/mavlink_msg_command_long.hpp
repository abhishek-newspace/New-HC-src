#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_command_long.hpp"
// MESSAGE COMMAND_LONG support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief COMMAND_LONG message
 *
 * Standard action block transmitting state adjustments across the data link.
 */
struct COMMAND_LONG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 76;
    static constexpr size_t LENGTH = 33;
    static constexpr size_t MIN_LENGTH = 33;
    static constexpr uint8_t CRC_EXTRA = 152;
    static constexpr auto NAME = "COMMAND_LONG";


    uint8_t target_system; /*<  Bytes: 10. System sequence destination validation field. Value expected: 1 (UGV). */
    uint8_t target_component; /*<  Bytes: 11. Component destination routing index. Value expected: 191 (Compute). */
    uint16_t command; /*<  Bytes: 12-13. Target internal action command code. Expected values: 176 (SET_MODE), 400 (ARM_DISARM), 179 (SET_HOME), 31900 (DRIVE_MODE), 31901 (LIGHT_CONTROL), 31902 (CAMERA_MARKER), 31904 (REMOTE_EMERGENCY). */
    uint8_t confirmation; /*<  Bytes: 14. Retransmission tracker. Value expected: 0 for first transmission, increments 1-255 on active retry attempts. */
    float param1; /*<  Bytes: 15-18. Command parameter argument slot 1 configuration. Sets Mode flag options, Arm/Disarm states, Drive modes, Light toggles, Camera streams, or Home activation rules. */
    float param2; /*<  Bytes: 19-22. Command parameter argument slot 2 configuration. Custom Mode Selection (1-5), Force Arm verification (21196), Fog lights toggle, or Range markers status. */
    float param3; /*<  Bytes: 23-26. Command parameter argument slot 3 configuration. Drive Mode speed limit selections (1: Low, 2: Medium, 3: High) or Aft Brake Lights control. */
    float param4; /*<  Bytes: 27-30. Command parameter argument slot 4 configuration. Hardcoded to NA / Reserved for future use. */
    float param5; /*<  Bytes: 31-34. Command parameter argument slot 5 configuration. Hardcoded to NA / Reserved except for Latitude value in Home commands. */
    float param6; /*<  Bytes: 35-38. Command parameter argument slot 6 configuration. Hardcoded to NA / Reserved except for Longitude value in Home commands. */
    float param7; /*<  Bytes: 39-42. Command parameter argument slot 7 configuration. Hardcoded to NA / Reserved except for Altitude value in Home commands. */


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
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  command: " << command << std::endl;
        ss << "  confirmation: " << +confirmation << std::endl;
        ss << "  param1: " << param1 << std::endl;
        ss << "  param2: " << param2 << std::endl;
        ss << "  param3: " << param3 << std::endl;
        ss << "  param4: " << param4 << std::endl;
        ss << "  param5: " << param5 << std::endl;
        ss << "  param6: " << param6 << std::endl;
        ss << "  param7: " << param7 << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << param1;                        // offset: 0
        map << param2;                        // offset: 4
        map << param3;                        // offset: 8
        map << param4;                        // offset: 12
        map << param5;                        // offset: 16
        map << param6;                        // offset: 20
        map << param7;                        // offset: 24
        map << command;                       // offset: 28
        map << target_system;                 // offset: 30
        map << target_component;              // offset: 31
        map << confirmation;                  // offset: 32
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> param1;                        // offset: 0
        map >> param2;                        // offset: 4
        map >> param3;                        // offset: 8
        map >> param4;                        // offset: 12
        map >> param5;                        // offset: 16
        map >> param6;                        // offset: 20
        map >> param7;                        // offset: 24
        map >> command;                       // offset: 28
        map >> target_system;                 // offset: 30
        map >> target_component;              // offset: 31
        map >> confirmation;                  // offset: 32
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
