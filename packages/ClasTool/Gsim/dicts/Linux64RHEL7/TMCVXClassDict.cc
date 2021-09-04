// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMCVXClassDict
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
#include "TMCVXClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMCVXClass(void *p = 0);
   static void *newArray_TMCVXClass(Long_t size, void *p);
   static void delete_TMCVXClass(void *p);
   static void deleteArray_TMCVXClass(void *p);
   static void destruct_TMCVXClass(void *p);
   static void streamer_TMCVXClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMCVXClass*)
   {
      ::TMCVXClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMCVXClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMCVXClass", ::TMCVXClass::Class_Version(), "TMCVXClass.h", 9,
                  typeid(::TMCVXClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMCVXClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMCVXClass) );
      instance.SetNew(&new_TMCVXClass);
      instance.SetNewArray(&newArray_TMCVXClass);
      instance.SetDelete(&delete_TMCVXClass);
      instance.SetDeleteArray(&deleteArray_TMCVXClass);
      instance.SetDestructor(&destruct_TMCVXClass);
      instance.SetStreamerFunc(&streamer_TMCVXClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMCVXClass*)
   {
      return GenerateInitInstanceLocal((::TMCVXClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMCVXClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMCVXClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMCVXClass::Class_Name()
{
   return "TMCVXClass";
}

//______________________________________________________________________________
const char *TMCVXClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCVXClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMCVXClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMCVXClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMCVXClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCVXClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMCVXClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMCVXClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMCVXClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMCVXClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> x;
      R__b >> y;
      R__b >> z;
      R__b >> tof;
      R__b >> flag;
      R__b.CheckByteCount(R__s, R__c, TMCVXClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMCVXClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << x;
      R__b << y;
      R__b << z;
      R__b << tof;
      R__b << flag;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMCVXClass(void *p) {
      return  p ? new(p) ::TMCVXClass : new ::TMCVXClass;
   }
   static void *newArray_TMCVXClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMCVXClass[nElements] : new ::TMCVXClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMCVXClass(void *p) {
      delete ((::TMCVXClass*)p);
   }
   static void deleteArray_TMCVXClass(void *p) {
      delete [] ((::TMCVXClass*)p);
   }
   static void destruct_TMCVXClass(void *p) {
      typedef ::TMCVXClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMCVXClass(TBuffer &buf, void *obj) {
      ((::TMCVXClass*)obj)->::TMCVXClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMCVXClass

namespace {
  void TriggerDictionaryInitialization_TMCVXClassDict_Impl() {
    static const char* headers[] = {
"TMCVXClass.h",
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
#line 1 "TMCVXClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the MCVX bank: Monte Carlo vertex.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMCVXClass.h")))  TMCVXClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMCVXClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMCVXClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMCVXClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMCVXClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMCVXClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMCVXClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMCVXClassDict() {
  TriggerDictionaryInitialization_TMCVXClassDict_Impl();
}
