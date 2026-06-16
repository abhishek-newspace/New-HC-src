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