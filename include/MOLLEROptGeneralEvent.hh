#ifndef MOLLEROptGeneralEvent_h
#define MOLLEROptGeneralEvent_h

#include "cpp_include.h"
#include "Root_include.h"

class MOLLEROptGeneralEvent : public TObject
{

private:

  vector <Int_t> PType;
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
  vector <Int_t> R9QuartzTrackHit;
  vector <Int_t> R10QuartzTrackHit;
  vector <Int_t> R11QuartzTrackHit;
  vector <Int_t> R12QuartzTrackHit;
  vector <Int_t> R13QuartzTrackHit;
  vector <Int_t> R14QuartzTrackHit;
  vector <Int_t> R15QuartzTrackHit;
  vector <Int_t> R16QuartzTrackHit;

  vector <Int_t> Scint1TrackHit;
  vector <Int_t> Scint2TrackHit;
  vector <Int_t> Scint3TrackHit;
  vector <Int_t> Scint4TrackHit;
  vector <Int_t> Scint5TrackHit;
  vector <Int_t> Scint6TrackHit;
  vector <Int_t> Scint7TrackHit;
  vector <Int_t> Scint8TrackHit;

  vector <Float_t> R1TileHitX;
  vector <Float_t> R2TileHitX;
  vector <Float_t> R3TileHitX;
  vector <Float_t> R4TileHitX;
  vector <Float_t> R5TileHitX;
  vector <Float_t> R6TileHitX;
  vector <Float_t> R7TileHitX;
  vector <Float_t> R8TileHitX;
  vector <Float_t> R9TileHitX;
  vector <Float_t> R10TileHitX;
  vector <Float_t> R11TileHitX;
  vector <Float_t> R12TileHitX;
  vector <Float_t> R13TileHitX;
  vector <Float_t> R14TileHitX;
  vector <Float_t> R15TileHitX;
  vector <Float_t> R16TileHitX;
  vector <Float_t> R1TileHitY;
  vector <Float_t> R2TileHitY;
  vector <Float_t> R3TileHitY;
  vector <Float_t> R4TileHitY;
  vector <Float_t> R5TileHitY;
  vector <Float_t> R6TileHitY;
  vector <Float_t> R7TileHitY;
  vector <Float_t> R8TileHitY;
  vector <Float_t> R9TileHitY;
  vector <Float_t> R10TileHitY;
  vector <Float_t> R11TileHitY;
  vector <Float_t> R12TileHitY;
  vector <Float_t> R13TileHitY;
  vector <Float_t> R14TileHitY;
  vector <Float_t> R15TileHitY;
  vector <Float_t> R16TileHitY;
  vector <Float_t> R1TileHitZ;
  vector <Float_t> R2TileHitZ;
  vector <Float_t> R3TileHitZ;
  vector <Float_t> R4TileHitZ;
  vector <Float_t> R5TileHitZ;
  vector <Float_t> R6TileHitZ;
  vector <Float_t> R7TileHitZ;
  vector <Float_t> R8TileHitZ;
  vector <Float_t> R9TileHitZ;
  vector <Float_t> R10TileHitZ;
  vector <Float_t> R11TileHitZ;
  vector <Float_t> R12TileHitZ;
  vector <Float_t> R13TileHitZ;
  vector <Float_t> R14TileHitZ;
  vector <Float_t> R15TileHitZ;
  vector <Float_t> R16TileHitZ;

  vector <Float_t> Scint1HitX;
  vector <Float_t> Scint2HitX;
  vector <Float_t> Scint3HitX;
  vector <Float_t> Scint4HitX;
  vector <Float_t> Scint5HitX;
  vector <Float_t> Scint6HitX;
  vector <Float_t> Scint7HitX;
  vector <Float_t> Scint8HitX;
  vector <Float_t> Scint1HitY;
  vector <Float_t> Scint2HitY;
  vector <Float_t> Scint3HitY;
  vector <Float_t> Scint4HitY;
  vector <Float_t> Scint5HitY;
  vector <Float_t> Scint6HitY;
  vector <Float_t> Scint7HitY;
  vector <Float_t> Scint8HitY;
  vector <Float_t> Scint1HitZ;
  vector <Float_t> Scint2HitZ;
  vector <Float_t> Scint3HitZ;
  vector <Float_t> Scint4HitZ;
  vector <Float_t> Scint5HitZ;
  vector <Float_t> Scint6HitZ;
  vector <Float_t> Scint7HitZ;
  vector <Float_t> Scint8HitZ;

