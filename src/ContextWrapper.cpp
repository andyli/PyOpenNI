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
#include <XnCppWrapper.h>

void Context_InitFromXmlFile_wrapped(xn::Context& self, const std::string& initializationFilename) {

#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = self.InitFromXmlFile(initializationFilename.c_str());

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

void Context_Shutdown_wrapped(xn::Context& self) {

#ifdef _DEBUG
    PyCout << "Shutting down OpenNI.." << std::endl;
#endif
    self.Shutdown();

}

void Context_Init_wrapped(xn::Context& self) {
 
#ifdef _DEBUG
    PyCout << "Initializing OpenNI.." << std::endl;
#endif

    XnStatus returnCode;
    returnCode = self.Init();

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

void Context_WaitAndUpdateAll_wrapped(xn::Context& self) {
    check( self.WaitAndUpdateAll() );
}

void Context_WaitAnyUpdateAll_wrapped(xn::Context& self) {
    check( self.WaitAnyUpdateAll() );
}

xn::ProductionNode* Context_FindExistingNode_wrapped(xn::Context& self, XnProductionNodeType type) {
    xn::ProductionNode* node = new xn::ProductionNode;
    check( self.FindExistingNode(type, *node) );
    return node;
}

void Context_StartGeneratingAll_wrapped(xn::Context& self) {
    check( self.StartGeneratingAll() );
}
void Context_StopGeneratingAll_wrapped(xn::Context& self) {
    check( self.StopGeneratingAll() );
}
