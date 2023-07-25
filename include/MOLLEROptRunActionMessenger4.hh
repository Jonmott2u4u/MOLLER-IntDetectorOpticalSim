#ifndef MOLLEROptRunActionMessenger4_h
#define MOLLEROptRunActionMessenger4_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction4.hh"

class MOLLEROptRunAction4;

class MOLLEROptRunActionMessenger4: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger4(MOLLEROptRunAction4*);
  ~MOLLEROptRunActionMessenger4();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction4*          RunAction4;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
