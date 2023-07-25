#include "Randomize.hh"
#include "MOLLEROptRunAction4.hh"

MOLLEROptRunAction4::MOLLEROptRunAction4(MOLLEROptAnalysis4* AN, MOLLEROptTrackingReadout4 *TrRO4)
  :runID(0), analysis4(AN), TrackingReadout4(TrRO4)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger4  = new MOLLEROptRunActionMessenger4(this);
}

MOLLEROptRunAction4::~MOLLEROptRunAction4()
{
  delete RunActionMessenger4;
}

void MOLLEROptRunAction4::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis4->SetROOTFileFlag(ROOTFileFlag);
  analysis4->SetROOTFileName(ROOTFileName);

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
  
  analysis4->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout4);

}

void MOLLEROptRunAction4::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis4->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis4->EndOfRun();
  TrackingReadout4->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction4::getRunID()
{
  return runID;
}

