// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME MOLLEROptDict
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
#include "/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_MOLLEROptPrimaryEvent(void *p = 0);
   static void *newArray_MOLLEROptPrimaryEvent(Long_t size, void *p);
   static void delete_MOLLEROptPrimaryEvent(void *p);
   static void deleteArray_MOLLEROptPrimaryEvent(void *p);
   static void destruct_MOLLEROptPrimaryEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MOLLEROptPrimaryEvent*)
   {
      ::MOLLEROptPrimaryEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MOLLEROptPrimaryEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MOLLEROptPrimaryEvent", ::MOLLEROptPrimaryEvent::Class_Version(), "MOLLEROptPrimaryEvent.hh", 8,
                  typeid(::MOLLEROptPrimaryEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MOLLEROptPrimaryEvent::Dictionary, isa_proxy, 4,
                  sizeof(::MOLLEROptPrimaryEvent) );
      instance.SetNew(&new_MOLLEROptPrimaryEvent);
      instance.SetNewArray(&newArray_MOLLEROptPrimaryEvent);
      instance.SetDelete(&delete_MOLLEROptPrimaryEvent);
      instance.SetDeleteArray(&deleteArray_MOLLEROptPrimaryEvent);
      instance.SetDestructor(&destruct_MOLLEROptPrimaryEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MOLLEROptPrimaryEvent*)
   {
      return GenerateInitInstanceLocal((::MOLLEROptPrimaryEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MOLLEROptPrimaryEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MOLLEROptDetectorEvent(void *p = 0);
   static void *newArray_MOLLEROptDetectorEvent(Long_t size, void *p);
   static void delete_MOLLEROptDetectorEvent(void *p);
   static void deleteArray_MOLLEROptDetectorEvent(void *p);
   static void destruct_MOLLEROptDetectorEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MOLLEROptDetectorEvent*)
   {
      ::MOLLEROptDetectorEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MOLLEROptDetectorEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MOLLEROptDetectorEvent", ::MOLLEROptDetectorEvent::Class_Version(), "MOLLEROptDetectorEvent.hh", 7,
                  typeid(::MOLLEROptDetectorEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MOLLEROptDetectorEvent::Dictionary, isa_proxy, 4,
                  sizeof(::MOLLEROptDetectorEvent) );
      instance.SetNew(&new_MOLLEROptDetectorEvent);
      instance.SetNewArray(&newArray_MOLLEROptDetectorEvent);
      instance.SetDelete(&delete_MOLLEROptDetectorEvent);
      instance.SetDeleteArray(&deleteArray_MOLLEROptDetectorEvent);
      instance.SetDestructor(&destruct_MOLLEROptDetectorEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MOLLEROptDetectorEvent*)
   {
      return GenerateInitInstanceLocal((::MOLLEROptDetectorEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MOLLEROptDetectorEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MOLLEROptMainEvent(void *p = 0);
   static void *newArray_MOLLEROptMainEvent(Long_t size, void *p);
   static void delete_MOLLEROptMainEvent(void *p);
   static void deleteArray_MOLLEROptMainEvent(void *p);
   static void destruct_MOLLEROptMainEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MOLLEROptMainEvent*)
   {
      ::MOLLEROptMainEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MOLLEROptMainEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MOLLEROptMainEvent", ::MOLLEROptMainEvent::Class_Version(), "MOLLEROptMainEvent.hh", 14,
                  typeid(::MOLLEROptMainEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MOLLEROptMainEvent::Dictionary, isa_proxy, 4,
                  sizeof(::MOLLEROptMainEvent) );
      instance.SetNew(&new_MOLLEROptMainEvent);
      instance.SetNewArray(&newArray_MOLLEROptMainEvent);
      instance.SetDelete(&delete_MOLLEROptMainEvent);
      instance.SetDeleteArray(&deleteArray_MOLLEROptMainEvent);
      instance.SetDestructor(&destruct_MOLLEROptMainEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MOLLEROptMainEvent*)
   {
      return GenerateInitInstanceLocal((::MOLLEROptMainEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MOLLEROptMainEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr MOLLEROptPrimaryEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MOLLEROptPrimaryEvent::Class_Name()
{
   return "MOLLEROptPrimaryEvent";
}

//______________________________________________________________________________
const char *MOLLEROptPrimaryEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptPrimaryEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MOLLEROptPrimaryEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptPrimaryEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MOLLEROptPrimaryEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptPrimaryEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MOLLEROptPrimaryEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptPrimaryEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MOLLEROptDetectorEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MOLLEROptDetectorEvent::Class_Name()
{
   return "MOLLEROptDetectorEvent";
}

//______________________________________________________________________________
const char *MOLLEROptDetectorEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptDetectorEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MOLLEROptDetectorEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptDetectorEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MOLLEROptDetectorEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptDetectorEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MOLLEROptDetectorEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptDetectorEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MOLLEROptMainEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MOLLEROptMainEvent::Class_Name()
{
   return "MOLLEROptMainEvent";
}

//______________________________________________________________________________
const char *MOLLEROptMainEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptMainEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MOLLEROptMainEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptMainEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MOLLEROptMainEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptMainEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MOLLEROptMainEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MOLLEROptMainEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void MOLLEROptPrimaryEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class MOLLEROptPrimaryEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MOLLEROptPrimaryEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(MOLLEROptPrimaryEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MOLLEROptPrimaryEvent(void *p) {
      return  p ? new(p) ::MOLLEROptPrimaryEvent : new ::MOLLEROptPrimaryEvent;
   }
   static void *newArray_MOLLEROptPrimaryEvent(Long_t nElements, void *p) {
      return p ? new(p) ::MOLLEROptPrimaryEvent[nElements] : new ::MOLLEROptPrimaryEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_MOLLEROptPrimaryEvent(void *p) {
      delete ((::MOLLEROptPrimaryEvent*)p);
   }
   static void deleteArray_MOLLEROptPrimaryEvent(void *p) {
      delete [] ((::MOLLEROptPrimaryEvent*)p);
   }
   static void destruct_MOLLEROptPrimaryEvent(void *p) {
      typedef ::MOLLEROptPrimaryEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MOLLEROptPrimaryEvent

//______________________________________________________________________________
void MOLLEROptDetectorEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class MOLLEROptDetectorEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MOLLEROptDetectorEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(MOLLEROptDetectorEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MOLLEROptDetectorEvent(void *p) {
      return  p ? new(p) ::MOLLEROptDetectorEvent : new ::MOLLEROptDetectorEvent;
   }
   static void *newArray_MOLLEROptDetectorEvent(Long_t nElements, void *p) {
      return p ? new(p) ::MOLLEROptDetectorEvent[nElements] : new ::MOLLEROptDetectorEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_MOLLEROptDetectorEvent(void *p) {
      delete ((::MOLLEROptDetectorEvent*)p);
   }
   static void deleteArray_MOLLEROptDetectorEvent(void *p) {
      delete [] ((::MOLLEROptDetectorEvent*)p);
   }
   static void destruct_MOLLEROptDetectorEvent(void *p) {
      typedef ::MOLLEROptDetectorEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MOLLEROptDetectorEvent

//______________________________________________________________________________
void MOLLEROptMainEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class MOLLEROptMainEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MOLLEROptMainEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(MOLLEROptMainEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MOLLEROptMainEvent(void *p) {
      return  p ? new(p) ::MOLLEROptMainEvent : new ::MOLLEROptMainEvent;
   }
   static void *newArray_MOLLEROptMainEvent(Long_t nElements, void *p) {
      return p ? new(p) ::MOLLEROptMainEvent[nElements] : new ::MOLLEROptMainEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_MOLLEROptMainEvent(void *p) {
      delete ((::MOLLEROptMainEvent*)p);
   }
   static void deleteArray_MOLLEROptMainEvent(void *p) {
      delete [] ((::MOLLEROptMainEvent*)p);
   }
   static void destruct_MOLLEROptMainEvent(void *p) {
      typedef ::MOLLEROptMainEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MOLLEROptMainEvent

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
         instance("vector<int>", -2, "vector", 216,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
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

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 216,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      ::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace {
  void TriggerDictionaryInitialization_libMOLLEROptDict_Impl() {
    static const char* headers[] = {
"/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh",
0
    };
    static const char* includePaths[] = {
"/home/moller/softwares/geant4-v10.6.3-install/include/Geant4",
"/home/moller/MOLLER-MultipleDetectorsCosmicStand/src/include",
"/home/moller/MOLLER-MultipleDetectorsCosmicStand/include",
"/home/moller/Desktop/root/include",
"/home/moller/MOLLER-MultipleDetectorsCosmicStand",
"/home/moller/Desktop/root/include/",
"/home/moller/MOLLER-MultipleDetectorsCosmicStand/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libMOLLEROptDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$MOLLEROptPrimaryEvent.hh")))  __attribute__((annotate("$clingAutoload$/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh")))  MOLLEROptPrimaryEvent;
class __attribute__((annotate("$clingAutoload$MOLLEROptDetectorEvent.hh")))  __attribute__((annotate("$clingAutoload$/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh")))  MOLLEROptDetectorEvent;
class __attribute__((annotate("$clingAutoload$MOLLEROptMainEvent.hh")))  __attribute__((annotate("$clingAutoload$/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh")))  MOLLEROptMainEvent;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libMOLLEROptDict dictionary payload"

#ifndef G4UI_USE_TCSH
  #define G4UI_USE_TCSH 1
#endif
#ifndef G4INTY_USE_QT
  #define G4INTY_USE_QT 1
#endif
#ifndef G4UI_USE_QT
  #define G4UI_USE_QT 1
#endif
#ifndef G4VIS_USE_OPENGLQT
  #define G4VIS_USE_OPENGLQT 1
#endif
#ifndef G4VIS_USE_OPENGL
  #define G4VIS_USE_OPENGL 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/moller/MOLLER-MultipleDetectorsCosmicStand/include/MOLLEROptDictClasses.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"MOLLEROptDetectorEvent", payloadCode, "@",
"MOLLEROptMainEvent", payloadCode, "@",
"MOLLEROptPrimaryEvent", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libMOLLEROptDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libMOLLEROptDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libMOLLEROptDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libMOLLEROptDict() {
  TriggerDictionaryInitialization_libMOLLEROptDict_Impl();
}
