#
#  this makefile sits on top of the tree and makes all the
#  binaries needed for CLAS software, currently RECSIS. FDUMP and GSIM_BAT are
#  supported.  We need to add: swish, ced, EventStore
#  to this list.
#

ifndef OS_NAME
 OS_NAME = $(shell $(CLAS_CMS)/uname_clas)
endif

ifdef ONLINE
 BINARIES += recon
else
# BINARIES += recsis ntuplemakers user_ana EventStore celeg fdump gsim_int gsim_bat utilities swish ced gpp nt10maker \
#	genbos caldb aao/aao_norad aao/aao_rad genbos caldb
# fk: shortlist
 BINARIES += recsis user_ana celeg  
 BINARIES += fdump gsim_int gsim_bat swish ced gpp nt10maker genbos psg caldb utilities
 BINARIES += ClasTool
endif

.PHONY : all $(BINARIES)

all: $(BINARIES)

help:
	@echo BINARIES = $(BINARIES)

$(BINARIES):
	@if [ -d $@ -a "$@" ]; then \
		echo "++++++++++++++++++++++++++++++++++++++++";\
		echo ">>>>>>>>>>>>>>>>>> bin: $@ <<<<<<<<<<<<<<<<<<";\
		echo "++++++++++++++++++++++++++++++++++++++++";\
		$(MAKE) -e -C $@ exe; \
	fi

# These following routines are needed to define the link list

include $(CLAS_CMS)/flags.$(OS_NAME).mk
include $(CLAS_CMS)/link.mk
include $(CLAS_CMS)/link.$(OS_NAME).mk
