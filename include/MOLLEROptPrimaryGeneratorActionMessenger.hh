#ifndef MOLLEROptPrimaryGeneratorActionMessenger_h
#define MOLLEROptPrimaryGeneratorActionMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptPrimaryGeneratorAction.hh"

class MOLLEROptPrimaryGeneratorAction;

class MOLLEROptPrimaryGeneratorActionMessenger: public G4UImessenger
{
public:  
   MOLLEROptPrimaryGeneratorActionMessenger(MOLLEROptPrimaryGeneratorAction* );
  ~MOLLEROptPrimaryGeneratorActionMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);
    
private:  
  
  MOLLEROptPrimaryGeneratorAction*     pPrimaryGeneratorAction;
  
  G4UIdirectory*           Dir;
  G4UIcmdWithAnInteger*    verboseCmd;
  G4UIcmdWithoutParameter* resetCmd;
  G4UIcmdWithAnInteger     *InitEventCounterCmd;
  G4UIcmdWithAnInteger     *EventHitRegionCmd;
  G4UIcmdWithAnInteger     *QuartzHitRegionCmd;
  G4UIcmdWithAnInteger     *BeamThetaCmd;
  G4UIcmdWithAnInteger     *BeamPhiCmd;
  G4UIcmdWithAnInteger     *BeamSolidAngleCmd;
  G4UIcmdWithAnInteger     *BeamEnergyCmd;

};

#endif
