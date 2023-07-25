#include "Randomize.hh"
#include "MOLLEROptRunAction3.hh"

MOLLEROptRunAction3::MOLLEROptRunAction3(MOLLEROptAnalysis3* AN, MOLLEROptTrackingReadout3 *TrRO3)
  :runID(0), analysis3(AN), TrackingReadout3(TrRO3)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger3  = new MOLLEROptRunActionMessenger3(this);
}

MOLLEROptRunAction3::~MOLLEROptRunAction3()
{
  delete RunActionMessenger3;
}

void MOLLEROptRunAction3::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis3->SetROOTFileFlag(ROOTFileFlag);
  analysis3->SetROOTFileName(ROOTFileName);

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
  
  analysis3->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout3);

}

void MOLLEROptRunAction3::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis3->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis3->EndOfRun();
  TrackingReadout3->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction3::getRunID()
{
  return runID;
}

