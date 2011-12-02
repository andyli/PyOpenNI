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


#ifndef USER_GENERATOR_WRAPPER_H
#define	USER_GENERATOR_WRAPPER_H

#include <XnCppWrapper.h>
#include "wrapperTypes.h"

void UserGenerator_Create_wrapped(xn::UserGenerator& self, xn::Context& ctx);

XnUInt16 UserGenerator_CountUsers(xn::UserGenerator const & self);

xn::SkeletonCapability UserGenerator_GetSkeletonCap_wrapped(xn::UserGenerator& self);
xn::PoseDetectionCapability UserGenerator_GetPoseDetectionCap_wrapped(xn::UserGenerator& self);

BP::list UserGenerator_GetCoM_wrapped(xn::UserGenerator& self, XnUserID user);

XnCallbackHandle UserGenerator_RegisterUserCallbacks_wrapped(xn::UserGenerator& self, BP::object newUser, BP::object lostUser);
void UserGenerator_UnregisterUserCallbacks_wrapped(xn::UserGenerator& self, XnCallbackHandle handle);

/** Internal callback implementations **/
void NewUser_callback(xn::UserGenerator& src, XnUserID user, void* cookie);
void LostUser_callback(xn::UserGenerator& src, XnUserID user, void* cookie);

#endif	/* USER_GENERATOR_WRAPPER_H */
