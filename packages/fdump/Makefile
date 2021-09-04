#
# Individual package makefile, calls $CLAS_CMS/Makefile with the
# appropriate arguments

# get the directory make has been invoked from, this is used to NAME the
# binary and executable

MAIN_DIRECTORY = $(notdir $(shell pwd))

# TOP_DIR points to the final location of binary and library tree:
# $(TOP_DIR)/$(OS_NAME)/bin/       $(TOP_DIR)/$(OS_NAME)/lib/
#
# USERS should set the enviroment TOP_DIR to a directory of their choice
# to override the default relative path

# CLAS_CMS points to the location of the included makefiles.  
# Default is to get this from the enviroment.

ifndef CLAS_CMS
 CLAS_CMS = ../
endif

CREATED_F=fdump.F

LIBNAMES=$(FDUMP_LIBS) $(FDUMP_MD_LIBS)

SHARED_LIBS=$(FDUMP_SHARED_LIBS)

# get the defined link lists, link.$(OS_NAME).mk contains the machine
# dependent part of the link list.

include $(CLAS_CMS)/Makefile
