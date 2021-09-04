// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITInterruptDict
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
#include "TInterrupt.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TInterrupt(void *p = 0);
   static void *newArray_TInterrupt(Long_t size, void *p);
   static void delete_TInterrupt(void *p);
   static void deleteArray_TInterrupt(void *p);
   static void destruct_TInterrupt(void *p);
   static void streamer_TInterrupt(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TInterrupt*)
   {
      ::TInterrupt *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TInterrupt >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TInterrupt", ::TInterrupt::Class_Version(), "TInterrupt.h", 10,
                  typeid(::TInterrupt), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TInterrupt::Dictionary, isa_proxy, 16,
                  sizeof(::TInterrupt) );
      instance.SetNew(&new_TInterrupt);
      instance.SetNewArray(&newArray_TInterrupt);
      instance.SetDelete(&delete_TInterrupt);
      instance.SetDeleteArray(&deleteArray_TInterrupt);
      instance.SetDestructor(&destruct_TInterrupt);
      instance.SetStreamerFunc(&streamer_TInterrupt);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TInterrupt*)
   {
      return GenerateInitInstanceLocal((::TInterrupt*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TInterrupt*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TInterrupt::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TInterrupt::Class_Name()
{
   return "TInterrupt";
}

//______________________________________________________________________________
const char *TInterrupt::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TInterrupt*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TInterrupt::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TInterrupt*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TInterrupt::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TInterrupt*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TInterrupt::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TInterrupt*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TInterrupt::Streamer(TBuffer &R__b)
{
   // Stream an object of class TInterrupt.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TSignalHandler::Streamer(R__b);
      R__b >> NumSig;
      R__b.CheckByteCount(R__s, R__c, TInterrupt::IsA());
   } else {
      R__c = R__b.WriteVersion(TInterrupt::IsA(), kTRUE);
      TSignalHandler::Streamer(R__b);
      R__b << NumSig;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TInterrupt(void *p) {
      return  p ? new(p) ::TInterrupt : new ::TInterrupt;
   }
   static void *newArray_TInterrupt(Long_t nElements, void *p) {
      return p ? new(p) ::TInterrupt[nElements] : new ::TInterrupt[nElements];
   }
   // Wrapper around operator delete
   static void delete_TInterrupt(void *p) {
      delete ((::TInterrupt*)p);
   }
   static void deleteArray_TInterrupt(void *p) {
      delete [] ((::TInterrupt*)p);
   }
   static void destruct_TInterrupt(void *p) {
      typedef ::TInterrupt current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TInterrupt(TBuffer &buf, void *obj) {
      ((::TInterrupt*)obj)->::TInterrupt::Streamer(buf);
   }
} // end of namespace ROOT for class ::TInterrupt

namespace {
  void TriggerDictionaryInitialization_TInterruptDict_Impl() {
    static const char* headers[] = {
"TInterrupt.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/TClasTool/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TInterruptDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(TInterrupt)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TInterrupt.h")))  TInterrupt;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TInterruptDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TInterrupt.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TInterrupt", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TInterruptDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TInterruptDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TInterruptDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TInterruptDict() {
  TriggerDictionaryInitialization_TInterruptDict_Impl();
}
