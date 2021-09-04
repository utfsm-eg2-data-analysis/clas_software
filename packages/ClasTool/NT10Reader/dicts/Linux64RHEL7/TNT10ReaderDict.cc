// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITNT10ReaderDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "TNT10Reader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TNT10Reader(void *p = 0);
   static void *newArray_TNT10Reader(Long_t size, void *p);
   static void delete_TNT10Reader(void *p);
   static void deleteArray_TNT10Reader(void *p);
   static void destruct_TNT10Reader(void *p);
   static void directoryAutoAdd_TNT10Reader(void *obj, TDirectory *dir);
   static void streamer_TNT10Reader(TBuffer &buf, void *obj);
   static Long64_t merge_TNT10Reader(void *obj, TCollection *coll,TFileMergeInfo *info);
   static void reset_TNT10Reader(void *obj, TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNT10Reader*)
   {
      ::TNT10Reader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNT10Reader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNT10Reader", ::TNT10Reader::Class_Version(), "TNT10Reader.h", 62,
                  typeid(::TNT10Reader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNT10Reader::Dictionary, isa_proxy, 16,
                  sizeof(::TNT10Reader) );
      instance.SetNew(&new_TNT10Reader);
      instance.SetNewArray(&newArray_TNT10Reader);
      instance.SetDelete(&delete_TNT10Reader);
      instance.SetDeleteArray(&deleteArray_TNT10Reader);
      instance.SetDestructor(&destruct_TNT10Reader);
      instance.SetDirectoryAutoAdd(&directoryAutoAdd_TNT10Reader);
      instance.SetStreamerFunc(&streamer_TNT10Reader);
      instance.SetMerge(&merge_TNT10Reader);
      instance.SetResetAfterMerge(&reset_TNT10Reader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNT10Reader*)
   {
      return GenerateInitInstanceLocal((::TNT10Reader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNT10Reader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TNT10Reader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNT10Reader::Class_Name()
{
   return "TNT10Reader";
}

//______________________________________________________________________________
const char *TNT10Reader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNT10Reader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNT10Reader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNT10Reader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNT10Reader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNT10Reader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNT10Reader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNT10Reader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TNT10Reader::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNT10Reader.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TChain::Streamer(R__b);
      TVirtualReader::Streamer(R__b);
      R__b >> fEvntHeader;
      R__b >> fScalerHead;
      fcaDataPointer->Streamer(R__b);
      fcaEVNTStore->Streamer(R__b);
      fcaECPBStore->Streamer(R__b);
      fcaSCPBStore->Streamer(R__b);
      fcaDCPBStore->Streamer(R__b);
      fcaCCPBStore->Streamer(R__b);
      fcaLCPBStore->Streamer(R__b);
      fcaTGBIStore->Streamer(R__b);
      R__b >> fEvntHeaderBranch;
      R__b >> fEVNTBranch;
      R__b >> fnEVNT_Store;
      R__b >> fEVNT;
      R__b >> fECPBBranch;
      R__b >> fnECPB_Store;
      R__b >> fECPB;
      R__b >> fSCPBBranch;
      R__b >> fnSCPB_Store;
      R__b >> fSCPB;
      R__b >> fDCPBBranch;
      R__b >> fnDCPB_Store;
      R__b >> fDCPB;
      R__b >> fCCPBBranch;
      R__b >> fnCCPB_Store;
      R__b >> fCCPB;
      R__b >> fLCPBBranch;
      R__b >> fnLCPB_Store;
      R__b >> fLCPB;
      R__b >> fHbookFiles;
      R__b >> fNRun;
      R__b >> fNevents;
      R__b >> fNtLastRead;
      R__b >> fReadSequential;
      R__b >> fNtNum;
      R__b >> fHbookLun;
      R__b >> fList;
      R__b >> fKeys;
      R__b.CheckByteCount(R__s, R__c, TNT10Reader::IsA());
   } else {
      R__c = R__b.WriteVersion(TNT10Reader::IsA(), kTRUE);
      TChain::Streamer(R__b);
      TVirtualReader::Streamer(R__b);
      R__b << fEvntHeader;
      R__b << fScalerHead;
      fcaDataPointer->Streamer(R__b);
      fcaEVNTStore->Streamer(R__b);
      fcaECPBStore->Streamer(R__b);
      fcaSCPBStore->Streamer(R__b);
      fcaDCPBStore->Streamer(R__b);
      fcaCCPBStore->Streamer(R__b);
      fcaLCPBStore->Streamer(R__b);
      fcaTGBIStore->Streamer(R__b);
      R__b << fEvntHeaderBranch;
      R__b << fEVNTBranch;
      R__b << fnEVNT_Store;
      R__b << fEVNT;
      R__b << fECPBBranch;
      R__b << fnECPB_Store;
      R__b << fECPB;
      R__b << fSCPBBranch;
      R__b << fnSCPB_Store;
      R__b << fSCPB;
      R__b << fDCPBBranch;
      R__b << fnDCPB_Store;
      R__b << fDCPB;
      R__b << fCCPBBranch;
      R__b << fnCCPB_Store;
      R__b << fCCPB;
      R__b << fLCPBBranch;
      R__b << fnLCPB_Store;
      R__b << fLCPB;
      R__b << fHbookFiles;
      R__b << fNRun;
      R__b << fNevents;
      R__b << fNtLastRead;
      R__b << fReadSequential;
      R__b << fNtNum;
      R__b << fHbookLun;
      R__b << fList;
      R__b << fKeys;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNT10Reader(void *p) {
      return  p ? new(p) ::TNT10Reader : new ::TNT10Reader;
   }
   static void *newArray_TNT10Reader(Long_t nElements, void *p) {
      return p ? new(p) ::TNT10Reader[nElements] : new ::TNT10Reader[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNT10Reader(void *p) {
      delete ((::TNT10Reader*)p);
   }
   static void deleteArray_TNT10Reader(void *p) {
      delete [] ((::TNT10Reader*)p);
   }
   static void destruct_TNT10Reader(void *p) {
      typedef ::TNT10Reader current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around the directory auto add.
   static void directoryAutoAdd_TNT10Reader(void *p, TDirectory *dir) {
      ((::TNT10Reader*)p)->DirectoryAutoAdd(dir);
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TNT10Reader(TBuffer &buf, void *obj) {
      ((::TNT10Reader*)obj)->::TNT10Reader::Streamer(buf);
   }
   // Wrapper around the merge function.
   static Long64_t merge_TNT10Reader(void *obj,TCollection *coll,TFileMergeInfo *info) {
      return ((::TNT10Reader*)obj)->Merge(coll,info);
   }
   // Wrapper around the Reset function.
   static void reset_TNT10Reader(void *obj,TFileMergeInfo *info) {
      ((::TNT10Reader*)obj)->ResetAfterMerge(info);
   }
} // end of namespace ROOT for class ::TNT10Reader

namespace {
  void TriggerDictionaryInitialization_TNT10ReaderDict_Impl() {
    static const char* headers[] = {
"TNT10Reader.h",
0
    };
    static const char* includePaths[] = {
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/ClasBanks",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/TClasTool",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/VirtualReader",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/DSTReader",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/NT10Reader",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/FillBank",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/Filter",
"/usr/include/mysql",
"/user/a/alaoui/software/root/6.20.04/include/",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/NT10Reader/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TNT10ReaderDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A class for interfacing to the Monte Carlo.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TNT10Reader.h")))  TNT10Reader;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TNT10ReaderDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TNT10Reader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TNT10Reader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TNT10ReaderDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TNT10ReaderDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TNT10ReaderDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TNT10ReaderDict() {
  TriggerDictionaryInitialization_TNT10ReaderDict_Impl();
}
