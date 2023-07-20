#include "MOLLEROptLightGuideHit7.hh"

MOLLEROptLightGuideHit7::MOLLEROptLightGuideHit7()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit7::~MOLLEROptLightGuideHit7()
{

}

