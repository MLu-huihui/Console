#pragma once
// MESSAGE FLY_QUICK_CTRL PACKING

#define MAVLINK_MSG_ID_FLY_QUICK_CTRL 173


typedef struct __mavlink_fly_quick_ctrl_t {
 int16_t backHome; /*<  When the value is 1, represent that the robot need to go back to the console, while the value is 0 is for nothing.*/
 int16_t flyUP; /*<  When the value is 1, represent that the robot need to take off to the specified altitude and hover, while the value is 0 is for nothing.*/
 int16_t flyDown; /*<  When the value is 1, represent that the robot need to descend to the ground, while the value is 0 is for nothing.*/
 int16_t hover; /*<  When the value is 1, represent that the robot need to hover on this altitude, while the value is 0 is for nothing.*/
} mavlink_fly_quick_ctrl_t;

#define MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN 8
#define MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN 8
#define MAVLINK_MSG_ID_173_LEN 8
#define MAVLINK_MSG_ID_173_MIN_LEN 8

#define MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC 59
#define MAVLINK_MSG_ID_173_CRC 59



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FLY_QUICK_CTRL { \
    173, \
    "FLY_QUICK_CTRL", \
    4, \
    {  { "backHome", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_fly_quick_ctrl_t, backHome) }, \
         { "flyUP", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_fly_quick_ctrl_t, flyUP) }, \
         { "flyDown", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_fly_quick_ctrl_t, flyDown) }, \
         { "hover", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_fly_quick_ctrl_t, hover) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FLY_QUICK_CTRL { \
    "FLY_QUICK_CTRL", \
    4, \
    {  { "backHome", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_fly_quick_ctrl_t, backHome) }, \
         { "flyUP", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_fly_quick_ctrl_t, flyUP) }, \
         { "flyDown", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_fly_quick_ctrl_t, flyDown) }, \
         { "hover", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_fly_quick_ctrl_t, hover) }, \
         } \
}
#endif

