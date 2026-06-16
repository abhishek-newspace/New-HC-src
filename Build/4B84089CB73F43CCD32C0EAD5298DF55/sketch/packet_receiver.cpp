#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/packet_receiver.cpp"
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



uint64_t  UGVTime = 0, //!< stores time of the drone at which timesync was received
          RecvTime = 0,  //!< stores time at which timesync was received.
          RecvTimeRef = 0,
          latency = 0;   //!< latency of timesync packet being sent
   
unsigned long last_heartbeat_received_at = -4000;

int arm_send_count = 0;

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
    clearInfo();

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
    radio_status.remrssi = mavlink_msg_radio_status_get_remrssi(msg);
    radio_status.txbuf = mavlink_msg_radio_status_get_txbuf(msg);
    
    // IF_DEBUG(Serial.print("rssi");)
    // IF_DEBUG(Serial.println(radio_status.rssi);)

    // IF_DEBUG(Serial.print("rem rssi");)
    // IF_DEBUG(Serial.println(radio_status.remrssi);)

    IF_DEBUG(Serial.print("tx buffer:");)
    IF_DEBUG(Serial.println(radio_status.txbuf);)

    if(radio_status.txbuf <= 10)
        displayError("Tx Buffer overload",RADIO_BUFFER_OVERLOAD);
    
    if(radio_status.remrssi > 0)
        connectRadio();
    else{    
        disconnectRadio();
        if(setUGV_state(disconnected)){
            displayUGV_status(disconnected);
        }
    }
        
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
    switch(mavlink_msg_command_ack_get_command(msg)){
        case MAV_CMD_COMPONENT_ARM_DISARM:
            displayInfo("ARM command acknowledged");
            arm_send_count = 0;
        break;
        case MAV_CMD_DRIVE_MODE:
            switchDriveMode();
            
            IF_DEBUG(Serial.println("drive mode switch acknowledged");)
        break;
        case MAV_CMD_DO_SET_MODE:
            inc_Speed();
            IF_DEBUG(Serial.println("speed mode acknowledged");)
        break;
        case MAV_CMD_LIGHT_CONTROL:
            IF_DEBUG(Serial.println("light control acknowledged");)
            
        break;
    }
    
}


void packet_receiver::receive_heartbeat(mavlink_message_t *msg)
{

    /*
     heartbeat_speed bitmask - 
        0000000000000000000000000000000011
    heartbeat light bitmask
        headlight - 
        0000000000000000000000000000000100

        foglight - 
        0000000000000000000000000000001000

        brakelight - 
        0000000000000000000000000000010000
    */
    if(msg->sysid != SCOUT_ID || msg->compid != ATLAS_COMP_ID){
        IF_DEBUG(Serial.println("heartbeat system validation failed");)
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
        //IF_DEBUG(Serial.println(mavlink_msg_heartbeat_get_system_status(msg)));
        if(setUGV_state(unknown)){
            displayUGV_status(unknown);
        }
    }
    
}


unsigned long getHeartbeatDiff(){
    return millis() - last_heartbeat_received_at;
}

bool is_arm_disarm_sending(){
    return arm_send_count > 0;
}
void reset_arm_disarm_sending(){
    arm_send_count = 0;
}
void init_arm_disarm_sending(){
    arm_send_count = 1;
}

void dec_arm_disarm_sending(){
    arm_send_count--;
}