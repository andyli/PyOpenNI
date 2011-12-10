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


// Boost
#include <boost/python.hpp>

// custom
#include "wrapper.h"

#include "wrapperExceptions.h"
#include "wrapperDocstrings.h"

#include "OpenNIException.h"
#include "ContextWrapper.h"
#include "OutputMetaDataWrapper.h"
#include "MapMetaDataWrapper.h"
#include "DepthMetaDataWrapper.h"
#include "ImageMetaDataWrapper.h"
#include "SkeletonJointWrapper.h"
#include "CapabilityWrapper.h"
#include "PoseDetectionCapabilityWrapper.h"
#include "SkeletonCapabilityWrapper.h"
#include "ProductionNodeWrapper.h"
#include "GeneratorWrapper.h"
#include "MapGeneratorWrapper.h"
#include "ImageGeneratorWrapper.h"
#include "DepthGeneratorWrapper.h"
#include "GestureGeneratorWrapper.h"
#include "UserGeneratorWrapper.h"
#include "VersionWrapper.h"

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

    enum_< XnSkeletonJoint > ("SkeletonJoint")
            .value("SKEL_HEAD", XN_SKEL_HEAD)
            .value("SKEL_NECK", XN_SKEL_NECK)
            .value("SKEL_TORSO", XN_SKEL_TORSO)
            .value("SKEL_WAIST", XN_SKEL_WAIST)
            .value("SKEL_LEFT_COLLAR", XN_SKEL_LEFT_COLLAR)
            .value("SKEL_LEFT_SHOULDER", XN_SKEL_LEFT_SHOULDER)
            .value("SKEL_LEFT_ELBOW", XN_SKEL_LEFT_ELBOW)
            .value("SKEL_LEFT_WRIST", XN_SKEL_LEFT_WRIST)
            .value("SKEL_LEFT_HAND", XN_SKEL_LEFT_HAND)
            .value("SKEL_LEFT_FINGERTIP", XN_SKEL_LEFT_FINGERTIP)
            .value("SKEL_RIGHT_COLLAR", XN_SKEL_RIGHT_COLLAR)
            .value("SKEL_RIGHT_SHOULDER", XN_SKEL_RIGHT_SHOULDER)
            .value("SKEL_RIGHT_ELBOW", XN_SKEL_RIGHT_ELBOW)
            .value("SKEL_RIGHT_WRIST", XN_SKEL_RIGHT_WRIST)
            .value("SKEL_RIGHT_HAND", XN_SKEL_RIGHT_HAND)
            .value("SKEL_RIGHT_FINGERTIP", XN_SKEL_RIGHT_FINGERTIP)
            .value("SKEL_LEFT_HIP", XN_SKEL_LEFT_HIP)
            .value("SKEL_LEFT_KNEE", XN_SKEL_LEFT_KNEE)
            .value("SKEL_LEFT_ANKLE", XN_SKEL_LEFT_ANKLE)
            .value("SKEL_LEFT_FOOT", XN_SKEL_LEFT_FOOT)
            .value("SKEL_RIGHT_HIP", XN_SKEL_RIGHT_HIP)
            .value("SKEL_RIGHT_KNEE", XN_SKEL_RIGHT_KNEE)
            .value("SKEL_RIGHT_ANKLE", XN_SKEL_RIGHT_ANKLE)
            .value("SKEL_RIGHT_FOOT", XN_SKEL_RIGHT_FOOT)
            .export_values()
            ;

    enum_< XnSkeletonProfile > ("SkeletonProfile")
            .value("SKEL_PROFILE_NONE", XN_SKEL_PROFILE_NONE)
            .value("SKEL_PROFILE_ALL", XN_SKEL_PROFILE_ALL)
            .value("SKEL_PROFILE_UPPER", XN_SKEL_PROFILE_UPPER)
            .value("SKEL_PROFILE_LOWER", XN_SKEL_PROFILE_LOWER)
            .value("SKEL_PROFILE_HEAD_HANDS", XN_SKEL_PROFILE_HEAD_HANDS)
            .export_values()
            ;
    
    enum_< XnCalibrationStatus > ("CalibrationStatus")
            .value("CALIBRATION_STATUS_OK", XN_CALIBRATION_STATUS_OK)
            .value("CALIBRATION_STATUS_NO_USER", XN_CALIBRATION_STATUS_NO_USER)
            .value("CALIBRATION_STATUS_ARM", XN_CALIBRATION_STATUS_ARM)
            .value("CALIBRATION_STATUS_LEG", XN_CALIBRATION_STATUS_LEG)
            .value("CALIBRATION_STATUS_HEAD", XN_CALIBRATION_STATUS_HEAD)
            .value("CALIBRATION_STATUS_TORSO", XN_CALIBRATION_STATUS_TORSO)
            .value("CALIBRATION_STATUS_TOP_FOV", XN_CALIBRATION_STATUS_TOP_FOV)
            .value("CALIBRATION_STATUS_SIDE_FOV", XN_CALIBRATION_STATUS_SIDE_FOV)
            .value("CALIBRATION_STATUS_POSE", XN_CALIBRATION_STATUS_POSE)
            //.value("CALIBRATION_STATUS_MANUAL_ABORT", XN_CALIBRATION_STATUS_MANUAL_ABORT)
            //.value("CALIBRATION_STATUS_MANUAL_RESET", XN_CALIBRATION_STATUS_MANUAL_RESET)
            //.value("CALIBRATION_STATUS_TIMEOUT_FAIL", XN_CALIBRATION_STATUS_TIMEOUT_FAIL)
            .export_values()
            ;
    
    ////////////////////////////////////////////////////////////////////////////
    // capability names
    
    scope().attr("CAPABILITY_EXTENDED_SERIALIZATION") = XN_CAPABILITY_EXTENDED_SERIALIZATION;
    scope().attr("CAPABILITY_MIRROR") = XN_CAPABILITY_MIRROR;
    scope().attr("CAPABILITY_ALTERNATIVE_VIEW_POINT") = XN_CAPABILITY_ALTERNATIVE_VIEW_POINT;
    scope().attr("CAPABILITY_CROPPING") = XN_CAPABILITY_CROPPING;
    scope().attr("CAPABILITY_USER_POSITION") = XN_CAPABILITY_USER_POSITION;
    scope().attr("CAPABILITY_SKELETON") = XN_CAPABILITY_SKELETON;
    scope().attr("CAPABILITY_POSE_DETECTION") = XN_CAPABILITY_POSE_DETECTION;
    scope().attr("CAPABILITY_LOCK_AWARE") = XN_CAPABILITY_LOCK_AWARE;
    scope().attr("CAPABILITY_ERROR_STATE") = XN_CAPABILITY_ERROR_STATE;
    scope().attr("CAPABILITY_FRAME_SYNC") = XN_CAPABILITY_FRAME_SYNC;
    scope().attr("CAPABILITY_DEVICE_IDENTIFICATION") = XN_CAPABILITY_DEVICE_IDENTIFICATION;
    scope().attr("CAPABILITY_BRIGHTNESS") = XN_CAPABILITY_BRIGHTNESS;
    scope().attr("CAPABILITY_CONTRAST") = XN_CAPABILITY_CONTRAST;
    scope().attr("CAPABILITY_HUE") = XN_CAPABILITY_HUE;
    scope().attr("CAPABILITY_SATURATION") = XN_CAPABILITY_SATURATION;
    scope().attr("CAPABILITY_SHARPNESS") = XN_CAPABILITY_SHARPNESS;
    scope().attr("CAPABILITY_GAMMA") = XN_CAPABILITY_GAMMA;
    scope().attr("CAPABILITY_COLOR_TEMPERATURE") = XN_CAPABILITY_COLOR_TEMPERATURE;
    scope().attr("CAPABILITY_BACKLIGHT_COMPENSATION") = XN_CAPABILITY_BACKLIGHT_COMPENSATION;
    scope().attr("CAPABILITY_GAIN") = XN_CAPABILITY_GAIN;
    scope().attr("CAPABILITY_PAN") = XN_CAPABILITY_PAN;
    scope().attr("CAPABILITY_TILT") = XN_CAPABILITY_TILT;
    scope().attr("CAPABILITY_ROLL") = XN_CAPABILITY_ROLL;
    scope().attr("CAPABILITY_ZOOM") = XN_CAPABILITY_ZOOM;
    scope().attr("CAPABILITY_EXPOSURE") = XN_CAPABILITY_EXPOSURE;
    scope().attr("CAPABILITY_IRIS") = XN_CAPABILITY_IRIS;
    scope().attr("CAPABILITY_FOCUS") = XN_CAPABILITY_FOCUS;
    scope().attr("CAPABILITY_LOW_LIGHT_COMPENSATION") = XN_CAPABILITY_LOW_LIGHT_COMPENSATION;
    scope().attr("CAPABILITY_ANTI_FLICKER") = XN_CAPABILITY_ANTI_FLICKER;
    scope().attr("CAPABILITY_HAND_TOUCHING_FOV_EDGE") = XN_CAPABILITY_HAND_TOUCHING_FOV_EDGE;
    scope().attr("CAPABILITY_ANTI_FILCKER") = XN_CAPABILITY_ANTI_FILCKER;
    
    


    ////////////////////////////////////////////////////////////////////////////
    // global functions

    def("bindings_version", version);
    def("version", &GetVersion_wrapped);



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
            
            .add_property("res", &MapMetaData_Res)
            .add_property("offset", &MapMetaData_Offset)
            .add_property("full_res", &MapMetaData_FullRes)
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ImageMetaData

    class_< xn::ImageMetaData,
            bases<xn::MapMetaData>, boost::noncopyable > ("ImageMetaData", no_init)
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class DepthMetaData

    class_< xn::DepthMetaData,
            bases<xn::MapMetaData>, boost::noncopyable> ("DepthMetaData", no_init)
    
            .add_property("z_res", &DepthMetaData_ZRes )
    
            ;




    ////////////////////////////////////////////////////////////////////////////
    // class SkeletonJointOrientation

    class_< XnSkeletonJointOrientation > ("SkeletonJointOrientation")
            .add_property("confidence", &XnSkeletonJointOrientation::fConfidence, &XnSkeletonJointOrientation::fConfidence)
            .add_property("matrix", &XnSkeletonJointOrientation_GetMatrix, &XnSkeletonJointOrientation_SetMatrix)
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class SkeletonJointPosition

    class_< XnSkeletonJointPosition > ("SkeletonJointPosition")
            .add_property("confidence", &XnSkeletonJointPosition::fConfidence, &XnSkeletonJointPosition::fConfidence)
            .add_property("point", &XnSkeletonJointPosition_GetPoint, &XnSkeletonJointPosition_SetPoint)
            ;


    ////////////////////////////////////////////////////////////////////////////
    // class SkeletonJointTransform

    class_< XnSkeletonJointTransformation > ("SkeletonJointTransform")
            .add_property("orientation", &XnSkeletonJointTransformation::orientation, &XnSkeletonJointTransformation::orientation)
            .add_property("position", &XnSkeletonJointTransformation::position, &XnSkeletonJointTransformation::position)
            ;




    ////////////////////////////////////////////////////////////////////////////
    // class Capability

    class_< xn::Capability > ("Capability", no_init)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class PoseDetectionCapability

    class_< xn::PoseDetectionCapability,
            bases<xn::Capability> > ("PoseDetectionCapability", no_init)

            .def("count_poses", &xn::PoseDetectionCapability::GetNumberOfPoses)
            .def("start_detection", &PoseDetectionCapability_StartPoseDetection_wrapped)
            .def("stop_detection", &PoseDetectionCapability_StopPoseDetection_wrapped)
    
            .def("register_pose_detected_cb", &PoseDetectionCapability_RegisterPoseDetectedCallback, return_value_policy<return_opaque_pointer>())
            .def("unregister_pose_detected_cb", &PoseDetectionCapability_UnregisterPoseDetectedCallback)
            .def("register_out_of_pose_cb", &PoseDetectionCapability_RegisterOutOfPoseCallback, return_value_policy<return_opaque_pointer>())
            .def("unregister_out_of_pose_cb", &PoseDetectionCapability_UnregisterOutOfPoseCallback)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class SkeletonCapability

    class_< xn::SkeletonCapability,
            bases<xn::Capability> > ("SkeletonCapability", no_init)

            .add_property("calibration_needs_pose", &xn::SkeletonCapability::NeedPoseForCalibration)

            .def("is_tracking", &xn::SkeletonCapability::IsTracking)
            .def("is_calibrated", &xn::SkeletonCapability::IsCalibrated)
            .def("is_calibrating", &xn::SkeletonCapability::IsCalibrating)
            .def("is_joint_available", &xn::SkeletonCapability::IsJointAvailable)
            .def("is_profile_available", &xn::SkeletonCapability::IsProfileAvailable)

            .def("is_joint_active", &SkeletonCapability_IsJointActive_wrapped)
            .def("set_joint_active", &SkeletonCapability_SetJointActive_wrapped)
            .def("set_profile", &SkeletonCapability_SetSkeletonProfile_wrapped)

            .def("reset", &SkeletonCapability_Reset_wrapped)
            .def("start_tracking", &SkeletonCapability_StartTracking_wrapped)
            .def("stop_tracking", &SkeletonCapability_StopTracking_wrapped)
            .def("request_calibration", &SkeletonCapability_RequestCalibration_wrapped)
            .def("abort_calibration", &SkeletonCapability_AbortCalibration_wrapped)

            .def("load_cdata", &SkeletonCapability_LoadCalibrationData_wrapped)
            .def("save_cdata", &SkeletonCapability_SaveCalibrationData_wrapped)
            .def("clear_cdata", &SkeletonCapability_ClearCalibrationData_wrapped)
            .def("has_cdata", &SkeletonCapability_IsCalibrationData_wrapped)

            .def("set_smoothing", &SkeletonCapability_SetSmoothing_wrapped)

            .def("get_joint", &SkeletonCapability_GetJoint_wrapped)
            .def("get_joint_orientation", &SkeletonCapability_GetJointOrientation_wrapped)
            .def("get_joint_position", &SkeletonCapability_GetJointPosition_wrapped)

            .def("register_c_start_cb", &SkeletonCapability_RegisterCalibrationStart, return_value_policy<return_opaque_pointer>())
            .def("register_c_complete_cb", &SkeletonCapability_RegisterCalibrationComplete, return_value_policy<return_opaque_pointer>())
            .def("register_c_in_progress_cb", &SkeletonCapability_RegisterCalibrationInProgress, return_value_policy<return_opaque_pointer>())

            .def("unregister_c_start_cb", &SkeletonCapability_UnregisterCalibrationStart)
            .def("unregister_c_complete_cb", &SkeletonCapability_UnregisterCalibrationComplete)
            .def("unregister_c_in_progress_cb", &SkeletonCapability_UnregisterCalibrationInProgress)

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
            .def("wait_one_update_all", &Context_WaitOneUpdateAll_wrapped, Context_WaitOneUpdateAll_DOC)
            .def("wait_none_update_all", &Context_WaitNoneUpdateAll_wrapped, Context_WaitNoneUpdateAll_DOC)
            .def("start_generating_all", &Context_StartGeneratingAll_wrapped, Context_StartGeneratingAll_DOC)
            .def("stop_generating_all", &Context_StopGeneratingAll_wrapped, Context_StopGeneratingAll_DOC)
            .def("find_existing_node", &Context_FindExistingNode_wrapped)

            .add_property("valid", &Context_IsValid)

            ;


    ////////////////////////////////////////////////////////////////////////////
    // class ProductionNode

    class_< xn::ProductionNode > ("ProductionNode", ProductionNode_DOC)
            .add_property("valid", &xn::ProductionNode::IsValid, ProductionNode_valid_DOC)
            .add_property("name", &ProductionNode_GetName_wrapped)

            .def("is_capability_supported", &ProductionNode_IsCapabilitySupported_wrapped, ProductionNode_IsCapabilitySupported_DOC)

            .add_property("context", &ProductionNode_GetContext_wrapped)

            ;//TODO: add optional params


    ////////////////////////////////////////////////////////////////////////////
    // class Generator

    class_< xn::Generator,
            bases<xn::ProductionNode> > ("Generator", Generator_DOC, no_init)

            //methods
            .def("start_generating", &Generator_StartGenerating_wrapped, Generator_StartGenerating_DOC)
            .def("stop_generating", &Generator_StopGenerating_wrapped, Generator_StopGenerating_DOC)
            .def("wait_and_update_data", &Generator_WaitAndUpdateData_wrapped, Generator_WaitAndUpdateData_DOC)

            //properties
            .add_property("data_new", &Generator_IsDataNew_wrapped, Generator_data_new_DOC)
            .add_property("generating", &Generator_IsGenerating_wrapped, &Generator_SetGenerating, Generator_generating_DOC)

            .add_property("timestamp", &Generator_GetTimestamp_wrapped)
            .add_property("frame_id", &Generator_GetFrameID_wrapped)
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

            .def("to_real_world", &DepthGenerator_ToRealWorld)
            .def("to_projective", &DepthGenerator_ToProjective)

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


    ////////////////////////////////////////////////////////////////////////////
    // class UserGenerator

    class_< xn::UserGenerator,
            bases<xn::Generator> >("UserGenerator")

            // capabilities

            .add_property("skeleton_cap", &UserGenerator_GetSkeletonCap_wrapped)
            .add_property("pose_detection_cap", &UserGenerator_GetPoseDetectionCap_wrapped)
            .add_property("users", &UserGenerator_GetUsers_wrapped)

            // methods

            .def("create", &UserGenerator_Create_wrapped)
            .def("count_users", &UserGenerator_CountUsers)
            .def("get_com", &UserGenerator_GetCoM_wrapped)
            .def("register_user_cb", &UserGenerator_RegisterUserCallbacks_wrapped, return_value_policy<return_opaque_pointer>())
            .def("unregister_user_cb", &UserGenerator_UnregisterUserCallbacks_wrapped)

            ;


} // End Boost Python module OpenNIPythonWrapper
