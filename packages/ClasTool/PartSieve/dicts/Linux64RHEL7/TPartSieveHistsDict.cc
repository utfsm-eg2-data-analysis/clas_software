// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dictsdILinux64RHEL7dITPartSieveHistsDict
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
#include "TPartSieveHists.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TPartSieveHists(void *p = 0);
   static void *newArray_TPartSieveHists(Long_t size, void *p);
   static void delete_TPartSieveHists(void *p);
   static void deleteArray_TPartSieveHists(void *p);
   static void destruct_TPartSieveHists(void *p);
   static void streamer_TPartSieveHists(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TPartSieveHists*)
   {
      ::TPartSieveHists *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TPartSieveHists >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TPartSieveHists", ::TPartSieveHists::Class_Version(), "TPartSieveHists.h", 45,
                  typeid(::TPartSieveHists), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TPartSieveHists::Dictionary, isa_proxy, 16,
                  sizeof(::TPartSieveHists) );
      instance.SetNew(&new_TPartSieveHists);
      instance.SetNewArray(&newArray_TPartSieveHists);
      instance.SetDelete(&delete_TPartSieveHists);
      instance.SetDeleteArray(&deleteArray_TPartSieveHists);
      instance.SetDestructor(&destruct_TPartSieveHists);
      instance.SetStreamerFunc(&streamer_TPartSieveHists);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TPartSieveHists*)
   {
      return GenerateInitInstanceLocal((::TPartSieveHists*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TPartSieveHists*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TPartSieveHists::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TPartSieveHists::Class_Name()
{
   return "TPartSieveHists";
}

//______________________________________________________________________________
const char *TPartSieveHists::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TPartSieveHists*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TPartSieveHists::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TPartSieveHists*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TPartSieveHists::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TPartSieveHists*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TPartSieveHists::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TPartSieveHists*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TPartSieveHists::Streamer(TBuffer &R__b)
{
   // Stream an object of class TPartSieveHists.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fControl;
      R__b >> fS;
      R__b >> fCT;
      fCuts.Streamer(R__b);
      R__b >> fH;
      R__b >> fHP;
      R__b >> APartCount;
      R__b >> AMassPos;
      R__b >> AMassNeg;
      R__b >> AElec_mom;
      R__b >> AElec_Q2W;
      R__b >> AElec_Q2Lc;
      R__b >> AElec_ec_u;
      R__b >> AElec_ec_v;
      R__b >> AElec_ec_w;
      R__b >> AElec_ec_xy;
      R__b >> AElec_ec_etot;
      R__b >> AElec_ec_eio;
      R__b >> AElec_cc;
      R__b >> ABetaPPos;
      R__b >> ABetaPNeg;
      R__b >> SPartCount;
      R__b >> SMassPos;
      R__b >> SMassNeg;
      R__b >> SElec_mom;
      R__b >> SElec_Q2W;
      R__b >> SElec_Q2Lc;
      R__b >> SElec_ec_u;
      R__b >> SElec_ec_v;
      R__b >> SElec_ec_w;
      R__b >> SElec_ec_xy;
      R__b >> SElec_ec_etot;
      R__b >> SElec_ec_eio;
      R__b >> SElec_cc;
      R__b >> SBetaPPos;
      R__b >> SBetaPNeg;
      {
         vector<int> &R__stl =  ABetaPIdx;
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
      {
         vector<int> &R__stl =  ADeltatPIdx;
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
      {
         vector<int> &R__stl =  SBetaPIdx;
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
      {
         vector<int> &R__stl =  SDeltatPIdx;
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
      {
         vector<vector<int> > &R__stl =  ASCBetaP;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<int, class std::allocator<int> >));
         if (R__tcl1==0) {
            Error("ASCBetaP streamer","Missing the TClass object for class std::vector<int, class std::allocator<int> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<int> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<vector<int> > &R__stl =  ASCDeltatP;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<int, class std::allocator<int> >));
         if (R__tcl1==0) {
            Error("ASCDeltatP streamer","Missing the TClass object for class std::vector<int, class std::allocator<int> >!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            vector<int> R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, TPartSieveHists::IsA());
   } else {
      R__c = R__b.WriteVersion(TPartSieveHists::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fControl;
      R__b << fS;
      R__b << fCT;
      fCuts.Streamer(R__b);
      R__b << fH;
      R__b << fHP;
      R__b << (TObject*)APartCount;
      R__b << (TObject*)AMassPos;
      R__b << (TObject*)AMassNeg;
      R__b << (TObject*)AElec_mom;
      R__b << (TObject*)AElec_Q2W;
      R__b << (TObject*)AElec_Q2Lc;
      R__b << (TObject*)AElec_ec_u;
      R__b << (TObject*)AElec_ec_v;
      R__b << (TObject*)AElec_ec_w;
      R__b << (TObject*)AElec_ec_xy;
      R__b << (TObject*)AElec_ec_etot;
      R__b << (TObject*)AElec_ec_eio;
      R__b << (TObject*)AElec_cc;
      R__b << (TObject*)ABetaPPos;
      R__b << (TObject*)ABetaPNeg;
      R__b << (TObject*)SPartCount;
      R__b << (TObject*)SMassPos;
      R__b << (TObject*)SMassNeg;
      R__b << (TObject*)SElec_mom;
      R__b << (TObject*)SElec_Q2W;
      R__b << (TObject*)SElec_Q2Lc;
      R__b << (TObject*)SElec_ec_u;
      R__b << (TObject*)SElec_ec_v;
      R__b << (TObject*)SElec_ec_w;
      R__b << (TObject*)SElec_ec_xy;
      R__b << (TObject*)SElec_ec_etot;
      R__b << (TObject*)SElec_ec_eio;
      R__b << (TObject*)SElec_cc;
      R__b << (TObject*)SBetaPPos;
      R__b << (TObject*)SBetaPNeg;
      {
         vector<int> &R__stl =  ABetaPIdx;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  ADeltatPIdx;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  SBetaPIdx;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  SDeltatPIdx;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<vector<int> > &R__stl =  ASCBetaP;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<int, class std::allocator<int> >));
         if (R__tcl1==0) {
            Error("ASCBetaP streamer","Missing the TClass object for class std::vector<int, class std::allocator<int> >!");
            return;
         }
            vector<vector<int> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<int>*)&(*R__k),R__tcl1);
            }
         }
      }
      {
         vector<vector<int> > &R__stl =  ASCDeltatP;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class std::vector<int, class std::allocator<int> >));
         if (R__tcl1==0) {
            Error("ASCDeltatP streamer","Missing the TClass object for class std::vector<int, class std::allocator<int> >!");
            return;
         }
            vector<vector<int> >::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((vector<int>*)&(*R__k),R__tcl1);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TPartSieveHists(void *p) {
      return  p ? new(p) ::TPartSieveHists : new ::TPartSieveHists;
   }
   static void *newArray_TPartSieveHists(Long_t nElements, void *p) {
      return p ? new(p) ::TPartSieveHists[nElements] : new ::TPartSieveHists[nElements];
   }
   // Wrapper around operator delete
   static void delete_TPartSieveHists(void *p) {
      delete ((::TPartSieveHists*)p);
   }
   static void deleteArray_TPartSieveHists(void *p) {
      delete [] ((::TPartSieveHists*)p);
   }
   static void destruct_TPartSieveHists(void *p) {
      typedef ::TPartSieveHists current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TPartSieveHists(TBuffer &buf, void *obj) {
      ((::TPartSieveHists*)obj)->::TPartSieveHists::Streamer(buf);
   }
} // end of namespace ROOT for class ::TPartSieveHists

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 210,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)0x0)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

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
  void TriggerDictionaryInitialization_TPartSieveHistsDict_Impl() {
    static const char* headers[] = {
"TPartSieveHists.h",
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
#line 1 "TPartSieveHistsDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(A PartSieveHists class for simple statistics.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TPartSieveHists.h")))  TPartSieveHists;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TPartSieveHistsDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TPartSieveHists.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TPartSieveHists", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TPartSieveHistsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TPartSieveHistsDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TPartSieveHistsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TPartSieveHistsDict() {
  TriggerDictionaryInitialization_TPartSieveHistsDict_Impl();
}
