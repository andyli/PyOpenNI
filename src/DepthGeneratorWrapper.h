/*****************************************************************************
*                                                                            *
*  OpenNI Python Wrapper (ONIPY)                                             *
*  Copyright (C) 2011 Gabriele Nataneli (gamix).                             *
*                                                                            *
*                                                                            *
*  This library is free software: you can redistribute it and/or modify      *
*  it under the terms of the GNU Lesser General Public License as published  *
*  by the Free Software Foundation, either version 3 of the License, or      *
*  (at your option) any later version.                                       *
*                                                                            *
*  OpenNI Python Wrapper is distributed in the hope that it will be useful,  *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              *
*  GNU Lesser General Public License for more details.                       *
*                                                                            *
*  You should have received a copy of the GNU Lesser General Public License  *
*  along with OpenNI Python Wrapper. If not,                                 *
* see <http://www.gnu.org/licenses/>.                                        *
*                                                                            *
*****************************************************************************/


#ifndef DEPTH_GENERATOR_WRAPPER_H
#define DEPTH_GENERATOR_WRAPPER_H

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>

// custom
#include "wrapperTypes.h"

XnUInt32 DepthGenerator_XRes_wrapped(xn::DepthGenerator const & self);

XnUInt32 DepthGenerator_YRes_wrapped(xn::DepthGenerator const & self);

BP::tuple DepthGenerator_Res_wrapped(xn::DepthGenerator const & self);

BP::tuple DepthGenerator_GetGrayscale16DepthMapTuple_wrapped(xn::DepthGenerator const & self);

std::string DepthGenerator_GetGrayscale16DepthMapRaw_wrapped(xn::DepthGenerator const & self);

std::string DepthGenerator_GetGrayscale8DepthMapRaw_wrapped(xn::DepthGenerator const & self);

void DepthGenerator_Create_wrapped(xn::DepthGenerator& self, xn::Context& ctx);

#endif    // DEPTH_GENERATOR_WRAPPER_H
