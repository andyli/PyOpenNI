#!/usr/bin/python
## The equivalent of:
##  "Working with Depth, Color and Audio Maps"
## in the OpenNI user guide.

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

    depthMap = depth.get_tuple_depth_map()
    res = depth.metadata.res

    # Calculate index of middle pixel
    middleIdx = res[0] * (res[1]/2) # start of the middle line...
    middleIdx += (res[0]/2)         # plus the middle of that line

    print "The middle pixel is %d millimeters away." % depthMap[middleIdx]


