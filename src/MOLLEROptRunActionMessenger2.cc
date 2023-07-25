#include "MOLLEROptRunActionMessenger2.hh"

MOLLEROptRunActionMessenger2::MOLLEROptRunActionMessenger2(MOLLEROptRunAction2* theRunAction2)
  :RunAction2(theRunAction2)
{ 

  Dir = new G4UIdirectory("/RunAction2/");
  Dir -> SetGuidance("My Run Action Control");

  MyRunIDCmd = new G4UIcmdWithAnInteger("/RunAction2/SetID",this);
  MyRunIDCmd->SetGuidance("Set the run ID.");
  MyRunIDCmd->SetParameterName("choice",false);
  MyRunIDCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileFlagCmd = new G4UIcmdWithAnInteger("/RunAction2/SetROOTFileFlag",this);
  ROOTFileFlagCmd->SetGuidance("Set the flag that specifies if ROOT files are written: 1 (yes)  0 (no).");
  ROOTFileFlagCmd->SetParameterName("flag",false);
  ROOTFileFlagCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileName = new G4UIcmdWithAString("/RunAction2/SetOutputName",this);
  ROOTFileName->SetGuidance("Set the output file name.");
  ROOTFileName->SetParameterName("setname",false);
  ROOTFileName->AvailableForStates(G4State_PreInit,G4State_Idle);
}

MOLLEROptRunActionMessenger2::~MOLLEROptRunActionMessenger2()
{
  if (MyRunIDCmd)   delete MyRunIDCmd;
  if(ROOTFileFlagCmd) delete ROOTFileFlagCmd;
  if(ROOTFileName) delete ROOTFileName;
  if (Dir) delete Dir;
}

void MOLLEROptRunActionMessenger2::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == MyRunIDCmd ){
    if(RunAction2)
      RunAction2->SetMyRunID(MyRunIDCmd->GetNewIntValue(newValue)); 
  }
  if(command == ROOTFileFlagCmd){
    if(RunAction2)
      RunAction2->SetROOTFileFlag(ROOTFileFlagCmd->GetNewIntValue(newValue));
  }
  if(command == ROOTFileName){
    if(RunAction2)
      RunAction2->SetROOTFileName(newValue);
      //RunAction->SetROOTFileName(ROOTFileName->GetCurrentValue());
  }
}
