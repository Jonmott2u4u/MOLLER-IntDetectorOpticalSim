#ifndef MOLLEROptAuxilaryScint_h
#define MOLLEROptAuxilaryScint_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"
#include "G4VisExtent.hh"

#include "MOLLEROptScintSD.hh"
#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"

class MOLLEROptAuxilaryScint 
{
public:
  MOLLEROptAuxilaryScint(MOLLEROptTrackingReadout*, G4String type9, MOLLEROptMaterial* mat);
  ~MOLLEROptAuxilaryScint();

  void Construct(G4VPhysicalVolume* Mother);
  void Initialize();
  void SetMaterial(G4String materialName);

  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);
  G4double GetCurrentCenterPositionInX()   {return ScintPhysical->GetTranslation().x();}//PositionX;};
  G4double GetCurrentCenterPositionInY()   {return ScintPhysical->GetTranslation().y();}//PositionY;};
  G4double GetCurrentCenterPositionInZ()   {return ScintPhysical->GetTranslation().z();}//PositionZ;};
  G4ThreeVector GetCurrentCenterPosition() {return ScintPhysical->GetTranslation();};
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

  void GetScintLimits(G4double *vals);

  void UpdateGeometry();
  void ClearVolumes();

  G4LogicalVolume*   GetLogicalVolume()    {return ScintLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return ScintPhysical;} 

private:

  G4String Name;
  
  MOLLEROptTrackingReadout *TrackingReadout;
  MOLLEROptMaterial* Materials;

  G4VPhysicalVolume* MotherVolume;

  G4GenericTrap*     ScintSolid;
  G4LogicalVolume*   ScintLogical; 
  G4VPhysicalVolume* ScintPhysical; 
  G4Material*        ScintMaterial;

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

  G4SDManager* SDman;
  G4VSensitiveDetector* ScintSD;
  
  OptParam* OpticalParameters;

};
#endif
