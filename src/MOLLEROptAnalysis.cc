#include "MOLLEROptAnalysis.hh"

MOLLEROptAnalysis::MOLLEROptAnalysis()
{	
    // Initialize 

    MOLLERMainEvent    = NULL;
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

    R1_CathodeEventsDistrHist = new TH1D("R1_CathodeEventsDistrHist","",100,0,100);
    R2_CathodeEventsDistrHist = new TH1D("R2_CathodeEventsDistrHist","",100,0,100);
    R3_CathodeEventsDistrHist = new TH1D("R3_CathodeEventsDistrHist","",100,0,100);
    R4_CathodeEventsDistrHist = new TH1D("R4_CathodeEventsDistrHist","",100,0,100);
    R5_CathodeEventsDistrHist = new TH1D("R5_CathodeEventsDistrHist","",100,0,100);
    R6_CathodeEventsDistrHist = new TH1D("R6_CathodeEventsDistrHist","",100,0,100);
    R7_CathodeEventsDistrHist = new TH1D("R7_CathodeEventsDistrHist","",100,0,100);
    R8_CathodeEventsDistrHist = new TH1D("R8_CathodeEventsDistrHist","",100,0,100);
    R1Only_CathodeEventsDistrHist = new TH1D("R1Only_CathodeEventsDistrHist","",100,0,100);
    R2Only_CathodeEventsDistrHist = new TH1D("R2Only_CathodeEventsDistrHist","",100,0,100);
    R3Only_CathodeEventsDistrHist = new TH1D("R3Only_CathodeEventsDistrHist","",100,0,100);
    R4Only_CathodeEventsDistrHist = new TH1D("R4Only_CathodeEventsDistrHist","",100,0,100);
    R5Only_CathodeEventsDistrHist = new TH1D("R5Only_CathodeEventsDistrHist","",100,0,100);
    R6Only_CathodeEventsDistrHist = new TH1D("R6Only_CathodeEventsDistrHist","",100,0,100);
    R7Only_CathodeEventsDistrHist = new TH1D("R7Only_CathodeEventsDistrHist","",100,0,100);
    R8Only_CathodeEventsDistrHist = new TH1D("R8Only_CathodeEventsDistrHist","",100,0,100);

    //Adding histograms that are GEM specific. Beam must the upstream and one downstream scintillator to be plotted here
    R1_GEM1_CathodeEventsDistrHist = new TH1D("R1_GEM1_CathodeEventsDistrHist","",100,0,100);
    R2_GEM1_CathodeEventsDistrHist = new TH1D("R2_GEM1_CathodeEventsDistrHist","",100,0,100);
    R3_GEM1_CathodeEventsDistrHist = new TH1D("R3_GEM1_CathodeEventsDistrHist","",100,0,100);
    R4_GEM1_CathodeEventsDistrHist = new TH1D("R4_GEM1_CathodeEventsDistrHist","",100,0,100);
    R5_GEM1_CathodeEventsDistrHist = new TH1D("R5_GEM1_CathodeEventsDistrHist","",100,0,100);
    R6_GEM1_CathodeEventsDistrHist = new TH1D("R6_GEM1_CathodeEventsDistrHist","",100,0,100);
    R7_GEM1_CathodeEventsDistrHist = new TH1D("R7_GEM1_CathodeEventsDistrHist","",100,0,100);
    R8_GEM1_CathodeEventsDistrHist = new TH1D("R8_GEM1_CathodeEventsDistrHist","",100,0,100);
    R1Only_GEM1_CathodeEventsDistrHist = new TH1D("R1Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R2Only_GEM1_CathodeEventsDistrHist = new TH1D("R2Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R3Only_GEM1_CathodeEventsDistrHist = new TH1D("R3Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R4Only_GEM1_CathodeEventsDistrHist = new TH1D("R4Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R5Only_GEM1_CathodeEventsDistrHist = new TH1D("R5Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R6Only_GEM1_CathodeEventsDistrHist = new TH1D("R6Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R7Only_GEM1_CathodeEventsDistrHist = new TH1D("R7Only_GEM1_CathodeEventsDistrHist","",100,0,100);
    R8Only_GEM1_CathodeEventsDistrHist = new TH1D("R8Only_GEM1_CathodeEventsDistrHist","",100,0,100);

    R1_GEM2_CathodeEventsDistrHist = new TH1D("R1_GEM2_CathodeEventsDistrHist","",100,0,100);
    R2_GEM2_CathodeEventsDistrHist = new TH1D("R2_GEM2_CathodeEventsDistrHist","",100,0,100);
    R3_GEM2_CathodeEventsDistrHist = new TH1D("R3_GEM2_CathodeEventsDistrHist","",100,0,100);
    R4_GEM2_CathodeEventsDistrHist = new TH1D("R4_GEM2_CathodeEventsDistrHist","",100,0,100);
    R5_GEM2_CathodeEventsDistrHist = new TH1D("R5_GEM2_CathodeEventsDistrHist","",100,0,100);
    R6_GEM2_CathodeEventsDistrHist = new TH1D("R6_GEM2_CathodeEventsDistrHist","",100,0,100);
    R7_GEM2_CathodeEventsDistrHist = new TH1D("R7_GEM2_CathodeEventsDistrHist","",100,0,100);
    R8_GEM2_CathodeEventsDistrHist = new TH1D("R8_GEM2_CathodeEventsDistrHist","",100,0,100);
    R1Only_GEM2_CathodeEventsDistrHist = new TH1D("R1Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R2Only_GEM2_CathodeEventsDistrHist = new TH1D("R2Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R3Only_GEM2_CathodeEventsDistrHist = new TH1D("R3Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R4Only_GEM2_CathodeEventsDistrHist = new TH1D("R4Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R5Only_GEM2_CathodeEventsDistrHist = new TH1D("R5Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R6Only_GEM2_CathodeEventsDistrHist = new TH1D("R6Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R7Only_GEM2_CathodeEventsDistrHist = new TH1D("R7Only_GEM2_CathodeEventsDistrHist","",100,0,100);
    R8Only_GEM2_CathodeEventsDistrHist = new TH1D("R8Only_GEM2_CathodeEventsDistrHist","",100,0,100);

    R1_InitialBeamAngleHist = new TH1F("R1_InitialBeamAngleHist","",100,0,25);
    R2_InitialBeamAngleHist = new TH1F("R2_InitialBeamAngleHist","",100,0,25);
    R3_InitialBeamAngleHist = new TH1F("R3_InitialBeamAngleHist","",100,0,25);
    R4_InitialBeamAngleHist = new TH1F("R4_InitialBeamAngleHist","",100,0,25);
    R5_InitialBeamAngleHist = new TH1F("R5_InitialBeamAngleHist","",100,0,25);
    R6_InitialBeamAngleHist = new TH1F("R6_InitialBeamAngleHist","",100,0,25);
    R7_InitialBeamAngleHist = new TH1F("R7_InitialBeamAngleHist","",100,0,25);
    R8_InitialBeamAngleHist = new TH1F("R8_InitialBeamAngleHist","",100,0,25);
    R1Only_InitialBeamAngleHist = new TH1F("R1Only_InitialBeamAngleHist","",100,0,25);
    R2Only_InitialBeamAngleHist = new TH1F("R2Only_InitialBeamAngleHist","",100,0,25);
    R3Only_InitialBeamAngleHist = new TH1F("R3Only_InitialBeamAngleHist","",100,0,25);
    R4Only_InitialBeamAngleHist = new TH1F("R4Only_InitialBeamAngleHist","",100,0,25);
    R5Only_InitialBeamAngleHist = new TH1F("R5Only_InitialBeamAngleHist","",100,0,25);
    R6Only_InitialBeamAngleHist = new TH1F("R6Only_InitialBeamAngleHist","",100,0,25);
    R7Only_InitialBeamAngleHist = new TH1F("R7Only_InitialBeamAngleHist","",100,0,25);
    R8Only_InitialBeamAngleHist = new TH1F("R8Only_InitialBeamAngleHist","",100,0,25);

    NoHit_InitialBeamAngleHist = new TH1F("NoHit_InitialBeamAngleHist","",100,0,25);

    
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
  if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLEROptMainBranch)     delete MOLLEROptMainBranch;
  if (MOLLEROptNtuple)         {MOLLEROptNtuple->Delete();}
  if (MOLLEROptFile)           delete MOLLEROptFile;
}   

void MOLLEROptAnalysis::BeginOfRun(G4int runID, G4String name1, MOLLEROptTrackingReadout *TrRO) 
{   

  if(ROOTFileFlag){

    MOLLEROptFile = new TFile(Form("%s_%04d.root",name1.c_str(),runID),"RECREATE","MOLLEROpt ROOT file");
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

    R1_CathodeEventsDistrHist->Write();
    R2_CathodeEventsDistrHist->Write();
    R3_CathodeEventsDistrHist->Write();
    R4_CathodeEventsDistrHist->Write();
    R5_CathodeEventsDistrHist->Write();
    R6_CathodeEventsDistrHist->Write();
    R7_CathodeEventsDistrHist->Write();
    R8_CathodeEventsDistrHist->Write();
    R1Only_CathodeEventsDistrHist->Write();
    R2Only_CathodeEventsDistrHist->Write();
    R3Only_CathodeEventsDistrHist->Write();
    R4Only_CathodeEventsDistrHist->Write();
    R5Only_CathodeEventsDistrHist->Write();
    R6Only_CathodeEventsDistrHist->Write();
    R7Only_CathodeEventsDistrHist->Write();
    R8Only_CathodeEventsDistrHist->Write();

    R1_GEM1_CathodeEventsDistrHist->Write();
    R2_GEM1_CathodeEventsDistrHist->Write();
    R3_GEM1_CathodeEventsDistrHist->Write();
    R4_GEM1_CathodeEventsDistrHist->Write();
    R5_GEM1_CathodeEventsDistrHist->Write();
    R6_GEM1_CathodeEventsDistrHist->Write();
    R7_GEM1_CathodeEventsDistrHist->Write();
    R8_GEM1_CathodeEventsDistrHist->Write();
    R1Only_GEM1_CathodeEventsDistrHist->Write();
    R2Only_GEM1_CathodeEventsDistrHist->Write();
    R3Only_GEM1_CathodeEventsDistrHist->Write();
    R4Only_GEM1_CathodeEventsDistrHist->Write();
    R5Only_GEM1_CathodeEventsDistrHist->Write();
    R6Only_GEM1_CathodeEventsDistrHist->Write();
    R7Only_GEM1_CathodeEventsDistrHist->Write();
    R8Only_GEM1_CathodeEventsDistrHist->Write();

    R1_GEM2_CathodeEventsDistrHist->Write();
    R2_GEM2_CathodeEventsDistrHist->Write();
    R3_GEM2_CathodeEventsDistrHist->Write();
    R4_GEM2_CathodeEventsDistrHist->Write();
    R5_GEM2_CathodeEventsDistrHist->Write();
    R6_GEM2_CathodeEventsDistrHist->Write();
    R7_GEM2_CathodeEventsDistrHist->Write();
    R8_GEM2_CathodeEventsDistrHist->Write();
    R1Only_GEM2_CathodeEventsDistrHist->Write();
    R2Only_GEM2_CathodeEventsDistrHist->Write();
    R3Only_GEM2_CathodeEventsDistrHist->Write();
    R4Only_GEM2_CathodeEventsDistrHist->Write();
    R5Only_GEM2_CathodeEventsDistrHist->Write();
    R6Only_GEM2_CathodeEventsDistrHist->Write();
    R7Only_GEM2_CathodeEventsDistrHist->Write();
    R8Only_GEM2_CathodeEventsDistrHist->Write();

    R1_InitialBeamAngleHist->Write();
    R2_InitialBeamAngleHist->Write();
    R3_InitialBeamAngleHist->Write();
    R4_InitialBeamAngleHist->Write();
    R5_InitialBeamAngleHist->Write();
    R6_InitialBeamAngleHist->Write();
    R7_InitialBeamAngleHist->Write();
    R8_InitialBeamAngleHist->Write();
    R1Only_InitialBeamAngleHist->Write();
    R2Only_InitialBeamAngleHist->Write();
    R3Only_InitialBeamAngleHist->Write();
    R4Only_InitialBeamAngleHist->Write();
    R5Only_InitialBeamAngleHist->Write();
    R6Only_InitialBeamAngleHist->Write();
    R7Only_InitialBeamAngleHist->Write();
    R8Only_InitialBeamAngleHist->Write();


    NoHit_InitialBeamAngleHist->Write();


    TrackingReadout->WriteAbsProfiles();
    MOLLEROptFile->Write("",TObject::kOverwrite); // Writing the data to the ROOT file
    
    MOLLEROptNtuple->Reset(); //This needs to be here, so that the file size doesn't keep growing for new files.
                            //Apparently things are kept in the background, from the previous tree, and then 
                            //written to the new tree, without it being visible or accessible in the new file.
                            //This is only happening or a concern if multiple ROOT files are written in the same
                            //execution of the simulation, but it is a collossally stupid attribute of ROOT.

    MOLLEROptFile->Close();
  }

  if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLEROptFile)           delete MOLLEROptFile;
  
}

void MOLLEROptAnalysis::EndOfEvent(G4int flag) 
{
  if(!flag) return;
}

void MOLLEROptAnalysis::ConstructRootNtuple() 
{
  MOLLERMainEvent   = new MOLLEROptMainEvent();

  if(ROOTFileFlag) {
    MOLLEROptNtuple = new TTree("MOLLEROptTree","MOLLEROptTree");
    MOLLEROptMainBranch  = MOLLEROptNtuple->Branch("MOLLEROptData", "MOLLEROptMainEvent", &MOLLERMainEvent, 64000, 10);
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
