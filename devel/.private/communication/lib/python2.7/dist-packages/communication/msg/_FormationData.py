# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from communication/FormationData.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy

class FormationData(genpy.Message):
  _md5sum = "ca7ccece133aa268e8465b3c1b1aa88d"
  _type = "communication/FormationData"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# FormationData.msg

float64 position_x
float64 position_y
float64 position_z

float64 homeLat
float64 homeLon
float64 homeAlt
time gps_time

float64 leaderHeading
float64 leaderCommand_yaw
float64 leaderAirspeed"""
  __slots__ = ['position_x','position_y','position_z','homeLat','homeLon','homeAlt','gps_time','leaderHeading','leaderCommand_yaw','leaderAirspeed']
  _slot_types = ['float64','float64','float64','float64','float64','float64','time','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       position_x,position_y,position_z,homeLat,homeLon,homeAlt,gps_time,leaderHeading,leaderCommand_yaw,leaderAirspeed

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FormationData, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.position_x is None:
        self.position_x = 0.
      if self.position_y is None:
        self.position_y = 0.
      if self.position_z is None:
        self.position_z = 0.
      if self.homeLat is None:
        self.homeLat = 0.
      if self.homeLon is None:
        self.homeLon = 0.
      if self.homeAlt is None:
        self.homeAlt = 0.
      if self.gps_time is None:
        self.gps_time = genpy.Time()
      if self.leaderHeading is None:
        self.leaderHeading = 0.
      if self.leaderCommand_yaw is None:
        self.leaderCommand_yaw = 0.
      if self.leaderAirspeed is None:
        self.leaderAirspeed = 0.
    else:
      self.position_x = 0.
      self.position_y = 0.
      self.position_z = 0.
      self.homeLat = 0.
      self.homeLon = 0.
      self.homeAlt = 0.
      self.gps_time = genpy.Time()
      self.leaderHeading = 0.
      self.leaderCommand_yaw = 0.
      self.leaderAirspeed = 0.

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
      buff.write(_get_struct_6d2I3d().pack(_x.position_x, _x.position_y, _x.position_z, _x.homeLat, _x.homeLon, _x.homeAlt, _x.gps_time.secs, _x.gps_time.nsecs, _x.leaderHeading, _x.leaderCommand_yaw, _x.leaderAirspeed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.gps_time is None:
        self.gps_time = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 80
      (_x.position_x, _x.position_y, _x.position_z, _x.homeLat, _x.homeLon, _x.homeAlt, _x.gps_time.secs, _x.gps_time.nsecs, _x.leaderHeading, _x.leaderCommand_yaw, _x.leaderAirspeed,) = _get_struct_6d2I3d().unpack(str[start:end])
      self.gps_time.canon()
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
      buff.write(_get_struct_6d2I3d().pack(_x.position_x, _x.position_y, _x.position_z, _x.homeLat, _x.homeLon, _x.homeAlt, _x.gps_time.secs, _x.gps_time.nsecs, _x.leaderHeading, _x.leaderCommand_yaw, _x.leaderAirspeed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.gps_time is None:
        self.gps_time = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 80
      (_x.position_x, _x.position_y, _x.position_z, _x.homeLat, _x.homeLon, _x.homeAlt, _x.gps_time.secs, _x.gps_time.nsecs, _x.leaderHeading, _x.leaderCommand_yaw, _x.leaderAirspeed,) = _get_struct_6d2I3d().unpack(str[start:end])
      self.gps_time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6d2I3d = None
def _get_struct_6d2I3d():
    global _struct_6d2I3d
    if _struct_6d2I3d is None:
        _struct_6d2I3d = struct.Struct("<6d2I3d")
    return _struct_6d2I3d
