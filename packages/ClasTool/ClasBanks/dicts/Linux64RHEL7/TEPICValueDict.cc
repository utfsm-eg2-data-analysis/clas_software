// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITEPICValueDict
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
#include "TEPICValue.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TEPICValue(void *p = 0);
   static void *newArray_TEPICValue(Long_t size, void *p);
   static void delete_TEPICValue(void *p);
   static void deleteArray_TEPICValue(void *p);
   static void destruct_TEPICValue(void *p);
   static void streamer_TEPICValue(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEPICValue*)
   {
      ::TEPICValue *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEPICValue >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEPICValue", ::TEPICValue::Class_Version(), "TEPICValue.h", 26,
                  typeid(::TEPICValue), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEPICValue::Dictionary, isa_proxy, 16,
                  sizeof(::TEPICValue) );
      instance.SetNew(&new_TEPICValue);
      instance.SetNewArray(&newArray_TEPICValue);
      instance.SetDelete(&delete_TEPICValue);
      instance.SetDeleteArray(&deleteArray_TEPICValue);
      instance.SetDestructor(&destruct_TEPICValue);
      instance.SetStreamerFunc(&streamer_TEPICValue);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEPICValue*)
   {
      return GenerateInitInstanceLocal((::TEPICValue*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEPICValue*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TEPICValue::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEPICValue::Class_Name()
{
   return "TEPICValue";
}

//______________________________________________________________________________
const char *TEPICValue::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEPICValue*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEPICValue::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEPICValue*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEPICValue::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEPICValue*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEPICValue::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEPICValue*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TEPICValue::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEPICValue.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      fName.Streamer(R__b);
      R__b >> fValue;
      R__b.CheckByteCount(R__s, R__c, TEPICValue::IsA());
   } else {
      R__c = R__b.WriteVersion(TEPICValue::IsA(), kTRUE);
      TObject::Streamer(R__b);
      fName.Streamer(R__b);
      R__b << fValue;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEPICValue(void *p) {
      return  p ? new(p) ::TEPICValue : new ::TEPICValue;
   }
   static void *newArray_TEPICValue(Long_t nElements, void *p) {
      return p ? new(p) ::TEPICValue[nElements] : new ::TEPICValue[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEPICValue(void *p) {
      delete ((::TEPICValue*)p);
   }
   static void deleteArray_TEPICValue(void *p) {
      delete [] ((::TEPICValue*)p);
   }
   static void destruct_TEPICValue(void *p) {
      typedef ::TEPICValue current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TEPICValue(TBuffer &buf, void *obj) {
      ((::TEPICValue*)obj)->::TEPICValue::Streamer(buf);
   }
} // end of namespace ROOT for class ::TEPICValue

namespace {
  void TriggerDictionaryInitialization_TEPICValueDict_Impl() {
    static const char* headers[] = {
"TEPICValue.h",
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
#line 1 "TEPICValueDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Container for TEPICClass)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TEPICValue.h")))  TEPICValue;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TEPICValueDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TEPICValue.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TEPICValue", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TEPICValueDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TEPICValueDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TEPICValueDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TEPICValueDict() {
  TriggerDictionaryInitialization_TEPICValueDict_Impl();
}
