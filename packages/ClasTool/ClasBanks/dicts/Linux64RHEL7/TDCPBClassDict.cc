// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITDCPBClassDict
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
#include "TDCPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TDCPBClass(void *p = 0);
   static void *newArray_TDCPBClass(Long_t size, void *p);
   static void delete_TDCPBClass(void *p);
   static void deleteArray_TDCPBClass(void *p);
   static void destruct_TDCPBClass(void *p);
   static void streamer_TDCPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDCPBClass*)
   {
      ::TDCPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDCPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDCPBClass", ::TDCPBClass::Class_Version(), "TDCPBClass.h", 28,
                  typeid(::TDCPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDCPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TDCPBClass) );
      instance.SetNew(&new_TDCPBClass);
      instance.SetNewArray(&newArray_TDCPBClass);
      instance.SetDelete(&delete_TDCPBClass);
      instance.SetDeleteArray(&deleteArray_TDCPBClass);
      instance.SetDestructor(&destruct_TDCPBClass);
      instance.SetStreamerFunc(&streamer_TDCPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDCPBClass*)
   {
      return GenerateInitInstanceLocal((::TDCPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDCPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDCPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDCPBClass::Class_Name()
{
   return "TDCPBClass";
}

//______________________________________________________________________________
const char *TDCPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDCPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDCPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDCPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDCPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDCPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDCPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDCPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDCPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDCPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Sctr;
      R__b >> X_sc;
      R__b >> Y_sc;
      R__b >> Z_sc;
      R__b >> Cx_sc;
      R__b >> Cy_sc;
      R__b >> Cz_sc;
      R__b >> X_ec;
      R__b >> Y_ec;
      R__b >> Z_ec;
      R__b >> Th_cc;
      R__b >> Chi2;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TDCPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TDCPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Sctr;
      R__b << X_sc;
      R__b << Y_sc;
      R__b << Z_sc;
      R__b << Cx_sc;
      R__b << Cy_sc;
      R__b << Cz_sc;
      R__b << X_ec;
      R__b << Y_ec;
      R__b << Z_ec;
      R__b << Th_cc;
      R__b << Chi2;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDCPBClass(void *p) {
      return  p ? new(p) ::TDCPBClass : new ::TDCPBClass;
   }
   static void *newArray_TDCPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TDCPBClass[nElements] : new ::TDCPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDCPBClass(void *p) {
      delete ((::TDCPBClass*)p);
   }
   static void deleteArray_TDCPBClass(void *p) {
      delete [] ((::TDCPBClass*)p);
   }
   static void destruct_TDCPBClass(void *p) {
      typedef ::TDCPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDCPBClass(TBuffer &buf, void *obj) {
      ((::TDCPBClass*)obj)->::TDCPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDCPBClass

namespace {
  void TriggerDictionaryInitialization_TDCPBClassDict_Impl() {
    static const char* headers[] = {
"TDCPBClass.h",
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
#line 1 "TDCPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the DCPB bank: Drift Chambers)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TDCPBClass.h")))  TDCPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TDCPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TDCPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TDCPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TDCPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TDCPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TDCPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TDCPBClassDict() {
  TriggerDictionaryInitialization_TDCPBClassDict_Impl();
}
