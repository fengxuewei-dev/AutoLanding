// Generated by gencpp from file navigator/position_setpoint_triplet.msg
// DO NOT EDIT!


#ifndef NAVIGATOR_MESSAGE_POSITION_SETPOINT_TRIPLET_H
#define NAVIGATOR_MESSAGE_POSITION_SETPOINT_TRIPLET_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/Waypoint.h>

namespace navigator
{
template <class ContainerAllocator>
struct position_setpoint_triplet_
{
  typedef position_setpoint_triplet_<ContainerAllocator> Type;

  position_setpoint_triplet_()
    : currentWaypoint()
    , nextWaypoint()
    , Throttle(0)
    , ExistNext(0)  {
    }
  position_setpoint_triplet_(const ContainerAllocator& _alloc)
    : currentWaypoint(_alloc)
    , nextWaypoint(_alloc)
    , Throttle(0)
    , ExistNext(0)  {
  (void)_alloc;
    }



   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _currentWaypoint_type;
  _currentWaypoint_type currentWaypoint;

   typedef  ::mavros_msgs::Waypoint_<ContainerAllocator>  _nextWaypoint_type;
  _nextWaypoint_type nextWaypoint;

   typedef int8_t _Throttle_type;
  _Throttle_type Throttle;

   typedef int8_t _ExistNext_type;
  _ExistNext_type ExistNext;





  typedef boost::shared_ptr< ::navigator::position_setpoint_triplet_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::navigator::position_setpoint_triplet_<ContainerAllocator> const> ConstPtr;

}; // struct position_setpoint_triplet_

typedef ::navigator::position_setpoint_triplet_<std::allocator<void> > position_setpoint_triplet;

typedef boost::shared_ptr< ::navigator::position_setpoint_triplet > position_setpoint_tripletPtr;
typedef boost::shared_ptr< ::navigator::position_setpoint_triplet const> position_setpoint_tripletConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::navigator::position_setpoint_triplet_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::navigator::position_setpoint_triplet_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::navigator::position_setpoint_triplet_<ContainerAllocator1> & lhs, const ::navigator::position_setpoint_triplet_<ContainerAllocator2> & rhs)
{
  return lhs.currentWaypoint == rhs.currentWaypoint &&
    lhs.nextWaypoint == rhs.nextWaypoint &&
    lhs.Throttle == rhs.Throttle &&
    lhs.ExistNext == rhs.ExistNext;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::navigator::position_setpoint_triplet_<ContainerAllocator1> & lhs, const ::navigator::position_setpoint_triplet_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace navigator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::navigator::position_setpoint_triplet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator::position_setpoint_triplet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator::position_setpoint_triplet_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3fb3b9f9f42aa6f50d1505ea97f3c07f";
  }

  static const char* value(const ::navigator::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3fb3b9f9f42aa6f5ULL;
  static const uint64_t static_value2 = 0x0d1505ea97f3c07fULL;
};

template<class ContainerAllocator>
struct DataType< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "navigator/position_setpoint_triplet";
  }

  static const char* value(const ::navigator::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# position_setpoint_triplet.msg\n"
"\n"
"mavros_msgs/Waypoint currentWaypoint\n"
"mavros_msgs/Waypoint nextWaypoint\n"
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

  static const char* value(const ::navigator::position_setpoint_triplet_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.currentWaypoint);
      stream.next(m.nextWaypoint);
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
struct Printer< ::navigator::position_setpoint_triplet_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::navigator::position_setpoint_triplet_<ContainerAllocator>& v)
  {
    s << indent << "currentWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.currentWaypoint);
    s << indent << "nextWaypoint: ";
    s << std::endl;
    Printer< ::mavros_msgs::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.nextWaypoint);
    s << indent << "Throttle: ";
    Printer<int8_t>::stream(s, indent + "  ", v.Throttle);
    s << indent << "ExistNext: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ExistNext);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NAVIGATOR_MESSAGE_POSITION_SETPOINT_TRIPLET_H