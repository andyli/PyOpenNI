# PyOpenNI #

## Introduction ##

**PyOpenNI** is a project integrating the [OpenNI](http://openni.org) computer vision library on Python.  
It is based on [onipy](http://code.google.com/p/onipy) but adds many improvements to it:

 * Implemented more features.
   - Some capabilities are now exposed!
   - Polymorphism on production nodes is handled correctly.
 * Removed unnecessary `OpenNI` prefixes.
 * Uses [CMake](http://cmake.org), the popular cross-platform buildsystem, to configure & compile the bindings.  
   This way, it autodetects needed libraries and warns you if they're not found.
 * Code cleanup and formatted according to [PEP 8](http://www.python.org/dev/peps/pep-0008) rules.
 * Directory structure simplified.
 * Errors are handled gracefully through the class `OpenNIError`.
 * Re-wrote wrapper's core to make it more robust and avoid crashes.
 * Callbacks are now completely supported!
 * Some exposed features are now documented in Python.

PyOpenNI is written with the [Boost.Python](http://www.boost.org/doc/libs/release/libs/python/doc/index.html) libraries. PyOpenNI is released under the [GNU LGPL](http://www.gnu.org/licenses/lgpl.html) version 3.

**Note:** Currently, not all features are being exposed to Python. We are working to add more, but if you want to accelerate this process you're encouraged to collaborate. [Contact me](mailto:jmendeth@gmail.com) if you wish to help develop PyOpenNI.
See the [github page](https://github.com/jmendeth/PyOpenNI) if you want to submit a **bug** or a **feature request**. Thanks!

## Quick install ##

Things you'll need:

 - [GIT](http://git-scm.org) to download
 - [OpenNI](http://openni.org) and [Python](http://python.org) (obviously)
 - [CMake](http://cmake.org)
 - A compiler for your platform (GCC, XCode, VS, MinGW, ...)

Then, assuming Git and CMake are installed and in your PATH:

```bash
git clone https://github.com/jmendeth/PyOpenNI.git
mkdir PyOpenNI-build
cd PyOpenNI-build
cmake ../PyOpenNI
# Build with your compiler
```

That's it! The finished module is at `lib/openni.<ext>`; just copy it to your Python modules' directory.

Instructions for specific platforms can be found on [the wiki](https://github.com/jmendeth/PyOpenNI/wiki/_pages).  
Still in trouble? [Signup](https://github.com/signup/free) on Github (it's free!) and [ask for support](https://github.com/jmendeth/PyOpenNI/issues/new).

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

