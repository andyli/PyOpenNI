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


#include "OpenNIDepthGeneratorWrapper.h"
#include "conversionHelpers.h"

#include "util/PythonOutputStream.h"

DepthGeneratorWrapper::DepthGeneratorWrapper() {

#ifdef _DEBUG
    PyCout << "Creating DepthGenerator" << std::endl;
#endif

}

XnUInt32 DepthGeneratorWrapper::XRes() const {

    xn::DepthMetaData proxyDepthMetaData;
    xn::DepthGenerator::GetMetaData(proxyDepthMetaData);

    return proxyDepthMetaData.XRes();

}

XnUInt32 DepthGeneratorWrapper::YRes() const {

    xn::DepthMetaData proxyDepthMetaData;
    xn::DepthGenerator::GetMetaData(proxyDepthMetaData);

    return proxyDepthMetaData.YRes();

}

BP::tuple DepthGeneratorWrapper::Res() const {

    return BP::make_tuple(XRes(), YRes());

}

BP::tuple DepthGeneratorWrapper::GetGrayscale16DepthMapTuple() const {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnDepthPixel const* depthMap = xn::DepthGenerator::GetDepthMap();

    BP::tuple mapTuple;
    convert(mapTuple, depthMap, XRes(), YRes());

    return mapTuple;

}

std::string DepthGeneratorWrapper::GetGrayscale16DepthMapRaw() const {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnDepthPixel const* depthMap = xn::DepthGenerator::GetDepthMap();

    std::string rawData(
            (const char*) depthMap,
            XRes() * YRes() * sizeof ( XnDepthPixel));

    return rawData;

}

std::string DepthGeneratorWrapper::GetGrayscale8DepthMapRaw() const {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnDepthPixel const* depthMap = xn::DepthGenerator::GetDepthMap();

    std::string rawDataGrayscale8;
    convertToGrayscale8Raw(rawDataGrayscale8, depthMap, XRes(), YRes());

    return rawDataGrayscale8;

}

XnStatus DepthGeneratorWrapper::Create(const ContextWrapper& ctx) {
    return xn::DepthGenerator::Create((xn::Context&)ctx, NULL, NULL);
}
