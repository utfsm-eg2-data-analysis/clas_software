// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITGSIMClassDict
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
#include "TGSIMClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TGSIMClass(void *p = 0);
   static void *newArray_TGSIMClass(Long_t size, void *p);
   static void delete_TGSIMClass(void *p);
   static void deleteArray_TGSIMClass(void *p);
   static void destruct_TGSIMClass(void *p);
   static void streamer_TGSIMClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGSIMClass*)
   {
      ::TGSIMClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TGSIMClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TGSIMClass", ::TGSIMClass::Class_Version(), "TGSIMClass.h", 80,
                  typeid(::TGSIMClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TGSIMClass::Dictionary, isa_proxy, 16,
                  sizeof(::TGSIMClass) );
      instance.SetNew(&new_TGSIMClass);
      instance.SetNewArray(&newArray_TGSIMClass);
      instance.SetDelete(&delete_TGSIMClass);
      instance.SetDeleteArray(&deleteArray_TGSIMClass);
      instance.SetDestructor(&destruct_TGSIMClass);
      instance.SetStreamerFunc(&streamer_TGSIMClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGSIMClass*)
   {
      return GenerateInitInstanceLocal((::TGSIMClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGSIMClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TGSIMClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TGSIMClass::Class_Name()
{
   return "TGSIMClass";
}

//______________________________________________________________________________
const char *TGSIMClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TGSIMClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TGSIMClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TGSIMClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TGSIMClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TGSIMClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TGSIMClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TGSIMClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TGSIMClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TGSIMClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TVirtualData::Streamer(R__b);
      R__b >> mass;
      R__b.CheckByteCount(R__s, R__c, TGSIMClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TGSIMClass::IsA(), kTRUE);
      TVirtualData::Streamer(R__b);
      R__b << mass;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGSIMClass(void *p) {
      return  p ? new(p) ::TGSIMClass : new ::TGSIMClass;
   }
   static void *newArray_TGSIMClass(Long_t nElements, void *p) {
      return p ? new(p) ::TGSIMClass[nElements] : new ::TGSIMClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGSIMClass(void *p) {
      delete ((::TGSIMClass*)p);
   }
   static void deleteArray_TGSIMClass(void *p) {
      delete [] ((::TGSIMClass*)p);
   }
   static void destruct_TGSIMClass(void *p) {
      typedef ::TGSIMClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TGSIMClass(TBuffer &buf, void *obj) {
      ((::TGSIMClass*)obj)->::TGSIMClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TGSIMClass

namespace {
  void TriggerDictionaryInitialization_TGSIMClassDict_Impl() {
    static const char* headers[] = {
"TGSIMClass.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/ClasBanks/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TGSIMClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Stores EVNT data for GSIM banks, inherit from TVirtualData.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TGSIMClass.h")))  TGSIMClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TGSIMClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TGSIMClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TGSIMClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TGSIMClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TGSIMClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TGSIMClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TGSIMClassDict() {
  TriggerDictionaryInitialization_TGSIMClassDict_Impl();
}
