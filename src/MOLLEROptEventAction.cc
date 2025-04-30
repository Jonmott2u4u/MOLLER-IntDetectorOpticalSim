#include "MOLLEROptEventAction.hh"
#include <math.h>

MOLLEROptEventAction::MOLLEROptEventAction(MOLLEROptAnalysis* AN, MOLLEROptTrackingReadout* TrRO)
{
  analysis    = AN;
  TrackingReadout  = TrRO;

  EventMessenger = new MOLLEROptEventActionMessenger(this);

  PMTSecOptPhotonCnt = new TH1D("PMTSecOptPhotonCnt","",800,100,900);
  PMTSecOptPhotonCnt->SetBit(TH1::kIsAverage);

  QuartzSecOptPhotonCnt = new TH1D("QuartzSecOptPhotonCnt","",800,100,900);
  QuartzSecOptPhotonCnt->SetBit(TH1::kIsAverage);
  
  LightGuideSecOptPhotonCnt = new TH1D("LightGuideSecOptPhotonCnt","",800,100,900);
  LightGuideSecOptPhotonCnt->SetBit(TH1::kIsAverage);

  TrackingReadout->Initialize();

}


MOLLEROptEventAction::~MOLLEROptEventAction()
{
  
}


void MOLLEROptEventAction::BeginOfEventAction(const G4Event* evt)
{
 
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  
  PMTSecOptPhotonCnt->Reset();
  QuartzSecOptPhotonCnt->Reset();
  LightGuideSecOptPhotonCnt->Reset();

  for(int n = 0; n < ProcessedTrack.size(); n++) delete ProcessedTrack[n];
  ProcessedTrack.clear();
  ProcessedTrack.resize(0);
  TrackingReadout->Initialize();

}

Bool_t MOLLEROptEventAction::TrackHasBeenProcessed(G4int id)
{
  Bool_t check = false;
  for(int n = 0; n < ProcessedTrack.size(); n++)
    if(ProcessedTrack[n]->ID == id) check = true;

  return check;
}

void MOLLEROptEventAction::AddTrackStep(G4int id, G4int step) //For quartz and scintillators
{
  for(int n = 0; n < ProcessedTrack.size(); n++){
    if(ProcessedTrack[n]->ID == id){
      ProcessedTrack[n]->Length += step;
      ProcessedTrack[n]->Steps++;
      return;
    }
  }

  lTrackData *data = new lTrackData;
  data->ID = id;
  data->Length = step;
  data->Steps = 1;
  
  ProcessedTrack.push_back(data);

  return;
}


