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

class UDPData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.number = null;
      this.messageid = null;
      this.uavid = null;
      this.plane_state = null;
      this.plane_group = null;
      this.longitudex = null;
      this.latitudey = null;
      this.altitudez = null;
      this.heading = null;
      this.velocity = null;
      this.commandyaw = null;
      this.GPStime = null;
      this.parity = null;
    }
    else {
      if (initObj.hasOwnProperty('number')) {
        this.number = initObj.number
      }
      else {
        this.number = 0;
      }
      if (initObj.hasOwnProperty('messageid')) {
        this.messageid = initObj.messageid
      }
      else {
        this.messageid = 0;
      }
      if (initObj.hasOwnProperty('uavid')) {
        this.uavid = initObj.uavid
      }
      else {
        this.uavid = 0;
      }
      if (initObj.hasOwnProperty('plane_state')) {
        this.plane_state = initObj.plane_state
      }
      else {
        this.plane_state = 0;
      }
      if (initObj.hasOwnProperty('plane_group')) {
        this.plane_group = initObj.plane_group
      }
      else {
        this.plane_group = 0;
      }
      if (initObj.hasOwnProperty('longitudex')) {
        this.longitudex = initObj.longitudex
      }
      else {
        this.longitudex = 0.0;
      }
      if (initObj.hasOwnProperty('latitudey')) {
        this.latitudey = initObj.latitudey
      }
      else {
        this.latitudey = 0.0;
      }
      if (initObj.hasOwnProperty('altitudez')) {
        this.altitudez = initObj.altitudez
      }
      else {
        this.altitudez = 0.0;
      }
      if (initObj.hasOwnProperty('heading')) {
        this.heading = initObj.heading
      }
      else {
        this.heading = 0.0;
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0.0;
      }
      if (initObj.hasOwnProperty('commandyaw')) {
        this.commandyaw = initObj.commandyaw
      }
      else {
        this.commandyaw = 0.0;
      }
      if (initObj.hasOwnProperty('GPStime')) {
        this.GPStime = initObj.GPStime
      }
      else {
        this.GPStime = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('parity')) {
        this.parity = initObj.parity
      }
      else {
        this.parity = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UDPData
    // Serialize message field [number]
    bufferOffset = _serializer.int64(obj.number, buffer, bufferOffset);
    // Serialize message field [messageid]
    bufferOffset = _serializer.uint16(obj.messageid, buffer, bufferOffset);
    // Serialize message field [uavid]
    bufferOffset = _serializer.uint16(obj.uavid, buffer, bufferOffset);
    // Serialize message field [plane_state]
    bufferOffset = _serializer.uint16(obj.plane_state, buffer, bufferOffset);
    // Serialize message field [plane_group]
    bufferOffset = _serializer.uint16(obj.plane_group, buffer, bufferOffset);
    // Serialize message field [longitudex]
    bufferOffset = _serializer.float64(obj.longitudex, buffer, bufferOffset);
    // Serialize message field [latitudey]
    bufferOffset = _serializer.float64(obj.latitudey, buffer, bufferOffset);
    // Serialize message field [altitudez]
    bufferOffset = _serializer.float64(obj.altitudez, buffer, bufferOffset);
    // Serialize message field [heading]
    bufferOffset = _serializer.float64(obj.heading, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.float64(obj.velocity, buffer, bufferOffset);
    // Serialize message field [commandyaw]
    bufferOffset = _serializer.float64(obj.commandyaw, buffer, bufferOffset);
    // Serialize message field [GPStime]
    bufferOffset = _serializer.time(obj.GPStime, buffer, bufferOffset);
    // Serialize message field [parity]
    bufferOffset = _serializer.int32(obj.parity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UDPData
    let len;
    let data = new UDPData(null);
    // Deserialize message field [number]
    data.number = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [messageid]
    data.messageid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [uavid]
    data.uavid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [plane_state]
    data.plane_state = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [plane_group]
    data.plane_group = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [longitudex]
    data.longitudex = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [latitudey]
    data.latitudey = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [altitudez]
    data.altitudez = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [heading]
    data.heading = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [commandyaw]
    data.commandyaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [GPStime]
    data.GPStime = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [parity]
    data.parity = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 76;
  }

  static datatype() {
    // Returns string type for a message object
    return 'communication/UDPData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1ff2b4674f767520061c38046240545f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # UDPMessage.msg
    
    int64 number
    uint16 messageid
    uint16 uavid
    uint16 plane_state
    uint16 plane_group
    float64 longitudex
    float64 latitudey
    float64 altitudez 
    float64 heading
    float64 velocity
    float64 commandyaw
    time GPStime
    int32 parity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new UDPData(null);
    if (msg.number !== undefined) {
      resolved.number = msg.number;
    }
    else {
      resolved.number = 0
    }

    if (msg.messageid !== undefined) {
      resolved.messageid = msg.messageid;
    }
    else {
      resolved.messageid = 0
    }

    if (msg.uavid !== undefined) {
      resolved.uavid = msg.uavid;
    }
    else {
      resolved.uavid = 0
    }

    if (msg.plane_state !== undefined) {
      resolved.plane_state = msg.plane_state;
    }
    else {
      resolved.plane_state = 0
    }

    if (msg.plane_group !== undefined) {
      resolved.plane_group = msg.plane_group;
    }
    else {
      resolved.plane_group = 0
    }

    if (msg.longitudex !== undefined) {
      resolved.longitudex = msg.longitudex;
    }
    else {
      resolved.longitudex = 0.0
    }

    if (msg.latitudey !== undefined) {
      resolved.latitudey = msg.latitudey;
    }
    else {
      resolved.latitudey = 0.0
    }

    if (msg.altitudez !== undefined) {
      resolved.altitudez = msg.altitudez;
    }
    else {
      resolved.altitudez = 0.0
    }

    if (msg.heading !== undefined) {
      resolved.heading = msg.heading;
    }
    else {
      resolved.heading = 0.0
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0.0
    }

    if (msg.commandyaw !== undefined) {
      resolved.commandyaw = msg.commandyaw;
    }
    else {
      resolved.commandyaw = 0.0
    }

    if (msg.GPStime !== undefined) {
      resolved.GPStime = msg.GPStime;
    }
    else {
      resolved.GPStime = {secs: 0, nsecs: 0}
    }

    if (msg.parity !== undefined) {
      resolved.parity = msg.parity;
    }
    else {
      resolved.parity = 0
    }

    return resolved;
    }
};

module.exports = UDPData;
