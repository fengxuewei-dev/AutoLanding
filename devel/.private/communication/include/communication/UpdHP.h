// Generated by gencpp from file communication/UpdHP.msg
// DO NOT EDIT!


#ifndef COMMUNICATION_MESSAGE_UPDHP_H
#define COMMUNICATION_MESSAGE_UPDHP_H


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
struct UpdHP_
{
  typedef UpdHP_<ContainerAllocator> Type;

  UpdHP_()
    : messageid(0)
    , uavid(0)
    , longitude(0.0)
    , latitude(0.0)
    , altitude(0.0)
    , parity(0)  {
    }
  UpdHP_(const ContainerAllocator& _alloc)
    : messageid(0)
    , uavid(0)
    , longitude(0.0)
    , latitude(0.0)
    , altitude(0.0)
    , parity(0)  {
  (void)_alloc;
    }



   typedef uint16_t _messageid_type;
  _messageid_type messageid;

   typedef uint16_t _uavid_type;
  _uavid_type uavid;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _altitude_type;
  _altitude_type altitude;

   typedef int32_t _parity_type;
  _parity_type parity;





  typedef boost::shared_ptr< ::communication::UpdHP_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::communication::UpdHP_<ContainerAllocator> const> ConstPtr;

}; // struct UpdHP_

typedef ::communication::UpdHP_<std::allocator<void> > UpdHP;

typedef boost::shared_ptr< ::communication::UpdHP > UpdHPPtr;
typedef boost::shared_ptr< ::communication::UpdHP const> UpdHPConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::communication::UpdHP_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::communication::UpdHP_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::communication::UpdHP_<ContainerAllocator1> & lhs, const ::communication::UpdHP_<ContainerAllocator2> & rhs)
{
  return lhs.messageid == rhs.messageid &&
    lhs.uavid == rhs.uavid &&
    lhs.longitude == rhs.longitude &&
    lhs.latitude == rhs.latitude &&
    lhs.altitude == rhs.altitude &&
    lhs.parity == rhs.parity;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::communication::UpdHP_<ContainerAllocator1> & lhs, const ::communication::UpdHP_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace communication

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::communication::UpdHP_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::communication::UpdHP_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::UpdHP_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::UpdHP_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::UpdHP_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::UpdHP_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::communication::UpdHP_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7f25d391682710b024a661224416d7c4";
  }

  static const char* value(const ::communication::UpdHP_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7f25d391682710b0ULL;
  static const uint64_t static_value2 = 0x24a661224416d7c4ULL;
};

template<class ContainerAllocator>
struct DataType< ::communication::UpdHP_<ContainerAllocator> >
{
  static const char* value()
  {
    return "communication/UpdHP";
  }

  static const char* value(const ::communication::UpdHP_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::communication::UpdHP_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# UDPMessage.msg\n"
"\n"
"uint16 messageid\n"
"uint16 uavid\n"
"float64 longitude\n"
"float64 latitude\n"
"float64 altitude \n"
"int32 parity\n"
;
  }

  static const char* value(const ::communication::UpdHP_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::communication::UpdHP_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.messageid);
      stream.next(m.uavid);
      stream.next(m.longitude);
      stream.next(m.latitude);
      stream.next(m.altitude);
      stream.next(m.parity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct UpdHP_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::communication::UpdHP_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::communication::UpdHP_<ContainerAllocator>& v)
  {
    s << indent << "messageid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.messageid);
    s << indent << "uavid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uavid);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "altitude: ";
    Printer<double>::stream(s, indent + "  ", v.altitude);
    s << indent << "parity: ";
    Printer<int32_t>::stream(s, indent + "  ", v.parity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMUNICATION_MESSAGE_UPDHP_H
