#include "MOLLEROptPMTSD.hh"

MOLLEROptPMTSD::MOLLEROptPMTSD(G4String name, MOLLEROptTrackingReadout* TrRO)
  :G4VSensitiveDetector(name)
{
  TrackingReadout = TrRO;
  if(SensitiveDetectorName == "Cathode1"){
    theCollectionName = G4String("CathodeHitCollection1");
  }
  else if(SensitiveDetectorName == "Cathode2"){
    theCollectionName = G4String("CathodeHitCollection2");
  }
  else if(SensitiveDetectorName == "Cathode3"){
    theCollectionName = G4String("CathodeHitCollection3");
  }
  else if(SensitiveDetectorName == "Cathode4"){
    theCollectionName = G4String("CathodeHitCollection4");
  }
  else if(SensitiveDetectorName == "Cathode5"){
    theCollectionName = G4String("CathodeHitCollection5");
  }
  else if(SensitiveDetectorName == "Cathode6"){
    theCollectionName = G4String("CathodeHitCollection6");
  }
  else if(SensitiveDetectorName == "Cathode7"){
    theCollectionName = G4String("CathodeHitCollection7");
  }
  else if(SensitiveDetectorName == "Cathode8"){
    theCollectionName = G4String("CathodeHitCollection8");
  }

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
}

MOLLEROptPMTSD::~MOLLEROptPMTSD()
{

}

void MOLLEROptPMTSD::Initialize(G4HCofThisEvent* HCE)
{
  if(theCollectionName == "CathodeHitCollection1"){
    HitsCollection1 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection1);
    //G4cout << "\n\n DET 1 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection2"){
    HitsCollection2 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection2);
    //G4cout << "\n\n DET 2 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection3"){
    HitsCollection3 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection3);
    //G4cout << "\n\n DET 3 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection4"){
    HitsCollection4 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection4);
    //G4cout << "\n\n DET 4 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection5"){
    HitsCollection5 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection5);
    //G4cout << "\n\n DET 5 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection6"){
    HitsCollection6 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection6);
    //G4cout << "\n\n DET 6 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection7"){
    HitsCollection7 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection7);
    //G4cout << "\n\n DET 7 \n\n" << G4endl;
  }
  else if(theCollectionName == "CathodeHitCollection8"){
    HitsCollection8 = new MOLLEROptPMTHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection8);
    //G4cout << "\n\n DET 8 \n\n" << G4endl;
  }
}

G4bool MOLLEROptPMTSD::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
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
	      // HitsCollection->insert(aHit);
	      //TrackingReadout->SetPMTWindowReflection(incidentAngle);

	    }	
	  }
	}

	
	  TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
					aStep->GetStepLength(),-1,1,myPMT,0,
					aStep->GetTrack()->GetKineticEnergy(),
					1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),0);
	  
	  //TrackingReadout->SetPMTHitLocation(aStep->GetTrack()->GetTrackID(),localpos,incidentAngle);
	  TrackingReadout->SetPMTHitLocation(aStep->GetTrack()->GetTrackID(),worldpos,incidentAngle);
	  //HitsCollection->insert(aHit); 
	// }
      // }

    }
  }
  return true;
}

void MOLLEROptPMTSD::EndOfEvent(G4HCofThisEvent* )
{

}
