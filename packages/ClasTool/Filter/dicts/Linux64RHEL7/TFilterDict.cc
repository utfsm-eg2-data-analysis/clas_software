// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITFilterDict
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
#include "TFilter.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TFilter(void *p = 0);
   static void *newArray_TFilter(Long_t size, void *p);
   static void delete_TFilter(void *p);
   static void deleteArray_TFilter(void *p);
   static void destruct_TFilter(void *p);
   static void streamer_TFilter(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TFilter*)
   {
      ::TFilter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TFilter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TFilter", ::TFilter::Class_Version(), "TFilter.h", 21,
                  typeid(::TFilter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TFilter::Dictionary, isa_proxy, 16,
                  sizeof(::TFilter) );
      instance.SetNew(&new_TFilter);
      instance.SetNewArray(&newArray_TFilter);
      instance.SetDelete(&delete_TFilter);
      instance.SetDeleteArray(&deleteArray_TFilter);
      instance.SetDestructor(&destruct_TFilter);
      instance.SetStreamerFunc(&streamer_TFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TFilter*)
   {
      return GenerateInitInstanceLocal((::TFilter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TFilter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TFilter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TFilter::Class_Name()
{
   return "TFilter";
}

//______________________________________________________________________________
const char *TFilter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TFilter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TFilter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TFilter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TFilter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TFilter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TFilter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TFilter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TFilter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TFilter.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TClasTool::Streamer(R__b);
      R__b >> gFix_EC_Bank;
      Cuts.Streamer(R__b);
      R__b >> H;
      R__b >> Interrupt;
      R__b >> Time;
      R__b >> chain;
      R__b >> tree;
      R__b >> H_PID;
      R__b >> iEvent;
      R__b >> C_Good_Event_Out;
      R__b.CheckByteCount(R__s, R__c, TFilter::IsA());
   } else {
      R__c = R__b.WriteVersion(TFilter::IsA(), kTRUE);
      TClasTool::Streamer(R__b);
      R__b << gFix_EC_Bank;
      Cuts.Streamer(R__b);
      R__b << H;
      R__b << Interrupt;
      R__b << Time;
      R__b << chain;
      R__b << tree;
      R__b << (TObject*)H_PID;
      R__b << iEvent;
      R__b << C_Good_Event_Out;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TFilter(void *p) {
      return  p ? new(p) ::TFilter : new ::TFilter;
   }
   static void *newArray_TFilter(Long_t nElements, void *p) {
      return p ? new(p) ::TFilter[nElements] : new ::TFilter[nElements];
   }
   // Wrapper around operator delete
   static void delete_TFilter(void *p) {
      delete ((::TFilter*)p);
   }
   static void deleteArray_TFilter(void *p) {
      delete [] ((::TFilter*)p);
   }
   static void destruct_TFilter(void *p) {
      typedef ::TFilter current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TFilter(TBuffer &buf, void *obj) {
      ((::TFilter*)obj)->::TFilter::Streamer(buf);
   }
} // end of namespace ROOT for class ::TFilter

namespace {
  void TriggerDictionaryInitialization_TFilterDict_Impl() {
    static const char* headers[] = {
"TFilter.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/PartSieve",
"/usr/include/mysql",
"/user/a/alaoui/software/root/6.20.04/include/",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/Filter/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TFilterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A Generic Data Filter Class.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TFilter.h")))  TFilter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TFilterDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TFilter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TFilter", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TFilterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TFilterDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TFilterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TFilterDict() {
  TriggerDictionaryInitialization_TFilterDict_Impl();
}
