#include "MOLLEROptRunActionMessenger5.hh"

MOLLEROptRunActionMessenger5::MOLLEROptRunActionMessenger5(MOLLEROptRunAction5* theRunAction5)
  :RunAction5(theRunAction5)
{ 

  Dir = new G4UIdirectory("/RunAction5/");
  Dir -> SetGuidance("My Run Action Control");

  MyRunIDCmd = new G4UIcmdWithAnInteger("/RunAction5/SetID",this);
  MyRunIDCmd->SetGuidance("Set the run ID.");
  MyRunIDCmd->SetParameterName("choice",false);
  MyRunIDCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileFlagCmd = new G4UIcmdWithAnInteger("/RunAction5/SetROOTFileFlag",this);
  ROOTFileFlagCmd->SetGuidance("Set the flag that specifies if ROOT files are written: 1 (yes)  0 (no).");
  ROOTFileFlagCmd->SetParameterName("flag",false);
  ROOTFileFlagCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileName = new G4UIcmdWithAString("/RunAction5/SetOutputName",this);
  ROOTFileName->SetGuidance("Set the output file name.");
  ROOTFileName->SetParameterName("setname",false);
  ROOTFileName->AvailableForStates(G4State_PreInit,G4State_Idle);
}

MOLLEROptRunActionMessenger5::~MOLLEROptRunActionMessenger5()
{
  if (MyRunIDCmd)   delete MyRunIDCmd;
  if(ROOTFileFlagCmd) delete ROOTFileFlagCmd;
  if(ROOTFileName) delete ROOTFileName;
  if (Dir) delete Dir;
}

void MOLLEROptRunActionMessenger5::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == MyRunIDCmd ){
    if(RunAction5)
      RunAction5->SetMyRunID(MyRunIDCmd->GetNewIntValue(newValue)); 
  }
  if(command == ROOTFileFlagCmd){
    if(RunAction5)
      RunAction5->SetROOTFileFlag(ROOTFileFlagCmd->GetNewIntValue(newValue));
  }
  if(command == ROOTFileName){
    if(RunAction5)
      RunAction5->SetROOTFileName(newValue);
      //RunAction->SetROOTFileName(ROOTFileName->GetCurrentValue());
  }
}
