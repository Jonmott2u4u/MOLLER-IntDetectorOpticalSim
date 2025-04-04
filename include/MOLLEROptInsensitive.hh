#ifndef MOLLEROptInsensitive_h
#define MOLLEROptInsensitive_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptInsensitiveAlPlate.hh"
#include "MOLLEROptInsensitiveMessenger.hh"

#include "G4GDMLParser.hh"

class MOLLEROptInsensitiveMessenger;

class MOLLEROptInsensitive
{
public:
  MOLLEROptInsensitive(G4String type,MOLLEROptMaterial* mat);
  ~MOLLEROptInsensitive();

  G4VPhysicalVolume* ConstructInsensitive(G4VPhysicalVolume* Mother);
  
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

  G4LogicalVolume*   GetLogicalVolume()    {return InsLogical;}
  G4VPhysicalVolume* GetPhysicalVolume()   {return InsPhysical;}

  void GetPlateLimits(G4double *vals);

private:

  G4String InsType;

  MOLLEROptInsensitiveMessenger*  InsMessenger;
  MOLLEROptTrackingReadout*       TrackingReadout;
  MOLLEROptMaterial*              Materials;
  MOLLEROptInsensitiveAlPlate*    AlPlate;

  G4VPhysicalVolume* MotherVolume;

  G4LogicalVolume*   InsLogical; 
  G4VPhysicalVolume* InsPhysical;
  G4Box*             InsSolid; 

  G4Material*        VolMaterial;

  G4double InsFullLengthX;
  G4double InsFullLengthY;
  G4double InsFullLengthZ;

  G4ThreeVector     PositionIns;

  G4RotationMatrix* RotationIns;   

  G4double PositionInsX;
  G4double PositionInsY;
  G4double PositionInsZ;

  G4double AzimuAngle;
  G4double PolarAngle;

};
#endif
