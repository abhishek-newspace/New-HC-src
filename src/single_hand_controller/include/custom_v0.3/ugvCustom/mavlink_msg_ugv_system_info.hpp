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
    static constexpr size_t LENGTH = 37;
    static constexpr size_t MIN_LENGTH = 37;
    static constexpr uint8_t CRC_EXTRA = 128;
    static constexpr auto NAME = "UGV_SYSTEM_INFO";


    uint8_t ts1_hour; /*<  no_definition */
    uint8_t ts1_minute; /*<  no_definition */
    uint8_t ts1_second; /*<  no_definition */
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
    uint8_t ts2_hour; /*<  no_definition */
    uint8_t ts2_minute; /*<  no_definition */
    uint8_t ts2_second; /*<  no_definition */
    uint8_t battery_soc; /*<  
          soc percentage of remaining battery
       */
    uint8_t main_mode; /*<  
        Current active main mode.
       */
    uint8_t sub_mode; /*<  
        Current active sub mode.
       */
    uint8_t speed_mode; /*<  
        Current active speed mode.
       */
    uint8_t drive_mode; /*<  
        Current active drive mode.
       */
    uint8_t arm_mode; /*<  
        Current active drive mode.Arm(MAV_BOOL_FALSE = Disarm).
       */
    uint8_t intended_main_mode; /*<  
        Last main mode commanded by GCS.
       */
    uint8_t intended_sub_mode; /*<  
        Last sub mode commanded by GCS.
       */
    uint8_t intended_speed_mode; /*<  
        Last speed mode commanded by GCS.
       */
    uint8_t intended_drive_mode; /*<  
        Last drive mode commanded by GCS.
       */
    uint8_t intended_arm_mode; /*<  
        Last arm mode commanded by GCS.
       */
    uint8_t mode_change_reason; /*<  
        Reason for last mode transition.
       */
    uint8_t ts3_hour; /*<  no_definition */
    uint8_t ts3_minute; /*<  no_definition */
    uint8_t ts3_second; /*<  no_definition */
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
    uint8_t rear_mc_faults; /*<  
        Rear Motor Controller Faults
       */
    uint8_t front_mc_faults; /*<  
        Front Motor Controller Faults
       */
    uint8_t rear_mc_voltage; /*<  Left Motor Controller Voltage (Unit: 0.1 V) */
    uint8_t front_mc_voltage; /*<  Right Motor Controller Voltage (Unit: 0.1 V) */
    uint8_t rear_mc_temperature; /*<  Left Motor Controller Temperature (Unit: 1 Degree Celsius) */
    uint8_t front_mc_temperature; /*<  Right Motor Controller Temperature (Unit: 1 Degree Celsius) */
    uint8_t light_status; /*<  
        bit 0: head light state
        bit 1: front fog light state
        bit 2: rear light state
       */
    uint8_t pdu_channel_status; /*<  
        bit 0: lv pdu channel 1 state
        bit 1: lv pdu channel 2 state
        bit 2: lv pdu channel 3 state
        bit 3: lv pdu channel 4 state
        bit 4: lv pdu channel 5 state
        bit 5: lv pdu channel 6 state
        bit 6: lv pdu channel 7 state
        bit 7: lv pdu channel 8 state
       */


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
        ss << "  ts1_hour: " << +ts1_hour << std::endl;
        ss << "  ts1_minute: " << +ts1_minute << std::endl;
        ss << "  ts1_second: " << +ts1_second << std::endl;
        ss << "  subsystem_health_1: " << +subsystem_health_1 << std::endl;
        ss << "  subsystem_health_2: " << +subsystem_health_2 << std::endl;
        ss << "  subsystem_health_3: " << +subsystem_health_3 << std::endl;
        ss << "  subsystem_health_4: " << +subsystem_health_4 << std::endl;
        ss << "  ts2_hour: " << +ts2_hour << std::endl;
        ss << "  ts2_minute: " << +ts2_minute << std::endl;
        ss << "  ts2_second: " << +ts2_second << std::endl;
        ss << "  battery_soc: " << +battery_soc << std::endl;
        ss << "  main_mode: " << +main_mode << std::endl;
        ss << "  sub_mode: " << +sub_mode << std::endl;
        ss << "  speed_mode: " << +speed_mode << std::endl;
        ss << "  drive_mode: " << +drive_mode << std::endl;
        ss << "  arm_mode: " << +arm_mode << std::endl;
        ss << "  intended_main_mode: " << +intended_main_mode << std::endl;
        ss << "  intended_sub_mode: " << +intended_sub_mode << std::endl;
        ss << "  intended_speed_mode: " << +intended_speed_mode << std::endl;
        ss << "  intended_drive_mode: " << +intended_drive_mode << std::endl;
        ss << "  intended_arm_mode: " << +intended_arm_mode << std::endl;
        ss << "  mode_change_reason: " << +mode_change_reason << std::endl;
        ss << "  ts3_hour: " << +ts3_hour << std::endl;
        ss << "  ts3_minute: " << +ts3_minute << std::endl;
        ss << "  ts3_second: " << +ts3_second << std::endl;
        ss << "  rear_left_motor_faults: " << +rear_left_motor_faults << std::endl;
        ss << "  rear_right_motor_faults: " << +rear_right_motor_faults << std::endl;
        ss << "  front_left_motor_faults: " << +front_left_motor_faults << std::endl;
        ss << "  front_right_motor_faults: " << +front_right_motor_faults << std::endl;
        ss << "  rear_mc_faults: " << +rear_mc_faults << std::endl;
        ss << "  front_mc_faults: " << +front_mc_faults << std::endl;
        ss << "  rear_mc_voltage: " << +rear_mc_voltage << std::endl;
        ss << "  front_mc_voltage: " << +front_mc_voltage << std::endl;
        ss << "  rear_mc_temperature: " << +rear_mc_temperature << std::endl;
        ss << "  front_mc_temperature: " << +front_mc_temperature << std::endl;
        ss << "  light_status: " << +light_status << std::endl;
        ss << "  pdu_channel_status: " << +pdu_channel_status << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ts1_hour;                      // offset: 0
        map << ts1_minute;                    // offset: 1
        map << ts1_second;                    // offset: 2
        map << subsystem_health_1;            // offset: 3
        map << subsystem_health_2;            // offset: 4
        map << subsystem_health_3;            // offset: 5
        map << subsystem_health_4;            // offset: 6
        map << ts2_hour;                      // offset: 7
        map << ts2_minute;                    // offset: 8
        map << ts2_second;                    // offset: 9
        map << battery_soc;                   // offset: 10
        map << main_mode;                     // offset: 11
        map << sub_mode;                      // offset: 12
        map << speed_mode;                    // offset: 13
        map << drive_mode;                    // offset: 14
        map << arm_mode;                      // offset: 15
        map << intended_main_mode;            // offset: 16
        map << intended_sub_mode;             // offset: 17
        map << intended_speed_mode;           // offset: 18
        map << intended_drive_mode;           // offset: 19
        map << intended_arm_mode;             // offset: 20
        map << mode_change_reason;            // offset: 21
        map << ts3_hour;                      // offset: 22
        map << ts3_minute;                    // offset: 23
        map << ts3_second;                    // offset: 24
        map << rear_left_motor_faults;        // offset: 25
        map << rear_right_motor_faults;       // offset: 26
        map << front_left_motor_faults;       // offset: 27
        map << front_right_motor_faults;      // offset: 28
        map << rear_mc_faults;                // offset: 29
        map << front_mc_faults;               // offset: 30
        map << rear_mc_voltage;               // offset: 31
        map << front_mc_voltage;              // offset: 32
        map << rear_mc_temperature;           // offset: 33
        map << front_mc_temperature;          // offset: 34
        map << light_status;                  // offset: 35
        map << pdu_channel_status;            // offset: 36
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ts1_hour;                      // offset: 0
        map >> ts1_minute;                    // offset: 1
        map >> ts1_second;                    // offset: 2
        map >> subsystem_health_1;            // offset: 3
        map >> subsystem_health_2;            // offset: 4
        map >> subsystem_health_3;            // offset: 5
        map >> subsystem_health_4;            // offset: 6
        map >> ts2_hour;                      // offset: 7
        map >> ts2_minute;                    // offset: 8
        map >> ts2_second;                    // offset: 9
        map >> battery_soc;                   // offset: 10
        map >> main_mode;                     // offset: 11
        map >> sub_mode;                      // offset: 12
        map >> speed_mode;                    // offset: 13
        map >> drive_mode;                    // offset: 14
        map >> arm_mode;                      // offset: 15
        map >> intended_main_mode;            // offset: 16
        map >> intended_sub_mode;             // offset: 17
        map >> intended_speed_mode;           // offset: 18
        map >> intended_drive_mode;           // offset: 19
        map >> intended_arm_mode;             // offset: 20
        map >> mode_change_reason;            // offset: 21
        map >> ts3_hour;                      // offset: 22
        map >> ts3_minute;                    // offset: 23
        map >> ts3_second;                    // offset: 24
        map >> rear_left_motor_faults;        // offset: 25
        map >> rear_right_motor_faults;       // offset: 26
        map >> front_left_motor_faults;       // offset: 27
        map >> front_right_motor_faults;      // offset: 28
        map >> rear_mc_faults;                // offset: 29
        map >> front_mc_faults;               // offset: 30
        map >> rear_mc_voltage;               // offset: 31
        map >> front_mc_voltage;              // offset: 32
        map >> rear_mc_temperature;           // offset: 33
        map >> front_mc_temperature;          // offset: 34
        map >> light_status;                  // offset: 35
        map >> pdu_channel_status;            // offset: 36
    }
};

} // namespace msg
} // namespace ugvCustom
} // namespace mavlink
