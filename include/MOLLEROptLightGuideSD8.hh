#ifndef MOLLEROptLightGuideSD8_h
#define MOLLEROptLightGuideSD8_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit8.hh"
#include "MOLLEROptTrackingReadout8.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD8 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD8(G4String name, MOLLEROptTrackingReadout8* TrRO);
  virtual ~MOLLEROptLightGuideSD8();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout8* TrackingReadout8;
  
  MOLLEROptLightGuideHitsCollection8*  HitsCollection8;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


