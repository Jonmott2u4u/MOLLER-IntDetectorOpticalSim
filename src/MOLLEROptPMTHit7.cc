#include "MOLLEROptPMTHit7.hh"

MOLLEROptPMTHit7::MOLLEROptPMTHit7()
{
  TrackID = -1;
  // PhotonEnergy.clear();
  // PhotonEnergy.resize(0);
  // HitX.clear();
  // HitX.resize(0);
  // HitY.clear();
  // HitY.resize(0);

}

void MOLLEROptPMTHit7::AddPhotonHit(G4ThreeVector pos, G4double eng)
{
  Particle = 0;
  PhotonEnergy = eng;
  HitX  = pos.x();
  HitY  = pos.y();
}

MOLLEROptPMTHit7::~MOLLEROptPMTHit7()
{

}
