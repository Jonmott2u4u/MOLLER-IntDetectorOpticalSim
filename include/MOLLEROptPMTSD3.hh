#ifndef MOLLEROptPMTSD3_h
#define MOLLEROptPMTSD3_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTHit3.hh"
#include "MOLLEROptTrackingReadout3.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptPMTSD3 : public G4VSensitiveDetector
{

public:
  MOLLEROptPMTSD3(G4String name, MOLLEROptTrackingReadout3* TrRO3);
  virtual ~MOLLEROptPMTSD3();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout3* TrackingReadout3;
  
  MOLLEROptPMTHitsCollection3*  HitsCollection3;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

