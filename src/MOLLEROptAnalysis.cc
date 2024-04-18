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

    PMTOptPhotonDistrHist = new TProfile("PMTOptPhotonDistrHist","",800,100,3000);
    QuartzOptPhotonDistrHist = new TProfile("QuartzOptPhotonDistrHist","",800,100,3000);
    LightGuideOptPhotonDistrHist = new TProfile("LightGuideOptPhotonDistrHist","",800,100,3000);

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
    R1Adjacent_CathodeEventsDistrHist = new TH1D("R1Adjacent_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_CathodeEventsDistrHist = new TH1D("R2Adjacent_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_CathodeEventsDistrHist = new TH1D("R3Adjacent_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_CathodeEventsDistrHist = new TH1D("R4Adjacent_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_CathodeEventsDistrHist = new TH1D("R5Adjacent_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_CathodeEventsDistrHist = new TH1D("R6Adjacent_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_CathodeEventsDistrHist = new TH1D("R7Adjacent_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_CathodeEventsDistrHist = new TH1D("R8Adjacent_CathodeEventsDistrHist","",100,0,100);

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

    //Quartz hit position plots (scint cut)
    R1_R1QuartzHitPos = new TH2F("R1_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R1_R2QuartzHitPos = new TH2F("R1_R2QuartzHitPos","",601,-300,300,601,-300,300);   
    R1_R3QuartzHitPos = new TH2F("R1_R3QuartzHitPos","",601,-300,300,601,-300,300);   
    R1_R4QuartzHitPos = new TH2F("R1_R4QuartzHitPos","",601,-300,300,601,-300,300); 
    R1_R5QuartzHitPos = new TH2F("R1_R5QuartzHitPos","",601,-300,300,601,-300,300);    
    R1_R8QuartzHitPos = new TH2F("R1_R8QuartzHitPos","",601,-300,300,601,-300,300); 
    R2_R1QuartzHitPos = new TH2F("R2_R1QuartzHitPos","",601,-300,300,601,-300,300);   
    R2_R2QuartzHitPos = new TH2F("R2_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R2_R3QuartzHitPos = new TH2F("R2_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R2_R4QuartzHitPos = new TH2F("R2_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R2_R5QuartzHitPos = new TH2F("R2_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R2_R8QuartzHitPos = new TH2F("R2_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R1QuartzHitPos = new TH2F("R3_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R2QuartzHitPos = new TH2F("R3_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R3QuartzHitPos = new TH2F("R3_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R4QuartzHitPos = new TH2F("R3_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R5QuartzHitPos = new TH2F("R3_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R3_R8QuartzHitPos = new TH2F("R3_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R1QuartzHitPos = new TH2F("R4_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R2QuartzHitPos = new TH2F("R4_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R3QuartzHitPos = new TH2F("R4_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R4QuartzHitPos = new TH2F("R4_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R5QuartzHitPos = new TH2F("R4_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R4_R8QuartzHitPos = new TH2F("R4_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R1QuartzHitPos = new TH2F("R5_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R2QuartzHitPos = new TH2F("R5_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R3QuartzHitPos = new TH2F("R5_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R4QuartzHitPos = new TH2F("R5_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R5QuartzHitPos = new TH2F("R5_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R5_R8QuartzHitPos = new TH2F("R5_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R1QuartzHitPos = new TH2F("R8_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R2QuartzHitPos = new TH2F("R8_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R3QuartzHitPos = new TH2F("R8_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R4QuartzHitPos = new TH2F("R8_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R5QuartzHitPos = new TH2F("R8_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R8_R8QuartzHitPos = new TH2F("R8_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R1_R1QuartzHitPos->SetOption("COLZ");
    R1_R2QuartzHitPos->SetOption("COLZ");
    R1_R3QuartzHitPos->SetOption("COLZ");
    R1_R4QuartzHitPos->SetOption("COLZ");
    R1_R5QuartzHitPos->SetOption("COLZ");
    R1_R8QuartzHitPos->SetOption("COLZ");
    R2_R1QuartzHitPos->SetOption("COLZ");
    R2_R2QuartzHitPos->SetOption("COLZ");
    R2_R3QuartzHitPos->SetOption("COLZ");
    R2_R4QuartzHitPos->SetOption("COLZ");
    R2_R5QuartzHitPos->SetOption("COLZ");
    R2_R8QuartzHitPos->SetOption("COLZ");
    R3_R1QuartzHitPos->SetOption("COLZ");
    R3_R2QuartzHitPos->SetOption("COLZ");
    R3_R3QuartzHitPos->SetOption("COLZ");
    R3_R4QuartzHitPos->SetOption("COLZ");
    R3_R5QuartzHitPos->SetOption("COLZ");
    R3_R8QuartzHitPos->SetOption("COLZ");
    R4_R1QuartzHitPos->SetOption("COLZ");
    R4_R2QuartzHitPos->SetOption("COLZ");
    R4_R3QuartzHitPos->SetOption("COLZ");
    R4_R4QuartzHitPos->SetOption("COLZ");
    R4_R5QuartzHitPos->SetOption("COLZ");
    R4_R8QuartzHitPos->SetOption("COLZ");
    R5_R1QuartzHitPos->SetOption("COLZ");
    R5_R2QuartzHitPos->SetOption("COLZ");
    R5_R3QuartzHitPos->SetOption("COLZ");
    R5_R4QuartzHitPos->SetOption("COLZ");
    R5_R5QuartzHitPos->SetOption("COLZ");
    R5_R8QuartzHitPos->SetOption("COLZ");
    R8_R1QuartzHitPos->SetOption("COLZ");
    R8_R2QuartzHitPos->SetOption("COLZ");
    R8_R3QuartzHitPos->SetOption("COLZ");
    R8_R4QuartzHitPos->SetOption("COLZ");
    R8_R5QuartzHitPos->SetOption("COLZ");
    R8_R8QuartzHitPos->SetOption("COLZ");
    //Ring cut
    R1Only_R1QuartzHitPos = new TH2F("R1Only_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R2Only_R2QuartzHitPos = new TH2F("R2Only_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R3Only_R3QuartzHitPos = new TH2F("R3Only_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R4Only_R4QuartzHitPos = new TH2F("R4Only_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R5Only_R5QuartzHitPos = new TH2F("R5Only_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R8Only_R8QuartzHitPos = new TH2F("R8Only_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R1Only_R1QuartzHitPos->SetOption("COLZ");
    R2Only_R2QuartzHitPos->SetOption("COLZ");
    R3Only_R3QuartzHitPos->SetOption("COLZ");
    R4Only_R4QuartzHitPos->SetOption("COLZ");
    R5Only_R5QuartzHitPos->SetOption("COLZ");
    R8Only_R8QuartzHitPos->SetOption("COLZ");
    //Adjacency cut
    R1Adjacent_R1QuartzHitPos = new TH2F("R1Adjacent_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R1Adjacent_R3QuartzHitPos = new TH2F("R1Adjacent_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R1Adjacent_R4QuartzHitPos = new TH2F("R1Adjacent_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R1Adjacent_R5QuartzHitPos = new TH2F("R1Adjacent_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R1Adjacent_R8QuartzHitPos = new TH2F("R1Adjacent_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R2Adjacent_R2QuartzHitPos = new TH2F("R2Adjacent_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R2Adjacent_R4QuartzHitPos = new TH2F("R2Adjacent_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R2Adjacent_R5QuartzHitPos = new TH2F("R2Adjacent_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R2Adjacent_R8QuartzHitPos = new TH2F("R2Adjacent_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R3Adjacent_R1QuartzHitPos = new TH2F("R3Adjacent_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R3Adjacent_R3QuartzHitPos = new TH2F("R3Adjacent_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R3Adjacent_R5QuartzHitPos = new TH2F("R3Adjacent_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R3Adjacent_R8QuartzHitPos = new TH2F("R3Adjacent_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R4Adjacent_R1QuartzHitPos = new TH2F("R4Adjacent_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R4Adjacent_R2QuartzHitPos = new TH2F("R4Adjacent_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R4Adjacent_R4QuartzHitPos = new TH2F("R4Adjacent_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R4Adjacent_R8QuartzHitPos = new TH2F("R4Adjacent_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R5Adjacent_R1QuartzHitPos = new TH2F("R5Adjacent_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R5Adjacent_R2QuartzHitPos = new TH2F("R5Adjacent_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R5Adjacent_R3QuartzHitPos = new TH2F("R5Adjacent_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R5Adjacent_R5QuartzHitPos = new TH2F("R5Adjacent_R5QuartzHitPos","",601,-300,300,601,-300,300);
    R8Adjacent_R1QuartzHitPos = new TH2F("R8Adjacent_R1QuartzHitPos","",601,-300,300,601,-300,300);
    R8Adjacent_R2QuartzHitPos = new TH2F("R8Adjacent_R2QuartzHitPos","",601,-300,300,601,-300,300);
    R8Adjacent_R3QuartzHitPos = new TH2F("R8Adjacent_R3QuartzHitPos","",601,-300,300,601,-300,300);
    R8Adjacent_R4QuartzHitPos = new TH2F("R8Adjacent_R4QuartzHitPos","",601,-300,300,601,-300,300);
    R8Adjacent_R8QuartzHitPos = new TH2F("R8Adjacent_R8QuartzHitPos","",601,-300,300,601,-300,300);
    R1Adjacent_R1QuartzHitPos->SetOption("COLZ");
    R1Adjacent_R3QuartzHitPos->SetOption("COLZ");
    R1Adjacent_R4QuartzHitPos->SetOption("COLZ");
    R1Adjacent_R5QuartzHitPos->SetOption("COLZ");
    R1Adjacent_R8QuartzHitPos->SetOption("COLZ");
    R2Adjacent_R2QuartzHitPos->SetOption("COLZ");
    R2Adjacent_R4QuartzHitPos->SetOption("COLZ");
    R2Adjacent_R5QuartzHitPos->SetOption("COLZ");
    R2Adjacent_R8QuartzHitPos->SetOption("COLZ");
    R3Adjacent_R1QuartzHitPos->SetOption("COLZ");
    R3Adjacent_R3QuartzHitPos->SetOption("COLZ");
    R3Adjacent_R5QuartzHitPos->SetOption("COLZ");
    R3Adjacent_R8QuartzHitPos->SetOption("COLZ");
    R4Adjacent_R1QuartzHitPos->SetOption("COLZ");
    R4Adjacent_R2QuartzHitPos->SetOption("COLZ");
    R4Adjacent_R4QuartzHitPos->SetOption("COLZ");
    R4Adjacent_R8QuartzHitPos->SetOption("COLZ");
    R5Adjacent_R1QuartzHitPos->SetOption("COLZ");
    R5Adjacent_R2QuartzHitPos->SetOption("COLZ");
    R5Adjacent_R3QuartzHitPos->SetOption("COLZ");
    R5Adjacent_R5QuartzHitPos->SetOption("COLZ");
    R8Adjacent_R1QuartzHitPos->SetOption("COLZ");
    R8Adjacent_R2QuartzHitPos->SetOption("COLZ");
    R8Adjacent_R3QuartzHitPos->SetOption("COLZ");
    R8Adjacent_R4QuartzHitPos->SetOption("COLZ");
    R8Adjacent_R8QuartzHitPos->SetOption("COLZ");
    
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
    R1Adjacent_CathodeEventsDistrHist->Write();
    R2Adjacent_CathodeEventsDistrHist->Write();
    R3Adjacent_CathodeEventsDistrHist->Write();
    R4Adjacent_CathodeEventsDistrHist->Write();
    R5Adjacent_CathodeEventsDistrHist->Write();
    R6Adjacent_CathodeEventsDistrHist->Write();
    R7Adjacent_CathodeEventsDistrHist->Write();
    R8Adjacent_CathodeEventsDistrHist->Write();

    /*R1_InitialBeamAngleHist->Write();
    R2_InitialBeamAngleHist->Write();
    R3_InitialBeamAngleHist->Write();
    R4_InitialBeamAngleHist->Write();
    R5_InitialBeamAngleHist->Write();
    R6_InitialBeamAngleHist->Write();
    R7_InitialBeamAngleHist->Write();
    R8_InitialBeamAngleHist->Write();*/
    /*R1Only_InitialBeamAngleHist->Write();
    R2Only_InitialBeamAngleHist->Write();
    R3Only_InitialBeamAngleHist->Write();
    R4Only_InitialBeamAngleHist->Write();
    R5Only_InitialBeamAngleHist->Write();
    R6Only_InitialBeamAngleHist->Write();
    R7Only_InitialBeamAngleHist->Write();
    R8Only_InitialBeamAngleHist->Write();*/

    R1_R1QuartzHitPos->Write();
    R1_R2QuartzHitPos->Write();
    R1_R3QuartzHitPos->Write();
    R1_R4QuartzHitPos->Write();
    R1_R5QuartzHitPos->Write();
    R1_R8QuartzHitPos->Write();
    R2_R1QuartzHitPos->Write();
    R2_R2QuartzHitPos->Write();
    R2_R3QuartzHitPos->Write();
    R2_R4QuartzHitPos->Write();
    R2_R5QuartzHitPos->Write();
    R2_R8QuartzHitPos->Write();
    R3_R1QuartzHitPos->Write();
    R3_R2QuartzHitPos->Write();
    R3_R3QuartzHitPos->Write();
    R3_R4QuartzHitPos->Write();
    R3_R5QuartzHitPos->Write();
    R3_R8QuartzHitPos->Write();
    R4_R1QuartzHitPos->Write();
    R4_R2QuartzHitPos->Write();
    R4_R3QuartzHitPos->Write();
    R4_R4QuartzHitPos->Write();
    R4_R5QuartzHitPos->Write();
    R4_R8QuartzHitPos->Write();
    R5_R1QuartzHitPos->Write();
    R5_R2QuartzHitPos->Write();
    R5_R3QuartzHitPos->Write();
    R5_R4QuartzHitPos->Write();
    R5_R5QuartzHitPos->Write();
    R5_R8QuartzHitPos->Write();
    R8_R1QuartzHitPos->Write();
    R8_R2QuartzHitPos->Write();
    R8_R3QuartzHitPos->Write();
    R8_R4QuartzHitPos->Write();
    R8_R5QuartzHitPos->Write();
    R8_R8QuartzHitPos->Write();
    R1Only_R1QuartzHitPos->Write();
    R2Only_R2QuartzHitPos->Write();
    R3Only_R3QuartzHitPos->Write();
    R4Only_R4QuartzHitPos->Write();
    R5Only_R5QuartzHitPos->Write();
    R8Only_R8QuartzHitPos->Write();
    R1Adjacent_R1QuartzHitPos->Write();
    R1Adjacent_R3QuartzHitPos->Write();
    R1Adjacent_R4QuartzHitPos->Write();
    R1Adjacent_R5QuartzHitPos->Write();
    R1Adjacent_R8QuartzHitPos->Write();
    R2Adjacent_R2QuartzHitPos->Write();
    R2Adjacent_R4QuartzHitPos->Write();
    R2Adjacent_R5QuartzHitPos->Write();
    R2Adjacent_R8QuartzHitPos->Write();
    R3Adjacent_R1QuartzHitPos->Write();
    R3Adjacent_R3QuartzHitPos->Write();
    R3Adjacent_R5QuartzHitPos->Write();
    R3Adjacent_R8QuartzHitPos->Write();
    R4Adjacent_R1QuartzHitPos->Write();
    R4Adjacent_R2QuartzHitPos->Write();
    R4Adjacent_R4QuartzHitPos->Write();
    R4Adjacent_R8QuartzHitPos->Write();
    R5Adjacent_R1QuartzHitPos->Write();
    R5Adjacent_R2QuartzHitPos->Write();
    R5Adjacent_R3QuartzHitPos->Write();
    R5Adjacent_R5QuartzHitPos->Write();
    R8Adjacent_R1QuartzHitPos->Write();
    R8Adjacent_R2QuartzHitPos->Write();
    R8Adjacent_R3QuartzHitPos->Write();
    R8Adjacent_R4QuartzHitPos->Write();
    R8Adjacent_R8QuartzHitPos->Write();


    //NoHit_InitialBeamAngleHist->Write();


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
    MOLLEROptMainBranch  = MOLLEROptNtuple->Branch("MOLLEROptData", "MOLLEROptMainEvent", &MOLLERMainEvent, 630000, 10);
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
