#ifndef MOLLEROptEventAction4_h
#define MOLLEROptEventAction4_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis4.hh"
#include "MOLLEROptQuartzHit4.hh"
#include "MOLLEROptLightGuideHit4.hh"
#include "MOLLEROptPMTHit4.hh"
#include "MOLLEROptTrackingReadout4.hh"

class MOLLEROptAnalysis4;

struct lTrackData4
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction4 : public G4UserEventAction
{
public:

    MOLLEROptEventAction4(MOLLEROptAnalysis4* AN, MOLLEROptTrackingReadout4* myUI);
    ~MOLLEROptEventAction4();
  
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
  vector <lTrackData4*> ProcessedTrack;


  MOLLEROptAnalysis4*             analysis4;
  MOLLEROptTrackingReadout4*      TrackingReadout4;

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
