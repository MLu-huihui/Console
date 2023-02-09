#pragma once
// MESSAGE ROBOT_POSTURE_INFO PACKING

#define MAVLINK_MSG_ID_ROBOT_POSTURE_INFO 171


typedef struct __mavlink_robot_posture_info_t {
 float longitude; /*<  The value of longitude where the robot is located in.*/
 float latitude; /*<  The value of latitude where the robot is located in.*/
 float altitude; /*<  The value of altitude where the robot is located in.*/
 float velocity; /*<  The value of velocity about the robot.*/
 float roll; /*<  The value of roll in the robot Euler Angle.*/
 float yaw; /*<  The value of yaw in the robot Euler Angle.*/
 float pitch; /*<  The value of pitch in the robot Euler Angle.*/
} mavlink_robot_posture_info_t;

#define MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN 28
#define MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN 28
#define MAVLINK_MSG_ID_171_LEN 28
#define MAVLINK_MSG_ID_171_MIN_LEN 28

#define MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC 84
#define MAVLINK_MSG_ID_171_CRC 84



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ROBOT_POSTURE_INFO { \
    171, \
    "ROBOT_POSTURE_INFO", \
    7, \
    {  { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_robot_posture_info_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_robot_posture_info_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_robot_posture_info_t, altitude) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_robot_posture_info_t, velocity) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_robot_posture_info_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_robot_posture_info_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_robot_posture_info_t, pitch) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ROBOT_POSTURE_INFO { \
    "ROBOT_POSTURE_INFO", \
    7, \
    {  { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_robot_posture_info_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_robot_posture_info_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_robot_posture_info_t, altitude) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_robot_posture_info_t, velocity) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_robot_posture_info_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_robot_posture_info_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_robot_posture_info_t, pitch) }, \
         } \
}
#endif

/**
 * @brief Pack a robot_posture_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param longitude  The value of longitude where the robot is located in.
 * @param latitude  The value of latitude where the robot is located in.
 * @param altitude  The value of altitude where the robot is located in.
 * @param velocity  The value of velocity about the robot.
 * @param roll  The value of roll in the robot Euler Angle.
 * @param yaw  The value of yaw in the robot Euler Angle.
 * @param pitch  The value of pitch in the robot Euler Angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_posture_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float longitude, float latitude, float altitude, float velocity, float roll, float yaw, float pitch)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, velocity);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, pitch);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN);
#else
    mavlink_robot_posture_info_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.velocity = velocity;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ROBOT_POSTURE_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
}

/**
 * @brief Pack a robot_posture_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param longitude  The value of longitude where the robot is located in.
 * @param latitude  The value of latitude where the robot is located in.
 * @param altitude  The value of altitude where the robot is located in.
 * @param velocity  The value of velocity about the robot.
 * @param roll  The value of roll in the robot Euler Angle.
 * @param yaw  The value of yaw in the robot Euler Angle.
 * @param pitch  The value of pitch in the robot Euler Angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_posture_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float longitude,float latitude,float altitude,float velocity,float roll,float yaw,float pitch)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, velocity);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, pitch);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN);
#else
    mavlink_robot_posture_info_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.velocity = velocity;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ROBOT_POSTURE_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
}

/**
 * @brief Encode a robot_posture_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param robot_posture_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_posture_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_robot_posture_info_t* robot_posture_info)
{
    return mavlink_msg_robot_posture_info_pack(system_id, component_id, msg, robot_posture_info->longitude, robot_posture_info->latitude, robot_posture_info->altitude, robot_posture_info->velocity, robot_posture_info->roll, robot_posture_info->yaw, robot_posture_info->pitch);
}

/**
 * @brief Encode a robot_posture_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param robot_posture_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_posture_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_robot_posture_info_t* robot_posture_info)
{
    return mavlink_msg_robot_posture_info_pack_chan(system_id, component_id, chan, msg, robot_posture_info->longitude, robot_posture_info->latitude, robot_posture_info->altitude, robot_posture_info->velocity, robot_posture_info->roll, robot_posture_info->yaw, robot_posture_info->pitch);
}

/**
 * @brief Send a robot_posture_info message
 * @param chan MAVLink channel to send the message
 *
 * @param longitude  The value of longitude where the robot is located in.
 * @param latitude  The value of latitude where the robot is located in.
 * @param altitude  The value of altitude where the robot is located in.
 * @param velocity  The value of velocity about the robot.
 * @param roll  The value of roll in the robot Euler Angle.
 * @param yaw  The value of yaw in the robot Euler Angle.
 * @param pitch  The value of pitch in the robot Euler Angle.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_robot_posture_info_send(mavlink_channel_t chan, float longitude, float latitude, float altitude, float velocity, float roll, float yaw, float pitch)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, velocity);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, pitch);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO, buf, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
#else
    mavlink_robot_posture_info_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.velocity = velocity;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO, (const char *)&packet, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
#endif
}

/**
 * @brief Send a robot_posture_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_robot_posture_info_send_struct(mavlink_channel_t chan, const mavlink_robot_posture_info_t* robot_posture_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_robot_posture_info_send(chan, robot_posture_info->longitude, robot_posture_info->latitude, robot_posture_info->altitude, robot_posture_info->velocity, robot_posture_info->roll, robot_posture_info->yaw, robot_posture_info->pitch);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO, (const char *)robot_posture_info, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_robot_posture_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float longitude, float latitude, float altitude, float velocity, float roll, float yaw, float pitch)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, velocity);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, yaw);
    _mav_put_float(buf, 24, pitch);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO, buf, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
#else
    mavlink_robot_posture_info_t *packet = (mavlink_robot_posture_info_t *)msgbuf;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->altitude = altitude;
    packet->velocity = velocity;
    packet->roll = roll;
    packet->yaw = yaw;
    packet->pitch = pitch;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO, (const char *)packet, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_MIN_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE ROBOT_POSTURE_INFO UNPACKING


/**
 * @brief Get field longitude from robot_posture_info message
 *
 * @return  The value of longitude where the robot is located in.
 */
