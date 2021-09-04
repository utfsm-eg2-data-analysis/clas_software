// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMiniDSTReaderDict
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
#include "TMiniDSTReader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMiniDSTReader(void *p = 0);
   static void *newArray_TMiniDSTReader(Long_t size, void *p);
   static void delete_TMiniDSTReader(void *p);
   static void deleteArray_TMiniDSTReader(void *p);
   static void destruct_TMiniDSTReader(void *p);
   static void streamer_TMiniDSTReader(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMiniDSTReader*)
   {
      ::TMiniDSTReader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMiniDSTReader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMiniDSTReader", ::TMiniDSTReader::Class_Version(), "TMiniDSTReader.h", 55,
                  typeid(::TMiniDSTReader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMiniDSTReader::Dictionary, isa_proxy, 16,
                  sizeof(::TMiniDSTReader) );
      instance.SetNew(&new_TMiniDSTReader);
      instance.SetNewArray(&newArray_TMiniDSTReader);
      instance.SetDelete(&delete_TMiniDSTReader);
      instance.SetDeleteArray(&deleteArray_TMiniDSTReader);
      instance.SetDestructor(&destruct_TMiniDSTReader);
      instance.SetStreamerFunc(&streamer_TMiniDSTReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMiniDSTReader*)
   {
      return GenerateInitInstanceLocal((::TMiniDSTReader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMiniDSTReader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMiniDSTReader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMiniDSTReader::Class_Name()
{
   return "TMiniDSTReader";
}

//______________________________________________________________________________
const char *TMiniDSTReader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTReader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMiniDSTReader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTReader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMiniDSTReader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTReader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMiniDSTReader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTReader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMiniDSTReader::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMiniDSTReader.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TVirtualReader::Streamer(R__b);
      R__b >> fEventChain;
      R__b >> fEvntHeader;
      R__b >> fPElectron;
      R__b >> fPProton;
      fcaPARTStore->Streamer(R__b);
      fcaGSIMStore->Streamer(R__b);
      R__b >> fCurrentEvent;
      R__b.CheckByteCount(R__s, R__c, TMiniDSTReader::IsA());
   } else {
      R__c = R__b.WriteVersion(TMiniDSTReader::IsA(), kTRUE);
      TVirtualReader::Streamer(R__b);
      R__b << fEventChain;
      R__b << fEvntHeader;
      R__b << fPElectron;
      R__b << fPProton;
      fcaPARTStore->Streamer(R__b);
      fcaGSIMStore->Streamer(R__b);
      R__b << fCurrentEvent;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMiniDSTReader(void *p) {
      return  p ? new(p) ::TMiniDSTReader : new ::TMiniDSTReader;
   }
   static void *newArray_TMiniDSTReader(Long_t nElements, void *p) {
      return p ? new(p) ::TMiniDSTReader[nElements] : new ::TMiniDSTReader[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMiniDSTReader(void *p) {
      delete ((::TMiniDSTReader*)p);
   }
   static void deleteArray_TMiniDSTReader(void *p) {
      delete [] ((::TMiniDSTReader*)p);
   }
   static void destruct_TMiniDSTReader(void *p) {
      typedef ::TMiniDSTReader current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMiniDSTReader(TBuffer &buf, void *obj) {
      ((::TMiniDSTReader*)obj)->::TMiniDSTReader::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMiniDSTReader

namespace {
  void TriggerDictionaryInitialization_TMiniDSTReaderDict_Impl() {
    static const char* headers[] = {
"TMiniDSTReader.h",
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
#line 1 "TMiniDSTReaderDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Example of a limited DST that takes less space (reader).)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMiniDSTReader.h")))  TMiniDSTReader;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMiniDSTReaderDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMiniDSTReader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMiniDSTReader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMiniDSTReaderDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMiniDSTReaderDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMiniDSTReaderDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMiniDSTReaderDict() {
  TriggerDictionaryInitialization_TMiniDSTReaderDict_Impl();
}
