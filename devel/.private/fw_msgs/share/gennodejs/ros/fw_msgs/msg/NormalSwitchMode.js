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

class NormalSwitchMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Normal_Switch_Mode_Flag = null;
    }
    else {
      if (initObj.hasOwnProperty('Normal_Switch_Mode_Flag')) {
        this.Normal_Switch_Mode_Flag = initObj.Normal_Switch_Mode_Flag
      }
      else {
        this.Normal_Switch_Mode_Flag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type NormalSwitchMode
    // Serialize message field [Normal_Switch_Mode_Flag]
    bufferOffset = _serializer.int32(obj.Normal_Switch_Mode_Flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type NormalSwitchMode
    let len;
    let data = new NormalSwitchMode(null);
    // Deserialize message field [Normal_Switch_Mode_Flag]
    data.Normal_Switch_Mode_Flag = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/NormalSwitchMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a9e01fe0fa34836a4cd37fddd4a5467f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # NormalSwitchMode.msg
    
    int32 Normal_Switch_Mode_Flag
    
    # "communication/protectExitFlag/normalSwitchModeFlag"
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new NormalSwitchMode(null);
    if (msg.Normal_Switch_Mode_Flag !== undefined) {
      resolved.Normal_Switch_Mode_Flag = msg.Normal_Switch_Mode_Flag;
    }
    else {
      resolved.Normal_Switch_Mode_Flag = 0
    }

    return resolved;
    }
};

module.exports = NormalSwitchMode;
