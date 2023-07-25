#include "MOLLEROptRunActionMessenger3.hh"

MOLLEROptRunActionMessenger3::MOLLEROptRunActionMessenger3(MOLLEROptRunAction3* theRunAction3)
  :RunAction3(theRunAction3)
{ 

  Dir = new G4UIdirectory("/RunAction3/");
  Dir -> SetGuidance("My Run Action Control");

  MyRunIDCmd = new G4UIcmdWithAnInteger("/RunAction3/SetID",this);
  MyRunIDCmd->SetGuidance("Set the run ID.");
  MyRunIDCmd->SetParameterName("choice",false);
  MyRunIDCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileFlagCmd = new G4UIcmdWithAnInteger("/RunAction3/SetROOTFileFlag",this);
  ROOTFileFlagCmd->SetGuidance("Set the flag that specifies if ROOT files are written: 1 (yes)  0 (no).");
  ROOTFileFlagCmd->SetParameterName("flag",false);
  ROOTFileFlagCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  ROOTFileName = new G4UIcmdWithAString("/RunAction3/SetOutputName",this);
  ROOTFileName->SetGuidance("Set the output file name.");
  ROOTFileName->SetParameterName("setname",false);
  ROOTFileName->AvailableForStates(G4State_PreInit,G4State_Idle);
}

MOLLEROptRunActionMessenger3::~MOLLEROptRunActionMessenger3()
{
  if (MyRunIDCmd)   delete MyRunIDCmd;
  if(ROOTFileFlagCmd) delete ROOTFileFlagCmd;
  if(ROOTFileName) delete ROOTFileName;
  if (Dir) delete Dir;
}

void MOLLEROptRunActionMessenger3::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == MyRunIDCmd ){
    if(RunAction3)
      RunAction3->SetMyRunID(MyRunIDCmd->GetNewIntValue(newValue)); 
  }
  if(command == ROOTFileFlagCmd){
    if(RunAction3)
      RunAction3->SetROOTFileFlag(ROOTFileFlagCmd->GetNewIntValue(newValue));
  }
  if(command == ROOTFileName){
    if(RunAction3)
      RunAction3->SetROOTFileName(newValue);
      //RunAction->SetROOTFileName(ROOTFileName->GetCurrentValue());
  }
}
