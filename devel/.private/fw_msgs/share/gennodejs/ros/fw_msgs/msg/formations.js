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

class formations {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.formationShape = null;
    }
    else {
      if (initObj.hasOwnProperty('formationShape')) {
        this.formationShape = initObj.formationShape
      }
      else {
        this.formationShape = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type formations
    // Serialize message field [formationShape]
    bufferOffset = _serializer.string(obj.formationShape, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type formations
    let len;
    let data = new formations(null);
    // Deserialize message field [formationShape]
    data.formationShape = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.formationShape.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fw_msgs/formations';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cb4dc526361d96c967f22a663f5d3a2a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # formations.msg
    
    string formationShape 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new formations(null);
    if (msg.formationShape !== undefined) {
      resolved.formationShape = msg.formationShape;
    }
    else {
      resolved.formationShape = ''
    }

    return resolved;
    }
};

module.exports = formations;
