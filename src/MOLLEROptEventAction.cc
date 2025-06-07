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
  G4int R1Hit, R2Hit, R3Hit, R4Hit, R5Hit, R6Hit, R7Hit, R8Hit;
  G4int R1_Tracker = 0;  //Stores whether the R1 tile has been hit this event  
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
  G4int R1_AdjacentTracker = 0; //Stores hits on R1 that do not hit R2
  G4int R2_AdjacentTracker = 0; //Stores hits on R2 that do not hit R1 or R3
  G4int R3_AdjacentTracker = 0; //Do not hit R2 or R4
  G4int R4_AdjacentTracker = 0; //Do not hit R3 or R5 FF ------}
  G4int R5_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R6_AdjacentTracker = 0; //Do not hit R4 or R6          }--- Subject to change (update as needed to include R5 BF)
  G4int R7_AdjacentTracker = 0; //Do not hit R4 or R6          }
  G4int R8_AdjacentTracker = 0; //Do not hit R5 FF       ------}

  ctrackID = -1;
  TrackData *track;
  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
  G4int NumTracks = TrackingReadout->GetNumTracks();
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  for(int t = 0; t < NumTracks; t++){

    PMThit = 0;
    R1Hit = 0, R2Hit = 0, R3Hit = 0, R4Hit = 0, R5Hit = 0, R6Hit = 0, R7Hit = 0, R8Hit = 0;
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
        if(track->ID == 1){
          if(track->R1QuartzHitFlag){
            R1Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionX((Float_t)track->R1QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionY((Float_t)track->R1QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR1QuartzHitPositionZ((Float_t)track->R1QuartzHitZ/cm);
          }
          if(track->R2QuartzHitFlag){
            R2Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionX((Float_t)track->R2QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionY((Float_t)track->R2QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR2QuartzHitPositionZ((Float_t)track->R2QuartzHitZ/cm);
          }
          if(track->R3QuartzHitFlag){
            R3Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionX((Float_t)track->R3QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionY((Float_t)track->R3QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR3QuartzHitPositionZ((Float_t)track->R3QuartzHitZ/cm);
          }
          if(track->R4QuartzHitFlag){
            R4Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionX((Float_t)track->R4QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionY((Float_t)track->R4QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR4QuartzHitPositionZ((Float_t)track->R4QuartzHitZ/cm);
          }
          if(track->R5QuartzHitFlag){
            R5Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionX((Float_t)track->R5QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionY((Float_t)track->R5QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR5QuartzHitPositionZ((Float_t)track->R5QuartzHitZ/cm);
          }
          if(track->R6QuartzHitFlag){
            R6Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionX((Float_t)track->R6QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionY((Float_t)track->R6QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR6QuartzHitPositionZ((Float_t)track->R6QuartzHitZ/cm);
          }
          if(track->R7QuartzHitFlag){
            R7Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionX((Float_t)track->R7QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionY((Float_t)track->R7QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR7QuartzHitPositionZ((Float_t)track->R7QuartzHitZ/cm);
          }
          if(track->R8QuartzHitFlag){
            R8Hit = 1;
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzTrackHit(1);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionX((Float_t)track->R8QuartzHitX/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionY((Float_t)track->R8QuartzHitY/cm);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddR8QuartzHitPositionZ((Float_t)track->R8QuartzHitZ/cm);
          }
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
    //This block can remove background events from LG's and secondary events
    //Remove if operating under the assumption that these signals are not detected
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
  }
  //Stores PEs if scintillator cuts are passed
  //The following sorting system is bulky, but it works. I will make this more space efficient at some point
  //--------BF Segment Histogram Filling--------//
  if(R1_Tracker == 1){
      analysis->R1_AddCathodeDetectionEvent(R1_pes);
  }
  if(R2_Tracker == 1){
    analysis->R2_AddCathodeDetectionEvent(R2_pes);
  }
  if(R3_Tracker == 1){
    analysis->R3_AddCathodeDetectionEvent(R3_pes);
  }
  if(R4_Tracker == 1){
    analysis->R4_AddCathodeDetectionEvent(R4_pes);
  }
  if(R5_Tracker == 1){
    analysis->R5_AddCathodeDetectionEvent(R5_pes);
  }
  if(R6_Tracker == 1){
    analysis->R6_AddCathodeDetectionEvent(R6_pes);
  }
  if(R7_Tracker == 1){
    analysis->R7_AddCathodeDetectionEvent(R7_pes);
  }
  if(R8_Tracker == 1){
    analysis->R8_AddCathodeDetectionEvent(R8_pes);
  }
  //Stores PEs if the scint cuts are passed and only one tile has been hit (Ring/Solo cuts)
  if(R1_SoloTracker == 1){
      analysis->R1Only_AddCathodeDetectionEvent(R1_pes);
  }
  if(R2_SoloTracker == 1){
    analysis->R2Only_AddCathodeDetectionEvent(R2_pes);
  }
  if(R3_SoloTracker == 1){
    analysis->R3Only_AddCathodeDetectionEvent(R3_pes);
  }
  if(R4_SoloTracker == 1){
    analysis->R4Only_AddCathodeDetectionEvent(R4_pes);
  }
  if(R5_SoloTracker == 1){
    analysis->R5Only_AddCathodeDetectionEvent(R5_pes);
  }
  if(R6_SoloTracker == 1){
    analysis->R6Only_AddCathodeDetectionEvent(R6_pes);
  }
  if(R7_SoloTracker == 1){
    analysis->R7Only_AddCathodeDetectionEvent(R7_pes);
  }
  if(R8_SoloTracker == 1){
    analysis->R8Only_AddCathodeDetectionEvent(R8_pes);
  }
  //Stores PEs if the scint cuts are passed and adjacent tiles are not hit (Adjacency cuts)
  if(R1_AdjacentTracker == 1){
    analysis->R1Adjacent_AddCathodeDetectionEvent(R1_pes);
  }
  if(R2_AdjacentTracker == 1){
    analysis->R2Adjacent_AddCathodeDetectionEvent(R2_pes);
  }
  if(R3_AdjacentTracker == 1){
    analysis->R3Adjacent_AddCathodeDetectionEvent(R3_pes);
  }
  if(R4_AdjacentTracker == 1){
    analysis->R4Adjacent_AddCathodeDetectionEvent(R4_pes);
  }
  if(R5_AdjacentTracker == 1){
    analysis->R5Adjacent_AddCathodeDetectionEvent(R5_pes);
  }
  if(R6_AdjacentTracker == 1){
    analysis->R6Adjacent_AddCathodeDetectionEvent(R6_pes);
  }
  if(R7_AdjacentTracker == 1){
    analysis->R7Adjacent_AddCathodeDetectionEvent(R7_pes);
  }
  if(R8_AdjacentTracker == 1){
    analysis->R8Adjacent_AddCathodeDetectionEvent(R8_pes);
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
