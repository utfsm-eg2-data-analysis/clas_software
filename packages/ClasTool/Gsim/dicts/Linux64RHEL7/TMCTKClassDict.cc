// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMCTKClassDict
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
#include "TMCTKClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMCTKClass(void *p = 0);
   static void *newArray_TMCTKClass(Long_t size, void *p);
   static void delete_TMCTKClass(void *p);
   static void deleteArray_TMCTKClass(void *p);
   static void destruct_TMCTKClass(void *p);
   static void streamer_TMCTKClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMCTKClass*)
   {
      ::TMCTKClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMCTKClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMCTKClass", ::TMCTKClass::Class_Version(), "TMCTKClass.h", 22,
                  typeid(::TMCTKClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMCTKClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMCTKClass) );
      instance.SetNew(&new_TMCTKClass);
      instance.SetNewArray(&newArray_TMCTKClass);
      instance.SetDelete(&delete_TMCTKClass);
      instance.SetDeleteArray(&deleteArray_TMCTKClass);
      instance.SetDestructor(&destruct_TMCTKClass);
      instance.SetStreamerFunc(&streamer_TMCTKClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMCTKClass*)
   {
      return GenerateInitInstanceLocal((::TMCTKClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMCTKClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMCTKClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMCTKClass::Class_Name()
{
   return "TMCTKClass";
}

//______________________________________________________________________________
const char *TMCTKClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCTKClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMCTKClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCTKClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMCTKClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCTKClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMCTKClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCTKClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMCTKClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMCTKClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Cx;
      R__b >> Cy;
      R__b >> Cz;
      R__b >> Pmom;
      R__b >> Mass;
      R__b >> Charge;
      R__b >> Id;
      R__b >> Flag;
      R__b >> Beg_vtx;
      R__b >> End_vtx;
      R__b >> Parent;
      R__b.CheckByteCount(R__s, R__c, TMCTKClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMCTKClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Cx;
      R__b << Cy;
      R__b << Cz;
      R__b << Pmom;
      R__b << Mass;
      R__b << Charge;
      R__b << Id;
      R__b << Flag;
      R__b << Beg_vtx;
      R__b << End_vtx;
      R__b << Parent;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMCTKClass(void *p) {
      return  p ? new(p) ::TMCTKClass : new ::TMCTKClass;
   }
   static void *newArray_TMCTKClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMCTKClass[nElements] : new ::TMCTKClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMCTKClass(void *p) {
      delete ((::TMCTKClass*)p);
   }
   static void deleteArray_TMCTKClass(void *p) {
      delete [] ((::TMCTKClass*)p);
   }
   static void destruct_TMCTKClass(void *p) {
      typedef ::TMCTKClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMCTKClass(TBuffer &buf, void *obj) {
      ((::TMCTKClass*)obj)->::TMCTKClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMCTKClass

namespace {
  void TriggerDictionaryInitialization_TMCTKClassDict_Impl() {
    static const char* headers[] = {
"TMCTKClass.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/bosio",
"/user/a/alaoui/software/root/6.20.04/include/",
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/Gsim/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TMCTKClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the MCTK bank: Monte Carlo particle vectors.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMCTKClass.h")))  TMCTKClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMCTKClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMCTKClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMCTKClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMCTKClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMCTKClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMCTKClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMCTKClassDict() {
  TriggerDictionaryInitialization_TMCTKClassDict_Impl();
}
