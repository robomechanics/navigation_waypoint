// Generated by gencpp from file microstrain_inertial_msgs/SetHeadingSource.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHEADINGSOURCE_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHEADINGSOURCE_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetHeadingSourceRequest.h>
#include <microstrain_inertial_msgs/SetHeadingSourceResponse.h>


namespace microstrain_inertial_msgs
{

struct SetHeadingSource
{

typedef SetHeadingSourceRequest Request;
typedef SetHeadingSourceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetHeadingSource
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHeadingSource > {
  static const char* value()
  {
    return "e390de146ace4f3cbedb9445dd2ef6f7";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSource&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetHeadingSource > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetHeadingSource";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSource&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHeadingSourceRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHeadingSource >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHeadingSourceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetHeadingSource >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSourceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetHeadingSourceRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetHeadingSource >
template<>
struct DataType< ::microstrain_inertial_msgs::SetHeadingSourceRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetHeadingSource >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSourceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHeadingSourceResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHeadingSource >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHeadingSourceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetHeadingSource >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSourceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetHeadingSourceResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetHeadingSource >
template<>
struct DataType< ::microstrain_inertial_msgs::SetHeadingSourceResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetHeadingSource >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHeadingSourceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHEADINGSOURCE_H