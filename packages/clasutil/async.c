/*======================================================================

routine to check if there is a completed type-in entry in the
standard input device.  Asynchronous read routine checks to decide
whether to do a FORTRAN read from unit 5.  If the returned argument
bytes is greater than 0 than there is input at STDIN, and one should
attempt to read it in.

======================================================================*/

#ifdef Linux
#include <sys/ioctl.h>
#endif

#ifdef HPUX
#include <sys/ioctl.h>
#endif

#ifdef IRIX
#include <sys/ioctl.h>
#endif

#ifdef IRIX64
#include <sys/ioctl.h>
#endif

#ifdef AIX
#include <sys/ioctl.h>
#endif

#ifdef _SUNOS_SOURCE
#include <inttypes.h>
#include <sys/filio.h>
#endif

void asynck_c_(bytes)
     int *bytes;
{
  int res;

  /* check standard input device byte count */
  res = ioctl(0,FIONREAD,bytes);
  if (*bytes <= 0) *bytes = -1;

  return;
}
