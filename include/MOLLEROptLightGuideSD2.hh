#ifndef MOLLEROptLightGuideSD2_h
#define MOLLEROptLightGuideSD2_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit2.hh"
#include "MOLLEROptTrackingReadout2.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD2 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD2(G4String name, MOLLEROptTrackingReadout2* TrRO2);
  virtual ~MOLLEROptLightGuideSD2();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout2* TrackingReadout2;
  
  MOLLEROptLightGuideHitsCollection2*  HitsCollection2;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


