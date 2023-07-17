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
  Detector2	  = NULL;
  Detector3       = NULL;
  Detector4       = NULL;
  Detector5       = NULL;
  Detector6       = NULL;
  Detector7       = NULL;
  Detector8       = NULL;
  LightGuide      = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  if (Detector)           delete Detector;
  if (Detector2)	  delete Detector2;
  if (Detector3)	  delete Detector3;
  if (Detector4)	  delete Detector4;
  if (Detector5)	  delete Detector5;
  if (Detector6)	  delete Detector6;
  if (Detector7)	  delete Detector7;
  if (Detector8)	  delete Detector8;
  //if (Material)         delete Material;
  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  Detector    = new MOLLEROptDetector(TrackingReadout,"Ring1",Materials);
  //DetMessenger = new MOLLEROptDetectorMessenger(Detector);
  Detector2   = new MOLLEROptDetector2(TrackingReadout,"Ring2",Materials); 
  Detector3   = new MOLLEROptDetector3(TrackingReadout,"Ring3",Materials);
  Detector4   = new MOLLEROptDetector4(TrackingReadout,"Ring4",Materials);
  Detector5   = new MOLLEROptDetector5(TrackingReadout,"Ring5a",Materials);
  Detector6   = new MOLLEROptDetector6(TrackingReadout,"Ring5b",Materials);
  Detector7   = new MOLLEROptDetector7(TrackingReadout,"Ring5c",Materials);
  Detector8   = new MOLLEROptDetector8(TrackingReadout,"Ring6",Materials);
  fWorldLengthInX =  25.0*m;
  fWorldLengthInY =  25.0*m;
  fWorldLengthInZ =  40.0*m;
  
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

  Detector->SetQuartzSizeX(8.4*cm);
  Detector->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector->SetQuartzSizeZ(1.5*cm);
  Detector->SetLowerInterfacePlane(5.6*cm);
  Detector->SetUpperInterfacePlane(25*cm);
  Detector->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector->SetLowerConeBackFaceAngle(22*degree);
  Detector->SetLowerConeSideFaceAngle(0*degree);
  Detector->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector->SetPMTInterfaceOpeningX(5.6*cm);  
  Detector->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector->SetPMTCathodeRadius(3.5*cm);
  Detector->SetPMTCathodeThickness(0.1*cm);
  Detector->SetAzimuthalRotationAngle(0);
  Detector->SetPolarRotationAngle(0);
  Detector->Initialize();
  Detector->ConstructDetector(World_Physical);
  Detector->SetCenterPositionInY(12*cm);

  //Detector2
  Detector2->SetQuartzSizeX(8.4*cm);
  Detector2->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector2->SetQuartzSizeZ(1.5*cm);
  Detector2->SetLowerInterfacePlane(5.6*cm);
  Detector2->SetUpperInterfacePlane(25*cm);
  Detector2->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector2->SetLowerConeBackFaceAngle(22*degree);
  Detector2->SetLowerConeSideFaceAngle(0*degree);
  Detector2->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector2->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector2->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector2->SetPMTInterfaceOpeningX(5.6*cm);
  Detector2->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector2->SetPMTCathodeRadius(3.5*cm);
  Detector2->SetPMTCathodeThickness(0.1*cm);
  Detector2->SetAzimuthalRotationAngle(0);
  Detector2->SetPolarRotationAngle(0);
  Detector2->Initialize();
  Detector2->ConstructDetector(World_Physical);
  Detector2->SetCenterPositionInY(12*cm);

  //Detector3
  Detector3->SetQuartzSizeX(8.4*cm);
  Detector3->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector3->SetQuartzSizeZ(1.5*cm);
  Detector3->SetLowerInterfacePlane(5.6*cm);
  Detector3->SetUpperInterfacePlane(25*cm);
  Detector3->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector3->SetLowerConeBackFaceAngle(22*degree);
  Detector3->SetLowerConeSideFaceAngle(0*degree);
  Detector3->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector3->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector3->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector3->SetPMTInterfaceOpeningX(5.6*cm);
  Detector3->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector3->SetPMTCathodeRadius(3.5*cm);
  Detector3->SetPMTCathodeThickness(0.1*cm);
  Detector3->SetAzimuthalRotationAngle(0);
  Detector3->SetPolarRotationAngle(0);
  Detector3->Initialize();
  Detector3->ConstructDetector(World_Physical);
  Detector3->SetCenterPositionInY(12*cm);

  //Detector4
  Detector4->SetQuartzSizeX(8.4*cm);
  Detector4->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector4->SetQuartzSizeZ(1.5*cm);
  Detector4->SetLowerInterfacePlane(5.6*cm);
  Detector4->SetUpperInterfacePlane(25*cm);
  Detector4->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector4->SetLowerConeBackFaceAngle(22*degree);
  Detector4->SetLowerConeSideFaceAngle(0*degree);
  Detector4->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector4->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector4->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector4->SetPMTInterfaceOpeningX(5.6*cm);
  Detector4->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector4->SetPMTCathodeRadius(3.5*cm);
  Detector4->SetPMTCathodeThickness(0.1*cm);
  Detector4->SetAzimuthalRotationAngle(0);
  Detector4->SetPolarRotationAngle(0);
  Detector4->Initialize();
  Detector4->ConstructDetector(World_Physical);
  Detector4->SetCenterPositionInY(12*cm);

  //Detector5
  Detector5->SetQuartzSizeX(8.4*cm);
  Detector5->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector5->SetQuartzSizeZ(1.5*cm);
  Detector5->SetLowerInterfacePlane(5.6*cm);
  Detector5->SetUpperInterfacePlane(25*cm);
  Detector5->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector5->SetLowerConeBackFaceAngle(22*degree);
  Detector5->SetLowerConeSideFaceAngle(0*degree);
  Detector5->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector5->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector5->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector5->SetPMTInterfaceOpeningX(5.6*cm);
  Detector5->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector5->SetPMTCathodeRadius(3.5*cm);
  Detector5->SetPMTCathodeThickness(0.1*cm);
  Detector5->SetAzimuthalRotationAngle(0);
  Detector5->SetPolarRotationAngle(0);
  Detector5->Initialize();
  Detector5->ConstructDetector(World_Physical);
  Detector5->SetCenterPositionInY(12*cm);

  //Detector6
  Detector6->SetQuartzSizeX(8.4*cm);
  Detector6->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector6->SetQuartzSizeZ(1.5*cm);
  Detector6->SetLowerInterfacePlane(5.6*cm);
  Detector6->SetUpperInterfacePlane(25*cm);
  Detector6->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector6->SetLowerConeBackFaceAngle(22*degree);
  Detector6->SetLowerConeSideFaceAngle(0*degree);
  Detector6->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector6->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector6->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector6->SetPMTInterfaceOpeningX(5.6*cm);
  Detector6->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector6->SetPMTCathodeRadius(3.5*cm);
  Detector6->SetPMTCathodeThickness(0.1*cm);
  Detector6->SetAzimuthalRotationAngle(0);
  Detector6->SetPolarRotationAngle(0);
  Detector6->Initialize();
  Detector6->ConstructDetector(World_Physical);
  Detector6->SetCenterPositionInY(12*cm);

  //Detector7
  Detector7->SetQuartzSizeX(8.4*cm);
  Detector7->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector7->SetQuartzSizeZ(1.5*cm);
  Detector7->SetLowerInterfacePlane(5.6*cm);
  Detector7->SetUpperInterfacePlane(25*cm);
  Detector7->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector7->SetLowerConeBackFaceAngle(22*degree);
  Detector7->SetLowerConeSideFaceAngle(0*degree);
  Detector7->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector7->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector7->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector7->SetPMTInterfaceOpeningX(5.6*cm);
  Detector7->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector7->SetPMTCathodeRadius(3.5*cm);
  Detector7->SetPMTCathodeThickness(0.1*cm);
  Detector7->SetAzimuthalRotationAngle(0);
  Detector7->SetPolarRotationAngle(0);
  Detector7->Initialize();
  Detector7->ConstructDetector(World_Physical);
  Detector7->SetCenterPositionInY(12*cm);

  //Detector8 
  Detector8->SetQuartzSizeX(8.4*cm);
  Detector8->SetQuartzSizeY(15*cm);  //without the 45 degree cut region
  Detector8->SetQuartzSizeZ(1.5*cm);
  Detector8->SetLowerInterfacePlane(5.6*cm);
  Detector8->SetUpperInterfacePlane(25*cm);
  Detector8->SetLowerConeFrontFaceAngle(28*degree); //degrees
  Detector8->SetLowerConeBackFaceAngle(22*degree);
  Detector8->SetLowerConeSideFaceAngle(0*degree);
  Detector8->SetQuartzInterfaceOpeningZ(1.8*cm);
  Detector8->SetQuartzInterfaceOpeningX(9.2*cm);
  Detector8->SetPMTInterfaceOpeningZ(5.6*cm);
  Detector8->SetPMTInterfaceOpeningX(5.6*cm);
  Detector8->SetQuartzToPMTOffsetInZ(-0.3*cm);
  Detector8->SetPMTCathodeRadius(3.5*cm);
  Detector8->SetPMTCathodeThickness(0.1*cm);
  Detector8->SetAzimuthalRotationAngle(0);
  Detector8->SetPolarRotationAngle(0);
  Detector8->Initialize();
  Detector8->ConstructDetector(World_Physical);
  Detector8->SetCenterPositionInY(12*cm);
 
  World_Logical->SetVisAttributes (G4VisAttributes::Invisible);
  DumpGeometricalTree(World_Physical);
  
  return World_Physical;
}

void MOLLEROptConstruction::GetQuartzLimits(G4double *vals)
{
  Detector->GetQuartzLimits(vals);
  Detector2->GetQuartzLimits(vals);
  Detector3->GetQuartzLimits(vals);
  Detector4->GetQuartzLimits(vals);
  Detector5->GetQuartzLimits(vals);
  Detector6->GetQuartzLimits(vals);
  Detector7->GetQuartzLimits(vals);
  Detector8->GetQuartzLimits(vals);
}

void MOLLEROptConstruction::GetLightGuideLimits(G4double *vals)
{
  Detector->GetLightGuideLimits(vals);
  Detector2->GetLightGuideLimits(vals);
  Detector3->GetLightGuideLimits(vals);
  Detector4->GetLightGuideLimits(vals);
  Detector5->GetLightGuideLimits(vals);
  Detector6->GetLightGuideLimits(vals);
  Detector7->GetLightGuideLimits(vals);
  Detector8->GetLightGuideLimits(vals);
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

