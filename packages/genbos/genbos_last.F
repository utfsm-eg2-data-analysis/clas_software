	subroutine genbos_last

c_begin_doc

c  Documentation for subroutine clas_last

c  $Id: genbos_last.F,v 1.2 1999/08/13 16:53:16 mirazita Exp $

c  Purpose:
c  --------
c     called once after geant run completed
c     closes bos output file, calls all last_xxxx routines

c  Author:
c  -------
c     Elliott Wolin, College of William and Mary, 27-jun-95

c  Major revisions:
c  ----------------

c_end_doc

      implicit none
      character*(*) crname
      parameter (crname= 'CLAS_LAST')
      save


c  include files:
c  --------------
#include "bcs.inc"
#include "control.inc"
#include "file_names.inc"
c_end_inc

c  local variables:
c  ----------------
      integer ierr,iky,mdrop
      character*100 crmess
c_end_var


c  executable code:
c  ----------------


C *** if no BOS outfile
	if(no_bos_out) return

c  write end run record and close BOS event output file
c  EOR record

         iky=mdrop(iw,'+KYE',0)
         call bos_head(20,0,0)     !class 20 is EOR, event number is 0
         call genbos_out
         call bdrop(iw,'E')
         call bgarb(iw)
c  close file
         call fwbos(iw,gsimout_unit,'0',ierr)
         if(ierr.ne.0)then
            write(crmess,
     1           '(''?unable to write last bos record, ierr is '',i4)')
     1           ierr
c         print *,' call recmes(crname,I',crmess
            call recmes(crname,'I',crmess)
         endif
         call fparm('CLOSE '//gsimout_daname)
          print *,'call recmes(crname,I',
     1        'closing BOS output file stream ',gsimout_daname
         call recmes(crname,'I',
     1        'closing BOS output file stream '//gsimout_daname)
C      endif


      return
      end

c------------------------------------------------------------------------
