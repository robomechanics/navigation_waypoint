// Generated by gencpp from file microstrain_inertial_msgs/SetRelativePositionReferenceRequest.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETRELATIVEPOSITIONREFERENCEREQUEST_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETRELATIVEPOSITIONREFERENCEREQUEST_H


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
struct SetRelativePositionReferenceRequest_
{
  typedef SetRelativePositionReferenceRequest_<ContainerAllocator> Type;

  SetRelativePositionReferenceRequest_()
    : source(0)
    , frame(0)
    , position()  {
    }
  SetRelativePositionReferenceRequest_(const ContainerAllocator& _alloc)
    : source(0)
    , frame(0)
    , position(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _source_type;
  _source_type source;

   typedef uint8_t _frame_type;
  _frame_type frame;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _position_type;
  _position_type position;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(SOURCE_AUTO)
  #undef SOURCE_AUTO
#endif
#if defined(_WIN32) && defined(SOURCE_MANUAL)
  #undef SOURCE_MANUAL
#endif
#if defined(_WIN32) && defined(FRAME_ECEF)
  #undef FRAME_ECEF
#endif
#if defined(_WIN32) && defined(FRAME_LLH)
  #undef FRAME_LLH
#endif

  enum {
    SOURCE_AUTO = 0u,
    SOURCE_MANUAL = 1u,
    FRAME_ECEF = 1u,
    FRAME_LLH = 2u,
  };


  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetRelativePositionReferenceRequest_

typedef ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<std::allocator<void> > SetRelativePositionReferenceRequest;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest > SetRelativePositionReferenceRequestPtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest const> SetRelativePositionReferenceRequestConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.source == rhs.source &&
    lhs.frame == rhs.frame &&
    lhs.position == rhs.position;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cfba0ceca2a76326ddb06933dd915725";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcfba0ceca2a76326ULL;
  static const uint64_t static_value2 = 0xddb06933dd915725ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/SetRelativePositionReferenceRequest";
  }

  static const char* value(const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8  source\n"
"uint8  frame\n"
"geometry_msgs/Vector3 position\n"
"\n"
"uint8 SOURCE_AUTO   = 0  #RTK base station required\n"
"uint8 SOURCE_MANUAL = 1  \n"
"uint8 FRAME_ECEF = 1  \n"
"uint8 FRAME_LLH  = 2  \n"
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

  static const char* value(const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.source);
      stream.next(m.frame);
      stream.next(m.position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetRelativePositionReferenceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::SetRelativePositionReferenceRequest_<ContainerAllocator>& v)
  {
    s << indent << "source: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.source);
    s << indent << "frame: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.frame);
    s << indent << "position: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_SETRELATIVEPOSITIONREFERENCEREQUEST_H
