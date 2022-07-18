// Generated by gencpp from file microstrain_inertial_msgs/SetSensor2VehicleOffsetRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEOFFSETREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEOFFSETREQUEST_H


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
struct SetSensor2VehicleOffsetRequest_
{
  typedef SetSensor2VehicleOffsetRequest_<ContainerAllocator> Type;

  SetSensor2VehicleOffsetRequest_()
    : offset()  {
    }
  SetSensor2VehicleOffsetRequest_(const ContainerAllocator& _alloc)
    : offset(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _offset_type;
  _offset_type offset;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetSensor2VehicleOffsetRequest_

typedef ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<std::allocator<void> > SetSensor2VehicleOffsetRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest > SetSensor2VehicleOffsetRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest const> SetSensor2VehicleOffsetRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator2> & rhs)
{
  return lhs.offset == rhs.offset;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "de19cca9344eb5bfedb7e55986a47f2e";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xde19cca9344eb5bfULL;
  static const uint64_t static_value2 = 0xedb7e55986a47f2eULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetSensor2VehicleOffsetRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3 offset\n"
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

  static const char* value(const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.offset);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetSensor2VehicleOffsetRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetSensor2VehicleOffsetRequest_<ContainerAllocator>& v)
  {
    s << indent << "offset: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.offset);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETSENSOR2VEHICLEOFFSETREQUEST_H