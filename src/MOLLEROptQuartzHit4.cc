#include "MOLLEROptQuartzHit4.hh"

MOLLEROptQuartzHit4::MOLLEROptQuartzHit4()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptQuartzHit4::~MOLLEROptQuartzHit4()
{

}
