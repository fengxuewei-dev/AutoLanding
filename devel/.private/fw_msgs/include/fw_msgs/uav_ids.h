// Generated by gencpp from file fw_msgs/uav_ids.msg
// DO NOT EDIT!


#ifndef FW_MSGS_MESSAGE_UAV_IDS_H
#define FW_MSGS_MESSAGE_UAV_IDS_H


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
struct uav_ids_
{
  typedef uav_ids_<ContainerAllocator> Type;

  uav_ids_()
    : current_id(0)
    , leader_id(0)  {
    }
  uav_ids_(const ContainerAllocator& _alloc)
    : current_id(0)
    , leader_id(0)  {
  (void)_alloc;
    }



   typedef uint16_t _current_id_type;
  _current_id_type current_id;

   typedef uint16_t _leader_id_type;
  _leader_id_type leader_id;





  typedef boost::shared_ptr< ::fw_msgs::uav_ids_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fw_msgs::uav_ids_<ContainerAllocator> const> ConstPtr;

}; // struct uav_ids_

typedef ::fw_msgs::uav_ids_<std::allocator<void> > uav_ids;

typedef boost::shared_ptr< ::fw_msgs::uav_ids > uav_idsPtr;
typedef boost::shared_ptr< ::fw_msgs::uav_ids const> uav_idsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fw_msgs::uav_ids_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fw_msgs::uav_ids_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fw_msgs::uav_ids_<ContainerAllocator1> & lhs, const ::fw_msgs::uav_ids_<ContainerAllocator2> & rhs)
{
  return lhs.current_id == rhs.current_id &&
    lhs.leader_id == rhs.leader_id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fw_msgs::uav_ids_<ContainerAllocator1> & lhs, const ::fw_msgs::uav_ids_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::uav_ids_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fw_msgs::uav_ids_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::uav_ids_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fw_msgs::uav_ids_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::uav_ids_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fw_msgs::uav_ids_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fw_msgs::uav_ids_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5a866f4d93c1cb2b5a3f11036043cf7f";
  }

  static const char* value(const ::fw_msgs::uav_ids_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5a866f4d93c1cb2bULL;
  static const uint64_t static_value2 = 0x5a3f11036043cf7fULL;
};

template<class ContainerAllocator>
struct DataType< ::fw_msgs::uav_ids_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fw_msgs/uav_ids";
  }

  static const char* value(const ::fw_msgs::uav_ids_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fw_msgs::uav_ids_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# uav_ids.msg\n"
"\n"
"uint16 current_id\n"
"uint16 leader_id\n"
;
  }

  static const char* value(const ::fw_msgs::uav_ids_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fw_msgs::uav_ids_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.current_id);
      stream.next(m.leader_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct uav_ids_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fw_msgs::uav_ids_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fw_msgs::uav_ids_<ContainerAllocator>& v)
  {
    s << indent << "current_id: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.current_id);
    s << indent << "leader_id: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.leader_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FW_MSGS_MESSAGE_UAV_IDS_H
