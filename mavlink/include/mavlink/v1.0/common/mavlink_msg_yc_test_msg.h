// MESSAGE YC_TEST_MSG PACKING

#define MAVLINK_MSG_ID_YC_TEST_MSG 202

typedef struct __mavlink_yc_test_msg_t
{
 int8_t data; ///< the only data
} mavlink_yc_test_msg_t;

#define MAVLINK_MSG_ID_YC_TEST_MSG_LEN 1
#define MAVLINK_MSG_ID_202_LEN 1

#define MAVLINK_MSG_ID_YC_TEST_MSG_CRC 170
#define MAVLINK_MSG_ID_202_CRC 170



#define MAVLINK_MESSAGE_INFO_YC_TEST_MSG { \
	"YC_TEST_MSG", \
	1, \
	{  { "data", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_yc_test_msg_t, data) }, \
         } \
}


/**
 * @brief Pack a yc_test_msg message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data the only data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_yc_test_msg_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YC_TEST_MSG_LEN];
	_mav_put_int8_t(buf, 0, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#else
	mavlink_yc_test_msg_t packet;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_YC_TEST_MSG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_YC_TEST_MSG_LEN, MAVLINK_MSG_ID_YC_TEST_MSG_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif
}

/**
 * @brief Pack a yc_test_msg message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data the only data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_yc_test_msg_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YC_TEST_MSG_LEN];
	_mav_put_int8_t(buf, 0, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#else
	mavlink_yc_test_msg_t packet;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_YC_TEST_MSG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_YC_TEST_MSG_LEN, MAVLINK_MSG_ID_YC_TEST_MSG_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif
}

/**
 * @brief Encode a yc_test_msg struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param yc_test_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_yc_test_msg_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_yc_test_msg_t* yc_test_msg)
{
	return mavlink_msg_yc_test_msg_pack(system_id, component_id, msg, yc_test_msg->data);
}

/**
 * @brief Encode a yc_test_msg struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param yc_test_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_yc_test_msg_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_yc_test_msg_t* yc_test_msg)
{
	return mavlink_msg_yc_test_msg_pack_chan(system_id, component_id, chan, msg, yc_test_msg->data);
}

/**
 * @brief Send a yc_test_msg message
 * @param chan MAVLink channel to send the message
 *
 * @param data the only data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_yc_test_msg_send(mavlink_channel_t chan, int8_t data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YC_TEST_MSG_LEN];
	_mav_put_int8_t(buf, 0, data);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YC_TEST_MSG, buf, MAVLINK_MSG_ID_YC_TEST_MSG_LEN, MAVLINK_MSG_ID_YC_TEST_MSG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YC_TEST_MSG, buf, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif
#else
	mavlink_yc_test_msg_t packet;
	packet.data = data;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YC_TEST_MSG, (const char *)&packet, MAVLINK_MSG_ID_YC_TEST_MSG_LEN, MAVLINK_MSG_ID_YC_TEST_MSG_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YC_TEST_MSG, (const char *)&packet, MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif
#endif
}

#endif

// MESSAGE YC_TEST_MSG UNPACKING


/**
 * @brief Get field data from yc_test_msg message
 *
 * @return the only data
 */
static inline int8_t mavlink_msg_yc_test_msg_get_data(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Decode a yc_test_msg message into a struct
 *
 * @param msg The message to decode
 * @param yc_test_msg C-struct to decode the message contents into
 */
static inline void mavlink_msg_yc_test_msg_decode(const mavlink_message_t* msg, mavlink_yc_test_msg_t* yc_test_msg)
{
#if MAVLINK_NEED_BYTE_SWAP
	yc_test_msg->data = mavlink_msg_yc_test_msg_get_data(msg);
#else
	memcpy(yc_test_msg, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_YC_TEST_MSG_LEN);
#endif
}
