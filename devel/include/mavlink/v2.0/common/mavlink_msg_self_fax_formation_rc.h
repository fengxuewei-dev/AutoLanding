#pragma once
// MESSAGE SELF_FAX_FORMATION_RC PACKING

#define MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC 305

MAVPACKED(
typedef struct __mavlink_self_fax_formation_rc_t {
 double longitude_x; /*<  longitude_x*/
 double latitude_y; /*<  latitude_y*/
 double altitude_z; /*<  altitude_z*/
 double heading; /*<  heading*/
 double velocity; /*<  velocity*/
 double command_yaw; /*<  command_yaw*/
 int32_t number; /*<  number*/
 uint16_t message_id; /*<  message_id*/
 uint16_t uav_id; /*<  uav_id*/
 uint16_t plane_state; /*<  plane_state*/
 uint16_t plane_group; /*<  plane_group*/
}) mavlink_self_fax_formation_rc_t;

#define MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN 60
#define MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN 60
#define MAVLINK_MSG_ID_305_LEN 60
#define MAVLINK_MSG_ID_305_MIN_LEN 60

#define MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC 103
#define MAVLINK_MSG_ID_305_CRC 103



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SELF_FAX_FORMATION_RC { \
    305, \
    "SELF_FAX_FORMATION_RC", \
    11, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_self_fax_formation_rc_t, message_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_self_fax_formation_rc_t, uav_id) }, \
         { "plane_state", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_self_fax_formation_rc_t, plane_state) }, \
         { "plane_group", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_self_fax_formation_rc_t, plane_group) }, \
         { "number", NULL, MAVLINK_TYPE_INT32_T, 0, 48, offsetof(mavlink_self_fax_formation_rc_t, number) }, \
         { "longitude_x", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_self_fax_formation_rc_t, longitude_x) }, \
         { "latitude_y", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_self_fax_formation_rc_t, latitude_y) }, \
         { "altitude_z", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_self_fax_formation_rc_t, altitude_z) }, \
         { "heading", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_self_fax_formation_rc_t, heading) }, \
         { "velocity", NULL, MAVLINK_TYPE_DOUBLE, 0, 32, offsetof(mavlink_self_fax_formation_rc_t, velocity) }, \
         { "command_yaw", NULL, MAVLINK_TYPE_DOUBLE, 0, 40, offsetof(mavlink_self_fax_formation_rc_t, command_yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SELF_FAX_FORMATION_RC { \
    "SELF_FAX_FORMATION_RC", \
    11, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_self_fax_formation_rc_t, message_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_self_fax_formation_rc_t, uav_id) }, \
         { "plane_state", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_self_fax_formation_rc_t, plane_state) }, \
         { "plane_group", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_self_fax_formation_rc_t, plane_group) }, \
         { "number", NULL, MAVLINK_TYPE_INT32_T, 0, 48, offsetof(mavlink_self_fax_formation_rc_t, number) }, \
         { "longitude_x", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_self_fax_formation_rc_t, longitude_x) }, \
         { "latitude_y", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_self_fax_formation_rc_t, latitude_y) }, \
         { "altitude_z", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_self_fax_formation_rc_t, altitude_z) }, \
         { "heading", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_self_fax_formation_rc_t, heading) }, \
         { "velocity", NULL, MAVLINK_TYPE_DOUBLE, 0, 32, offsetof(mavlink_self_fax_formation_rc_t, velocity) }, \
         { "command_yaw", NULL, MAVLINK_TYPE_DOUBLE, 0, 40, offsetof(mavlink_self_fax_formation_rc_t, command_yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a self_fax_formation_rc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param number  number
 * @param longitude_x  longitude_x
 * @param latitude_y  latitude_y
 * @param altitude_z  altitude_z
 * @param heading  heading
 * @param velocity  velocity
 * @param command_yaw  command_yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t message_id, uint16_t uav_id, uint16_t plane_state, uint16_t plane_group, int32_t number, double longitude_x, double latitude_y, double altitude_z, double heading, double velocity, double command_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN];
    _mav_put_double(buf, 0, longitude_x);
    _mav_put_double(buf, 8, latitude_y);
    _mav_put_double(buf, 16, altitude_z);
    _mav_put_double(buf, 24, heading);
    _mav_put_double(buf, 32, velocity);
    _mav_put_double(buf, 40, command_yaw);
    _mav_put_int32_t(buf, 48, number);
    _mav_put_uint16_t(buf, 52, message_id);
    _mav_put_uint16_t(buf, 54, uav_id);
    _mav_put_uint16_t(buf, 56, plane_state);
    _mav_put_uint16_t(buf, 58, plane_group);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN);
