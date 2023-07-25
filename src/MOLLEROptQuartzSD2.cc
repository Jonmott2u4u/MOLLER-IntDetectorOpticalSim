#include "MOLLEROptQuartzSD2.hh"

MOLLEROptQuartzSD2::MOLLEROptQuartzSD2(G4String name, MOLLEROptTrackingReadout2* TrRO2)
  :G4VSensitiveDetector(name)
{
  TrackingReadout2 = TrRO2;
  theCollectionName = G4String("QuartzHitCollection");

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
}

MOLLEROptQuartzSD2::~MOLLEROptQuartzSD2()
{

}

void MOLLEROptQuartzSD2::Initialize(G4HCofThisEvent* HCE)
{
  HitsCollection2 = new MOLLEROptQuartzHitsCollection2(SensitiveDetectorName,collectionName[0]);
  theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
  
  HCE->AddHitsCollection(theCollectionID , HitsCollection2);
}

G4bool MOLLEROptQuartzSD2::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
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

  MOLLEROptQuartzHit2* aHit = new MOLLEROptQuartzHit2();

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

	    // G4cout << "Exit after step: " << TrackingReadout2->GetStepInQuartz(aStep->GetTrack()->GetTrackID()) << G4endl;
	    
	    aHit->SetPhotonAtExit(1);
	    QEx = 1;
	    
	  }
	  if((postStep->GetPhysicalVolume()->GetName().contains("Ring5_Physical") ||
	      postStep->GetPhysicalVolume()->GetName().contains("LG_Physical") )&&
	     preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")){
	    incidentAngle = 90.0 - 180*0.5*(1 - acos(imom.dot(fmom))/TMath::Pi());
	  }  
	}
	
	TrackingReadout2->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
				      aStep->GetStepLength(),QEx,0,myQuartz,0,
				      aStep->GetTrack()->GetKineticEnergy(),
				      1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),
				      incidentAngle);
	// G4cout << "Quartz Incident Angle: " << incidentAngle << G4endl;	  
	
	HitsCollection2->insert(aHit); 
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
      // 	// TrackingReadout2->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
      // 	// 			      aStep->GetStepLength(),0,0,myQuartz,0,
      // 	// 			      aStep->GetTrack()->GetKineticEnergy(),0,0);
      // }
      if((*Secondaries)[n]->GetDefinition() ==  G4OpticalPhoton::OpticalPhotonDefinition() && (*Secondaries)[n]->GetCreatorProcess()->GetProcessName().contains("Cerenkov")){

	G4ThreeVector secmom = (*Secondaries)[n]->GetMomentumDirection();
	// std::cout << "Secondary mom dir: " << secmom.x() << ", " << secmom.y() << ", " << secmom.z() << ", " << secmom.mag() << ", "  << 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi() << std::endl;	  
	Float_t Angle = 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi();
	TrackingReadout2->AddSecPhoton(aStep->GetTrack()->GetTrackID(),Angle,1239.842/((*Secondaries)[n]->GetTotalEnergy()/eV));
	if(preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")) nsec++;
      }
    }
    TrackingReadout2->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
				  aStep->GetStepLength(),0,0,myQuartz,0,
				  aStep->GetTrack()->GetKineticEnergy(),0,0);
    TrackingReadout2->AddStepNCherenkovs(aStep->GetTrack()->GetTrackID(),nsec);
    TrackingReadout2->SetQuartzHitLocation(aStep->GetTrack()->GetTrackID(),worldpos);
    
  }
  
  
  return true;
}

void MOLLEROptQuartzSD2::EndOfEvent(G4HCofThisEvent* )
{

}
