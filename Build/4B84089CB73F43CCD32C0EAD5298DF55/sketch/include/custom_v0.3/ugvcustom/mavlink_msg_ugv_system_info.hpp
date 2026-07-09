#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvcustom/mavlink_msg_ugv_system_info.hpp"
// MESSAGE UGV_SYSTEM_INFO support class

#pragma once

namespace mavlink {
namespace ugvcustom {
namespace msg {

/**
 * @brief UGV_SYSTEM_INFO message
 *
 * Provides aggregated health and status of all subsystems. ICD: COMP_UGV_STATUS. Direction: Compute broadcast. Frequency: 1 Hz. Payload length: 55 bytes.
 */
struct UGV_SYSTEM_INFO : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 55;
    static constexpr size_t MIN_LENGTH = 55;
    static constexpr uint8_t CRC_EXTRA = 88;
    static constexpr auto NAME = "UGV_SYSTEM_INFO";


    uint8_t vcu_status; /*<  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved. */
    uint16_t battery_soc; /*<  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. */
    uint16_t comp_mode1; /*<  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved. */
    uint8_t comp_mode2; /*<  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on. */
    uint16_t sensor_subsystem_health_1; /*<  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use. */
    uint8_t sensor_subsystem_health_2; /*<  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use. */
    uint32_t sensor_subsystem_health_3; /*<  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present. */
    uint16_t sensor_subsystem_health_4; /*<  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use. */
    uint32_t vcu_subsystem_status; /*<  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use. */
    uint16_t comp_subsystem_status; /*<  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use. */
    uint32_t vcu_subsystem_power_state1; /*<  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. */
    uint8_t vcu_power_subsystem_state2; /*<  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use. */
    uint32_t motor_faults; /*<  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present. */
    uint8_t validity_motor_faults; /*<  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use. */
    uint16_t mc_faults_1; /*<  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present. */
    uint8_t mc_faults_2; /*<  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use. */
    uint8_t contactor_fault; /*<  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use. */
    uint8_t pdu_fault; /*<  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault. */
    uint16_t power_subsystem_faults1; /*<  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present. */
    uint8_t power_subsystem_faults2; /*<  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use. */
    uint16_t vcu_interface_health; /*<  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault. */
    uint16_t sec_comp_status; /*<  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use. */
    uint8_t comp_interface_health1; /*<  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use. */
    uint16_t comp_interface_health2; /*<  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use. */
    uint8_t home_location; /*<  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use. */
    int32_t lat; /*<  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7. */
    int32_t lon; /*<  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7. */


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
        ss << "  vcu_status: " << +vcu_status << std::endl;
        ss << "  battery_soc: " << battery_soc << std::endl;
        ss << "  comp_mode1: " << comp_mode1 << std::endl;
        ss << "  comp_mode2: " << +comp_mode2 << std::endl;
        ss << "  sensor_subsystem_health_1: " << sensor_subsystem_health_1 << std::endl;
        ss << "  sensor_subsystem_health_2: " << +sensor_subsystem_health_2 << std::endl;
        ss << "  sensor_subsystem_health_3: " << sensor_subsystem_health_3 << std::endl;
        ss << "  sensor_subsystem_health_4: " << sensor_subsystem_health_4 << std::endl;
        ss << "  vcu_subsystem_status: " << vcu_subsystem_status << std::endl;
        ss << "  comp_subsystem_status: " << comp_subsystem_status << std::endl;
        ss << "  vcu_subsystem_power_state1: " << vcu_subsystem_power_state1 << std::endl;
        ss << "  vcu_power_subsystem_state2: " << +vcu_power_subsystem_state2 << std::endl;
        ss << "  motor_faults: " << motor_faults << std::endl;
        ss << "  validity_motor_faults: " << +validity_motor_faults << std::endl;
        ss << "  mc_faults_1: " << mc_faults_1 << std::endl;
        ss << "  mc_faults_2: " << +mc_faults_2 << std::endl;
        ss << "  contactor_fault: " << +contactor_fault << std::endl;
        ss << "  pdu_fault: " << +pdu_fault << std::endl;
        ss << "  power_subsystem_faults1: " << power_subsystem_faults1 << std::endl;
        ss << "  power_subsystem_faults2: " << +power_subsystem_faults2 << std::endl;
        ss << "  vcu_interface_health: " << vcu_interface_health << std::endl;
        ss << "  sec_comp_status: " << sec_comp_status << std::endl;
        ss << "  comp_interface_health1: " << +comp_interface_health1 << std::endl;
        ss << "  comp_interface_health2: " << comp_interface_health2 << std::endl;
        ss << "  home_location: " << +home_location << std::endl;
        ss << "  lat: " << lat << std::endl;
        ss << "  lon: " << lon << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << sensor_subsystem_health_3;     // offset: 0
        map << vcu_subsystem_status;          // offset: 4
        map << vcu_subsystem_power_state1;    // offset: 8
        map << motor_faults;                  // offset: 12
        map << lat;                           // offset: 16
        map << lon;                           // offset: 20
        map << battery_soc;                   // offset: 24
        map << comp_mode1;                    // offset: 26
        map << sensor_subsystem_health_1;     // offset: 28
        map << sensor_subsystem_health_4;     // offset: 30
        map << comp_subsystem_status;         // offset: 32
        map << mc_faults_1;                   // offset: 34
        map << power_subsystem_faults1;       // offset: 36
        map << vcu_interface_health;          // offset: 38
        map << sec_comp_status;               // offset: 40
        map << comp_interface_health2;        // offset: 42
        map << vcu_status;                    // offset: 44
        map << comp_mode2;                    // offset: 45
        map << sensor_subsystem_health_2;     // offset: 46
        map << vcu_power_subsystem_state2;    // offset: 47
        map << validity_motor_faults;         // offset: 48
        map << mc_faults_2;                   // offset: 49
        map << contactor_fault;               // offset: 50
        map << pdu_fault;                     // offset: 51
        map << power_subsystem_faults2;       // offset: 52
        map << comp_interface_health1;        // offset: 53
        map << home_location;                 // offset: 54
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> sensor_subsystem_health_3;     // offset: 0
        map >> vcu_subsystem_status;          // offset: 4
        map >> vcu_subsystem_power_state1;    // offset: 8
        map >> motor_faults;                  // offset: 12
        map >> lat;                           // offset: 16
        map >> lon;                           // offset: 20
        map >> battery_soc;                   // offset: 24
        map >> comp_mode1;                    // offset: 26
        map >> sensor_subsystem_health_1;     // offset: 28
        map >> sensor_subsystem_health_4;     // offset: 30
        map >> comp_subsystem_status;         // offset: 32
        map >> mc_faults_1;                   // offset: 34
        map >> power_subsystem_faults1;       // offset: 36
        map >> vcu_interface_health;          // offset: 38
        map >> sec_comp_status;               // offset: 40
        map >> comp_interface_health2;        // offset: 42
        map >> vcu_status;                    // offset: 44
        map >> comp_mode2;                    // offset: 45
        map >> sensor_subsystem_health_2;     // offset: 46
        map >> vcu_power_subsystem_state2;    // offset: 47
        map >> validity_motor_faults;         // offset: 48
        map >> mc_faults_2;                   // offset: 49
        map >> contactor_fault;               // offset: 50
        map >> pdu_fault;                     // offset: 51
        map >> power_subsystem_faults2;       // offset: 52
        map >> comp_interface_health1;        // offset: 53
        map >> home_location;                 // offset: 54
    }
};

} // namespace msg
} // namespace ugvcustom
} // namespace mavlink
