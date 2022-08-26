
"use strict";

let GetTorque = require('./GetTorque.js')
let GetPosition = require('./GetPosition.js')
let SyncGetPosition = require('./SyncGetPosition.js')
let BulkGetItem = require('./BulkGetItem.js')

module.exports = {
  GetTorque: GetTorque,
  GetPosition: GetPosition,
  SyncGetPosition: SyncGetPosition,
  BulkGetItem: BulkGetItem,
};
