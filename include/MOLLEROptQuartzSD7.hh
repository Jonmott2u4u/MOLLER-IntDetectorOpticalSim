#ifndef MOLLEROptQuartzSD7_h
#define MOLLEROptQuartzSD7_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit7.hh"
#include "MOLLEROptTrackingReadout7.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD7 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD7(G4String name, MOLLEROptTrackingReadout7* TrRO7);
  virtual ~MOLLEROptQuartzSD7();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout7* TrackingReadout7;
  
  MOLLEROptQuartzHitsCollection7*  HitsCollection7;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

