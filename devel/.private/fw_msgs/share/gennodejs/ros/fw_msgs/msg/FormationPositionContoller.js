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

class FormationPositionContoller {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.count_number = null;
      this.leaderHeading = null;
      this.leaderCommand_yaw = null;
      this.leaderAirspeed = null;
    }
    else {
      if (initObj.hasOwnProperty('count_number')) {
        this.count_number = initObj.count_number
      }
      else {
        this.count_number = 0.0;
      }
      if (initObj.hasOwnProperty('leaderHeading')) {
        this.leaderHeading = initObj.leaderHeading
      }
      else {
        this.leaderHeading = 0.0;
      }
      if (initObj.hasOwnProperty('leaderCommand_yaw')) {
        this.leaderCommand_yaw = initObj.leaderCommand_yaw
      }
      else {
        this.leaderCommand_yaw = 0.0;
      }
      if (initObj.hasOwnProperty('leaderAirspeed')) {
        this.leaderAirspeed = initObj.leaderAirspeed
      }
      else {
        this.leaderAirspeed = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FormationPositionContoller
    // Serialize message field [count_number]
    bufferOffset = _serializer.float64(obj.count_number, buffer, bufferOffset);
    // Serialize message field [leaderHeading]
    bufferOffset = _serializer.float64(obj.leaderHeading, buffer, bufferOffset);
    // Serialize message field [leaderCommand_yaw]
    bufferOffset = _serializer.float64(obj.leaderCommand_yaw, buffer, bufferOffset);
    // Serialize message field [leaderAirspeed]
    bufferOffset = _serializer.float64(obj.leaderAirspeed, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FormationPositionContoller
    let len;
    let data = new FormationPositionContoller(null);
    // Deserialize message field [count_number]
    data.count_number = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leaderHeading]
    data.leaderHeading = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leaderCommand_yaw]
    data.leaderCommand_yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leaderAirspeed]
    data.leaderAirspeed = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/FormationPositionContoller';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd87d2620f7eee8afb717e021cba9a3f4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # FormationPositionContoller.msg
    
    float64 count_number
    float64 leaderHeading
    float64 leaderCommand_yaw
    float64 leaderAirspeed
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FormationPositionContoller(null);
    if (msg.count_number !== undefined) {
      resolved.count_number = msg.count_number;
    }
    else {
      resolved.count_number = 0.0
    }

    if (msg.leaderHeading !== undefined) {
      resolved.leaderHeading = msg.leaderHeading;
    }
    else {
      resolved.leaderHeading = 0.0
    }

    if (msg.leaderCommand_yaw !== undefined) {
      resolved.leaderCommand_yaw = msg.leaderCommand_yaw;
    }
    else {
      resolved.leaderCommand_yaw = 0.0
    }

    if (msg.leaderAirspeed !== undefined) {
      resolved.leaderAirspeed = msg.leaderAirspeed;
    }
    else {
      resolved.leaderAirspeed = 0.0
    }

    return resolved;
    }
};

module.exports = FormationPositionContoller;
