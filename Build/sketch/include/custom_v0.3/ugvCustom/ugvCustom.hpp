#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/custom_v0.3/ugvCustom/ugvCustom.hpp"
/** @file
 *  @brief MAVLink comm protocol generated from ugvCustom.xml
 *  @see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace ugvCustom {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 11> MESSAGE_ENTRIES {{ {0, 50, 9, 9, 0, 0, 0}, {1, 3, 5, 5, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {69, 96, 11, 28, 1, 10, 0}, {76, 152, 33, 33, 3, 30, 31}, {77, 143, 3, 10, 3, 8, 9}, {109, 185, 9, 9, 0, 0, 0}, {111, 34, 16, 18, 3, 16, 17}, {50001, 128, 37, 37, 0, 0, 0}, {50002, 161, 38, 38, 3, 36, 37}, {50003, 50, 181, 181, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS


/** @brief MAVLINK component type reported in HEARTBEAT message. Flight controllers must report the type of the vehicle on which they are mounted (e.g. MAV_TYPE_OCTOROTOR). All other components must report a value appropriate for their type (e.g. a camera must use MAV_TYPE_CAMERA). */
enum class MAV_TYPE : uint8_t
{
    GENERIC=0, /* Generic micro air vehicle | */
    ONBOARD_CONTROLLER=18, /* Onboard companion controller | */
};

//! MAV_TYPE ENUM_END
constexpr auto MAV_TYPE_ENUM_END = 19;

/** @brief Micro air vehicle / autopilot classes. This identifies the individual model. */
enum class MAV_AUTOPILOT : uint8_t
{
    GENERIC=0, /* Generic autopilot, full support for everything | */
    INVALID=8, /* No valid autopilot, e.g. a GCS or other MAVLink component | */
};

//! MAV_AUTOPILOT ENUM_END
constexpr auto MAV_AUTOPILOT_ENUM_END = 9;

/** @brief  */
enum class MAV_STATE : uint8_t
{
    UNINIT=0, /* Uninitialized system, state is unknown. | */
    STANDBY=3, /* System is grounded and on standby. It can be launched any time. | */
    ACTIVE=4, /* System is active and might be already airborne. Motors are engaged. | */
};

//! MAV_STATE ENUM_END
constexpr auto MAV_STATE_ENUM_END = 5;

/** @brief Commands to be executed by the MAV. They can be executed on user request, or as part of a mission script. If the action is used in a mission, the parameter mapping to the waypoint/mission message is as follows: Param 1, Param 2, Param 3, Param 4, X: Param 5, Y:Param 6, Z:Param 7. This command list is similar what ARINC 424 is for commercial aircraft: A data format how to interpret waypoint/mission data. NaN and INT32_MAX may be used in float/integer params (respectively) to indicate optional/default values (e.g. to use the component's current yaw or latitude rather than a specific value). See https://mavlink.io/en/guide/xml_schema.html#MAV_CMD for information about the structure of the MAV_CMD entries */
enum class MAV_CMD : uint16_t
{
    DO_SET_MODE=176, /* Set system mode. |Mode flags. MAV_MODE values can be used to set some mode flag combinations.| Main mode selection for UGV| Sub mode selection for UGV| Speed sub mode selection| Empty| Empty| Empty|  */
    COMPONENT_ARM_DISARM=400, /* Arms / Disarms a component |Arm (MAV_BOOL_FALSE: disarm). Values not equal to 0 or 1 are invalid.| 0: arm-disarm unless prevented by safety checks (i.e. when landed), 21196: force arming/disarming (e.g. allow arming to override preflight checks and disarming in flight)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
    REQUEST_MESSAGE=512, /* Request the target system(s) emit a single instance of a specified message (i.e. a "one-shot" version of MAV_CMD_SET_MESSAGE_INTERVAL). |The MAVLink message ID of the requested message.| Use for index ID, if required. Otherwise, the use of this parameter (if any) must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| Target address for requested message (if message has target address fields). 0: Flight-stack default, 1: address of requester, 2: broadcast.|  */
    DRIVE_MODE=31900, /* Command to change drive mode of UGV |Drive mode request.| Empty| Empty| Empty| Empty| Empty| Empty|  */
    LIGHT_CONTROL=31901, /* Command to change light state of UGV |ON (MAV_BOOL_FALSE: OFF).| ON (MAV_BOOL_FALSE: OFF).| ON (MAV_BOOL_FALSE: OFF).| Empty| Empty| Empty| Empty|  */
};

