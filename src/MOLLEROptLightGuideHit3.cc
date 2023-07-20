#include "MOLLEROptLightGuideHit3.hh"

MOLLEROptLightGuideHit3::MOLLEROptLightGuideHit3()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit3::~MOLLEROptLightGuideHit3()
{

}

