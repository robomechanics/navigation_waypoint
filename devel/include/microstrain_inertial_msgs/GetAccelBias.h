// Generated by gencpp from file microstrain_inertial_msgs/GetAccelBias.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIAS_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIAS_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/GetAccelBiasRequest.h>
#include <microstrain_inertial_msgs/GetAccelBiasResponse.h>


namespace microstrain_inertial_msgs
{

struct GetAccelBias
{

typedef GetAccelBiasRequest Request;
typedef GetAccelBiasResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetAccelBias
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetAccelBias > {
  static const char* value()
  {
    return "9427c94a8464f80e7ccfb4c788698d94";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetAccelBias&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::GetAccelBias > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetAccelBias";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetAccelBias&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetAccelBiasRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetAccelBias >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetAccelBiasRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetAccelBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetAccelBiasRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetAccelBias >
template<>
struct DataType< ::microstrain_inertial_msgs::GetAccelBiasRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetAccelBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetAccelBiasResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetAccelBias >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetAccelBiasResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetAccelBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetAccelBiasResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetAccelBias >
template<>
struct DataType< ::microstrain_inertial_msgs::GetAccelBiasResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetAccelBias >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIAS_H
