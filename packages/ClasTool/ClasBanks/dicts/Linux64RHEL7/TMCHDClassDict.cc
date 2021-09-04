// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMCHDClassDict
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
#include "TMCHDClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMCHDClass(void *p = 0);
   static void *newArray_TMCHDClass(Long_t size, void *p);
   static void delete_TMCHDClass(void *p);
   static void deleteArray_TMCHDClass(void *p);
   static void destruct_TMCHDClass(void *p);
   static void streamer_TMCHDClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMCHDClass*)
   {
      ::TMCHDClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMCHDClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMCHDClass", ::TMCHDClass::Class_Version(), "TMCHDClass.h", 17,
                  typeid(::TMCHDClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMCHDClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMCHDClass) );
      instance.SetNew(&new_TMCHDClass);
      instance.SetNewArray(&newArray_TMCHDClass);
      instance.SetDelete(&delete_TMCHDClass);
      instance.SetDeleteArray(&deleteArray_TMCHDClass);
      instance.SetDestructor(&destruct_TMCHDClass);
      instance.SetStreamerFunc(&streamer_TMCHDClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMCHDClass*)
   {
      return GenerateInitInstanceLocal((::TMCHDClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMCHDClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMCHDClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMCHDClass::Class_Name()
{
   return "TMCHDClass";
}

//______________________________________________________________________________
const char *TMCHDClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCHDClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMCHDClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCHDClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMCHDClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCHDClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMCHDClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCHDClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMCHDClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMCHDClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Nrun;
      R__b >> Nevent;
      R__b >> Time;
      R__b >> Type;
      R__b >> ReacType;
      R__b >> Weight;
      Photon.Streamer(R__b);
      Target.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TMCHDClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMCHDClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Nrun;
      R__b << Nevent;
      R__b << Time;
      R__b << Type;
      R__b << ReacType;
      R__b << Weight;
      Photon.Streamer(R__b);
      Target.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMCHDClass(void *p) {
      return  p ? new(p) ::TMCHDClass : new ::TMCHDClass;
   }
   static void *newArray_TMCHDClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMCHDClass[nElements] : new ::TMCHDClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMCHDClass(void *p) {
      delete ((::TMCHDClass*)p);
   }
   static void deleteArray_TMCHDClass(void *p) {
      delete [] ((::TMCHDClass*)p);
   }
   static void destruct_TMCHDClass(void *p) {
      typedef ::TMCHDClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMCHDClass(TBuffer &buf, void *obj) {
      ((::TMCHDClass*)obj)->::TMCHDClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMCHDClass

namespace {
  void TriggerDictionaryInitialization_TMCHDClassDict_Impl() {
    static const char* headers[] = {
"TMCHDClass.h",
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
#line 1 "TMCHDClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Header information for event)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMCHDClass.h")))  TMCHDClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMCHDClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMCHDClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMCHDClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMCHDClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMCHDClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMCHDClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMCHDClassDict() {
  TriggerDictionaryInitialization_TMCHDClassDict_Impl();
}
