// Auto-generated. Do not edit!

// (in-package communication.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class FormationNavigator {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.count_number = null;
      this.position_x = null;
      this.position_y = null;
      this.position_z = null;
      this.homeLat = null;
      this.homeLon = null;
      this.homeAlt = null;
      this.gps_time = null;
      this.gap_x = null;
      this.gap_y = null;
      this.leaderAirspeed = null;
      this.leaderHeading = null;
    }
    else {
      if (initObj.hasOwnProperty('count_number')) {
        this.count_number = initObj.count_number
      }
      else {
        this.count_number = 0.0;
      }
      if (initObj.hasOwnProperty('position_x')) {
        this.position_x = initObj.position_x
      }
      else {
        this.position_x = 0.0;
      }
      if (initObj.hasOwnProperty('position_y')) {
        this.position_y = initObj.position_y
      }
      else {
        this.position_y = 0.0;
      }
      if (initObj.hasOwnProperty('position_z')) {
        this.position_z = initObj.position_z
      }
      else {
        this.position_z = 0.0;
      }
      if (initObj.hasOwnProperty('homeLat')) {
        this.homeLat = initObj.homeLat
      }
      else {
        this.homeLat = 0.0;
      }
      if (initObj.hasOwnProperty('homeLon')) {
        this.homeLon = initObj.homeLon
      }
      else {
        this.homeLon = 0.0;
      }
      if (initObj.hasOwnProperty('homeAlt')) {
        this.homeAlt = initObj.homeAlt
      }
      else {
        this.homeAlt = 0.0;
      }
      if (initObj.hasOwnProperty('gps_time')) {
        this.gps_time = initObj.gps_time
      }
      else {
        this.gps_time = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('gap_x')) {
        this.gap_x = initObj.gap_x
      }
      else {
        this.gap_x = 0;
      }
      if (initObj.hasOwnProperty('gap_y')) {
        this.gap_y = initObj.gap_y
      }
      else {
        this.gap_y = 0;
      }
      if (initObj.hasOwnProperty('leaderAirspeed')) {
        this.leaderAirspeed = initObj.leaderAirspeed
      }
      else {
        this.leaderAirspeed = 0.0;
      }
      if (initObj.hasOwnProperty('leaderHeading')) {
        this.leaderHeading = initObj.leaderHeading
      }
      else {
        this.leaderHeading = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FormationNavigator
    // Serialize message field [count_number]
    bufferOffset = _serializer.float64(obj.count_number, buffer, bufferOffset);
    // Serialize message field [position_x]
    bufferOffset = _serializer.float64(obj.position_x, buffer, bufferOffset);
    // Serialize message field [position_y]
    bufferOffset = _serializer.float64(obj.position_y, buffer, bufferOffset);
    // Serialize message field [position_z]
    bufferOffset = _serializer.float64(obj.position_z, buffer, bufferOffset);
    // Serialize message field [homeLat]
    bufferOffset = _serializer.float64(obj.homeLat, buffer, bufferOffset);
    // Serialize message field [homeLon]
    bufferOffset = _serializer.float64(obj.homeLon, buffer, bufferOffset);
    // Serialize message field [homeAlt]
    bufferOffset = _serializer.float64(obj.homeAlt, buffer, bufferOffset);
    // Serialize message field [gps_time]
    bufferOffset = _serializer.time(obj.gps_time, buffer, bufferOffset);
    // Serialize message field [gap_x]
    bufferOffset = _serializer.int32(obj.gap_x, buffer, bufferOffset);
    // Serialize message field [gap_y]
    bufferOffset = _serializer.int32(obj.gap_y, buffer, bufferOffset);
    // Serialize message field [leaderAirspeed]
    bufferOffset = _serializer.float64(obj.leaderAirspeed, buffer, bufferOffset);
    // Serialize message field [leaderHeading]
    bufferOffset = _serializer.float64(obj.leaderHeading, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FormationNavigator
    let len;
    let data = new FormationNavigator(null);
    // Deserialize message field [count_number]
    data.count_number = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [position_x]
    data.position_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [position_y]
    data.position_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [position_z]
    data.position_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [homeLat]
    data.homeLat = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [homeLon]
    data.homeLon = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [homeAlt]
    data.homeAlt = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [gps_time]
    data.gps_time = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [gap_x]
    data.gap_x = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [gap_y]
    data.gap_y = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [leaderAirspeed]
    data.leaderAirspeed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leaderHeading]
    data.leaderHeading = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'communication/FormationNavigator';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a05bd8f0a47698fdac1759384190f8ba';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # FormationNavigator.msg
    
    float64 count_number
    float64 position_x
    float64 position_y
    float64 position_z
    
    float64 homeLat
    float64 homeLon
    float64 homeAlt
    
    time gps_time
    
    int32 gap_x
    int32 gap_y
    
    float64 leaderAirspeed
    float64 leaderHeading
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FormationNavigator(null);
    if (msg.count_number !== undefined) {
      resolved.count_number = msg.count_number;
    }
    else {
      resolved.count_number = 0.0
    }

    if (msg.position_x !== undefined) {
      resolved.position_x = msg.position_x;
    }
    else {
      resolved.position_x = 0.0
    }

    if (msg.position_y !== undefined) {
      resolved.position_y = msg.position_y;
    }
    else {
      resolved.position_y = 0.0
    }

    if (msg.position_z !== undefined) {
      resolved.position_z = msg.position_z;
    }
    else {
      resolved.position_z = 0.0
    }

    if (msg.homeLat !== undefined) {
      resolved.homeLat = msg.homeLat;
    }
    else {
      resolved.homeLat = 0.0
    }

    if (msg.homeLon !== undefined) {
      resolved.homeLon = msg.homeLon;
    }
    else {
      resolved.homeLon = 0.0
    }

    if (msg.homeAlt !== undefined) {
      resolved.homeAlt = msg.homeAlt;
    }
    else {
      resolved.homeAlt = 0.0
    }

    if (msg.gps_time !== undefined) {
      resolved.gps_time = msg.gps_time;
    }
    else {
      resolved.gps_time = {secs: 0, nsecs: 0}
    }

    if (msg.gap_x !== undefined) {
      resolved.gap_x = msg.gap_x;
    }
    else {
      resolved.gap_x = 0
    }

    if (msg.gap_y !== undefined) {
      resolved.gap_y = msg.gap_y;
    }
    else {
      resolved.gap_y = 0
    }

    if (msg.leaderAirspeed !== undefined) {
      resolved.leaderAirspeed = msg.leaderAirspeed;
    }
    else {
      resolved.leaderAirspeed = 0.0
    }

    if (msg.leaderHeading !== undefined) {
      resolved.leaderHeading = msg.leaderHeading;
    }
    else {
      resolved.leaderHeading = 0.0
    }

    return resolved;
    }
};

module.exports = FormationNavigator;