#else
    mavlink_self_fax_formation_rc_t packet;
    packet.longitude_x = longitude_x;
    packet.latitude_y = latitude_y;
    packet.altitude_z = altitude_z;
    packet.heading = heading;
    packet.velocity = velocity;
    packet.command_yaw = command_yaw;
    packet.number = number;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
}

/**
 * @brief Pack a self_fax_formation_rc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param number  number
 * @param longitude_x  longitude_x
 * @param latitude_y  latitude_y
 * @param altitude_z  altitude_z
 * @param heading  heading
 * @param velocity  velocity
 * @param command_yaw  command_yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t message_id,uint16_t uav_id,uint16_t plane_state,uint16_t plane_group,int32_t number,double longitude_x,double latitude_y,double altitude_z,double heading,double velocity,double command_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN];
    _mav_put_double(buf, 0, longitude_x);
    _mav_put_double(buf, 8, latitude_y);
    _mav_put_double(buf, 16, altitude_z);
    _mav_put_double(buf, 24, heading);
    _mav_put_double(buf, 32, velocity);
    _mav_put_double(buf, 40, command_yaw);
    _mav_put_int32_t(buf, 48, number);
    _mav_put_uint16_t(buf, 52, message_id);
    _mav_put_uint16_t(buf, 54, uav_id);
    _mav_put_uint16_t(buf, 56, plane_state);
    _mav_put_uint16_t(buf, 58, plane_group);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN);
#else
    mavlink_self_fax_formation_rc_t packet;
    packet.longitude_x = longitude_x;
    packet.latitude_y = latitude_y;
    packet.altitude_z = altitude_z;
    packet.heading = heading;
    packet.velocity = velocity;
    packet.command_yaw = command_yaw;
    packet.number = number;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
}

/**
 * @brief Encode a self_fax_formation_rc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param self_fax_formation_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_self_fax_formation_rc_t* self_fax_formation_rc)
{
    return mavlink_msg_self_fax_formation_rc_pack(system_id, component_id, msg, self_fax_formation_rc->message_id, self_fax_formation_rc->uav_id, self_fax_formation_rc->plane_state, self_fax_formation_rc->plane_group, self_fax_formation_rc->number, self_fax_formation_rc->longitude_x, self_fax_formation_rc->latitude_y, self_fax_formation_rc->altitude_z, self_fax_formation_rc->heading, self_fax_formation_rc->velocity, self_fax_formation_rc->command_yaw);
}

/**
 * @brief Encode a self_fax_formation_rc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param self_fax_formation_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_self_fax_formation_rc_t* self_fax_formation_rc)
{
    return mavlink_msg_self_fax_formation_rc_pack_chan(system_id, component_id, chan, msg, self_fax_formation_rc->message_id, self_fax_formation_rc->uav_id, self_fax_formation_rc->plane_state, self_fax_formation_rc->plane_group, self_fax_formation_rc->number, self_fax_formation_rc->longitude_x, self_fax_formation_rc->latitude_y, self_fax_formation_rc->altitude_z, self_fax_formation_rc->heading, self_fax_formation_rc->velocity, self_fax_formation_rc->command_yaw);
}

/**
 * @brief Send a self_fax_formation_rc message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  message_id
 * @param uav_id  uav_id
 * @param plane_state  plane_state
 * @param plane_group  plane_group
 * @param number  number
 * @param longitude_x  longitude_x
 * @param latitude_y  latitude_y
 * @param altitude_z  altitude_z
 * @param heading  heading
 * @param velocity  velocity
 * @param command_yaw  command_yaw
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_self_fax_formation_rc_send(mavlink_channel_t chan, uint16_t message_id, uint16_t uav_id, uint16_t plane_state, uint16_t plane_group, int32_t number, double longitude_x, double latitude_y, double altitude_z, double heading, double velocity, double command_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN];
    _mav_put_double(buf, 0, longitude_x);
    _mav_put_double(buf, 8, latitude_y);
    _mav_put_double(buf, 16, altitude_z);
    _mav_put_double(buf, 24, heading);
    _mav_put_double(buf, 32, velocity);
    _mav_put_double(buf, 40, command_yaw);
    _mav_put_int32_t(buf, 48, number);
    _mav_put_uint16_t(buf, 52, message_id);
    _mav_put_uint16_t(buf, 54, uav_id);
    _mav_put_uint16_t(buf, 56, plane_state);
    _mav_put_uint16_t(buf, 58, plane_group);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC, buf, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
#else
    mavlink_self_fax_formation_rc_t packet;
    packet.longitude_x = longitude_x;
    packet.latitude_y = latitude_y;
    packet.altitude_z = altitude_z;
    packet.heading = heading;
    packet.velocity = velocity;
    packet.command_yaw = command_yaw;
    packet.number = number;
    packet.message_id = message_id;
    packet.uav_id = uav_id;
    packet.plane_state = plane_state;
    packet.plane_group = plane_group;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC, (const char *)&packet, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
#endif
}

/**
 * @brief Send a self_fax_formation_rc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_self_fax_formation_rc_send_struct(mavlink_channel_t chan, const mavlink_self_fax_formation_rc_t* self_fax_formation_rc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_self_fax_formation_rc_send(chan, self_fax_formation_rc->message_id, self_fax_formation_rc->uav_id, self_fax_formation_rc->plane_state, self_fax_formation_rc->plane_group, self_fax_formation_rc->number, self_fax_formation_rc->longitude_x, self_fax_formation_rc->latitude_y, self_fax_formation_rc->altitude_z, self_fax_formation_rc->heading, self_fax_formation_rc->velocity, self_fax_formation_rc->command_yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC, (const char *)self_fax_formation_rc, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
#endif
}

#if MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_self_fax_formation_rc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t message_id, uint16_t uav_id, uint16_t plane_state, uint16_t plane_group, int32_t number, double longitude_x, double latitude_y, double altitude_z, double heading, double velocity, double command_yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, longitude_x);
    _mav_put_double(buf, 8, latitude_y);
    _mav_put_double(buf, 16, altitude_z);
    _mav_put_double(buf, 24, heading);
    _mav_put_double(buf, 32, velocity);
    _mav_put_double(buf, 40, command_yaw);
    _mav_put_int32_t(buf, 48, number);
    _mav_put_uint16_t(buf, 52, message_id);
    _mav_put_uint16_t(buf, 54, uav_id);
    _mav_put_uint16_t(buf, 56, plane_state);
    _mav_put_uint16_t(buf, 58, plane_group);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC, buf, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
#else
    mavlink_self_fax_formation_rc_t *packet = (mavlink_self_fax_formation_rc_t *)msgbuf;
    packet->longitude_x = longitude_x;
    packet->latitude_y = latitude_y;
    packet->altitude_z = altitude_z;
    packet->heading = heading;
    packet->velocity = velocity;
    packet->command_yaw = command_yaw;
    packet->number = number;
    packet->message_id = message_id;
    packet->uav_id = uav_id;
    packet->plane_state = plane_state;
    packet->plane_group = plane_group;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC, (const char *)packet, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_MIN_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_CRC);
#endif
}
#endif

#endif

// MESSAGE SELF_FAX_FORMATION_RC UNPACKING


/**
 * @brief Get field message_id from self_fax_formation_rc message
 *
 * @return  message_id
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field uav_id from self_fax_formation_rc message
 *
 * @return  uav_id
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_get_uav_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  54);
}

/**
 * @brief Get field plane_state from self_fax_formation_rc message
 *
 * @return  plane_state
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_get_plane_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  56);
}

/**
 * @brief Get field plane_group from self_fax_formation_rc message
 *
 * @return  plane_group
 */
