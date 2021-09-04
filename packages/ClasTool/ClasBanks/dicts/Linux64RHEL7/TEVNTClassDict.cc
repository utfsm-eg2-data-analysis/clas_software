// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITEVNTClassDict
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
#include "TEVNTClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TEVNTClass(void *p = 0);
   static void *newArray_TEVNTClass(Long_t size, void *p);
   static void delete_TEVNTClass(void *p);
   static void deleteArray_TEVNTClass(void *p);
   static void destruct_TEVNTClass(void *p);
   static void streamer_TEVNTClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEVNTClass*)
   {
      ::TEVNTClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEVNTClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TEVNTClass", ::TEVNTClass::Class_Version(), "TEVNTClass.h", 29,
                  typeid(::TEVNTClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEVNTClass::Dictionary, isa_proxy, 16,
                  sizeof(::TEVNTClass) );
      instance.SetNew(&new_TEVNTClass);
      instance.SetNewArray(&newArray_TEVNTClass);
      instance.SetDelete(&delete_TEVNTClass);
      instance.SetDeleteArray(&deleteArray_TEVNTClass);
      instance.SetDestructor(&destruct_TEVNTClass);
      instance.SetStreamerFunc(&streamer_TEVNTClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEVNTClass*)
   {
      return GenerateInitInstanceLocal((::TEVNTClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TEVNTClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TEVNTClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEVNTClass::Class_Name()
{
   return "TEVNTClass";
}

//______________________________________________________________________________
const char *TEVNTClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEVNTClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEVNTClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEVNTClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEVNTClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEVNTClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEVNTClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEVNTClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TEVNTClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEVNTClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TVirtualData::Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TEVNTClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TEVNTClass::IsA(), kTRUE);
      TVirtualData::Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEVNTClass(void *p) {
      return  p ? new(p) ::TEVNTClass : new ::TEVNTClass;
   }
   static void *newArray_TEVNTClass(Long_t nElements, void *p) {
      return p ? new(p) ::TEVNTClass[nElements] : new ::TEVNTClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEVNTClass(void *p) {
      delete ((::TEVNTClass*)p);
   }
   static void deleteArray_TEVNTClass(void *p) {
      delete [] ((::TEVNTClass*)p);
   }
   static void destruct_TEVNTClass(void *p) {
      typedef ::TEVNTClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TEVNTClass(TBuffer &buf, void *obj) {
      ((::TEVNTClass*)obj)->::TEVNTClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TEVNTClass

namespace {
  void TriggerDictionaryInitialization_TEVNTClassDict_Impl() {
    static const char* headers[] = {
"TEVNTClass.h",
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
#line 1 "TEVNTClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the EVNT bank: particle information)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TEVNTClass.h")))  TEVNTClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TEVNTClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TEVNTClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TEVNTClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TEVNTClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TEVNTClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TEVNTClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TEVNTClassDict() {
  TriggerDictionaryInitialization_TEVNTClassDict_Impl();
}
