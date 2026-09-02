#ifndef MOLLEROptEventAction_h
#define MOLLEROptEventAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis.hh"
#include "MOLLEROptQuartzHit.hh"
#include "MOLLEROptLightGuideHit.hh"
#include "MOLLEROptPMTHit.hh"
#include "MOLLEROptScintHit.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptEventActionMessenger.hh"

class MOLLEROptAnalysis;
class MOLLEROptEventActionMessenger;

struct lTrackData
{
  Int_t ID;
  Int_t Length;
  Int_t Steps;
};

class MOLLEROptEventAction : public G4UserEventAction
{
public:

    MOLLEROptEventAction(MOLLEROptAnalysis* AN, MOLLEROptTrackingReadout* myUI);
    ~MOLLEROptEventAction();
  
public:

  void BeginOfEventAction(const G4Event* evt);
  void EndOfEventAction(const G4Event* evt);
  
public:

  void SetDetectorFocus(G4int reg) {Det = reg;};

private:

  void Initialize();
  Bool_t TrackHasBeenProcessed(G4int ID);
  void AddTrackStep(G4int id, G4int step); //For quartz and scint
  char buffer[100];
  G4int Det;

  vector <lTrackData*> ProcessedTrack;

  MOLLEROptAnalysis*             analysis;
  MOLLEROptTrackingReadout*      TrackingReadout;

  //Float_t  OriginVertexX;
  //Float_t  OriginVertexY;
  //Float_t  OriginVertexZ;
  Float_t  OriginVertexKineticEnergy;
  
  //G4int  primaryEventNumber;
  TH1D *PMTSecOptPhotonCnt;
  TH1D *QuartzSecOptPhotonCnt;
  TH1D *LightGuideSecOptPhotonCnt;

  MOLLEROptEventActionMessenger* EventMessenger;
};

#endif

