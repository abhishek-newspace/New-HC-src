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

# Adding a new type of user output
For every new type of user output / any output coming from the microcontroller, a handler function should be created to handle the same.

Current user outputs consist of display, and radio communication, which are handled by `displayHandler.hpp` and `packetHandler.h` respectively.

# Adding new MAVLink messages
Any new MAVLink message being added to the project needs to be done with proper planning. Steps to be followed - 
1. **ICD updation** - Any change to the MAVLink message being sent or parsing a received message begins from a change in the ICD. **No changes** are meant to be made before this step.
2. **Update XML** if required. When the XML is updated, ensure that the MAVLink message fields currently being used aren't removed in the updated XML.
3. **Parser Generation** - use `mavgenerate.py` (from MAVlink official repository) to generate the parser header files for **C++11** with `validate units` enabled.
4. Compile the code once to ensure again that no field that is currently used is accidentally removed, or needs to be removed.

## For a MAVLink message that is to be sent - 
5. Define a struct for the particular message in the top half of the `message_structs.h` header file, with the exact same name as in the ICD.
6. In `message_sender.hpp` create an instance of the struct with appropriate naming, within the message_sender class.
7. declare a function of `int` return type with naming given in snake casing as - `buffer` followed by the name of the message, whatever fields need to be changed dynamically within the message that is going to be sent, must be included as a parameter for the function declaration.
8. Define the function in `message_sender.cpp`, to directly place the parameters into the message struct and when the packing function is called, **only use fields from the struct to fill in the parameters to the packing function**, except the common fields filled by *HC_ID*, *HC_COMP_ID*, and *msg*. Return the value obtained from `mavlink_msg_send_to_buffer()` function call.
9. Within `packetHandler.h`, create a function declaration for a function that is meant to send the given message. Naming convention should be given as `send` followed by the message name, in camel case, and the return type to the function must be `void`.  It may or may not be given parameters as per requirements.
10. In `packetHandler.cpp`, define the message as required along with a function call to `sendBuffer()` with the `message_sender` instance's function call to the given message to send the MAVLink message.

## For a MAVLink message that is to be received - 
5. Define a struct for the particular message in the bottom half of the `message_structs.h` header file, with the exact same name as in the ICD.
6. In `packet_receiver.hpp`, create an instance of the given struct, along with a declaration of a `static void` function to receive the given message. Naming is to be in snake casing, with `receive` followed by the message name. Parameters should just be the message received, of type `mavlink_message_t*`.
7. In `packet_receiver.cpp`, create a respective function definition that first updates the fields of the respective struct for the given message followed by handlig the data received from the message appropriately.
8. In the `handlePacketRecieved()` function within `packetHandler.cpp`, update the switch case to handle the message ID respsective to the message that is added newly.

# Adding new inputs (Buttons/toggle switches)
An input can also act similar to how a button/toggle switch operates, and can be categorized into this category.

1.  Define the input name within `IO_defs.h` and associate it with a pin number. Naming convention to be followed is - input type (toggle/button) followed by the purpose, all given in snake casing and all caps.
2. In `setupIO()` function that is defined within `setupFunctions.cpp`, configure the pin as an input, or input pullup pin.
3. create an instance of button at the top of the file in `IOhandler.cpp`, long_press_button (a button that has events that can be triggered for long presses as well as short presses), toggle, or two_pos_toggle based on the input type, in case the input is entirely new, refer the next section. Follow struct documentation to understand how to fill in the fields.
4. In `void checkUserInput()` that is defined within `IOhandler.cpp`, add a function call of `updateButtonValues()`, `updateLongPressButtonValues()`, `updateToggleValues`, or `updateTwoPosToggleValues()` based on the type of input that was created.

## creating a new input type - 
In case the type of input is not a button or a toggle switch, a new input type would be required.
1. Create a struct with naming in snake case, followed by the pins used, a variable to define its current state, and callback functions that are to be executed when their respective states are triggered.
2. In `IOhandler.cpp`, create a function with name given by 'update' followed by the type of input, all in camel case. This function is to be of `void` return type, and must accept a pointer to the struct to update the instance of the struct, and another variable `ms_since_last_check` that is to contain the number of milliseconds since the function was last called. This is included in all input update functions regardless of usage for uniformity. It is generally used to update cooldown time.

This function must also contain logic to call the respective callback function based on conditions.

# Modes for compiling code - 
## Release mode - 
This is the default mode, where no debug data is given from the serial port. Place the code in this mode to ensure that the code is going to run without extra print statements.

In `definitions.h`, uncomment `#define RELEASE` to enable Release mode.

## Debug mode - 
When a piece of code (single line) is to only execute when debugging (i.e. debug messages), mention it as `IF_DEBUG(<your code here>)`. Now whenever the code is set to run in debug mode, by commenting out `#define RELEASE` and uncommenting `#define _DEBUG_` (if not already uncommented) that are both defined within `definitions.h`, the code compiles in debug mode which allows all debug statements to print out.

In case of blocks of code that should run only in debug mode, add a line - `#ifdef _DEBUG_` at the beginning of the code block, and `#endif` towards the end of the code block.

## Radio Configuration mode - 
The radio can be set to be configured when in this mode.
Uncomment **only** `#define GET_RADIO_CONFIG` in order to startup the microcontroller in radio configuration mode, where the configurations can be managed in `void performConfig()` function that is present in `radio_config.cpp`.

## Testing modes - 
Any of these modes can be enabled by uncommenting the definition given in brackets, next to the mode name.

### Radio simulation testing mode (RADIO_SIMULATION_TESTING)
All the data that is normally sent to the radio through the dedicated serial port will be sent to the serial port for debugging so that the computer used to program the HC can directly access this data through the serial monitor.

### Testing (TESTING)
This is a temporary mode that is meant to test particular parts of the code, In this mode, the HC ignores establishing connectivity, and directly moves to the OFP Cycle.

#### Testing Joystick (TESTING_JOYSTICK)
When just the joystick data output needs to be tested.

#### stop radio communications (STOP_COMM)
Stops all data communication to the radio. This is used when testing whether certain buttons are working, without actually sending or receiving packets from radio.

#### stop radio receiving (STOP_RECV)
Stops any packets from being received on the radio communication channel.

#### print the received bytes (PRINT_BYTES)
For extended debugging of the packets being sent or received, this can be enabled

# Compiling and running the code - 
## Requirements - 
1. Arduino IDE
2. Linux OS (optional, for running shell files only)
3. avrdude (optional, for verification/downloading flashed code only)

## steps - 
1. Open Arduino IDE
2. Open `scout-td0-HC/src/single_hand_controller/single_hand_controller.ino`
3. Click on File > Preferences, or just press `ctrl + ','`
4. Update the sketchbook location to the current location of `single_hand_controller.ino`.
5. Ensure the board is connected, currently only Arduino Mega is supported for this build.
6. click on the arrow mark present on the top-left corner to compile and upload the code into the board.

****Extra****
7. In case the build files are required, run `import_build.sh`.
8. To flash code from the Build directory, run `flash_code.sh`
9. To chack whether there is a different code currently running in the hand controller than what is present in the Build directory, run `check_version_change.sh`
10. To check the data that is being printed from the debug port/serial port, run `check_serial_buffer.sh`

***Refer error_handling.md for understanding how to handle error codes displayed on screen***