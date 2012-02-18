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


#include "MapGeneratorWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

BP::list MapGenerator_GetRes(xn::MapGenerator& self) {
    XnMapOutputMode outmode;
    check( self.GetMapOutputMode(outmode) );

    return convertPair(outmode.nXRes, outmode.nYRes);
}
void MapGenerator_SetRes(xn::MapGenerator& self, BP::list res) {
    XnMapOutputMode outmode;
    check( self.GetMapOutputMode(outmode) );
    XnUInt32XYPair resc = convertToPair(res);

    outmode.nXRes = resc.X;
    outmode.nYRes = resc.Y;
    check( self.SetMapOutputMode(outmode) );
}
XnUInt32 MapGenerator_GetFPS(xn::MapGenerator& self) {
    XnMapOutputMode outmode;
    check( self.GetMapOutputMode(outmode) );

    return outmode.nFPS;
}
void MapGenerator_SetFPS(xn::MapGenerator& self, XnUInt32 fps) {
    XnMapOutputMode outmode;
    check( self.GetMapOutputMode(outmode) );

    outmode.nFPS = fps;
    check( self.SetMapOutputMode(outmode) );
}
void MapGenerator_SetResolutionPreset(xn::MapGenerator& self, XnResolution res) {
    XnMapOutputMode outmode;
    check( self.GetMapOutputMode(outmode) );

    outmode.nXRes = xnResolutionGetXRes(res);
    outmode.nYRes = xnResolutionGetYRes(res);
    check( self.SetMapOutputMode(outmode) );
}
