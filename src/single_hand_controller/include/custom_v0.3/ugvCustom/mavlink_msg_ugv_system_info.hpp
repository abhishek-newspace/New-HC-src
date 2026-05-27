// MESSAGE UGV_SYSTEM_INFO support class

#pragma once

namespace mavlink {
namespace ugvCustom {
namespace msg {

/**
 * @brief UGV_SYSTEM_INFO message
 *
 * 
            Reports subsystem communication and health status of the UGV platform.
            Each subsystem uses 2-bit encoding:
            0x01 = No communication
            0x10 = Communicating and healthy
            0x11 = Communicating and unhealthy (fault present)
            0x00 = Reserved
        
 */
struct UGV_SYSTEM_INFO : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 20;
    static constexpr size_t MIN_LENGTH = 20;
    static constexpr uint8_t CRC_EXTRA = 101;
    static constexpr auto NAME = "UGV_SYSTEM_INFO";


    uint8_t subsystem_health_1; /*<  
            Packed subsystem health information.

            Bit 0-1 : Left Motor Controller Health
            Bit 2-3 : Right Motor Controller Health
            Bit 4-5 : HV Battery Health
            Bit 6-7 : LV Battery Health
         */
    uint8_t subsystem_health_2; /*<  
        Bit 0-1 : LV PDU
        Bit 2-3 : DC-DC 48V to 12V
        Bit 4-5 : DC-DC 12V to 5V
        Bit 6-7 : VCU
       */
    uint8_t subsystem_health_3; /*<  
        Bit 0-1 : Front Left Motor
        Bit 2-3 : Rear Left Motor
        Bit 4-5 : Front Right Motor
        Bit 6-7 : Rear Right Motor
       */
    uint8_t subsystem_health_4; /*<  
        Bit 0-1 : UHF Radio
        Bit 2-3 : LBAND Radio
        Bit 4-5 : Compute
        Bit 6-7 : Reserved
       */
    uint8_t battery_soc; /*<  
          soc percentage of remaining battery
       */
    uint8_t main_mode; /*<  
        Current active main mode.
       */
    uint8_t sub_mode; /*<  
        Current active sub mode.
       */
    uint8_t intended_main_mode; /*<  
        Last main mode commanded by GCS.
       */
    uint8_t intended_sub_mode; /*<  
        Last sub mode commanded by GCS.
       */
    uint8_t mode_change_reason; /*<  
        Reason for last mode transition.
       */
    uint8_t rear_left_motor_faults; /*<  
        Rear Left Motor Faults
       */
    uint8_t rear_right_motor_faults; /*<  
        Rear Right Motor Faults
       */
    uint8_t front_left_motor_faults; /*<  
        Front Left Motor Faults
       */
    uint8_t front_right_motor_faults; /*<  
        Front Right Motor Faults
       */
    uint8_t left_mc_faults; /*<  
        Left Motor Controller Faults
       */
    uint8_t right_mc_faults; /*<  
        Right Motor Controller Faults
       */
    uint8_t left_mc_voltage; /*<  Left Motor Controller Voltage (Unit: 0.1 V) */
    uint8_t right_mc_voltage; /*<  Right Motor Controller Voltage (Unit: 0.1 V) */
    uint8_t left_mc_temperature; /*<  Left Motor Controller Temperature (Unit: 1 Degree Celsius) */
    uint8_t right_mc_temperature; /*<  Right Motor Controller Temperature (Unit: 1 Degree Celsius) */


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
        ss << "  subsystem_health_1: " << +subsystem_health_1 << std::endl;
        ss << "  subsystem_health_2: " << +subsystem_health_2 << std::endl;
        ss << "  subsystem_health_3: " << +subsystem_health_3 << std::endl;
        ss << "  subsystem_health_4: " << +subsystem_health_4 << std::endl;
        ss << "  battery_soc: " << +battery_soc << std::endl;
        ss << "  main_mode: " << +main_mode << std::endl;
        ss << "  sub_mode: " << +sub_mode << std::endl;
        ss << "  intended_main_mode: " << +intended_main_mode << std::endl;
        ss << "  intended_sub_mode: " << +intended_sub_mode << std::endl;
        ss << "  mode_change_reason: " << +mode_change_reason << std::endl;
        ss << "  rear_left_motor_faults: " << +rear_left_motor_faults << std::endl;
        ss << "  rear_right_motor_faults: " << +rear_right_motor_faults << std::endl;
        ss << "  front_left_motor_faults: " << +front_left_motor_faults << std::endl;
        ss << "  front_right_motor_faults: " << +front_right_motor_faults << std::endl;
        ss << "  left_mc_faults: " << +left_mc_faults << std::endl;
        ss << "  right_mc_faults: " << +right_mc_faults << std::endl;
        ss << "  left_mc_voltage: " << +left_mc_voltage << std::endl;
        ss << "  right_mc_voltage: " << +right_mc_voltage << std::endl;
        ss << "  left_mc_temperature: " << +left_mc_temperature << std::endl;
        ss << "  right_mc_temperature: " << +right_mc_temperature << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << subsystem_health_1;            // offset: 0
        map << subsystem_health_2;            // offset: 1
        map << subsystem_health_3;            // offset: 2
        map << subsystem_health_4;            // offset: 3
        map << battery_soc;                   // offset: 4
        map << main_mode;                     // offset: 5
        map << sub_mode;                      // offset: 6
        map << intended_main_mode;            // offset: 7
        map << intended_sub_mode;             // offset: 8
        map << mode_change_reason;            // offset: 9
        map << rear_left_motor_faults;        // offset: 10
        map << rear_right_motor_faults;       // offset: 11
        map << front_left_motor_faults;       // offset: 12
        map << front_right_motor_faults;      // offset: 13
        map << left_mc_faults;                // offset: 14
        map << right_mc_faults;               // offset: 15
        map << left_mc_voltage;               // offset: 16
        map << right_mc_voltage;              // offset: 17
        map << left_mc_temperature;           // offset: 18
        map << right_mc_temperature;          // offset: 19
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> subsystem_health_1;            // offset: 0
        map >> subsystem_health_2;            // offset: 1
        map >> subsystem_health_3;            // offset: 2
        map >> subsystem_health_4;            // offset: 3
        map >> battery_soc;                   // offset: 4
        map >> main_mode;                     // offset: 5
        map >> sub_mode;                      // offset: 6
        map >> intended_main_mode;            // offset: 7
        map >> intended_sub_mode;             // offset: 8
        map >> mode_change_reason;            // offset: 9
        map >> rear_left_motor_faults;        // offset: 10
        map >> rear_right_motor_faults;       // offset: 11
        map >> front_left_motor_faults;       // offset: 12
        map >> front_right_motor_faults;      // offset: 13
        map >> left_mc_faults;                // offset: 14
        map >> right_mc_faults;               // offset: 15
        map >> left_mc_voltage;               // offset: 16
        map >> right_mc_voltage;              // offset: 17
        map >> left_mc_temperature;           // offset: 18
        map >> right_mc_temperature;          // offset: 19
    }
};

} // namespace msg
} // namespace ugvCustom
} // namespace mavlink
