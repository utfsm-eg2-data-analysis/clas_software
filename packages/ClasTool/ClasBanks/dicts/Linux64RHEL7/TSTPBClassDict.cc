// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITSTPBClassDict
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
#include "TSTPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TSTPBClass(void *p = 0);
   static void *newArray_TSTPBClass(Long_t size, void *p);
   static void delete_TSTPBClass(void *p);
   static void deleteArray_TSTPBClass(void *p);
   static void destruct_TSTPBClass(void *p);
   static void streamer_TSTPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSTPBClass*)
   {
      ::TSTPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TSTPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TSTPBClass", ::TSTPBClass::Class_Version(), "TSTPBClass.h", 16,
                  typeid(::TSTPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TSTPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TSTPBClass) );
      instance.SetNew(&new_TSTPBClass);
      instance.SetNewArray(&newArray_TSTPBClass);
      instance.SetDelete(&delete_TSTPBClass);
      instance.SetDeleteArray(&deleteArray_TSTPBClass);
      instance.SetDestructor(&destruct_TSTPBClass);
      instance.SetStreamerFunc(&streamer_TSTPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSTPBClass*)
   {
      return GenerateInitInstanceLocal((::TSTPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TSTPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TSTPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TSTPBClass::Class_Name()
{
   return "TSTPBClass";
}

//______________________________________________________________________________
const char *TSTPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSTPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TSTPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSTPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TSTPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSTPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TSTPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSTPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TSTPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TSTPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> SThid;
      R__b >> Time;
      R__b >> Path;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TSTPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TSTPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << SThid;
      R__b << Time;
      R__b << Path;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSTPBClass(void *p) {
      return  p ? new(p) ::TSTPBClass : new ::TSTPBClass;
   }
   static void *newArray_TSTPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TSTPBClass[nElements] : new ::TSTPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSTPBClass(void *p) {
      delete ((::TSTPBClass*)p);
   }
   static void deleteArray_TSTPBClass(void *p) {
      delete [] ((::TSTPBClass*)p);
   }
   static void destruct_TSTPBClass(void *p) {
      typedef ::TSTPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TSTPBClass(TBuffer &buf, void *obj) {
      ((::TSTPBClass*)obj)->::TSTPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TSTPBClass

namespace {
  void TriggerDictionaryInitialization_TSTPBClassDict_Impl() {
    static const char* headers[] = {
"TSTPBClass.h",
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
#line 1 "TSTPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the STPB bank: Time of Flight.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TSTPBClass.h")))  TSTPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TSTPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TSTPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TSTPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TSTPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TSTPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TSTPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TSTPBClassDict() {
  TriggerDictionaryInitialization_TSTPBClassDict_Impl();
}
