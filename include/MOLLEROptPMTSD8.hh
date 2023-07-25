#ifndef MOLLEROptPMTSD8_h
#define MOLLEROptPMTSD8_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTHit8.hh"
#include "MOLLEROptTrackingReadout8.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptPMTSD8 : public G4VSensitiveDetector
{

public:
  MOLLEROptPMTSD8(G4String name, MOLLEROptTrackingReadout8* TrRO8);
  virtual ~MOLLEROptPMTSD8();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout8* TrackingReadout8;
  
  MOLLEROptPMTHitsCollection8*  HitsCollection8;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

