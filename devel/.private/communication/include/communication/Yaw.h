// Generated by gencpp from file communication/Yaw.msg
// DO NOT EDIT!


#ifndef COMMUNICATION_MESSAGE_YAW_H
#define COMMUNICATION_MESSAGE_YAW_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace communication
{
template <class ContainerAllocator>
struct Yaw_
{
  typedef Yaw_<ContainerAllocator> Type;

  Yaw_()
    : yaw(0.0)  {
    }
  Yaw_(const ContainerAllocator& _alloc)
    : yaw(0.0)  {
  (void)_alloc;
    }



   typedef double _yaw_type;
  _yaw_type yaw;





  typedef boost::shared_ptr< ::communication::Yaw_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::communication::Yaw_<ContainerAllocator> const> ConstPtr;

}; // struct Yaw_

typedef ::communication::Yaw_<std::allocator<void> > Yaw;

typedef boost::shared_ptr< ::communication::Yaw > YawPtr;
typedef boost::shared_ptr< ::communication::Yaw const> YawConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::communication::Yaw_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::communication::Yaw_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::communication::Yaw_<ContainerAllocator1> & lhs, const ::communication::Yaw_<ContainerAllocator2> & rhs)
{
  return lhs.yaw == rhs.yaw;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::communication::Yaw_<ContainerAllocator1> & lhs, const ::communication::Yaw_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace communication

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::communication::Yaw_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::communication::Yaw_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::Yaw_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::Yaw_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::Yaw_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::Yaw_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::communication::Yaw_<ContainerAllocator> >
{
  static const char* value()
  {
    return "08cb8274b6ddb17af5a842bca0b17db1";
  }

  static const char* value(const ::communication::Yaw_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x08cb8274b6ddb17aULL;
  static const uint64_t static_value2 = 0xf5a842bca0b17db1ULL;
};

template<class ContainerAllocator>
struct DataType< ::communication::Yaw_<ContainerAllocator> >
{
  static const char* value()
  {
    return "communication/Yaw";
  }

  static const char* value(const ::communication::Yaw_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::communication::Yaw_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# yaw.msg\n"
"\n"
"float64 yaw\n"
;
  }

  static const char* value(const ::communication::Yaw_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::communication::Yaw_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.yaw);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Yaw_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::communication::Yaw_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::communication::Yaw_<ContainerAllocator>& v)
  {
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMUNICATION_MESSAGE_YAW_H
