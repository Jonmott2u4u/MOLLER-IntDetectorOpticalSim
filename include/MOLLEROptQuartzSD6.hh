#ifndef MOLLEROptQuartzSD6_h
#define MOLLEROptQuartzSD6_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit6.hh"
#include "MOLLEROptTrackingReadout6.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD6 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD6(G4String name, MOLLEROptTrackingReadout6* TrRO6);
  virtual ~MOLLEROptQuartzSD6();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout6* TrackingReadout6;
  
  MOLLEROptQuartzHitsCollection6*  HitsCollection6;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

