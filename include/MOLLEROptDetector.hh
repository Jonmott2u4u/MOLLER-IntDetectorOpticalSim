#ifndef MOLLEROptDetector_h
#define MOLLEROptDetector_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptDetectorQuartz.hh"
#include "MOLLEROptDetectorLightGuide.hh"
#include "MOLLEROptDetectorPMT.hh"
#include "MOLLEROptDetectorMessenger.hh"

#include "G4GDMLParser.hh"

class MOLLEROptDetectorMessenger;

class MOLLEROptDetector
{
public:
  MOLLEROptDetector(MOLLEROptTrackingReadout*,G4String type,MOLLEROptMaterial* mat,G4String lgmat);
  ~MOLLEROptDetector();

  G4VPhysicalVolume* ConstructDetector(G4VPhysicalVolume* Mother);
  
  void DestroyComponent();
  void Initialize();
  void SetMaterial(G4String materialName);

  //The standard coordinate system is: z=beam direction, y=beam up, x = beam left
  //Dimensions below assume a detector that is located at the origin with the 45 degreee
  //exit face at the upper y end and the width of the detector along +-x.
  
  //Ring objects
  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);
  void SetQuartzRotX(G4double a); 
  void SetQuartzSizeX(G4double x); 
  void SetQuartzSizeY(G4double y); 
  void SetQuartzSizeZ(G4double z);
  void SetLowerInterfacePlane(G4double LowerPlane);
  void SetMiddleBoxHeight(G4double MiddlePlane);
  void SetUpperInterfacePlane(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle(G4double angle);
  void SetLowerConeSideFaceAngle(G4double angle);
  void SetQuartzInterfaceOpeningZ(G4double size);
  void SetQuartzInterfaceOpeningX(G4double size);
  void SetQuartzToPMTOffsetInZ(G4double val);

  void SetAzimuthalRotationAngle(G4double a); //w.r.t. to the positive y axis (up) in radians
  void SetPolarRotationAngle(G4double a); //w.r.t. to the positive z axis (downstream) in radians

  void SetLightGuideOffsetInX(G4double x);
  void SetLightGuideOffsetInY(G4double y);
  void SetLightGuideOffsetInZ(G4double z);

  void SetPMTInterfaceOpeningZ(G4double size);
  void SetPMTInterfaceOpeningX(G4double size);
  void SetQuartzBevel(G4double bev) {Quartz->SetBevelSize(bev);}

  void SetPMTCathodeRadius(G4double size);
  void SetPMTCathodeThickness(G4double size);
  
  void UpdateThisGeometry();
  void CalculateDimensions();
  void ResetCenterLocation();

  G4LogicalVolume*   GetLogicalVolume()    {return DetLogical;}
  G4VPhysicalVolume* GetPhysicalVolume()   {return DetPhysical;}

  void GetQuartzLimits(G4double *vals);
  void GetLightGuideLimits(G4double *vals);

private:

  G4String DetType;
  G4String LightGuideMat;

  MOLLEROptDetectorMessenger*  detMessenger;
  MOLLEROptTrackingReadout*    TrackingReadout;
  MOLLEROptMaterial*           Materials;
  MOLLEROptDetectorLightGuide* LightGuide; 
  MOLLEROptDetectorQuartz*     Quartz;
  MOLLEROptDetectorPMT*        PMT;

  G4VPhysicalVolume* MotherVolume;

  G4LogicalVolume*   DetLogical; 
  G4VPhysicalVolume* DetPhysical;
  G4Box*             DetSolid; 

  G4Material*        VolMaterial;

  G4double DetFullLengthX;
  G4double DetFullLengthY;
  G4double DetFullLengthZ;

  G4ThreeVector     PositionDet;
  G4ThreeVector     QuartzPos;

  G4RotationMatrix* RotationDet;   

  G4double PositionDetX;
  G4double PositionDetY;
  G4double PositionDetZ;

  G4double AzimuAngle;
  G4double PolarAngle;

  G4double PMTToQuartzOffset;

};
#endif
