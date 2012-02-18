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


#ifndef POSE_DETECTION_CAPABILITY_WRAPPER_H
#define	POSE_DETECTION_CAPABILITY_WRAPPER_H

#include "wrapperTypes.h"

void PoseDetectionCapability_StartPoseDetection_wrapped(xn::PoseDetectionCapability& self, std::string pose, XnUserID user);

void PoseDetectionCapability_StopPoseDetection_wrapped(xn::PoseDetectionCapability& self, XnUserID user);

XnCallbackHandle PoseDetectionCapability_RegisterPoseDetectedCallback(xn::PoseDetectionCapability& self, BP::object callback);
void PoseDetectionCapability_UnregisterPoseDetectedCallback(xn::PoseDetectionCapability& self, XnCallbackHandle handle);

XnCallbackHandle PoseDetectionCapability_RegisterOutOfPoseCallback(xn::PoseDetectionCapability& self, BP::object callback);
void PoseDetectionCapability_UnregisterOutOfPoseCallback(xn::PoseDetectionCapability& self, XnCallbackHandle handle);


/** Internal callback implementations **/
void PoseDetectionCapability_PoseDetection_cb(xn::PoseDetectionCapability& src, const XnChar* pose, XnUserID user, void* cookie);

#endif	/* POSE_DETECTION_CAPABILITY_WRAPPER_H */
