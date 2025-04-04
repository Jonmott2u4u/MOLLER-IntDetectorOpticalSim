#ifndef MOLLEROptScintSD_h
#define MOLLEROptScintSD_h 

#include "cpp_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptScintHit.hh"
#include "MOLLEROptTrackingReadout.hh"

class G4Step;
class G4HCofThisEvent;

class MOLLEROptScintSD : public G4VSensitiveDetector
{

public:
  MOLLEROptScintSD(G4String name, MOLLEROptTrackingReadout* TrRO);
  virtual ~MOLLEROptScintSD();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep,G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:

  MOLLEROptTrackingReadout* TrackingReadout;
  //MOLLEROptTrackingReadout* TrackingReadout2;  
  
  MOLLEROptScintHitsCollection*  HitsCollection01;
  MOLLEROptScintHitsCollection*  HitsCollection02;
  MOLLEROptScintHitsCollection*  HitsCollection03;
  MOLLEROptScintHitsCollection*  HitsCollection04;
  
  G4String theCollectionName;
  G4int theCollectionID;
  const std::vector<const G4Track*>* Secondaries;

};
#endif

