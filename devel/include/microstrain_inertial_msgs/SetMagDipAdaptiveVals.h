// Generated by gencpp from file microstrain_inertial_msgs/SetMagDipAdaptiveVals.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETMAGDIPADAPTIVEVALS_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETMAGDIPADAPTIVEVALS_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetMagDipAdaptiveValsRequest.h>
#include <microstrain_inertial_msgs/SetMagDipAdaptiveValsResponse.h>


namespace microstrain_inertial_msgs
{

struct SetMagDipAdaptiveVals
{

typedef SetMagDipAdaptiveValsRequest Request;
typedef SetMagDipAdaptiveValsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetMagDipAdaptiveVals
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals > {
  static const char* value()
  {
    return "c71450f947e543c107e6e7b633ac2f16";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveVals&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetMagDipAdaptiveVals";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveVals&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >
template<>
struct DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveValsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >
template<>
struct DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetMagDipAdaptiveVals >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetMagDipAdaptiveValsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETMAGDIPADAPTIVEVALS_H