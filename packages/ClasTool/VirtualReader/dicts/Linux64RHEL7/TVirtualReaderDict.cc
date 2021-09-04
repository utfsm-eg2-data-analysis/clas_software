// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITVirtualReaderDict
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
#include "TVirtualReader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TVirtualReader(void *p = 0);
   static void *newArray_TVirtualReader(Long_t size, void *p);
   static void delete_TVirtualReader(void *p);
   static void deleteArray_TVirtualReader(void *p);
   static void destruct_TVirtualReader(void *p);
   static void streamer_TVirtualReader(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVirtualReader*)
   {
      ::TVirtualReader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVirtualReader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVirtualReader", ::TVirtualReader::Class_Version(), "TVirtualReader.h", 132,
                  typeid(::TVirtualReader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVirtualReader::Dictionary, isa_proxy, 16,
                  sizeof(::TVirtualReader) );
      instance.SetNew(&new_TVirtualReader);
      instance.SetNewArray(&newArray_TVirtualReader);
      instance.SetDelete(&delete_TVirtualReader);
      instance.SetDeleteArray(&deleteArray_TVirtualReader);
      instance.SetDestructor(&destruct_TVirtualReader);
      instance.SetStreamerFunc(&streamer_TVirtualReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVirtualReader*)
   {
      return GenerateInitInstanceLocal((::TVirtualReader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVirtualReader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TVirtualReader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVirtualReader::Class_Name()
{
   return "TVirtualReader";
}

//______________________________________________________________________________
const char *TVirtualReader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVirtualReader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVirtualReader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVirtualReader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVirtualReader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVirtualReader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVirtualReader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVirtualReader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TVirtualReader::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVirtualReader.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fDebug_Mode;
      R__b >> fCurrentEvent;
      R__b >> fCurrentScaler;
      R__b >> fScalerLastEvt;
      R__b >> fReadScaler;
      R__b >> fReadMCHD;
      R__b >> fReadGSIM;
      R__b >> fUseGSIM;
      R__b >> fThisInstance;
      R__b.CheckByteCount(R__s, R__c, TVirtualReader::IsA());
   } else {
      R__c = R__b.WriteVersion(TVirtualReader::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fDebug_Mode;
      R__b << fCurrentEvent;
      R__b << fCurrentScaler;
      R__b << fScalerLastEvt;
      R__b << fReadScaler;
      R__b << fReadMCHD;
      R__b << fReadGSIM;
      R__b << fUseGSIM;
      R__b << fThisInstance;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVirtualReader(void *p) {
      return  p ? new(p) ::TVirtualReader : new ::TVirtualReader;
   }
   static void *newArray_TVirtualReader(Long_t nElements, void *p) {
      return p ? new(p) ::TVirtualReader[nElements] : new ::TVirtualReader[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVirtualReader(void *p) {
      delete ((::TVirtualReader*)p);
   }
   static void deleteArray_TVirtualReader(void *p) {
      delete [] ((::TVirtualReader*)p);
   }
   static void destruct_TVirtualReader(void *p) {
      typedef ::TVirtualReader current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TVirtualReader(TBuffer &buf, void *obj) {
      ((::TVirtualReader*)obj)->::TVirtualReader::Streamer(buf);
   }
} // end of namespace ROOT for class ::TVirtualReader

namespace {
  void TriggerDictionaryInitialization_TVirtualReaderDict_Impl() {
    static const char* headers[] = {
"TVirtualReader.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/VirtualReader/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TVirtualReaderDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Virtual base class for all reader implementations.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVirtualReader.h")))  TVirtualReader;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TVirtualReaderDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TVirtualReader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TVirtualReader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TVirtualReaderDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TVirtualReaderDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TVirtualReaderDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TVirtualReaderDict() {
  TriggerDictionaryInitialization_TVirtualReaderDict_Impl();
}
