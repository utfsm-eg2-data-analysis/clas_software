// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMiniDSTWriterDict
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
#include "TMiniDSTWriter.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMiniDSTWriter(void *p = 0);
   static void *newArray_TMiniDSTWriter(Long_t size, void *p);
   static void delete_TMiniDSTWriter(void *p);
   static void deleteArray_TMiniDSTWriter(void *p);
   static void destruct_TMiniDSTWriter(void *p);
   static void streamer_TMiniDSTWriter(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMiniDSTWriter*)
   {
      ::TMiniDSTWriter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMiniDSTWriter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMiniDSTWriter", ::TMiniDSTWriter::Class_Version(), "TMiniDSTWriter.h", 27,
                  typeid(::TMiniDSTWriter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMiniDSTWriter::Dictionary, isa_proxy, 16,
                  sizeof(::TMiniDSTWriter) );
      instance.SetNew(&new_TMiniDSTWriter);
      instance.SetNewArray(&newArray_TMiniDSTWriter);
      instance.SetDelete(&delete_TMiniDSTWriter);
      instance.SetDeleteArray(&deleteArray_TMiniDSTWriter);
      instance.SetDestructor(&destruct_TMiniDSTWriter);
      instance.SetStreamerFunc(&streamer_TMiniDSTWriter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMiniDSTWriter*)
   {
      return GenerateInitInstanceLocal((::TMiniDSTWriter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMiniDSTWriter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMiniDSTWriter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMiniDSTWriter::Class_Name()
{
   return "TMiniDSTWriter";
}

//______________________________________________________________________________
const char *TMiniDSTWriter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTWriter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMiniDSTWriter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTWriter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMiniDSTWriter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTWriter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMiniDSTWriter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTWriter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMiniDSTWriter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMiniDSTWriter.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fDSTFile;
      R__b >> fEventTree;
      R__b >> fEventHeader;
      fcaPARTStore->Streamer(R__b);
      fcaGSIMStore->Streamer(R__b);
      R__b >> fbElectron;
      R__b >> fbProton;
      R__b >> nPARTStore;
      R__b >> nGSIMStore;
      R__b >> fCompression;
      R__b >> brHeader;
      R__b >> brPART;
      R__b >> brGSIM;
      R__b >> brElectron;
      R__b >> brProton;
      R__b.CheckByteCount(R__s, R__c, TMiniDSTWriter::IsA());
   } else {
      R__c = R__b.WriteVersion(TMiniDSTWriter::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fDSTFile;
      R__b << fEventTree;
      R__b << fEventHeader;
      fcaPARTStore->Streamer(R__b);
      fcaGSIMStore->Streamer(R__b);
      R__b << fbElectron;
      R__b << fbProton;
      R__b << nPARTStore;
      R__b << nGSIMStore;
      R__b << fCompression;
      R__b << brHeader;
      R__b << brPART;
      R__b << brGSIM;
      R__b << brElectron;
      R__b << brProton;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMiniDSTWriter(void *p) {
      return  p ? new(p) ::TMiniDSTWriter : new ::TMiniDSTWriter;
   }
   static void *newArray_TMiniDSTWriter(Long_t nElements, void *p) {
      return p ? new(p) ::TMiniDSTWriter[nElements] : new ::TMiniDSTWriter[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMiniDSTWriter(void *p) {
      delete ((::TMiniDSTWriter*)p);
   }
   static void deleteArray_TMiniDSTWriter(void *p) {
      delete [] ((::TMiniDSTWriter*)p);
   }
   static void destruct_TMiniDSTWriter(void *p) {
      typedef ::TMiniDSTWriter current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMiniDSTWriter(TBuffer &buf, void *obj) {
      ((::TMiniDSTWriter*)obj)->::TMiniDSTWriter::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMiniDSTWriter

namespace {
  void TriggerDictionaryInitialization_TMiniDSTWriterDict_Impl() {
    static const char* headers[] = {
"TMiniDSTWriter.h",
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
#line 1 "TMiniDSTWriterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Example of a limited DST that takes less space (writer).)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMiniDSTWriter.h")))  TMiniDSTWriter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMiniDSTWriterDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMiniDSTWriter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMiniDSTWriter", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMiniDSTWriterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMiniDSTWriterDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMiniDSTWriterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMiniDSTWriterDict() {
  TriggerDictionaryInitialization_TMiniDSTWriterDict_Impl();
}
