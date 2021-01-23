
"use strict";

let CommandInt = require('./CommandInt.js')
let FileChecksum = require('./FileChecksum.js')
let FileMakeDir = require('./FileMakeDir.js')
let WaypointClear = require('./WaypointClear.js')
let ParamPull = require('./ParamPull.js')
let CommandLong = require('./CommandLong.js')
let LogRequestList = require('./LogRequestList.js')
let LogRequestData = require('./LogRequestData.js')
let ParamSet = require('./ParamSet.js')
let SetMode = require('./SetMode.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let FileTruncate = require('./FileTruncate.js')
let SetMavFrame = require('./SetMavFrame.js')
let CommandTOL = require('./CommandTOL.js')
let ParamPush = require('./ParamPush.js')
let ParamGet = require('./ParamGet.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let WaypointPull = require('./WaypointPull.js')
let FileOpen = require('./FileOpen.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let FileRead = require('./FileRead.js')
let FileWrite = require('./FileWrite.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let FileRemove = require('./FileRemove.js')
let FileList = require('./FileList.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let FileClose = require('./FileClose.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let StreamRate = require('./StreamRate.js')
let FileRename = require('./FileRename.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let WaypointPush = require('./WaypointPush.js')
let MessageInterval = require('./MessageInterval.js')
let MountConfigure = require('./MountConfigure.js')
let CommandBool = require('./CommandBool.js')
let CommandHome = require('./CommandHome.js')

module.exports = {
  CommandInt: CommandInt,
  FileChecksum: FileChecksum,
  FileMakeDir: FileMakeDir,
  WaypointClear: WaypointClear,
  ParamPull: ParamPull,
  CommandLong: CommandLong,
  LogRequestList: LogRequestList,
  LogRequestData: LogRequestData,
  ParamSet: ParamSet,
  SetMode: SetMode,
  WaypointSetCurrent: WaypointSetCurrent,
  FileTruncate: FileTruncate,
  SetMavFrame: SetMavFrame,
  CommandTOL: CommandTOL,
  ParamPush: ParamPush,
  ParamGet: ParamGet,
  FileRemoveDir: FileRemoveDir,
  WaypointPull: WaypointPull,
  FileOpen: FileOpen,
  VehicleInfoGet: VehicleInfoGet,
  FileRead: FileRead,
  FileWrite: FileWrite,
  LogRequestEnd: LogRequestEnd,
  FileRemove: FileRemove,
  FileList: FileList,
  CommandTriggerControl: CommandTriggerControl,
  FileClose: FileClose,
  CommandVtolTransition: CommandVtolTransition,
  StreamRate: StreamRate,
  FileRename: FileRename,
  CommandTriggerInterval: CommandTriggerInterval,
  WaypointPush: WaypointPush,
  MessageInterval: MessageInterval,
  MountConfigure: MountConfigure,
  CommandBool: CommandBool,
  CommandHome: CommandHome,
};
