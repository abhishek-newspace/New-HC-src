#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_heartbeat.hpp"
// MESSAGE HEARTBEAT support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief HEARTBEAT message
 *
 * Indicates vehicle or ground station entity connectivity status.
 */
struct HEARTBEAT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 0;
    static constexpr size_t LENGTH = 9;
    static constexpr size_t MIN_LENGTH = 9;
    static constexpr uint8_t CRC_EXTRA = 50;
    static constexpr auto NAME = "HEARTBEAT";


    uint8_t type; /*<  Bytes: 6. Component type. COMP sends 18 (MAV_TYPE_ONBOARD_CONTROLLER). HC sends 6 (GCS Type). GCS sends 6 (GCS Type). */
    uint8_t autopilot; /*<  Bytes: 7. Autopilot identifier. Compute/HC/GCS all hardcode to 8 (MAV_AUTOPILOT_INVALID). */
    uint8_t base_mode; /*<  Bytes: 8. System wide flag bitmask. COMP sends 1 (Custom mode enable). HC and GCS send 0 (No MAV_MODE_FLAG enabled). */
    uint32_t custom_mode; /*<  Bytes: 9-12 (HC/GCS) or Bytes 9 (COMP). Drive mode rules. COMP sends 1: Speed, 2: Torque, 3: Torque with speed limit. HC and GCS send 0 (Not used). */
    uint8_t system_status; /*<  Bytes: 13 (HC/GCS) or Bytes 17 (COMP). Status flags. Mapped as 3: Standby mode, 4: Active mode. */
    uint8_t mavlink_version; /*<  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version */


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
        ss << "  type: " << +type << std::endl;
        ss << "  autopilot: " << +autopilot << std::endl;
        ss << "  base_mode: " << +base_mode << std::endl;
        ss << "  custom_mode: " << custom_mode << std::endl;
        ss << "  system_status: " << +system_status << std::endl;
        ss << "  mavlink_version: " << +mavlink_version << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << custom_mode;                   // offset: 0
        map << type;                          // offset: 4
        map << autopilot;                     // offset: 5
        map << base_mode;                     // offset: 6
        map << system_status;                 // offset: 7
        map << uint8_t(2);               // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> custom_mode;                   // offset: 0
        map >> type;                          // offset: 4
        map >> autopilot;                     // offset: 5
        map >> base_mode;                     // offset: 6
        map >> system_status;                 // offset: 7
        map >> mavlink_version;               // offset: 8
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
