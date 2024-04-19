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
  
  oFile.open("TestFile.txt");

  TrackingReadout->Initialize();

}


MOLLEROptEventAction::~MOLLEROptEventAction()
{
  oFile.close();
}


void MOLLEROptEventAction::BeginOfEventAction(const G4Event* evt)
{
 
  G4SDManager * SDman = G4SDManager::GetSDMpointer();

  //CollID[0] = SDman->GetCollectionID("Quartz/QuartzHitCollection");         //Currently does nothing
  //CollID[1] = SDman->GetCollectionID("LightGuide/LightGuideHitCollection"); //
  //CollID[2] = SDman->GetCollectionID("Cathode/PMTHitCollection");           //
  
  PMTSecOptPhotonCnt->Reset();
  QuartzSecOptPhotonCnt->Reset();
  LightGuideSecOptPhotonCnt->Reset();

  for(int n = 0; n < ProcessedTrack.size(); n++) delete ProcessedTrack[n];
  ProcessedTrack.clear();
  ProcessedTrack.resize(0);
  TrackingReadout->Initialize();
  // G4cout << "Event ID: " <<  evt->GetEventID() << G4endl;

}

Bool_t MOLLEROptEventAction::TrackHasBeenProcessed(G4int id)
{
  Bool_t check = false;
  for(int n = 0; n < ProcessedTrack.size(); n++)
    if(ProcessedTrack[n]->ID == id) check = true;

  return check;
}

