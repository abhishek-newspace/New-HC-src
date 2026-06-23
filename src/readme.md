\mainpage

Application entry point is in `single_hand_controller/single_hand_controller.ino`

All header files are defined in `single_hand_controller/include/includes.h`

## Procedure for editing any file - 
1. Review documentation for existing functionality, in order to ensure new functionality being added doesn't clash with existing functionality.

2. Check ammendment history of the given file, in case the similar functionality existed in a previous version, then verify why it was removed, and the functionality can be brought back from git commit history

3. Edit file and track all the edits made to the given file

4. Update file header comments (date, author, version number, description, and ammendment history. Add the history in case it doesn't exist)



# Mode/State change - 

## How to add new modes/states - 

Currently implemented modes and states include speed, arm/disarm, headlight, foglight, etc.
Out of these, arm/disarm state is not managed by the hand controller, however rest are managed by the hand controller.

1. The current state is always maintained in `stateHandler.cpp`. Hence create a variable to maintain the state and place it in `stateHandler.cpp`.
2. For each state, 2 functions are absolutely necessary are -
    1. **getter function** - a function to return the current state.
    2. **state modification function** - a function to manage how the state is modified.
3. Create function declarations for the newly defined functions in `stateHandler.hpp`
4. Wherever the state is required to be modified, use only the functions present in `stateHandler` to modify the state.


## State modification logic, through I/O and requests - 
State is generally modified through a request that is sent from the controller followed by an acknowledgment that lets the controller to know that it is ok to transition to thr given state. 

Hence an *enable* variable is declared in `standard_procedures.cpp`, which is checked to know whether to send a state change request within the next OFP cycle, or not. Within the file that actually requires to initiate the state change (i.e. `IOhandler.cpp`, if a button press is meant to actually cause the state change) the variable is declared as an `extern`, so that the required function can easily modify the *enable* variable.

## Put into practice - 
This is how drive mode state is handled - 
1. `driveMode current_mode = speed;` is defined in `stateHandler.cpp`
2. `int getDriveMode()` is defined to get the current drive mode, `void switchDriveMode()` is defined to switch between the current drive modes (since there are only 2 drive modes). `get_inc_driveMode()` is used to get the next drive mode, just as another function to be able to define the 
3. The 3 functions are declared and documented in `stateHandler.hpp`.
4. within `packetHandler.hpp`, MAV_DRIVE_MODE acknowledgment causes a drive mode change by invoking the `switchDriveMode()` function.
5. Within `standard_procedures.cpp`, defined 
```C++
bool switchMode = false;
```
This variable is used to initiate a mode switch.
6. Within `standard_procedures.cpp`, added this function to check whether the drive mode needs to be changed - 
```C++
inline bool switchModeCondition(){
    return switchMode;
}
```
Then, this code block is added within `run_OFP_cycle()` - 
```C++
if(switchModeCondition()){
    sendModeChangeRequest();
    switchMode = false;
}
```
to send a mode change request.

7. When the acknowledgment for mode change arrives, the display of current mode should be changed, hence within the packet_receiver.cpp, `switchDriveMode();` is called on receiving an acknowledgment. This function is defined within `stateHandler.cpp` as - 
```cpp
void switchDriveMode(){
    current_mode = (current_mode + 1) % 2;
    displayDriveMode(current_mode);
}
```

in order to switch the drive mode display, as well as change the internal state for the current drive mode.

# Changing/Updating Display - 
All functions that deal with display are declared in `displayHandler.hpp` and are defined in `displayHandler.cpp`. Further, definitions that deal with color and position of the displayed item is defined in `definitions/display_defs.h`.

`displayHandler.hpp` is included in `stateHandler.cpp`, hence these functions defined here are meant to be called within `stateHandler.cpp` in order to update the display.

## Adding a new display item - 
1. Identify the handler associated with the display item. i.e. if the button state needs to be displayed, then `IOhandler.hpp` is the associated handler.
2. There are 2 ways of the display being updated -
    1. **Direct Updates** - when the change needs to be instantly, use this method. A function is called to directly update the given item in display.
    2. **Periodic Updates** - Some items don't need to reflect instantly, i.e. battery status, radio connectivity, etc. For such items, make a function to update its current state, which is called by the associated handler when necessary. These items are updated along with a function call of `updateDisplay()`

## Displaying items with direct updates
1. create a function with naming in camel casing given by *display* followed by the parameter that needs to be displayed, i.e. if *speed* is the parameter that needs to be displayed, then the function declaration should look like - 
```cpp
void displaySpeed(int speed);
```
Ensure the function declaration in `displayHandler.hpp`.

2. The function definition can be as required, however ensure that the position of the item can be changed easily, by defining a `POS_X` and `POS_Y` for the same. Further, if it's a figure that is being displayed, also ensure that the figure's scale can be easily modified through parameters that should all be modifiable from within `display_defs.h`
3. Use this function call wherever the particular display item needs to be updated.

## Displaying items with periodic updates
When items need to be updated periodically, 
1. make a variable to handle the state, and functions to **only update** the state variable.
2. make a function to display the given item, of `void` return type.
3. Within `updateDisplay()`, create a static variable to maintain the previous state of the display item to check whether it should really be updated.
4. within `updateDisplay()` function, add function call to the function to display the item, after checking for updates in state. 

Example for battery updates - 
```cpp
static int prevBattery = 0;
if(ugv_battery_soc != prevBattery)
    displayBattery();

prevBattery = ugv_battery_soc;
```

## Items that are to only be displayed once
Some items only need to be displayed once, on startup (i.e. logo, and placeholders). Place holder displaying functions are to be called within `displayBasic()` function, and other items that are to be displayed absolutely only once are to be called in `setupDisplay()`




