// Auto-generated. Do not edit!

// (in-package fw_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class UpdHP {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.messageid = null;
      this.uavid = null;
      this.longitude = null;
      this.latitude = null;
      this.altitude = null;
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
      if (initObj.hasOwnProperty('longitude')) {
        this.longitude = initObj.longitude
      }
      else {
        this.longitude = 0.0;
      }
      if (initObj.hasOwnProperty('latitude')) {
        this.latitude = initObj.latitude
      }
      else {
        this.latitude = 0.0;
      }
      if (initObj.hasOwnProperty('altitude')) {
        this.altitude = initObj.altitude
      }
      else {
        this.altitude = 0.0;
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
    // Serializes a message object of type UpdHP
    // Serialize message field [messageid]
    bufferOffset = _serializer.uint16(obj.messageid, buffer, bufferOffset);
    // Serialize message field [uavid]
    bufferOffset = _serializer.uint16(obj.uavid, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float64(obj.longitude, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float64(obj.latitude, buffer, bufferOffset);
    // Serialize message field [altitude]
    bufferOffset = _serializer.float64(obj.altitude, buffer, bufferOffset);
    // Serialize message field [parity]
    bufferOffset = _serializer.int32(obj.parity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UpdHP
    let len;
    let data = new UpdHP(null);
    // Deserialize message field [messageid]
    data.messageid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [uavid]
    data.uavid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [altitude]
    data.altitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [parity]
    data.parity = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/UpdHP';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7f25d391682710b024a661224416d7c4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # UDPMessage.msg
    
    uint16 messageid
    uint16 uavid
    float64 longitude
    float64 latitude
    float64 altitude 
    int32 parity
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new UpdHP(null);
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

    if (msg.longitude !== undefined) {
      resolved.longitude = msg.longitude;
    }
    else {
      resolved.longitude = 0.0
    }

    if (msg.latitude !== undefined) {
      resolved.latitude = msg.latitude;
    }
    else {
      resolved.latitude = 0.0
    }

    if (msg.altitude !== undefined) {
      resolved.altitude = msg.altitude;
    }
    else {
      resolved.altitude = 0.0
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

module.exports = UpdHP;
