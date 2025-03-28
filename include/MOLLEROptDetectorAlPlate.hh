#ifndef MOLLEROptDetectorAlPlate_h
#define MOLLEROptDetectorAlPlate_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"
#include "G4VisExtent.hh"

#include "MOLLEROptMaterial.hh"

class MOLLEROptDetectorAlPlate 
{
public:
  MOLLEROptDetectorAlPlate(G4String type13, MOLLEROptMaterial* mat);
  ~MOLLEROptDetectorAlPlate();

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
  //Dimensions below assume a detector that is located at the origin with the 45 degreee
  //exit face at the upper y end and the width of the detector along +-x.

  void SetPlateSizeX(G4double x){FullLengthX = x;}; 
  void SetPlateSizeY(G4double y){FullLengthY = y;}; 
  void SetPlateSizeZ(G4double z){FullLengthZ = z;};
  void SetPlateRotX(G4double r);
  void SetPlateRotZ(G4double r);
  G4double GetPlateSizeX() {return FullLengthX;}; 
  G4double GetPlateSizeY() {return FullLengthY;}; 
  G4double GetPlateSizeZ() {return FullLengthZ;};

  G4double GetPlateRotationX(){return RotationX;};
  G4double GetPlateRotationZ(){return RotationZ;};

  void GetPlateLimits(G4double *vals);

  void UpdateGeometry();
  void ClearVolumes();

  G4LogicalVolume*   GetLogicalVolume()    {return PlateLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return PlatePhysical;} 

private:

  G4String Name;
  
  MOLLEROptMaterial* Materials;
  
  // MOLLEROptDetectorMessenger* DetMessenger;

  G4VPhysicalVolume* MotherVolume;

  G4LogicalVolume*   PlateLogical; 
  G4VPhysicalVolume* PlatePhysical; 
  G4Material*        PlateMaterial;
  G4SubtractionSolid* PlateSolid;
  //G4GenericTrap*     PlateSolid;

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
