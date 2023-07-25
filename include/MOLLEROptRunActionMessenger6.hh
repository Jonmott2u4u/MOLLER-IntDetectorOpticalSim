#ifndef MOLLEROptRunActionMessenger6_h
#define MOLLEROptRunActionMessenger6_h 1

#include "cpp_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptRunAction6.hh"

class MOLLEROptRunAction6;

class MOLLEROptRunActionMessenger6: public G4UImessenger
{
public:
    MOLLEROptRunActionMessenger6(MOLLEROptRunAction6*);
  ~MOLLEROptRunActionMessenger6();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  MOLLEROptRunAction6*          RunAction6;
  G4UIdirectory*             Dir;
  
  G4UIcmdWithAnInteger*      MyRunIDCmd;
  G4UIcmdWithAnInteger*      ROOTFileFlagCmd;
  G4UIcmdWithAString*      ROOTFileName;

};

#endif
