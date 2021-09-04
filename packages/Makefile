#
#  this makefile sits on top of the tree and makes all the
#  binaries needed for CLAS software, currently only RECSIS is
#  supported.  We need to add: gsim, fdump, swish, ced, EventStore
#  to this list of supported binaries and libraries.
#

export CLAS_CMS  := $(shell pwd)/cms
ifndef OS_NAME
  export OS_NAME   := $(shell CLAS_CMS=$(CLAS_CMS); export CLAS_CMS; $(CLAS_CMS)/uname_clas)
endif
export CLAS_PACK := $(shell pwd)
export TOP_DIR   := $(shell cd ../; pwd)
export CLAS_LIB  := $(TOP_DIR)/lib/$(OS_NAME)
export CLAS_BIN  := $(TOP_DIR)/bin/$(OS_NAME)
export CLAS_SCRIPTS := $(CLAS_PACK)/scripts
export HV_LOCATION := $(CLAS_PACK)/Hv

all: lib exe

lib:
ifndef PARALLEL_BUILD
	$(MAKE) -e -f $(CLAS_CMS)/clas_lib.mk all
else
	$(MAKE) -e -f $(CLAS_CMS)/clas_lib.mk -j 4 all
endif

exe:
	$(MAKE) -e -f $(CLAS_CMS)/clas_bin.mk

clean:
	$(MAKE) -e -f $(CLAS_CMS)/clas_clean.mk -j 4

help_mother:
	$(MAKE) -f $(CLAS_CMS)/Makefile help

help_lib:
	$(MAKE) -f $(CLAS_CMS)/clas_lib.mk help

help_bin:
	$(MAKE) -f $(CLAS_CMS)/clas_bin.mk help

.PHONY : lib exe clean
#
