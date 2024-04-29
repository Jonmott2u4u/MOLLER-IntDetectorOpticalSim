#ifndef MOLLEROptTrackingReadout_h
#define MOLLEROptTrackingReadout_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#define myElectron 1
#define myPositron 2
#define myGamma    3  //as in non-optical photon including x-ray
#define myPhoton   4  //as in optical photon
#define myBeam     5  //Replacement for myElectron in beam

#define myQuartz 10
#define myLightGuide 11
#define myPMT 12

class OptParam;

class TrackData{

public:
  Int_t ID;
  Int_t ParentID;
  Int_t Particle;
  Int_t Length;
  Int_t QLength;
  Int_t LGLength;
  Int_t NSteps;
  Int_t QSteps;
  Int_t LGSteps;
  Int_t QExitFlag;
  Int_t PMTHitFlag;
  Int_t R1QuartzHitFlag = 0;
  Int_t R2QuartzHitFlag = 0;
  Int_t R3QuartzHitFlag = 0;
  Int_t R4QuartzHitFlag = 0;
  Int_t R5QuartzHitFlag = 0;
  Int_t R6QuartzHitFlag = 0;
  Int_t R7QuartzHitFlag = 0;
  Int_t R8QuartzHitFlag = 0;
  Int_t Scint1HitFlag = 0;
  Int_t Scint2HitFlag = 0;
  Int_t Scint3HitFlag = 0;
  Int_t Scint4HitFlag = 0;
  Int_t LGHitFlag=0;
  Int_t R1_Detected;
  Int_t R2_Detected;
  Int_t R3_Detected;
  Int_t R4_Detected;
  Int_t R5_Detected;
  Int_t R6_Detected;
  Int_t R7_Detected;
  Int_t R8_Detected;
  Float_t InitEnergy;
  Float_t InitKinEnergy;
  Float_t InitWavelength;
  Float_t InitMomDirX;
  Float_t InitMomDirY;
  Float_t InitMomDirZ;
  Float_t PMTHitX;
  Float_t PMTHitY;
  Float_t PMTHitZ;
  Float_t PMTWinRefl;
  Float_t R1QuartzHitX=0;
  Float_t R1QuartzHitY=0;
  Float_t R1QuartzHitZ=0;
  Float_t R2QuartzHitX=0;
  Float_t R2QuartzHitY=0;
  Float_t R2QuartzHitZ=0;
  Float_t R3QuartzHitX=0;
  Float_t R3QuartzHitY=0;
  Float_t R3QuartzHitZ=0;
  Float_t R4QuartzHitX=0;
  Float_t R4QuartzHitY=0;
  Float_t R4QuartzHitZ=0;
  Float_t R5QuartzHitX=0;
  Float_t R5QuartzHitY=0;
  Float_t R5QuartzHitZ=0;
  Float_t R6QuartzHitX=0;
  Float_t R6QuartzHitY=0;
  Float_t R6QuartzHitZ=0;
  Float_t R7QuartzHitX=0;
  Float_t R7QuartzHitY=0;
  Float_t R7QuartzHitZ=0;
  Float_t R8QuartzHitX=0;
  Float_t R8QuartzHitY=0;
  Float_t R8QuartzHitZ=0;
  Float_t Scint1HitX=0;
  Float_t Scint1HitY=0;
  Float_t Scint1HitZ=0;
  Float_t Scint2HitX=0;
  Float_t Scint2HitY=0;
  Float_t Scint2HitZ=0;
  Float_t Scint3HitX=0;
  Float_t Scint3HitY=0;
  Float_t Scint3HitZ=0;
  Float_t Scint4HitX=0;
  Float_t Scint4HitY=0;
  Float_t Scint4HitZ=0;
  vector <Float_t> StepLength;
  vector <Float_t> StepAngle;  
  vector <Float_t> SecPhotonAngle;  
  vector <Float_t> SecPhotonWavelength;  
  vector <Int_t> StepVolume;
  vector <Int_t> StepDefProc;
  vector <Int_t> StepNChPhotons;
  vector <Float_t> StepEnergy;
  vector <Float_t> StepWavelength;
};


