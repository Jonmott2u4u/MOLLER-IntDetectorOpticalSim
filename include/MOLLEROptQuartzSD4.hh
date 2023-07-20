#ifndef MOLLEROptQuartzSD4_h
#define MOLLEROptQuartzSD4_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptQuartzHit4.hh"
#include "MOLLEROptTrackingReadout4.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptQuartzSD4 : public G4VSensitiveDetector
{

public:
  MOLLEROptQuartzSD4(G4String name, MOLLEROptTrackingReadout4* TrRO);
  virtual ~MOLLEROptQuartzSD4();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout4* TrackingReadout4;
  
  MOLLEROptQuartzHitsCollection4*  HitsCollection4;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

