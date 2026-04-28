#pragma once
/**
 * @file standard_procedures.hpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 28/04/2026
 * @brief set of functions to represent phases within the main control loop of the microcontroller in the hand controller.
 */
#include "definitions.h"
#include "includes.h"


/// @brief identify controller drift and calibrate controller for further use
void initiateController();

/// @brief establish connectivity with Scout, by waiting for heartbeat
void establish_connectivity();

/// @brief synchronize time with ATLAS compute of Scout
void time_synchronize();

/// @brief run through the OFP cycle once.
void run_OFP_cycle();


