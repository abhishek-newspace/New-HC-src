#pragma once
/**
 * @file display_defs.h
 * @version 0.4
 * @author Abhishek
 * @date 21/09/2026
 * 
 * definitions required for display
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - RSSI_WEAK_THRESHOLD_DBM (-120) for Yellow low-link LED
 * - compact UGV/HC battery layout (BATTERY_LENGTH/HEIGHT, UGV_/HC_BATTERY_POS_*)
 * - DISCONNECTED_COLOR set to Red per SRS §3.2.2
 *
 * @date 21/08/2026
 * @author Abhishek
 * - ENABLE_STARTUP_LOGO / STARTUP_LOGO_HOLD_MS: static NS splash (no invert animation)
 * - splash/UI painted with backlight gated to hide soft-SPI scan wipe
 *
 * @date 09/09/2026
 * - drive-mode text colours: Speed=green, Torque=blue, Torque+SL=orange
 *
 * @date 21/09/2026
 * @author Abhishek
 * - remote e-stop LED indicator (Engaged=Red, Disengaged=Green, Disabled=Gray)
 *   placed below connectivity LED so it does not overlap status text
 *
 * @date 22/09/2026
 * - HC_NO_DISPLAY: skip TFT header and layout macros (headless HC builds)
 *
 * Requires HC_NO_DISPLAY (optional) from definitions.h — include that first.
 */

#ifndef HC_NO_DISPLAY

// LCD Device-specific header file
#include "TFT_22_ILI9225.h"


//#define DISPLAY_NS_LOGO

/**
 * Boot splash: NewSpace logo shown as a single frame (backlight off while painting
 * so soft-SPI scan is not visible), brief hold, then main UI.
 * Comment out to skip logo and go straight to the status screen.
 */
// #define ENABLE_STARTUP_LOGO
/** How long the completed logo stays visible (ms). Keep short — no fade/animation. */
#define STARTUP_LOGO_HOLD_MS 200

#define BACKGROUND_COLOR COLOR_BLACK
#define DEFAULT_TEXT_COLOR  COLOR_WHITE

#define BATTERY_BG_COLOR COLOR_BLACK    
#define BATTERY_COLOR COLOR_WHITE

#define INFO_TEXT_COLOR COLOR_YELLOW
#define ERROR_TEXT_COLOR COLOR_RED

#define CONNECTED_COLOR COLOR_GREEN
#define RADIO_CONNECTED_COLOR COLOR_CYAN
/** Status text when UGV is disconnected — SRS Red = not connected to UGV. */
#define DISCONNECTED_COLOR COLOR_RED

/**
 * Local/remote RSSI (after RFD scaling `raw/2 - 152`) below this value → Yellow LED
 * while UGV is connected (SRS §3.2.2 low-link warning).
 */
#define RSSI_WEAK_THRESHOLD_DBM (-120)

/**
 * Drive-mode text colours (stand-in for HC drive-mode LED — SRS / test matrix):
 *   Speed                    -> Green
 *   Torque                   -> Blue
 *   Torque with speed limit  -> Orange
 */
#define DM_COLOR_SPEED   COLOR_GREEN
#define DM_COLOR_TORQUE  COLOR_BLUE
#define DM_COLOR_TORQUE_SL COLOR_ORANGE
#define DM_COLOR DM_COLOR_SPEED

/**
 * Battery box labels ("UGV"/"HC"). This TFT has no true alpha blending;
 * drawText() also paints an opaque black glyph background that hides the fill.
 * Use a dim grey stroke + transparent (foreground-only) drawing instead.
 */
#define BATTERY_LABEL_COLOR COLOR_GRAY

#define SCREEN_HEIGHT 221
#define SCREEN_WIDTH 176

/**
 * Top row: drive mode (left) + small UGV/HC battery rectangles (right).
 * Compact size so both fit with mode on one row.
 */
#define DM_POS_X 5
#define DM_POS_Y 5

#define BATTERY_TIP_WIDTH 2
#define BATTERY_RECTANGLE_THICKNESS 1
#define BATTERY_LENGTH 28
#define BATTERY_HEIGHT 9

#define UGV_BATTERY_POS_X 85
#define UGV_BATTERY_POS_Y 4
#define HC_BATTERY_POS_X 128
#define HC_BATTERY_POS_Y 4

#define Y_OFFSET 5

/* Original status layout below top row */
#define UGV_STATUS_POS_X 25
#define UGV_STATUS_TEXT_POS_X 5
#define UGV_STATUS_TEXT_POS_Y (UGV_STATUS_POS_X + 19)

#define SPEED_POS_X 65
#define SPEED_TEXT_POS_X 70
#define SPEED_TEXT_POS_Y SPEED_POS_X

#define RSSI_POS_X 90
#define RSSI_TEXT_POS_X 55
#define RSSI_TEXT_POS_Y RSSI_POS_X

#define DIRN_POS_X 115
#define DIRN_POS_TEXT_X 55
#define DIRN_POS_TEXT_Y DIRN_POS_X

#define ERROR_MSG_POS_X 0
#define ERROR_MSG_POS_Y 150

#define ERROR_MSG_POS_X1 176
#define ERROR_MSG_POS_Y1 200

#define INFO_MSG_POS_X 0
#define INFO_MSG_POS_Y 200

#define INFO_MSG_POS_X1 176
#define INFO_MSG_POS_Y1 221

#define CONNECTED_MSG_POS_X 5
#define CONNECTED_MSG_POS_Y 115

#define CONN_STAT_MSG_POS_X 150
#define CONN_STAT_MSG_POS_Y 25
#define CONN_STAT_MSG_SZ_X 20
#define CONN_STAT_MSG_SZ_Y 20

/**
 * Remote e-stop LED (SRS §3.3.1) — same size as conn LED, stacked below it
 * on the right margin so it clears UGV STATUS / SPEED / RSSI text columns.
 *   Engaged    -> Red
 *   Disengaged -> Green
 *   Disabled   -> Gray
 */
#define ESTOP_STAT_MSG_POS_X 150
#define ESTOP_STAT_MSG_POS_Y 50
#define ESTOP_STAT_MSG_SZ_X  20
#define ESTOP_STAT_MSG_SZ_Y  20
/** Tiny "E" label just left of the e-stop LED (Terminal6x8). */
#define ESTOP_LABEL_POS_X 138
#define ESTOP_LABEL_POS_Y 55

#define ESTOP_COLOR_ENGAGED    COLOR_RED
#define ESTOP_COLOR_DISENGAGED COLOR_GREEN
#define ESTOP_COLOR_DISABLED   COLOR_GRAY

#endif /* !HC_NO_DISPLAY */
