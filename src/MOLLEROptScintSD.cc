#include "MOLLEROptScintSD.hh"

MOLLEROptScintSD::MOLLEROptScintSD(G4String name, MOLLEROptTrackingReadout* TrRO)
  :G4VSensitiveDetector(name)
{
  //G4cout << "\n\n" << name << "\n\n" <<G4endl;
  TrackingReadout = TrRO;
  //If you need to use scintillators in your setup, change the options here. No scintillators currently exist, so this is unused
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
  else if(SensitiveDetectorName == "Scint5"){
    theCollectionName = G4String("ScintHitCollection5");
  }
  else if(SensitiveDetectorName == "Scint6"){
    theCollectionName = G4String("ScintHitCollection6");
  }
  else if(SensitiveDetectorName == "Scint7"){
    theCollectionName = G4String("ScintHitCollection7");
  }
  else if(SensitiveDetectorName == "Scint8"){
    theCollectionName = G4String("ScintHitCollection8");
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
