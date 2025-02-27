#include "MOLLEROptPrimaryGeneratorActionMessenger.hh"

MOLLEROptPrimaryGeneratorActionMessenger::MOLLEROptPrimaryGeneratorActionMessenger(MOLLEROptPrimaryGeneratorAction* pPhys)
  :pPrimaryGeneratorAction(pPhys)
{
  Dir = new G4UIdirectory("/Generator/");
  Dir->SetGuidance("UI commands of this example");
 
  verboseCmd = new G4UIcmdWithAnInteger("/Generator/verbose",this);  
  verboseCmd->SetGuidance("set verbose for primary generator");
  verboseCmd->SetParameterName("verbose",true);
  verboseCmd->SetDefaultValue(1);
  verboseCmd->SetRange("verbose>=0");
  verboseCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  resetCmd = new G4UIcmdWithoutParameter("/Generator/ResetNtupleEventCounter",this);  
  resetCmd->SetGuidance("resets Ntuple Event Counter");
  resetCmd->AvailableForStates(G4State_Idle);  

  InitEventCounterCmd = new G4UIcmdWithAnInteger("/Generator/StartingEvent",this);
  InitEventCounterCmd->SetGuidance("set starting event count for primary generator");
  InitEventCounterCmd->SetParameterName("StartingEvent",true);
  InitEventCounterCmd->SetDefaultValue(1);
  InitEventCounterCmd->SetRange("StartingEvent>=0");
  InitEventCounterCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  PrimaryParticleCmd = new G4UIcmdWithAnInteger("/Generator/PrimaryParticle",this);
  PrimaryParticleCmd->SetGuidance("Set Primary (beam) particle.");
  PrimaryParticleCmd->SetParameterName("PrimaryParticle",true);
  PrimaryParticleCmd->SetDefaultValue(1);
  PrimaryParticleCmd->SetRange("PrimaryParticle>=1");
  PrimaryParticleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  EventHitRegionCmd = new G4UIcmdWithAnInteger("/Generator/EventHitRegion",this);
  EventHitRegionCmd->SetGuidance("Set region in which event hits.");
  EventHitRegionCmd->SetParameterName("EventHitRegion",true);
  EventHitRegionCmd->SetDefaultValue(1);
  EventHitRegionCmd->SetRange("EventHitRegion>=1");
  EventHitRegionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzHitRegionCmd = new G4UIcmdWithAnInteger("/Generator/QuartzHitRegion",this);
  QuartzHitRegionCmd->SetGuidance("Set cut of quartz to look at.");
  QuartzHitRegionCmd->SetParameterName("QuartzHitRegion",true);
  QuartzHitRegionCmd->SetDefaultValue(1);
  QuartzHitRegionCmd->SetRange("QuartzHitRegion>=0");
  QuartzHitRegionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamThetaCmd = new G4UIcmdWithAnInteger("/Generator/BeamTheta",this);
  BeamThetaCmd->SetGuidance("Set angle of beam in y direction from z axis.");
  BeamThetaCmd->SetParameterName("BeamTheta",true);
  BeamThetaCmd->SetDefaultValue(0);
  BeamThetaCmd->SetRange("BeamTheta<=90");
  BeamThetaCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamPhiCmd = new G4UIcmdWithAnInteger("/Generator/BeamPhi",this);
  BeamPhiCmd->SetGuidance("Set angle of beam in x direction from z axis.");
  BeamPhiCmd->SetParameterName("BeamPhi",true);
  BeamPhiCmd->SetDefaultValue(0);
  BeamPhiCmd->SetRange("BeamPhi<=360");
  BeamPhiCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamSolidAngleCmd = new G4UIcmdWithAnInteger("/Generator/BeamSolidAngle",this);
  BeamSolidAngleCmd->SetGuidance("Set maximum angle of beam from z-axis. Beam can take any angle between that and 0");
  BeamSolidAngleCmd->SetParameterName("BeamSolidAngle",true);
  BeamSolidAngleCmd->SetDefaultValue(0);
  BeamSolidAngleCmd->SetRange("BeamSolidAngle<=360");
  BeamSolidAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamEnergyCmd = new G4UIcmdWithAnInteger("/Generator/BeamEnergy",this);
  BeamEnergyCmd->SetGuidance("Set Energy of beam.");
  BeamEnergyCmd->SetParameterName("BeamEnergy",true);
  BeamEnergyCmd->SetDefaultValue(8000);
  BeamEnergyCmd->SetRange("BeamEnergy > 0");
  BeamEnergyCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamEnergyCutCmd = new G4UIcmdWithAnInteger("/Generator/BeamEnergyCut",this);
  BeamEnergyCutCmd->SetGuidance("Set Energy cut of beam in units of MeV.");
  BeamEnergyCutCmd->SetParameterName("BeamEnergyCut",true);
  BeamEnergyCutCmd->SetDefaultValue(0);
  BeamEnergyCutCmd->SetRange("BeamEnergyCut >= 0");
  BeamEnergyCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);


}

MOLLEROptPrimaryGeneratorActionMessenger::~MOLLEROptPrimaryGeneratorActionMessenger()
{
  delete verboseCmd;
  delete resetCmd;
  delete Dir;
}

void MOLLEROptPrimaryGeneratorActionMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{       
  if( command == resetCmd )
    {pPrimaryGeneratorAction->ResetNtupleEventCounter(); }

  if( command == InitEventCounterCmd )
    { pPrimaryGeneratorAction->SetNtupleEventCounter(InitEventCounterCmd->GetNewIntValue(newValue)); }

  if( command == PrimaryParticleCmd )
    { pPrimaryGeneratorAction->SetPrimaryParticle(PrimaryParticleCmd->GetNewIntValue(newValue));}

  if( command == EventHitRegionCmd )
    { pPrimaryGeneratorAction->SetEventHitRgion(EventHitRegionCmd->GetNewIntValue(newValue)); }

  if( command == QuartzHitRegionCmd )
    { pPrimaryGeneratorAction->SetQuartzHitRegion(QuartzHitRegionCmd->GetNewIntValue(newValue)); }

  if( command == BeamThetaCmd )
    { pPrimaryGeneratorAction->SetBeamTheta(BeamThetaCmd->GetNewIntValue(newValue)); }

  if( command == BeamPhiCmd )
    { pPrimaryGeneratorAction->SetBeamPhi(BeamPhiCmd->GetNewIntValue(newValue)); }

  if( command == BeamSolidAngleCmd )
    { pPrimaryGeneratorAction->SetBeamSolidAngle(BeamSolidAngleCmd->GetNewIntValue(newValue)); }
 
  if( command == BeamEnergyCmd )
    { pPrimaryGeneratorAction->SetBeamEnergy(BeamEnergyCmd->GetNewIntValue(newValue)); }

  if( command == BeamEnergyCutCmd )
    { pPrimaryGeneratorAction->SetBeamEnergyCut(BeamEnergyCutCmd->GetNewIntValue(newValue));}

}
