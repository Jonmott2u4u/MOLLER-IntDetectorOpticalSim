#ifndef MOLLEROptDetectorEvent_h
#define MOLLEROptDetectorEvent_h

#include "cpp_include.h"
#include "Root_include.h"

class MOLLEROptDetectorEvent : public TObject
{

private:

  vector <Int_t> PType;
  // vector <Int_t> ElectronTrackID;
  // vector <Int_t> PhotonTrackID;
  Int_t ElectronTrackID;
  Int_t PhotonTrackID;
  Int_t ParentID;
  Int_t EventID;

  Float_t InitialTrackMomDirectionX;
  Float_t InitialTrackMomDirectionY;
  Float_t InitialTrackMomDirectionZ;
  
  // vector <Int_t> PMTTrackHit;
  Int_t PMTTrackHit;
  
  vector <Float_t> PMTPhotonEnergy;
  vector <Float_t> PMTCathodeHitX;
  vector <Float_t> PMTCathodeHitY;
  vector <Float_t> PMTCathodeHitZ;
  vector <Float_t> PMTWindowReflectionAngle;
  
  vector <Int_t> LightGuideTrackHit;
  vector <Float_t> LightGuidePhotonEnergy;
  vector <Int_t> LightGuideSteps;
  vector <Float_t> LightGuideStepLength;
  vector <Float_t> LightGuideTrackLength;
  vector <Float_t> LightGuideIncidentPhotonAngle;
  vector <Int_t> LightGuideReflectionProcess;

  vector <Int_t> R1QuartzTrackHit;
  vector <Int_t> R2QuartzTrackHit;
  vector <Int_t> R3QuartzTrackHit;
  vector <Int_t> R4QuartzTrackHit;
  vector <Int_t> R5QuartzTrackHit;
  vector <Int_t> R6QuartzTrackHit;
  vector <Int_t> R7QuartzTrackHit;
  vector <Int_t> R8QuartzTrackHit;
  vector <Int_t> ScintTrackHit;
  vector <Int_t> GEMScint1TrackHit;
  vector <Int_t> GEMScint2TrackHit;

  vector <Float_t> R1QuartzHitX;
  vector <Float_t> R2QuartzHitX;
  vector <Float_t> R3QuartzHitX;
  vector <Float_t> R4QuartzHitX;
  vector <Float_t> R5QuartzHitX;
  vector <Float_t> R6QuartzHitX;
  vector <Float_t> R7QuartzHitX;
  vector <Float_t> R8QuartzHitX;
  vector <Float_t> ScintHitX;
  vector <Float_t> GEMScint1HitX;
  vector <Float_t> GEMScint2HitX;
  vector <Float_t> R1QuartzHitY;
  vector <Float_t> R2QuartzHitY;
  vector <Float_t> R3QuartzHitY;
  vector <Float_t> R4QuartzHitY;
  vector <Float_t> R5QuartzHitY;
  vector <Float_t> R6QuartzHitY;
  vector <Float_t> R7QuartzHitY;
  vector <Float_t> R8QuartzHitY;
  vector <Float_t> ScintHitY;
  vector <Float_t> GEMScint1HitY;
  vector <Float_t> GEMScint2HitY;
  vector <Float_t> R1QuartzHitZ;
  vector <Float_t> R2QuartzHitZ;
  vector <Float_t> R3QuartzHitZ;
  vector <Float_t> R4QuartzHitZ;
  vector <Float_t> R5QuartzHitZ;
  vector <Float_t> R6QuartzHitZ;
  vector <Float_t> R7QuartzHitZ;
  vector <Float_t> R8QuartzHitZ;
  vector <Float_t> ScintHitZ;
  vector <Float_t> GEMScint1HitZ;
  vector <Float_t> GEMScint2HitZ;

  // vector <Float_t> QuartzPhotonEnergy;
  Float_t QuartzPhotonEnergy;
  vector <Float_t> QuartzSecondaryPhotonAngle;
  // vector <Int_t> QuartzSteps;
  Int_t QuartzSteps;
  vector <Float_t> QuartzStepLength;
  vector <Float_t> QuartzElectronStepLength;
  vector <Float_t> QuartzIncidentPhotonAngle;
  // vector <Float_t> QuartzTrackLength;
  Float_t QuartzTrackLength;
  vector <Int_t>  QuartzStepNPhotons;
  // vector <Int_t>  QuartzPhotonAtExit;
  Int_t  QuartzPhotonAtExit;

