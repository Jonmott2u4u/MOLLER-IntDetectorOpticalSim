#ifndef MOLLEROptTrackingAction_h
#define MOLLEROptTrackingAction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "G4RandomDirection.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptTrackingReadout2.hh"
#include "MOLLEROptTrackingReadout3.hh"
#include "MOLLEROptTrackingReadout4.hh"
#include "MOLLEROptTrackingReadout5.hh"
#include "MOLLEROptTrackingReadout6.hh"
#include "MOLLEROptTrackingReadout7.hh"
#include "MOLLEROptTrackingReadout8.hh"

class MOLLEROptTrackingAction : public G4UserTrackingAction
{

public:

   MOLLEROptTrackingAction(MOLLEROptTrackingReadout*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout2*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout3*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout4*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout5*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout6*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout7*);
   MOLLEROptTrackingAction(MOLLEROptTrackingReadout8*);
  ~MOLLEROptTrackingAction();

 
 void  PreUserTrackingAction(const G4Track* aTrack, const G4Track* aTrack2, const G4Track* aTrack3, const G4Track* aTrack4, const G4Track* aTrack5, const G4Track* aTrack6, const G4Track* aTrack7, const G4Track* aTrack8);
  void  PostUserTrackingAction(const G4Track* aTrack, const G4Track* aTrack2, const G4Track* aTrack3, const G4Track* aTrack4, const G4Track* aTrack5, const G4Track* aTrack6, const G4Track* aTrack7, const G4Track* aTrack8);

private:
  
  MOLLEROptTrackingReadout*  TrackingReadout;
  MOLLEROptTrackingReadout2*  TrackingReadout2;
  MOLLEROptTrackingReadout3*  TrackingReadout3;
  MOLLEROptTrackingReadout4*  TrackingReadout4;
  MOLLEROptTrackingReadout5*  TrackingReadout5;
  MOLLEROptTrackingReadout6*  TrackingReadout6;
  MOLLEROptTrackingReadout7*  TrackingReadout7;
  MOLLEROptTrackingReadout8*  TrackingReadout8;
};

#endif
