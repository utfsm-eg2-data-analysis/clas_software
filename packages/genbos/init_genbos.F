      subroutine init_genbos

c_begin_doc

c  Documentation for subroutine init_bos

c  $Id: init_genbos.F,v 1.2 1999/08/13 16:53:17 mirazita Exp $

c  Purpose:
c  --------
c     initializes bos banks and opens output file (if requested)

c  Author:
c  -------
c     Created  22 June 1995 E.Doroshkevich

c  Major revisions:
c  ----------------
c     Elliott Wolin, College of William and Mary, 30-jun-95
c_end_doc


      implicit none
      character*(*) crname
      parameter (crname= 'INIT_BOS')
      save


c  include files:
c  --------------
#include "control.inc"
#include "bcs.inc"
#include "file_names.inc"

c_end_inc

c  local variables:
c  ----------------
      integer iflag
      logical lerr,accessf
      integer iret,lenocc
      character*8 cunit
      character*200 crmess
c_end_var

C *** marco
C *** modifica del nome del file
	integer kk

c  executable code:
c  ----------------


      call BOS(IW,50000)


c     print*,'init_bos: will call bkfmt'

c  set the format for all banks
      call bkfmt('HEAD','I')
      call bkfmt('MCEV','I')
      call bkfmt('MCVX','4F,I')        ! TEST BANKS 
      call bkfmt('MCTK','6F,5I')
      call bkfmt('TAGR','3F,3I')       ! Tagger bank format (federico)
c  create list of banks 
      call blist(iw,'E=','HEAD')
      call blist(iw,'E+','MCEV')
      call blist(iw,'E+','MCVX')
      call blist(iw,'E+','MCTK')
      call blist(iw,'E+','TAGR')       ! Tagger bank creation (federico)


c  open output file, if requested
c      if(nobosout(all))return

c  get fortran unit
      call reslun(crname,gsimout_unit,iret)
      if(iret.eq.-1)call recmes(crname,'F',
     1     '?unable to reserve fortran unit')
      write(cunit,'(i8)')gsimout_unit

       gsimout_daname='genbos'
       gsimout_filename='out_bos_0.evt'
       file_nt='out_nt_0.rzn'
       file_log='out_log_0.log'

c  if file already exists, rename the old one with a new version number
	kk=0
        
5	kk=kk+1
 
      if( (accessf(gsimout_filename,0))
     +       .or.(accessf(file_nt,0)) )then
         if (kk.gt.9) then
            kk = kk - 1
            goto 6
          endif
	  write (unit=gsimout_filename,fmt='(a8,i1,a4)')
     +		'out_bos_',kk,'.evt'
	  write (unit=file_nt,fmt='(a7,i1,a4)')
     +		'out_nt_',kk,'.rzn'
	  write (unit=file_log,fmt='(a8,i1,a4)')
     +		'out_log_',kk,'.log'

	  go to 5
      endif
     
 6    kk=kk+1                      ! Ronchetti: Add files with different 
                                   ! version numbers up to 99 
      if( (accessf(gsimout_filename,0))
     +       .or.(accessf(file_nt,0)) ) then
          
          if (kk.ge.99) then 
             print *,'********************** Run stopped'
             print *,'********************** Please delete some files'
             stop
          endif
	  write (unit=gsimout_filename,fmt='(a8,i2,a4)')
     +		'out_bos_',kk,'.evt'
	  write (unit=file_nt,fmt='(a7,i2,a4)')
     +		'out_nt_',kk,'.rzn'
	  write (unit=file_log,fmt='(a8,i2,a4)')
     +		'out_log_',kk,'.log'

	  go to 6
      endif


      print *,'-------------------------------'
      if (.not.no_bos_out)
     +     write (*,'(20a)') ' BOS file name: ',gsimout_filename
      if (.not.no_nt_out)
     +     write (*,'(20a)') ' CWN file name: ',file_nt
      write (*,'(20a)') ' LOG file name: ',file_log
      print *,'-------------------------------'

C *** if no BOS outfile
      if (no_bos_out) return

c  *** open file
         write(crmess,'(''opening BOS output file on unit: '',i2,
     1        '', filename: '',a,'', daname: '',a)')
     1        gsimout_unit,gsimout_filename(1:lenocc(gsimout_filename)),
     1        gsimout_daname(1:lenocc(gsimout_daname))
         call recmes(crname,'I',crmess)
c          print *,'call recmes(crname,',crmess,'1111',crname

         call fparm(
     1     ' OPEN '//gsimout_daname(1:lenocc(gsimout_daname))//
     1     ' UNIT='//cunit//
     1     ' FILE="'//
     1          gsimout_filename(1:lenocc(gsimout_filename))//'"'//
     1     ' RECL=32760 ACTION=WRITE STATUS=NEW FORM=BINARY')

c  stop if error opening file
         call fermes(crmess,1)
         if(lenocc(crmess).gt.0)call recmes(crname,'F',
     1        '?FPARM: '//crmess)
c         print *,"call recmes(crname,",crmess,'2222',crname
         call fermes(crmess,0)
c         print *,"call recmes(crname,",crmess,'3333',crname
         call recmes(crname,'I',
     1        'FPARM: '//crmess)

      return
      end


