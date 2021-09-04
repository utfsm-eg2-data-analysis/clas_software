// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITS1STClassDict
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
#include "TS1STClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TS1STClass(void *p = 0);
   static void *newArray_TS1STClass(Long_t size, void *p);
   static void delete_TS1STClass(void *p);
   static void deleteArray_TS1STClass(void *p);
   static void destruct_TS1STClass(void *p);
   static void streamer_TS1STClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TS1STClass*)
   {
      ::TS1STClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TS1STClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TS1STClass", ::TS1STClass::Class_Version(), "TS1STClass.h", 20,
                  typeid(::TS1STClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TS1STClass::Dictionary, isa_proxy, 16,
                  sizeof(::TS1STClass) );
      instance.SetNew(&new_TS1STClass);
      instance.SetNewArray(&newArray_TS1STClass);
      instance.SetDelete(&delete_TS1STClass);
      instance.SetDeleteArray(&deleteArray_TS1STClass);
      instance.SetDestructor(&destruct_TS1STClass);
      instance.SetStreamerFunc(&streamer_TS1STClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TS1STClass*)
   {
      return GenerateInitInstanceLocal((::TS1STClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TS1STClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TS1STClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TS1STClass::Class_Name()
{
   return "TS1STClass";
}

//______________________________________________________________________________
const char *TS1STClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TS1STClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TS1STClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TS1STClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TS1STClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TS1STClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TS1STClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TS1STClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TS1STClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TS1STClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Latch1_bit1_count;
      R__b >> Latch1_bit2_count;
      R__b >> Latch1_bit3_count;
      R__b >> Latch1_bit4_count;
      R__b >> Latch1_bit5_count;
      R__b >> Latch1_bit6_count;
      R__b >> Latch1_bit7_count;
      R__b >> Latch1_bit8_count;
      R__b >> Latch1_bit9_count;
      R__b >> Latch1_bit10_count;
      R__b >> Latch1_bit11_count;
      R__b >> Latch1_bit12_count;
      R__b >> Event_count;
      R__b >> Latch1_zero_count;
      R__b >> Latch1_empty_count;
      R__b >> Latch1_not_empty_count;
      R__b >> Latch1_ok_count;
      R__b >> Level2_sector1;
      R__b >> Level2_sector2;
      R__b >> Level2_sector3;
      R__b >> Level2_sector4;
      R__b >> Level2_sector5;
      R__b >> Level2_sector6;
      R__b >> Level2_pass;
      R__b >> Level2_fail;
      R__b >> Latch2_zero_count;
      R__b >> Latch2_empty_count;
      R__b >> Latch2_not_empty_count;
      R__b >> Latch2_ok_count;
      R__b >> Roc_13_count;
      R__b >> Roc_15_count;
      R__b >> L1l2_zero_count;
      R__b >> L1zero_13_count;
      R__b >> L2zero_13_count;
      R__b >> L1l2zero_13_count;
      R__b.CheckByteCount(R__s, R__c, TS1STClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TS1STClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Latch1_bit1_count;
      R__b << Latch1_bit2_count;
      R__b << Latch1_bit3_count;
      R__b << Latch1_bit4_count;
      R__b << Latch1_bit5_count;
      R__b << Latch1_bit6_count;
      R__b << Latch1_bit7_count;
      R__b << Latch1_bit8_count;
      R__b << Latch1_bit9_count;
      R__b << Latch1_bit10_count;
      R__b << Latch1_bit11_count;
      R__b << Latch1_bit12_count;
      R__b << Event_count;
      R__b << Latch1_zero_count;
      R__b << Latch1_empty_count;
      R__b << Latch1_not_empty_count;
      R__b << Latch1_ok_count;
      R__b << Level2_sector1;
      R__b << Level2_sector2;
      R__b << Level2_sector3;
      R__b << Level2_sector4;
      R__b << Level2_sector5;
      R__b << Level2_sector6;
      R__b << Level2_pass;
      R__b << Level2_fail;
      R__b << Latch2_zero_count;
      R__b << Latch2_empty_count;
      R__b << Latch2_not_empty_count;
      R__b << Latch2_ok_count;
      R__b << Roc_13_count;
      R__b << Roc_15_count;
      R__b << L1l2_zero_count;
      R__b << L1zero_13_count;
      R__b << L2zero_13_count;
      R__b << L1l2zero_13_count;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TS1STClass(void *p) {
      return  p ? new(p) ::TS1STClass : new ::TS1STClass;
   }
   static void *newArray_TS1STClass(Long_t nElements, void *p) {
      return p ? new(p) ::TS1STClass[nElements] : new ::TS1STClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TS1STClass(void *p) {
      delete ((::TS1STClass*)p);
   }
   static void deleteArray_TS1STClass(void *p) {
      delete [] ((::TS1STClass*)p);
   }
   static void destruct_TS1STClass(void *p) {
      typedef ::TS1STClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TS1STClass(TBuffer &buf, void *obj) {
      ((::TS1STClass*)obj)->::TS1STClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TS1STClass

namespace {
  void TriggerDictionaryInitialization_TS1STClassDict_Impl() {
    static const char* headers[] = {
"TS1STClass.h",
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
#line 1 "TS1STClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Scaler bank with trigger and latch information)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TS1STClass.h")))  TS1STClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TS1STClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TS1STClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TS1STClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TS1STClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TS1STClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TS1STClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TS1STClassDict() {
  TriggerDictionaryInitialization_TS1STClassDict_Impl();
}
