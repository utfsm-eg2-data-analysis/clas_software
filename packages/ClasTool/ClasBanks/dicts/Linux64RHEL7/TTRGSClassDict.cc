// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTRGSClassDict
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
#include "TTRGSClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTRGSClass(void *p = 0);
   static void *newArray_TTRGSClass(Long_t size, void *p);
   static void delete_TTRGSClass(void *p);
   static void deleteArray_TTRGSClass(void *p);
   static void destruct_TTRGSClass(void *p);
   static void streamer_TTRGSClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTRGSClass*)
   {
      ::TTRGSClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTRGSClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTRGSClass", ::TTRGSClass::Class_Version(), "TTRGSClass.h", 20,
                  typeid(::TTRGSClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTRGSClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTRGSClass) );
      instance.SetNew(&new_TTRGSClass);
      instance.SetNewArray(&newArray_TTRGSClass);
      instance.SetDelete(&delete_TTRGSClass);
      instance.SetDeleteArray(&deleteArray_TTRGSClass);
      instance.SetDestructor(&destruct_TTRGSClass);
      instance.SetStreamerFunc(&streamer_TTRGSClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTRGSClass*)
   {
      return GenerateInitInstanceLocal((::TTRGSClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTRGSClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTRGSClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTRGSClass::Class_Name()
{
   return "TTRGSClass";
}

//______________________________________________________________________________
const char *TTRGSClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTRGSClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTRGSClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTRGSClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTRGSClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTRGSClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTRGSClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTRGSClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTRGSClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTRGSClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Clock_ug;
      R__b >> Fcup_ug;
      R__b >> Microsec;
      R__b >> Mor_st;
      R__b >> Mor_pc;
      R__b >> Mor_ps;
      R__b >> Mor_tac;
      R__b >> Mor;
      R__b >> Pc;
      R__b >> Ps;
      R__b >> Tac;
      R__b >> St;
      R__b >> Clock_ug_2;
      R__b >> Fcup_ug_2;
      R__b >> Clock_g1;
      R__b >> Fcup_g1;
      R__b >> Mor_st_rg;
      R__b >> Mor_pc_rg;
      R__b >> Mor_ps_rg;
      R__b >> Mor_tac_rg;
      R__b >> Mor_rg;
      R__b >> Pc_rg;
      R__b >> Ps_rg;
      R__b >> Tac_rg;
      R__b >> St_rg;
      R__b >> Clock_g1_2;
      R__b >> Fcup_g1_2;
      R__b >> Clock_g2;
      R__b >> Fcup_g2;
      R__b >> Mor_lg;
      R__b >> Clock_g2_2;
      R__b >> Fcup_g2_2;
      R__b >> Trig1_ug;
      R__b >> Trig2_ug;
      R__b >> Trig3_ug;
      R__b >> Trig4_ug;
      R__b >> Trig5_ug;
      R__b >> Trig6_ug;
      R__b >> Trig7_ug;
      R__b >> Trig8_ug;
      R__b >> Trig9_ug;
      R__b >> Trig10_ug;
      R__b >> Trig11_ug;
      R__b >> Trig12_ug;
      R__b >> Trig_or_ug;
      R__b >> L1accept;
      R__b >> L2fail;
      R__b >> L2pass;
      R__b >> L2start;
      R__b >> L2clear;
      R__b >> L2accept;
      R__b >> L3accept;
      R__b.CheckByteCount(R__s, R__c, TTRGSClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTRGSClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Clock_ug;
      R__b << Fcup_ug;
      R__b << Microsec;
      R__b << Mor_st;
      R__b << Mor_pc;
      R__b << Mor_ps;
      R__b << Mor_tac;
      R__b << Mor;
      R__b << Pc;
      R__b << Ps;
      R__b << Tac;
      R__b << St;
      R__b << Clock_ug_2;
      R__b << Fcup_ug_2;
      R__b << Clock_g1;
      R__b << Fcup_g1;
      R__b << Mor_st_rg;
      R__b << Mor_pc_rg;
      R__b << Mor_ps_rg;
      R__b << Mor_tac_rg;
      R__b << Mor_rg;
      R__b << Pc_rg;
      R__b << Ps_rg;
      R__b << Tac_rg;
      R__b << St_rg;
      R__b << Clock_g1_2;
      R__b << Fcup_g1_2;
      R__b << Clock_g2;
      R__b << Fcup_g2;
      R__b << Mor_lg;
      R__b << Clock_g2_2;
      R__b << Fcup_g2_2;
      R__b << Trig1_ug;
      R__b << Trig2_ug;
      R__b << Trig3_ug;
      R__b << Trig4_ug;
      R__b << Trig5_ug;
      R__b << Trig6_ug;
      R__b << Trig7_ug;
      R__b << Trig8_ug;
      R__b << Trig9_ug;
      R__b << Trig10_ug;
      R__b << Trig11_ug;
      R__b << Trig12_ug;
      R__b << Trig_or_ug;
      R__b << L1accept;
      R__b << L2fail;
      R__b << L2pass;
      R__b << L2start;
      R__b << L2clear;
      R__b << L2accept;
      R__b << L3accept;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTRGSClass(void *p) {
      return  p ? new(p) ::TTRGSClass : new ::TTRGSClass;
   }
   static void *newArray_TTRGSClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTRGSClass[nElements] : new ::TTRGSClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTRGSClass(void *p) {
      delete ((::TTRGSClass*)p);
   }
   static void deleteArray_TTRGSClass(void *p) {
      delete [] ((::TTRGSClass*)p);
   }
   static void destruct_TTRGSClass(void *p) {
      typedef ::TTRGSClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTRGSClass(TBuffer &buf, void *obj) {
      ((::TTRGSClass*)obj)->::TTRGSClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTRGSClass

namespace {
  void TriggerDictionaryInitialization_TTRGSClassDict_Impl() {
    static const char* headers[] = {
"TTRGSClass.h",
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
#line 1 "TTRGSClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Scaler bank TRGS for trigger, MOR and counters.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTRGSClass.h")))  TTRGSClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTRGSClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTRGSClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTRGSClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTRGSClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTRGSClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTRGSClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTRGSClassDict() {
  TriggerDictionaryInitialization_TTRGSClassDict_Impl();
}
