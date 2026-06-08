/**
 * @file definitions.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * All definitions, used within every header file is included here. 
 */
#pragma once
#include "definitions/enum_defs.h"
#include "definitions/IO_defs.h"
#include "definitions/time_defs.h"
#include "definitions/version.h"



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
#define LCD_DISPLAY_BAUD_RATE 9600

// if the code is not meant to be deployed on the prototype hand controller, then comment out this line
#define PROTOTYPE

//#define SIGN_PACKETS  // used to send and receive signed packets
#define BYPASS_NO_SIGNING   // prevents display of error to show that signing is disabled

// if the code is not meant to operate in debug mode (prints out info on serial communication), comment out this line
//#define _DEBUG_
//#define TESTING_JOYSTICK
//#define TESTING // ONLY use this when testing features
//#define STOP_COMM   // when testing features and no communication is to be sent.

//#define SPECIAL_TESTING

//#define PRINT_BYTES // used to print raw received bytes



#define TIME_REQ

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


