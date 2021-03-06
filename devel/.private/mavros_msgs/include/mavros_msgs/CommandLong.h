// Generated by gencpp from file mavros_msgs/CommandLong.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_COMMANDLONG_H
#define MAVROS_MSGS_MESSAGE_COMMANDLONG_H

#include <ros/service_traits.h>


#include <mavros_msgs/CommandLongRequest.h>
#include <mavros_msgs/CommandLongResponse.h>


namespace mavros_msgs
{

struct CommandLong
{

typedef CommandLongRequest Request;
typedef CommandLongResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct CommandLong
} // namespace mavros_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros_msgs::CommandLong > {
  static const char* value()
  {
    return "eb9034afc87577c0a235d45b8f3437d2";
  }

  static const char* value(const ::mavros_msgs::CommandLong&) { return value(); }
};

template<>
struct DataType< ::mavros_msgs::CommandLong > {
  static const char* value()
  {
    return "mavros_msgs/CommandLong";
  }

  static const char* value(const ::mavros_msgs::CommandLong&) { return value(); }
};


// service_traits::MD5Sum< ::mavros_msgs::CommandLongRequest> should match
// service_traits::MD5Sum< ::mavros_msgs::CommandLong >
template<>
struct MD5Sum< ::mavros_msgs::CommandLongRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros_msgs::CommandLong >::value();
  }
  static const char* value(const ::mavros_msgs::CommandLongRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros_msgs::CommandLongRequest> should match
// service_traits::DataType< ::mavros_msgs::CommandLong >
template<>
struct DataType< ::mavros_msgs::CommandLongRequest>
{
  static const char* value()
  {
    return DataType< ::mavros_msgs::CommandLong >::value();
  }
  static const char* value(const ::mavros_msgs::CommandLongRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros_msgs::CommandLongResponse> should match
// service_traits::MD5Sum< ::mavros_msgs::CommandLong >
template<>
struct MD5Sum< ::mavros_msgs::CommandLongResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros_msgs::CommandLong >::value();
  }
  static const char* value(const ::mavros_msgs::CommandLongResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros_msgs::CommandLongResponse> should match
// service_traits::DataType< ::mavros_msgs::CommandLong >
template<>
struct DataType< ::mavros_msgs::CommandLongResponse>
{
  static const char* value()
  {
    return DataType< ::mavros_msgs::CommandLong >::value();
  }
  static const char* value(const ::mavros_msgs::CommandLongResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_COMMANDLONG_H