  vector <Int_t> R1PEs;
  vector <Int_t> R2PEs;
  vector <Int_t> R3PEs;
  vector <Int_t> R4PEs;
  vector <Int_t> R5PEs;
  vector <Int_t> R6PEs;
  vector <Int_t> R7PEs;
  vector <Int_t> R8PEs;
  vector <Int_t> R9PEs;
  vector <Int_t> R10PEs;
  vector <Int_t> R11PEs;
  vector <Int_t> R12PEs;
  vector <Int_t> R13PEs;
  vector <Int_t> R14PEs;
  vector <Int_t> R15PEs;
  vector <Int_t> R16PEs;

  vector <Int_t> R1SoloPEs;
  vector <Int_t> R2SoloPEs;
  vector <Int_t> R3SoloPEs;
  vector <Int_t> R4SoloPEs;
  vector <Int_t> R5SoloPEs;
  vector <Int_t> R6SoloPEs;
  vector <Int_t> R7SoloPEs;
  vector <Int_t> R8SoloPEs;
  vector <Int_t> R9SoloPEs;
  vector <Int_t> R10SoloPEs;
  vector <Int_t> R11SoloPEs;
  vector <Int_t> R12SoloPEs;
  vector <Int_t> R13SoloPEs;
  vector <Int_t> R14SoloPEs;
  vector <Int_t> R15SoloPEs;
  vector <Int_t> R16SoloPEs;


public:


  MOLLEROptGeneralEvent();
  virtual ~MOLLEROptGeneralEvent();

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

  //void AddScintTrackData(Float_t STrackL, Int_t SSteps);

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
  void AddR9QuartzTrackHit(Int_t tID){R9QuartzTrackHit.push_back(tID);};
  void AddR10QuartzTrackHit(Int_t tID){R10QuartzTrackHit.push_back(tID);};
  void AddR11QuartzTrackHit(Int_t tID){R11QuartzTrackHit.push_back(tID);};
  void AddR12QuartzTrackHit(Int_t tID){R12QuartzTrackHit.push_back(tID);};
  void AddR13QuartzTrackHit(Int_t tID){R13QuartzTrackHit.push_back(tID);};
  void AddR14QuartzTrackHit(Int_t tID){R14QuartzTrackHit.push_back(tID);};
  void AddR15QuartzTrackHit(Int_t tID){R15QuartzTrackHit.push_back(tID);};
  void AddR16QuartzTrackHit(Int_t tID){R16QuartzTrackHit.push_back(tID);};

