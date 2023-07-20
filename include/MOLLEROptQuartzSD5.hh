#ifndef MOLLEROptQuartzSD5_h
#define MOLLEROptQuartzSD5_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit5.hh"
#include "MOLLEROptTrackingReadout5.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD5 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD5(G4String name, MOLLEROptTrackingReadout5* TrRO);
  virtual ~MOLLEROptQuartzSD5();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout5* TrackingReadout5;
  
  MOLLEROptQuartzHitsCollection5*  HitsCollection5;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

