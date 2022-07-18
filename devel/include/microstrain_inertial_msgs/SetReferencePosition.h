// Generated by gencpp from file microstrain_inertial_msgs/SetReferencePosition.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETREFERENCEPOSITION_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETREFERENCEPOSITION_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetReferencePositionRequest.h>
#include <microstrain_inertial_msgs/SetReferencePositionResponse.h>


namespace microstrain_inertial_msgs
{

struct SetReferencePosition
{

typedef SetReferencePositionRequest Request;
typedef SetReferencePositionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetReferencePosition
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetReferencePosition > {
  static const char* value()
  {
    return "eed8c009a979878261617f53e8264ddc";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetReferencePosition&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetReferencePosition > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetReferencePosition";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetReferencePosition&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetReferencePositionRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetReferencePosition >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetReferencePositionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetReferencePositionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetReferencePositionRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetReferencePosition >
template<>
struct DataType< ::microstrain_inertial_msgs::SetReferencePositionRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetReferencePositionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetReferencePositionResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetReferencePosition >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetReferencePositionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetReferencePositionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetReferencePositionResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetReferencePosition >
template<>
struct DataType< ::microstrain_inertial_msgs::SetReferencePositionResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetReferencePosition >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetReferencePositionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETREFERENCEPOSITION_H
