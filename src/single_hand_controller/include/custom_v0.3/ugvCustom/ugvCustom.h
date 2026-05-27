/** @file
 *  @brief MAVLink comm protocol generated from ugvCustom.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_UGVCUSTOM_H
#define MAVLINK_UGVCUSTOM_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_UGVCUSTOM.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_UGVCUSTOM_XML_HASH 1390003806544637740

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 50, 9, 9, 0, 0, 0}, {1, 3, 5, 5, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {69, 170, 15, 32, 1, 14, 0}, {76, 152, 33, 33, 3, 30, 31}, {77, 143, 3, 10, 3, 8, 9}, {109, 185, 9, 9, 0, 0, 0}, {111, 34, 16, 18, 3, 16, 17}, {50001, 101, 20, 20, 0, 0, 0}, {50002, 161, 38, 38, 3, 36, 37}, {50003, 50, 181, 181, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_UGVCUSTOM

// ENUM DEFINITIONS


/** @brief MAVLINK component type reported in HEARTBEAT message. Flight controllers must report the type of the vehicle on which they are mounted (e.g. MAV_TYPE_OCTOROTOR). All other components must report a value appropriate for their type (e.g. a camera must use MAV_TYPE_CAMERA). */
#ifndef HAVE_ENUM_MAV_TYPE
#define HAVE_ENUM_MAV_TYPE
typedef enum MAV_TYPE
{
   MAV_TYPE_GENERIC=0, /* Generic micro air vehicle | */
   MAV_TYPE_ONBOARD_CONTROLLER=18, /* Onboard companion controller | */
   MAV_TYPE_ENUM_END=19, /*  | */
} MAV_TYPE;
#endif

/** @brief Micro air vehicle / autopilot classes. This identifies the individual model. */
#ifndef HAVE_ENUM_MAV_AUTOPILOT
#define HAVE_ENUM_MAV_AUTOPILOT
typedef enum MAV_AUTOPILOT
{
   MAV_AUTOPILOT_GENERIC=0, /* Generic autopilot, full support for everything | */
   MAV_AUTOPILOT_INVALID=8, /* No valid autopilot, e.g. a GCS or other MAVLink component | */
   MAV_AUTOPILOT_ENUM_END=9, /*  | */
} MAV_AUTOPILOT;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_STATE
#define HAVE_ENUM_MAV_STATE
typedef enum MAV_STATE
{
   MAV_STATE_UNINIT=0, /* Uninitialized system, state is unknown. | */
   MAV_STATE_STANDBY=3, /* System is grounded and on standby. It can be launched any time. | */
   MAV_STATE_ACTIVE=4, /* System is active and might be already airborne. Motors are engaged. | */
   MAV_STATE_ENUM_END=5, /*  | */
} MAV_STATE;
#endif

