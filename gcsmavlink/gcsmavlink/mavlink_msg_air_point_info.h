#pragma once
// MESSAGE AIR_POINT_INFO PACKING

#define MAVLINK_MSG_ID_AIR_POINT_INFO 172


typedef struct __mavlink_air_point_info_t {
 float longitude[18]; /*<  The value of longitude in an air point.*/
 float latitude[18]; /*<  The value of latitude in an air point.*/
 float altitude[18]; /*<  The value of altitude in an ait point.*/
 int16_t pointCount; /*<  The count of air point in the fly line of the robot, and the count must less than 18.*/
} mavlink_air_point_info_t;

#define MAVLINK_MSG_ID_AIR_POINT_INFO_LEN 218
#define MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN 218
#define MAVLINK_MSG_ID_172_LEN 218
#define MAVLINK_MSG_ID_172_MIN_LEN 218

#define MAVLINK_MSG_ID_AIR_POINT_INFO_CRC 103
#define MAVLINK_MSG_ID_172_CRC 103

#define MAVLINK_MSG_AIR_POINT_INFO_FIELD_LONGITUDE_LEN 18
#define MAVLINK_MSG_AIR_POINT_INFO_FIELD_LATITUDE_LEN 18
#define MAVLINK_MSG_AIR_POINT_INFO_FIELD_ALTITUDE_LEN 18

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AIR_POINT_INFO { \
    172, \
    "AIR_POINT_INFO", \
    4, \
    {  { "pointCount", NULL, MAVLINK_TYPE_INT16_T, 0, 216, offsetof(mavlink_air_point_info_t, pointCount) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 18, 0, offsetof(mavlink_air_point_info_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 18, 72, offsetof(mavlink_air_point_info_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 18, 144, offsetof(mavlink_air_point_info_t, altitude) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AIR_POINT_INFO { \
    "AIR_POINT_INFO", \
    4, \
    {  { "pointCount", NULL, MAVLINK_TYPE_INT16_T, 0, 216, offsetof(mavlink_air_point_info_t, pointCount) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 18, 0, offsetof(mavlink_air_point_info_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 18, 72, offsetof(mavlink_air_point_info_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 18, 144, offsetof(mavlink_air_point_info_t, altitude) }, \
         } \
}
#endif

/**
 * @brief Pack a air_point_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pointCount  The count of air point in the fly line of the robot, and the count must less than 18.
 * @param longitude  The value of longitude in an air point.
 * @param latitude  The value of latitude in an air point.
 * @param altitude  The value of altitude in an ait point.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_air_point_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t pointCount, const float *longitude, const float *latitude, const float *altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_POINT_INFO_LEN];
    _mav_put_int16_t(buf, 216, pointCount);
    _mav_put_float_array(buf, 0, longitude, 18);
    _mav_put_float_array(buf, 72, latitude, 18);
    _mav_put_float_array(buf, 144, altitude, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN);
#else
    mavlink_air_point_info_t packet;
    packet.pointCount = pointCount;
    mav_array_memcpy(packet.longitude, longitude, sizeof(float)*18);
    mav_array_memcpy(packet.latitude, latitude, sizeof(float)*18);
    mav_array_memcpy(packet.altitude, altitude, sizeof(float)*18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIR_POINT_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
}

/**
 * @brief Pack a air_point_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pointCount  The count of air point in the fly line of the robot, and the count must less than 18.
 * @param longitude  The value of longitude in an air point.
 * @param latitude  The value of latitude in an air point.
 * @param altitude  The value of altitude in an ait point.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_air_point_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t pointCount,const float *longitude,const float *latitude,const float *altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_POINT_INFO_LEN];
    _mav_put_int16_t(buf, 216, pointCount);
    _mav_put_float_array(buf, 0, longitude, 18);
    _mav_put_float_array(buf, 72, latitude, 18);
    _mav_put_float_array(buf, 144, altitude, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN);
#else
    mavlink_air_point_info_t packet;
    packet.pointCount = pointCount;
    mav_array_memcpy(packet.longitude, longitude, sizeof(float)*18);
    mav_array_memcpy(packet.latitude, latitude, sizeof(float)*18);
    mav_array_memcpy(packet.altitude, altitude, sizeof(float)*18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIR_POINT_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
}

/**
 * @brief Encode a air_point_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param air_point_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_air_point_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_air_point_info_t* air_point_info)
{
    return mavlink_msg_air_point_info_pack(system_id, component_id, msg, air_point_info->pointCount, air_point_info->longitude, air_point_info->latitude, air_point_info->altitude);
}

/**
 * @brief Encode a air_point_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param air_point_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_air_point_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_air_point_info_t* air_point_info)
{
    return mavlink_msg_air_point_info_pack_chan(system_id, component_id, chan, msg, air_point_info->pointCount, air_point_info->longitude, air_point_info->latitude, air_point_info->altitude);
}

/**
 * @brief Send a air_point_info message
 * @param chan MAVLink channel to send the message
 *
 * @param pointCount  The count of air point in the fly line of the robot, and the count must less than 18.
 * @param longitude  The value of longitude in an air point.
 * @param latitude  The value of latitude in an air point.
 * @param altitude  The value of altitude in an ait point.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_air_point_info_send(mavlink_channel_t chan, int16_t pointCount, const float *longitude, const float *latitude, const float *altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIR_POINT_INFO_LEN];
    _mav_put_int16_t(buf, 216, pointCount);
    _mav_put_float_array(buf, 0, longitude, 18);
    _mav_put_float_array(buf, 72, latitude, 18);
    _mav_put_float_array(buf, 144, altitude, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR_POINT_INFO, buf, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
#else
    mavlink_air_point_info_t packet;
    packet.pointCount = pointCount;
    mav_array_memcpy(packet.longitude, longitude, sizeof(float)*18);
    mav_array_memcpy(packet.latitude, latitude, sizeof(float)*18);
    mav_array_memcpy(packet.altitude, altitude, sizeof(float)*18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR_POINT_INFO, (const char *)&packet, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
#endif
}

/**
 * @brief Send a air_point_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_air_point_info_send_struct(mavlink_channel_t chan, const mavlink_air_point_info_t* air_point_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_air_point_info_send(chan, air_point_info->pointCount, air_point_info->longitude, air_point_info->latitude, air_point_info->altitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR_POINT_INFO, (const char *)air_point_info, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_AIR_POINT_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_air_point_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t pointCount, const float *longitude, const float *latitude, const float *altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 216, pointCount);
    _mav_put_float_array(buf, 0, longitude, 18);
    _mav_put_float_array(buf, 72, latitude, 18);
    _mav_put_float_array(buf, 144, altitude, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR_POINT_INFO, buf, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
#else
    mavlink_air_point_info_t *packet = (mavlink_air_point_info_t *)msgbuf;
    packet->pointCount = pointCount;
    mav_array_memcpy(packet->longitude, longitude, sizeof(float)*18);
    mav_array_memcpy(packet->latitude, latitude, sizeof(float)*18);
    mav_array_memcpy(packet->altitude, altitude, sizeof(float)*18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIR_POINT_INFO, (const char *)packet, MAVLINK_MSG_ID_AIR_POINT_INFO_MIN_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN, MAVLINK_MSG_ID_AIR_POINT_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE AIR_POINT_INFO UNPACKING


/**
 * @brief Get field pointCount from air_point_info message
 *
 * @return  The count of air point in the fly line of the robot, and the count must less than 18.
 */
static inline int16_t mavlink_msg_air_point_info_get_pointCount(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  216);
}

/**
 * @brief Get field longitude from air_point_info message
 *
 * @return  The value of longitude in an air point.
 */
static inline uint16_t mavlink_msg_air_point_info_get_longitude(const mavlink_message_t* msg, float *longitude)
{
    return _MAV_RETURN_float_array(msg, longitude, 18,  0);
}

/**
 * @brief Get field latitude from air_point_info message
 *
 * @return  The value of latitude in an air point.
 */
static inline uint16_t mavlink_msg_air_point_info_get_latitude(const mavlink_message_t* msg, float *latitude)
{
    return _MAV_RETURN_float_array(msg, latitude, 18,  72);
}

/**
 * @brief Get field altitude from air_point_info message
 *
 * @return  The value of altitude in an ait point.
 */
static inline uint16_t mavlink_msg_air_point_info_get_altitude(const mavlink_message_t* msg, float *altitude)
{
    return _MAV_RETURN_float_array(msg, altitude, 18,  144);
}

/**
 * @brief Decode a air_point_info message into a struct
 *
 * @param msg The message to decode
 * @param air_point_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_air_point_info_decode(const mavlink_message_t* msg, mavlink_air_point_info_t* air_point_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_air_point_info_get_longitude(msg, air_point_info->longitude);
    mavlink_msg_air_point_info_get_latitude(msg, air_point_info->latitude);
    mavlink_msg_air_point_info_get_altitude(msg, air_point_info->altitude);
    air_point_info->pointCount = mavlink_msg_air_point_info_get_pointCount(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AIR_POINT_INFO_LEN? msg->len : MAVLINK_MSG_ID_AIR_POINT_INFO_LEN;
        memset(air_point_info, 0, MAVLINK_MSG_ID_AIR_POINT_INFO_LEN);
    memcpy(air_point_info, _MAV_PAYLOAD(msg), len);
#endif
}
