#ifndef MOLLEROptConstruction_h
#define MOLLEROptConstruction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"

#include "MOLLEROptMessenger.hh"
#include "MOLLEROptMaterial.hh"
#include "MOLLEROptDetector.hh"
#include "MOLLEROptAuxilary.hh"
#include "MOLLEROptInsensitive.hh"
#include "MOLLEROptTrackingReadout.hh"

class MOLLEROptMessenger;
class MOLLEROptTrackingReadout;

class MOLLEROptConstruction : public G4VUserDetectorConstruction
{
public:
  
  MOLLEROptConstruction(MOLLEROptTrackingReadout*, MOLLEROptMaterial*);
    ~MOLLEROptConstruction();

public:
  
  G4VPhysicalVolume* Construct();

  void UpdateGeometry();

  G4double   GetWorldFullLengthInX()    {return fWorldLengthInX;}
  G4double   GetWorldFullLengthInY()    {return fWorldLengthInY;}
  G4double   GetWorldFullLengthInZ()    {return fWorldLengthInZ;}
  void       SetRadDamageLevel(Int_t dam) {Materials->SetRadDamageLevel(dam);};
  
  void       GetQuartz1Limits(G4double *vals);
  void       GetQuartz2Limits(G4double *vals);
  void       GetQuartz3Limits(G4double *vals);
  void       GetQuartz4Limits(G4double *vals);
  void       GetQuartz5Limits(G4double *vals);
  void       GetQuartz6Limits(G4double *vals);
  void       GetQuartz7Limits(G4double *vals);
  void       GetQuartz8Limits(G4double *vals);
  void       GetQuartz9Limits(G4double *vals);
  void       GetQuartz10Limits(G4double *vals);
  void       GetQuartz11Limits(G4double *vals);
  void       GetQuartz12Limits(G4double *vals);
  void       GetQuartz13Limits(G4double *vals);
  void       GetQuartz14Limits(G4double *vals);
  void       GetQuartz15Limits(G4double *vals);
  void       GetQuartz16Limits(G4double *vals);
  void       GetLightGuide1Limits(G4double *vals);
  void       GetLightGuide2Limits(G4double *vals);
  void       GetLightGuide3Limits(G4double *vals);
  void       GetLightGuide4Limits(G4double *vals);
  void       GetLightGuide5Limits(G4double *vals);
  void       GetLightGuide6Limits(G4double *vals);
  void       GetLightGuide7Limits(G4double *vals);
  void       GetLightGuide8Limits(G4double *vals);
  void       GetLightGuide9Limits(G4double *vals);
  void       GetLightGuide10Limits(G4double *vals);
  void       GetLightGuide11Limits(G4double *vals);
  void       GetLightGuide12Limits(G4double *vals);
  void       GetLightGuide13Limits(G4double *vals);
  void       GetLightGuide14Limits(G4double *vals);
  void       GetLightGuide15Limits(G4double *vals);
  void       GetLightGuide16Limits(G4double *vals);
  void       GetScint1Limits(G4double *vals);
  void       GetScint2Limits(G4double *vals);
  void       GetScint3Limits(G4double *vals);
  void       GetScint4Limits(G4double *vals);
  void       GetScint5Limits(G4double *vals);
  void       GetScint6Limits(G4double *vals);
  void       GetScint7Limits(G4double *vals);
  void       GetScint8Limits(G4double *vals);

private:
  
  MOLLEROptTrackingReadout *TrackingReadout;
  MOLLEROptMaterial* Materials;
  
  void DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth=0);
  
  MOLLEROptDetector*     Ring1;
  MOLLEROptDetector*     Ring2;
  MOLLEROptDetector*     Ring3;
  MOLLEROptDetector*     Ring4;
  MOLLEROptDetector*     Ring5;
  MOLLEROptDetector*     Ring6;
  MOLLEROptDetector*     Ring7;
  MOLLEROptDetector*     Ring8;
  MOLLEROptDetector*     Ring9;
  MOLLEROptDetector*     Ring10;
  MOLLEROptDetector*     Ring11;
  MOLLEROptDetector*     Ring12;
  MOLLEROptDetector*     Ring13;
  MOLLEROptDetector*     Ring14;
  MOLLEROptDetector*     Ring15;
  MOLLEROptDetector*     Ring16;

  MOLLEROptAuxilary*     Scint1;
  MOLLEROptAuxilary*     Scint2;
  MOLLEROptAuxilary*     Scint3;
  MOLLEROptAuxilary*     Scint4;
  MOLLEROptAuxilary*     Scint5;
  MOLLEROptAuxilary*     Scint6;
  MOLLEROptAuxilary*     Scint7;
  MOLLEROptAuxilary*     Scint8;

  MOLLEROptInsensitive*  AlPlate;

  MOLLEROptMessenger*  MOLLERMessenger;


  G4Box*             World_Solid;     
  G4LogicalVolume*   World_Logical;   
  G4VPhysicalVolume* World_Physical;  
  G4Material*        World_Material; 

  G4double fWorldLength;    
  G4double fWorldLengthInX; 
  G4double fWorldLengthInY; 
  G4double fWorldLengthInZ; 
};

#endif
