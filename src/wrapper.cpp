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
#include "OpenNIContextWrapper.h"
#include "OpenNIImageGeneratorWrapper.h"
#include "OpenNIImageMetaDataWrapper.h"
#include "OpenNIDepthGeneratorWrapper.h"

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

BOOST_PYTHON_MODULE(PyOpenNI) {

    using namespace boost::python;

    ////////////////////////////////////////////////////////////////////////////
    // global constants

    scope().attr("XN_STATUS_OK") = XN_STATUS_OK;


    ////////////////////////////////////////////////////////////////////////////
    // enumerations

    enum_< XnProductionNodeType > ("XnProductionNodeType")
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
    // class OpenNIContext

    class_< ContextWrapper > ("Context")

            // methods

            .def("InitFromXmlFile", &ContextWrapper::InitFromXmlFile)
            .def("Shutdown", &ContextWrapper::Shutdown)
            .def("WaitAnyUpdateAll", &ContextWrapper::WaitAnyUpdateAll)
            .def("WaitAndUpdateAll", &ContextWrapper::WaitAndUpdateAll)
            .def("FindExistingNode", &ContextWrapper::FindExistingNode)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIProductionNode

    class_< xn::ProductionNode > ("ProductionNode")
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIImageGenerator

    class_< ImageGeneratorWrapper,
            bases< xn::ProductionNode > >("ImageGenerator")

            // methods

            .def("IsValid", &ImageGeneratorWrapper::IsValid)
            .def("XRes", &ImageGeneratorWrapper::XRes)
            .def("YRes", &ImageGeneratorWrapper::YRes)
            .def("Res", &ImageGeneratorWrapper::Res)

            .def(
            "GetRGB24ImageMapTuple",
            &ImageGeneratorWrapper::GetRGB24ImageMapTuple)

            .def(
            "GetRGB24ImageMapRaw",
            &ImageGeneratorWrapper::GetRGB24ImageMapRaw)

            .def(
            "GetSyncedRGB24ImageMapRaw",
            &ImageGeneratorWrapper::GetSyncedRGB24ImageMapRaw)

            .def(
            "GetBGR24ImageMapRaw",
            &ImageGeneratorWrapper::GetBGR24ImageMapRaw)

            .def(
            "GetSyncedBGR24ImageMapRaw",
            &ImageGeneratorWrapper::GetSyncedBGR24ImageMapRaw)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIImageMetaData

    class_< ImageMetaDataWrapper > ("ImageMetaData")
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIDepthGenerator

    class_< DepthGeneratorWrapper,
            bases<xn::ProductionNode> >("DepthGenerator")

            // methods

            .def("IsValid", &DepthGeneratorWrapper::IsValid)
            .def("XRes", &DepthGeneratorWrapper::XRes)
            .def("YRes", &DepthGeneratorWrapper::YRes)
            .def("Res", &DepthGeneratorWrapper::Res)

            .def("GetGrayscale16DepthMapTuple",
            &DepthGeneratorWrapper::GetGrayscale16DepthMapTuple)

            .def("GetGrayscale16DepthMapRaw",
            &DepthGeneratorWrapper::GetGrayscale16DepthMapRaw)

            .def("GetGrayscale8DepthMapRaw",
            &DepthGeneratorWrapper::GetGrayscale8DepthMapRaw)

            ;


} // End Boost Python module OpenNIPythonWrapper
