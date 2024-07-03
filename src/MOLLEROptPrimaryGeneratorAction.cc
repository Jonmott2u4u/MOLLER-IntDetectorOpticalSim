#include "MOLLEROptPrimaryGeneratorAction.hh"
#include <stdlib.h>
#include <iostream>


MOLLEROptPrimaryGeneratorAction::MOLLEROptPrimaryGeneratorAction(MOLLEROptConstruction* Constr)
{

  Messenger = new MOLLEROptPrimaryGeneratorActionMessenger(this);

  EventCounter = 0;
  EventRegion = 1; 

  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  Construction = Constr;

  //G4ParticleDefinition* particle = G4Electron::Definition();
  G4ParticleDefinition* particle = G4MuonMinus::Definition();
  /*if (PrimaryParticle == 1) particle = G4Electron::Definition();
  if (PrimaryParticle == 2) particle = G4MuonMinus::Definition();*/
  particleGun->SetParticleDefinition(particle);
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
    
  G4double Qlim1[4];
  G4double Qlim2[4];
  G4double Qlim3[4];
  G4double Qlim4[4];
  G4double Qlim5[4];
  G4double Qlim6[4];
  G4double Qlim7[4];
  G4double Qlim8[4];
  G4double LGlim1[8];
  G4double LGlim2[8];
  G4double LGlim3[8];
  G4double LGlim4[8];
  G4double LGlim5[8];
  G4double LGlim6[8];
  G4double LGlim7[8];
  G4double LGlim8[8];
  G4double Slim1[8];
  G4double Slim2[8];
  G4double Slim3[8];
  G4double Slim4[8];
  Construction->GetQuartz1Limits(Qlim1);//Ring 1
  Construction->GetQuartz2Limits(Qlim2);//Ring 2
  Construction->GetQuartz3Limits(Qlim3);//Ring 3
  Construction->GetQuartz4Limits(Qlim4);//Ring 4
  Construction->GetQuartz5Limits(Qlim5);//Ring 5
  Construction->GetQuartz6Limits(Qlim6);//Ring 6
  Construction->GetQuartz7Limits(Qlim7);//Ring 7
  Construction->GetQuartz8Limits(Qlim8);//Ring 8
  Construction->GetLightGuide1Limits(LGlim1);//Currently R6. Overwritten each time a detector is generated. Can easily be changed
  Construction->GetLightGuide2Limits(LGlim2);
  Construction->GetLightGuide3Limits(LGlim3);
  Construction->GetLightGuide4Limits(LGlim4);
  Construction->GetLightGuide5Limits(LGlim5);
  Construction->GetLightGuide6Limits(LGlim6);
  Construction->GetLightGuide7Limits(LGlim7);
  Construction->GetLightGuide8Limits(LGlim8);
  Construction->GetScint1Limits(Slim1);
  Construction->GetScint2Limits(Slim2);
  Construction->GetScint3Limits(Slim3);
  Construction->GetScint4Limits(Slim4);

//~~~~~~~~Commenting this out does not effect anything, but leaving as is for now~~~~~~~~~~~~~~~~~
  if(Qlim1[0]<=0) Qlim1[0] += 1; else Qlim1[0] -= 1; 
  if(Qlim1[1]<=0) Qlim1[1] += 1; else Qlim1[1] -= 1; 
  if(Qlim1[2]<=0) Qlim1[2] += 1; else Qlim1[2] -= 1; 
  if(Qlim1[3]<=0) Qlim1[3] += 1; else Qlim1[3] -= 1;

  if(Qlim2[0]<=0) Qlim2[0] += 1; else Qlim2[0] -= 1; 
  if(Qlim2[1]<=0) Qlim2[1] += 1; else Qlim2[1] -= 1; 
  if(Qlim2[2]<=0) Qlim2[2] += 1; else Qlim2[2] -= 1; 
  if(Qlim2[3]<=0) Qlim2[3] += 1; else Qlim2[3] -= 1; 

  if(Qlim3[0]<=0) Qlim3[0] += 1; else Qlim3[0] -= 1; 
  if(Qlim3[1]<=0) Qlim3[1] += 1; else Qlim3[1] -= 1; 
  if(Qlim3[2]<=0) Qlim3[2] += 1; else Qlim3[2] -= 1; 
  if(Qlim3[3]<=0) Qlim3[3] += 1; else Qlim3[3] -= 1; 

  if(Qlim4[0]<=0) Qlim4[0] += 1; else Qlim4[0] -= 1; 
  if(Qlim4[1]<=0) Qlim4[1] += 1; else Qlim4[1] -= 1; 
  if(Qlim4[2]<=0) Qlim4[2] += 1; else Qlim4[2] -= 1; 
  if(Qlim4[3]<=0) Qlim4[3] += 1; else Qlim4[3] -= 1; 

  if(Qlim5[0]<=0) Qlim5[0] += 1; else Qlim5[0] -= 1; 
  if(Qlim5[1]<=0) Qlim5[1] += 1; else Qlim5[1] -= 1; 
  if(Qlim5[2]<=0) Qlim5[2] += 1; else Qlim5[2] -= 1; 
  if(Qlim5[3]<=0) Qlim5[3] += 1; else Qlim5[3] -= 1; 

  if(Qlim6[0]<=0) Qlim6[0] += 1; else Qlim6[0] -= 1; 
  if(Qlim6[1]<=0) Qlim6[1] += 1; else Qlim6[1] -= 1; 
  if(Qlim6[2]<=0) Qlim6[2] += 1; else Qlim6[2] -= 1; 
  if(Qlim6[3]<=0) Qlim6[3] += 1; else Qlim6[3] -= 1; 

  if(Qlim7[0]<=0) Qlim7[0] += 1; else Qlim7[0] -= 1; 
  if(Qlim7[1]<=0) Qlim7[1] += 1; else Qlim7[1] -= 1; 
  if(Qlim7[2]<=0) Qlim7[2] += 1; else Qlim7[2] -= 1; 
  if(Qlim7[3]<=0) Qlim7[3] += 1; else Qlim7[3] -= 1; 

  if(Qlim8[0]<=0) Qlim8[0] += 1; else Qlim8[0] -= 1; 
  if(Qlim8[1]<=0) Qlim8[1] += 1; else Qlim8[1] -= 1; 
  if(Qlim8[2]<=0) Qlim8[2] += 1; else Qlim8[2] -= 1; 
  if(Qlim8[3]<=0) Qlim8[3] += 1; else Qlim8[3] -= 1;

  if(Slim1[0]<=0) Slim1[0] += 1; else Slim1[0] -= 1; 
  if(Slim1[1]<=0) Slim1[1] += 1; else Slim1[1] -= 1; 
  if(Slim1[2]<=0) Slim1[2] += 1; else Slim1[2] -= 1; 
  if(Slim1[3]<=0) Slim1[3] += 1; else Slim1[3] -= 1;
  if(Slim1[4]<=0) Slim1[4] += 1; else Slim1[4] -= 1; 
  if(Slim1[5]<=0) Slim1[5] += 1; else Slim1[5] -= 1; 
  if(Slim1[6]<=0) Slim1[6] += 1; else Slim1[6] -= 1; 
  if(Slim1[7]<=0) Slim1[7] += 1; else Slim1[7] -= 1;

  if(Slim2[0]<=0) Slim2[0] += 1; else Slim2[0] -= 1; 
  if(Slim2[1]<=0) Slim2[1] += 1; else Slim2[1] -= 1; 
  if(Slim2[2]<=0) Slim2[2] += 1; else Slim2[2] -= 1; 
  if(Slim2[3]<=0) Slim2[3] += 1; else Slim2[3] -= 1;
  if(Slim2[4]<=0) Slim2[4] += 1; else Slim2[4] -= 1; 
  if(Slim2[5]<=0) Slim2[5] += 1; else Slim2[5] -= 1; 
  if(Slim2[6]<=0) Slim2[6] += 1; else Slim2[6] -= 1; 
  if(Slim2[7]<=0) Slim2[7] += 1; else Slim2[7] -= 1;

  if(Slim3[0]<=0) Slim3[0] += 1; else Slim3[0] -= 1; 
  if(Slim3[1]<=0) Slim3[1] += 1; else Slim3[1] -= 1; 
  if(Slim3[2]<=0) Slim3[2] += 1; else Slim3[2] -= 1; 
  if(Slim3[3]<=0) Slim3[3] += 1; else Slim3[3] -= 1;
  if(Slim3[4]<=0) Slim3[4] += 1; else Slim3[4] -= 1; 
  if(Slim3[5]<=0) Slim3[5] += 1; else Slim3[5] -= 1; 
  if(Slim3[6]<=0) Slim3[6] += 1; else Slim3[6] -= 1; 
  if(Slim3[7]<=0) Slim3[7] += 1; else Slim3[7] -= 1;

  if(Slim4[0]<=0) Slim4[0] += 1; else Slim4[0] -= 1; 
  if(Slim4[1]<=0) Slim4[1] += 1; else Slim4[1] -= 1; 
  if(Slim4[2]<=0) Slim4[2] += 1; else Slim4[2] -= 1; 
  if(Slim4[3]<=0) Slim4[3] += 1; else Slim4[3] -= 1;
  if(Slim4[4]<=0) Slim4[4] += 1; else Slim4[4] -= 1; 
  if(Slim4[5]<=0) Slim4[5] += 1; else Slim4[5] -= 1; 
  if(Slim4[6]<=0) Slim4[6] += 1; else Slim4[6] -= 1; 
  if(Slim4[7]<=0) Slim4[7] += 1; else Slim4[7] -= 1;

  if(LGlim1[0]<=0) LGlim1[0] += 1; else LGlim1[0] -= 1; 
  if(LGlim1[1]<=0) LGlim1[1] += 1; else LGlim1[1] -= 1; 
  if(LGlim1[2]<=0) LGlim1[2] += 1; else LGlim1[2] -= 1; 
  if(LGlim1[3]<=0) LGlim1[3] += 1; else LGlim1[3] -= 1; 
  if(LGlim1[4]<=0) LGlim1[4] += 1; else LGlim1[4] -= 1; 
  if(LGlim1[5]<=0) LGlim1[5] += 1; else LGlim1[5] -= 1; 
  if(LGlim1[6]<=0) LGlim1[6] += 1; else LGlim1[6] -= 1; 
  if(LGlim1[7]<=0) LGlim1[7] += 1; else LGlim1[7] -= 1; 

  //Other LGlimits (2->8) will be added when needed
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*~~~~~~~Previously used for just 1 detector. Replaced by next section~~~~~~~~~~~~~~~~~~~~~
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
    //2x2 mm^2 spot on quartz center
    x = (Qlim[1]+Qlim[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim[3]+Qlim[2])/2.0 -2 +4*G4UniformRand();
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
    //Vertical cut on the quartz (currently 10 implemented, can be changed here)
    x = Qlim[0] + ((Qlim[1]-Qlim[0])/10)*cut + ((Qlim[1]-Qlim[0])/10)*G4UniformRand();
    y = Qlim[2] + (Qlim[3]-Qlim[2])*G4UniformRand();
   }
  else if(EventRegion == 9){
    //Horizontal cut on the quartz (currently 10 implemented, can be changed here)
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = Qlim[2] + ((Qlim[3]-Qlim[2])/10)*cut + ((Qlim[3]-Qlim[2])/10)*G4UniformRand();
  }
  else{ 
    //On Quartz
    x = Qlim[0] + (Qlim[1]-Qlim[0])*G4UniformRand();
    y = Qlim[2] + (Qlim[3]-Qlim[2])*G4UniformRand();
  }
*/
  if(EventRegion == 1){
    //4x4 mm^2 spot on R1 quartz center
    x = (Qlim1[1]+Qlim1[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim1[3]+Qlim1[2])/2.0 -2 +4*G4UniformRand() + 1423.94*TMath::Sin(6*pi/180);
    //y = Qlim1[3] - 1;
  }
  else if(EventRegion == 2){
    //4x4 mm^2 spot on R2 quartz center
    x = (Qlim2[1]+Qlim2[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim2[3]+Qlim2[2])/2.0 -2 +4*G4UniformRand() + 1145.60*TMath::Sin(6*pi/180);
    //y = Qlim2[3] - 1;
  }
  else if(EventRegion == 3){
    //4x4 mm^2 spot on R3 quartz center
    x = (Qlim3[1]+Qlim3[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim3[3]+Qlim3[2])/2.0 -2 +4*G4UniformRand() + 871.51*TMath::Sin(6*pi/180);
    //y = Qlim3[3] - 1;
  }
  else if(EventRegion == 4){
    //4x4 mm^2 spot on R4 quartz center
    x = (Qlim4[1]+Qlim4[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim4[3]+Qlim4[2])/2.0 -2 +4*G4UniformRand() + 592.08*TMath::Sin(6*pi/180);
    //y = Qlim4[3] - 1;
  }
  else if(EventRegion == 5){
    //4x4 mm^2 spot on R5 FF quartz center
    x = (Qlim5[1]+Qlim5[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim5[3]+Qlim5[2])/2.0 -2 +4*G4UniformRand() + 151.64*TMath::Sin(6*pi/180);
  }
  else if(EventRegion == 6){
    //4x4 mm^2 spot on R5 BF 1 quartz center
    x = (Qlim6[1]+Qlim6[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim6[3]+Qlim6[2])/2.0 -2 +4*G4UniformRand() + 302.47*TMath::Sin(6*pi/180);
  }
  else if(EventRegion == 7){
    //4x4 mm^2 spot on R5 BF 2 quartz center
    x = (Qlim7[1]+Qlim7[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim7[3]+Qlim7[2])/2.0 -2 +4*G4UniformRand() + 302.47*TMath::Sin(6*pi/180);
  }
  else if(EventRegion == 8){
    //4x4 mm^2 spot on R6 quartz center
    x = (Qlim8[1]+Qlim8[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim8[3]+Qlim8[2])/2.0 -2 +4*G4UniformRand() + 1.78*TMath::Sin(6*pi/180);
  }
  else if(EventRegion == 9){
    //Hits a random location from the top of R6 quartz to the bottom of R1 quartz (may hit empty space on sides of quartz)
    x = Qlim1[0] + (Qlim1[1]-Qlim1[0])*G4UniformRand();
    y = (Qlim1[2] + 1423.94*TMath::Sin(6*pi/180)) + (Qlim8[3]-Qlim1[2]-1560*TMath::Sin(6*pi/180))*G4UniformRand();
  }
  else if(EventRegion == 10){
    //Used for performing segment scans along the y-axis. The x-axis is focused on the center of the segment (quartz tiles for all but R5 FF) in a 4x4 mm^2 spot
    x = (Qlim1[1]+Qlim1[0])/2.0 -2 +4*G4UniformRand();
    y = Qlim1[2] + 1423.94*TMath::Sin(6*pi/180) + (cut-5*G4UniformRand()); //cut has units cm, whereas the rest has units mm
  }
  else if(EventRegion == 11){
    //Cosmic distribution for cosmic stands. Update the numbers in the "y" expression as needed.
    //When using, set sa to the maximum accepted angle in the macros (currently calculated by hand)
    y_base = Slim1[4] + (Slim1[5]-Slim1[4])*G4UniformRand(); //Value of y before applying vertical shift (shift is needed due to improper implementation of polar angle for multiple detectors)
    //x_shift = (Slim[3]-Slim[0])*(y_base-Slim[4])/(Slim[5]-Slim[4]); //Shift used for making x positions y-dependent. Designed to convert a rectangular to a trapezoidal shift, but is not used currently
    y = y_base;
    x = Slim1[0] + (Slim1[1]-Slim1[0])*G4UniformRand();
  }
  else{
    //Defaults to Ring 1
    x = (Qlim1[1]+Qlim1[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim1[3]+Qlim1[2])/2.0 -2 +4*G4UniformRand() + 1423.94*TMath::Sin(6*pi/180);
  }

  G4double sa_rad = sa*pi/180.;   //Angular acceptance of the beam in radians (how much it deviates from the z-axis)
  G4double Phi = 2*pi*G4UniformRand();
  G4double cosTheta = TMath::Cos(G4UniformRand()*sa_rad);
  G4double ThetaInc = G4UniformRand();
  while (ThetaInc > (cosTheta*cosTheta)){
    cosTheta = TMath::Cos(G4UniformRand()*sa_rad);
  }
  //G4double cosTheta = 1-(1-TMath::Cos(sa_rad))*G4UniformRand(); 
  G4double sinTheta = std::sqrt(1-cosTheta*cosTheta);
  G4double p_x = sinTheta*TMath::Cos(Phi); G4double p_y = sinTheta*TMath::Sin(Phi); G4double p_z = cosTheta; //Makes the angle of the beam random within +- sa

  particleGun->SetParticlePosition(G4ThreeVector(x*mm, (y+shift)*mm, -11*mm));
  particleGun->SetParticleMomentumDirection(G4ThreeVector(p_x, p_y, p_z));

  //The following section reads cosmics.txt to generate beam energies following cosmic muon energy distributions
  //****************************************
  G4int muon_energy;
  G4int pass = 0;
  FILE *fptr;
  while(pass == 0){
    G4double rand_int = G4UniformRand()*342800; //342800 is from the length of the file cosmics.txt
    rand_int = rand_int/1;
    fptr = fopen("data/cosmics.txt", "r");
    muon_energy = getw(fptr);
    G4int inc = 1;
    pass = 1;
    while (inc < rand_int){
      muon_energy = getw(fptr);
      inc++;
    }
    if (muon_energy <= EnergyCut){
      pass = 0;
    }
    fclose(fptr);
  }

  //G4cout << "Muon energy is: " << energy << " MeV \n" << G4endl;
  //G4cout << "Random integer was: " << rand_int << "\n" << G4endl;
  //G4cout << "\n Increment reached: " << inc << "\n" << G4endl;
  //fclose(fptr);
  //*****************************************

  if (PrimaryParticle == 1) particleGun->SetParticleEnergy(Energy*MeV); //Uses energy set by macro
  if (PrimaryParticle == 2) particleGun->SetParticleEnergy(muon_energy*MeV);// Uses energy following sea level cosmic muon distribution

  particleGun->GeneratePrimaryVertex(anEvent);
  EventCounter += 1;

  // myUserInfo->SetPrimaryEventNumber( (G4int) myEventCounter );
  
  if(EventCounter%100 == 0)
    G4cout << "Capture Event# " << EventCounter << G4endl;
}
