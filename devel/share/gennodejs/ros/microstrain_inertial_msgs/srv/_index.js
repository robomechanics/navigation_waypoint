
"use strict";

let GetHeadingSource = require('./GetHeadingSource.js')
let SetDynamicsMode = require('./SetDynamicsMode.js')
let GetSensor2VehicleOffset = require('./GetSensor2VehicleOffset.js')
let GetComplementaryFilter = require('./GetComplementaryFilter.js')
let GetGyroBiasModel = require('./GetGyroBiasModel.js')
let SetZeroVelocityUpdateThreshold = require('./SetZeroVelocityUpdateThreshold.js')
let GetAccelNoise = require('./GetAccelNoise.js')
let SetGyroBias = require('./SetGyroBias.js')
let SetHardIronValues = require('./SetHardIronValues.js')
let GetRelativePositionReference = require('./GetRelativePositionReference.js')
let SetAccelBiasModel = require('./SetAccelBiasModel.js')
let GetMagNoise = require('./GetMagNoise.js')
let SetRelativePositionReference = require('./SetRelativePositionReference.js')
let GetSensor2VehicleRotation = require('./GetSensor2VehicleRotation.js')
let GetAccelBias = require('./GetAccelBias.js')
let DeviceReport = require('./DeviceReport.js')
let SetAccelNoise = require('./SetAccelNoise.js')
let SetMagDipAdaptiveVals = require('./SetMagDipAdaptiveVals.js')
let ExternalHeadingUpdate = require('./ExternalHeadingUpdate.js')
let GetMagDipAdaptiveVals = require('./GetMagDipAdaptiveVals.js')
let SetAccelBias = require('./SetAccelBias.js')
let GetGyroBias = require('./GetGyroBias.js')
let GetAccelAdaptiveVals = require('./GetAccelAdaptiveVals.js')
let SetGyroBiasModel = require('./SetGyroBiasModel.js')
let GetAccelBiasModel = require('./GetAccelBiasModel.js')
let GetSensor2VehicleTransformation = require('./GetSensor2VehicleTransformation.js')
let SetAccelAdaptiveVals = require('./SetAccelAdaptiveVals.js')
let SetTareOrientation = require('./SetTareOrientation.js')
let GetZeroAngleUpdateThreshold = require('./GetZeroAngleUpdateThreshold.js')
let SetConingScullingComp = require('./SetConingScullingComp.js')
let SetZeroAngleUpdateThreshold = require('./SetZeroAngleUpdateThreshold.js')
let GetZeroVelocityUpdateThreshold = require('./GetZeroVelocityUpdateThreshold.js')
let GetSoftIronMatrix = require('./GetSoftIronMatrix.js')
let GetHardIronValues = require('./GetHardIronValues.js')
let SetReferencePosition = require('./SetReferencePosition.js')
let GetGravityAdaptiveVals = require('./GetGravityAdaptiveVals.js')
let SetGyroNoise = require('./SetGyroNoise.js')
let InitFilterHeading = require('./InitFilterHeading.js')
let GetTareOrientation = require('./GetTareOrientation.js')
let SetSensor2VehicleOffset = require('./SetSensor2VehicleOffset.js')
let SetComplementaryFilter = require('./SetComplementaryFilter.js')
let SetMagAdaptiveVals = require('./SetMagAdaptiveVals.js')
let GetDynamicsMode = require('./GetDynamicsMode.js')
let InitFilterEuler = require('./InitFilterEuler.js')
let GetConingScullingComp = require('./GetConingScullingComp.js')
let SetMagNoise = require('./SetMagNoise.js')
let SetGravityAdaptiveVals = require('./SetGravityAdaptiveVals.js')
let GetGyroNoise = require('./GetGyroNoise.js')
let SetEstimationControlFlags = require('./SetEstimationControlFlags.js')
let SetSensor2VehicleRotation = require('./SetSensor2VehicleRotation.js')
let SetSoftIronMatrix = require('./SetSoftIronMatrix.js')
let GetMagAdaptiveVals = require('./GetMagAdaptiveVals.js')
let SetFilterSpeedLeverArm = require('./SetFilterSpeedLeverArm.js')
let DeviceSettings = require('./DeviceSettings.js')
let GetReferencePosition = require('./GetReferencePosition.js')
let SetHeadingSource = require('./SetHeadingSource.js')
let GetEstimationControlFlags = require('./GetEstimationControlFlags.js')

