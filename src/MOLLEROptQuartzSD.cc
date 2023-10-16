#include "MOLLEROptQuartzSD.hh"

MOLLEROptQuartzSD::MOLLEROptQuartzSD(G4String name, MOLLEROptTrackingReadout* TrRO)
  :G4VSensitiveDetector(name)
{
  //G4cout << "\n\n" << name << "\n\n" <<G4endl;
  TrackingReadout = TrRO;
  if(SensitiveDetectorName == "Quartz"){
    theCollectionName = G4String("QuartzHitCollection");
  }
  else if(SensitiveDetectorName == "Quartz2"){
    theCollectionName = G4String("QuartzHitCollection2");
  }
  else if(SensitiveDetectorName == "Quartz3"){
    theCollectionName = G4String("QuartzHitCollection3");
  }
  else if(SensitiveDetectorName == "Quartz4"){
    theCollectionName = G4String("QuartzHitCollection4");
  }
  else if(SensitiveDetectorName == "Quartz5"){
    theCollectionName = G4String("QuartzHitCollection5");
  }
  else if(SensitiveDetectorName == "Quartz6"){
    theCollectionName = G4String("QuartzHitCollection6");
  }
  else if(SensitiveDetectorName == "Quartz7"){
    theCollectionName = G4String("QuartzHitCollection7");
  }
  else if(SensitiveDetectorName == "Quartz8"){
    theCollectionName = G4String("QuartzHitCollection8");
  }

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
  //G4cout << "\n\n" << SensitiveDetectorName<<" \n\n" << G4endl;  
  //G4cout << "\n\n" << name<<" \n\n" << G4endl;  
  
}

MOLLEROptQuartzSD::~MOLLEROptQuartzSD()
{

}

void MOLLEROptQuartzSD::Initialize(G4HCofThisEvent* HCE)
{
  //G4cout << "\n\n" << collectionName[0] <<" \n\n" << G4endl;
  if(theCollectionName == "QuartzHitCollection"){
    HitsCollection = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection);
    //G4cout << "\n\n DET 1 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection2"){
    HitsCollection2 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection2);
    //G4cout << "\n\n DET 2 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection3"){
    HitsCollection3 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection3);
    //G4cout << "\n\n DET 3 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection4"){
    HitsCollection4 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection4);
    //G4cout << "\n\n DET 4 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection5"){
    HitsCollection5 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection5);
    //G4cout << "\n\n DET 5 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection6"){
    HitsCollection6 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection6);
    //G4cout << "\n\n DET 6 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection7"){
    HitsCollection7 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection7);
    //G4cout << "\n\n DET 7 \n\n" << G4endl;
  }
  else if(theCollectionName == "QuartzHitCollection8"){
    HitsCollection8 = new MOLLEROptQuartzHitsCollection(SensitiveDetectorName,collectionName[0]);
    theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
    HCE->AddHitsCollection(theCollectionID , HitsCollection8);
    //G4cout << "\n\n DET 8 \n\n" << G4endl;
  }
    //G4cout << "\n\n Initialized \n\n" << G4endl;

}

