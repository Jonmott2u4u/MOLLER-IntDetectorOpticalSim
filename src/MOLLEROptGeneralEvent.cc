#include "MOLLEROptGeneralEvent.hh"


//These are defined in "TrackInformation"
// #define myElectron 1
// #define myPositron 2
// #define myGamma    3  //as in non-optical photon including x-ray
// #define myProton   4
// #define myBeam     5  //Used to be myNeutron, but does not seem to be implemented
// #define myTriton   6
// #define myAlpha    7
// #define myHelium3  8
// #define myNucleus  9


MOLLEROptGeneralEvent::MOLLEROptGeneralEvent() 
{
  Initialize();
} 

MOLLEROptGeneralEvent::~MOLLEROptGeneralEvent()
{ 

}

void MOLLEROptGeneralEvent::Initialize()
{
  LightGuideStepLength.clear();  
  LightGuideStepLength.resize(0);

  LightGuideIncidentPhotonAngle.clear();
  LightGuideIncidentPhotonAngle.resize(0);

  QuartzIncidentPhotonAngle.clear();
  QuartzIncidentPhotonAngle.resize(0);

  QuartzSecondaryPhotonAngle.clear();
  QuartzSecondaryPhotonAngle.resize(0);

  QuartzStepLength.clear();  
  QuartzStepLength.resize(0);
  
  TotalTrackLength.clear();  
  TotalTrackLength.resize(0);

  QuartzTrackLength = 0;

  //ScintTrackLength = 0;

  LightGuideTrackLength.clear();  
  LightGuideTrackLength.resize(0);
  
  TotalSteps.clear();  
  TotalSteps.resize(0);

  QuartzSteps = 0;

  //ScintStept = 0;

  LightGuideSteps.clear();  
  LightGuideSteps.resize(0);

  PMTTrackHit = 0;

  LightGuideTrackHit.clear();  
  LightGuideTrackHit.resize(0);

  R1QuartzTrackHit.clear();  
  R1QuartzTrackHit.resize(0);
  R2QuartzTrackHit.clear();  
  R2QuartzTrackHit.resize(0);
  R3QuartzTrackHit.clear();  
  R3QuartzTrackHit.resize(0);
  R4QuartzTrackHit.clear();  
  R4QuartzTrackHit.resize(0);
  R5QuartzTrackHit.clear();  
  R5QuartzTrackHit.resize(0);
  R6QuartzTrackHit.clear();  
  R6QuartzTrackHit.resize(0);
  R7QuartzTrackHit.clear();  
  R7QuartzTrackHit.resize(0);
  R8QuartzTrackHit.clear();  
  R8QuartzTrackHit.resize(0);
  R9QuartzTrackHit.clear();  
  R9QuartzTrackHit.resize(0);
  R10QuartzTrackHit.clear();  
  R10QuartzTrackHit.resize(0);
  R11QuartzTrackHit.clear();  
  R11QuartzTrackHit.resize(0);
  R12QuartzTrackHit.clear();  
  R12QuartzTrackHit.resize(0);
  R13QuartzTrackHit.clear();  
  R13QuartzTrackHit.resize(0);
  R14QuartzTrackHit.clear();  
  R14QuartzTrackHit.resize(0);
  R15QuartzTrackHit.clear();  
  R15QuartzTrackHit.resize(0);
  R16QuartzTrackHit.clear();  
  R16QuartzTrackHit.resize(0);

  Scint1TrackHit.clear();  
  Scint1TrackHit.resize(0);
  Scint2TrackHit.clear();  
  Scint2TrackHit.resize(0);
  Scint3TrackHit.clear();  
  Scint3TrackHit.resize(0);
  Scint4TrackHit.clear();  
  Scint4TrackHit.resize(0);
  Scint5TrackHit.clear();  
  Scint5TrackHit.resize(0);
  Scint6TrackHit.clear();  
  Scint6TrackHit.resize(0);
  Scint7TrackHit.clear();  
  Scint7TrackHit.resize(0);
  Scint8TrackHit.clear();  
  Scint8TrackHit.resize(0);

  R1TileHitX.clear();  
  R1TileHitX.resize(0);
  R2TileHitX.clear();  
  R2TileHitX.resize(0);
  R3TileHitX.clear();  
  R3TileHitX.resize(0);
  R4TileHitX.clear();  
  R4TileHitX.resize(0);
  R5TileHitX.clear();  
  R5TileHitX.resize(0);
  R6TileHitX.clear();  
  R6TileHitX.resize(0);
  R7TileHitX.clear();  
  R7TileHitX.resize(0);
  R8TileHitX.clear();  
  R8TileHitX.resize(0);
  R9TileHitX.clear();  
  R9TileHitX.resize(0);
  R10TileHitX.clear();  
  R10TileHitX.resize(0);
  R11TileHitX.clear();  
  R11TileHitX.resize(0);
  R12TileHitX.clear();  
  R12TileHitX.resize(0);
  R13TileHitX.clear();  
  R13TileHitX.resize(0);
  R14TileHitX.clear();  
  R14TileHitX.resize(0);
  R15TileHitX.clear();  
  R15TileHitX.resize(0);
  R16TileHitX.clear();  
  R16TileHitX.resize(0);

  Scint1HitX.clear();  
  Scint1HitX.resize(0);
  Scint2HitX.clear();  
  Scint2HitX.resize(0);
  Scint3HitX.clear();  
  Scint3HitX.resize(0);
  Scint4HitX.clear();  
  Scint4HitX.resize(0);
  Scint5HitX.clear();  
  Scint5HitX.resize(0);
  Scint6HitX.clear();  
  Scint6HitX.resize(0);
  Scint7HitX.clear();  
  Scint7HitX.resize(0);
  Scint8HitX.clear();  
  Scint8HitX.resize(0);

  R1TileHitY.clear();  
  R1TileHitY.resize(0);
  R2TileHitY.clear();  
  R2TileHitY.resize(0);
  R3TileHitY.clear();  
  R3TileHitY.resize(0);
  R4TileHitY.clear();  
  R4TileHitY.resize(0);
  R5TileHitY.clear();  
  R5TileHitY.resize(0);
  R6TileHitY.clear();  
  R6TileHitY.resize(0);
  R7TileHitY.clear();  
  R7TileHitY.resize(0);
  R8TileHitY.clear();  
  R8TileHitY.resize(0);
  R9TileHitY.clear();  
  R9TileHitY.resize(0);
  R10TileHitY.clear();  
  R10TileHitY.resize(0);
  R11TileHitY.clear();  
  R11TileHitY.resize(0);
  R12TileHitY.clear();  
  R12TileHitY.resize(0);
  R13TileHitY.clear();  
  R13TileHitY.resize(0);
  R14TileHitY.clear();  
  R14TileHitY.resize(0);
  R15TileHitY.clear();  
  R15TileHitY.resize(0);
  R16TileHitY.clear();  
  R16TileHitY.resize(0);

  Scint1HitY.clear();  
  Scint1HitY.resize(0);
  Scint2HitY.clear();  
  Scint2HitY.resize(0);
  Scint3HitY.clear();  
  Scint3HitY.resize(0);
  Scint4HitY.clear();  
  Scint4HitY.resize(0);
  Scint5HitY.clear();  
  Scint5HitY.resize(0);
  Scint6HitY.clear();  
  Scint6HitY.resize(0);
  Scint7HitY.clear();  
  Scint7HitY.resize(0);
  Scint8HitY.clear();  
  Scint8HitY.resize(0);

  R1TileHitZ.clear();  
  R1TileHitZ.resize(0);
  R2TileHitZ.clear();  
  R2TileHitZ.resize(0);
  R3TileHitZ.clear();  
  R3TileHitZ.resize(0);
  R4TileHitZ.clear();  
  R4TileHitZ.resize(0);
  R5TileHitZ.clear();  
  R5TileHitZ.resize(0);
  R6TileHitZ.clear();  
  R6TileHitZ.resize(0);
  R7TileHitZ.clear();  
  R7TileHitZ.resize(0);
  R8TileHitZ.clear();  
  R8TileHitZ.resize(0);
  R9TileHitZ.clear();  
  R9TileHitZ.resize(0);
  R10TileHitZ.clear();  
  R10TileHitZ.resize(0);
  R11TileHitZ.clear();  
  R11TileHitZ.resize(0);
  R12TileHitZ.clear();  
  R12TileHitZ.resize(0);
  R13TileHitZ.clear();  
  R13TileHitZ.resize(0);
  R14TileHitZ.clear();  
  R14TileHitZ.resize(0);
  R15TileHitZ.clear();  
  R15TileHitZ.resize(0);
  R16TileHitZ.clear();  
  R16TileHitZ.resize(0);

  Scint1HitZ.clear();  
  Scint1HitZ.resize(0);
  Scint2HitZ.clear();  
  Scint2HitZ.resize(0);
  Scint3HitZ.clear();  
  Scint3HitZ.resize(0);
  Scint4HitZ.clear();  
  Scint4HitZ.resize(0);
  Scint5HitZ.clear();  
  Scint5HitZ.resize(0);
  Scint6HitZ.clear();  
  Scint6HitZ.resize(0);
  Scint7HitZ.clear();  
  Scint7HitZ.resize(0);
  Scint8HitZ.clear();  
  Scint8HitZ.resize(0);

  PMTPhotonEnergy.clear();  
  PMTPhotonEnergy.resize(0);

  InitialBeamEnergy.clear();
  InitialBeamEnergy.resize(0);

  InitialBeamAngle.clear();
  InitialBeamAngle.resize(0);

  QuartzPhotonEnergy = 0;

  QuartzStepNPhotons.clear();
  QuartzStepNPhotons.resize(0);
  
  LightGuidePhotonEnergy.clear();  
  LightGuidePhotonEnergy.resize(0);

  QuartzElectronStepLength.clear();
  QuartzElectronStepLength.resize(0);

  ElectronTrackID = 0;
  PhotonTrackID = 0;
  
  PType.clear();  
  PType.resize(0);

  PMTCathodeHitX.clear();  
  PMTCathodeHitX.resize(0);
  PMTCathodeHitY.clear();  
  PMTCathodeHitY.resize(0);
  PMTCathodeHitZ.clear();  
  PMTCathodeHitZ.resize(0);

  PMTWindowReflectionAngle.clear();  
  PMTWindowReflectionAngle.resize(0);

  R1PEs.clear();
  R1PEs.resize(0);
  R2PEs.clear();
  R2PEs.resize(0);
  R3PEs.clear();
  R3PEs.resize(0);
  R4PEs.clear();
  R4PEs.resize(0);
  R5PEs.clear();
  R5PEs.resize(0);
  R6PEs.clear();
  R6PEs.resize(0);
  R7PEs.clear();
  R7PEs.resize(0);
  R8PEs.clear();
  R8PEs.resize(0);
  R9PEs.clear();
  R9PEs.resize(0);
  R10PEs.clear();
  R10PEs.resize(0);
  R11PEs.clear();
  R11PEs.resize(0);
  R12PEs.clear();
  R12PEs.resize(0);
  R13PEs.clear();
  R13PEs.resize(0);
  R14PEs.clear();
  R14PEs.resize(0);
  R15PEs.clear();
  R15PEs.resize(0);
  R16PEs.clear();
  R16PEs.resize(0);

  R1SoloPEs.clear();
  R1SoloPEs.resize(0);
  R2SoloPEs.clear();
  R2SoloPEs.resize(0);
  R3SoloPEs.clear();
  R3SoloPEs.resize(0);
  R4SoloPEs.clear();
  R4SoloPEs.resize(0);
  R5SoloPEs.clear();
  R5SoloPEs.resize(0);
  R6SoloPEs.clear();
  R6SoloPEs.resize(0);
  R7SoloPEs.clear();
  R7SoloPEs.resize(0);
  R8SoloPEs.clear();
  R8SoloPEs.resize(0);
  R9SoloPEs.clear();
  R9SoloPEs.resize(0);
  R10SoloPEs.clear();
  R10SoloPEs.resize(0);
  R11SoloPEs.clear();
  R11SoloPEs.resize(0);
  R12SoloPEs.clear();
  R12SoloPEs.resize(0);
  R13SoloPEs.clear();
  R13SoloPEs.resize(0);
  R14SoloPEs.clear();
  R14SoloPEs.resize(0);
  R15SoloPEs.clear();
  R15SoloPEs.resize(0);
  R16SoloPEs.clear();
  R16SoloPEs.resize(0);

}	


void MOLLEROptGeneralEvent::AddQuartzTrackData(Float_t QTrackL, Int_t QSteps)
{
  QuartzTrackLength = QTrackL;  
  QuartzSteps = QSteps;  
}

/*void MOLLEROptGeneralEvent::AddScintTrackData(Float_t STrackL, Int_t SSteps)
{
  ScintTrackLength = STrackL;  
  ScintSteps = SSteps;  
}*/

void MOLLEROptGeneralEvent::AddLightGuideTrackData(Float_t LGTrackL, Int_t LGSteps)
{
  LightGuideTrackLength.push_back(LGTrackL);
  LightGuideSteps.push_back(LGSteps);  
}

