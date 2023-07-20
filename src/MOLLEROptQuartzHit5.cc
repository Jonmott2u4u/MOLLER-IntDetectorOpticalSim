#include "MOLLEROptQuartzHit5.hh"

MOLLEROptQuartzHit5::MOLLEROptQuartzHit5()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit5::~MOLLEROptQuartzHit5()
{

}
