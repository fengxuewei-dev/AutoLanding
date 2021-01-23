// Generated by gencpp from file fw_att_control/commands.msg
// DO NOT EDIT!


#ifndef FW_ATT_CONTROL_MESSAGE_COMMANDS_H
#define FW_ATT_CONTROL_MESSAGE_COMMANDS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fw_att_control
{
template <class ContainerAllocator>
struct commands_
{
  typedef commands_<ContainerAllocator> Type;

  commands_()
    : yaw(0.0)
    , throttle(0.0)
    , roll(0.0)
    , pitch(0.0)  {
    }
  commands_(const ContainerAllocator& _alloc)
    : yaw(0.0)
    , throttle(0.0)
    , roll(0.0)
    , pitch(0.0)  {
  (void)_alloc;
    }



   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _throttle_type;
  _throttle_type throttle;

   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;





  typedef boost::shared_ptr< ::fw_att_control::commands_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_att_control::commands_<ContainerAllocator> const> ConstPtr;

}; // struct commands_

typedef ::fw_att_control::commands_<std::allocator<void> > commands;

typedef boost::shared_ptr< ::fw_att_control::commands > commandsPtr;
typedef boost::shared_ptr< ::fw_att_control::commands const> commandsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_att_control::commands_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_att_control::commands_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_att_control::commands_<ContainerAllocator1> & lhs, const ::fw_att_control::commands_<ContainerAllocator2> & rhs)
{
  return lhs.yaw == rhs.yaw &&
    lhs.throttle == rhs.throttle &&
    lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_att_control::commands_<ContainerAllocator1> & lhs, const ::fw_att_control::commands_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_att_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_att_control::commands_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_att_control::commands_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_att_control::commands_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_att_control::commands_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_att_control::commands_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_att_control::commands_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_att_control::commands_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3ed53da7ed658276464982ccd25dbfcd";
  }

  static const char* value(const ::fw_att_control::commands_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3ed53da7ed658276ULL;
  static const uint64_t static_value2 = 0x464982ccd25dbfcdULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_att_control::commands_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_att_control/commands";
  }

  static const char* value(const ::fw_att_control::commands_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_att_control::commands_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# commands.msg\n"
"\n"
"float32 yaw\n"
"float32 throttle\n"
"float32 roll\n"
"float32 pitch\n"
;
  }

  static const char* value(const ::fw_att_control::commands_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_att_control::commands_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.yaw);
      stream.next(m.throttle);
      stream.next(m.roll);
      stream.next(m.pitch);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct commands_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_att_control::commands_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_att_control::commands_<ContainerAllocator>& v)
  {
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "throttle: ";
    Printer<float>::stream(s, indent + "  ", v.throttle);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_ATT_CONTROL_MESSAGE_COMMANDS_H
