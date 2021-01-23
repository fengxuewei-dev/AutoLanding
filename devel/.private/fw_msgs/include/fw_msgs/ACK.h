// Generated by gencpp from file fw_msgs/ACK.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_ACK_H
#define FW_MSGS_MESSAGE_ACK_H


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
struct ACK_
{
  typedef ACK_<ContainerAllocator> Type;

  ACK_()
    : messageid(0)
    , uavid(0)
    , GPStime()
    , judge(false)
    , parity(0)  {
    }
  ACK_(const ContainerAllocator& _alloc)
    : messageid(0)
    , uavid(0)
    , GPStime()
    , judge(false)
    , parity(0)  {
  (void)_alloc;
    }



   typedef uint16_t _messageid_type;
  _messageid_type messageid;

   typedef uint16_t _uavid_type;
  _uavid_type uavid;

   typedef ros::Time _GPStime_type;
  _GPStime_type GPStime;

   typedef uint8_t _judge_type;
  _judge_type judge;

   typedef int32_t _parity_type;
  _parity_type parity;





  typedef boost::shared_ptr< ::fw_msgs::ACK_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::ACK_<ContainerAllocator> const> ConstPtr;

}; // struct ACK_

typedef ::fw_msgs::ACK_<std::allocator<void> > ACK;

typedef boost::shared_ptr< ::fw_msgs::ACK > ACKPtr;
typedef boost::shared_ptr< ::fw_msgs::ACK const> ACKConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::ACK_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::ACK_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::ACK_<ContainerAllocator1> & lhs, const ::fw_msgs::ACK_<ContainerAllocator2> & rhs)
{
  return lhs.messageid == rhs.messageid &&
    lhs.uavid == rhs.uavid &&
    lhs.GPStime == rhs.GPStime &&
    lhs.judge == rhs.judge &&
    lhs.parity == rhs.parity;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::ACK_<ContainerAllocator1> & lhs, const ::fw_msgs::ACK_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::ACK_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::ACK_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::ACK_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::ACK_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::ACK_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::ACK_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::ACK_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1572b006872bc5799fbee1b02a88be5b";
  }

  static const char* value(const ::fw_msgs::ACK_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1572b006872bc579ULL;
  static const uint64_t static_value2 = 0x9fbee1b02a88be5bULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::ACK_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/ACK";
  }

  static const char* value(const ::fw_msgs::ACK_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::ACK_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# UDPMessage.msg\n"
"\n"
"uint16 messageid\n"
"uint16 uavid\n"
"time GPStime\n"
"bool judge\n"
"int32 parity\n"
;
  }

  static const char* value(const ::fw_msgs::ACK_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::ACK_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.messageid);
      stream.next(m.uavid);
      stream.next(m.GPStime);
      stream.next(m.judge);
      stream.next(m.parity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ACK_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::ACK_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::ACK_<ContainerAllocator>& v)
  {
    s << indent << "messageid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.messageid);
    s << indent << "uavid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uavid);
    s << indent << "GPStime: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.GPStime);
    s << indent << "judge: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.judge);
    s << indent << "parity: ";
    Printer<int32_t>::stream(s, indent + "  ", v.parity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_ACK_H
