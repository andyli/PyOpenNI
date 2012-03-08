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

    depthMap = depth.map

    # Get the coordinates of the middle pixel
    x = depthMap.width / 2
    y = depthMap.height / 2
    
    # Get the pixel at these coordinates
    pixel = depthMap[x,y]

    print "The middle pixel is %d millimeters away." % pixel


