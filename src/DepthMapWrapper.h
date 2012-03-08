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


#ifndef DEPTH_MAP_WRAPPER_H
#define	DEPTH_MAP_WRAPPER_H

#include "wrapperTypes.h"
#include "conversionHelpers.h"

namespace pyopenni {

    class DepthMap {
        XnUInt32XYPair size;
        const XnDepthPixel* data;

    private:
        void throwNotOnBounds();
    public:
        DepthMap(const XnDepthPixel* data, XnUInt32XYPair size) {
            this->data = data;
            this->size = size;
        }

        XnDepthPixel get_wrapped(BP::object loc);

        BP::list getSize() {return convertPair(size);}
        XnUInt32 getWidth() {return size.X;}
        XnUInt32 getHeight() {return size.Y;}
        XnUInt32 getLength() {return size.X * size.Y;}
    };

}

#endif	/* DEPTH_MAP_WRAPPER_H */
