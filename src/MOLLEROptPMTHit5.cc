#include "MOLLEROptPMTHit5.hh"

MOLLEROptPMTHit5::MOLLEROptPMTHit5()
{
  TrackID = -1;
  // PhotonEnergy.clear();
  // PhotonEnergy.resize(0);
  // HitX.clear();
  // HitX.resize(0);
  // HitY.clear();
  // HitY.resize(0);

}

void MOLLEROptPMTHit5::AddPhotonHit(G4ThreeVector pos, G4double eng)
{
  Particle = 0;
  PhotonEnergy = eng;
  HitX  = pos.x();
  HitY  = pos.y();
}

MOLLEROptPMTHit5::~MOLLEROptPMTHit5()
{

}
