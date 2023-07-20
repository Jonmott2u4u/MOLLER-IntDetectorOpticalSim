#include "MOLLEROptQuartzHit2.hh"

MOLLEROptQuartzHit2::MOLLEROptQuartzHit2()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit2::~MOLLEROptQuartzHit2()
{

}
