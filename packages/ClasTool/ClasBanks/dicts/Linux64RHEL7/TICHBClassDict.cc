// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITICHBClassDict
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
#include "TICHBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TICHBClass(void *p = 0);
   static void *newArray_TICHBClass(Long_t size, void *p);
   static void delete_TICHBClass(void *p);
   static void deleteArray_TICHBClass(void *p);
   static void destruct_TICHBClass(void *p);
   static void streamer_TICHBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TICHBClass*)
   {
      ::TICHBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TICHBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TICHBClass", ::TICHBClass::Class_Version(), "TICHBClass.h", 13,
                  typeid(::TICHBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TICHBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TICHBClass) );
      instance.SetNew(&new_TICHBClass);
      instance.SetNewArray(&newArray_TICHBClass);
      instance.SetDelete(&delete_TICHBClass);
      instance.SetDeleteArray(&deleteArray_TICHBClass);
      instance.SetDestructor(&destruct_TICHBClass);
      instance.SetStreamerFunc(&streamer_TICHBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TICHBClass*)
   {
      return GenerateInitInstanceLocal((::TICHBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TICHBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TICHBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TICHBClass::Class_Name()
{
   return "TICHBClass";
}

//______________________________________________________________________________
const char *TICHBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TICHBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TICHBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TICHBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TICHBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TICHBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TICHBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TICHBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TICHBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TICHBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Eclust;
      R__b >> Eclmax;
      R__b >> Tclust;
      R__b >> T_next;
      R__b >> xclust;
      R__b >> yclust;
      R__b >> zclust;
      R__b >> xclmax;
      R__b >> yclmax;
      R__b >> M2_x;
      R__b >> M2_y;
      R__b >> M3_x;
      R__b >> M3_y;
      R__b >> ncryst;
      R__b.CheckByteCount(R__s, R__c, TICHBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TICHBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Eclust;
      R__b << Eclmax;
      R__b << Tclust;
      R__b << T_next;
      R__b << xclust;
      R__b << yclust;
      R__b << zclust;
      R__b << xclmax;
      R__b << yclmax;
      R__b << M2_x;
      R__b << M2_y;
      R__b << M3_x;
      R__b << M3_y;
      R__b << ncryst;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TICHBClass(void *p) {
      return  p ? new(p) ::TICHBClass : new ::TICHBClass;
   }
   static void *newArray_TICHBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TICHBClass[nElements] : new ::TICHBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TICHBClass(void *p) {
      delete ((::TICHBClass*)p);
   }
   static void deleteArray_TICHBClass(void *p) {
      delete [] ((::TICHBClass*)p);
   }
   static void destruct_TICHBClass(void *p) {
      typedef ::TICHBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TICHBClass(TBuffer &buf, void *obj) {
      ((::TICHBClass*)obj)->::TICHBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TICHBClass

namespace {
  void TriggerDictionaryInitialization_TICHBClassDict_Impl() {
    static const char* headers[] = {
"TICHBClass.h",
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
#line 1 "TICHBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TICHBClass.h")))  TICHBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TICHBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TICHBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TICHBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TICHBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TICHBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TICHBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TICHBClassDict() {
  TriggerDictionaryInitialization_TICHBClassDict_Impl();
}
