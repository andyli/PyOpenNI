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


#ifndef OPENNI_IMAGE_GENERATOR_WRAPPER_H
#define OPENNI_IMAGE_GENERATOR_WRAPPER_H

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>

// custom
#include "OpenNIWrapperTypes.h"

class OpenNIImageGeneratorWrapper : public xn::ImageGenerator {
public:
    OpenNIImageGeneratorWrapper();

    // WARNING: this function does not work!
    void GetMetaData(OpenNIImageMetaDataWrapper& metaData) const;

    // NOTE: the meta data is exposed directly through the generator
    XnUInt32 XRes() const;
    XnUInt32 YRes() const;
    BP::tuple Res() const;

    // use this method if you want to readily manipulate image data with NumPy
    BP::tuple GetRGB24ImageMapTuple() const;


    // these methods are the preffered and fasted way to retrieve image data
    // NOTE: these methods are not const because they modify shared data

    // get image data in the internal RGB24 data format
    std::string GetRGB24ImageMapRaw();

    // same as before, but it updates the node with the latest image data first 
    std::string GetSyncedRGB24ImageMapRaw();

    // these methods are slower than the RGB version, but useful when using
    // this wrapper with OpenCV

    std::string GetBGR24ImageMapRaw();
    std::string GetSyncedBGR24ImageMapRaw();

private:
    std::string _rawData;

    void _GetRGB24ImageMapRaw();
    void _GetBGR24ImageMapRaw();

};

#endif    // OPENNI_IMAGE_GENERATOR_WRAPPER_H