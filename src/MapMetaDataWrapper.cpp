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


#include "MapMetaDataWrapper.h"

#include <XnCppWrapper.h>
#include "conversionHelpers.h"

BP::list MapMetaData_Res(xn::MapMetaData& self) {
    return convertPair(self.XRes(), self.YRes());
}
BP::list MapMetaData_FullRes(xn::MapMetaData& self) {
    return convertPair(self.FullXRes(), self.FullYRes());
}
BP::list MapMetaData_Offset(xn::MapMetaData& self) {
    return convertPair(self.XOffset(), self.YOffset());
}

XnUInt32 MapMetaData_FPS_wrapped(xn::MapMetaData& self) {
    return self.FPS();
}

XnUInt32 MapMetaData_BytesPerPixel_wrapped(xn::MapMetaData& self) {
    return self.BytesPerPixel();
}

XnPixelFormat MapMetaData_PixelFormat_wrapped(xn::MapMetaData& self) {
    return self.PixelFormat();
}
