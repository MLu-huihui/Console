#pragma once
// MESSAGE JS_CRTL_INFO PACKING

#define MAVLINK_MSG_ID_JS_CRTL_INFO 170


typedef struct __mavlink_js_crtl_info_t {
 int16_t leftX; /*<  The value of leftX in joystick.*/
 int16_t leftY; /*<  The value of leftY in joystick.*/
 int16_t rightX; /*<  The value of rightX in joystick.*/
 int16_t rightY; /*<  The value of rightY in joystick.*/
 uint8_t mode; /*<  Indicate the mode of the robot.*/
} mavlink_js_crtl_info_t;

#define MAVLINK_MSG_ID_JS_CRTL_INFO_LEN 9
#define MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN 9
#define MAVLINK_MSG_ID_170_LEN 9
#define MAVLINK_MSG_ID_170_MIN_LEN 9

#define MAVLINK_MSG_ID_JS_CRTL_INFO_CRC 136
#define MAVLINK_MSG_ID_170_CRC 136



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_JS_CRTL_INFO { \
    170, \
    "JS_CRTL_INFO", \
    5, \
    {  { "leftX", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_js_crtl_info_t, leftX) }, \
         { "leftY", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_js_crtl_info_t, leftY) }, \
         { "rightX", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_js_crtl_info_t, rightX) }, \
         { "rightY", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_js_crtl_info_t, rightY) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_js_crtl_info_t, mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_JS_CRTL_INFO { \
    "JS_CRTL_INFO", \
    5, \
    {  { "leftX", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_js_crtl_info_t, leftX) }, \
         { "leftY", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_js_crtl_info_t, leftY) }, \
         { "rightX", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_js_crtl_info_t, rightX) }, \
         { "rightY", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_js_crtl_info_t, rightY) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_js_crtl_info_t, mode) }, \
         } \
}
#endif

