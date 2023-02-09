/** @file
 *    @brief MAVLink comm protocol testsuite generated from gcsmavlink.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef GCSMAVLINK_TESTSUITE_H
#define GCSMAVLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_gcsmavlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_gcsmavlink(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_js_crtl_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_JS_CRTL_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_js_crtl_info_t packet_in = {
        17235,17339,17443,17547,29
    };
    mavlink_js_crtl_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.leftX = packet_in.leftX;
        packet1.leftY = packet_in.leftY;
        packet1.rightX = packet_in.rightX;
        packet1.rightY = packet_in.rightY;
        packet1.mode = packet_in.mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_js_crtl_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_js_crtl_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_js_crtl_info_pack(system_id, component_id, &msg , packet1.leftX , packet1.leftY , packet1.rightX , packet1.rightY , packet1.mode );
    mavlink_msg_js_crtl_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_js_crtl_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.leftX , packet1.leftY , packet1.rightX , packet1.rightY , packet1.mode );
    mavlink_msg_js_crtl_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_js_crtl_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_js_crtl_info_send(MAVLINK_COMM_1 , packet1.leftX , packet1.leftY , packet1.rightX , packet1.rightY , packet1.mode );
    mavlink_msg_js_crtl_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("JS_CRTL_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_JS_CRTL_INFO) != NULL);
#endif
}

static void mavlink_test_robot_posture_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ROBOT_POSTURE_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_robot_posture_info_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0
    };
    mavlink_robot_posture_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.longitude = packet_in.longitude;
        packet1.latitude = packet_in.latitude;
        packet1.altitude = packet_in.altitude;
        packet1.velocity = packet_in.velocity;
        packet1.roll = packet_in.roll;
        packet1.yaw = packet_in.yaw;
        packet1.pitch = packet_in.pitch;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_posture_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_robot_posture_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_posture_info_pack(system_id, component_id, &msg , packet1.longitude , packet1.latitude , packet1.altitude , packet1.velocity , packet1.roll , packet1.yaw , packet1.pitch );
    mavlink_msg_robot_posture_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_posture_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.longitude , packet1.latitude , packet1.altitude , packet1.velocity , packet1.roll , packet1.yaw , packet1.pitch );
    mavlink_msg_robot_posture_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_robot_posture_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_posture_info_send(MAVLINK_COMM_1 , packet1.longitude , packet1.latitude , packet1.altitude , packet1.velocity , packet1.roll , packet1.yaw , packet1.pitch );
    mavlink_msg_robot_posture_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ROBOT_POSTURE_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ROBOT_POSTURE_INFO) != NULL);
#endif
}

static void mavlink_test_air_point_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AIR_POINT_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_air_point_info_t packet_in = {
        { 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0 },{ 521.0, 522.0, 523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0, 533.0, 534.0, 535.0, 536.0, 537.0, 538.0 },{ 1025.0, 1026.0, 1027.0, 1028.0, 1029.0, 1030.0, 1031.0, 1032.0, 1033.0, 1034.0, 1035.0, 1036.0, 1037.0, 1038.0, 1039.0, 1040.0, 1041.0, 1042.0 },28467
    };
    mavlink_air_point_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pointCount = packet_in.pointCount;
        
        mav_array_memcpy(packet1.longitude, packet_in.longitude, sizeof(float)*18);
        mav_array_memcpy(packet1.latitude, packet_in.latitude, sizeof(float)*18);
        mav_array_memcpy(packet1.altitude, packet_in.altitude, sizeof(float)*18);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_point_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_air_point_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_point_info_pack(system_id, component_id, &msg , packet1.pointCount , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_air_point_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_point_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pointCount , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_air_point_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_air_point_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_air_point_info_send(MAVLINK_COMM_1 , packet1.pointCount , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_air_point_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AIR_POINT_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AIR_POINT_INFO) != NULL);
#endif
}

static void mavlink_test_fly_quick_ctrl(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FLY_QUICK_CTRL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fly_quick_ctrl_t packet_in = {
        17235,17339,17443,17547
    };
    mavlink_fly_quick_ctrl_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.backHome = packet_in.backHome;
        packet1.flyUP = packet_in.flyUP;
        packet1.flyDown = packet_in.flyDown;
        packet1.hover = packet_in.hover;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fly_quick_ctrl_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fly_quick_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fly_quick_ctrl_pack(system_id, component_id, &msg , packet1.backHome , packet1.flyUP , packet1.flyDown , packet1.hover );
    mavlink_msg_fly_quick_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fly_quick_ctrl_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.backHome , packet1.flyUP , packet1.flyDown , packet1.hover );
    mavlink_msg_fly_quick_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fly_quick_ctrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fly_quick_ctrl_send(MAVLINK_COMM_1 , packet1.backHome , packet1.flyUP , packet1.flyDown , packet1.hover );
    mavlink_msg_fly_quick_ctrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FLY_QUICK_CTRL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FLY_QUICK_CTRL) != NULL);
#endif
}

static void mavlink_test_gcsmavlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_js_crtl_info(system_id, component_id, last_msg);
    mavlink_test_robot_posture_info(system_id, component_id, last_msg);
    mavlink_test_air_point_info(system_id, component_id, last_msg);
    mavlink_test_fly_quick_ctrl(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GCSMAVLINK_TESTSUITE_H
