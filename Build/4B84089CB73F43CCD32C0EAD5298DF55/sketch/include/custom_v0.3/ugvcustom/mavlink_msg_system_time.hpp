#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_system_time.hpp"
// MESSAGE SYSTEM_TIME support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief SYSTEM_TIME message
 *
 * Provides relative power-on uptime and absolute Unix Epoch timestamps from Compute node.
 */
struct SYSTEM_TIME : mavlink::Message {
    static constexpr msgid_t MSG_ID = 2;
    static constexpr size_t LENGTH = 12;
    static constexpr size_t MIN_LENGTH = 12;
    static constexpr uint8_t CRC_EXTRA = 137;
    static constexpr auto NAME = "SYSTEM_TIME";


    uint64_t time_unix_usec; /*<  Bytes: 10-17. Unix Epoch absolute time signature tracking slot. Expression value: current global clock timestamp measured in microseconds elapsed since Jan 1, 1970 (UTC). */
    uint32_t time_boot_ms; /*<  Bytes: 18-21. Uptime counter tracking. Expression value: continuous clock tracking representing internal relative time in milliseconds since the central compute system initially initialized power-on execution. */


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
        ss << "  time_unix_usec: " << time_unix_usec << std::endl;
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << time_boot_ms;                  // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> time_boot_ms;                  // offset: 8
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
