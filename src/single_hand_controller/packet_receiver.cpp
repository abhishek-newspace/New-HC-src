/**
 * @file packet_receiver.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of packet receiver library; used in Single Hand Controller for Scout
 * Defines member functions of message_sender class
 */
#include "include/packet_receiver.hpp"

static struct ATLAS_HC_HEARTBEAT_BC packet_receiver::heartbeat;
static struct ATLAS_HC_TIMESYNC_RESP packet_receiver::timesync;
static struct HC_RADIO_STATUS packet_receiver::radio_status;
static struct ATLAS_HC_SYS_STAT packet_receiver::sys_status;
static struct ATLAS_HC_ARM_DISARM_ACK packet_receiver::ack;


uint32_t arm_start = 0, disarm_start = 0;
int requests_sent = 0;

uint64_t  UGVTime = 0, //!< stores time of the drone at which timesync was received
          RecvTime = 0,  //!< stores time at which timesync was received.
          RecvTimeRef = 0,
          latency = 0;   //!< latency of timesync packet being sent
   
unsigned long last_heartbeat_received_at = -4000;

bool receivedFirstTimesync(){
    return !(UGVTime == 0);
}

#ifdef TIME_REQ
bool isLeapYear(uint16_t y) {
  // A year is a leap year if divisible by 4, 
  // but not by 100 unless also divisible by 400.
  return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

void printWithLeadingZero(uint32_t val) {
  if (val < 10) Serial.print('0');
  Serial.print(val);
}
#endif


void packet_receiver::receive_timesync(mavlink_message_t *msg)
{
    timesync.tc1 = mavlink_msg_timesync_get_tc1(msg);
    timesync.ts1 = mavlink_msg_timesync_get_ts1(msg);
    IF_DEBUG(Serial.print("timesync_diff :"));
    IF_DEBUG(Serial.println((unsigned long)(timesync.tc1 - timesync.ts1)));

    
    
    RecvTime = UGVTime + micros() - RecvTimeRef;
    latency = (RecvTime - timesync.ts1) / 2;

    UGVTime = timesync.tc1 + latency;
    RecvTimeRef = micros();

    IF_DEBUG(Serial.print("comm latency :"));
    IF_DEBUG(Serial.println((unsigned long)(UGVTime - timesync.tc1)));


#ifdef TIME_REQ
    uint32_t seconds, minutes, hours;
    uint32_t days, year, month, day;
    uint32_t epoch = (unsigned long)((UGVTime + micros() - RecvTimeRef) / SECONDS_US_1);
    seconds = epoch % 60;
    uint32_t totalMinutes = epoch / 60;
    minutes = (totalMinutes + 30) % 60;
    uint32_t totalHours = totalMinutes / 60;
    hours = (totalHours + 5) % 24;
    
    String time = String("Time  ") + String(hours) + String (":") + String(minutes) + String(":") + String(seconds);
    clearInfo();
    displayInfo(time);
#endif
    mavlink_get_channel_status(MAVLINK_COMM_0)->signing->timestamp = UGVTime / 10;
}




void packet_receiver::receive_radio_status(mavlink_message_t *msg)
{
    radio_status.rssi = mavlink_msg_radio_status_get_rssi(msg);
    IF_DEBUG(Serial.print("rssi");)
    IF_DEBUG(Serial.println(radio_status.rssi);)
    setRSSI(radio_status.rssi);
}

void packet_receiver::receive_sys_status(mavlink_message_t *msg)
{
    sys_status.battery_remaining = mavlink_msg_sys_status_get_battery_remaining(msg);
    sys_status.drop_rate_comm = mavlink_msg_sys_status_get_drop_rate_comm(msg);
    sys_status.voltage_battery = mavlink_msg_sys_status_get_voltage_battery(msg);

    setBatterySOC(sys_status.battery_remaining);

    // display errors when drop rate or battery voltage above/below thresholds
}

void packet_receiver::receive_ack(mavlink_message_t *msg)
{
    displayInfo("ARM command acknowledged");
    resetArmDisarm();
}

void resetArmDisarm(){
    requests_sent = 0;
    disarm_start = 0;
    arm_start = 0;
}

void setArmNow()
{
    requests_sent = 1;
    arm_start = micros();
}

void setDisarmNow()
{
    requests_sent = 1;
    disarm_start = micros();
}

uint32_t get_arm_start(){
    return arm_start;
}
uint32_t get_disarm_start(){
    return disarm_start;
}

void inc_requests_sent(){
    requests_sent++;
}

int get_requests_sent(){
    return requests_sent;
}
void init_requests_sent(){
    requests_sent = 1;
}



void packet_receiver::receive_heartbeat(mavlink_message_t *msg)
{
    if(msg->sysid != SCOUT_ID || msg->compid != ATLAS_COMP_ID){
        IF_DEBUG(Serial.println("heartbeat system validation failed");)
        return;
    }
    if(mavlink_msg_heartbeat_get_custom_mode(msg) != SCOUT_HEARTBEAT_IDENTIFIER){
        IF_DEBUG(Serial.println("heartbeat system identification (custom_mode) failed");)
        return;
    }
    IF_DEBUG(Serial.println("heartbeat verified!");)
    last_heartbeat_received_at = millis();

    
    switch(mavlink_msg_heartbeat_get_system_status(msg)){
        case MAV_STATE_STANDBY:
            if(setUGV_state(standby)){
                displayUGV_status(standby);
            }
            break;
        case MAV_STATE_ACTIVE:
            if(setUGV_state(active)){
                displayUGV_status(active);
            }
        break;
        default:
        IF_DEBUG(Serial.println(mavlink_msg_heartbeat_get_system_status(msg)));
        if(setUGV_state(unknown)){
            displayUGV_status(unknown);
        }
    }
    
}


unsigned long getHeartbeatDiff(){
    return millis() - last_heartbeat_received_at;
}
