#ifndef MOLLEROptInsensitiveMessenger_h
#define MOLLEROptInsensitiveMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptInsensitive.hh"

class MOLLEROptInsensitive;

class MOLLEROptInsensitiveMessenger: public G4UImessenger
{
  public:
    MOLLEROptInsensitiveMessenger(MOLLEROptInsensitive*, G4String);
   ~MOLLEROptInsensitiveMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  G4String                   InsType;
  MOLLEROptInsensitive*      Ins;
  G4UIdirectory*             Dir;

  G4UIcmdWithAString*        InsMatCmd;
  
  G4UIcmdWithADoubleAndUnit* InsXPositionCmd;
  G4UIcmdWithADoubleAndUnit* InsYPositionCmd;
  G4UIcmdWithADoubleAndUnit* InsZPositionCmd;
  G4UIcmdWithADoubleAndUnit* SizeXCmd;       
  G4UIcmdWithADoubleAndUnit* SizeYCmd;       
  G4UIcmdWithADoubleAndUnit* SizeZCmd;
                     
  G4UIcmdWithADoubleAndUnit* RotXCmd;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd;
  G4UIcmdWithADoubleAndUnit* AzimuthalRotationCmd;

  G4UIcmdWithoutParameter*   UpdateGeometryCmd;

};

#endif
