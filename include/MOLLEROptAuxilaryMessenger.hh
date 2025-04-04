#ifndef MOLLEROptAuxilaryMessenger_h
#define MOLLEROptAuxilaryMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAuxilary.hh"

class MOLLEROptAuxilary;

class MOLLEROptAuxilaryMessenger: public G4UImessenger
{
  public:
    MOLLEROptAuxilaryMessenger(MOLLEROptAuxilary*, G4String);
   ~MOLLEROptAuxilaryMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  G4String                   AuxType;
  MOLLEROptAuxilary*         Aux;
  G4UIdirectory*             Dir;

  G4UIcmdWithAString*        AuxMatCmd;
  
  G4UIcmdWithADoubleAndUnit* AuxXPositionCmd;
  G4UIcmdWithADoubleAndUnit* AuxYPositionCmd;
  G4UIcmdWithADoubleAndUnit* AuxZPositionCmd;
  G4UIcmdWithADoubleAndUnit* SizeXCmd;       
  G4UIcmdWithADoubleAndUnit* SizeYCmd;       
  G4UIcmdWithADoubleAndUnit* SizeZCmd;
                     
  G4UIcmdWithADoubleAndUnit* RotXCmd;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd;
  G4UIcmdWithADoubleAndUnit* AzimuthalRotationCmd;

  G4UIcmdWithoutParameter*   UpdateGeometryCmd;

};

#endif
