// Generated by gencpp from file microstrain_inertial_msgs/GetGyroBias.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIAS_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIAS_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/GetGyroBiasRequest.h>
#include <microstrain_inertial_msgs/GetGyroBiasResponse.h>


namespace microstrain_inertial_msgs
{

struct GetGyroBias
{

typedef GetGyroBiasRequest Request;
typedef GetGyroBiasResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetGyroBias
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBias > {
  static const char* value()
  {
    return "9427c94a8464f80e7ccfb4c788698d94";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetGyroBias&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBias > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetGyroBias";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetGyroBias&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBias >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetGyroBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBias >
template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBiasRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetGyroBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBias >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetGyroBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBias >
template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBiasResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetGyroBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIAS_H