# PyOpenNI #

## Introduction ##

**PyOpenNI** is a project providing bindings for the [OpenNI](http://openni.org) computer vision library on Python. It is based on [onipy](http://code.google.com/p/onipy) but adds many improvements to it:

 * Implemented more features.
   - The first capabilities are now exposed!
   - Polymorphism on production nodes is good.
 * Removed unnecessary `OpenNI` prefixes.
 * Uses [CMake](http://cmake.org), the popular cross-platform buildsystem, to configure & compile the bindings.  
   This way, it autodetects needed libraries and warns you if they're not found.
 * Code cleanup and formatted according to [PEP 8](http://www.python.org/dev/peps/pep-0008) rules.
 * Directory structure simplified.
 * **New!** Errors are handled gracefully through the class `OpenNIError`.
 * **New!** Re-wrote wrapper's core to make it more robust and avoid crashes.
 * **New!** Callbacks are now completely supported!
 * **New!** Some exposed features are now documented in Python.

PyOpenNI is written with the [Boost.Python](http://www.boost.org/doc/libs/release/libs/python/doc/index.html) libraries. PyOpenNI is released under the [GNU LGPL](http://www.gnu.org/licenses/lgpl.html) version 3.

**Note:** Currently, only a _small group of features_ are being exposed to Python. We are working to add more, but if you want to accelerate this process you're encouraged to collaborate. [Contact me](mailto:jmendeth@gmail.com) if you wish to help develop PyOpenNI.
See the [github page](https://github.com/jmendeth/PyOpenNI) if you want to submit a **bug** or a **feature request**. Thanks!

## Using the bindings ##

To import the module:

```python
import openni
```

and, if you prefer, you can also

```python
from openni import *
```

so you don't have to type this annonying `openni.` before the class names.  
To get started, I suggest you to see the samples at the `examples/` folder.
And, to look at the documentation of PyOpenNI:

```python
help(openni)              #Help about the whole module
help(openni.Context)      #Help about a specific class
help(openni.Context.init) #Help about a specific function
```

