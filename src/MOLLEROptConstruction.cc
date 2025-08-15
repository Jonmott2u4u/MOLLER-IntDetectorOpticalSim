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
  MainDet        = NULL;

  fWorldLengthInX = 0.0; 
  fWorldLengthInY = 0.0;
  fWorldLengthInZ = 0.0;

  TrackingReadout = trReadout;

  MOLLERMessenger = new MOLLEROptMessenger(this);
}

MOLLEROptConstruction::~MOLLEROptConstruction()
{
  //BF segment objects
  if (MainDet)          delete MainDet;

  if (MOLLERMessenger)    delete MOLLERMessenger;             
}

G4VPhysicalVolume* MOLLEROptConstruction::Construct()
{
  MainDet = new MOLLEROptDetector(TrackingReadout,"MainDet",Materials,"UVS"); //"UVS" & "UVC" are the available options. Must be changed here in the single-det branch

  //Auxilary detectors (for now just scintillators) used to track particle positions

  //Insensitive objects (for now just an aluminum plate) that do not store hit info

  
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
  
  //----------------FF SEGMENT OBJECTS----------------//
  //Main Det 9currently R1 dimensions)
  MainDet->SetQuartzSizeX(16.9*cm);
  MainDet->SetQuartzSizeY(2.0*cm);  //without the 45 degree cut region
  MainDet->SetQuartzSizeZ(2.0*cm);
  MainDet->SetLowerInterfacePlane(7.5*cm);
  MainDet->SetMiddleBoxHeight(41.0*cm);
  MainDet->SetUpperInterfacePlane(25.1*cm);
  MainDet->SetLowerConeFrontFaceAngle(18*degree);
  MainDet->SetLowerConeBackFaceAngle(22*degree);
  MainDet->SetLowerConeSideFaceAngle(0*degree);
  MainDet->SetQuartzInterfaceOpeningZ(2.7*cm);
  MainDet->SetQuartzInterfaceOpeningX(17.7*cm);
  MainDet->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  MainDet->SetPMTInterfaceOpeningZ(7.0*cm);
  MainDet->SetPMTInterfaceOpeningX(7.0*cm);  
  MainDet->SetPMTCathodeRadius(3.5*cm);
  MainDet->SetPMTCathodeThickness(0.1*cm);
  MainDet->SetAzimuthalRotationAngle(0*degree);
  MainDet->SetPolarRotationAngle(3*degree);
  MainDet->SetYawRotationAngle(0*degree);
  MainDet->Initialize();
  MainDet->ConstructDetector(World_Physical);
  MainDet->SetCenterPositionInX(0*mm);           //Positions must be set after placing the detector in the world
  MainDet->SetCenterPositionInY(270.7*mm);
  MainDet->SetCenterPositionInZ(1923.94*mm);

  //-------Misc. objects-------//

  
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
  MainDet->GetQuartzLimits(vals);
}

void MOLLEROptConstruction::GetLightGuideLimits(G4double *vals)
{
  MainDet->GetLightGuideLimits(vals);
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