void MOLLEROptEventAction::AddQuartzTrackStep(G4int id, G4int step)
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
  
  G4float InitialBeamAngle = 99;
  G4double LGTrackLength, QuartzTrackLength, TotalTrackLength;
  G4double R1pes = 0, R2pes = 0, R3pes = 0, R4pes = 0, R5pes = 0, R6pes = 0, R7pes = 0, R8pes = 0;
  G4int hitCnt1, hitCnt2, PMThit, qtrackID, lgtrackID, pmttrackID, ctrackID, LGSteps, QSteps, TSteps, secPhCnt;
  G4int R1Hit, R2Hit, R3Hit, R4Hit, R5Hit, R6Hit, R7Hit, R8Hit, ScintHit, GEM1Hit, GEM2Hit; //Tracks whether a detector's quartz tile has been hit in a given event
  G4float R1XHit = 999, R2XHit = 999, R3XHit = 999, R4XHit = 999, R5XHit = 999, R6XHit = 999, R7XHit = 999, R8XHit = 999; //Stores the X position of the beam when hitting the quartz tile
  G4float R1YHit = 999, R2YHit = 999, R3YHit = 999, R4YHit = 999, R5YHit = 999, R6YHit = 999, R7YHit = 999, R8YHit = 999; //Same but Y position
  G4int NumSecPhotons = 0;
  G4int hitflag = 0;
  G4int R1_Tracker = 0;  //Stores whether the R1 tile (+ scint) has been hit this event  
  G4int R2_Tracker = 0;  //
  G4int R3_Tracker = 0;  //  
  G4int R4_Tracker = 0;  //  
  G4int R5_Tracker = 0;  //  
  G4int R6_Tracker = 0;  //  
  G4int R7_Tracker = 0;  //  
  G4int R8_Tracker = 0;  //
  G4int R1_SoloTracker = 0;  //Stores whether only the R1 tile (+ scint) has been hit this event
  G4int R2_SoloTracker = 0;  //
  G4int R3_SoloTracker = 0;  //  
  G4int R4_SoloTracker = 0;  //  
  G4int R5_SoloTracker = 0;  //  
  G4int R6_SoloTracker = 0;  //  
  G4int R7_SoloTracker = 0;  //  
  G4int R8_SoloTracker = 0;  //  
  G4int Scint_Tracker = 0;   //Stores whether the spectrum defining scintillator has been hit
  G4int GEM_Tracker = 0;     //Stores whether both GEMs were hit this run (can be adjusted to one or two)
  G4int R1_AdjacentTracker = 0; //Stores hits on R1 that do not hit R2
  G4int R2_AdjacentTracker = 0; //Stores hits on R2 that do not hit R1 or R3
  G4int R3_AdjacentTracker = 0; //
  G4int R4_AdjacentTracker = 0; //
  G4int R5_AdjacentTracker = 0; //
  G4int R6_AdjacentTracker = 0; //
  G4int R7_AdjacentTracker = 0; //
  G4int R8_AdjacentTracker = 0; //

 
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);

  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();

  ctrackID = -1;

  G4int NumTracks = TrackingReadout->GetNumTracks();
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  TrackData *track;
  for(int t = 0; t < NumTracks; t++){

    R1Hit = 0, R2Hit = 0, R3Hit = 0, R4Hit = 0, R5Hit = 0, R6Hit = 0, R7Hit = 0, R8Hit = 0, ScintHit = 0, GEM1Hit = 0, GEM2Hit = 0;
    PMThit = 0; //Seems to not be used
    
    analysis->MOLLERMainEvent->MOLLERDetectorEvent.Initialize();  

    track  = TrackingReadout->GetTrackData(t);
    if(track){

      analysis->MOLLERMainEvent->MOLLERDetectorEvent.SetEventID(evt->GetEventID());
      analysis->MOLLERMainEvent->MOLLERDetectorEvent.SetTrackParentID(track->ParentID);      
      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,track->InitMomDirZ);      

      
      if(track->Particle == myBeam){
	      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddElectronTrackID(track->ID);
        //G4cout << track->ID << G4endl; //Original particle has ID = 1
	      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPhotonTrackID(0);
        if(track->ID == 1){
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddInitialBeamEnergy(track->InitKinEnergy/GeV);
          InitialBeamAngle = asin(sqrt(pow(track->InitMomDirX,2) + pow(track->InitMomDirY,2)))*180./TMath::Pi();
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddInitialBeamAngle(InitialBeamAngle);
        }

        if(track->R1QuartzHitFlag & (track->ID == 1)){
          R1Hit = 1;
          R1XHit = track->R1QuartzHitX/mm;
          R1YHit = track->R1QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionX((Float_t)track->R1QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionY((Float_t)track->R1QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionZ((Float_t)track->R1QuartzHitZ/cm);
          //G4cout << "RING 1" << track->R1QuartzHitFlag << G4endl;
        }
        	if(track->R2QuartzHitFlag & (track->ID == 1)){
          R2Hit = 1;
          R2XHit = track->R2QuartzHitX/mm;
          R2YHit = track->R2QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionX((Float_t)track->R2QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionY((Float_t)track->R2QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionZ((Float_t)track->R2QuartzHitZ/cm);
        }
        if(track->R3QuartzHitFlag & (track->ID == 1)){
          R3Hit = 1;
          R3XHit = track->R3QuartzHitX/mm;
          R3YHit = track->R3QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionX((Float_t)track->R3QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionY((Float_t)track->R3QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionZ((Float_t)track->R3QuartzHitZ/cm);
        }
        if(track->R4QuartzHitFlag & (track->ID == 1)){
          R4Hit = 1;
          R4XHit = track->R4QuartzHitX/mm;
          R4YHit = track->R4QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionX((Float_t)track->R4QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionY((Float_t)track->R4QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionZ((Float_t)track->R4QuartzHitZ/cm);
        }
        if(track->R5QuartzHitFlag & (track->ID == 1)){
          R5Hit = 1;
          R5XHit = track->R5QuartzHitX/mm;
          R5YHit = track->R5QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionX((Float_t)track->R5QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionY((Float_t)track->R5QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionZ((Float_t)track->R5QuartzHitZ/cm);
        }
        if(track->R6QuartzHitFlag & (track->ID == 1)){
          R6Hit = 1;
          R6XHit = track->R6QuartzHitX/mm;
          R6YHit = track->R6QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionX((Float_t)track->R6QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionY((Float_t)track->R6QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionZ((Float_t)track->R6QuartzHitZ/cm);
        }
        if(track->R7QuartzHitFlag & (track->ID == 1)){
          R7Hit = 1;
          R7XHit = track->R7QuartzHitX/mm;
          R7YHit = track->R7QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionX((Float_t)track->R7QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionY((Float_t)track->R7QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionZ((Float_t)track->R7QuartzHitZ/cm);
        }
        if(track->R8QuartzHitFlag & (track->ID == 1)){
          R8Hit = 1;
          R8XHit = track->R8QuartzHitX/mm;
          R8YHit = track->R8QuartzHitY/mm;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionX((Float_t)track->R8QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionY((Float_t)track->R8QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionZ((Float_t)track->R8QuartzHitZ/cm);
        }
        if(track->ScintHitFlag & (track->ID == 1) ){
          ScintHit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionX((Float_t)track->ScintHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionY((Float_t)track->ScintHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionZ((Float_t)track->ScintHitZ/cm);
        }
        if(track->GEMScint1HitFlag & (track->ID == 1)){
          GEM1Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionX((Float_t)track->GEMScint1HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionY((Float_t)track->GEMScint1HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionZ((Float_t)track->GEMScint1HitZ/cm);
        }
        if(track->GEMScint2HitFlag & (track->ID == 1)){
          GEM2Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionX((Float_t)track->GEMScint2HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionY((Float_t)track->GEMScint2HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionZ((Float_t)track->GEMScint2HitZ/cm);
        }
        if((ScintHit == 1)){
          Scint_Tracker = 1;
          if(R1Hit==1) R1_Tracker = 1;
          if(R2Hit==1) R2_Tracker = 1;
          if(R3Hit==1) R3_Tracker = 1;
          if(R4Hit==1) R4_Tracker = 1;
          if(R5Hit==1) R5_Tracker = 1;
          if(R6Hit==1) R6_Tracker = 1;
          if(R7Hit==1) R7_Tracker = 1;
          if(R8Hit==1) R8_Tracker = 1;
          if((GEM1Hit==1) & (GEM2Hit==1)) GEM_Tracker = 1;
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
          if((R5Hit==0) & (R6Hit==1) & (R8Hit==0)) R6_AdjacentTracker = 1;
          if((R5Hit==0) & (R7Hit==1) & (R8Hit==0)) R7_AdjacentTracker = 1;
          if((R5Hit==0) & (R8Hit==1)) R8_AdjacentTracker = 1;
        }
        for(int p = 0; p < track->StepNChPhotons.size(); p++){
          // analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzStepNPhotons(track->StepNChPhotons[p]);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzElectronStepLength(track->StepLength[p]/cm);
        }
        for(int p = 0; p < track->SecPhotonAngle.size(); p++)
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
      }
      if(track->Particle == myPhoton){
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPhotonTrackID(track->ID);	
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddElectronTrackID(0);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzTrackData(track->QLength/cm, track->QSteps);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzPhotonEnergy(track->InitKinEnergy/eV);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzPhotonAtExitFlag(track->QExitFlag);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddLightGuideTrackData(track->LGLength/cm, track->LGSteps);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTTrackHit(track->PMTHitFlag);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddLightGuideTrackHit(track->LGHitFlag);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTPhotonEnergy(track->InitKinEnergy/eV);
        analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddLightGuidePhotonEnergy(track->InitKinEnergy/eV);
        QuartzSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
        if(track->QExitFlag)
          LightGuideSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
        if(track->PMTHitFlag){
          //G4cout << "PHOTON" << G4endl;
          PMTSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTHitPositionX((Float_t)track->PMTHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTHitPositionY((Float_t)track->PMTHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTHitPositionZ((Float_t)track->PMTHitZ/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTWindowReflectionAngle((Float_t)track->PMTWinRefl);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTPhotonEnergy(track->InitKinEnergy/eV);
          optPhEng = track->InitKinEnergy/eV;
          OptParam* op = TrackingReadout->GetOpticalParameters();
          /*for(int n = 0; n < op->npar-1; n++){
            if(optPhEng >= op->EPhoton[n]/eV && optPhEng < op->EPhoton[n+1]/eV){
              if(track->PMTHitZ/cm > 120){
                R1pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(100 < track->PMTHitZ/cm && track->PMTHitZ/cm < 120){
                R2pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(70 < track->PMTHitZ/cm && track->PMTHitZ/cm < 90){
                R3pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(45 < track->PMTHitZ/cm && track->PMTHitZ/cm < 70){
                R4pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(5 < track->PMTHitZ/cm && track->PMTHitZ/cm < 15){
                R5pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(15 < track->PMTHitZ/cm && track->PMTHitZ/cm < 35 && track->PMTHitX/cm < 0){
                R6pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(15 < track->PMTHitZ/cm && track->PMTHitZ/cm < 35 && track->PMTHitX/cm > 0){
                R7pes += gRandom->PoissonD(op->QEff[n]);
              }
              if(track->PMTHitZ/cm < 5){
                R8pes += gRandom->PoissonD(op->QEff[n]);
              }
            }
          }*/
          PMThit++;
        }
          
        for(int s = 0; s < track->NSteps; s++){
          if(track->StepVolume[s] == myQuartz){
            analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzStepLength(track->StepLength[s]/cm);
            analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzIncidentPhotonAngle(track->StepAngle[s]);
          }
          if(track->StepVolume[s] == myLightGuide){
            analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddLightGuideStepLength(track->StepLength[s]/cm);
            analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddLightGuideIncidentPhotonAngle(track->StepAngle[s]);
          }
        }
        
      }
    }
    //Storing PEs
    R1pes = TrackingReadout->R1_GetCathodeDetections();
    R2pes = TrackingReadout->R2_GetCathodeDetections();
    R3pes = TrackingReadout->R3_GetCathodeDetections();
    R4pes = TrackingReadout->R4_GetCathodeDetections();
    R5pes = TrackingReadout->R5_GetCathodeDetections();
    R6pes = TrackingReadout->R6_GetCathodeDetections();
    R7pes = TrackingReadout->R7_GetCathodeDetections();
    R8pes = TrackingReadout->R8_GetCathodeDetections();
    //Stores data in root for specific  detectors. Used to control amount of data that is saved for large simulations
    //This also stores PEs as variables at the end of the event (specifically during the last track to prevent overwrite)
    if(Det == 0){
      if(track->ID == 1){
        if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1pes);
        if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2pes);
        if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3pes);
        if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4pes);
        if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5pes);
        if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6pes);
        if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7pes);
        if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8pes);
        if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1pes);
        if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2pes);
        if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3pes);
        if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4pes);
        if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5pes);
        if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6pes);
        if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7pes);
        if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8pes);
      }
      analysis->FillRootNtuple();
    }
    if(Det == 1){
      if((R1_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1pes);
      if(R1_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 2){
      if((R2_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2pes);
      if(R2_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 3){
      if((R3_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3pes);
      if(R3_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 4){
      if((R4_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4pes);
      if(R4_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 5){
      if((R5_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5pes);
      if(R5_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 6){
      if((R6_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6pes);
      if(R6_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 7){
      if((R7_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7pes);
      if(R7_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 8){
      if((R8_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8pes);
      if(R8_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 9){
      if(Scint_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8pes);
        }
        analysis->FillRootNtuple();
      }
    }
    if(Det == 10 || Det == 11){
      if(GEM_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8pes);
        }
        analysis->FillRootNtuple();
      }
    }
  }
  //Stores PEs if Scint has been hit
  if(R1_Tracker == 1){
    analysis->R1_AddCathodeDetectionEvent(R1pes);
    analysis->R1_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R1_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R1_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R1_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R1_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R1_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R1_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R2_Tracker == 1){
    analysis->R2_AddCathodeDetectionEvent(R2pes);
    analysis->R2_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R2_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R2_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R2_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R2_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R2_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R2_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R3_Tracker == 1){
    analysis->R3_AddCathodeDetectionEvent(R3pes);
    analysis->R3_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R3_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R3_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R3_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R3_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R3_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R3_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R4_Tracker == 1){
    analysis->R4_AddCathodeDetectionEvent(R4pes);
    analysis->R4_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R4_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R4_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R4_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R4_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R4_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R4_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R5_Tracker == 1){
    analysis->R5_AddCathodeDetectionEvent(R5pes);
    analysis->R5_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R5_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R5_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R5_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R5_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R5_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R5_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R6_Tracker == 1){
    analysis->R6_AddCathodeDetectionEvent(R6pes);
    analysis->R6_AddInitialBeamAngleHist(InitialBeamAngle);
  }
  if(R7_Tracker == 1){
    analysis->R7_AddCathodeDetectionEvent(R7pes);
    analysis->R7_AddInitialBeamAngleHist(InitialBeamAngle);
  }
  if(R8_Tracker == 1){
    analysis->R8_AddCathodeDetectionEvent(R8pes);
    analysis->R8_AddInitialBeamAngleHist(InitialBeamAngle);
    if(R1XHit != 999) analysis->R8_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R8_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R8_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R8_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R8_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R8_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  //Stores PEs if Scint & one tile have been hit
  if(R1_SoloTracker == 1){
    analysis->R1Only_AddCathodeDetectionEvent(R1pes);
    analysis->R1Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R1Only_AddR1QuartzHitPos(R1XHit,R1YHit);
  }
  if(R2_SoloTracker == 1){
    analysis->R2Only_AddCathodeDetectionEvent(R2pes);
    analysis->R2Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R2Only_AddR2QuartzHitPos(R2XHit,R2YHit);
  }
  if(R3_SoloTracker == 1){
    analysis->R3Only_AddCathodeDetectionEvent(R3pes);
    analysis->R3Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R3Only_AddR3QuartzHitPos(R3XHit,R3YHit);
  }
  if(R4_SoloTracker == 1){
    analysis->R4Only_AddCathodeDetectionEvent(R4pes);
    analysis->R4Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R4Only_AddR4QuartzHitPos(R4XHit,R4YHit);
  }
  if(R5_SoloTracker == 1){
    analysis->R5Only_AddCathodeDetectionEvent(R5pes);
    analysis->R5Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R5Only_AddR5QuartzHitPos(R5XHit,R5YHit);
  }
  if(R6_SoloTracker == 1){
    analysis->R6Only_AddCathodeDetectionEvent(R6pes);
    analysis->R6Only_AddInitialBeamAngleHist(InitialBeamAngle);
  }
  if(R7_SoloTracker == 1){
    analysis->R7Only_AddCathodeDetectionEvent(R7pes);
    analysis->R7Only_AddInitialBeamAngleHist(InitialBeamAngle);
  }
  if(R8_SoloTracker == 1){
    analysis->R8Only_AddCathodeDetectionEvent(R8pes);
    analysis->R8Only_AddInitialBeamAngleHist(InitialBeamAngle);
    analysis->R8Only_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  //Stores PEs if adjacent tiles have not been hit
  if(R1_AdjacentTracker == 1){
    analysis->R1Adjacent_AddCathodeDetectionEvent(R1pes);
    if(R1XHit != 999) analysis->R1Adjacent_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R3XHit != 999) analysis->R1Adjacent_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R1Adjacent_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R1Adjacent_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R1Adjacent_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R2_AdjacentTracker == 1){
    analysis->R2Adjacent_AddCathodeDetectionEvent(R2pes);
    if(R2XHit != 999) analysis->R2Adjacent_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R4XHit != 999) analysis->R2Adjacent_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R5XHit != 999) analysis->R2Adjacent_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R2Adjacent_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R3_AdjacentTracker == 1){
    analysis->R3Adjacent_AddCathodeDetectionEvent(R3pes);
    if(R1XHit != 999) analysis->R3Adjacent_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R3XHit != 999) analysis->R3Adjacent_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R5XHit != 999) analysis->R3Adjacent_AddR5QuartzHitPos(R5XHit,R5YHit);
    if(R8XHit != 999) analysis->R3Adjacent_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R4_AdjacentTracker == 1){
    analysis->R4Adjacent_AddCathodeDetectionEvent(R4pes);
    if(R1XHit != 999) analysis->R4Adjacent_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R4Adjacent_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R4XHit != 999) analysis->R4Adjacent_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R8XHit != 999) analysis->R4Adjacent_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  if(R5_AdjacentTracker == 1){
    analysis->R5Adjacent_AddCathodeDetectionEvent(R5pes);
    analysis->R5Adjacent_AddR1QuartzHitPos(R1XHit,R1YHit);
    analysis->R5Adjacent_AddR2QuartzHitPos(R2XHit,R2YHit);
    analysis->R5Adjacent_AddR3QuartzHitPos(R3XHit,R3YHit);
    analysis->R5Adjacent_AddR5QuartzHitPos(R5XHit,R5YHit);
  }
  if(R6_AdjacentTracker == 1){
    analysis->R6Adjacent_AddCathodeDetectionEvent(R6pes);
  }
  if(R7_AdjacentTracker == 1){
    analysis->R7Adjacent_AddCathodeDetectionEvent(R7pes);
  }
  if(R8_AdjacentTracker == 1){
    analysis->R8Adjacent_AddCathodeDetectionEvent(R8pes);
    if(R1XHit != 999) analysis->R8Adjacent_AddR1QuartzHitPos(R1XHit,R1YHit);
    if(R2XHit != 999) analysis->R8Adjacent_AddR2QuartzHitPos(R2XHit,R2YHit);
    if(R3XHit != 999) analysis->R8Adjacent_AddR3QuartzHitPos(R3XHit,R3YHit);
    if(R4XHit != 999) analysis->R8Adjacent_AddR4QuartzHitPos(R4XHit,R4YHit);
    if(R8XHit != 999) analysis->R8Adjacent_AddR8QuartzHitPos(R8XHit,R8YHit);
  }
  //
  if(Scint_Tracker == 0) analysis->NoHit_AddInitialBeamAngleHist(InitialBeamAngle);
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