static inline uint16_t mavlink_msg_self_fax_formation_rc_get_plane_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  58);
}

/**
 * @brief Get field number from self_fax_formation_rc message
 *
 * @return  number
 */
static inline int32_t mavlink_msg_self_fax_formation_rc_get_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field longitude_x from self_fax_formation_rc message
 *
 * @return  longitude_x
 */
static inline double mavlink_msg_self_fax_formation_rc_get_longitude_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field latitude_y from self_fax_formation_rc message
 *
 * @return  latitude_y
 */
static inline double mavlink_msg_self_fax_formation_rc_get_latitude_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field altitude_z from self_fax_formation_rc message
 *
 * @return  altitude_z
 */
static inline double mavlink_msg_self_fax_formation_rc_get_altitude_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field heading from self_fax_formation_rc message
 *
 * @return  heading
 */
static inline double mavlink_msg_self_fax_formation_rc_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Get field velocity from self_fax_formation_rc message
 *
 * @return  velocity
 */
static inline double mavlink_msg_self_fax_formation_rc_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  32);
}

/**
 * @brief Get field command_yaw from self_fax_formation_rc message
 *
 * @return  command_yaw
 */
static inline double mavlink_msg_self_fax_formation_rc_get_command_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  40);
}

/**
 * @brief Decode a self_fax_formation_rc message into a struct
 *
 * @param msg The message to decode
 * @param self_fax_formation_rc C-struct to decode the message contents into
 */
