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
  void R1Adjacent_AddCathodeDetectionEvent(Int_t events) {R1Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R2Adjacent_AddCathodeDetectionEvent(Int_t events) {R2Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R3Adjacent_AddCathodeDetectionEvent(Int_t events) {R3Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R4Adjacent_AddCathodeDetectionEvent(Int_t events) {R4Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R5Adjacent_AddCathodeDetectionEvent(Int_t events) {R5Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R6Adjacent_AddCathodeDetectionEvent(Int_t events) {R6Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R7Adjacent_AddCathodeDetectionEvent(Int_t events) {R7Adjacent_CathodeEventsDistrHist->Fill(events);};
  void R8Adjacent_AddCathodeDetectionEvent(Int_t events) {R8Adjacent_CathodeEventsDistrHist->Fill(events);};

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
  void NoHit_AddInitialBeamAngleHist(Float_t aang){ NoHit_InitialBeamAngleHist->Fill(aang);};

  void R1_AddR1QuartzHitPos(Float_t y,Float_t x) {R1_R1QuartzHitPos->Fill(y,x);};
  void R1_AddR2QuartzHitPos(Float_t y,Float_t x) {R1_R2QuartzHitPos->Fill(y,x);};
  void R1_AddR3QuartzHitPos(Float_t y,Float_t x) {R1_R3QuartzHitPos->Fill(y,x);};
  void R1_AddR4QuartzHitPos(Float_t y,Float_t x) {R1_R4QuartzHitPos->Fill(y,x);};
  void R1_AddR5QuartzHitPos(Float_t y,Float_t x) {R1_R5QuartzHitPos->Fill(y,x);};
  void R1_AddR8QuartzHitPos(Float_t y,Float_t x) {R1_R8QuartzHitPos->Fill(y,x);};
  void R2_AddR1QuartzHitPos(Float_t y,Float_t x) {R2_R1QuartzHitPos->Fill(y,x);};
  void R2_AddR2QuartzHitPos(Float_t y,Float_t x) {R2_R2QuartzHitPos->Fill(y,x);};
  void R2_AddR3QuartzHitPos(Float_t y,Float_t x) {R2_R3QuartzHitPos->Fill(y,x);};
  void R2_AddR4QuartzHitPos(Float_t y,Float_t x) {R2_R4QuartzHitPos->Fill(y,x);};
  void R2_AddR5QuartzHitPos(Float_t y,Float_t x) {R2_R5QuartzHitPos->Fill(y,x);};
  void R2_AddR8QuartzHitPos(Float_t y,Float_t x) {R2_R8QuartzHitPos->Fill(y,x);};
  void R3_AddR1QuartzHitPos(Float_t y,Float_t x) {R3_R1QuartzHitPos->Fill(y,x);};
  void R3_AddR2QuartzHitPos(Float_t y,Float_t x) {R3_R2QuartzHitPos->Fill(y,x);};
  void R3_AddR3QuartzHitPos(Float_t y,Float_t x) {R3_R3QuartzHitPos->Fill(y,x);};
  void R3_AddR4QuartzHitPos(Float_t y,Float_t x) {R3_R4QuartzHitPos->Fill(y,x);};
  void R3_AddR5QuartzHitPos(Float_t y,Float_t x) {R3_R5QuartzHitPos->Fill(y,x);};
  void R3_AddR8QuartzHitPos(Float_t y,Float_t x) {R3_R8QuartzHitPos->Fill(y,x);};
  void R4_AddR1QuartzHitPos(Float_t y,Float_t x) {R4_R1QuartzHitPos->Fill(y,x);};
  void R4_AddR2QuartzHitPos(Float_t y,Float_t x) {R4_R2QuartzHitPos->Fill(y,x);};
  void R4_AddR3QuartzHitPos(Float_t y,Float_t x) {R4_R3QuartzHitPos->Fill(y,x);};
  void R4_AddR4QuartzHitPos(Float_t y,Float_t x) {R4_R4QuartzHitPos->Fill(y,x);};
  void R4_AddR5QuartzHitPos(Float_t y,Float_t x) {R4_R5QuartzHitPos->Fill(y,x);};
  void R4_AddR8QuartzHitPos(Float_t y,Float_t x) {R4_R8QuartzHitPos->Fill(y,x);};
  void R5_AddR1QuartzHitPos(Float_t y,Float_t x) {R5_R1QuartzHitPos->Fill(y,x);};
  void R5_AddR2QuartzHitPos(Float_t y,Float_t x) {R5_R2QuartzHitPos->Fill(y,x);};
  void R5_AddR3QuartzHitPos(Float_t y,Float_t x) {R5_R3QuartzHitPos->Fill(y,x);};
  void R5_AddR4QuartzHitPos(Float_t y,Float_t x) {R5_R4QuartzHitPos->Fill(y,x);};
  void R5_AddR5QuartzHitPos(Float_t y,Float_t x) {R5_R5QuartzHitPos->Fill(y,x);};
  void R5_AddR8QuartzHitPos(Float_t y,Float_t x) {R5_R8QuartzHitPos->Fill(y,x);};
  void R8_AddR1QuartzHitPos(Float_t y,Float_t x) {R8_R1QuartzHitPos->Fill(y,x);};
  void R8_AddR2QuartzHitPos(Float_t y,Float_t x) {R8_R2QuartzHitPos->Fill(y,x);};
  void R8_AddR3QuartzHitPos(Float_t y,Float_t x) {R8_R3QuartzHitPos->Fill(y,x);};
  void R8_AddR4QuartzHitPos(Float_t y,Float_t x) {R8_R4QuartzHitPos->Fill(y,x);};
  void R8_AddR5QuartzHitPos(Float_t y,Float_t x) {R8_R5QuartzHitPos->Fill(y,x);};
  void R8_AddR8QuartzHitPos(Float_t y,Float_t x) {R8_R8QuartzHitPos->Fill(y,x);};
  //
  void R1Only_AddR1QuartzHitPos(Float_t y,Float_t x) {R1Only_R1QuartzHitPos->Fill(y,x);};
  void R2Only_AddR2QuartzHitPos(Float_t y,Float_t x) {R2Only_R2QuartzHitPos->Fill(y,x);};
  void R3Only_AddR3QuartzHitPos(Float_t y,Float_t x) {R3Only_R3QuartzHitPos->Fill(y,x);};
  void R4Only_AddR4QuartzHitPos(Float_t y,Float_t x) {R4Only_R4QuartzHitPos->Fill(y,x);};
  void R5Only_AddR5QuartzHitPos(Float_t y,Float_t x) {R5Only_R5QuartzHitPos->Fill(y,x);};
  void R8Only_AddR8QuartzHitPos(Float_t y,Float_t x) {R8Only_R8QuartzHitPos->Fill(y,x);};
  //
  void R1Adjacent_AddR1QuartzHitPos(Float_t y,Float_t x) {R1Adjacent_R1QuartzHitPos->Fill(y,x);};
  void R1Adjacent_AddR3QuartzHitPos(Float_t y,Float_t x) {R1Adjacent_R3QuartzHitPos->Fill(y,x);};
  void R1Adjacent_AddR4QuartzHitPos(Float_t y,Float_t x) {R1Adjacent_R4QuartzHitPos->Fill(y,x);};
  void R1Adjacent_AddR5QuartzHitPos(Float_t y,Float_t x) {R1Adjacent_R5QuartzHitPos->Fill(y,x);};
  void R1Adjacent_AddR8QuartzHitPos(Float_t y,Float_t x) {R1Adjacent_R8QuartzHitPos->Fill(y,x);};
  void R2Adjacent_AddR2QuartzHitPos(Float_t y,Float_t x) {R2Adjacent_R2QuartzHitPos->Fill(y,x);};
  void R2Adjacent_AddR4QuartzHitPos(Float_t y,Float_t x) {R2Adjacent_R4QuartzHitPos->Fill(y,x);};
  void R2Adjacent_AddR5QuartzHitPos(Float_t y,Float_t x) {R2Adjacent_R5QuartzHitPos->Fill(y,x);};
  void R2Adjacent_AddR8QuartzHitPos(Float_t y,Float_t x) {R2Adjacent_R8QuartzHitPos->Fill(y,x);};
  void R3Adjacent_AddR1QuartzHitPos(Float_t y,Float_t x) {R3Adjacent_R1QuartzHitPos->Fill(y,x);};
  void R3Adjacent_AddR3QuartzHitPos(Float_t y,Float_t x) {R3Adjacent_R3QuartzHitPos->Fill(y,x);};
  void R3Adjacent_AddR5QuartzHitPos(Float_t y,Float_t x) {R3Adjacent_R5QuartzHitPos->Fill(y,x);};
  void R3Adjacent_AddR8QuartzHitPos(Float_t y,Float_t x) {R3Adjacent_R8QuartzHitPos->Fill(y,x);};
  void R4Adjacent_AddR1QuartzHitPos(Float_t y,Float_t x) {R4Adjacent_R1QuartzHitPos->Fill(y,x);};
  void R4Adjacent_AddR2QuartzHitPos(Float_t y,Float_t x) {R4Adjacent_R2QuartzHitPos->Fill(y,x);};
  void R4Adjacent_AddR4QuartzHitPos(Float_t y,Float_t x) {R4Adjacent_R4QuartzHitPos->Fill(y,x);};
  void R4Adjacent_AddR8QuartzHitPos(Float_t y,Float_t x) {R4Adjacent_R8QuartzHitPos->Fill(y,x);};
  void R5Adjacent_AddR1QuartzHitPos(Float_t y,Float_t x) {R5Adjacent_R1QuartzHitPos->Fill(y,x);};
  void R5Adjacent_AddR2QuartzHitPos(Float_t y,Float_t x) {R5Adjacent_R2QuartzHitPos->Fill(y,x);};
  void R5Adjacent_AddR3QuartzHitPos(Float_t y,Float_t x) {R5Adjacent_R3QuartzHitPos->Fill(y,x);};
  void R5Adjacent_AddR5QuartzHitPos(Float_t y,Float_t x) {R5Adjacent_R5QuartzHitPos->Fill(y,x);};
  void R8Adjacent_AddR1QuartzHitPos(Float_t y,Float_t x) {R8Adjacent_R1QuartzHitPos->Fill(y,x);};
  void R8Adjacent_AddR2QuartzHitPos(Float_t y,Float_t x) {R8Adjacent_R2QuartzHitPos->Fill(y,x);};
  void R8Adjacent_AddR3QuartzHitPos(Float_t y,Float_t x) {R8Adjacent_R3QuartzHitPos->Fill(y,x);};
  void R8Adjacent_AddR4QuartzHitPos(Float_t y,Float_t x) {R8Adjacent_R4QuartzHitPos->Fill(y,x);};
  void R8Adjacent_AddR8QuartzHitPos(Float_t y,Float_t x) {R8Adjacent_R8QuartzHitPos->Fill(y,x);};


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
  TH1D*    R1Adjacent_CathodeEventsDistrHist; //PEs generated from events that do not hit adjacent detector tiles
  TH1D*    R2Adjacent_CathodeEventsDistrHist; 
  TH1D*    R3Adjacent_CathodeEventsDistrHist; 
  TH1D*    R4Adjacent_CathodeEventsDistrHist; 
  TH1D*    R5Adjacent_CathodeEventsDistrHist; 
  TH1D*    R6Adjacent_CathodeEventsDistrHist; 
  TH1D*    R7Adjacent_CathodeEventsDistrHist; 
  TH1D*    R8Adjacent_CathodeEventsDistrHist; 

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
  TH1F*    NoHit_InitialBeamAngleHist;

  TH2F*    R1_R1QuartzHitPos;
  TH2F*    R1_R2QuartzHitPos;
  TH2F*    R1_R3QuartzHitPos;
  TH2F*    R1_R4QuartzHitPos;
  TH2F*    R1_R5QuartzHitPos;
  TH2F*    R1_R8QuartzHitPos;
  TH2F*    R2_R1QuartzHitPos;
  TH2F*    R2_R2QuartzHitPos;
  TH2F*    R2_R3QuartzHitPos;
  TH2F*    R2_R4QuartzHitPos;
  TH2F*    R2_R5QuartzHitPos;
  TH2F*    R2_R8QuartzHitPos;
  TH2F*    R3_R1QuartzHitPos;
  TH2F*    R3_R2QuartzHitPos;
  TH2F*    R3_R3QuartzHitPos;
  TH2F*    R3_R4QuartzHitPos;
  TH2F*    R3_R5QuartzHitPos;
  TH2F*    R3_R8QuartzHitPos;
  TH2F*    R4_R1QuartzHitPos;
  TH2F*    R4_R2QuartzHitPos;
  TH2F*    R4_R3QuartzHitPos;
  TH2F*    R4_R4QuartzHitPos;
  TH2F*    R4_R5QuartzHitPos;
  TH2F*    R4_R8QuartzHitPos;
  TH2F*    R5_R1QuartzHitPos;
  TH2F*    R5_R2QuartzHitPos;
  TH2F*    R5_R3QuartzHitPos;
  TH2F*    R5_R4QuartzHitPos;
  TH2F*    R5_R5QuartzHitPos;
  TH2F*    R5_R8QuartzHitPos;
  TH2F*    R8_R1QuartzHitPos;
  TH2F*    R8_R2QuartzHitPos;
  TH2F*    R8_R3QuartzHitPos;
  TH2F*    R8_R4QuartzHitPos;
  TH2F*    R8_R5QuartzHitPos;
  TH2F*    R8_R8QuartzHitPos;
  TH2F*    R1Only_R1QuartzHitPos;
  TH2F*    R2Only_R2QuartzHitPos;
  TH2F*    R3Only_R3QuartzHitPos;
  TH2F*    R4Only_R4QuartzHitPos;
  TH2F*    R5Only_R5QuartzHitPos;
  TH2F*    R8Only_R8QuartzHitPos;
  TH2F*    R1Adjacent_R1QuartzHitPos;
  TH2F*    R1Adjacent_R3QuartzHitPos;
  TH2F*    R1Adjacent_R4QuartzHitPos;
  TH2F*    R1Adjacent_R5QuartzHitPos;
  TH2F*    R1Adjacent_R8QuartzHitPos;
  TH2F*    R2Adjacent_R2QuartzHitPos;
  TH2F*    R2Adjacent_R4QuartzHitPos;
  TH2F*    R2Adjacent_R5QuartzHitPos;
  TH2F*    R2Adjacent_R8QuartzHitPos;
  TH2F*    R3Adjacent_R1QuartzHitPos;
  TH2F*    R3Adjacent_R3QuartzHitPos;
  TH2F*    R3Adjacent_R5QuartzHitPos;
  TH2F*    R3Adjacent_R8QuartzHitPos;
  TH2F*    R4Adjacent_R1QuartzHitPos;
  TH2F*    R4Adjacent_R2QuartzHitPos;
  TH2F*    R4Adjacent_R4QuartzHitPos;
  TH2F*    R4Adjacent_R8QuartzHitPos;
  TH2F*    R5Adjacent_R1QuartzHitPos;
  TH2F*    R5Adjacent_R2QuartzHitPos;
  TH2F*    R5Adjacent_R3QuartzHitPos;
  TH2F*    R5Adjacent_R5QuartzHitPos;
  TH2F*    R8Adjacent_R1QuartzHitPos;
  TH2F*    R8Adjacent_R2QuartzHitPos;
  TH2F*    R8Adjacent_R3QuartzHitPos;
  TH2F*    R8Adjacent_R4QuartzHitPos;
  TH2F*    R8Adjacent_R8QuartzHitPos;
  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
