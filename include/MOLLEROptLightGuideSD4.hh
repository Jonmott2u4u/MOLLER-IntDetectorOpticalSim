#ifndef MOLLEROptLightGuideSD4_h
#define MOLLEROptLightGuideSD4_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptLightGuideHit4.hh"
#include "MOLLEROptTrackingReadout4.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptLightGuideSD4 : public G4VSensitiveDetector
{

public:
  MOLLEROptLightGuideSD4(G4String name, MOLLEROptTrackingReadout4* TrRO4);
  virtual ~MOLLEROptLightGuideSD4();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout4* TrackingReadout4;
  
  MOLLEROptLightGuideHitsCollection4*  HitsCollection4;
  G4String theCollectionName;
  G4int theCollectionID;

};
#endif


