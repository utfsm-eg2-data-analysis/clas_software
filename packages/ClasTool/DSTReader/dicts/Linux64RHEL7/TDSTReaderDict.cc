// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITDSTReaderDict
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
#include "TDSTReader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TDSTReader(void *p = 0);
   static void *newArray_TDSTReader(Long_t size, void *p);
   static void delete_TDSTReader(void *p);
   static void deleteArray_TDSTReader(void *p);
   static void destruct_TDSTReader(void *p);
   static void streamer_TDSTReader(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDSTReader*)
   {
      ::TDSTReader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDSTReader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDSTReader", ::TDSTReader::Class_Version(), "TDSTReader.h", 99,
                  typeid(::TDSTReader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDSTReader::Dictionary, isa_proxy, 16,
                  sizeof(::TDSTReader) );
      instance.SetNew(&new_TDSTReader);
      instance.SetNewArray(&newArray_TDSTReader);
      instance.SetDelete(&delete_TDSTReader);
      instance.SetDeleteArray(&deleteArray_TDSTReader);
      instance.SetDestructor(&destruct_TDSTReader);
      instance.SetStreamerFunc(&streamer_TDSTReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDSTReader*)
   {
      return GenerateInitInstanceLocal((::TDSTReader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDSTReader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDSTReader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDSTReader::Class_Name()
{
   return "TDSTReader";
}

//______________________________________________________________________________
const char *TDSTReader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTReader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDSTReader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTReader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDSTReader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTReader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDSTReader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTReader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDSTReader::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDSTReader.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TVirtualReader::Streamer(R__b);
      R__b >> fEvntHeader;
      R__b >> fScalerHead;
      R__b >> fEPIC;
      fClones.Streamer(R__b);
      fScalerClones.Streamer(R__b);
      R__b >> fEventChain;
      R__b >> fScalerChain;
      R__b >> fEPICChain;
      R__b >> fCurrentEPIC;
      R__b >> EPICTable;
      R__b.CheckByteCount(R__s, R__c, TDSTReader::IsA());
   } else {
      R__c = R__b.WriteVersion(TDSTReader::IsA(), kTRUE);
      TVirtualReader::Streamer(R__b);
      R__b << fEvntHeader;
      R__b << fScalerHead;
      R__b << fEPIC;
      fClones.Streamer(R__b);
      fScalerClones.Streamer(R__b);
      R__b << fEventChain;
      R__b << fScalerChain;
      R__b << fEPICChain;
      R__b << fCurrentEPIC;
      R__b << EPICTable;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDSTReader(void *p) {
      return  p ? new(p) ::TDSTReader : new ::TDSTReader;
   }
   static void *newArray_TDSTReader(Long_t nElements, void *p) {
      return p ? new(p) ::TDSTReader[nElements] : new ::TDSTReader[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDSTReader(void *p) {
      delete ((::TDSTReader*)p);
   }
   static void deleteArray_TDSTReader(void *p) {
      delete [] ((::TDSTReader*)p);
   }
   static void destruct_TDSTReader(void *p) {
      typedef ::TDSTReader current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDSTReader(TBuffer &buf, void *obj) {
      ((::TDSTReader*)obj)->::TDSTReader::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDSTReader

namespace {
  void TriggerDictionaryInitialization_TDSTReaderDict_Impl() {
    static const char* headers[] = {
"TDSTReader.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/DSTReader/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TDSTReaderDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A reader interface for ROOT files.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TDSTReader.h")))  TDSTReader;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TDSTReaderDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TDSTReader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TDSTReader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TDSTReaderDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TDSTReaderDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TDSTReaderDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TDSTReaderDict() {
  TriggerDictionaryInitialization_TDSTReaderDict_Impl();
}
