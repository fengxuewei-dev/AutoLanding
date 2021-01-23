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

class EXITflag {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.EXIT_FLAG = null;
    }
    else {
      if (initObj.hasOwnProperty('EXIT_FLAG')) {
        this.EXIT_FLAG = initObj.EXIT_FLAG
      }
      else {
        this.EXIT_FLAG = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EXITflag
    // Serialize message field [EXIT_FLAG]
    bufferOffset = _serializer.int32(obj.EXIT_FLAG, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EXITflag
    let len;
    let data = new EXITflag(null);
    // Deserialize message field [EXIT_FLAG]
    data.EXIT_FLAG = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/EXITflag';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eef81bba155a9b445b2c20263a5058af';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # EXITflag.msg
    
    int32 EXIT_FLAG
    
    # 0: 正常      1: 退出
    # uavName + "communication/exitFlag/exitflag"
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EXITflag(null);
    if (msg.EXIT_FLAG !== undefined) {
      resolved.EXIT_FLAG = msg.EXIT_FLAG;
    }
    else {
      resolved.EXIT_FLAG = 0
    }

    return resolved;
    }
};

module.exports = EXITflag;
