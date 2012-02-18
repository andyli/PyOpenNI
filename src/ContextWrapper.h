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


#ifndef CONTEXT_WRAPPER_H
#define CONTEXT_WRAPPER_H

#include "wrapperTypes.h"

void Context_Init_wrapped(xn::Context& self);
void Context_InitFromXmlFile_wrapped(xn::Context& self, const std::string& initializationFilename);

void Context_WaitAnyUpdateAll_wrapped(xn::Context& self);
void Context_WaitAndUpdateAll_wrapped(xn::Context& self);
void Context_WaitNoneUpdateAll_wrapped(xn::Context& self);
void Context_WaitOneUpdateAll_wrapped(xn::Context& self, xn::ProductionNode& node);

void Context_StartGeneratingAll_wrapped(xn::Context& self);
void Context_StopGeneratingAll_wrapped(xn::Context& self);

BP::object Context_FindExistingNode_wrapped(xn::Context& self, XnProductionNodeType type);

void Context_Shutdown_wrapped(xn::Context& self);

XnBool Context_IsValid(xn::Context& self);

#endif    // CONTEXT_WRAPPER_H
