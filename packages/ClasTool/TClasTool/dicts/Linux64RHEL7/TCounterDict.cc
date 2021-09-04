// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITCounterDict
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
#include "TCounter.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TCounter(void *p = 0);
   static void *newArray_TCounter(Long_t size, void *p);
   static void delete_TCounter(void *p);
   static void deleteArray_TCounter(void *p);
   static void destruct_TCounter(void *p);
   static void streamer_TCounter(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TCounter*)
   {
      ::TCounter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TCounter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TCounter", ::TCounter::Class_Version(), "TCounter.h", 29,
                  typeid(::TCounter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TCounter::Dictionary, isa_proxy, 16,
                  sizeof(::TCounter) );
      instance.SetNew(&new_TCounter);
      instance.SetNewArray(&newArray_TCounter);
      instance.SetDelete(&delete_TCounter);
      instance.SetDeleteArray(&deleteArray_TCounter);
      instance.SetDestructor(&destruct_TCounter);
      instance.SetStreamerFunc(&streamer_TCounter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TCounter*)
   {
      return GenerateInitInstanceLocal((::TCounter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TCounter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TCounter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TCounter::Class_Name()
{
   return "TCounter";
}

//______________________________________________________________________________
const char *TCounter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCounter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TCounter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCounter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TCounter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCounter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TCounter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCounter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TCounter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TCounter.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TNamed::Streamer(R__b);
      R__b >> fNumtrue;
      R__b >> fNumfalse;
      R__b.CheckByteCount(R__s, R__c, TCounter::IsA());
   } else {
      R__c = R__b.WriteVersion(TCounter::IsA(), kTRUE);
      TNamed::Streamer(R__b);
      R__b << fNumtrue;
      R__b << fNumfalse;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TCounter(void *p) {
      return  p ? new(p) ::TCounter : new ::TCounter;
   }
   static void *newArray_TCounter(Long_t nElements, void *p) {
      return p ? new(p) ::TCounter[nElements] : new ::TCounter[nElements];
   }
   // Wrapper around operator delete
   static void delete_TCounter(void *p) {
      delete ((::TCounter*)p);
   }
   static void deleteArray_TCounter(void *p) {
      delete [] ((::TCounter*)p);
   }
   static void destruct_TCounter(void *p) {
      typedef ::TCounter current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TCounter(TBuffer &buf, void *obj) {
      ((::TCounter*)obj)->::TCounter::Streamer(buf);
   }
} // end of namespace ROOT for class ::TCounter

namespace {
  void TriggerDictionaryInitialization_TCounterDict_Impl() {
    static const char* headers[] = {
"TCounter.h",
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
#line 1 "TCounterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A Counter class for simple statistics.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TCounter.h")))  TCounter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TCounterDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TCounter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TCounter", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TCounterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TCounterDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TCounterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TCounterDict() {
  TriggerDictionaryInitialization_TCounterDict_Impl();
}
