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

  // QuartzTrackLength.clear();  
  // QuartzTrackLength.resize(0);

  QuartzTrackLength = 0;

  LightGuideTrackLength.clear();  
  LightGuideTrackLength.resize(0);
  
  TotalSteps.clear();  
  TotalSteps.resize(0);

  // QuartzSteps.clear();  
  // QuartzSteps.resize(0);

  QuartzSteps = 0;

  LightGuideSteps.clear();  
  LightGuideSteps.resize(0);

  // PMTTrackHit.clear();  
  // PMTTrackHit.resize(0);

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

  R1QuartzHitX.clear();  
  R1QuartzHitX.resize(0);
  R2QuartzHitX.clear();  
  R2QuartzHitX.resize(0);
  R3QuartzHitX.clear();  
  R3QuartzHitX.resize(0);
  R4QuartzHitX.clear();  
  R4QuartzHitX.resize(0);
  R5QuartzHitX.clear();  
  R5QuartzHitX.resize(0);
  R6QuartzHitX.clear();  
  R6QuartzHitX.resize(0);
  R7QuartzHitX.clear();  
  R7QuartzHitX.resize(0);
  R8QuartzHitX.clear();  
  R8QuartzHitX.resize(0);
  ScintHitX.clear();  
  ScintHitX.resize(0);

  R1QuartzHitY.clear();  
  R1QuartzHitY.resize(0);
  R2QuartzHitY.clear();  
  R2QuartzHitY.resize(0);
  R3QuartzHitY.clear();  
  R3QuartzHitY.resize(0);
  R4QuartzHitY.clear();  
  R4QuartzHitY.resize(0);
  R5QuartzHitY.clear();  
  R5QuartzHitY.resize(0);
  R6QuartzHitY.clear();  
  R6QuartzHitY.resize(0);
  R7QuartzHitY.clear();  
  R7QuartzHitY.resize(0);
  R8QuartzHitY.clear();  
  R8QuartzHitY.resize(0);
  ScintHitY.clear();  
  ScintHitY.resize(0);

  R1QuartzHitZ.clear();  
  R1QuartzHitZ.resize(0);
  R2QuartzHitZ.clear();  
  R2QuartzHitZ.resize(0);
  R3QuartzHitZ.clear();  
  R3QuartzHitZ.resize(0);
  R4QuartzHitZ.clear();  
  R4QuartzHitZ.resize(0);
  R5QuartzHitZ.clear();  
  R5QuartzHitZ.resize(0);
  R6QuartzHitZ.clear();  
  R6QuartzHitZ.resize(0);
  R7QuartzHitZ.clear();  
  R7QuartzHitZ.resize(0);
  R8QuartzHitZ.clear();  
  R8QuartzHitZ.resize(0);
  ScintHitZ.clear();  
  ScintHitZ.resize(0);

  PMTPhotonEnergy.clear();  
  PMTPhotonEnergy.resize(0);

  // QuartzPhotonEnergy.clear();  
  // QuartzPhotonEnergy.resize(0);

  QuartzPhotonEnergy = 0;

  QuartzStepNPhotons.clear();
  QuartzStepNPhotons.resize(0);
  
  LightGuidePhotonEnergy.clear();  
  LightGuidePhotonEnergy.resize(0);

  // ElectronTrackID.clear();
  // ElectronTrackID.resize(0);

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

