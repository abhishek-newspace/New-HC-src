#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/include/radio_config.h"
#pragma once
#include "definitions.h"
/**
 * @author Nikhil Tom Jose
 * @brief functions to configure RFD915 radio on-the-go
 */

 void getRadioConfigurations();

 void waitForResponse();

 void initRadioConnection();

 void setParameter(String param, String val);

 void exitConfig();

 void performConfig();