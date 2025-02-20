#include "MOLLEROptEventAction.hh"

MOLLEROptEventAction::MOLLEROptEventAction(MOLLEROptAnalysis* AN, MOLLEROptTrackingReadout* TrRO)
{
  analysis    = AN;
  TrackingReadout  = TrRO;

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
  G4double PMTPe = 0;
  G4int NumSecPhotons = 0;
  G4int hitflag = 0;
 
  Float_t  optPhEng, wvl, bwdt = QuartzSecOptPhotonCnt->GetBinWidth(2);

  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();

  ctrackID = -1;

  G4int NumTracks = TrackingReadout->GetNumTracks();
  // G4cout << "Number of electron tracks = " << TrackingReadout->GetNumElectronTracks() << G4endl;
  // G4cout << "Number of photon tracks = " << TrackingReadout->GetNumPhotonTracks() << G4endl;

  TrackData *track;
  for(int t = 0; t < NumTracks; t++){

    PMThit = 0;
    
    analysis->MOLLERMainEvent->MOLLERDetectorEvent.Initialize();  

    track  = TrackingReadout->GetTrackData(t);
    if(track){

      analysis->MOLLERMainEvent->MOLLERDetectorEvent.SetEventID(evt->GetEventID());
      analysis->MOLLERMainEvent->MOLLERDetectorEvent.SetTrackParentID(track->ParentID);      
      analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddTrackInitMomDirection(track->InitMomDirX,track->InitMomDirY,
									      track->InitMomDirZ);      
      
      if(track->Particle == myElectron){
	analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddElectronTrackID(track->ID);
	analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPhotonTrackID(0);

	if(track->QuartzHitFlag){
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzTrackHit(1);
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzHitPositionX((Float_t)track->QuartzHitX/cm);
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddQuartzHitPositionY((Float_t)track->QuartzHitY/cm);
	}	
	// for(int p = 0; p < track->SecPhotonAngle.size(); p++){
	// }
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
	  PMTSecOptPhotonCnt->Fill(track->InitWavelength,1.0/(bwdt));
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTHitPositionX((Float_t)track->PMTHitX/cm);
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTHitPositionY((Float_t)track->PMTHitY/cm);
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTWindowReflectionAngle((Float_t)track->PMTWinRefl);
	  analysis->MOLLERMainEvent->MOLLERDetectorEvent.AddPMTPhotonEnergy(track->InitKinEnergy/eV);
	  optPhEng = track->InitKinEnergy/eV;
	  OptParam* op = TrackingReadout->GetOpticalParameters();
	  for(int n = 0; n < op->npar-1; n++)
	    if(optPhEng >= op->EPhoton[n]/eV && optPhEng < op->EPhoton[n+1]/eV){
	      PMTPe += gRandom->PoissonD(op->QEff[n]);
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
    analysis->FillRootNtuple();
  }

  analysis->AddPhotoElectronEvent(PMTPe);
  analysis->AddCathodeDetectionEvent(TrackingReadout->GetCathodeDetections());
  
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
