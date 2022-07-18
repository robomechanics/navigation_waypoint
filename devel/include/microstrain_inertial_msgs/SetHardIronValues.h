// Generated by gencpp from file microstrain_inertial_msgs/SetHardIronValues.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHARDIRONVALUES_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHARDIRONVALUES_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetHardIronValuesRequest.h>
#include <microstrain_inertial_msgs/SetHardIronValuesResponse.h>


namespace microstrain_inertial_msgs
{

struct SetHardIronValues
{

typedef SetHardIronValuesRequest Request;
typedef SetHardIronValuesResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetHardIronValues
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHardIronValues > {
  static const char* value()
  {
    return "7f2cf85b824b45f9f629310ab233f3c6";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValues&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetHardIronValues > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetHardIronValues";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValues&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHardIronValuesRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHardIronValues >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHardIronValuesRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetHardIronValues >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValuesRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetHardIronValuesRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetHardIronValues >
template<>
struct DataType< ::microstrain_inertial_msgs::SetHardIronValuesRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetHardIronValues >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValuesRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHardIronValuesResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetHardIronValues >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetHardIronValuesResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetHardIronValues >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValuesResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetHardIronValuesResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetHardIronValues >
template<>
struct DataType< ::microstrain_inertial_msgs::SetHardIronValuesResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetHardIronValues >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetHardIronValuesResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETHARDIRONVALUES_H