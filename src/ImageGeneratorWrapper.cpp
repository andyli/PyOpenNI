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


#include "ImageGeneratorWrapper.h"
#include "wrapperExceptions.h"
#include "conversionHelpers.h"

#include "util/PythonOutputStream.h"

ImageGeneratorWrapper::ImageGeneratorWrapper() {

#ifdef _DEBUG
    PyCout << "Creating ImageGenerator" << std::endl;
#endif

}

void ImageGeneratorWrapper::GetMetaData(
        ImageMetaDataWrapper& metaData) const {

    // FIXME: it does not seem to be a good idea to expose the meta data
    // directly to Python
    assert(false);

}

XnUInt32 ImageGeneratorWrapper::XRes() const {

    xn::ImageMetaData proxyImageMetaData;
    xn::ImageGenerator::GetMetaData(proxyImageMetaData);

    return proxyImageMetaData.XRes();

}

XnUInt32 ImageGeneratorWrapper::YRes() const {

    xn::ImageMetaData proxyImageMetaData;
    xn::ImageGenerator::GetMetaData(proxyImageMetaData);

    return proxyImageMetaData.YRes();

}

BP::tuple ImageGeneratorWrapper::Res() const {

    return BP::make_tuple(XRes(), YRes());

}

BP::tuple ImageGeneratorWrapper::GetRGB24ImageMapTuple() const {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnRGB24Pixel const* imageMap = xn::ImageGenerator::GetRGB24ImageMap();

    BP::tuple mapTuple;
    convert(mapTuple, imageMap, XRes(), YRes());

    return mapTuple;

}

std::string ImageGeneratorWrapper::GetRGB24ImageMapRaw() {

    _GetRGB24ImageMapRaw();

    return _rawData;

}

std::string ImageGeneratorWrapper::GetSyncedRGB24ImageMapRaw() {

    WaitAndUpdateData();

    _GetRGB24ImageMapRaw();

    return _rawData;

}

std::string ImageGeneratorWrapper::GetBGR24ImageMapRaw() {

    _GetBGR24ImageMapRaw();

    return _rawData;

}

std::string ImageGeneratorWrapper::GetSyncedBGR24ImageMapRaw() {

    WaitAndUpdateData();

    _GetBGR24ImageMapRaw();

    return _rawData;

}

void ImageGeneratorWrapper::_GetRGB24ImageMapRaw() {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnRGB24Pixel const* imageMap = xn::ImageGenerator::GetRGB24ImageMap();
    _rawData.assign((const char*) imageMap, GetDataSize());

}

void ImageGeneratorWrapper::_GetBGR24ImageMapRaw() {

    // PRECONDITION: the generator is valid
    assert(IsValid());

#ifdef _DEBUG
    if (IsDataNew() == false)
        PyCout << "WARNING: data is out of sync!" << std::endl;
#endif

    XnRGB24Pixel const* imageMap = xn::ImageGenerator::GetRGB24ImageMap();

    convertToBGR24Raw(_rawData, imageMap, XRes(), YRes());

}

void ImageGeneratorWrapper::_Create(const ContextWrapper& ctx) {
    check( xn::ImageGenerator::Create((xn::Context&)ctx, NULL, NULL) );
}
