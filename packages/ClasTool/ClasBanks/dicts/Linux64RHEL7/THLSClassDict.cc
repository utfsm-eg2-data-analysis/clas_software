// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITHLSClassDict
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
#include "THLSClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_THLSClass(void *p = 0);
   static void *newArray_THLSClass(Long_t size, void *p);
   static void delete_THLSClass(void *p);
   static void deleteArray_THLSClass(void *p);
   static void destruct_THLSClass(void *p);
   static void streamer_THLSClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::THLSClass*)
   {
      ::THLSClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::THLSClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("THLSClass", ::THLSClass::Class_Version(), "THLSClass.h", 23,
                  typeid(::THLSClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::THLSClass::Dictionary, isa_proxy, 16,
                  sizeof(::THLSClass) );
      instance.SetNew(&new_THLSClass);
      instance.SetNewArray(&newArray_THLSClass);
      instance.SetDelete(&delete_THLSClass);
      instance.SetDeleteArray(&deleteArray_THLSClass);
      instance.SetDestructor(&destruct_THLSClass);
      instance.SetStreamerFunc(&streamer_THLSClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::THLSClass*)
   {
      return GenerateInitInstanceLocal((::THLSClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::THLSClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr THLSClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *THLSClass::Class_Name()
{
   return "THLSClass";
}

//______________________________________________________________________________
const char *THLSClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THLSClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int THLSClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THLSClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *THLSClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THLSClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *THLSClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THLSClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void THLSClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class THLSClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> TenMhz;
      R__b >> OTR1;
      R__b >> OTR2;
      R__b >> SLM;
      R__b >> LVL1R;
      R__b >> LRC;
      R__b >> LRA;
      R__b >> Fci;
      R__b >> Pmt1;
      R__b >> Pmt2;
      R__b >> Pmt3;
      R__b >> Pmt4;
      R__b >> Res1;
      R__b >> Res2;
      R__b >> HelAcc;
      R__b >> HLSAcc;
      R__b.CheckByteCount(R__s, R__c, THLSClass::IsA());
   } else {
      R__c = R__b.WriteVersion(THLSClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << TenMhz;
      R__b << OTR1;
      R__b << OTR2;
      R__b << SLM;
      R__b << LVL1R;
      R__b << LRC;
      R__b << LRA;
      R__b << Fci;
      R__b << Pmt1;
      R__b << Pmt2;
      R__b << Pmt3;
      R__b << Pmt4;
      R__b << Res1;
      R__b << Res2;
      R__b << HelAcc;
      R__b << HLSAcc;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_THLSClass(void *p) {
      return  p ? new(p) ::THLSClass : new ::THLSClass;
   }
   static void *newArray_THLSClass(Long_t nElements, void *p) {
      return p ? new(p) ::THLSClass[nElements] : new ::THLSClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_THLSClass(void *p) {
      delete ((::THLSClass*)p);
   }
   static void deleteArray_THLSClass(void *p) {
      delete [] ((::THLSClass*)p);
   }
   static void destruct_THLSClass(void *p) {
      typedef ::THLSClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_THLSClass(TBuffer &buf, void *obj) {
      ((::THLSClass*)obj)->::THLSClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::THLSClass

namespace {
  void TriggerDictionaryInitialization_THLSClassDict_Impl() {
    static const char* headers[] = {
"THLSClass.h",
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
#line 1 "THLSClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Scaler Bank HLS for Helicity related signals)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$THLSClass.h")))  THLSClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "THLSClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "THLSClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"THLSClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("THLSClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_THLSClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_THLSClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_THLSClassDict() {
  TriggerDictionaryInitialization_THLSClassDict_Impl();
}
