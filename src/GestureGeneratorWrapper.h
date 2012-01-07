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


#ifndef GESTURE_GENERATOR_WRAPPER_H
#define	GESTURE_GENERATOR_WRAPPER_H

#include <XnCppWrapper.h>
#include "wrapperTypes.h"
#include <string>

void GestureGenerator_Create_wrapped(xn::GestureGenerator& self, xn::Context& context);

void GestureGenerator_AddGesture_wrapped(xn::GestureGenerator& self, std::string gesture);

void GestureGenerator_RemoveGesture_wrapped(xn::GestureGenerator& self, std::string gesture);

XnBool GestureGenerator_IsGestureProgressSupported_wrapped(xn::GestureGenerator& self, std::string gesture);

XnBool GestureGenerator_IsGestureAvailable_wrapped(xn::GestureGenerator& self, std::string gesture);

XnCallbackHandle* GestureGenerator_RegisterGestureCallbacks_wrapped(xn::GestureGenerator& self, BP::object& gesture_recognized, BP::object& gesture_progress);

void GestureGenerator_UnregisterGestureCallbacks_wrapped(xn::GestureGenerator& self, XnCallbackHandle* handle);

BP::list GestureGenerator_GetAvailableGestures(xn::GestureGenerator& self);


//Internal callback implementations
void GestureRecognized_callback(xn::GestureGenerator &generator, const XnChar *strGesture, const XnPoint3D *pIDPosition, const XnPoint3D *pEndPosition, void *pCookie);
void GestureProgress_callback(xn::GestureGenerator &generator, const XnChar *strGesture, const XnPoint3D *pPosition, XnFloat fProgress, void *pCookie);

#endif	/* GESTURE_GENERATOR_WRAPPER_H */
