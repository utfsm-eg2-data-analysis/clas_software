// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITDSTWriterDict
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
#include "TDSTWriter.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TDSTWriter(void *p = 0);
   static void *newArray_TDSTWriter(Long_t size, void *p);
   static void delete_TDSTWriter(void *p);
   static void deleteArray_TDSTWriter(void *p);
   static void destruct_TDSTWriter(void *p);
   static void streamer_TDSTWriter(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDSTWriter*)
   {
      ::TDSTWriter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDSTWriter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDSTWriter", ::TDSTWriter::Class_Version(), "TDSTWriter.h", 70,
                  typeid(::TDSTWriter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDSTWriter::Dictionary, isa_proxy, 16,
                  sizeof(::TDSTWriter) );
      instance.SetNew(&new_TDSTWriter);
      instance.SetNewArray(&newArray_TDSTWriter);
      instance.SetDelete(&delete_TDSTWriter);
      instance.SetDeleteArray(&deleteArray_TDSTWriter);
      instance.SetDestructor(&destruct_TDSTWriter);
      instance.SetStreamerFunc(&streamer_TDSTWriter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDSTWriter*)
   {
      return GenerateInitInstanceLocal((::TDSTWriter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDSTWriter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDSTWriter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDSTWriter::Class_Name()
{
   return "TDSTWriter";
}

//______________________________________________________________________________
const char *TDSTWriter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDSTWriter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDSTWriter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDSTWriter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDSTWriter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDSTWriter.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fDSTFile;
      R__b >> fEventTree;
      fcaPARTStore->Streamer(R__b);
      R__b >> nPARTStore;
      R__b >> fCompression;
      EVNTStore->Streamer(R__b);
      ECPBStore->Streamer(R__b);
      SCPBStore->Streamer(R__b);
      DCPBStore->Streamer(R__b);
      CCPBStore->Streamer(R__b);
      ICPBStore->Streamer(R__b);
      ICHBStore->Streamer(R__b);
      FBPMStore->Streamer(R__b);
      LCPBStore->Streamer(R__b);
      STPBStore->Streamer(R__b);
      TGPBStore->Streamer(R__b);
      TAGRStore->Streamer(R__b);
      VERTStore->Streamer(R__b);
      MVRTStore->Streamer(R__b);
      TBERStore->Streamer(R__b);
      TGBIStore->Streamer(R__b);
      GSIMStore->Streamer(R__b);
      R__b >> brHeader;
      R__b >> brPART;
      R__b >> brElectron;
      R__b >> brProton;
      fClones.Streamer(R__b);
      fScalerClones.Streamer(R__b);
      R__b >> hHEADER;
      R__b >> HEADERBranch;
      R__b >> EVNTBranch;
      R__b >> nEVNT_Store;
      R__b >> ECPBBranch;
      R__b >> nECPB_Store;
      R__b >> SCPBBranch;
      R__b >> nSCPB_Store;
      R__b >> DCPBBranch;
      R__b >> nDCPB_Store;
      R__b >> CCPBBranch;
      R__b >> nCCPB_Store;
      R__b >> ICPBBranch;
      R__b >> nICPB_Store;
      R__b >> ICHBBranch;
      R__b >> nICHB_Store;
      R__b >> FBPMBranch;
      R__b >> nFBPM_Store;
      R__b >> LCPBBranch;
      R__b >> nLCPB_Store;
      R__b >> STPBBranch;
      R__b >> nSTPB_Store;
      R__b >> TGPBBranch;
      R__b >> nTGPB_Store;
      R__b >> TAGRBranch;
      R__b >> nTAGR_Store;
      R__b >> VERTBranch;
      R__b >> nVERT_Store;
      R__b >> MVRTBranch;
      R__b >> nMVRT_Store;
      R__b >> TBERBranch;
      R__b >> nTBER_Store;
      R__b >> TGBIBranch;
      R__b >> nTGBI_Store;
      R__b >> GSIMBranch;
      R__b >> nGSIM_Store;
      R__b.CheckByteCount(R__s, R__c, TDSTWriter::IsA());
   } else {
      R__c = R__b.WriteVersion(TDSTWriter::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fDSTFile;
      R__b << fEventTree;
      fcaPARTStore->Streamer(R__b);
      R__b << nPARTStore;
      R__b << fCompression;
      EVNTStore->Streamer(R__b);
      ECPBStore->Streamer(R__b);
      SCPBStore->Streamer(R__b);
      DCPBStore->Streamer(R__b);
      CCPBStore->Streamer(R__b);
      ICPBStore->Streamer(R__b);
      ICHBStore->Streamer(R__b);
      FBPMStore->Streamer(R__b);
      LCPBStore->Streamer(R__b);
      STPBStore->Streamer(R__b);
      TGPBStore->Streamer(R__b);
      TAGRStore->Streamer(R__b);
      VERTStore->Streamer(R__b);
      MVRTStore->Streamer(R__b);
      TBERStore->Streamer(R__b);
      TGBIStore->Streamer(R__b);
      GSIMStore->Streamer(R__b);
      R__b << brHeader;
      R__b << brPART;
      R__b << brElectron;
      R__b << brProton;
      fClones.Streamer(R__b);
      fScalerClones.Streamer(R__b);
      R__b << hHEADER;
      R__b << HEADERBranch;
      R__b << EVNTBranch;
      R__b << nEVNT_Store;
      R__b << ECPBBranch;
      R__b << nECPB_Store;
      R__b << SCPBBranch;
      R__b << nSCPB_Store;
      R__b << DCPBBranch;
      R__b << nDCPB_Store;
      R__b << CCPBBranch;
      R__b << nCCPB_Store;
      R__b << ICPBBranch;
      R__b << nICPB_Store;
      R__b << ICHBBranch;
      R__b << nICHB_Store;
      R__b << FBPMBranch;
      R__b << nFBPM_Store;
      R__b << LCPBBranch;
      R__b << nLCPB_Store;
      R__b << STPBBranch;
      R__b << nSTPB_Store;
      R__b << TGPBBranch;
      R__b << nTGPB_Store;
      R__b << TAGRBranch;
      R__b << nTAGR_Store;
      R__b << VERTBranch;
      R__b << nVERT_Store;
      R__b << MVRTBranch;
      R__b << nMVRT_Store;
      R__b << TBERBranch;
      R__b << nTBER_Store;
      R__b << TGBIBranch;
      R__b << nTGBI_Store;
      R__b << GSIMBranch;
      R__b << nGSIM_Store;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDSTWriter(void *p) {
      return  p ? new(p) ::TDSTWriter : new ::TDSTWriter;
   }
   static void *newArray_TDSTWriter(Long_t nElements, void *p) {
      return p ? new(p) ::TDSTWriter[nElements] : new ::TDSTWriter[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDSTWriter(void *p) {
      delete ((::TDSTWriter*)p);
   }
   static void deleteArray_TDSTWriter(void *p) {
      delete [] ((::TDSTWriter*)p);
   }
   static void destruct_TDSTWriter(void *p) {
      typedef ::TDSTWriter current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDSTWriter(TBuffer &buf, void *obj) {
      ((::TDSTWriter*)obj)->::TDSTWriter::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDSTWriter

namespace {
  void TriggerDictionaryInitialization_TDSTWriterDict_Impl() {
    static const char* headers[] = {
"TDSTWriter.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/DSTReader/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TDSTWriterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Example of a limited DST that takes less space (writer).)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TDSTWriter.h")))  TDSTWriter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TDSTWriterDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TDSTWriter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TDSTWriter", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TDSTWriterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TDSTWriterDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TDSTWriterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TDSTWriterDict() {
  TriggerDictionaryInitialization_TDSTWriterDict_Impl();
}
