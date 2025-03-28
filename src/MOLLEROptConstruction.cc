#include "MOLLEROptConstruction.hh"

MOLLEROptConstruction::MOLLEROptConstruction(MOLLEROptTrackingReadout *trReadout, MOLLEROptMaterial* mat) 
  : G4VUserDetectorConstruction()
{
  World_Solid    = NULL;  
  World_Logical  = NULL;  
  World_Physical = NULL;
  
  MOLLERMessenger = NULL;
  Materials       = mat;

  Ring1        = NULL;
  Ring2        = NULL;
  Ring3        = NULL;
  Ring4        = NULL;
  Ring5        = NULL;
  Ring6        = NULL;
  Ring7        = NULL;
  Ring8        = NULL;

  Scint1        = NULL;
  Scint2        = NULL;
  Scint3        = NULL;
  Scint4        = NULL;

  AlPlate        = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  if (Ring1)          delete Ring1;
  if (Ring2)          delete Ring2;
  if (Ring3)          delete Ring3;
  if (Ring4)          delete Ring4;
  if (Ring5)          delete Ring5;
  if (Ring6)          delete Ring6;
  if (Ring7)          delete Ring7;
  if (Ring8)          delete Ring8
  
  if (Scint1)         delete Scint1;
  if (Scint2)         delete Scint2;
  if (Scint3)         delete Scint3;
  if (Scint4)         delete Scint4;

  if (AlPlate)        delete AlPlate;

  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  Ring1 = new MOLLEROptDetector(TrackingReadout,"1Ring",Materials);
  Ring2 = new MOLLEROptDetector(TrackingReadout,"2Ring",Materials);
  Ring3 = new MOLLEROptDetector(TrackingReadout,"3Ring",Materials);
  Ring4 = new MOLLEROptDetector(TrackingReadout,"4Ring",Materials);
  Ring5 = new MOLLEROptDetector(TrackingReadout,"5Ring",Materials);
  Ring6 = new MOLLEROptDetector(TrackingReadout,"6Ring",Materials);
  Ring7 = new MOLLEROptDetector(TrackingReadout,"7Ring",Materials);
  Ring8 = new MOLLEROptDetector(TrackingReadout,"8Ring",Materials);

  //Build a new file MOLLEROptAuxilary.cc that connects to MOLLEROptAuxilaryScint.cc, Hit.cc and SD.cc
  //Should stop reusing Quartz.cc files
  Scint1 = new MOLLEROptAuxilary(TrackingReadout,"1Scint",Materials);
  Scint2 = new MOLLEROptAuxilary(TrackingReadout,"2Scint",Materials);
  Scint3 = new MOLLEROptAuxilary(TrackingReadout,"3Scint",Materials);
  Scint4 = new MOLLEROptAuxilary(TrackingReadout,"4Scint",Materials);

  //Do the same for the Aluminum Plate. Make a MOLLEROptInsensitives.cc file to contain optically insensitive materials
  //These should be objects that we do not store info for, such as the Al Plate, and are not SD's
  AlPlate = new MOLLEROptInsensitive("AlPlate",Materials)
  
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

  //Ring 1
  Ring1->SetQuartzSizeX1(8.4*cm);
  Ring1->SetQuartzSizeY1(15*cm);  //without the 45 degree cut region
  Ring1->SetQuartzSizeZ1(1.5*cm);
  Ring1->SetLowerInterfacePlane1(5.6*cm);
  Ring1->SetMiddleBoxHeight1(9.0*cm);
  Ring1->SetUpperInterfacePlane1(25*cm);
  Ring1->SetLowerConeFrontFaceAngle1(28*degree);
  Ring1->SetLowerConeBackFaceAngle1(22*degree);
  Ring1->SetLowerConeSideFaceAngle1(0*degree);
  Ring1->SetQuartzInterfaceOpeningZ1(1.8*cm);
  Ring1->SetQuartzInterfaceOpeningX1(9.2*cm);
  Ring1->SetQuartzToPMTOffsetInZ1(-0.3*cm);  
  Ring1->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring1->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring1->SetPMTCathodeRadius(3.5*cm);
  Ring1->SetPMTCathodeThickness(0.1*cm);
  Ring1->SetAzimuthalRotationAngle(0);
  Ring1->SetPolarRotationAngle(0);
  Ring1->Initialize();
  Ring1->ConstructDetector(World_Physical);
  
  //Ring 2
  Ring2->SetQuartzSizeX2(8.4*cm);
  Ring2->SetQuartzSizeY2(15*cm);  //without the 45 degree cut region
  Ring2->SetQuartzSizeZ2(1.5*cm);
  Ring2->SetLowerInterfacePlane2(5.6*cm);
  Ring2->SetMiddleBoxHeight2(9.0*cm);
  Ring2->SetUpperInterfacePlane2(25*cm);
  Ring2->SetLowerConeFrontFaceAngle2(28*degree);
  Ring2->SetLowerConeBackFaceAngle2(22*degree);
  Ring2->SetLowerConeSideFaceAngle2(0*degree);
  Ring2->SetQuartzInterfaceOpeningZ2(1.8*cm);
  Ring2->SetQuartzInterfaceOpeningX2(9.2*cm);
  Ring2->SetQuartzToPMTOffsetInZ2(-0.3*cm);  
  Ring2->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring2->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring2->SetPMTCathodeRadius(3.5*cm);
  Ring2->SetPMTCathodeThickness(0.1*cm);
  Ring2->SetAzimuthalRotationAngle(0);
  Ring2->SetPolarRotationAngle(0);
  Ring2->Initialize();
  Ring2->ConstructDetector(World_Physical);

  //Ring 3
  Ring3->SetQuartzSizeX3(8.4*cm);
  Ring3->SetQuartzSizeY3(15*cm);  //without the 45 degree cut region
  Ring3->SetQuartzSizeZ3(1.5*cm);
  Ring3->SetLowerInterfacePlane3(5.6*cm);
  Ring3->SetMiddleBoxHeight3(9.0*cm);
  Ring3->SetUpperInterfacePlane3(25*cm);
  Ring3->SetLowerConeFrontFaceAngle3(28*degree);
  Ring3->SetLowerConeBackFaceAngle3(22*degree);
  Ring3->SetLowerConeSideFaceAngle3(0*degree);
  Ring3->SetQuartzInterfaceOpeningZ3(1.8*cm);
  Ring3->SetQuartzInterfaceOpeningX3(9.2*cm);
  Ring3->SetQuartzToPMTOffsetInZ3(-0.3*cm);  
  Ring3->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring3->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring3->SetPMTCathodeRadius(3.5*cm);
  Ring3->SetPMTCathodeThickness(0.1*cm);
  Ring3->SetAzimuthalRotationAngle(0);
  Ring3->SetPolarRotationAngle(0);
  Ring3->Initialize();
  Ring3->ConstructDetector(World_Physical);
  
  //Ring 4
  Ring4->SetQuartzSizeX4(8.4*cm);
  Ring4->SetQuartzSizeY4(15*cm);  //without the 45 degree cut region
  Ring4->SetQuartzSizeZ4(1.5*cm);
  Ring4->SetLowerInterfacePlane4(5.6*cm);
  Ring4->SetMiddleBoxHeight4(9.0*cm);
  Ring4->SetUpperInterfacePlane4(25*cm);
  Ring4->SetLowerConeFrontFaceAngle4(28*degree);
  Ring4->SetLowerConeBackFaceAngle4(22*degree);
  Ring4->SetLowerConeSideFaceAngle4(0*degree);
  Ring4->SetQuartzInterfaceOpeningZ4(1.8*cm);
  Ring4->SetQuartzInterfaceOpeningX4(9.2*cm);
  Ring4->SetQuartzToPMTOffsetInZ4(-0.3*cm); 
  Ring4->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring4->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring4->SetPMTCathodeRadius(3.5*cm);
  Ring4->SetPMTCathodeThickness(0.1*cm);
  Ring4->SetAzimuthalRotationAngle(0);
  Ring4->SetPolarRotationAngle(0);
  Ring4->Initialize();
  Ring4->ConstructDetector(World_Physical);
  
  //Ring 5
  Ring5->SetQuartzSizeX5(8.4*cm);
  Ring5->SetQuartzSizeY5(15*cm);  //without the 45 degree cut region
  Ring5->SetQuartzSizeZ5(1.5*cm);
  Ring5->SetLowerInterfacePlane5(5.6*cm);
  Ring5->SetMiddleBoxHeight5(9.0*cm);
  Ring5->SetUpperInterfacePlane5(25*cm);
  Ring5->SetLowerConeFrontFaceAngle5(28*degree);
  Ring5->SetLowerConeBackFaceAngle5(22*degree);
  Ring5->SetLowerConeSideFaceAngle5(0*degree);
  Ring5->SetQuartzInterfaceOpeningZ5(1.8*cm);
  Ring5->SetQuartzInterfaceOpeningX5(9.2*cm);
  Ring5->SetQuartzToPMTOffsetInZ5(-0.3*cm);  
  Ring5->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring5->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring5->SetPMTCathodeRadius(3.5*cm);
  Ring5->SetPMTCathodeThickness(0.1*cm);
  Ring5->SetAzimuthalRotationAngle(0);
  Ring5->SetPolarRotationAngle(0);
  Ring5->Initialize();
  Ring5->ConstructDetector(World_Physical);
 
  //Ring 6 (R5 backflush 1)
  Ring6->SetQuartzSizeX6(8.4*cm);
  Ring6->SetQuartzSizeY6(15*cm);  //without the 45 degree cut region
  Ring6->SetQuartzSizeZ6(1.5*cm);
  Ring6->SetLowerInterfacePlane6(5.6*cm);
  Ring6->SetMiddleBoxHeight6(9.0*cm);
  Ring6->SetUpperInterfacePlane6(25*cm);
  Ring6->SetLowerConeFrontFaceAngle6(28*degree);
  Ring6->SetLowerConeBackFaceAngle6(22*degree);
  Ring6->SetLowerConeSideFaceAngle6(0*degree);
  Ring6->SetQuartzInterfaceOpeningZ6(1.8*cm);
  Ring6->SetQuartzInterfaceOpeningX6(9.2*cm);
  Ring6->SetQuartzToPMTOffsetInZ6(-0.3*cm);  
  Ring6->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring6->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring6->SetPMTCathodeRadius(3.5*cm);
  Ring6->SetPMTCathodeThickness(0.1*cm);
  Ring6->SetAzimuthalRotationAngle(0);
  Ring6->SetPolarRotationAngle(0);
  Ring6->Initialize();
  Ring6->ConstructDetector(World_Physical);
  
  //Ring 7 (R5 backflush 2)
  Ring7->SetQuartzSizeX7(8.4*cm);
  Ring7->SetQuartzSizeY7(15*cm);  //without the 45 degree cut region
  Ring7->SetQuartzSizeZ7(1.5*cm);
  Ring7->SetLowerInterfacePlane7(5.6*cm);
  Ring7->SetMiddleBoxHeight7(9.0*cm);
  Ring7->SetUpperInterfacePlane7(25*cm);
  Ring7->SetLowerConeFrontFaceAngle7(28*degree);
  Ring7->SetLowerConeBackFaceAngle7(22*degree);
  Ring7->SetLowerConeSideFaceAngle7(0*degree);
  Ring7->SetQuartzInterfaceOpeningZ7(1.8*cm);
  Ring7->SetQuartzInterfaceOpeningX7(9.2*cm);
  Ring7->SetQuartzToPMTOffsetInZ7(-0.3*cm);  
  Ring7->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring7->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring7->SetPMTCathodeRadius(3.5*cm);
  Ring7->SetPMTCathodeThickness(0.1*cm);
  Ring7->SetAzimuthalRotationAngle(0);
  Ring7->SetPolarRotationAngle(0);
  Ring7->Initialize();
  Ring7->ConstructDetector(World_Physical);
  
  //Ring 8 (R6)
  Ring8->SetQuartzSizeX8(8.4*cm);
  Ring8->SetQuartzSizeY8(15*cm);  //without the 45 degree cut region
  Ring8->SetQuartzSizeZ8(1.5*cm);
  Ring8->SetLowerInterfacePlane8(5.6*cm);
  Ring8->SetMiddleBoxHeight8(9.0*cm);
  Ring8->SetUpperInterfacePlane8(25*cm);
  Ring8->SetLowerConeFrontFaceAngle8(28*degree);
  Ring8->SetLowerConeBackFaceAngle8(22*degree);
  Ring8->SetLowerConeSideFaceAngle8(0*degree);
  Ring8->SetQuartzInterfaceOpeningZ8(1.8*cm);
  Ring8->SetQuartzInterfaceOpeningX8(9.2*cm);
  Ring8->SetQuartzToPMTOffsetInZ8(-0.3*cm);  
  Ring8->SetPMTInterfaceOpeningZ(5.6*cm);
  Ring8->SetPMTInterfaceOpeningX(5.6*cm);  
  Ring8->SetPMTCathodeRadius(3.5*cm);
  Ring8->SetPMTCathodeThickness(0.1*cm);
  Ring8->SetAzimuthalRotationAngle(0);
  Ring8->SetPolarRotationAngle(0);
  Ring8->Initialize();
  Ring8->ConstructDetector(World_Physical);

  //Scint1 
  Scint1->SetScint1SizeX(60.0*cm);
  Scint1->SetScint1SizeY(60.0*cm);
  Scint1->SetScint1SizeZ(0.01*cm);
  Scint1->SetAzimuthalRotationAngle(0);
  Scint1->SetPolarRotationAngle(0);
  Scint1->Initialize();
  Scint1->ConstructDetector(World_Physical);

  //Scint2
  Scint2->SetScint2SizeX(10.0*cm);
  Scint2->SetScint2SizeY(10.0*cm);
  Scint2->SetScint2SizeZ(0.01*cm);
  Scint2->SetAzimuthalRotationAngle(0);
  Scint2->SetPolarRotationAngle(0);
  Scint2->Initialize();
  Scint2->ConstructDetector(World_Physical);

  //Scint3
  Scint3->SetSizeX(10.0*cm);
  Scint3->SetSizeY(10.0*cm);
  Scint3->SetSizeZ(0.01*cm);
  Scint3->SetAzimuthalRotationAngle(0);
  Scint3->SetPolarRotationAngle(0);
  Scint3->Initialize();
  Scint3->ConstructDetector(World_Physical);

  //Scint4
  Scint4->SetSizeX(10.0*cm);
  Scint4->SetSizeY(10.0*cm);
  Scint4->SetSizeZ(0.01*cm);
  Scint4->SetAzimuthalRotationAngle(0);
  Scint4->SetPolarRotationAngle(0);
  Scint4->Initialize();
  Scint4->ConstructDetector(World_Physical);

  //AlPlate
  AlPlate->SetSizeX(80.0*cm);
  AlPlate->SetSizeY(80.0*cm);
  AlPlate->SetSizeZ(0.635*cm);
  AlPlate->SetAzimuthalRotationAngle(0);
  AlPlate->SetPolarRotationAngle(0);
  AlPlate->Initialize();
  AlPlate->ConstructDetector(World_Physical);
  
  //End of object parameter setting

  World_Logical->SetVisAttributes (G4VisAttributes::GetInvisible);
  
  DumpGeometricalTree(World_Physical);
  
  return World_Physical;
}

