# -*- mode: cmake; -*-

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
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/)
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


project (PyOpenNI)

# Find the needed libraries
find_package (PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
set(LIBS ${LIBS} ${PYTHON_LIBRARIES})

find_package (OpenNI REQUIRED)
include_directories(${OPENNI_INCLUDE_DIRS})
set(LIBS ${LIBS} ${OPENNI_LIBRARIES})

#TODO find Boost.Python


# Finally, set add subdirectory and target libraries:
add_subdirectory (src)
target_link_libraries (PyOpenNI ${LIBS})

