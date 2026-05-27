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


message_sender msgsndr(buf, &msg);

uint8_t radio_status_trigger[] = {0xFE,0x9,0x31,0xFF,0xBE,0x0,0x0,0x0,0x0,0x0,0x6,0x8,0x0,0x0,0x3,0xAA,0x4F};

bool arm_request_sent = false,  //!< whether an arm request was sent (COMMAND_LONG)
    disarm_request_sent = false;  //!< whether a disarm request was sent (COMMAND_LONG)

int rssi;

unsigned long getHeartbeatDiff();

bool is_unsigned_message(const mavlink_status_t* status, uint32_t msgId) {
  return (msgId == MAVLINK_MSG_ID_TIMESYNC || msgId == MAVLINK_MSG_ID_HEARTBEAT || msgId == MAVLINK_MSG_ID_RADIO_STATUS);
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
        Serial3.write(buf[i]);
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

void sendManualControl(){
    IF_DEBUG(Serial.println("sending manual control");)
    thumbstickControl thumbstick_input;
    getXY(&thumbstick_input);
    sendBuffer(
        msgsndr.buffer_manual_control(
            thumbstick_input.X / (float)100 * 2.78 ,
            thumbstick_input.Y / (float)100 * 13.7,
            0,
            0,
            0,
            0
        )
    );
}

void handlePacketReceived()
{

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