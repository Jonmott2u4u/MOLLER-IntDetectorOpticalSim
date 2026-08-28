#include "MOLLEROptConstruction.hh"

MOLLEROptConstruction::MOLLEROptConstruction(MOLLEROptTrackingReadout *trReadout, MOLLEROptMaterial* mat) 
  : G4VUserDetectorConstruction()
{
  World_Solid    = NULL;  
  World_Logical  = NULL;  
  World_Physical = NULL;
  
  MOLLERMessenger = NULL;
  Materials       = mat;

  //Modules
  ShowerMax        = NULL;

  //Scintillators
  Scint1 = NULL;
  Scint2 = NULL;
  Scint3 = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  //BF segment objects
  if (ShowerMax)          delete ShowerMax;

  if (Scint1)             delete Scint1;
  if (Scint2)             delete Scint2;
  if (Scint3)             delete Scint3;

  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  ShowerMax = new MOLLEROptDetector(TrackingReadout,"ShowerMax",Materials,"UVS"); //"UVS" & "UVC" are the available options. Must be changed here in the single-det branch

  //Auxilary detectors (for now just scintillators) used to track particle positions
  Scint1 = new MOLLEROptAuxilary(TrackingReadout,"Scint1",Materials);
  Scint2 = new MOLLEROptAuxilary(TrackingReadout,"Scint2",Materials);
  Scint3 = new MOLLEROptAuxilary(TrackingReadout,"Scint3",Materials);

  fWorldLengthInX =  2.0*m;
  fWorldLengthInY =  2.0*m;
  fWorldLengthInZ =  2.0*m;
  
  World_Material = Materials->GetMaterial("Air");
  //World_Material = Materials->GetMaterial("Vacuum");
  
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
  
  //----------------ShowerMax Initial Settings----------------//
  ShowerMax->SetQuartzSizeX(265*mm);
  ShowerMax->SetQuartzSizeY(160*mm);  //without the 45 degree cut region
  ShowerMax->SetQuartzSizeZ(6*mm);
  ShowerMax->SetTungstenSizeX(265*mm);
  ShowerMax->SetTungstenSizeY(160*mm);  //without the 45 degree cut region
  ShowerMax->SetTungstenSizeZ(8*mm);
  ShowerMax->SetLowerInterfacePlane(67.462*mm);
  ShowerMax->SetMiddleBoxHeight(0.01*mm);
  ShowerMax->SetUpperInterfacePlane(250.52*mm);
  ShowerMax->SetLowerConeFrontFaceAngle(12.9*degree);
  ShowerMax->SetLowerConeBackFaceAngle(12.9*degree);
  ShowerMax->SetLowerConeSideFaceAngle(0*degree);
  ShowerMax->SetQuartzInterfaceOpeningZ(5.496*mm);
  ShowerMax->SetQuartzInterfaceOpeningX(266*mm);
  ShowerMax->SetQuartzToPMTOffsetInZ(0.0*mm);  
  ShowerMax->SetPMTInterfaceOpeningZ(7.0*cm);
  ShowerMax->SetPMTInterfaceOpeningX(7.0*cm);  
  ShowerMax->SetPMTCathodeRadius(3.5*cm);
  ShowerMax->SetPMTCathodeThickness(0.1*cm);
  ShowerMax->SetAzimuthalRotationAngle(0*degree);
  ShowerMax->SetPolarRotationAngle(0*degree);
  ShowerMax->SetYawRotationAngle(0*degree);
  ShowerMax->Initialize();
  ShowerMax->ConstructDetector(World_Physical);
  ShowerMax->SetCenterPositionInX(0*mm);           //Positions must be set after placing the detector in the world
  ShowerMax->SetCenterPositionInY(0*mm);
  ShowerMax->SetCenterPositionInZ(0*mm);

  //-------Scintillator Initial Settings-------//
  Scint1->SetSizeX(30.5*cm);
  Scint1->SetSizeY(30.5*cm);
  Scint1->SetSizeZ(2.54*cm);
  Scint1->SetAzimuthalRotationAngle(0);
  Scint1->SetPolarRotationAngle(0);
  Scint1->Initialize();
  Scint1->ConstructAuxilary(World_Physical);
  Scint1->SetCenterPositionInX(0*mm);
  Scint1->SetCenterPositionInY(0.8*mm);
  Scint1->SetCenterPositionInZ(-919*mm);

  Scint2->SetSizeX(20*cm);
  Scint2->SetSizeY(7*cm);
  Scint2->SetSizeZ(0.7*cm);
  Scint2->SetAzimuthalRotationAngle(0);
  Scint2->SetPolarRotationAngle(0);
  Scint2->Initialize();
  Scint2->ConstructAuxilary(World_Physical);
  Scint2->SetCenterPositionInX(0*mm);
  Scint2->SetCenterPositionInY(-116.7*mm);
  Scint2->SetCenterPositionInZ(-40*mm);

  Scint3->SetSizeX(30.5*cm);
  Scint3->SetSizeY(30.5*cm);
  Scint3->SetSizeZ(2.54*cm);
  Scint3->SetAzimuthalRotationAngle(0);
  Scint3->SetPolarRotationAngle(0);
  Scint3->Initialize();
  Scint3->ConstructAuxilary(World_Physical);
  Scint3->SetCenterPositionInX(0*mm);
  Scint3->SetCenterPositionInY(15.8*mm);
  Scint3->SetCenterPositionInZ(794*mm);

  
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

void MOLLEROptConstruction::GetQuartzLimits(G4double *vals)
{
  ShowerMax->GetQuartzLimits(vals);
}

void MOLLEROptConstruction::GetLightGuideLimits(G4double *vals)
{
  ShowerMax->GetLightGuideLimits(vals);
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

