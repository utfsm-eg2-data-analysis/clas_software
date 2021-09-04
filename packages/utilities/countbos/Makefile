ifndef OS_NAME
 OS_NAME=$(shell $(CLAS_CMS)/uname_clas)
endif

CREATED_C = countbos.c
LIBNAMES = c_bos_io$(ADD_DEBUG) bankdefs$(ADD_DEBUG) fputil$(ADD_DEBUG) fpack$(ADD_DEBUG) bos$(ADD_DEBUG) packlib kernlib
include $(CLAS_CMS)/Makefile

ifeq ($(OS_NAME),SunOS)
  LIBNAMES += nsl
endif

ifeq ($(OS_NAME),SunOSws6)
  LIBNAMES += nsl
endif

ifeq ($(OS_NAME),HP-UX)
        LIBNAMES += C
        LIB_PATH += /opt/CC/lib/eh
endif
