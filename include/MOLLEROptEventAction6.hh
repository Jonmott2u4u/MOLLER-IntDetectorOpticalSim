#ifndef MOLLEROptEventAction6_h
#define MOLLEROptEventAction6_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis6.hh"
#include "MOLLEROptQuartzHit6.hh"
#include "MOLLEROptLightGuideHit6.hh"
#include "MOLLEROptPMTHit6.hh"
#include "MOLLEROptTrackingReadout6.hh"

class MOLLEROptAnalysis6;

struct lTrackData6
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction6 : public G4UserEventAction
{
public:

    MOLLEROptEventAction6(MOLLEROptAnalysis6* AN, MOLLEROptTrackingReadout6* myUI);
    ~MOLLEROptEventAction6();
  
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
  vector <lTrackData6*> ProcessedTrack;


  MOLLEROptAnalysis6*             analysis6;
  MOLLEROptTrackingReadout6*      TrackingReadout6;

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
