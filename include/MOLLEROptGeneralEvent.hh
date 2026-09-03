#ifndef MOLLEROptGeneralEvent_h
#define MOLLEROptGeneralEvent_h

#include "cpp_include.h"
#include "Root_include.h"

class MOLLEROptGeneralEvent : public TObject
{

private:

  vector <Float_t> InitialTrackMomDirectionX;
  vector <Float_t> InitialTrackMomDirectionY;
  vector <Float_t> InitialTrackMomDirectionZ;

  vector <Float_t> InitialBeamEnergy;
  vector <Float_t> InitialBeamAngle;

  vector <Int_t> PMTTrackHit;
  vector <Float_t> PMTPhotonEnergy;
  vector <Float_t> PMTPhotonWavelength;
  vector <Float_t> PMTCathodeHitX;
  vector <Float_t> PMTCathodeHitY;
  vector <Float_t> PMTCathodeHitZ;
  vector <Float_t> PMTWindowReflectionAngle;
  
  vector <Int_t> LightGuideTrackHit;
  vector <Float_t> LightGuidePhotonEnergy;
  vector <Float_t> LightGuideIncidentPhotonAngle;

  vector <Int_t>  QuartzPhotonAtExit;
  vector <Float_t> QuartzPhotonEnergy;
  vector <Float_t> QuartzSecondaryPhotonAngle;
  vector <Float_t> QuartzIncidentPhotonAngle;

  vector <Int_t> RingQuartzTrackHit;

  vector <Int_t> Scint1TrackHit;
  vector <Int_t> Scint2TrackHit;
  vector <Int_t> Scint3TrackHit;

  vector <Float_t> RingTileHitX;
  vector <Float_t> RingTileHitY;
  vector <Float_t> RingTileHitZ;

  vector <Float_t> Scint1HitX;
  vector <Float_t> Scint1HitY;
  vector <Float_t> Scint1HitZ;

  vector <Float_t> Scint2HitX;
  vector <Float_t> Scint2HitY;
  vector <Float_t> Scint2HitZ;

  vector <Float_t> Scint3HitX;
  vector <Float_t> Scint3HitY;
  vector <Float_t> Scint3HitZ;

  vector <Int_t> RingPEs;

public:


  MOLLEROptGeneralEvent();
  virtual ~MOLLEROptGeneralEvent();

  void Initialize();

  void AddLightGuidePhotonEnergy(Float_t eng) {LightGuidePhotonEnergy.push_back(eng);};
  void AddLightGuideTrackHit(Int_t tID){LightGuideTrackHit.push_back(tID);};
  void AddLightGuideIncidentPhotonAngle(Float_t angle) {LightGuideIncidentPhotonAngle.push_back(angle);};

  void AddQuartzPhotonEnergy(Float_t eng) {QuartzPhotonEnergy.push_back(eng);};
  void AddQuartzIncidentPhotonAngle(Float_t angle) {QuartzIncidentPhotonAngle.push_back(angle);};
  void AddQuartzPhotonAtExitFlag(Int_t flag){QuartzPhotonAtExit.push_back(flag);};
  void AddQuartzTrackSecPhotonAngle(Float_t angle) {QuartzSecondaryPhotonAngle.push_back(angle);}

  void AddInitialBeamEnergy(Float_t eng) {InitialBeamEnergy.push_back(eng);};
  void AddInitialBeamAngle(Float_t aang) {InitialBeamAngle.push_back(aang);};

  void AddPMTPhotonEnergy(Float_t eng) {PMTPhotonEnergy.push_back(eng);};
  void AddPMTPhotonWavelength(Float_t wvl) {PMTPhotonWavelength.push_back(wvl);};
  void AddPMTTrackHit(Int_t tID){PMTTrackHit.push_back(tID);};
  void AddPMTHitPositionX(Float_t x) {PMTCathodeHitX.push_back(x);};
  void AddPMTHitPositionY(Float_t y) {PMTCathodeHitY.push_back(y);};
  void AddPMTHitPositionZ(Float_t z) {PMTCathodeHitZ.push_back(z);};
  void AddPMTWindowReflectionAngle(Float_t ang) {PMTWindowReflectionAngle.push_back(ang);};
  
  void AddRingQuartzTrackHit(Int_t tID){RingQuartzTrackHit.push_back(tID);};

  void AddScint1TrackHit(Int_t tID){Scint1TrackHit.push_back(tID);};
  void AddScint2TrackHit(Int_t tID){Scint2TrackHit.push_back(tID);};
  void AddScint3TrackHit(Int_t tID){Scint3TrackHit.push_back(tID);};

  void AddRingQuartzHitPositionX(Float_t x) {RingTileHitX.push_back(x);};
  void AddRingQuartzHitPositionY(Float_t y) {RingTileHitY.push_back(y);};
  void AddRingQuartzHitPositionZ(Float_t z) {RingTileHitZ.push_back(z);};

  void AddScint1HitPositionX(Float_t x) {Scint1HitX.push_back(x);};
  void AddScint1HitPositionY(Float_t y) {Scint1HitY.push_back(y);};
  void AddScint1HitPositionZ(Float_t z) {Scint1HitZ.push_back(z);};

  void AddScint2HitPositionX(Float_t x) {Scint2HitX.push_back(x);};
  void AddScint2HitPositionY(Float_t y) {Scint2HitY.push_back(y);};
  void AddScint2HitPositionZ(Float_t z) {Scint2HitZ.push_back(z);};

  void AddScint3HitPositionX(Float_t x) {Scint3HitX.push_back(x);};
  void AddScint3HitPositionY(Float_t y) {Scint3HitY.push_back(y);};
  void AddScint3HitPositionZ(Float_t z) {Scint3HitZ.push_back(z);};

  void AddRingPEs(Int_t pes) {RingPEs.push_back(pes);};
 
  void AddTrackInitMomDirection(Float_t x, Float_t y, Float_t z) {
    InitialTrackMomDirectionX.push_back(x);
    InitialTrackMomDirectionY.push_back(y);
    InitialTrackMomDirectionZ.push_back(z);
  };

  
  ClassDef(MOLLEROptGeneralEvent,1)

};

#endif 
