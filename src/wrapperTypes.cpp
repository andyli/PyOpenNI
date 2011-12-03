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

#include "wrapperTypes.h"

#include <XnCppWrapper.h>
#include <XnUtils.h>
#include <XnPrdNode.h>
#include <XnPrdNodeInfo.h>

#include "wrapperExceptions.h"

#include <iostream>

// One of the core methods of PyOpenNI:
// It tries to find the exposed class that best matches the given node.
BP::object wrapNode(XnNodeHandle node) {
    if (node == NULL) {
        return BP::object();
    }
    
    XnNodeInfo* info = xnGetNodeInfo(node);
    const XnProductionNodeDescription* desc = xnNodeInfoGetDescription(info);
    XnProductionNodeType original = desc->Type;
    
    std::cout << "Type is " << original << std::endl;
    
    if (isInstanceOf(original, XN_NODE_TYPE_PRODUCTION_NODE)) {
        if (isInstanceOf(original, XN_NODE_TYPE_GENERATOR)) {
            if (isInstanceOf(original, XN_NODE_TYPE_MAP_GENERATOR)) {
                if (isInstanceOf(original, XN_NODE_TYPE_DEPTH)) {
                    return BP::object(xn::DepthGenerator(node));
                }
                if (isInstanceOf(original, XN_NODE_TYPE_IMAGE)) {
                    return BP::object(xn::ImageGenerator(node));
                }
                return BP::object(xn::MapGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_GESTURE)) {
                return BP::object(xn::GestureGenerator(node));
            }
            if (isInstanceOf(original, XN_NODE_TYPE_USER)) {
                return BP::object(xn::UserGenerator(node));
            }
            return BP::object(xn::Generator(node));
        }
        return BP::object(xn::ProductionNode(node));
    }
    
    PyErr_SetString(PyExc_TypeError, "Couldn't find appropiate type to wrap node.");
    throw BP::error_already_set();
}

XnBool isInstanceOf(XnProductionNodeType deriv, XnProductionNodeType base) {
    if (deriv == base) {
        return true;
    }
    return xnIsTypeDerivedFrom(deriv, base);
}
