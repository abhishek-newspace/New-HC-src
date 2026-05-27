#include"include/PeriodicActions.hpp"

int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time){
    addPeriodicAction(function, action_sleep_time,nullptr,nullptr);
}
int periodicActions::addPeriodicAction(void (*function)(void), uint32_t action_sleep_time, bool (*stopCondition)(void)){
    addPeriodicAction(function, action_sleep_time,stopCondition,nullptr);
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

    if(stopQueueHead == nullptr)
        return;

    stopActionQueue* curr_stop = stopQueueHead;
    action* curr_action, *prev_action, *temp;
    curr_action = actionsHead;
    prev_action = nullptr;


    // if head needs to be deleted is a special case
    if(curr_stop->actionID == actionsHead->actionID){
        temp = actionsHead;
        actionsHead = actionsHead->nextAction;
        delete actionsHead;
        curr_stop = curr_stop->next;
    }

    prev_action = actionsHead;
    curr_action = actionsHead->nextAction;

    while(curr_stop != nullptr && curr_action != nullptr){
        if(curr_stop->actionID == curr_action->actionID){
            // delete the action
            prev_action->nextAction = curr_action->nextAction;
            temp = curr_action;
            curr_action = curr_action->nextAction;
            delete curr_action;
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