#pragma once
// MESSAGE UGV_SYSTEM_INFO PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO 50001


typedef struct __mavlink_ugv_system_info_t {
 uint32_t sensor_subsystem_health_3; /*<  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.*/
 uint32_t vcu_subsystem_status; /*<  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.*/
 uint32_t vcu_subsystem_power_state1; /*<  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.*/
 uint32_t motor_faults; /*<  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.*/
 int32_t lat; /*<  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.*/
 int32_t lon; /*<  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.*/
 uint16_t battery_soc; /*<  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.*/
 uint16_t comp_mode1; /*<  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.*/
 uint16_t sensor_subsystem_health_1; /*<  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.*/
 uint16_t sensor_subsystem_health_4; /*<  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.*/
 uint16_t comp_subsystem_status; /*<  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.*/
 uint16_t mc_faults_1; /*<  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.*/
 uint16_t power_subsystem_faults1; /*<  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.*/
 uint16_t vcu_interface_health; /*<  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.*/
 uint16_t sec_comp_status; /*<  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.*/
 uint16_t comp_interface_health2; /*<  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.*/
 uint8_t vcu_status; /*<  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.*/
 uint8_t comp_mode2; /*<  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.*/
 uint8_t sensor_subsystem_health_2; /*<  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.*/
 uint8_t vcu_power_subsystem_state2; /*<  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.*/
 uint8_t validity_motor_faults; /*<  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.*/
 uint8_t mc_faults_2; /*<  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.*/
 uint8_t contactor_fault; /*<  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.*/
 uint8_t pdu_fault; /*<  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.*/
 uint8_t power_subsystem_faults2; /*<  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.*/
 uint8_t comp_interface_health1; /*<  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.*/
 uint8_t home_location; /*<  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.*/
} mavlink_ugv_system_info_t;

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN 55
#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN 55
#define MAVLINK_MSG_ID_50001_LEN 55
#define MAVLINK_MSG_ID_50001_MIN_LEN 55

#define MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC 88
#define MAVLINK_MSG_ID_50001_CRC 88



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    50001, \
    "UGV_SYSTEM_INFO", \
    27, \
    {  { "vcu_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ugv_system_info_t, vcu_status) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "comp_mode1", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ugv_system_info_t, comp_mode1) }, \
         { "comp_mode2", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_ugv_system_info_t, comp_mode2) }, \
         { "sensor_subsystem_health_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_1) }, \
         { "sensor_subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_2) }, \
         { "sensor_subsystem_health_3", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_3) }, \
         { "sensor_subsystem_health_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_4) }, \
         { "vcu_subsystem_status", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ugv_system_info_t, vcu_subsystem_status) }, \
         { "comp_subsystem_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_ugv_system_info_t, comp_subsystem_status) }, \
         { "vcu_subsystem_power_state1", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ugv_system_info_t, vcu_subsystem_power_state1) }, \
         { "vcu_power_subsystem_state2", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_ugv_system_info_t, vcu_power_subsystem_state2) }, \
         { "motor_faults", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_ugv_system_info_t, motor_faults) }, \
         { "validity_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_ugv_system_info_t, validity_motor_faults) }, \
         { "mc_faults_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ugv_system_info_t, mc_faults_1) }, \
         { "mc_faults_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_ugv_system_info_t, mc_faults_2) }, \
         { "contactor_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_ugv_system_info_t, contactor_fault) }, \
         { "pdu_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_ugv_system_info_t, pdu_fault) }, \
         { "power_subsystem_faults1", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ugv_system_info_t, power_subsystem_faults1) }, \
         { "power_subsystem_faults2", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_ugv_system_info_t, power_subsystem_faults2) }, \
         { "vcu_interface_health", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_ugv_system_info_t, vcu_interface_health) }, \
         { "sec_comp_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_ugv_system_info_t, sec_comp_status) }, \
         { "comp_interface_health1", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_ugv_system_info_t, comp_interface_health1) }, \
         { "comp_interface_health2", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_ugv_system_info_t, comp_interface_health2) }, \
         { "home_location", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_ugv_system_info_t, home_location) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_ugv_system_info_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_ugv_system_info_t, lon) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO { \
    "UGV_SYSTEM_INFO", \
    27, \
    {  { "vcu_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ugv_system_info_t, vcu_status) }, \
         { "battery_soc", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_ugv_system_info_t, battery_soc) }, \
         { "comp_mode1", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_ugv_system_info_t, comp_mode1) }, \
         { "comp_mode2", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_ugv_system_info_t, comp_mode2) }, \
         { "sensor_subsystem_health_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_1) }, \
         { "sensor_subsystem_health_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_2) }, \
         { "sensor_subsystem_health_3", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_3) }, \
         { "sensor_subsystem_health_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_ugv_system_info_t, sensor_subsystem_health_4) }, \
         { "vcu_subsystem_status", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_ugv_system_info_t, vcu_subsystem_status) }, \
         { "comp_subsystem_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_ugv_system_info_t, comp_subsystem_status) }, \
         { "vcu_subsystem_power_state1", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ugv_system_info_t, vcu_subsystem_power_state1) }, \
         { "vcu_power_subsystem_state2", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_ugv_system_info_t, vcu_power_subsystem_state2) }, \
         { "motor_faults", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_ugv_system_info_t, motor_faults) }, \
         { "validity_motor_faults", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_ugv_system_info_t, validity_motor_faults) }, \
         { "mc_faults_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ugv_system_info_t, mc_faults_1) }, \
         { "mc_faults_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_ugv_system_info_t, mc_faults_2) }, \
         { "contactor_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_ugv_system_info_t, contactor_fault) }, \
         { "pdu_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_ugv_system_info_t, pdu_fault) }, \
         { "power_subsystem_faults1", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ugv_system_info_t, power_subsystem_faults1) }, \
         { "power_subsystem_faults2", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_ugv_system_info_t, power_subsystem_faults2) }, \
         { "vcu_interface_health", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_ugv_system_info_t, vcu_interface_health) }, \
         { "sec_comp_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_ugv_system_info_t, sec_comp_status) }, \
         { "comp_interface_health1", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_ugv_system_info_t, comp_interface_health1) }, \
         { "comp_interface_health2", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_ugv_system_info_t, comp_interface_health2) }, \
         { "home_location", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_ugv_system_info_t, home_location) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_ugv_system_info_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_ugv_system_info_t, lon) }, \
         } \
}
#endif

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vcu_status  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.
 * @param battery_soc  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.
 * @param comp_mode1  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.
 * @param comp_mode2  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.
 * @param sensor_subsystem_health_1  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.
 * @param sensor_subsystem_health_2  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.
 * @param sensor_subsystem_health_3  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.
 * @param sensor_subsystem_health_4  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.
 * @param vcu_subsystem_status  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.
 * @param comp_subsystem_status  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.
 * @param vcu_subsystem_power_state1  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.
 * @param vcu_power_subsystem_state2  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.
 * @param motor_faults  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.
 * @param validity_motor_faults  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.
 * @param mc_faults_1  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.
 * @param mc_faults_2  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.
 * @param contactor_fault  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.
 * @param pdu_fault  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.
 * @param power_subsystem_faults1  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.
 * @param power_subsystem_faults2  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.
 * @param vcu_interface_health  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.
 * @param sec_comp_status  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.
 * @param comp_interface_health1  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.
 * @param comp_interface_health2  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.
 * @param home_location  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.
 * @param lat  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.
 * @param lon  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vcu_status, uint16_t battery_soc, uint16_t comp_mode1, uint8_t comp_mode2, uint16_t sensor_subsystem_health_1, uint8_t sensor_subsystem_health_2, uint32_t sensor_subsystem_health_3, uint16_t sensor_subsystem_health_4, uint32_t vcu_subsystem_status, uint16_t comp_subsystem_status, uint32_t vcu_subsystem_power_state1, uint8_t vcu_power_subsystem_state2, uint32_t motor_faults, uint8_t validity_motor_faults, uint16_t mc_faults_1, uint8_t mc_faults_2, uint8_t contactor_fault, uint8_t pdu_fault, uint16_t power_subsystem_faults1, uint8_t power_subsystem_faults2, uint16_t vcu_interface_health, uint16_t sec_comp_status, uint8_t comp_interface_health1, uint16_t comp_interface_health2, uint8_t home_location, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, sensor_subsystem_health_3);
    _mav_put_uint32_t(buf, 4, vcu_subsystem_status);
    _mav_put_uint32_t(buf, 8, vcu_subsystem_power_state1);
    _mav_put_uint32_t(buf, 12, motor_faults);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_uint16_t(buf, 24, battery_soc);
    _mav_put_uint16_t(buf, 26, comp_mode1);
    _mav_put_uint16_t(buf, 28, sensor_subsystem_health_1);
    _mav_put_uint16_t(buf, 30, sensor_subsystem_health_4);
    _mav_put_uint16_t(buf, 32, comp_subsystem_status);
    _mav_put_uint16_t(buf, 34, mc_faults_1);
    _mav_put_uint16_t(buf, 36, power_subsystem_faults1);
    _mav_put_uint16_t(buf, 38, vcu_interface_health);
    _mav_put_uint16_t(buf, 40, sec_comp_status);
    _mav_put_uint16_t(buf, 42, comp_interface_health2);
    _mav_put_uint8_t(buf, 44, vcu_status);
    _mav_put_uint8_t(buf, 45, comp_mode2);
    _mav_put_uint8_t(buf, 46, sensor_subsystem_health_2);
    _mav_put_uint8_t(buf, 47, vcu_power_subsystem_state2);
    _mav_put_uint8_t(buf, 48, validity_motor_faults);
    _mav_put_uint8_t(buf, 49, mc_faults_2);
    _mav_put_uint8_t(buf, 50, contactor_fault);
    _mav_put_uint8_t(buf, 51, pdu_fault);
    _mav_put_uint8_t(buf, 52, power_subsystem_faults2);
    _mav_put_uint8_t(buf, 53, comp_interface_health1);
    _mav_put_uint8_t(buf, 54, home_location);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.sensor_subsystem_health_3 = sensor_subsystem_health_3;
    packet.vcu_subsystem_status = vcu_subsystem_status;
    packet.vcu_subsystem_power_state1 = vcu_subsystem_power_state1;
    packet.motor_faults = motor_faults;
    packet.lat = lat;
    packet.lon = lon;
    packet.battery_soc = battery_soc;
    packet.comp_mode1 = comp_mode1;
    packet.sensor_subsystem_health_1 = sensor_subsystem_health_1;
    packet.sensor_subsystem_health_4 = sensor_subsystem_health_4;
    packet.comp_subsystem_status = comp_subsystem_status;
    packet.mc_faults_1 = mc_faults_1;
    packet.power_subsystem_faults1 = power_subsystem_faults1;
    packet.vcu_interface_health = vcu_interface_health;
    packet.sec_comp_status = sec_comp_status;
    packet.comp_interface_health2 = comp_interface_health2;
    packet.vcu_status = vcu_status;
    packet.comp_mode2 = comp_mode2;
    packet.sensor_subsystem_health_2 = sensor_subsystem_health_2;
    packet.vcu_power_subsystem_state2 = vcu_power_subsystem_state2;
    packet.validity_motor_faults = validity_motor_faults;
    packet.mc_faults_2 = mc_faults_2;
    packet.contactor_fault = contactor_fault;
    packet.pdu_fault = pdu_fault;
    packet.power_subsystem_faults2 = power_subsystem_faults2;
    packet.comp_interface_health1 = comp_interface_health1;
    packet.home_location = home_location;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
}

