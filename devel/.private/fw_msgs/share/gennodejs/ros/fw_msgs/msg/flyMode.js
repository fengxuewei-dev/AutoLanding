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

class flyMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.IsSingleMode = null;
      this.ControlMode = null;
    }
    else {
      if (initObj.hasOwnProperty('IsSingleMode')) {
        this.IsSingleMode = initObj.IsSingleMode
      }
      else {
        this.IsSingleMode = 0.0;
      }
      if (initObj.hasOwnProperty('ControlMode')) {
        this.ControlMode = initObj.ControlMode
      }
      else {
        this.ControlMode = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type flyMode
    // Serialize message field [IsSingleMode]
    bufferOffset = _serializer.float64(obj.IsSingleMode, buffer, bufferOffset);
    // Serialize message field [ControlMode]
    bufferOffset = _serializer.float64(obj.ControlMode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type flyMode
    let len;
    let data = new flyMode(null);
    // Deserialize message field [IsSingleMode]
    data.IsSingleMode = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ControlMode]
    data.ControlMode = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/flyMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8bbfbbef36e847700d30280b89afcfb1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # flyMode.msg
    
    float64 IsSingleMode
    float64 ControlMode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new flyMode(null);
    if (msg.IsSingleMode !== undefined) {
      resolved.IsSingleMode = msg.IsSingleMode;
    }
    else {
      resolved.IsSingleMode = 0.0
    }

    if (msg.ControlMode !== undefined) {
      resolved.ControlMode = msg.ControlMode;
    }
    else {
      resolved.ControlMode = 0.0
    }

    return resolved;
    }
};

module.exports = flyMode;
