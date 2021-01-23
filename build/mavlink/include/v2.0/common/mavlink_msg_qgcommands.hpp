// MESSAGE QGCOMMANDS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief QGCOMMANDS message
 *
 * Set UAV statement
 */
struct QGCOMMANDS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 306;
    static constexpr size_t LENGTH = 44;
    static constexpr size_t MIN_LENGTH = 44;
    static constexpr uint8_t CRC_EXTRA = 149;
    static constexpr auto NAME = "QGCOMMANDS";


    uint16_t message_id; /*<  message_id */
    uint16_t uav_id; /*<  uav_id */
    uint16_t gs_id; /*<  gs_id */
    uint16_t vehicleNumber; /*<  vehicleNumber */
    int32_t taskType; /*<  taskType */
    double plane_state; /*<  plane_state */
    double plane_group; /*<  plane_group */
    double gapx; /*<  gapx */
    double gapy; /*<  gapy */


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
        ss << "  gs_id: " << gs_id << std::endl;
        ss << "  vehicleNumber: " << vehicleNumber << std::endl;
        ss << "  taskType: " << taskType << std::endl;
        ss << "  plane_state: " << plane_state << std::endl;
        ss << "  plane_group: " << plane_group << std::endl;
        ss << "  gapx: " << gapx << std::endl;
        ss << "  gapy: " << gapy << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << plane_state;                   // offset: 0
        map << plane_group;                   // offset: 8
        map << gapx;                          // offset: 16
        map << gapy;                          // offset: 24
        map << taskType;                      // offset: 32
        map << message_id;                    // offset: 36
        map << uav_id;                        // offset: 38
        map << gs_id;                         // offset: 40
        map << vehicleNumber;                 // offset: 42
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> plane_state;                   // offset: 0
        map >> plane_group;                   // offset: 8
        map >> gapx;                          // offset: 16
        map >> gapy;                          // offset: 24
        map >> taskType;                      // offset: 32
        map >> message_id;                    // offset: 36
        map >> uav_id;                        // offset: 38
        map >> gs_id;                         // offset: 40
        map >> vehicleNumber;                 // offset: 42
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