static inline void mavlink_msg_self_fax_formation_rc_decode(const mavlink_message_t* msg, mavlink_self_fax_formation_rc_t* self_fax_formation_rc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    self_fax_formation_rc->longitude_x = mavlink_msg_self_fax_formation_rc_get_longitude_x(msg);
    self_fax_formation_rc->latitude_y = mavlink_msg_self_fax_formation_rc_get_latitude_y(msg);
    self_fax_formation_rc->altitude_z = mavlink_msg_self_fax_formation_rc_get_altitude_z(msg);
    self_fax_formation_rc->heading = mavlink_msg_self_fax_formation_rc_get_heading(msg);
    self_fax_formation_rc->velocity = mavlink_msg_self_fax_formation_rc_get_velocity(msg);
    self_fax_formation_rc->command_yaw = mavlink_msg_self_fax_formation_rc_get_command_yaw(msg);
    self_fax_formation_rc->number = mavlink_msg_self_fax_formation_rc_get_number(msg);
    self_fax_formation_rc->message_id = mavlink_msg_self_fax_formation_rc_get_message_id(msg);
    self_fax_formation_rc->uav_id = mavlink_msg_self_fax_formation_rc_get_uav_id(msg);
    self_fax_formation_rc->plane_state = mavlink_msg_self_fax_formation_rc_get_plane_state(msg);
    self_fax_formation_rc->plane_group = mavlink_msg_self_fax_formation_rc_get_plane_group(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN? msg->len : MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN;
        memset(self_fax_formation_rc, 0, MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC_LEN);
    memcpy(self_fax_formation_rc, _MAV_PAYLOAD(msg), len);
#endif
}
