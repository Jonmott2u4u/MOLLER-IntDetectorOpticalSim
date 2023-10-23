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

  void R1_AddPhotoElectronEvent(Double_t pe){ R1_PhotoElectronDistrHist->Fill(pe);};
  void R1_AddCathodeDetectionEvent(Int_t events) {R1_CathodeEventsDistrHist->Fill(events);};
  void R2_AddPhotoElectronEvent(Double_t pe){ R2_PhotoElectronDistrHist->Fill(pe);};
  void R2_AddCathodeDetectionEvent(Int_t events) {R2_CathodeEventsDistrHist->Fill(events);};
  void R3_AddPhotoElectronEvent(Double_t pe){ R3_PhotoElectronDistrHist->Fill(pe);};
  void R3_AddCathodeDetectionEvent(Int_t events) {R3_CathodeEventsDistrHist->Fill(events);};
  void R4_AddPhotoElectronEvent(Double_t pe){ R4_PhotoElectronDistrHist->Fill(pe);};
  void R4_AddCathodeDetectionEvent(Int_t events) {R4_CathodeEventsDistrHist->Fill(events);};
  void R5_AddPhotoElectronEvent(Double_t pe){ R5_PhotoElectronDistrHist->Fill(pe);};
  void R5_AddCathodeDetectionEvent(Int_t events) {R5_CathodeEventsDistrHist->Fill(events);};
  void R6_AddPhotoElectronEvent(Double_t pe){ R6_PhotoElectronDistrHist->Fill(pe);};
  void R6_AddCathodeDetectionEvent(Int_t events) {R6_CathodeEventsDistrHist->Fill(events);};
  void R7_AddPhotoElectronEvent(Double_t pe){ R7_PhotoElectronDistrHist->Fill(pe);};
  void R7_AddCathodeDetectionEvent(Int_t events) {R7_CathodeEventsDistrHist->Fill(events);};
  void R8_AddPhotoElectronEvent(Double_t pe){ R8_PhotoElectronDistrHist->Fill(pe);};
  void R8_AddCathodeDetectionEvent(Int_t events) {R8_CathodeEventsDistrHist->Fill(events);};

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
  TH1D*    R1_PhotoElectronDistrHist;
  TH1D*    R1_CathodeEventsDistrHist;
  TH1D*    R2_PhotoElectronDistrHist;
  TH1D*    R2_CathodeEventsDistrHist;
  TH1D*    R3_PhotoElectronDistrHist;
  TH1D*    R3_CathodeEventsDistrHist;
  TH1D*    R4_PhotoElectronDistrHist;
  TH1D*    R4_CathodeEventsDistrHist;
  TH1D*    R5_PhotoElectronDistrHist;
  TH1D*    R5_CathodeEventsDistrHist;
  TH1D*    R6_PhotoElectronDistrHist;
  TH1D*    R6_CathodeEventsDistrHist;
  TH1D*    R7_PhotoElectronDistrHist;
  TH1D*    R7_CathodeEventsDistrHist;
  TH1D*    R8_PhotoElectronDistrHist;
  TH1D*    R8_CathodeEventsDistrHist;
  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
