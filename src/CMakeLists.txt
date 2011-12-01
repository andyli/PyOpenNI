# -*- mode: cmake; -*-
# ***** BEGIN GPL LICENSE BLOCK *****
#
# This file is part of PyOpenNI.
#
# PyOpenNI is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PyOpenNI is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
#
# PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
# OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
#
# ***** END GPL LICENSE BLOCK *****


# Find the needed libraries
find_package (PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
set(LIBS ${LIBS} ${PYTHON_LIBRARIES})

find_package (OpenNI REQUIRED)
include_directories(${OPENNI_INCLUDE_DIRS})
set(LIBS ${LIBS} ${OPENNI_LIBRARIES})

find_package (Boost REQUIRED COMPONENTS python)
include_directories(${Boost_INCLUDE_DIRS})
set(LIBS ${LIBS} ${Boost_LIBRARIES})


set (SOURCES
    wrapper.cpp
    wrapper.h
    wrapperTypes.h
    wrapperExceptions.cpp
    wrapperExceptions.h
    wrapperDocstrings.h
    VersionWrapper.cpp
    VersionWrapper.h
    OutputMetaDataWrapper.cpp
    OutputMetaDataWrapper.h
    MapMetaDataWrapper.cpp
    MapMetaDataWrapper.h
    ImageMetaDataWrapper.cpp
    ImageMetaDataWrapper.h
    DepthMetaDataWrapper.cpp
    DepthMetaDataWrapper.h
    SkeletonJointWrapper.cpp
    SkeletonJointWrapper.h
    CapabilityWrapper.cpp
    CapabilityWrapper.h
    PoseDetectionCapabilityWrapper.cpp
    PoseDetectionCapabilityWrapper.h
    SkeletonCapabilityWrapper.cpp
    SkeletonCapabilityWrapper.h
    ProductionNodeWrapper.cpp
    ProductionNodeWrapper.h
    GeneratorWrapper.cpp
    GeneratorWrapper.h
    MapGeneratorWrapper.cpp
    MapGeneratorWrapper.h
    ImageGeneratorWrapper.cpp
    ImageGeneratorWrapper.h
    DepthGeneratorWrapper.cpp
    DepthGeneratorWrapper.h
    GestureGeneratorWrapper.cpp
    GestureGeneratorWrapper.h
    UserGeneratorWrapper.cpp
    UserGeneratorWrapper.h
    ContextWrapper.cpp
    ContextWrapper.h
    OpenNIException.cpp
    OpenNIException.h
    conversionHelpers.cpp
    conversionHelpers.h
    util/PythonOutputStream.cpp
    util/PythonOutputStream.h
    util/PythonOutputStreamManager.hpp
    util/PythonOutputStreamSink.hpp
)

add_library (PyOpenNI SHARED ${SOURCES})
target_link_libraries (PyOpenNI ${LIBS})

set_target_properties (PyOpenNI PROPERTIES OUTPUT_NAME ${MODULE_NAME})
# Remove the "lib" prefix:
set_target_properties (PyOpenNI PROPERTIES PREFIX "")
# Set output directories:
set_target_properties (PyOpenNI PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_RESULT_DIR})
set_target_properties (PyOpenNI PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_RESULT_DIR})
set_target_properties (PyOpenNI PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_RESULT_DIR})
