#ifndef MOLLEROptAnalysis4_h 
#define MOLLEROptAnalysis4_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptMainEvent.hh"
#include "MOLLEROptTrackingReadout4.hh"

class MOLLEROptMainEvent;

class MOLLEROptAnalysis4 {
public:
  MOLLEROptAnalysis4();
  virtual ~MOLLEROptAnalysis4();
  
public:

  // void BeginOfRun(G4int runID, G4double pressure, G4double coll);
  void BeginOfRun(G4int runID, G4String name1, MOLLEROptTrackingReadout4 *TrRO);
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

  void AddPhotoElectronEvent(Double_t pe){ PhotoElectronDistrHist->Fill(pe);};
  void AddCathodeDetectionEvent(Int_t events) {CathodeEventsDistrHist->Fill(events);};

  MOLLEROptMainEvent* MOLLERMainEvent;

private:

  MOLLEROptTrackingReadout4* TrackingReadout4;
  
  void ConstructRootNtuple(); 

  TTree*   MOLLEROptNtuple;
  TBranch* MOLLEROptMainBranch;
  TFile*   MOLLEROptFile;
  TProfile*    PMTOptPhotonDistrHist;
  TProfile*    QuartzOptPhotonDistrHist;
  TProfile*    LightGuideOptPhotonDistrHist;
  TH1D*    PhotoElectronDistrHist;
  TH1D*    CathodeEventsDistrHist;
  
  TVectorD *NumberOfPrimaries;
  Float_t OptPhotonDist[800];
  Int_t OptPhotonDistCnt[800];

  G4int ROOTFileFlag;
  G4String ROOTFileName;
  Int_t EventCnt;


};

#endif
