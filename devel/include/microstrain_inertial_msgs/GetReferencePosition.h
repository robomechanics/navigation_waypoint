// Generated by gencpp from file microstrain_inertial_msgs/GetReferencePosition.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETREFERENCEPOSITION_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETREFERENCEPOSITION_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/GetReferencePositionRequest.h>
#include <microstrain_inertial_msgs/GetReferencePositionResponse.h>


namespace microstrain_inertial_msgs
{

struct GetReferencePosition
{

typedef GetReferencePositionRequest Request;
typedef GetReferencePositionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetReferencePosition
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetReferencePosition > {
  static const char* value()
  {
    return "10b5e069422b2cf203664f7c0186f64a";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetReferencePosition&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::GetReferencePosition > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetReferencePosition";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetReferencePosition&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetReferencePositionRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetReferencePosition >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetReferencePositionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetReferencePositionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetReferencePositionRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetReferencePosition >
template<>
struct DataType< ::microstrain_inertial_msgs::GetReferencePositionRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetReferencePositionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetReferencePositionResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::GetReferencePosition >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::GetReferencePositionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::GetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetReferencePositionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::GetReferencePositionResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::GetReferencePosition >
template<>
struct DataType< ::microstrain_inertial_msgs::GetReferencePositionResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::GetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::GetReferencePositionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETREFERENCEPOSITION_H
