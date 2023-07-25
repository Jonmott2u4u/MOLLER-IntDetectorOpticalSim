#ifndef MOLLEROptRunActionMessenger3_h
#define MOLLEROptRunActionMessenger3_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction3.hh"

class MOLLEROptRunAction3;

class MOLLEROptRunActionMessenger3: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger3(MOLLEROptRunAction3*);
  ~MOLLEROptRunActionMessenger3();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction3*          RunAction3;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