/**
 * @brief Pack a fly_quick_ctrl message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param backHome  When the value is 1, represent that the robot need to go back to the console, while the value is 0 is for nothing.
 * @param flyUP  When the value is 1, represent that the robot need to take off to the specified altitude and hover, while the value is 0 is for nothing.
 * @param flyDown  When the value is 1, represent that the robot need to descend to the ground, while the value is 0 is for nothing.
 * @param hover  When the value is 1, represent that the robot need to hover on this altitude, while the value is 0 is for nothing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fly_quick_ctrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t backHome, int16_t flyUP, int16_t flyDown, int16_t hover)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN];
    _mav_put_int16_t(buf, 0, backHome);
    _mav_put_int16_t(buf, 2, flyUP);
    _mav_put_int16_t(buf, 4, flyDown);
    _mav_put_int16_t(buf, 6, hover);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN);
#else
    mavlink_fly_quick_ctrl_t packet;
    packet.backHome = backHome;
    packet.flyUP = flyUP;
    packet.flyDown = flyDown;
    packet.hover = hover;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FLY_QUICK_CTRL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
}

/**
 * @brief Pack a fly_quick_ctrl message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param backHome  When the value is 1, represent that the robot need to go back to the console, while the value is 0 is for nothing.
 * @param flyUP  When the value is 1, represent that the robot need to take off to the specified altitude and hover, while the value is 0 is for nothing.
 * @param flyDown  When the value is 1, represent that the robot need to descend to the ground, while the value is 0 is for nothing.
 * @param hover  When the value is 1, represent that the robot need to hover on this altitude, while the value is 0 is for nothing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fly_quick_ctrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t backHome,int16_t flyUP,int16_t flyDown,int16_t hover)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN];
    _mav_put_int16_t(buf, 0, backHome);
    _mav_put_int16_t(buf, 2, flyUP);
    _mav_put_int16_t(buf, 4, flyDown);
    _mav_put_int16_t(buf, 6, hover);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN);
#else
    mavlink_fly_quick_ctrl_t packet;
    packet.backHome = backHome;
    packet.flyUP = flyUP;
    packet.flyDown = flyDown;
    packet.hover = hover;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FLY_QUICK_CTRL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
}

/**
 * @brief Encode a fly_quick_ctrl struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fly_quick_ctrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fly_quick_ctrl_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fly_quick_ctrl_t* fly_quick_ctrl)
{
    return mavlink_msg_fly_quick_ctrl_pack(system_id, component_id, msg, fly_quick_ctrl->backHome, fly_quick_ctrl->flyUP, fly_quick_ctrl->flyDown, fly_quick_ctrl->hover);
}

/**
 * @brief Encode a fly_quick_ctrl struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fly_quick_ctrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fly_quick_ctrl_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fly_quick_ctrl_t* fly_quick_ctrl)
{
    return mavlink_msg_fly_quick_ctrl_pack_chan(system_id, component_id, chan, msg, fly_quick_ctrl->backHome, fly_quick_ctrl->flyUP, fly_quick_ctrl->flyDown, fly_quick_ctrl->hover);
}

/**
 * @brief Send a fly_quick_ctrl message
 * @param chan MAVLink channel to send the message
 *
 * @param backHome  When the value is 1, represent that the robot need to go back to the console, while the value is 0 is for nothing.
 * @param flyUP  When the value is 1, represent that the robot need to take off to the specified altitude and hover, while the value is 0 is for nothing.
 * @param flyDown  When the value is 1, represent that the robot need to descend to the ground, while the value is 0 is for nothing.
 * @param hover  When the value is 1, represent that the robot need to hover on this altitude, while the value is 0 is for nothing.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fly_quick_ctrl_send(mavlink_channel_t chan, int16_t backHome, int16_t flyUP, int16_t flyDown, int16_t hover)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN];
    _mav_put_int16_t(buf, 0, backHome);
    _mav_put_int16_t(buf, 2, flyUP);
    _mav_put_int16_t(buf, 4, flyDown);
    _mav_put_int16_t(buf, 6, hover);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL, buf, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
#else
    mavlink_fly_quick_ctrl_t packet;
    packet.backHome = backHome;
    packet.flyUP = flyUP;
    packet.flyDown = flyDown;
    packet.hover = hover;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL, (const char *)&packet, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
#endif
}

/**
 * @brief Send a fly_quick_ctrl message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fly_quick_ctrl_send_struct(mavlink_channel_t chan, const mavlink_fly_quick_ctrl_t* fly_quick_ctrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fly_quick_ctrl_send(chan, fly_quick_ctrl->backHome, fly_quick_ctrl->flyUP, fly_quick_ctrl->flyDown, fly_quick_ctrl->hover);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL, (const char *)fly_quick_ctrl, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
#endif
}

#if MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fly_quick_ctrl_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t backHome, int16_t flyUP, int16_t flyDown, int16_t hover)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, backHome);
    _mav_put_int16_t(buf, 2, flyUP);
    _mav_put_int16_t(buf, 4, flyDown);
    _mav_put_int16_t(buf, 6, hover);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL, buf, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
#else
    mavlink_fly_quick_ctrl_t *packet = (mavlink_fly_quick_ctrl_t *)msgbuf;
    packet->backHome = backHome;
    packet->flyUP = flyUP;
    packet->flyDown = flyDown;
    packet->hover = hover;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FLY_QUICK_CTRL, (const char *)packet, MAVLINK_MSG_ID_FLY_QUICK_CTRL_MIN_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN, MAVLINK_MSG_ID_FLY_QUICK_CTRL_CRC);
#endif
}
#endif

#endif

// MESSAGE FLY_QUICK_CTRL UNPACKING


/**
 * @brief Get field backHome from fly_quick_ctrl message
 *
 * @return  When the value is 1, represent that the robot need to go back to the console, while the value is 0 is for nothing.
 */
static inline int16_t mavlink_msg_fly_quick_ctrl_get_backHome(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field flyUP from fly_quick_ctrl message
 *
 * @return  When the value is 1, represent that the robot need to take off to the specified altitude and hover, while the value is 0 is for nothing.
 */
static inline int16_t mavlink_msg_fly_quick_ctrl_get_flyUP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field flyDown from fly_quick_ctrl message
 *
 * @return  When the value is 1, represent that the robot need to descend to the ground, while the value is 0 is for nothing.
 */
static inline int16_t mavlink_msg_fly_quick_ctrl_get_flyDown(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field hover from fly_quick_ctrl message
 *
 * @return  When the value is 1, represent that the robot need to hover on this altitude, while the value is 0 is for nothing.
 */
static inline int16_t mavlink_msg_fly_quick_ctrl_get_hover(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Decode a fly_quick_ctrl message into a struct
 *
 * @param msg The message to decode
 * @param fly_quick_ctrl C-struct to decode the message contents into
 */
static inline void mavlink_msg_fly_quick_ctrl_decode(const mavlink_message_t* msg, mavlink_fly_quick_ctrl_t* fly_quick_ctrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fly_quick_ctrl->backHome = mavlink_msg_fly_quick_ctrl_get_backHome(msg);
    fly_quick_ctrl->flyUP = mavlink_msg_fly_quick_ctrl_get_flyUP(msg);
    fly_quick_ctrl->flyDown = mavlink_msg_fly_quick_ctrl_get_flyDown(msg);
    fly_quick_ctrl->hover = mavlink_msg_fly_quick_ctrl_get_hover(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN? msg->len : MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN;
        memset(fly_quick_ctrl, 0, MAVLINK_MSG_ID_FLY_QUICK_CTRL_LEN);
    memcpy(fly_quick_ctrl, _MAV_PAYLOAD(msg), len);
#endif
}
