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

class ACK {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.messageid = null;
      this.uavid = null;
      this.GPStime = null;
      this.judge = null;
      this.parity = null;
    }
    else {
      if (initObj.hasOwnProperty('messageid')) {
        this.messageid = initObj.messageid
      }
      else {
        this.messageid = 0;
      }
      if (initObj.hasOwnProperty('uavid')) {
        this.uavid = initObj.uavid
      }
      else {
        this.uavid = 0;
      }
      if (initObj.hasOwnProperty('GPStime')) {
        this.GPStime = initObj.GPStime
      }
      else {
        this.GPStime = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('judge')) {
        this.judge = initObj.judge
      }
      else {
        this.judge = false;
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
    // Serializes a message object of type ACK
    // Serialize message field [messageid]
    bufferOffset = _serializer.uint16(obj.messageid, buffer, bufferOffset);
    // Serialize message field [uavid]
    bufferOffset = _serializer.uint16(obj.uavid, buffer, bufferOffset);
    // Serialize message field [GPStime]
    bufferOffset = _serializer.time(obj.GPStime, buffer, bufferOffset);
    // Serialize message field [judge]
    bufferOffset = _serializer.bool(obj.judge, buffer, bufferOffset);
    // Serialize message field [parity]
    bufferOffset = _serializer.int32(obj.parity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ACK
    let len;
    let data = new ACK(null);
    // Deserialize message field [messageid]
    data.messageid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [uavid]
    data.uavid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [GPStime]
    data.GPStime = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [judge]
    data.judge = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [parity]
    data.parity = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'communication/ACK';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1572b006872bc5799fbee1b02a88be5b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # UDPMessage.msg
    
    uint16 messageid
    uint16 uavid
    time GPStime
    bool judge
    int32 parity
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ACK(null);
    if (msg.messageid !== undefined) {
      resolved.messageid = msg.messageid;
    }
    else {
      resolved.messageid = 0
    }

    if (msg.uavid !== undefined) {
      resolved.uavid = msg.uavid;
    }
    else {
      resolved.uavid = 0
    }

    if (msg.GPStime !== undefined) {
      resolved.GPStime = msg.GPStime;
    }
    else {
      resolved.GPStime = {secs: 0, nsecs: 0}
    }

    if (msg.judge !== undefined) {
      resolved.judge = msg.judge;
    }
    else {
      resolved.judge = false
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

module.exports = ACK;
