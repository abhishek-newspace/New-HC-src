#include"include/PeriodicActions.hpp"

int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time){
    return addPeriodicAction(function, action_sleep_time, nullptr, nullptr);
}
int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void)){
    return addPeriodicAction(function, action_sleep_time, stopCondition, nullptr);
}

int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void), void (*stopAction)(void)){
    function();  // execute function when first initialized
    if(actionsTail == nullptr){
        actionsTail = new action;
        actionsHead = actionsTail;
        actionsTail->actionID = 0;
    }
    else{
        actionsTail->nextAction = new action;
        actionsTail->nextAction->actionID = actionsTail->actionID + 1;
        actionsTail = actionsTail->nextAction;
    }
    actionsTail->performAction = function;
    actionsTail->intervalDuration = timer(action_sleep_time);
    actionsTail->intervalDuration.resetTimer();
    actionsTail->stopCondition = stopCondition;
    actionsTail->stopAction = stopAction;
    return actionsTail->actionID;
}

void periodicActions::performPeriodicActions(){
    deleteStoppedPeriodicActions();
    action* curr_action = actionsHead;
    while(curr_action != nullptr){
        if(curr_action->intervalDuration.timeup()){
            if(curr_action->stopCondition != nullptr && curr_action->stopCondition()){
                stopPeriodicAction(curr_action);
            }
            else if(curr_action->performAction != nullptr){
                curr_action->performAction();
            }
        }
        curr_action = curr_action->nextAction;
    }
}

void periodicActions::stopPeriodicAction(int ID){
    stopPeriodicAction(getActionWithID(ID));
}

void periodicActions::reset()
{
    action *temp;
    stopActionQueue* temp2;
    while(actionsHead != nullptr){
        temp = actionsHead;
        actionsHead = actionsHead->nextAction;
        delete temp;
    }
    while(stopQueueHead != nullptr){
        temp2 = stopQueueHead;
        stopQueueHead = stopQueueHead->next;
        delete temp2;
    }
    actionsHead = nullptr;
    actionsTail = nullptr;
    stopQueueHead = nullptr;
    stopQueueTail = nullptr;
}

action *periodicActions::getActionWithID(int ID)
{
    action* curr_action = actionsHead;
    while(curr_action != nullptr && curr_action->actionID != ID){
        curr_action = curr_action->nextAction;
    }
    return curr_action;
}

void periodicActions::stopPeriodicAction(action* stopAction){
    if(stopAction == nullptr)
        return;
    if(stopQueueTail == nullptr){
        stopQueueTail = new stopActionQueue;
        stopQueueHead = stopQueueTail;
        stopQueueTail->actionID = stopAction->actionID;
    }
    else{
        stopQueueTail->next = new stopActionQueue;
        stopQueueTail = stopQueueTail->next;
        stopQueueTail->actionID = stopAction->actionID;
    }

    if(stopAction->stopAction != nullptr){
        stopAction->stopAction();
    }
}

void periodicActions::deleteStoppedPeriodicActions(){

    if(stopQueueHead == nullptr || actionsHead == nullptr)
        return;

    stopActionQueue* curr_stop = stopQueueHead;
    action* curr_action, *prev_action, *temp;

    while(curr_stop != nullptr && actionsHead != nullptr &&
          curr_stop->actionID == actionsHead->actionID){
        temp = actionsHead;
        actionsHead = actionsHead->nextAction;
        delete temp;
        curr_stop = curr_stop->next;
    }

    if(actionsHead == nullptr){
        actionsTail = nullptr;
        stopQueueHead = nullptr;
        stopQueueTail = nullptr;
        return;
    }

    prev_action = actionsHead;
    curr_action = actionsHead->nextAction;

    while(curr_stop != nullptr && curr_action != nullptr){
        if(curr_stop->actionID == curr_action->actionID){
            prev_action->nextAction = curr_action->nextAction;
            temp = curr_action;
            curr_action = curr_action->nextAction;
            if(temp == actionsTail)
                actionsTail = prev_action;
            delete temp;
            curr_stop = curr_stop->next;
        }
        else{
            prev_action = curr_action;
            curr_action = curr_action->nextAction;
        }
    }
    stopQueueHead = nullptr;
    stopQueueTail = nullptr;
}
