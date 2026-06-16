/**
 * @file packetHandler.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of packet handler library.
 * Defines variables and functions used in packetHandler.h
*/

#include "include/packetHandler.h"

mavlink_status_t* status_chan;
mavlink_signing_t signing; 
mavlink_signing_streams_t signing_streams; 

byte buf[300];  //!< buffer to store serialized mavlink data

mavlink_status_t  status;    //!< used to check parsing status
mavlink_message_t msg;

extern speedToggle requested_spd;

message_sender msgsndr(buf, &msg);


bool arm_request_sent = false,  //!< whether an arm request was sent (COMMAND_LONG)
    disarm_request_sent = false;  //!< whether a disarm request was sent (COMMAND_LONG)

int rssi;

unsigned long getHeartbeatDiff();

bool is_unsigned_message(const mavlink_status_t* status, uint32_t msgId) {
  return (msgId == MAVLINK_MSG_ID_TIMESYNC || msgId == MAVLINK_MSG_ID_HEARTBEAT || msgId == MAVLINK_MSG_ID_RADIO_STATUS || msgId == 77);
}

bool setupSigning(){


#ifdef SIGN_PACKETS
    memset(&signing, 0, sizeof(signing)); // ensure no garbage values
    signing.flags = MAVLINK_SIGNING_FLAG_SIGN_OUTGOING; 
    memcpy(signing.secret_key, signing_key, 32);  // set signing key

    signing_streams.num_signing_streams = 0;

    signing.link_id = 0;           // setting unique ID
    signing.timestamp = 0;         // Current time in 10us units
    signing.accept_unsigned_callback = is_unsigned_message; // list of functions which don't require signing
    status_chan = mavlink_get_channel_status(MAVLINK_COMM_0);
    status_chan->signing = &signing;

    IF_DEBUG(Serial.print("set up signing, current flags ->");)
#endif
    IF_DEBUG(Serial.println(mavlink_get_channel_status(MAVLINK_COMM_0)->flags);)

#ifdef BYPASS_NO_SIGNING
    return true;
#endif
    return !(status_chan == nullptr);
}

void initiateSerialComm(){
    Serial3.begin(BAUD_RATE);
}

bool heartbeat_timed_out()
{
    if(getHeartbeatDiff() > HEARTBEAT_TIMEOUT){
        //IF_DEBUG(Serial.println(getHeartbeatDiff()));
        return true;
    }
    else 
        return false;

}


void sendBuffer(int len){
    //IF_DEBUG(Serial.print("current flags ->");)
    //IF_DEBUG(Serial.println(mavlink_get_channel_status(MAVLINK_COMM_0)->flags);)
    IF_PRINT_BYTES(Serial.print("sending -> "));
    for(int i = 0; i < len; i++){
        IF_PRINT_BYTES(Serial.print("0x");)
        IF_PRINT_BYTES(Serial.print(buf[i],HEX));
        IF_PRINT_BYTES(Serial.print(",");)
        #ifndef STOP_COMM
        Serial3.write(buf[i]);
        #endif
    }
    IF_PRINT_BYTES(Serial.println("");)
}

void sendHeartbeat(){
    IF_DEBUG(Serial.println("---sending heartbeat!---");)
    sendBuffer(msgsndr.buffer_heartbeat());
}

void sendComponentVersion()
{
    IF_DEBUG(Serial.println("---sending component version!---");)
    sendBuffer(msgsndr.buffer_component_version());
}


void sendTimesyncRequest()
{
    IF_DEBUG(Serial.println("---sending timesync request!---");)
    sendBuffer(msgsndr.buffer_timesync());
}

void sendArmCommand(){
    IF_DEBUG(Serial.println("\\\\\\\\\\\\\\\\\\\\\\\\\\ARM\\\\\\\\\\\\\\");)
    sendBuffer(msgsndr.buffer_arm_disarm_cmd(1));
}

void sendDisarmCommand(){
    IF_DEBUG(Serial.println("///////////////////////////DISARM//////////");)
    sendBuffer(msgsndr.buffer_arm_disarm_cmd(0));
}

void sendHeadlight(){
    // sendBuffer(msgsndr.buffer_light_control_cmd(0,0,0));
    // return;
    IF_DEBUG(Serial.println("+++++++++++++HEADLIGHT");)
    if(headlight_off()){
        
        setHeadlighState(1);
        if(foglight_off()){
            sendBuffer(msgsndr.buffer_light_control_cmd(1,0,1));
        }
        else{
            sendBuffer(msgsndr.buffer_light_control_cmd(1,1,1));
        }
    }
    else{
        setHeadlighState(0);
        if(foglight_off()){
            sendBuffer(msgsndr.buffer_light_control_cmd(0,0,0));
        }
        else{
            sendBuffer(msgsndr.buffer_light_control_cmd(0,1,0));
        }
    }
}

