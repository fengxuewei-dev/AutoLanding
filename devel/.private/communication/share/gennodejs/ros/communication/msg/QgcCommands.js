// Auto-generated. Do not edit!

// (in-package communication.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class QgcCommands {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.messageid = null;
      this.gsid = null;
      this.uavid = null;
      this.uavnumber = null;
      this.tasktype = null;
      this.plane_state = null;
      this.plane_group = null;
      this.gapx = null;
      this.gapy = null;
      this.GPStime = null;
      this.parity = null;
    }
    else {
      if (initObj.hasOwnProperty('messageid')) {
        this.messageid = initObj.messageid
      }
      else {
        this.messageid = 0;
      }
      if (initObj.hasOwnProperty('gsid')) {
        this.gsid = initObj.gsid
      }
      else {
        this.gsid = 0;
      }
      if (initObj.hasOwnProperty('uavid')) {
        this.uavid = initObj.uavid
      }
      else {
        this.uavid = 0;
      }
      if (initObj.hasOwnProperty('uavnumber')) {
        this.uavnumber = initObj.uavnumber
      }
      else {
        this.uavnumber = 0;
      }
      if (initObj.hasOwnProperty('tasktype')) {
        this.tasktype = initObj.tasktype
      }
      else {
        this.tasktype = 0;
      }
      if (initObj.hasOwnProperty('plane_state')) {
        this.plane_state = initObj.plane_state
      }
      else {
        this.plane_state = 0;
      }
      if (initObj.hasOwnProperty('plane_group')) {
        this.plane_group = initObj.plane_group
      }
      else {
        this.plane_group = 0;
      }
      if (initObj.hasOwnProperty('gapx')) {
        this.gapx = initObj.gapx
      }
      else {
        this.gapx = 0;
      }
      if (initObj.hasOwnProperty('gapy')) {
        this.gapy = initObj.gapy
      }
      else {
        this.gapy = 0;
      }
      if (initObj.hasOwnProperty('GPStime')) {
        this.GPStime = initObj.GPStime
      }
      else {
        this.GPStime = 0.0;
      }
      if (initObj.hasOwnProperty('parity')) {
        this.parity = initObj.parity
      }
      else {
        this.parity = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type QgcCommands
    // Serialize message field [messageid]
    bufferOffset = _serializer.uint16(obj.messageid, buffer, bufferOffset);
    // Serialize message field [gsid]
    bufferOffset = _serializer.uint16(obj.gsid, buffer, bufferOffset);
    // Serialize message field [uavid]
    bufferOffset = _serializer.uint16(obj.uavid, buffer, bufferOffset);
    // Serialize message field [uavnumber]
    bufferOffset = _serializer.uint16(obj.uavnumber, buffer, bufferOffset);
    // Serialize message field [tasktype]
    bufferOffset = _serializer.int32(obj.tasktype, buffer, bufferOffset);
    // Serialize message field [plane_state]
    bufferOffset = _serializer.int16(obj.plane_state, buffer, bufferOffset);
    // Serialize message field [plane_group]
    bufferOffset = _serializer.int16(obj.plane_group, buffer, bufferOffset);
    // Serialize message field [gapx]
    bufferOffset = _serializer.int16(obj.gapx, buffer, bufferOffset);
    // Serialize message field [gapy]
    bufferOffset = _serializer.int16(obj.gapy, buffer, bufferOffset);
    // Serialize message field [GPStime]
    bufferOffset = _serializer.float64(obj.GPStime, buffer, bufferOffset);
    // Serialize message field [parity]
    bufferOffset = _serializer.int32(obj.parity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type QgcCommands
    let len;
    let data = new QgcCommands(null);
    // Deserialize message field [messageid]
    data.messageid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [gsid]
    data.gsid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [uavid]
    data.uavid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [uavnumber]
    data.uavnumber = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [tasktype]
    data.tasktype = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [plane_state]
    data.plane_state = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [plane_group]
    data.plane_group = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gapx]
    data.gapx = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gapy]
    data.gapy = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [GPStime]
    data.GPStime = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [parity]
    data.parity = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'communication/QgcCommands';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0e2eb4b83ad275dc0706fdd57e60ccec';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # UDPMessage.msg
    
    uint16 messageid
    uint16 gsid
    uint16 uavid
    uint16 uavnumber
    int32 tasktype
    int16 plane_state
    int16 plane_group
    int16 gapx
    int16 gapy
    float64 GPStime
    int32 parity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new QgcCommands(null);
    if (msg.messageid !== undefined) {
      resolved.messageid = msg.messageid;
    }
    else {
      resolved.messageid = 0
    }

    if (msg.gsid !== undefined) {
      resolved.gsid = msg.gsid;
    }
    else {
      resolved.gsid = 0
    }

    if (msg.uavid !== undefined) {
      resolved.uavid = msg.uavid;
    }
    else {
      resolved.uavid = 0
    }

    if (msg.uavnumber !== undefined) {
      resolved.uavnumber = msg.uavnumber;
    }
    else {
      resolved.uavnumber = 0
    }

    if (msg.tasktype !== undefined) {
      resolved.tasktype = msg.tasktype;
    }
    else {
      resolved.tasktype = 0
    }

    if (msg.plane_state !== undefined) {
      resolved.plane_state = msg.plane_state;
    }
    else {
      resolved.plane_state = 0
    }

    if (msg.plane_group !== undefined) {
      resolved.plane_group = msg.plane_group;
    }
    else {
      resolved.plane_group = 0
    }

    if (msg.gapx !== undefined) {
      resolved.gapx = msg.gapx;
    }
    else {
      resolved.gapx = 0
    }

    if (msg.gapy !== undefined) {
      resolved.gapy = msg.gapy;
    }
    else {
      resolved.gapy = 0
    }

    if (msg.GPStime !== undefined) {
      resolved.GPStime = msg.GPStime;
    }
    else {
      resolved.GPStime = 0.0
    }

    if (msg.parity !== undefined) {
      resolved.parity = msg.parity;
    }
    else {
      resolved.parity = 0
    }

    return resolved;
    }
};

module.exports = QgcCommands;
