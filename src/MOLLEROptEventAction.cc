#include "MOLLEROptEventAction.hh"

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

  CollID[0] = SDman->GetCollectionID("Quartz/QuartzHitCollection");
  CollID[1] = SDman->GetCollectionID("LightGuide/LightGuideHitCollection");
  CollID[2] = SDman->GetCollectionID("Cathode/PMTHitCollection");
  
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

  G4int hitCnt1, hitCnt2, PMThit, qtrackID, lgtrackID, pmttrackID, ctrackID, LGSteps, QSteps, TSteps, secPhCnt; 
  G4double LGTrackLength, QuartzTrackLength, TotalTrackLength;
  G4double R1_PMTPe = 0, R2_PMTPe = 0, R3_PMTPe = 0, R4_PMTPe = 0, R5_PMTPe = 0, R6_PMTPe = 0, R7_PMTPe = 0, R8_PMTPe = 0;
  G4int R1Hit, R2Hit, R3Hit, R4Hit, R5Hit, R6Hit, R7Hit, R8Hit, ScintHit, GEM1Hit, GEM2Hit; //Tracks whether a detector's quartz tile has been hit in a given event
  G4int NumSecPhotons = 0;
  G4int hitflag = 0;
  G4int R1_Tracker = 0;    
  G4int R2_Tracker = 0;    
  G4int R3_Tracker = 0;    
  G4int R4_Tracker = 0;    
  G4int R5_Tracker = 0;    
  G4int R6_Tracker = 0;    
  G4int R7_Tracker = 0;    
  G4int R8_Tracker = 0;    
  G4int Scint_Tracker = 0; 
  G4int GEM_Tracker = 0;   

 
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
      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,
									      track->InitMomDirZ);      
      
      if(track->Particle == myBeam){
	      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddElectronTrackID(track->ID);
	      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPhotonTrackID(0);

        if(track->R1QuartzHitFlag & (track->R1QuartzHitX/cm < 10000) & (track->R1QuartzHitY/cm >- 10000) & (track->R1QuartzHitY/cm < 10000) & (track->R1QuartzHitZ/cm < 500)){
          R1Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionX((Float_t)track->R1QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionY((Float_t)track->R1QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionZ((Float_t)track->R1QuartzHitZ/cm);
          //G4cout << "RING 1" << track->R1QuartzHitFlag << G4endl;
        }
        	if(track->R2QuartzHitFlag & (track->R2QuartzHitX/cm < 10000) & (track->R2QuartzHitY/cm >- 10000) & (track->R2QuartzHitY/cm < 10000) & (track->R2QuartzHitZ/cm < 500)){
          R2Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionX((Float_t)track->R2QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionY((Float_t)track->R2QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionZ((Float_t)track->R2QuartzHitZ/cm);
        }
        if(track->R3QuartzHitFlag & (track->R3QuartzHitX/cm < 10000) & (track->R3QuartzHitY/cm >- 10000) & (track->R3QuartzHitY/cm < 10000) & (track->R3QuartzHitZ/cm < 500)){
          R3Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionX((Float_t)track->R3QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionY((Float_t)track->R3QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionZ((Float_t)track->R3QuartzHitZ/cm);
        }
        if(track->R4QuartzHitFlag & (track->R4QuartzHitX/cm < 10000) & (track->R4QuartzHitY/cm >- 10000) & (track->R4QuartzHitY/cm < 10000) & (track->R4QuartzHitZ/cm < 500)){
          R4Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionX((Float_t)track->R4QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionY((Float_t)track->R4QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionZ((Float_t)track->R4QuartzHitZ/cm);
        }
        if(track->R5QuartzHitFlag & (track->R5QuartzHitX/cm < 10000) & (track->R5QuartzHitY/cm >- 10000) & (track->R5QuartzHitY/cm < 10000) & (track->R5QuartzHitZ/cm < 500)){
          R5Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionX((Float_t)track->R5QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionY((Float_t)track->R5QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionZ((Float_t)track->R5QuartzHitZ/cm);
        }
        if(track->R6QuartzHitFlag & (track->R6QuartzHitX/cm < 10000) & (track->R6QuartzHitY/cm >- 10000) & (track->R6QuartzHitY/cm < 10000) & (track->R6QuartzHitZ/cm < 500)){
          R6Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionX((Float_t)track->R6QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionY((Float_t)track->R6QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionZ((Float_t)track->R6QuartzHitZ/cm);
        }
        if(track->R7QuartzHitFlag & (track->R7QuartzHitX/cm < 10000) & (track->R7QuartzHitY/cm >- 10000) & (track->R7QuartzHitY/cm < 10000) & (track->R7QuartzHitZ/cm < 500)){
          R7Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionX((Float_t)track->R7QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionY((Float_t)track->R7QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionZ((Float_t)track->R7QuartzHitZ/cm);
        }
        if(track->R8QuartzHitFlag & (track->R8QuartzHitX/cm < 10000) & (track->R8QuartzHitY/cm >- 10000) & (track->R8QuartzHitY/cm < 10000) & (track->R8QuartzHitZ/cm < 500)){
          R8Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionX((Float_t)track->R8QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionY((Float_t)track->R8QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionZ((Float_t)track->R8QuartzHitZ/cm);
        }
        if(track->ScintHitFlag & (track->ScintHitX/cm < 10000) & (track->ScintHitY/cm >- 10000) & (track->ScintHitY/cm < 10000) & (track->ScintHitZ/cm < 500)){
          ScintHit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionX((Float_t)track->ScintHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionY((Float_t)track->ScintHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScintHitPositionZ((Float_t)track->ScintHitZ/cm);
        }
        if(track->GEMScint1HitFlag & (track->GEMScint1HitX/cm < 10000) & (track->GEMScint1HitY/cm >- 10000) & (track->GEMScint1HitY/cm < 10000) & (track->GEMScint1HitZ/cm < 500)){
          GEM1Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionX((Float_t)track->GEMScint1HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionY((Float_t)track->GEMScint1HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint1HitPositionZ((Float_t)track->GEMScint1HitZ/cm);
        }
        if(track->GEMScint2HitFlag & (track->GEMScint2HitX/cm < 10000) & (track->GEMScint2HitY/cm >- 10000) & (track->GEMScint2HitY/cm < 10000) & (track->GEMScint2HitZ/cm < 500)){
          GEM2Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionX((Float_t)track->GEMScint2HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionY((Float_t)track->GEMScint2HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddGEMScint2HitPositionZ((Float_t)track->GEMScint2HitZ/cm);
        }
        if((ScintHit == 1) /*& (Scint_Tracker != 1)*/){
          Scint_Tracker = 1;
          if((GEM1Hit==1) & (GEM2Hit==1)) GEM_Tracker = 1;
          if((R1Hit==1) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R1_Tracker = 1;
          if((R1Hit==0) & (R2Hit==1) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R2_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R4Hit==1) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R3_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==1) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R4_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==1) & (R6Hit==0) & (R7Hit==0) & (R8Hit==0)) R5_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==1) & (R7Hit==0) & (R8Hit==0)) R6_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==1) & (R8Hit==0)) R7_Tracker = 1;
          if((R1Hit==0) & (R2Hit==0) & (R3Hit==0) & (R4Hit==0) & (R5Hit==0) & (R6Hit==0) & (R7Hit==0) & (R8Hit==1)) R8_Tracker = 1;
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
	  for(int n = 0; n < op->npar-1; n++){
	    if(optPhEng >= op->EPhoton[n]/eV && optPhEng < op->EPhoton[n+1]/eV){
	      if(track->PMTHitZ/cm > 120){
          R1_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(100 < track->PMTHitZ/cm && track->PMTHitZ/cm < 120){
          R2_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(70 < track->PMTHitZ/cm && track->PMTHitZ/cm < 90){
          R3_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(50 < track->PMTHitZ/cm && track->PMTHitZ/cm < 70){
          R4_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(30 < track->PMTHitZ/cm && track->PMTHitZ/cm < 50){
          R5_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(10 < track->PMTHitZ/cm && track->PMTHitZ/cm < 30 && track->PMTHitX/cm < -4){
          R6_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(10 < track->PMTHitZ/cm && track->PMTHitZ/cm < 30 && track->PMTHitX/cm > 4){
          R7_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
        if(track->PMTHitZ/cm < 10){
          R8_PMTPe += gRandom->PoissonD(op->QEff[n]);
        }
	    }
    }
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
    if(Det == 0){
      analysis->FillRootNtuple();
    }
    if(Det == 1){
      if(R1_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 2){
      if(R2_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 3){
      if(R3_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 4){
      if(R4_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 5){
      if(R5_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 6){
      if(R6_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 7){
      if(R7_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 8){
      if(R8_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 9){
      if(Scint_Tracker == 1) analysis->FillRootNtuple();
    }
    if(Det == 10 || Det == 11){
      if(GEM_Tracker == 1) analysis->FillRootNtuple();
    }
  }
  //Stores all PEs regardless of criteria above
  /*analysis->R1_AddPhotoElectronEvent(R1_PMTPe);//Defunct
  analysis->R1_AddCathodeDetectionEvent(TrackingReadout->R1_GetCathodeDetections());
  analysis->R2_AddPhotoElectronEvent(R2_PMTPe);//Defunct
  analysis->R2_AddCathodeDetectionEvent(TrackingReadout->R2_GetCathodeDetections());
  analysis->R3_AddPhotoElectronEvent(R3_PMTPe);//Defunct
  analysis->R3_AddCathodeDetectionEvent(TrackingReadout->R3_GetCathodeDetections());
  analysis->R4_AddPhotoElectronEvent(R4_PMTPe);//Defunct
  analysis->R4_AddCathodeDetectionEvent(TrackingReadout->R4_GetCathodeDetections());
  analysis->R5_AddPhotoElectronEvent(R5_PMTPe);//Defunct
  analysis->R5_AddCathodeDetectionEvent(TrackingReadout->R5_GetCathodeDetections());
  analysis->R6_AddPhotoElectronEvent(R6_PMTPe);//Defunct
  analysis->R6_AddCathodeDetectionEvent(TrackingReadout->R6_GetCathodeDetections());
  analysis->R7_AddPhotoElectronEvent(R7_PMTPe);//Defunct
  analysis->R7_AddCathodeDetectionEvent(TrackingReadout->R7_GetCathodeDetections());
  analysis->R8_AddPhotoElectronEvent(R8_PMTPe);//Defunct
  analysis->R8_AddCathodeDetectionEvent(TrackingReadout->R8_GetCathodeDetections());*/

  //Build system for sorting PEs into histograms for e- that hit only one quartz tile. Purpose is to mimic certain cuts made on UMass cosmic stand data
  if(R1_Tracker == 1) analysis->R1Only_AddCathodeDetectionEvent(TrackingReadout->R1_GetCathodeDetections());
  if(R2_Tracker == 1) analysis->R2Only_AddCathodeDetectionEvent(TrackingReadout->R2_GetCathodeDetections());
  if(R3_Tracker == 1) analysis->R3Only_AddCathodeDetectionEvent(TrackingReadout->R3_GetCathodeDetections());
  if(R4_Tracker == 1) analysis->R4Only_AddCathodeDetectionEvent(TrackingReadout->R4_GetCathodeDetections());
  if(R5_Tracker == 1) analysis->R5Only_AddCathodeDetectionEvent(TrackingReadout->R5_GetCathodeDetections());
  if(R6_Tracker == 1) analysis->R6Only_AddCathodeDetectionEvent(TrackingReadout->R6_GetCathodeDetections());
  if(R7_Tracker == 1) analysis->R7Only_AddCathodeDetectionEvent(TrackingReadout->R7_GetCathodeDetections());
  if(R8_Tracker == 1) analysis->R8Only_AddCathodeDetectionEvent(TrackingReadout->R8_GetCathodeDetections());

  //Sorting based on whether both GEMs were hit.
  //The data is stored properly, but if Det != 0 in the macros, the numbers will appear to not add up with those saved in the root files.
  //For verification that this works, set Det = 0 before running.
  if(GEM_Tracker == 1){
    //G4cout << "HISTO" << G4endl;
    analysis->R1_AddPhotoElectronEvent(R1_PMTPe);//Defunct
    analysis->R1_AddCathodeDetectionEvent(TrackingReadout->R1_GetCathodeDetections());
    analysis->R2_AddPhotoElectronEvent(R2_PMTPe);//Defunct
    analysis->R2_AddCathodeDetectionEvent(TrackingReadout->R2_GetCathodeDetections());
    analysis->R3_AddPhotoElectronEvent(R3_PMTPe);//Defunct
    analysis->R3_AddCathodeDetectionEvent(TrackingReadout->R3_GetCathodeDetections());
    analysis->R4_AddPhotoElectronEvent(R4_PMTPe);//Defunct
    analysis->R4_AddCathodeDetectionEvent(TrackingReadout->R4_GetCathodeDetections());
    analysis->R5_AddPhotoElectronEvent(R5_PMTPe);//Defunct
    analysis->R5_AddCathodeDetectionEvent(TrackingReadout->R5_GetCathodeDetections());
    analysis->R6_AddPhotoElectronEvent(R6_PMTPe);//Defunct
    analysis->R6_AddCathodeDetectionEvent(TrackingReadout->R6_GetCathodeDetections());
    analysis->R7_AddPhotoElectronEvent(R7_PMTPe);//Defunct
    analysis->R7_AddCathodeDetectionEvent(TrackingReadout->R7_GetCathodeDetections());
    analysis->R8_AddPhotoElectronEvent(R8_PMTPe);//Defunct
    analysis->R8_AddCathodeDetectionEvent(TrackingReadout->R8_GetCathodeDetections());
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
