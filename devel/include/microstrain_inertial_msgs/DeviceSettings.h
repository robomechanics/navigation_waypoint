// Generated by gencpp from file microstrain_inertial_msgs/DeviceSettings.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_DEVICESETTINGS_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_DEVICESETTINGS_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/DeviceSettingsRequest.h>
#include <microstrain_inertial_msgs/DeviceSettingsResponse.h>


namespace microstrain_inertial_msgs
{

struct DeviceSettings
{

typedef DeviceSettingsRequest Request;
typedef DeviceSettingsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DeviceSettings
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::DeviceSettings > {
  static const char* value()
  {
    return "a5738bbd08ff2569a7464cd41b071fc3";
  }

  static const char* value(const ::microstrain_inertial_msgs::DeviceSettings&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::DeviceSettings > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/DeviceSettings";
  }

  static const char* value(const ::microstrain_inertial_msgs::DeviceSettings&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::DeviceSettingsRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::DeviceSettings >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::DeviceSettingsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::DeviceSettings >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::DeviceSettingsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::DeviceSettingsRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::DeviceSettings >
template<>
struct DataType< ::microstrain_inertial_msgs::DeviceSettingsRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::DeviceSettings >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::DeviceSettingsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::DeviceSettingsResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::DeviceSettings >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::DeviceSettingsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::DeviceSettings >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::DeviceSettingsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::DeviceSettingsResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::DeviceSettings >
template<>
struct DataType< ::microstrain_inertial_msgs::DeviceSettingsResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::DeviceSettings >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::DeviceSettingsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_DEVICESETTINGS_H