/// @brief send a request to turn on brake light and fog light
void sendFogBrakeLight(){
    // sendBuffer(msgsndr.buffer_light_control_cmd(1,1,1));
    // return;
    IF_DEBUG(Serial.println("---------------FOGLIGHT");)
    if(headlight_off()){
        
        if(foglight_off()){
            setFoglightState(1);
            sendBuffer(msgsndr.buffer_light_control_cmd(0,1,0));
        }
        else{
            setFoglightState(0);
            sendBuffer(msgsndr.buffer_light_control_cmd(0,0,0));
        }
    }
    else{
        
        if(foglight_off()){
            setFoglightState(1);
            sendBuffer(msgsndr.buffer_light_control_cmd(1,1,1));
        }
        else{
            setFoglightState(0);
            sendBuffer(msgsndr.buffer_light_control_cmd(1,0,1));
        }
    }   
}

/// @brief send a request to turn off headlight
void sendHeadlight_OFF(){
    setHeadlighState(0);
    IF_DEBUG(Serial.println("sending headlight turn off request");)
        sendBuffer(msgsndr.buffer_light_control_cmd(0,0,0));
}

/// @brief send a request to turn off brake light and fog light
void sendFogBrakeLight_OFF(){
    setFoglightState(0);
    IF_DEBUG(Serial.println("sending foglight turn off request");)
        sendBuffer(msgsndr.buffer_light_control_cmd(0,0,0));
}

/// @brief send request to set speed to required speed
void sendSpeedChangeRequest(){
    IF_DEBUG(Serial.print("sending speed change request : ");)
    sendBuffer(msgsndr.buffer_mode_cmd(get_inc_speed() + 1));
    IF_DEBUG(Serial.println(get_inc_speed() + 1);)
}

void sendModeChangeRequest(){
    IF_DEBUG(Serial.print("sending drive mode change request : ");)
    msgsndr.buffer_drive_mode_cmd(get_inc_driveMode() + 1);
    IF_DEBUG(Serial.println(get_inc_driveMode() + 1);)
}

void sendManualControl(){
    IF_DEBUG(Serial.println("sending manual control");)
    thumbstickControl thumbstick_input;
    getXY(&thumbstick_input);
    
    sendBuffer(
        msgsndr.buffer_manual_control(
            thumbstick_input.X,
            thumbstick_input.Y,
            0,
            0,
            0,
            0
        )
    );
}

void handlePacketReceived()
{
    #ifdef STOP_RECV
        return;
    #endif

    byte data;
    IF_PRINT_BYTES(Serial.print("receiving->");)
    while(Serial3.available()){
        data = Serial3.read();
        IF_PRINT_BYTES(Serial.print("0x");)
        IF_PRINT_BYTES(Serial.print(data,HEX);)
        IF_PRINT_BYTES(Serial.print(",");)
        if (mavlink_parse_char(MAVLINK_COMM_0, data, &msg, &status)) {
            IF_DEBUG(Serial.print("received message ID : ");)
            IF_DEBUG(Serial.println(msg.msgid);)
            switch(msg.msgid){

            case MAVLINK_MSG_ID_TIMESYNC: // used for syncing and identifying latency in communication, on the drone's side.
                IF_DEBUG(Serial.println("received timesync");)
                packet_receiver::receive_timesync(&msg);
            break;

            case MAVLINK_MSG_ID_RADIO_STATUS:
                IF_DEBUG(Serial.println("received radio"));
                packet_receiver::receive_radio_status(&msg);
             break;

            case MAVLINK_MSG_ID_HEARTBEAT:
                IF_DEBUG(Serial.println("((((((((((((((((((((received heartbeat))))))))))))))))"));
                packet_receiver::receive_heartbeat(&msg);
            break;
            case MAVLINK_MSG_ID_SYS_STATUS: 
                IF_DEBUG(Serial.println("received system status"));
                packet_receiver::receive_sys_status(&msg);
                break;
            case MAVLINK_MSG_ID_COMMAND_ACK:
                IF_DEBUG(Serial.println("++++++++++++++++++received command ack"));
                packet_receiver::receive_ack(&msg);
                break;
            }
        }
        // else if(status.parse_state == 14)
        //     IF_DEBUG(Serial.println("failed CRC");)

        
    }
    
        
    IF_PRINT_BYTES(Serial.println(""));
}