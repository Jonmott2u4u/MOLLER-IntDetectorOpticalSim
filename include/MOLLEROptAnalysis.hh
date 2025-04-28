#ifndef MOLLEROptAnalysis_h 
#define MOLLEROptAnalysis_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptMainEvent.hh"
#include "MOLLEROptTrackingReadout.hh"

class MOLLEROptMainEvent;

class MOLLEROptAnalysis {
public:
  MOLLEROptAnalysis();
  virtual ~MOLLEROptAnalysis();
  
public:

  // void BeginOfRun(G4int runID, G4double pressure, G4double coll);
  void BeginOfRun(G4int runID, G4String name1, MOLLEROptTrackingReadout *TrRO);
  void EndOfRun();
  void EndOfEvent(G4int flag);

  void Init();
  void Finish();

  void FillRootNtuple() {if(ROOTFileFlag) MOLLEROptNtuple->Fill();}
  void AutoSaveRootNtuple();

  void SetTotalNumberOfPrimaries(Int_t n) {(*NumberOfPrimaries)[0] = (Double_t)n;};
  void SetROOTFileFlag(G4int flag) {ROOTFileFlag = flag;};
  void SetROOTFileName(G4String name1) {ROOTFileName = name1;};

  void AddToAveragePMTOptPhotonDist(Float_t wvl, Float_t wgt){PMTOptPhotonDistrHist->Fill(wvl,wgt);};
  void AddToAverageQuartzOptPhotonDist(Float_t wvl, Float_t wgt){QuartzOptPhotonDistrHist->Fill(wvl,wgt);};
  void AddToAverageLightGuideOptPhotonDist(Float_t wvl, Float_t wgt){LightGuideOptPhotonDistrHist->Fill(wvl,wgt);};

