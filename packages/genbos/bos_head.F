      subroutine bos_head(class,run,event)

c_begin_doc

c  Documentation for subroutine bos_head

c  Purpose:
c  --------
c	creates bos HEAD bank

c  input:
c  ------
c     class     event class 
c     run       run number
c     event     event number

c  Author:
c  -------
c     Elliott Wolin, College of William and Mary, 30-jun-95

c  Major revisions:
c  ----------------
c_end_doc


      implicit none
      save


c  include files:
c  --------------
#include "bcs.inc"
c_end_inc

c  input/output variables:
c  -----------------------
      integer class,run,event

c  local variables:
c   ----------------
      integer nbank,head,unixtime
c_end_var


c  executable code:
c  ----------------

      call getunixtime(unixtime)
c fill bos banks...fpack wants the head bank to be number 0
      head=nbank('HEAD',0,8,1)
      iw(head+ 1) = 2                   !version of event format
      iw(head+ 2) = run                 !run number
      iw(head+ 3) = event               !event number
      iw(head+ 4) = 0            !32 bit unix time
      iw(head+ 5) = -2                  !geant
      iw(head+ 6) = 0                   !ROC status
      iw(head+ 7) = class               !event class
      iw(head+ 8) = 1                   !prescale factor

      return
      end

c------------------------------------------------------------------------

