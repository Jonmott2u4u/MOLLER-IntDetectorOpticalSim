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

  RingQuartzTrackHit.clear();  
  RingQuartzTrackHit.resize(0);

  Gem1TrackHit.clear();  
  Gem1TrackHit.resize(0);
  Gem2TrackHit.clear();  
  Gem2TrackHit.resize(0);
  Gem3TrackHit.clear();  
  Gem3TrackHit.resize(0);

  RingTileHitX.clear();  
  RingTileHitX.resize(0);
  RingTileHitY.clear();  
  RingTileHitY.resize(0);
  RingTileHitZ.clear();  
  RingTileHitZ.resize(0);

  Gem1HitX.clear();  
  Gem1HitX.resize(0);
  Gem1HitY.clear();  
  Gem1HitY.resize(0);
  Gem1HitZ.clear();  
  Gem1HitZ.resize(0);

  Gem2HitX.clear();  
  Gem2HitX.resize(0);
  Gem2HitY.clear();  
  Gem2HitY.resize(0);
  Gem2HitZ.clear();  
  Gem2HitZ.resize(0);

  Gem3HitX.clear();  
  Gem3HitX.resize(0);
  Gem3HitY.clear();  
  Gem3HitY.resize(0);
  Gem3HitZ.clear();  
  Gem3HitZ.resize(0);

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

  RingPEs.clear();
  RingPEs.resize(0);

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