/** @brief Commands to be executed by the MAV. They can be executed on user request, or as part of a mission script. If the action is used in a mission, the parameter mapping to the waypoint/mission message is as follows: Param 1, Param 2, Param 3, Param 4, X: Param 5, Y:Param 6, Z:Param 7. This command list is similar what ARINC 424 is for commercial aircraft: A data format how to interpret waypoint/mission data. NaN and INT32_MAX may be used in float/integer params (respectively) to indicate optional/default values (e.g. to use the component's current yaw or latitude rather than a specific value). See https://mavlink.io/en/guide/xml_schema.html#MAV_CMD for information about the structure of the MAV_CMD entries */
#ifndef HAVE_ENUM_MAV_CMD
#define HAVE_ENUM_MAV_CMD
typedef enum MAV_CMD
{
   MAV_CMD_DO_SET_MODE=176, /* Set system mode. |Mode flags. MAV_MODE values can be used to set some mode flag combinations.| Custom system-specific mode (see target autopilot specifications for mode information). If MAV_MODE_FLAG_CUSTOM_MODE_ENABLED is set in param1 (mode) this mode is used: otherwise the field is ignored.| Custom sub mode - this is system specific, please refer to the individual autopilot specifications for details.| Empty| Empty| Empty| Empty|  */
   MAV_CMD_COMPONENT_ARM_DISARM=400, /* Arms / Disarms a component |Arm (MAV_BOOL_FALSE: disarm). Values not equal to 0 or 1 are invalid.| 0: arm-disarm unless prevented by safety checks (i.e. when landed), 21196: force arming/disarming (e.g. allow arming to override preflight checks and disarming in flight)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
   MAV_CMD_REQUEST_MESSAGE=512, /* Request the target system(s) emit a single instance of a specified message (i.e. a "one-shot" version of MAV_CMD_SET_MESSAGE_INTERVAL). |The MAVLink message ID of the requested message.| Use for index ID, if required. Otherwise, the use of this parameter (if any) must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| The use of this parameter (if any), must be defined in the requested message. By default assumed not used (0).| Target address for requested message (if message has target address fields). 0: Flight-stack default, 1: address of requester, 2: broadcast.|  */
   MAV_CMD_ENUM_END=513, /*  | */
} MAV_CMD;
#endif

/** @brief Result from a MAVLink command (MAV_CMD) */
#ifndef HAVE_ENUM_MAV_RESULT
#define HAVE_ENUM_MAV_RESULT
typedef enum MAV_RESULT
{
   MAV_RESULT_ACCEPTED=0, /* Command is valid (is supported and has valid parameters), and was executed. | */
   MAV_RESULT_TEMPORARILY_REJECTED=1, /* Command is valid, but cannot be executed at this time. This is used to indicate a problem that should be fixed just by waiting (e.g. a state machine is busy, can't arm because have not got GPS lock, etc.). Retrying later should work. | */
   MAV_RESULT_DENIED=2, /* Command is invalid; it is supported but one or more parameter values are invalid (i.e. parameter reserved, value allowed by spec but not supported by flight stack, and so on). Retrying the same command and parameters will not work. | */
   MAV_RESULT_UNSUPPORTED=3, /* Command is not supported (unknown). | */
   MAV_RESULT_FAILED=4, /* Command is valid, but execution has failed. This is used to indicate any non-temporary or unexpected problem, i.e. any problem that must be fixed before the command can succeed/be retried. For example, attempting to write a file when out of memory, attempting to arm when sensors are not calibrated, etc. | */
   MAV_RESULT_IN_PROGRESS=5, /* Command is valid and is being executed. This will be followed by further progress updates, i.e. the component may send further COMMAND_ACK messages with result MAV_RESULT_IN_PROGRESS (at a rate decided by the implementation), and must terminate by sending a COMMAND_ACK message with final result of the operation. The COMMAND_ACK.progress field can be used to indicate the progress of the operation. | */
   MAV_RESULT_CANCELLED=6, /* Command has been cancelled (as a result of receiving a COMMAND_CANCEL message). | */
   MAV_RESULT_COMMAND_LONG_ONLY=7, /* Command is only accepted when sent as a COMMAND_LONG. | */
   MAV_RESULT_COMMAND_INT_ONLY=8, /* Command is only accepted when sent as a COMMAND_INT. | */
   MAV_RESULT_COMMAND_UNSUPPORTED_MAV_FRAME=9, /* Command is invalid because a frame is required and the specified frame is not supported. | */
   MAV_RESULT_NOT_IN_CONTROL=10, /* Command has been rejected because source system is not in control of the target system/component. | */
   MAV_RESULT_ENUM_END=11, /*  | */
} MAV_RESULT;
#endif

/** @brief Enum used to indicate true or false (also: success or failure, enabled or disabled, active or inactive). */
#ifndef HAVE_ENUM_MAV_BOOL
#define HAVE_ENUM_MAV_BOOL
typedef enum MAV_BOOL
{
   MAV_BOOL_FALSE=0, /* False. | */
   MAV_BOOL_TRUE=1, /* True. | */
   MAV_BOOL_ENUM_END=2, /*  | */
} MAV_BOOL;
#endif

