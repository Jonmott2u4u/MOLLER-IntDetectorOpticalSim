#ifndef MOLLEROptSteppingAction_h
#define MOLLEROptSteppingAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptTrackingReadout2.hh"
#include "MOLLEROptTrackingReadout3.hh"
#include "MOLLEROptTrackingReadout4.hh"
#include "MOLLEROptTrackingReadout5.hh"
#include "MOLLEROptTrackingReadout6.hh"
#include "MOLLEROptTrackingReadout7.hh"
#include "MOLLEROptTrackingReadout8.hh"

class MOLLEROptSteppingAction : public G4UserSteppingAction
{
  
public:
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout* TrRO);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout2* TrRO2);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout3* TrRO3);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout4* TrRO4);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout5* TrRO5);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout6* TrRO6);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout7* TrRO7);
  MOLLEROptSteppingAction(MOLLEROptTrackingReadout8* TrRO8);
  ~MOLLEROptSteppingAction(){};
  
  void UserSteppingAction(const G4Step*);

  G4int GetNumOfAtRestSecondaries(){return    fpSteppingManager->GetfN2ndariesAtRestDoIt();};
  G4int GetNumOfAlongStepSecondaries(){return fpSteppingManager->GetfN2ndariesAlongStepDoIt();};
  G4int GetNumOfPostStepSecondaries(){return  fpSteppingManager->GetfN2ndariesPostStepDoIt();};
  G4int GetTotalNumOfSecondaries(){return     GetNumOfAtRestSecondaries() + GetNumOfAlongStepSecondaries() + GetNumOfPostStepSecondaries();};

  G4int GetTrackVectorStartIndex();
  G4int GetTrackVectorSize();

  G4ParticleDefinition *GetSecondaryParticleDefinition(G4int idx); 
  G4String              GetSecondaryParticleName(G4int idx); 
  G4double              GetSecondaryParticleTotalEnergy(G4int idx);
  G4double              GetSecondaryParticleKineticEnergy(G4int idx);
  G4double              GetSecondaryParticleXOrigin(G4int idx);
  G4double              GetSecondaryParticleYOrigin(G4int idx);
  G4double              GetSecondaryParticleZOrigin(G4int idx);    
  G4ThreeVector         GetSecondaryParticleOrigin(G4int idx);    
  G4ThreeVector         GetSecondaryParticleMomentum(G4int idx);    
  G4String              GetSecondaryCreatorProcessName(G4int idx);

  G4ThreeVector         ErrorVal;

private:

  void DrawTracks(G4bool, G4Track*);
  void DrawHits(G4bool, G4Track*);

  G4TrackVector *fSecondary;
  MOLLEROptTrackingReadout* TrackingReadout;
  MOLLEROptTrackingReadout2* TrackingReadout2;
  MOLLEROptTrackingReadout3* TrackingReadout3;
  MOLLEROptTrackingReadout4* TrackingReadout4;
  MOLLEROptTrackingReadout5* TrackingReadout5;
  MOLLEROptTrackingReadout6* TrackingReadout6;
  MOLLEROptTrackingReadout7* TrackingReadout7;
  MOLLEROptTrackingReadout8* TrackingReadout8;
  
};

#endif
