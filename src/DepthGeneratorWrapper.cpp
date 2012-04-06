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


#include "DepthGeneratorWrapper.h"

#include "wrapperTypes.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"
#include "util/PythonOutputStream.h"
#include "DepthMapWrapper.h"

using namespace pyopenni;

xn::DepthMetaData* DepthGenerator_GetMetaData_wrapped(xn::DepthGenerator const & self) {
    checkValid(self);

    xn::DepthMetaData * ret = new xn::DepthMetaData;
    self.GetMetaData(*ret);
    return ret;
}


/**DEPRECATED, slow map functions**/
BP::tuple DepthGenerator_GetGrayscale16DepthMapTuple_wrapped(xn::DepthGenerator const & self) {
    checkValid(self);

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
    checkValid(self);

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
    checkValid(self);

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

/**The new, efficient way of getting the map**/
DepthMap DepthGenerator_GetWrappedMap(xn::DepthGenerator& self) {
    checkValid(self);
    
    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    XnUInt32XYPair size;
    size.X = metadata.XRes();
    size.Y = metadata.YRes();
    
    return DepthMap(self.GetDepthMap(), size);
}


PointMap DepthGenerator_GetPointMap(xn::DepthGenerator& self) {
    checkValid(self);
    
    xn::DepthMetaData metadata;
    self.GetMetaData(metadata);
    
    XnUInt32XYPair size;
    size.X = metadata.XRes();
    size.Y = metadata.YRes();
    
    const XnDepthPixel* depthmap = self.GetDepthMap();
    XnVector3D* point3ds = new XnVector3D[size.X * size.Y];
    int _i = 0;
    for (int y = 0 ; y < size.Y ; ++y){
        for (int x = 0 ; x < size.X ; ++x) {
            XnVector3D* p = &point3ds[_i];
            p->X = x;
            p->Y = y;
            p->Z = depthmap[_i];
            
            ++_i;
        }
    }
    
    self.ConvertProjectiveToRealWorld(size.X * size.Y, point3ds, point3ds);
    
    return PointMap(point3ds, size);
}

void DepthGenerator_Create_wrapped(xn::DepthGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}

//WARNING: these methods convert a SINGLE point
BP::list DepthGenerator_ToRealWorld(xn::DepthGenerator& self, BP::list point) {
    XnPoint3D projective [1];
    projective[0] = convertToVec3D(point);
    
    XnPoint3D realWorld [1];
    
    check( self.ConvertProjectiveToRealWorld(1, projective, realWorld) );
    
    return convertVec3D(realWorld[0]);
}
BP::list DepthGenerator_ToProjective(xn::DepthGenerator& self, BP::list point) {
    XnPoint3D realWorld [1];
    realWorld[0] = convertToVec3D(point);
    
    XnPoint3D projective [1];
    
    check( self.ConvertProjectiveToRealWorld(1, projective, realWorld) );
    
    return convertVec3D(projective[0]);
}
