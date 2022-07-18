# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from microstrain_inertial_msgs/GNSSFixInfo.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class GNSSFixInfo(genpy.Message):
  _md5sum = "cb3314532886b25255798400e78fc222"
  _type = "microstrain_inertial_msgs/GNSSFixInfo"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint8 fix_type
uint8 num_sv
bool sbas_used
bool dngss_used

uint8 FIX_3D = 0
uint8 FIX_2D = 1
uint8 FIX_TIME_ONLY = 2
uint8 FIX_NONE = 3
uint8 FIX_INVALID = 4
uint8 FIX_RTK_FLOAT = 5
uint8 FIX_RTK_FIXED = 6"""
  # Pseudo-constants
  FIX_3D = 0
  FIX_2D = 1
  FIX_TIME_ONLY = 2
  FIX_NONE = 3
  FIX_INVALID = 4
  FIX_RTK_FLOAT = 5
  FIX_RTK_FIXED = 6

  __slots__ = ['fix_type','num_sv','sbas_used','dngss_used']
  _slot_types = ['uint8','uint8','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       fix_type,num_sv,sbas_used,dngss_used

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(GNSSFixInfo, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.fix_type is None:
        self.fix_type = 0
      if self.num_sv is None:
        self.num_sv = 0
      if self.sbas_used is None:
        self.sbas_used = False
      if self.dngss_used is None:
        self.dngss_used = False
    else:
      self.fix_type = 0
      self.num_sv = 0
      self.sbas_used = False
      self.dngss_used = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_4B().pack(_x.fix_type, _x.num_sv, _x.sbas_used, _x.dngss_used))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.fix_type, _x.num_sv, _x.sbas_used, _x.dngss_used,) = _get_struct_4B().unpack(str[start:end])
      self.sbas_used = bool(self.sbas_used)
      self.dngss_used = bool(self.dngss_used)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_4B().pack(_x.fix_type, _x.num_sv, _x.sbas_used, _x.dngss_used))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.fix_type, _x.num_sv, _x.sbas_used, _x.dngss_used,) = _get_struct_4B().unpack(str[start:end])
      self.sbas_used = bool(self.sbas_used)
      self.dngss_used = bool(self.dngss_used)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4B = None
def _get_struct_4B():
    global _struct_4B
    if _struct_4B is None:
        _struct_4B = struct.Struct("<4B")
    return _struct_4B