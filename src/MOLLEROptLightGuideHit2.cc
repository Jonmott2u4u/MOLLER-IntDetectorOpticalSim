#include "MOLLEROptLightGuideHit2.hh"

MOLLEROptLightGuideHit2::MOLLEROptLightGuideHit2()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit2::~MOLLEROptLightGuideHit2()
{

}