  vector <Int_t> TotalSteps;
  vector <Float_t> TotalTrackLength;  
  

public:


  MOLLEROptDetectorEvent();
  virtual ~MOLLEROptDetectorEvent();

  void Initialize();

  void AddLightGuidePhotonEnergy(Float_t eng) {LightGuidePhotonEnergy.push_back(eng);};
  void AddLightGuideTrackHit(Int_t tID){LightGuideTrackHit.push_back(tID);};
  void AddLightGuideStepLength(Float_t dx){ LightGuideStepLength.push_back(dx);};
  void AddLightGuideIncidentPhotonAngle(Float_t angle) {LightGuideIncidentPhotonAngle.push_back(angle);};
  void AddLightGuideReflectionProcess(Int_t proc){LightGuideReflectionProcess.push_back(proc);};
  void AddLightGuideTrackData(Float_t LGTrackL, Int_t LGSteps);

  // void AddQuartzPhotonEnergy(Float_t eng) {QuartzPhotonEnergy.push_back(eng);};
  void AddQuartzPhotonEnergy(Float_t eng) {QuartzPhotonEnergy = eng;};
  void AddQuartzStepLength(Float_t dx){ QuartzStepLength.push_back(dx);};
  void AddQuartzElectronStepLength(Float_t dx) {QuartzElectronStepLength.push_back(dx);};
  void AddQuartzIncidentPhotonAngle(Float_t angle) {QuartzIncidentPhotonAngle.push_back(angle);};
  void AddQuartzTrackData(Float_t QTrackL, Int_t QSteps);
  void AddQuartzStepNPhotons(Int_t n){QuartzStepNPhotons.push_back(n);};
  // void AddQuartzPhotonAtExitFlag(Int_t flag){QuartzPhotonAtExit.push_back(flag);};
  void AddQuartzPhotonAtExitFlag(Int_t flag){QuartzPhotonAtExit = flag;};
  void AddQuartzTrackSecPhotonAngle(Float_t angle) {QuartzSecondaryPhotonAngle.push_back(angle);}

  // void AddElectronTrackID(Int_t tID){ElectronTrackID.push_back(tID);};
  // void AddPhotonTrackID(Int_t tID){PhotonTrackID.push_back(tID);};
  void AddElectronTrackID(Int_t tID){ElectronTrackID = tID;};
  void AddPhotonTrackID(Int_t tID){PhotonTrackID = tID;};

  // void AddParticleType(Int_t pTyp) {PType.push_back(pTyp);};

  void AddPMTPhotonEnergy(Float_t eng) {PMTPhotonEnergy.push_back(eng);};
  // void AddPMTTrackHit(Int_t tID){PMTTrackHit.push_back(tID);};
  void AddPMTTrackHit(Int_t tID){PMTTrackHit = tID;};
  void AddPMTHitPositionX(Float_t x) {PMTCathodeHitX.push_back(x);};
  void AddPMTHitPositionY(Float_t y) {PMTCathodeHitY.push_back(y);};
  void AddPMTHitPositionZ(Float_t z) {PMTCathodeHitZ.push_back(z);};
  void AddPMTWindowReflectionAngle(Float_t ang) {PMTWindowReflectionAngle.push_back(ang);};
  
  void AddR1QuartzTrackHit(Int_t tID){R1QuartzTrackHit.push_back(tID);};
  void AddR2QuartzTrackHit(Int_t tID){R2QuartzTrackHit.push_back(tID);};
  void AddR3QuartzTrackHit(Int_t tID){R3QuartzTrackHit.push_back(tID);};
  void AddR4QuartzTrackHit(Int_t tID){R4QuartzTrackHit.push_back(tID);};
  void AddR5QuartzTrackHit(Int_t tID){R5QuartzTrackHit.push_back(tID);};
  void AddR6QuartzTrackHit(Int_t tID){R6QuartzTrackHit.push_back(tID);};
  void AddR7QuartzTrackHit(Int_t tID){R7QuartzTrackHit.push_back(tID);};
  void AddR8QuartzTrackHit(Int_t tID){R8QuartzTrackHit.push_back(tID);};
  void AddScintTrackHit(Int_t tID){ScintTrackHit.push_back(tID);};
  void AddGEMScint1TrackHit(Int_t tID){GEMScint1TrackHit.push_back(tID);};
  void AddGEMScint2TrackHit(Int_t tID){GEMScint2TrackHit.push_back(tID);};

