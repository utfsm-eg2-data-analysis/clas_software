      SUBROUTINE FILL_MC_NT(ierr)
c     
c     _begin_doc
c     RCS ID string
c     $Id: fill_mc_nt.F,v 1.6 2004/04/20 19:29:38 clasdvcs Exp $
c     
c     Documentation for subroutine FILL_MC_NT
c     
c     Purpose:
c     --------
c     
c     Input Parameters:  NON
c     ----------------
c     
c     Output Parameters:  NON
c     -----------------
c     
c     Other routines:
c     ---------------
c     
c     Notes:
c     ------
c     
c     Author:    Stepan     Created:  Tue Mar  4 16:49:27 EST 1997
c     -------
c     
c     Major revisions:
c     ----------------
c     
c     
c     _end_doc
c     
      IMPLICIT NONE
      SAVE
c     
c     _begin_inc
c     include files :
c     ---------------------
c     BOS common block  uncomment the next line for BOS include file
#include "bcs.inc"
#include "mc_nt.inc"
c     _end_inc
c     
c     _begin_var
c     input/output variables:
c     -----------------------
c     
c     Local pre-defined variables:
c     ---------------------------
c     RCS information: 
      CHARACTER*132  CFILE, CREVIS, CSTATE, CDATE, CAUTHO, CRCSID
      PARAMETER (CFILE = '$RCSfile: fill_mc_nt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.6 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 2004/04/20 19:29:38 $')
      PARAMETER (CAUTHO = '$Author: clasdvcs $')
      DATA CRCSID/ 
     +'$Id: fill_mc_nt.F,v 1.6 2004/04/20 19:29:38 clasdvcs Exp $'/
c     Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='FILL_MC_NT')
      PARAMETER (CRAUTH='whoistheauthor')
c     
c     Local User defined variables:
c     -----------------------------
      INTEGER NWRITE
      INTEGER MAMIND,ierr
      INTEGER nameindex,nameind
      DATA nameindex,nameind/0,0/
      INTEGER nwords
      INTEGER ind, indx, j, ind1,indx1
      REAL cx,cy,cz,char
      real pi
      DATA pi/3.141592654/
c     _end_var
c     
c     executable code for routine FILL_MC_NT:
c---- 6----------------------------------------------------------------72
c     
      IF (NWRITE .LT. 1) THEN
         NWRITE = NWRITE + 1
         CRMESS='This is a DUMMY routine, this message written once'
         CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
      if(nameindex.eq.0)nameindex=MAMIND(IW,'MCTK')
      ind=IW(nameindex)
      if(nameind.eq.0)nameind=MAMIND(IW,'MCVX')
      ind1=IW(nameind)
      mcnentr=0
      if(ind.gt.0)then
         nwords=IW(ind)
         mcnpart=0 
         do j=1,nwords,11
            indx=ind+j-1
            mcnentr=mcnentr+1
            cx = rw(indx+1) 
            cy = rw(indx+2) 
            cz = rw(indx+3)
            mcp(mcnentr)   = rw(indx+4)
            mcm(mcnentr)   = rw(indx+5)
            char=rw(indx+6)
            mcid(mcnentr)  = iw(indx+7)
            mcst(mcnentr)  = iw(indx+8)
            mcpid(mcnentr) = iw(indx+11)
            if(mcst(mcnentr).lt.10)then
               mcnpart=mcnpart+1
            endif
            mctheta(mcnentr) = acos(cz)*180./pi
            mcphi(mcnentr)   = atan2(cy,cx)*180./pi
            if(mcphi(mcnentr).lt.0.)mcphi(mcnentr)=360+mcphi(mcnentr) 
c MCVX corresponding hits
            indx1=ind1+(mcnentr-1)*5
            mcvx(mcnentr) = rw(indx1+1) 
            mcvy(mcnentr) = rw(indx1+2) 
            mcvz(mcnentr) = rw(indx1+3)
         enddo
      endif
      ierr=mcnentr   
c
      RETURN
      END
c
c------------------------------------------------------------------------------




