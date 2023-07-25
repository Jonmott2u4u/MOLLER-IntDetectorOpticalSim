#ifndef MOLLEROptLightGuideSD6_h
#define MOLLEROptLightGuideSD6_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit6.hh"
#include "MOLLEROptTrackingReadout6.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD6 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD6(G4String name, MOLLEROptTrackingReadout6* TrRO6);
  virtual ~MOLLEROptLightGuideSD6();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout6* TrackingReadout6;
  
  MOLLEROptLightGuideHitsCollection6*  HitsCollection6;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


