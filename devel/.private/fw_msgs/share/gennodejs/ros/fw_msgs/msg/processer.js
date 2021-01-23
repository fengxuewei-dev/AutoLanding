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

class processer {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.execflag = null;
    }
    else {
      if (initObj.hasOwnProperty('execflag')) {
        this.execflag = initObj.execflag
      }
      else {
        this.execflag = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type processer
    // Serialize message field [execflag]
    bufferOffset = _serializer.float32(obj.execflag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type processer
    let len;
    let data = new processer(null);
    // Deserialize message field [execflag]
    data.execflag = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/processer';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fff3fb7d3ee0a7ebfa5a6a893b0503a1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # processer.msg
    
    float32 execflag
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new processer(null);
    if (msg.execflag !== undefined) {
      resolved.execflag = msg.execflag;
    }
    else {
      resolved.execflag = 0.0
    }

    return resolved;
    }
};

module.exports = processer;
