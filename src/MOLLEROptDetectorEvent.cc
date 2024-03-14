#include "MOLLEROptDetectorEvent.hh"


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


MOLLEROptDetectorEvent::MOLLEROptDetectorEvent() 
{
  Initialize();
} 

MOLLEROptDetectorEvent::~MOLLEROptDetectorEvent()
{ 

}

void MOLLEROptDetectorEvent::Initialize()
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

  LightGuideTrackLength.clear();  
  LightGuideTrackLength.resize(0);
  
  TotalSteps.clear();  
  TotalSteps.resize(0);

  QuartzSteps = 0;

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
  ScintTrackHit.clear();  
  ScintTrackHit.resize(0);
  GEMScint1TrackHit.clear();  
  GEMScint1TrackHit.resize(0);
  GEMScint2TrackHit.clear();  
  GEMScint2TrackHit.resize(0);

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
  ScintillatorHitX.clear();  
  ScintillatorHitX.resize(0);
  GEMScintillator1HitX.clear();  
  GEMScintillator1HitX.resize(0);
  GEMScintillator2HitX.clear();  
  GEMScintillator2HitX.resize(0);

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
  ScintillatorHitY.clear();  
  ScintillatorHitY.resize(0);
  GEMScintillator1HitY.clear();  
  GEMScintillator1HitY.resize(0);
  GEMScintillator2HitY.clear();  
  GEMScintillator2HitY.resize(0);

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
  ScintillatorHitZ.clear();  
  ScintillatorHitZ.resize(0);
  GEMScintillator1HitZ.clear();  
  GEMScintillator1HitZ.resize(0);
  GEMScintillator2HitZ.clear();  
  GEMScintillator2HitZ.resize(0);

  PMTPhotonEnergy.clear();  
  PMTPhotonEnergy.resize(0);

  InitialBeamEnergy.clear();
  InitialBeamEnergy.resize(0);

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

}	


void MOLLEROptDetectorEvent::AddQuartzTrackData(Float_t QTrackL, Int_t QSteps)
{
  QuartzTrackLength = QTrackL;  
  QuartzSteps = QSteps;  
  // QuartzTrackLength.push_back(QTrackL);  
  // QuartzSteps.push_back(QSteps);  
}

void MOLLEROptDetectorEvent::AddLightGuideTrackData(Float_t LGTrackL, Int_t LGSteps)
{
  LightGuideTrackLength.push_back(LGTrackL);
  LightGuideSteps.push_back(LGSteps);  
}

