// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITClasToolDict
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
#include "TClasTool.h"

// Header files passed via #pragma extra_include

namespace ClasTool {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *ClasTool_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("ClasTool", 0 /*version*/, "TClasTool.h", 112,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &ClasTool_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *ClasTool_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static void *new_TClasTool(void *p = 0);
   static void *newArray_TClasTool(Long_t size, void *p);
   static void delete_TClasTool(void *p);
   static void deleteArray_TClasTool(void *p);
   static void destruct_TClasTool(void *p);
   static void streamer_TClasTool(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TClasTool*)
   {
      ::TClasTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TClasTool >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TClasTool", ::TClasTool::Class_Version(), "TClasTool.h", 228,
                  typeid(::TClasTool), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TClasTool::Dictionary, isa_proxy, 16,
                  sizeof(::TClasTool) );
      instance.SetNew(&new_TClasTool);
      instance.SetNewArray(&newArray_TClasTool);
      instance.SetDelete(&delete_TClasTool);
      instance.SetDeleteArray(&deleteArray_TClasTool);
      instance.SetDestructor(&destruct_TClasTool);
      instance.SetStreamerFunc(&streamer_TClasTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TClasTool*)
   {
      return GenerateInitInstanceLocal((::TClasTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TClasTool*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TClasTool::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TClasTool::Class_Name()
{
   return "TClasTool";
}

//______________________________________________________________________________
const char *TClasTool::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TClasTool*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TClasTool::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TClasTool*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TClasTool::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TClasTool*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TClasTool::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TClasTool*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TClasTool::Streamer(TBuffer &R__b)
{
   // Stream an object of class TClasTool.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fReader;
      R__b >> fDebug_Mode;
      R__b >> fEBeam;
      R__b >> isReaderDefined;
      R__b.CheckByteCount(R__s, R__c, TClasTool::IsA());
   } else {
      R__c = R__b.WriteVersion(TClasTool::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fReader;
      R__b << fDebug_Mode;
      R__b << fEBeam;
      R__b << isReaderDefined;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TClasTool(void *p) {
      return  p ? new(p) ::TClasTool : new ::TClasTool;
   }
   static void *newArray_TClasTool(Long_t nElements, void *p) {
      return p ? new(p) ::TClasTool[nElements] : new ::TClasTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_TClasTool(void *p) {
      delete ((::TClasTool*)p);
   }
   static void deleteArray_TClasTool(void *p) {
      delete [] ((::TClasTool*)p);
   }
   static void destruct_TClasTool(void *p) {
      typedef ::TClasTool current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TClasTool(TBuffer &buf, void *obj) {
      ((::TClasTool*)obj)->::TClasTool::Streamer(buf);
   }
} // end of namespace ROOT for class ::TClasTool

namespace {
  void TriggerDictionaryInitialization_TClasToolDict_Impl() {
    static const char* headers[] = {
"TClasTool.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/TClasTool/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TClasToolDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Main class for ClasTool package, drives everything else.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TClasTool.h")))  TClasTool;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TClasToolDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TClasTool.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TClasTool", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TClasToolDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TClasToolDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TClasToolDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TClasToolDict() {
  TriggerDictionaryInitialization_TClasToolDict_Impl();
}
