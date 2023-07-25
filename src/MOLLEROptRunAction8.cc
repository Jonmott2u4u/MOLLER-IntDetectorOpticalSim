#include "Randomize.hh"
#include "MOLLEROptRunAction8.hh"

MOLLEROptRunAction8::MOLLEROptRunAction8(MOLLEROptAnalysis8* AN, MOLLEROptTrackingReadout8 *TrRO8)
  :runID(0), analysis8(AN), TrackingReadout8(TrRO8)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger8  = new MOLLEROptRunActionMessenger8(this);
}

MOLLEROptRunAction8::~MOLLEROptRunAction8()
{
  delete RunActionMessenger8;
}

void MOLLEROptRunAction8::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis8->SetROOTFileFlag(ROOTFileFlag);
  analysis8->SetROOTFileName(ROOTFileName);

  long seeds[2];
  time_t systime = time(NULL);
  seeds[0] = (long) systime;
  seeds[1] = (long) (systime*G4UniformRand());
  CLHEP::HepRandom::setTheSeeds(seeds);
  CLHEP::HepRandom::showEngineStatus();

  TString InfoFile;
  InfoFile.Form("%s_%04d.rndm",ROOTFileName.c_str(),MyRunID);
  CLHEP::HepRandom::saveEngineStatus(InfoFile); 
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager* UI = G4UImanager::GetUIpointer();
      UI->ApplyCommand("/vis/scene/notifyHandlers");
    } 
  
  analysis8->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout8);

}

void MOLLEROptRunAction8::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis8->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis8->EndOfRun();
  TrackingReadout8->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction8::getRunID()
{
  return runID;
}

