/**
 * @file includes.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * all the header files that are included within the main file
 */
#pragma once
#include "definitions.h"    // contains all required definitions used by all other header files.

// complete setup
#include "setupFunctions.h" // setup of all required headers

// header files for handling MAVLink packets
#include "packetHandler.h"  // receiving and sending of packets to and from buffer
#include "packet_receiver.hpp"  // processing of received packets
#include "message_sender.hpp"   // packing data into buffer and sending

#include "timer.hpp"    // handles timing within loop

#include "IOhandler.hpp"    // sending and receiving data between input, output ports
#include "displayHandler.hpp"   // displays anything meant to be displayed on LCD screen
#include "stateHandler.hpp" // handles state of connection, and speed