#include "MOLLEROptEventActionMessenger.hh"

MOLLEROptEventActionMessenger::MOLLEROptEventActionMessenger(MOLLEROptEventAction* theDet)
    :EventAction(theDet)
{

    Dir = new G4UIdirectory("/Storage/");
    Dir -> SetGuidance("Controlling what is saved in Root files.");
    
    //File selection command
    DetectorFocusCmd = new G4UIcmdWithAnInteger("/Storage/DetectorFocus",this);
    DetectorFocusCmd->SetGuidance("Set which detector to save Root info for.");
    DetectorFocusCmd->SetParameterName("DetectorFocus",true);
    DetectorFocusCmd->SetDefaultValue(0);
    DetectorFocusCmd->SetRange("DetectorFocus>=0");
    DetectorFocusCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

MOLLEROptEventActionMessenger::~MOLLEROptEventActionMessenger()
{
  delete Dir;
}

void MOLLEROptEventActionMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
    if( command == DetectorFocusCmd )
        { EventAction->SetDetectorFocus(DetectorFocusCmd->GetNewIntValue(newValue));}
}