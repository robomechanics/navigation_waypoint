// Auto-generated. Do not edit!

// (in-package pxrf.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class PxrfMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.dailyId = null;
      this.testId = null;
      this.testDateTime = null;
      this.chemistry = null;
    }
    else {
      if (initObj.hasOwnProperty('dailyId')) {
        this.dailyId = initObj.dailyId
      }
      else {
        this.dailyId = 0;
      }
      if (initObj.hasOwnProperty('testId')) {
        this.testId = initObj.testId
      }
      else {
        this.testId = 0;
      }
      if (initObj.hasOwnProperty('testDateTime')) {
        this.testDateTime = initObj.testDateTime
      }
      else {
        this.testDateTime = '';
      }
      if (initObj.hasOwnProperty('chemistry')) {
        this.chemistry = initObj.chemistry
      }
      else {
        this.chemistry = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PxrfMsg
    // Serialize message field [dailyId]
    bufferOffset = _serializer.int64(obj.dailyId, buffer, bufferOffset);
    // Serialize message field [testId]
    bufferOffset = _serializer.int64(obj.testId, buffer, bufferOffset);
    // Serialize message field [testDateTime]
    bufferOffset = _serializer.string(obj.testDateTime, buffer, bufferOffset);
    // Serialize message field [chemistry]
    bufferOffset = _serializer.string(obj.chemistry, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PxrfMsg
    let len;
    let data = new PxrfMsg(null);
    // Deserialize message field [dailyId]
    data.dailyId = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [testId]
    data.testId = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [testDateTime]
    data.testDateTime = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [chemistry]
    data.chemistry = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.testDateTime);
    length += _getByteLength(object.chemistry);
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pxrf/PxrfMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0ded31cc28f81581de2d0d50d228d3dc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 dailyId
    int64 testId
    string testDateTime
    string chemistry
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PxrfMsg(null);
    if (msg.dailyId !== undefined) {
      resolved.dailyId = msg.dailyId;
    }
    else {
      resolved.dailyId = 0
    }

    if (msg.testId !== undefined) {
      resolved.testId = msg.testId;
    }
    else {
      resolved.testId = 0
    }

    if (msg.testDateTime !== undefined) {
      resolved.testDateTime = msg.testDateTime;
    }
    else {
      resolved.testDateTime = ''
    }

    if (msg.chemistry !== undefined) {
      resolved.chemistry = msg.chemistry;
    }
    else {
      resolved.chemistry = ''
    }

    return resolved;
    }
};

module.exports = PxrfMsg;
