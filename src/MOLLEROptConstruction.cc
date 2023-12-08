#include "MOLLEROptConstruction.hh"

MOLLEROptConstruction::MOLLEROptConstruction(MOLLEROptTrackingReadout *trReadout, MOLLEROptMaterial* mat) 
  : G4VUserDetectorConstruction()
{
  World_Solid    = NULL;  
  World_Logical  = NULL;  
  World_Physical = NULL;
  
  MOLLERMessenger = NULL;
  Materials       = mat;

  Detector        = NULL;
  //LightGuide1      = NULL;
  //Detector2        = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  if (Detector)          delete Detector;
  //if (Material)         delete Material;
  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  Detector = new MOLLEROptDetector(TrackingReadout,"1Ring","2Ring", "3Ring","4Ring","5Ring","6Ring","7Ring","8Ring","9Ring", Materials);
  //DetMessenger = new MOLLEROptDetectorMessenger(Detector);
  
  fWorldLengthInX =  15.0*m;
  fWorldLengthInY =  15.0*m;
  fWorldLengthInZ =  30.0*m;
  
  World_Material   = Materials->GetMaterial("Vacuum");
  
  World_Solid = new G4Box("World_Solid",
			  0.5* fWorldLengthInX , 
			  0.5* fWorldLengthInY ,
			  0.5* fWorldLengthInZ );
  
  World_Logical = new G4LogicalVolume( World_Solid, 
				       World_Material, 
				       "World_Logical", 
				       0, 0, 0);
  World_Physical = new G4PVPlacement(0, // no rotation
				     G4ThreeVector(), // at (0,0,0)
				     World_Logical,  
				     "World_Physical", 
				     0,false,0);             
  
  // Detector->ConstructComponent(World_Physical);
  // Detector->SetCenterPositionInZ(0.0*cm);
  // LightGuide->ConstructComponent(World_Physical);
  // LightGuide->SetCenterPositionInY(7.5*cm);

  //Ring 1
  Detector->SetQuartzSizeX1(8.4*cm);
  Detector->SetQuartzSizeY1(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ1(1.5*cm);
  Detector->SetLowerInterfacePlane1(5.6*cm);
  Detector->SetMiddleBoxHeight1(9.0*cm);
  Detector->SetUpperInterfacePlane1(25*cm);
  Detector->SetLowerConeFrontFaceAngle1(28*degree);
  Detector->SetLowerConeBackFaceAngle1(22*degree);
  Detector->SetLowerConeSideFaceAngle1(0*degree);
  Detector->SetQuartzInterfaceOpeningZ1(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX1(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ1(-0.3*cm);  
  
  //Ring 2
  Detector->SetQuartzSizeX2(8.4*cm);
  Detector->SetQuartzSizeY2(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ2(1.5*cm);
  Detector->SetLowerInterfacePlane2(5.6*cm);
  Detector->SetMiddleBoxHeight2(9.0*cm);
  Detector->SetUpperInterfacePlane2(25*cm);
  Detector->SetLowerConeFrontFaceAngle2(28*degree);
  Detector->SetLowerConeBackFaceAngle2(22*degree);
  Detector->SetLowerConeSideFaceAngle2(0*degree);
  Detector->SetQuartzInterfaceOpeningZ2(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX2(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ2(-0.3*cm);  

  //Ring 3
  Detector->SetQuartzSizeX3(8.4*cm);
  Detector->SetQuartzSizeY3(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ3(1.5*cm);
  Detector->SetLowerInterfacePlane3(5.6*cm);
  Detector->SetMiddleBoxHeight3(9.0*cm);
  Detector->SetUpperInterfacePlane3(25*cm);
  Detector->SetLowerConeFrontFaceAngle3(28*degree);
  Detector->SetLowerConeBackFaceAngle3(22*degree);
  Detector->SetLowerConeSideFaceAngle3(0*degree);
  Detector->SetQuartzInterfaceOpeningZ3(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX3(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ3(-0.3*cm);  
  
  //Ring 4
  Detector->SetQuartzSizeX4(8.4*cm);
  Detector->SetQuartzSizeY4(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ4(1.5*cm);
  Detector->SetLowerInterfacePlane4(5.6*cm);
  Detector->SetMiddleBoxHeight4(9.0*cm);
  Detector->SetUpperInterfacePlane4(25*cm);
  Detector->SetLowerConeFrontFaceAngle4(28*degree);
  Detector->SetLowerConeBackFaceAngle4(22*degree);
  Detector->SetLowerConeSideFaceAngle4(0*degree);
  Detector->SetQuartzInterfaceOpeningZ4(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX4(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ4(-0.3*cm);  
  
  //Ring 5
  Detector->SetQuartzSizeX5(8.4*cm);
  Detector->SetQuartzSizeY5(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ5(1.5*cm);
  Detector->SetLowerInterfacePlane5(5.6*cm);
  Detector->SetMiddleBoxHeight5(9.0*cm);
  Detector->SetUpperInterfacePlane5(25*cm);
  Detector->SetLowerConeFrontFaceAngle5(28*degree);
  Detector->SetLowerConeBackFaceAngle5(22*degree);
  Detector->SetLowerConeSideFaceAngle5(0*degree);
  Detector->SetQuartzInterfaceOpeningZ5(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX5(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ5(-0.3*cm);  
 
  //Ring 6 (R5 backflush 1)
  Detector->SetQuartzSizeX6(8.4*cm);
  Detector->SetQuartzSizeY6(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ6(1.5*cm);
  Detector->SetLowerInterfacePlane6(5.6*cm);
  Detector->SetMiddleBoxHeight6(9.0*cm);
  Detector->SetUpperInterfacePlane6(25*cm);
  Detector->SetLowerConeFrontFaceAngle6(28*degree);
  Detector->SetLowerConeBackFaceAngle6(22*degree);
  Detector->SetLowerConeSideFaceAngle6(0*degree);
  Detector->SetQuartzInterfaceOpeningZ6(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX6(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ6(-0.3*cm);  
  
  //Ring 7 (R5 backflush 2)
  Detector->SetQuartzSizeX7(8.4*cm);
  Detector->SetQuartzSizeY7(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ7(1.5*cm);
  Detector->SetLowerInterfacePlane7(5.6*cm);
  Detector->SetMiddleBoxHeight7(9.0*cm);
  Detector->SetUpperInterfacePlane7(25*cm);
  Detector->SetLowerConeFrontFaceAngle7(28*degree);
  Detector->SetLowerConeBackFaceAngle7(22*degree);
  Detector->SetLowerConeSideFaceAngle7(0*degree);
  Detector->SetQuartzInterfaceOpeningZ7(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX7(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ7(-0.3*cm);  
  
  //Ring 8 (R6)
  Detector->SetQuartzSizeX8(8.4*cm);
  Detector->SetQuartzSizeY8(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ8(1.5*cm);
  Detector->SetLowerInterfacePlane8(5.6*cm);
  Detector->SetMiddleBoxHeight8(9.0*cm);
  Detector->SetUpperInterfacePlane8(25*cm);
  Detector->SetLowerConeFrontFaceAngle8(28*degree);
  Detector->SetLowerConeBackFaceAngle8(22*degree);
  Detector->SetLowerConeSideFaceAngle8(0*degree);
  Detector->SetQuartzInterfaceOpeningZ8(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX8(9.2*cm);
  Detector->SetQuartzToPMTOffsetInZ8(-0.3*cm);  

  //Scintillator (After R1)
  Detector->SetScintillatorSizeX(60.0*cm);
  Detector->SetScintillatorSizeY(72.0*cm);  //without the 45 degree cut region
  Detector->SetScintillatorSizeZ(0.01*cm);
  
  //General objects
  Detector->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector->SetPMTInterfaceOpeningX(5.6*cm);  
  Detector->SetPMTCathodeRadius(3.5*cm);
  Detector->SetPMTCathodeThickness(0.1*cm);
  Detector->SetAzimuthalRotationAngle(0);
  Detector->SetPolarRotationAngle(0);
  Detector->Initialize();
  Detector->ConstructDetector(World_Physical);

  World_Logical->SetVisAttributes (G4VisAttributes::GetInvisible);
  
  DumpGeometricalTree(World_Physical);
  
  return World_Physical;
}

void MOLLEROptConstruction::GetQuartz1Limits(G4double *vals)
{
  Detector->GetQuartz1Limits(vals);
}
void MOLLEROptConstruction::GetQuartz2Limits(G4double *vals)
{
  Detector->GetQuartz2Limits(vals);
}
void MOLLEROptConstruction::GetQuartz3Limits(G4double *vals)
{
  Detector->GetQuartz3Limits(vals);
}
void MOLLEROptConstruction::GetQuartz4Limits(G4double *vals)
{
  Detector->GetQuartz4Limits(vals);
}
void MOLLEROptConstruction::GetQuartz5Limits(G4double *vals)
{
  Detector->GetQuartz5Limits(vals);
}
void MOLLEROptConstruction::GetQuartz6Limits(G4double *vals)
{
  Detector->GetQuartz6Limits(vals);
}
void MOLLEROptConstruction::GetQuartz7Limits(G4double *vals)
{
  Detector->GetQuartz7Limits(vals);
}
void MOLLEROptConstruction::GetQuartz8Limits(G4double *vals)
{
  Detector->GetQuartz8Limits(vals);
}
void MOLLEROptConstruction::GetScintillatorLimits(G4double *vals)
{
  Detector->GetScintillatorLimits(vals);
}

void MOLLEROptConstruction::GetLightGuide1Limits(G4double *vals)
{
  Detector->GetLightGuide1Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide2Limits(G4double *vals)
{
  Detector->GetLightGuide2Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide3Limits(G4double *vals)
{
  Detector->GetLightGuide3Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide4Limits(G4double *vals)
{
  Detector->GetLightGuide4Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide5Limits(G4double *vals)
{
  Detector->GetLightGuide5Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide6Limits(G4double *vals)
{
  Detector->GetLightGuide6Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide7Limits(G4double *vals)
{
  Detector->GetLightGuide7Limits(vals);
}
void MOLLEROptConstruction::GetLightGuide8Limits(G4double *vals)
{
  Detector->GetLightGuide8Limits(vals);
}


void MOLLEROptConstruction::DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth)
{
  for(int isp=0;isp<depth;isp++)
    { G4cout << "  "; }
  G4cout << aVolume->GetName() << "[" << aVolume->GetCopyNo() << "] "
         << aVolume->GetLogicalVolume()->GetName() << " "
         << aVolume->GetLogicalVolume()->GetNoDaughters() << " "
	 << aVolume->GetLogicalVolume()->GetMaterial()->GetName();
  if(aVolume->GetLogicalVolume()->GetSensitiveDetector())
  {
    G4cout << " " << aVolume->GetLogicalVolume()->GetSensitiveDetector()
                            ->GetFullPathName();
  }
  G4cout << G4endl;
  for(int i=0;i<aVolume->GetLogicalVolume()->GetNoDaughters();i++){
    
    DumpGeometricalTree(aVolume->GetLogicalVolume()->GetDaughter(i),depth+1);


  }
}


void MOLLEROptConstruction::UpdateGeometry()
{
  G4GeometryManager::GetInstance()->OpenGeometry();

  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
  G4LogicalBorderSurface::CleanSurfaceTable();


  G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
}

