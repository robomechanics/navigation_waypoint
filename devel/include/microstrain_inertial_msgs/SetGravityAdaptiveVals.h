// Generated by gencpp from file microstrain_inertial_msgs/SetGravityAdaptiveVals.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETGRAVITYADAPTIVEVALS_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETGRAVITYADAPTIVEVALS_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetGravityAdaptiveValsRequest.h>
#include <microstrain_inertial_msgs/SetGravityAdaptiveValsResponse.h>


namespace microstrain_inertial_msgs
{

struct SetGravityAdaptiveVals
{

typedef SetGravityAdaptiveValsRequest Request;
typedef SetGravityAdaptiveValsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetGravityAdaptiveVals
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveVals > {
  static const char* value()
  {
    return "f4333508f865a0d6b01f8e48e0168654";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveVals&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveVals > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetGravityAdaptiveVals";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveVals&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >
template<>
struct DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveValsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >
template<>
struct DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetGravityAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetGravityAdaptiveValsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETGRAVITYADAPTIVEVALS_H