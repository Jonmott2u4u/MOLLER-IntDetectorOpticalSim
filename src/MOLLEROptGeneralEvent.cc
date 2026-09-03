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

  LightGuideIncidentPhotonAngle.clear();
  QuartzIncidentPhotonAngle.clear();
  QuartzSecondaryPhotonAngle.clear();

  RingQuartzTrackHit.clear(); 
  LightGuideTrackHit.clear(); 
  PMTTrackHit.clear();


  Scint1TrackHit.clear();
  Scint2TrackHit.clear();
  Scint3TrackHit.clear();

  RingTileHitX.clear();  
  RingTileHitY.clear();  
  RingTileHitZ.clear();  

  Scint1HitX.clear();
  Scint1HitY.clear();
  Scint1HitZ.clear();

  Scint2HitX.clear();
  Scint2HitY.clear();
  Scint2HitZ.clear();

  Scint3HitX.clear();
  Scint3HitY.clear();
  Scint3HitZ.clear();

  PMTPhotonEnergy.clear();  
  PMTPhotonWavelength.clear();  

  InitialBeamEnergy.clear();
  InitialBeamAngle.clear();

  QuartzPhotonEnergy.clear();
  LightGuidePhotonEnergy.clear();  

  InitialTrackMomDirectionX.clear();
  InitialTrackMomDirectionY.clear();
  InitialTrackMomDirectionZ.clear();

  PMTCathodeHitX.clear();  
  PMTCathodeHitY.clear();  
  PMTCathodeHitZ.clear();  

  QuartzPhotonAtExit.clear();
  PMTWindowReflectionAngle.clear();  

  RingPEs.clear();

}	