#ifndef MOLLEROptQuartzSD8_h
#define MOLLEROptQuartzSD8_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit8.hh"
#include "MOLLEROptTrackingReadout8.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD8 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD8(G4String name, MOLLEROptTrackingReadout8* TrRO8);
  virtual ~MOLLEROptQuartzSD8();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout8* TrackingReadout8;
  
  MOLLEROptQuartzHitsCollection8*  HitsCollection8;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

