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

  //These histograms do not care about the scintillator combination (only that the scint cuts were passed)
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

  //These histograms store the initial angles of primary particles that hit each tile. Will eventually update to angle when striking tile
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

  void R1_Scint13_AddInitialBeamAngleHist(Float_t aang){ R1_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R2_Scint13_AddInitialBeamAngleHist(Float_t aang){ R2_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R3_Scint13_AddInitialBeamAngleHist(Float_t aang){ R3_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R4_Scint13_AddInitialBeamAngleHist(Float_t aang){ R4_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R5_Scint13_AddInitialBeamAngleHist(Float_t aang){ R5_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R6_Scint13_AddInitialBeamAngleHist(Float_t aang){ R6_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R7_Scint13_AddInitialBeamAngleHist(Float_t aang){ R7_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R8_Scint13_AddInitialBeamAngleHist(Float_t aang){ R8_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R1Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R1Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R2Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R2Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R3Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R3Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R4Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R4Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R5Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R5Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R6Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R6Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R7Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R7Only_Scint13_InitialBeamAngleHist->Fill(aang);};
  void R8Only_Scint13_AddInitialBeamAngleHist(Float_t aang){ R8Only_Scint13_InitialBeamAngleHist->Fill(aang);};

  void R1_Scint14_AddInitialBeamAngleHist(Float_t aang){ R1_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R2_Scint14_AddInitialBeamAngleHist(Float_t aang){ R2_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R3_Scint14_AddInitialBeamAngleHist(Float_t aang){ R3_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R4_Scint14_AddInitialBeamAngleHist(Float_t aang){ R4_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R5_Scint14_AddInitialBeamAngleHist(Float_t aang){ R5_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R6_Scint14_AddInitialBeamAngleHist(Float_t aang){ R6_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R7_Scint14_AddInitialBeamAngleHist(Float_t aang){ R7_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R8_Scint14_AddInitialBeamAngleHist(Float_t aang){ R8_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R1Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R1Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R2Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R2Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R3Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R3Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R4Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R4Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R5Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R5Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R6Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R6Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R7Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R7Only_Scint14_InitialBeamAngleHist->Fill(aang);};
  void R8Only_Scint14_AddInitialBeamAngleHist(Float_t aang){ R8Only_Scint14_InitialBeamAngleHist->Fill(aang);};

  void R1_Scint23_AddInitialBeamAngleHist(Float_t aang){ R1_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R2_Scint23_AddInitialBeamAngleHist(Float_t aang){ R2_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R3_Scint23_AddInitialBeamAngleHist(Float_t aang){ R3_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R4_Scint23_AddInitialBeamAngleHist(Float_t aang){ R4_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R5_Scint23_AddInitialBeamAngleHist(Float_t aang){ R5_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R6_Scint23_AddInitialBeamAngleHist(Float_t aang){ R6_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R7_Scint23_AddInitialBeamAngleHist(Float_t aang){ R7_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R8_Scint23_AddInitialBeamAngleHist(Float_t aang){ R8_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R1Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R1Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R2Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R2Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R3Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R3Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R4Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R4Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R5Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R5Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R6Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R6Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R7Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R7Only_Scint23_InitialBeamAngleHist->Fill(aang);};
  void R8Only_Scint23_AddInitialBeamAngleHist(Float_t aang){ R8Only_Scint23_InitialBeamAngleHist->Fill(aang);};

  void R1_Scint24_AddInitialBeamAngleHist(Float_t aang){ R1_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R2_Scint24_AddInitialBeamAngleHist(Float_t aang){ R2_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R3_Scint24_AddInitialBeamAngleHist(Float_t aang){ R3_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R4_Scint24_AddInitialBeamAngleHist(Float_t aang){ R4_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R5_Scint24_AddInitialBeamAngleHist(Float_t aang){ R5_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R6_Scint24_AddInitialBeamAngleHist(Float_t aang){ R6_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R7_Scint24_AddInitialBeamAngleHist(Float_t aang){ R7_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R8_Scint24_AddInitialBeamAngleHist(Float_t aang){ R8_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R1Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R1Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R2Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R2Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R3Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R3Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R4Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R4Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R5Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R5Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R6Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R6Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R7Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R7Only_Scint24_InitialBeamAngleHist->Fill(aang);};
  void R8Only_Scint24_AddInitialBeamAngleHist(Float_t aang){ R8Only_Scint24_InitialBeamAngleHist->Fill(aang);};

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

  TH1F*    R1_Scint13_InitialBeamAngleHist;
  TH1F*    R2_Scint13_InitialBeamAngleHist;
  TH1F*    R3_Scint13_InitialBeamAngleHist;
  TH1F*    R4_Scint13_InitialBeamAngleHist;
  TH1F*    R5_Scint13_InitialBeamAngleHist;
  TH1F*    R6_Scint13_InitialBeamAngleHist;
  TH1F*    R7_Scint13_InitialBeamAngleHist;
  TH1F*    R8_Scint13_InitialBeamAngleHist;
  TH1F*    R1Only_Scint13_InitialBeamAngleHist;
  TH1F*    R2Only_Scint13_InitialBeamAngleHist;
  TH1F*    R3Only_Scint13_InitialBeamAngleHist;
  TH1F*    R4Only_Scint13_InitialBeamAngleHist;
  TH1F*    R5Only_Scint13_InitialBeamAngleHist;
  TH1F*    R6Only_Scint13_InitialBeamAngleHist;
  TH1F*    R7Only_Scint13_InitialBeamAngleHist;
  TH1F*    R8Only_Scint13_InitialBeamAngleHist;

  TH1F*    R1_Scint14_InitialBeamAngleHist;
  TH1F*    R2_Scint14_InitialBeamAngleHist;
  TH1F*    R3_Scint14_InitialBeamAngleHist;
  TH1F*    R4_Scint14_InitialBeamAngleHist;
  TH1F*    R5_Scint14_InitialBeamAngleHist;
  TH1F*    R6_Scint14_InitialBeamAngleHist;
  TH1F*    R7_Scint14_InitialBeamAngleHist;
  TH1F*    R8_Scint14_InitialBeamAngleHist;
  TH1F*    R1Only_Scint14_InitialBeamAngleHist;
  TH1F*    R2Only_Scint14_InitialBeamAngleHist;
  TH1F*    R3Only_Scint14_InitialBeamAngleHist;
  TH1F*    R4Only_Scint14_InitialBeamAngleHist;
  TH1F*    R5Only_Scint14_InitialBeamAngleHist;
  TH1F*    R6Only_Scint14_InitialBeamAngleHist;
  TH1F*    R7Only_Scint14_InitialBeamAngleHist;
  TH1F*    R8Only_Scint14_InitialBeamAngleHist;

  TH1F*    R1_Scint23_InitialBeamAngleHist;
  TH1F*    R2_Scint23_InitialBeamAngleHist;
  TH1F*    R3_Scint23_InitialBeamAngleHist;
  TH1F*    R4_Scint23_InitialBeamAngleHist;
  TH1F*    R5_Scint23_InitialBeamAngleHist;
  TH1F*    R6_Scint23_InitialBeamAngleHist;
  TH1F*    R7_Scint23_InitialBeamAngleHist;
  TH1F*    R8_Scint23_InitialBeamAngleHist;
  TH1F*    R1Only_Scint23_InitialBeamAngleHist;
  TH1F*    R2Only_Scint23_InitialBeamAngleHist;
  TH1F*    R3Only_Scint23_InitialBeamAngleHist;
  TH1F*    R4Only_Scint23_InitialBeamAngleHist;
  TH1F*    R5Only_Scint23_InitialBeamAngleHist;
  TH1F*    R6Only_Scint23_InitialBeamAngleHist;
  TH1F*    R7Only_Scint23_InitialBeamAngleHist;
  TH1F*    R8Only_Scint23_InitialBeamAngleHist;

  TH1F*    R1_Scint24_InitialBeamAngleHist;
  TH1F*    R2_Scint24_InitialBeamAngleHist;
  TH1F*    R3_Scint24_InitialBeamAngleHist;
  TH1F*    R4_Scint24_InitialBeamAngleHist;
  TH1F*    R5_Scint24_InitialBeamAngleHist;
  TH1F*    R6_Scint24_InitialBeamAngleHist;
  TH1F*    R7_Scint24_InitialBeamAngleHist;
  TH1F*    R8_Scint24_InitialBeamAngleHist;
  TH1F*    R1Only_Scint24_InitialBeamAngleHist;
  TH1F*    R2Only_Scint24_InitialBeamAngleHist;
  TH1F*    R3Only_Scint24_InitialBeamAngleHist;
  TH1F*    R4Only_Scint24_InitialBeamAngleHist;
  TH1F*    R5Only_Scint24_InitialBeamAngleHist;
  TH1F*    R6Only_Scint24_InitialBeamAngleHist;
  TH1F*    R7Only_Scint24_InitialBeamAngleHist;
  TH1F*    R8Only_Scint24_InitialBeamAngleHist;

  TH1F*    NoHit_InitialBeamAngleHist;
  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
