// Generated by gencpp from file microstrain_inertial_msgs/GetConingScullingCompRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETCONINGSCULLINGCOMPREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETCONINGSCULLINGCOMPREQUEST_H


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
struct GetConingScullingCompRequest_
{
  typedef GetConingScullingCompRequest_<ContainerAllocator> Type;

  GetConingScullingCompRequest_()
    {
    }
  GetConingScullingCompRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetConingScullingCompRequest_

typedef ::microstrain_inertial_msgs::GetConingScullingCompRequest_<std::allocator<void> > GetConingScullingCompRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetConingScullingCompRequest > GetConingScullingCompRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetConingScullingCompRequest const> GetConingScullingCompRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetConingScullingCompRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetConingScullingCompRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::microstrain_inertial_msgs::GetConingScullingCompRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETCONINGSCULLINGCOMPREQUEST_H
