// Auto-generated. Do not edit!

// (in-package navigator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let mavros_msgs = _finder('mavros_msgs');

//-----------------------------------------------------------

class position_setpoint_triplet {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.currentWaypoint = null;
      this.nextWaypoint = null;
      this.Throttle = null;
      this.ExistNext = null;
    }
    else {
      if (initObj.hasOwnProperty('currentWaypoint')) {
        this.currentWaypoint = initObj.currentWaypoint
      }
      else {
        this.currentWaypoint = new mavros_msgs.msg.Waypoint();
      }
      if (initObj.hasOwnProperty('nextWaypoint')) {
        this.nextWaypoint = initObj.nextWaypoint
      }
      else {
        this.nextWaypoint = new mavros_msgs.msg.Waypoint();
      }
      if (initObj.hasOwnProperty('Throttle')) {
        this.Throttle = initObj.Throttle
      }
      else {
        this.Throttle = 0;
      }
      if (initObj.hasOwnProperty('ExistNext')) {
        this.ExistNext = initObj.ExistNext
      }
      else {
        this.ExistNext = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type position_setpoint_triplet
    // Serialize message field [currentWaypoint]
    bufferOffset = mavros_msgs.msg.Waypoint.serialize(obj.currentWaypoint, buffer, bufferOffset);
    // Serialize message field [nextWaypoint]
    bufferOffset = mavros_msgs.msg.Waypoint.serialize(obj.nextWaypoint, buffer, bufferOffset);
    // Serialize message field [Throttle]
    bufferOffset = _serializer.int8(obj.Throttle, buffer, bufferOffset);
    // Serialize message field [ExistNext]
    bufferOffset = _serializer.int8(obj.ExistNext, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type position_setpoint_triplet
    let len;
    let data = new position_setpoint_triplet(null);
    // Deserialize message field [currentWaypoint]
    data.currentWaypoint = mavros_msgs.msg.Waypoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [nextWaypoint]
    data.nextWaypoint = mavros_msgs.msg.Waypoint.deserialize(buffer, bufferOffset);
    // Deserialize message field [Throttle]
    data.Throttle = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [ExistNext]
    data.ExistNext = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 92;
  }

  static datatype() {
    // Returns string type for a message object
    return 'navigator/position_setpoint_triplet';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3fb3b9f9f42aa6f50d1505ea97f3c07f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # position_setpoint_triplet.msg
    
    mavros_msgs/Waypoint currentWaypoint
    mavros_msgs/Waypoint nextWaypoint
    int8 Throttle
    int8 ExistNext
    
    ================================================================================
    MSG: mavros_msgs/Waypoint
    # Waypoint.msg
    #
    # ROS representation of MAVLink MISSION_ITEM
    # See mavlink documentation
    
    
    
    # see enum MAV_FRAME
    uint8 frame
    uint8 FRAME_GLOBAL = 0
    uint8 FRAME_LOCAL_NED = 1
    uint8 FRAME_MISSION = 2
    uint8 FRAME_GLOBAL_REL_ALT = 3
    uint8 FRAME_LOCAL_ENU = 4
    
    # see enum MAV_CMD and CommandCode.msg
    uint16 command
    
    bool is_current
    bool autocontinue
    # meaning of this params described in enum MAV_CMD
    float32 param1
    float32 param2
    float32 param3
    float32 param4
    float64 x_lat
    float64 y_long
    float64 z_alt
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new position_setpoint_triplet(null);
    if (msg.currentWaypoint !== undefined) {
      resolved.currentWaypoint = mavros_msgs.msg.Waypoint.Resolve(msg.currentWaypoint)
    }
    else {
      resolved.currentWaypoint = new mavros_msgs.msg.Waypoint()
    }

    if (msg.nextWaypoint !== undefined) {
      resolved.nextWaypoint = mavros_msgs.msg.Waypoint.Resolve(msg.nextWaypoint)
    }
    else {
      resolved.nextWaypoint = new mavros_msgs.msg.Waypoint()
    }

    if (msg.Throttle !== undefined) {
      resolved.Throttle = msg.Throttle;
    }
    else {
      resolved.Throttle = 0
    }

    if (msg.ExistNext !== undefined) {
      resolved.ExistNext = msg.ExistNext;
    }
    else {
      resolved.ExistNext = 0
    }

    return resolved;
    }
};

module.exports = position_setpoint_triplet;
