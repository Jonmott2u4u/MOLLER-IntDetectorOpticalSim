#include "Randomize.hh"
#include "MOLLEROptRunAction7.hh"

MOLLEROptRunAction7::MOLLEROptRunAction7(MOLLEROptAnalysis7* AN, MOLLEROptTrackingReadout7 *TrRO7)
  :runID(0), analysis7(AN), TrackingReadout7(TrRO7)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger7  = new MOLLEROptRunActionMessenger7(this);
}

MOLLEROptRunAction7::~MOLLEROptRunAction7()
{
  delete RunActionMessenger7;
}

void MOLLEROptRunAction7::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis7->SetROOTFileFlag(ROOTFileFlag);
  analysis7->SetROOTFileName(ROOTFileName);

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
  
  analysis7->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout7);

}

void MOLLEROptRunAction7::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis7->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis7->EndOfRun();
  TrackingReadout7->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction7::getRunID()
{
  return runID;
}