  void AddScint1TrackHit(Int_t tID){Scint1TrackHit.push_back(tID);};
  void AddScint2TrackHit(Int_t tID){Scint2TrackHit.push_back(tID);};
  void AddScint3TrackHit(Int_t tID){Scint3TrackHit.push_back(tID);};
  void AddScint4TrackHit(Int_t tID){Scint4TrackHit.push_back(tID);};
  void AddScint5TrackHit(Int_t tID){Scint5TrackHit.push_back(tID);};
  void AddScint6TrackHit(Int_t tID){Scint6TrackHit.push_back(tID);};
  void AddScint7TrackHit(Int_t tID){Scint7TrackHit.push_back(tID);};
  void AddScint8TrackHit(Int_t tID){Scint8TrackHit.push_back(tID);};

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
  void AddR9QuartzHitPositionX(Float_t x) {R9TileHitX.push_back(x);};
  void AddR9QuartzHitPositionY(Float_t y) {R9TileHitY.push_back(y);};
  void AddR9QuartzHitPositionZ(Float_t z) {R9TileHitZ.push_back(z);};
  void AddR10QuartzHitPositionX(Float_t x) {R10TileHitX.push_back(x);};
  void AddR10QuartzHitPositionY(Float_t y) {R10TileHitY.push_back(y);};
  void AddR10QuartzHitPositionZ(Float_t z) {R10TileHitZ.push_back(z);};
  void AddR11QuartzHitPositionX(Float_t x) {R11TileHitX.push_back(x);};
  void AddR11QuartzHitPositionY(Float_t y) {R11TileHitY.push_back(y);};
  void AddR11QuartzHitPositionZ(Float_t z) {R11TileHitZ.push_back(z);};
  void AddR12QuartzHitPositionX(Float_t x) {R12TileHitX.push_back(x);};
  void AddR12QuartzHitPositionY(Float_t y) {R12TileHitY.push_back(y);};
  void AddR12QuartzHitPositionZ(Float_t z) {R12TileHitZ.push_back(z);};
  void AddR13QuartzHitPositionX(Float_t x) {R13TileHitX.push_back(x);};
  void AddR13QuartzHitPositionY(Float_t y) {R13TileHitY.push_back(y);};
  void AddR13QuartzHitPositionZ(Float_t z) {R13TileHitZ.push_back(z);};
  void AddR14QuartzHitPositionX(Float_t x) {R14TileHitX.push_back(x);};
  void AddR14QuartzHitPositionY(Float_t y) {R14TileHitY.push_back(y);};
  void AddR14QuartzHitPositionZ(Float_t z) {R14TileHitZ.push_back(z);};
  void AddR15QuartzHitPositionX(Float_t x) {R15TileHitX.push_back(x);};
  void AddR15QuartzHitPositionY(Float_t y) {R15TileHitY.push_back(y);};
  void AddR15QuartzHitPositionZ(Float_t z) {R15TileHitZ.push_back(z);};
  void AddR16QuartzHitPositionX(Float_t x) {R16TileHitX.push_back(x);};
  void AddR16QuartzHitPositionY(Float_t y) {R16TileHitY.push_back(y);};
  void AddR16QuartzHitPositionZ(Float_t z) {R16TileHitZ.push_back(z);};

  void AddScint1HitPositionX(Float_t x) {Scint1HitX.push_back(x);};
  void AddScint1HitPositionY(Float_t y) {Scint1HitY.push_back(y);};
  void AddScint1HitPositionZ(Float_t z) {Scint1HitZ.push_back(z);};
  void AddScint2HitPositionX(Float_t x) {Scint2HitX.push_back(x);};
  void AddScint2HitPositionY(Float_t y) {Scint2HitY.push_back(y);};
  void AddScint2HitPositionZ(Float_t z) {Scint2HitZ.push_back(z);};
  void AddScint3HitPositionX(Float_t x) {Scint3HitX.push_back(x);};
  void AddScint3HitPositionY(Float_t y) {Scint3HitY.push_back(y);};
  void AddScint3HitPositionZ(Float_t z) {Scint3HitZ.push_back(z);};
  void AddScint4HitPositionX(Float_t x) {Scint4HitX.push_back(x);};
  void AddScint4HitPositionY(Float_t y) {Scint4HitY.push_back(y);};
  void AddScint4HitPositionZ(Float_t z) {Scint4HitZ.push_back(z);};
  void AddScint5HitPositionX(Float_t x) {Scint5HitX.push_back(x);};
  void AddScint5HitPositionY(Float_t y) {Scint5HitY.push_back(y);};
  void AddScint5HitPositionZ(Float_t z) {Scint5HitZ.push_back(z);};
  void AddScint6HitPositionX(Float_t x) {Scint6HitX.push_back(x);};
  void AddScint6HitPositionY(Float_t y) {Scint6HitY.push_back(y);};
  void AddScint6HitPositionZ(Float_t z) {Scint6HitZ.push_back(z);};
  void AddScint7HitPositionX(Float_t x) {Scint7HitX.push_back(x);};
  void AddScint7HitPositionY(Float_t y) {Scint7HitY.push_back(y);};
  void AddScint7HitPositionZ(Float_t z) {Scint7HitZ.push_back(z);};
  void AddScint8HitPositionX(Float_t x) {Scint8HitX.push_back(x);};
  void AddScint8HitPositionY(Float_t y) {Scint8HitY.push_back(y);};
  void AddScint8HitPositionZ(Float_t z) {Scint8HitZ.push_back(z);};

