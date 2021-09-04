// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITCCPBClassDict
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
#include "TCCPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TCCPBClass(void *p = 0);
   static void *newArray_TCCPBClass(Long_t size, void *p);
   static void delete_TCCPBClass(void *p);
   static void deleteArray_TCCPBClass(void *p);
   static void destruct_TCCPBClass(void *p);
   static void streamer_TCCPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TCCPBClass*)
   {
      ::TCCPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TCCPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TCCPBClass", ::TCCPBClass::Class_Version(), "TCCPBClass.h", 22,
                  typeid(::TCCPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TCCPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TCCPBClass) );
      instance.SetNew(&new_TCCPBClass);
      instance.SetNewArray(&newArray_TCCPBClass);
      instance.SetDelete(&delete_TCCPBClass);
      instance.SetDeleteArray(&deleteArray_TCCPBClass);
      instance.SetDestructor(&destruct_TCCPBClass);
      instance.SetStreamerFunc(&streamer_TCCPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TCCPBClass*)
   {
      return GenerateInitInstanceLocal((::TCCPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TCCPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TCCPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TCCPBClass::Class_Name()
{
   return "TCCPBClass";
}

//______________________________________________________________________________
const char *TCCPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCCPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TCCPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCCPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TCCPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCCPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TCCPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCCPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TCCPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TCCPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Scsght;
      R__b >> Nphe;
      R__b >> Time;
      R__b >> Path;
      R__b >> Chi2cc;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TCCPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TCCPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Scsght;
      R__b << Nphe;
      R__b << Time;
      R__b << Path;
      R__b << Chi2cc;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TCCPBClass(void *p) {
      return  p ? new(p) ::TCCPBClass : new ::TCCPBClass;
   }
   static void *newArray_TCCPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TCCPBClass[nElements] : new ::TCCPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TCCPBClass(void *p) {
      delete ((::TCCPBClass*)p);
   }
   static void deleteArray_TCCPBClass(void *p) {
      delete [] ((::TCCPBClass*)p);
   }
   static void destruct_TCCPBClass(void *p) {
      typedef ::TCCPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TCCPBClass(TBuffer &buf, void *obj) {
      ((::TCCPBClass*)obj)->::TCCPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TCCPBClass

namespace {
  void TriggerDictionaryInitialization_TCCPBClassDict_Impl() {
    static const char* headers[] = {
"TCCPBClass.h",
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
#line 1 "TCCPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the CCPB bank: Cherencov.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TCCPBClass.h")))  TCCPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TCCPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TCCPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TCCPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TCCPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TCCPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TCCPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TCCPBClassDict() {
  TriggerDictionaryInitialization_TCCPBClassDict_Impl();
}
