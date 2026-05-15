// MESSAGE SYS_STATUS support class

#pragma once

namespace mavlink {
namespace ugvCustom {
namespace msg {

/**
 * @brief SYS_STATUS message
 *
 * Sensor and subsystem status information. Provides a compact representation of sensor/subsystem status and a few other basic statistics.
 */
struct SYS_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 1;
    static constexpr size_t LENGTH = 5;
    static constexpr size_t MIN_LENGTH = 5;
    static constexpr uint8_t CRC_EXTRA = 3;
    static constexpr auto NAME = "SYS_STATUS";


    uint16_t voltage_battery; /*< [mV] Battery voltage, UINT16_MAX: Voltage not sent by autopilot */
    int8_t battery_remaining; /*< [%] Battery energy remaining, -1: Battery remaining energy not sent by autopilot */
    uint16_t drop_rate_comm; /*< [c%] Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) */


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
        ss << "  voltage_battery: " << voltage_battery << std::endl;
        ss << "  battery_remaining: " << +battery_remaining << std::endl;
        ss << "  drop_rate_comm: " << drop_rate_comm << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << voltage_battery;               // offset: 0
        map << drop_rate_comm;                // offset: 2
        map << battery_remaining;             // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> voltage_battery;               // offset: 0
        map >> drop_rate_comm;                // offset: 2
        map >> battery_remaining;             // offset: 4
    }
};

} // namespace msg
} // namespace ugvCustom
} // namespace mavlink
