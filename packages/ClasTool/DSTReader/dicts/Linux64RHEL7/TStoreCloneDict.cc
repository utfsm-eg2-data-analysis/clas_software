// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITStoreCloneDict
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
#include "TStoreClone.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TStoreClone(void *p = 0);
   static void *newArray_TStoreClone(Long_t size, void *p);
   static void delete_TStoreClone(void *p);
   static void deleteArray_TStoreClone(void *p);
   static void destruct_TStoreClone(void *p);
   static void streamer_TStoreClone(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TStoreClone*)
   {
      ::TStoreClone *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TStoreClone >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TStoreClone", ::TStoreClone::Class_Version(), "TStoreClone.h", 26,
                  typeid(::TStoreClone), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TStoreClone::Dictionary, isa_proxy, 16,
                  sizeof(::TStoreClone) );
      instance.SetNew(&new_TStoreClone);
      instance.SetNewArray(&newArray_TStoreClone);
      instance.SetDelete(&delete_TStoreClone);
      instance.SetDeleteArray(&deleteArray_TStoreClone);
      instance.SetDestructor(&destruct_TStoreClone);
      instance.SetStreamerFunc(&streamer_TStoreClone);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TStoreClone*)
   {
      return GenerateInitInstanceLocal((::TStoreClone*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TStoreClone*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TStoreClone::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TStoreClone::Class_Name()
{
   return "TStoreClone";
}

//______________________________________________________________________________
const char *TStoreClone::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TStoreClone*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TStoreClone::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TStoreClone*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TStoreClone::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TStoreClone*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TStoreClone::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TStoreClone*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TStoreClone::Streamer(TBuffer &R__b)
{
   // Stream an object of class TStoreClone.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObjString::Streamer(R__b);
      fCloneArr->Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TStoreClone::IsA());
   } else {
      R__c = R__b.WriteVersion(TStoreClone::IsA(), kTRUE);
      TObjString::Streamer(R__b);
      fCloneArr->Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TStoreClone(void *p) {
      return  p ? new(p) ::TStoreClone : new ::TStoreClone;
   }
   static void *newArray_TStoreClone(Long_t nElements, void *p) {
      return p ? new(p) ::TStoreClone[nElements] : new ::TStoreClone[nElements];
   }
   // Wrapper around operator delete
   static void delete_TStoreClone(void *p) {
      delete ((::TStoreClone*)p);
   }
   static void deleteArray_TStoreClone(void *p) {
      delete [] ((::TStoreClone*)p);
   }
   static void destruct_TStoreClone(void *p) {
      typedef ::TStoreClone current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TStoreClone(TBuffer &buf, void *obj) {
      ((::TStoreClone*)obj)->::TStoreClone::Streamer(buf);
   }
} // end of namespace ROOT for class ::TStoreClone

namespace {
  void TriggerDictionaryInitialization_TStoreCloneDict_Impl() {
    static const char* headers[] = {
"TStoreClone.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/DSTReader/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TStoreCloneDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Small object to aid storing TClonesArray pointers in TObjArray)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TStoreClone.h")))  TStoreClone;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TStoreCloneDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TStoreClone.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TStoreClone", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TStoreCloneDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TStoreCloneDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TStoreCloneDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TStoreCloneDict() {
  TriggerDictionaryInitialization_TStoreCloneDict_Impl();
}
