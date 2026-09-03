#include "MOLLEROptAnalysis.hh"

MOLLEROptAnalysis::MOLLEROptAnalysis()
{	
    // Initialize 

    //MOLLERMainEvent    = NULL;
    MOLLERGeneralEvent = NULL;
    MOLLEROptMainBranch   = NULL;

    MOLLEROptNtuple         = NULL;
    MOLLEROptFile           = NULL;
    NumberOfPrimaries     = new TVectorD(1);
    NumberOfPrimaries[0]  = 0;
    ROOTFileFlag = 1;
    ROOTFileName = "MOLLEROpt";

    PMTOptPhotonDistrHist = new TProfile("PMTOptPhotonDistrHist","",800,100,900);
    QuartzOptPhotonDistrHist = new TProfile("QuartzOptPhotonDistrHist","",800,100,900);
    LightGuideOptPhotonDistrHist = new TProfile("LightGuideOptPhotonDistrHist","",800,100,900);

    //--------BF segment histograms--------//
    Ring_CathodeEventsDistrHist = new TH1D("Ring_CathodeEventsDistrHist","",100,0,100);

    EventCnt = 0;
}

MOLLEROptAnalysis::~MOLLEROptAnalysis() 
{
  Finish();
  delete[] NumberOfPrimaries;
}

void MOLLEROptAnalysis::Init()
{;}


void MOLLEROptAnalysis::Finish()
{
  //if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLERGeneralEvent)      delete MOLLERGeneralEvent;
  if (MOLLEROptMainBranch)     delete MOLLEROptMainBranch;
  if (MOLLEROptNtuple)         {MOLLEROptNtuple->Delete();}
  if (MOLLEROptFile)           delete MOLLEROptFile;
}   

void MOLLEROptAnalysis::BeginOfRun(G4int runID, G4String name1, MOLLEROptTrackingReadout *TrRO) 
{   

  if(ROOTFileFlag){

    MOLLEROptFile = new TFile(Form("rootfiles/%s_%04d.root",name1.c_str(),runID),"RECREATE","MOLLEROpt ROOT file");
  }
  TrackingReadout = TrRO;
    
  ConstructRootNtuple();
}

void MOLLEROptAnalysis::EndOfRun() 
{
  if(ROOTFileFlag){
    NumberOfPrimaries->Write("NumberOfPrimaries");
    //FillOptPhotonDistrHist();
    PMTOptPhotonDistrHist->Write();
    QuartzOptPhotonDistrHist->Write();
    LightGuideOptPhotonDistrHist->Write();

    //--------BF segment histograms--------//
    Ring_CathodeEventsDistrHist->Write();
    TrackingReadout->WriteAbsProfiles();
    //MOLLEROptNtuple->OptimizeBaskets(); //Removes empty baskets from the tree, lowering file size
    MOLLEROptFile->Write("",TObject::kOverwrite); // Writing the data to the ROOT file

    //MOLLEROptNtuple->OptimizeBaskets(); //Removes empty baskets from the tree, lowering file size
    
    MOLLEROptNtuple->Reset(); //This needs to be here, so that the file size doesn't keep growing for new files.
                            //Apparently things are kept in the background, from the previous tree, and then 
                            //written to the new tree, without it being visible or accessible in the new file.
                            //This is only happening or a concern if multiple ROOT files are written in the same
                            //execution of the simulation, but it is a collossally stupid attribute of ROOT.

    MOLLEROptFile->Close();
  }

  //if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLERGeneralEvent)         delete MOLLERGeneralEvent;
  if (MOLLEROptFile)           delete MOLLEROptFile;
  
}

void MOLLEROptAnalysis::EndOfEvent(G4int flag) 
{
  if(!flag) return;
}

void MOLLEROptAnalysis::ConstructRootNtuple() 
{
  //MOLLERMainEvent   = new MOLLEROptMainEvent();
  MOLLERGeneralEvent = new MOLLEROptGeneralEvent();

  if(ROOTFileFlag) {
    TClass::GetClass("MOLLEROptGeneralEvent")->IgnoreTObjectStreamer();//This wipes the TObject branch from MOLLERGeneralEvent
    MOLLEROptNtuple = new TTree("MOLLEROptTree","MOLLEROptTree");
    MOLLEROptMainBranch  = MOLLEROptNtuple->Branch("MOLLEROptData", "MOLLEROptGeneralEvent", &MOLLERGeneralEvent, 64000, 10);
  }
}

void MOLLEROptAnalysis::AutoSaveRootNtuple() 
{
    // save the current ntuple:
    // In case your program crashes before closing the file holding this tree,
    // the file will be automatically recovered when you will connect the file
    // in UPDATE mode.
    // The Tree will be recovered at the status corresponding to the last AutoSave.
    //
    // if option contains "SaveSelf", gDirectory->SaveSelf() is called.
    // This allows another process to analyze the Tree while the Tree is being filled.
    //
    // see http://root.cern.ch/root/html/TTree.html#TTree:AutoSave

    //MOLLEROptG4_RootNtuple -> AutoSave("SaveSelf");
  if(ROOTFileFlag) MOLLEROptNtuple->AutoSave();

}
