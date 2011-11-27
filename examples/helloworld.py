#!/usr/bin/python
"""
The 'hello world' in PyOpenNI.

It simply prints out OpenNI version
and PyOpenNI's.

You can run this to test your installation.
"""

import openni

print "OpenNI version:", openni.version()
print "PyOpenNI version:", openni.bindings_version()
