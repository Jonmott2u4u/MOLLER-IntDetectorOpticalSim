#ifndef MOLLEROptQuartzSD3_h
#define MOLLEROptQuartzSD3_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit3.hh"
#include "MOLLEROptTrackingReadout3.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD3 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD3(G4String name, MOLLEROptTrackingReadout3* TrRO3);
  virtual ~MOLLEROptQuartzSD3();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout3* TrackingReadout3;
  
  MOLLEROptQuartzHitsCollection3*  HitsCollection3;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

