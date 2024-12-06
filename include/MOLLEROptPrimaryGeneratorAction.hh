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
  void SetPrimaryParticle(G4int reg) {PrimaryParticle = reg;};
  void SetEventHitRegion(G4int reg) {EventRegion = reg;};
  void SetEventShift(G4double reg) {shift = reg;};
  void SetSegmentHitRegion(G4double reg) {cut = reg;};
  void SetBeamTheta(G4int reg) {theta = reg;};
  void SetBeamPhi(G4int reg) {phi = reg;};
  void SetBeamSolidAngle(G4double reg) {sa = reg;};
  void SetBeamTiltAngle(G4double reg) {tilt = reg;};
  void SetBeamTiltDirection(G4double reg) {tilt_dir = reg;};
  void SetBeamEnergy(G4int reg) {Energy = reg;};
  void SetBeamEnergyCut(G4int reg) {EnergyCut = reg;};
    
  
private:

  G4int PrimaryParticle;
  G4int EventRegion;
  G4int EventCounter;
  G4int theta;
  G4int phi;
  G4double sa;
  G4double tilt;
  G4double tilt_dir;
  G4int Energy;
  G4int EnergyCut;
  G4double shift;
  G4double cut;
  
  G4ParticleGun* particleGun;

  MOLLEROptConstruction* Construction;
  
  MOLLEROptPrimaryGeneratorActionMessenger* Messenger;

};

#endif
