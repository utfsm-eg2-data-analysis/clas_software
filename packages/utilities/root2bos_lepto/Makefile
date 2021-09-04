CCSRCS    =  $(wildcard *.cc)

EXE       =  $(CLAS_BIN)/root2bos_lepto

CXX       =  g++

CCFLAGS   =  -g -Wall -fPIC -Wno-deprecated
CCFLAGS   += `$(ROOTSYS)/bin/root-config --cflags`
CCFLAGS   += -I$(ROOTSYS)/include -I$(CLAS_PACK)/include

ROOTLIB   =  `$(ROOTSYS)/bin/root-config --glibs` -ltbb
CLIB      = -L$(CERN_LIB) -lpdflib804 -lpacklib -lmathlib -lkernlib -lnsl -lcrypt -ldl
#BOSLIB   = -L$(CLAS_LIB) -lfputil -lbos -lfpack -lpacklib -lgfortran
BOSLIB    = -L$(CLAS_LIB) -lfputil -lbos -lfpack -lpacklib -lgfortran

LIBS      = $(ROOTLIB) $(CLIB) $(BOSLIB)

CCOBJ     =  $(CCSRCS:.cc=.o)

all:  echo $(EXE) 

echo:
	@echo 'Start compilation at : '
	@date 

.cc.o:
	@echo compiling $<
	${CXX} -c ${CCFLAGS} $<

$(EXE):$(CCOBJ)
	${CXX} -o ${EXE} $(CCOBJ) $(LIBS) ${CCFLAGS}
	@echo ' '
	@echo 'done.'

clean:
	/bin/rm -f $(EXE) $(CCOBJ)
