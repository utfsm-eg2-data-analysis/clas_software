// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTAGRClassDict
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
#include "TTAGRClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTAGRClass(void *p = 0);
   static void *newArray_TTAGRClass(Long_t size, void *p);
   static void delete_TTAGRClass(void *p);
   static void deleteArray_TTAGRClass(void *p);
   static void destruct_TTAGRClass(void *p);
   static void streamer_TTAGRClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTAGRClass*)
   {
      ::TTAGRClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTAGRClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTAGRClass", ::TTAGRClass::Class_Version(), "TTAGRClass.h", 16,
                  typeid(::TTAGRClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTAGRClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTAGRClass) );
      instance.SetNew(&new_TTAGRClass);
      instance.SetNewArray(&newArray_TTAGRClass);
      instance.SetDelete(&delete_TTAGRClass);
      instance.SetDeleteArray(&deleteArray_TTAGRClass);
      instance.SetDestructor(&destruct_TTAGRClass);
      instance.SetStreamerFunc(&streamer_TTAGRClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTAGRClass*)
   {
      return GenerateInitInstanceLocal((::TTAGRClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTAGRClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTAGRClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTAGRClass::Class_Name()
{
   return "TTAGRClass";
}

//______________________________________________________________________________
const char *TTAGRClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTAGRClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTAGRClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTAGRClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTAGRClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTAGRClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTAGRClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTAGRClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTAGRClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTAGRClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> ERG;
      R__b >> TTAG;
      R__b >> TPHO;
      R__b >> STAT;
      R__b >> T_id;
      R__b >> E_id;
      R__b.CheckByteCount(R__s, R__c, TTAGRClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTAGRClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << ERG;
      R__b << TTAG;
      R__b << TPHO;
      R__b << STAT;
      R__b << T_id;
      R__b << E_id;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTAGRClass(void *p) {
      return  p ? new(p) ::TTAGRClass : new ::TTAGRClass;
   }
   static void *newArray_TTAGRClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTAGRClass[nElements] : new ::TTAGRClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTAGRClass(void *p) {
      delete ((::TTAGRClass*)p);
   }
   static void deleteArray_TTAGRClass(void *p) {
      delete [] ((::TTAGRClass*)p);
   }
   static void destruct_TTAGRClass(void *p) {
      typedef ::TTAGRClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTAGRClass(TBuffer &buf, void *obj) {
      ((::TTAGRClass*)obj)->::TTAGRClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTAGRClass

namespace {
  void TriggerDictionaryInitialization_TTAGRClassDict_Impl() {
    static const char* headers[] = {
"TTAGRClass.h",
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
#line 1 "TTAGRClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TGPB bank: Tagger)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTAGRClass.h")))  TTAGRClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTAGRClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTAGRClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTAGRClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTAGRClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTAGRClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTAGRClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTAGRClassDict() {
  TriggerDictionaryInitialization_TTAGRClassDict_Impl();
}
