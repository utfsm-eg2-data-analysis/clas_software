#
# The "lib" and "exe" targets are required by the make system 
#

FORCE = DUMMY
ifndef OS_NAME
 OS_NAME = $(shell $(CLAS_CMS)/uname_clas)
endif

DUMMY :

lib:

#exe: countbos_dir bosdump_dir_lepto root2bos_dir_genie
#bosdump_dir:
#	cd bosdump; $(MAKE)
#countbos_dir:
#	cd countbos; $(MAKE)
#root2bos_dir:
#	cd root2bos; $(MAKE)
#%.dir:
#	$(MAKE) -C $* exe

SUBDIRS = countbos bosdump root2bos_lepto root2bos_genie

exe:
	for dir in $(SUBDIRS); do \
	make -C $$dir; \
	done;

clean:
	for dir in $(SUBDIRS); do make -C $$dir clean; done;

#exe:
#	for dir in $(SUBDIRS); do \
#	cd $(SUBDIRS); $(MAKE); done;
#
#clean:
#	for dir in $(SUBDIRS); do \
#	cd $(SUBDIRS); make clean; done;

# end of makefile
