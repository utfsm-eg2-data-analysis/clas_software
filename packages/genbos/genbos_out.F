      subroutine genbos_out

c_begin_doc

c  Documentation for subroutine bos_out

c  $Id: genbos_out.F,v 1.2 1999/08/13 16:53:16 mirazita Exp $

c  Purpose:
c  --------
c     writes out bos banks

c  Author:
c  -------
c     Elliott Wolin, College of William and Mary, 28-sep-95

c  Major revisions:
c  ----------------

c_end_doc


      implicit none
      character*(*) crname
      parameter (crname= 'BOS_OUT')
      save


c  include files:
c  --------------
#include "file_names.inc"
#include "bcs.inc"
c_end_inc

c  local variables:
c   ----------------
      integer iret
      character*120 crmess
c_end_var


c  executable code:
c  ----------------

c  write bos data
      call fwbos(iw,gsimout_unit,'E',iret)
      if(iret.ne.0)then
         write(crmess,'(''?unable to write bos record, iret is '',i4)')
     1        iret
         call recmes(crname,'I',crmess)
c         print *,'call recmes(crname,I',crmess
      endif

c  drop and remove event banks
      call bdrop(iw,'E')
      call bgarb(iw)
      return
      end

c------------------------------------------------------------------------

