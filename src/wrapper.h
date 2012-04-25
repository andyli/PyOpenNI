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


#ifndef WRAPPER_H
#define WRAPPER_H

#include "wrapperTypes.h"
#include "boost/python/numeric.hpp"
#include <numpy/noprefix.h>

////////////////////////////////////////////////////////////////////////////////
// Constants

const std::string OPENNI_WRAPPER_VERSION_STRING = "2.1.0 alpha"; //FIXME: CMake should to configure version, debug and modulename

#ifdef _DEBUG
const std::string DEBUG_TAG = " [debug]";
#else
const std::string DEBUG_TAG = "";
#endif


////////////////////////////////////////////////////////////////////////////////
// exposed functions

// return a string that specifies the version of this module
std::string version();
BP::list py_xnResolutionGetRes(XnResolution res);


#endif    // WRAPPER_H
