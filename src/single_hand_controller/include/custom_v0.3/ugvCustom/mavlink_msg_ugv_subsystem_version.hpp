// MESSAGE UGV_SUBSYSTEM_VERSION support class

#pragma once

namespace mavlink {
namespace ugvCustom {
namespace msg {

/**
 * @brief UGV_SUBSYSTEM_VERSION message
 *
 * Describes the current software version along with checksum of whole UGV system
 */
struct UGV_SUBSYSTEM_VERSION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50003;
    static constexpr size_t LENGTH = 181;
    static constexpr size_t MIN_LENGTH = 181;
    static constexpr uint8_t CRC_EXTRA = 50;
    static constexpr auto NAME = "UGV_SUBSYSTEM_VERSION";


    uint8_t type; /*<  Type of the subsystem software. */
    uint32_t component1_sw; /*<  Software version of component 1. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> component1_checksum; /*<  Software checksum of component 1. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    uint32_t component2_sw; /*<  Software version of component 2. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> component2_checksum; /*<  Software checksum of component 2. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    uint32_t component3_sw; /*<  Software version of component 3. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> component3_checksum; /*<  Software checksum of component 3. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    uint32_t component4_sw; /*<  Software version of component 4. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> component4_checksum; /*<  Software checksum of component 4. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    uint32_t component5_sw; /*<  Software version of component 5. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    std::array<uint8_t, 32> component5_checksum; /*<  Software checksum of component 5. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */


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
        ss << "  component1_sw: " << component1_sw << std::endl;
        ss << "  component1_checksum: [" << to_string(component1_checksum) << "]" << std::endl;
        ss << "  component2_sw: " << component2_sw << std::endl;
        ss << "  component2_checksum: [" << to_string(component2_checksum) << "]" << std::endl;
        ss << "  component3_sw: " << component3_sw << std::endl;
        ss << "  component3_checksum: [" << to_string(component3_checksum) << "]" << std::endl;
        ss << "  component4_sw: " << component4_sw << std::endl;
        ss << "  component4_checksum: [" << to_string(component4_checksum) << "]" << std::endl;
        ss << "  component5_sw: " << component5_sw << std::endl;
        ss << "  component5_checksum: [" << to_string(component5_checksum) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << component1_sw;                 // offset: 0
        map << component2_sw;                 // offset: 4
        map << component3_sw;                 // offset: 8
        map << component4_sw;                 // offset: 12
        map << component5_sw;                 // offset: 16
        map << type;                          // offset: 20
        map << component1_checksum;           // offset: 21
        map << component2_checksum;           // offset: 53
        map << component3_checksum;           // offset: 85
        map << component4_checksum;           // offset: 117
        map << component5_checksum;           // offset: 149
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> component1_sw;                 // offset: 0
        map >> component2_sw;                 // offset: 4
        map >> component3_sw;                 // offset: 8
        map >> component4_sw;                 // offset: 12
        map >> component5_sw;                 // offset: 16
        map >> type;                          // offset: 20
        map >> component1_checksum;           // offset: 21
        map >> component2_checksum;           // offset: 53
        map >> component3_checksum;           // offset: 85
        map >> component4_checksum;           // offset: 117
        map >> component5_checksum;           // offset: 149
    }
};

} // namespace msg
} // namespace ugvCustom
} // namespace mavlink
