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


#ifndef PYTHON_OUTPUT_STREAM_SINK_H
#define PYTHON_OUTPUT_STREAM_SINK_H

// resolve collisions with between std::min/std::max and the min/max macros defined in windows.h

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

#include <iostream>
#include <algorithm> 
#include <iosfwd> 
#include <boost/iostreams/categories.hpp> 
#include <boost/iostreams/stream.hpp>
#include <boost/format.hpp>
#include <boost/python.hpp>

const std::streamsize SIZE_STREAM_BUFFER = 1000;

class PythonOutputStreamSink {
public:

    typedef char char_type;
    //    typedef boost::iostreams::sink_tag category; 

    struct category :
    boost::iostreams::flushable_tag,
    boost::iostreams::sink_tag {
    };

    std::streamsize write(const char* rawString, std::streamsize stringSize) {

        std::streamsize charactersWritten;
        charactersWritten = std::min(stringSize, SIZE_STREAM_BUFFER);

        PySys_WriteStdout((boost::format("%%.%1%s") %
                charactersWritten).str().c_str(), rawString);

        return charactersWritten;

    } // PythonOutputStreamSink::write

    bool flush() {
        return true;
    }

};

#endif    // PYTHON_OUTPUT_STREAM_SINK_H