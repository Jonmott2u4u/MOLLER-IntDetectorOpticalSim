#include "MOLLEROptPMTHit3.hh"

MOLLEROptPMTHit3::MOLLEROptPMTHit3()
{
  TrackID = -1;
  // PhotonEnergy.clear();
  // PhotonEnergy.resize(0);
  // HitX.clear();
  // HitX.resize(0);
  // HitY.clear();
  // HitY.resize(0);

}

void MOLLEROptPMTHit3::AddPhotonHit(G4ThreeVector pos, G4double eng)
{
  Particle = 0;
  PhotonEnergy = eng;
  HitX  = pos.x();
  HitY  = pos.y();
}

MOLLEROptPMTHit3::~MOLLEROptPMTHit3()
{

}
