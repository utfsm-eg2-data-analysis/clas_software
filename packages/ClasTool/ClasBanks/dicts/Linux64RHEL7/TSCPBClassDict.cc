// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITSCPBClassDict
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
#include "TSCPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TSCPBClass(void *p = 0);
   static void *newArray_TSCPBClass(Long_t size, void *p);
   static void delete_TSCPBClass(void *p);
   static void deleteArray_TSCPBClass(void *p);
   static void destruct_TSCPBClass(void *p);
   static void streamer_TSCPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSCPBClass*)
   {
      ::TSCPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TSCPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TSCPBClass", ::TSCPBClass::Class_Version(), "TSCPBClass.h", 24,
                  typeid(::TSCPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TSCPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TSCPBClass) );
      instance.SetNew(&new_TSCPBClass);
      instance.SetNewArray(&newArray_TSCPBClass);
      instance.SetDelete(&delete_TSCPBClass);
      instance.SetDeleteArray(&deleteArray_TSCPBClass);
      instance.SetDestructor(&destruct_TSCPBClass);
      instance.SetStreamerFunc(&streamer_TSCPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSCPBClass*)
   {
      return GenerateInitInstanceLocal((::TSCPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TSCPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TSCPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TSCPBClass::Class_Name()
{
   return "TSCPBClass";
}

//______________________________________________________________________________
const char *TSCPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSCPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TSCPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSCPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TSCPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSCPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TSCPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSCPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TSCPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TSCPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Scpdht;
      R__b >> Edep;
      R__b >> Time;
      R__b >> Path;
      R__b >> Chi2sc;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TSCPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TSCPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Scpdht;
      R__b << Edep;
      R__b << Time;
      R__b << Path;
      R__b << Chi2sc;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSCPBClass(void *p) {
      return  p ? new(p) ::TSCPBClass : new ::TSCPBClass;
   }
   static void *newArray_TSCPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TSCPBClass[nElements] : new ::TSCPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSCPBClass(void *p) {
      delete ((::TSCPBClass*)p);
   }
   static void deleteArray_TSCPBClass(void *p) {
      delete [] ((::TSCPBClass*)p);
   }
   static void destruct_TSCPBClass(void *p) {
      typedef ::TSCPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TSCPBClass(TBuffer &buf, void *obj) {
      ((::TSCPBClass*)obj)->::TSCPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TSCPBClass

namespace {
  void TriggerDictionaryInitialization_TSCPBClassDict_Impl() {
    static const char* headers[] = {
"TSCPBClass.h",
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
#line 1 "TSCPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the SCPB bank: Time of Flight.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TSCPBClass.h")))  TSCPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TSCPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TSCPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TSCPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TSCPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TSCPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TSCPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TSCPBClassDict() {
  TriggerDictionaryInitialization_TSCPBClassDict_Impl();
}
