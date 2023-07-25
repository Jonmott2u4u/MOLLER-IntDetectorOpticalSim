#ifndef MOLLEROptEventAction8_h
#define MOLLEROptEventAction8_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis8.hh"
#include "MOLLEROptQuartzHit8.hh"
#include "MOLLEROptLightGuideHit8.hh"
#include "MOLLEROptPMTHit8.hh"
#include "MOLLEROptTrackingReadout8.hh"

class MOLLEROptAnalysis8;

struct lTrackData8
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction8 : public G4UserEventAction
{
public:

    MOLLEROptEventAction8(MOLLEROptAnalysis8* AN, MOLLEROptTrackingReadout8* myUI);
    ~MOLLEROptEventAction8();
  
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
  vector <lTrackData8*> ProcessedTrack;


  MOLLEROptAnalysis8*             analysis8;
  MOLLEROptTrackingReadout8*      TrackingReadout8;

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
