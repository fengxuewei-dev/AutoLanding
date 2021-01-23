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

class ProtectFlag {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.PROTECT_EXIT_FLAG = null;
    }
    else {
      if (initObj.hasOwnProperty('PROTECT_EXIT_FLAG')) {
        this.PROTECT_EXIT_FLAG = initObj.PROTECT_EXIT_FLAG
      }
      else {
        this.PROTECT_EXIT_FLAG = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ProtectFlag
    // Serialize message field [PROTECT_EXIT_FLAG]
    bufferOffset = _serializer.int32(obj.PROTECT_EXIT_FLAG, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ProtectFlag
    let len;
    let data = new ProtectFlag(null);
    // Deserialize message field [PROTECT_EXIT_FLAG]
    data.PROTECT_EXIT_FLAG = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/ProtectFlag';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3cbdec5b7556f1bc61b85f03babb7b6d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ProtectFlag.msg
    
    int32 PROTECT_EXIT_FLAG
    
    # "communication/protectExitFlag/protecEexitFlag"
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ProtectFlag(null);
    if (msg.PROTECT_EXIT_FLAG !== undefined) {
      resolved.PROTECT_EXIT_FLAG = msg.PROTECT_EXIT_FLAG;
    }
    else {
      resolved.PROTECT_EXIT_FLAG = 0
    }

    return resolved;
    }
};

module.exports = ProtectFlag;
