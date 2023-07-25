#include "Randomize.hh"
#include "MOLLEROptRunAction2.hh"

MOLLEROptRunAction2::MOLLEROptRunAction2(MOLLEROptAnalysis2* AN, MOLLEROptTrackingReadout2 *TrRO2)
  :runID(0), analysis2(AN), TrackingReadout2(TrRO2)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger2  = new MOLLEROptRunActionMessenger2(this);
}

MOLLEROptRunAction2::~MOLLEROptRunAction2()
{
  delete RunActionMessenger2;
}

void MOLLEROptRunAction2::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis2->SetROOTFileFlag(ROOTFileFlag);
  analysis2->SetROOTFileName(ROOTFileName);

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
  
  analysis2->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout2);

}

void MOLLEROptRunAction2::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis2->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis2->EndOfRun();
  TrackingReadout2->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction2::getRunID()
{
  return runID;
}

