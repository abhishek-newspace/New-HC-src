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
5. Within `standard_procedures.cpp`, defined `bool switchMode = false;`. This variable is used to enable sending the switch drive mode request.
6. 



