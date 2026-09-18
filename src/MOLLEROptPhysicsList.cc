#include "G4Version.hh"

#include "MOLLEROptPhysicsList.hh"


MOLLEROptPhysicsList::MOLLEROptPhysicsList(G4bool toggle)
  : G4VPhysicsConstructor("Optical")
{
  theWLSProcess                = NULL;
  theScintProcess              = NULL;
  theCerenkovProcess           = NULL;
  theBoundaryProcess           = NULL;
  theAbsorptionProcess         = NULL;
  theRayleighScattering        = NULL;
  theMieHGScatteringProcess    = NULL;
  theeBremsstrahlungProcess    = NULL;
  theMuBremsstrahlungProcess   = NULL;
  
  AbsorptionOn                 = toggle;

}


MOLLEROptPhysicsList::~MOLLEROptPhysicsList()
{

}


#include "G4OpticalPhoton.hh"

void MOLLEROptPhysicsList::ConstructParticle()
{
  G4OpticalPhoton::OpticalPhotonDefinition();
}

#include "G4ProcessManager.hh"

void MOLLEROptPhysicsList::ConstructProcess()
{

  theWLSProcess = new G4OpWLS();

  theScintProcess = new G4Scintillation();
  theScintProcess->SetTrackSecondariesFirst(true);

  theCerenkovProcess = new G4Cerenkov();
  theCerenkovProcess->SetMaxNumPhotonsPerStep(5000);
  theCerenkovProcess->SetTrackSecondariesFirst(true);

  theeBremsstrahlungProcess = new G4eBremsstrahlung();
  //theeBremsstrahlungProcess->SetMaxNumPhotonsPerStep(5000);
  //theeBremsstrahlungProcess->SetTrackSecondariesFirst(true);
  theMuBremsstrahlungProcess = new G4MuBremsstrahlung();
  //theMuBremsstrahlungProcess->SetMaxNumPhotonsPerStep(5000);
  //theMuBremsstrahlungProcess->SetTrackSecondariesFirst(true);

  theAbsorptionProcess      = new G4OpAbsorption();
  theRayleighScattering     = new G4OpRayleigh();
  theMieHGScatteringProcess = new G4OpMieHG();

  theBoundaryProcess        = new MOLLEROptOpBoundaryProcess();

  G4ProcessManager* pManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
  //pManager->AddProcess(new G4UserSpecialCuts(),-1,-1,1);

  if (!pManager) {
     std::ostringstream o;
     o << "Optical Photon without a Process Manager";
     G4Exception("qsimOpticalPhysics::ConstructProcess()","",
                  FatalException,o.str().c_str());
  }

  if (AbsorptionOn) pManager->AddDiscreteProcess(theAbsorptionProcess);

  pManager->AddDiscreteProcess(theRayleighScattering);
  pManager->AddDiscreteProcess(theMieHGScatteringProcess);

  pManager->AddDiscreteProcess(theBoundaryProcess);

  theWLSProcess->UseTimeProfile("delta");

  pManager->AddDiscreteProcess(theWLSProcess);
  
  #if G4VERSION_NUMBER < 1100
  theScintProcess->SetScintillationExcitationRatio(0.0);
  #endif
  theScintProcess->SetTrackSecondariesFirst(true);

  // Use Birks Correction in the Scintillation process

  G4EmSaturation* emSaturation = G4LossTableManager::Instance()->EmSaturation();
  theScintProcess->AddSaturation(emSaturation);

  auto aParticleIterator=GetParticleIterator(); // NEW FOR GEANT4.10.4. Erase for older versions.
  aParticleIterator->reset();
  while ( (*aParticleIterator)() ){

    G4ParticleDefinition* particle = aParticleIterator->value();
    G4String particleName = particle->GetParticleName();

    pManager = particle->GetProcessManager();
    if (!pManager) {
       std::ostringstream o;
       o << "Particle " << particleName << "without a Process Manager";
       G4Exception("qsimOpticalPhysics::ConstructProcess()","",
                    FatalException,o.str().c_str());
    }

    if(theCerenkovProcess->IsApplicable(*particle)){
      pManager->AddProcess(theCerenkovProcess);
      //pManager->SetProcessOrdering(theCerenkovProcess,idxAlongStep);
      pManager->SetProcessOrdering(theCerenkovProcess,idxPostStep);
    }
    if(theeBremsstrahlungProcess->IsApplicable(*particle)){
      pManager->AddProcess(theeBremsstrahlungProcess);
      pManager->SetProcessOrdering(theeBremsstrahlungProcess,idxPostStep);
    }
    if(theMuBremsstrahlungProcess->IsApplicable(*particle)){
      pManager->AddProcess(theMuBremsstrahlungProcess);
      pManager->SetProcessOrdering(theMuBremsstrahlungProcess,idxPostStep);
    }
    if(theScintProcess->IsApplicable(*particle)){
      pManager->AddProcess(theScintProcess);
      pManager->SetProcessOrderingToLast(theScintProcess,idxAtRest);
      pManager->SetProcessOrderingToLast(theScintProcess,idxPostStep);
    }

  }
}

void MOLLEROptPhysicsList::SetNbOfPhotonsCerenkov(G4int MaxNumber)
{
  theCerenkovProcess->SetMaxNumPhotonsPerStep(MaxNumber);
}
/*void MOLLEROptPhysicsList::SetNbOfPhotonsBremsstrahlung(G4int MaxNumber)
{
  theeBremsstrahlungProcess->SetMaxNumPhotonsPerStep(MaxNumber);
  theMuBremsstrahlungProcess->SetMaxNumPhotonsPerStep(MaxNumber);
}*/




