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
#include "OpenNIDepthGeneratorWrapper.h"
#include "OpenNIImageMetaDataWrapper.h"

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

BOOST_PYTHON_MODULE(OpenNIPythonWrapper) {

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

    def("version", version);


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIContext

    class_< OpenNIContextWrapper > ("OpenNIContext")

            // methods

            .def("InitFromXmlFile", &OpenNIContextWrapper::InitFromXmlFile)
            .def("Shutdown", &OpenNIContextWrapper::Shutdown)
            .def("WaitAnyUpdateAll", &OpenNIContextWrapper::WaitAnyUpdateAll)
            .def("WaitAndUpdateAll", &OpenNIContextWrapper::WaitAndUpdateAll)
            .def("FindExistingNode", &OpenNIContextWrapper::FindExistingNode)

            ; // class OpenNIContext


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIProductionNode

    class_< xn::ProductionNode > ("OpenNIProductionNode")
            ; // class OpenNIProductionNode


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIImageGenerator

    class_<
            OpenNIImageGeneratorWrapper,
            bases< xn::ProductionNode > >("OpenNIImageGenerator")

            // methods

            .def("IsValid", &OpenNIImageGeneratorWrapper::IsValid)
            .def("XRes", &OpenNIImageGeneratorWrapper::XRes)
            .def("YRes", &OpenNIImageGeneratorWrapper::YRes)
            .def("Res", &OpenNIImageGeneratorWrapper::Res)

            .def(
            "GetRGB24ImageMapTuple",
            &OpenNIImageGeneratorWrapper::GetRGB24ImageMapTuple)

            .def(
            "GetRGB24ImageMapRaw",
            &OpenNIImageGeneratorWrapper::GetRGB24ImageMapRaw)

            .def(
            "GetSyncedRGB24ImageMapRaw",
            &OpenNIImageGeneratorWrapper::GetSyncedRGB24ImageMapRaw)

            .def(
            "GetBGR24ImageMapRaw",
            &OpenNIImageGeneratorWrapper::GetBGR24ImageMapRaw)

            .def(
            "GetSyncedBGR24ImageMapRaw",
            &OpenNIImageGeneratorWrapper::GetSyncedBGR24ImageMapRaw)

            ; // class OpenNIImageGenerator


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIImageMetaData

    class_< OpenNIImageMetaDataWrapper > ("OpenNIImageMetaData")

            ; // class OpenNIImageMetaData


    ////////////////////////////////////////////////////////////////////////////
    // class OpenNIDepthGenerator

    class_<
            OpenNIDepthGeneratorWrapper,
            bases< xn::ProductionNode > >("OpenNIDepthGenerator")

            // methods

            .def("IsValid", &OpenNIDepthGeneratorWrapper::IsValid)
            .def("XRes", &OpenNIDepthGeneratorWrapper::XRes)
            .def("YRes", &OpenNIDepthGeneratorWrapper::YRes)
            .def("Res", &OpenNIDepthGeneratorWrapper::Res)

            .def(
            "GetGrayscale16DepthMapTuple",
            &OpenNIDepthGeneratorWrapper::GetGrayscale16DepthMapTuple)

            .def(
            "GetGrayscale16DepthMapRaw",
            &OpenNIDepthGeneratorWrapper::GetGrayscale16DepthMapRaw)

            .def(
            "GetGrayscale8DepthMapRaw",
            &OpenNIDepthGeneratorWrapper::GetGrayscale8DepthMapRaw)

            ; // class OpenNIImageGenerator

} // Boost Python module OpenNIPythonWrapper
