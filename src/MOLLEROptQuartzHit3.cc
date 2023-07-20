#include "MOLLEROptQuartzHit3.hh"

MOLLEROptQuartzHit3::MOLLEROptQuartzHit3()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit3::~MOLLEROptQuartzHit3()
{

}
