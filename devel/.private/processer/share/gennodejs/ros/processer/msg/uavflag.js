// Auto-generated. Do not edit!

// (in-package processer.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class uavflag {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.group = null;
      this.isleader = null;
      this.leaderid = null;
      this.myid = null;
      this.gapx = null;
      this.gapy = null;
    }
    else {
      if (initObj.hasOwnProperty('group')) {
        this.group = initObj.group
      }
      else {
        this.group = 0.0;
      }
      if (initObj.hasOwnProperty('isleader')) {
        this.isleader = initObj.isleader
      }
      else {
        this.isleader = 0.0;
      }
      if (initObj.hasOwnProperty('leaderid')) {
        this.leaderid = initObj.leaderid
      }
      else {
        this.leaderid = 0.0;
      }
      if (initObj.hasOwnProperty('myid')) {
        this.myid = initObj.myid
      }
      else {
        this.myid = 0.0;
      }
      if (initObj.hasOwnProperty('gapx')) {
        this.gapx = initObj.gapx
      }
      else {
        this.gapx = 0.0;
      }
      if (initObj.hasOwnProperty('gapy')) {
        this.gapy = initObj.gapy
      }
      else {
        this.gapy = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type uavflag
    // Serialize message field [group]
    bufferOffset = _serializer.float32(obj.group, buffer, bufferOffset);
    // Serialize message field [isleader]
    bufferOffset = _serializer.float32(obj.isleader, buffer, bufferOffset);
    // Serialize message field [leaderid]
    bufferOffset = _serializer.float32(obj.leaderid, buffer, bufferOffset);
    // Serialize message field [myid]
    bufferOffset = _serializer.float32(obj.myid, buffer, bufferOffset);
    // Serialize message field [gapx]
    bufferOffset = _serializer.float32(obj.gapx, buffer, bufferOffset);
    // Serialize message field [gapy]
    bufferOffset = _serializer.float32(obj.gapy, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type uavflag
    let len;
    let data = new uavflag(null);
    // Deserialize message field [group]
    data.group = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [isleader]
    data.isleader = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [leaderid]
    data.leaderid = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [myid]
    data.myid = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [gapx]
    data.gapx = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [gapy]
    data.gapy = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'processer/uavflag';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5d0019540b3060372b57877eb8d6b603';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # uavflag.msg
    
    float32 group
    float32 isleader
    float32 leaderid
    float32 myid
    float32 gapx
    float32 gapy
    
    # qgccommand 当前状态
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new uavflag(null);
    if (msg.group !== undefined) {
      resolved.group = msg.group;
    }
    else {
      resolved.group = 0.0
    }

    if (msg.isleader !== undefined) {
      resolved.isleader = msg.isleader;
    }
    else {
      resolved.isleader = 0.0
    }

    if (msg.leaderid !== undefined) {
      resolved.leaderid = msg.leaderid;
    }
    else {
      resolved.leaderid = 0.0
    }

    if (msg.myid !== undefined) {
      resolved.myid = msg.myid;
    }
    else {
      resolved.myid = 0.0
    }

    if (msg.gapx !== undefined) {
      resolved.gapx = msg.gapx;
    }
    else {
      resolved.gapx = 0.0
    }

    if (msg.gapy !== undefined) {
      resolved.gapy = msg.gapy;
    }
    else {
      resolved.gapy = 0.0
    }

    return resolved;
    }
};

module.exports = uavflag;
