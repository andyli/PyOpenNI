#!/usr/bin/python
## The equivalent of:
##  "Basic Functions: Initialize, Create a Node and Read Data"
## in the OpenNI user guide.

# This template provides the basic structure of any OpenNI program:
# initialize a Context, create and start a Node, and keep processing its data.
# ==============================================================================


"""
TODO: Put the description of this script here.
"""

from openni import *

shouldRun = True

try:

    ctx = Context()

    # Initialize context object
    ctx.init()

    # Create a DepthGenerator node
    depth = DepthGenerator()
    depth.create(ctx)

    # Make it start generating data
    ctx.start_generating_all()

    # Main loop
    while shouldRun:
        try:
            # Wait for new data to be available
            ctx.wait_one_update_all(depth)
        except OpenNIError, err:
            print "Failed updating data:", err
        else:
            # Take current depth map
            depthMap = depth.get_tuple_depth_map()

            # TODO: process depth map

except OpenNIError, err:
    # Inform the user about the error.
    print "OpenNI found an error:", err

