// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITFBPMClassDict
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
#include "TFBPMClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TFBPMClass(void *p = 0);
   static void *newArray_TFBPMClass(Long_t size, void *p);
   static void delete_TFBPMClass(void *p);
   static void deleteArray_TFBPMClass(void *p);
   static void destruct_TFBPMClass(void *p);
   static void streamer_TFBPMClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TFBPMClass*)
   {
      ::TFBPMClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TFBPMClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TFBPMClass", ::TFBPMClass::Class_Version(), "TFBPMClass.h", 13,
                  typeid(::TFBPMClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TFBPMClass::Dictionary, isa_proxy, 16,
                  sizeof(::TFBPMClass) );
      instance.SetNew(&new_TFBPMClass);
      instance.SetNewArray(&newArray_TFBPMClass);
      instance.SetDelete(&delete_TFBPMClass);
      instance.SetDeleteArray(&deleteArray_TFBPMClass);
      instance.SetDestructor(&destruct_TFBPMClass);
      instance.SetStreamerFunc(&streamer_TFBPMClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TFBPMClass*)
   {
      return GenerateInitInstanceLocal((::TFBPMClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TFBPMClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TFBPMClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TFBPMClass::Class_Name()
{
   return "TFBPMClass";
}

//______________________________________________________________________________
const char *TFBPMClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TFBPMClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TFBPMClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TFBPMClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TFBPMClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TFBPMClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TFBPMClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TFBPMClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TFBPMClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TFBPMClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> ID;
      R__b >> TDC;
      R__b >> ADC;
      R__b.CheckByteCount(R__s, R__c, TFBPMClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TFBPMClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << ID;
      R__b << TDC;
      R__b << ADC;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TFBPMClass(void *p) {
      return  p ? new(p) ::TFBPMClass : new ::TFBPMClass;
   }
   static void *newArray_TFBPMClass(Long_t nElements, void *p) {
      return p ? new(p) ::TFBPMClass[nElements] : new ::TFBPMClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TFBPMClass(void *p) {
      delete ((::TFBPMClass*)p);
   }
   static void deleteArray_TFBPMClass(void *p) {
      delete [] ((::TFBPMClass*)p);
   }
   static void destruct_TFBPMClass(void *p) {
      typedef ::TFBPMClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TFBPMClass(TBuffer &buf, void *obj) {
      ((::TFBPMClass*)obj)->::TFBPMClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TFBPMClass

namespace {
  void TriggerDictionaryInitialization_TFBPMClassDict_Impl() {
    static const char* headers[] = {
"TFBPMClass.h",
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
#line 1 "TFBPMClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TFBPMClass.h")))  TFBPMClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TFBPMClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TFBPMClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TFBPMClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TFBPMClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TFBPMClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TFBPMClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TFBPMClassDict() {
  TriggerDictionaryInitialization_TFBPMClassDict_Impl();
}
