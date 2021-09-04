// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITCounterColDict
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
#include "TCounterCol.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TCounterCol(void *p = 0);
   static void *newArray_TCounterCol(Long_t size, void *p);
   static void delete_TCounterCol(void *p);
   static void deleteArray_TCounterCol(void *p);
   static void destruct_TCounterCol(void *p);
   static void streamer_TCounterCol(TBuffer &buf, void *obj);
   static Long64_t merge_TCounterCol(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TCounterCol*)
   {
      ::TCounterCol *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TCounterCol >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TCounterCol", ::TCounterCol::Class_Version(), "TCounterCol.h", 28,
                  typeid(::TCounterCol), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TCounterCol::Dictionary, isa_proxy, 16,
                  sizeof(::TCounterCol) );
      instance.SetNew(&new_TCounterCol);
      instance.SetNewArray(&newArray_TCounterCol);
      instance.SetDelete(&delete_TCounterCol);
      instance.SetDeleteArray(&deleteArray_TCounterCol);
      instance.SetDestructor(&destruct_TCounterCol);
      instance.SetStreamerFunc(&streamer_TCounterCol);
      instance.SetMerge(&merge_TCounterCol);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TCounterCol*)
   {
      return GenerateInitInstanceLocal((::TCounterCol*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TCounterCol*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TCounterCol::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TCounterCol::Class_Name()
{
   return "TCounterCol";
}

//______________________________________________________________________________
const char *TCounterCol::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCounterCol*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TCounterCol::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TCounterCol*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TCounterCol::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCounterCol*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TCounterCol::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TCounterCol*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TCounterCol::Streamer(TBuffer &R__b)
{
   // Stream an object of class TCounterCol.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObjArray::Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TCounterCol::IsA());
   } else {
      R__c = R__b.WriteVersion(TCounterCol::IsA(), kTRUE);
      TObjArray::Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TCounterCol(void *p) {
      return  p ? new(p) ::TCounterCol : new ::TCounterCol;
   }
   static void *newArray_TCounterCol(Long_t nElements, void *p) {
      return p ? new(p) ::TCounterCol[nElements] : new ::TCounterCol[nElements];
   }
   // Wrapper around operator delete
   static void delete_TCounterCol(void *p) {
      delete ((::TCounterCol*)p);
   }
   static void deleteArray_TCounterCol(void *p) {
      delete [] ((::TCounterCol*)p);
   }
   static void destruct_TCounterCol(void *p) {
      typedef ::TCounterCol current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TCounterCol(TBuffer &buf, void *obj) {
      ((::TCounterCol*)obj)->::TCounterCol::Streamer(buf);
   }
   // Wrapper around the merge function.
   static Long64_t  merge_TCounterCol(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::TCounterCol*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::TCounterCol

namespace {
  void TriggerDictionaryInitialization_TCounterColDict_Impl() {
    static const char* headers[] = {
"TCounterCol.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/TClasTool/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TCounterColDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A ClonesArray of counters.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TCounterCol.h")))  TCounterCol;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TCounterColDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TCounterCol.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TCounterCol", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TCounterColDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TCounterColDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TCounterColDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TCounterColDict() {
  TriggerDictionaryInitialization_TCounterColDict_Impl();
}
