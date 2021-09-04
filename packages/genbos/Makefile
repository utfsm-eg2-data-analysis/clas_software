CREATED_F = genbos.F
LIBNAMES = genbos$(ADD_DEBUG) recutl$(ADD_DEBUG) clasutil$(ADD_DEBUG) fputil$(ADD_DEBUG) bos$(ADD_DEBUG) fpack$(ADD_DEBUG) geant321 phtools packlib \
	mathlib
include $(CLAS_CMS)/Makefile

ifeq ($(OS_NAME),HP-UX)
  MD_LIBS += -lm
endif

ifeq ($(OS_NAME),SunOS)
  MD_LIBS += -lnsl -lsocket
endif

ifeq ($(OS_NAME),SunOSws6)
  MD_LIBS += -lnsl -lsocket
endif

ifeq ($(OS_NAME),Linux)
  MD_LIBS += -ldl -lnsl 
endif

ifeq ($(OS_NAME),LinuxRH6)
  MD_LIBS += -lnsl
endif

ifeq ($(OS_NAME),LinuxRH7)
  MD_LIBS += -lnsl
endif

ifeq ($(OS_NAME),LinuxRH8)
  MD_LIBS += -lnsl
endif

ifeq ($(OS_NAME),LinuxRH9)
  MD_LIBS += -lnsl
endif

# end of makefile
