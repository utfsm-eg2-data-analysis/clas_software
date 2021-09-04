// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTBERClassDict
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
#include "TTBERClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTBERClass(void *p = 0);
   static void *newArray_TTBERClass(Long_t size, void *p);
   static void delete_TTBERClass(void *p);
   static void deleteArray_TTBERClass(void *p);
   static void destruct_TTBERClass(void *p);
   static void streamer_TTBERClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTBERClass*)
   {
      ::TTBERClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTBERClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTBERClass", ::TTBERClass::Class_Version(), "TTBERClass.h", 70,
                  typeid(::TTBERClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTBERClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTBERClass) );
      instance.SetNew(&new_TTBERClass);
      instance.SetNewArray(&newArray_TTBERClass);
      instance.SetDelete(&delete_TTBERClass);
      instance.SetDeleteArray(&deleteArray_TTBERClass);
      instance.SetDestructor(&destruct_TTBERClass);
      instance.SetStreamerFunc(&streamer_TTBERClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTBERClass*)
   {
      return GenerateInitInstanceLocal((::TTBERClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTBERClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTBERClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTBERClass::Class_Name()
{
   return "TTBERClass";
}

//______________________________________________________________________________
const char *TTBERClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBERClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTBERClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBERClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTBERClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBERClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTBERClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBERClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTBERClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTBERClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> q_over_p;
      R__b >> lambda;
      R__b >> phi;
      R__b >> d0;
      R__b >> z0;
      R__b >> chi2;
      R__b >> layinfo1;
      R__b >> layinfo2;
      R__b >> c11;
      R__b >> c12;
      R__b >> c13;
      R__b >> c14;
      R__b >> c15;
      R__b >> c22;
      R__b >> c23;
      R__b >> c24;
      R__b >> c25;
      R__b >> c33;
      R__b >> c34;
      R__b >> c35;
      R__b >> c44;
      R__b >> c45;
      R__b >> c55;
      R__b.CheckByteCount(R__s, R__c, TTBERClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTBERClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << q_over_p;
      R__b << lambda;
      R__b << phi;
      R__b << d0;
      R__b << z0;
      R__b << chi2;
      R__b << layinfo1;
      R__b << layinfo2;
      R__b << c11;
      R__b << c12;
      R__b << c13;
      R__b << c14;
      R__b << c15;
      R__b << c22;
      R__b << c23;
      R__b << c24;
      R__b << c25;
      R__b << c33;
      R__b << c34;
      R__b << c35;
      R__b << c44;
      R__b << c45;
      R__b << c55;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTBERClass(void *p) {
      return  p ? new(p) ::TTBERClass : new ::TTBERClass;
   }
   static void *newArray_TTBERClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTBERClass[nElements] : new ::TTBERClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTBERClass(void *p) {
      delete ((::TTBERClass*)p);
   }
   static void deleteArray_TTBERClass(void *p) {
      delete [] ((::TTBERClass*)p);
   }
   static void destruct_TTBERClass(void *p) {
      typedef ::TTBERClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTBERClass(TBuffer &buf, void *obj) {
      ((::TTBERClass*)obj)->::TTBERClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTBERClass

namespace {
  void TriggerDictionaryInitialization_TTBERClassDict_Impl() {
    static const char* headers[] = {
"TTBERClass.h",
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
#line 1 "TTBERClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TBER bank: Tracking error information.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTBERClass.h")))  TTBERClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTBERClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTBERClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTBERClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTBERClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTBERClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTBERClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTBERClassDict() {
  TriggerDictionaryInitialization_TTBERClassDict_Impl();
}
