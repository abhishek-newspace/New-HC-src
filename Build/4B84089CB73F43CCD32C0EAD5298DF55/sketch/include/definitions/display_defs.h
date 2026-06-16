#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/definitions/display_defs.h"
#pragma once
/**
 * @file display_defs.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 20/05/2026
 * 
 * definitions required for display
 */


// LCD Device-specific header file
#include "TFT_22_ILI9225.h"


//#define DISPLAY_NS_LOGO

#define BACKGROUND_COLOR COLOR_BLACK
#define DEFAULT_TEXT_COLOR  COLOR_WHITE

#define BATTERY_BG_COLOR COLOR_BLACK    
#define BATTERY_COLOR COLOR_WHITE

#define INFO_TEXT_COLOR COLOR_YELLOW
#define ERROR_TEXT_COLOR COLOR_RED

#define CONNECTED_COLOR COLOR_GREEN
#define RADIO_CONNECTED_COLOR COLOR_CYAN
#define DISCONNECTED_COLOR COLOR_ORANGE

#define DM_COLOR COLOR_GREENYELLOW

#define SCREEN_HEIGHT 221
#define SCREEN_WIDTH 176

// display configurations
#define BATTERY_TIP_WIDTH 3
#define BATTERY_RECTANGLE_THICKNESS 2
#define BATTERY_LENGTH 40
#define BATTERY_HEIGHT 10

#define BATTERY_POS_X 100 
#define BATTERY_POS_Y 5

#define Y_OFFSET 5

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

#define DM_POS_X 5
#define DM_POS_Y 5
