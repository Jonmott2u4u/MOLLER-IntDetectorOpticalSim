#ifndef MOLLEROptPMTSD2_h
#define MOLLEROptPMTSD2_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTHit2.hh"
#include "MOLLEROptTrackingReadout2.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptPMTSD2 : public G4VSensitiveDetector
{

public:
  MOLLEROptPMTSD2(G4String name, MOLLEROptTrackingReadout2* TrRO2);
  virtual ~MOLLEROptPMTSD2();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout2* TrackingReadout2;
  
  MOLLEROptPMTHitsCollection2*  HitsCollection2;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

