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


#ifndef AUDIO_GENERATOR_WRAPPER_H
#define	AUDIO_GENERATOR_WRAPPER_H

#include "wrapperTypes.h"
#include <string>

void AudioGenerator_Create_wrapped(xn::AudioGenerator& self, xn::Context& context);

std::string* AudioGenerator_GetAudioBuffer_wrapped(xn::AudioGenerator& self);

xn::AudioMetaData* AudioGenerator_GetMetaData_wrapped(xn::AudioGenerator& self);

#endif	/* AUDIO_GENERATOR_WRAPPER_H */
