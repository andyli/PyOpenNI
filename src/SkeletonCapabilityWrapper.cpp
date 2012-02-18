/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#include "SkeletonCapabilityWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"

/** Managing active joints and profiles **/
XnBool SkeletonCapability_IsJointActive_wrapped(xn::SkeletonCapability& self, XnSkeletonJoint joint) {
    return self.IsJointActive(joint);
}
void SkeletonCapability_SetJointActive_wrapped(xn::SkeletonCapability& self, XnSkeletonJoint joint, XnBool active) {
    check( self.SetJointActive(joint, active) );
}
void SkeletonCapability_SetSkeletonProfile_wrapped(xn::SkeletonCapability& self, XnSkeletonProfile profile) {
    check( self.SetSkeletonProfile(profile) );
}

/** User tracking and calibrating methods **/
void SkeletonCapability_StartTracking_wrapped(xn::SkeletonCapability& self, XnUserID user) {
    check( self.StartTracking(user) );
}
void SkeletonCapability_StopTracking_wrapped(xn::SkeletonCapability& self, XnUserID user) {
    check( self.StopTracking(user) );
}
void SkeletonCapability_Reset_wrapped(xn::SkeletonCapability& self, XnUserID user) {
    check( self.Reset(user) );
}
void SkeletonCapability_RequestCalibration_wrapped(xn::SkeletonCapability& self, XnUserID user, XnBool force) {
    check( self.RequestCalibration(user, force) );//TODO: add optional params here
}
void SkeletonCapability_AbortCalibration_wrapped(xn::SkeletonCapability& self, XnUserID user) {
    check( self.AbortCalibration(user) );
}

/** Calibration data methods **/
void SkeletonCapability_SaveCalibrationData_wrapped(xn::SkeletonCapability& self, XnUserID user, XnUInt32 slot) {
    check( self.SaveCalibrationData(user, slot) );
}
void SkeletonCapability_ClearCalibrationData_wrapped(xn::SkeletonCapability& self, XnUInt32 slot) {
    check( self.ClearCalibrationData(slot) );
}
void SkeletonCapability_LoadCalibrationData_wrapped(xn::SkeletonCapability& self, XnUserID user, XnUInt32 slot) {
    check( self.LoadCalibrationData(user, slot) );
}
void SkeletonCapability_IsCalibrationData_wrapped(xn::SkeletonCapability& self, XnUInt32 slot) {
    check( self.IsCalibrationData(slot) );
}

/** Other properties and methods **/
void SkeletonCapability_SetSmoothing_wrapped(xn::SkeletonCapability& self, XnFloat smoothing) {
    check( self.SetSmoothing(smoothing) );
}

/** Callbacks **/

XnCallbackHandle SkeletonCapability_RegisterCalibrationStart(xn::SkeletonCapability& self, BP::object& callback) {
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object;
    *cookie = callback;
    
    check( self.RegisterToCalibrationStart(&SkeletonCapability_CalibrationStart_cb, cookie, handle) );
    
    return handle;
}
void SkeletonCapability_UnregisterCalibrationStart(xn::SkeletonCapability& self, XnCallbackHandle handle) {
    check( self.UnregisterFromCalibrationStart(handle) );
}

XnCallbackHandle SkeletonCapability_RegisterCalibrationComplete(xn::SkeletonCapability& self, BP::object& callback) {
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object;
    *cookie = callback;
    
    check( self.RegisterToCalibrationComplete(&SkeletonCapability_CalibrationStatus_cb, cookie, handle) );
    
    return handle;
}
void SkeletonCapability_UnregisterCalibrationComplete(xn::SkeletonCapability& self, XnCallbackHandle handle) {
    self.UnregisterFromCalibrationComplete(handle);
}

XnCallbackHandle SkeletonCapability_RegisterCalibrationInProgress(xn::SkeletonCapability& self, BP::object& callback) {
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object;
    *cookie = callback;
    
    check( self.RegisterToCalibrationInProgress(&SkeletonCapability_CalibrationStatus_cb, cookie, handle) );
    
    return handle;
}
void SkeletonCapability_UnregisterCalibrationInProgress(xn::SkeletonCapability& self, XnCallbackHandle handle) {
    self.UnregisterFromCalibrationInProgress(handle);
}


/** Getting individual joints orientation/position **/
XnSkeletonJointOrientation SkeletonCapability_GetJointOrientation_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint) {
    XnSkeletonJointOrientation ret;
    check( self.GetSkeletonJointOrientation(user, joint, ret) );
    return ret;
}
XnSkeletonJointPosition SkeletonCapability_GetJointPosition_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint) {
    XnSkeletonJointPosition ret;
    check( self.GetSkeletonJointPosition(user, joint, ret) );
    return ret;
}
XnSkeletonJointTransformation SkeletonCapability_GetJoint_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint) {
    XnSkeletonJointTransformation ret;
    check( self.GetSkeletonJoint(user, joint, ret) );
    return ret;
}

/** Internal callback implementations **/

void SkeletonCapability_CalibrationStart_cb(xn::SkeletonCapability &src, XnUserID user, void *cookie) {
    BP::object& func = *((BP::object*)cookie);
    
    func(src, user);
}

//This is used for both CalibrationInProgress and CalibrationCompleted
void SkeletonCapability_CalibrationStatus_cb(xn::SkeletonCapability &src, XnUserID user, XnCalibrationStatus status, void *cookie) {
    BP::object& func = *((BP::object*)cookie);
    
    func(src, user, status);
}
