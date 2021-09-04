// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITQueryDict
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
#include "TQuery.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TQuery(void *p = 0);
   static void *newArray_TQuery(Long_t size, void *p);
   static void delete_TQuery(void *p);
   static void deleteArray_TQuery(void *p);
   static void destruct_TQuery(void *p);
   static void streamer_TQuery(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TQuery*)
   {
      ::TQuery *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TQuery >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TQuery", ::TQuery::Class_Version(), "TQuery.h", 30,
                  typeid(::TQuery), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TQuery::Dictionary, isa_proxy, 16,
                  sizeof(::TQuery) );
      instance.SetNew(&new_TQuery);
      instance.SetNewArray(&newArray_TQuery);
      instance.SetDelete(&delete_TQuery);
      instance.SetDeleteArray(&deleteArray_TQuery);
      instance.SetDestructor(&destruct_TQuery);
      instance.SetStreamerFunc(&streamer_TQuery);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TQuery*)
   {
      return GenerateInitInstanceLocal((::TQuery*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TQuery*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TQuery::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TQuery::Class_Name()
{
   return "TQuery";
}

//______________________________________________________________________________
const char *TQuery::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TQuery*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TQuery::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TQuery*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TQuery::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TQuery*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TQuery::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TQuery*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TQuery::Streamer(TBuffer &R__b)
{
   // Stream an object of class TQuery.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      fQuery.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TQuery::IsA());
   } else {
      R__c = R__b.WriteVersion(TQuery::IsA(), kTRUE);
      TObject::Streamer(R__b);
      fQuery.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TQuery(void *p) {
      return  p ? new(p) ::TQuery : new ::TQuery;
   }
   static void *newArray_TQuery(Long_t nElements, void *p) {
      return p ? new(p) ::TQuery[nElements] : new ::TQuery[nElements];
   }
   // Wrapper around operator delete
   static void delete_TQuery(void *p) {
      delete ((::TQuery*)p);
   }
   static void deleteArray_TQuery(void *p) {
      delete [] ((::TQuery*)p);
   }
   static void destruct_TQuery(void *p) {
      typedef ::TQuery current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TQuery(TBuffer &buf, void *obj) {
      ((::TQuery*)obj)->::TQuery::Streamer(buf);
   }
} // end of namespace ROOT for class ::TQuery

namespace {
  void TriggerDictionaryInitialization_TQueryDict_Impl() {
    static const char* headers[] = {
"TQuery.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/MapUtils/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TQueryDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class to construct MySQL Queries)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TQuery.h")))  TQuery;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TQueryDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TQuery.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TQuery", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TQueryDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TQueryDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TQueryDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TQueryDict() {
  TriggerDictionaryInitialization_TQueryDict_Impl();
}
