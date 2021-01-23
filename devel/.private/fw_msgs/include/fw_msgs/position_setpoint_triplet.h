// Generated by gencpp from file fw_msgs/position_setpoint_triplet.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_POSITION_SETPOINT_TRIPLET_H
#define FW_MSGS_MESSAGE_POSITION_SETPOINT_TRIPLET_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/Waypoint.h>

namespace fw_msgs
{
template <class ContainerAllocator>
struct position_setpoint_triplet_
{
  typedef position_setpoint_triplet_<ContainerAllocator> Type;

  position_setpoint_triplet_()
    : count_number(0.0)
    , selforgheading(0.0)
    , currentWaypoint()
    , nextWaypoint()
    , enu_currentWaypoint()
    , enu_nextWaypoint()
    , Throttle(0)
    , ExistNext(0)  {
    }
  position_setpoint_triplet_(const ContainerAllocator& _alloc)
    : count_number(0.0)
    , selforgheading(0.0)
    , currentWaypoint(_alloc)
    , nextWaypoint(_alloc)
    , enu_currentWaypoint(_alloc)
    , enu_nextWaypoint(_alloc)
    , Throttle(0)
    , ExistNext(0)  {
  (void)_alloc;
    }



   typedef double _count_number_type;
  _count_number_type count_number;

   typedef double _selforgheading_type;
  _selforgheading_type selforgheading;

   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _currentWaypoint_type;
  _currentWaypoint_type currentWaypoint;

   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _nextWaypoint_type;
  _nextWaypoint_type nextWaypoint;

   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _enu_currentWaypoint_type;
  _enu_currentWaypoint_type enu_currentWaypoint;

   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _enu_nextWaypoint_type;
  _enu_nextWaypoint_type enu_nextWaypoint;

   typedef int8_t _Throttle_type;
  _Throttle_type Throttle;

   typedef int8_t _ExistNext_type;
  _ExistNext_type ExistNext;





  typedef boost::shared_ptr< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> const> ConstPtr;

}; // struct position_setpoint_triplet_

typedef ::fw_msgs::position_setpoint_triplet_<std::allocator<void> > position_setpoint_triplet;

typedef boost::shared_ptr< ::fw_msgs::position_setpoint_triplet > position_setpoint_tripletPtr;
typedef boost::shared_ptr< ::fw_msgs::position_setpoint_triplet const> position_setpoint_tripletConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator1> & lhs, const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator2> & rhs)
{
  return lhs.count_number == rhs.count_number &&
    lhs.selforgheading == rhs.selforgheading &&
    lhs.currentWaypoint == rhs.currentWaypoint &&
    lhs.nextWaypoint == rhs.nextWaypoint &&
    lhs.enu_currentWaypoint == rhs.enu_currentWaypoint &&
    lhs.enu_nextWaypoint == rhs.enu_nextWaypoint &&
    lhs.Throttle == rhs.Throttle &&
    lhs.ExistNext == rhs.ExistNext;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator1> & lhs, const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5c2856e9a0135c7692129a603be86694";
  }

  static const char* value(const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5c2856e9a0135c76ULL;
  static const uint64_t static_value2 = 0x92129a603be86694ULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/position_setpoint_triplet";
  }

  static const char* value(const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# position_setpoint_triplet.msg\n"
"\n"
"float64 count_number\n"
"float64 selforgheading\n"
"mavros_msgs/Waypoint currentWaypoint\n"
"mavros_msgs/Waypoint nextWaypoint\n"
"mavros_msgs/Waypoint enu_currentWaypoint\n"
"mavros_msgs/Waypoint enu_nextWaypoint\n"
"int8 Throttle\n"
"int8 ExistNext\n"
"\n"
"================================================================================\n"
"MSG: mavros_msgs/Waypoint\n"
"# Waypoint.msg\n"
"#\n"
"# ROS representation of MAVLink MISSION_ITEM\n"
"# See mavlink documentation\n"
"\n"
"\n"
"\n"
"# see enum MAV_FRAME\n"
"uint8 frame\n"
"uint8 FRAME_GLOBAL = 0\n"
"uint8 FRAME_LOCAL_NED = 1\n"
"uint8 FRAME_MISSION = 2\n"
"uint8 FRAME_GLOBAL_REL_ALT = 3\n"
"uint8 FRAME_LOCAL_ENU = 4\n"
"\n"
"# see enum MAV_CMD and CommandCode.msg\n"
"uint16 command\n"
"\n"
"bool is_current\n"
"bool autocontinue\n"
"# meaning of this params described in enum MAV_CMD\n"
"float32 param1\n"
"float32 param2\n"
"float32 param3\n"
"float32 param4\n"
"float64 x_lat\n"
"float64 y_long\n"
"float64 z_alt\n"
;
  }

  static const char* value(const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.count_number);
      stream.next(m.selforgheading);
      stream.next(m.currentWaypoint);
      stream.next(m.nextWaypoint);
      stream.next(m.enu_currentWaypoint);
      stream.next(m.enu_nextWaypoint);
      stream.next(m.Throttle);
      stream.next(m.ExistNext);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct position_setpoint_triplet_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::position_setpoint_triplet_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::position_setpoint_triplet_<ContainerAllocator>& v)
  {
    s << indent << "count_number: ";
    Printer<double>::stream(s, indent + "  ", v.count_number);
    s << indent << "selforgheading: ";
    Printer<double>::stream(s, indent + "  ", v.selforgheading);
    s << indent << "currentWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.currentWaypoint);
    s << indent << "nextWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.nextWaypoint);
    s << indent << "enu_currentWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.enu_currentWaypoint);
    s << indent << "enu_nextWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.enu_nextWaypoint);
    s << indent << "Throttle: ";
    Printer<int8_t>::stream(s, indent + "  ", v.Throttle);
    s << indent << "ExistNext: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ExistNext);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_POSITION_SETPOINT_TRIPLET_H
