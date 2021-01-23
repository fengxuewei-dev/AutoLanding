// MESSAGE SELF_FAX_FORMATION_RC support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SELF_FAX_FORMATION_RC message
 *
 * Custom drone messages for fixed-wing formation flight
 */
struct SELF_FAX_FORMATION_RC : mavlink::Message {
    static constexpr msgid_t MSG_ID = 305;
    static constexpr size_t LENGTH = 60;
    static constexpr size_t MIN_LENGTH = 60;
    static constexpr uint8_t CRC_EXTRA = 103;
    static constexpr auto NAME = "SELF_FAX_FORMATION_RC";


    uint16_t message_id; /*<  message_id */
    uint16_t uav_id; /*<  uav_id */
    uint16_t plane_state; /*<  plane_state */
    uint16_t plane_group; /*<  plane_group */
    int32_t number; /*<  number */
    double longitude_x; /*<  longitude_x */
    double latitude_y; /*<  latitude_y */
    double altitude_z; /*<  altitude_z */
    double heading; /*<  heading */
    double velocity; /*<  velocity */
    double command_yaw; /*<  command_yaw */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  message_id: " << message_id << std::endl;
        ss << "  uav_id: " << uav_id << std::endl;
        ss << "  plane_state: " << plane_state << std::endl;
        ss << "  plane_group: " << plane_group << std::endl;
        ss << "  number: " << number << std::endl;
        ss << "  longitude_x: " << longitude_x << std::endl;
        ss << "  latitude_y: " << latitude_y << std::endl;
        ss << "  altitude_z: " << altitude_z << std::endl;
        ss << "  heading: " << heading << std::endl;
        ss << "  velocity: " << velocity << std::endl;
        ss << "  command_yaw: " << command_yaw << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << longitude_x;                   // offset: 0
        map << latitude_y;                    // offset: 8
        map << altitude_z;                    // offset: 16
        map << heading;                       // offset: 24
        map << velocity;                      // offset: 32
        map << command_yaw;                   // offset: 40
        map << number;                        // offset: 48
        map << message_id;                    // offset: 52
        map << uav_id;                        // offset: 54
        map << plane_state;                   // offset: 56
        map << plane_group;                   // offset: 58
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> longitude_x;                   // offset: 0
        map >> latitude_y;                    // offset: 8
        map >> altitude_z;                    // offset: 16
        map >> heading;                       // offset: 24
        map >> velocity;                      // offset: 32
        map >> command_yaw;                   // offset: 40
        map >> number;                        // offset: 48
        map >> message_id;                    // offset: 52
        map >> uav_id;                        // offset: 54
        map >> plane_state;                   // offset: 56
        map >> plane_group;                   // offset: 58
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
