/**
 * @file packetHandler.h
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * Handles all incoming communication over UART, from the hand controller radio
 * 
 * <h2>changes</h2>
 * @date 06/05/2026
 * added functions for arm, disarm and sending heartbeat
 * @date 07/05/2026
 * added function to send component version
 */
#pragma once
#include "definitions.h"
#include "message_structs.h"
#include "message_sender.hpp"
#include "packet_receiver.hpp"
#include "displayHandler.hpp"
#include "IOhandler.hpp"



/// @brief sets up signing for all MAVLink packets
/// @return true when signing is successfully setup
bool setupSigning();

/// @brief check whether heartbeat has not been received within HEARTBEAT_TIMEOUT microseconds (3 seconds)
/// @return true when timeout has occured
bool heartbeat_timed_out();

/// @brief handle any packet that is received and send to packet_receiver
void handlePacketReceived();

/// @brief send a timesync request
void sendTimesyncRequest();

/// @brief send manual control packet
void sendManualControl();

/// @brief initiates serial communication with radio to send MAVLink packets; baud rate for serial communication is set in definitions.h
void initiateSerialComm();

/// @brief send an arm request
void sendArmCommand();

/// @brief send a disarm request
void sendDisarmCommand();

/// @brief send a heartbeat
void sendHeartbeat();

/// @brief send a request to turn on headlight
void sendHeadlight();

/// @brief send a request to turn on brake light and fog light
void sendFogBrakeLight();

/// @brief send request to set speed to required speed
void sendSpeedChangeRequest(int speed);

/// @brief send a request to switch mode
void sendModeChangeRequest();

void getRadioConfigurations();

/// @brief send a request for emergency stop
/// @param enable whether to engage an emergency stop or to disengage the emergency stop
void sendEstopRequest(bool enable);

#ifndef DEPRECATED_REV_1
/// @brief send component version
void sendComponentVersion();
#endif