/**
 * @brief Pack a ugv_system_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vcu_status  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.
 * @param battery_soc  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.
 * @param comp_mode1  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.
 * @param comp_mode2  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.
 * @param sensor_subsystem_health_1  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.
 * @param sensor_subsystem_health_2  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.
 * @param sensor_subsystem_health_3  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.
 * @param sensor_subsystem_health_4  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.
 * @param vcu_subsystem_status  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.
 * @param comp_subsystem_status  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.
 * @param vcu_subsystem_power_state1  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.
 * @param vcu_power_subsystem_state2  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.
 * @param motor_faults  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.
 * @param validity_motor_faults  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.
 * @param mc_faults_1  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.
 * @param mc_faults_2  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.
 * @param contactor_fault  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.
 * @param pdu_fault  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.
 * @param power_subsystem_faults1  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.
 * @param power_subsystem_faults2  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.
 * @param vcu_interface_health  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.
 * @param sec_comp_status  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.
 * @param comp_interface_health1  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.
 * @param comp_interface_health2  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.
 * @param home_location  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.
 * @param lat  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.
 * @param lon  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vcu_status, uint16_t battery_soc, uint16_t comp_mode1, uint8_t comp_mode2, uint16_t sensor_subsystem_health_1, uint8_t sensor_subsystem_health_2, uint32_t sensor_subsystem_health_3, uint16_t sensor_subsystem_health_4, uint32_t vcu_subsystem_status, uint16_t comp_subsystem_status, uint32_t vcu_subsystem_power_state1, uint8_t vcu_power_subsystem_state2, uint32_t motor_faults, uint8_t validity_motor_faults, uint16_t mc_faults_1, uint8_t mc_faults_2, uint8_t contactor_fault, uint8_t pdu_fault, uint16_t power_subsystem_faults1, uint8_t power_subsystem_faults2, uint16_t vcu_interface_health, uint16_t sec_comp_status, uint8_t comp_interface_health1, uint16_t comp_interface_health2, uint8_t home_location, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, sensor_subsystem_health_3);
    _mav_put_uint32_t(buf, 4, vcu_subsystem_status);
    _mav_put_uint32_t(buf, 8, vcu_subsystem_power_state1);
    _mav_put_uint32_t(buf, 12, motor_faults);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_uint16_t(buf, 24, battery_soc);
    _mav_put_uint16_t(buf, 26, comp_mode1);
    _mav_put_uint16_t(buf, 28, sensor_subsystem_health_1);
    _mav_put_uint16_t(buf, 30, sensor_subsystem_health_4);
    _mav_put_uint16_t(buf, 32, comp_subsystem_status);
    _mav_put_uint16_t(buf, 34, mc_faults_1);
    _mav_put_uint16_t(buf, 36, power_subsystem_faults1);
    _mav_put_uint16_t(buf, 38, vcu_interface_health);
    _mav_put_uint16_t(buf, 40, sec_comp_status);
    _mav_put_uint16_t(buf, 42, comp_interface_health2);
    _mav_put_uint8_t(buf, 44, vcu_status);
    _mav_put_uint8_t(buf, 45, comp_mode2);
    _mav_put_uint8_t(buf, 46, sensor_subsystem_health_2);
    _mav_put_uint8_t(buf, 47, vcu_power_subsystem_state2);
    _mav_put_uint8_t(buf, 48, validity_motor_faults);
    _mav_put_uint8_t(buf, 49, mc_faults_2);
    _mav_put_uint8_t(buf, 50, contactor_fault);
    _mav_put_uint8_t(buf, 51, pdu_fault);
    _mav_put_uint8_t(buf, 52, power_subsystem_faults2);
    _mav_put_uint8_t(buf, 53, comp_interface_health1);
    _mav_put_uint8_t(buf, 54, home_location);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.sensor_subsystem_health_3 = sensor_subsystem_health_3;
    packet.vcu_subsystem_status = vcu_subsystem_status;
    packet.vcu_subsystem_power_state1 = vcu_subsystem_power_state1;
    packet.motor_faults = motor_faults;
    packet.lat = lat;
    packet.lon = lon;
    packet.battery_soc = battery_soc;
    packet.comp_mode1 = comp_mode1;
    packet.sensor_subsystem_health_1 = sensor_subsystem_health_1;
    packet.sensor_subsystem_health_4 = sensor_subsystem_health_4;
    packet.comp_subsystem_status = comp_subsystem_status;
    packet.mc_faults_1 = mc_faults_1;
    packet.power_subsystem_faults1 = power_subsystem_faults1;
    packet.vcu_interface_health = vcu_interface_health;
    packet.sec_comp_status = sec_comp_status;
    packet.comp_interface_health2 = comp_interface_health2;
    packet.vcu_status = vcu_status;
    packet.comp_mode2 = comp_mode2;
    packet.sensor_subsystem_health_2 = sensor_subsystem_health_2;
    packet.vcu_power_subsystem_state2 = vcu_power_subsystem_state2;
    packet.validity_motor_faults = validity_motor_faults;
    packet.mc_faults_2 = mc_faults_2;
    packet.contactor_fault = contactor_fault;
    packet.pdu_fault = pdu_fault;
    packet.power_subsystem_faults2 = power_subsystem_faults2;
    packet.comp_interface_health1 = comp_interface_health1;
    packet.home_location = home_location;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif
}

/**
 * @brief Pack a ugv_system_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vcu_status  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.
 * @param battery_soc  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.
 * @param comp_mode1  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.
 * @param comp_mode2  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.
 * @param sensor_subsystem_health_1  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.
 * @param sensor_subsystem_health_2  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.
 * @param sensor_subsystem_health_3  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.
 * @param sensor_subsystem_health_4  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.
 * @param vcu_subsystem_status  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.
 * @param comp_subsystem_status  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.
 * @param vcu_subsystem_power_state1  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.
 * @param vcu_power_subsystem_state2  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.
 * @param motor_faults  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.
 * @param validity_motor_faults  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.
 * @param mc_faults_1  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.
 * @param mc_faults_2  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.
 * @param contactor_fault  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.
 * @param pdu_fault  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.
 * @param power_subsystem_faults1  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.
 * @param power_subsystem_faults2  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.
 * @param vcu_interface_health  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.
 * @param sec_comp_status  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.
 * @param comp_interface_health1  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.
 * @param comp_interface_health2  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.
 * @param home_location  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.
 * @param lat  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.
 * @param lon  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ugv_system_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vcu_status,uint16_t battery_soc,uint16_t comp_mode1,uint8_t comp_mode2,uint16_t sensor_subsystem_health_1,uint8_t sensor_subsystem_health_2,uint32_t sensor_subsystem_health_3,uint16_t sensor_subsystem_health_4,uint32_t vcu_subsystem_status,uint16_t comp_subsystem_status,uint32_t vcu_subsystem_power_state1,uint8_t vcu_power_subsystem_state2,uint32_t motor_faults,uint8_t validity_motor_faults,uint16_t mc_faults_1,uint8_t mc_faults_2,uint8_t contactor_fault,uint8_t pdu_fault,uint16_t power_subsystem_faults1,uint8_t power_subsystem_faults2,uint16_t vcu_interface_health,uint16_t sec_comp_status,uint8_t comp_interface_health1,uint16_t comp_interface_health2,uint8_t home_location,int32_t lat,int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, sensor_subsystem_health_3);
    _mav_put_uint32_t(buf, 4, vcu_subsystem_status);
    _mav_put_uint32_t(buf, 8, vcu_subsystem_power_state1);
    _mav_put_uint32_t(buf, 12, motor_faults);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_uint16_t(buf, 24, battery_soc);
    _mav_put_uint16_t(buf, 26, comp_mode1);
    _mav_put_uint16_t(buf, 28, sensor_subsystem_health_1);
    _mav_put_uint16_t(buf, 30, sensor_subsystem_health_4);
    _mav_put_uint16_t(buf, 32, comp_subsystem_status);
    _mav_put_uint16_t(buf, 34, mc_faults_1);
    _mav_put_uint16_t(buf, 36, power_subsystem_faults1);
    _mav_put_uint16_t(buf, 38, vcu_interface_health);
    _mav_put_uint16_t(buf, 40, sec_comp_status);
    _mav_put_uint16_t(buf, 42, comp_interface_health2);
    _mav_put_uint8_t(buf, 44, vcu_status);
    _mav_put_uint8_t(buf, 45, comp_mode2);
    _mav_put_uint8_t(buf, 46, sensor_subsystem_health_2);
    _mav_put_uint8_t(buf, 47, vcu_power_subsystem_state2);
    _mav_put_uint8_t(buf, 48, validity_motor_faults);
    _mav_put_uint8_t(buf, 49, mc_faults_2);
    _mav_put_uint8_t(buf, 50, contactor_fault);
    _mav_put_uint8_t(buf, 51, pdu_fault);
    _mav_put_uint8_t(buf, 52, power_subsystem_faults2);
    _mav_put_uint8_t(buf, 53, comp_interface_health1);
    _mav_put_uint8_t(buf, 54, home_location);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#else
    mavlink_ugv_system_info_t packet;
    packet.sensor_subsystem_health_3 = sensor_subsystem_health_3;
    packet.vcu_subsystem_status = vcu_subsystem_status;
    packet.vcu_subsystem_power_state1 = vcu_subsystem_power_state1;
    packet.motor_faults = motor_faults;
    packet.lat = lat;
    packet.lon = lon;
    packet.battery_soc = battery_soc;
    packet.comp_mode1 = comp_mode1;
    packet.sensor_subsystem_health_1 = sensor_subsystem_health_1;
    packet.sensor_subsystem_health_4 = sensor_subsystem_health_4;
    packet.comp_subsystem_status = comp_subsystem_status;
    packet.mc_faults_1 = mc_faults_1;
    packet.power_subsystem_faults1 = power_subsystem_faults1;
    packet.vcu_interface_health = vcu_interface_health;
    packet.sec_comp_status = sec_comp_status;
    packet.comp_interface_health2 = comp_interface_health2;
    packet.vcu_status = vcu_status;
    packet.comp_mode2 = comp_mode2;
    packet.sensor_subsystem_health_2 = sensor_subsystem_health_2;
    packet.vcu_power_subsystem_state2 = vcu_power_subsystem_state2;
    packet.validity_motor_faults = validity_motor_faults;
    packet.mc_faults_2 = mc_faults_2;
    packet.contactor_fault = contactor_fault;
    packet.pdu_fault = pdu_fault;
    packet.power_subsystem_faults2 = power_subsystem_faults2;
    packet.comp_interface_health1 = comp_interface_health1;
    packet.home_location = home_location;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UGV_SYSTEM_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
}

/**
 * @brief Encode a ugv_system_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack(system_id, component_id, msg, ugv_system_info->vcu_status, ugv_system_info->battery_soc, ugv_system_info->comp_mode1, ugv_system_info->comp_mode2, ugv_system_info->sensor_subsystem_health_1, ugv_system_info->sensor_subsystem_health_2, ugv_system_info->sensor_subsystem_health_3, ugv_system_info->sensor_subsystem_health_4, ugv_system_info->vcu_subsystem_status, ugv_system_info->comp_subsystem_status, ugv_system_info->vcu_subsystem_power_state1, ugv_system_info->vcu_power_subsystem_state2, ugv_system_info->motor_faults, ugv_system_info->validity_motor_faults, ugv_system_info->mc_faults_1, ugv_system_info->mc_faults_2, ugv_system_info->contactor_fault, ugv_system_info->pdu_fault, ugv_system_info->power_subsystem_faults1, ugv_system_info->power_subsystem_faults2, ugv_system_info->vcu_interface_health, ugv_system_info->sec_comp_status, ugv_system_info->comp_interface_health1, ugv_system_info->comp_interface_health2, ugv_system_info->home_location, ugv_system_info->lat, ugv_system_info->lon);
}

/**
 * @brief Encode a ugv_system_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack_chan(system_id, component_id, chan, msg, ugv_system_info->vcu_status, ugv_system_info->battery_soc, ugv_system_info->comp_mode1, ugv_system_info->comp_mode2, ugv_system_info->sensor_subsystem_health_1, ugv_system_info->sensor_subsystem_health_2, ugv_system_info->sensor_subsystem_health_3, ugv_system_info->sensor_subsystem_health_4, ugv_system_info->vcu_subsystem_status, ugv_system_info->comp_subsystem_status, ugv_system_info->vcu_subsystem_power_state1, ugv_system_info->vcu_power_subsystem_state2, ugv_system_info->motor_faults, ugv_system_info->validity_motor_faults, ugv_system_info->mc_faults_1, ugv_system_info->mc_faults_2, ugv_system_info->contactor_fault, ugv_system_info->pdu_fault, ugv_system_info->power_subsystem_faults1, ugv_system_info->power_subsystem_faults2, ugv_system_info->vcu_interface_health, ugv_system_info->sec_comp_status, ugv_system_info->comp_interface_health1, ugv_system_info->comp_interface_health2, ugv_system_info->home_location, ugv_system_info->lat, ugv_system_info->lon);
}

/**
 * @brief Encode a ugv_system_info struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ugv_system_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ugv_system_info_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ugv_system_info_t* ugv_system_info)
{
    return mavlink_msg_ugv_system_info_pack_status(system_id, component_id, _status, msg,  ugv_system_info->vcu_status, ugv_system_info->battery_soc, ugv_system_info->comp_mode1, ugv_system_info->comp_mode2, ugv_system_info->sensor_subsystem_health_1, ugv_system_info->sensor_subsystem_health_2, ugv_system_info->sensor_subsystem_health_3, ugv_system_info->sensor_subsystem_health_4, ugv_system_info->vcu_subsystem_status, ugv_system_info->comp_subsystem_status, ugv_system_info->vcu_subsystem_power_state1, ugv_system_info->vcu_power_subsystem_state2, ugv_system_info->motor_faults, ugv_system_info->validity_motor_faults, ugv_system_info->mc_faults_1, ugv_system_info->mc_faults_2, ugv_system_info->contactor_fault, ugv_system_info->pdu_fault, ugv_system_info->power_subsystem_faults1, ugv_system_info->power_subsystem_faults2, ugv_system_info->vcu_interface_health, ugv_system_info->sec_comp_status, ugv_system_info->comp_interface_health1, ugv_system_info->comp_interface_health2, ugv_system_info->home_location, ugv_system_info->lat, ugv_system_info->lon);
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 *
 * @param vcu_status  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.
 * @param battery_soc  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.
 * @param comp_mode1  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.
 * @param comp_mode2  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.
 * @param sensor_subsystem_health_1  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.
 * @param sensor_subsystem_health_2  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.
 * @param sensor_subsystem_health_3  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.
 * @param sensor_subsystem_health_4  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.
 * @param vcu_subsystem_status  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.
 * @param comp_subsystem_status  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.
 * @param vcu_subsystem_power_state1  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.
 * @param vcu_power_subsystem_state2  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.
 * @param motor_faults  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.
 * @param validity_motor_faults  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.
 * @param mc_faults_1  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.
 * @param mc_faults_2  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.
 * @param contactor_fault  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.
 * @param pdu_fault  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.
 * @param power_subsystem_faults1  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.
 * @param power_subsystem_faults2  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.
 * @param vcu_interface_health  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.
 * @param sec_comp_status  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.
 * @param comp_interface_health1  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.
 * @param comp_interface_health2  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.
 * @param home_location  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.
 * @param lat  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.
 * @param lon  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ugv_system_info_send(mavlink_channel_t chan, uint8_t vcu_status, uint16_t battery_soc, uint16_t comp_mode1, uint8_t comp_mode2, uint16_t sensor_subsystem_health_1, uint8_t sensor_subsystem_health_2, uint32_t sensor_subsystem_health_3, uint16_t sensor_subsystem_health_4, uint32_t vcu_subsystem_status, uint16_t comp_subsystem_status, uint32_t vcu_subsystem_power_state1, uint8_t vcu_power_subsystem_state2, uint32_t motor_faults, uint8_t validity_motor_faults, uint16_t mc_faults_1, uint8_t mc_faults_2, uint8_t contactor_fault, uint8_t pdu_fault, uint16_t power_subsystem_faults1, uint8_t power_subsystem_faults2, uint16_t vcu_interface_health, uint16_t sec_comp_status, uint8_t comp_interface_health1, uint16_t comp_interface_health2, uint8_t home_location, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN];
    _mav_put_uint32_t(buf, 0, sensor_subsystem_health_3);
    _mav_put_uint32_t(buf, 4, vcu_subsystem_status);
    _mav_put_uint32_t(buf, 8, vcu_subsystem_power_state1);
    _mav_put_uint32_t(buf, 12, motor_faults);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_uint16_t(buf, 24, battery_soc);
    _mav_put_uint16_t(buf, 26, comp_mode1);
    _mav_put_uint16_t(buf, 28, sensor_subsystem_health_1);
    _mav_put_uint16_t(buf, 30, sensor_subsystem_health_4);
    _mav_put_uint16_t(buf, 32, comp_subsystem_status);
    _mav_put_uint16_t(buf, 34, mc_faults_1);
    _mav_put_uint16_t(buf, 36, power_subsystem_faults1);
    _mav_put_uint16_t(buf, 38, vcu_interface_health);
    _mav_put_uint16_t(buf, 40, sec_comp_status);
    _mav_put_uint16_t(buf, 42, comp_interface_health2);
    _mav_put_uint8_t(buf, 44, vcu_status);
    _mav_put_uint8_t(buf, 45, comp_mode2);
    _mav_put_uint8_t(buf, 46, sensor_subsystem_health_2);
    _mav_put_uint8_t(buf, 47, vcu_power_subsystem_state2);
    _mav_put_uint8_t(buf, 48, validity_motor_faults);
    _mav_put_uint8_t(buf, 49, mc_faults_2);
    _mav_put_uint8_t(buf, 50, contactor_fault);
    _mav_put_uint8_t(buf, 51, pdu_fault);
    _mav_put_uint8_t(buf, 52, power_subsystem_faults2);
    _mav_put_uint8_t(buf, 53, comp_interface_health1);
    _mav_put_uint8_t(buf, 54, home_location);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t packet;
    packet.sensor_subsystem_health_3 = sensor_subsystem_health_3;
    packet.vcu_subsystem_status = vcu_subsystem_status;
    packet.vcu_subsystem_power_state1 = vcu_subsystem_power_state1;
    packet.motor_faults = motor_faults;
    packet.lat = lat;
    packet.lon = lon;
    packet.battery_soc = battery_soc;
    packet.comp_mode1 = comp_mode1;
    packet.sensor_subsystem_health_1 = sensor_subsystem_health_1;
    packet.sensor_subsystem_health_4 = sensor_subsystem_health_4;
    packet.comp_subsystem_status = comp_subsystem_status;
    packet.mc_faults_1 = mc_faults_1;
    packet.power_subsystem_faults1 = power_subsystem_faults1;
    packet.vcu_interface_health = vcu_interface_health;
    packet.sec_comp_status = sec_comp_status;
    packet.comp_interface_health2 = comp_interface_health2;
    packet.vcu_status = vcu_status;
    packet.comp_mode2 = comp_mode2;
    packet.sensor_subsystem_health_2 = sensor_subsystem_health_2;
    packet.vcu_power_subsystem_state2 = vcu_power_subsystem_state2;
    packet.validity_motor_faults = validity_motor_faults;
    packet.mc_faults_2 = mc_faults_2;
    packet.contactor_fault = contactor_fault;
    packet.pdu_fault = pdu_fault;
    packet.power_subsystem_faults2 = power_subsystem_faults2;
    packet.comp_interface_health1 = comp_interface_health1;
    packet.home_location = home_location;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)&packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}

/**
 * @brief Send a ugv_system_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ugv_system_info_send_struct(mavlink_channel_t chan, const mavlink_ugv_system_info_t* ugv_system_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ugv_system_info_send(chan, ugv_system_info->vcu_status, ugv_system_info->battery_soc, ugv_system_info->comp_mode1, ugv_system_info->comp_mode2, ugv_system_info->sensor_subsystem_health_1, ugv_system_info->sensor_subsystem_health_2, ugv_system_info->sensor_subsystem_health_3, ugv_system_info->sensor_subsystem_health_4, ugv_system_info->vcu_subsystem_status, ugv_system_info->comp_subsystem_status, ugv_system_info->vcu_subsystem_power_state1, ugv_system_info->vcu_power_subsystem_state2, ugv_system_info->motor_faults, ugv_system_info->validity_motor_faults, ugv_system_info->mc_faults_1, ugv_system_info->mc_faults_2, ugv_system_info->contactor_fault, ugv_system_info->pdu_fault, ugv_system_info->power_subsystem_faults1, ugv_system_info->power_subsystem_faults2, ugv_system_info->vcu_interface_health, ugv_system_info->sec_comp_status, ugv_system_info->comp_interface_health1, ugv_system_info->comp_interface_health2, ugv_system_info->home_location, ugv_system_info->lat, ugv_system_info->lon);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)ugv_system_info, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ugv_system_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vcu_status, uint16_t battery_soc, uint16_t comp_mode1, uint8_t comp_mode2, uint16_t sensor_subsystem_health_1, uint8_t sensor_subsystem_health_2, uint32_t sensor_subsystem_health_3, uint16_t sensor_subsystem_health_4, uint32_t vcu_subsystem_status, uint16_t comp_subsystem_status, uint32_t vcu_subsystem_power_state1, uint8_t vcu_power_subsystem_state2, uint32_t motor_faults, uint8_t validity_motor_faults, uint16_t mc_faults_1, uint8_t mc_faults_2, uint8_t contactor_fault, uint8_t pdu_fault, uint16_t power_subsystem_faults1, uint8_t power_subsystem_faults2, uint16_t vcu_interface_health, uint16_t sec_comp_status, uint8_t comp_interface_health1, uint16_t comp_interface_health2, uint8_t home_location, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, sensor_subsystem_health_3);
    _mav_put_uint32_t(buf, 4, vcu_subsystem_status);
    _mav_put_uint32_t(buf, 8, vcu_subsystem_power_state1);
    _mav_put_uint32_t(buf, 12, motor_faults);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_uint16_t(buf, 24, battery_soc);
    _mav_put_uint16_t(buf, 26, comp_mode1);
    _mav_put_uint16_t(buf, 28, sensor_subsystem_health_1);
    _mav_put_uint16_t(buf, 30, sensor_subsystem_health_4);
    _mav_put_uint16_t(buf, 32, comp_subsystem_status);
    _mav_put_uint16_t(buf, 34, mc_faults_1);
    _mav_put_uint16_t(buf, 36, power_subsystem_faults1);
    _mav_put_uint16_t(buf, 38, vcu_interface_health);
    _mav_put_uint16_t(buf, 40, sec_comp_status);
    _mav_put_uint16_t(buf, 42, comp_interface_health2);
    _mav_put_uint8_t(buf, 44, vcu_status);
    _mav_put_uint8_t(buf, 45, comp_mode2);
    _mav_put_uint8_t(buf, 46, sensor_subsystem_health_2);
    _mav_put_uint8_t(buf, 47, vcu_power_subsystem_state2);
    _mav_put_uint8_t(buf, 48, validity_motor_faults);
    _mav_put_uint8_t(buf, 49, mc_faults_2);
    _mav_put_uint8_t(buf, 50, contactor_fault);
    _mav_put_uint8_t(buf, 51, pdu_fault);
    _mav_put_uint8_t(buf, 52, power_subsystem_faults2);
    _mav_put_uint8_t(buf, 53, comp_interface_health1);
    _mav_put_uint8_t(buf, 54, home_location);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, buf, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#else
    mavlink_ugv_system_info_t *packet = (mavlink_ugv_system_info_t *)msgbuf;
    packet->sensor_subsystem_health_3 = sensor_subsystem_health_3;
    packet->vcu_subsystem_status = vcu_subsystem_status;
    packet->vcu_subsystem_power_state1 = vcu_subsystem_power_state1;
    packet->motor_faults = motor_faults;
    packet->lat = lat;
    packet->lon = lon;
    packet->battery_soc = battery_soc;
    packet->comp_mode1 = comp_mode1;
    packet->sensor_subsystem_health_1 = sensor_subsystem_health_1;
    packet->sensor_subsystem_health_4 = sensor_subsystem_health_4;
    packet->comp_subsystem_status = comp_subsystem_status;
    packet->mc_faults_1 = mc_faults_1;
    packet->power_subsystem_faults1 = power_subsystem_faults1;
    packet->vcu_interface_health = vcu_interface_health;
    packet->sec_comp_status = sec_comp_status;
    packet->comp_interface_health2 = comp_interface_health2;
    packet->vcu_status = vcu_status;
    packet->comp_mode2 = comp_mode2;
    packet->sensor_subsystem_health_2 = sensor_subsystem_health_2;
    packet->vcu_power_subsystem_state2 = vcu_power_subsystem_state2;
    packet->validity_motor_faults = validity_motor_faults;
    packet->mc_faults_2 = mc_faults_2;
    packet->contactor_fault = contactor_fault;
    packet->pdu_fault = pdu_fault;
    packet->power_subsystem_faults2 = power_subsystem_faults2;
    packet->comp_interface_health1 = comp_interface_health1;
    packet->home_location = home_location;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UGV_SYSTEM_INFO, (const char *)packet, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_MIN_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE UGV_SYSTEM_INFO UNPACKING


/**
 * @brief Get field vcu_status from ugv_system_info message
 *
 * @return  Byte 10 (Bits 0-1): VCU operational state. Range 0-3. 0: reserved, 1: Idle, 2: Key On, 3: Drive. Byte 10 (Bits 2-3): Charger connected state. Range 0-3. 0: Not connected, 1: connected, 2-3: Reserved. Byte 10 (Bits 4-5): Charging in progress state. Range 0-3. 0: Not charging, 1: Charging, 2-3: Reserved. Byte 10 (Bits 6-7): Tow state. Range 0-3. 0: Disengaged, 1: Engaged, 2-3: Reserved.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_vcu_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field battery_soc from ugv_system_info message
 *
 * @return  Byte 11: LV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid. Byte 12: HV battery SoC. Range 0-255. 0-100: valid percentage, 101-255: Invalid.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_battery_soc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field comp_mode1 from ugv_system_info message
 *
 * @return  Byte 13 (Bits 0-3): Autonomy Mode. Range 0-15. 1: Mode A, 2: Mode B, 3: Mode C, 4: Mode D, 5: Mode E, 0 and 6-15: reserved. Byte 13 (Bits 4-5): Hold State. Range 0-3. 1: Disengaged, 2: Engaged, 0 and 3: Reserved. Byte 13 (Bits 6-7): Arm mode. Range 0-3. 1: Disarmed, 2: Armed, 3: Override, 0: Reserved. Byte 14 (Bits 0-3): Drive mode limit. Range 0-15. 1: Low, 2: Medium, 3: High, 0 and 4-15: reserved. Byte 14 (Bits 4-7): Drive Mode. Range 0-15. 1: Speed mode, 2: Torque mode, 3: Torque with speed limit, 0 and 4-15: reserved.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_comp_mode1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field comp_mode2 from ugv_system_info message
 *
 * @return  Byte 15 (Bits 0-1): On Vehicle emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 2-3): Remote emergency stop. Range 0-3. 1: Disengaged, 2: Engaged, 3: Disabled, 0: Reserved. Byte 15 (Bits 4-6): Selected camera stream. Range 0-7. 0: Reserved, 1: Forward single camera, 2: Port Camera, 3: Starboard camera, 4: Aft camera, 5: Day/Night camera, 6: Forward Composite camera, 7: Invalid. Byte 15 (Bit 7): Selected camera range marker on/off status. Range 0-1. 0: Range marker off, 1: Range marker on.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_comp_mode2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Get field sensor_subsystem_health_1 from ugv_system_info message
 *
 * @return  Byte 16 (Bit 0): UHF Radio Fault UART communication fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 1): UHF Radio fault Firmware fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 2): UHF Radio Fault Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 3): UHF Radio fault Temperature fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 4): UHF Link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 5): UHF Link connection Remote RSSI fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 6): UHF Link Health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 16 (Bit 7): UHF Link Health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 0): UHF Link Health Local noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 1): UHF Link Health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 2): UHF Link Health SNR Fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 3): UHF Link Health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 17 (Bit 4): UHF Link Health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 17 (Bits 5-7): Reserved for future use.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_sensor_subsystem_health_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field sensor_subsystem_health_2 from ugv_system_info message
 *
 * @return  Byte 18 (Bits 0-1): UHF Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 18 (Bits 2-3): UHF Link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 18 (Bits 4-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_sensor_subsystem_health_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  46);
}

/**
 * @brief Get field sensor_subsystem_health_3 from ugv_system_info message
 *
 * @return  Byte 19 (Bit 0): L band radio UGV Ethernet Communication fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 1): L band radio UGV Firmware fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 2): L band radio UGV Local RSSI/Noise fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 3): L band radio UGV Temperature fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 4): L band link connection Heartbeat fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 5): L band link connection Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 6): L band link health Local RSSI Fault. 0: Fault not present, 1: Fault present. Byte 19 (Bit 7): L band link health Remote RSSI Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 0): L band link health Local noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 1): L band link health Remote noise fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 2): L band link health SNR Fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 3): L band link health Packet loss fault. 0: Fault not present, 1: Fault present. Byte 20 (Bit 4): L band link health Heartbeat timeout fault. 0: Fault not present, 1: Fault present. Byte 20 (Bits 5-6): L band Link connection. Range 0-3. 0: Unknown, 1: Connected, 2: Disconnected, 3: Reserved. Byte 20 (Bit 7): Reserved for future use. Byte 21 (Bits 0-1): L band link health. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 21 (Bit 2): Ethernet switch GNSS Ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 3): Ethernet switch L Band radio ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 4): Ethernet switch 2D Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 5): Ethernet switch 3d Lidar ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 6): Ethernet switch secondary compute ping fault. 0: Fault not present, 1: Fault present. Byte 21 (Bit 7): GNSS Position validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 0): GNSS Fix quality fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 1): GNSS Fix dimension fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 2): GNSS Satellite fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 3): GNSS HDOP Fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 4): GNSS Heading validity error fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 5): IMU Communication fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 6): IMU Data integrity fault. 0: Fault not present, 1: Fault present. Byte 22 (Bit 7): 2D Lidar Communication fault. 0: Fault not present, 1: Fault present.
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_sensor_subsystem_health_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sensor_subsystem_health_4 from ugv_system_info message
 *
 * @return  Byte 23 (Bit 0): 2D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 23 (Bit 1): 3D Lidar Communication fault. 0: Fault not present, 1: Fault present. Byte 23 (Bits 2-3): Forward-single camera Fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 4-5): Forward-composite Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 23 (Bits 6-7): Port Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 0-1): Starboard Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 2-3): Rear Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bits 4-5): Forward day/night Camera fault. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 24 (Bit 6): 3D Lidar Data integrity fault. 0: Fault not present, 1: Fault present. Byte 24 (Bit 7): Reserved for future use.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_sensor_subsystem_health_4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field vcu_subsystem_status from ugv_system_info message
 *
 * @return  Byte 25 (Bits 0-1): Aft Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 2-3): Forward Motor controller state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 4-5): HV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 25 (Bits 6-7): LV Battery state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 0-1): LV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 2-3): DC DC (48V to 12V) state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 4-5): HV PDU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 26 (Bits 6-7): Forward left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 0-1): Aft left motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 2-3): Forward right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 4-5): Aft right motor state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 27 (Bits 6-7): Main Compute state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 0-1): LV Battery Charger State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 2-3): VCU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 28 (Bits 4-7): Reserved for future use.
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_vcu_subsystem_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field comp_subsystem_status from ugv_system_info message
 *
 * @return  Byte 29 (Bits 0-1): UHF Radio - UGV State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 29 (Bits 2-3): LBAND radio state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 4-5): Ethernet switch state. Range 0-3. 0: Unknown, 1: False, 2: True, 3: Reserved. Byte 29 (Bits 6-7): GNSS state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 0-1): IMU state. Range 0-3. 0: Unknown, 1: Healthy, 2: Degraded, 3: Faulty. Byte 30 (Bits 2-3): 2D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 4-5): 3D lidar state. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 30 (Bits 6-7): Reserved for future use.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_comp_subsystem_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field vcu_subsystem_power_state1 from ugv_system_info message
 *
 * @return  Byte 31 (Bits 0-1): Forward motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 2-3): Aft motor controller power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 4-5): DC DC (48 V to 12 V) power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 31 (Bits 6-7): HV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 0-1): LV PDU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 2-3): UHF radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 4-5): LBAND radio power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 32 (Bits 6-7): Ethernet switch power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 0-1): GNSS power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 2-3): IMU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 4-5): 2D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 33 (Bits 6-7): 3D Lidar power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 0-1): VCU power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 2-3): Main compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 4-5): Secondary compute power state. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 34 (Bits 6-7): RGBD Camera Power State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved.
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_vcu_subsystem_power_state1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field vcu_power_subsystem_state2 from ugv_system_info message
 *
 * @return  Byte 35 (Bits 0-1): Head lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 2-3): Aft lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 4-5): Fog lights State. Range 0-3. 0: Unknown, 1: ON, 2: OFF, 3: Reserved. Byte 35 (Bits 6-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_vcu_power_subsystem_state2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  47);
}

/**
 * @brief Get field motor_faults from ugv_system_info message
 *
 * @return  Byte 36 (Bit 0): Aft motor controller Aft Port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 36 (Bit 1): Aft motor controller Aft Port Motor overload. 0: Fault not present, 1: Fault present. Byte 36 (Bit 2): Aft motor controller Aft Port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 36 (Bit 3): Aft motor controller Aft Port Motor brake. 0: Fault not present, 1: Fault present. Byte 36 (Bit 4): Aft motor controller Aft Port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 5): Aft motor controller Aft Port Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 36 (Bit 6): Aft motor controller Aft Port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 36 (Bit 7): Aft motor controller Aft Port Motor stalled. 0: Fault not present, 1: Fault present. Byte 37 (Bit 0): Aft motor controller Aft starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 37 (Bit 1): Aft motor controller Aft starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 37 (Bit 2): Aft motor controller Aft starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 37 (Bit 3): Aft motor controller Aft starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 37 (Bit 4): Aft motor controller Aft starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 5): Aft motor controller Aft starboard Motor overtemperature. 0: Fault not present, 1: Fault present. Byte 37 (Bit 6): Aft motor controller Aft starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 37 (Bit 7): Aft motor controller Aft starboard Motor stalled. 0: Fault not present, 1: Fault present. Byte 38 (Bit 0): Forward motor controller Forward port Motor overspeed. 0: Fault not present, 1: Fault present. Byte 38 (Bit 1): Forward motor controller Forward port Motor overload. 0: Fault not present, 1: Fault present. Byte 38 (Bit 2): Forward motor controller Forward port Motor phase loss. 0: Fault not present, 1: Fault present. Byte 38 (Bit 3): Forward motor controller Forward port Motor brake. 0: Fault not present, 1: Fault present. Byte 38 (Bit 4): Forward motor controller Forward port Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 5): Forward motor controller Forward port Motor over temperature. 0: Fault not present, 1: Fault present. Byte 38 (Bit 6): Forward motor controller Forward port Motor Hall fault. 0: Fault not present, 1: Fault present. Byte 38 (Bit 7): Forward motor controller Forward port Motor stalled. 0: Fault not present, 1: Fault present. Byte 39 (Bit 0): Forward motor controller Forward starboard Motor overspeed. 0: Fault not present, 1: Fault present. Byte 39 (Bit 1): Forward motor controller Forward starboard Motor overload. 0: Fault not present, 1: Fault present. Byte 39 (Bit 2): Forward motor controller Forward starboard Motor phase loss. 0: Fault not present, 1: Fault present. Byte 39 (Bit 3): Forward motor controller Forward starboard Motor brake. 0: Fault not present, 1: Fault present. Byte 39 (Bit 4): Forward motor controller Forward starboard Motor encoder fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 5): Forward motor controller Forward starboard Motor over temperature. 0: Fault not present, 1: Fault present. Byte 39 (Bit 6): Forward motor controller Forward starboard Motor hall fault. 0: Fault not present, 1: Fault present. Byte 39 (Bit 7): Forward motor controller Forward starboard Motor stalled. 0: Fault not present, 1: Fault present.
 */
