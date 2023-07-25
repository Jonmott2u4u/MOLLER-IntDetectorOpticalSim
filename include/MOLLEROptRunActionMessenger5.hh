#ifndef MOLLEROptRunActionMessenger5_h
#define MOLLEROptRunActionMessenger5_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction5.hh"

class MOLLEROptRunAction5;

class MOLLEROptRunActionMessenger5: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger5(MOLLEROptRunAction5*);
  ~MOLLEROptRunActionMessenger5();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction5*          RunAction5;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
