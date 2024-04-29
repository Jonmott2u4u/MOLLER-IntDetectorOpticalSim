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
  
  G4float InitialBeamAngle = 25;
  G4double LGTrackLength, QuartzTrackLength, TotalTrackLength;
  G4double R1_pes = 0, R2_pes = 0, R3_pes = 0, R4_pes = 0, R5_pes = 0, R6_pes = 0, R7_pes = 0, R8_pes = 0;
  G4int hitCnt1, hitCnt2, PMThit, qtrackID, lgtrackID, pmttrackID, ctrackID, LGSteps, QSteps, TSteps, secPhCnt;
  G4int R1Hit, R2Hit, R3Hit, R4Hit, R5Hit, R6Hit, R7Hit, R8Hit, Scint1Hit, Scint2Hit, Scint3Hit, Scint4Hit; //Tracks whether a detector's quartz tile has been hit in a given event
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
  G4int Scint1_Tracker = 0;   //Stores whether the spectrum defining scintillator has been hit
  G4int Scint2_Tracker = 0;
  G4int Scint3_Tracker = 0;
  G4int Scint4_Tracker = 0;
  G4int Scint13_Tracker = 0;
  G4int Scint14_Tracker = 0;
  G4int Scint23_Tracker = 0;
  G4int Scint24_Tracker = 0;

 
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);

  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();

  ctrackID = -1;

  G4int NumTracks = TrackingReadout->GetNumTracks();
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  TrackData *track;
  for(int t = 0; t < NumTracks; t++){

    R1Hit = 0, R2Hit = 0, R3Hit = 0, R4Hit = 0, R5Hit = 0, R6Hit = 0, R7Hit = 0, R8Hit = 0, Scint1Hit = 0, Scint2Hit = 0, Scint3Hit = 0, Scint4Hit = 0;
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
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionX((Float_t)track->R1QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionY((Float_t)track->R1QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1QuartzHitPositionZ((Float_t)track->R1QuartzHitZ/cm);
          //G4cout << "RING 1" << track->R1QuartzHitFlag << G4endl;
        }
        	if(track->R2QuartzHitFlag & (track->ID == 1)){
          R2Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionX((Float_t)track->R2QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionY((Float_t)track->R2QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2QuartzHitPositionZ((Float_t)track->R2QuartzHitZ/cm);
        }
        if(track->R3QuartzHitFlag & (track->ID == 1)){
          R3Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionX((Float_t)track->R3QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionY((Float_t)track->R3QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3QuartzHitPositionZ((Float_t)track->R3QuartzHitZ/cm);
        }
        if(track->R4QuartzHitFlag & (track->ID == 1)){
          R4Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionX((Float_t)track->R4QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionY((Float_t)track->R4QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4QuartzHitPositionZ((Float_t)track->R4QuartzHitZ/cm);
        }
        if(track->R5QuartzHitFlag & (track->ID == 1)){
          R5Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionX((Float_t)track->R5QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionY((Float_t)track->R5QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5QuartzHitPositionZ((Float_t)track->R5QuartzHitZ/cm);
        }
        if(track->R6QuartzHitFlag & (track->ID == 1)){
          R6Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionX((Float_t)track->R6QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionY((Float_t)track->R6QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6QuartzHitPositionZ((Float_t)track->R6QuartzHitZ/cm);
        }
        if(track->R7QuartzHitFlag & (track->ID == 1)){
          R7Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionX((Float_t)track->R7QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionY((Float_t)track->R7QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7QuartzHitPositionZ((Float_t)track->R7QuartzHitZ/cm);
        }
        if(track->R8QuartzHitFlag & (track->ID == 1)){
          R8Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzTrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionX((Float_t)track->R8QuartzHitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionY((Float_t)track->R8QuartzHitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8QuartzHitPositionZ((Float_t)track->R8QuartzHitZ/cm);
        }
        if(track->Scint1HitFlag & (track->ID == 1) ){
          Scint1Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint1TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint1HitPositionX((Float_t)track->Scint1HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint1HitPositionY((Float_t)track->Scint1HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint1HitPositionZ((Float_t)track->Scint1HitZ/cm);
        }
        if(track->Scint2HitFlag & (track->ID == 1)){
          Scint2Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint2TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint2HitPositionX((Float_t)track->Scint2HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint2HitPositionY((Float_t)track->Scint2HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint2HitPositionZ((Float_t)track->Scint2HitZ/cm);
        }
        if(track->Scint3HitFlag & (track->ID == 1)){
          Scint3Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint3TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint3HitPositionX((Float_t)track->Scint3HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint3HitPositionY((Float_t)track->Scint3HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint3HitPositionZ((Float_t)track->Scint3HitZ/cm);
        }
        if(track->Scint4HitFlag & (track->ID == 1)){
          Scint4Hit = 1;
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint4TrackHit(1);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint4HitPositionX((Float_t)track->Scint4HitX/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint4HitPositionY((Float_t)track->Scint4HitY/cm);
          analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddScint4HitPositionZ((Float_t)track->Scint4HitZ/cm);
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
    //Storing the pes generates in each cathode. SoloTracker is reset to 0 if it fails the pe yield cuts
    R1_pes = TrackingReadout->R1_GetCathodeDetections();
    R2_pes = TrackingReadout->R2_GetCathodeDetections();
    R3_pes = TrackingReadout->R3_GetCathodeDetections();
    R4_pes = TrackingReadout->R4_GetCathodeDetections();
    R5_pes = TrackingReadout->R5_GetCathodeDetections();
    R6_pes = TrackingReadout->R6_GetCathodeDetections();
    R7_pes = TrackingReadout->R7_GetCathodeDetections();
    R8_pes = TrackingReadout->R8_GetCathodeDetections();
    if((R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R1_SoloTracker = 0;
    if((R1_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R2_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R3_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R4_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R5_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R7_pes >= 1) || (R8_pes >= 1)) R6_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R8_pes >= 1)) R7_SoloTracker = 0;
    if((R1_pes >= 1) || (R2_pes >= 1) || (R3_pes >= 1) || (R4_pes >= 1) || (R5_pes >= 1) || (R6_pes >= 1) || (R7_pes >= 1)) R8_SoloTracker = 0;
  
    //Stores data in root for specific detectors. Used to control amount of data that is saved for large simulations
    //This also stores PEs as variables at the end of the event (specifically during the last track to prevent overwrite)
    if(Det == 0){
      if(track->ID == 1){
        if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
        if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
        if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
        if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
        if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
        if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
        if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
        if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
        if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
        if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
        if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
        if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
        if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
        if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
        if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
        if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
      }
      analysis->FillRootNtuple();
    }
    if(Det == 1){
      if((R1_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
      if(R1_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 2){
      if((R2_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
      if(R2_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 3){
      if((R3_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
      if(R3_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 4){
      if((R4_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
      if(R4_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 5){
      if((R5_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
      if(R5_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 6){
      if((R6_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
      if(R6_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 7){
      if((R7_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
      if(R7_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 8){
      if((R8_Tracker == 1) && (track->ID == 1)) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
      if(R8_SoloTracker == 1){
        if(track->ID == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
        analysis->FillRootNtuple();
      }
    }
    if(Det == 9){
      if(Scint13_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    if(Det == 10){
      if(Scint14_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    if(Det == 11){
      if(Scint23_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
    if(Det == 12){
      if(Scint24_Tracker == 1){
        if(track->ID == 1){
          if(R1_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1PEs(R1_pes);
          if(R2_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2PEs(R2_pes);
          if(R3_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3PEs(R3_pes);
          if(R4_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4PEs(R4_pes);
          if(R5_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5PEs(R5_pes);
          if(R6_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6PEs(R6_pes);
          if(R7_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7PEs(R7_pes);
          if(R8_Tracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8PEs(R8_pes);
          if(R1_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR1SoloPEs(R1_pes);
          if(R2_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR2SoloPEs(R2_pes);
          if(R3_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR3SoloPEs(R3_pes);
          if(R4_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR4SoloPEs(R4_pes);
          if(R5_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR5SoloPEs(R5_pes);
          if(R6_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR6SoloPEs(R6_pes);
          if(R7_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR7SoloPEs(R7_pes);
          if(R8_SoloTracker == 1) analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddR8SoloPEs(R8_pes);
        }
        analysis->FillRootNtuple();
      }
    }
  }
  //Stores PEs if scintillator cuts are passed
  if(R1_Tracker == 1){
      analysis->R1_AddCathodeDetectionEvent(R1_pes);
      analysis->R1_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R1_Scint13_AddCathodeDetectionEvent(R1_pes);
      analysis->R1_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R1_Scint14_AddCathodeDetectionEvent(R1_pes);
      analysis->R1_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R1_Scint23_AddCathodeDetectionEvent(R1_pes);
      analysis->R1_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R1_Scint24_AddCathodeDetectionEvent(R1_pes);
      analysis->R1_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R2_Tracker == 1){
    analysis->R2_AddCathodeDetectionEvent(R2_pes);
    analysis->R2_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R2_Scint13_AddCathodeDetectionEvent(R2_pes);
      analysis->R2_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R2_Scint14_AddCathodeDetectionEvent(R2_pes);
      analysis->R2_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R2_Scint23_AddCathodeDetectionEvent(R2_pes);
      analysis->R2_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R2_Scint24_AddCathodeDetectionEvent(R2_pes);
      analysis->R2_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R3_Tracker == 1){
    analysis->R3_AddCathodeDetectionEvent(R3_pes);
    analysis->R3_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R3_Scint13_AddCathodeDetectionEvent(R3_pes);
      analysis->R3_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R3_Scint14_AddCathodeDetectionEvent(R3_pes);
      analysis->R3_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R3_Scint23_AddCathodeDetectionEvent(R3_pes);
      analysis->R3_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R3_Scint24_AddCathodeDetectionEvent(R3_pes);
      analysis->R3_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R4_Tracker == 1){
    analysis->R4_AddCathodeDetectionEvent(R4_pes);
    analysis->R4_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R4_Scint13_AddCathodeDetectionEvent(R4_pes);
      analysis->R4_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R4_Scint14_AddCathodeDetectionEvent(R4_pes);
      analysis->R4_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R4_Scint23_AddCathodeDetectionEvent(R4_pes);
      analysis->R4_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R4_Scint24_AddCathodeDetectionEvent(R4_pes);
      analysis->R4_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R5_Tracker == 1){
    analysis->R5_AddCathodeDetectionEvent(R5_pes);
    analysis->R5_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R5_Scint13_AddCathodeDetectionEvent(R5_pes);
      analysis->R5_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R5_Scint14_AddCathodeDetectionEvent(R5_pes);
      analysis->R5_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R5_Scint23_AddCathodeDetectionEvent(R5_pes);
      analysis->R5_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R5_Scint24_AddCathodeDetectionEvent(R5_pes);
      analysis->R5_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R6_Tracker == 1){
    analysis->R6_AddCathodeDetectionEvent(R6_pes);
    analysis->R6_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R6_Scint13_AddCathodeDetectionEvent(R6_pes);
      analysis->R6_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R6_Scint14_AddCathodeDetectionEvent(R6_pes);
      analysis->R6_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R6_Scint23_AddCathodeDetectionEvent(R6_pes);
      analysis->R6_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R6_Scint24_AddCathodeDetectionEvent(R6_pes);
      analysis->R6_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R7_Tracker == 1){
    analysis->R7_AddCathodeDetectionEvent(R7_pes);
    analysis->R7_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R7_Scint13_AddCathodeDetectionEvent(R7_pes);
      analysis->R7_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R7_Scint14_AddCathodeDetectionEvent(R7_pes);
      analysis->R7_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R7_Scint23_AddCathodeDetectionEvent(R7_pes);
      analysis->R7_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R7_Scint24_AddCathodeDetectionEvent(R7_pes);
      analysis->R7_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R8_Tracker == 1){
    analysis->R8_AddCathodeDetectionEvent(R8_pes);
    analysis->R8_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R8_Scint13_AddCathodeDetectionEvent(R8_pes);
      analysis->R8_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R8_Scint14_AddCathodeDetectionEvent(R8_pes);
      analysis->R8_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R8_Scint23_AddCathodeDetectionEvent(R8_pes);
      analysis->R8_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R8_Scint24_AddCathodeDetectionEvent(R8_pes);
      analysis->R8_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  //Stores PEs if the scint cuts are passed and only one tile has been hit
  if(R1_SoloTracker == 1){
      analysis->R1Only_AddCathodeDetectionEvent(R1_pes);
      analysis->R1Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R1Only_Scint13_AddCathodeDetectionEvent(R1_pes);
      analysis->R1Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R1Only_Scint14_AddCathodeDetectionEvent(R1_pes);
      analysis->R1Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R1Only_Scint23_AddCathodeDetectionEvent(R1_pes);
      analysis->R1Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R1Only_Scint24_AddCathodeDetectionEvent(R1_pes);
      analysis->R1Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R2_SoloTracker == 1){
    analysis->R2Only_AddCathodeDetectionEvent(R2_pes);
    analysis->R2Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R2Only_Scint13_AddCathodeDetectionEvent(R2_pes);
      analysis->R2Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R2Only_Scint14_AddCathodeDetectionEvent(R2_pes);
      analysis->R2Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R2Only_Scint23_AddCathodeDetectionEvent(R2_pes);
      analysis->R2Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R2Only_Scint24_AddCathodeDetectionEvent(R2_pes);
      analysis->R2Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R3_SoloTracker == 1){
    analysis->R3Only_AddCathodeDetectionEvent(R3_pes);
    analysis->R3Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R3Only_Scint13_AddCathodeDetectionEvent(R3_pes);
      analysis->R3Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R3Only_Scint14_AddCathodeDetectionEvent(R3_pes);
      analysis->R3Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R3Only_Scint23_AddCathodeDetectionEvent(R3_pes);
      analysis->R3Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R3Only_Scint24_AddCathodeDetectionEvent(R3_pes);
      analysis->R3Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R4_SoloTracker == 1){
    analysis->R4Only_AddCathodeDetectionEvent(R4_pes);
    analysis->R4Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R4Only_Scint13_AddCathodeDetectionEvent(R4_pes);
      analysis->R4Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R4Only_Scint14_AddCathodeDetectionEvent(R4_pes);
      analysis->R4Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R4Only_Scint23_AddCathodeDetectionEvent(R4_pes);
      analysis->R4Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R4Only_Scint24_AddCathodeDetectionEvent(R4_pes);
      analysis->R4Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R5_SoloTracker == 1){
    analysis->R5Only_AddCathodeDetectionEvent(R5_pes);
    analysis->R5Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R5Only_Scint13_AddCathodeDetectionEvent(R5_pes);
      analysis->R5Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R5Only_Scint14_AddCathodeDetectionEvent(R5_pes);
      analysis->R5Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R5Only_Scint23_AddCathodeDetectionEvent(R5_pes);
      analysis->R5Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R5Only_Scint24_AddCathodeDetectionEvent(R5_pes);
      analysis->R5Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R6_SoloTracker == 1){
    analysis->R6Only_AddCathodeDetectionEvent(R6_pes);
    analysis->R6Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R6Only_Scint13_AddCathodeDetectionEvent(R6_pes);
      analysis->R6Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R6Only_Scint14_AddCathodeDetectionEvent(R6_pes);
      analysis->R6Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R6Only_Scint23_AddCathodeDetectionEvent(R6_pes);
      analysis->R6Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R6Only_Scint24_AddCathodeDetectionEvent(R6_pes);
      analysis->R6Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R7_SoloTracker == 1){
    analysis->R7Only_AddCathodeDetectionEvent(R7_pes);
    analysis->R7Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R7Only_Scint13_AddCathodeDetectionEvent(R7_pes);
      analysis->R7Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R7Only_Scint14_AddCathodeDetectionEvent(R7_pes);
      analysis->R7Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R7Only_Scint23_AddCathodeDetectionEvent(R7_pes);
      analysis->R7Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R7Only_Scint24_AddCathodeDetectionEvent(R7_pes);
      analysis->R7Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if(R8_SoloTracker == 1){
    analysis->R8Only_AddCathodeDetectionEvent(R8_pes);
    analysis->R8Only_AddInitialBeamAngleHist(InitialBeamAngle);
    if(Scint13_Tracker == 1){
      analysis->R8Only_Scint13_AddCathodeDetectionEvent(R8_pes);
      analysis->R8Only_Scint13_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint14_Tracker == 1){
      analysis->R8Only_Scint14_AddCathodeDetectionEvent(R8_pes);
      analysis->R8Only_Scint14_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint23_Tracker == 1){
      analysis->R8Only_Scint23_AddCathodeDetectionEvent(R8_pes);
      analysis->R8Only_Scint23_AddInitialBeamAngleHist(InitialBeamAngle);
    }
    if(Scint24_Tracker == 1){
      analysis->R8Only_Scint24_AddCathodeDetectionEvent(R8_pes);
      analysis->R8Only_Scint24_AddInitialBeamAngleHist(InitialBeamAngle);
    }
  }
  if((Scint13_Tracker == 0) && (Scint14_Tracker == 0) && (Scint23_Tracker == 0)  && (Scint24_Tracker == 0)) analysis->NoHit_AddInitialBeamAngleHist(InitialBeamAngle);
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