  //--------BF segment histograms--------//
  void R1_AddCathodeDetectionEvent(Int_t events) {R1_CathodeEventsDistrHist->Fill(events);};
  void R2_AddCathodeDetectionEvent(Int_t events) {R2_CathodeEventsDistrHist->Fill(events);};
  void R3_AddCathodeDetectionEvent(Int_t events) {R3_CathodeEventsDistrHist->Fill(events);};
  void R4_AddCathodeDetectionEvent(Int_t events) {R4_CathodeEventsDistrHist->Fill(events);};
  void R5_AddCathodeDetectionEvent(Int_t events) {R5_CathodeEventsDistrHist->Fill(events);};
  void R6_AddCathodeDetectionEvent(Int_t events) {R6_CathodeEventsDistrHist->Fill(events);};
  void R7_AddCathodeDetectionEvent(Int_t events) {R7_CathodeEventsDistrHist->Fill(events);};
  void R8_AddCathodeDetectionEvent(Int_t events) {R8_CathodeEventsDistrHist->Fill(events);};
  void R1Only_AddCathodeDetectionEvent(Int_t events) {R1Only_CathodeEventsDistrHist->Fill(events);};
  void R2Only_AddCathodeDetectionEvent(Int_t events) {R2Only_CathodeEventsDistrHist->Fill(events);};
  void R3Only_AddCathodeDetectionEvent(Int_t events) {R3Only_CathodeEventsDistrHist->Fill(events);};
  void R4Only_AddCathodeDetectionEvent(Int_t events) {R4Only_CathodeEventsDistrHist->Fill(events);};
  void R5Only_AddCathodeDetectionEvent(Int_t events) {R5Only_CathodeEventsDistrHist->Fill(events);};
  void R6Only_AddCathodeDetectionEvent(Int_t events) {R6Only_CathodeEventsDistrHist->Fill(events);};
  void R7Only_AddCathodeDetectionEvent(Int_t events) {R7Only_CathodeEventsDistrHist->Fill(events);};
  void R8Only_AddCathodeDetectionEvent(Int_t events) {R8Only_CathodeEventsDistrHist->Fill(events);};
  void R1Adjacent_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_CathodeEventsDistrHist->Fill(events);};

  //These histograms are specific to each scintillator combination
  void R1_Scint13_AddCathodeDetectionEvent(Int_t events) {R1_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R2_Scint13_AddCathodeDetectionEvent(Int_t events) {R2_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R3_Scint13_AddCathodeDetectionEvent(Int_t events) {R3_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R4_Scint13_AddCathodeDetectionEvent(Int_t events) {R4_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R5_Scint13_AddCathodeDetectionEvent(Int_t events) {R5_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R6_Scint13_AddCathodeDetectionEvent(Int_t events) {R6_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R7_Scint13_AddCathodeDetectionEvent(Int_t events) {R7_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R8_Scint13_AddCathodeDetectionEvent(Int_t events) {R8_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R1Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R1Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R2Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R2Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R3Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R3Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R4Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R4Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R5Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R5Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R6Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R6Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R7Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R7Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R8Only_Scint13_AddCathodeDetectionEvent(Int_t events) {R8Only_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R1Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_Scint13_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_Scint13_CathodeEventsDistrHist->Fill(events);};
  
  void R1_Scint14_AddCathodeDetectionEvent(Int_t events) {R1_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R2_Scint14_AddCathodeDetectionEvent(Int_t events) {R2_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R3_Scint14_AddCathodeDetectionEvent(Int_t events) {R3_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R4_Scint14_AddCathodeDetectionEvent(Int_t events) {R4_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R5_Scint14_AddCathodeDetectionEvent(Int_t events) {R5_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R6_Scint14_AddCathodeDetectionEvent(Int_t events) {R6_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R7_Scint14_AddCathodeDetectionEvent(Int_t events) {R7_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R8_Scint14_AddCathodeDetectionEvent(Int_t events) {R8_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R1Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R1Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R2Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R2Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R3Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R3Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R4Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R4Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R5Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R5Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R6Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R6Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R7Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R7Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R8Only_Scint14_AddCathodeDetectionEvent(Int_t events) {R8Only_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R1Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_Scint14_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_Scint14_CathodeEventsDistrHist->Fill(events);};

  void R1_Scint23_AddCathodeDetectionEvent(Int_t events) {R1_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R2_Scint23_AddCathodeDetectionEvent(Int_t events) {R2_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R3_Scint23_AddCathodeDetectionEvent(Int_t events) {R3_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R4_Scint23_AddCathodeDetectionEvent(Int_t events) {R4_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R5_Scint23_AddCathodeDetectionEvent(Int_t events) {R5_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R6_Scint23_AddCathodeDetectionEvent(Int_t events) {R6_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R7_Scint23_AddCathodeDetectionEvent(Int_t events) {R7_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R8_Scint23_AddCathodeDetectionEvent(Int_t events) {R8_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R1Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R1Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R2Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R2Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R3Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R3Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R4Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R4Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R5Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R5Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R6Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R6Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R7Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R7Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R8Only_Scint23_AddCathodeDetectionEvent(Int_t events) {R8Only_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R1Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_Scint23_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_Scint23_CathodeEventsDistrHist->Fill(events);};

  void R1_Scint24_AddCathodeDetectionEvent(Int_t events) {R1_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R2_Scint24_AddCathodeDetectionEvent(Int_t events) {R2_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R3_Scint24_AddCathodeDetectionEvent(Int_t events) {R3_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R4_Scint24_AddCathodeDetectionEvent(Int_t events) {R4_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R5_Scint24_AddCathodeDetectionEvent(Int_t events) {R5_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R6_Scint24_AddCathodeDetectionEvent(Int_t events) {R6_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R7_Scint24_AddCathodeDetectionEvent(Int_t events) {R7_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R8_Scint24_AddCathodeDetectionEvent(Int_t events) {R8_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R1Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R1Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R2Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R2Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R3Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R3Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R4Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R4Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R5Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R5Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R6Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R6Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R7Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R7Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R8Only_Scint24_AddCathodeDetectionEvent(Int_t events) {R8Only_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R1Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_Scint24_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_Scint24_CathodeEventsDistrHist->Fill(events);};


  //--------FF segment histograms--------//
  void R9_AddCathodeDetectionEvent(Int_t events) {R9_CathodeEventsDistrHist->Fill(events);};
  void R10_AddCathodeDetectionEvent(Int_t events) {R10_CathodeEventsDistrHist->Fill(events);};
  void R11_AddCathodeDetectionEvent(Int_t events) {R11_CathodeEventsDistrHist->Fill(events);};
  void R12_AddCathodeDetectionEvent(Int_t events) {R12_CathodeEventsDistrHist->Fill(events);};
  void R13_AddCathodeDetectionEvent(Int_t events) {R13_CathodeEventsDistrHist->Fill(events);};
  void R14_AddCathodeDetectionEvent(Int_t events) {R14_CathodeEventsDistrHist->Fill(events);};
  void R15_AddCathodeDetectionEvent(Int_t events) {R15_CathodeEventsDistrHist->Fill(events);};
  void R16_AddCathodeDetectionEvent(Int_t events) {R16_CathodeEventsDistrHist->Fill(events);};
  void R9Only_AddCathodeDetectionEvent(Int_t events) {R9Only_CathodeEventsDistrHist->Fill(events);};
  void R10Only_AddCathodeDetectionEvent(Int_t events) {R10Only_CathodeEventsDistrHist->Fill(events);};
  void R11Only_AddCathodeDetectionEvent(Int_t events) {R11Only_CathodeEventsDistrHist->Fill(events);};
  void R12Only_AddCathodeDetectionEvent(Int_t events) {R12Only_CathodeEventsDistrHist->Fill(events);};
  void R13Only_AddCathodeDetectionEvent(Int_t events) {R13Only_CathodeEventsDistrHist->Fill(events);};
  void R14Only_AddCathodeDetectionEvent(Int_t events) {R14Only_CathodeEventsDistrHist->Fill(events);};
  void R15Only_AddCathodeDetectionEvent(Int_t events) {R15Only_CathodeEventsDistrHist->Fill(events);};
  void R16Only_AddCathodeDetectionEvent(Int_t events) {R16Only_CathodeEventsDistrHist->Fill(events);};
  void R9Adjacent_AddCathodeDetectionEvent(Int_t events) {R9Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R10Adjacent_AddCathodeDetectionEvent(Int_t events) {R10Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R11Adjacent_AddCathodeDetectionEvent(Int_t events) {R11Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R12Adjacent_AddCathodeDetectionEvent(Int_t events) {R12Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R13Adjacent_AddCathodeDetectionEvent(Int_t events) {R13Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R14Adjacent_AddCathodeDetectionEvent(Int_t events) {R14Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R15Adjacent_AddCathodeDetectionEvent(Int_t events) {R15Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R16Adjacent_AddCathodeDetectionEvent(Int_t events) {R16Adjacent_CathodeEventsDistrHist->Fill(events);};

  void R9_Scint57_AddCathodeDetectionEvent(Int_t events) {R9_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R10_Scint57_AddCathodeDetectionEvent(Int_t events) {R10_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R11_Scint57_AddCathodeDetectionEvent(Int_t events) {R11_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R12_Scint57_AddCathodeDetectionEvent(Int_t events) {R12_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R13_Scint57_AddCathodeDetectionEvent(Int_t events) {R13_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R14_Scint57_AddCathodeDetectionEvent(Int_t events) {R14_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R15_Scint57_AddCathodeDetectionEvent(Int_t events) {R15_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R16_Scint57_AddCathodeDetectionEvent(Int_t events) {R16_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R9Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R9Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R10Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R10Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R11Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R11Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R12Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R12Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R13Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R13Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R14Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R14Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R15Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R15Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R16Only_Scint57_AddCathodeDetectionEvent(Int_t events) {R16Only_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R9Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R9Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R10Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R10Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R11Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R11Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R12Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R12Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R13Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R13Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R14Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R14Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R15Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R15Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};
  void R16Adjacent_Scint57_AddCathodeDetectionEvent(Int_t events) {R16Adjacent_Scint57_CathodeEventsDistrHist->Fill(events);};

  void R9_Scint58_AddCathodeDetectionEvent(Int_t events) {R9_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R10_Scint58_AddCathodeDetectionEvent(Int_t events) {R10_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R11_Scint58_AddCathodeDetectionEvent(Int_t events) {R11_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R12_Scint58_AddCathodeDetectionEvent(Int_t events) {R12_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R13_Scint58_AddCathodeDetectionEvent(Int_t events) {R13_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R14_Scint58_AddCathodeDetectionEvent(Int_t events) {R14_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R15_Scint58_AddCathodeDetectionEvent(Int_t events) {R15_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R16_Scint58_AddCathodeDetectionEvent(Int_t events) {R16_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R9Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R9Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R10Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R10Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R11Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R11Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R12Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R12Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R13Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R13Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R14Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R14Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R15Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R15Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R16Only_Scint58_AddCathodeDetectionEvent(Int_t events) {R16Only_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R9Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R9Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R10Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R10Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R11Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R11Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R12Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R12Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R13Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R13Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R14Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R14Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R15Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R15Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};
  void R16Adjacent_Scint58_AddCathodeDetectionEvent(Int_t events) {R16Adjacent_Scint58_CathodeEventsDistrHist->Fill(events);};

  void R9_Scint67_AddCathodeDetectionEvent(Int_t events) {R9_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R10_Scint67_AddCathodeDetectionEvent(Int_t events) {R10_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R11_Scint67_AddCathodeDetectionEvent(Int_t events) {R11_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R12_Scint67_AddCathodeDetectionEvent(Int_t events) {R12_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R13_Scint67_AddCathodeDetectionEvent(Int_t events) {R13_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R14_Scint67_AddCathodeDetectionEvent(Int_t events) {R14_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R15_Scint67_AddCathodeDetectionEvent(Int_t events) {R15_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R16_Scint67_AddCathodeDetectionEvent(Int_t events) {R16_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R9Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R9Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R10Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R10Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R11Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R11Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R12Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R12Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R13Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R13Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R14Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R14Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R15Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R15Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R16Only_Scint67_AddCathodeDetectionEvent(Int_t events) {R16Only_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R9Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R9Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R10Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R10Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R11Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R11Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R12Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R12Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R13Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R13Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R14Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R14Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R15Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R15Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};
  void R16Adjacent_Scint67_AddCathodeDetectionEvent(Int_t events) {R16Adjacent_Scint67_CathodeEventsDistrHist->Fill(events);};

  void R9_Scint68_AddCathodeDetectionEvent(Int_t events) {R9_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R10_Scint68_AddCathodeDetectionEvent(Int_t events) {R10_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R11_Scint68_AddCathodeDetectionEvent(Int_t events) {R11_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R12_Scint68_AddCathodeDetectionEvent(Int_t events) {R12_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R13_Scint68_AddCathodeDetectionEvent(Int_t events) {R13_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R14_Scint68_AddCathodeDetectionEvent(Int_t events) {R14_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R15_Scint68_AddCathodeDetectionEvent(Int_t events) {R15_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R16_Scint68_AddCathodeDetectionEvent(Int_t events) {R16_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R9Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R9Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R10Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R10Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R11Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R11Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R12Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R12Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R13Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R13Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R14Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R14Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R15Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R15Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R16Only_Scint68_AddCathodeDetectionEvent(Int_t events) {R16Only_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R9Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R9Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R10Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R10Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R11Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R11Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R12Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R12Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R13Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R13Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R14Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R14Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R15Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R15Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};
  void R16Adjacent_Scint68_AddCathodeDetectionEvent(Int_t events) {R16Adjacent_Scint68_CathodeEventsDistrHist->Fill(events);};


  MOLLEROptMainEvent* MOLLERMainEvent;

private:

  MOLLEROptTrackingReadout* TrackingReadout;
  
  void ConstructRootNtuple(); 

  TTree*   MOLLEROptNtuple;
  TBranch* MOLLEROptMainBranch;
  TFile*   MOLLEROptFile;
  TProfile*    PMTOptPhotonDistrHist;
  TProfile*    QuartzOptPhotonDistrHist;
  TProfile*    LightGuideOptPhotonDistrHist;

  //--------BF segment histograms--------//
  TH1D*    R1_CathodeEventsDistrHist;
  TH1D*    R2_CathodeEventsDistrHist;
  TH1D*    R3_CathodeEventsDistrHist;
  TH1D*    R4_CathodeEventsDistrHist;
  TH1D*    R5_CathodeEventsDistrHist;
  TH1D*    R6_CathodeEventsDistrHist;
  TH1D*    R7_CathodeEventsDistrHist;
  TH1D*    R8_CathodeEventsDistrHist;
  TH1D*    R1Only_CathodeEventsDistrHist; //Unlike R#_CathodeEvents, only includes PEs from electrons that hit only that detector
  TH1D*    R2Only_CathodeEventsDistrHist; //
  TH1D*    R3Only_CathodeEventsDistrHist; //
  TH1D*    R4Only_CathodeEventsDistrHist; //
  TH1D*    R5Only_CathodeEventsDistrHist; //
  TH1D*    R6Only_CathodeEventsDistrHist; //
  TH1D*    R7Only_CathodeEventsDistrHist; //
  TH1D*    R8Only_CathodeEventsDistrHist; //
  TH1D*    R1Adjacent_CathodeEventsDistrHist; //Plots PEs for adjacency cuts (rejects events that hit both the desired detector and an adjacent one)
  TH1D*    R2Adjacent_CathodeEventsDistrHist; //
  TH1D*    R3Adjacent_CathodeEventsDistrHist; //
  TH1D*    R4Adjacent_CathodeEventsDistrHist; //
  TH1D*    R5Adjacent_CathodeEventsDistrHist; //
  TH1D*    R6Adjacent_CathodeEventsDistrHist; //
  TH1D*    R7Adjacent_CathodeEventsDistrHist; //
  TH1D*    R8Adjacent_CathodeEventsDistrHist; //

  TH1D*    R1_Scint13_CathodeEventsDistrHist;
  TH1D*    R2_Scint13_CathodeEventsDistrHist;
  TH1D*    R3_Scint13_CathodeEventsDistrHist;
  TH1D*    R4_Scint13_CathodeEventsDistrHist;
  TH1D*    R5_Scint13_CathodeEventsDistrHist;
  TH1D*    R6_Scint13_CathodeEventsDistrHist;
  TH1D*    R7_Scint13_CathodeEventsDistrHist;
  TH1D*    R8_Scint13_CathodeEventsDistrHist;
  TH1D*    R1Only_Scint13_CathodeEventsDistrHist;
  TH1D*    R2Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R3Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R4Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R5Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R6Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R7Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R8Only_Scint13_CathodeEventsDistrHist; 
  TH1D*    R1Adjacent_Scint13_CathodeEventsDistrHist;
  TH1D*    R2Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R3Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R4Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R5Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R6Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R7Adjacent_Scint13_CathodeEventsDistrHist; 
  TH1D*    R8Adjacent_Scint13_CathodeEventsDistrHist;

  TH1D*    R1_Scint14_CathodeEventsDistrHist;
  TH1D*    R2_Scint14_CathodeEventsDistrHist;
  TH1D*    R3_Scint14_CathodeEventsDistrHist;
  TH1D*    R4_Scint14_CathodeEventsDistrHist;
  TH1D*    R5_Scint14_CathodeEventsDistrHist;
  TH1D*    R6_Scint14_CathodeEventsDistrHist;
  TH1D*    R7_Scint14_CathodeEventsDistrHist;
  TH1D*    R8_Scint14_CathodeEventsDistrHist;
  TH1D*    R1Only_Scint14_CathodeEventsDistrHist;
  TH1D*    R2Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R3Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R4Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R5Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R6Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R7Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R8Only_Scint14_CathodeEventsDistrHist; 
  TH1D*    R1Adjacent_Scint14_CathodeEventsDistrHist;
  TH1D*    R2Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R3Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R4Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R5Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R6Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R7Adjacent_Scint14_CathodeEventsDistrHist; 
  TH1D*    R8Adjacent_Scint14_CathodeEventsDistrHist;

  TH1D*    R1_Scint23_CathodeEventsDistrHist;
  TH1D*    R2_Scint23_CathodeEventsDistrHist;
  TH1D*    R3_Scint23_CathodeEventsDistrHist;
  TH1D*    R4_Scint23_CathodeEventsDistrHist;
  TH1D*    R5_Scint23_CathodeEventsDistrHist;
  TH1D*    R6_Scint23_CathodeEventsDistrHist;
  TH1D*    R7_Scint23_CathodeEventsDistrHist;
  TH1D*    R8_Scint23_CathodeEventsDistrHist;
  TH1D*    R1Only_Scint23_CathodeEventsDistrHist;
  TH1D*    R2Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R3Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R4Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R5Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R6Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R7Only_Scint23_CathodeEventsDistrHist; 
  TH1D*    R8Only_Scint23_CathodeEventsDistrHist;
  TH1D*    R1Adjacent_Scint23_CathodeEventsDistrHist;
  TH1D*    R2Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R3Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R4Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R5Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R6Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R7Adjacent_Scint23_CathodeEventsDistrHist; 
  TH1D*    R8Adjacent_Scint23_CathodeEventsDistrHist;


  TH1D*    R1_Scint24_CathodeEventsDistrHist;
  TH1D*    R2_Scint24_CathodeEventsDistrHist;
  TH1D*    R3_Scint24_CathodeEventsDistrHist;
  TH1D*    R4_Scint24_CathodeEventsDistrHist;
  TH1D*    R5_Scint24_CathodeEventsDistrHist;
  TH1D*    R6_Scint24_CathodeEventsDistrHist;
  TH1D*    R7_Scint24_CathodeEventsDistrHist;
  TH1D*    R8_Scint24_CathodeEventsDistrHist;
  TH1D*    R1Only_Scint24_CathodeEventsDistrHist;
  TH1D*    R2Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R3Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R4Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R5Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R6Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R7Only_Scint24_CathodeEventsDistrHist; 
  TH1D*    R8Only_Scint24_CathodeEventsDistrHist;
  TH1D*    R1Adjacent_Scint24_CathodeEventsDistrHist;
  TH1D*    R2Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R3Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R4Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R5Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R6Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R7Adjacent_Scint24_CathodeEventsDistrHist; 
  TH1D*    R8Adjacent_Scint24_CathodeEventsDistrHist;

  //--------FF segment histograms--------//
  TH1D*    R9_CathodeEventsDistrHist;
  TH1D*    R10_CathodeEventsDistrHist;
  TH1D*    R11_CathodeEventsDistrHist;
  TH1D*    R12_CathodeEventsDistrHist;
  TH1D*    R13_CathodeEventsDistrHist;
  TH1D*    R14_CathodeEventsDistrHist;
  TH1D*    R15_CathodeEventsDistrHist;
  TH1D*    R16_CathodeEventsDistrHist;
  TH1D*    R9Only_CathodeEventsDistrHist;
  TH1D*    R10Only_CathodeEventsDistrHist;
  TH1D*    R11Only_CathodeEventsDistrHist;
  TH1D*    R12Only_CathodeEventsDistrHist;
  TH1D*    R13Only_CathodeEventsDistrHist;
  TH1D*    R14Only_CathodeEventsDistrHist;
  TH1D*    R15Only_CathodeEventsDistrHist;
  TH1D*    R16Only_CathodeEventsDistrHist;
  TH1D*    R9Adjacent_CathodeEventsDistrHist;
  TH1D*    R10Adjacent_CathodeEventsDistrHist;
  TH1D*    R11Adjacent_CathodeEventsDistrHist;
  TH1D*    R12Adjacent_CathodeEventsDistrHist;
  TH1D*    R13Adjacent_CathodeEventsDistrHist;
  TH1D*    R14Adjacent_CathodeEventsDistrHist;
  TH1D*    R15Adjacent_CathodeEventsDistrHist;
  TH1D*    R16Adjacent_CathodeEventsDistrHist;

  TH1D*    R9_Scint57_CathodeEventsDistrHist;
  TH1D*    R10_Scint57_CathodeEventsDistrHist;
  TH1D*    R11_Scint57_CathodeEventsDistrHist;
  TH1D*    R12_Scint57_CathodeEventsDistrHist;
  TH1D*    R13_Scint57_CathodeEventsDistrHist;
  TH1D*    R14_Scint57_CathodeEventsDistrHist;
  TH1D*    R15_Scint57_CathodeEventsDistrHist;
  TH1D*    R16_Scint57_CathodeEventsDistrHist;
  TH1D*    R9Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R10Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R11Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R12Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R13Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R14Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R15Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R16Only_Scint57_CathodeEventsDistrHist;
  TH1D*    R9Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R10Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R11Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R12Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R13Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R14Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R15Adjacent_Scint57_CathodeEventsDistrHist;
  TH1D*    R16Adjacent_Scint57_CathodeEventsDistrHist;

  TH1D*    R9_Scint58_CathodeEventsDistrHist;
  TH1D*    R10_Scint58_CathodeEventsDistrHist;
  TH1D*    R11_Scint58_CathodeEventsDistrHist;
  TH1D*    R12_Scint58_CathodeEventsDistrHist;
  TH1D*    R13_Scint58_CathodeEventsDistrHist;
  TH1D*    R14_Scint58_CathodeEventsDistrHist;
  TH1D*    R15_Scint58_CathodeEventsDistrHist;
  TH1D*    R16_Scint58_CathodeEventsDistrHist;
  TH1D*    R9Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R10Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R11Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R12Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R13Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R14Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R15Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R16Only_Scint58_CathodeEventsDistrHist;
  TH1D*    R9Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R10Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R11Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R12Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R13Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R14Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R15Adjacent_Scint58_CathodeEventsDistrHist;
  TH1D*    R16Adjacent_Scint58_CathodeEventsDistrHist;

  TH1D*    R9_Scint67_CathodeEventsDistrHist;
  TH1D*    R10_Scint67_CathodeEventsDistrHist;
  TH1D*    R11_Scint67_CathodeEventsDistrHist;
  TH1D*    R12_Scint67_CathodeEventsDistrHist;
  TH1D*    R13_Scint67_CathodeEventsDistrHist;
  TH1D*    R14_Scint67_CathodeEventsDistrHist;
  TH1D*    R15_Scint67_CathodeEventsDistrHist;
  TH1D*    R16_Scint67_CathodeEventsDistrHist;
  TH1D*    R9Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R10Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R11Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R12Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R13Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R14Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R15Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R16Only_Scint67_CathodeEventsDistrHist;
  TH1D*    R9Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R10Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R11Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R12Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R13Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R14Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R15Adjacent_Scint67_CathodeEventsDistrHist;
  TH1D*    R16Adjacent_Scint67_CathodeEventsDistrHist;

  TH1D*    R9_Scint68_CathodeEventsDistrHist;
  TH1D*    R10_Scint68_CathodeEventsDistrHist;
  TH1D*    R11_Scint68_CathodeEventsDistrHist;
  TH1D*    R12_Scint68_CathodeEventsDistrHist;
  TH1D*    R13_Scint68_CathodeEventsDistrHist;
  TH1D*    R14_Scint68_CathodeEventsDistrHist;
  TH1D*    R15_Scint68_CathodeEventsDistrHist;
  TH1D*    R16_Scint68_CathodeEventsDistrHist;
  TH1D*    R9Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R10Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R11Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R12Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R13Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R14Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R15Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R16Only_Scint68_CathodeEventsDistrHist;
  TH1D*    R9Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R10Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R11Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R12Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R13Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R14Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R15Adjacent_Scint68_CathodeEventsDistrHist;
  TH1D*    R16Adjacent_Scint68_CathodeEventsDistrHist;

  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
