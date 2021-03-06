// Generated by gencpp from file fw_msgs/formations.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_FORMATIONS_H
#define FW_MSGS_MESSAGE_FORMATIONS_H


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
struct formations_
{
  typedef formations_<ContainerAllocator> Type;

  formations_()
    : formationShape()  {
    }
  formations_(const ContainerAllocator& _alloc)
    : formationShape(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _formationShape_type;
  _formationShape_type formationShape;





  typedef boost::shared_ptr< ::fw_msgs::formations_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::formations_<ContainerAllocator> const> ConstPtr;

}; // struct formations_

typedef ::fw_msgs::formations_<std::allocator<void> > formations;

typedef boost::shared_ptr< ::fw_msgs::formations > formationsPtr;
typedef boost::shared_ptr< ::fw_msgs::formations const> formationsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::formations_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::formations_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::formations_<ContainerAllocator1> & lhs, const ::fw_msgs::formations_<ContainerAllocator2> & rhs)
{
  return lhs.formationShape == rhs.formationShape;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::formations_<ContainerAllocator1> & lhs, const ::fw_msgs::formations_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::formations_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::formations_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::formations_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::formations_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::formations_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::formations_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::formations_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cb4dc526361d96c967f22a663f5d3a2a";
  }

  static const char* value(const ::fw_msgs::formations_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcb4dc526361d96c9ULL;
  static const uint64_t static_value2 = 0x67f22a663f5d3a2aULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::formations_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/formations";
  }

  static const char* value(const ::fw_msgs::formations_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::formations_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# formations.msg\n"
"\n"
"string formationShape \n"
;
  }

  static const char* value(const ::fw_msgs::formations_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::formations_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.formationShape);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct formations_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::formations_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::formations_<ContainerAllocator>& v)
  {
    s << indent << "formationShape: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.formationShape);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_FORMATIONS_H