//! MAV_CMD ENUM_END
constexpr auto MAV_CMD_ENUM_END = 31902;

/** @brief Result from a MAVLink command (MAV_CMD) */
enum class MAV_RESULT : uint8_t
{
    ACCEPTED=0, /* Command is valid (is supported and has valid parameters), and was executed. | */
    TEMPORARILY_REJECTED=1, /* Command is valid, but cannot be executed at this time. This is used to indicate a problem that should be fixed just by waiting (e.g. a state machine is busy, can't arm because have not got GPS lock, etc.). Retrying later should work. | */
    DENIED=2, /* Command is invalid; it is supported but one or more parameter values are invalid (i.e. parameter reserved, value allowed by spec but not supported by flight stack, and so on). Retrying the same command and parameters will not work. | */
    UNSUPPORTED=3, /* Command is not supported (unknown). | */
    FAILED=4, /* Command is valid, but execution has failed. This is used to indicate any non-temporary or unexpected problem, i.e. any problem that must be fixed before the command can succeed/be retried. For example, attempting to write a file when out of memory, attempting to arm when sensors are not calibrated, etc. | */
    IN_PROGRESS=5, /* Command is valid and is being executed. This will be followed by further progress updates, i.e. the component may send further COMMAND_ACK messages with result MAV_RESULT_IN_PROGRESS (at a rate decided by the implementation), and must terminate by sending a COMMAND_ACK message with final result of the operation. The COMMAND_ACK.progress field can be used to indicate the progress of the operation. | */
    CANCELLED=6, /* Command has been cancelled (as a result of receiving a COMMAND_CANCEL message). | */
    COMMAND_LONG_ONLY=7, /* Command is only accepted when sent as a COMMAND_LONG. | */
    COMMAND_INT_ONLY=8, /* Command is only accepted when sent as a COMMAND_INT. | */
    COMMAND_UNSUPPORTED_MAV_FRAME=9, /* Command is invalid because a frame is required and the specified frame is not supported. | */
    NOT_IN_CONTROL=10, /* Command has been rejected because source system is not in control of the target system/component. | */
};

//! MAV_RESULT ENUM_END
constexpr auto MAV_RESULT_ENUM_END = 11;

/** @brief Enum used to indicate true or false (also: success or failure, enabled or disabled, active or inactive). */
enum class MAV_BOOL : uint8_t
{
    FALSE_=0, /* False. | */
    TRUE_=1, /* True. | */
};

//! MAV_BOOL ENUM_END
constexpr auto MAV_BOOL_ENUM_END = 2;

/** @brief Used to indicate the current state of the extra feature buttons */
enum class PUSH_BUTTONS : uint16_t
{
    EXTRA_FEATURE_1_PRESS=1, /*  a single short press of extra feature 1 button.  | */
    EXTRA_FEATURE_1_LONG_PRESS=2, /*  a long press of extra feature 1 button.  | */
    EXTRA_FEATURE_2_PRESS=4, /*  a single short press of extra feature 2 button.  | */
    EXTRA_FEATURE_2_LONG_PRESS=8, /*  a long press of extra feature 2 button.  | */
};

//! PUSH_BUTTONS ENUM_END
constexpr auto PUSH_BUTTONS_ENUM_END = 9;

