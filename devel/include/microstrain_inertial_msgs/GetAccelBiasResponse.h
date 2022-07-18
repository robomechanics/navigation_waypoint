// Generated by gencpp from file microstrain_inertial_msgs/GetAccelBiasResponse.msg
// DO NOT EDIT!


#ifndef MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIASRESPONSE_H
#define MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIASRESPONSE_H


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
struct GetAccelBiasResponse_
{
  typedef GetAccelBiasResponse_<ContainerAllocator> Type;

  GetAccelBiasResponse_()
    : bias()
    , success(false)  {
    }
  GetAccelBiasResponse_(const ContainerAllocator& _alloc)
    : bias(_alloc)
    , success(false)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _bias_type;
  _bias_type bias;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetAccelBiasResponse_

typedef ::microstrain_inertial_msgs::GetAccelBiasResponse_<std::allocator<void> > GetAccelBiasResponse;

typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetAccelBiasResponse > GetAccelBiasResponsePtr;
typedef boost::shared_ptr< ::microstrain_inertial_msgs::GetAccelBiasResponse const> GetAccelBiasResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator2> & rhs)
{
  return lhs.bias == rhs.bias &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator1> & lhs, const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace microstrain_inertial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9427c94a8464f80e7ccfb4c788698d94";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9427c94a8464f80eULL;
  static const uint64_t static_value2 = 0x7ccfb4c788698d94ULL;
};

template<class ContainerAllocator>
struct DataType< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "microstrain_inertial_msgs/GetAccelBiasResponse";
  }

  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3 bias\n"
"bool success\n"
"\n"
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

  static const char* value(const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bias);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetAccelBiasResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::microstrain_inertial_msgs::GetAccelBiasResponse_<ContainerAllocator>& v)
  {
    s << indent << "bias: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.bias);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MICROSTRAIN_INERTIAL_MSGS_MESSAGE_GETACCELBIASRESPONSE_H
