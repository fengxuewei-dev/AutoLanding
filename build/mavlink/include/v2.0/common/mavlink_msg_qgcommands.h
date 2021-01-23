#pragma once
// MESSAGE QGCOMMANDS PACKING

#define MAVLINK_MSG_ID_QGCOMMANDS 306

MAVPACKED(
typedef struct __mavlink_qgcommands_t {
 double plane_state; /*<  plane_state*/
 double plane_group; /*<  plane_group*/
 double gapx; /*<  gapx*/
 double gapy; /*<  gapy*/
 int32_t taskType; /*<  taskType*/
 uint16_t message_id; /*<  message_id*/
 uint16_t uav_id; /*<  uav_id*/
 uint16_t gs_id; /*<  gs_id*/
 uint16_t vehicleNumber; /*<  vehicleNumber*/
}) mavlink_qgcommands_t;

#define MAVLINK_MSG_ID_QGCOMMANDS_LEN 44
#define MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN 44
#define MAVLINK_MSG_ID_306_LEN 44
#define MAVLINK_MSG_ID_306_MIN_LEN 44

#define MAVLINK_MSG_ID_QGCOMMANDS_CRC 149
#define MAVLINK_MSG_ID_306_CRC 149



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_QGCOMMANDS { \
    306, \
    "QGCOMMANDS", \
    9, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_qgcommands_t, message_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_qgcommands_t, uav_id) }, \
         { "gs_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_qgcommands_t, gs_id) }, \
         { "vehicleNumber", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_qgcommands_t, vehicleNumber) }, \
         { "taskType", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_qgcommands_t, taskType) }, \
         { "plane_state", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_qgcommands_t, plane_state) }, \
         { "plane_group", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_qgcommands_t, plane_group) }, \
         { "gapx", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_qgcommands_t, gapx) }, \
         { "gapy", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_qgcommands_t, gapy) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_QGCOMMANDS { \
    "QGCOMMANDS", \
    9, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_qgcommands_t, message_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_qgcommands_t, uav_id) }, \
         { "gs_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_qgcommands_t, gs_id) }, \
         { "vehicleNumber", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_qgcommands_t, vehicleNumber) }, \
         { "taskType", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_qgcommands_t, taskType) }, \
         { "plane_state", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_qgcommands_t, plane_state) }, \
         { "plane_group", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_qgcommands_t, plane_group) }, \
         { "gapx", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_qgcommands_t, gapx) }, \
         { "gapy", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_qgcommands_t, gapy) }, \
         } \
}
#endif

