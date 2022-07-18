// Generated by gencpp from file microstrain_inertial_msgs/SetTareOrientationRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETTAREORIENTATIONREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETTAREORIENTATIONREQUEST_H


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
struct SetTareOrientationRequest_
{
  typedef SetTareOrientationRequest_<ContainerAllocator> Type;

  SetTareOrientationRequest_()
    : axis(0)  {
    }
  SetTareOrientationRequest_(const ContainerAllocator& _alloc)
    : axis(0)  {
  (void)_alloc;
    }



   typedef int8_t _axis_type;
  _axis_type axis;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetTareOrientationRequest_

typedef ::microstrain_inertial_msgs::SetTareOrientationRequest_<std::allocator<void> > SetTareOrientationRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetTareOrientationRequest > SetTareOrientationRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetTareOrientationRequest const> SetTareOrientationRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator2> & rhs)
{
  return lhs.axis == rhs.axis;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ea297538e481c0b3228cef125a01ff35";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xea297538e481c0b3ULL;
  static const uint64_t static_value2 = 0x228cef125a01ff35ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetTareOrientationRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 axis\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.axis);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetTareOrientationRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetTareOrientationRequest_<ContainerAllocator>& v)
  {
    s << indent << "axis: ";
    Printer<int8_t>::stream(s, indent + "  ", v.axis);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETTAREORIENTATIONREQUEST_H
