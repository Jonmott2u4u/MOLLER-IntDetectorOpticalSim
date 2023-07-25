#ifndef MOLLEROptPMTSD7_h
#define MOLLEROptPMTSD7_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTHit7.hh"
#include "MOLLEROptTrackingReadout7.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptPMTSD7 : public G4VSensitiveDetector
{

public:
  MOLLEROptPMTSD7(G4String name, MOLLEROptTrackingReadout7* TrRO7);
  virtual ~MOLLEROptPMTSD7();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout7* TrackingReadout7;
  
  MOLLEROptPMTHitsCollection7*  HitsCollection7;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

