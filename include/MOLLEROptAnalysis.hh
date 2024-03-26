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

  //Adding histograms that are GEM specific. Beam must the upstream and one downstream scintillator to be plotted here
  void R1_GEM1_AddCathodeDetectionEvent(Int_t events) {R1_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R2_GEM1_AddCathodeDetectionEvent(Int_t events) {R2_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R3_GEM1_AddCathodeDetectionEvent(Int_t events) {R3_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R4_GEM1_AddCathodeDetectionEvent(Int_t events) {R4_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R5_GEM1_AddCathodeDetectionEvent(Int_t events) {R5_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R6_GEM1_AddCathodeDetectionEvent(Int_t events) {R6_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R7_GEM1_AddCathodeDetectionEvent(Int_t events) {R7_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R8_GEM1_AddCathodeDetectionEvent(Int_t events) {R8_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R1Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R1Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R2Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R2Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R3Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R3Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R4Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R4Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R5Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R5Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R6Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R6Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R7Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R7Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  void R8Only_GEM1_AddCathodeDetectionEvent(Int_t events) {R8Only_GEM1_CathodeEventsDistrHist->Fill(events);};
  
  void R1_GEM2_AddCathodeDetectionEvent(Int_t events) {R1_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R2_GEM2_AddCathodeDetectionEvent(Int_t events) {R2_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R3_GEM2_AddCathodeDetectionEvent(Int_t events) {R3_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R4_GEM2_AddCathodeDetectionEvent(Int_t events) {R4_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R5_GEM2_AddCathodeDetectionEvent(Int_t events) {R5_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R6_GEM2_AddCathodeDetectionEvent(Int_t events) {R6_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R7_GEM2_AddCathodeDetectionEvent(Int_t events) {R7_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R8_GEM2_AddCathodeDetectionEvent(Int_t events) {R8_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R1Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R1Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R2Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R2Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R3Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R3Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R4Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R4Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R5Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R5Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R6Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R6Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R7Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R7Only_GEM2_CathodeEventsDistrHist->Fill(events);};
  void R8Only_GEM2_AddCathodeDetectionEvent(Int_t events) {R8Only_GEM2_CathodeEventsDistrHist->Fill(events);};

  void R1_AddInitialBeamAngleHist(Float_t aang){ R1_InitialBeamAngleHist->Fill(aang);};
  void R2_AddInitialBeamAngleHist(Float_t aang){ R2_InitialBeamAngleHist->Fill(aang);};
  void R3_AddInitialBeamAngleHist(Float_t aang){ R3_InitialBeamAngleHist->Fill(aang);};
  void R4_AddInitialBeamAngleHist(Float_t aang){ R4_InitialBeamAngleHist->Fill(aang);};
  void R5_AddInitialBeamAngleHist(Float_t aang){ R5_InitialBeamAngleHist->Fill(aang);};
  void R6_AddInitialBeamAngleHist(Float_t aang){ R6_InitialBeamAngleHist->Fill(aang);};
  void R7_AddInitialBeamAngleHist(Float_t aang){ R7_InitialBeamAngleHist->Fill(aang);};
  void R8_AddInitialBeamAngleHist(Float_t aang){ R8_InitialBeamAngleHist->Fill(aang);};
  void R1Only_AddInitialBeamAngleHist(Float_t aang){ R1Only_InitialBeamAngleHist->Fill(aang);};
  void R2Only_AddInitialBeamAngleHist(Float_t aang){ R2Only_InitialBeamAngleHist->Fill(aang);};
  void R3Only_AddInitialBeamAngleHist(Float_t aang){ R3Only_InitialBeamAngleHist->Fill(aang);};
  void R4Only_AddInitialBeamAngleHist(Float_t aang){ R4Only_InitialBeamAngleHist->Fill(aang);};
  void R5Only_AddInitialBeamAngleHist(Float_t aang){ R5Only_InitialBeamAngleHist->Fill(aang);};
  void R6Only_AddInitialBeamAngleHist(Float_t aang){ R6Only_InitialBeamAngleHist->Fill(aang);};
  void R7Only_AddInitialBeamAngleHist(Float_t aang){ R7Only_InitialBeamAngleHist->Fill(aang);};
  void R8Only_AddInitialBeamAngleHist(Float_t aang){ R8Only_InitialBeamAngleHist->Fill(aang);};

  void R1_GEM1_AddInitialBeamAngleHist(Float_t aang){ R1_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R2_GEM1_AddInitialBeamAngleHist(Float_t aang){ R2_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R3_GEM1_AddInitialBeamAngleHist(Float_t aang){ R3_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R4_GEM1_AddInitialBeamAngleHist(Float_t aang){ R4_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R5_GEM1_AddInitialBeamAngleHist(Float_t aang){ R5_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R6_GEM1_AddInitialBeamAngleHist(Float_t aang){ R6_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R7_GEM1_AddInitialBeamAngleHist(Float_t aang){ R7_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R8_GEM1_AddInitialBeamAngleHist(Float_t aang){ R8_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R1Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R1Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R2Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R2Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R3Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R3Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R4Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R4Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R5Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R5Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R6Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R6Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R7Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R7Only_GEM1_InitialBeamAngleHist->Fill(aang);};
  void R8Only_GEM1_AddInitialBeamAngleHist(Float_t aang){ R8Only_GEM1_InitialBeamAngleHist->Fill(aang);};

  void R1_GEM2_AddInitialBeamAngleHist(Float_t aang){ R1_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R2_GEM2_AddInitialBeamAngleHist(Float_t aang){ R2_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R3_GEM2_AddInitialBeamAngleHist(Float_t aang){ R3_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R4_GEM2_AddInitialBeamAngleHist(Float_t aang){ R4_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R5_GEM2_AddInitialBeamAngleHist(Float_t aang){ R5_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R6_GEM2_AddInitialBeamAngleHist(Float_t aang){ R6_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R7_GEM2_AddInitialBeamAngleHist(Float_t aang){ R7_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R8_GEM2_AddInitialBeamAngleHist(Float_t aang){ R8_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R1Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R1Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R2Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R2Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R3Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R3Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R4Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R4Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R5Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R5Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R6Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R6Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R7Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R7Only_GEM2_InitialBeamAngleHist->Fill(aang);};
  void R8Only_GEM2_AddInitialBeamAngleHist(Float_t aang){ R8Only_GEM2_InitialBeamAngleHist->Fill(aang);};

  void NoHit_AddInitialBeamAngleHist(Float_t aang){ NoHit_InitialBeamAngleHist->Fill(aang);};



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

  TH1D*    R1_GEM1_CathodeEventsDistrHist;
  TH1D*    R2_GEM1_CathodeEventsDistrHist;
  TH1D*    R3_GEM1_CathodeEventsDistrHist;
  TH1D*    R4_GEM1_CathodeEventsDistrHist;
  TH1D*    R5_GEM1_CathodeEventsDistrHist;
  TH1D*    R6_GEM1_CathodeEventsDistrHist;
  TH1D*    R7_GEM1_CathodeEventsDistrHist;
  TH1D*    R8_GEM1_CathodeEventsDistrHist;
  TH1D*    R1Only_GEM1_CathodeEventsDistrHist;
  TH1D*    R2Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R3Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R4Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R5Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R6Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R7Only_GEM1_CathodeEventsDistrHist; 
  TH1D*    R8Only_GEM1_CathodeEventsDistrHist; 

  TH1D*    R1_GEM2_CathodeEventsDistrHist;
  TH1D*    R2_GEM2_CathodeEventsDistrHist;
  TH1D*    R3_GEM2_CathodeEventsDistrHist;
  TH1D*    R4_GEM2_CathodeEventsDistrHist;
  TH1D*    R5_GEM2_CathodeEventsDistrHist;
  TH1D*    R6_GEM2_CathodeEventsDistrHist;
  TH1D*    R7_GEM2_CathodeEventsDistrHist;
  TH1D*    R8_GEM2_CathodeEventsDistrHist;
  TH1D*    R1Only_GEM2_CathodeEventsDistrHist;
  TH1D*    R2Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R3Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R4Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R5Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R6Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R7Only_GEM2_CathodeEventsDistrHist; 
  TH1D*    R8Only_GEM2_CathodeEventsDistrHist; 

  TH1F*    R1_InitialBeamAngleHist;
  TH1F*    R2_InitialBeamAngleHist;
  TH1F*    R3_InitialBeamAngleHist;
  TH1F*    R4_InitialBeamAngleHist;
  TH1F*    R5_InitialBeamAngleHist;
  TH1F*    R6_InitialBeamAngleHist;
  TH1F*    R7_InitialBeamAngleHist;
  TH1F*    R8_InitialBeamAngleHist;
  TH1F*    R1Only_InitialBeamAngleHist;
  TH1F*    R2Only_InitialBeamAngleHist;
  TH1F*    R3Only_InitialBeamAngleHist;
  TH1F*    R4Only_InitialBeamAngleHist;
  TH1F*    R5Only_InitialBeamAngleHist;
  TH1F*    R6Only_InitialBeamAngleHist;
  TH1F*    R7Only_InitialBeamAngleHist;
  TH1F*    R8Only_InitialBeamAngleHist;

  TH1F*    R1_GEM1_InitialBeamAngleHist;
  TH1F*    R2_GEM1_InitialBeamAngleHist;
  TH1F*    R3_GEM1_InitialBeamAngleHist;
  TH1F*    R4_GEM1_InitialBeamAngleHist;
  TH1F*    R5_GEM1_InitialBeamAngleHist;
  TH1F*    R6_GEM1_InitialBeamAngleHist;
  TH1F*    R7_GEM1_InitialBeamAngleHist;
  TH1F*    R8_GEM1_InitialBeamAngleHist;
  TH1F*    R1Only_GEM1_InitialBeamAngleHist;
  TH1F*    R2Only_GEM1_InitialBeamAngleHist;
  TH1F*    R3Only_GEM1_InitialBeamAngleHist;
  TH1F*    R4Only_GEM1_InitialBeamAngleHist;
  TH1F*    R5Only_GEM1_InitialBeamAngleHist;
  TH1F*    R6Only_GEM1_InitialBeamAngleHist;
  TH1F*    R7Only_GEM1_InitialBeamAngleHist;
  TH1F*    R8Only_GEM1_InitialBeamAngleHist;

  TH1F*    R1_GEM2_InitialBeamAngleHist;
  TH1F*    R2_GEM2_InitialBeamAngleHist;
  TH1F*    R3_GEM2_InitialBeamAngleHist;
  TH1F*    R4_GEM2_InitialBeamAngleHist;
  TH1F*    R5_GEM2_InitialBeamAngleHist;
  TH1F*    R6_GEM2_InitialBeamAngleHist;
  TH1F*    R7_GEM2_InitialBeamAngleHist;
  TH1F*    R8_GEM2_InitialBeamAngleHist;
  TH1F*    R1Only_GEM2_InitialBeamAngleHist;
  TH1F*    R2Only_GEM2_InitialBeamAngleHist;
  TH1F*    R3Only_GEM2_InitialBeamAngleHist;
  TH1F*    R4Only_GEM2_InitialBeamAngleHist;
  TH1F*    R5Only_GEM2_InitialBeamAngleHist;
  TH1F*    R6Only_GEM2_InitialBeamAngleHist;
  TH1F*    R7Only_GEM2_InitialBeamAngleHist;
  TH1F*    R8Only_GEM2_InitialBeamAngleHist;


  TH1F*    NoHit_InitialBeamAngleHist;
  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
