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

class ModeSetting {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Mode = null;
    }
    else {
      if (initObj.hasOwnProperty('Mode')) {
        this.Mode = initObj.Mode
      }
      else {
        this.Mode = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ModeSetting
    // Serialize message field [Mode]
    bufferOffset = _serializer.float64(obj.Mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ModeSetting
    let len;
    let data = new ModeSetting(null);
    // Deserialize message field [Mode]
    data.Mode = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/ModeSetting';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fa9a51763d03303f4394bfc6178f2b70';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ModeSetting.msg
    
    float64 Mode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ModeSetting(null);
    if (msg.Mode !== undefined) {
      resolved.Mode = msg.Mode;
    }
    else {
      resolved.Mode = 0.0
    }

    return resolved;
    }
};

module.exports = ModeSetting;
