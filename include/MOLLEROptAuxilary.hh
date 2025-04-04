#ifndef MOLLEROptAuxilary_h
#define MOLLEROptAuxilary_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptAuxilaryScint.hh"
#include "MOLLEROptAuxilaryMessenger.hh"

#include "G4GDMLParser.hh"

class MOLLEROptAuxilaryMessenger;

class MOLLEROptAuxilary
{
public:
  MOLLEROptAuxilary(MOLLEROptTrackingReadout*,G4String type,MOLLEROptMaterial* mat);
  ~MOLLEROptAuxilary();

  G4VPhysicalVolume* ConstructAuxilary(G4VPhysicalVolume* Mother);
  
  void DestroyComponent();
  void Initialize();
  void SetMaterial(G4String materialName);

  //The standard coordinate system is: z=beam direction, y=beam up, x = beam left
  
  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);
  void SetSizeX(G4double x); 
  void SetSizeY(G4double y); 
  void SetSizeZ(G4double z);

  void SetAzimuthalRotationAngle(G4double a); //w.r.t. to the positive y axis (up) in radians
  void SetPolarRotationAngle(G4double a); //w.r.t. to the positive z axis (downstream) in radians

  void UpdateThisGeometry();
  void CalculateDimensions();
  void ResetCenterLocation();

  G4LogicalVolume*   GetLogicalVolume()    {return AuxLogical;}
  G4VPhysicalVolume* GetPhysicalVolume()   {return AuxPhysical;}

  void GetScintLimits(G4double *vals);

private:

  G4String AuxType;

  MOLLEROptAuxilaryMessenger*  AuxMessenger;
  MOLLEROptTrackingReadout*    TrackingReadout;
  MOLLEROptMaterial*           Materials;
  MOLLEROptAuxilaryScint*      Scint;

  G4VPhysicalVolume* MotherVolume;

  G4LogicalVolume*   AuxLogical; 
  G4VPhysicalVolume* AuxPhysical;
  G4Box*             AuxSolid; 

  G4Material*        VolMaterial;

  G4double AuxFullLengthX;
  G4double AuxFullLengthY;
  G4double AuxFullLengthZ;

  G4ThreeVector     PositionAux;

  G4RotationMatrix* RotationAux;   

  G4double PositionAuxX;
  G4double PositionAuxY;
  G4double PositionAuxZ;

  G4double AzimuAngle;
  G4double PolarAngle;

};
#endif
