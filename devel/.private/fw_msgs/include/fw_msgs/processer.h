// Generated by gencpp from file fw_msgs/processer.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_PROCESSER_H
#define FW_MSGS_MESSAGE_PROCESSER_H


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
struct processer_
{
  typedef processer_<ContainerAllocator> Type;

  processer_()
    : execflag(0.0)  {
    }
  processer_(const ContainerAllocator& _alloc)
    : execflag(0.0)  {
  (void)_alloc;
    }



   typedef float _execflag_type;
  _execflag_type execflag;





  typedef boost::shared_ptr< ::fw_msgs::processer_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::processer_<ContainerAllocator> const> ConstPtr;

}; // struct processer_

typedef ::fw_msgs::processer_<std::allocator<void> > processer;

typedef boost::shared_ptr< ::fw_msgs::processer > processerPtr;
typedef boost::shared_ptr< ::fw_msgs::processer const> processerConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::processer_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::processer_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::processer_<ContainerAllocator1> & lhs, const ::fw_msgs::processer_<ContainerAllocator2> & rhs)
{
  return lhs.execflag == rhs.execflag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::processer_<ContainerAllocator1> & lhs, const ::fw_msgs::processer_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::processer_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::processer_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::processer_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::processer_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::processer_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::processer_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::processer_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fff3fb7d3ee0a7ebfa5a6a893b0503a1";
  }

  static const char* value(const ::fw_msgs::processer_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfff3fb7d3ee0a7ebULL;
  static const uint64_t static_value2 = 0xfa5a6a893b0503a1ULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::processer_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/processer";
  }

  static const char* value(const ::fw_msgs::processer_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::processer_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# processer.msg\n"
"\n"
"float32 execflag\n"
;
  }

  static const char* value(const ::fw_msgs::processer_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::processer_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.execflag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct processer_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::processer_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::processer_<ContainerAllocator>& v)
  {
    s << indent << "execflag: ";
    Printer<float>::stream(s, indent + "  ", v.execflag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_PROCESSER_H
