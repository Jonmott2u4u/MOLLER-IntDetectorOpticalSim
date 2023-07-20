#ifndef MOLLEROptLightGuideSD7_h
#define MOLLEROptLightGuideSD7_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit7.hh"
#include "MOLLEROptTrackingReadout7.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD7 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD7(G4String name, MOLLEROptTrackingReadout7* TrRO);
  virtual ~MOLLEROptLightGuideSD7();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout7* TrackingReadout7;
  
  MOLLEROptLightGuideHitsCollection7*  HitsCollection7;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


