#ifndef MOLLEROptEventAction3_h
#define MOLLEROptEventAction3_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis3.hh"
#include "MOLLEROptQuartzHit3.hh"
#include "MOLLEROptLightGuideHit3.hh"
#include "MOLLEROptPMTHit3.hh"
#include "MOLLEROptTrackingReadout3.hh"

class MOLLEROptAnalysis3;

struct lTrackData3
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction3 : public G4UserEventAction
{
public:

    MOLLEROptEventAction3(MOLLEROptAnalysis3* AN, MOLLEROptTrackingReadout3* myUI);
    ~MOLLEROptEventAction3();
  
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
  vector <lTrackData3*> ProcessedTrack;


  MOLLEROptAnalysis3*             analysis3;
  MOLLEROptTrackingReadout3*      TrackingReadout3;

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
