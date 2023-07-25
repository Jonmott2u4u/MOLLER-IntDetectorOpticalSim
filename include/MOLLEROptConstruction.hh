#ifndef MOLLEROptConstruction_h
#define MOLLEROptConstruction_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 
#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"

#include "MOLLEROptMessenger.hh"
#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptTrackingReadout2.hh"
#include "MOLLEROptTrackingReadout3.hh"
#include "MOLLEROptTrackingReadout4.hh"
#include "MOLLEROptTrackingReadout5.hh"
#include "MOLLEROptTrackingReadout6.hh"
#include "MOLLEROptTrackingReadout7.hh"
#include "MOLLEROptTrackingReadout8.hh"

//Includes for all detectors
#include "MOLLEROptDetector.hh"
#include "MOLLEROptDetector2.hh"
#include "MOLLEROptDetector3.hh"
#include "MOLLEROptDetector4.hh"
#include "MOLLEROptDetector5.hh"
#include "MOLLEROptDetector6.hh"
#include "MOLLEROptDetector7.hh"
#include "MOLLEROptDetector8.hh"

class MOLLEROptMessenger;
class MOLLEROptTrackingReadout;
class MOLLEROptTrackingReadout2;
class MOLLEROptTrackingReadout3;
class MOLLEROptTrackingReadout4;
class MOLLEROptTrackingReadout5;
class MOLLEROptTrackingReadout6;
class MOLLEROptTrackingReadout7;
class MOLLEROptTrackingReadout8;

class MOLLEROptConstruction : public G4VUserDetectorConstruction
{
public:
  
  MOLLEROptConstruction(MOLLEROptTrackingReadout*,MOLLEROptTrackingReadout2*,MOLLEROptTrackingReadout3*,MOLLEROptTrackingReadout4*,MOLLEROptTrackingReadout5*,MOLLEROptTrackingReadout6*,MOLLEROptTrackingReadout7*,MOLLEROptTrackingReadout8*, MOLLEROptMaterial*);
    ~MOLLEROptConstruction();

public:
  
  G4VPhysicalVolume* Construct();

  void UpdateGeometry();

  G4double   GetWorldFullLengthInX()    {return fWorldLengthInX;}
  G4double   GetWorldFullLengthInY()    {return fWorldLengthInY;}
  G4double   GetWorldFullLengthInZ()    {return fWorldLengthInZ;}
  void       SetRadDamageLevel(Int_t dam) {Materials->SetRadDamageLevel(dam);};
  
  void       GetQuartzLimits(G4double *vals);
  void       GetLightGuideLimits(G4double *vals);

private:
  
  MOLLEROptTrackingReadout *TrackingReadout;
  MOLLEROptTrackingReadout2 *TrackingReadout2;
  MOLLEROptTrackingReadout3 *TrackingReadout3;
  MOLLEROptTrackingReadout4 *TrackingReadout4;
  MOLLEROptTrackingReadout5 *TrackingReadout5;
  MOLLEROptTrackingReadout6 *TrackingReadout6;
  MOLLEROptTrackingReadout7 *TrackingReadout7;
  MOLLEROptTrackingReadout8 *TrackingReadout8;
  MOLLEROptMaterial* Materials;
  
  void DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth=0);
  
  MOLLEROptDetector*               Detector;
  MOLLEROptDetector2*	       	   Detector2;	
  MOLLEROptDetector3*              Detector3;
  MOLLEROptDetector4*              Detector4;
  MOLLEROptDetector5*              Detector5;
  MOLLEROptDetector6*              Detector6;
  MOLLEROptDetector7*              Detector7;
  MOLLEROptDetector8*              Detector8;
  
  MOLLEROptDetectorLightGuide*    LightGuide;

  MOLLEROptMessenger*  MOLLERMessenger;
  //MOLLEROptDetectorMessenger *DetMessenger;

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
