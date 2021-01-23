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

class DataLinkDown {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isDataLinkDown = null;
    }
    else {
      if (initObj.hasOwnProperty('isDataLinkDown')) {
        this.isDataLinkDown = initObj.isDataLinkDown
      }
      else {
        this.isDataLinkDown = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DataLinkDown
    // Serialize message field [isDataLinkDown]
    bufferOffset = _serializer.int32(obj.isDataLinkDown, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DataLinkDown
    let len;
    let data = new DataLinkDown(null);
    // Deserialize message field [isDataLinkDown]
    data.isDataLinkDown = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/DataLinkDown';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '27e3a3f98f0830d328812cc2b4a61f31';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # DataLinkDown.msg
    
    int32 isDataLinkDown
    
    # "communication/dataLinkDown/isBreak"
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DataLinkDown(null);
    if (msg.isDataLinkDown !== undefined) {
      resolved.isDataLinkDown = msg.isDataLinkDown;
    }
    else {
      resolved.isDataLinkDown = 0
    }

    return resolved;
    }
};

module.exports = DataLinkDown;