/** @brief Used to indicate the current state of the extra feature buttons */
#ifndef HAVE_ENUM_PUSH_BUTTONS
#define HAVE_ENUM_PUSH_BUTTONS
typedef enum PUSH_BUTTONS
{
   EXTRA_FEATURE_1_PRESS=1, /*  a single short press of extra feature 1 button.  | */
   EXTRA_FEATURE_1_LONG_PRESS=2, /*  a long press of extra feature 1 button.  | */
   EXTRA_FEATURE_2_PRESS=4, /*  a single short press of extra feature 2 button.  | */
   EXTRA_FEATURE_2_LONG_PRESS=8, /*  a long press of extra feature 2 button.  | */
   PUSH_BUTTONS_ENUM_END=9, /*  | */
} PUSH_BUTTONS;
#endif

/** @brief Used to indicate the position of the tristate toggle switches. */
#ifndef HAVE_ENUM_TOGGLE_SWITCH_POS
#define HAVE_ENUM_TOGGLE_SWITCH_POS
typedef enum TOGGLE_SWITCH_POS
{
   FORWARD_DIRECTION=1, /* 0x01 Forward Direction | */
   REVERSE_DIRECTION=2, /* 0x02 Reverse Direction | */
   MEDIUM_SPEED=4, /* 0x04 Medium Speed | */
   HIGH_SPEED=8, /* 0x08 High Speed | */
   TOGGLE_SWITCH_POS_ENUM_END=9, /*  | */
} TOGGLE_SWITCH_POS;
#endif

/** @brief These flags encode the MAV mode, see MAV_MODE enum for useful combinations. */
#ifndef HAVE_ENUM_MAV_MODE_FLAG
#define HAVE_ENUM_MAV_MODE_FLAG
typedef enum MAV_MODE_FLAG
{
   MAV_MODE_FLAG_CUSTOM_MODE_ENABLED=1, /* 0b00000001 system-specific custom mode is enabled. When using this flag to enable a custom mode all other flags should be ignored. | */
   MAV_MODE_FLAG_TEST_ENABLED=2, /* 0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations. | */
   MAV_MODE_FLAG_AUTO_ENABLED=4, /* 0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation. | */
   MAV_MODE_FLAG_GUIDED_ENABLED=8, /* 0b00001000 guided mode enabled, system flies waypoints / mission items. | */
   MAV_MODE_FLAG_STABILIZE_ENABLED=16, /* 0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around. | */
   MAV_MODE_FLAG_HIL_ENABLED=32, /* 0b00100000 hardware in the loop simulation. All motors / actuators are blocked, but internal software is full operational. | */
   MAV_MODE_FLAG_MANUAL_INPUT_ENABLED=64, /* 0b01000000 remote control input is enabled. | */
   MAV_MODE_FLAG_SAFETY_ARMED=128, /* 0b10000000 MAV safety set to armed. Motors are enabled / running / can start. Ready to fly. Additional note: this flag is to be ignore when sent in the command MAV_CMD_DO_SET_MODE and MAV_CMD_COMPONENT_ARM_DISARM shall be used instead. The flag can still be used to report the armed state. | */
   MAV_MODE_FLAG_ENUM_END=129, /*  | */
} MAV_MODE_FLAG;
#endif

