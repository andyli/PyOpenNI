/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#include "GestureGeneratorWrapper.h"

#include <XnCppWrapper.h>
#include "conversionHelpers.h"
#include "wrapperExceptions.h"
#include "wrapperTypes.h"
#include <string>

void GestureGenerator_Create_wrapped(xn::GestureGenerator& self, xn::Context& context) {
    check( self.Create(context, NULL, NULL) );
}

void GestureGenerator_AddGesture_wrapped(xn::GestureGenerator& self, std::string gesture) {
    checkValid(self);
    
    check( self.AddGesture(gesture.c_str(), NULL) ); //FIXME: add default params here
}

void GestureGenerator_RemoveGesture_wrapped(xn::GestureGenerator& self, std::string gesture) {
    checkValid(self);
    
    check( self.RemoveGesture(gesture.c_str()) );
}

XnBool GestureGenerator_IsGestureProgressSupported_wrapped(xn::GestureGenerator& self, std::string gesture) {
    checkValid(self);
    
    return self.IsGestureProgressSupported(gesture.c_str());
}

XnBool GestureGenerator_IsGestureAvailable_wrapped(xn::GestureGenerator& self, std::string gesture) {
    checkValid(self);
    
    return self.IsGestureAvailable(gesture.c_str());
}

void GestureGenerator_RegisterGestureCallbacks_wrapped(xn::GestureGenerator& self, BP::object& gesture_recognized, BP::object& gesture_progress) {
    checkValid(self);
    
    XnCallbackHandle handle;//FIXME: return callback handle; also fix cookie
    BP::object* cookie = new BP::object [2];
    
    cookie[0] = gesture_recognized;
    cookie[1] = gesture_progress;
    
    check( self.RegisterGestureCallbacks(&GestureRecognized_callback, &GestureProgress_callback, cookie, handle) );
    //return (XnUInt64)handle;
}

void GestureRecognized_callback(xn::GestureGenerator &generator, const XnChar *strGesture, const XnPoint3D *pIDPosition, const XnPoint3D *pEndPosition, void *pCookie) {
    std::string gesture (strGesture);
    BP::object& func = ((BP::object*)pCookie)[0];
    
    //Call the function
    func(generator, gesture, convertVec3D(*pIDPosition), convertVec3D(*pEndPosition));
}

void GestureProgress_callback(xn::GestureGenerator &generator, const XnChar *strGesture, const XnPoint3D *pPosition, XnFloat fProgress, void *pCookie) {
    std::string gesture (strGesture);
    BP::object& func = ((BP::object*)pCookie)[1];
    
    //Call the function
    func(generator, gesture, convertVec3D(*pPosition), fProgress);
}
