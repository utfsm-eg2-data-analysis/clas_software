// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITVirtualDataDict
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
#include "TVirtualData.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TVirtualData(void *p = 0);
   static void *newArray_TVirtualData(Long_t size, void *p);
   static void delete_TVirtualData(void *p);
   static void deleteArray_TVirtualData(void *p);
   static void destruct_TVirtualData(void *p);
   static void streamer_TVirtualData(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVirtualData*)
   {
      ::TVirtualData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVirtualData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVirtualData", ::TVirtualData::Class_Version(), "TVirtualData.h", 22,
                  typeid(::TVirtualData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVirtualData::Dictionary, isa_proxy, 16,
                  sizeof(::TVirtualData) );
      instance.SetNew(&new_TVirtualData);
      instance.SetNewArray(&newArray_TVirtualData);
      instance.SetDelete(&delete_TVirtualData);
      instance.SetDeleteArray(&deleteArray_TVirtualData);
      instance.SetDestructor(&destruct_TVirtualData);
      instance.SetStreamerFunc(&streamer_TVirtualData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVirtualData*)
   {
      return GenerateInitInstanceLocal((::TVirtualData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVirtualData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TVirtualData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVirtualData::Class_Name()
{
   return "TVirtualData";
}

//______________________________________________________________________________
const char *TVirtualData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVirtualData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVirtualData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVirtualData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVirtualData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVirtualData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVirtualData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVirtualData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TVirtualData::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVirtualData.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Id;
      R__b >> Charge;
      R__b >> Betta;
      R__b >> Px;
      R__b >> Py;
      R__b >> Pz;
      R__b >> X;
      R__b >> Y;
      R__b >> Z;
      R__b >> Dcstat;
      R__b >> Ccstat;
      R__b >> Scstat;
      R__b >> Ecstat;
      R__b >> Lcstat;
      R__b >> Ststat;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TVirtualData::IsA());
   } else {
      R__c = R__b.WriteVersion(TVirtualData::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Id;
      R__b << Charge;
      R__b << Betta;
      R__b << Px;
      R__b << Py;
      R__b << Pz;
      R__b << X;
      R__b << Y;
      R__b << Z;
      R__b << Dcstat;
      R__b << Ccstat;
      R__b << Scstat;
      R__b << Ecstat;
      R__b << Lcstat;
      R__b << Ststat;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVirtualData(void *p) {
      return  p ? new(p) ::TVirtualData : new ::TVirtualData;
   }
   static void *newArray_TVirtualData(Long_t nElements, void *p) {
      return p ? new(p) ::TVirtualData[nElements] : new ::TVirtualData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVirtualData(void *p) {
      delete ((::TVirtualData*)p);
   }
   static void deleteArray_TVirtualData(void *p) {
      delete [] ((::TVirtualData*)p);
   }
   static void destruct_TVirtualData(void *p) {
      typedef ::TVirtualData current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TVirtualData(TBuffer &buf, void *obj) {
      ((::TVirtualData*)obj)->::TVirtualData::Streamer(buf);
   }
} // end of namespace ROOT for class ::TVirtualData

namespace {
  void TriggerDictionaryInitialization_TVirtualDataDict_Impl() {
    static const char* headers[] = {
"TVirtualData.h",
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
#line 1 "TVirtualDataDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Virtual base Class for accessing the EVNT bank: particle information. Version 3.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVirtualData.h")))  TVirtualData;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TVirtualDataDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TVirtualData.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TVirtualData", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TVirtualDataDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TVirtualDataDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TVirtualDataDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TVirtualDataDict() {
  TriggerDictionaryInitialization_TVirtualDataDict_Impl();
}
