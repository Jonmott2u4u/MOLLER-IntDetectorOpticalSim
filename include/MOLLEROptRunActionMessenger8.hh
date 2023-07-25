#ifndef MOLLEROptRunActionMessenger8_h
#define MOLLEROptRunActionMessenger8_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction8.hh"

class MOLLEROptRunAction8;

class MOLLEROptRunActionMessenger8: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger8(MOLLEROptRunAction8*);
  ~MOLLEROptRunActionMessenger8();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction8*          RunAction8;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
