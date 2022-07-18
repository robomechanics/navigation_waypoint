// Generated by gencpp from file microstrain_inertial_msgs/InputSpeedMeasurement.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_INPUTSPEEDMEASUREMENT_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_INPUTSPEEDMEASUREMENT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace microstrain_inertial_msgs
{
template <class ContainerAllocator>
struct InputSpeedMeasurement_
{
  typedef InputSpeedMeasurement_<ContainerAllocator> Type;

  InputSpeedMeasurement_()
    : gps_tow(0.0)
    , speed(0.0)
    , speed_uncertainty(0.0)  {
    }
  InputSpeedMeasurement_(const ContainerAllocator& _alloc)
    : gps_tow(0.0)
    , speed(0.0)
    , speed_uncertainty(0.0)  {
  (void)_alloc;
    }



   typedef float _gps_tow_type;
  _gps_tow_type gps_tow;

   typedef float _speed_type;
  _speed_type speed;

   typedef float _speed_uncertainty_type;
  _speed_uncertainty_type speed_uncertainty;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> const> ConstPtr;

}; // struct InputSpeedMeasurement_

typedef ::microstrain_inertial_msgs::InputSpeedMeasurement_<std::allocator<void> > InputSpeedMeasurement;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::InputSpeedMeasurement > InputSpeedMeasurementPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::InputSpeedMeasurement const> InputSpeedMeasurementConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator2> & rhs)
{
  return lhs.gps_tow == rhs.gps_tow &&
    lhs.speed == rhs.speed &&
    lhs.speed_uncertainty == rhs.speed_uncertainty;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c23013e9b4813b23fc2611c8b2e2b2c8";
  }

  static const char* value(const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc23013e9b4813b23ULL;
  static const uint64_t static_value2 = 0xfc2611c8b2e2b2c8ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/InputSpeedMeasurement";
  }

  static const char* value(const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 gps_tow  # GPS time of week when speed was sampled\n"
"float32 speed  # Estimated speed along vehicle's x-axis (may be positive or negative) (m/s)\n"
"float32 speed_uncertainty  # Estimated uncertainty in the speed measurement (1-sigma value) (m/s)\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gps_tow);
      stream.next(m.speed);
      stream.next(m.speed_uncertainty);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct InputSpeedMeasurement_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::InputSpeedMeasurement_<ContainerAllocator>& v)
  {
    s << indent << "gps_tow: ";
    Printer<float>::stream(s, indent + "  ", v.gps_tow);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "speed_uncertainty: ";
    Printer<float>::stream(s, indent + "  ", v.speed_uncertainty);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_INPUTSPEEDMEASUREMENT_H
