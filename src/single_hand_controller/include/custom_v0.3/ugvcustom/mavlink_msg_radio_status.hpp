// MESSAGE RADIO_STATUS support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief RADIO_STATUS message
 *
 * Telemetry radio budget metrics tracking wireless signal health indicators.
 */
struct RADIO_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 109;
    static constexpr size_t LENGTH = 9;
    static constexpr size_t MIN_LENGTH = 9;
    static constexpr uint8_t CRC_EXTRA = 185;
    static constexpr auto NAME = "RADIO_STATUS";


    uint16_t rxerrors; /*<  Bytes: 6-7. Total corrupted or invalid packets received by the UGV radio telemetry node since system boot up. */
    uint16_t fixed; /*<  Bytes: 8-9. Total radio packets successfully repaired using internal forward error correction (FEC) mechanisms (Not used, set to 0-65535). */
    uint8_t rssi; /*<  Byte: 10. Local signal strength indicator measured at the UGV receiver. Range: 0-254, 255: Invalid. */
    uint8_t remrssi; /*<  Byte: 11. Remote endpoint link signal strength measured at hand controller. Range: 0-254, 255: Invalid. */
    uint8_t txbuf; /*<  Byte: 12. Percentage metric tracking available transmitter buffer queue volume space (Not used, returns 0-100). */
    uint8_t noise; /*<  Byte: 13. Local background RF electrical noise measurement envelope at the UGV unit. Range: 0-254, 255: Invalid. */
    uint8_t remnoise; /*<  Byte: 14. Remote background RF noise recorded at the hand controller terminal unit. Range: 0-254, 255: Invalid. */


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
        ss << "  rxerrors: " << rxerrors << std::endl;
        ss << "  fixed: " << fixed << std::endl;
        ss << "  rssi: " << +rssi << std::endl;
        ss << "  remrssi: " << +remrssi << std::endl;
        ss << "  txbuf: " << +txbuf << std::endl;
        ss << "  noise: " << +noise << std::endl;
        ss << "  remnoise: " << +remnoise << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << rxerrors;                      // offset: 0
        map << fixed;                         // offset: 2
        map << rssi;                          // offset: 4
        map << remrssi;                       // offset: 5
        map << txbuf;                         // offset: 6
        map << noise;                         // offset: 7
        map << remnoise;                      // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> rxerrors;                      // offset: 0
        map >> fixed;                         // offset: 2
        map >> rssi;                          // offset: 4
        map >> remrssi;                       // offset: 5
        map >> txbuf;                         // offset: 6
        map >> noise;                         // offset: 7
        map >> remnoise;                      // offset: 8
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