void MOLLEROptEventAction::EndOfEventAction(const G4Event* evt)
{

  Initialize();
  analysis->MOLLERMainEvent->MOLLERPrimEvent.Initialize(); 
  
  G4int hitflag = 0;
  G4int NumSecPhotons = 0;
  G4float InitialBeamAngle = 99;
  G4double LGTrackLength, QuartzTrackLength, TotalTrackLength;
  G4int hitCnt1, hitCnt2, PMThit, qtrackID, lgtrackID, pmttrackID, ctrackID, LGSteps, QSteps, TSteps, secPhCnt;

  //--------BF segment Variables--------//
  G4double R1_pes = 0, R2_pes = 0, R3_pes = 0, R4_pes = 0, R5_pes = 0, R6_pes = 0, R7_pes = 0, R8_pes = 0;
  G4int R1Hit, R2Hit, R3Hit, R4Hit, R5Hit, R6Hit, R7Hit, R8Hit, Scint1Hit, Scint2Hit, Scint3Hit, Scint4Hit;
  G4int R1_Tracker = 0;  //Stores whether the R1 tile (+ scint) has been hit this event  
  G4int R2_Tracker = 0;  //
  G4int R3_Tracker = 0;  //  
  G4int R4_Tracker = 0;  //  
  G4int R5_Tracker = 0;  //  
  G4int R6_Tracker = 0;  //  
  G4int R7_Tracker = 0;  //  
  G4int R8_Tracker = 0;  //
  G4int R1_SoloTracker = 0;  //Stores whether only the R1 tile (+ scints) have been hit this event
  G4int R2_SoloTracker = 0;  //
  G4int R3_SoloTracker = 0;  //  
  G4int R4_SoloTracker = 0;  //  
  G4int R5_SoloTracker = 0;  //  
  G4int R6_SoloTracker = 0;  //  
  G4int R7_SoloTracker = 0;  //  
  G4int R8_SoloTracker = 0;  //  
  G4int Scint1_Tracker = 0;   //Stores whether the spectrum defining scintillator has been hit
  G4int Scint2_Tracker = 0;
  G4int Scint3_Tracker = 0;
  G4int Scint4_Tracker = 0;
  G4int Scint13_Tracker = 0;
  G4int Scint14_Tracker = 0;
  G4int Scint23_Tracker = 0;
  G4int Scint24_Tracker = 0;
  G4int R1_AdjacentTracker = 0; //Stores hits on R1 that do not hit R2
  G4int R2_AdjacentTracker = 0; //Stores hits on R2 that do not hit R1 or R3
  G4int R3_AdjacentTracker = 0; //Do not hit R2 or R4
  G4int R4_AdjacentTracker = 0; //Do not hit R3 or R5 FF ------}
  G4int R5_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R6_AdjacentTracker = 0; //Do not hit R4 or R6          }--- Subject to change (update as needed to include R5 BF)
  G4int R7_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R8_AdjacentTracker = 0; //Do not hit R5 FF       ------}

  //--------FF segment Variables--------//
  G4double R9_pes = 0, R10_pes = 0, R11_pes = 0, R12_pes = 0, R13_pes = 0, R14_pes = 0, R15_pes = 0, R16_pes = 0;
  G4int R9Hit, R10Hit, R11Hit, R12Hit, R13Hit, R14Hit, R15Hit, R16Hit, Scint5Hit, Scint6Hit, Scint7Hit, Scint8Hit;
  G4int R9_Tracker = 0;  //Stores whether the R1 tile (+ scint) has been hit this event  
  G4int R10_Tracker = 0;  //
  G4int R11_Tracker = 0;  //  
  G4int R12_Tracker = 0;  //  
  G4int R13_Tracker = 0;  //  
  G4int R14_Tracker = 0;  //  
  G4int R15_Tracker = 0;  //  
  G4int R16_Tracker = 0;  //
  G4int R9_SoloTracker = 0;  //Stores whether only the R9 tile (+ scint) has been hit this event
  G4int R10_SoloTracker = 0;  //
  G4int R11_SoloTracker = 0;  //  
  G4int R12_SoloTracker = 0;  //  
  G4int R13_SoloTracker = 0;  //  
  G4int R14_SoloTracker = 0;  //  
  G4int R15_SoloTracker = 0;  //  
  G4int R16_SoloTracker = 0;  //  
  G4int Scint5_Tracker = 0;   //Stores whether the spectrum defining scintillator has been hit
  G4int Scint6_Tracker = 0;
  G4int Scint7_Tracker = 0;
  G4int Scint8_Tracker = 0;
  G4int Scint57_Tracker = 0;
  G4int Scint58_Tracker = 0;
  G4int Scint67_Tracker = 0;
  G4int Scint68_Tracker = 0;
  G4int R9_AdjacentTracker = 0; //Stores hits on R1 that do not hit R2
  G4int R10_AdjacentTracker = 0; //Stores hits on R2 that do not hit R1 or R3
  G4int R11_AdjacentTracker = 0; //Do not hit R2 or R4
  G4int R12_AdjacentTracker = 0; //Do not hit R3 or R5 BF ------}
  G4int R13_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R14_AdjacentTracker = 0; //Do not hit R4 or R6          }--- Subject to change (update as needed to include R5 FF)
  G4int R15_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R16_AdjacentTracker = 0; //Do not hit R5 BF       ------}

  ctrackID = -1;
  TrackData *track;
  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
  G4int NumTracks = TrackingReadout->GetNumTracks();
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  for(int t = 0; t < NumTracks; t++){

    PMThit = 0;
    R1Hit = 0, R2Hit = 0, R3Hit = 0, R4Hit = 0, R5Hit = 0, R6Hit = 0, R7Hit = 0, R8Hit = 0, Scint1Hit = 0, Scint2Hit = 0, Scint3Hit = 0, Scint4Hit = 0;
    R9Hit = 0, R10Hit = 0, R11Hit = 0, R12Hit = 0, R13Hit = 0, R14Hit = 0, R15Hit = 0, R16Hit = 0, Scint5Hit = 0, Scint6Hit = 0, Scint7Hit = 0, Scint8Hit = 0;
    analysis->MOLLERMainEvent->MOLLERGeneralEvent.Initialize();  
    track  = TrackingReadout->GetTrackData(t);
    if(track){

      analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetEventID(evt->GetEventID());
      analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetTrackParentID(track->ParentID);      
      analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,track->InitMomDirZ);      

      
      if(track->Particle == myBeam){
	      analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddElectronTrackID(track->ID);
        //G4cout << track->ID << G4endl; //Original particle has ID = 1
	      analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPhotonTrackID(0);
        if(track->ID == 1){
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddInitialBeamEnergy(track->InitKinEnergy/GeV);
          InitialBeamAngle = asin(sqrt(pow(track->InitMomDirX,2) + pow(track->InitMomDirY,2)))*180./TMath::Pi();
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddInitialBeamAngle(InitialBeamAngle);
        }
        //--------BF Segment tracking--------//
        if((track->Scint1HitFlag || track->Scint2HitFlag) & (track->ID == 1)){
          if(track->R1QuartzHitFlag & (track->ID == 1)){
            R1Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionX((Float_t)track->R1QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionY((Float_t)track->R1QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionZ((Float_t)track->R1QuartzHitZ/cm);
          }
          if(track->R2QuartzHitFlag & (track->ID == 1)){
            R2Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionX((Float_t)track->R2QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionY((Float_t)track->R2QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionZ((Float_t)track->R2QuartzHitZ/cm);
          }
          if(track->R3QuartzHitFlag & (track->ID == 1)){
            R3Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionX((Float_t)track->R3QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionY((Float_t)track->R3QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionZ((Float_t)track->R3QuartzHitZ/cm);
          }
          if(track->R4QuartzHitFlag & (track->ID == 1)){
            R4Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionX((Float_t)track->R4QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionY((Float_t)track->R4QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionZ((Float_t)track->R4QuartzHitZ/cm);
          }
          if(track->R5QuartzHitFlag & (track->ID == 1)){
            R5Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionX((Float_t)track->R5QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionY((Float_t)track->R5QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionZ((Float_t)track->R5QuartzHitZ/cm);
          }
          if(track->R6QuartzHitFlag & (track->ID == 1)){
            R6Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionX((Float_t)track->R6QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionY((Float_t)track->R6QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionZ((Float_t)track->R6QuartzHitZ/cm);
          }
          if(track->R7QuartzHitFlag & (track->ID == 1)){
            R7Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionX((Float_t)track->R7QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionY((Float_t)track->R7QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionZ((Float_t)track->R7QuartzHitZ/cm);
          }
          if(track->R8QuartzHitFlag & (track->ID == 1)){
            R8Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionX((Float_t)track->R8QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionY((Float_t)track->R8QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionZ((Float_t)track->R8QuartzHitZ/cm);
          }
          if(track->Scint1HitFlag & (track->ID == 1) ){
            Scint1Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint1TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint1HitPositionX((Float_t)track->Scint1HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint1HitPositionY((Float_t)track->Scint1HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint1HitPositionZ((Float_t)track->Scint1HitZ/cm);
          }
          if(track->Scint2HitFlag & (track->ID == 1)){
            Scint2Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint2TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint2HitPositionX((Float_t)track->Scint2HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint2HitPositionY((Float_t)track->Scint2HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint2HitPositionZ((Float_t)track->Scint2HitZ/cm);
          }
          if(track->Scint3HitFlag & (track->ID == 1)){
            Scint3Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint3TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint3HitPositionX((Float_t)track->Scint3HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint3HitPositionY((Float_t)track->Scint3HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint3HitPositionZ((Float_t)track->Scint3HitZ/cm);
          }
          if(track->Scint4HitFlag & (track->ID == 1)){
            Scint4Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint4TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint4HitPositionX((Float_t)track->Scint4HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint4HitPositionY((Float_t)track->Scint4HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint4HitPositionZ((Float_t)track->Scint4HitZ/cm);
          }
          if(((Scint1Hit == 1) && ((Scint3Hit == 1) || (Scint4Hit == 1))) || ((Scint2Hit == 1) && ((Scint3Hit == 1) || (Scint4Hit == 1)))){
            if(Scint1Hit==1) Scint1_Tracker = 1;
            if(Scint2Hit==1) Scint2_Tracker = 1;
            if(Scint3Hit==1) Scint3_Tracker = 1;
            if(Scint4Hit==1) Scint4_Tracker = 1;
            if((Scint1Hit==1) && (Scint3Hit==1)) Scint13_Tracker = 1;
            if((Scint1Hit==1) && (Scint4Hit==1)) Scint14_Tracker = 1;
            if((Scint2Hit==1) && (Scint3Hit==1)) Scint23_Tracker = 1;
            if((Scint2Hit==1) && (Scint4Hit==1)) Scint24_Tracker = 1;
            if(R1Hit==1) R1_Tracker = 1;
            if(R2Hit==1) R2_Tracker = 1;
            if(R3Hit==1) R3_Tracker = 1;
            if(R4Hit==1) R4_Tracker = 1;
            if(R5Hit==1) R5_Tracker = 1;
            if(R6Hit==1) R6_Tracker = 1;
            if(R7Hit==1) R7_Tracker = 1;
            if(R8Hit==1) R8_Tracker = 1;
            if((R1Hit==1) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R1_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==1) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R2_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==1) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R3_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==1) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R4_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==1) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R5_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==1) & (R7Hit==0) & (R8Hit==0)) R6_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==1) & (R8Hit==0)) R7_SoloTracker = 1;
            if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==1)) R8_SoloTracker = 1;
            if((R1Hit==1) & (R2Hit==0)) R1_AdjacentTracker = 1;
            if((R1Hit==0) & (R2Hit==1) & (R3Hit==0)) R2_AdjacentTracker = 1;
            if((R2Hit==0) & (R3Hit==1) & (R4Hit==0)) R3_AdjacentTracker = 1;
            if((R3Hit==0) & (R4Hit==1) & (R5Hit==0)) R4_AdjacentTracker = 1;
            if((R4Hit==0) & (R5Hit==1) & (R8Hit==0)) R5_AdjacentTracker = 1;
            if((R4Hit==0) & (R6Hit==1) & (R8Hit==0)) R6_AdjacentTracker = 1;
            if((R4Hit==0) & (R7Hit==1) & (R8Hit==0)) R7_AdjacentTracker = 1;
            if((R5Hit==0) & (R8Hit==1)) R8_AdjacentTracker = 1;
          }
        }
        //--------FF Segment Tracking--------//
        if((track->Scint5HitFlag || track->Scint6HitFlag) & (track->ID == 1)){
          if(track->R9QuartzHitFlag & (track->ID == 1)){
            R9Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9QuartzHitPositionX((Float_t)track->R9QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9QuartzHitPositionY((Float_t)track->R9QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9QuartzHitPositionZ((Float_t)track->R9QuartzHitZ/cm);
          }
          if(track->R10QuartzHitFlag & (track->ID == 1)){
            R10Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10QuartzHitPositionX((Float_t)track->R10QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10QuartzHitPositionY((Float_t)track->R10QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10QuartzHitPositionZ((Float_t)track->R10QuartzHitZ/cm);
          }
          if(track->R11QuartzHitFlag & (track->ID == 1)){
            R11Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11QuartzHitPositionX((Float_t)track->R11QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11QuartzHitPositionY((Float_t)track->R11QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11QuartzHitPositionZ((Float_t)track->R11QuartzHitZ/cm);
          }
          if(track->R12QuartzHitFlag & (track->ID == 1)){
            R12Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12QuartzHitPositionX((Float_t)track->R12QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12QuartzHitPositionY((Float_t)track->R12QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12QuartzHitPositionZ((Float_t)track->R12QuartzHitZ/cm);
          }
          if(track->R13QuartzHitFlag & (track->ID == 1)){
            R13Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13QuartzHitPositionX((Float_t)track->R13QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13QuartzHitPositionY((Float_t)track->R13QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13QuartzHitPositionZ((Float_t)track->R13QuartzHitZ/cm);
          }
          if(track->R14QuartzHitFlag & (track->ID == 1)){
            R14Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14QuartzHitPositionX((Float_t)track->R14QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14QuartzHitPositionY((Float_t)track->R14QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14QuartzHitPositionZ((Float_t)track->R14QuartzHitZ/cm);
          }
          if(track->R15QuartzHitFlag & (track->ID == 1)){
            R15Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15QuartzHitPositionX((Float_t)track->R15QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15QuartzHitPositionY((Float_t)track->R15QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15QuartzHitPositionZ((Float_t)track->R15QuartzHitZ/cm);
          }
          if(track->R16QuartzHitFlag & (track->ID == 1)){
            R16Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16QuartzHitPositionX((Float_t)track->R16QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16QuartzHitPositionY((Float_t)track->R16QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16QuartzHitPositionZ((Float_t)track->R16QuartzHitZ/cm);
          }
          if(track->Scint5HitFlag & (track->ID == 1) ){
            Scint5Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint5TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint5HitPositionX((Float_t)track->Scint5HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint5HitPositionY((Float_t)track->Scint5HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint5HitPositionZ((Float_t)track->Scint5HitZ/cm);
          }
          if(track->Scint6HitFlag & (track->ID == 1) ){
            Scint6Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint6TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint6HitPositionX((Float_t)track->Scint6HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint6HitPositionY((Float_t)track->Scint6HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint6HitPositionZ((Float_t)track->Scint6HitZ/cm);
          }
          if(track->Scint7HitFlag & (track->ID == 1) ){
            Scint7Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint7TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint7HitPositionX((Float_t)track->Scint7HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint7HitPositionY((Float_t)track->Scint7HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint7HitPositionZ((Float_t)track->Scint7HitZ/cm);
          }
          if(track->Scint8HitFlag & (track->ID == 1) ){
            Scint8Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint8TrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint8HitPositionX((Float_t)track->Scint8HitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint8HitPositionY((Float_t)track->Scint8HitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScint8HitPositionZ((Float_t)track->Scint8HitZ/cm);
          }
          if(((Scint5Hit == 1) && ((Scint7Hit == 1) || (Scint8Hit == 1))) || ((Scint6Hit == 1) && ((Scint7Hit == 1) || (Scint8Hit == 1)))){
            if(Scint5Hit==1) Scint5_Tracker = 1;
            if(Scint6Hit==1) Scint6_Tracker = 1;
            if(Scint7Hit==1) Scint7_Tracker = 1;
            if(Scint8Hit==1) Scint8_Tracker = 1;
            if((Scint5Hit==1) && (Scint7Hit==1)) Scint57_Tracker = 1;
            if((Scint5Hit==1) && (Scint8Hit==1)) Scint58_Tracker = 1;
            if((Scint6Hit==1) && (Scint7Hit==1)) Scint67_Tracker = 1;
            if((Scint6Hit==1) && (Scint8Hit==1)) Scint68_Tracker = 1;
            if(R9Hit==1) R9_Tracker = 1;
            if(R10Hit==1) R10_Tracker = 1;
            if(R11Hit==1) R11_Tracker = 1;
            if(R12Hit==1) R12_Tracker = 1;
            if(R13Hit==1) R13_Tracker = 1;
            if(R14Hit==1) R14_Tracker = 1;
            if(R15Hit==1) R15_Tracker = 1;
            if(R16Hit==1) R16_Tracker = 1;
            if((R9Hit==1) & (R10Hit==0) & (R11Hit==0) & (R12Hit==0) & (R13Hit==0) & (R14Hit==0) & (R15Hit==0) & (R16Hit==0)) R9_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==1) & (R11Hit==0) & (R12Hit==0) & (R13Hit==0) & (R14Hit==0) & (R15Hit==0) & (R16Hit==0)) R10_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==1) & (R12Hit==0) & (R13Hit==0) & (R14Hit==0) & (R15Hit==0) & (R16Hit==0)) R11_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==0) & (R12Hit==1) & (R13Hit==0) & (R14Hit==0) & (R15Hit==0) & (R16Hit==0)) R12_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==0) & (R12Hit==0) & (R13Hit==1) & (R14Hit==0) & (R15Hit==0) & (R16Hit==0)) R13_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==0) & (R12Hit==0) & (R13Hit==0) & (R14Hit==1) & (R15Hit==0) & (R16Hit==0)) R14_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==0) & (R12Hit==0) & (R13Hit==0) & (R14Hit==0) & (R15Hit==1) & (R16Hit==0)) R15_SoloTracker = 1;
            if((R9Hit==0) & (R10Hit==0) & (R11Hit==0) & (R12Hit==0) & (R13Hit==0) & (R14Hit==0) & (R15Hit==0) & (R16Hit==1)) R16_SoloTracker = 1;
            if((R9Hit==1) & (R10Hit==0)) R9_AdjacentTracker = 1;
            if((R9Hit==0) & (R10Hit==1) & (R11Hit==0)) R10_AdjacentTracker = 1;
            if((R10Hit==0) & (R11Hit==1) & (R12Hit==0)) R11_AdjacentTracker = 1;
            if((R11Hit==0) & (R12Hit==1) & (R13Hit==0)) R12_AdjacentTracker = 1;
            if((R12Hit==0) & (R13Hit==1) & (R16Hit==0)) R13_AdjacentTracker = 1;
            if((R12Hit==0) & (R14Hit==1) & (R16Hit==0)) R14_AdjacentTracker = 1;
            if((R12Hit==0) & (R15Hit==1) & (R16Hit==0)) R15_AdjacentTracker = 1;
            if((R13Hit==0) & (R16Hit==1)) R16_AdjacentTracker = 1;
          }
        }
        for(int p = 0; p < track->StepNChPhotons.size(); p++){
          // analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzStepNPhotons(track->StepNChPhotons[p]);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzElectronStepLength(track->StepLength[p]/cm);
        }
        for(int p = 0; p < track->SecPhotonAngle.size(); p++)
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
      }
      if(track->Particle == myPhoton){
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPhotonTrackID(track->ID);	
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddElectronTrackID(0);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzTrackData(track->QLength/cm, track->QSteps);
        //analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddScintTrackData(track->SLength/cm, track->SSteps);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzPhotonEnergy(track->InitKinEnergy/eV);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzPhotonAtExitFlag(track->QExitFlag);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddLightGuideTrackData(track->LGLength/cm, track->LGSteps);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTTrackHit(track->PMTHitFlag);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddLightGuideTrackHit(track->LGHitFlag);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTPhotonEnergy(track->InitKinEnergy/eV);
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddLightGuidePhotonEnergy(track->InitKinEnergy/eV);
        QuartzSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
        if(track->QExitFlag)
          LightGuideSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
        if(track->PMTHitFlag){
          //G4cout << "PHOTON" << G4endl;
          PMTSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTHitPositionX((Float_t)track->PMTHitX/cm);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTHitPositionY((Float_t)track->PMTHitY/cm);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTHitPositionZ((Float_t)track->PMTHitZ/cm);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTWindowReflectionAngle((Float_t)track->PMTWinRefl);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPMTPhotonEnergy(track->InitKinEnergy/eV);
          optPhEng = track->InitKinEnergy/eV;
          OptParam* op = TrackingReadout->GetOpticalParameters();
          PMThit++;
        }     
        for(int s = 0; s < track->NSteps; s++){
          if(track->StepVolume[s] == myQuartz){
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzStepLength(track->StepLength[s]/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzIncidentPhotonAngle(track->StepAngle[s]);
          }
          if(track->StepVolume[s] == myLightGuide){
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddLightGuideStepLength(track->StepLength[s]/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddLightGuideIncidentPhotonAngle(track->StepAngle[s]);
          }
        }
      }
    }
    //Storing the pes generates in each cathode. SoloTracker is reset to 0 if it fails the pe yield cuts
    //--------BF & FF Segment Tracking--------//
    R1_pes = TrackingReadout->R1_GetCathodeDetections();
    R2_pes = TrackingReadout->R2_GetCathodeDetections();
    R3_pes = TrackingReadout->R3_GetCathodeDetections();
    R4_pes = TrackingReadout->R4_GetCathodeDetections();
    R5_pes = TrackingReadout->R5_GetCathodeDetections();
    R6_pes = TrackingReadout->R6_GetCathodeDetections();
    R7_pes = TrackingReadout->R7_GetCathodeDetections();
    R8_pes = TrackingReadout->R8_GetCathodeDetections();
    R9_pes = TrackingReadout->R9_GetCathodeDetections();
    R10_pes = TrackingReadout->R10_GetCathodeDetections();
    R11_pes = TrackingReadout->R11_GetCathodeDetections();
    R12_pes = TrackingReadout->R12_GetCathodeDetections();
    R13_pes = TrackingReadout->R13_GetCathodeDetections();
    R14_pes = TrackingReadout->R14_GetCathodeDetections();
    R15_pes = TrackingReadout->R15_GetCathodeDetections();
    R16_pes = TrackingReadout->R16_GetCathodeDetections();
    if((R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R1_SoloTracker = 0;
    if((R1_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R2_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R3_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R4_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R5_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R6_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R8_pes >= 1)) R7_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1)) R8_SoloTracker = 0;
    if((R10_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R9_SoloTracker = 0;
    if((R9_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R10_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R11_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R11_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R12_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R13_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R15_pes >= 1) || (R16_pes >= 1)) R14_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R16_pes >= 1)) R15_SoloTracker = 0;
    if((R9_pes >= 1) || (R10_pes >= 1) || (R11_pes >= 1) || (R12_pes >= 1) || (R13_pes >= 1) || (R14_pes >= 1) || (R15_pes >= 1)) R16_SoloTracker = 0;
    
    //Stores data in root for specific detectors. Used to control amount of data that is saved for large simulations
    //This also stores PEs as variables at the end of the event (specifically during the last track to prevent overwrite)
    if(Det == 999){
      //The Ntuple is not filled if Det == 999. Use when file size is a serious constraint
      //PE yield histograms will still be written, but not accessible as leaves in the root file
    }
    else if(Det == 0){
      //Everything is stored
      if(track->ID == 1){
        //if(track->ID == 1) G4cout << R3_Tracker << G4endl;
        if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
        if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
        if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
        if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
        if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
        if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
        if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
        if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
        if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
        if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
        if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
        if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
        if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
        if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
        if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
        if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        if(R9_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
        if(R10_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
        if(R11_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
        if(R12_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
        if(R13_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
        if(R14_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
        if(R15_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
        if(R16_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
        if(R9_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
        if(R10_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
        if(R11_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
        if(R12_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
        if(R13_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
        if(R14_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
        if(R15_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
        if(R16_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
      }
      analysis->FillRootNtuple();
    }
    else if(Det == 1){
      if((R1_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
      if(R1_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 2){
      if((R2_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
      if(R2_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 3){
      //G4cout << "Entrance" << G4endl;
      //if(track->ID == 1) G4cout << R3_Tracker << G4endl;
      if((R3_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
      if(R3_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 4){
      if((R4_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
      if(R4_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 5){
      if((R5_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
      if(R5_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 6){
      if((R6_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
      if(R6_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 7){
      if((R7_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
      if(R7_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 8){
      if((R8_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
      if(R8_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 9){
      if((R9_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
      if(R9_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 10){
      if((R10_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
      if(R10_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 11){
      if((R11_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
      if(R11_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 12){
      if((R12_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
      if(R12_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 13){
      if((R13_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
      if(R13_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 14){
      if((R14_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
      if(R14_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 15){
      if((R15_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
      if(R15_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 16){
      if((R16_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
      if(R16_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 17){
      if(Scint13_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 18){
      if(Scint14_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 19){
      if(Scint23_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 20){
      if(Scint24_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 21){
      if(Scint57_Tracker == 1){
        if(track->ID == 1){
          if(R9_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
          if(R10_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
          if(R11_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
          if(R12_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
          if(R13_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
          if(R14_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
          if(R15_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
          if(R16_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
          if(R9_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
          if(R10_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
          if(R11_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
          if(R12_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
          if(R13_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
          if(R14_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
          if(R15_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
          if(R16_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 22){
      if(Scint58_Tracker == 1){
        if(track->ID == 1){
          if(R9_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
          if(R10_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
          if(R11_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
          if(R12_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
          if(R13_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
          if(R14_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
          if(R15_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
          if(R16_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
          if(R9_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
          if(R10_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
          if(R11_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
          if(R12_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
          if(R13_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
          if(R14_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
          if(R15_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
          if(R16_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 23){
      if(Scint67_Tracker == 1){
        if(track->ID == 1){
          if(R9_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
          if(R10_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
          if(R11_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
          if(R12_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
          if(R13_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
          if(R14_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
          if(R15_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
          if(R16_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
          if(R9_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
          if(R10_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
          if(R11_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
          if(R12_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
          if(R13_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
          if(R14_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
          if(R15_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
          if(R16_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    else if(Det == 24){
      if(Scint68_Tracker == 1){
        if(track->ID == 1){
          if(R9_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9PEs(R9_pes);
          if(R10_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10PEs(R10_pes);
          if(R11_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11PEs(R11_pes);
          if(R12_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12PEs(R12_pes);
          if(R13_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13PEs(R13_pes);
          if(R14_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14PEs(R14_pes);
          if(R15_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15PEs(R15_pes);
          if(R16_Tracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16PEs(R16_pes);
          if(R9_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR9SoloPEs(R9_pes);
          if(R10_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR10SoloPEs(R10_pes);
          if(R11_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR11SoloPEs(R11_pes);
          if(R12_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR12SoloPEs(R12_pes);
          if(R13_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR13SoloPEs(R13_pes);
          if(R14_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR14SoloPEs(R14_pes);
          if(R15_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR15SoloPEs(R15_pes);
          if(R16_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR16SoloPEs(R16_pes);
        }
        analysis->FillRootNtuple();
      }
    }
  }
  //Stores PEs if scintillator cuts are passed
  //The following sorting system is bulky, but it works. I will make this more space efficient at some point
  //--------BF Segment Histogram Filling--------//
  if(R1_Tracker == 1){
      analysis->R1_AddCathodeDetectionEvent(R1_pes);
    if(Scint13_Tracker == 1){
      analysis->R1_Scint13_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R1_Scint14_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R1_Scint23_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R1_Scint24_AddCathodeDetectionEvent(R1_pes);
    }
  }
  if(R2_Tracker == 1){
    analysis->R2_AddCathodeDetectionEvent(R2_pes);
    if(Scint13_Tracker == 1){
      analysis->R2_Scint13_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R2_Scint14_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R2_Scint23_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R2_Scint24_AddCathodeDetectionEvent(R2_pes);
    }
  }
  if(R3_Tracker == 1){
    analysis->R3_AddCathodeDetectionEvent(R3_pes);
    if(Scint13_Tracker == 1){
      analysis->R3_Scint13_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R3_Scint14_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R3_Scint23_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R3_Scint24_AddCathodeDetectionEvent(R3_pes);
    }
  }
  if(R4_Tracker == 1){
    analysis->R4_AddCathodeDetectionEvent(R4_pes);
    if(Scint13_Tracker == 1){
      analysis->R4_Scint13_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R4_Scint14_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R4_Scint23_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R4_Scint24_AddCathodeDetectionEvent(R4_pes);
    }
  }
  if(R5_Tracker == 1){
    analysis->R5_AddCathodeDetectionEvent(R5_pes);
    if(Scint13_Tracker == 1){
      analysis->R5_Scint13_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R5_Scint14_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R5_Scint23_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R5_Scint24_AddCathodeDetectionEvent(R5_pes);
    }
  }
  if(R6_Tracker == 1){
    analysis->R6_AddCathodeDetectionEvent(R6_pes);
    if(Scint13_Tracker == 1){
      analysis->R6_Scint13_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R6_Scint14_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R6_Scint23_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R6_Scint24_AddCathodeDetectionEvent(R6_pes);
    }
  }
  if(R7_Tracker == 1){
    analysis->R7_AddCathodeDetectionEvent(R7_pes);
    if(Scint13_Tracker == 1){
      analysis->R7_Scint13_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R7_Scint14_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R7_Scint23_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R7_Scint24_AddCathodeDetectionEvent(R7_pes);
    }
  }
  if(R8_Tracker == 1){
    analysis->R8_AddCathodeDetectionEvent(R8_pes);
    if(Scint13_Tracker == 1){
      analysis->R8_Scint13_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R8_Scint14_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R8_Scint23_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R8_Scint24_AddCathodeDetectionEvent(R8_pes);
    }
  }
  //Stores PEs if the scint cuts are passed and only one tile has been hit (Ring/Solo cuts)
  if(R1_SoloTracker == 1){
      analysis->R1Only_AddCathodeDetectionEvent(R1_pes);
    if(Scint13_Tracker == 1){
      analysis->R1Only_Scint13_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R1Only_Scint14_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R1Only_Scint23_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R1Only_Scint24_AddCathodeDetectionEvent(R1_pes);
    }
  }
  if(R2_SoloTracker == 1){
    analysis->R2Only_AddCathodeDetectionEvent(R2_pes);
    if(Scint13_Tracker == 1){
      analysis->R2Only_Scint13_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R2Only_Scint14_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R2Only_Scint23_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R2Only_Scint24_AddCathodeDetectionEvent(R2_pes);
    }
  }
  if(R3_SoloTracker == 1){
    analysis->R3Only_AddCathodeDetectionEvent(R3_pes);
    if(Scint13_Tracker == 1){
      analysis->R3Only_Scint13_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R3Only_Scint14_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R3Only_Scint23_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R3Only_Scint24_AddCathodeDetectionEvent(R3_pes);
    }
  }
  if(R4_SoloTracker == 1){
    analysis->R4Only_AddCathodeDetectionEvent(R4_pes);
    if(Scint13_Tracker == 1){
      analysis->R4Only_Scint13_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R4Only_Scint14_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R4Only_Scint23_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R4Only_Scint24_AddCathodeDetectionEvent(R4_pes);
    }
  }
  if(R5_SoloTracker == 1){
    analysis->R5Only_AddCathodeDetectionEvent(R5_pes);
    if(Scint13_Tracker == 1){
      analysis->R5Only_Scint13_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R5Only_Scint14_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R5Only_Scint23_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R5Only_Scint24_AddCathodeDetectionEvent(R5_pes);
    }
  }
  if(R6_SoloTracker == 1){
    analysis->R6Only_AddCathodeDetectionEvent(R6_pes);
    if(Scint13_Tracker == 1){
      analysis->R6Only_Scint13_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R6Only_Scint14_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R6Only_Scint23_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R6Only_Scint24_AddCathodeDetectionEvent(R6_pes);
    }
  }
  if(R7_SoloTracker == 1){
    analysis->R7Only_AddCathodeDetectionEvent(R7_pes);
    if(Scint13_Tracker == 1){
      analysis->R7Only_Scint13_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R7Only_Scint14_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R7Only_Scint23_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R7Only_Scint24_AddCathodeDetectionEvent(R7_pes);
    }
  }
  if(R8_SoloTracker == 1){
    analysis->R8Only_AddCathodeDetectionEvent(R8_pes);
    if(Scint13_Tracker == 1){
      analysis->R8Only_Scint13_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R8Only_Scint14_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R8Only_Scint23_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R8Only_Scint24_AddCathodeDetectionEvent(R8_pes);
    }
  }
  //Stores PEs if the scint cuts are passed and adjacent tiles are not hit (Adjacency cuts)
  if(R1_AdjacentTracker == 1){
    analysis->R1Adjacent_AddCathodeDetectionEvent(R1_pes);
    if(Scint13_Tracker == 1){
      analysis->R1Adjacent_Scint13_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R1Adjacent_Scint14_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R1Adjacent_Scint23_AddCathodeDetectionEvent(R1_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R1Adjacent_Scint24_AddCathodeDetectionEvent(R1_pes);
    }
  }
  if(R2_AdjacentTracker == 1){
    analysis->R2Adjacent_AddCathodeDetectionEvent(R2_pes);
    if(Scint13_Tracker == 1){
      analysis->R2Adjacent_Scint13_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R2Adjacent_Scint14_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R2Adjacent_Scint23_AddCathodeDetectionEvent(R2_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R2Adjacent_Scint24_AddCathodeDetectionEvent(R2_pes);
    }
  }
  if(R3_AdjacentTracker == 1){
    analysis->R3Adjacent_AddCathodeDetectionEvent(R3_pes);
    if(Scint13_Tracker == 1){
      analysis->R3Adjacent_Scint13_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R3Adjacent_Scint14_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R3Adjacent_Scint23_AddCathodeDetectionEvent(R3_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R3Adjacent_Scint24_AddCathodeDetectionEvent(R3_pes);
    }
  }
  if(R4_AdjacentTracker == 1){
    analysis->R4Adjacent_AddCathodeDetectionEvent(R4_pes);
    if(Scint13_Tracker == 1){
      analysis->R4Adjacent_Scint13_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R4Adjacent_Scint14_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R4Adjacent_Scint23_AddCathodeDetectionEvent(R4_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R4Adjacent_Scint24_AddCathodeDetectionEvent(R4_pes);
    }
  }
  if(R5_AdjacentTracker == 1){
    analysis->R5Adjacent_AddCathodeDetectionEvent(R5_pes);
    if(Scint13_Tracker == 1){
      analysis->R5Adjacent_Scint13_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R5Adjacent_Scint14_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R5Adjacent_Scint23_AddCathodeDetectionEvent(R5_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R5Adjacent_Scint24_AddCathodeDetectionEvent(R5_pes);
    }
  }
  if(R6_AdjacentTracker == 1){
    analysis->R6Adjacent_AddCathodeDetectionEvent(R6_pes);
    if(Scint13_Tracker == 1){
      analysis->R6Adjacent_Scint13_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R6Adjacent_Scint14_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R6Adjacent_Scint23_AddCathodeDetectionEvent(R6_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R6Adjacent_Scint24_AddCathodeDetectionEvent(R6_pes);
    }
  }
  if(R7_AdjacentTracker == 1){
    analysis->R7Adjacent_AddCathodeDetectionEvent(R7_pes);
    if(Scint13_Tracker == 1){
      analysis->R7Adjacent_Scint13_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R7Adjacent_Scint14_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R7Adjacent_Scint23_AddCathodeDetectionEvent(R7_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R7Adjacent_Scint24_AddCathodeDetectionEvent(R7_pes);
    }
  }
  if(R8_AdjacentTracker == 1){
    analysis->R8Adjacent_AddCathodeDetectionEvent(R8_pes);
    if(Scint13_Tracker == 1){
      analysis->R8Adjacent_Scint13_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint14_Tracker == 1){
      analysis->R8Adjacent_Scint14_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint23_Tracker == 1){
      analysis->R8Adjacent_Scint23_AddCathodeDetectionEvent(R8_pes);
    }
    if(Scint24_Tracker == 1){
      analysis->R8Adjacent_Scint24_AddCathodeDetectionEvent(R8_pes);
    }
  }

  //--------FF Segment Histogram Filling--------//
  if(R9_Tracker == 1){
    analysis->R9_AddCathodeDetectionEvent(R9_pes);
    if(Scint57_Tracker == 1){
      analysis->R9_Scint57_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R9_Scint58_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R9_Scint67_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R9_Scint68_AddCathodeDetectionEvent(R9_pes);
    }
  }
  if(R10_Tracker == 1){
    analysis->R10_AddCathodeDetectionEvent(R10_pes);
    if(Scint57_Tracker == 1){
      analysis->R10_Scint57_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R10_Scint58_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R10_Scint67_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R10_Scint68_AddCathodeDetectionEvent(R10_pes);
    }
  }
  if(R11_Tracker == 1){
    analysis->R11_AddCathodeDetectionEvent(R11_pes);
    if(Scint57_Tracker == 1){
      analysis->R11_Scint57_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R11_Scint58_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R11_Scint67_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R11_Scint68_AddCathodeDetectionEvent(R11_pes);
    }
  }
  if(R12_Tracker == 1){
    analysis->R12_AddCathodeDetectionEvent(R12_pes);
    if(Scint57_Tracker == 1){
      analysis->R12_Scint57_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R12_Scint58_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R12_Scint67_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R12_Scint68_AddCathodeDetectionEvent(R12_pes);
    }
  }
  if(R13_Tracker == 1){
    analysis->R13_AddCathodeDetectionEvent(R13_pes);
    if(Scint57_Tracker == 1){
      analysis->R13_Scint57_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R13_Scint58_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R13_Scint67_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R13_Scint68_AddCathodeDetectionEvent(R13_pes);
    }
  }
  if(R14_Tracker == 1){
    analysis->R14_AddCathodeDetectionEvent(R14_pes);
    if(Scint57_Tracker == 1){
      analysis->R14_Scint57_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R14_Scint58_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R14_Scint67_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R14_Scint68_AddCathodeDetectionEvent(R14_pes);
    }
  }
  if(R15_Tracker == 1){
    analysis->R15_AddCathodeDetectionEvent(R15_pes);
    if(Scint57_Tracker == 1){
      analysis->R15_Scint57_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R15_Scint58_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R15_Scint67_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R15_Scint68_AddCathodeDetectionEvent(R15_pes);
    }
  }
  if(R16_Tracker == 1){
    analysis->R16_AddCathodeDetectionEvent(R16_pes);
    if(Scint57_Tracker == 1){
      analysis->R16_Scint57_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R16_Scint58_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R16_Scint67_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R16_Scint68_AddCathodeDetectionEvent(R16_pes);
    }
  }
  //Stores PEs if the scint cuts are passed and only one tile has been hit (Ring/Solo cuts)
  if(R9_SoloTracker == 1){
      analysis->R9Only_AddCathodeDetectionEvent(R9_pes);
    if(Scint57_Tracker == 1){
      analysis->R9Only_Scint57_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R9Only_Scint58_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R9Only_Scint67_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R9Only_Scint68_AddCathodeDetectionEvent(R9_pes);
    }
  }
  if(R10_SoloTracker == 1){
    analysis->R10Only_AddCathodeDetectionEvent(R10_pes);
    if(Scint57_Tracker == 1){
      analysis->R10Only_Scint57_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R10Only_Scint58_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R10Only_Scint67_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R10Only_Scint68_AddCathodeDetectionEvent(R10_pes);
    }
  }
  if(R11_SoloTracker == 1){
    analysis->R11Only_AddCathodeDetectionEvent(R11_pes);
    if(Scint57_Tracker == 1){
      analysis->R11Only_Scint57_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R11Only_Scint58_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R11Only_Scint67_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R11Only_Scint68_AddCathodeDetectionEvent(R11_pes);
    }
  }
  if(R12_SoloTracker == 1){
    analysis->R12Only_AddCathodeDetectionEvent(R12_pes);
    if(Scint57_Tracker == 1){
      analysis->R12Only_Scint57_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R12Only_Scint58_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R12Only_Scint67_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R12Only_Scint68_AddCathodeDetectionEvent(R12_pes);
    }
  }
  if(R13_SoloTracker == 1){
    analysis->R13Only_AddCathodeDetectionEvent(R13_pes);
    if(Scint57_Tracker == 1){
      analysis->R13Only_Scint57_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R13Only_Scint58_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R13Only_Scint67_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R13Only_Scint68_AddCathodeDetectionEvent(R13_pes);
    }
  }
  if(R14_SoloTracker == 1){
    analysis->R14Only_AddCathodeDetectionEvent(R14_pes);
    if(Scint57_Tracker == 1){
      analysis->R14Only_Scint57_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R14Only_Scint58_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R14Only_Scint67_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R14Only_Scint68_AddCathodeDetectionEvent(R14_pes);
    }
  }
  if(R15_SoloTracker == 1){
    analysis->R15Only_AddCathodeDetectionEvent(R15_pes);
    if(Scint57_Tracker == 1){
      analysis->R15Only_Scint57_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R15Only_Scint58_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R15Only_Scint67_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R15Only_Scint68_AddCathodeDetectionEvent(R15_pes);
    }
  }
  if(R16_SoloTracker == 1){
    analysis->R16Only_AddCathodeDetectionEvent(R16_pes);
    if(Scint57_Tracker == 1){
      analysis->R16Only_Scint57_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R16Only_Scint58_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R16Only_Scint67_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R16Only_Scint68_AddCathodeDetectionEvent(R16_pes);
    }
  }
  //Stores PEs if the scint cuts are passed and adjacent tiles are not hit (Adjacency cuts)
  if(R9_AdjacentTracker == 1){
    analysis->R9Adjacent_AddCathodeDetectionEvent(R9_pes);
    if(Scint57_Tracker == 1){
      analysis->R9Adjacent_Scint57_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R9Adjacent_Scint58_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R9Adjacent_Scint67_AddCathodeDetectionEvent(R9_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R9Adjacent_Scint68_AddCathodeDetectionEvent(R9_pes);
    }
  }
  if(R10_AdjacentTracker == 1){
    analysis->R10Adjacent_AddCathodeDetectionEvent(R10_pes);
    if(Scint57_Tracker == 1){
      analysis->R10Adjacent_Scint57_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R10Adjacent_Scint58_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R10Adjacent_Scint67_AddCathodeDetectionEvent(R10_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R10Adjacent_Scint68_AddCathodeDetectionEvent(R10_pes);
    }
  }
  if(R11_AdjacentTracker == 1){
    analysis->R11Adjacent_AddCathodeDetectionEvent(R11_pes);
    if(Scint57_Tracker == 1){
      analysis->R11Adjacent_Scint57_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R11Adjacent_Scint58_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R11Adjacent_Scint67_AddCathodeDetectionEvent(R11_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R11Adjacent_Scint68_AddCathodeDetectionEvent(R11_pes);
    }
  }
  if(R12_AdjacentTracker == 1){
    analysis->R12Adjacent_AddCathodeDetectionEvent(R12_pes);
    if(Scint57_Tracker == 1){
      analysis->R12Adjacent_Scint57_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R12Adjacent_Scint58_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R12Adjacent_Scint67_AddCathodeDetectionEvent(R12_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R12Adjacent_Scint68_AddCathodeDetectionEvent(R12_pes);
    }
  }
  if(R13_AdjacentTracker == 1){
    analysis->R13Adjacent_AddCathodeDetectionEvent(R13_pes);
    if(Scint57_Tracker == 1){
      analysis->R13Adjacent_Scint57_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R13Adjacent_Scint58_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R13Adjacent_Scint67_AddCathodeDetectionEvent(R13_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R13Adjacent_Scint68_AddCathodeDetectionEvent(R13_pes);
    }
  }
  if(R14_AdjacentTracker == 1){
    analysis->R14Adjacent_AddCathodeDetectionEvent(R14_pes);
    if(Scint57_Tracker == 1){
      analysis->R14Adjacent_Scint57_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R14Adjacent_Scint58_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R14Adjacent_Scint67_AddCathodeDetectionEvent(R14_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R14Adjacent_Scint68_AddCathodeDetectionEvent(R14_pes);
    }
  }
  if(R15_AdjacentTracker == 1){
    analysis->R15Adjacent_AddCathodeDetectionEvent(R15_pes);
    if(Scint57_Tracker == 1){
      analysis->R15Adjacent_Scint57_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R15Adjacent_Scint58_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R15Adjacent_Scint67_AddCathodeDetectionEvent(R15_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R15Adjacent_Scint68_AddCathodeDetectionEvent(R15_pes);
    }
  }
  if(R16_AdjacentTracker == 1){
    analysis->R16Adjacent_AddCathodeDetectionEvent(R16_pes);
    if(Scint57_Tracker == 1){
      analysis->R16Adjacent_Scint57_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint58_Tracker == 1){
      analysis->R16Adjacent_Scint58_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint67_Tracker == 1){
      analysis->R16Adjacent_Scint67_AddCathodeDetectionEvent(R16_pes);
    }
    if(Scint68_Tracker == 1){
      analysis->R16Adjacent_Scint68_AddCathodeDetectionEvent(R16_pes);
    }
  }

  //Sorting complete
  
  for(int n = 1; n <= QuartzSecOptPhotonCnt->GetNbinsX(); n++)
    analysis->AddToAverageQuartzOptPhotonDist(QuartzSecOptPhotonCnt->GetBinCenter(n),QuartzSecOptPhotonCnt->GetBinContent(n));
  for(int n = 1; n <= LightGuideSecOptPhotonCnt->GetNbinsX(); n++)
    analysis->AddToAverageLightGuideOptPhotonDist(LightGuideSecOptPhotonCnt->GetBinCenter(n),LightGuideSecOptPhotonCnt->GetBinContent(n));
  for(int n = 1; n <= PMTSecOptPhotonCnt->GetNbinsX(); n++)
    analysis->AddToAveragePMTOptPhotonDist(PMTSecOptPhotonCnt->GetBinCenter(n),PMTSecOptPhotonCnt->GetBinContent(n));

  
  //=======================================================================
  // Save the Ntuple periodically so we have some data in case of a crash

  G4int eventNumber = evt->GetEventID();

  if (eventNumber%10000 == 1) analysis->AutoSaveRootNtuple();
  //=======================================================================
  
  
} // end of  MOLLEROptEventAction::EndOfEventAction()

void MOLLEROptEventAction::Initialize()
{	  
  
  primaryEventNumber = 0;
  
}
