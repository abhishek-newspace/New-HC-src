#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_timesync.hpp"
// MESSAGE TIMESYNC support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief TIMESYNC message
 *
 * Time synchronization mechanism ensuring clock drift alignments.
 */
struct TIMESYNC : mavlink::Message {
    static constexpr msgid_t MSG_ID = 111;
    static constexpr size_t LENGTH = 18;
    static constexpr size_t MIN_LENGTH = 18;
    static constexpr uint8_t CRC_EXTRA = 198;
    static constexpr auto NAME = "TIMESYNC";


    int64_t tc1; /*<  Bytes: 10-17. Time synchronization payload marker segment 1 (us). HC requests send 0. COMP responses send the UGV clock timestamp. */
    int64_t ts1; /*<  Bytes: 18-25. Time synchronization payload marker segment 2 (us). Current timestamp of the HC or GCS, mirrored back in response. */
    uint8_t target_system; /*<  Bytes: 26. Target routing system validation field. Mapped as 1: UGV/Compute, 2: Hand controller, 255: GCS, 0: Broadcast. */
    uint8_t target_component; /*<  Bytes: 27. Target component identifier address block. Mapped as 191: Compute, 190: Mission Planner GCS, 1: HC, 0: Broadcast. */


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
        ss << "  tc1: " << tc1 << std::endl;
        ss << "  ts1: " << ts1 << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << tc1;                           // offset: 0
        map << ts1;                           // offset: 8
        map << target_system;                 // offset: 16
        map << target_component;              // offset: 17
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> tc1;                           // offset: 0
        map >> ts1;                           // offset: 8
        map >> target_system;                 // offset: 16
        map >> target_component;              // offset: 17
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
