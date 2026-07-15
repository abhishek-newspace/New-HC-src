/**
 * @file time_defs.h
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
 * 
 * definitions related to time conversions, delays, and waits set for various function callbacks
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - STATE_REQUEST_TIMEOUT_MS (3 s) for arm/speed/drive-mode request visibility
 * - ESTOP_RETRANSMIT_MS / LIGHT_RETRANSMIT_MS (1 s) periodic retransmit periods
 */
#pragma once


// unique identifier placed within heartbeat packets sent from scout, used to identify scout.
#define SCOUT_HEARTBEAT_IDENTIFIER 1191


/**
 * naming convention ->
 * SECONDS => seconds
 * US => microseconds
 * MS => milliseconds
 * 
 * SECONDS_US_count => conversion of count seconds to microseconds
 * SECONDS_MS_count => conversion of count seconds to milliseconds
 * MS_count => count milliseconds
 */
#define SECONDS_US_10 10000000 /// 10 seconds to microseconds
#define SECONDS_US_3 3000000 /// 3 seconds to microseconds
#define SECONDS_US_2 2000000 /// 2 seconds to microseconds
#define SECONDS_US_1 1000000 /// 1 seconds to microseconds

#define SECONDS_MS_10 10000 /// 10 seconds to milliseconds
#define SECONDS_MS_5 5000 /// 5 seconds to milliseconds
#define SECONDS_MS_3 3000 /// 3 seconds to milliseconds
#define SECONDS_MS_2 2000 /// 2 seconds to milliseconds
#define SECONDS_MS_1 1000 /// 1 seconds to milliseconds

#define MS_1500 1500
#define MS_500 500
#define MS_200 200  // 200 milliseconds
#define MS_40 40    // 40 milliseconds
#define MS_20 20    // 20 milliseconds
#define MS_10 10    // 10 milliseconds





// all durations to be defined in microseconds
#define HEARTBEAT_TIMEOUT       SECONDS_MS_3   // left to be in milliseconds due to limitation of micros() function that resets every 70 minutes 
#define TIMESYNC_MSG_WAIT       SECONDS_MS_10  // left to be in milliseconds due to limitation of micros() function that resets every 70 minutes 
#define MANUAL_CONTROL_MSG_WAIT MS_10
#define ARM_DISARM_RESEND_DELAY MS_1500
#define RESEND_DELAY MS_1500

/** SRS §3.2.5 / §3.2.6 / §3.2.7: operator state-change requests time out / retry at 3 s. */
#define STATE_REQUEST_TIMEOUT_MS SECONDS_MS_3

/** SRS §3.3.1.3.2: retransmit remote-emergency engagement periodically while toggle is armed. */
#define ESTOP_RETRANSMIT_MS SECONDS_MS_1

/** SRS §3.2.9.3.2: retransmit light ON/OFF state periodically while lights are commanded ON. */
#define LIGHT_RETRANSMIT_MS SECONDS_MS_1

#define OFP_LOOP_TIME           MS_20
#define SCREEN_UPDATE_DELAY     SECONDS_MS_2    // screen to be updated every 2 second

#define LONG_PRESS_DURATION     MS_500
#define BUTTON_PRESS_COOLDOWN   MS_40
#define TOGGLE_DEBOUNCE_DURATION SECONDS_US_2
