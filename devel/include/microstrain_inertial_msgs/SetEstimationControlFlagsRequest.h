// Generated by gencpp from file microstrain_inertial_msgs/SetEstimationControlFlagsRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETESTIMATIONCONTROLFLAGSREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETESTIMATIONCONTROLFLAGSREQUEST_H


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
struct SetEstimationControlFlagsRequest_
{
  typedef SetEstimationControlFlagsRequest_<ContainerAllocator> Type;

  SetEstimationControlFlagsRequest_()
    : flags(0)  {
    }
  SetEstimationControlFlagsRequest_(const ContainerAllocator& _alloc)
    : flags(0)  {
  (void)_alloc;
    }



   typedef int8_t _flags_type;
  _flags_type flags;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(GYRO_BIAS_ESTIMATION)
  #undef GYRO_BIAS_ESTIMATION
#endif
#if defined(_WIN32) && defined(HARD_IRON_AUTO_CALIBRATION)
  #undef HARD_IRON_AUTO_CALIBRATION
#endif
#if defined(_WIN32) && defined(SOFT_IRON_AUTO_CALIBRATION)
  #undef SOFT_IRON_AUTO_CALIBRATION
#endif

  enum {
    GYRO_BIAS_ESTIMATION = 1,
    HARD_IRON_AUTO_CALIBRATION = 32,
    SOFT_IRON_AUTO_CALIBRATION = 64,
  };


  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetEstimationControlFlagsRequest_

typedef ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<std::allocator<void> > SetEstimationControlFlagsRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest > SetEstimationControlFlagsRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest const> SetEstimationControlFlagsRequestConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator2> & rhs)
{
  return lhs.flags == rhs.flags;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bcc1a9b0f97d53343afbd10c56611cf6";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbcc1a9b0f97d5334ULL;
  static const uint64_t static_value2 = 0x3afbd10c56611cf6ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetEstimationControlFlagsRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 GYRO_BIAS_ESTIMATION=1\n"
"int8 HARD_IRON_AUTO_CALIBRATION=32\n"
"int8 SOFT_IRON_AUTO_CALIBRATION=64\n"
"int8 flags\n"
;
  }

  static const char* value(const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.flags);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetEstimationControlFlagsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetEstimationControlFlagsRequest_<ContainerAllocator>& v)
  {
    s << indent << "flags: ";
    Printer<int8_t>::stream(s, indent + "  ", v.flags);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETESTIMATIONCONTROLFLAGSREQUEST_H
