// MESSAGE UGV_COMPONENT_VERSION support class

#pragma once

namespace mavlink {
namespace ugvCustom {
namespace msg {

/**
 * @brief UGV_COMPONENT_VERSION message
 *
 * Describes the current software version along with checksum of the particular component of UGV system.
 */
struct UGV_COMPONENT_VERSION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50002;
    static constexpr size_t LENGTH = 38;
    static constexpr size_t MIN_LENGTH = 38;
    static constexpr uint8_t CRC_EXTRA = 161;
    static constexpr auto NAME = "UGV_COMPONENT_VERSION";


    uint32_t software_version; /*<  Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> checksum; /*<  SHA 256 Checksum of the build */
    uint8_t target_system; /*<  Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component. */
    uint8_t target_component; /*<  Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component. */


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
        ss << "  software_version: " << software_version << std::endl;
        ss << "  checksum: [" << to_string(checksum) << "]" << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << software_version;              // offset: 0
        map << checksum;                      // offset: 4
        map << target_system;                 // offset: 36
        map << target_component;              // offset: 37
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> software_version;              // offset: 0
        map >> checksum;                      // offset: 4
        map >> target_system;                 // offset: 36
        map >> target_component;              // offset: 37
    }
};

} // namespace msg
} // namespace ugvCustom
} // namespace mavlink
