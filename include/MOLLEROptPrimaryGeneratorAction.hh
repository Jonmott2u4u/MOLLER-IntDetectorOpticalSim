#ifndef MOLLEROptPrimaryGeneratorAction_h
#define MOLLEROptPrimaryGeneratorAction_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "MOLLEROptConstruction.hh"

#include "MOLLEROptPrimaryGeneratorActionMessenger.hh"

class MOLLEROptPrimaryGeneratorActionMessenger;
class G4ParticleGun;
class G4Event;
 
class MOLLEROptPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
   MOLLEROptPrimaryGeneratorAction(MOLLEROptConstruction*);    
  ~MOLLEROptPrimaryGeneratorAction();
  
public:

  void GeneratePrimaries(G4Event* anEvent);
  void ResetNtupleEventCounter() {EventCounter = 0;};
  void SetNtupleEventCounter(G4int cnt) {EventCounter = cnt;};
  void SetEventHitRgion(G4int reg) {EventRegion = reg;};
  void SetSegmentHitRegion(G4double reg) {cut = reg;};
  void SetBeamTheta(G4int reg) {theta = reg;};
  void SetBeamPhi(G4int reg) {phi = reg;};
  void SetBeamSolidAngle(G4int reg) {sa = reg;};
  void SetBeamEnergy(G4int reg) {Energy = reg;};
    
  
private:

  G4int EventRegion;
  G4int EventCounter;
  G4int cut;
  G4int theta;
  G4int phi;
  G4int sa;
  G4int Energy;
  
  G4ParticleGun* particleGun;

  MOLLEROptConstruction* Construction;
  
  MOLLEROptPrimaryGeneratorActionMessenger* Messenger;

};

#endif
