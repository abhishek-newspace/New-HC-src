/**
 * @file displayHandler.hpp
 * @version 0.3
 * @author Abhishek
 * @date 21/08/2026
 * Takes care of all display-related functionality
 *
 * <h2>Changes</h2>
 * @date 15/07/2026
 * - declared displayHcBatteryStatus() and triggerTactileAlert() (SRS §3.2.3.3 / §3.2.4)
 *
 * @date 21/08/2026
 * @author Abhishek
 * - declared setDisplayBacklight() and showStartupLogo() for static backlight-gated splash
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

/// @brief TFT backlight on/off (used to hide soft-SPI paint scan)
void setDisplayBacklight(bool on);

/// @brief static NS logo splash (backlight-gated; no wipe/invert animation)
void showStartupLogo();

void displayLogo();
void displayInvertedLogo();

/// @brief display error message and confirm with user whether to proceed or wait
void displayError(String message, int error_code);

/// @brief display info message and wait for any user input to continue execution
void displayInfo(String message);

/// initialize display communications (serial baud rate)
void initDisplayComm();

/// @brief update UGV status dislay
void displayUGV_status(ugv_status);

/// @brief display current connection status
void displayConnectionStatus();

/// @brief update speed display
void displaySpeed(int speed);

/// @brief update RSSI stat display
void displayRSSI();

/// update UGV battery stat display
void displayBattery();

/**
 * SRS §3.2.3.3 — HC pack compact battery box on the top row (label "HC" inside).
 */
void displayHcBatteryStatus();

/// @brief set the screen with symbols/text that is required to understand the output of the display updates
void displayBasic();

/// @brief display newspace logo in white background and blue foreground colors
void displayLogo();

/// @brief display newspace logo in grey background and light blue foreground (to look like an translucent grey film filter)
void displayInvertedLogo();


void setBatterySOC(uint8_t);
void setRSSI(int16_t);
void setRemRSSI(uint16_t curr_remRSSI);

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

/// @brief set radio status to disconnected
void disconnectRadio();

/// @brief set radio status to connected
void connectRadio();

/// @brief update the display for drive mode
/// @param mode speed / torque
void displayDriveMode(driveMode mode);

/// @brief returns the current error code currently dosplsyed
int getErrorCodeDisplayed();

/**
 * SRS §3.2.4 tactile alert for low UGV battery.
 * Pulses TACTILE_PIN when defined in IO_defs.h; no-op on remotes without haptic HW.
 */
void triggerTactileAlert();

