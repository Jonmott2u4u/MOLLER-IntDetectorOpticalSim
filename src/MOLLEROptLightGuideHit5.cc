#include "MOLLEROptLightGuideHit5.hh"

MOLLEROptLightGuideHit5::MOLLEROptLightGuideHit5()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit5::~MOLLEROptLightGuideHit5()
{

}

