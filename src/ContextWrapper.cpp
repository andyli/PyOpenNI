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


#include "ContextWrapper.h"
#include "wrapperExceptions.h"
#include "util/PythonOutputStream.h"

#include <stddef.h>

void ContextWrapper::_InitFromXmlFile(const std::string& initializationFilename) {

#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = xn::Context::InitFromXmlFile(initializationFilename.c_str());

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "OpenNI was initialized successfully" << std::endl;
    else {
        PyCout << "OpenNI failed to initialize: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    return check(returnCode);
}

void ContextWrapper::Shutdown() {

#ifdef _DEBUG
    PyCout << "Shutting down OpenNI.." << std::endl;
#endif

}

void ContextWrapper::_Init() {
 
#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = xn::Context::Init();

#ifdef _DEBUG
    if (returnCode == XN_STATUS_OK)
        PyCout << "OpenNI was initialized successfully" << std::endl;
    else {
        PyCout << "OpenNI failed to initialize: " <<
                xnGetStatusName(returnCode) << std::endl;
    }
#endif

    check(returnCode);    
}

void ContextWrapper::_WaitAndUpdateAll() {
    check( xn::Context::WaitAndUpdateAll() );
}

void ContextWrapper::_WaitAnyUpdateAll() {
    check( xn::Context::WaitAnyUpdateAll() );
}

xn::ProductionNode ContextWrapper::_FindExistingNode(XnProductionNodeType type) const {
    xn::ProductionNode* node = NULL;
    check( xn::Context::FindExistingNode(type, *node) );
    return *node;
}
