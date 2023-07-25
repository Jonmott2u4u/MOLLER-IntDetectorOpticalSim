#include "MOLLEROptTrackingAction.hh"

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout* TrRO)
  : TrackingReadout(TrRO) 
{

}


MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout2* TrRO2)
  : TrackingReadout2(TrRO2) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout3* TrRO3)
  : TrackingReadout3(TrRO3) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout4* TrRO4)
  : TrackingReadout4(TrRO4) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout5* TrRO5)
  : TrackingReadout5(TrRO5) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout6* TrRO6)
  : TrackingReadout6(TrRO6) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout7* TrRO7)
  : TrackingReadout7(TrRO7) 
{

}

MOLLEROptTrackingAction::MOLLEROptTrackingAction(MOLLEROptTrackingReadout8* TrRO8)
  : TrackingReadout8(TrRO8) 
{

}

MOLLEROptTrackingAction::~MOLLEROptTrackingAction()
{

}

void MOLLEROptTrackingAction::PreUserTrackingAction(const G4Track* aTrack, const G4Track* aTrack2, const G4Track* aTrack3, const G4Track* aTrack4, const G4Track* aTrack5, const G4Track* aTrack6, const G4Track* aTrack7, const G4Track* aTrack8)
{    
  if( TrackingReadout->TrackExists(aTrack->GetTrackID()) ) return;

  TrackData *nTrack = new TrackData;
  const G4VProcess *proc = aTrack->GetCreatorProcess();
  nTrack->ID = aTrack->GetTrackID();
  nTrack->ParentID = aTrack->GetParentID();

  if(aTrack->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack->Particle = myPhoton;
    // if(aTrack->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack->GetKineticEnergy() > 1.0/MeV){
    nTrack->Particle = myElectron;
    // G4cout << "ID = " << aTrack->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack->Particle = 0;
    
  nTrack->Length = 0;
  nTrack->NSteps = 0;
  nTrack->QLength = 0;
  nTrack->QSteps = 0;
  nTrack->LGLength = 0;
  nTrack->LGSteps = 0;
  nTrack->QExitFlag = 0;
  nTrack->PMTHitFlag = 0;
  nTrack->LGHitFlag = 0;
  nTrack->PMTHitX = 6666;
  nTrack->PMTHitY = 6666;
  nTrack->PMTHitZ = 6666;
  nTrack->Detected = 0;
  
  nTrack->InitEnergy = aTrack->GetTotalEnergy();
  nTrack->InitKinEnergy = aTrack->GetKineticEnergy();
  nTrack->InitWavelength = 1293.842/(aTrack->GetKineticEnergy()/eV); 
  nTrack->InitMomDirX = aTrack->GetMomentumDirection().x();
  nTrack->InitMomDirY = aTrack->GetMomentumDirection().y();
  nTrack->InitMomDirZ = aTrack->GetMomentumDirection().z();

  TrackingReadout->AddNewTrack(nTrack);

  if( TrackingReadout2->TrackExists(aTrack2->GetTrackID()) ) return;

  TrackData2 *nTrack2 = new TrackData2;
  const G4VProcess *proc2 = aTrack2->GetCreatorProcess();
  nTrack2->ID = aTrack2->GetTrackID();
  nTrack2->ParentID = aTrack2->GetParentID();

  if(aTrack2->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack2->Particle = myPhoton;
    // if(aTrack2->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc2->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack2->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack2->GetKineticEnergy() > 1.0/MeV){
    nTrack2->Particle = myElectron;
    // G4cout << "ID = " << aTrack2->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack2->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack2->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack2->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc2->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack2->Particle = 0;
    
  nTrack2->Length = 0;
  nTrack2->NSteps = 0;
  nTrack2->QLength = 0;
  nTrack2->QSteps = 0;
  nTrack2->LGLength = 0;
  nTrack2->LGSteps = 0;
  nTrack2->QExitFlag = 0;
  nTrack2->PMTHitFlag = 0;
  nTrack2->LGHitFlag = 0;
  nTrack2->PMTHitX = 6666;
  nTrack2->PMTHitY = 6666;
  nTrack2->PMTHitZ = 6666;
  nTrack2->Detected = 0;
  
  nTrack2->InitEnergy = aTrack2->GetTotalEnergy();
  nTrack2->InitKinEnergy = aTrack2->GetKineticEnergy();
  nTrack2->InitWavelength = 1293.842/(aTrack2->GetKineticEnergy()/eV); 
  nTrack2->InitMomDirX = aTrack2->GetMomentumDirection().x();
  nTrack2->InitMomDirY = aTrack2->GetMomentumDirection().y();
  nTrack2->InitMomDirZ = aTrack2->GetMomentumDirection().z();

  TrackingReadout2->AddNewTrack(nTrack2);

  if( TrackingReadout3->TrackExists(aTrack3->GetTrackID()) ) return;

  TrackData3 *nTrack3 = new TrackData3;
  const G4VProcess *proc3 = aTrack3->GetCreatorProcess();
  nTrack3->ID = aTrack3->GetTrackID();
  nTrack3->ParentID = aTrack3->GetParentID();

  if(aTrack3->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack3->Particle = myPhoton;
    // if(aTrack3->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack3->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack3->GetKineticEnergy() > 1.0/MeV){
    nTrack3->Particle = myElectron;
    // G4cout << "ID = " << aTrack3->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack3->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack3->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack3->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack3->Particle = 0;
    
  nTrack3->Length = 0;
  nTrack3->NSteps = 0;
  nTrack3->QLength = 0;
  nTrack3->QSteps = 0;
  nTrack3->LGLength = 0;
  nTrack3->LGSteps = 0;
  nTrack3->QExitFlag = 0;
  nTrack3->PMTHitFlag = 0;
  nTrack3->LGHitFlag = 0;
  nTrack3->PMTHitX = 6666;
  nTrack3->PMTHitY = 6666;
  nTrack3->PMTHitZ = 6666;
  nTrack3->Detected = 0;
  
  nTrack3->InitEnergy = aTrack3->GetTotalEnergy();
  nTrack3->InitKinEnergy = aTrack3->GetKineticEnergy();
  nTrack3->InitWavelength = 1293.842/(aTrack3->GetKineticEnergy()/eV); 
  nTrack3->InitMomDirX = aTrack3->GetMomentumDirection().x();
  nTrack3->InitMomDirY = aTrack3->GetMomentumDirection().y();
  nTrack3->InitMomDirZ = aTrack3->GetMomentumDirection().z();

  TrackingReadout3->AddNewTrack(nTrack3);

  if( TrackingReadout4->TrackExists(aTrack4->GetTrackID()) ) return;

  TrackData4 *nTrack4 = new TrackData4;
  const G4VProcess *proc4 = aTrack4->GetCreatorProcess();
  nTrack4->ID = aTrack4->GetTrackID();
  nTrack4->ParentID = aTrack4->GetParentID();

  if(aTrack4->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack4->Particle = myPhoton;
    // if(aTrack4->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack4->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack4->GetKineticEnergy() > 1.0/MeV){
    nTrack4->Particle = myElectron;
    // G4cout << "ID = " << aTrack4->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack4->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack4->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack4->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack4->Particle = 0;
    
  nTrack4->Length = 0;
  nTrack4->NSteps = 0;
  nTrack4->QLength = 0;
  nTrack4->QSteps = 0;
  nTrack4->LGLength = 0;
  nTrack4->LGSteps = 0;
  nTrack4->QExitFlag = 0;
  nTrack4->PMTHitFlag = 0;
  nTrack4->LGHitFlag = 0;
  nTrack4->PMTHitX = 6666;
  nTrack4->PMTHitY = 6666;
  nTrack4->PMTHitZ = 6666;
  nTrack4->Detected = 0;
  
  nTrack4->InitEnergy = aTrack4->GetTotalEnergy();
  nTrack4->InitKinEnergy = aTrack4->GetKineticEnergy();
  nTrack4->InitWavelength = 1293.842/(aTrack4->GetKineticEnergy()/eV); 
  nTrack4->InitMomDirX = aTrack4->GetMomentumDirection().x();
  nTrack4->InitMomDirY = aTrack4->GetMomentumDirection().y();
  nTrack4->InitMomDirZ = aTrack4->GetMomentumDirection().z();

  TrackingReadout4->AddNewTrack(nTrack4);

  if( TrackingReadout5->TrackExists(aTrack5->GetTrackID()) ) return;

  TrackData5 *nTrack5 = new TrackData5;
  const G4VProcess *proc5 = aTrack5->GetCreatorProcess();
  nTrack5->ID = aTrack5->GetTrackID();
  nTrack5->ParentID = aTrack5->GetParentID();

  if(aTrack5->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack5->Particle = myPhoton;
    // if(aTrack5->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack5->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack5->GetKineticEnergy() > 1.0/MeV){
    nTrack5->Particle = myElectron;
    // G4cout << "ID = " << aTrack5->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack5->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack5->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack5->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack5->Particle = 0;
    
  nTrack5->Length = 0;
  nTrack5->NSteps = 0;
  nTrack5->QLength = 0;
  nTrack5->QSteps = 0;
  nTrack5->LGLength = 0;
  nTrack5->LGSteps = 0;
  nTrack5->QExitFlag = 0;
  nTrack5->PMTHitFlag = 0;
  nTrack5->LGHitFlag = 0;
  nTrack5->PMTHitX = 6666;
  nTrack5->PMTHitY = 6666;
  nTrack5->PMTHitZ = 6666;
  nTrack5->Detected = 0;
  
  nTrack5->InitEnergy = aTrack5->GetTotalEnergy();
  nTrack5->InitKinEnergy = aTrack5->GetKineticEnergy();
  nTrack5->InitWavelength = 1293.842/(aTrack5->GetKineticEnergy()/eV); 
  nTrack5->InitMomDirX = aTrack5->GetMomentumDirection().x();
  nTrack5->InitMomDirY = aTrack5->GetMomentumDirection().y();
  nTrack5->InitMomDirZ = aTrack5->GetMomentumDirection().z();

  TrackingReadout5->AddNewTrack(nTrack5);

  if( TrackingReadout6->TrackExists(aTrack6->GetTrackID()) ) return;

  TrackData6 *nTrack6 = new TrackData6;
  const G4VProcess *proc6 = aTrack6->GetCreatorProcess();
  nTrack6->ID = aTrack6->GetTrackID();
  nTrack6->ParentID = aTrack6->GetParentID();

  if(aTrack6->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack6->Particle = myPhoton;
    // if(aTrack6->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack6->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack6->GetKineticEnergy() > 1.0/MeV){
    nTrack6->Particle = myElectron;
    // G4cout << "ID = " << aTrack6->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack6->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack6->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack6->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack6->Particle = 0;
    
  nTrack6->Length = 0;
  nTrack6->NSteps = 0;
  nTrack6->QLength = 0;
  nTrack6->QSteps = 0;
  nTrack6->LGLength = 0;
  nTrack6->LGSteps = 0;
  nTrack6->QExitFlag = 0;
  nTrack6->PMTHitFlag = 0;
  nTrack6->LGHitFlag = 0;
  nTrack6->PMTHitX = 6666;
  nTrack6->PMTHitY = 6666;
  nTrack6->PMTHitZ = 6666;
  nTrack6->Detected = 0;
  
  nTrack6->InitEnergy = aTrack6->GetTotalEnergy();
  nTrack6->InitKinEnergy = aTrack6->GetKineticEnergy();
  nTrack6->InitWavelength = 1293.842/(aTrack6->GetKineticEnergy()/eV); 
  nTrack6->InitMomDirX = aTrack6->GetMomentumDirection().x();
  nTrack6->InitMomDirY = aTrack6->GetMomentumDirection().y();
  nTrack6->InitMomDirZ = aTrack6->GetMomentumDirection().z();

  TrackingReadout6->AddNewTrack(nTrack6);

  if( TrackingReadout7->TrackExists(aTrack7->GetTrackID()) ) return;

  TrackData7 *nTrack7 = new TrackData7;
  const G4VProcess *proc7 = aTrack7->GetCreatorProcess();
  nTrack7->ID = aTrack7->GetTrackID();
  nTrack7->ParentID = aTrack7->GetParentID();

  if(aTrack7->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack7->Particle = myPhoton;
    // if(aTrack7->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack7->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack7->GetKineticEnergy() > 1.0/MeV){
    nTrack7->Particle = myElectron;
    // G4cout << "ID = " << aTrack7->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack7->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack7->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack7->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack7->Particle = 0;
    
  nTrack7->Length = 0;
  nTrack7->NSteps = 0;
  nTrack7->QLength = 0;
  nTrack7->QSteps = 0;
  nTrack7->LGLength = 0;
  nTrack7->LGSteps = 0;
  nTrack7->QExitFlag = 0;
  nTrack7->PMTHitFlag = 0;
  nTrack7->LGHitFlag = 0;
  nTrack7->PMTHitX = 6666;
  nTrack7->PMTHitY = 6666;
  nTrack7->PMTHitZ = 6666;
  nTrack7->Detected = 0;
  
  nTrack7->InitEnergy = aTrack7->GetTotalEnergy();
  nTrack7->InitKinEnergy = aTrack7->GetKineticEnergy();
  nTrack7->InitWavelength = 1293.842/(aTrack7->GetKineticEnergy()/eV); 
  nTrack7->InitMomDirX = aTrack7->GetMomentumDirection().x();
  nTrack7->InitMomDirY = aTrack7->GetMomentumDirection().y();
  nTrack7->InitMomDirZ = aTrack7->GetMomentumDirection().z();

  TrackingReadout7->AddNewTrack(nTrack7);

  if( TrackingReadout8->TrackExists(aTrack8->GetTrackID()) ) return;

  TrackData8 *nTrack8 = new TrackData8;
  const G4VProcess *proc8 = aTrack8->GetCreatorProcess();
  nTrack8->ID = aTrack8->GetTrackID();
  nTrack8->ParentID = aTrack8->GetParentID();

  if(aTrack8->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()){
    nTrack8->Particle = myPhoton;
    // if(aTrack8->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else if(aTrack8->GetDefinition() == G4Electron::ElectronDefinition() &&  aTrack8->GetKineticEnergy() > 1.0/MeV){
    nTrack8->Particle = myElectron;
    // G4cout << "ID = " << aTrack8->GetTrackID() << G4endl;
    // G4cout << "Parent ID = " << aTrack8->GetParentID() << G4endl;
    // G4cout << "Track Energy = " << aTrack8->GetKineticEnergy()/keV << G4endl;      
    // if(aTrack8->GetTrackID() != 1){
    //   G4cout << "Creator Process = " << proc->GetProcessName() << G4endl;
    // }
  }
  else
    nTrack8->Particle = 0;
    
  nTrack8->Length = 0;
  nTrack8->NSteps = 0;
  nTrack8->QLength = 0;
  nTrack8->QSteps = 0;
  nTrack8->LGLength = 0;
  nTrack8->LGSteps = 0;
  nTrack8->QExitFlag = 0;
  nTrack8->PMTHitFlag = 0;
  nTrack8->LGHitFlag = 0;
  nTrack8->PMTHitX = 6666;
  nTrack8->PMTHitY = 6666;
  nTrack8->PMTHitZ = 6666;
  nTrack8->Detected = 0;
  
  nTrack8->InitEnergy = aTrack8->GetTotalEnergy();
  nTrack8->InitKinEnergy = aTrack8->GetKineticEnergy();
  nTrack8->InitWavelength = 1293.842/(aTrack8->GetKineticEnergy()/eV); 
  nTrack8->InitMomDirX = aTrack8->GetMomentumDirection().x();
  nTrack8->InitMomDirY = aTrack8->GetMomentumDirection().y();
  nTrack8->InitMomDirZ = aTrack8->GetMomentumDirection().z();

  TrackingReadout8->AddNewTrack(nTrack8);
}

void MOLLEROptTrackingAction::PostUserTrackingAction(const G4Track* aTrack, const G4Track* aTrack2, const G4Track* aTrack3, const G4Track* aTrack4, const G4Track* aTrack5, const G4Track* aTrack6, const G4Track* aTrack7, const G4Track* aTrack8)
{

}

