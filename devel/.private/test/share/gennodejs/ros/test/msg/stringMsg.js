// Auto-generated. Do not edit!

// (in-package test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class stringMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.number = null;
      this.testData1 = null;
      this.testData2 = null;
    }
    else {
      if (initObj.hasOwnProperty('number')) {
        this.number = initObj.number
      }
      else {
        this.number = 0;
      }
      if (initObj.hasOwnProperty('testData1')) {
        this.testData1 = initObj.testData1
      }
      else {
        this.testData1 = 0;
      }
      if (initObj.hasOwnProperty('testData2')) {
        this.testData2 = initObj.testData2
      }
      else {
        this.testData2 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type stringMsg
    // Serialize message field [number]
    bufferOffset = _serializer.uint32(obj.number, buffer, bufferOffset);
    // Serialize message field [testData1]
    bufferOffset = _serializer.uint32(obj.testData1, buffer, bufferOffset);
    // Serialize message field [testData2]
    bufferOffset = _serializer.uint32(obj.testData2, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type stringMsg
    let len;
    let data = new stringMsg(null);
    // Deserialize message field [number]
    data.number = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [testData1]
    data.testData1 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [testData2]
    data.testData2 = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test/stringMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ceb80582456c5541e317ccd118b86605';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # stringMsg.msg
    
    uint32 number
    uint32 testData1
    uint32 testData2
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new stringMsg(null);
    if (msg.number !== undefined) {
      resolved.number = msg.number;
    }
    else {
      resolved.number = 0
    }

    if (msg.testData1 !== undefined) {
      resolved.testData1 = msg.testData1;
    }
    else {
      resolved.testData1 = 0
    }

    if (msg.testData2 !== undefined) {
      resolved.testData2 = msg.testData2;
    }
    else {
      resolved.testData2 = 0
    }

    return resolved;
    }
};

module.exports = stringMsg;
