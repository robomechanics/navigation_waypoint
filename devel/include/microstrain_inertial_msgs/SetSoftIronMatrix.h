// Generated by gencpp from file microstrain_inertial_msgs/SetSoftIronMatrix.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSOFTIRONMATRIX_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSOFTIRONMATRIX_H

#include <ros/service_traits.h>


#include <microstrain_inertial_msgs/SetSoftIronMatrixRequest.h>
#include <microstrain_inertial_msgs/SetSoftIronMatrixResponse.h>


namespace microstrain_inertial_msgs
{

struct SetSoftIronMatrix
{

typedef SetSoftIronMatrixRequest Request;
typedef SetSoftIronMatrixResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetSoftIronMatrix
} // namespace microstrain_inertial_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrix > {
  static const char* value()
  {
    return "ec07578ea93b9bb8b21d87ab5d1f0c81";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrix&) { return value(); }
};

template<>
struct DataType< ::microstrain_inertial_msgs::SetSoftIronMatrix > {
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetSoftIronMatrix";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrix&) { return value(); }
};


// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrixRequest> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrix >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrixRequest>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrix >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrixRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetSoftIronMatrixRequest> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetSoftIronMatrix >
template<>
struct DataType< ::microstrain_inertial_msgs::SetSoftIronMatrixRequest>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetSoftIronMatrix >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrixRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrixResponse> should match
// service_traits::MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrix >
template<>
struct MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrixResponse>
{
  static const char* value()
  {
    return MD5Sum< ::microstrain_inertial_msgs::SetSoftIronMatrix >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrixResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::microstrain_inertial_msgs::SetSoftIronMatrixResponse> should match
// service_traits::DataType< ::microstrain_inertial_msgs::SetSoftIronMatrix >
template<>
struct DataType< ::microstrain_inertial_msgs::SetSoftIronMatrixResponse>
{
  static const char* value()
  {
    return DataType< ::microstrain_inertial_msgs::SetSoftIronMatrix >::value();
  }
  static const char* value(const ::microstrain_inertial_msgs::SetSoftIronMatrixResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSOFTIRONMATRIX_H