static inline uint32_t mavlink_msg_ugv_system_info_get_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field validity_motor_faults from ugv_system_info message
 *
 * @return  Byte 40 (Bit 0): Validity of the data of Aft motor. 0: Valid, 1: Invalid. Byte 40 (Bit 1): Validity of the data of Forward motor. 0: Valid, 1: Invalid. Byte 40 (Bits 2-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_validity_motor_faults(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field mc_faults_1 from ugv_system_info message
 *
 * @return  Byte 41 (Bit 0): Aft motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 1): Aft motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 41 (Bit 2): Aft motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 3): Aft motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 4): Aft motor controller UART Communication failure. 0: Fault not present, 1: Fault present. Byte 41 (Bit 5): Aft motor controller DC Bus voltage. 0: Fault not present, 1: Fault present. Byte 41 (Bit 6): Aft motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 41 (Bit 7): Aft motor controller CAN communication fault. 0: Fault not present, 1: Fault present. Byte 42 (Bit 0): Forward motor controller Drive failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 1): Forward motor controller Overcurrent. 0: Fault not present, 1: Fault present. Byte 42 (Bit 2): Forward motor controller Overvoltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 3): Forward motor controller Under voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 4): Forward motor controller UART communication failure. 0: Fault not present, 1: Fault present. Byte 42 (Bit 5): Forward motor controller DC bus voltage. 0: Fault not present, 1: Fault present. Byte 42 (Bit 6): Forward motor controller Over temperature. 0: Fault not present, 1: Fault present. Byte 42 (Bit 7): Forward motor controller CAN communication loss. 0: Fault not present, 1: Fault present.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_mc_faults_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field mc_faults_2 from ugv_system_info message
 *
 * @return  Byte 43 (Bit 0): Validity of the data of Aft motor controller. 0: Valid, 1: Invalid. Byte 43 (Bit 1): Validity of the data of Forward motor controller. 0: Valid, 1: Invalid. Byte 43 (Bits 2-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_mc_faults_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field contactor_fault from ugv_system_info message
 *
 * @return  Byte 44 (Bit 0): Pre-charge Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 1): Motor controller contactor fault. 0: No, 1: Yes. Byte 44 (Bit 2): I/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bit 3): HV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 4): LV Charging contactor fault. 0: No, 1: Yes. Byte 44 (Bit 5): O/P DC-DC Contactor fault. 0: No, 1: Yes. Byte 44 (Bits 6-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_contactor_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  50);
}

/**
 * @brief Get field pdu_fault from ugv_system_info message
 *
 * @return  Byte 45 (Bit 0): Channel 1 Fault state. 0: No, 1: Fault. Byte 45 (Bit 1): Channel 2 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 2): Channel 3 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 3): Channel 4 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 4): Channel 5 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 5): Channel 6 Fault State. 0: No Fault, 1: Fault. Byte 45 (Bit 6): Channel 7 Fault state. 0: No fault, 1: Fault. Byte 45 (Bit 7): Channel 8 Fault state. 0: No Fault, 1: Fault.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_pdu_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  51);
}

/**
 * @brief Get field power_subsystem_faults1 from ugv_system_info message
 *
 * @return  Byte 46 (Bit 0): HV battery Single cell overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 1): HV battery Single cell undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 2): HV battery Pack overvoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 3): HV battery Pack undervoltage. 0: Fault not present, 1: Fault present. Byte 46 (Bit 4): HV battery Charge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 5): HV battery Charge low temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 6): HV battery Discharge over temperature. 0: Fault not present, 1: Fault present. Byte 46 (Bit 7): HV battery Discharge low temperature. 0: Fault not present, 1: Fault present. Byte 47 (Bit 0): HV battery Charge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 1): HV battery Discharge overcurrent. 0: Fault not present, 1: Fault present. Byte 47 (Bit 2): HV battery Short circuit protection. 0: Fault not present, 1: Fault present. Byte 47 (Bit 3): HV battery Forward detection IC error. 0: Fault not present, 1: Fault present. Byte 47 (Bit 4): HV battery Software lock MOS. 0: Fault not present, 1: Fault present. Byte 47 (Bit 5): HV Battery Cycle life fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 6): HV Battery Capacity fault. 0: Fault not present, 1: Fault Present. Byte 47 (Bit 7): LV Battery Battery deeply discharged. 0: Fault not present, 1: Fault Present.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_power_subsystem_faults1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field power_subsystem_faults2 from ugv_system_info message
 *
 * @return  Byte 48 (Bit 0): LV Battery Under voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 1): LV Battery Over Voltage. 0: Fault not present, 1: Fault Present. Byte 48 (Bit 2): LV Battery Load fault. 0: Fault not present, 1: Fault Present. Byte 48 (Bits 3-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_power_subsystem_faults2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field vcu_interface_health from ugv_system_info message
 *
 * @return  Byte 49 (Bit 0): CAN C Bus off. 0: No, 1: Yes. Byte 49 (Bit 1): CAN A Bus off. 0: No, 1: Yes. Byte 49 (Bit 2): CAN B Bus off. 0: No, 1: Yes. Byte 49 (Bit 3): Status of the Discete inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 4): Status of the Analog inputs fault. 0: No fault, 1: Fault. Byte 49 (Bit 5): Status of the High side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 6): Status of the Low side output drivers fault. 0: No fault, 1: Fault. Byte 49 (Bit 7): Supply voltage fault. 0: No fault, 1: Fault. Byte 50 (Bit 0): MCU watchdog fault. 0: No Fault, 1: Fault. Byte 50 (Bit 1): CPU Overload. 0: No, 1: Yes. Byte 50 (Bit 2): RAM fault. 0: No fault, 1: Fault. Byte 50 (Bit 3): Flash CRC Failure. 0: No Fault, 1: Fault. Byte 50 (Bit 4): FCC Active. 0: Active, 1: Inactive. Byte 50 (Bit 5): Safety SBC Fault. 0: No fault, 1: Fault. Byte 50 (Bit 6): Internal Temperature fault. 0: No fault, 1: Fault. Byte 50 (Bit 7): Boot Failure. 0: No fault, 1: Fault.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_vcu_interface_health(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field sec_comp_status from ugv_system_info message
 *
 * @return  Byte 51 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 2): Status of the Actuator CAN interface. 0: Inactive, 1: Active. Byte 51 (Bit 3): Status of the Forward motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 4): Status of the Aft motor controller serial interface. 0: Inactive, 1: Active. Byte 51 (Bit 5): Status of the ethernet interface. 0: Inactive, 1: Active. Byte 51 (Bit 6): CPU load fault. 0: No fault, 1: Fault. Byte 51 (Bit 7): Memory fault. 0: No fault, 1: Fault. Byte 52 (Bit 0): Storage fault. 0: No fault, 1: Fault. Byte 52 (Bits 1-2): Secondary compute State. Range 0-3. 0: Unknown, 1: Healthy, 2: Faulty, 3: Reserved. Byte 52 (Bits 3-7): Reserved for future use.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_sec_comp_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field comp_interface_health1 from ugv_system_info message
 *
 * @return  Byte 53 (Bit 0): Jetson Heartbeat. 0: Fault not present, 1: Fault present. Byte 53 (Bit 1): Temperature fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 2): Voltage Fault. 0: Fault not present, 1: Fault present. Byte 53 (Bit 3): CPU load fault. 0: Fault not present, 1: Fault present. Byte 53 (Bits 4-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_comp_interface_health1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  53);
}

/**
 * @brief Get field comp_interface_health2 from ugv_system_info message
 *
 * @return  Byte 54 (Bit 0): Status of the Control CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 1): Status of the Auxiliary CAN interface. 0: Inactive, 1: Active. Byte 54 (Bit 2): Status of the Ethernet interface. 0: Inactive, 1: Active. Byte 54 (Bit 3): Status of Hand Controller Serial interface. 0: Inactive, 1: Active. Byte 54 (Bit 4): Vision Ethernet interface health. 0: Inactive, 1: Active. Byte 54 (Bit 5): Vision GMSL-1 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 6): Vision GMSL-2 interface health. 0: Inactive, 1: Active. Byte 54 (Bit 7): Vision GMSL-3 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 0): Vision GMSL-4 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 1): Vision GMSL-5 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 2): Vision GMSL-6 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 3): Vision GMSL-7 interface health. 0: Inactive, 1: Active. Byte 55 (Bit 4): Vision GMSL-8 interface health. 0: Inactive, 1: Active. Byte 55 (Bits 5-7): Reserved for future use.
 */
