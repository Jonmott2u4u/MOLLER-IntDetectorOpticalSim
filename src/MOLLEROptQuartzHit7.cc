#include "MOLLEROptQuartzHit7.hh"

MOLLEROptQuartzHit7::MOLLEROptQuartzHit7()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit7::~MOLLEROptQuartzHit7()
{

}