void MOLLEROptConstruction::GetQuartz1Limits(G4double *vals)
{
  Ring1->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz2Limits(G4double *vals)
{
  Ring2->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz3Limits(G4double *vals)
{
  Ring3->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz4Limits(G4double *vals)
{
  Ring4->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz5Limits(G4double *vals)
{
  Ring5->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz6Limits(G4double *vals)
{
  Ring6->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz7Limits(G4double *vals)
{
  Ring7->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz8Limits(G4double *vals)
{
  Ring8->GetQuartzLimits(vals);
}

void MOLLEROptConstruction::GetScint1Limits(G4double *vals)
{
  Scint1->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint2Limits(G4double *vals)
{
  Scint2->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint3Limits(G4double *vals)
{
  Scint3->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint4Limits(G4double *vals)
{
  Scint4->GetScintLimits(vals);
}

void MOLLEROptConstruction::GetLightGuide1Limits(G4double *vals)
{
  Ring1->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide2Limits(G4double *vals)
{
  Ring2->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide3Limits(G4double *vals)
{
  Ring3->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide4Limits(G4double *vals)
{
  Ring4->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide5Limits(G4double *vals)
{
  Ring5->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide6Limits(G4double *vals)
{
  Ring6->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide7Limits(G4double *vals)
{
  Ring7->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide8Limits(G4double *vals)
{
  Ring8->GetLightGuideLimits(vals);
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