static inline uint16_t mavlink_msg_ugv_system_info_get_comp_interface_health2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field home_location from ugv_system_info message
 *
 * @return  Byte 56 (Bit 0): Home location status. 0: Not set, 1: Set. Byte 56 (Bit 1): Path saving status. 0: OFF, 1: ON. Byte 56 (Bits 2-7): Reserved for future use.
 */
static inline uint8_t mavlink_msg_ugv_system_info_get_home_location(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  54);
}

/**
 * @brief Get field lat from ugv_system_info message
 *
 * @return  Bytes 57-60. Range -900000000 to 900000000. If Byte 56 (Bit 0) is set to 1, then lat value is valid. Scale = 1e-7.
 */
static inline int32_t mavlink_msg_ugv_system_info_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field lon from ugv_system_info message
 *
 * @return  Bytes 61-64. Range -1800000000 to 1800000000. If Byte 56 (Bit 0) is set to 1, then long value is valid. Scale = 1e-7.
 */
static inline int32_t mavlink_msg_ugv_system_info_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Decode a ugv_system_info message into a struct
 *
 * @param msg The message to decode
 * @param ugv_system_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_ugv_system_info_decode(const mavlink_message_t* msg, mavlink_ugv_system_info_t* ugv_system_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ugv_system_info->sensor_subsystem_health_3 = mavlink_msg_ugv_system_info_get_sensor_subsystem_health_3(msg);
    ugv_system_info->vcu_subsystem_status = mavlink_msg_ugv_system_info_get_vcu_subsystem_status(msg);
    ugv_system_info->vcu_subsystem_power_state1 = mavlink_msg_ugv_system_info_get_vcu_subsystem_power_state1(msg);
    ugv_system_info->motor_faults = mavlink_msg_ugv_system_info_get_motor_faults(msg);
    ugv_system_info->lat = mavlink_msg_ugv_system_info_get_lat(msg);
    ugv_system_info->lon = mavlink_msg_ugv_system_info_get_lon(msg);
    ugv_system_info->battery_soc = mavlink_msg_ugv_system_info_get_battery_soc(msg);
    ugv_system_info->comp_mode1 = mavlink_msg_ugv_system_info_get_comp_mode1(msg);
    ugv_system_info->sensor_subsystem_health_1 = mavlink_msg_ugv_system_info_get_sensor_subsystem_health_1(msg);
    ugv_system_info->sensor_subsystem_health_4 = mavlink_msg_ugv_system_info_get_sensor_subsystem_health_4(msg);
    ugv_system_info->comp_subsystem_status = mavlink_msg_ugv_system_info_get_comp_subsystem_status(msg);
    ugv_system_info->mc_faults_1 = mavlink_msg_ugv_system_info_get_mc_faults_1(msg);
    ugv_system_info->power_subsystem_faults1 = mavlink_msg_ugv_system_info_get_power_subsystem_faults1(msg);
    ugv_system_info->vcu_interface_health = mavlink_msg_ugv_system_info_get_vcu_interface_health(msg);
    ugv_system_info->sec_comp_status = mavlink_msg_ugv_system_info_get_sec_comp_status(msg);
    ugv_system_info->comp_interface_health2 = mavlink_msg_ugv_system_info_get_comp_interface_health2(msg);
    ugv_system_info->vcu_status = mavlink_msg_ugv_system_info_get_vcu_status(msg);
    ugv_system_info->comp_mode2 = mavlink_msg_ugv_system_info_get_comp_mode2(msg);
    ugv_system_info->sensor_subsystem_health_2 = mavlink_msg_ugv_system_info_get_sensor_subsystem_health_2(msg);
    ugv_system_info->vcu_power_subsystem_state2 = mavlink_msg_ugv_system_info_get_vcu_power_subsystem_state2(msg);
    ugv_system_info->validity_motor_faults = mavlink_msg_ugv_system_info_get_validity_motor_faults(msg);
    ugv_system_info->mc_faults_2 = mavlink_msg_ugv_system_info_get_mc_faults_2(msg);
    ugv_system_info->contactor_fault = mavlink_msg_ugv_system_info_get_contactor_fault(msg);
    ugv_system_info->pdu_fault = mavlink_msg_ugv_system_info_get_pdu_fault(msg);
    ugv_system_info->power_subsystem_faults2 = mavlink_msg_ugv_system_info_get_power_subsystem_faults2(msg);
    ugv_system_info->comp_interface_health1 = mavlink_msg_ugv_system_info_get_comp_interface_health1(msg);
    ugv_system_info->home_location = mavlink_msg_ugv_system_info_get_home_location(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN? msg->len : MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN;
        memset(ugv_system_info, 0, MAVLINK_MSG_ID_UGV_SYSTEM_INFO_LEN);
    memcpy(ugv_system_info, _MAV_PAYLOAD(msg), len);
#endif
}
