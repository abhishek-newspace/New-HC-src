/**
 * @file IOhandler.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * Any interfacing with input/output pins of the microcontroller is taken care of, within this header file, except handling display output, which is done by the displayHandler
 * 
 * <h2>Changes</h2>
 * @date 28/04/2026
 * - Modified struct to inclued cooldown period, so that when the button is pressed and released, the next press is only registered after the cooldown period
 * - modified struct to include callback functions to increase, decrease and set speed to neutral
 */
#pragma once
#include "definitions.h"
#include "stateHandler.hpp"

#define SPEED_HIGH
#define SPEED_MID

#define DIR_FORWARD
#define DIR_REVERSE

/// @brief thumbstick control is used within this library
struct thumbstickControl{
    int X, Y;
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

/// @brief whether arm/disarm button is pressed or not
/// @return true when arm/disarm button is pressed
bool arm_pressed();


/// @brief whether arm/disarm button is long pressed or not
/// @return true when arm/disarm button is long pressed
bool arm_long_pressed();


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
    /**
     * @brief This is waiting period to confirm 1 as the state.
     * 
     * when the state is 0, and 0 is the state that is read, then toggled_at is set to 0
     * 
     * when the state is 0, and 1 is the state that is read while toggled_at is 0, then toggled_at is set to micros();
     * 
     * when the state is 0, and 1 is the state that is read while toggled_at is more than 0, then if micros() - toggled_at > 1 second, then state is set to 1.
     * 
     * when the state is 1 and 0 is the state that is read, then toggled_at is set to 0, and state is set to 0.
     */
    uint32_t toggled_at;

    void (*pos_0_callback)(void);   /// callback function to be triggered when toggle in position 1 (forward)
    void (*pos_1_callback)(void);   /// callback function to be triggered when toggle in position 0 (reverse)
};
