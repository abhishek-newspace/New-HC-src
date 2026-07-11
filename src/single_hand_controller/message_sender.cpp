/**
 * @file message_sender.cpp
 * @version 0.1
 * @author Nikhil Tom Jose
 * @date 22/04/2026
 * 
 * Part of message sender library.
 * Defines member functions of message_sender class
 */
#include "include/message_sender.hpp"

extern uint64_t UGVTime,RecvTime, RecvTimeRef;
extern mavlink_status_t* status_chan;

int message_sender::buffer_arm_disarm_cmd(bool state)
{
    if(state)
        arm_disarm_cmd.param1 = 1;  // arm
    else
        arm_disarm_cmd.param1 = 2;  // disarm

    mavlink_msg_command_long_pack(
        HC_ID,
        HC_COMP_ID,
        msg,

        arm_disarm_cmd.target_system,
        arm_disarm_cmd.target_component,
        arm_disarm_cmd.command,
        arm_disarm_cmd.confirmation,
        arm_disarm_cmd.param1,
        arm_disarm_cmd.param2,
        0,0,0,0,0);

    return mavlink_msg_to_send_buffer(buf,msg);
}

int message_sender::buffer_light_control_cmd(bool headlight, bool foglight, bool brakelight)
{

    light_ctrl_cmd.param1 = headlight;
    light_ctrl_cmd.param2 = foglight;
    light_ctrl_cmd.param3 = brakelight;

    mavlink_msg_command_long_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        light_ctrl_cmd.target_system,
        light_ctrl_cmd.target_component,
        light_ctrl_cmd.command,
        light_ctrl_cmd.confirmation,
        light_ctrl_cmd.param1,
        light_ctrl_cmd.param2,
        light_ctrl_cmd.param3,
        0,0,0,0
    );
    return mavlink_msg_to_send_buffer(buf, msg);
}
int message_sender::buffer_mode_cmd(int speed)
{
    mode_cmd.param3 = speed;
    mavlink_msg_command_long_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        mode_cmd.target_system,
        mode_cmd.target_component,
        mode_cmd.command,
        mode_cmd.confirmation,
        mode_cmd.param1,
        mode_cmd.param2,
        mode_cmd.param3,
        0, 0,0,0
    );
    return mavlink_msg_to_send_buffer(buf, msg);
}

int message_sender::buffer_drive_mode_cmd(int mode)
{
    drive_cmd.param1 = mode;
    mavlink_msg_command_long_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        drive_cmd.target_system,
        drive_cmd.target_component,
        drive_cmd.command,
        drive_cmd.confirmation,
        drive_cmd.param1,
        0,0,0,0,0,0
    );
    return mavlink_msg_to_send_buffer(buf, msg);
}

int message_sender::buffer_heartbeat()
{
    uint8_t prevFlags = mavlink_get_channel_status(MAVLINK_COMM_0)->flags;  
    mavlink_get_channel_status(MAVLINK_COMM_0)->flags = MAVLINK_STATUS_FLAG_OUT_MAVLINK1;  
    
    mavlink_msg_heartbeat_pack(
        heartbeat.sys_id,
        heartbeat.comp_id,
        msg,
        heartbeat.type,
        heartbeat.autopilot,
        heartbeat.base_mode,
        heartbeat.custom_mode,
        heartbeat.system_status);

    mavlink_get_channel_status(MAVLINK_COMM_0)->flags = prevFlags;
    return mavlink_msg_to_send_buffer(buf,msg);
}


int message_sender::buffer_timesync()
{
    if(RecvTimeRef == 0)    // during first timesync
        RecvTimeRef = micros();
    
    timesync.ts1 = UGVTime + (micros() - RecvTimeRef);
        
    mavlink_msg_timesync_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        timesync.tc1,
        timesync.ts1,
        timesync.target_sys,
        timesync.target_comp
    );

    return mavlink_msg_to_send_buffer(buf,msg);
}


int message_sender::buffer_manual_control(int x, int y, bool extra_feature_1_press, bool extra_feature_1_long_press, bool extra_feature_2_press, bool extra_feature_2_long_press)
{
    manual_control.x = x;
    manual_control.y = y;
    manual_control.Push_buttons = extra_feature_1_press | extra_feature_1_long_press << 1 | extra_feature_2_press << 2 | extra_feature_2_long_press << 3;

    mavlink_msg_manual_control_pack(
        HC_ID,
        HC_COMP_ID,
        msg,

        manual_control.target,
        manual_control.x,
        manual_control.y,
        manual_control.z,
        manual_control.r,
        manual_control.Push_buttons,
        //manual_control.Tristate_Toggle_switches
        0,0,0,0,0,0,0,0,0, 0
    );

    return mavlink_msg_to_send_buffer(buf,msg);
}

int message_sender::buffer_remote_emergency_cmd(bool engage){
    if(engage){
        estop_cmd.param1 = 2;
    }
    else{
        estop_cmd.param1 = 1;
    }
    
    mavlink_msg_command_long_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        estop_cmd.target_system,
        estop_cmd.target_component,
        estop_cmd.command,
        estop_cmd.confirmation,
        estop_cmd.param1,
        0,0,0,0,0,0
    );
    return mavlink_msg_to_send_buffer(buf, msg);

}

#ifndef DEPRECATED_REV_1
int message_sender::buffer_component_version()
{
    mavlink_msg_ugv_component_version_pack(
        HC_ID,
        HC_COMP_ID,
        msg,
        
        component_version.software_version,
        component_version.checksum,
        component_version.target_system,
        component_version.target_component);
        return mavlink_msg_to_send_buffer(buf,msg);
    }
#endif
