#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/radio_config.h"
#pragma once
#include "definitions.h"
/**
 * @author Nikhil Tom Jose
 * @brief functions to configure RFD915 radio on-the-go
 */

/// @brief get all the radio configurations/properties of the locally connected radio
void getRadioConfigurations();

/// @brief get all the radio configurations/properties of the remotely connected radio
void getRemoteRadioConfigurations();

/// @brief wait for an "OK" from the radio
void waitForResponse();

/// @brief switch the radio to the radio configuration mode
void initRadioConnection();

/// @brief exit configuration mode
void exitConfig();

/// @brief set a given value for a parameter in the configuration
/// @param param name of the parameter that is to be configured
/// @param val value to be given to the particular configuration
void setParameter(String param, String val);

/// @brief essentially the main function within this header
void performConfig();

/// @brief write all user configurable parameters to the radios (remote + local)
void writeParameters();

/// @brief reboot both radios (remote + local)
void rebootRadio();

void requestParam(String param);    