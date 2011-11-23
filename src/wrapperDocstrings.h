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


#ifndef WRAPPER_DOCSTRINGS_H
#define	WRAPPER_DOCSTRINGS_H

//Context class documentation
const char* Context_DOC =
    "Represents an OpenNI context object.";

const char* Context_Init_DOC =
    "Initializates the OpenNI library.\n\n"
    "OpenNI *must* be initializated before any of its features can be used.";
const char* Context_Shutdown_DOC =
    "Destroys this context and all of its nodes and resources.\n\n"
    "Deprecated. This context and his objects will be automatically\n"
    "destroyed when they're deleted or no longer used; it's not recommended\n"
    "to call this method.";
const char* Context_StartGeneratingAll_DOC =
    "Make sure all generators are generating data.";
const char* Context_StopGeneratingAll_DOC =
    "Stop all generators from generating data.";
const char* Context_WaitAnyUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "once any of them have new data.";
const char* Context_WaitAndUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "waiting for all to have new data.";
const char* Context_WaitNoneUpdateAll_DOC =
    "Updates all generator nodes in the context, without any waiting.\n"
    "If a node has new data, it will be updated.";
const char* Context_WaitOneUpdateAll_DOC =
    "Updates all generators nodes in the context,\n"
    "waiting for a specific one to have new data.";


#endif	/* WRAPPER_DOCSTRINGS_H */
