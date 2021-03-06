// Generated by gencpp from file communication/UDPData.msg
// DO NOT EDIT!


#ifndef COMMUNICATION_MESSAGE_UDPDATA_H
#define COMMUNICATION_MESSAGE_UDPDATA_H


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
struct UDPData_
{
  typedef UDPData_<ContainerAllocator> Type;

  UDPData_()
    : number(0)
    , messageid(0)
    , uavid(0)
    , plane_state(0)
    , plane_group(0)
    , longitudex(0.0)
    , latitudey(0.0)
    , altitudez(0.0)
    , heading(0.0)
    , velocity(0.0)
    , commandyaw(0.0)
    , GPStime()
    , parity(0)  {
    }
  UDPData_(const ContainerAllocator& _alloc)
    : number(0)
    , messageid(0)
    , uavid(0)
    , plane_state(0)
    , plane_group(0)
    , longitudex(0.0)
    , latitudey(0.0)
    , altitudez(0.0)
    , heading(0.0)
    , velocity(0.0)
    , commandyaw(0.0)
    , GPStime()
    , parity(0)  {
  (void)_alloc;
    }



   typedef int64_t _number_type;
  _number_type number;

   typedef uint16_t _messageid_type;
  _messageid_type messageid;

   typedef uint16_t _uavid_type;
  _uavid_type uavid;

   typedef uint16_t _plane_state_type;
  _plane_state_type plane_state;

   typedef uint16_t _plane_group_type;
  _plane_group_type plane_group;

   typedef double _longitudex_type;
  _longitudex_type longitudex;

   typedef double _latitudey_type;
  _latitudey_type latitudey;

   typedef double _altitudez_type;
  _altitudez_type altitudez;

   typedef double _heading_type;
  _heading_type heading;

   typedef double _velocity_type;
  _velocity_type velocity;

   typedef double _commandyaw_type;
  _commandyaw_type commandyaw;

   typedef ros::Time _GPStime_type;
  _GPStime_type GPStime;

   typedef int32_t _parity_type;
  _parity_type parity;





  typedef boost::shared_ptr< ::communication::UDPData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::communication::UDPData_<ContainerAllocator> const> ConstPtr;

}; // struct UDPData_

typedef ::communication::UDPData_<std::allocator<void> > UDPData;

typedef boost::shared_ptr< ::communication::UDPData > UDPDataPtr;
typedef boost::shared_ptr< ::communication::UDPData const> UDPDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::communication::UDPData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::communication::UDPData_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::communication::UDPData_<ContainerAllocator1> & lhs, const ::communication::UDPData_<ContainerAllocator2> & rhs)
{
  return lhs.number == rhs.number &&
    lhs.messageid == rhs.messageid &&
    lhs.uavid == rhs.uavid &&
    lhs.plane_state == rhs.plane_state &&
    lhs.plane_group == rhs.plane_group &&
    lhs.longitudex == rhs.longitudex &&
    lhs.latitudey == rhs.latitudey &&
    lhs.altitudez == rhs.altitudez &&
    lhs.heading == rhs.heading &&
    lhs.velocity == rhs.velocity &&
    lhs.commandyaw == rhs.commandyaw &&
    lhs.GPStime == rhs.GPStime &&
    lhs.parity == rhs.parity;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::communication::UDPData_<ContainerAllocator1> & lhs, const ::communication::UDPData_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace communication

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::communication::UDPData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::communication::UDPData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::UDPData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication::UDPData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::UDPData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication::UDPData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::communication::UDPData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1ff2b4674f767520061c38046240545f";
  }

  static const char* value(const ::communication::UDPData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1ff2b4674f767520ULL;
  static const uint64_t static_value2 = 0x061c38046240545fULL;
};

template<class ContainerAllocator>
struct DataType< ::communication::UDPData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "communication/UDPData";
  }

  static const char* value(const ::communication::UDPData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::communication::UDPData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# UDPMessage.msg\n"
"\n"
"int64 number\n"
"uint16 messageid\n"
"uint16 uavid\n"
"uint16 plane_state\n"
"uint16 plane_group\n"
"float64 longitudex\n"
"float64 latitudey\n"
"float64 altitudez \n"
"float64 heading\n"
"float64 velocity\n"
"float64 commandyaw\n"
"time GPStime\n"
"int32 parity\n"
;
  }

  static const char* value(const ::communication::UDPData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::communication::UDPData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.number);
      stream.next(m.messageid);
      stream.next(m.uavid);
      stream.next(m.plane_state);
      stream.next(m.plane_group);
      stream.next(m.longitudex);
      stream.next(m.latitudey);
      stream.next(m.altitudez);
      stream.next(m.heading);
      stream.next(m.velocity);
      stream.next(m.commandyaw);
      stream.next(m.GPStime);
      stream.next(m.parity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct UDPData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::communication::UDPData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::communication::UDPData_<ContainerAllocator>& v)
  {
    s << indent << "number: ";
    Printer<int64_t>::stream(s, indent + "  ", v.number);
    s << indent << "messageid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.messageid);
    s << indent << "uavid: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uavid);
    s << indent << "plane_state: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.plane_state);
    s << indent << "plane_group: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.plane_group);
    s << indent << "longitudex: ";
    Printer<double>::stream(s, indent + "  ", v.longitudex);
    s << indent << "latitudey: ";
    Printer<double>::stream(s, indent + "  ", v.latitudey);
    s << indent << "altitudez: ";
    Printer<double>::stream(s, indent + "  ", v.altitudez);
    s << indent << "heading: ";
    Printer<double>::stream(s, indent + "  ", v.heading);
    s << indent << "velocity: ";
    Printer<double>::stream(s, indent + "  ", v.velocity);
    s << indent << "commandyaw: ";
    Printer<double>::stream(s, indent + "  ", v.commandyaw);
    s << indent << "GPStime: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.GPStime);
    s << indent << "parity: ";
    Printer<int32_t>::stream(s, indent + "  ", v.parity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMUNICATION_MESSAGE_UDPDATA_H