/** @brief Used to indicate the position of the tristate toggle switches. */
enum class TOGGLE_SWITCH_POS
{
    FORWARD_DIRECTION=1, /* 0x01 Forward Direction | */
    REVERSE_DIRECTION=2, /* 0x02 Reverse Direction | */
    MEDIUM_SPEED=4, /* 0x04 Medium Speed | */
    HIGH_SPEED=8, /* 0x08 High Speed | */
};

//! TOGGLE_SWITCH_POS ENUM_END
constexpr auto TOGGLE_SWITCH_POS_ENUM_END = 9;

/** @brief These flags encode the MAV mode, see MAV_MODE enum for useful combinations. */
enum class MAV_MODE_FLAG : uint8_t
{
    CUSTOM_MODE_ENABLED=1, /* 0b00000001 system-specific custom mode is enabled. When using this flag to enable a custom mode all other flags should be ignored. | */
    TEST_ENABLED=2, /* 0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations. | */
    AUTO_ENABLED=4, /* 0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation. | */
    GUIDED_ENABLED=8, /* 0b00001000 guided mode enabled, system flies waypoints / mission items. | */
    STABILIZE_ENABLED=16, /* 0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around. | */
    HIL_ENABLED=32, /* 0b00100000 hardware in the loop simulation. All motors / actuators are blocked, but internal software is full operational. | */
    MANUAL_INPUT_ENABLED=64, /* 0b01000000 remote control input is enabled. | */
    SAFETY_ARMED=128, /* 0b10000000 MAV safety set to armed. Motors are enabled / running / can start. Ready to fly. Additional note: this flag is to be ignore when sent in the command MAV_CMD_DO_SET_MODE and MAV_CMD_COMPONENT_ARM_DISARM shall be used instead. The flag can still be used to report the armed state. | */
};

//! MAV_MODE_FLAG ENUM_END
constexpr auto MAV_MODE_FLAG_ENUM_END = 129;

/** @brief These encode the sub systems whose status is sent as part of the UGV_MASTER_HEALTH message. */
enum class UGV_COMP_BITMASK
{
    COMP_COMPUTE=1, /* 0x01 Atlas Compute | */
    VCU=2, /* 0x02 Vehicle Control Unit (VCU) | */
    LEFT_MOTOR=4, /* 0x04 Motor Controller (left) | */
    RIGHT_MOTOR=8, /* 0x08 Motor Controller (right) | */
    BMS=16, /* 0x10 Battery Management System (BMS) | */
    PDU=32, /* 0x20 Power Distribution Unit (PDU) | */
    UHF_RADIO=64, /* 0x40 UHF radio | */
    DISPLAY=128, /* 0x80 Display | */
    HAND_CTRL=256, /* 0x100 Hand controller | */
    GCS=512, /* 0x200 Ground Control Station (GCS) | */
};

//! UGV_COMP_BITMASK ENUM_END
constexpr auto UGV_COMP_BITMASK_ENUM_END = 513;

/** @brief Enum used to indicate the errors present in Motors */
enum class UGV_MOTOR_ERROR : uint8_t
{
    OVER_SPEED=1, /* 0x01 Motor Over Speed | */
    OVERLOAD=2, /* 0x02 Motor Overload | */
    PHASE_LOSS=4, /* 0x04 Motor Phase Loss | */
    BRAKE_FAULT=8, /* 0x08 Motor Brake Fault | */
    ENCODER_FAULT=16, /* 0x10 Motor Encoder Fault | */
    OVER_TEMPERATURE=32, /* 0x20 Motor Over Temperature | */
    HALL_FAULT=64, /* 0x40 Motor Hall Fault | */
    STALLED=128, /* 0x80 Motor Stalled Fault | */
};

//! UGV_MOTOR_ERROR ENUM_END
constexpr auto UGV_MOTOR_ERROR_ENUM_END = 129;

/** @brief Enum used to indicate the errors present in Motor Controller */
enum class UGV_MOTOR_CTRL_ERROR : uint8_t
{
    DRIVE=1, /* 0x01 Drive Fault | */
    OVER_CURRENT=2, /* 0x02 Over Current | */
    OVER_PRESSURE=4, /* 0x04 Over Pressure | */
    UNDER_VOLTAGE=8, /* 0x08 Under Voltage | */
    OVER_TEMPERATURE=16, /* 0x10 Over Temperature | */
    CAN_COMM=32, /* 0x20 CAN Communication Fault | */
};

