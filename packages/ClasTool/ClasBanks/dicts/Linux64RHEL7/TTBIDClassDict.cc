// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTBIDClassDict
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
#include "TTBIDClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTBIDClass(void *p = 0);
   static void *newArray_TTBIDClass(Long_t size, void *p);
   static void delete_TTBIDClass(void *p);
   static void deleteArray_TTBIDClass(void *p);
   static void destruct_TTBIDClass(void *p);
   static void streamer_TTBIDClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTBIDClass*)
   {
      ::TTBIDClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTBIDClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTBIDClass", ::TTBIDClass::Class_Version(), "TTBIDClass.h", 10,
                  typeid(::TTBIDClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTBIDClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTBIDClass) );
      instance.SetNew(&new_TTBIDClass);
      instance.SetNewArray(&newArray_TTBIDClass);
      instance.SetDelete(&delete_TTBIDClass);
      instance.SetDeleteArray(&deleteArray_TTBIDClass);
      instance.SetDestructor(&destruct_TTBIDClass);
      instance.SetStreamerFunc(&streamer_TTBIDClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTBIDClass*)
   {
      return GenerateInitInstanceLocal((::TTBIDClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTBIDClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTBIDClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTBIDClass::Class_Name()
{
   return "TTBIDClass";
}

//______________________________________________________________________________
const char *TTBIDClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBIDClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTBIDClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBIDClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTBIDClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBIDClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTBIDClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBIDClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTBIDClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTBIDClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> track;
      R__b >> sec;
      R__b >> beta;
      R__b >> vtime;
      R__b >> sc_stat;
      R__b >> sc_id;
      R__b >> sc_time;
      R__b >> sc_qual;
      R__b >> sc_vtime;
      R__b >> sc_beta;
      R__b >> cc_stat;
      R__b >> cc_id;
      R__b >> cc_time;
      R__b >> cc_qual;
      R__b >> cc_vtime;
      R__b >> cc_beta;
      R__b >> ec_stat;
      R__b >> ec_id;
      R__b >> ec_time;
      R__b >> ec_qual;
      R__b >> ec_vtime;
      R__b >> ec_beta;
      R__b >> st_stat;
      R__b >> st_id;
      R__b >> st_time;
      R__b >> st_qual;
      R__b >> st_vtime;
      R__b >> st_beta;
      R__b >> lac_stat;
      R__b >> lac_id;
      R__b >> lac_time;
      R__b >> lac_qual;
      R__b >> lac_vtime;
      R__b >> lac_beta;
      R__b.CheckByteCount(R__s, R__c, TTBIDClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTBIDClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << track;
      R__b << sec;
      R__b << beta;
      R__b << vtime;
      R__b << sc_stat;
      R__b << sc_id;
      R__b << sc_time;
      R__b << sc_qual;
      R__b << sc_vtime;
      R__b << sc_beta;
      R__b << cc_stat;
      R__b << cc_id;
      R__b << cc_time;
      R__b << cc_qual;
      R__b << cc_vtime;
      R__b << cc_beta;
      R__b << ec_stat;
      R__b << ec_id;
      R__b << ec_time;
      R__b << ec_qual;
      R__b << ec_vtime;
      R__b << ec_beta;
      R__b << st_stat;
      R__b << st_id;
      R__b << st_time;
      R__b << st_qual;
      R__b << st_vtime;
      R__b << st_beta;
      R__b << lac_stat;
      R__b << lac_id;
      R__b << lac_time;
      R__b << lac_qual;
      R__b << lac_vtime;
      R__b << lac_beta;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTBIDClass(void *p) {
      return  p ? new(p) ::TTBIDClass : new ::TTBIDClass;
   }
   static void *newArray_TTBIDClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTBIDClass[nElements] : new ::TTBIDClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTBIDClass(void *p) {
      delete ((::TTBIDClass*)p);
   }
   static void deleteArray_TTBIDClass(void *p) {
      delete [] ((::TTBIDClass*)p);
   }
   static void destruct_TTBIDClass(void *p) {
      typedef ::TTBIDClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTBIDClass(TBuffer &buf, void *obj) {
      ((::TTBIDClass*)obj)->::TTBIDClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTBIDClass

namespace {
  void TriggerDictionaryInitialization_TTBIDClassDict_Impl() {
    static const char* headers[] = {
"TTBIDClass.h",
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
#line 1 "TTBIDClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TBER bank: Tracking error information.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTBIDClass.h")))  TTBIDClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTBIDClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTBIDClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTBIDClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTBIDClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTBIDClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTBIDClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTBIDClassDict() {
  TriggerDictionaryInitialization_TTBIDClassDict_Impl();
}
