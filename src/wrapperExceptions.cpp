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


#include "wrapperExceptions.h"

#include <assert.h>
#include <Python.h>
#include <boost/python.hpp>

#include <openni/XnStatus.h>

#include "OpenNIException.h"

void translateGeneralException(OpenNIException const &e) {
    assert(exceptionType != NULL);
    boost::python::object pythonExceptionInstance(e);
    PyErr_SetObject(exceptionType, pythonExceptionInstance.ptr());
}

void check(XnStatus status) {
    if (status != XN_STATUS_OK) {
        throw OpenNIException(status);
    }
}
