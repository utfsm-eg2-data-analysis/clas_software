#ifndef bos_interface_hh 
#define bos_interface_hh 1

#include "cpp_headers.hh"
#include <ntypes.h> 
#include <bostypes.h> 

extern BOSbank bcs_;
extern BOSbank wcs_;

extern clasHEAD_t *HEAD;
extern clasMCEV_t *MCEV;
extern clasMCTK_t *MCTK;
extern clasMCVX_t *MCVX;
extern clasPART_t *PART;

extern "C" void fparm_(const char*, int);
extern "C" void fermes_(const char*,int*, int);
extern "C" void bnames_(int*); 
extern "C" void bos_(int*, int*);
extern "C" void mkfmt_(int*, const char*, const char*, int, int);
extern "C" void blist_(int*, const char*, const char*, int, int);
extern "C" int  mbank_(int*, const char*, int*, int*, int*, int);
extern "C" void fwbos_(int*, int*, const char*, int*, int);
extern "C" int  mdrop_(int*, const char*, int*, int);
extern "C" void bdrop_(int*, const char*, int);
extern "C" void bgarb_(int*);

#endif
