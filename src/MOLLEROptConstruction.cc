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
  //FF modules
  Ring9        = NULL;
  Ring10        = NULL;
  Ring11        = NULL;
  Ring12        = NULL;
  Ring13        = NULL;
  Ring14        = NULL;
  Ring15        = NULL;
  Ring16        = NULL;

  //BF scints
  Scint1        = NULL;
  Scint2        = NULL;
  Scint3        = NULL;
  Scint4        = NULL;
  //FF scints
  Scint5        = NULL;
  Scint6        = NULL;
  Scint7        = NULL;
  Scint8        = NULL;

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
  if (Scint3)         delete Scint3;
  if (Scint4)         delete Scint4;

  //FF segment objects
  if (Ring9)          delete Ring9;
  if (Ring10)         delete Ring10;
  if (Ring11)         delete Ring11;
  if (Ring12)         delete Ring12;
  if (Ring13)         delete Ring13;
  if (Ring14)         delete Ring14;
  if (Ring15)         delete Ring15;
  if (Ring16)         delete Ring16;

  if (Scint5)         delete Scint5;
  if (Scint6)         delete Scint6;
  if (Scint7)         delete Scint7;
  if (Scint8)         delete Scint8;

  //Misc. objects
  if (AlPlate)        delete AlPlate;

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

  Ring9 = new MOLLEROptDetector(TrackingReadout,"Ring9",Materials,"UVC");
  Ring10 = new MOLLEROptDetector(TrackingReadout,"Ring10",Materials,"UVC");
  Ring11 = new MOLLEROptDetector(TrackingReadout,"Ring11",Materials,"UVC");
  Ring12 = new MOLLEROptDetector(TrackingReadout,"Ring12",Materials,"UVC");
  Ring13 = new MOLLEROptDetector(TrackingReadout,"Ring13",Materials,"UVS");
  Ring14 = new MOLLEROptDetector(TrackingReadout,"Ring14",Materials,"UVS");
  Ring15 = new MOLLEROptDetector(TrackingReadout,"Ring15",Materials,"UVS");
  Ring16 = new MOLLEROptDetector(TrackingReadout,"Ring16",Materials,"UVC");

  //Auxilary detectors (for now just scintillators) used to track particle positions
  Scint1 = new MOLLEROptAuxilary(TrackingReadout,"Scint1",Materials);
  Scint2 = new MOLLEROptAuxilary(TrackingReadout,"Scint2",Materials);
  Scint3 = new MOLLEROptAuxilary(TrackingReadout,"Scint3",Materials);
  Scint4 = new MOLLEROptAuxilary(TrackingReadout,"Scint4",Materials);

  Scint5 = new MOLLEROptAuxilary(TrackingReadout,"Scint5",Materials);
  Scint6 = new MOLLEROptAuxilary(TrackingReadout,"Scint6",Materials);
  Scint7 = new MOLLEROptAuxilary(TrackingReadout,"Scint7",Materials);
  Scint8 = new MOLLEROptAuxilary(TrackingReadout,"Scint8",Materials);

  //Insensitive objects (for now just an aluminum plate) that do not store hit info
  AlPlate = new MOLLEROptInsensitive("AlPlate",Materials);
  
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
  Ring1->SetQuartzSizeY(2.0*cm);  //without the 45 degree cut region
  Ring1->SetQuartzSizeZ(2.0*cm);
  Ring1->SetLowerInterfacePlane(7.5*cm);
  Ring1->SetMiddleBoxHeight(41.0*cm);
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
  Ring1->SetCenterPositionInX(-250*mm);           //Positions must be set after placing the detector in the world
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
  Ring2->SetCenterPositionInX(-250*mm);
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
  Ring3->SetCenterPositionInX(-250*mm);
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
  Ring4->SetCenterPositionInX(-250*mm);
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
  Ring5->SetCenterPositionInX(-250*mm);
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
  Ring6->SetCenterPositionInX(-336.7*mm);
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
  Ring7->SetCenterPositionInX(-163.3*mm);
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
  Ring8->SetCenterPositionInX(-250*mm);
  Ring8->SetCenterPositionInY(509.3*mm);
  Ring8->SetCenterPositionInZ(501.78*mm);

  //Scint1 
  Scint1->SetSizeX(30*cm);
  Scint1->SetSizeY(25*cm);
  Scint1->SetSizeZ(2*cm);
  Scint1->SetAzimuthalRotationAngle(0);
  Scint1->SetPolarRotationAngle(0);
  Scint1->Initialize();
  Scint1->ConstructAuxilary(World_Physical);
  Scint1->SetCenterPositionInX(-250*mm);
  Scint1->SetCenterPositionInY(0*mm);
  Scint1->SetCenterPositionInZ(70*mm);

  //Scint2
  Scint2->SetSizeX(30*cm);
  Scint2->SetSizeY(25*cm);
  Scint2->SetSizeZ(2*cm);
  Scint2->SetAzimuthalRotationAngle(0);
  Scint2->SetPolarRotationAngle(0);
  Scint2->Initialize();
  Scint2->ConstructAuxilary(World_Physical);
  Scint2->SetCenterPositionInX(-250*mm);
  Scint2->SetCenterPositionInY(250*mm);
  Scint2->SetCenterPositionInZ(70*mm);

  //Scint3
  Scint3->SetSizeX(30*cm);
  Scint3->SetSizeY(25*cm);
  Scint3->SetSizeZ(2*cm);
  Scint3->SetAzimuthalRotationAngle(0);
  Scint3->SetPolarRotationAngle(0);
  Scint3->Initialize();
  Scint3->ConstructAuxilary(World_Physical);
  Scint3->SetCenterPositionInX(-250*mm);
  Scint3->SetCenterPositionInY(0*mm);
  Scint3->SetCenterPositionInZ(2060*mm);

  //Scint4
  Scint4->SetSizeX(30*cm);
  Scint4->SetSizeY(25*cm);
  Scint4->SetSizeZ(2*cm);
  Scint4->SetAzimuthalRotationAngle(0);
  Scint4->SetPolarRotationAngle(0);
  Scint4->Initialize();
  Scint4->ConstructAuxilary(World_Physical);
  Scint4->SetCenterPositionInX(-250*mm);
  Scint4->SetCenterPositionInY(250*mm);
  Scint4->SetCenterPositionInZ(2060*mm);

  //----------------BF SEGMENT OBJECTS----------------//
  //Ring 9 (R1)
  Ring9->SetQuartzSizeX(16.9*cm);
  Ring9->SetQuartzSizeY(2.0*cm);  //without the 45 degree cut region
  Ring9->SetQuartzSizeZ(2.0*cm);
  Ring9->SetLowerInterfacePlane(7.5*cm);
  Ring9->SetMiddleBoxHeight(41.0*cm);
  Ring9->SetUpperInterfacePlane(25.1*cm);
  Ring9->SetLowerConeFrontFaceAngle(18*degree);
  Ring9->SetLowerConeBackFaceAngle(22*degree);
  Ring9->SetLowerConeSideFaceAngle(0*degree);
  Ring9->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring9->SetQuartzInterfaceOpeningX(17.7*cm);
  Ring9->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring9->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring9->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring9->SetPMTCathodeRadius(3.5*cm);
  Ring9->SetPMTCathodeThickness(0.1*cm);
  Ring9->SetAzimuthalRotationAngle(0*degree);
  Ring9->SetPolarRotationAngle(6*degree);
  Ring9->Initialize();
  Ring9->ConstructDetector(World_Physical);
  Ring9->SetCenterPositionInX(250*mm);           //Positions must be set after placing the detector in the world
  Ring9->SetCenterPositionInY(263*mm);
  Ring9->SetCenterPositionInZ(1773.11*mm);

  //Ring 10 (R2)
  Ring10->SetQuartzSizeX(17.9*cm);
  Ring10->SetQuartzSizeY(6.0*cm);  //without the 45 degree cut region
  Ring10->SetQuartzSizeZ(2.0*cm);
  Ring10->SetLowerInterfacePlane(7.5*cm);
  Ring10->SetMiddleBoxHeight(40.0*cm);
  Ring10->SetUpperInterfacePlane(20.5*cm);
  Ring10->SetLowerConeFrontFaceAngle(18*degree);
  Ring10->SetLowerConeBackFaceAngle(22*degree);
  Ring10->SetLowerConeSideFaceAngle(0*degree);
  Ring10->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring10->SetQuartzInterfaceOpeningX(18.7*cm);
  Ring10->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring10->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring10->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring10->SetPMTCathodeRadius(3.5*cm);
  Ring10->SetPMTCathodeThickness(0.1*cm);
  Ring10->SetAzimuthalRotationAngle(0*degree);
  Ring10->SetPolarRotationAngle(6*degree);
  Ring10->Initialize();
  Ring10->ConstructDetector(World_Physical);
  Ring10->SetCenterPositionInX(250*mm);
  Ring10->SetCenterPositionInY(285.0*mm);
  Ring10->SetCenterPositionInZ(1494.77*mm);

  //Ring 11 (R3)
  Ring11->SetQuartzSizeX(19.0*cm);
  Ring11->SetQuartzSizeY(6.0*cm);  //without the 45 degree cut region
  Ring11->SetQuartzSizeZ(2.0*cm);
  Ring11->SetLowerInterfacePlane(7.5*cm);
  Ring11->SetMiddleBoxHeight(30.0*cm);
  Ring11->SetUpperInterfacePlane(20.5*cm);
  Ring11->SetLowerConeFrontFaceAngle(18*degree);
  Ring11->SetLowerConeBackFaceAngle(22*degree);
  Ring11->SetLowerConeSideFaceAngle(0*degree);
  Ring11->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring11->SetQuartzInterfaceOpeningX(19.8*cm);
  Ring11->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring11->SetPMTInterfaceOpeningZ(7.0*cm);
  Ring11->SetPMTInterfaceOpeningX(7.0*cm);  
  Ring11->SetPMTCathodeRadius(3.5*cm);
  Ring11->SetPMTCathodeThickness(0.1*cm);
  Ring11->SetAzimuthalRotationAngle(0*degree);
  Ring11->SetPolarRotationAngle(6*degree);
  Ring11->Initialize();
  Ring11->ConstructDetector(World_Physical);
  Ring11->SetCenterPositionInX(250*mm);
  Ring11->SetCenterPositionInY(322.1*mm);
  Ring11->SetCenterPositionInZ(1220.68*mm);
  
  //Ring 12 (R4)
  Ring12->SetQuartzSizeX(21.3*cm);
  Ring12->SetQuartzSizeY(12*cm);  //without the 45 degree cut region
  Ring12->SetQuartzSizeZ(2*cm);
  Ring12->SetLowerInterfacePlane(7.5*cm);
  Ring12->SetMiddleBoxHeight(20*cm);
  Ring12->SetUpperInterfacePlane(25.3*cm);
  Ring12->SetLowerConeFrontFaceAngle(17*degree);
  Ring12->SetLowerConeBackFaceAngle(22*degree);
  Ring12->SetLowerConeSideFaceAngle(0*degree);
  Ring12->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring12->SetQuartzInterfaceOpeningX(22.1*cm);
  Ring12->SetQuartzToPMTOffsetInZ(0.3*cm); 
  Ring12->SetPMTInterfaceOpeningZ(7*cm);
  Ring12->SetPMTInterfaceOpeningX(7*cm);  
  Ring12->SetPMTCathodeRadius(3.5*cm);
  Ring12->SetPMTCathodeThickness(0.1*cm);
  Ring12->SetAzimuthalRotationAngle(0*degree);
  Ring12->SetPolarRotationAngle(6*degree);
  Ring12->Initialize();
  Ring12->ConstructDetector(World_Physical);
  Ring12->SetCenterPositionInX(250*mm);
  Ring12->SetCenterPositionInY(359.3*mm);
  Ring12->SetCenterPositionInZ(941.25*mm);
  
  //Ring 13 (R5 bf)
  Ring13->SetQuartzSizeX(8.0*cm);
  Ring13->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring13->SetQuartzSizeZ(1.7*cm);
  Ring13->SetLowerInterfacePlane(9*cm);
  Ring13->SetMiddleBoxHeight(0.001*mm);
  Ring13->SetUpperInterfacePlane(32.95*cm);
  Ring13->SetLowerConeFrontFaceAngle(18*degree);
  Ring13->SetLowerConeBackFaceAngle(19*degree);
  Ring13->SetLowerConeSideFaceAngle(0*degree);
  Ring13->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring13->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring13->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring13->SetPMTInterfaceOpeningZ(7*cm);
  Ring13->SetPMTInterfaceOpeningX(7*cm);  
  Ring13->SetPMTCathodeRadius(3.5*cm);
  Ring13->SetPMTCathodeThickness(0.1*cm);
  Ring13->SetAzimuthalRotationAngle(0*degree);
  Ring13->SetPolarRotationAngle(6*degree);
  Ring13->Initialize();
  Ring13->ConstructDetector(World_Physical);
  Ring13->SetCenterPositionInX(250*mm);
  Ring13->SetCenterPositionInY(427.7*mm);
  Ring13->SetCenterPositionInZ(802.47*mm);
 
  //Ring 14 (R5 ff 1)
  Ring14->SetQuartzSizeX(8.0*cm);
  Ring14->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring14->SetQuartzSizeZ(1.7*cm);
  Ring14->SetLowerInterfacePlane(9*cm);
  Ring14->SetMiddleBoxHeight(0.001*mm);
  Ring14->SetUpperInterfacePlane(32.95*cm);
  Ring14->SetLowerConeFrontFaceAngle(18*degree);
  Ring14->SetLowerConeBackFaceAngle(19*degree);
  Ring14->SetLowerConeSideFaceAngle(0*degree);
  Ring14->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring14->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring14->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring14->SetPMTInterfaceOpeningZ(7*cm);
  Ring14->SetPMTInterfaceOpeningX(7*cm);  
  Ring14->SetPMTCathodeRadius(3.5*cm);
  Ring14->SetPMTCathodeThickness(0.1*cm);
  Ring14->SetAzimuthalRotationAngle(0*degree);
  Ring14->SetPolarRotationAngle(6*degree);
  Ring14->Initialize();
  Ring14->ConstructDetector(World_Physical);
  Ring14->SetCenterPositionInX(163.3*mm);
  Ring14->SetCenterPositionInY(427.7*mm);
  Ring14->SetCenterPositionInZ(651.64*mm);
  
  //Ring 15 (R5 ff2)
  Ring15->SetQuartzSizeX(8.0*cm);
  Ring15->SetQuartzSizeY(14*cm);  //without the 45 degree cut region
  Ring15->SetQuartzSizeZ(1.7*cm);
  Ring15->SetLowerInterfacePlane(9*cm);
  Ring15->SetMiddleBoxHeight(0.001*mm);
  Ring15->SetUpperInterfacePlane(32.95*cm);
  Ring15->SetLowerConeFrontFaceAngle(18*degree);
  Ring15->SetLowerConeBackFaceAngle(19*degree);
  Ring15->SetLowerConeSideFaceAngle(0*degree);
  Ring15->SetQuartzInterfaceOpeningZ(2.4*cm);
  Ring15->SetQuartzInterfaceOpeningX(8.8*cm);
  Ring15->SetQuartzToPMTOffsetInZ(-0.2*cm);  
  Ring15->SetPMTInterfaceOpeningZ(7*cm);
  Ring15->SetPMTInterfaceOpeningX(7*cm);  
  Ring15->SetPMTCathodeRadius(3.5*cm);
  Ring15->SetPMTCathodeThickness(0.1*cm);
  Ring15->SetAzimuthalRotationAngle(0*degree);
  Ring15->SetPolarRotationAngle(6*degree);
  Ring15->Initialize();
  Ring15->ConstructDetector(World_Physical);
  Ring15->SetCenterPositionInX(336.7*mm);
  Ring15->SetCenterPositionInY(427.7*mm);
  Ring15->SetCenterPositionInZ(651.64*mm);
  
  //Ring 16 (R6)
  Ring16->SetQuartzSizeX(26*cm);
  Ring16->SetQuartzSizeY(10*cm);  //without the 45 degree cut region
  Ring16->SetQuartzSizeZ(2*cm);
  Ring16->SetLowerInterfacePlane(8.3*cm);
  Ring16->SetMiddleBoxHeight(9.0*cm);
  Ring16->SetUpperInterfacePlane(16.3*cm);
  Ring16->SetLowerConeFrontFaceAngle(17*degree);
  Ring16->SetLowerConeBackFaceAngle(20*degree);
  Ring16->SetLowerConeSideFaceAngle(0*degree);
  Ring16->SetQuartzInterfaceOpeningZ(2.7*cm);
  Ring16->SetQuartzInterfaceOpeningX(26.8*cm);
  Ring16->SetQuartzToPMTOffsetInZ(0*cm);  
  Ring16->SetPMTInterfaceOpeningZ(7*cm);
  Ring16->SetPMTInterfaceOpeningX(7*cm);  
  Ring16->SetPMTCathodeRadius(3.5*cm);
  Ring16->SetPMTCathodeThickness(0.1*cm);
  Ring16->SetAzimuthalRotationAngle(0*degree);
  Ring16->SetPolarRotationAngle(6*degree);
  Ring16->Initialize();
  Ring16->ConstructDetector(World_Physical);
  Ring16->SetCenterPositionInX(250*mm);
  Ring16->SetCenterPositionInY(509.3*mm);
  Ring16->SetCenterPositionInZ(350.95*mm);

  //Scint5 
  Scint5->SetSizeX(30*cm);
  Scint5->SetSizeY(25*cm);
  Scint5->SetSizeZ(2*cm);
  Scint5->SetAzimuthalRotationAngle(0);
  Scint5->SetPolarRotationAngle(0);
  Scint5->Initialize();
  Scint5->ConstructAuxilary(World_Physical);
  Scint5->SetCenterPositionInX(250*mm);
  Scint5->SetCenterPositionInY(0*mm);
  Scint5->SetCenterPositionInZ(70*mm);

  //Scint6
  Scint6->SetSizeX(30*cm);
  Scint6->SetSizeY(25*cm);
  Scint6->SetSizeZ(2*cm);
  Scint6->SetAzimuthalRotationAngle(0);
  Scint6->SetPolarRotationAngle(0);
  Scint6->Initialize();
  Scint6->ConstructAuxilary(World_Physical);
  Scint6->SetCenterPositionInX(250*mm);
  Scint6->SetCenterPositionInY(250*mm);
  Scint6->SetCenterPositionInZ(70*mm);

  //Scint7
  Scint7->SetSizeX(30*cm);
  Scint7->SetSizeY(25*cm);
  Scint7->SetSizeZ(2*cm);
  Scint7->SetAzimuthalRotationAngle(0);
  Scint7->SetPolarRotationAngle(0);
  Scint7->Initialize();
  Scint7->ConstructAuxilary(World_Physical);
  Scint7->SetCenterPositionInX(250*mm);
  Scint7->SetCenterPositionInY(0*mm);
  Scint7->SetCenterPositionInZ(2060*mm);

  //Scint8
  Scint8->SetSizeX(30*cm);
  Scint8->SetSizeY(25*cm);
  Scint8->SetSizeZ(2*cm);
  Scint8->SetAzimuthalRotationAngle(0);
  Scint8->SetPolarRotationAngle(0);
  Scint8->Initialize();
  Scint8->ConstructAuxilary(World_Physical);
  Scint8->SetCenterPositionInX(250*mm);
  Scint8->SetCenterPositionInY(250*mm);
  Scint8->SetCenterPositionInZ(2060*mm);

  //-------Misc. objects-------//
  //AlPlate
  AlPlate->SetSizeX(0.1*cm);
  AlPlate->SetSizeY(0.1*cm);
  AlPlate->SetSizeZ(0.635*cm);
  AlPlate->SetAzimuthalRotationAngle(0);
  AlPlate->SetPolarRotationAngle(0);
  AlPlate->Initialize();
  AlPlate->ConstructInsensitive(World_Physical);
  AlPlate->SetCenterPositionInX(700*mm);
  AlPlate->SetCenterPositionInY(700*mm);
  AlPlate->SetCenterPositionInZ(100*mm);
  
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
void MOLLEROptConstruction::GetQuartz9Limits(G4double *vals)
{
  Ring9->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz10Limits(G4double *vals)
{
  Ring10->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz11Limits(G4double *vals)
{
  Ring11->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz12Limits(G4double *vals)
{
  Ring12->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz13Limits(G4double *vals)
{
  Ring13->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz14Limits(G4double *vals)
{
  Ring14->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz15Limits(G4double *vals)
{
  Ring15->GetQuartzLimits(vals);
}
void MOLLEROptConstruction::GetQuartz16Limits(G4double *vals)
{
  Ring16->GetQuartzLimits(vals);
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
void MOLLEROptConstruction::GetScint5Limits(G4double *vals)
{
  Scint5->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint6Limits(G4double *vals)
{
  Scint6->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint7Limits(G4double *vals)
{
  Scint7->GetScintLimits(vals);
}
void MOLLEROptConstruction::GetScint8Limits(G4double *vals)
{
  Scint8->GetScintLimits(vals);
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
void MOLLEROptConstruction::GetLightGuide9Limits(G4double *vals)
{
  Ring9->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide10Limits(G4double *vals)
{
  Ring10->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide11Limits(G4double *vals)
{
  Ring11->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide12Limits(G4double *vals)
{
  Ring12->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide13Limits(G4double *vals)
{
  Ring13->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide14Limits(G4double *vals)
{
  Ring14->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide15Limits(G4double *vals)
{
  Ring15->GetLightGuideLimits(vals);
}
void MOLLEROptConstruction::GetLightGuide16Limits(G4double *vals)
{
  Ring16->GetLightGuideLimits(vals);
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