static inline float mavlink_msg_robot_posture_info_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field latitude from robot_posture_info message
 *
 * @return  The value of latitude where the robot is located in.
 */
static inline float mavlink_msg_robot_posture_info_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field altitude from robot_posture_info message
 *
 * @return  The value of altitude where the robot is located in.
 */
static inline float mavlink_msg_robot_posture_info_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field velocity from robot_posture_info message
 *
 * @return  The value of velocity about the robot.
 */
static inline float mavlink_msg_robot_posture_info_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll from robot_posture_info message
 *
 * @return  The value of roll in the robot Euler Angle.
 */
static inline float mavlink_msg_robot_posture_info_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field yaw from robot_posture_info message
 *
 * @return  The value of yaw in the robot Euler Angle.
 */
static inline float mavlink_msg_robot_posture_info_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch from robot_posture_info message
 *
 * @return  The value of pitch in the robot Euler Angle.
 */
static inline float mavlink_msg_robot_posture_info_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a robot_posture_info message into a struct
 *
 * @param msg The message to decode
 * @param robot_posture_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_robot_posture_info_decode(const mavlink_message_t* msg, mavlink_robot_posture_info_t* robot_posture_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    robot_posture_info->longitude = mavlink_msg_robot_posture_info_get_longitude(msg);
    robot_posture_info->latitude = mavlink_msg_robot_posture_info_get_latitude(msg);
    robot_posture_info->altitude = mavlink_msg_robot_posture_info_get_altitude(msg);
    robot_posture_info->velocity = mavlink_msg_robot_posture_info_get_velocity(msg);
    robot_posture_info->roll = mavlink_msg_robot_posture_info_get_roll(msg);
    robot_posture_info->yaw = mavlink_msg_robot_posture_info_get_yaw(msg);
    robot_posture_info->pitch = mavlink_msg_robot_posture_info_get_pitch(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN? msg->len : MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN;
        memset(robot_posture_info, 0, MAVLINK_MSG_ID_ROBOT_POSTURE_INFO_LEN);
    memcpy(robot_posture_info, _MAV_PAYLOAD(msg), len);
#endif
}
