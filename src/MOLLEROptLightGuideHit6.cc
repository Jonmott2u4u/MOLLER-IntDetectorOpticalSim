#include "MOLLEROptLightGuideHit6.hh"

MOLLEROptLightGuideHit6::MOLLEROptLightGuideHit6()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit6::~MOLLEROptLightGuideHit6()
{

}

