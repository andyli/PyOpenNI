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


#ifndef OPENNI_DEPTH_GENERATOR_WRAPPER_H
#define OPENNI_DEPTH_GENERATOR_WRAPPER_H

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>

// custom
#include "OpenNIWrapperTypes.h"

class OpenNIDepthGeneratorWrapper : public xn::DepthGenerator
{

public:
    OpenNIDepthGeneratorWrapper();

    // return the x resolution of the map
    XnUInt32 XRes() const;    

    // return the y resolution of the map
    XnUInt32 YRes() const;    

    // return a (x,y) with the resolution of the map
    BP::tuple Res() const;

    BP::tuple GetGrayscale16DepthMapTuple() const;
    std::string GetGrayscale16DepthMapRaw() const;

    // NOTE: this method converts the data supplied by OpenNI to a format that
    // is more friendly for visualization (e.g. PIL in L mode). It is a slow 
    // operation, so use it only for debugging
    std::string GetGrayscale8DepthMapRaw() const;

};

#endif    // OPENNI_DEPTH_GENERATOR_WRAPPER_H