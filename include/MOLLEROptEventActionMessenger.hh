#ifndef MOLLEROptEventActionMessenger_h
#define MOLLEROptEventActionMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptEventAction.hh"

class MOLLEROptEventAction;

class MOLLEROptEventActionMessenger: public G4UImessenger
{
public:  
   MOLLEROptEventActionMessenger(MOLLEROptEventAction* );
  ~MOLLEROptEventActionMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);
    
private:  
  
  MOLLEROptEventAction*     EventAction;
  
  G4UIdirectory*           Dir;
  G4UIcmdWithAnInteger     *DetectorFocusCmd;
  G4UIcmdWithADouble        *BeamEnergyCutCmd;

};

#endif