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


#ifndef CONVERSION_HELPERS_H
#define CONVERSION_HELPERS_H

#include "wrapperTypes.h"

BP::list convertPair(XnUInt32 x, XnUInt32 y);
BP::list convertPair(XnUInt32XYPair const & pair);

BP::list convertVec3D(XnVector3D const & vector);

void convert(
        BP::tuple& targetTuple,
        XnRGB24Pixel const* sourceMap,
        XnUInt32 sourceXResolution,
        XnUInt32 sourceYResolution);

void convert(
        BP::tuple& targetTuple,
        XnDepthPixel const* sourceMap,
        XnUInt32 sourceXResolution,
        XnUInt32 sourceYResolution);

void convertToGrayscale8Raw(
        std::string& targetMapRaw,
        XnDepthPixel const* sourceMap,
        XnUInt32 sourceXResolution,
        XnUInt32 sourceYResolution);

void convertToBGR24Raw(
        std::string& targetMapRaw,
        XnRGB24Pixel const* sourceMap,
        XnUInt32 sourceXResolution,
        XnUInt32 sourceYResolution);

#endif    // CONVERSION_HELPERS_H