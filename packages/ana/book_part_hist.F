      SUBROUTINE BOOK_PART_HIST
c
c_begin_doc
c  RCS ID string
c  $Id: book_part_hist.F,v 1.14 2005/10/06 14:44:19 clasdvcs Exp $
c
c  Documentation for subroutine BOOK_PART_HIST
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
c  Author:         Created:  Wed Jun 11 00:13:56 EDT 1997
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
c BOS common block  uncomment the next line for BOS include file
c#include "bcs.inc"
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
      PARAMETER (CFILE = '$RCSfile: book_part_hist.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.14 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 2005/10/06 14:44:19 $')
      PARAMETER (CAUTHO = '$Author: clasdvcs $')
      DATA CRCSID/ 
     +'$Id: book_part_hist.F,v 1.14 2005/10/06 14:44:19 clasdvcs Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='BOOK_PART_HIST')
      PARAMETER (CRAUTH='whoistheauthor')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE,i
      CHARACTER*3 si(0:6)
      data si/' ','S1','S2','S3','S4','S5','S6'/
c_end_var
c
c  executable code for routine BOOK_PART_HIST:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='This is a DUMMY routine, this message written once'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
      write(6,*)'Booking seb histos'
c
       call hbook1(3101,'Corrected RF time',500,0.,250.,0.)
       call hbook1(3102,'RF offsets',150,-1.5,1.5,0.)
       call hbook1(3103,'RF ',1000,-0.,210.,0.)
       call hbook1(3104,'RF offsets for triggers',150,-1.5,1.5,0.)
       call hbook2(3105,'RF new  vs RF old',100,0.,100.,100,0.,250.,0.)
       call hbook2(3111,'RF offsets vs RF',100,0.,250.,100,-1.,1.,0.)
       call hbook2(3112,'RF offsets vs Z?v!',100,-1.,1.,100,
     +   -120.,-80.,0.)
c
       call hbook2(3201,'Raster x.vs.y',200,0.,8200,200,0.,8200.,0.)
       call hbook1(3211,'Raster x',200,0.,8200,0.)
       call hbook1(3212,'Raster y',200,0.,8200,0.)
c
       call hbook1(3301,'Trigger Bits',200,0.,200.,0.)
       call hbook1(3302,'Helicity',4,-1.,3.,0.)
       call hbook1(3303,'True Helicity',4,-1.,3.,0.)
c
       call hbook1(6041,'Electron Z vertex',100,-140.,-60.,0.)
       call hbook1(6042,'Hadron Z vertex'  ,100,-140.,-60.,0.)
       call hbook2(6043,'Electron Z vertex',100,-140.,-60.,90,
     +   -30.,330.,0.)
       call hbook2(6044,'Hadron Z vertex'  ,100,-140.,-60.,90,
     +   -30.,330.,0.)
c
       call hbook1(6051,'MVRT X vertex',100,-10.,10.,0.)
       call hbook1(6052,'MVRT Y vertex',100,-10.,10.,0.)
       call hbook2(6053,'MVRT X vs. Y vertex',100,-10.,10.,100,
     +   -10.,10.,0.0)
