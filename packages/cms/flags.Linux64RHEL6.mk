#
#  This file contains the default FORTRAN and C compile flags
#  for Linux platforms
#  $Id: flags.Linux64RHEL5.mk,v 1.2 2007/07/12 21:14:38 hovanes Exp $
#
# set the optimization level, to compile and link debug invoke the Makefile
# with "DEBUG=1" in the command line.
#
ifdef DEBUG
  FLEVEL +=  -g -ffloat-store
  CLEVEL +=  -g  -ffloat-store
  CXXLEVEL += -g -ffloat-store
  CPPFLAGS += -DDEBUG
  ADD_DEBUG = _debug
else
  ifndef NOOPTIMIZE
    FLEVEL += -g -O3
    CLEVEL += -g -O3
    CXXLEVEL += -g -O3
  endif
  ADD_DEBUG = 
endif

ifdef GPROF
  FLEVEL += -pg
  CLEVEL += -pg         
  ifdef DEBUG
    ADD_DEBUG = _debug_prof
  else
    ADD_DEBUG = _prof
  endif
endif

# FORTRAN section

FC = gfortran
LNKCMD = gfortran
FFLAGS += $(FLEVEL)
FFLAFS += -fno-f2c -DLinux
FFLAGS += -m64 -fno-automatic -fPIC
FFLAGS += -ffixed-line-length-none
FFLAGS += -fno-second-underscore
FFLAGS += -funroll-loops
FFLAGS += -fomit-frame-pointer
FFLAGS += -fno-range-check
FFLAGS += -falign-commons
#
# Note: The -fno-f2c option is very important for mixed FORTRAN/C environment
# where there are C functions that return a float to some FORTRAN code. The "f2c" 
# calling convention wants all routines to use double only. CLAS code is not
# consistend in this.
#

# C section (vs. natural methods)

CC = gcc
CFLAGS += $(CLEVEL) -m64 -fPIC -Wall -DLinux

# LD section

FLDFLAGS += $(CLEVEL)
FLDFLAGS += -m64 -fno-automatic 
FLDFLAGS += -ffixed-line-length-none
FLDFLAGS += -fno-second-underscore

# c++ section

CXX = g++
CXXFLAGS += $(CXXLEVEL) -m64 -Wall

# SL section:

DLLFLAGS= -O -Wall -fPIC
SOFLAGS=  -shared
SL_SUF = so
SLLD=g++

# RCS section

CO = co
COFLAGS =

# CPP section

CPPFLAGS += -DLinux -fPIC

# archiver section

AR = ar
ARFLAGS = rv

# flags needed for dependency creation

CPP = gcc -MM -ffixed-line-length-none
CPP_CXX = g++ -MM -ffixed-line-length-none

# Tell the Makefile where the libraries are (X, TCL and CERNLIB)

X_LIB += /usr/lib64
X_INC += /usr/include/X11

# tell me where you keep the tcl include

TCL_INC = $(TCL_INC)
TCL_VER = tcl$(TCL_VERSION)

# DEFAULT_INCLUDES defines the default search path for include files

CTMP = $(CLAS_PACK)

DEFAULT_INCLUDES += $(addprefix -I, \
$(CTMP)/include $(CTMP)/inc_derived $(TCL_INC) $(X_INC))

ifdef USE_ROOT_SYSTEM 
  DEFAULT_INCLUDES += -I$(shell $(ROOTSYS)/bin/root-config --incdir)
endif
