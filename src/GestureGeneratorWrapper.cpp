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
