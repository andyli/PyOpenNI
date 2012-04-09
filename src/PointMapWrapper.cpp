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


#include "PointMapWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include <Python.h>
#include <python2.7/intobject.h>
#include <python2.7/object.h>

namespace pyopenni {

    void PointMap::throwNotOnBounds() {
        PyErr_SetString(PyExc_ValueError, "The index is out of bounds!");
        throw BP::error_already_set();
    }
    
    BP::list PointMap::get_wrapped(BP::object loc) {
        if (loc.is_none()) throwValueError();
        if (PyObject_IsInstance(loc.ptr(), (_object*)(&PyTuple_Type))) {
            //We have a tuple
            if (PyObject_Length(loc.ptr()) != 2)
                throwValueError();
            XnInt32 x = BP::extract<XnInt32>(loc[0]);
            XnInt32 y = BP::extract<XnInt32>(loc[1]);
            
            //Check bounds
            if (x<0 || y<0) throwNotOnBounds();
            if (x >= getWidth() || y >= getHeight()) throwNotOnBounds();
            
            return convertVec3D(data[y*getWidth() + x]);
        }
        if (PyObject_IsInstance(loc.ptr(), (_object*)(&PyInt_Type))) {
            //We have a single number
            XnInt32 idx = BP::extract<XnInt32>(loc);
            
            //Check bounds
            if (idx < 0) throwNotOnBounds();
            if (idx >= getLength()) throwNotOnBounds();
            
            return convertVec3D(data[idx]);
        }
        throwValueError();
    }

}
