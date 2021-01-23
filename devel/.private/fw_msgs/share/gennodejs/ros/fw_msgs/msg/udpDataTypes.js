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

class udpDataTypes {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.startUDP_Data = null;
      this.startUPD_HOME = null;
      this.startACK = null;
    }
    else {
      if (initObj.hasOwnProperty('startUDP_Data')) {
        this.startUDP_Data = initObj.startUDP_Data
      }
      else {
        this.startUDP_Data = 0;
      }
      if (initObj.hasOwnProperty('startUPD_HOME')) {
        this.startUPD_HOME = initObj.startUPD_HOME
      }
      else {
        this.startUPD_HOME = 0;
      }
      if (initObj.hasOwnProperty('startACK')) {
        this.startACK = initObj.startACK
      }
      else {
        this.startACK = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type udpDataTypes
    // Serialize message field [startUDP_Data]
    bufferOffset = _serializer.int8(obj.startUDP_Data, buffer, bufferOffset);
    // Serialize message field [startUPD_HOME]
    bufferOffset = _serializer.int8(obj.startUPD_HOME, buffer, bufferOffset);
    // Serialize message field [startACK]
    bufferOffset = _serializer.int8(obj.startACK, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type udpDataTypes
    let len;
    let data = new udpDataTypes(null);
    // Deserialize message field [startUDP_Data]
    data.startUDP_Data = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [startUPD_HOME]
    data.startUPD_HOME = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [startACK]
    data.startACK = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/udpDataTypes';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '24c91d25d88a35c807139468a346102b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # udpDataTypes.msg
    
    
    int8 startUDP_Data
    int8 startUPD_HOME
    int8 startACK
    
    # 数据分发
    # 数据控制
    
    # taskType_sub = nh.advertise<fw_msgs::udpDataTypes>
    #           ("communication/taskTypes/udpDataTypes", 1);
    
    # taskType_sub = nh.subscribe<fw_msgs::QgcCommands>
    #           (uavName + "/communication/QgcCommands" + s_i,1, handler_taskType);
    # 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new udpDataTypes(null);
    if (msg.startUDP_Data !== undefined) {
      resolved.startUDP_Data = msg.startUDP_Data;
    }
    else {
      resolved.startUDP_Data = 0
    }

    if (msg.startUPD_HOME !== undefined) {
      resolved.startUPD_HOME = msg.startUPD_HOME;
    }
    else {
      resolved.startUPD_HOME = 0
    }

    if (msg.startACK !== undefined) {
      resolved.startACK = msg.startACK;
    }
    else {
      resolved.startACK = 0
    }

    return resolved;
    }
};

module.exports = udpDataTypes;
