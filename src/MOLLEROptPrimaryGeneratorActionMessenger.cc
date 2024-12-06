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

  EventShiftCmd = new G4UIcmdWithADoubleAndUnit("/Generator/EventShift",this);
  EventShiftCmd->SetGuidance("Shift the spawning location of the primary particle.");
  EventShiftCmd->SetParameterName("EventShift",true);
  EventShiftCmd->SetDefaultValue(1);
  EventShiftCmd->SetRange("EventShift>=-10000");
  EventShiftCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegmentHitRegionCmd = new G4UIcmdWithADoubleAndUnit("/Generator/SegmentHitRegion",this);
  SegmentHitRegionCmd->SetGuidance("Set cut of segment to look at.");
  SegmentHitRegionCmd->SetParameterName("SegmentHitRegion",true);
  SegmentHitRegionCmd->SetDefaultValue(1);
  SegmentHitRegionCmd->SetRange("SegmentHitRegion>=-9");
  SegmentHitRegionCmd->SetDefaultUnit("mm");
  SegmentHitRegionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

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

  BeamSolidAngleCmd = new G4UIcmdWithADoubleAndUnit("/Generator/BeamSolidAngle",this);
  BeamSolidAngleCmd->SetGuidance("Set maximum angle of beam from z-axis. Beam can take any angle between that and 0");
  BeamSolidAngleCmd->SetParameterName("BeamSolidAngle",true);
  BeamSolidAngleCmd->SetDefaultValue(0);
  BeamSolidAngleCmd->SetRange("BeamSolidAngle<=360");
  BeamSolidAngleCmd->SetDefaultUnit("degree");
  BeamSolidAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamTiltAngleCmd = new G4UIcmdWithADoubleAndUnit("/Generator/BeamTiltAngle",this);
  BeamTiltAngleCmd->SetGuidance("Set tilt of beam from z-axis in degrees. Maximum value of 90");
  BeamTiltAngleCmd->SetParameterName("BeamTiltAngle",true);
  BeamTiltAngleCmd->SetDefaultValue(0);
  BeamTiltAngleCmd->SetRange("BeamTiltAngle<=900");
  BeamTiltAngleCmd->SetDefaultUnit("degree");
  BeamTiltAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamTiltDirectionCmd = new G4UIcmdWithADoubleAndUnit("/Generator/BeamTiltDirection",this);
  BeamTiltDirectionCmd->SetGuidance("Set direction of beam tilt around z-axis. 0 is along x-axis, 90 along y-axis");
  BeamTiltDirectionCmd->SetParameterName("BeamTiltDir",true);
  BeamTiltDirectionCmd->SetDefaultValue(0);
  BeamTiltDirectionCmd->SetRange("BeamTiltDir<=360");
  BeamTiltDirectionCmd->SetDefaultUnit("degree");
  BeamTiltDirectionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  BeamEnergyCmd = new G4UIcmdWithAnInteger("/Generator/BeamEnergy",this);
  BeamEnergyCmd->SetGuidance("Set Energy of beam in units of MeV.");
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
    {pPrimaryGeneratorAction->ResetNtupleEventCounter();}

  if( command == InitEventCounterCmd )
    { pPrimaryGeneratorAction->SetNtupleEventCounter(InitEventCounterCmd->GetNewIntValue(newValue));}

  if( command == PrimaryParticleCmd )
    { pPrimaryGeneratorAction->SetPrimaryParticle(PrimaryParticleCmd->GetNewIntValue(newValue));}

  if( command == EventHitRegionCmd )
    { pPrimaryGeneratorAction->SetEventHitRegion(EventHitRegionCmd->GetNewIntValue(newValue));}

  if( command == EventShiftCmd )
    { pPrimaryGeneratorAction->SetEventShift(EventShiftCmd->GetNewDoubleValue(newValue));}

  if( command == SegmentHitRegionCmd )
    { pPrimaryGeneratorAction->SetSegmentHitRegion(SegmentHitRegionCmd->GetNewDoubleValue(newValue));}

  if( command == BeamThetaCmd )
    { pPrimaryGeneratorAction->SetBeamTheta(BeamThetaCmd->GetNewIntValue(newValue));}

  if( command == BeamPhiCmd )
    { pPrimaryGeneratorAction->SetBeamPhi(BeamPhiCmd->GetNewIntValue(newValue));}

  if( command == BeamSolidAngleCmd )
    { pPrimaryGeneratorAction->SetBeamSolidAngle(BeamSolidAngleCmd->GetNewDoubleValue(newValue));}

  if( command == BeamTiltAngleCmd )
    { pPrimaryGeneratorAction->SetBeamTiltAngle(BeamTiltAngleCmd->GetNewDoubleValue(newValue));}

  if( command == BeamTiltDirectionCmd )
    { pPrimaryGeneratorAction->SetBeamTiltDirection(BeamTiltDirectionCmd->GetNewDoubleValue(newValue));}

  if( command == BeamEnergyCmd )
    { pPrimaryGeneratorAction->SetBeamEnergy(BeamEnergyCmd->GetNewIntValue(newValue));}

  if( command == BeamEnergyCutCmd )
    { pPrimaryGeneratorAction->SetBeamEnergyCut(BeamEnergyCutCmd->GetNewIntValue(newValue));}
}
