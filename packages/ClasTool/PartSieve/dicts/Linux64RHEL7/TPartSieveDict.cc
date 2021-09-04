// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITPartSieveDict
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
#include "TPartSieve.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TPartSieve(void *p = 0);
   static void *newArray_TPartSieve(Long_t size, void *p);
   static void delete_TPartSieve(void *p);
   static void deleteArray_TPartSieve(void *p);
   static void destruct_TPartSieve(void *p);
   static void streamer_TPartSieve(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TPartSieve*)
   {
      ::TPartSieve *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TPartSieve >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TPartSieve", ::TPartSieve::Class_Version(), "TPartSieve.h", 95,
                  typeid(::TPartSieve), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TPartSieve::Dictionary, isa_proxy, 16,
                  sizeof(::TPartSieve) );
      instance.SetNew(&new_TPartSieve);
      instance.SetNewArray(&newArray_TPartSieve);
      instance.SetDelete(&delete_TPartSieve);
      instance.SetDeleteArray(&deleteArray_TPartSieve);
      instance.SetDestructor(&destruct_TPartSieve);
      instance.SetStreamerFunc(&streamer_TPartSieve);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TPartSieve*)
   {
      return GenerateInitInstanceLocal((::TPartSieve*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TPartSieve*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TPartSieve::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TPartSieve::Class_Name()
{
   return "TPartSieve";
}

//______________________________________________________________________________
const char *TPartSieve::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TPartSieve*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TPartSieve::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TPartSieve*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TPartSieve::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TPartSieve*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TPartSieve::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TPartSieve*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TPartSieve::Streamer(TBuffer &R__b)
{
   // Stream an object of class TPartSieve.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fEC_U_Cut;
      R__b >> fEC_V_Cut;
      R__b >> fEC_W_Cut;
      R__b >> fEC_U_Cut_width;
      R__b >> fEC_V_Cut_width;
      R__b >> fEC_W_Cut_width;
      R__b >> fEC_Eio_slope;
      R__b >> fEC_Eio_off;
      R__b >> fEC_Ein_cut;
      R__b >> fEC_Eout_cut;
      R__b >> fCC_Phe_cut;
      R__b >> fCC_Phe_width;
      R__b >> fConf_Pim_DT_min;
      R__b >> fConf_Pim_DT_max;
      R__b >> fConf_Pip_DT_min;
      R__b >> fConf_Pip_DT_max;
      R__b >> fConf_Km_DT_min;
      R__b >> fConf_Km_DT_max;
      R__b >> fConf_Kp_DT_min;
      R__b >> fConf_Kp_DT_max;
      R__b >> fConf_Prot_DT_min;
      R__b >> fConf_Prot_DT_max;
      R__b >> fConf_Deut_DT_min;
      R__b >> fConf_Deut_DT_max;
      R__b >> fConf_He3_DT_min;
      R__b >> fConf_He3_DT_max;
      R__b >> fConf_He4_DT_min;
      R__b >> fConf_He4_DT_max;
      R__b >> fConf_Neut_DT_min;
      R__b >> fConf_Neut_DT_max;
      R__b >> fConf_El_DC_chi2;
      R__b >> fConf_Prot_DC_chi2;
      R__b >> fConf_Pim_DC_chi2;
      R__b >> fConf_Pip_DC_chi2;
      R__b >> fConf_Km_DC_chi2;
      R__b >> fConf_Kp_DC_chi2;
      R__b >> fConf_Deut_DC_chi2;
      R__b >> fConf_He3_DC_chi2;
      R__b >> fConf_He4_DC_chi2;
      R__b >> fConf_El_DC_chi2_width;
      R__b >> fConf_Prot_DC_chi2_width;
      R__b >> fConf_Pim_DC_chi2_width;
      R__b >> fConf_Pip_DC_chi2_width;
      R__b >> fConf_Km_DC_chi2_width;
      R__b >> fConf_Kp_DC_chi2_width;
      R__b >> fConf_Deut_DC_chi2_width;
      R__b >> fConf_He3_DC_chi2_width;
      R__b >> fConf_He4_DC_chi2_width;
      {
         vector<int> &R__stl =  fvBadPaddles;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> fCT;
      R__b >> fSortFlag;
      R__b >> fDebug_Mode;
      R__b >> fIndexSave;
      R__b >> fRefConfidenceCut;
      R__b >> fConfidenceCut;
      R__b.ReadStaticArray((int*)fNPart);
      R__b.ReadStaticArray((int*)fIndex);
      R__b.ReadStaticArray((float*)fConfidence);
      R__b.CheckByteCount(R__s, R__c, TPartSieve::IsA());
   } else {
      R__c = R__b.WriteVersion(TPartSieve::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fEC_U_Cut;
      R__b << fEC_V_Cut;
      R__b << fEC_W_Cut;
      R__b << fEC_U_Cut_width;
      R__b << fEC_V_Cut_width;
      R__b << fEC_W_Cut_width;
      R__b << fEC_Eio_slope;
      R__b << fEC_Eio_off;
      R__b << fEC_Ein_cut;
      R__b << fEC_Eout_cut;
      R__b << fCC_Phe_cut;
      R__b << fCC_Phe_width;
      R__b << fConf_Pim_DT_min;
      R__b << fConf_Pim_DT_max;
      R__b << fConf_Pip_DT_min;
      R__b << fConf_Pip_DT_max;
      R__b << fConf_Km_DT_min;
      R__b << fConf_Km_DT_max;
      R__b << fConf_Kp_DT_min;
      R__b << fConf_Kp_DT_max;
      R__b << fConf_Prot_DT_min;
      R__b << fConf_Prot_DT_max;
      R__b << fConf_Deut_DT_min;
      R__b << fConf_Deut_DT_max;
      R__b << fConf_He3_DT_min;
      R__b << fConf_He3_DT_max;
      R__b << fConf_He4_DT_min;
      R__b << fConf_He4_DT_max;
      R__b << fConf_Neut_DT_min;
      R__b << fConf_Neut_DT_max;
      R__b << fConf_El_DC_chi2;
      R__b << fConf_Prot_DC_chi2;
      R__b << fConf_Pim_DC_chi2;
      R__b << fConf_Pip_DC_chi2;
      R__b << fConf_Km_DC_chi2;
      R__b << fConf_Kp_DC_chi2;
      R__b << fConf_Deut_DC_chi2;
      R__b << fConf_He3_DC_chi2;
      R__b << fConf_He4_DC_chi2;
      R__b << fConf_El_DC_chi2_width;
      R__b << fConf_Prot_DC_chi2_width;
      R__b << fConf_Pim_DC_chi2_width;
      R__b << fConf_Pip_DC_chi2_width;
      R__b << fConf_Km_DC_chi2_width;
      R__b << fConf_Kp_DC_chi2_width;
      R__b << fConf_Deut_DC_chi2_width;
      R__b << fConf_He3_DC_chi2_width;
      R__b << fConf_He4_DC_chi2_width;
      {
         vector<int> &R__stl =  fvBadPaddles;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << fCT;
      R__b << fSortFlag;
      R__b << fDebug_Mode;
      R__b << fIndexSave;
      R__b << fRefConfidenceCut;
      R__b << fConfidenceCut;
      R__b.WriteArray(fNPart, 13);
      R__b.WriteArray((int*)fIndex, 130);
      R__b.WriteArray((float*)fConfidence, 130);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TPartSieve(void *p) {
      return  p ? new(p) ::TPartSieve : new ::TPartSieve;
   }
   static void *newArray_TPartSieve(Long_t nElements, void *p) {
      return p ? new(p) ::TPartSieve[nElements] : new ::TPartSieve[nElements];
   }
   // Wrapper around operator delete
   static void delete_TPartSieve(void *p) {
      delete ((::TPartSieve*)p);
   }
   static void deleteArray_TPartSieve(void *p) {
      delete [] ((::TPartSieve*)p);
   }
   static void destruct_TPartSieve(void *p) {
      typedef ::TPartSieve current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TPartSieve(TBuffer &buf, void *obj) {
      ((::TPartSieve*)obj)->::TPartSieve::Streamer(buf);
   }
} // end of namespace ROOT for class ::TPartSieve

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 210,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace {
  void TriggerDictionaryInitialization_TPartSieveDict_Impl() {
    static const char* headers[] = {
"TPartSieve.h",
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
"/user/a/alaoui/software/clas_software_ver1/packages/ClasTool/PartSieve/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TPartSieveDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Package to sort particles and fix PID.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TPartSieve.h")))  TPartSieve;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TPartSieveDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TPartSieve.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TPartSieve", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TPartSieveDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TPartSieveDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TPartSieveDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TPartSieveDict() {
  TriggerDictionaryInitialization_TPartSieveDict_Impl();
}
