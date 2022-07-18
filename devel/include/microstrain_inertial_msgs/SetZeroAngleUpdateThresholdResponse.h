// Generated by gencpp from file microstrain_inertial_msgs/SetZeroAngleUpdateThresholdResponse.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETZEROANGLEUPDATETHRESHOLDRESPONSE_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETZEROANGLEUPDATETHRESHOLDRESPONSE_H


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
struct SetZeroAngleUpdateThresholdResponse_
{
  typedef SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> Type;

  SetZeroAngleUpdateThresholdResponse_()
    : success(false)  {
    }
  SetZeroAngleUpdateThresholdResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetZeroAngleUpdateThresholdResponse_

typedef ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<std::allocator<void> > SetZeroAngleUpdateThresholdResponse;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse > SetZeroAngleUpdateThresholdResponsePtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse const> SetZeroAngleUpdateThresholdResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetZeroAngleUpdateThresholdResponse";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n"
"\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetZeroAngleUpdateThresholdResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetZeroAngleUpdateThresholdResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETZEROANGLEUPDATETHRESHOLDRESPONSE_H