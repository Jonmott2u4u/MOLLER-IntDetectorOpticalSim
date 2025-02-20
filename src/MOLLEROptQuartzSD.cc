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
  else if(SensitiveDetectorName == "Scintillator"){
    theCollectionName = G4String("ScintHitCollection");
  }
  else if(SensitiveDetectorName == "GEMScint1"){
    theCollectionName = G4String("GEMScint1HitCollection");
  }
  else if(SensitiveDetectorName == "GEMScint2"){
    theCollectionName = G4String("GEMScint2HitCollection");
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

  if(aStep->GetTrack()->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){

    if(procName.compare("Transportation") == 0){
      
      G4ThreeVector imom = preStep->GetMomentumDirection();
      G4ThreeVector fmom = postStep->GetMomentumDirection();
      // G4cout << "Quartz step volumes: " << preStep->GetPhysicalVolume()->GetName()<< " " << postStep->GetPhysicalVolume()->GetName() << G4endl;
      G4double incidentAngle = 360;
	
	    G4VPhysicalVolume *vol = postStep->GetPhysicalVolume();
	    if(vol){
	      G4String name = vol->GetName();
	      if(postStep->GetPhysicalVolume()->GetName().contains("LG_Physical") &&
	      preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")){
	        // G4cout << "Exit after step: " << TrackingReadout->GetStepInQuartz(aStep->GetTrack()->GetTrackID()) << G4endl;
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
      
    }
  }
  
  if((aStep->GetTrack()->GetDefinition() == G4Electron::ElectronDefinition()) || (aStep->GetTrack()->GetDefinition() == G4MuonMinus::MuonMinusDefinition())){
    G4ThreeVector primom = aStep->GetTrack()->GetMomentumDirection();  
    
    for(int n = 0; n < (*Secondaries).size(); n++){
      if((*Secondaries)[n]->GetDefinition() ==  G4OpticalPhoton::OpticalPhotonDefinition() && (*Secondaries)[n]->GetCreatorProcess()->GetProcessName().contains("Cerenkov")){

	      G4ThreeVector secmom = (*Secondaries)[n]->GetMomentumDirection();
        // std::cout << "Secondary mom dir: " << secmom.x() << ", " << secmom.y() << ", " << secmom.z() << ", " << secmom.mag() << ", "  << 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi() << std::endl;	  
        Float_t Angle = 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi();
        TrackingReadout->AddSecPhoton(aStep->GetTrack()->GetTrackID(),Angle,1239.842/((*Secondaries)[n]->GetTotalEnergy()/eV));
        if(preStep->GetPhysicalVolume()->GetName().contains("Quartz_Physical")) nsec++;
      }
    }
    TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myBeam,
				  aStep->GetStepLength(),0,0,myQuartz,0,
				  aStep->GetTrack()->GetKineticEnergy(),0,0);
    TrackingReadout->AddStepNCherenkovs(aStep->GetTrack()->GetTrackID(),nsec);
    TrackingReadout->SetQuartzHitLocation(aStep->GetTrack()->GetTrackID(),worldpos,theCollectionName);
    
  }
  
  
  return true;
}

void MOLLEROptQuartzSD::EndOfEvent(G4HCofThisEvent* )
{

}
