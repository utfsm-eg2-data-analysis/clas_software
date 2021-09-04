// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMVRTClassDict
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
#include "TMVRTClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMVRTClass(void *p = 0);
   static void *newArray_TMVRTClass(Long_t size, void *p);
   static void delete_TMVRTClass(void *p);
   static void deleteArray_TMVRTClass(void *p);
   static void destruct_TMVRTClass(void *p);
   static void streamer_TMVRTClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMVRTClass*)
   {
      ::TMVRTClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMVRTClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMVRTClass", ::TMVRTClass::Class_Version(), "TMVRTClass.h", 28,
                  typeid(::TMVRTClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMVRTClass::Dictionary, isa_proxy, 16,
                  sizeof(::TMVRTClass) );
      instance.SetNew(&new_TMVRTClass);
      instance.SetNewArray(&newArray_TMVRTClass);
      instance.SetDelete(&delete_TMVRTClass);
      instance.SetDeleteArray(&deleteArray_TMVRTClass);
      instance.SetDestructor(&destruct_TMVRTClass);
      instance.SetStreamerFunc(&streamer_TMVRTClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMVRTClass*)
   {
      return GenerateInitInstanceLocal((::TMVRTClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMVRTClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMVRTClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMVRTClass::Class_Name()
{
   return "TMVRTClass";
}

//______________________________________________________________________________
const char *TMVRTClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMVRTClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMVRTClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMVRTClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMVRTClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMVRTClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMVRTClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMVRTClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMVRTClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMVRTClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> v_id;
      R__b >> ntrk;
      R__b >> x;
      R__b >> y;
      R__b >> z;
      R__b >> chi2;
      R__b >> cxx;
      R__b >> cxy;
      R__b >> cxz;
      R__b >> cyy;
      R__b >> cyz;
      R__b >> czz;
      R__b >> stat;
      R__b.CheckByteCount(R__s, R__c, TMVRTClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TMVRTClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << v_id;
      R__b << ntrk;
      R__b << x;
      R__b << y;
      R__b << z;
      R__b << chi2;
      R__b << cxx;
      R__b << cxy;
      R__b << cxz;
      R__b << cyy;
      R__b << cyz;
      R__b << czz;
      R__b << stat;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMVRTClass(void *p) {
      return  p ? new(p) ::TMVRTClass : new ::TMVRTClass;
   }
   static void *newArray_TMVRTClass(Long_t nElements, void *p) {
      return p ? new(p) ::TMVRTClass[nElements] : new ::TMVRTClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMVRTClass(void *p) {
      delete ((::TMVRTClass*)p);
   }
   static void deleteArray_TMVRTClass(void *p) {
      delete [] ((::TMVRTClass*)p);
   }
   static void destruct_TMVRTClass(void *p) {
      typedef ::TMVRTClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMVRTClass(TBuffer &buf, void *obj) {
      ((::TMVRTClass*)obj)->::TMVRTClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMVRTClass

namespace {
  void TriggerDictionaryInitialization_TMVRTClassDict_Impl() {
    static const char* headers[] = {
"TMVRTClass.h",
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
#line 1 "TMVRTClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the MVRT bank: Fitted Vertex.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMVRTClass.h")))  TMVRTClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMVRTClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMVRTClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMVRTClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMVRTClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMVRTClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMVRTClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMVRTClassDict() {
  TriggerDictionaryInitialization_TMVRTClassDict_Impl();
}
