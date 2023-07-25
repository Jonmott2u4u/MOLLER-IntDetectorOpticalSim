#ifndef MOLLEROptLightGuideSD5_h
#define MOLLEROptLightGuideSD5_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit5.hh"
#include "MOLLEROptTrackingReadout5.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD5 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD5(G4String name, MOLLEROptTrackingReadout5* TrRO5);
  virtual ~MOLLEROptLightGuideSD5();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout5* TrackingReadout5;
  
  MOLLEROptLightGuideHitsCollection5*  HitsCollection5;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


