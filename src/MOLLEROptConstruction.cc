#include "MOLLEROptConstruction.hh"

MOLLEROptConstruction::MOLLEROptConstruction(MOLLEROptTrackingReadout *trReadout, MOLLEROptMaterial* mat) 
  : G4VUserDetectorConstruction()
{
  World_Solid    = NULL;  
  World_Logical  = NULL;  
  World_Physical = NULL;
  
  MOLLERMessenger = NULL;
  Materials       = mat;

  //BF modules
  Ring1        = NULL;
  Ring2        = NULL;
  Ring3        = NULL;
  Ring4        = NULL;
  Ring5        = NULL; //ff
  Ring6        = NULL; //bf1
  Ring7        = NULL; //bf2
  Ring8        = NULL;

  //BF scints
  Scint1        = NULL;
  Scint2        = NULL;

  AlPlate        = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  //BF segment objects
  if (Ring1)          delete Ring1;
  if (Ring2)          delete Ring2;
  if (Ring3)          delete Ring3;
  if (Ring4)          delete Ring4;
  if (Ring5)          delete Ring5;
  if (Ring6)          delete Ring6;
  if (Ring7)          delete Ring7;
  if (Ring8)          delete Ring8;

  if (Scint1)         delete Scint1;
  if (Scint2)         delete Scint2;

  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  Ring1 = new MOLLEROptDetector(TrackingReadout,"Ring1",Materials,"UVC");
  Ring2 = new MOLLEROptDetector(TrackingReadout,"Ring2",Materials,"UVC");
  Ring3 = new MOLLEROptDetector(TrackingReadout,"Ring3",Materials,"UVC");
  Ring4 = new MOLLEROptDetector(TrackingReadout,"Ring4",Materials,"UVC");
  Ring5 = new MOLLEROptDetector(TrackingReadout,"Ring5",Materials,"UVS");
  Ring6 = new MOLLEROptDetector(TrackingReadout,"Ring6",Materials,"UVS");
  Ring7 = new MOLLEROptDetector(TrackingReadout,"Ring7",Materials,"UVS");
  Ring8 = new MOLLEROptDetector(TrackingReadout,"Ring8",Materials,"UVC");

  //Auxilary detectors (for now just scintillators) used to track particle positions
  Scint1 = new MOLLEROptAuxilary(TrackingReadout,"Scint1",Materials);
  Scint2 = new MOLLEROptAuxilary(TrackingReadout,"Scint2",Materials);

  //Insensitive objects (for now just an aluminum plate) that do not store hit info
  
  fWorldLengthInX =  15.0*m;
  fWorldLengthInY =  15.0*m;
  fWorldLengthInZ =  30.0*m;
  
  World_Material = Materials->GetMaterial("Air");
  
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
  
  //----------------FF SEGMENT OBJECTS----------------//
  //Ring 1
  Ring1->SetQuartzSizeX(16.9*cm);
  Ring1->SetQuartzSizeY(3.0*cm);  //without the 45 degree cut region
  Ring1->SetQuartzSizeZ(2.0*cm);
  Ring1->SetLowerInterfacePlane(7.5*cm);
  Ring1->SetMiddleBoxHeight(40.0*cm);
  Ring1->SetUpperInterfacePlane(25.1*cm);
  Ring1->SetLowerConeFrontFaceAngle(18*degree);
  Ring1->SetLowerConeBackFaceAngle(22*degree);
  Ring1->SetLowerConeSideFaceAngle(0*degree);
  Ring1->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring1->SetQuartzInterfaceOpeningX(17.7*cm);
  Ring1->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring1->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring1->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring1->SetPMTCathodeRadius(3.5*cm);
  Ring1->SetPMTCathodeThickness(0.1*cm);
  Ring1->SetAzimuthalRotationAngle(0*degree);
  Ring1->SetPolarRotationAngle(6*degree);
  Ring1->Initialize();
  Ring1->ConstructDetector(World_Physical);
  Ring1->SetCenterPositionInX(0*mm);           //Positions must be set after placing the detector in the world
  Ring1->SetCenterPositionInY(263*mm);
  Ring1->SetCenterPositionInZ(1923.94*mm);

  //Ring 2
  Ring2->SetQuartzSizeX(17.9*cm);
  Ring2->SetQuartzSizeY(6.0*cm);  //without the 45 degree cut region
  Ring2->SetQuartzSizeZ(2.0*cm);
  Ring2->SetLowerInterfacePlane(7.5*cm);
  Ring2->SetMiddleBoxHeight(40.0*cm);
  Ring2->SetUpperInterfacePlane(20.5*cm);
  Ring2->SetLowerConeFrontFaceAngle(18*degree);
  Ring2->SetLowerConeBackFaceAngle(22*degree);
  Ring2->SetLowerConeSideFaceAngle(0*degree);
  Ring2->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring2->SetQuartzInterfaceOpeningX(18.7*cm);
  Ring2->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring2->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring2->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring2->SetPMTCathodeRadius(3.5*cm);
  Ring2->SetPMTCathodeThickness(0.1*cm);
  Ring2->SetAzimuthalRotationAngle(0*degree);
  Ring2->SetPolarRotationAngle(6*degree);
  Ring2->Initialize();
  Ring2->ConstructDetector(World_Physical);
  Ring2->SetCenterPositionInX(0*mm);
  Ring2->SetCenterPositionInY(285.0*mm);
  Ring2->SetCenterPositionInZ(1645.6*mm);

  //Ring 3
  Ring3->SetQuartzSizeX(19.0*cm);
  Ring3->SetQuartzSizeY(6.0*cm);  //without the 45 degree cut region
  Ring3->SetQuartzSizeZ(2.0*cm);
  Ring3->SetLowerInterfacePlane(7.5*cm);
  Ring3->SetMiddleBoxHeight(30.0*cm);
  Ring3->SetUpperInterfacePlane(20.5*cm);
  Ring3->SetLowerConeFrontFaceAngle(18*degree);
  Ring3->SetLowerConeBackFaceAngle(22*degree);
  Ring3->SetLowerConeSideFaceAngle(0*degree);
  Ring3->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring3->SetQuartzInterfaceOpeningX(19.8*cm);
  Ring3->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring3->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring3->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring3->SetPMTCathodeRadius(3.5*cm);
  Ring3->SetPMTCathodeThickness(0.1*cm);
  Ring3->SetAzimuthalRotationAngle(0*degree);
  Ring3->SetPolarRotationAngle(6*degree);
  Ring3->Initialize();
  Ring3->ConstructDetector(World_Physical);
  Ring3->SetCenterPositionInX(0*mm);
  Ring3->SetCenterPositionInY(322.1*mm);
  Ring3->SetCenterPositionInZ(1371.51*mm);
  
  //Ring 4
  Ring4->SetQuartzSizeX(21.3*cm);
  Ring4->SetQuartzSizeY(12*cm);  //without the 45 degree cut region
  Ring4->SetQuartzSizeZ(2*cm);
  Ring4->SetLowerInterfacePlane(7.5*cm);
  Ring4->SetMiddleBoxHeight(20*cm);
  Ring4->SetUpperInterfacePlane(25.3*cm);
  Ring4->SetLowerConeFrontFaceAngle(17*degree);
  Ring4->SetLowerConeBackFaceAngle(22*degree);
  Ring4->SetLowerConeSideFaceAngle(0*degree);
  Ring4->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring4->SetQuartzInterfaceOpeningX(22.1*cm);
  Ring4->SetQuartzToPMTOffsetInZ(0.3*cm); 
  Ring4->SetPMTInterfaceOpeningZ(7*cm);
  Ring4->SetPMTInterfaceOpeningX(7*cm);  
  Ring4->SetPMTCathodeRadius(3.5*cm);
  Ring4->SetPMTCathodeThickness(0.1*cm);
  Ring4->SetAzimuthalRotationAngle(0*degree);
  Ring4->SetPolarRotationAngle(6*degree);
  Ring4->Initialize();
  Ring4->ConstructDetector(World_Physical);
  Ring4->SetCenterPositionInX(0*mm);
  Ring4->SetCenterPositionInY(359.3*mm);
  Ring4->SetCenterPositionInZ(1092.08*mm);
  
  //Ring 5 ff
  Ring5->SetQuartzSizeX(8.0*cm);
  Ring5->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring5->SetQuartzSizeZ(1.7*cm);
  Ring5->SetLowerInterfacePlane(9*cm);
  Ring5->SetMiddleBoxHeight(0.001*mm);
  Ring5->SetUpperInterfacePlane(32.95*cm);
  Ring5->SetLowerConeFrontFaceAngle(18*degree);
  Ring5->SetLowerConeBackFaceAngle(19*degree);
  Ring5->SetLowerConeSideFaceAngle(0*degree);
  Ring5->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring5->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring5->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring5->SetPMTInterfaceOpeningZ(7*cm);
  Ring5->SetPMTInterfaceOpeningX(7*cm);  
  Ring5->SetPMTCathodeRadius(3.5*cm);
  Ring5->SetPMTCathodeThickness(0.1*cm);
  Ring5->SetAzimuthalRotationAngle(0*degree);
  Ring5->SetPolarRotationAngle(6*degree);
  Ring5->Initialize();
  Ring5->ConstructDetector(World_Physical);
  Ring5->SetCenterPositionInX(0*mm);
  Ring5->SetCenterPositionInY(427.7*mm);
  Ring5->SetCenterPositionInZ(651.64*mm);
 
  //Ring 6 (R5 backflush 1)
  Ring6->SetQuartzSizeX(8.0*cm);
  Ring6->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring6->SetQuartzSizeZ(1.7*cm);
  Ring6->SetLowerInterfacePlane(9*cm);
  Ring6->SetMiddleBoxHeight(0.001*mm);
  Ring6->SetUpperInterfacePlane(32.95*cm);
  Ring6->SetLowerConeFrontFaceAngle(18*degree);
  Ring6->SetLowerConeBackFaceAngle(19*degree);
  Ring6->SetLowerConeSideFaceAngle(0*degree);
  Ring6->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring6->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring6->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring6->SetPMTInterfaceOpeningZ(7*cm);
  Ring6->SetPMTInterfaceOpeningX(7*cm);  
  Ring6->SetPMTCathodeRadius(3.5*cm);
  Ring6->SetPMTCathodeThickness(0.1*cm);
  Ring6->SetAzimuthalRotationAngle(0*degree);
  Ring6->SetPolarRotationAngle(6*degree);
  Ring6->Initialize();
  Ring6->ConstructDetector(World_Physical);
  Ring6->SetCenterPositionInX(-86.7*mm);
  Ring6->SetCenterPositionInY(427.7*mm);
  Ring6->SetCenterPositionInZ(802.47*mm);
  
  //Ring 7 (R5 backflush 2)
  Ring7->SetQuartzSizeX(8.0*cm);
  Ring7->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring7->SetQuartzSizeZ(1.7*cm);
  Ring7->SetLowerInterfacePlane(9*cm);
  Ring7->SetMiddleBoxHeight(0.001*mm);
  Ring7->SetUpperInterfacePlane(32.95*cm);
  Ring7->SetLowerConeFrontFaceAngle(18*degree);
  Ring7->SetLowerConeBackFaceAngle(19*degree);
  Ring7->SetLowerConeSideFaceAngle(0*degree);
  Ring7->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring7->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring7->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring7->SetPMTInterfaceOpeningZ(7*cm);
  Ring7->SetPMTInterfaceOpeningX(7*cm);  
  Ring7->SetPMTCathodeRadius(3.5*cm);
  Ring7->SetPMTCathodeThickness(0.1*cm);
  Ring7->SetAzimuthalRotationAngle(0*degree);
  Ring7->SetPolarRotationAngle(6*degree);
  Ring7->Initialize();
  Ring7->ConstructDetector(World_Physical);
  Ring7->SetCenterPositionInX(86.7*mm);
  Ring7->SetCenterPositionInY(427.7*mm);
  Ring7->SetCenterPositionInZ(802.47*mm);
  
  //Ring 8 (R6)
  Ring8->SetQuartzSizeX(26*cm);
  Ring8->SetQuartzSizeY(10*cm);  //without the 45 degree cut region
  Ring8->SetQuartzSizeZ(2*cm);
  Ring8->SetLowerInterfacePlane(8.3*cm);
  Ring8->SetMiddleBoxHeight(9.0*cm);
  Ring8->SetUpperInterfacePlane(16.3*cm);
  Ring8->SetLowerConeFrontFaceAngle(17*degree);
  Ring8->SetLowerConeBackFaceAngle(20*degree);
  Ring8->SetLowerConeSideFaceAngle(0*degree);
  Ring8->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring8->SetQuartzInterfaceOpeningX(26.8*cm);
  Ring8->SetQuartzToPMTOffsetInZ(0*cm);  
  Ring8->SetPMTInterfaceOpeningZ(7*cm);
  Ring8->SetPMTInterfaceOpeningX(7*cm);  
  Ring8->SetPMTCathodeRadius(3.5*cm);
  Ring8->SetPMTCathodeThickness(0.1*cm);
  Ring8->SetAzimuthalRotationAngle(0*degree);
  Ring8->SetPolarRotationAngle(6*degree);
  Ring8->Initialize();
  Ring8->ConstructDetector(World_Physical);
  Ring8->SetCenterPositionInX(0*mm);
  Ring8->SetCenterPositionInY(509.3*mm);
  Ring8->SetCenterPositionInZ(501.78*mm);

  //Scint1 
  Scint1->SetSizeX(30*cm);
  Scint1->SetSizeY(30*cm);
  Scint1->SetSizeZ(2*cm);
  Scint1->SetAzimuthalRotationAngle(0);
  Scint1->SetPolarRotationAngle(0);
  Scint1->Initialize();
  Scint1->ConstructAuxilary(World_Physical);
  Scint1->SetCenterPositionInX(0*mm);
  Scint1->SetCenterPositionInY(8*mm);
  Scint1->SetCenterPositionInZ(97*mm);

  //Scint2
  Scint2->SetSizeX(30*cm);
  Scint2->SetSizeY(30*cm);
  Scint2->SetSizeZ(2*cm);
  Scint2->SetAzimuthalRotationAngle(0);
  Scint2->SetPolarRotationAngle(0);
  Scint2->Initialize();
  Scint2->ConstructAuxilary(World_Physical);
  Scint2->SetCenterPositionInX(0*mm);
  Scint2->SetCenterPositionInY(120*mm);
  Scint2->SetCenterPositionInZ(2247*mm);

  //End of object parameter setting

  G4Colour  grey      ( 127/255., 127/255., 127/255.);
  G4VisAttributes *att = new G4VisAttributes(grey);
  att->SetVisibility(false);
  att->SetForceWireframe(true);
  World_Logical->SetVisAttributes(att);
  //World_Logical->SetVisAttributes (G4VisAttributes::GetInvisible);
  
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

