c  gsimout.inc

c  $Id: file_names.inc,v 1.2 1999/08/13 16:53:16 mirazita Exp $

      character*132 cigsimout
      data cigsimout/
     1'$Id: file_names.inc,v 1.2 1999/08/13 16:53:16 mirazita Exp $'
     1/

	integer gsimout_unit
	character*120 gsimout_filename,gsimout_daname,file_nt,file_log

      	common/gsimout/gsimout_unit,gsimout_filename,
     1      gsimout_daname,file_nt,file_log


