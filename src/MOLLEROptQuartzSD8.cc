#include "MOLLEROptQuartzSD8.hh"

MOLLEROptQuartzSD8::MOLLEROptQuartzSD8(G4String name, MOLLEROptTrackingReadout8* TrRO8)
  :G4VSensitiveDetector(name)
{
  TrackingReadout8 = TrRO8;
  theCollectionName = G4String("QuartzHitCollection");

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
}

MOLLEROptQuartzSD8::~MOLLEROptQuartzSD8()
{

}

void MOLLEROptQuartzSD8::Initialize(G4HCofThisEvent* HCE)
{
  HitsCollection8 = new MOLLEROptQuartzHitsCollection8(SensitiveDetectorName,collectionName[0]);
  theCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
  
  HCE->AddHitsCollection(theCollectionID , HitsCollection8);
}

G4bool MOLLEROptQuartzSD8::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
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

  MOLLEROptQuartzHit8* aHit = new MOLLEROptQuartzHit8();

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

	    // G4cout << "Exit after step: " << TrackingReadout8->GetStepInQuartz(aStep->GetTrack()->GetTrackID()) << G4endl;
	    
	    aHit->SetPhotonAtExit(1);
	    QEx = 1;
	    
	  }
	  if((postStep->GetPhysicalVolume()->GetName().contains("Ring5_Physical") ||
	      postStep->GetPhysicalVolume()->GetName().contains("LG_Physical") )&&
	     preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")){
	    incidentAngle = 90.0 - 180*0.5*(1 - acos(imom.dot(fmom))/TMath::Pi());
	  }  
	}
	
	TrackingReadout8->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
				      aStep->GetStepLength(),QEx,0,myQuartz,0,
				      aStep->GetTrack()->GetKineticEnergy(),
				      1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),
				      incidentAngle);
	// G4cout << "Quartz Incident Angle: " << incidentAngle << G4endl;	  
	
	HitsCollection8->insert(aHit); 
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
      // 	// TrackingReadout8->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
      // 	// 			      aStep->GetStepLength(),0,0,myQuartz,0,
      // 	// 			      aStep->GetTrack()->GetKineticEnergy(),0,0);
      // }
      if((*Secondaries)[n]->GetDefinition() ==  G4OpticalPhoton::OpticalPhotonDefinition() && (*Secondaries)[n]->GetCreatorProcess()->GetProcessName().contains("Cerenkov")){

	G4ThreeVector secmom = (*Secondaries)[n]->GetMomentumDirection();
	// std::cout << "Secondary mom dir: " << secmom.x() << ", " << secmom.y() << ", " << secmom.z() << ", " << secmom.mag() << ", "  << 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi() << std::endl;	  
	Float_t Angle = 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi();
	TrackingReadout8->AddSecPhoton(aStep->GetTrack()->GetTrackID(),Angle,1239.842/((*Secondaries)[n]->GetTotalEnergy()/eV));
	if(preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")) nsec++;
      }
    }
    TrackingReadout8->AddTrackData(aStep->GetTrack()->GetTrackID(),myElectron,
				  aStep->GetStepLength(),0,0,myQuartz,0,
				  aStep->GetTrack()->GetKineticEnergy(),0,0);
    TrackingReadout8->AddStepNCherenkovs(aStep->GetTrack()->GetTrackID(),nsec);
    TrackingReadout8->SetQuartzHitLocation(aStep->GetTrack()->GetTrackID(),worldpos);
    
  }
  
  
  return true;
}

void MOLLEROptQuartzSD8::EndOfEvent(G4HCofThisEvent* )
{

}
