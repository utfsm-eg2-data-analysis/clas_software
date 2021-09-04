// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITMapUtilsDict
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
#include "TMapUtils.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TMapUtils(void *p = 0);
   static void *newArray_TMapUtils(Long_t size, void *p);
   static void delete_TMapUtils(void *p);
   static void deleteArray_TMapUtils(void *p);
   static void destruct_TMapUtils(void *p);
   static void streamer_TMapUtils(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMapUtils*)
   {
      ::TMapUtils *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMapUtils >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMapUtils", ::TMapUtils::Class_Version(), "TMapUtils.h", 55,
                  typeid(::TMapUtils), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMapUtils::Dictionary, isa_proxy, 16,
                  sizeof(::TMapUtils) );
      instance.SetNew(&new_TMapUtils);
      instance.SetNewArray(&newArray_TMapUtils);
      instance.SetDelete(&delete_TMapUtils);
      instance.SetDeleteArray(&deleteArray_TMapUtils);
      instance.SetDestructor(&destruct_TMapUtils);
      instance.SetStreamerFunc(&streamer_TMapUtils);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMapUtils*)
   {
      return GenerateInitInstanceLocal((::TMapUtils*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMapUtils*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TMapUtils::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMapUtils::Class_Name()
{
   return "TMapUtils";
}

//______________________________________________________________________________
const char *TMapUtils::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMapUtils*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMapUtils::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMapUtils*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMapUtils::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMapUtils*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMapUtils::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMapUtils*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TMapUtils::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMapUtils.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      fHOSTNAME.Streamer(R__b);
      fDATABASE.Streamer(R__b);
      fUSERNAME.Streamer(R__b);
      fPASSWORD.Streamer(R__b);
      fRun_INDEX_Table.Streamer(R__b);
      R__b >> fDebugMode;
      fItemValueVersion.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TMapUtils::IsA());
   } else {
      R__c = R__b.WriteVersion(TMapUtils::IsA(), kTRUE);
      TObject::Streamer(R__b);
      fHOSTNAME.Streamer(R__b);
      fDATABASE.Streamer(R__b);
      fUSERNAME.Streamer(R__b);
      fPASSWORD.Streamer(R__b);
      fRun_INDEX_Table.Streamer(R__b);
      R__b << fDebugMode;
      fItemValueVersion.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMapUtils(void *p) {
      return  p ? new(p) ::TMapUtils : new ::TMapUtils;
   }
   static void *newArray_TMapUtils(Long_t nElements, void *p) {
      return p ? new(p) ::TMapUtils[nElements] : new ::TMapUtils[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMapUtils(void *p) {
      delete ((::TMapUtils*)p);
   }
   static void deleteArray_TMapUtils(void *p) {
      delete [] ((::TMapUtils*)p);
   }
   static void destruct_TMapUtils(void *p) {
      typedef ::TMapUtils current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TMapUtils(TBuffer &buf, void *obj) {
      ((::TMapUtils*)obj)->::TMapUtils::Streamer(buf);
   }
} // end of namespace ROOT for class ::TMapUtils

namespace {
  void TriggerDictionaryInitialization_TMapUtilsDict_Impl() {
    static const char* headers[] = {
"TMapUtils.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/MapUtils/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TMapUtilsDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class of Tools for Calibration Constant Maps)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TMapUtils.h")))  TMapUtils;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TMapUtilsDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TMapUtils.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMapUtils", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TMapUtilsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TMapUtilsDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TMapUtilsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TMapUtilsDict() {
  TriggerDictionaryInitialization_TMapUtilsDict_Impl();
}
