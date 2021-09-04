// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITHEADERClassDict
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
#include "THEADERClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_THEADERClass(void *p = 0);
   static void *newArray_THEADERClass(Long_t size, void *p);
   static void delete_THEADERClass(void *p);
   static void deleteArray_THEADERClass(void *p);
   static void destruct_THEADERClass(void *p);
   static void streamer_THEADERClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::THEADERClass*)
   {
      ::THEADERClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::THEADERClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("THEADERClass", ::THEADERClass::Class_Version(), "THEADERClass.h", 21,
                  typeid(::THEADERClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::THEADERClass::Dictionary, isa_proxy, 17,
                  sizeof(::THEADERClass) );
      instance.SetNew(&new_THEADERClass);
      instance.SetNewArray(&newArray_THEADERClass);
      instance.SetDelete(&delete_THEADERClass);
      instance.SetDeleteArray(&deleteArray_THEADERClass);
      instance.SetDestructor(&destruct_THEADERClass);
      instance.SetStreamerFunc(&streamer_THEADERClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::THEADERClass*)
   {
      return GenerateInitInstanceLocal((::THEADERClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::THEADERClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr THEADERClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *THEADERClass::Class_Name()
{
   return "THEADERClass";
}

//______________________________________________________________________________
const char *THEADERClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THEADERClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int THEADERClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THEADERClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *THEADERClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THEADERClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *THEADERClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THEADERClass*)0x0)->GetClass(); }
   return fgIsA;
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_THEADERClass(void *p) {
      return  p ? new(p) ::THEADERClass : new ::THEADERClass;
   }
   static void *newArray_THEADERClass(Long_t nElements, void *p) {
      return p ? new(p) ::THEADERClass[nElements] : new ::THEADERClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_THEADERClass(void *p) {
      delete ((::THEADERClass*)p);
   }
   static void deleteArray_THEADERClass(void *p) {
      delete [] ((::THEADERClass*)p);
   }
   static void destruct_THEADERClass(void *p) {
      typedef ::THEADERClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_THEADERClass(TBuffer &buf, void *obj) {
      ((::THEADERClass*)obj)->::THEADERClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::THEADERClass

namespace {
  void TriggerDictionaryInitialization_THEADERClassDict_Impl() {
    static const char* headers[] = {
"THEADERClass.h",
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
#line 1 "THEADERClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class containing all the header information for an event.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$THEADERClass.h")))  THEADERClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "THEADERClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "THEADERClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"THEADERClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("THEADERClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_THEADERClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_THEADERClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_THEADERClassDict() {
  TriggerDictionaryInitialization_THEADERClassDict_Impl();
}