class MOLLEROptTrackingReadout 
{
public:
  
   MOLLEROptTrackingReadout();
  ~MOLLEROptTrackingReadout();

private:

  vector <TrackData*> Tracks;
  Int_t ElectronTracks;
  Int_t PhotonTracks;
  //Int_t CathodeDetections;
  Int_t R1_CathodeDetections;
  Int_t R2_CathodeDetections;
  Int_t R3_CathodeDetections;
  Int_t R4_CathodeDetections;
  Int_t R5_CathodeDetections;
  Int_t R6_CathodeDetections;
  Int_t R7_CathodeDetections;
  Int_t R8_CathodeDetections;

  TH2D *DetectorRateGlobal;
  TH2D *DetectorRateGlobalRotated;
  TH2D *DetectorRateLocalRotated;
  TH2D *DetectorRateLocalRotatedCoarse;
  TH1D *QEfficiency;

  TProfile* Transm35;
  TProfile* Transm70;
  TProfile* Transm170;
  TProfile* Reflectivity;
  
  TH1D *LGRefl30;
  TH1D *LGRefl45;
  TH1D *LGRefl60;
  TH1D *LGRefl90;

  TH1D* CathIndR;  
  TH1D* CathIndI;  

  OptParam* OpticalParameters;

  vector <TProfile*> QAbsProf; 


 public:

  void Initialize();
  void AddNewTrack(TrackData *track);
  void AddTrackData(Int_t id, Int_t type, Int_t StepL, Int_t QEFlag, Int_t PMTHit, Int_t Volume, Int_t Proc, Float_t eng, Float_t wvl, Float_t Ang);
  void AddSecPhoton(Int_t id, Float_t ang, Float_t wvl);
  void AddStepNCherenkovs(Int_t n, Int_t nsec);
  void IncrementEventCathodeDetection(Int_t ID);
  //Int_t GetCathodeDetections() {return CathodeDetections;};
  Int_t R1_GetCathodeDetections() {return R1_CathodeDetections;};
  Int_t R2_GetCathodeDetections() {return R2_CathodeDetections;};
  Int_t R3_GetCathodeDetections() {return R3_CathodeDetections;};
  Int_t R4_GetCathodeDetections() {return R4_CathodeDetections;};
  Int_t R5_GetCathodeDetections() {return R5_CathodeDetections;};
  Int_t R6_GetCathodeDetections() {return R6_CathodeDetections;};
  Int_t R7_GetCathodeDetections() {return R7_CathodeDetections;};
  Int_t R8_GetCathodeDetections() {return R8_CathodeDetections;};
  void SetPMTHitLocation(Int_t id, G4ThreeVector loc, Float_t angle);
  void SetQuartzHitLocation(Int_t id, G4ThreeVector loc, G4String quartz);
  Bool_t TrackExists(Int_t ID);
  Int_t GetNumTracks(){return Tracks.size();};
  Int_t GetNumPhotonTracks(){return PhotonTracks;};
  Int_t GetNumElectronTracks(){return ElectronTracks;};
  TrackData* GetTrackData(Int_t n) {if(n >= 0 && n < Tracks.size()) return Tracks[n]; return 0;};
  Int_t GetStepInQuartz(Int_t TID);
  void SetRadiationDamageHistograms(TH2 *hst, TH2 *hst2, TH2 *hst3, TH2 *hst4);
  void StoreQuartzOpticalPlots(TProfile*,TProfile*,TProfile*,TProfile*,TH1D*);
  void StoreGuideOpticalPlots(TH1D*,TH1D*,TH1D*,TH1D*);
  void StoreCathodeOpticalPlots(TH1D*, TH1D*);
  void SetNewQAbsorptionProfile(TProfile* abs);
  void WriteAbsProfiles();
  void SetOpticalParameters(OptParam* op){ OpticalParameters = op;};
  OptParam* GetOpticalParameters(){ return OpticalParameters;};
  
  
};

#endif
