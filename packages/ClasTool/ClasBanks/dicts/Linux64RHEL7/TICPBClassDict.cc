// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITICPBClassDict
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
#include "TICPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TICPBClass(void *p = 0);
   static void *newArray_TICPBClass(Long_t size, void *p);
   static void delete_TICPBClass(void *p);
   static void deleteArray_TICPBClass(void *p);
   static void destruct_TICPBClass(void *p);
   static void streamer_TICPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TICPBClass*)
   {
      ::TICPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TICPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TICPBClass", ::TICPBClass::Class_Version(), "TICPBClass.h", 22,
                  typeid(::TICPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TICPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TICPBClass) );
      instance.SetNew(&new_TICPBClass);
      instance.SetNewArray(&newArray_TICPBClass);
      instance.SetDelete(&delete_TICPBClass);
      instance.SetDeleteArray(&deleteArray_TICPBClass);
      instance.SetDestructor(&destruct_TICPBClass);
      instance.SetStreamerFunc(&streamer_TICPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TICPBClass*)
   {
      return GenerateInitInstanceLocal((::TICPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TICPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TICPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TICPBClass::Class_Name()
{
   return "TICPBClass";
}

//______________________________________________________________________________
const char *TICPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TICPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TICPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TICPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TICPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TICPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TICPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TICPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TICPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TICPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Etot;
      R__b >> Ecen;
      R__b >> Time;
      R__b >> T_next;
      R__b >> X;
      R__b >> Y;
      R__b >> Z;
      R__b >> M2_hit;
      R__b >> M3_hit;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TICPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TICPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Etot;
      R__b << Ecen;
      R__b << Time;
      R__b << T_next;
      R__b << X;
      R__b << Y;
      R__b << Z;
      R__b << M2_hit;
      R__b << M3_hit;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TICPBClass(void *p) {
      return  p ? new(p) ::TICPBClass : new ::TICPBClass;
   }
   static void *newArray_TICPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TICPBClass[nElements] : new ::TICPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TICPBClass(void *p) {
      delete ((::TICPBClass*)p);
   }
   static void deleteArray_TICPBClass(void *p) {
      delete [] ((::TICPBClass*)p);
   }
   static void destruct_TICPBClass(void *p) {
      typedef ::TICPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TICPBClass(TBuffer &buf, void *obj) {
      ((::TICPBClass*)obj)->::TICPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TICPBClass

namespace {
  void TriggerDictionaryInitialization_TICPBClassDict_Impl() {
    static const char* headers[] = {
"TICPBClass.h",
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
#line 1 "TICPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the CCPB bank: Cherencov.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TICPBClass.h")))  TICPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TICPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TICPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TICPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TICPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TICPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TICPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TICPBClassDict() {
  TriggerDictionaryInitialization_TICPBClassDict_Impl();
}
