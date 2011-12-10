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


#ifndef DEPTH_GENERATOR_WRAPPER_H
#define DEPTH_GENERATOR_WRAPPER_H

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>

// custom
#include "wrapperTypes.h"

xn::DepthMetaData* DepthGenerator_GetMetaData_wrapped(xn::DepthGenerator const & self);

BP::tuple DepthGenerator_GetGrayscale16DepthMapTuple_wrapped(xn::DepthGenerator const & self);

std::string DepthGenerator_GetGrayscale16DepthMapRaw_wrapped(xn::DepthGenerator const & self);

std::string DepthGenerator_GetGrayscale8DepthMapRaw_wrapped(xn::DepthGenerator const & self);

void DepthGenerator_Create_wrapped(xn::DepthGenerator& self, xn::Context& ctx);

//WARNING: these methods convert a SINGLE point
BP::list DepthGenerator_ToRealWorld(xn::DepthGenerator& self, BP::list point);
BP::list DepthGenerator_ToProjective(xn::DepthGenerator& self, BP::list point);

#endif    // DEPTH_GENERATOR_WRAPPER_H