c
       call hbook1(6100,'TOF mass',200,0.,4.,0.0)
       call hbook1(6110,'dt prot',200,-6.,6.,0.0)
       call hbook1(6120,'dt [p]+',200,-6.,6.,0.0)
       call hbook1(6130,'dt [p]-',200,-6.,6.,0.0)
       do i=6101,6106
         call hbook2(i,si(i-6100)//'M vs PD',50,0.,50.,70,-0.1,1.3,0.0)
         call hbook2(i+10,si(i-6100)//'dt vs PD prot',50,0.,50.,
     +     100,-6.,6.,0.0)
         call hbook2(i+20,si(i-6100)//'dt vs PD [p]+',50,0.,50.,
     +     100,-6.,6.,0.0)
         call hbook2(i+30,si(i-6100)//'dt vs PD [p-',50,0.,50.,
     +     100,-6.,6.,0.0)
         call hbook2(i-2980,si(i-6100)//'RF offsets vs PD',75,
     +     -1.5,1.5,50,0.,50.,0.)
         call hbook2(i+100,si(i-6100)//'p vs [q], h^+!',50,0.,3.,
     +     60,5.,125.,0.0)
         call hbook2(i+110,si(i-6100)//'p vs [q], h^-!',50,0.,3.,
     +     60,5.,125.,0.0)
         call hbook1(i+120,si(i-6100)//'SC?PD!, h^-!',50,0.,50.,0.0)
         call hbook1(i+130,si(i-6100)//'SC?PD!, h^-!',50,0.,50.,0.0)
       enddo
c
       call hbook1(6300,'E?EC!/P',100,0.,0.5,0.)
       call hbook2(6310,'dE/dX vs P pos',50,0.1,2.1,50,0.,200.,0.)
       do i=6301,6306
         call hbook2(i,si(i-6300)//'E?EC!/P vs P',55,0.2,5.7,
     +     50,0.,0.5,0.)
         call hbook2(i+10,si(i-6300)//'dE/dX vs P',50,0.1,2.1,50,
     +     0.,200.,0.)
       enddo
       call hbook1(6500,'CC sector',6,1.,7.,0.)
       do i=6501,6506
         call hbook1(i,si(i-6500)//'CC segment',160,-20.,20.,0.)
         call hbook1(i+10,si(i-6500)//'CC ph.e.',100,0.,400.,0.)
         call hbook2(i+20,si(i-6500)//'CC ph.e. vs [D]E/p',25,0.,
     +     0.5,50,0.,400.,0.)
         call hbook1(i+30,si(i-6500)//'CCt-SCt',200,-5.,5.,0.)
         call hbook2(i+40,si(i-6500)//'CCt-SCt vs. CC Pmt',40,0.,
     +     40.,200,-5.,5.,0.)
       enddo
c
       call hbook1(6600,'ECt-SCt, electrons',200,-2.,2.,0.)
       call hbook1(6620,'Beta for neutrals', 200,0.,2.,0.)
       do i=6601,6606
         call hbook1(i,si(i-6600)//'ECt-SCt, electrons',200,-2.,2.,0.)
         call hbook2(i+40,si(i-6600)//'ECt-SCt, electrons',25,0.,25.,
     +     100,-2.,2.,0.)
         call hbook1(i+10,si(i-6600)//'ECt-SCt, protons',200,-5.,5.,0.)
         call hbook1(i+20,si(i-6600)//'Beta for neutrals',200,0.,2.,0.)
         call hbook2(i+30,si(i-6600)//'E?EC! vs Beta for neutrals',
     +     200,0.,2.,100,0.,1.,0.)
       enddo
c
c+  Invariant and Missing Mass spectra
c-  Inclusive W Spectra
       call hbook1(10000,'W(e)',200,0.5,2.5,0.0)
       call hbook1(10011,'W(e) h+',200,0.5,2.5,0.0)
       call hbook1(10012,'W(e) h-',200,0.5,2.5,0.0)
       do i=10001,10006
          call hbook1(i,si(i-10000)//'W(e)',200,0.5,2.5,0.0)
       enddo
c-  Elastic 
       call hbook1(10101,'M?X!^2!(ep"L#epX)',120,-0.2,0.2,0.0)
       call hbook1(10102,'abs([f]?e!-[f]?p!)',120,120,240,0.0)
c-  Single Pion       
       call hbook1(10201,'M?X!^2!(ep"L#epX)',120,-0.1,0.6,0.0)
       call hbook1(10202,'M?X!(ep"L#e[p]^+!X)',120,0.5,1.7,0.0)
c-  Photon
       call hbook1(10300,'M?[gg]!(GeV)',200,0.,0.8,0.)
       call hbook1(10310,'M?X!^2!(ep"L#enX) (GeV)',200,-0.2,1.2,0.)
       do i=10301,10306
         call hbook1(i   ,si(i-10300)//'M?[gg]!(GeV)',200,0.,0.8,0.)
       enddo

      RETURN
      END
c
c-----------------------------------------------------------------------
