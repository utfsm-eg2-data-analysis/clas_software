      SUBROUTINE CC_BOOK
c
c_begin_doc
c  RCS ID string
c  $Id: cc_book.F,v 1.5 1999/06/09 19:35:30 stepanya Exp $
c
c  Documentation for subroutine CC_BOOK
c
c  Purpose:
c  --------
c
c  Input Parameters:  (Name - Type - Meaning)
c  ----------------
c
c  Output Parameters:  (Name - Type - Meaning)
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:   Alexander Vlassov    Created:  Fri Jun 13 17:00:00 EDT 1997
c  -------
c
c  Major revisions:
c  ----------------
c     
c
c_end_doc
c
      IMPLICIT NONE
      SAVE
c
c_begin_inc
c  include files :
c  ---------------------
c_end_inc
c
c_begin_var
c  input/output variables:
c  -----------------------
c
c  Local pre-defined variables:
c  ---------------------------
c  RCS information: 
      CHARACTER*132  CFILE, CREVIS, CSTATE, CDATE, CAUTHO, CRCSID
      PARAMETER (CFILE = '$RCSfile: cc_book.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.5 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1999/06/09 19:35:30 $')
      PARAMETER (CAUTHO = '$Author: stepanya $')
      DATA CRCSID/   
     1'$Id: cc_book.F,v 1.5 1999/06/09 19:35:30 stepanya Exp $'   
     2/   
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='CC_BOOK')
      PARAMETER (CRAUTH='Alexander Vlassov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
      integer nsect, nhis
c_end_var
c
c  executable code for routine CC_BOOK:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='Booking CC Histograms'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF

c Do the HMDIR stuff twice to declare the subdirectory in memory and disk

      call hcdir('//PAWC',' ')
      call hmdir('CC','S')
c  Do your HbookS below this line
c ====  Place for histogramm booking
c
c     ==============> Event histogramms for whole CLAS
c
      NHIS = 1000
c
      do nsect = 1,6
c     ==============      
      NHIS = 100*nsect
c     ==============> loop over sector number
        call hbook2(NHIS +   1,'CC  amplitude channels',
     &  50,-100.,8200.,36,0.5,36.5,0.)
        call hbook2(NHIS +   2,'CC  amplitude channels - pedestals',
     &  50,-600.,8200.,36,0.5,36.5,0.)
c
        call hbook2(NHIS +   7,' CC  amplitude - ped ',
     &  100,-100.,1000.,36,0.5,36.5,0.)
c
        call hbook2(NHIS +  11,'CC  time channels',
     &  50,-100.,8200.,36,0.5,36.5,0.)
c
      end do
c changed back to top directory
      call hcdir('//PAWC',' ')       !   Return to the initial directory
      call hcdir('//LUN2',' ')

      RETURN
      END
c
c------------------------------------------------------------------------------