  void AddR1PEs(Int_t pes) {R1PEs.push_back(pes);};
  void AddR2PEs(Int_t pes) {R2PEs.push_back(pes);};
  void AddR3PEs(Int_t pes) {R3PEs.push_back(pes);};
  void AddR4PEs(Int_t pes) {R4PEs.push_back(pes);};
  void AddR5PEs(Int_t pes) {R5PEs.push_back(pes);};
  void AddR6PEs(Int_t pes) {R6PEs.push_back(pes);};
  void AddR7PEs(Int_t pes) {R7PEs.push_back(pes);};
  void AddR8PEs(Int_t pes) {R8PEs.push_back(pes);};
  void AddR9PEs(Int_t pes) {R9PEs.push_back(pes);};
  void AddR10PEs(Int_t pes) {R10PEs.push_back(pes);};
  void AddR11PEs(Int_t pes) {R11PEs.push_back(pes);};
  void AddR12PEs(Int_t pes) {R12PEs.push_back(pes);};
  void AddR13PEs(Int_t pes) {R13PEs.push_back(pes);};
  void AddR14PEs(Int_t pes) {R14PEs.push_back(pes);};
  void AddR15PEs(Int_t pes) {R15PEs.push_back(pes);};
  void AddR16PEs(Int_t pes) {R16PEs.push_back(pes);};
  void AddR1SoloPEs(Int_t pes) {R1SoloPEs.push_back(pes);};
  void AddR2SoloPEs(Int_t pes) {R2SoloPEs.push_back(pes);};
  void AddR3SoloPEs(Int_t pes) {R3SoloPEs.push_back(pes);};
  void AddR4SoloPEs(Int_t pes) {R4SoloPEs.push_back(pes);};
  void AddR5SoloPEs(Int_t pes) {R5SoloPEs.push_back(pes);};
  void AddR6SoloPEs(Int_t pes) {R6SoloPEs.push_back(pes);};
  void AddR7SoloPEs(Int_t pes) {R7SoloPEs.push_back(pes);};
  void AddR8SoloPEs(Int_t pes) {R8SoloPEs.push_back(pes);};
  void AddR9SoloPEs(Int_t pes) {R9SoloPEs.push_back(pes);};
  void AddR10SoloPEs(Int_t pes) {R11SoloPEs.push_back(pes);};
  void AddR11SoloPEs(Int_t pes) {R12SoloPEs.push_back(pes);};
  void AddR12SoloPEs(Int_t pes) {R13SoloPEs.push_back(pes);};
  void AddR13SoloPEs(Int_t pes) {R14SoloPEs.push_back(pes);};
  void AddR14SoloPEs(Int_t pes) {R15SoloPEs.push_back(pes);};
  void AddR15SoloPEs(Int_t pes) {R16SoloPEs.push_back(pes);};
  void AddR16SoloPEs(Int_t pes) {R16SoloPEs.push_back(pes);};

  void AddTrackInitMomDirection(Float_t x, Float_t y, Float_t z) {
    InitialTrackMomDirectionX = x;
    InitialTrackMomDirectionY = y;
    InitialTrackMomDirectionZ = z;
  };
  void SetTrackParentID(Int_t ID) {ParentID = ID;};
  void SetEventID(Int_t ID) {EventID = ID;};
  
  ClassDef(MOLLEROptGeneralEvent,1)

};

#endif 
