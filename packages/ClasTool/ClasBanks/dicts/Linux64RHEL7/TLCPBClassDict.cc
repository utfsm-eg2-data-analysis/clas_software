// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITLCPBClassDict
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
#include "TLCPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TLCPBClass(void *p = 0);
   static void *newArray_TLCPBClass(Long_t size, void *p);
   static void delete_TLCPBClass(void *p);
   static void deleteArray_TLCPBClass(void *p);
   static void destruct_TLCPBClass(void *p);
   static void streamer_TLCPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TLCPBClass*)
   {
      ::TLCPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TLCPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TLCPBClass", ::TLCPBClass::Class_Version(), "TLCPBClass.h", 19,
                  typeid(::TLCPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TLCPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TLCPBClass) );
      instance.SetNew(&new_TLCPBClass);
      instance.SetNewArray(&newArray_TLCPBClass);
      instance.SetDelete(&delete_TLCPBClass);
      instance.SetDeleteArray(&deleteArray_TLCPBClass);
      instance.SetDestructor(&destruct_TLCPBClass);
      instance.SetStreamerFunc(&streamer_TLCPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TLCPBClass*)
   {
      return GenerateInitInstanceLocal((::TLCPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TLCPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TLCPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TLCPBClass::Class_Name()
{
   return "TLCPBClass";
}

//______________________________________________________________________________
const char *TLCPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TLCPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TLCPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TLCPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TLCPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TLCPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TLCPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TLCPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TLCPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TLCPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Scht;
      R__b >> Etot;
      R__b >> Time;
      R__b >> Path;
      R__b >> X;
      R__b >> Y;
      R__b >> Z;
      R__b >> Chi2lc;
      R__b >> Status;
      R__b >> Ein;
      R__b.CheckByteCount(R__s, R__c, TLCPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TLCPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Scht;
      R__b << Etot;
      R__b << Time;
      R__b << Path;
      R__b << X;
      R__b << Y;
      R__b << Z;
      R__b << Chi2lc;
      R__b << Status;
      R__b << Ein;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TLCPBClass(void *p) {
      return  p ? new(p) ::TLCPBClass : new ::TLCPBClass;
   }
   static void *newArray_TLCPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TLCPBClass[nElements] : new ::TLCPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TLCPBClass(void *p) {
      delete ((::TLCPBClass*)p);
   }
   static void deleteArray_TLCPBClass(void *p) {
      delete [] ((::TLCPBClass*)p);
   }
   static void destruct_TLCPBClass(void *p) {
      typedef ::TLCPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TLCPBClass(TBuffer &buf, void *obj) {
      ((::TLCPBClass*)obj)->::TLCPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TLCPBClass

namespace {
  void TriggerDictionaryInitialization_TLCPBClassDict_Impl() {
    static const char* headers[] = {
"TLCPBClass.h",
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
#line 1 "TLCPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the LCPB Bank (Large Angle Calorimeter))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TLCPBClass.h")))  TLCPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TLCPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TLCPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TLCPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TLCPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TLCPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TLCPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TLCPBClassDict() {
  TriggerDictionaryInitialization_TLCPBClassDict_Impl();
}
