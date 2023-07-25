#include "MOLLEROptRunActionMessenger7.hh"

MOLLEROptRunActionMessenger7::MOLLEROptRunActionMessenger7(MOLLEROptRunAction7* theRunAction7)
  :RunAction7(theRunAction7)
{ 

  Dir = new G4UIdirectory("/RunAction7/");
  Dir -> SetGuidance("My Run Action Control");

  MyRunIDCmd = new G4UIcmdWithAnInteger("/RunAction7/SetID",this);
  MyRunIDCmd->SetGuidance("Set the run ID.");
  MyRunIDCmd->SetParameterName("choice",false);
  MyRunIDCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileFlagCmd = new G4UIcmdWithAnInteger("/RunAction7/SetROOTFileFlag",this);
  ROOTFileFlagCmd->SetGuidance("Set the flag that specifies if ROOT files are written: 1 (yes)  0 (no).");
  ROOTFileFlagCmd->SetParameterName("flag",false);
  ROOTFileFlagCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileName = new G4UIcmdWithAString("/RunAction7/SetOutputName",this);
  ROOTFileName->SetGuidance("Set the output file name.");
  ROOTFileName->SetParameterName("setname",false);
  ROOTFileName->AvailableForStates(G4State_PreInit,G4State_Idle);
}

MOLLEROptRunActionMessenger7::~MOLLEROptRunActionMessenger7()
{
  if (MyRunIDCmd)   delete MyRunIDCmd;
  if(ROOTFileFlagCmd) delete ROOTFileFlagCmd;
  if(ROOTFileName) delete ROOTFileName;
  if (Dir) delete Dir;
}

void MOLLEROptRunActionMessenger7::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == MyRunIDCmd ){
    if(RunAction7)
      RunAction7->SetMyRunID(MyRunIDCmd->GetNewIntValue(newValue)); 
  }
  if(command == ROOTFileFlagCmd){
    if(RunAction7)
      RunAction7->SetROOTFileFlag(ROOTFileFlagCmd->GetNewIntValue(newValue));
  }
  if(command == ROOTFileName){
    if(RunAction7)
      RunAction7->SetROOTFileName(newValue);
      //RunAction->SetROOTFileName(ROOTFileName->GetCurrentValue());
  }
}
