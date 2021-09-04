// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTBTRClassDict
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
#include "TTBTRClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTBTRClass(void *p = 0);
   static void *newArray_TTBTRClass(Long_t size, void *p);
   static void delete_TTBTRClass(void *p);
   static void deleteArray_TTBTRClass(void *p);
   static void destruct_TTBTRClass(void *p);
   static void streamer_TTBTRClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTBTRClass*)
   {
      ::TTBTRClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTBTRClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTBTRClass", ::TTBTRClass::Class_Version(), "TTBTRClass.h", 11,
                  typeid(::TTBTRClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTBTRClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTBTRClass) );
      instance.SetNew(&new_TTBTRClass);
      instance.SetNewArray(&newArray_TTBTRClass);
      instance.SetDelete(&delete_TTBTRClass);
      instance.SetDeleteArray(&deleteArray_TTBTRClass);
      instance.SetDestructor(&destruct_TTBTRClass);
      instance.SetStreamerFunc(&streamer_TTBTRClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTBTRClass*)
   {
      return GenerateInitInstanceLocal((::TTBTRClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTBTRClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTBTRClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTBTRClass::Class_Name()
{
   return "TTBTRClass";
}

//______________________________________________________________________________
const char *TTBTRClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBTRClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTBTRClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTBTRClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTBTRClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBTRClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTBTRClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTBTRClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTBTRClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTBTRClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> x;
      R__b >> y;
      R__b >> z;
      R__b >> px;
      R__b >> py;
      R__b >> pz;
      R__b >> q;
      R__b >> chi2;
      R__b >> itr_sec;
      R__b >> itr_hbt;
      R__b.CheckByteCount(R__s, R__c, TTBTRClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTBTRClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << x;
      R__b << y;
      R__b << z;
      R__b << px;
      R__b << py;
      R__b << pz;
      R__b << q;
      R__b << chi2;
      R__b << itr_sec;
      R__b << itr_hbt;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTBTRClass(void *p) {
      return  p ? new(p) ::TTBTRClass : new ::TTBTRClass;
   }
   static void *newArray_TTBTRClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTBTRClass[nElements] : new ::TTBTRClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTBTRClass(void *p) {
      delete ((::TTBTRClass*)p);
   }
   static void deleteArray_TTBTRClass(void *p) {
      delete [] ((::TTBTRClass*)p);
   }
   static void destruct_TTBTRClass(void *p) {
      typedef ::TTBTRClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTBTRClass(TBuffer &buf, void *obj) {
      ((::TTBTRClass*)obj)->::TTBTRClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTBTRClass

namespace {
  void TriggerDictionaryInitialization_TTBTRClassDict_Impl() {
    static const char* headers[] = {
"TTBTRClass.h",
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
#line 1 "TTBTRClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TBER bank: Tracking error information.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTBTRClass.h")))  TTBTRClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTBTRClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTBTRClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTBTRClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTBTRClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTBTRClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTBTRClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTBTRClassDict() {
  TriggerDictionaryInitialization_TTBTRClassDict_Impl();
}
