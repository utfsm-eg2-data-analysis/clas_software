#  This file contains the default FORTRAN and C compile flags
#  for Linux platforms
#  $Id: flags.Linux64RHEL5.mk,v 1.2 2007/07/12 21:14:38 hovanes Exp $
#
# set the optimization level, to compile and link debug invoke the Makefile
# with "DEBUG=1" in the command line.

ifdef DEBUG
  FLEVEL   += -g
  CLEVEL   += -g
  CXXLEVEL += -g
  CPPFLAGS += -DDEBUG
  ADD_DEBUG = _debug
else
  ifndef NOOPTIMIZE
    FLEVEL += -O3
    CLEVEL += -O3
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
LNKCMD   = gfortran
FFLAGS  += $(FLEVEL)
FFLAGS  += -fno-automatic -fPIC
FFLAGS  += -ffixed-line-length-none
FFLAGS  += -fno-second-underscore
FFLAGS  += -fno-range-check
FFLAGS  += -fno-align-commons
FFLAGS  += -std=legacy
##
##

# Note: The -fno-f2c option is very important for mixed FORTRAN/C environment
# where there are C functions that return a float to some FORTRAN code. The "f2c" 
# calling convention wants all routines to use double only. CLAS code is not
# consistend in this.

# C section (vs. natural methods)
CC        = gcc
CFLAGS   += $(CLEVEL) -fPIC

# LD section
FLDFLAGS  += $(CLEVEL)
FLDFLAGS  += -fno-automatic -fPIC
FLDFLAGS  += -ffixed-line-length-none
FLDFLAGS  += -fno-second-underscore
FLDFLAGS  += -fno-range-check
FLDFLAGS  += -fno-align-commons
FLDFLAGS  += -std=legacy

# c++ section
CXX = g++
CXXFLAGS += $(CXXLEVEL)

# SL section:
DLLFLAGS = -O -Wall -fPIC
SOFLAGS  = -shared
SL_SUF   = so
SLLD     = g++

# RCS section
CO      = co
COFLAGS =

# CPP section
CPPFLAGS += -DLinux -fPIC

# archiver section
AR      = ar
ARFLAGS = rv

# flags needed for dependency creation
CPP     = gfortran -MM
CPP_CXX = g++ -MM

X_INC += /usr/include
X_INC += /usr/include/freetype2

# tell me where you keep the tcl includes
ifndef TCL_INC
  TCL_INC = /usr/include
endif
TCL_VER = TCL80

# DEFAULT_INCLUDES defines the default search path for include files
CTMP = $(CLAS_PACK)
DEFAULT_INCLUDES += $(addprefix -I, $(CTMP)/include $(CTMP)/inc_derived $(TCL_INC) $(X_INC))
ifdef USE_ROOT_SYSTEM 
  DEFAULT_INCLUDES += -I$(shell $(ROOTSYS)/bin/root-config --incdir)
endif

ifeq ($(ARCH), 32bit)
  FFLAGS   += -m32
  CFLAGS   += -m32
  FLDFLAGS += -m32
  CXXFLAGS += -m32
  CPPFLAGS += -m32
  # Tell the Makefile where the libraries are (X, TCL and CERNLIB)
  X_LIB    += /usr/lib $(SOFT)/lib
endif
ifeq ($(ARCH), 64bit)
  FFLAGS   += -m64
  CFLAGS   += -m64
  FLDFLAGS += -m64
  CXXFLAGS += -m64
  CPPFLAGS += -m64
  # Tell the Makefile where the libraries are (X, TCL and CERNLIB)
  X_LIB    += /usr/lib64
endif
