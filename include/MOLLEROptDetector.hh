#ifndef MOLLEROptDetector_h
#define MOLLEROptDetector_h 

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptDetectorLightGuide.hh"
#include "MOLLEROptDetectorQuartz.hh"
#include "MOLLEROptDetectorQuartz2.hh"
#include "MOLLEROptDetectorQuartz3.hh"
#include "MOLLEROptDetectorQuartz4.hh"
#include "MOLLEROptDetectorQuartz5.hh"
#include "MOLLEROptDetectorQuartz6.hh"
#include "MOLLEROptDetectorQuartz7.hh"
#include "MOLLEROptDetectorQuartz8.hh"
#include "MOLLEROptDetectorPMT.hh"
#include "MOLLEROptDetectorMessenger.hh"

#include "G4GDMLParser.hh"

class MOLLEROptDetectorMessenger;

class MOLLEROptDetector
{
public:
  MOLLEROptDetector(MOLLEROptTrackingReadout*,G4String type1, G4String type2, G4String type3, G4String type4, G4String type5, G4String type6, G4String type7, G4String type8, MOLLEROptMaterial* mat);
  ~MOLLEROptDetector();

  G4VPhysicalVolume* ConstructDetector(G4VPhysicalVolume* Mother);
  void ConstructMountingStructure(G4VPhysicalVolume* Mother);
  
  void DestroyComponent();
  void Initialize();
  void SetMaterial(G4String materialName);

  //The standard coordinate system is: z=beam direction, y=beam up, x = beam left
  //Dimensions below assume a detector that is located at the origin with the 45 degreee
  //exit face at the upper y end and the width of the detector along +-x.
  