module.exports = {
  GetHeadingSource: GetHeadingSource,
  SetDynamicsMode: SetDynamicsMode,
  GetSensor2VehicleOffset: GetSensor2VehicleOffset,
  GetComplementaryFilter: GetComplementaryFilter,
  GetGyroBiasModel: GetGyroBiasModel,
  SetZeroVelocityUpdateThreshold: SetZeroVelocityUpdateThreshold,
  GetAccelNoise: GetAccelNoise,
  SetGyroBias: SetGyroBias,
  SetHardIronValues: SetHardIronValues,
  GetRelativePositionReference: GetRelativePositionReference,
  SetAccelBiasModel: SetAccelBiasModel,
  GetMagNoise: GetMagNoise,
  SetRelativePositionReference: SetRelativePositionReference,
  GetSensor2VehicleRotation: GetSensor2VehicleRotation,
  GetAccelBias: GetAccelBias,
  DeviceReport: DeviceReport,
  SetAccelNoise: SetAccelNoise,
  SetMagDipAdaptiveVals: SetMagDipAdaptiveVals,
  ExternalHeadingUpdate: ExternalHeadingUpdate,
  GetMagDipAdaptiveVals: GetMagDipAdaptiveVals,
  SetAccelBias: SetAccelBias,
  GetGyroBias: GetGyroBias,
  GetAccelAdaptiveVals: GetAccelAdaptiveVals,
  SetGyroBiasModel: SetGyroBiasModel,
  GetAccelBiasModel: GetAccelBiasModel,
  GetSensor2VehicleTransformation: GetSensor2VehicleTransformation,
  SetAccelAdaptiveVals: SetAccelAdaptiveVals,
  SetTareOrientation: SetTareOrientation,
  GetZeroAngleUpdateThreshold: GetZeroAngleUpdateThreshold,
  SetConingScullingComp: SetConingScullingComp,
  SetZeroAngleUpdateThreshold: SetZeroAngleUpdateThreshold,
  GetZeroVelocityUpdateThreshold: GetZeroVelocityUpdateThreshold,
  GetSoftIronMatrix: GetSoftIronMatrix,
  GetHardIronValues: GetHardIronValues,
  SetReferencePosition: SetReferencePosition,
  GetGravityAdaptiveVals: GetGravityAdaptiveVals,
  SetGyroNoise: SetGyroNoise,
  InitFilterHeading: InitFilterHeading,
  GetTareOrientation: GetTareOrientation,
  SetSensor2VehicleOffset: SetSensor2VehicleOffset,
  SetComplementaryFilter: SetComplementaryFilter,
  SetMagAdaptiveVals: SetMagAdaptiveVals,
  GetDynamicsMode: GetDynamicsMode,
  InitFilterEuler: InitFilterEuler,
  GetConingScullingComp: GetConingScullingComp,
  SetMagNoise: SetMagNoise,
  SetGravityAdaptiveVals: SetGravityAdaptiveVals,
  GetGyroNoise: GetGyroNoise,
  SetEstimationControlFlags: SetEstimationControlFlags,
  SetSensor2VehicleRotation: SetSensor2VehicleRotation,
  SetSoftIronMatrix: SetSoftIronMatrix,
  GetMagAdaptiveVals: GetMagAdaptiveVals,
  SetFilterSpeedLeverArm: SetFilterSpeedLeverArm,
  DeviceSettings: DeviceSettings,
  GetReferencePosition: GetReferencePosition,
  SetHeadingSource: SetHeadingSource,
  GetEstimationControlFlags: GetEstimationControlFlags,
};
