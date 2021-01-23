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

class uav_ids {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.current_id = null;
      this.leader_id = null;
    }
    else {
      if (initObj.hasOwnProperty('current_id')) {
        this.current_id = initObj.current_id
      }
      else {
        this.current_id = 0;
      }
      if (initObj.hasOwnProperty('leader_id')) {
        this.leader_id = initObj.leader_id
      }
      else {
        this.leader_id = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type uav_ids
    // Serialize message field [current_id]
    bufferOffset = _serializer.uint16(obj.current_id, buffer, bufferOffset);
    // Serialize message field [leader_id]
    bufferOffset = _serializer.uint16(obj.leader_id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type uav_ids
    let len;
    let data = new uav_ids(null);
    // Deserialize message field [current_id]
    data.current_id = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [leader_id]
    data.leader_id = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/uav_ids';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5a866f4d93c1cb2b5a3f11036043cf7f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # uav_ids.msg
    
    uint16 current_id
    uint16 leader_id
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new uav_ids(null);
    if (msg.current_id !== undefined) {
      resolved.current_id = msg.current_id;
    }
    else {
      resolved.current_id = 0
    }

    if (msg.leader_id !== undefined) {
      resolved.leader_id = msg.leader_id;
    }
    else {
      resolved.leader_id = 0
    }

    return resolved;
    }
};

module.exports = uav_ids;
