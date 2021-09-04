#include <stdio.h>
#include "ntypes.h"
#include "bostypes.h"
#include "map_manager.h"

int get_code_type_(int* runno) {
  int value[1];
  int firsttime;
  char mapname[255];
  sprintf(mapname,"%s/Maps/STN_CALIB.map",getenv("CLAS_PARMS"));
  int status = map_get_int(mapname, "code_type", "value", 1, 
			   value, *runno, &firsttime);
  if (status != 0) return -1;
  return value[0];
}

