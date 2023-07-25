#ifndef MOLLEROptPMTSD4_h
#define MOLLEROptPMTSD4_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTHit4.hh"
#include "MOLLEROptTrackingReadout4.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptPMTSD4 : public G4VSensitiveDetector
{

public:
  MOLLEROptPMTSD4(G4String name, MOLLEROptTrackingReadout4* TrRO4);
  virtual ~MOLLEROptPMTSD4();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout4* TrackingReadout4;
  
  MOLLEROptPMTHitsCollection4*  HitsCollection4;
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

