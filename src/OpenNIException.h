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


#ifndef OPENNI_EXCEPTION_H
#define	OPENNI_EXCEPTION_H

#include <openni/XnStatus.h>
#include <string>

class OpenNIException : public std::exception {
public:
    OpenNIException(XnStatus status) {
        this->status = status;
    }
    ~OpenNIException() throw() {}
    XnStatus getStatus() {
        return this->status;
    }
    const char *what() const throw() {
        return getMessage().c_str();
    }
    std::string getMessage() const;
    std::string getStatusString() const {
        const XnChar* ch = xnGetStatusString(this->status);
        return std::string(ch);
    }
    std::string getStatusName() const {
        const XnChar* ch = xnGetStatusName(this->status);
        return std::string(ch);
    }
private:
    XnStatus status;
};

#endif	/* OPENNI_EXCEPTION_H */
