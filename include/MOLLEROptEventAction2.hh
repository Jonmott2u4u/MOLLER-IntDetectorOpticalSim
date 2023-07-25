#ifndef MOLLEROptEventAction2_h
#define MOLLEROptEventAction2_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis2.hh"
#include "MOLLEROptQuartzHit2.hh"
#include "MOLLEROptLightGuideHit2.hh"
#include "MOLLEROptPMTHit2.hh"
#include "MOLLEROptTrackingReadout2.hh"

class MOLLEROptAnalysis2;

struct lTrackData2
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction2 : public G4UserEventAction
{
public:

    MOLLEROptEventAction2(MOLLEROptAnalysis2* AN, MOLLEROptTrackingReadout2* myUI);
    ~MOLLEROptEventAction2();
  
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
  vector <lTrackData2*> ProcessedTrack;


  MOLLEROptAnalysis2*             analysis2;
  MOLLEROptTrackingReadout2*      TrackingReadout2;

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
