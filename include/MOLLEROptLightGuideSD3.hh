#ifndef MOLLEROptLightGuideSD3_h
#define MOLLEROptLightGuideSD3_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit3.hh"
#include "MOLLEROptTrackingReadout3.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD3 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD3(G4String name, MOLLEROptTrackingReadout3* TrRO3);
  virtual ~MOLLEROptLightGuideSD3();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout3* TrackingReadout3;
  
  MOLLEROptLightGuideHitsCollection3*  HitsCollection3;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


