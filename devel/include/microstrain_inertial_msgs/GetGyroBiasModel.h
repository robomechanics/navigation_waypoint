// Generated by gencpp from file microstrain_inertial_msgs/GetGyroBiasModel.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIASMODEL_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIASMODEL_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/GetGyroBiasModelRequest.h>
#include <microstrain_inertial_msgs/GetGyroBiasModelResponse.h>


namespace microstrain_inertial_msgs
{

struct GetGyroBiasModel
{

typedef GetGyroBiasModelRequest Request;
typedef GetGyroBiasModelResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetGyroBiasModel
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModel > {
  static const char* value()
  {
    return "b507c17fd666c16c0721d62595a47085";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModel&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBiasModel > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetGyroBiasModel";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModel&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModelRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModel >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModelRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModel >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModelRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasModelRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasModel >
template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBiasModelRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetGyroBiasModel >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModelRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModelResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModel >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModelResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetGyroBiasModel >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModelResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasModelResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetGyroBiasModel >
template<>
struct DataType< ::microstrain_inertial_msgs::GetGyroBiasModelResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetGyroBiasModel >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetGyroBiasModelResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETGYROBIASMODEL_H
