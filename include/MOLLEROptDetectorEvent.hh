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

  vector <Float_t> InitialBeamEnergy;
  vector <Float_t> InitialBeamAngle;

  Int_t PMTTrackHit;
  vector <Float_t> PMTPhotonEnergy;
  vector <Float_t> PMTCathodeHitX;
  vector <Float_t> PMTCathodeHitY;
  vector <Float_t> PMTCathodeHitZ;
  vector <Float_t> PMTWindowReflectionAngle;
  
  vector <Int_t> LightGuideSteps;
  vector <Int_t> LightGuideTrackHit;
  vector <Int_t> LightGuideReflectionProcess;
  vector <Float_t> LightGuidePhotonEnergy;
  vector <Float_t> LightGuideStepLength;
  vector <Float_t> LightGuideTrackLength;
  vector <Float_t> LightGuideIncidentPhotonAngle;

  Int_t QuartzSteps;
  Int_t  QuartzPhotonAtExit;
  Float_t QuartzPhotonEnergy;
  Float_t QuartzTrackLength;
  vector <Int_t> TotalSteps;
  vector <Int_t>  QuartzStepNPhotons;
  vector <Float_t> QuartzSecondaryPhotonAngle;
  vector <Float_t> QuartzStepLength;
  vector <Float_t> QuartzElectronStepLength;
  vector <Float_t> QuartzIncidentPhotonAngle;

  vector <Float_t> TotalTrackLength; 

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

  vector <Float_t> R1TileHitX;
  vector <Float_t> R2TileHitX;
  vector <Float_t> R3TileHitX;
  vector <Float_t> R4TileHitX;
  vector <Float_t> R5TileHitX;
  vector <Float_t> R6TileHitX;
  vector <Float_t> R7TileHitX;
  vector <Float_t> R8TileHitX;
  vector <Float_t> ScintillatorHitX;
  vector <Float_t> GEMScintillator1HitX;
  vector <Float_t> GEMScintillator2HitX;
  vector <Float_t> R1TileHitY;
  vector <Float_t> R2TileHitY;
  vector <Float_t> R3TileHitY;
  vector <Float_t> R4TileHitY;
  vector <Float_t> R5TileHitY;
  vector <Float_t> R6TileHitY;
  vector <Float_t> R7TileHitY;
  vector <Float_t> R8TileHitY;
  vector <Float_t> ScintillatorHitY;
  vector <Float_t> GEMScintillator1HitY;
  vector <Float_t> GEMScintillator2HitY;
  vector <Float_t> R1TileHitZ;
  vector <Float_t> R2TileHitZ;
  vector <Float_t> R3TileHitZ;
  vector <Float_t> R4TileHitZ;
  vector <Float_t> R5TileHitZ;
  vector <Float_t> R6TileHitZ;
  vector <Float_t> R7TileHitZ;
  vector <Float_t> R8TileHitZ;
  vector <Float_t> ScintillatorHitZ;
  vector <Float_t> GEMScintillator1HitZ;
  vector <Float_t> GEMScintillator2HitZ;

  vector <Int_t> R1PEs;
  vector <Int_t> R2PEs;
  vector <Int_t> R3PEs;
  vector <Int_t> R4PEs;
  vector <Int_t> R5PEs;
  vector <Int_t> R6PEs;
  vector <Int_t> R7PEs;
  vector <Int_t> R8PEs;

  vector <Int_t> R1SoloPEs;
  vector <Int_t> R2SoloPEs;
  vector <Int_t> R3SoloPEs;
  vector <Int_t> R4SoloPEs;
  vector <Int_t> R5SoloPEs;
  vector <Int_t> R6SoloPEs;
  vector <Int_t> R7SoloPEs;
  vector <Int_t> R8SoloPEs;


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

  void AddQuartzPhotonEnergy(Float_t eng) {QuartzPhotonEnergy = eng;};
  void AddQuartzStepLength(Float_t dx){ QuartzStepLength.push_back(dx);};
  void AddQuartzElectronStepLength(Float_t dx) {QuartzElectronStepLength.push_back(dx);};
  void AddQuartzIncidentPhotonAngle(Float_t angle) {QuartzIncidentPhotonAngle.push_back(angle);};
  void AddQuartzTrackData(Float_t QTrackL, Int_t QSteps);
  void AddQuartzStepNPhotons(Int_t n){QuartzStepNPhotons.push_back(n);};
  void AddQuartzPhotonAtExitFlag(Int_t flag){QuartzPhotonAtExit = flag;};
  void AddQuartzTrackSecPhotonAngle(Float_t angle) {QuartzSecondaryPhotonAngle.push_back(angle);}

  void AddElectronTrackID(Int_t tID){ElectronTrackID = tID;};
  void AddPhotonTrackID(Int_t tID){PhotonTrackID = tID;};

  void AddInitialBeamEnergy(Float_t eng) {InitialBeamEnergy.push_back(eng);};
  void AddInitialBeamAngle(Float_t aang) {InitialBeamAngle.push_back(aang);};

  void AddPMTPhotonEnergy(Float_t eng) {PMTPhotonEnergy.push_back(eng);};
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

  void AddR1QuartzHitPositionX(Float_t x) {R1TileHitX.push_back(x);};
  void AddR1QuartzHitPositionY(Float_t y) {R1TileHitY.push_back(y);};
  void AddR1QuartzHitPositionZ(Float_t z) {R1TileHitZ.push_back(z);};
  void AddR2QuartzHitPositionX(Float_t x) {R2TileHitX.push_back(x);};
  void AddR2QuartzHitPositionY(Float_t y) {R2TileHitY.push_back(y);};
  void AddR2QuartzHitPositionZ(Float_t z) {R2TileHitZ.push_back(z);};
  void AddR3QuartzHitPositionX(Float_t x) {R3TileHitX.push_back(x);};
  void AddR3QuartzHitPositionY(Float_t y) {R3TileHitY.push_back(y);};
  void AddR3QuartzHitPositionZ(Float_t z) {R3TileHitZ.push_back(z);};
  void AddR4QuartzHitPositionX(Float_t x) {R4TileHitX.push_back(x);};
  void AddR4QuartzHitPositionY(Float_t y) {R4TileHitY.push_back(y);};
  void AddR4QuartzHitPositionZ(Float_t z) {R4TileHitZ.push_back(z);};
  void AddR5QuartzHitPositionX(Float_t x) {R5TileHitX.push_back(x);};
  void AddR5QuartzHitPositionY(Float_t y) {R5TileHitY.push_back(y);};
  void AddR5QuartzHitPositionZ(Float_t z) {R5TileHitZ.push_back(z);};
  void AddR6QuartzHitPositionX(Float_t x) {R6TileHitX.push_back(x);};
  void AddR6QuartzHitPositionY(Float_t y) {R6TileHitY.push_back(y);};
  void AddR6QuartzHitPositionZ(Float_t z) {R6TileHitZ.push_back(z);};
  void AddR7QuartzHitPositionX(Float_t x) {R7TileHitX.push_back(x);};
  void AddR7QuartzHitPositionY(Float_t y) {R7TileHitY.push_back(y);};
  void AddR7QuartzHitPositionZ(Float_t z) {R7TileHitZ.push_back(z);};
  void AddR8QuartzHitPositionX(Float_t x) {R8TileHitX.push_back(x);};
  void AddR8QuartzHitPositionY(Float_t y) {R8TileHitY.push_back(y);};
  void AddR8QuartzHitPositionZ(Float_t z) {R8TileHitZ.push_back(z);};
  void AddScintHitPositionX(Float_t x) {ScintillatorHitX.push_back(x);};
  void AddScintHitPositionY(Float_t y) {ScintillatorHitY.push_back(y);};
  void AddScintHitPositionZ(Float_t z) {ScintillatorHitZ.push_back(z);};
  void AddGEMScint1HitPositionX(Float_t x) {GEMScintillator1HitX.push_back(x);};
  void AddGEMScint1HitPositionY(Float_t y) {GEMScintillator1HitY.push_back(y);};
  void AddGEMScint1HitPositionZ(Float_t z) {GEMScintillator1HitZ.push_back(z);};
  void AddGEMScint2HitPositionX(Float_t x) {GEMScintillator2HitX.push_back(x);};
  void AddGEMScint2HitPositionY(Float_t y) {GEMScintillator2HitY.push_back(y);};
  void AddGEMScint2HitPositionZ(Float_t z) {GEMScintillator2HitZ.push_back(z);};

  void AddR1PEs(Int_t pes) {R1PEs.push_back(pes);};
  void AddR2PEs(Int_t pes) {R2PEs.push_back(pes);};
  void AddR3PEs(Int_t pes) {R3PEs.push_back(pes);};
  void AddR4PEs(Int_t pes) {R4PEs.push_back(pes);};
  void AddR5PEs(Int_t pes) {R5PEs.push_back(pes);};
  void AddR6PEs(Int_t pes) {R6PEs.push_back(pes);};
  void AddR7PEs(Int_t pes) {R7PEs.push_back(pes);};
  void AddR8PEs(Int_t pes) {R8PEs.push_back(pes);};
  void AddR1SoloPEs(Int_t pes) {R1SoloPEs.push_back(pes);};
  void AddR2SoloPEs(Int_t pes) {R2SoloPEs.push_back(pes);};
  void AddR3SoloPEs(Int_t pes) {R3SoloPEs.push_back(pes);};
  void AddR4SoloPEs(Int_t pes) {R4SoloPEs.push_back(pes);};
  void AddR5SoloPEs(Int_t pes) {R5SoloPEs.push_back(pes);};
  void AddR6SoloPEs(Int_t pes) {R6SoloPEs.push_back(pes);};
  void AddR7SoloPEs(Int_t pes) {R7SoloPEs.push_back(pes);};
  void AddR8SoloPEs(Int_t pes) {R8SoloPEs.push_back(pes);};

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
