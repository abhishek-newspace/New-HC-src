#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/PeriodicActions.hpp"
/**
 * @file PeriodicActions.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 13/05/2026
 * @brief Run functions periodically
 */
#pragma once
#include "timer.hpp"

/**
 * @struct action
 * defines all the variables required to
 * 
 * 1. know when to perform the action
 * 2. know when to stop performing the action
 * 3. action to perform as the periodic action is stopped
 * 4. 
 */
struct action{
    timer intervalDuration;
    int actionID;
    bool (*stopCondition)() =  nullptr;
    void (*performAction)(void) =  nullptr;
    void (*stopAction)(void) =  nullptr;
    action* nextAction =  nullptr;
};

struct stopActionQueue{
    int actionID;
    stopActionQueue* next = nullptr;
};

/**
 * @class periodicActions
 * When functions need to be called periodically, it can be added to an instance of periodicActions
 */
class periodicActions{
    action* actionsHead;
    action* actionsTail;
    stopActionQueue* stopQueueHead;
    stopActionQueue* stopQueueTail;
    
public:
    /// @brief make a function to be executed periodically
    /// @param action function to be periodically executed
    /// @param action_sleep_time time interval for the periodic function to execute
    /// @return ID of the periodic function; required when calling stopPeriodicAction
    int addPeriodicAction(void (*function)(void), uint32_t action_sleep_time);

    /// @brief make a function to be executed periodically with a condition based on which the function should stop executing
    /// @param action function to be periodically executed
    /// @param action_sleep_time time interval for the periodic function to execute
    /// @param stopCondition condition based on which the function should stop executing periodically.
    /// @return ID of the periodic function; required when calling stopPeriodicAction
    int addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void));

    /// @brief make a function to be executed periodically with a condition for stopping, and a function to be executed when stopping
    /// @param action function to be periodically executed
    /// @param action_sleep_time time interval for the periodic function to execute
    /// @param stopCondition condition based on which the function should stop executing periodically.
    /// @param stopAction function to be executed when the periodic function stops executing
    /// @return ID of the periodic function; required when calling stopPeriodicAction
    int addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void), void (*stopAction)(void));

    /// @brief add the action to the stop action queue
    /// @param id ID of the action that needs to be stopped. Is returned by addPeriodicAction when called.
    void stopPeriodicAction(action* stopAction);

    /// @brief add the action id to the stop action queue
    /// @param id ID of the action that needs to be stopped. Is returned by addPeriodicAction when called.
    void stopPeriodicAction(int ID);

    /// @brief delete all periodic actions and reset.
    void reset();
    /// @brief get pointer to the action with given ID
    /// @param ID ID of action
    /// @return pointer to the action struct, however returns nullptr if action with given ID doesn't exist
    action* getActionWithID(int ID);

    /// @brief used to delete all the actions that are currently stopped
    void deleteStoppedPeriodicActions();
    
    /// @brief Function to be called by user, to check and execute periodic functions that need to be executed
    void performPeriodicActions();
};