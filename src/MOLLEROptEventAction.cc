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

  G4int R0_Tracker = 0, R999_Tracker = 0;

  //--------Segment Variables--------//
  G4double Ring_pes = 0;
  G4int RingHit;
  G4int Ring_Tracker = 0;  //Stores whether the tile has been hit this event  


  ctrackID = -1;
  TrackData *track;
  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
  G4int NumTracks = TrackingReadout->GetNumTracks();
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  for(int t = 0; t < NumTracks; t++){

    PMThit = 0;
    RingHit = 0;
    analysis->MOLLERMainEvent->MOLLERGeneralEvent.Initialize();  
    track  = TrackingReadout->GetTrackData(t);
    if(track){

      analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetEventID(evt->GetEventID());
      analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetTrackParentID(track->ParentID);      
      analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,track->InitMomDirZ);      

      
      if(track->Particle == myBeam){
        //--------Segment tracking--------//
        if(track->ID == 1){//Prevents secondaries from being stored
          if(track->RingQuartzHitFlag){
            RingHit = 1;
            Ring_pes = TrackingReadout->Ring_GetCathodeDetections();
            if((Det == 0) || (Det == 1)){
              analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddRingQuartzTrackHit(1);
              analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddRingQuartzHitPositionX((Float_t)track->RingQuartzHitX/cm);
              analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddRingQuartzHitPositionY((Float_t)track->RingQuartzHitY/cm);
              analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddRingQuartzHitPositionZ((Float_t)track->RingQuartzHitZ/cm);
              analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddRingPEs(Ring_pes);
            }
          }
          if(RingHit==1) Ring_Tracker = 1;
        }
        if(Det != 999){
          //G4cout << track->ID << G4endl; //Original particle has ID = 1
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddElectronTrackID(track->ID);
          analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddPhotonTrackID(0);
          if(track->ID == 1){
            InitialBeamAngle = asin(sqrt(pow(track->InitMomDirX,2) + pow(track->InitMomDirY,2)))*180./TMath::Pi();
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddInitialBeamEnergy(track->InitKinEnergy/GeV);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddInitialBeamAngle(InitialBeamAngle);
          }
          for(int p = 0; p < track->StepNChPhotons.size(); p++){
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzStepNPhotons(track->StepNChPhotons[p]);
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzElectronStepLength(track->StepLength[p]/cm);
          }
          for(int p = 0; p < track->SecPhotonAngle.size(); p++){
            analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddQuartzTrackSecPhotonAngle(track->SecPhotonAngle[p]);
          }
        }
      }
      if(track->Particle == myPhoton){
        if(Det == 0){
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
      if(Det == 0){
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetEventID(evt->GetEventID());
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.SetTrackParentID(track->ParentID);      
        analysis->MOLLERMainEvent->MOLLERGeneralEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,track->InitMomDirZ);
      }
    }  

    if(Det == 0) analysis->FillRootNtuple();
    else if((Ring_Tracker == 1) & (Det == 1)) analysis->FillRootNtuple();
    
  }
  //Stores PEs if scint cuts are passed (all events pass if no scints exist)
  //Found when opening the root file and are normally used for analysis. They currently require track->ID==1
  //--------Segment Histogram Filling--------//
  if(Ring_Tracker == 1){
      analysis->Ring_AddCathodeDetectionEvent(Ring_pes);
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