//! UGV_MOTOR_CTRL_ERROR ENUM_END
constexpr auto UGV_MOTOR_CTRL_ERROR_ENUM_END = 33;

/** @brief Operator mode in which the UGV operates in. Mode A signifies hand controller, Mode B signifies GCS */
enum class UGV_MAIN_MODE : uint8_t
{
    MODE_A=1, /* Mode A, hand controller | */
    MODE_B=2, /* Mode B, GCS | */
};

//! UGV_MAIN_MODE ENUM_END
constexpr auto UGV_MAIN_MODE_ENUM_END = 3;

/** @brief Operator submode in which the UGV operates in. */
enum class UGV_SUB_MODE : uint8_t
{
    NONE=0, /* no active submode | */
    HOLD=10, /* Hold submode, used when UGV is temporarily in halt. | */
};

//! UGV_SUB_MODE ENUM_END
constexpr auto UGV_SUB_MODE_ENUM_END = 11;

/** @brief Operator speed mode in which the UGV operates in. */
enum class UGV_SPEED_MODE : uint8_t
{
    LOW=1, /* low speed mode | */
    MEDIUM=2, /* medium speed mode | */
    HIGH=3, /* high speed mode | */
};

//! UGV_SPEED_MODE ENUM_END
constexpr auto UGV_SPEED_MODE_ENUM_END = 4;

/** @brief Operator drive mode in which the UGV operates in. */
enum class UGV_DRIVE_MODE : uint8_t
{
    SPEED=1, /* speed mode | */
    TORQUE=2, /* torque mode | */
    TORQUE_WITH_SPEED_LIMIT=3, /* torque with speed limit mode | */
    POSITION=4, /* position mode | */
};

//! UGV_DRIVE_MODE ENUM_END
constexpr auto UGV_DRIVE_MODE_ENUM_END = 5;

/** @brief Reason for sub-mode change. */
enum class MODE_CHANGE_REASON : uint8_t
{
    GCS_COMMAND=0, /* submode changed due to GCS command | */
    FAILSAFE=1, /* submode changed due to activation of failsafe | */
    SENSOR_FAULT=2, /* submode changed due to sensor fault | */
    COMM_LOSS=3, /* submode change due to loss of communication | */
};

//! MODE_CHANGE_REASON ENUM_END
constexpr auto MODE_CHANGE_REASON_ENUM_END = 4;

/** @brief 
            Generic subsystem communication and health status.
            Used for motor controllers, batteries, PDUs, and other subsystems.
         */
enum class UGV_HEALTH_STATE : uint8_t
{
    RESERVED_STATE=0, /* Reserved state. | */
    NO_COMMUNICATION_STATE=1, /* No communication with subsystem. | */
    COMMUNICATING_HEALTHY_STATE=2, /* Subsystem communicating and healthy. | */
    FAULT_STATE=3, /* Subsystem communicating but unhealthy. Fault present. | */
};

//! UGV_HEALTH_STATE ENUM_END
constexpr auto UGV_HEALTH_STATE_ENUM_END = 4;


} // namespace ugvCustom
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.hpp"
#include "./mavlink_msg_timesync.hpp"
#include "./mavlink_msg_command_long.hpp"
#include "./mavlink_msg_command_ack.hpp"
#include "./mavlink_msg_manual_control.hpp"
#include "./mavlink_msg_radio_status.hpp"
#include "./mavlink_msg_sys_status.hpp"
#include "./mavlink_msg_system_time.hpp"
#include "./mavlink_msg_ugv_system_info.hpp"
#include "./mavlink_msg_ugv_component_version.hpp"
#include "./mavlink_msg_ugv_subsystem_version.hpp"

// base include

