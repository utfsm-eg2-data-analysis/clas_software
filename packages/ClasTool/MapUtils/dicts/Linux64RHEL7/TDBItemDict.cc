// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITDBItemDict
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
#include "TDBItem.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TDBItem(void *p = 0);
   static void *newArray_TDBItem(Long_t size, void *p);
   static void delete_TDBItem(void *p);
   static void deleteArray_TDBItem(void *p);
   static void destruct_TDBItem(void *p);
   static void streamer_TDBItem(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDBItem*)
   {
      ::TDBItem *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDBItem >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDBItem", ::TDBItem::Class_Version(), "TDBItem.h", 18,
                  typeid(::TDBItem), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDBItem::Dictionary, isa_proxy, 16,
                  sizeof(::TDBItem) );
      instance.SetNew(&new_TDBItem);
      instance.SetNewArray(&newArray_TDBItem);
      instance.SetDelete(&delete_TDBItem);
      instance.SetDeleteArray(&deleteArray_TDBItem);
      instance.SetDestructor(&destruct_TDBItem);
      instance.SetStreamerFunc(&streamer_TDBItem);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDBItem*)
   {
      return GenerateInitInstanceLocal((::TDBItem*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDBItem*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDBItem::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDBItem::Class_Name()
{
   return "TDBItem";
}

//______________________________________________________________________________
const char *TDBItem::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDBItem*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDBItem::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDBItem*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDBItem::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDBItem*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDBItem::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDBItem*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDBItem::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDBItem.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fItemId;
      fItemName.Streamer(R__b);
      R__b >> fSubsystemId;
      R__b >> fLength;
      fType.Streamer(R__b);
      fDescription.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TDBItem::IsA());
   } else {
      R__c = R__b.WriteVersion(TDBItem::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fItemId;
      fItemName.Streamer(R__b);
      R__b << fSubsystemId;
      R__b << fLength;
      fType.Streamer(R__b);
      fDescription.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDBItem(void *p) {
      return  p ? new(p) ::TDBItem : new ::TDBItem;
   }
   static void *newArray_TDBItem(Long_t nElements, void *p) {
      return p ? new(p) ::TDBItem[nElements] : new ::TDBItem[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDBItem(void *p) {
      delete ((::TDBItem*)p);
   }
   static void deleteArray_TDBItem(void *p) {
      delete [] ((::TDBItem*)p);
   }
   static void destruct_TDBItem(void *p) {
      typedef ::TDBItem current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDBItem(TBuffer &buf, void *obj) {
      ((::TDBItem*)obj)->::TDBItem::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDBItem

namespace {
  void TriggerDictionaryInitialization_TDBItemDict_Impl() {
    static const char* headers[] = {
"TDBItem.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/MapUtils/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TDBItemDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Class to keep Map Item information)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TDBItem.h")))  TDBItem;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TDBItemDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TDBItem.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TDBItem", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TDBItemDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TDBItemDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TDBItemDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TDBItemDict() {
  TriggerDictionaryInitialization_TDBItemDict_Impl();
}
