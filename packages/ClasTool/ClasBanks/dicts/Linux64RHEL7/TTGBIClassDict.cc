// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITTGBIClassDict
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
#include "TTGBIClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTGBIClass(void *p = 0);
   static void *newArray_TTGBIClass(Long_t size, void *p);
   static void delete_TTGBIClass(void *p);
   static void deleteArray_TTGBIClass(void *p);
   static void destruct_TTGBIClass(void *p);
   static void streamer_TTGBIClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTGBIClass*)
   {
      ::TTGBIClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTGBIClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTGBIClass", ::TTGBIClass::Class_Version(), "TTGBIClass.h", 24,
                  typeid(::TTGBIClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTGBIClass::Dictionary, isa_proxy, 16,
                  sizeof(::TTGBIClass) );
      instance.SetNew(&new_TTGBIClass);
      instance.SetNewArray(&newArray_TTGBIClass);
      instance.SetDelete(&delete_TTGBIClass);
      instance.SetDeleteArray(&deleteArray_TTGBIClass);
      instance.SetDestructor(&destruct_TTGBIClass);
      instance.SetStreamerFunc(&streamer_TTGBIClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTGBIClass*)
   {
      return GenerateInitInstanceLocal((::TTGBIClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTGBIClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTGBIClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTGBIClass::Class_Name()
{
   return "TTGBIClass";
}

//______________________________________________________________________________
const char *TTGBIClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTGBIClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTGBIClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTGBIClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTGBIClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTGBIClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTGBIClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTGBIClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTGBIClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTGBIClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Latch1;
      R__b >> Helicity_scaler;
      R__b >> Interrupt_time;
      R__b >> Latch2;
      R__b >> Level3;
      R__b.CheckByteCount(R__s, R__c, TTGBIClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TTGBIClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Latch1;
      R__b << Helicity_scaler;
      R__b << Interrupt_time;
      R__b << Latch2;
      R__b << Level3;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTGBIClass(void *p) {
      return  p ? new(p) ::TTGBIClass : new ::TTGBIClass;
   }
   static void *newArray_TTGBIClass(Long_t nElements, void *p) {
      return p ? new(p) ::TTGBIClass[nElements] : new ::TTGBIClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTGBIClass(void *p) {
      delete ((::TTGBIClass*)p);
   }
   static void deleteArray_TTGBIClass(void *p) {
      delete [] ((::TTGBIClass*)p);
   }
   static void destruct_TTGBIClass(void *p) {
      typedef ::TTGBIClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTGBIClass(TBuffer &buf, void *obj) {
      ((::TTGBIClass*)obj)->::TTGBIClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTGBIClass

namespace {
  void TriggerDictionaryInitialization_TTGBIClassDict_Impl() {
    static const char* headers[] = {
"TTGBIClass.h",
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
#line 1 "TTGBIClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the TGBI bank: trigger info.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTGBIClass.h")))  TTGBIClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TTGBIClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TTGBIClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TTGBIClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TTGBIClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TTGBIClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TTGBIClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TTGBIClassDict() {
  TriggerDictionaryInitialization_TTGBIClassDict_Impl();
}
