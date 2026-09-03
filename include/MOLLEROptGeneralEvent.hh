#ifndef MOLLEROptGeneralEvent_h
#define MOLLEROptGeneralEvent_h

#include "cpp_include.h"
#include "Root_include.h"

class MOLLEROptGeneralEvent : public TObject
{

private:

  //vector <Int_t> PType;
  //vector <Int_t> ElectronTrackID;
  //vector <Int_t> PhotonTrackID;
  //vector <Int_t> ParentID;
  //vector <Int_t> EventID;

  vector <Float_t> InitialTrackMomDirectionX;
  vector <Float_t> InitialTrackMomDirectionY;
  vector <Float_t> InitialTrackMomDirectionZ;

  vector <Float_t> InitialBeamEnergy;
  vector <Float_t> InitialBeamAngle;

  vector <Int_t> PMTTrackHit;
  vector <Float_t> PMTPhotonEnergy;
  vector <Float_t> PMTCathodeHitX;
  vector <Float_t> PMTCathodeHitY;
  vector <Float_t> PMTCathodeHitZ;
  vector <Float_t> PMTWindowReflectionAngle;
  
  vector <Int_t> LightGuideTrackHit;
  //vector <Int_t> LightGuideReflectionProcess;
  vector <Float_t> LightGuidePhotonEnergy;
  //vector <Float_t> LightGuideStepLength;
  vector <Float_t> LightGuideIncidentPhotonAngle;

  vector <Int_t>  QuartzPhotonAtExit;
  vector <Float_t> QuartzPhotonEnergy;
  vector <Float_t> QuartzSecondaryPhotonAngle;
  vector <Float_t> QuartzIncidentPhotonAngle;

  vector <Int_t> RingQuartzTrackHit;

  vector <Int_t> Gem1TrackHit;
  vector <Int_t> Gem2TrackHit;
  vector <Int_t> Gem3TrackHit;

  vector <Float_t> RingTileHitX;
  vector <Float_t> RingTileHitY;
  vector <Float_t> RingTileHitZ;

  vector <Float_t> Gem1HitX;
  vector <Float_t> Gem1HitY;
  vector <Float_t> Gem1HitZ;

  vector <Float_t> Gem2HitX;
  vector <Float_t> Gem2HitY;
  vector <Float_t> Gem2HitZ;

  vector <Float_t> Gem3HitX;
  vector <Float_t> Gem3HitY;
  vector <Float_t> Gem3HitZ;

  vector <Int_t> RingPEs;

public:


  MOLLEROptGeneralEvent();
  virtual ~MOLLEROptGeneralEvent();

  void Initialize();

  void AddLightGuidePhotonEnergy(Float_t eng) {LightGuidePhotonEnergy.push_back(eng);};
  void AddLightGuideTrackHit(Int_t tID){LightGuideTrackHit.push_back(tID);};
  //void AddLightGuideStepLength(Float_t dx){ LightGuideStepLength.push_back(dx);};
  void AddLightGuideIncidentPhotonAngle(Float_t angle) {LightGuideIncidentPhotonAngle.push_back(angle);};

  void AddQuartzPhotonEnergy(Float_t eng) {QuartzPhotonEnergy.push_back(eng);};
  //void AddQuartzStepLength(Float_t dx){ QuartzStepLength.push_back(dx);};
  //void AddQuartzElectronStepLength(Float_t dx) {QuartzElectronStepLength.push_back(dx);};
  void AddQuartzIncidentPhotonAngle(Float_t angle) {QuartzIncidentPhotonAngle.push_back(angle);};
  //void AddQuartzStepNPhotons(Int_t n){QuartzStepNPhotons.push_back(n);};
  void AddQuartzPhotonAtExitFlag(Int_t flag){QuartzPhotonAtExit.push_back(flag);};
  void AddQuartzTrackSecPhotonAngle(Float_t angle) {QuartzSecondaryPhotonAngle.push_back(angle);}

  //void AddElectronTrackID(Int_t tID){ElectronTrackID.push_back(tID);};
  //void AddPhotonTrackID(Int_t tID){PhotonTrackID.push_back(tID);};

  void AddInitialBeamEnergy(Float_t eng) {InitialBeamEnergy.push_back(eng);};
  void AddInitialBeamAngle(Float_t aang) {InitialBeamAngle.push_back(aang);};

  void AddPMTPhotonEnergy(Float_t eng) {PMTPhotonEnergy.push_back(eng);};
  void AddPMTTrackHit(Int_t tID) {PMTTrackHit.push_back(tID);};
  void AddPMTHitPositionX(Float_t x) {PMTCathodeHitX.push_back(x);};
  void AddPMTHitPositionY(Float_t y) {PMTCathodeHitY.push_back(y);};
  void AddPMTHitPositionZ(Float_t z) {PMTCathodeHitZ.push_back(z);};
  void AddPMTWindowReflectionAngle(Float_t ang) {PMTWindowReflectionAngle.push_back(ang);};
  
  void AddRingQuartzTrackHit(Int_t tID){RingQuartzTrackHit.push_back(tID);};

  void AddGem1TrackHit(Int_t tID){Gem1TrackHit.push_back(tID);};
  void AddGem2TrackHit(Int_t tID){Gem2TrackHit.push_back(tID);};
  void AddGem3TrackHit(Int_t tID){Gem3TrackHit.push_back(tID);};

  void AddRingQuartzHitPositionX(Float_t x) {RingTileHitX.push_back(x);};
  void AddRingQuartzHitPositionY(Float_t y) {RingTileHitY.push_back(y);};
  void AddRingQuartzHitPositionZ(Float_t z) {RingTileHitZ.push_back(z);};

  void AddGem1HitPositionX(Float_t x) {Gem1HitX.push_back(x);};
  void AddGem1HitPositionY(Float_t y) {Gem1HitY.push_back(y);};
  void AddGem1HitPositionZ(Float_t z) {Gem1HitZ.push_back(z);};

  void AddGem2HitPositionX(Float_t x) {Gem2HitX.push_back(x);};
  void AddGem2HitPositionY(Float_t y) {Gem2HitY.push_back(y);};
  void AddGem2HitPositionZ(Float_t z) {Gem2HitZ.push_back(z);};

  void AddGem3HitPositionX(Float_t x) {Gem3HitX.push_back(x);};
  void AddGem3HitPositionY(Float_t y) {Gem3HitY.push_back(y);};
  void AddGem3HitPositionZ(Float_t z) {Gem3HitZ.push_back(z);};

  void AddRingPEs(Int_t pes) {RingPEs.push_back(pes);};
 
  void AddTrackInitMomDirection(Float_t x, Float_t y, Float_t z) {
    InitialTrackMomDirectionX.push_back(x);
    InitialTrackMomDirectionY.push_back(y);
    InitialTrackMomDirectionZ.push_back(z);
  };

  //void SetTrackParentID(Int_t ID) {ParentID.push_back(ID);};
  //void SetEventID(Int_t ID) {EventID.push_back(ID);};
  
  ClassDef(MOLLEROptGeneralEvent,1)

};

#endif 
