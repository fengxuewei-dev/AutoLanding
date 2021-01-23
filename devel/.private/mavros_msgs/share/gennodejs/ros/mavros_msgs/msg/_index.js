
"use strict";

let Mavlink = require('./Mavlink.js');
let Param = require('./Param.js');
let PositionTarget = require('./PositionTarget.js');
let CommandCode = require('./CommandCode.js');
let RCOut = require('./RCOut.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let HomePosition = require('./HomePosition.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let HilGPS = require('./HilGPS.js');
let Formation_fixed_wing = require('./Formation_fixed_wing.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let MountControl = require('./MountControl.js');
let Commands = require('./Commands.js');
let LogEntry = require('./LogEntry.js');
let ActuatorControl = require('./ActuatorControl.js');
let RTCM = require('./RTCM.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let DebugValue = require('./DebugValue.js');
let StatusText = require('./StatusText.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let RadioStatus = require('./RadioStatus.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let VehicleInfo = require('./VehicleInfo.js');
let EstimatorStatus = require('./EstimatorStatus.js');
let VFR_HUD = require('./VFR_HUD.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let ExtendedState = require('./ExtendedState.js');
let Thrust = require('./Thrust.js');
let HilSensor = require('./HilSensor.js');
let RCIn = require('./RCIn.js');
let State = require('./State.js');
let ManualControl = require('./ManualControl.js');
let Formations = require('./Formations.js');
let FileEntry = require('./FileEntry.js');
let ParamValue = require('./ParamValue.js');
let WaypointList = require('./WaypointList.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let Waypoint = require('./Waypoint.js');
let Altitude = require('./Altitude.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let LandingTarget = require('./LandingTarget.js');
let HilControls = require('./HilControls.js');
let Trajectory = require('./Trajectory.js');
let BatteryStatus = require('./BatteryStatus.js');
let LogData = require('./LogData.js');
let Vibration = require('./Vibration.js');
let WaypointReached = require('./WaypointReached.js');

module.exports = {
  Mavlink: Mavlink,
  Param: Param,
  PositionTarget: PositionTarget,
  CommandCode: CommandCode,
  RCOut: RCOut,
  CamIMUStamp: CamIMUStamp,
  ADSBVehicle: ADSBVehicle,
  HomePosition: HomePosition,
  HilStateQuaternion: HilStateQuaternion,
  HilGPS: HilGPS,
  Formation_fixed_wing: Formation_fixed_wing,
  CompanionProcessStatus: CompanionProcessStatus,
  MountControl: MountControl,
  Commands: Commands,
  LogEntry: LogEntry,
  ActuatorControl: ActuatorControl,
  RTCM: RTCM,
  WheelOdomStamped: WheelOdomStamped,
  DebugValue: DebugValue,
  StatusText: StatusText,
  OpticalFlowRad: OpticalFlowRad,
  GlobalPositionTarget: GlobalPositionTarget,
  RadioStatus: RadioStatus,
  OverrideRCIn: OverrideRCIn,
  VehicleInfo: VehicleInfo,
  EstimatorStatus: EstimatorStatus,
  VFR_HUD: VFR_HUD,
  TimesyncStatus: TimesyncStatus,
  ExtendedState: ExtendedState,
  Thrust: Thrust,
  HilSensor: HilSensor,
  RCIn: RCIn,
  State: State,
  ManualControl: ManualControl,
  Formations: Formations,
  FileEntry: FileEntry,
  ParamValue: ParamValue,
  WaypointList: WaypointList,
  HilActuatorControls: HilActuatorControls,
  AttitudeTarget: AttitudeTarget,
  Waypoint: Waypoint,
  Altitude: Altitude,
  OnboardComputerStatus: OnboardComputerStatus,
  LandingTarget: LandingTarget,
  HilControls: HilControls,
  Trajectory: Trajectory,
  BatteryStatus: BatteryStatus,
  LogData: LogData,
  Vibration: Vibration,
  WaypointReached: WaypointReached,
};
