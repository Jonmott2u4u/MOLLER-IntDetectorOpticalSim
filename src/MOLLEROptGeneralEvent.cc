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

  QuartzIncidentPhotonAngle.clear();
  QuartzSecondaryPhotonAngle.clear();
  LightGuideIncidentPhotonAngle.clear();

  RingQuartzTrackHit.clear();
  LightGuideTrackHit.clear();
  PMTTrackHit.clear();

  Gem1TrackHit.clear();  
  Gem2TrackHit.clear();  
  Gem3TrackHit.clear();  

  RingTileHitX.clear();  
  RingTileHitY.clear();  
  RingTileHitZ.clear();  

  Gem1HitX.clear();  
  Gem1HitY.clear();  
  Gem1HitZ.clear();  

  Gem2HitX.clear();  
  Gem2HitY.clear();  
  Gem2HitZ.clear();  

  Gem3HitX.clear();  
  Gem3HitY.clear();  
  Gem3HitZ.clear();  

  PMTCathodeHitX.clear();  
  PMTCathodeHitY.clear();  
  PMTCathodeHitZ.clear(); 

  InitialTrackMomDirectionX.clear();
  InitialTrackMomDirectionY.clear();
  InitialTrackMomDirectionZ.clear();

  QuartzPhotonEnergy.clear();
  LightGuidePhotonEnergy.clear();  
  PMTPhotonEnergy.clear(); 
  InitialBeamEnergy.clear();

  InitialBeamAngle.clear();
  PMTWindowReflectionAngle.clear();
  QuartzIncidentPhotonAngle.clear();
  QuartzSecondaryPhotonAngle.clear();
  LightGuideIncidentPhotonAngle.clear();

  RingPEs.clear();

  //ElectronTrackID.clear();
  //PhotonTrackID.clear();
  //ParentID.clear();
  //EventID.clear();
  //PType.clear();    

}	