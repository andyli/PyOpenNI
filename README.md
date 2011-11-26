# PyOpenNI #

## Introduction ##

**PyOpenNI** is a project providing bindings for the [OpenNI](http://openni.org) computer vision library on Python. It is based on [onipy](http://code.google.com/p/onipy) but adds many improvements to it:

 * Implemented more features.
 * Removed unnecessary `OpenNI` prefixes.
 * Uses [CMake](http://cmake.org), the popular cross-platform buildsystem, to configure & compile the bindings.  
   This way, it autodetects needed libraries and warns you if they're not found.
 * Code cleanup and formatted according to [PEP 8](http://www.python.org/dev/peps/pep-0008) rules.
 * Directory structure simplified.
 * **New!** Errors are handled gracefully through the class `OpenNIError`.
 * **New!** Re-wrote wrapper's core to make it more robust and avoid crashes.
 * **New!** Callbacks are now completely supported!
 * **New!** Exposed features are now documented in Python.

PyOpenNI is written with the [Boost.Python](http://www.boost.org/doc/libs/release/libs/python/doc/index.html) libraries. PyOpenNI is released under the [GNU GPL](http://www.gnu.org/copyleft/gpl.html) version 3.

**Note:** Currently, only a _small group of features_ are being exposed to Python. We are working to add more, but if you want to accelerate this process you're encouraged to collaborate. [Contact me](mailto:jmendeth@gmail.com) if you wish to help develop PyOpenNI.
See the [github page](https://github.com/jmendeth/PyOpenNI) if you want to submit a **bug** or a **feature request**. Thanks!

## Using the bindings ##

**An example script that uses the bindings:**

```python
from openni import *

print "Initializing..."
ctx = Context()
ctx.init()
gest = GestureGenerator()
gest.create(ctx)

print "Registering listeners..."
gest.add_gesture("Wave")
gest.add_gesture("Click")

def gesture_detected(src, gesture, id, endPoint):
    print "Detected gesture:", gesture

def gesture_progress(src, gesture, point, progress): pass

gest.register_gesture_cb(gesture_detected, gesture_progress)
print "Ready! Starting to detect gestures."
ctx.start_generating_all()

try:
    print "Press Control-C to quit.\n"
    while True: ctx.wait_any_update_all()
except KeyboardInterrupt: print
```

We tried to respect the C++ names and structure.  
See the documentation (stored at `doc/`) for more details.
