// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTGPBClassDict
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
#include "TTGPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTGPBClass(void *p = 0);
   static void *newArray_TTGPBClass(Long_t size, void *p);
   static void delete_TTGPBClass(void *p);
   static void deleteArray_TTGPBClass(void *p);
   static void destruct_TTGPBClass(void *p);
   static void streamer_TTGPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTGPBClass*)
   {
      ::TTGPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTGPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTGPBClass", ::TTGPBClass::Class_Version(), "TTGPBClass.h", 16,
                  typeid(::TTGPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTGPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTGPBClass) );
      instance.SetNew(&new_TTGPBClass);
      instance.SetNewArray(&newArray_TTGPBClass);
      instance.SetDelete(&delete_TTGPBClass);
      instance.SetDeleteArray(&deleteArray_TTGPBClass);
      instance.SetDestructor(&destruct_TTGPBClass);
      instance.SetStreamerFunc(&streamer_TTGPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTGPBClass*)
   {
      return GenerateInitInstanceLocal((::TTGPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTGPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTGPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTGPBClass::Class_Name()
{
   return "TTGPBClass";
}

//______________________________________________________________________________
const char *TTGPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTGPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTGPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTGPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTGPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTGPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTGPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTGPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTGPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTGPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> pointer;
      R__b >> Time;
      R__b >> Energy;
      R__b >> dt;
      R__b.CheckByteCount(R__s, R__c, TTGPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTGPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << pointer;
      R__b << Time;
      R__b << Energy;
      R__b << dt;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTGPBClass(void *p) {
      return  p ? new(p) ::TTGPBClass : new ::TTGPBClass;
   }
   static void *newArray_TTGPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTGPBClass[nElements] : new ::TTGPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTGPBClass(void *p) {
      delete ((::TTGPBClass*)p);
   }
   static void deleteArray_TTGPBClass(void *p) {
      delete [] ((::TTGPBClass*)p);
   }
   static void destruct_TTGPBClass(void *p) {
      typedef ::TTGPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTGPBClass(TBuffer &buf, void *obj) {
      ((::TTGPBClass*)obj)->::TTGPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTGPBClass

namespace {
  void TriggerDictionaryInitialization_TTGPBClassDict_Impl() {
    static const char* headers[] = {
"TTGPBClass.h",
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
#line 1 "TTGPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TGPB bank: Tagger)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTGPBClass.h")))  TTGPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTGPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTGPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTGPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTGPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTGPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTGPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTGPBClassDict() {
  TriggerDictionaryInitialization_TTGPBClassDict_Impl();
}
