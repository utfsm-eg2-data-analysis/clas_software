// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITRunIndexDict
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
#include "TRunIndex.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TRunIndex(void *p = 0);
   static void *newArray_TRunIndex(Long_t size, void *p);
   static void delete_TRunIndex(void *p);
   static void deleteArray_TRunIndex(void *p);
   static void destruct_TRunIndex(void *p);
   static void streamer_TRunIndex(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRunIndex*)
   {
      ::TRunIndex *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRunIndex >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRunIndex", ::TRunIndex::Class_Version(), "TRunIndex.h", 19,
                  typeid(::TRunIndex), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRunIndex::Dictionary, isa_proxy, 16,
                  sizeof(::TRunIndex) );
      instance.SetNew(&new_TRunIndex);
      instance.SetNewArray(&newArray_TRunIndex);
      instance.SetDelete(&delete_TRunIndex);
      instance.SetDeleteArray(&deleteArray_TRunIndex);
      instance.SetDestructor(&destruct_TRunIndex);
      instance.SetStreamerFunc(&streamer_TRunIndex);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRunIndex*)
   {
      return GenerateInitInstanceLocal((::TRunIndex*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRunIndex*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TRunIndex::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRunIndex::Class_Name()
{
   return "TRunIndex";
}

//______________________________________________________________________________
const char *TRunIndex::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRunIndex*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRunIndex::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRunIndex*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRunIndex::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRunIndex*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRunIndex::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRunIndex*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TRunIndex::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRunIndex.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fRunIndexId;
      R__b >> fMinRun;
      R__b >> fMaxRun;
      R__b >> fItemId;
      R__b >> fItemValueId;
      fOfficer.Streamer(R__b);
      fTime.Streamer(R__b);
      fComment.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TRunIndex::IsA());
   } else {
      R__c = R__b.WriteVersion(TRunIndex::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fRunIndexId;
      R__b << fMinRun;
      R__b << fMaxRun;
      R__b << fItemId;
      R__b << fItemValueId;
      fOfficer.Streamer(R__b);
      fTime.Streamer(R__b);
      fComment.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRunIndex(void *p) {
      return  p ? new(p) ::TRunIndex : new ::TRunIndex;
   }
   static void *newArray_TRunIndex(Long_t nElements, void *p) {
      return p ? new(p) ::TRunIndex[nElements] : new ::TRunIndex[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRunIndex(void *p) {
      delete ((::TRunIndex*)p);
   }
   static void deleteArray_TRunIndex(void *p) {
      delete [] ((::TRunIndex*)p);
   }
   static void destruct_TRunIndex(void *p) {
      typedef ::TRunIndex current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRunIndex(TBuffer &buf, void *obj) {
      ((::TRunIndex*)obj)->::TRunIndex::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRunIndex

namespace {
  void TriggerDictionaryInitialization_TRunIndexDict_Impl() {
    static const char* headers[] = {
"TRunIndex.h",
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
#line 1 "TRunIndexDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for Map Item Value Description)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TRunIndex.h")))  TRunIndex;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TRunIndexDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TRunIndex.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TRunIndex", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TRunIndexDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TRunIndexDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TRunIndexDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TRunIndexDict() {
  TriggerDictionaryInitialization_TRunIndexDict_Impl();
}
