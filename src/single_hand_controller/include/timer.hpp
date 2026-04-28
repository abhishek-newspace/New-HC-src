/**
 * @file timer.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * All timing functions are contained within this header file
 */
#pragma once
#include "definitions.h"
#include "IOhandler.hpp"


/// @brief start a timer, that keeps count of number of microseconds elapsed
void startTimer();

/// @brief check whether time_ms microseconds are completed since start of timer
/// @param time_ms milliseconds since start of timer
/// @return true when time_ms microseconds are completed since start of timer.
bool timeup(unsigned long int time_ms);

/// @brief essentially performs same task as startTimer(); used to reset the timer to 0 and start again.
void resetTimer();

/// @brief second timer meant to be used only within the OFP loop
void startOFPTimer();

/// @brief waits until time_limit microseconds are completed since beginning of OFP timer
/// @param time_limit number of microseconds the OFP loop is meant to last for
void end_OFP_timer(unsigned long int time_limit);


/// @brief get the current global time as provided by ATLAS.
/// @param UGVTime time provided by ATLAS
/// @param RecvTime time at which the packet was received
/// @param Now current time of microcontroller (kept track only by microcontroller)
/// @return global time
inline long long unsigned getGlobalTime(uint64_t UGVTime, uint64_t RecvTime, uint64_t Now){
    return UGVTime + (Now - RecvTime);
}