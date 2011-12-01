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


# Check that we aren't building in-source
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR
        "We don't allow building in the original (source) directory!\n"
        "Please, remove the CMakeCache.txt and repeat from a dedicate directory, e.g:\n"
        "\n"
        " rm CMakeCache.txt\n"
        " mkdir ../onipy-build\n"
        " cd ../onipy-build\n"
        " cmake ../onipy-2.0   #or whatever it is!"
    )
endif()

# Setup global vars
cmake_minimum_required (VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(LIBRARY_RESULT_DIR ${CMAKE_BINARY_DIR}/lib/)
set(ARCHIVE_RESULT_DIR ${CMAKE_BINARY_DIR}/lib/)
set(RUNTIME_RESULT_DIR ${CMAKE_BINARY_DIR}/bin/)

set(MODULE_NAME "openni")
set(BUILD_SHARED_LIBS True)

set(Boost_ADDITIONAL_VERSIONS "1.47" "1.47.0" "1.47.1" "1.48" "1.48.0")


project (PyOpenNI)

# Build the library
add_subdirectory (src)

