// MESSAGE SELF_FAX_FORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SELF_FAX_FORMATION message
 *
 * Custom drone messages for fixed-wing formation flight
 */
struct SELF_FAX_FORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 304;
    static constexpr size_t LENGTH = 48;
    static constexpr size_t MIN_LENGTH = 48;
    static constexpr uint8_t CRC_EXTRA = 208;
    static constexpr auto NAME = "SELF_FAX_FORMATION";


    double ned_vel_x; /*< [m/s] ned_vel_x */
    double ned_vel_y; /*< [m/s] ned_vel_y */
    double ned_vel_z; /*< [m/s] ned_vel_z */
    double latitude; /*<  latitude */
    double altitude; /*<  altitude */
    double longtitude; /*<  longtitude */


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
        ss << "  ned_vel_x: " << ned_vel_x << std::endl;
        ss << "  ned_vel_y: " << ned_vel_y << std::endl;
        ss << "  ned_vel_z: " << ned_vel_z << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  altitude: " << altitude << std::endl;
        ss << "  longtitude: " << longtitude << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ned_vel_x;                     // offset: 0
        map << ned_vel_y;                     // offset: 8
        map << ned_vel_z;                     // offset: 16
        map << latitude;                      // offset: 24
        map << altitude;                      // offset: 32
        map << longtitude;                    // offset: 40
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ned_vel_x;                     // offset: 0
        map >> ned_vel_y;                     // offset: 8
        map >> ned_vel_z;                     // offset: 16
        map >> latitude;                      // offset: 24
        map >> altitude;                      // offset: 32
        map >> longtitude;                    // offset: 40
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
