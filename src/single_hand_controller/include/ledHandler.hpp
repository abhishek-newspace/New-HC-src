#pragma once
#include "definitions.h"
#include "definitions/IO_defs.h"
#include "IOhandler.hpp"      // Provides readHcBatterySoc()
#include "stateHandler.hpp"

// RGB Colors for Common Anode LEDs
enum RGBColor {
    COLOR_OFF = 0,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_CYAN
};

/// @brief Initialize GPIOs for discrete Arm LED and all 5 RGB LEDs
void setupLEDs();

/// @brief Set specific RGB LED (0 to 4) to a color
void setRGBColor(uint8_t ledIndex, RGBColor color);

/// @brief Periodically update LEDs based on system states
void updateLEDs();

/// @brief Control the discrete ARM status LED
void setArmLED(bool state);
