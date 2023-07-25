#include "MOLLEROptPMTSD7.hh"

MOLLEROptPMTSD7::MOLLEROptPMTSD7(G4String name, MOLLEROptTrackingReadout7* TrRO7)
  :G4VSensitiveDetector(name)
{
  TrackingReadout7 = TrRO7;
  theCollectionName = G4String("PMTHitCollection");

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
}

MOLLEROptPMTSD7::~MOLLEROptPMTSD7()
{

}

void MOLLEROptPMTSD7::Initialize(G4HCofThisEvent* HCE)
{
  HitsCollection7 = new MOLLEROptPMTHitsCollection7(SensitiveDetectorName,collectionName[0]);
  theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
  
  HCE->AddHitsCollection(theCollectionID , HitsCollection7);
}

G4bool MOLLEROptPMTSD7::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
{
  G4String procName = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();   
  G4StepStatus status = aStep->GetPostStepPoint()->GetStepStatus();   

  G4TouchableHandle touchable = aStep->GetPostStepPoint()->GetTouchableHandle();
  G4ThreeVector worldpos = aStep->GetPreStepPoint()->GetPosition();
  G4ThreeVector localpos = touchable->GetHistory()->GetTopTransform().TransformPoint(worldpos);

  G4StepPoint *preStep = aStep->GetPreStepPoint();
  G4StepPoint *postStep = aStep->GetPostStepPoint();
  
  G4ProcessManager* OpManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
  G4int MAXofPostStepLoops = OpManager->GetPostStepProcessVector()->entries();
  G4ProcessVector* postStepDoItVector = OpManager->GetPostStepProcessVector(typeDoIt);
  G4VProcess* currentProcess;
  G4OpBoundaryProcessStatus theStatus = Undefined;
  G4double incidentAngle = -180;

  if(aStep->GetTrack()->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
      
    // if(procName.compare("Transportation") == 0){
      

      if(status == fGeomBoundary){
	
	// MOLLEROptPMTHit* aHit = new MOLLEROptPMTHit();
	
	// if(aHit){
	//   aHit->AddPhotonHit(localpos,aStep->GetTrack()->GetKineticEnergy());
	//   aHit->StoreTrackID(aStep->GetTrack()->GetTrackID());
	//   aHit->SetParticleType(10);

	for (G4int i=0; i<MAXofPostStepLoops; ++i) {
	  currentProcess = (*postStepDoItVector)[i];
	  G4OpBoundaryProcess* opProc = dynamic_cast<G4OpBoundaryProcess*>(currentProcess);
	  if (opProc) {
	    theStatus = opProc->GetStatus();
	    
	    if(theStatus == FresnelReflection ||
	       theStatus == TotalInternalReflection ||
	       theStatus == LambertianReflection ||
	       theStatus == LobeReflection ||
	       theStatus == SpikeReflection){
	      
	      G4ThreeVector imom = preStep->GetMomentumDirection();
	      G4ThreeVector fmom = -1.0*postStep->GetMomentumDirection();
	      //G4double tmpA = TMath::ACos(imom.dot(fmom));
	      
	      incidentAngle = 90.0 - 180*0.5*(1 - TMath::ACos(imom.dot(fmom))/TMath::Pi());
	      
	      // aHit->StoreStepLength(aStep->GetStepLength());
	      // aHit->StoreTrackID(aStep->GetTrack()->GetTrackID());
	      // aHit->SetParticleType(10); //photon
	      // aHit->StorePhotonEnergy(aStep->GetTrack()->GetKineticEnergy());
	      // aHit->StoreIncidentPhotonAngle(incidentAngle);
	      // aHit->StoreReflectionProcess(theStatus);
	      // HitsCollection7->insert(aHit);
	      //TrackingReadout7->SetPMTWindowReflection(incidentAngle);

	    }	
	  }
	}

	
	  TrackingReadout7->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
					aStep->GetStepLength(),-1,1,myPMT,0,
					aStep->GetTrack()->GetKineticEnergy(),
					1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),0);
	  
	  TrackingReadout7->SetPMTHitLocation(aStep->GetTrack()->GetTrackID(),localpos,incidentAngle);
	  //HitsCollection7->insert(aHit); 
	// }
      // }

    }
  }
  return true;
}

void MOLLEROptPMTSD7::EndOfEvent(G4HCofThisEvent* )
{

}