  //Ring 1 objects
  void SetCenterPositionInX1(G4double xPos);
  void SetCenterPositionInY1(G4double yPos);
  void SetCenterPositionInZ1(G4double zPos);
  void SetQuartzSizeX1(G4double x); 
  void SetQuartzSizeY1(G4double y); 
  void SetQuartzSizeZ1(G4double z);
  void SetLowerInterfacePlane1(G4double LowerPlane);
  void SetMiddleBoxHeight1(G4double MiddlePlane);
  void SetUpperInterfacePlane1(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle1(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle1(G4double angle);
  void SetLowerConeSideFaceAngle1(G4double angle);
  void SetQuartzInterfaceOpeningZ1(G4double size);
  void SetQuartzInterfaceOpeningX1(G4double size);
  void SetQuartzToPMTOffsetInZ1(G4double val);

  //Ring 2 objects
  void SetCenterPositionInX2(G4double xPos);
  void SetCenterPositionInY2(G4double yPos);
  void SetCenterPositionInZ2(G4double zPos);
  void SetQuartzSizeX2(G4double x); 
  void SetQuartzSizeY2(G4double y); 
  void SetQuartzSizeZ2(G4double z);
  void SetLowerInterfacePlane2(G4double LowerPlane);
  void SetMiddleBoxHeight2(G4double MiddlePlane);
  void SetUpperInterfacePlane2(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle2(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle2(G4double angle);
  void SetLowerConeSideFaceAngle2(G4double angle);
  void SetQuartzInterfaceOpeningZ2(G4double size);
  void SetQuartzInterfaceOpeningX2(G4double size);
  void SetQuartzToPMTOffsetInZ2(G4double val);

  //Ring 3 objects
  void SetCenterPositionInX3(G4double xPos);
  void SetCenterPositionInY3(G4double yPos);
  void SetCenterPositionInZ3(G4double zPos);
  void SetQuartzSizeX3(G4double x); 
  void SetQuartzSizeY3(G4double y); 
  void SetQuartzSizeZ3(G4double z);
  void SetLowerInterfacePlane3(G4double LowerPlane);
  void SetMiddleBoxHeight3(G4double MiddlePlane);
  void SetUpperInterfacePlane3(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle3(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle3(G4double angle);
  void SetLowerConeSideFaceAngle3(G4double angle);
  void SetQuartzInterfaceOpeningZ3(G4double size);
  void SetQuartzInterfaceOpeningX3(G4double size);
  void SetQuartzToPMTOffsetInZ3(G4double val);

  //Ring 4 objects
  void SetCenterPositionInX4(G4double xPos);
  void SetCenterPositionInY4(G4double yPos);
  void SetCenterPositionInZ4(G4double zPos);
  void SetQuartzSizeX4(G4double x); 
  void SetQuartzSizeY4(G4double y); 
  void SetQuartzSizeZ4(G4double z);
  void SetLowerInterfacePlane4(G4double LowerPlane);
  void SetMiddleBoxHeight4(G4double MiddlePlane);
  void SetUpperInterfacePlane4(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle4(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle4(G4double angle);
  void SetLowerConeSideFaceAngle4(G4double angle);
  void SetQuartzInterfaceOpeningZ4(G4double size);
  void SetQuartzInterfaceOpeningX4(G4double size);
  void SetQuartzToPMTOffsetInZ4(G4double val);

  //Ring 5 objects
  void SetCenterPositionInX5(G4double xPos);
  void SetCenterPositionInY5(G4double yPos);
  void SetCenterPositionInZ5(G4double zPos);
  void SetQuartzSizeX5(G4double x); 
  void SetQuartzSizeY5(G4double y); 
  void SetQuartzSizeZ5(G4double z);
  void SetLowerInterfacePlane5(G4double LowerPlane);
  void SetMiddleBoxHeight5(G4double MiddlePlane);
  void SetUpperInterfacePlane5(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle5(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle5(G4double angle);
  void SetLowerConeSideFaceAngle5(G4double angle);
  void SetQuartzInterfaceOpeningZ5(G4double size);
  void SetQuartzInterfaceOpeningX5(G4double size);
  void SetQuartzToPMTOffsetInZ5(G4double val);

  //Ring 6 objects
  void SetCenterPositionInX6(G4double xPos);
  void SetCenterPositionInY6(G4double yPos);
  void SetCenterPositionInZ6(G4double zPos);
  void SetQuartzSizeX6(G4double x); 
  void SetQuartzSizeY6(G4double y); 
  void SetQuartzSizeZ6(G4double z);
  void SetLowerInterfacePlane6(G4double LowerPlane);
  void SetMiddleBoxHeight6(G4double MiddlePlane);
  void SetUpperInterfacePlane6(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle6(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle6(G4double angle);
  void SetLowerConeSideFaceAngle6(G4double angle);
  void SetQuartzInterfaceOpeningZ6(G4double size);
  void SetQuartzInterfaceOpeningX6(G4double size);
  void SetQuartzToPMTOffsetInZ6(G4double val);

  //Ring 7 objects
  void SetCenterPositionInX7(G4double xPos);
  void SetCenterPositionInY7(G4double yPos);
  void SetCenterPositionInZ7(G4double zPos);
  void SetQuartzSizeX7(G4double x); 
  void SetQuartzSizeY7(G4double y); 
  void SetQuartzSizeZ7(G4double z);
  void SetLowerInterfacePlane7(G4double LowerPlane);
  void SetMiddleBoxHeight7(G4double MiddlePlane);
  void SetUpperInterfacePlane7(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle7(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle7(G4double angle);
  void SetLowerConeSideFaceAngle7(G4double angle);
  void SetQuartzInterfaceOpeningZ7(G4double size);
  void SetQuartzInterfaceOpeningX7(G4double size);
  void SetQuartzToPMTOffsetInZ7(G4double val);

  //Ring 8 objects
  void SetCenterPositionInX8(G4double xPos);
  void SetCenterPositionInY8(G4double yPos);
  void SetCenterPositionInZ8(G4double zPos);
  void SetQuartzSizeX8(G4double x); 
  void SetQuartzSizeY8(G4double y); 
  void SetQuartzSizeZ8(G4double z);
  void SetLowerInterfacePlane8(G4double LowerPlane);
  void SetMiddleBoxHeight8(G4double MiddlePlane);
  void SetUpperInterfacePlane8(G4double UpperPlane);
  void SetLowerConeFrontFaceAngle8(G4double angle) ; //in radians
  void SetLowerConeBackFaceAngle8(G4double angle);
  void SetLowerConeSideFaceAngle8(G4double angle);
  void SetQuartzInterfaceOpeningZ8(G4double size);
  void SetQuartzInterfaceOpeningX8(G4double size);
  void SetQuartzToPMTOffsetInZ8(G4double val);

  //General objects
  void SetQuartzRotX(G4double r);
  void SetAzimuthalRotationAngle(G4double a); //w.r.t. to the positive y axis (up) in radians
  void SetPolarRotationAngle(G4double a); //w.r.t. to the positive z axis (downstream) in radians

  void SetLightGuideOffsetInX(G4double x);
  void SetLightGuideOffsetInY(G4double y);
  void SetLightGuideOffsetInZ(G4double z);

  void SetPMTInterfaceOpeningZ(G4double size);
  void SetPMTInterfaceOpeningX(G4double size);
  void SetQuartzBevel(G4double bev) {Quartz1->SetBevelSize(bev); Quartz2->SetBevelSize(bev); Quartz3->SetBevelSize(bev); Quartz4->SetBevelSize(bev); Quartz5->SetBevelSize(bev); Quartz6->SetBevelSize(bev); Quartz7->SetBevelSize(bev); Quartz8->SetBevelSize(bev); }

  void SetPMTCathodeRadius(G4double size);
  void SetPMTCathodeThickness(G4double size);
  
  void UpdateThisGeometry();
  void CalculateDimensions();
  void ResetCenterLocation();
  void SetSegRadDamageFlag() {if(Quartz1) Quartz1->SetSegRadDamageFlag(); if(Quartz2) Quartz2->SetSegRadDamageFlag(); if(Quartz3) Quartz3->SetSegRadDamageFlag(); if(Quartz4) Quartz4->SetSegRadDamageFlag(); if(Quartz5) Quartz5->SetSegRadDamageFlag(); if(Quartz6) Quartz6->SetSegRadDamageFlag(); if(Quartz7) Quartz7->SetSegRadDamageFlag(); if(Quartz8) Quartz8->SetSegRadDamageFlag(); Materials->SetSegRadDamage();}

  G4LogicalVolume*   GetLogicalVolume()    {return DetLogical;}
  G4VPhysicalVolume* GetPhysicalVolume()   {return DetPhysical;}

  void GetQuartzLimits(G4double *vals);
  void GetLightGuideLimits(G4double *vals);


private:

  G4GDMLParser gdmlParser;

  G4String fReadFile;
  G4String fWriteFile;
  G4String fStepFile;
  G4int fWritingChoice;

  G4String DetType1; //like: Ring5, or Ring1 ...
  G4String DetType2;
  G4String DetType3;
  G4String DetType4;
  G4String DetType5;
  G4String DetType6;
  G4String DetType7;
  G4String DetType8;

  MOLLEROptDetectorMessenger*  detMessenger;
  MOLLEROptTrackingReadout *TrackingReadout;
  MOLLEROptMaterial* Materials;
  MOLLEROptDetectorLightGuide* LightGuide1; 
  MOLLEROptDetectorQuartz*     Quartz1;
  MOLLEROptDetectorPMT*        PMT1;
  MOLLEROptDetectorLightGuide* LightGuide2; 
  MOLLEROptDetectorQuartz2*    Quartz2;
  MOLLEROptDetectorPMT*        PMT2;
  MOLLEROptDetectorLightGuide* LightGuide3; 
  MOLLEROptDetectorQuartz3*     Quartz3;
  MOLLEROptDetectorPMT*        PMT3;
  MOLLEROptDetectorLightGuide* LightGuide4; 
  MOLLEROptDetectorQuartz4*     Quartz4;
  MOLLEROptDetectorPMT*        PMT4;
  MOLLEROptDetectorLightGuide* LightGuide5; 
  MOLLEROptDetectorQuartz5*     Quartz5;
  MOLLEROptDetectorPMT*        PMT5;
  MOLLEROptDetectorLightGuide* LightGuide6; 
  MOLLEROptDetectorQuartz6*     Quartz6;
  MOLLEROptDetectorPMT*        PMT6;
  MOLLEROptDetectorLightGuide* LightGuide7; 
  MOLLEROptDetectorQuartz7*     Quartz7;
  MOLLEROptDetectorPMT*        PMT7;
  MOLLEROptDetectorLightGuide* LightGuide8; 
  MOLLEROptDetectorQuartz8*     Quartz8;
  MOLLEROptDetectorPMT*        PMT8;

  G4VPhysicalVolume* MotherVolume;

  G4LogicalVolume*   DetLogical; 
  G4VPhysicalVolume* DetPhysical;
  G4Box*             DetSolid; 

  G4Material*        DetMaterial;

  G4double DetFullLengthX1;
  G4double DetFullLengthY1;
  G4double DetFullLengthZ1;
  G4double DetFullLengthX2;
  G4double DetFullLengthY2;
  G4double DetFullLengthZ2;
  G4double DetFullLengthX3;
  G4double DetFullLengthY3;
  G4double DetFullLengthZ3;
  G4double DetFullLengthX4;
  G4double DetFullLengthY4;
  G4double DetFullLengthZ4;
  G4double DetFullLengthX5;
  G4double DetFullLengthY5;
  G4double DetFullLengthZ5;
  G4double DetFullLengthX6;
  G4double DetFullLengthY6;
  G4double DetFullLengthZ6;
  G4double DetFullLengthX7;
  G4double DetFullLengthY7;
  G4double DetFullLengthZ7;
  G4double DetFullLengthX8;
  G4double DetFullLengthY8;
  G4double DetFullLengthZ8;

  G4ThreeVector     PositionDet1;
  G4ThreeVector     PositionDet2;
  G4ThreeVector     PositionDet3;
  G4ThreeVector     PositionDet4;
  G4ThreeVector     PositionDet5;
  G4ThreeVector     PositionDet6;
  G4ThreeVector     PositionDet7;
  G4ThreeVector     PositionDet8;

  G4RotationMatrix* RotationDet;  

  G4double PositionDetX1;
  G4double PositionDetY1;
  G4double PositionDetZ1;
  G4double PositionDetX2;
  G4double PositionDetY2;
  G4double PositionDetZ2;
  G4double PositionDetX3;
  G4double PositionDetY3;
  G4double PositionDetZ3;
  G4double PositionDetX4;
  G4double PositionDetY4;
  G4double PositionDetZ4;
  G4double PositionDetX5;
  G4double PositionDetY5;
  G4double PositionDetZ5;
  G4double PositionDetX6;
  G4double PositionDetY6;
  G4double PositionDetZ6;
  G4double PositionDetX7;
  G4double PositionDetY7;
  G4double PositionDetZ7;
  G4double PositionDetX8;
  G4double PositionDetY8;
  G4double PositionDetZ8;

  G4double AzimuAngle;
  G4double PolarAngle;

  G4double PMTToQuartzOffset1;
  G4double PMTToQuartzOffset2;  
  G4double PMTToQuartzOffset3;  
  G4double PMTToQuartzOffset4;  
  G4double PMTToQuartzOffset5;  
  G4double PMTToQuartzOffset6;  
  G4double PMTToQuartzOffset7;  
  G4double PMTToQuartzOffset8;  

  //Detector Mounting structure

  //Left side of LG lower cone and quartz tray
  G4GenericTrap* QLGTray_Sld_Left_out;
  G4GenericTrap* QLGTray_Sld_Left_In; 
  G4SubtractionSolid* QLGTray_Sld_Left;

  
};
#endif
