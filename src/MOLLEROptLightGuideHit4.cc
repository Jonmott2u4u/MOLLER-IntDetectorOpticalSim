#include "MOLLEROptLightGuideHit4.hh"

MOLLEROptLightGuideHit4::MOLLEROptLightGuideHit4()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptLightGuideHit4::~MOLLEROptLightGuideHit4()
{

}