  void AddR1QuartzHitPositionX(Float_t x) {R1QuartzHitX.push_back(x);};
  void AddR1QuartzHitPositionY(Float_t y) {R1QuartzHitY.push_back(y);};
  void AddR1QuartzHitPositionZ(Float_t z) {R1QuartzHitZ.push_back(z);};
  void AddR2QuartzHitPositionX(Float_t x) {R2QuartzHitX.push_back(x);};
  void AddR2QuartzHitPositionY(Float_t y) {R2QuartzHitY.push_back(y);};
  void AddR2QuartzHitPositionZ(Float_t z) {R2QuartzHitZ.push_back(z);};
  void AddR3QuartzHitPositionX(Float_t x) {R3QuartzHitX.push_back(x);};
  void AddR3QuartzHitPositionY(Float_t y) {R3QuartzHitY.push_back(y);};
  void AddR3QuartzHitPositionZ(Float_t z) {R3QuartzHitZ.push_back(z);};
  void AddR4QuartzHitPositionX(Float_t x) {R4QuartzHitX.push_back(x);};
  void AddR4QuartzHitPositionY(Float_t y) {R4QuartzHitY.push_back(y);};
  void AddR4QuartzHitPositionZ(Float_t z) {R4QuartzHitZ.push_back(z);};
  void AddR5QuartzHitPositionX(Float_t x) {R5QuartzHitX.push_back(x);};
  void AddR5QuartzHitPositionY(Float_t y) {R5QuartzHitY.push_back(y);};
  void AddR5QuartzHitPositionZ(Float_t z) {R5QuartzHitZ.push_back(z);};
  void AddR6QuartzHitPositionX(Float_t x) {R6QuartzHitX.push_back(x);};
  void AddR6QuartzHitPositionY(Float_t y) {R6QuartzHitY.push_back(y);};
  void AddR6QuartzHitPositionZ(Float_t z) {R6QuartzHitZ.push_back(z);};
  void AddR7QuartzHitPositionX(Float_t x) {R7QuartzHitX.push_back(x);};
  void AddR7QuartzHitPositionY(Float_t y) {R7QuartzHitY.push_back(y);};
  void AddR7QuartzHitPositionZ(Float_t z) {R7QuartzHitZ.push_back(z);};
  void AddR8QuartzHitPositionX(Float_t x) {R8QuartzHitX.push_back(x);};
  void AddR8QuartzHitPositionY(Float_t y) {R8QuartzHitY.push_back(y);};
  void AddR8QuartzHitPositionZ(Float_t z) {R8QuartzHitZ.push_back(z);};
  void AddScintHitPositionX(Float_t x) {ScintHitX.push_back(x);};
  void AddScintHitPositionY(Float_t y) {ScintHitY.push_back(y);};
  void AddScintHitPositionZ(Float_t z) {ScintHitZ.push_back(z);};
  void AddGEMScint1HitPositionX(Float_t x) {GEMScint1HitX.push_back(x);};
  void AddGEMScint1HitPositionY(Float_t y) {GEMScint1HitY.push_back(y);};
  void AddGEMScint1HitPositionZ(Float_t z) {GEMScint1HitZ.push_back(z);};
  void AddGEMScint2HitPositionX(Float_t x) {GEMScint2HitX.push_back(x);};
  void AddGEMScint2HitPositionY(Float_t y) {GEMScint2HitY.push_back(y);};
  void AddGEMScint2HitPositionZ(Float_t z) {GEMScint2HitZ.push_back(z);};

  void AddTrackInitMomDirection(Float_t x, Float_t y, Float_t z) {
    InitialTrackMomDirectionX = x;
    InitialTrackMomDirectionY = y;
    InitialTrackMomDirectionZ = z;
  };
  void SetTrackParentID(Int_t ID) {ParentID = ID;};
  void SetEventID(Int_t ID) {EventID = ID;};
  
  ClassDef(MOLLEROptDetectorEvent,1)

};

#endif 
