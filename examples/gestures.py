#!/usr/bin/python
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

"""
A nice and complete example of OpenNI:

it starts tracking some gestures and alerts you
when they're recognized.
"""

from openni import *

try:

    # Start OpenNI
    print "Initializing..."
    ctx = Context()
    ctx.init()
    gest = GestureGenerator()
    gest.create(ctx)

    # Add some gestures to look for
    print "Registering listeners..."
    gest.add_gesture("Wave")
    gest.add_gesture("Click")

    # Register callbacks
    def gesture_detected(src, gesture, id, endPoint):
        print "Detected gesture:", gesture

    def gesture_progress(src, gesture, point, progress): pass

    gest.register_gesture_cb(gesture_detected, gesture_progress)

    # Start generating
    print "Ready! Starting to detect gestures."
    ctx.start_generating_all()

    # Main loop:
    # process every frame until the user interrupts
    try:
        print "Press Control-C to quit.\n"
        while True: ctx.wait_any_update_all()
    except KeyboardInterrupt: print

except OpenNIError, error:
    # When an error occurs:
    print "OpenNI raised an error:", error
