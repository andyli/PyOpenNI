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


#ifndef SKELETON_CAPABILITY_WRAPPER_H
#define	SKELETON_CAPABILITY_WRAPPER_H

#include <XnCppWrapper.h>
#include "wrapperTypes.h"

/** Managing active joints and profiles **/
XnBool SkeletonCapability_IsJointActive_wrapped(xn::SkeletonCapability& self, XnSkeletonJoint joint);
void SkeletonCapability_SetJointActive_wrapped(xn::SkeletonCapability& self, XnSkeletonJoint joint, XnBool active);
void SkeletonCapability_SetSkeletonProfile_wrapped(xn::SkeletonCapability& self, XnSkeletonProfile profile);

/** User tracking and calibrating methods **/
void SkeletonCapability_StartTracking_wrapped(xn::SkeletonCapability& self, XnUserID user);
void SkeletonCapability_StopTracking_wrapped(xn::SkeletonCapability& self, XnUserID user);
void SkeletonCapability_Reset_wrapped(xn::SkeletonCapability& self, XnUserID user);
void SkeletonCapability_RequestCalibration_wrapped(xn::SkeletonCapability& self, XnUserID user, XnBool force);
void SkeletonCapability_AbortCalibration_wrapped(xn::SkeletonCapability& self, XnUserID user);

/** Calibration data methods **/
void SkeletonCapability_SaveCalibrationData_wrapped(xn::SkeletonCapability& self, XnUserID user, XnUInt32 slot);
void SkeletonCapability_ClearCalibrationData_wrapped(xn::SkeletonCapability& self, XnUInt32 slot);
void SkeletonCapability_LoadCalibrationData_wrapped(xn::SkeletonCapability& self, XnUserID user, XnUInt32 slot);
void SkeletonCapability_IsCalibrationData_wrapped(xn::SkeletonCapability& self, XnUInt32 slot);

/** Other properties and methods **/
void SkeletonCapability_SetSmoothing_wrapped(xn::SkeletonCapability& self, XnFloat smoothing);

/** Callbacks **/

XnCallbackHandle SkeletonCapability_RegisterCalibrationStart(xn::SkeletonCapability& self, BP::object& callback);
void SkeletonCapability_UnregisterCalibrationStart(xn::SkeletonCapability& self, XnCallbackHandle handle);

XnCallbackHandle SkeletonCapability_RegisterCalibrationComplete(xn::SkeletonCapability& self, BP::object& callback);
void SkeletonCapability_UnregisterCalibrationComplete(xn::SkeletonCapability& self, XnCallbackHandle handle);

XnCallbackHandle SkeletonCapability_RegisterCalibrationInProgress(xn::SkeletonCapability& self, BP::object& callback);
void SkeletonCapability_UnregisterCalibrationInProgress(xn::SkeletonCapability& self, XnCallbackHandle handle);


/** Getting individual joints orientation/position **/
XnSkeletonJointOrientation SkeletonCapability_GetJointOrientation_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint);
XnSkeletonJointPosition SkeletonCapability_GetJointPosition_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint);
XnSkeletonJointTransformation SkeletonCapability_GetJoint_wrapped(xn::SkeletonCapability& self, XnUserID user, XnSkeletonJoint joint);

/** Internal callback implementations **/

void SkeletonCapability_CalibrationStart_cb(xn::SkeletonCapability &src, XnUserID user, void *cookie);

//This is used for both CalibrationInProgress and CalibrationCompleted
void SkeletonCapability_CalibrationStatus_cb(xn::SkeletonCapability &src, XnUserID user, XnCalibrationStatus status, void *cookie);

#endif	/* SKELETON_CAPABILITY_WRAPPER_H */
