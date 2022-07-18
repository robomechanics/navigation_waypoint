// Generated by gencpp from file microstrain_inertial_msgs/GetMagDipAdaptiveValsRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETMAGDIPADAPTIVEVALSREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETMAGDIPADAPTIVEVALSREQUEST_H


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
struct GetMagDipAdaptiveValsRequest_
{
  typedef GetMagDipAdaptiveValsRequest_<ContainerAllocator> Type;

  GetMagDipAdaptiveValsRequest_()
    {
    }
  GetMagDipAdaptiveValsRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetMagDipAdaptiveValsRequest_

typedef ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<std::allocator<void> > GetMagDipAdaptiveValsRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest > GetMagDipAdaptiveValsRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest const> GetMagDipAdaptiveValsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetMagDipAdaptiveValsRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetMagDipAdaptiveValsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::microstrain_inertial_msgs::GetMagDipAdaptiveValsRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETMAGDIPADAPTIVEVALSREQUEST_H