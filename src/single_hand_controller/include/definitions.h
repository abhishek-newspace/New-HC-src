/**
 * @file definitions.h
 * @version 0.3
 * @author Abhishek
 * @date 17/07/2026
 *
 * All definitions used by the Hand Controller.
 *
 * ---------------------------------------------------------------------------
 * HOW TO SWITCH LINK MODE (only this section — then Verify + Upload)
 * ---------------------------------------------------------------------------
 * Development (no UHF radio, Atlas on same USB COM as HC):
 *   1) Comment out  #define RELEASE
 *   2) Keep          #define HC_LINK_OVER_USB
 *
 * Production (UHF radio on Serial3):
 *   1) Uncomment     #define RELEASE
 *   2) Comment out   #define HC_LINK_OVER_USB
 *
 * Optional: with RELEASE commented and HC_LINK_OVER_USB commented, you can
 * enable _DEBUG_ / PRINT_BYTES for Serial Monitor while using real radio.
 * ---------------------------------------------------------------------------
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - HC_LINK_OVER_USB link-mode switch documentation
 * - MANUAL_CONTROL_ONLY_WHEN_MOVING gate
 * - ICD_ARM_PARAM1 / ICD_DISARM_PARAM1
 * - ICD_REMOTE_EMERGENCY_* (1=Disable, 2=Engaged, 3=Disengaged)
 *
 * @date 17/07/2026
 * @author Abhishek
 * - flipped arm/disarm command param1 to ICD: 2=ARM, 1=DISARM
 */
#pragma once
#include "definitions/enum_defs.h"
#include "definitions/IO_defs.h"
#include "definitions/time_defs.h"
#include "definitions/version.h"
#include "definitions/error_codes.h"



/// @brief signing key used to sign packets [meant to be changed on deployment]
unsigned char const signing_key[32] = {0x2d,0x3d,0x67,0xb6,0xa9,0x92,0x1b,0x1a,0xb0,0x93,0x11,0x73,0xe2,0xda,0x1c,0xee,0x26,0x3,0x53,0x39,0x23,0xb4,0x58,0x19,0xe4,0xa6,0x9c,0x92,0x5b,0x45,0x96,0x45};

// MAVLink system ID, and Component ID for scout
#define SCOUT_ID 1
#define ATLAS_COMP_ID 191

// MAVLink system ID, and Component ID for single hand controller
#define HC_ID 2
#define HC_COMP_ID 1


// can be used when invoking an arm_disarm command long message
#define STATE_DISARM 0
#define STATE_ARM 1

// baud rates; used in setupFunctions.h
#define BAUD_RATE 115200
#define LCD_DISPLAY_BAUD_RATE 115200

// if the code is not meant to be deployed on the prototype hand controller, then comment out this line
#define PROTOTYPE

/**
 * HC hardware without TFT: uncomment to disable ALL display init/draw.
 * Teleop, MAVLink, buttons, and state logic keep working; TFT pins are never touched.
 * Comment out again for Helios remotes that still have the ILI9225 screen.
 *
 *   Headless (no screen):  #define HC_NO_DISPLAY
 *   With TFT:              // #define HC_NO_DISPLAY
 */
#define HC_NO_DISPLAY

#define SIGN_PACKETS  // used to send and receive signed packets
//#define BYPASS_NO_SIGNING   // prevents display of error to show that signing is disabled

/* Must be defined before any mavlink.h include in every TU — shared channel
 * status so setupSigning() reaches message_sender finalize (else incompat=0). */
#define MAVLINK_EXTERNAL_RX_STATUS
#define MAVLINK_EXTERNAL_RX_BUFFER

//#define RELEASE_ARDUINO_UNO

/* ===================== SWITCH THESE TWO FOR DEV vs PRODUCTION ===================== */

#ifndef RELEASE_ARDUINO_UNO
// PRODUCTION UHF: uncomment RELEASE and comment out HC_LINK_OVER_USB.
#define RELEASE
#endif

/**
 * CURRENT LAB MODE: USB ↔ Atlas (UHF off, clean MAVLink — no Serial debug).
 *   - MAVLink on USB Serial (same COM used to flash) @ 115200
 *   - Close Serial Monitor while Atlas owns the COM (debug text corrupts MAVLink)
 *
 * For PRODUCTION UHF: comment out HC_LINK_OVER_USB and uncomment RELEASE above.
 */
// #define HC_LINK_OVER_USB

/* Alias used by the rest of the codebase (do not rename call sites). */
#ifdef HC_LINK_OVER_USB
#define RADIO_SIMULATION_TESTING
#endif

/* ===================== END SWITCH SECTION ======================================== */


#ifndef RELEASE // Turn off all debug features during release

// #define GET_RADIO_CONFIG

/*
 * Keep Serial debug OFF when HC_LINK_OVER_USB is set: RADIO_PORT is Serial, so
 * IF_DEBUG prints would interleave with MAVLink and corrupt Atlas decode
 * (including incompat_flags / signing). Enable _DEBUG_ only with real UHF
 * (Serial3) and a separate USB Serial Monitor.
 */
#ifndef HC_LINK_OVER_USB
// #define _DEBUG_
#endif
// #define PRINT_BYTES
// #define TESTING
// #define DEBUG_OFP_TIMING

//#define TESTING_TIMESYNC
// #define TESTING_JOYSTICK
//#define STOP_COMM
//#define STOP_RECV
//#define SPECIAL_TESTING

#endif


//#define TIME_REQ  // comment out this definition in case of not requiring time to be displayed

/**
 * When defined: MANUAL_CONTROL is sent only while the stick is out of the dead-zone
 * (plus one final zero frame when it returns to center so the UGV stops).
 * Comment out to restore SRS §3.2.8 continuous 50 Hz while armed.
 */
#define MANUAL_CONTROL_ONLY_WHEN_MOVING

#define ICD_ARM_PARAM1    2.0f
#define ICD_DISARM_PARAM1 1.0f

#define ICD_REMOTE_EMERGENCY_DISABLE    1.0f
#define ICD_REMOTE_EMERGENCY_ENGAGED    2.0f
#define ICD_REMOTE_EMERGENCY_DISENGAGED 3.0f

#define USE_HEARTBEAT_MAVLINKV1


#ifdef SPECIAL_TESTING
#define IF_SPECIAL_TESTING(CODE) CODE
#else
#define IF_SPECIAL_TESTING(CODE)
#endif

#ifdef PRINT_BYTES
#define IF_PRINT_BYTES(CODE) CODE
#else
#define IF_PRINT_BYTES(CODE)
#endif


#ifdef TESTING_JOYSTICK
#define IF_TESTING_JOYSTICK(CODE) CODE
#else
#define IF_TESTING_JOYSTICK(CODE)
#endif

#ifdef TESTING

#define IF_TESTING(CODE) CODE
#define IGNORE_WHILE_TESTING(CODE)

#else

#define IGNORE_WHILE_TESTING(CODE) CODE
#define IF_TESTING(CODE)

#endif



#ifdef PROTOTYPE
#define IF_PROTOTYPE(CODE) CODE
#else
#define IF_PROTOTYPE(CODE)
#endif


#ifdef _DEBUG_
#define DEBUG(CODE) CODE
#define IF_DEBUG(CODE) CODE
#else
#define DEBUG(CODE)
#define IF_DEBUG(CODE)
#endif

#ifdef RADIO_SIMULATION_TESTING
#define RADIO_PORT Serial
#else
#define RADIO_PORT Serial3
#endif


#define DEPRECATED_REV_1    // wrap items that were deprecated in major revision of MAVLink XML into this
