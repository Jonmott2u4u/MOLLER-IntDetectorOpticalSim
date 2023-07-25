#include "Randomize.hh"
#include "MOLLEROptRunAction6.hh"

MOLLEROptRunAction6::MOLLEROptRunAction6(MOLLEROptAnalysis6* AN, MOLLEROptTrackingReadout6 *TrRO6)
  :runID(0), analysis6(AN), TrackingReadout6(TrRO6)
{
  MyRunID = 0;
  ROOTFileFlag = 1;
  ROOTFileName = "MOLLEROpt";
  RunActionMessenger6  = new MOLLEROptRunActionMessenger6(this);
}

MOLLEROptRunAction6::~MOLLEROptRunAction6()
{
  delete RunActionMessenger6;
}

void MOLLEROptRunAction6::BeginOfRunAction(const G4Run* aRun)
{
  // userInfo->SetMyRunID(MyRunID);
  // userInfo->SetROOTFileFlag(ROOTFileFlag);
  analysis6->SetROOTFileFlag(ROOTFileFlag);
  analysis6->SetROOTFileName(ROOTFileName);

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
  
  analysis6->BeginOfRun(MyRunID, ROOTFileName,TrackingReadout6);

}

void MOLLEROptRunAction6::EndOfRunAction(const G4Run* aRun)
{ 

  // analysis6->SetTotalNumberOfPrimaries((Int_t)userInfo->GetPrimaryEventNumber());
  
  analysis6->EndOfRun();
  TrackingReadout6->Initialize();

  CLHEP::HepRandom::showEngineStatus();
  
  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }
}

G4int MOLLEROptRunAction6::getRunID()
{
  return runID;
}

