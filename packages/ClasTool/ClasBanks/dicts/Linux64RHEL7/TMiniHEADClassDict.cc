// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMiniHEADClassDict
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
#include "TMiniHEADClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMiniHEADClass(void *p = 0);
   static void *newArray_TMiniHEADClass(Long_t size, void *p);
   static void delete_TMiniHEADClass(void *p);
   static void deleteArray_TMiniHEADClass(void *p);
   static void destruct_TMiniHEADClass(void *p);
   static void streamer_TMiniHEADClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMiniHEADClass*)
   {
      ::TMiniHEADClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMiniHEADClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMiniHEADClass", ::TMiniHEADClass::Class_Version(), "TMiniHEADClass.h", 15,
                  typeid(::TMiniHEADClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMiniHEADClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMiniHEADClass) );
      instance.SetNew(&new_TMiniHEADClass);
      instance.SetNewArray(&newArray_TMiniHEADClass);
      instance.SetDelete(&delete_TMiniHEADClass);
      instance.SetDeleteArray(&deleteArray_TMiniHEADClass);
      instance.SetDestructor(&destruct_TMiniHEADClass);
      instance.SetStreamerFunc(&streamer_TMiniHEADClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMiniHEADClass*)
   {
      return GenerateInitInstanceLocal((::TMiniHEADClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMiniHEADClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMiniHEADClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMiniHEADClass::Class_Name()
{
   return "TMiniHEADClass";
}

//______________________________________________________________________________
const char *TMiniHEADClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniHEADClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMiniHEADClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMiniHEADClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMiniHEADClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniHEADClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMiniHEADClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMiniHEADClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMiniHEADClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMiniHEADClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> NRun;
      R__b >> NEvent;
      R__b >> FC;
      R__b >> FCG;
      R__b >> RF1;
      R__b >> Beam_E;
      R__b >> Beam_DT;
      R__b >> Beam_EID;
      R__b >> Helicity;
      R__b.CheckByteCount(R__s, R__c, TMiniHEADClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMiniHEADClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << NRun;
      R__b << NEvent;
      R__b << FC;
      R__b << FCG;
      R__b << RF1;
      R__b << Beam_E;
      R__b << Beam_DT;
      R__b << Beam_EID;
      R__b << Helicity;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMiniHEADClass(void *p) {
      return  p ? new(p) ::TMiniHEADClass : new ::TMiniHEADClass;
   }
   static void *newArray_TMiniHEADClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMiniHEADClass[nElements] : new ::TMiniHEADClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMiniHEADClass(void *p) {
      delete ((::TMiniHEADClass*)p);
   }
   static void deleteArray_TMiniHEADClass(void *p) {
      delete [] ((::TMiniHEADClass*)p);
   }
   static void destruct_TMiniHEADClass(void *p) {
      typedef ::TMiniHEADClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMiniHEADClass(TBuffer &buf, void *obj) {
      ((::TMiniHEADClass*)obj)->::TMiniHEADClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMiniHEADClass

namespace {
  void TriggerDictionaryInitialization_TMiniHEADClassDict_Impl() {
    static const char* headers[] = {
"TMiniHEADClass.h",
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
#line 1 "TMiniHEADClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Header class for example limited DST.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMiniHEADClass.h")))  TMiniHEADClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMiniHEADClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMiniHEADClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMiniHEADClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMiniHEADClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMiniHEADClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMiniHEADClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMiniHEADClassDict() {
  TriggerDictionaryInitialization_TMiniHEADClassDict_Impl();
}
