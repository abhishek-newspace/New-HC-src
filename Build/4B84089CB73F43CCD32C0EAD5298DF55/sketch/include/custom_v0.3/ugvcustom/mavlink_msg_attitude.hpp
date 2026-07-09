#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_attitude.hpp"
// MESSAGE ATTITUDE support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief ATTITUDE message
 *
 * Spatial dynamics orientation vector tracking relative rotational plane movements derived from the IMU hardware.
 */
struct ATTITUDE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 30;
    static constexpr size_t LENGTH = 28;
    static constexpr size_t MIN_LENGTH = 28;
    static constexpr uint8_t CRC_EXTRA = 39;
    static constexpr auto NAME = "ATTITUDE";


    uint32_t time_boot_ms; /*<  Bytes: 10-13. Uptime tracking tracking index register validating timestamp inputs. Expression value: tracking elapsed time in milliseconds directly since initial compute hardware boot up. */
    float roll; /*<  Bytes: 14-17. Spatial vehicle roll orientation angle state vector parameter mapping. Value expected: angular metrics scaled in radians format bounding limits within parameters range -pi to +pi. */
    float pitch; /*<  Bytes: 18-21. Spatial vehicle pitch orientation angle state vector parameter mapping. Value expected: angular metrics scaled in radians format bounding limits within parameters range -pi to +pi. */
    float yaw; /*<  Bytes: 22-25. Spatial vehicle yaw orientation angle state vector parameter mapping. Value expected: angular metrics scaled in radians format bounding limits within parameters range -pi to +pi. */
    float rollspeed; /*<  Bytes: 26-29. Spatial angular displacement rate tracking vector mapping covering system roll acceleration changes. Expected tracking values parameter boundaries match ranges limits from -2.78 to 2.78 rad/s. */
    float pitchspeed; /*<  Bytes: 30-33. Spatial angular displacement rate tracking vector mapping covering system pitch acceleration changes (Not used by Compute, hardcoded constant placeholder to NA). */
    float yawspeed; /*<  Bytes: 34-37. Spatial angular displacement rate tracking vector mapping covering system yaw acceleration changes (Not used by Compute, hardcoded constant placeholder to NA). */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  rollspeed: " << rollspeed << std::endl;
        ss << "  pitchspeed: " << pitchspeed << std::endl;
        ss << "  yawspeed: " << yawspeed << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << roll;                          // offset: 4
        map << pitch;                         // offset: 8
        map << yaw;                           // offset: 12
        map << rollspeed;                     // offset: 16
        map << pitchspeed;                    // offset: 20
        map << yawspeed;                      // offset: 24
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> roll;                          // offset: 4
        map >> pitch;                         // offset: 8
        map >> yaw;                           // offset: 12
        map >> rollspeed;                     // offset: 16
        map >> pitchspeed;                    // offset: 20
        map >> yawspeed;                      // offset: 24
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
