#ifndef MOLLEROptEventAction7_h
#define MOLLEROptEventAction7_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis7.hh"
#include "MOLLEROptQuartzHit7.hh"
#include "MOLLEROptLightGuideHit7.hh"
#include "MOLLEROptPMTHit7.hh"
#include "MOLLEROptTrackingReadout7.hh"

class MOLLEROptAnalysis7;

struct lTrackData7
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction7 : public G4UserEventAction
{
public:

    MOLLEROptEventAction7(MOLLEROptAnalysis7* AN, MOLLEROptTrackingReadout7* myUI);
    ~MOLLEROptEventAction7();
  
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
  vector <lTrackData7*> ProcessedTrack;


  MOLLEROptAnalysis7*             analysis7;
  MOLLEROptTrackingReadout7*      TrackingReadout7;

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