/**
 * @brief Pack a qgcommands message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param gs_id  gs_id
 * @param vehicleNumber  vehicleNumber
 * @param taskType  taskType
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param gapx  gapx
 * @param gapy  gapy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_qgcommands_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t message_id, uint16_t uav_id, uint16_t gs_id, uint16_t vehicleNumber, int32_t taskType, double plane_state, double plane_group, double gapx, double gapy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_QGCOMMANDS_LEN];
    _mav_put_double(buf, 0, plane_state);
    _mav_put_double(buf, 8, plane_group);
    _mav_put_double(buf, 16, gapx);
    _mav_put_double(buf, 24, gapy);
    _mav_put_int32_t(buf, 32, taskType);
    _mav_put_uint16_t(buf, 36, message_id);
    _mav_put_uint16_t(buf, 38, uav_id);
    _mav_put_uint16_t(buf, 40, gs_id);
    _mav_put_uint16_t(buf, 42, vehicleNumber);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QGCOMMANDS_LEN);
#else
    mavlink_qgcommands_t packet;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;
    packet.gapx = gapx;
    packet.gapy = gapy;
    packet.taskType = taskType;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.gs_id = gs_id;
    packet.vehicleNumber = vehicleNumber;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_QGCOMMANDS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_QGCOMMANDS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
}

/**
 * @brief Pack a qgcommands message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param gs_id  gs_id
 * @param vehicleNumber  vehicleNumber
 * @param taskType  taskType
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param gapx  gapx
 * @param gapy  gapy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_qgcommands_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t message_id,uint16_t uav_id,uint16_t gs_id,uint16_t vehicleNumber,int32_t taskType,double plane_state,double plane_group,double gapx,double gapy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_QGCOMMANDS_LEN];
    _mav_put_double(buf, 0, plane_state);
    _mav_put_double(buf, 8, plane_group);
    _mav_put_double(buf, 16, gapx);
    _mav_put_double(buf, 24, gapy);
    _mav_put_int32_t(buf, 32, taskType);
    _mav_put_uint16_t(buf, 36, message_id);
    _mav_put_uint16_t(buf, 38, uav_id);
    _mav_put_uint16_t(buf, 40, gs_id);
    _mav_put_uint16_t(buf, 42, vehicleNumber);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QGCOMMANDS_LEN);
#else
    mavlink_qgcommands_t packet;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;
    packet.gapx = gapx;
    packet.gapy = gapy;
    packet.taskType = taskType;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.gs_id = gs_id;
    packet.vehicleNumber = vehicleNumber;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_QGCOMMANDS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_QGCOMMANDS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
}

/**
 * @brief Encode a qgcommands struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param qgcommands C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_qgcommands_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_qgcommands_t* qgcommands)
{
    return mavlink_msg_qgcommands_pack(system_id, component_id, msg, qgcommands->message_id, qgcommands->uav_id, qgcommands->gs_id, qgcommands->vehicleNumber, qgcommands->taskType, qgcommands->plane_state, qgcommands->plane_group, qgcommands->gapx, qgcommands->gapy);
}

/**
 * @brief Encode a qgcommands struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param qgcommands C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_qgcommands_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_qgcommands_t* qgcommands)
{
    return mavlink_msg_qgcommands_pack_chan(system_id, component_id, chan, msg, qgcommands->message_id, qgcommands->uav_id, qgcommands->gs_id, qgcommands->vehicleNumber, qgcommands->taskType, qgcommands->plane_state, qgcommands->plane_group, qgcommands->gapx, qgcommands->gapy);
}

/**
 * @brief Send a qgcommands message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param gs_id  gs_id
 * @param vehicleNumber  vehicleNumber
 * @param taskType  taskType
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param gapx  gapx
 * @param gapy  gapy
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_qgcommands_send(mavlink_channel_t chan, uint16_t message_id, uint16_t uav_id, uint16_t gs_id, uint16_t vehicleNumber, int32_t taskType, double plane_state, double plane_group, double gapx, double gapy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_QGCOMMANDS_LEN];
    _mav_put_double(buf, 0, plane_state);
    _mav_put_double(buf, 8, plane_group);
    _mav_put_double(buf, 16, gapx);
    _mav_put_double(buf, 24, gapy);
    _mav_put_int32_t(buf, 32, taskType);
    _mav_put_uint16_t(buf, 36, message_id);
    _mav_put_uint16_t(buf, 38, uav_id);
    _mav_put_uint16_t(buf, 40, gs_id);
    _mav_put_uint16_t(buf, 42, vehicleNumber);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QGCOMMANDS, buf, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
#else
    mavlink_qgcommands_t packet;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;
    packet.gapx = gapx;
    packet.gapy = gapy;
    packet.taskType = taskType;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.gs_id = gs_id;
    packet.vehicleNumber = vehicleNumber;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QGCOMMANDS, (const char *)&packet, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
#endif
}

/**
 * @brief Send a qgcommands message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_qgcommands_send_struct(mavlink_channel_t chan, const mavlink_qgcommands_t* qgcommands)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_qgcommands_send(chan, qgcommands->message_id, qgcommands->uav_id, qgcommands->gs_id, qgcommands->vehicleNumber, qgcommands->taskType, qgcommands->plane_state, qgcommands->plane_group, qgcommands->gapx, qgcommands->gapy);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QGCOMMANDS, (const char *)qgcommands, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
#endif
}

#if MAVLINK_MSG_ID_QGCOMMANDS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_qgcommands_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t message_id, uint16_t uav_id, uint16_t gs_id, uint16_t vehicleNumber, int32_t taskType, double plane_state, double plane_group, double gapx, double gapy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, plane_state);
    _mav_put_double(buf, 8, plane_group);
    _mav_put_double(buf, 16, gapx);
    _mav_put_double(buf, 24, gapy);
    _mav_put_int32_t(buf, 32, taskType);
    _mav_put_uint16_t(buf, 36, message_id);
    _mav_put_uint16_t(buf, 38, uav_id);
    _mav_put_uint16_t(buf, 40, gs_id);
    _mav_put_uint16_t(buf, 42, vehicleNumber);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QGCOMMANDS, buf, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
#else
    mavlink_qgcommands_t *packet = (mavlink_qgcommands_t *)msgbuf;
    packet->plane_state = plane_state;
    packet->plane_group = plane_group;
    packet->gapx = gapx;
    packet->gapy = gapy;
    packet->taskType = taskType;
    packet->message_id = message_id;
    packet->uav_id = uav_id;
    packet->gs_id = gs_id;
    packet->vehicleNumber = vehicleNumber;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QGCOMMANDS, (const char *)packet, MAVLINK_MSG_ID_QGCOMMANDS_MIN_LEN, MAVLINK_MSG_ID_QGCOMMANDS_LEN, MAVLINK_MSG_ID_QGCOMMANDS_CRC);
#endif
}
#endif

#endif

// MESSAGE QGCOMMANDS UNPACKING


/**
 * @brief Get field message_id from qgcommands message
 *
 * @return  message_id
 */
