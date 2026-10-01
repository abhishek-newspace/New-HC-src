#include"include/PeriodicActions.hpp"

int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time){
    return addPeriodicAction(function, action_sleep_time,nullptr,nullptr);
}
int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void)){
    return addPeriodicAction(function, action_sleep_time,stopCondition,nullptr);
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

    actionsTail->stopCondition = stopCondition;
    actionsTail->stopAction = stopAction;
    return actionsTail->actionID;
}

void periodicActions::performPeriodicActions(){
    deleteStoppedPeriodicActions();
    int activeActions = 0;
    action* curr_action = actionsHead;  
    while(curr_action != nullptr){
        activeActions++;
        if(curr_action->intervalDuration.timeup()){
            if(curr_action->stopCondition != nullptr && curr_action->stopCondition()){
            //IF_DEBUG(Serial.println("STOPPING action!");)
                stopPeriodicAction(curr_action);
                curr_action = curr_action->nextAction;
                continue;
            }
            //IF_DEBUG(Serial.println("performing action!");)
            curr_action->performAction();
        }
        curr_action = curr_action->nextAction;
    }
    // IF_DEBUG(Serial.print("currently active actions : "));
    // IF_DEBUG(Serial.println(activeActions);)
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
    action* curr_action;
    curr_action = actionsHead;
    while(curr_action != nullptr && curr_action->actionID != ID){
        curr_action = curr_action->nextAction;
    }
    return curr_action;
}

void periodicActions::stopPeriodicAction(action* stopAction){
    //IF_DEBUG(Serial.println("+=+= STOP ACTION ADDING ... ");)
    if(stopAction == nullptr)
        return;
    // update tail of the queue
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

    // execute stop action
    if(stopAction->stopAction != nullptr){
        stopAction->stopAction();
    }
    //IF_DEBUG(Serial.println("+=+= STOP ACTION ADDED ");)
}

void periodicActions::deleteStoppedPeriodicActions(){

    while(stopQueueHead != nullptr){
        stopActionQueue* curr_stop = stopQueueHead;
        action* prev_action = nullptr;
        action* curr_action = actionsHead;

        while(curr_action != nullptr && curr_action->actionID != curr_stop->actionID){
            prev_action = curr_action;
            curr_action = curr_action->nextAction;
        }

        if(curr_action != nullptr){
            if(prev_action == nullptr)
                actionsHead = curr_action->nextAction;
            else
                prev_action->nextAction = curr_action->nextAction;
            if(curr_action == actionsTail)
                actionsTail = prev_action;
            delete curr_action;
        }

        stopQueueHead = curr_stop->next;
        delete curr_stop;
    }
    stopQueueTail = nullptr;
}