/**
 * @brief Pack a js_crtl_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param leftX  The value of leftX in joystick.
 * @param leftY  The value of leftY in joystick.
 * @param rightX  The value of rightX in joystick.
 * @param rightY  The value of rightY in joystick.
 * @param mode  Indicate the mode of the robot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_js_crtl_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t leftX, int16_t leftY, int16_t rightX, int16_t rightY, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JS_CRTL_INFO_LEN];
    _mav_put_int16_t(buf, 0, leftX);
    _mav_put_int16_t(buf, 2, leftY);
    _mav_put_int16_t(buf, 4, rightX);
    _mav_put_int16_t(buf, 6, rightY);
    _mav_put_uint8_t(buf, 8, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN);
#else
    mavlink_js_crtl_info_t packet;
    packet.leftX = leftX;
    packet.leftY = leftY;
    packet.rightX = rightX;
    packet.rightY = rightY;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JS_CRTL_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
}

/**
 * @brief Pack a js_crtl_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param leftX  The value of leftX in joystick.
 * @param leftY  The value of leftY in joystick.
 * @param rightX  The value of rightX in joystick.
 * @param rightY  The value of rightY in joystick.
 * @param mode  Indicate the mode of the robot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_js_crtl_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t leftX,int16_t leftY,int16_t rightX,int16_t rightY,uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JS_CRTL_INFO_LEN];
    _mav_put_int16_t(buf, 0, leftX);
    _mav_put_int16_t(buf, 2, leftY);
    _mav_put_int16_t(buf, 4, rightX);
    _mav_put_int16_t(buf, 6, rightY);
    _mav_put_uint8_t(buf, 8, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN);
#else
    mavlink_js_crtl_info_t packet;
    packet.leftX = leftX;
    packet.leftY = leftY;
    packet.rightX = rightX;
    packet.rightY = rightY;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JS_CRTL_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
}

/**
 * @brief Encode a js_crtl_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param js_crtl_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_js_crtl_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_js_crtl_info_t* js_crtl_info)
{
    return mavlink_msg_js_crtl_info_pack(system_id, component_id, msg, js_crtl_info->leftX, js_crtl_info->leftY, js_crtl_info->rightX, js_crtl_info->rightY, js_crtl_info->mode);
}

/**
 * @brief Encode a js_crtl_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param js_crtl_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_js_crtl_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_js_crtl_info_t* js_crtl_info)
{
    return mavlink_msg_js_crtl_info_pack_chan(system_id, component_id, chan, msg, js_crtl_info->leftX, js_crtl_info->leftY, js_crtl_info->rightX, js_crtl_info->rightY, js_crtl_info->mode);
}

/**
 * @brief Send a js_crtl_info message
 * @param chan MAVLink channel to send the message
 *
 * @param leftX  The value of leftX in joystick.
 * @param leftY  The value of leftY in joystick.
 * @param rightX  The value of rightX in joystick.
 * @param rightY  The value of rightY in joystick.
 * @param mode  Indicate the mode of the robot.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_js_crtl_info_send(mavlink_channel_t chan, int16_t leftX, int16_t leftY, int16_t rightX, int16_t rightY, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JS_CRTL_INFO_LEN];
    _mav_put_int16_t(buf, 0, leftX);
    _mav_put_int16_t(buf, 2, leftY);
    _mav_put_int16_t(buf, 4, rightX);
    _mav_put_int16_t(buf, 6, rightY);
    _mav_put_uint8_t(buf, 8, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JS_CRTL_INFO, buf, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
#else
    mavlink_js_crtl_info_t packet;
    packet.leftX = leftX;
    packet.leftY = leftY;
    packet.rightX = rightX;
    packet.rightY = rightY;
    packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JS_CRTL_INFO, (const char *)&packet, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
#endif
}

/**
 * @brief Send a js_crtl_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_js_crtl_info_send_struct(mavlink_channel_t chan, const mavlink_js_crtl_info_t* js_crtl_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_js_crtl_info_send(chan, js_crtl_info->leftX, js_crtl_info->leftY, js_crtl_info->rightX, js_crtl_info->rightY, js_crtl_info->mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JS_CRTL_INFO, (const char *)js_crtl_info, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_JS_CRTL_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_js_crtl_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t leftX, int16_t leftY, int16_t rightX, int16_t rightY, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, leftX);
    _mav_put_int16_t(buf, 2, leftY);
    _mav_put_int16_t(buf, 4, rightX);
    _mav_put_int16_t(buf, 6, rightY);
    _mav_put_uint8_t(buf, 8, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JS_CRTL_INFO, buf, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
#else
    mavlink_js_crtl_info_t *packet = (mavlink_js_crtl_info_t *)msgbuf;
    packet->leftX = leftX;
    packet->leftY = leftY;
    packet->rightX = rightX;
    packet->rightY = rightY;
    packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JS_CRTL_INFO, (const char *)packet, MAVLINK_MSG_ID_JS_CRTL_INFO_MIN_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN, MAVLINK_MSG_ID_JS_CRTL_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE JS_CRTL_INFO UNPACKING


/**
 * @brief Get field leftX from js_crtl_info message
 *
 * @return  The value of leftX in joystick.
 */
static inline int16_t mavlink_msg_js_crtl_info_get_leftX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field leftY from js_crtl_info message
 *
 * @return  The value of leftY in joystick.
 */
static inline int16_t mavlink_msg_js_crtl_info_get_leftY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field rightX from js_crtl_info message
 *
 * @return  The value of rightX in joystick.
 */
static inline int16_t mavlink_msg_js_crtl_info_get_rightX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field rightY from js_crtl_info message
 *
 * @return  The value of rightY in joystick.
 */
static inline int16_t mavlink_msg_js_crtl_info_get_rightY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field mode from js_crtl_info message
 *
 * @return  Indicate the mode of the robot.
 */
static inline uint8_t mavlink_msg_js_crtl_info_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a js_crtl_info message into a struct
 *
 * @param msg The message to decode
 * @param js_crtl_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_js_crtl_info_decode(const mavlink_message_t* msg, mavlink_js_crtl_info_t* js_crtl_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    js_crtl_info->leftX = mavlink_msg_js_crtl_info_get_leftX(msg);
    js_crtl_info->leftY = mavlink_msg_js_crtl_info_get_leftY(msg);
    js_crtl_info->rightX = mavlink_msg_js_crtl_info_get_rightX(msg);
    js_crtl_info->rightY = mavlink_msg_js_crtl_info_get_rightY(msg);
    js_crtl_info->mode = mavlink_msg_js_crtl_info_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_JS_CRTL_INFO_LEN? msg->len : MAVLINK_MSG_ID_JS_CRTL_INFO_LEN;
        memset(js_crtl_info, 0, MAVLINK_MSG_ID_JS_CRTL_INFO_LEN);
    memcpy(js_crtl_info, _MAV_PAYLOAD(msg), len);
#endif
}
