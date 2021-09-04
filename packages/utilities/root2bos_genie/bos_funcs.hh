#ifndef bos_funcs_hh
#define bos_funcs_hh 1

#include "cpp_headers.hh"
#include "bos_interface.hh"
#include "dvect.hh"

int  open_wbos(int, string);
void init_bos();
void map_banks();
void bankList(BOSbank*, string, string);
void *makeBank(BOSbank*,string,int,int,int);
void fill_header(clasHEAD_t*,int);
void fill_part(clasPART_t*, int, dvec, double, int, int);
void fill_mctk(clasMCTK_t*, int, dvec, double, int, int);
void fill_mcvx(clasMCVX_t*, int, double, double, double, double);
int  putBOS(BOSbank*, int, string);
void *dropBank(BOSbank*, string, int);
void dropAllBanks(BOSbank*, string);
void cleanBanks(BOSbank*);
int  close_bos(int);

#endif
