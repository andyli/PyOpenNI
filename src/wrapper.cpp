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


// Boost
#include <boost/python.hpp>

// custom
#include "wrapper.h"

#include "wrapperExceptions.h"

#include "OpenNIException.h"
#include "ContextWrapper.h"
#include "ImageGeneratorWrapper.h"
#include "ImageMetaDataWrapper.h"
#include "DepthGeneratorWrapper.h"

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>


////////////////////////////////////////////////////////////////////////////////
// version

std::string version() {

    return OPENNI_WRAPPER_VERSION_STRING + DEBUG_TAG;

} // version


////////////////////////////////////////////////////////////////////////////////
// Boost Python wrapper code

BOOST_PYTHON_MODULE(openni) {

    using namespace boost::python;

    ////////////////////////////////////////////////////////////////////////////
    // global constants

    scope().attr("XN_STATUS_OK") = XN_STATUS_OK;


    ////////////////////////////////////////////////////////////////////////////
    // enumerations

    enum_< XnProductionNodeType > ("ProductionNodeType")
            .value("XN_NODE_TYPE_DEVICE", XN_NODE_TYPE_DEVICE)
            .value("XN_NODE_TYPE_DEPTH", XN_NODE_TYPE_DEPTH)
            .value("XN_NODE_TYPE_IMAGE", XN_NODE_TYPE_IMAGE)
            .value("XN_NODE_TYPE_AUDIO", XN_NODE_TYPE_AUDIO)
            .value("XN_NODE_TYPE_IR", XN_NODE_TYPE_IR)
            .value("XN_NODE_TYPE_USER", XN_NODE_TYPE_USER)
            .value("XN_NODE_TYPE_RECORDER", XN_NODE_TYPE_RECORDER)
            .value("XN_NODE_TYPE_GESTURE", XN_NODE_TYPE_GESTURE)
            .value("XN_NODE_TYPE_HANDS", XN_NODE_TYPE_HANDS)
            .value("XN_NODE_TYPE_CODEC", XN_NODE_TYPE_CODEC)
            .export_values()
            ;


    ////////////////////////////////////////////////////////////////////////////
    // global functions

    def("bindings_version", version);
    //FIXME: Also provide OpenNI version


    
    ////////////////////////////////////////////////////////////////////////////
    // exception class OpenNIException
    
    class_<OpenNIException> generalExceptionClass("OpenNIError",
            boost::python::init<XnStatus>());
    
    //properties
    generalExceptionClass.add_property("message", &OpenNIException::getMessage)
            .add_property("status", &OpenNIException::getStatus)
            .add_property("status_name", &OpenNIException::getStatusName)
            .add_property("status_string", &OpenNIException::getStatusString)
            .def("__str__", &OpenNIException__str__);
    
    register_exception_translator<OpenNIException> (&translateGeneralException);
    
    
    ////////////////////////////////////////////////////////////////////////////
    // class Context

    class_< ContextWrapper > ("Context")

            // methods

            .def("init", &ContextWrapper::Init)
            .def("init_from_xml_file", &ContextWrapper::InitFromXmlFile)
            .def("shutdown", &ContextWrapper::Shutdown)
            .def("wait_any_update_all", &ContextWrapper::WaitAnyUpdateAll)
            .def("wait_and_update_all", &ContextWrapper::WaitAndUpdateAll)
            .def("find_existing_node", &ContextWrapper::FindExistingNode)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ProductionNode

    class_< xn::ProductionNode > ("ProductionNode")
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ImageGenerator

    class_< ImageGeneratorWrapper,
            bases< xn::ProductionNode > >("ImageGenerator")

            // methods
    
            .def("create", &ImageGeneratorWrapper::Create)

            .def("is_valid", &ImageGeneratorWrapper::IsValid)
            .def("get_x_resolution", &ImageGeneratorWrapper::XRes)
            .def("get_y_resolution", &ImageGeneratorWrapper::YRes)
            .def("get_resolution", &ImageGeneratorWrapper::Res)

            .def(
            "get_tuple_image_map",
            &ImageGeneratorWrapper::GetRGB24ImageMapTuple)

            .def(
            "get_raw_image_map",
            &ImageGeneratorWrapper::GetRGB24ImageMapRaw)

            .def(
            "get_synced_image_map",
            &ImageGeneratorWrapper::GetSyncedRGB24ImageMapRaw)

            .def(
            "get_raw_image_map_bgr",
            &ImageGeneratorWrapper::GetBGR24ImageMapRaw)

            .def(
            "get_synced_image_map_bgr",
            &ImageGeneratorWrapper::GetSyncedBGR24ImageMapRaw)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ImageMetaData

    class_< ImageMetaDataWrapper > ("ImageMetaData")
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class DepthGenerator

    class_< DepthGeneratorWrapper,
            bases<xn::ProductionNode> >("DepthGenerator")

            // methods
    
            .def("create", &DepthGeneratorWrapper::Create)

            .def("is_valid", &DepthGeneratorWrapper::IsValid)
            .def("get_x_resolution", &DepthGeneratorWrapper::XRes)
            .def("get_y_resolution", &DepthGeneratorWrapper::YRes)
            .def("get_resolution", &DepthGeneratorWrapper::Res)

            .def("get_tuple_depth_map",
            &DepthGeneratorWrapper::GetGrayscale16DepthMapTuple)

            .def("get_raw_depth_map",
            &DepthGeneratorWrapper::GetGrayscale16DepthMapRaw)

            .def("get_raw_depth_map_8",
            &DepthGeneratorWrapper::GetGrayscale8DepthMapRaw)

            ;


} // End Boost Python module OpenNIPythonWrapper