/** @brief These encode the sub systems whose status is sent as part of the UGV_MASTER_HEALTH message. */
#ifndef HAVE_ENUM_UGV_COMP_BITMASK
#define HAVE_ENUM_UGV_COMP_BITMASK
typedef enum UGV_COMP_BITMASK
{
   UGV_COMP_COMP_COMPUTE=1, /* 0x01 Atlas Compute | */
   UGV_COMP_VCU=2, /* 0x02 Vehicle Control Unit (VCU) | */
   UGV_COMP_LEFT_MOTOR=4, /* 0x04 Motor Controller (left) | */
   UGV_COMP_RIGHT_MOTOR=8, /* 0x08 Motor Controller (right) | */
   UGV_COMP_BMS=16, /* 0x10 Battery Management System (BMS) | */
   UGV_COMP_PDU=32, /* 0x20 Power Distribution Unit (PDU) | */
   UGV_COMP_UHF_RADIO=64, /* 0x40 UHF radio | */
   UGV_COMP_DISPLAY=128, /* 0x80 Display | */
   UGV_COMP_HAND_CTRL=256, /* 0x100 Hand controller | */
   UGV_COMP_GCS=512, /* 0x200 Ground Control Station (GCS) | */
   UGV_COMP_BITMASK_ENUM_END=513, /*  | */
} UGV_COMP_BITMASK;
#endif

/** @brief Enum used to indicate the errors present in Motors */
#ifndef HAVE_ENUM_UGV_MOTOR_ERROR
#define HAVE_ENUM_UGV_MOTOR_ERROR
typedef enum UGV_MOTOR_ERROR
{
   UGV_MOTOR_ERROR_OVER_SPEED=1, /* 0x01 Motor Over Speed | */
   UGV_MOTOR_ERROR_OVERLOAD=2, /* 0x02 Motor Overload | */
   UGV_MOTOR_ERROR_PHASE_LOSS=4, /* 0x04 Motor Phase Loss | */
   UGV_MOTOR_ERROR_BRAKE_FAULT=8, /* 0x08 Motor Brake Fault | */
   UGV_MOTOR_ERROR_ENCODER_FAULT=16, /* 0x10 Motor Encoder Fault | */
   UGV_MOTOR_ERROR_OVER_TEMPERATURE=32, /* 0x20 Motor Over Temperature | */
   UGV_MOTOR_ERROR_HALL_FAULT=64, /* 0x40 Motor Hall Fault | */
   UGV_MOTOR_ERROR_STALLED=128, /* 0x80 Motor Stalled Fault | */
   UGV_MOTOR_ERROR_ENUM_END=129, /*  | */
} UGV_MOTOR_ERROR;
#endif

/** @brief Enum used to indicate the errors present in Motor Controller */
#ifndef HAVE_ENUM_UGV_MOTOR_CTRL_ERROR
#define HAVE_ENUM_UGV_MOTOR_CTRL_ERROR
typedef enum UGV_MOTOR_CTRL_ERROR
{
   UGV_MOTOR_CTRL_ERROR_DRIVE=1, /* 0x01 Drive Fault | */
   UGV_MOTOR_CTRL_ERROR_OVER_CURRENT=2, /* 0x02 Over Current | */
   UGV_MOTOR_CTRL_ERROR_OVER_PRESSURE=4, /* 0x04 Over Pressure | */
   UGV_MOTOR_CTRL_ERROR_UNDER_VOLTAGE=8, /* 0x08 Under Voltage | */
   UGV_MOTOR_CTRL_ERROR_OVER_TEMPERATURE=16, /* 0x10 Over Temperature | */
   UGV_MOTOR_CTRL_ERROR_CAN_COMM=32, /* 0x20 CAN Communication Fault | */
   UGV_MOTOR_CTRL_ERROR_ENUM_END=33, /*  | */
} UGV_MOTOR_CTRL_ERROR;
#endif

/** @brief Operator mode in which the UGV operates in. Mode A signifies hand controller, Mode B signifies GCS */
#ifndef HAVE_ENUM_UGV_MAIN_MODE
#define HAVE_ENUM_UGV_MAIN_MODE
typedef enum UGV_MAIN_MODE
{
   MODE_A=1, /* Mode A, hand controller | */
   MODE_B=2, /* Mode B, GCS | */
   UGV_MAIN_MODE_ENUM_END=3, /*  | */
} UGV_MAIN_MODE;
#endif

