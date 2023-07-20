#include "MOLLEROptQuartzHit8.hh"

MOLLEROptQuartzHit8::MOLLEROptQuartzHit8()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit8::~MOLLEROptQuartzHit8()
{

}
