#include "MOLLEROptScintHit.hh"

MOLLEROptScintHit::MOLLEROptScintHit()
{
  Particle      = -1;
  StepLength = 0.;
  PhotonEnergy = 0.;
  TrackID = -1;
  SecPhotonEnergy.clear();
  SecPhotonEnergy.resize(0);
}


MOLLEROptScintHit::~MOLLEROptScintHit()
{

}