/** @brief Operator submode in which the UGV operates in. */
#ifndef HAVE_ENUM_UGV_SUB_MODE
#define HAVE_ENUM_UGV_SUB_MODE
typedef enum UGV_SUB_MODE
{
   NONE=0, /* no active submode | */
   HOLD=10, /* Hold submode, used when UGV is temporarily in halt. | */
   UGV_SUB_MODE_ENUM_END=11, /*  | */
} UGV_SUB_MODE;
#endif

/** @brief Reason for sub-mode change. */
#ifndef HAVE_ENUM_MODE_CHANGE_REASON
#define HAVE_ENUM_MODE_CHANGE_REASON
typedef enum MODE_CHANGE_REASON
{
   GCS_COMMAND=0, /* submode changed due to GCS command | */
   FAILSAFE=1, /* submode changed due to activation of failsafe | */
   SENSOR_FAULT=2, /* submode changed due to sensor fault | */
   COMM_LOSS=3, /* submode change due to loss of communication | */
   MODE_CHANGE_REASON_ENUM_END=4, /*  | */
} MODE_CHANGE_REASON;
#endif

/** @brief 
            Generic subsystem communication and health status.
            Used for motor controllers, batteries, PDUs, and other subsystems.
         */
#ifndef HAVE_ENUM_UGV_HEALTH_STATE
#define HAVE_ENUM_UGV_HEALTH_STATE
typedef enum UGV_HEALTH_STATE
{
   RESERVED_STATE=0, /* Reserved state. | */
   NO_COMMUNICATION_STATE=1, /* No communication with subsystem. | */
   COMMUNICATING_HEALTHY_STATE=2, /* Subsystem communicating and healthy. | */
   FAULT_STATE=3, /* Subsystem communicating but unhealthy. Fault present. | */
   UGV_HEALTH_STATE_ENUM_END=4, /*  | */
} UGV_HEALTH_STATE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_sys_status.h"
#include "./mavlink_msg_system_time.h"
#include "./mavlink_msg_manual_control.h"
#include "./mavlink_msg_command_long.h"
#include "./mavlink_msg_command_ack.h"
#include "./mavlink_msg_radio_status.h"
#include "./mavlink_msg_timesync.h"
#include "./mavlink_msg_ugv_system_info.h"
#include "./mavlink_msg_ugv_component_version.h"
#include "./mavlink_msg_ugv_subsystem_version.h"

// base include



#if MAVLINK_UGVCUSTOM_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SYS_STATUS, MAVLINK_MESSAGE_INFO_SYSTEM_TIME, MAVLINK_MESSAGE_INFO_MANUAL_CONTROL, MAVLINK_MESSAGE_INFO_COMMAND_LONG, MAVLINK_MESSAGE_INFO_COMMAND_ACK, MAVLINK_MESSAGE_INFO_RADIO_STATUS, MAVLINK_MESSAGE_INFO_TIMESYNC, MAVLINK_MESSAGE_INFO_UGV_SYSTEM_INFO, MAVLINK_MESSAGE_INFO_UGV_COMPONENT_VERSION, MAVLINK_MESSAGE_INFO_UGV_SUBSYSTEM_VERSION}
# define MAVLINK_MESSAGE_NAMES {{ "COMMAND_ACK", 77 }, { "COMMAND_LONG", 76 }, { "HEARTBEAT", 0 }, { "MANUAL_CONTROL", 69 }, { "RADIO_STATUS", 109 }, { "SYSTEM_TIME", 2 }, { "SYS_STATUS", 1 }, { "TIMESYNC", 111 }, { "UGV_COMPONENT_VERSION", 50002 }, { "UGV_SUBSYSTEM_VERSION", 50003 }, { "UGV_SYSTEM_INFO", 50001 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_UGVCUSTOM_H
