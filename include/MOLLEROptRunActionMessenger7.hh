#ifndef MOLLEROptRunActionMessenger7_h
#define MOLLEROptRunActionMessenger7_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction7.hh"

class MOLLEROptRunAction7;

class MOLLEROptRunActionMessenger7: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger7(MOLLEROptRunAction7*);
  ~MOLLEROptRunActionMessenger7();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction7*          RunAction7;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
