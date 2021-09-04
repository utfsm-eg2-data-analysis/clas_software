// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITHEADClassDict
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
#include "THEADClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_THEADClass(void *p = 0);
   static void *newArray_THEADClass(Long_t size, void *p);
   static void delete_THEADClass(void *p);
   static void deleteArray_THEADClass(void *p);
   static void destruct_THEADClass(void *p);
   static void streamer_THEADClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::THEADClass*)
   {
      ::THEADClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::THEADClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("THEADClass", ::THEADClass::Class_Version(), "THEADClass.h", 17,
                  typeid(::THEADClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::THEADClass::Dictionary, isa_proxy, 16,
                  sizeof(::THEADClass) );
      instance.SetNew(&new_THEADClass);
      instance.SetNewArray(&newArray_THEADClass);
      instance.SetDelete(&delete_THEADClass);
      instance.SetDeleteArray(&deleteArray_THEADClass);
      instance.SetDestructor(&destruct_THEADClass);
      instance.SetStreamerFunc(&streamer_THEADClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::THEADClass*)
   {
      return GenerateInitInstanceLocal((::THEADClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::THEADClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr THEADClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *THEADClass::Class_Name()
{
   return "THEADClass";
}

//______________________________________________________________________________
const char *THEADClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THEADClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int THEADClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THEADClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *THEADClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THEADClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *THEADClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THEADClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void THEADClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class THEADClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Version;
      R__b >> Nrun;
      R__b >> Nevent;
      R__b >> Time;
      R__b >> Type;
      R__b >> Roc;
      R__b >> Evtclass;
      R__b >> Trigbits;
      R__b.CheckByteCount(R__s, R__c, THEADClass::IsA());
   } else {
      R__c = R__b.WriteVersion(THEADClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Version;
      R__b << Nrun;
      R__b << Nevent;
      R__b << Time;
      R__b << Type;
      R__b << Roc;
      R__b << Evtclass;
      R__b << Trigbits;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_THEADClass(void *p) {
      return  p ? new(p) ::THEADClass : new ::THEADClass;
   }
   static void *newArray_THEADClass(Long_t nElements, void *p) {
      return p ? new(p) ::THEADClass[nElements] : new ::THEADClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_THEADClass(void *p) {
      delete ((::THEADClass*)p);
   }
   static void deleteArray_THEADClass(void *p) {
      delete [] ((::THEADClass*)p);
   }
   static void destruct_THEADClass(void *p) {
      typedef ::THEADClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_THEADClass(TBuffer &buf, void *obj) {
      ((::THEADClass*)obj)->::THEADClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::THEADClass

namespace {
  void TriggerDictionaryInitialization_THEADClassDict_Impl() {
    static const char* headers[] = {
"THEADClass.h",
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
#line 1 "THEADClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Header information for event)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$THEADClass.h")))  THEADClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "THEADClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "THEADClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"THEADClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("THEADClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_THEADClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_THEADClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_THEADClassDict() {
  TriggerDictionaryInitialization_THEADClassDict_Impl();
}
