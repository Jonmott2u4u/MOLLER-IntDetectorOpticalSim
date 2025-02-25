#include "MOLLEROptPrimaryGeneratorAction.hh"
#include <stdlib.h>
#include <iostream>


MOLLEROptPrimaryGeneratorAction::MOLLEROptPrimaryGeneratorAction(MOLLEROptConstruction* Constr, MOLLEROptCosmics* cos)
{

  Messenger = new MOLLEROptPrimaryGeneratorActionMessenger(this);

  EventCounter = 0;
  EventRegion = 1; 

  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  Construction = Constr;
  Cosmics = cos;
  CosmicParams = Cosmics->GetCosmicParametersTable();

}

MOLLEROptPrimaryGeneratorAction::~MOLLEROptPrimaryGeneratorAction()
{
  if (particleGun) delete particleGun;
}

void MOLLEROptPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  G4double x = 0;
  G4double y = 0;   
  G4double Qlim[4];
  G4double LGlim[8];
  Construction->GetQuartzLimits(Qlim);
  Construction->GetLightGuideLimits(LGlim);

  if(Qlim[0]<=0) Qlim[0] += 1; else Qlim[0] -= 1; 
  if(Qlim[1]<=0) Qlim[1] += 1; else Qlim[1] -= 1; 
  if(Qlim[2]<=0) Qlim[2] += 1; else Qlim[2] -= 1; 
  if(Qlim[3]<=0) Qlim[3] += 1; else Qlim[3] -= 1; 

  if(LGlim[0]<=0) LGlim[0] += 1; else LGlim[0] -= 1; 
  if(LGlim[1]<=0) LGlim[1] += 1; else LGlim[1] -= 1; 
  if(LGlim[2]<=0) LGlim[2] += 1; else LGlim[2] -= 1; 
  if(LGlim[3]<=0) LGlim[3] += 1; else LGlim[3] -= 1; 
  if(LGlim[4]<=0) LGlim[4] += 1; else LGlim[4] -= 1; 
  if(LGlim[5]<=0) LGlim[5] += 1; else LGlim[5] -= 1; 
  if(LGlim[6]<=0) LGlim[6] += 1; else LGlim[6] -= 1; 
  if(LGlim[7]<=0) LGlim[7] += 1; else LGlim[7] -= 1; 


  if(EventRegion == 2){
  //On Lower Light Guide cone
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = LGlim[2] + (LGlim[3]-LGlim[2])*G4UniformRand();
  }
  else if(EventRegion == 3){
    //On box between LG cones
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = LGlim[6] + (90*mm)*G4UniformRand(); //hard-coded to the box height. Update at some point 
  }
  else if(EventRegion == 4){
    //On Upper Light Guide cone
    x = LGlim[4] + (LGlim[5]-LGlim[4])*G4UniformRand();
    y = LGlim[6]+90*mm + (LGlim[7]-LGlim[6]-10*mm)*G4UniformRand(); //Also hard-coded
  }
  else if(EventRegion == 5){
    //2x2m^2 spot on quartz center
    x = (Qlim[1]+Qlim[0])/2.0 -1 +2*G4UniformRand();
    y = (Qlim[3]+Qlim[2])/2.0 -1 +2*G4UniformRand();
  }
  else if(EventRegion == 6){
    //4x4 mm^2 spot on lower guide cone
    x = (LGlim[1]+LGlim[0])/2.0 -2 +4*G4UniformRand();
    y = (LGlim[3]+LGlim[2])/2.0 -2 +4*G4UniformRand();
  }  
  else if(EventRegion == 7){
    //4x4 mm^2 spot on upper guide cone
    x = (LGlim[5]+LGlim[4])/2.0 -2 +4*G4UniformRand();
    y = (LGlim[7]+LGlim[6])/2.0 -2 +4*G4UniformRand();
  }  
  else if(EventRegion == 8){
    //x cut on the quartz (currently 10 implemented, can be changed here)
    x = Qlim[0] + ((Qlim[1]-Qlim[0])/20)*cut + ((Qlim[1]-Qlim[0])/20)*G4UniformRand();
    y = Qlim[2] + (Qlim[3]-Qlim[2])*G4UniformRand();
   }
  else if(EventRegion == 9){
    //y cut on the quartz (currently 10 implemented, can be changed here)
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = Qlim[2] + ((Qlim[3]-Qlim[2])/20)*cut + ((Qlim[3]-Qlim[2])/20)*G4UniformRand();
  }
  else{ 
    //On Quartz
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = Qlim[2] + (Qlim[3]-Qlim[2])*G4UniformRand();
  }

  G4double pi = TMath::Pi();
  G4double sa_rad = sa*pi/180;   //Angular acceptance of the beam in radians (how much it deviates from the z-axis)
  G4double Phi = 2*pi*G4UniformRand();
  G4double cosTheta = TMath::Cos(G4UniformRand()*sa_rad);
  G4double ThetaInc = G4UniformRand();
  while (ThetaInc > (cosTheta*cosTheta)){
    cosTheta = TMath::Cos(G4UniformRand()*sa_rad);
  }

  G4double sinTheta = std::sqrt(1-cosTheta*cosTheta);
  G4double p_x = sinTheta*TMath::Cos(Phi);
  G4double p_y = sinTheta*TMath::Sin(Phi);
  G4double p_z = cosTheta; //Makes the angle of the beam random within +- sa


  particleGun->SetParticlePosition(G4ThreeVector((x-300.0*p_x)*mm,(y-300.0*p_y)*mm, -(300*p_z)*mm));
  particleGun->SetParticleMomentumDirection(G4ThreeVector(p_x, p_y, p_z));

  //Following section reads cosmics.txt to generate beam energies following cosmic muon energy distributions
  //****************************************
  G4ParticleDefinition* particle = G4Electron::Definition();//Primary event particle defaults to electron
  if (PrimaryParticle == 1) particle = G4Electron::Definition();
  if (PrimaryParticle == 2) particle = G4MuonMinus::Definition();
  particleGun->SetParticleDefinition(particle);

  G4int muon_energy = 0;
  G4int pass = 0;
  G4double rand = G4UniformRand()*CosmicParams->RateMuon[CosmicParams->GetNPar()-1];
  int rand_int = rand/1;
  //G4cout << "Random integer was initially: " << rand_int << "\n" << G4endl;

  int z = 0;
  int low_bound = 0;
  int high_bound = CosmicParams->RateMuon[z];
  if(PrimaryParticle == 2){
    while((pass == 0)){
      if((rand_int <= high_bound) && (rand_int > low_bound)){
        muon_energy = CosmicParams->EMuon[z];
        pass = 1;
      }
      else{
        low_bound = high_bound;
        high_bound = CosmicParams->RateMuon[z+1];
        //G4cout << "Low Bound after failure: " << low_bound << "\n" << G4endl;
        //G4cout << "High Bound after failure: " << high_bound << "\n" << G4endl;
      }
      z++;
      if((muon_energy <= EnergyCut) && (pass == 1)){
        //G4cout << "The random integer that failed was: " << rand_int << "\n" << G4endl;
        z = 0;
        pass = 0;
        low_bound = 0;
        high_bound = CosmicParams->RateMuon[z];
        rand = G4UniformRand()*CosmicParams->RateMuon[CosmicParams->GetNPar()-1];
        rand_int = rand/1;
      }
    }
  }

  muon_energy = muon_energy/1;


  //G4cout << "Muon energy is: " << muon_energy << " MeV \n" << G4endl;
  //G4cout << "Random integer was finally: " << rand_int << "\n" << G4endl;
  //*****************************************

  if (PrimaryParticle == 1) particleGun->SetParticleEnergy(Energy*MeV); //Uses energy set by macro
  if (PrimaryParticle == 2) particleGun->SetParticleEnergy(muon_energy*MeV);// Uses energy following sea level cosmic muon distribution

  particleGun->GeneratePrimaryVertex(anEvent);
  EventCounter += 1;

  // myUserInfo->SetPrimaryEventNumber( (G4int) myEventCounter );
  
  if(EventCounter%100 == 0){
    G4cout << "Capture Event# " << EventCounter << G4endl;
    //G4cout << "Solid angle# " << sa_rad << G4endl;
  }
}
