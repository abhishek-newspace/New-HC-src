This document outlines the meaning behind error codes displayed on the hand controller, and how to handle/resolve them.

1. **Error code 1 : Signing Failure**

**Meaning** : Either signing of packets is disabled or there's an internal issue within the hand controller's microcontroller

**How to Resolve** : Check whether signing is disabled in `definitions.h`

2. **Error code 2 : Joystick calibration error**

*This error is no longer meant to appear; this is part of a depracated feature*

**Meaning** : There has been an issue with joystick calibration due to damage to the joystick, or the user deliberately placing the joystick to an extreme position.

**How to Resolve** : Ensure that the thumbstick is in central position during startup, if the error still occurs, then replace the thumbstick on the hand controller.

3. **Error code 3 : Arm/Disarm Failure**

**Meaning** : Either the request to arm/disarm Scout is rejected, or left without acknowledgment.

**How to Resolve** : The issue is meant to be resolved on Scout to allow for arming/disarming.

4. none

5. **Error code 5 : Radio Communication Failure**

**Meaning** : There's a communication issue between the Hand controller's microcontroller and its own radio.

**How to Resolve** : Follow these steps - 

5.1. Ensure that the configurations for the radio haven't been altered.

5.2. Open the Hand Controller, and check whether the pins are connected correctly, refer it's [datasheet](https://files.rfdesign.com.au/Files/documents/RFD900x%20DataSheet%20V1.2.pdf)

5.3. In case the radio is powered up correctly, and the Rx/Tx pins are correctly connected with the microcontroller, then the radio may be configured on radio simulation testing mode, refer `readme.md` to understand the various testing, debug, and release modes.

6. **Error code 6 : Radio Transmission Buffer Full**

**Meaning** : The serial buffer on the radio that handles transmission of data is full.

**How to Resolve** : Ensure that the radio configurations are correct as per the [datasheet](https://files.rfdesign.com.au/Files/documents/RFD900x%20DataSheet%20V1.2.pdf).

7. **Error code 7 : Time Synchronization Error / No response from Scout**

**Meaning** : There is an issue due to which Scout is not sending any response to requests from the Hand Controller, which is likely an issue with the Tx pin on Scout's radio. Or in a rare case, Time Synchronization is disabled on Scout. *Note that the issue is* **not** *on the hand controller*

**How to Resolve** : Verify the following in order - 

7.1. Check transmission buffer of the Radio on Scout for issues.

7.2. Check pin connection issue with the Radio on Scout, which could very likely be the case.

7.3. In case there are absolutely no issues between communication between ATLAS and the Scout's Radio, then the issue lies within ATLAS.

8. **Error code 8 : Emergency stop engaged**

**Meaning** : Emergency stop is engaged, no issues

**How to Resolve** : Disengage the emergency stop.

