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


#include "GeneratorWrapper.h"

#include <string>
#include <boost/python/detail/cv_category.hpp>
#include "wrapperExceptions.h"

#include <XnCppWrapper.h>

void Generator_StartGenerating_wrapped(xn::Generator& self) {
    checkValid(self);
    
    check( self.StartGenerating() );
}

void Generator_StopGenerating_wrapped(xn::Generator& self) {
    checkValid(self);
    
    check( self.StopGenerating() );
}

void Generator_WaitAndUpdateData_wrapped(xn::Generator& self) {
    checkValid(self);
    
    check( self.WaitAndUpdateData() );
}

void Generator_SetGenerating(xn::Generator& self, XnBool value) {
    checkValid(self);
    
    if (value != self.IsGenerating()) { //OPTIMIZATION
        if (value) {
            check( self.StartGenerating() );
        } else {
            check( self.StopGenerating() );
        }
    }
}

XnBool Generator_IsGenerating_wrapped(xn::Generator& self) {
    checkValid(self);
    
    return self.IsGenerating();
}

XnBool Generator_IsDataNew_wrapped(xn::Generator& self) {
    checkValid(self);
    
    return self.IsDataNew();
}

XnUInt64 Generator_GetTimestamp_wrapped(xn::Generator& self) {
    checkValid(self);
    
    return self.GetTimestamp();
}
XnUInt32 Generator_GetFrameID_wrapped(xn::Generator& self) {
    checkValid(self);
    
    return self.GetFrameID();
}
