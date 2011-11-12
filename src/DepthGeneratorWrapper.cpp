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


#include "DepthGeneratorWrapper.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

#include "util/PythonOutputStream.h"

/** XnUInt32 DepthGenerator_XRes_wrapped(xn::DepthGenerator const & self) {//FIXME: this should be removed! use metadata instead

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);

    return metadata.XRes();

}

XnUInt32 DepthGenerator_YRes_wrapped(xn::DepthGenerator const & self) {

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);

    return metadata.YRes();

}

BP::tuple DepthGenerator_Res_wrapped(xn::DepthGenerator const & self) {

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    return BP::make_tuple(metadata.XRes(), metadata.YRes());

} **/

BP::tuple DepthGenerator_GetGrayscale16DepthMapTuple_wrapped(xn::DepthGenerator const & self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    XnDepthPixel const* depthMap = self.GetDepthMap();

    BP::tuple mapTuple;
    convert(mapTuple, depthMap, metadata.XRes(), metadata.YRes());

    return mapTuple;

}

std::string DepthGenerator_GetGrayscale16DepthMapRaw_wrapped(xn::DepthGenerator const & self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    XnDepthPixel const* depthMap = self.GetDepthMap();

    std::string rawData(
            (const char*) depthMap,
            metadata.XRes() * metadata.YRes() * sizeof ( XnDepthPixel));

    return rawData;

}

std::string DepthGenerator_GetGrayscale8DepthMapRaw_wrapped(xn::DepthGenerator const & self) {

    // PRECONDITION: the generator is valid
    assert(self.IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    XnDepthPixel const* depthMap = self.GetDepthMap();

    std::string rawDataGrayscale8;
    convertToGrayscale8Raw(rawDataGrayscale8, depthMap, metadata.XRes(), metadata.YRes());

    return rawDataGrayscale8;

}

void DepthGenerator_Create_wrapped(xn::DepthGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}
