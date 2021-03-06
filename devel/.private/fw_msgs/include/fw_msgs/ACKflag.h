// Generated by gencpp from file fw_msgs/ACKflag.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_ACKFLAG_H
#define FW_MSGS_MESSAGE_ACKFLAG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fw_msgs
{
template <class ContainerAllocator>
struct ACKflag_
{
  typedef ACKflag_<ContainerAllocator> Type;

  ACKflag_()
    : ACKflag(0)  {
    }
  ACKflag_(const ContainerAllocator& _alloc)
    : ACKflag(0)  {
  (void)_alloc;
    }



   typedef int32_t _ACKflag_type;
  _ACKflag_type ACKflag;





  typedef boost::shared_ptr< ::fw_msgs::ACKflag_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::ACKflag_<ContainerAllocator> const> ConstPtr;

}; // struct ACKflag_

typedef ::fw_msgs::ACKflag_<std::allocator<void> > ACKflag;

typedef boost::shared_ptr< ::fw_msgs::ACKflag > ACKflagPtr;
typedef boost::shared_ptr< ::fw_msgs::ACKflag const> ACKflagConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::ACKflag_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::ACKflag_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::ACKflag_<ContainerAllocator1> & lhs, const ::fw_msgs::ACKflag_<ContainerAllocator2> & rhs)
{
  return lhs.ACKflag == rhs.ACKflag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::ACKflag_<ContainerAllocator1> & lhs, const ::fw_msgs::ACKflag_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::ACKflag_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::ACKflag_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::ACKflag_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::ACKflag_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::ACKflag_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::ACKflag_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::ACKflag_<ContainerAllocator> >
{
  static const char* value()
  {
    return "45bdb69dba2c6d2adc0542aeb7f54879";
  }

  static const char* value(const ::fw_msgs::ACKflag_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x45bdb69dba2c6d2aULL;
  static const uint64_t static_value2 = 0xdc0542aeb7f54879ULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::ACKflag_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/ACKflag";
  }

  static const char* value(const ::fw_msgs::ACKflag_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::ACKflag_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ACKflag.msg\n"
"\n"
"int32 ACKflag\n"
;
  }

  static const char* value(const ::fw_msgs::ACKflag_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::ACKflag_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ACKflag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ACKflag_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::ACKflag_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::ACKflag_<ContainerAllocator>& v)
  {
    s << indent << "ACKflag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ACKflag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_ACKFLAG_H
