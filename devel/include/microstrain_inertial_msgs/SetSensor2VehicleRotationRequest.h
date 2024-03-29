// Generated by gencpp from file microstrain_inertial_msgs/SetSensor2VehicleRotationRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEROTATIONREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEROTATIONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>

namespace microstrain_inertial_msgs
{
template <class ContainerAllocator>
struct SetSensor2VehicleRotationRequest_
{
  typedef SetSensor2VehicleRotationRequest_<ContainerAllocator> Type;

  SetSensor2VehicleRotationRequest_()
    : angle()  {
    }
  SetSensor2VehicleRotationRequest_(const ContainerAllocator& _alloc)
    : angle(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _angle_type;
  _angle_type angle;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetSensor2VehicleRotationRequest_

typedef ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<std::allocator<void> > SetSensor2VehicleRotationRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest > SetSensor2VehicleRotationRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest const> SetSensor2VehicleRotationRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator2> & rhs)
{
  return lhs.angle == rhs.angle;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d1832802105b934d111265eaec60b073";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd1832802105b934dULL;
  static const uint64_t static_value2 = 0x111265eaec60b073ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetSensor2VehicleRotationRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3 angle\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.angle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetSensor2VehicleRotationRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetSensor2VehicleRotationRequest_<ContainerAllocator>& v)
  {
    s << indent << "angle: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.angle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEROTATIONREQUEST_H
