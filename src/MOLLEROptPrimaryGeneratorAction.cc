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
  G4double x_shift = 0;
  G4double y_base = 0;
  G4double pi = TMath::Pi();

  G4int random_tilt = 0;
    
  G4double Qlim[4];
  G4double LGlim[8];
  G4double Slim1[4];
  G4double Slim2[4];
  G4double Slim3[4];
  Construction->GetQuartzLimits(Qlim); //Calls the limits from quartz1, the furthers US in ShowerMax
  Construction->GetLightGuideLimits(LGlim);
  Construction->GetScint1Limits(Slim1);
  Construction->GetScint2Limits(Slim2);
  Construction->GetScint3Limits(Slim3);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if(EventRegion == 1){
    //Center of Ring quartz center
    x = (Qlim[1]+Qlim[0])/2.0;
    y = (Qlim[3]+Qlim[2])/2.0;
  }
  else if(EventRegion == 2){
    x = (Qlim[1]+Qlim[0])/2.0 + cutx;
    y = Qlim[2] + cuty;
  }
  else if(EventRegion == 3){
    //Same as 2, but random_tilt is enabled
    random_tilt = 1;
    x = (Qlim[1]+Qlim[0])/2.0 + cutx;
    y = Qlim[2] + cuty;
  }
  else if(EventRegion == 4){
    //Horizontal band across tile
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = (Qlim[3]+Qlim[2])/2.0 - 2.5 + 5*G4UniformRand();
  }
  else if(EventRegion == 5){
    random_tilt = 1;
    x = (Qlim[1]+Qlim[0])/2;
    y = (Qlim[3]+Qlim[2])/2.0 - 2.5 + 5*G4UniformRand();
  }
  else if(EventRegion == 6){
    //Anywhere within Scint1 (the US scintillator)
    x = Slim1[0] + (Slim1[1]-Slim1[0])*G4UniformRand();
    y = Slim1[2] + (Slim1[3]-Slim1[2])*G4UniformRand();
  }
  else{
    //Defaults to EventRegion == 1
    x = (Qlim[1]+Qlim[0])/2.0;
    y = (Qlim[3]+Qlim[2])/2.0;
  }

  G4double cosTilt;
  G4double sinTilt;
  G4double tilt_rad = tilt; //Global tilt applied to the beam. In radians due to internal G4 process
  G4double tilt_dir_rad = tilt_dir; //Sets the direction of the beam tilt. In radians due to internal G4 process
  G4double rand2 = G4UniformRand();
  if (random_tilt == 1) {
    cosTilt = TMath::Cos(tilt_rad*(1-2*rand2)); //Uses a randomized tilt angle between the set tilt and its negative value
    sinTilt = TMath::Sin(tilt_rad*(1-2*rand2)); //
  }
  else {
    cosTilt = TMath::Cos(tilt_rad); //Uses a fixed tilt angle
    sinTilt = TMath::Sin(tilt_rad);
  }
  G4double cosTilt_dir = TMath::Cos(tilt_dir_rad); //
  G4double sinTilt_dir = TMath::Sin(tilt_dir_rad); //

  //G4double sa_rad = sa*pi/180.;   //Angular acceptance of the beam in radians (how much it deviates from the z-axis)
  G4double sa_rad = sa; //sa is already converted to radians due to an internal Geant4 process
  G4double Phi = 2*pi*G4UniformRand();
  G4double cosTheta = TMath::Cos(G4UniformRand()*sa_rad); //Randomized the beam angle within +- sa
  G4double ThetaInc = G4UniformRand();
  while (ThetaInc > (cosTheta*cosTheta)){
    cosTheta = TMath::Cos(G4UniformRand()*sa_rad);
  }
  //G4double cosTheta = 1-(1-TMath::Cos(sa_rad))*G4UniformRand(); 
  G4double sinTheta = std::sqrt(1-cosTheta*cosTheta);
  G4double p_x = sinTheta*TMath::Cos(Phi);
  G4double p_y = sinTheta*TMath::Sin(Phi);
  G4double p_z = cosTheta;

  G4double p_x_tilt = cosTilt_dir*(p_x*cosTilt + p_z*sinTilt) - p_y*sinTilt_dir;
  G4double p_y_tilt = sinTilt_dir*(p_x*cosTilt + p_z*sinTilt) - p_y*cosTilt_dir;
  G4double p_z_tilt = p_z*cosTilt - p_x*sinTilt;

  //-650 mm is ~ the right distance for a 3.5 deg tilted beam to hit the edge of the R5 tile. Used for 2025 HallD beam test
  particleGun->SetParticlePosition(G4ThreeVector(x*mm, (y+shift)*mm, -932*mm)); //Use when scintillators are active
  //particleGun->SetParticlePosition(G4ThreeVector((x-932*p_x_tilt)*mm, (y+shift-932*p_y_tilt)*mm, (-932*p_z_tilt - 34.48)*mm)); //Adjusted beam positioning. Ensures angled primaries hit specific spots on the tile at specific angles/orientations on the xy-plane
  //34.48 ensures the beam hits the face of the US tungsten at the correct position. It's composed of tungsten, wrapper, quartz, and LG thickness
  //particleGun->SetParticlePosition(G4ThreeVector(x*mm, (y+shift)*mm, -470*p_z_tilt*mm)); //Normal beam positioning?
  particleGun->SetParticleMomentumDirection(G4ThreeVector(p_x_tilt, p_y_tilt, p_z_tilt));

  //The following section reads cosmics.txt to generate beam energies following cosmic muon energy distributions
  //****************************************
  G4ParticleDefinition* particle = G4Electron::Definition();//Primary event particle defaults to electron
  if (PrimaryParticle == 1) particle = G4Electron::Definition();
  if (PrimaryParticle == 2) particle = G4MuonMinus::Definition();
  if (PrimaryParticle == 3) particle = G4Positron::Definition();
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

  if ((PrimaryParticle == 1) || (PrimaryParticle == 3)) particleGun->SetParticleEnergy(Energy*MeV); //Uses energy set by macro
  if (PrimaryParticle == 2) particleGun->SetParticleEnergy(muon_energy*MeV);// Uses energy following sea level cosmic muon distribution

  particleGun->GeneratePrimaryVertex(anEvent);
  EventCounter += 1;

  // myUserInfo->SetPrimaryEventNumber( (G4int) myEventCounter );
  
  if(EventCounter%100 == 0){
    G4cout << "Capture Event# " << EventCounter << G4endl;
    //G4cout << "Solid angle# " << sa << G4endl;
  }
}
