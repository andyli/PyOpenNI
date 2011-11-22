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
#include "wrapperDocstrings.h"

#include "OpenNIException.h"
#include "ContextWrapper.h"
#include "ProductionNodeWrapper.h"
#include "GeneratorWrapper.h"
#include "MapGeneratorWrapper.h"
#include "ImageGeneratorWrapper.h"
#include "DepthGeneratorWrapper.h"
#include "GestureGeneratorWrapper.h"
#include "VersionWrapper.h"
#include "OutputMetaDataWrapper.h"
#include "MapMetaDataWrapper.h"

// OpenNI
#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <boost/python/detail/cv_category.hpp>


////////////////////////////////////////////////////////////////////////////////
// version

std::string version() {

    return OPENNI_WRAPPER_VERSION_STRING + DEBUG_TAG;

} // version


////////////////////////////////////////////////////////////////////////////////
// Boost Python wrapper code

BOOST_PYTHON_MODULE(openni) {

    using namespace boost::python;
    
    //Customize what will appear on the docstrings:
    docstring_options local_docstring_options(true, true, false);
      //Custom docstring -> ON
      //Python signature -> ON
      //C++ signature    -> OFF

    ////////////////////////////////////////////////////////////////////////////
    // global constants

    scope().attr("STATUS_OK") = XN_STATUS_OK;


    ////////////////////////////////////////////////////////////////////////////
    // enumerations

    enum_< XnProductionNodeType > ("ProductionNodeType")
            .value("NODE_TYPE_DEVICE", XN_NODE_TYPE_DEVICE)
            .value("NODE_TYPE_DEPTH", XN_NODE_TYPE_DEPTH)
            .value("NODE_TYPE_IMAGE", XN_NODE_TYPE_IMAGE)
            .value("NODE_TYPE_AUDIO", XN_NODE_TYPE_AUDIO)
            .value("NODE_TYPE_IR", XN_NODE_TYPE_IR)
            .value("NODE_TYPE_USER", XN_NODE_TYPE_USER)
            .value("NODE_TYPE_RECORDER", XN_NODE_TYPE_RECORDER)
            .value("NODE_TYPE_GESTURE", XN_NODE_TYPE_GESTURE)
            .value("NODE_TYPE_HANDS", XN_NODE_TYPE_HANDS)
            .value("NODE_TYPE_CODEC", XN_NODE_TYPE_CODEC)
            .value("NODE_TYPE_PLAYER", XN_NODE_TYPE_PLAYER)
            .value("NODE_TYPE_SCENE", XN_NODE_TYPE_SCENE)
    
            .value("NODE_TYPE_INVALID", XN_NODE_TYPE_INVALID)
    
            //Abstract types
            .value("NODE_TYPE_GENERATOR", XN_NODE_TYPE_GENERATOR)
            .value("NODE_TYPE_MAP_GENERATOR", XN_NODE_TYPE_MAP_GENERATOR)
            .value("NODE_TYPE_FIRST_EXTENSION", XN_NODE_TYPE_FIRST_EXTENSION)
            .value("NODE_TYPE_PRODUCTION_NODE", XN_NODE_TYPE_PRODUCTION_NODE)
            .value("NODE_TYPE_SCRIPT", XN_NODE_TYPE_SCRIPT)
            .export_values()
            ;
    enum_< XnPixelFormat > ("PixelFormat")
            .value("PIXEL_FORMAT_GRAYSCALE_16_BIT", XN_PIXEL_FORMAT_GRAYSCALE_16_BIT)
            .value("PIXEL_FORMAT_GRAYSCALE_8_BIT", XN_PIXEL_FORMAT_GRAYSCALE_8_BIT)
            .value("PIXEL_FORMAT_MJPEG", XN_PIXEL_FORMAT_MJPEG)
            .value("PIXEL_FORMAT_RGB24", XN_PIXEL_FORMAT_RGB24)
            .value("PIXEL_FORMAT_YUV422", XN_PIXEL_FORMAT_YUV422)
            .export_values()
            ;


    ////////////////////////////////////////////////////////////////////////////
    // global functions

    def("bindings_version", version);
    def("version", &GetVersion_wrapped, return_value_policy<manage_new_object>());



    ////////////////////////////////////////////////////////////////////////////
    // exception class OpenNIException

    class_<OpenNIException> generalExceptionClass("OpenNIError",
            boost::python::init<XnStatus > ());

    //properties
    generalExceptionClass.add_property("message", &OpenNIException::getMessage)
            .add_property("status", &OpenNIException::getStatus)
            .add_property("status_name", &OpenNIException::getStatusName)
            .add_property("status_string", &OpenNIException::getStatusString)
            .def("__str__", &OpenNIException__str__);

    register_exception_translator<OpenNIException > (&translateGeneralException);


    ////////////////////////////////////////////////////////////////////////////
    // class Version
    class_< XnVersion > ("Version")
            .add_property("major", &XnVersion::nMajor, &XnVersion::nMajor)
            .add_property("minor", &XnVersion::nMinor, &XnVersion::nMinor)
            .add_property("maintenance", &XnVersion::nMaintenance, &XnVersion::nMaintenance)
            .add_property("build", &XnVersion::nBuild, &XnVersion::nBuild)
    
            .def("__cmp__", &compareVersions)
            .def("__str__", &Version__str__);
    
    
    ////////////////////////////////////////////////////////////////////////////
    // class OutputMetaData

    class_< xn::OutputMetaData > ("OutputMetaData", no_init)
            .add_property("timestamp", &OutputMetaData_Timestamp_wrapped)
            .add_property("frame_id", &OutputMetaData_FrameID_wrapped)
            .add_property("data_new", &OutputMetaData_IsDataNew_wrapped)
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class MapMetaData

    class_< xn::MapMetaData,
            bases<xn::OutputMetaData>, boost::noncopyable > ("MapMetaData", no_init)
            .add_property("bytes_per_pixel", &xn::MapMetaData::BytesPerPixel)
            .add_property("pixel_format", &xn::MapMetaData::PixelFormat)
            .add_property("fps", &MapMetaData_FPS_wrapped)
            
            .add_property("res", make_function(&MapMetaData_Res))
            .add_property("offset", make_function(&MapMetaData_Offset))
            .add_property("full_res", make_function(&MapMetaData_FullRes))
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ImageMetaData

    class_< xn::ImageMetaData,
            bases<xn::MapMetaData>, boost::noncopyable > ("ImageMetaData", no_init)
            ;//TODO: make files for imagemetadata and depthmetadata


    ////////////////////////////////////////////////////////////////////////////
    // class DepthMetaData

    class_< xn::DepthMetaData,
            bases<xn::MapMetaData>, boost::noncopyable> ("DepthMetaData", no_init)
            ;
    



    ////////////////////////////////////////////////////////////////////////////
    // class Context

    class_< xn::Context > ("Context", Context_DOC)

            // methods

            .def("init", &Context_Init_wrapped, Context_Init_DOC)
            .def("init_from_xml_file", &Context_InitFromXmlFile_wrapped)
            .def("shutdown", &Context_Shutdown_wrapped, Context_Shutdown_DOC)
            .def("wait_any_update_all", &Context_WaitAnyUpdateAll_wrapped, Context_WaitAnyUpdateAll_DOC)
            .def("wait_and_update_all", &Context_WaitAndUpdateAll_wrapped, Context_WaitAndUpdateAll_DOC)
            .def("start_generating_all", &Context_StartGeneratingAll_wrapped, Context_StartGeneratingAll_DOC)
            .def("stop_generating_all", &Context_StopGeneratingAll_wrapped, Context_StopGeneratingAll_DOC)
            .def("find_existing_node", &Context_FindExistingNode_wrapped, return_value_policy<manage_new_object>())

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ProductionNode

    class_< xn::ProductionNode > ("ProductionNode")
            .add_property("valid", &xn::ProductionNode::IsValid)
            .def("is_capability_supported", &ProductionNode_IsCapabilitySupported_wrapped)
            ;//TODO: add optional params and capability names


    ////////////////////////////////////////////////////////////////////////////
    // class Generator

    class_< xn::Generator,
            bases<xn::ProductionNode> > ("Generator", no_init)
    
            //methods
            .def("start_generating", &Generator_StartGenerating_wrapped)
            .def("stop_generating", &Generator_StopGenerating_wrapped)
            .def("wait_and_update_data", &Generator_WaitAndUpdateData_wrapped)
    
            //properties
            .add_property("data_new", &Generator_IsDataNew_wrapped)
            .add_property("generating", &Generator_IsGenerating_wrapped, &Generator_SetGenerating)
    
            ;

    
    ////////////////////////////////////////////////////////////////////////////
    // class MapGenerator

    class_< xn::MapGenerator,
            bases<xn::Generator> > ("MapGenerator", no_init)
    
            //.def("get_x_resolution", &MapGeneratorWrapper::XRes)
            //.def("get_y_resolution", &MapGeneratorWrapper::YRes)
            //.def("get_resolution", &MapGeneratorWrapper::Res)
    
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ImageGenerator

    class_< xn::ImageGenerator,
            bases< xn::MapGenerator > >("ImageGenerator")

            // methods

            .def("create", &ImageGenerator_Create_wrapped)
    
            .add_property("metadata", make_function(&ImageGenerator_GetMetaData_wrapped, return_value_policy<manage_new_object>()))

            .def(
            "get_tuple_image_map",
            &ImageGenerator_GetRGB24ImageMapTuple_wrapped)

            .def(
            "get_raw_image_map",
            &ImageGenerator_GetRGB24ImageMapRaw_wrapped)

            .def(
            "get_synced_image_map",
            &ImageGenerator_GetSyncedRGB24ImageMapRaw_wrapped)

            .def(
            "get_raw_image_map_bgr",
            &ImageGenerator_GetBGR24ImageMapRaw_wrapped)

            .def(
            "get_synced_image_map_bgr",
            &ImageGenerator_GetSyncedBGR24ImageMapRaw_wrapped)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class DepthGenerator

    class_< xn::DepthGenerator,
            bases<xn::MapGenerator> >("DepthGenerator")

            // methods

            .def("create", &DepthGenerator_Create_wrapped)

            .def("get_tuple_depth_map",
            &DepthGenerator_GetGrayscale16DepthMapTuple_wrapped)

            .def("get_raw_depth_map",
            &DepthGenerator_GetGrayscale16DepthMapRaw_wrapped)

            .def("get_raw_depth_map_8",
            &DepthGenerator_GetGrayscale8DepthMapRaw_wrapped)

            .add_property("metadata", make_function(&DepthGenerator_GetMetaData_wrapped, return_value_policy<manage_new_object>()))
    
            ;
    
    
    ////////////////////////////////////////////////////////////////////////////
    // class GestureGenerator

    class_< xn::GestureGenerator,
            bases<xn::Generator> >("GestureGenerator")

            // methods

            .def("create", &GestureGenerator_Create_wrapped)
            .def("add_gesture", &GestureGenerator_AddGesture_wrapped)
            .def("remove_gesture", &GestureGenerator_RemoveGesture_wrapped)
            .def("is_gesture_available", &GestureGenerator_IsGestureAvailable_wrapped)
            .def("is_gesture_progress_supported", &GestureGenerator_IsGestureProgressSupported_wrapped)
            .def("register_gesture_cb", &GestureGenerator_RegisterGestureCallbacks_wrapped, return_value_policy<return_opaque_pointer>())
            .def("unregister_gesture_cb", &GestureGenerator_UnregisterGestureCallbacks_wrapped)

            ;


} // End Boost Python module OpenNIPythonWrapper
