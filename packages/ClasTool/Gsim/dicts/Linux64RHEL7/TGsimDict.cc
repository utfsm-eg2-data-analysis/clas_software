// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITGsimDict
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
#include "TGsim.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TGsim(void *p = 0);
   static void *newArray_TGsim(Long_t size, void *p);
   static void delete_TGsim(void *p);
   static void deleteArray_TGsim(void *p);
   static void destruct_TGsim(void *p);
   static void streamer_TGsim(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGsim*)
   {
      ::TGsim *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TGsim >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TGsim", ::TGsim::Class_Version(), "TGsim.h", 61,
                  typeid(::TGsim), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TGsim::Dictionary, isa_proxy, 16,
                  sizeof(::TGsim) );
      instance.SetNew(&new_TGsim);
      instance.SetNewArray(&newArray_TGsim);
      instance.SetDelete(&delete_TGsim);
      instance.SetDeleteArray(&deleteArray_TGsim);
      instance.SetDestructor(&destruct_TGsim);
      instance.SetStreamerFunc(&streamer_TGsim);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGsim*)
   {
      return GenerateInitInstanceLocal((::TGsim*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGsim*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TGsim::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TGsim::Class_Name()
{
   return "TGsim";
}

//______________________________________________________________________________
const char *TGsim::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TGsim*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TGsim::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TGsim*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TGsim::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TGsim*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TGsim::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TGsim*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TGsim::Streamer(TBuffer &R__b)
{
   // Stream an object of class TGsim.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fDebug_Mode;
      R__b >> fDesc_in;
      R__b >> fDesc_out;
      fNow.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TGsim::IsA());
   } else {
      R__c = R__b.WriteVersion(TGsim::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fDebug_Mode;
      R__b << fDesc_in;
      R__b << fDesc_out;
      fNow.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGsim(void *p) {
      return  p ? new(p) ::TGsim : new ::TGsim;
   }
   static void *newArray_TGsim(Long_t nElements, void *p) {
      return p ? new(p) ::TGsim[nElements] : new ::TGsim[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGsim(void *p) {
      delete ((::TGsim*)p);
   }
   static void deleteArray_TGsim(void *p) {
      delete [] ((::TGsim*)p);
   }
   static void destruct_TGsim(void *p) {
      typedef ::TGsim current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TGsim(TBuffer &buf, void *obj) {
      ((::TGsim*)obj)->::TGsim::Streamer(buf);
   }
} // end of namespace ROOT for class ::TGsim

namespace {
  void TriggerDictionaryInitialization_TGsimDict_Impl() {
    static const char* headers[] = {
"TGsim.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/bosio",
"/user/a/alaoui/software/root/6.20.04/include/",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/Gsim/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TGsimDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A class for interfacing to the Monte Carlo.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TGsim.h")))  TGsim;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TGsimDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TGsim.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TGsim", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TGsimDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TGsimDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TGsimDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TGsimDict() {
  TriggerDictionaryInitialization_TGsimDict_Impl();
}
