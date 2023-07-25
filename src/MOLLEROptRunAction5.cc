#include "Randomize.hh"
#include "MOLLEROptRunAction5.hh"

MOLLEROptRunAction5::MOLLEROptRunAction5(MOLLEROptAnalysis5* AN, MOLLEROptTrackingReadout5 *TrRO5)
  :runID(0), analysis5(AN), TrackingReadout5(TrRO5)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger5  = new MOLLEROptRunActionMessenger5(this);
}

MOLLEROptRunAction5::~MOLLEROptRunAction5()
{
  delete RunActionMessenger5;
}

void MOLLEROptRunAction5::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis5->SetROOTFileFlag(ROOTFileFlag);
  analysis5->SetROOTFileName(ROOTFileName);

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
  
  analysis5->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout5);

}

void MOLLEROptRunAction5::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis5->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis5->EndOfRun();
  TrackingReadout5->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction5::getRunID()
{
  return runID;
}

