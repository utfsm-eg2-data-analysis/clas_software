// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITVERTClassDict
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
#include "TVERTClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TVERTClass(void *p = 0);
   static void *newArray_TVERTClass(Long_t size, void *p);
   static void delete_TVERTClass(void *p);
   static void deleteArray_TVERTClass(void *p);
   static void destruct_TVERTClass(void *p);
   static void streamer_TVERTClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVERTClass*)
   {
      ::TVERTClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVERTClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVERTClass", ::TVERTClass::Class_Version(), "TVERTClass.h", 19,
                  typeid(::TVERTClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVERTClass::Dictionary, isa_proxy, 16,
                  sizeof(::TVERTClass) );
      instance.SetNew(&new_TVERTClass);
      instance.SetNewArray(&newArray_TVERTClass);
      instance.SetDelete(&delete_TVERTClass);
      instance.SetDeleteArray(&deleteArray_TVERTClass);
      instance.SetDestructor(&destruct_TVERTClass);
      instance.SetStreamerFunc(&streamer_TVERTClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVERTClass*)
   {
      return GenerateInitInstanceLocal((::TVERTClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVERTClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TVERTClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVERTClass::Class_Name()
{
   return "TVERTClass";
}

//______________________________________________________________________________
const char *TVERTClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVERTClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVERTClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVERTClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVERTClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVERTClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVERTClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVERTClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TVERTClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVERTClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> vertex;
      R__b >> trk1;
      R__b >> trk2;
      R__b >> x;
      R__b >> y;
      R__b >> z;
      R__b >> sepd;
      R__b.CheckByteCount(R__s, R__c, TVERTClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TVERTClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << vertex;
      R__b << trk1;
      R__b << trk2;
      R__b << x;
      R__b << y;
      R__b << z;
      R__b << sepd;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVERTClass(void *p) {
      return  p ? new(p) ::TVERTClass : new ::TVERTClass;
   }
   static void *newArray_TVERTClass(Long_t nElements, void *p) {
      return p ? new(p) ::TVERTClass[nElements] : new ::TVERTClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVERTClass(void *p) {
      delete ((::TVERTClass*)p);
   }
   static void deleteArray_TVERTClass(void *p) {
      delete [] ((::TVERTClass*)p);
   }
   static void destruct_TVERTClass(void *p) {
      typedef ::TVERTClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TVERTClass(TBuffer &buf, void *obj) {
      ((::TVERTClass*)obj)->::TVERTClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TVERTClass

namespace {
  void TriggerDictionaryInitialization_TVERTClassDict_Impl() {
    static const char* headers[] = {
"TVERTClass.h",
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
#line 1 "TVERTClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the VERT bank, 2 track vertexes.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVERTClass.h")))  TVERTClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TVERTClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TVERTClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TVERTClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TVERTClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TVERTClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TVERTClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TVERTClassDict() {
  TriggerDictionaryInitialization_TVERTClassDict_Impl();
}
