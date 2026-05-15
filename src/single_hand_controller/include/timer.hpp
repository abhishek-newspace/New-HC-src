/**
 * @file timer.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * All timing functions are contained within this header file
 * 
 * <h2>changes</h2>
 * @date 06/05/2026
 * placed startTimer, timeup, and resetTimer functions into a class so that multiple timers can be made within the OFP loop
 */
#pragma once
#include "definitions.h"

class timer{
    long unsigned int current_time = 0;
    long unsigned int duration = 0;

public:
    timer(){
        duration = 0;
    }

    timer(long unsigned int intervalDuration){
        duration = intervalDuration;
    }

    /// @brief start a timer, that keeps count of number of microseconds elapsed
    void startTimer();

    /// @brief check whether time_ms microseconds are completed since start of timer
    /// @param time_ms milliseconds since start of timer
    /// @return true when time_ms microseconds are completed since start of timer.
    bool timeup(unsigned long int time_ms);

    /// @brief check whether the duration for which the timer should run is complete, and resets timer. Will always return true if intervalDuration is not set.
    /// @return true when duration is complete
    bool timeup();

    /// @brief essentially performs same task as startTimer(); used to reset the timer to 0 and start again.
    void resetTimer();


};

/// @brief get the current global time as provided by ATLAS.
/// @param UGVTime time provided by ATLAS
/// @param RecvTime time at which the packet was received
/// @param Now current time of microcontroller (kept track only by microcontroller)
/// @return global time
inline long long unsigned getGlobalTime(uint64_t UGVTime, uint64_t RecvTime, uint64_t Now){
    return UGVTime + (Now - RecvTime);
}