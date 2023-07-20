#include "MOLLEROptLightGuideHit8.hh"

MOLLEROptLightGuideHit8::MOLLEROptLightGuideHit8()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit8::~MOLLEROptLightGuideHit8()
{

}

