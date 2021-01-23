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

class ACKflag {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ACKflag = null;
    }
    else {
      if (initObj.hasOwnProperty('ACKflag')) {
        this.ACKflag = initObj.ACKflag
      }
      else {
        this.ACKflag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ACKflag
    // Serialize message field [ACKflag]
    bufferOffset = _serializer.int32(obj.ACKflag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ACKflag
    let len;
    let data = new ACKflag(null);
    // Deserialize message field [ACKflag]
    data.ACKflag = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/ACKflag';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '45bdb69dba2c6d2adc0542aeb7f54879';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ACKflag.msg
    
    int32 ACKflag
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ACKflag(null);
    if (msg.ACKflag !== undefined) {
      resolved.ACKflag = msg.ACKflag;
    }
    else {
      resolved.ACKflag = 0
    }

    return resolved;
    }
};

module.exports = ACKflag;
