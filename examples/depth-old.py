#!/usr/bin/python
## The equivalent of:
##  "Working with Depth, Color and Audio Maps"
## in the OpenNI user guide.

## WARNING: This sample is deprecated and kept only
## for historical reasons. It's recommended to use the
## new way of calculating the index of a pixel;
## see depth.py instead.

"""
This creates a depth generator, checks if it can generate VGA maps in 30 FPS,
configures it to that mode, and then reads frames from it, printing out the
middle pixel value.
"""


from openni import *

ctx = Context()
ctx.init()

# Create a depth generator
depth = DepthGenerator()
depth.create(ctx)

# Set it to VGA maps at 30 FPS
depth.set_resolution_preset(RES_VGA)
depth.fps = 30

# Start generating
ctx.start_generating_all()

while True:
    # Update to next frame
    nRetVal = ctx.wait_one_update_all(depth)

    dmap = depth.map

    # Calculate index of middle pixel
    middleIdx = dmap.width * (dmap.height/2) # start of the middle line...
    middleIdx += (dmap.width/2)              # plus the middle of that line

    print "The middle pixel is %d millimeters away." % dmap[middleIdx]


