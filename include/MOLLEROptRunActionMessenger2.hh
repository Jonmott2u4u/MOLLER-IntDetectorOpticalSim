#ifndef MOLLEROptRunActionMessenger2_h
#define MOLLEROptRunActionMessenger2_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction2.hh"

class MOLLEROptRunAction2;

class MOLLEROptRunActionMessenger2: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger2(MOLLEROptRunAction2*);
  ~MOLLEROptRunActionMessenger2();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction2*          RunAction2;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
