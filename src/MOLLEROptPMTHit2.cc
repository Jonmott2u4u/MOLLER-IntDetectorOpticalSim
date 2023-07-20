#include "MOLLEROptPMTHit2.hh"

MOLLEROptPMTHit2::MOLLEROptPMTHit2()
{
  TrackID = -1;
  // PhotonEnergy.clear();
  // PhotonEnergy.resize(0);
  // HitX.clear();
  // HitX.resize(0);
  // HitY.clear();
  // HitY.resize(0);

}

void MOLLEROptPMTHit2::AddPhotonHit(G4ThreeVector pos, G4double eng)
{
  Particle = 0;
  PhotonEnergy = eng;
  HitX  = pos.x();
  HitY  = pos.y();
}

MOLLEROptPMTHit2::~MOLLEROptPMTHit2()
{

}