G4bool MOLLEROptQuartzSD::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
{
  G4int QEx = 0;
  G4int nsec = 0;
  
  G4StepPoint *preStep = aStep->GetPreStepPoint();
  G4StepPoint *postStep = aStep->GetPostStepPoint();

  G4TouchableHandle touchable = postStep->GetTouchableHandle();
  G4ThreeVector worldpos = preStep->GetPosition();
  G4ThreeVector localpos = touchable->GetHistory()->GetTopTransform().TransformPoint(worldpos);

  G4String procName = postStep->GetProcessDefinedStep()->GetProcessName();   
  G4StepStatus status = postStep->GetStepStatus();   
  G4ThreeVector stepPos = preStep->GetPosition();
  Secondaries = aStep->GetSecondaryInCurrentStep();  

  MOLLEROptQuartzHit* aHit = new MOLLEROptQuartzHit();

  if(aStep->GetTrack()->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){

    if(procName.compare("Transportation") == 0){
      
      G4ThreeVector imom = preStep->GetMomentumDirection();
      G4ThreeVector fmom = postStep->GetMomentumDirection();
      // G4cout << "Quartz step volumes: " << preStep->GetPhysicalVolume()->GetName()<< " " << postStep->GetPhysicalVolume()->GetName() << G4endl;
      G4double incidentAngle = 360;
      
      if(aHit){
	aHit->StoreStepLength(aStep->GetStepLength());
	aHit->StoreTrackID(aStep->GetTrack()->GetTrackID());
	aHit->SetParticleType(10); //photons
	aHit->StorePhotonEnergy(aStep->GetTrack()->GetKineticEnergy());
	aHit->SetPhotonAtExit(0);

	// if(postStep && preStep){
	
	G4VPhysicalVolume *vol = postStep->GetPhysicalVolume();
	if(vol){
	  G4String name = vol->GetName();
	  if(postStep->GetPhysicalVolume()->GetName().contains("LG_Physical") &&
	     preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")){

	    // G4cout << "Exit after step: " << TrackingReadout->GetStepInQuartz(aStep->GetTrack()->GetTrackID()) << G4endl;
	    
	    aHit->SetPhotonAtExit(1);
	    QEx = 1;
	    
	  }
	  if((postStep->GetPhysicalVolume()->GetName().contains("Ring_Physical") ||
	      postStep->GetPhysicalVolume()->GetName().contains("LG_Physical") )&&
	     preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")){
	    incidentAngle = 90.0 - 180*0.5*(1 - acos(imom.dot(fmom))/TMath::Pi());
	  }  
	}
	
	TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
				      aStep->GetStepLength(),QEx,0,myQuartz,0,
				      aStep->GetTrack()->GetKineticEnergy(),
				      1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),
				      incidentAngle);
	// G4cout << "Quartz Incident Angle: " << incidentAngle << G4endl;	  
  	//G4cout << "\n\n" << theCollectionName <<" \n\n" << G4endl;	
	if(theCollectionName == "QuartzHitCollection"){
	  HitsCollection->insert(aHit); 
	  //G4cout << "\n\n ENTERED \n\n " << G4endl;	  
	}
	else if(theCollectionName == "QuartzHitCollection2"){
          HitsCollection2->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection3"){
          HitsCollection3->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection4"){
          HitsCollection4->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection5"){
          HitsCollection5->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection6"){
          HitsCollection6->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection7"){
          HitsCollection7->insert(aHit);
	}
	else if(theCollectionName == "QuartzHitCollection8"){
          HitsCollection8->insert(aHit);
	}
      }
    }
  }
  
  if(aStep->GetTrack()->GetDefinition() == G4Electron::ElectronDefinition()){
    

    G4ThreeVector primom = aStep->GetTrack()->GetMomentumDirection();
    // std::cout.precision(17);
    // std::cout << std::scientific; 
    // std::cout << "track mom dir: " << primom.x() << ", " << primom.y() << ", " << primom.z() << ", " << primom.mag() <<  std::endl;	  
    
    for(int n = 0; n < (*Secondaries).size(); n++){

      // if((*Secondaries)[n]->GetDefinition() == G4Electron::ElectronDefinition() &&
      // 	 (*Secondaries)[n]->GetKineticEnergy() > 1.0/MeV){
      // 	// TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
      // 	// 			      aStep->GetStepLength(),0,0,myQuartz,0,
      // 	// 			      aStep->GetTrack()->GetKineticEnergy(),0,0);
      // }
      if((*Secondaries)[n]->GetDefinition() ==  G4OpticalPhoton::OpticalPhotonDefinition() && (*Secondaries)[n]->GetCreatorProcess()->GetProcessName().contains("Cerenkov")){

	G4ThreeVector secmom = (*Secondaries)[n]->GetMomentumDirection();
	// std::cout << "Secondary mom dir: " << secmom.x() << ", " << secmom.y() << ", " << secmom.z() << ", " << secmom.mag() << ", "  << 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi() << std::endl;	  
	Float_t Angle = 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi();
	TrackingReadout->AddSecPhoton(aStep->GetTrack()->GetTrackID(),Angle,1239.842/((*Secondaries)[n]->GetTotalEnergy()/eV));
	if(preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")) nsec++;
      }
    }
    TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
				  aStep->GetStepLength(),0,0,myQuartz,0,
				  aStep->GetTrack()->GetKineticEnergy(),0,0);
    TrackingReadout->AddStepNCherenkovs(aStep->GetTrack()->GetTrackID(),nsec);
    TrackingReadout->SetQuartzHitLocation(aStep->GetTrack()->GetTrackID(),worldpos);
    
  }
  
  
  return true;
}

void MOLLEROptQuartzSD::EndOfEvent(G4HCofThisEvent* )
{

}
