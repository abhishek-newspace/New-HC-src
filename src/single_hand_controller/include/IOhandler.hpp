/**
 * @file IOhandler.hpp
 * @version 0.2
 * @author Abhishek
 * @date 15/07/2026
 * Any interfacing with input/output pins of the microcontroller is taken care of, within this header file, except handling display output, which is done by the displayHandler
 * 
 * <h2>Changes</h2>
 * @date 28/04/2026
 * - Modified struct to inclued cooldown period, so that when the button is pressed and released, the next press is only registered after the cooldown period
 * - modified struct to include callback functions to increase, decrease and set speed to neutral
 *
 * @date 15/07/2026
 * - declared updateLightToggleEdge() for pins 6/8 light toggle (edge-triggered only)
 * - declared readHcBatterySoc() for local HC battery SoC (SRS §3.2.3.3)
 *
 * @date 29/07/2026
 * @author Abhishek
 * - declared updateEstopToggleEdge() for pins 4/5 e-stop toggle
 */
#pragma once
#include "definitions.h"
#include "stateHandler.hpp"


/// @brief thumbstick control is used within this library
struct thumbstickControl{
    float X, Y;
};

/**
 * @brief update user input struct
 * @details user input struct is defined in IOhandler.cpp. declare it in the file where it is required as `extern struct buttons user_input` and access the variables in it to obtain updated user input
 */
void checkUserInput();

/// @brief get thumbstick's raw position (0 to 1023)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY_raw(struct thumbstickControl *control);

/// @brief get thumbstick's normalized position (-100 to 100)
/// @param control -> the current position of the thumbstick is written into this struct
void getXY(struct thumbstickControl *control);


/// @brief update parameters within the button struct
/// @param b1 button struct in which update needs to happen
/// @param ms_since_last_check number of milliseconds since last time this function was called (ideally to only be used within checkUserInput() function) 
void updateButtonValues(struct button *b1, int32_t ms_since_last_check);

/// @brief update parameters within the button struct
/// @param b1 long press button struct in which update needs to happen
/// @param ms_since_last_check number of milliseconds since last time this function was called (ideally to only be used within checkUserInput() function) 
void updateLongPressButtonValues(struct long_press_button *b1, int32_t ms_since_last_check);

/// @brief update parameters within the toggle struct
/// @param t1 toggle struct in which update needs to happen
/// @param ms_since_last_check number of milliseconds since last time this function was called (ideally to only be used within checkUserInput() function) 
void updateToggleValues(struct toggle *t1, int32_t ms_since_last_check);


void updateTwoPosToggleValues(struct two_pos_toggle *t1, int32_t ms_since_last_check);

/**
 * Light 3-pos toggle (pins 6=OFF, mid=HEAD, 8=FOG): fire callbacks only on position change
 * so MAVLink LIGHT_CONTROL is not requested every input poll.
 */
void updateLightToggleEdge(struct two_pos_toggle *t1, int32_t ms_since_last_check);

/**
 * E-stop 3-pos toggle (pin4=engage, pin5=disengage, centre=N/A):
 * edge-triggered only — centre does nothing.
 */
void updateEstopToggleEdge(struct two_pos_toggle *t1, int32_t ms_since_last_check);

/**
 * SRS §3.2.3.3 — read HC pack SoC % from HC_BATTERY_ADC_PIN (0–100).
 * Local indication only; never transmitted.
 */
uint8_t readHcBatterySoc();

/// @brief normal button for which there is just a single press
struct button{
    uint8_t pin;
    buttonPress press_state;    // 0 => not pressed, 1 => pressed
    void (*press_callback)(void);   // callback function; to be called when the button is pressed
    int32_t cooldown;  // button cooldown period. 0 when cooldown period is over, and more than 0 when cooling down
};


/// @brief a button in which long press is allowed
struct long_press_button{
    uint8_t pin;
    buttonPress press_state; //0=> not pressed, 1=> short pressed, 3 => long pressed
    void (*short_press_callback)(void);
    void (*long_press_callback)(void);
    int32_t cooldown;
    uint32_t pressed_for;
};

/// @brief 2-state direction toggle switch on prototype; requires jitter correction due to fault
struct toggle{
    uint8_t pin;
    uint8_t state;  /// 1 when the toggle is in forward position; 0 when in reverse position
    void (*pos_0_callback)(void);   /// callback function to be triggered when toggle in position 0 (reverse)
    void (*pos_1_callback)(void);   /// callback function to be triggered when toggle in position 1 (forward)
};

struct two_pos_toggle{
    uint8_t pin_pos2;
    uint8_t pin_pos0;
    uint8_t state;
    void (*pos_0_callback)(void);   /// callback function to be triggered when toggle in position 0 (reverse)
    void (*pos_1_callback)(void);   /// callback function to be triggered when toggle in position 1 (mid)
    void (*pos_2_callback)(void);   /// callback function to be triggered when toggle in position 2 (forward)
};