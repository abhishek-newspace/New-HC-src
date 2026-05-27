/**
 * @file displayHandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * Takes care of all display-related functionality
 */
#pragma once
#include "definitions.h"
#include "definitions/display_defs.h"



/**
 * 1. setup display baud rate
 * 2. clear display
 * 3. display logo/initial messages
 * 4. display text/symbols for status indication
 */
void setupDisplay();

/// @brief clear LCD display
void clear_display();


IF_PROTOTYPE(
    void displayLogo();
    void displayInvertedLogo();
)   // IF_PROTOTYPE

/// @brief display error message and confirm with user whether to proceed or wait
void displayError(String message, int error_code);

/// @brief display info message and wait for any user input to continue execution
void displayInfo(String message);

/// initialize display communications (serial baud rate)
void initDisplayComm();

/// @brief update UGV status dislay
void displayUGV_status(ugv_status);

/// @brief update speed display
void displaySpeed(int speed);

/// @brief update RSSI stat display
void displayRSSI();

/// update battery stat display
void displayBattery();

/// @brief set the screen with symbols/text that is required to understand the output of the display updates
void displayBasic();

/// @brief display newspace logo in white background and blue foreground colors
void displayLogo();

/// @brief display newspace logo in grey background and light blue foreground (to look like an translucent grey film filter)
void displayInvertedLogo();


void setBatterySOC(uint8_t);
void setRSSI(uint8_t);

/**
 * this function is meant to be called once every 1 second, and only updates RSSI, and battery stats.
 * call displaySpeed() and displayUGV_status() separately when the values are updated (must be event based, and not periodic)
 */
void updateDisplay();

/// @brief set font style to 1
void setFont1();

/// @brief clear all info that is displayed
void clearInfo();


/// @brief clear displayed error
void clearError();


/// @brief writes direction onto screen
/// @param direction current direction
void displayDirection(directionToggle direction);