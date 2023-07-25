#ifndef MOLLEROptEventAction5_h
#define MOLLEROptEventAction5_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis5.hh"
#include "MOLLEROptQuartzHit5.hh"
#include "MOLLEROptLightGuideHit5.hh"
#include "MOLLEROptPMTHit5.hh"
#include "MOLLEROptTrackingReadout5.hh"

class MOLLEROptAnalysis5;

struct lTrackData5
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction5 : public G4UserEventAction
{
public:

    MOLLEROptEventAction5(MOLLEROptAnalysis5* AN, MOLLEROptTrackingReadout5* myUI);
    ~MOLLEROptEventAction5();
  
public:

  void BeginOfEventAction(const G4Event* evt);
  void EndOfEventAction(const G4Event* evt);
  
private:

  void Initialize();
  Bool_t TrackHasBeenProcessed(G4int ID);
  void AddQuartzTrackStep(G4int id, G4int step);
  char buffer[100];
  G4int CollID[3];

  //vector <Int_t> ProcessedTrack;
  vector <lTrackData5*> ProcessedTrack;


  MOLLEROptAnalysis5*             analysis5;
  MOLLEROptTrackingReadout5*      TrackingReadout5;

  Float_t  OriginVertexX;
  Float_t  OriginVertexY;
  Float_t  OriginVertexZ;
  Float_t  OriginVertexKineticEnergy;
  
  G4int  primaryEventNumber;
  TH1D *PMTSecOptPhotonCnt;
  TH1D *QuartzSecOptPhotonCnt;
  TH1D *LightGuideSecOptPhotonCnt;

  ofstream oFile;
};

#endif
