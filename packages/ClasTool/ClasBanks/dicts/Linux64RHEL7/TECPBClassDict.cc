// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITECPBClassDict
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
#include "TECPBClass.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TECPBClass(void *p = 0);
   static void *newArray_TECPBClass(Long_t size, void *p);
   static void delete_TECPBClass(void *p);
   static void deleteArray_TECPBClass(void *p);
   static void destruct_TECPBClass(void *p);
   static void streamer_TECPBClass(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TECPBClass*)
   {
      ::TECPBClass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TECPBClass >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TECPBClass", ::TECPBClass::Class_Version(), "TECPBClass.h", 23,
                  typeid(::TECPBClass), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TECPBClass::Dictionary, isa_proxy, 16,
                  sizeof(::TECPBClass) );
      instance.SetNew(&new_TECPBClass);
      instance.SetNewArray(&newArray_TECPBClass);
      instance.SetDelete(&delete_TECPBClass);
      instance.SetDeleteArray(&deleteArray_TECPBClass);
      instance.SetDestructor(&destruct_TECPBClass);
      instance.SetStreamerFunc(&streamer_TECPBClass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TECPBClass*)
   {
      return GenerateInitInstanceLocal((::TECPBClass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TECPBClass*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TECPBClass::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TECPBClass::Class_Name()
{
   return "TECPBClass";
}

//______________________________________________________________________________
const char *TECPBClass::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TECPBClass*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TECPBClass::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TECPBClass*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TECPBClass::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TECPBClass*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TECPBClass::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TECPBClass*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TECPBClass::Streamer(TBuffer &R__b)
{
   // Stream an object of class TECPBClass.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Scht;
      R__b >> Etot;
      R__b >> Ein;
      R__b >> Eout;
      R__b >> Time;
      R__b >> Path;
      R__b >> X;
      R__b >> Y;
      R__b >> Z;
      R__b >> M2_hit;
      R__b >> M3_hit;
      R__b >> M4_hit;
      R__b >> Innstr;
      R__b >> Outstr;
      R__b >> Chi2ec;
      R__b >> Status;
      R__b.CheckByteCount(R__s, R__c, TECPBClass::IsA());
   } else {
      R__c = R__b.WriteVersion(TECPBClass::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Scht;
      R__b << Etot;
      R__b << Ein;
      R__b << Eout;
      R__b << Time;
      R__b << Path;
      R__b << X;
      R__b << Y;
      R__b << Z;
      R__b << M2_hit;
      R__b << M3_hit;
      R__b << M4_hit;
      R__b << Innstr;
      R__b << Outstr;
      R__b << Chi2ec;
      R__b << Status;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TECPBClass(void *p) {
      return  p ? new(p) ::TECPBClass : new ::TECPBClass;
   }
   static void *newArray_TECPBClass(Long_t nElements, void *p) {
      return p ? new(p) ::TECPBClass[nElements] : new ::TECPBClass[nElements];
   }
   // Wrapper around operator delete
   static void delete_TECPBClass(void *p) {
      delete ((::TECPBClass*)p);
   }
   static void deleteArray_TECPBClass(void *p) {
      delete [] ((::TECPBClass*)p);
   }
   static void destruct_TECPBClass(void *p) {
      typedef ::TECPBClass current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TECPBClass(TBuffer &buf, void *obj) {
      ((::TECPBClass*)obj)->::TECPBClass::Streamer(buf);
   }
} // end of namespace ROOT for class ::TECPBClass

namespace {
  void TriggerDictionaryInitialization_TECPBClassDict_Impl() {
    static const char* headers[] = {
"TECPBClass.h",
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
#line 1 "TECPBClassDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class for accessing the ECPB bank: Calorimeter)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TECPBClass.h")))  TECPBClass;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TECPBClassDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TECPBClass.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TECPBClass", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TECPBClassDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TECPBClassDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TECPBClassDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TECPBClassDict() {
  TriggerDictionaryInitialization_TECPBClassDict_Impl();
}
