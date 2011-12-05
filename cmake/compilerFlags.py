import os
import distutils
from distutils import sysconfig

varnames = ['BASECFLAGS', 'CFLAGSFORSHARED', 'LINKFORSHARED', 'LIBS']

def retrieve(vnames):
    vars = sysconfig.get_config_vars(*vnames)
    return ' '.join(vars)

print retrieve(varnames)
