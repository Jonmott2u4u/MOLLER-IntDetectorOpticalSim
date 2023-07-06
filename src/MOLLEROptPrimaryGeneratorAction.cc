#include "MOLLEROptPrimaryGeneratorAction.hh"

MOLLEROptPrimaryGeneratorAction::MOLLEROptPrimaryGeneratorAction(MOLLEROptConstruction* Constr)
{

  Messenger = new MOLLEROptPrimaryGeneratorActionMessenger(this);

  EventCounter = 0;
  EventRegion = 1; 

  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  Construction = Constr;

  G4ParticleDefinition* particle = G4Electron::Definition();
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
  G4double pi = TMath::Pi();
  G4double sa_rad = sa*pi/180;   //Angular acceptance of the beam in radians (how much it deviates from the z-axis)
  G4double cosTheta = 1-(1-TMath::Cos(sa_rad))*G4UniformRand(); G4double sinTheta = std::sqrt(1-cosTheta*cosTheta); G4double Phi = 2*pi*G4UniformRand();
  //G4double p_x = (TMath::Sin(theta*pi/180))*TMath::Cos(phi*pi/180);
  //G4double p_y = (TMath::Sin(theta*pi/180))*TMath::Sin(phi*pi/180);
  //G4double p_z = TMath::Cos(theta*pi/180);			     //Allows you to assign angles to the beam using macros. Replaced by sa
  G4double p_x = sinTheta*TMath::Cos(Phi); G4double p_y = sinTheta*TMath::Sin(Phi); G4double p_z = cosTheta; //Makes the angle of the beam random within +- sa
    
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
    //2x2 mm^2 spot on quartz
    x = (Qlim[1]+Qlim[0])/2.0 -2 +4*G4UniformRand();
    y = (Qlim[3]+Qlim[2])/2.0 -2 +4*G4UniformRand();
  }
  else if(EventRegion == 6){
    //2x2 mm^2 spot on lower guide cone
    x = (LGlim[1]+LGlim[0])/2.0 -2 +4*G4UniformRand();
    y = (LGlim[3]+LGlim[2])/2.0 -2 +4*G4UniformRand();
  }  
  else if(EventRegion == 7){
    //2x2 mm^2 spot on upper guide cone
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


  particleGun->SetParticlePosition(G4ThreeVector((x-300.0*p_x)*mm,(y-300.0*p_y)*mm, -(300*p_z)*mm));
  particleGun->SetParticleMomentumDirection(G4ThreeVector(p_x, p_y, p_z));
  particleGun->SetParticleEnergy(Energy*MeV);

  particleGun->GeneratePrimaryVertex(anEvent);
  EventCounter += 1;

  // myUserInfo->SetPrimaryEventNumber( (G4int) myEventCounter );
  
  if(EventCounter%100 == 0)
    G4cout << "Capture Event# " << EventCounter << G4endl;
}
