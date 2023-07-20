#ifndef MOLLEROptDetectorPMT5_h
#define MOLLEROptDetectorPMT5_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptPMTSD5.hh"
#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout5.hh"
#include "MOLLEROptDetectorLightGuide5.hh"

class MOLLEROptDetectorPMT5 
{
public:
  MOLLEROptDetectorPMT5(MOLLEROptTrackingReadout5*, G4String type, MOLLEROptMaterial* mat, MOLLEROptDetectorLightGuide5* guide);
  ~MOLLEROptDetectorPMT5();

  G4VPhysicalVolume* Construct(G4VPhysicalVolume* Mother);
  void Initialize();
  void SetMaterial(G4String materialName);

  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);  
  G4double GetCurrentCenterPositionInX() {return PositionX;};
  G4double GetCurrentCenterPositionInY() {return PositionY;};
  G4double GetCurrentCenterPositionInZ() {return PositionZ;};

  void SetCathodeThickness(G4double v) {CathodeThickness = v;};
  void SetCathodeRadius(G4double v) {CathodeRadius = v;};
  void SetLGInterfaceOpeningZ(G4double v) {LGInterfaceOpeningZ = v;};
  void SetLGInterfaceOpeningX(G4double v) {LGInterfaceOpeningX = v;};

  G4double GetPMTLength(){return PMTThickness;};
  G4double GetRadius(){return CathodeRadius+0.4*cm;};

  //The standard coordinate system is: z=beam direction, y=beam up, x = beam left
  //Dimensions below assume a detector that is located at the origin with the 45 degreee
  //exit face at the upper y end and the width of the detector along +-x.

  void ClearVolumes();
  void UpdateGeometry();

  G4LogicalVolume*   GetLogicalVolume()    {return PMTLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return PMTPhysical;} 

private:

  // void CreateOpticalSurface(G4VPhysicalVolume *, G4VPhysicalVolume *);
  void CreateOpticalSurface(G4LogicalVolume*);

  G4String Name;
  
  MOLLEROptTrackingReadout5 *TrackingReadout5;
  MOLLEROptDetectorLightGuide5 * LightGuide5;
  MOLLEROptMaterial* Materials;
  
  // MOLLEROptDetectorMessenger* DetMessenger;

  G4VPhysicalVolume* MotherVolume;

  G4Tubs*            PMTSolid;
  G4LogicalVolume*   PMTLogical; 
  G4VPhysicalVolume* PMTPhysical; 
  G4Material*        PMTMaterial;

  G4Tubs*            PMTWindowSolid;
  G4LogicalVolume*   PMTWindowLogical; 
  G4VPhysicalVolume* PMTWindowPhysical; 
  G4Material*        PMTWindowMaterial;

  G4Tubs*            PMTCathodeSolid;
  G4LogicalVolume*   PMTCathodeLogical; 
  G4VPhysicalVolume* PMTCathodePhysical; 
  G4Material*        PMTCathodeMaterial;
  

  G4OpticalSurface*  PMTCathodeSurface;
  G4MaterialPropertiesTable *CathodeMatPropTable;
  G4LogicalBorderSurface *PMTCathodeBorderSurface;
  G4LogicalSkinSurface* PMTWindowLogicalSkinSurface;

  G4double CathodeRadius;
  G4double CathodeThickness;

  G4double PMTThickness;
  G4double WindowRadius;
  G4double PMTWindowThickness;

  G4ThreeVector     Position;
  G4RotationMatrix* Rotation;  

  G4double PositionX;
  G4double PositionY;
  G4double PositionZ;

  G4double PositionCathodeX;
  G4double PositionCathodeY;
  G4double PositionCathodeZ;

  G4double PositionWindowX;
  G4double PositionWindowY;
  G4double PositionWindowZ;

  G4double LGInterfaceOpeningZ;
  G4double LGInterfaceOpeningX;

  G4SDManager* SDman;
  G4VSensitiveDetector* CathSD;


};
#endif
