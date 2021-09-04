// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMiniDSTClassDict
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
#include "TMiniDSTClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMiniDSTClass(void *p = 0);
   static void *newArray_TMiniDSTClass(Long_t size, void *p);
   static void delete_TMiniDSTClass(void *p);
   static void deleteArray_TMiniDSTClass(void *p);
   static void destruct_TMiniDSTClass(void *p);
   static void streamer_TMiniDSTClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMiniDSTClass*)
   {
      ::TMiniDSTClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMiniDSTClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMiniDSTClass", ::TMiniDSTClass::Class_Version(), "TMiniDSTClass.h", 23,
                  typeid(::TMiniDSTClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMiniDSTClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMiniDSTClass) );
      instance.SetNew(&new_TMiniDSTClass);
      instance.SetNewArray(&newArray_TMiniDSTClass);
      instance.SetDelete(&delete_TMiniDSTClass);
      instance.SetDeleteArray(&deleteArray_TMiniDSTClass);
      instance.SetDestructor(&destruct_TMiniDSTClass);
      instance.SetStreamerFunc(&streamer_TMiniDSTClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMiniDSTClass*)
   {
      return GenerateInitInstanceLocal((::TMiniDSTClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMiniDSTClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMiniDSTClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMiniDSTClass::Class_Name()
{
   return "TMiniDSTClass";
}

//______________________________________________________________________________
const char *TMiniDSTClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMiniDSTClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMiniDSTClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMiniDSTClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniDSTClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMiniDSTClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMiniDSTClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fPartID;
      R__b >> fStatus;
      R__b >> fPq;
      R__b >> fPb;
      R__b >> fPx;
      R__b >> fPy;
      R__b >> fPz;
      R__b >> fVxp;
      R__b >> fVyp;
      R__b >> fVzp;
      R__b >> fThL;
      R__b >> fPhL;
      R__b >> fXiec;
      R__b >> fYiec;
      R__b >> fEff;
      R__b >> fEdp;
      R__b.CheckByteCount(R__s, R__c, TMiniDSTClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMiniDSTClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fPartID;
      R__b << fStatus;
      R__b << fPq;
      R__b << fPb;
      R__b << fPx;
      R__b << fPy;
      R__b << fPz;
      R__b << fVxp;
      R__b << fVyp;
      R__b << fVzp;
      R__b << fThL;
      R__b << fPhL;
      R__b << fXiec;
      R__b << fYiec;
      R__b << fEff;
      R__b << fEdp;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMiniDSTClass(void *p) {
      return  p ? new(p) ::TMiniDSTClass : new ::TMiniDSTClass;
   }
   static void *newArray_TMiniDSTClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMiniDSTClass[nElements] : new ::TMiniDSTClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMiniDSTClass(void *p) {
      delete ((::TMiniDSTClass*)p);
   }
   static void deleteArray_TMiniDSTClass(void *p) {
      delete [] ((::TMiniDSTClass*)p);
   }
   static void destruct_TMiniDSTClass(void *p) {
      typedef ::TMiniDSTClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMiniDSTClass(TBuffer &buf, void *obj) {
      ((::TMiniDSTClass*)obj)->::TMiniDSTClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMiniDSTClass

namespace {
  void TriggerDictionaryInitialization_TMiniDSTClassDict_Impl() {
    static const char* headers[] = {
"TMiniDSTClass.h",
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
#line 1 "TMiniDSTClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Data class for example limited DST.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMiniDSTClass.h")))  TMiniDSTClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMiniDSTClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMiniDSTClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMiniDSTClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMiniDSTClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMiniDSTClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMiniDSTClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMiniDSTClassDict() {
  TriggerDictionaryInitialization_TMiniDSTClassDict_Impl();
}
