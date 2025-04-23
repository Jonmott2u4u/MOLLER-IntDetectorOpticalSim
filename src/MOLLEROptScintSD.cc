#include "MOLLEROptScintSD.hh"

MOLLEROptScintSD::MOLLEROptScintSD(G4String name, MOLLEROptTrackingReadout* TrRO)
  :G4VSensitiveDetector(name)
{
  //G4cout << "\n\n" << name << "\n\n" <<G4endl;
  TrackingReadout = TrRO;
  if(SensitiveDetectorName == "Scint1"){
    theCollectionName = G4String("ScintHitCollection1");
  }
  else if(SensitiveDetectorName == "Scint2"){
    theCollectionName = G4String("ScintHitCollection2");
  }
  else if(SensitiveDetectorName == "Scint3"){
    theCollectionName = G4String("ScintHitCollection3");
  }
  else if(SensitiveDetectorName == "Scint4"){
    theCollectionName = G4String("ScintHitCollection4");
  }

  collectionName.insert(theCollectionName); 
  theCollectionID = -1;
  
}

MOLLEROptScintSD::~MOLLEROptScintSD()
{

}

void MOLLEROptScintSD::Initialize(G4HCofThisEvent* HCE)
{
  
}

G4bool MOLLEROptScintSD::ProcessHits(G4Step* aStep, G4TouchableHistory* theTouchable)
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
  
  /*if(aStep->GetTrack()->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    if(procName.compare("Transportation") == 0){
      G4ThreeVector imom = preStep->GetMomentumDirection();
      G4ThreeVector fmom = postStep->GetMomentumDirection();
      // G4cout << "Quartz step volumes: " << preStep->GetPhysicalVolume()->GetName()<< " " << postStep->GetPhysicalVolume()->GetName() << G4endl;
      G4double incidentAngle = 360;
      G4VPhysicalVolume *vol = postStep->GetPhysicalVolume();
      if(vol){
        G4String name = vol->GetName();
        if(postStep->GetPhysicalVolume()->GetName().contains("LG_Physical")&&(
        preStep->GetPhysicalVolume()->GetName().contains("Scint")&&
        preStep->GetPhysicalVolume()->GetName().contains("Physical"))){
          QEx = 1; 
	      }
        if((postStep->GetPhysicalVolume()->GetName().contains("Ring_Physical") ||
        postStep->GetPhysicalVolume()->GetName().contains("LG_Physical"))&&(
        preStep->GetPhysicalVolume()->GetName().contains("Scint")&&
        preStep->GetPhysicalVolume()->GetName().contains("Physical"))){
          incidentAngle = 90.0 - 180*0.5*(1 - acos(imom.dot(fmom))/TMath::Pi());
        }  
      }
      TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myPhoton,
                  aStep->GetStepLength(),QEx,0,theCollectionName,myScint,0,
                  aStep->GetTrack()->GetKineticEnergy(),
                  1239.842/(aStep->GetTrack()->GetKineticEnergy()/eV),
                  incidentAngle);
    }
  }*/
  if((aStep->GetTrack()->GetDefinition() == G4Electron::ElectronDefinition()) || (aStep->GetTrack()->GetDefinition() == G4MuonMinus::MuonMinusDefinition())){
    G4ThreeVector primom = aStep->GetTrack()->GetMomentumDirection();         
    for(int n = 0; n < (*Secondaries).size(); n++){
      if((*Secondaries)[n]->GetDefinition() ==  G4OpticalPhoton::OpticalPhotonDefinition() && (*Secondaries)[n]->GetCreatorProcess()->GetProcessName().contains("Cerenkov")){
        G4ThreeVector secmom = (*Secondaries)[n]->GetMomentumDirection();
        Float_t Angle = 180.0*TMath::ACos(secmom.dot(primom))/TMath::Pi();
        TrackingReadout->AddSecPhoton(aStep->GetTrack()->GetTrackID(),Angle,1239.842/((*Secondaries)[n]->GetTotalEnergy()/eV));
	      if(preStep->GetPhysicalVolume()->GetName().contains("Scint") && preStep->GetPhysicalVolume()->GetName().contains("Physical")) nsec++;
      }
    }
    TrackingReadout->AddTrackData(aStep->GetTrack()->GetTrackID(),myBeam,
				  aStep->GetStepLength(),0,0,theCollectionName,myScint,0,
				  aStep->GetTrack()->GetKineticEnergy(),0,0);
    //TrackingReadout->AddStepNCherenkovs(aStep->GetTrack()->GetTrackID(),nsec);
    TrackingReadout->SetScintHitLocation(aStep->GetTrack()->GetTrackID(),worldpos,theCollectionName);
  }
  return true;
}

void MOLLEROptScintSD::EndOfEvent(G4HCofThisEvent* )
{

}