static inline uint16_t mavlink_msg_qgcommands_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field uav_id from qgcommands message
 *
 * @return  uav_id
 */
static inline uint16_t mavlink_msg_qgcommands_get_uav_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field gs_id from qgcommands message
 *
 * @return  gs_id
 */
static inline uint16_t mavlink_msg_qgcommands_get_gs_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field vehicleNumber from qgcommands message
 *
 * @return  vehicleNumber
 */
static inline uint16_t mavlink_msg_qgcommands_get_vehicleNumber(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field taskType from qgcommands message
 *
 * @return  taskType
 */
static inline int32_t mavlink_msg_qgcommands_get_taskType(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field plane_state from qgcommands message
 *
 * @return  plane_state
 */
static inline double mavlink_msg_qgcommands_get_plane_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field plane_group from qgcommands message
 *
 * @return  plane_group
 */
static inline double mavlink_msg_qgcommands_get_plane_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field gapx from qgcommands message
 *
 * @return  gapx
 */
static inline double mavlink_msg_qgcommands_get_gapx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field gapy from qgcommands message
 *
 * @return  gapy
 */
static inline double mavlink_msg_qgcommands_get_gapy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Decode a qgcommands message into a struct
 *
 * @param msg The message to decode
 * @param qgcommands C-struct to decode the message contents into
 */
static inline void mavlink_msg_qgcommands_decode(const mavlink_message_t* msg, mavlink_qgcommands_t* qgcommands)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    qgcommands->plane_state = mavlink_msg_qgcommands_get_plane_state(msg);
    qgcommands->plane_group = mavlink_msg_qgcommands_get_plane_group(msg);
    qgcommands->gapx = mavlink_msg_qgcommands_get_gapx(msg);
    qgcommands->gapy = mavlink_msg_qgcommands_get_gapy(msg);
    qgcommands->taskType = mavlink_msg_qgcommands_get_taskType(msg);
    qgcommands->message_id = mavlink_msg_qgcommands_get_message_id(msg);
    qgcommands->uav_id = mavlink_msg_qgcommands_get_uav_id(msg);
    qgcommands->gs_id = mavlink_msg_qgcommands_get_gs_id(msg);
    qgcommands->vehicleNumber = mavlink_msg_qgcommands_get_vehicleNumber(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_QGCOMMANDS_LEN? msg->len : MAVLINK_MSG_ID_QGCOMMANDS_LEN;
        memset(qgcommands, 0, MAVLINK_MSG_ID_QGCOMMANDS_LEN);
    memcpy(qgcommands, _MAV_PAYLOAD(msg), len);
#endif
}
