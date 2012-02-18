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


#include "PoseDetectionCapabilityWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"

void PoseDetectionCapability_StartPoseDetection_wrapped(xn::PoseDetectionCapability& self, std::string pose, XnUserID user) {
    check( self.StartPoseDetection(pose.c_str(), user) );
}

void PoseDetectionCapability_StopPoseDetection_wrapped(xn::PoseDetectionCapability& self, XnUserID user) {
    check( self.StopPoseDetection(user) );
}

XnCallbackHandle PoseDetectionCapability_RegisterPoseDetectedCallback(xn::PoseDetectionCapability& self, BP::object callback) {
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object;
    *cookie = callback;
    
    check( self.RegisterToPoseDetected(&PoseDetectionCapability_PoseDetection_cb, cookie, handle) );
    
    return handle;
}
void PoseDetectionCapability_UnregisterPoseDetectedCallback(xn::PoseDetectionCapability& self, XnCallbackHandle handle) {
    self.UnregisterFromPoseDetected(handle);
}

XnCallbackHandle PoseDetectionCapability_RegisterOutOfPoseCallback(xn::PoseDetectionCapability& self, BP::object callback) {
    XnCallbackHandle handle;
    
    BP::object* cookie = new BP::object;
    *cookie = callback;
    
    check( self.RegisterToOutOfPose(&PoseDetectionCapability_PoseDetection_cb, cookie, handle) );
    
    return handle;
}
void PoseDetectionCapability_UnregisterOutOfPoseCallback(xn::PoseDetectionCapability& self, XnCallbackHandle handle) {
    self.UnregisterFromOutOfPose(handle);
}


/** Internal callback implementations **/
void PoseDetectionCapability_PoseDetection_cb(xn::PoseDetectionCapability& src, const XnChar* pose, XnUserID user, void* cookie) {
    BP::object& func = *((BP::object*)cookie);
    
    func(src, std::string(pose), user);
}
