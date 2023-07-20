#include "MOLLEROptQuartzHit6.hh"

MOLLEROptQuartzHit6::MOLLEROptQuartzHit6()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit6::~MOLLEROptQuartzHit6()
{

}
