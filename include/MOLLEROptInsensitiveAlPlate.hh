#ifndef MOLLEROptInsensitiveAlPlate_h
#define MOLLEROptInsensitiveAlPlate_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"
#include "G4VisExtent.hh"

#include "MOLLEROptMaterial.hh"

class MOLLEROptInsensitiveAlPlate 
{
public:
  MOLLEROptInsensitiveAlPlate(G4String type13, MOLLEROptMaterial* mat);
  ~MOLLEROptInsensitiveAlPlate();

  void Construct(G4VPhysicalVolume* Mother);
  void Initialize();
  void SetMaterial(G4String materialName);

  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);
  G4double GetCurrentCenterPositionInX()   {return PlatePhysical->GetTranslation().x();}//PositionX;};
  G4double GetCurrentCenterPositionInY()   {return PlatePhysical->GetTranslation().y();}//PositionY;};
  G4double GetCurrentCenterPositionInZ()   {return PlatePhysical->GetTranslation().z();}//PositionZ;};
  G4ThreeVector GetCurrentCenterPosition() {return PlatePhysical->GetTranslation();};
  void SetAzimuthalRotationAngle(G4double a); //w.r.t. to the positive y axis (up) in radians
  void SetPolarRotationAngle(G4double a); //w.r.t. to the positive z axis (downstream) in radians
  
  //The standard coordinate system is: z=beam direction, y=beam up, x = beam left

  void SetSizeX(G4double x){FullLengthX = x;}; 
  void SetSizeY(G4double y){FullLengthY = y;}; 
  void SetSizeZ(G4double z){FullLengthZ = z;};
  void SetRotX(G4double r);
  void SetRotZ(G4double r);
  G4double GetSizeX() {return FullLengthX;}; 
  G4double GetSizeY() {return FullLengthY;}; 
  G4double GetSizeZ() {return FullLengthZ;};

  G4double GetRotationX(){return RotationX;};
  G4double GetRotationZ(){return RotationZ;};

  void GetPlateLimits(G4double *vals);

  void UpdateGeometry();
  void ClearVolumes();

  G4LogicalVolume*   GetLogicalVolume()    {return PlateLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return PlatePhysical;} 

private:

  G4String Name;
  
  MOLLEROptMaterial* Materials;
  

  G4VPhysicalVolume* MotherVolume;

  G4GenericTrap*      PlateSolid;
  G4LogicalVolume*    PlateLogical; 
  G4VPhysicalVolume*  PlatePhysical; 
  G4Material*         PlateMaterial;

  G4double FullLengthX;
  G4double FullLengthY;
  G4double FullLengthZ;

  std::vector<G4TwoVector> Vertices;
  
  G4ThreeVector     Position;
  G4RotationMatrix* Rotation;
  G4double   RotationX;
  G4double   RotationZ;

  G4double PositionX;
  G4double PositionY;
  G4double PositionZ;
  
  OptParam* OpticalParameters;

};
#endif
