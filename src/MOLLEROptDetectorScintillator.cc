#include "MOLLEROptDetectorScintillator.hh"

MOLLEROptDetectorScintillator::MOLLEROptDetectorScintillator(MOLLEROptTrackingReadout *TrRO, G4String name, MOLLEROptMaterial* mat)
{
  Name = name+"_Quartz";
  
  TrackingReadout = TrRO;
  Materials = mat;
  QuartzMaterial = Materials->GetMaterial("Air");  

  QuartzLogical  = NULL;
  QuartzPhysical = NULL;
  QuartzSolid = NULL;

  Rotation       = NULL;
  ScintillatorSD       = NULL;

  SegRadDamageFlag = false;
  OpticalParameters = Materials->GetOpticalParametersTable();

  QRotationX = 0;
  QRotationZ = 0;
  
  Vertices.resize(8);

  bevel = 0.0*cm;

}

MOLLEROptDetectorScintillator::~MOLLEROptDetectorScintillator()
{
  
}


void MOLLEROptDetectorScintillator::Initialize()
{
  //Quartz backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Quartz frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2+FullLengthZ);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2+FullLengthZ);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);


  G4GenericTrap *temp1Solid = new G4GenericTrap(Name+"_Solid_tmp1",FullLengthZ/2, Vertices);

  G4Box* box1 = new G4Box(Name+"_Solid_box1",(FullLengthX+FullLengthZ)/(2*sqrt(2))-bevel,(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ)/(2*sqrt(2))-bevel);
  G4Box* box2 = new G4Box(Name+"_Solid_box2",(FullLengthX+FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ  + 1.0*cm)/(2*sqrt(2)));

  G4Box* box3 = new G4Box(Name+"_Solid_box3",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ)/(2*sqrt(2))-bevel   ,(FullLengthY+2*FullLengthZ)/(2*sqrt(2))-bevel);
  G4Box* box4 = new G4Box(Name+"_Solid_box4",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY+2*FullLengthZ  + 1.0*cm)/(2*sqrt(2)));
  
  G4SubtractionSolid *box5 = new G4SubtractionSolid(Name+"_Solid_box5",box2,box1);
  G4SubtractionSolid *box6 = new G4SubtractionSolid(Name+"_Solid_box6",box4,box3);

  G4RotationMatrix *rot = new G4RotationMatrix;
  G4ThreeVector trans = G4ThreeVector(0,0,0);
  rot->rotateY(45*degree);

  G4SubtractionSolid *temp2Solid = new G4SubtractionSolid(Name+"_Solid_tmp2",temp1Solid,box5,rot,trans);

  trans = G4ThreeVector(0,FullLengthZ/2,0);
  G4RotationMatrix *rot2 = new G4RotationMatrix;
  rot2->rotateX(45*degree);
  
  QuartzSolid = new G4SubtractionSolid(Name+"_Solid",temp2Solid,box6,rot2,trans);

  // QuartzSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);
  
  QuartzLogical = new G4LogicalVolume(QuartzSolid,QuartzMaterial,Name+"_Logical");      
  
  G4OpticalSurface* QuartzSurface = new G4OpticalSurface(Name+"_Surface");
  
  const G4double pol = 0.99;
  QuartzSurface->SetModel(unified);
  QuartzSurface->SetFinish(polished);
  QuartzSurface->SetType(dielectric_dielectric);
  QuartzSurface->SetPolish(pol);

  //reposition the quartz to lign up with the bottom of the mother volume
  //G4double motherYmin = MotherVolume->GetLogicalVolume()->GetSolid().GetExtent().GetYmin();
  //G4double motherYmax = MotherVolume->GetLogicalVolume()->GetSolid()->GetExtent().GetYmax();

  PositionX = 0.0*cm;
  PositionY = 0.0*cm;//motherYmin+FullLengthY/2.0; 
  PositionZ = 0.0*cm; 
  
  Position  = G4ThreeVector(PositionX,
			    PositionY,
			    PositionZ);
  
  Rotation = new G4RotationMatrix;
  Rotation->rotateY(0.0*degree);
  
  new G4LogicalSkinSurface("QuartzSurface", QuartzLogical, QuartzSurface);

  SDman = G4SDManager::GetSDMpointer();
  ScintillatorSD = new MOLLEROptQuartzSD("/Scintillator",TrackingReadout);
  SDman->AddNewDetector(ScintillatorSD);  
  QuartzLogical->SetSensitiveDetector(ScintillatorSD);

  G4Colour  blue    ( 0/255., 0/255.,   255/255.);
  G4VisAttributes* VisAtt = new G4VisAttributes(blue);
  VisAtt->SetVisibility(true);
  VisAtt->SetForceWireframe(true);
  QuartzLogical->SetVisAttributes(VisAtt);

}

void MOLLEROptDetectorScintillator::Construct(G4VPhysicalVolume* Mother)
{

  MotherVolume = Mother;

  
  QuartzPhysical = new G4PVPlacement(Rotation,  
				     Position, 
				     Name+"_Physical", 
				     QuartzLogical,
				     MotherVolume, 
				     false, 
				     2);
} 

void MOLLEROptDetectorScintillator::SetMaterial(G4String materialName)
{

}


void MOLLEROptDetectorScintillator::SetQuartzRotX(G4double rot)
{

  QRotationX = rot;
  Rotation->rotateX(rot);

  // PositionZ += 0.5*FullLengthY*TMath::Sin(rot);
  // PositionY += 0.5*FullLengthY*(1.0-TMath::Cos(rot)) + 0.5*FullLengthZ*TMath::Sin(rot);

    //TMath::Tan(rot)*FullLengthY/2;

  cout << "PositionZ = " << PositionZ << " delta = " <<  TMath::Tan(rot)*FullLengthY/2 << endl;
  // PositionY += TMath::Sin(rot)*FullLengthZ/2;
  

  QuartzPhysical->SetRotation(Rotation);
  // QuartzPhysical->SetTranslation(G4ThreeVector(PositionX,
  // 					       PositionY, 
  // 					       PositionZ));
    
}
void MOLLEROptDetectorScintillator::SetQuartzRotZ(G4double rot)
{

  QRotationZ = rot;
  Rotation->rotateZ(rot);
  QuartzPhysical->SetRotation(Rotation);
}

void MOLLEROptDetectorScintillator::SetCenterPositionInX(G4double xPos)
{
    PositionX =xPos;	 

    QuartzPhysical->SetTranslation(G4ThreeVector(PositionX,
						 PositionY, 
						 PositionZ));
}

void MOLLEROptDetectorScintillator::SetCenterPositionInY(G4double yPos)
{
    PositionY = yPos;

    QuartzPhysical->SetTranslation(G4ThreeVector(PositionX,
					      PositionY, 
					      PositionZ));
}

void MOLLEROptDetectorScintillator::SetCenterPositionInZ(G4double zPos)
{
    PositionZ = zPos;

    QuartzPhysical->SetTranslation(G4ThreeVector(PositionX,
					      PositionY, 
					      PositionZ));
}


void MOLLEROptDetectorScintillator::ClearVolumes()
{
  //SDman->Activate("/Detector",false);
  if(ScintillatorSD) delete ScintillatorSD;
  if(QuartzPhysical) delete QuartzPhysical;
  if(QuartzLogical) delete QuartzLogical;
}


void MOLLEROptDetectorScintillator::UpdateGeometry()
{
  // G4PhysicalVolumeStore::GetInstance()->DeRegister(QuartzPhysical);
  // G4LogicalVolumeStore::GetInstance()->DeRegister(QuartzLogical);
  
  G4SolidStore::GetInstance()->DeRegister(QuartzSolid);
  
  // G4LogicalBorderSurface::CleanSurfaceTable();
  delete QuartzSolid;

  //Quartz backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Quartz frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2+FullLengthZ);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2+FullLengthZ);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);

  G4GenericTrap *temp1Solid = new G4GenericTrap(Name+"_Solid_tmp1",FullLengthZ/2, Vertices);

  G4Box* box1 = new G4Box(Name+"_Solid_box1",(FullLengthX+FullLengthZ)/(2*sqrt(2))-bevel,(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ)/(2*sqrt(2))-bevel);
  G4Box* box2 = new G4Box(Name+"_Solid_box2",(FullLengthX+FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ  + 1.0*cm)/(2*sqrt(2)));

  G4Box* box3 = new G4Box(Name+"_Solid_box3",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ)/(2*sqrt(2))-bevel   ,(FullLengthY+2*FullLengthZ)/(2*sqrt(2))-bevel);
  G4Box* box4 = new G4Box(Name+"_Solid_box4",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY+2*FullLengthZ  + 1.0*cm)/(2*sqrt(2)));

  G4SubtractionSolid *box5 = new G4SubtractionSolid(Name+"_Solid_box5",box2,box1);
  G4SubtractionSolid *box6 = new G4SubtractionSolid(Name+"_Solid_box6",box4,box3);

  G4RotationMatrix *rot = new G4RotationMatrix;
  G4ThreeVector trans = G4ThreeVector(0,0,0);
  rot->rotateY(45*degree);

  G4SubtractionSolid *temp2Solid = new G4SubtractionSolid(Name+"_Solid_tmp2",temp1Solid,box5,rot,trans);

  trans = G4ThreeVector(0,FullLengthZ/2,0);
  G4RotationMatrix *rot2 = new G4RotationMatrix;
  rot2->rotateX(45*degree);
  
  
  QuartzSolid = new G4SubtractionSolid(Name+"_Solid",temp2Solid,box6,rot2,trans);
  // QuartzSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);

  QuartzLogical->SetSolid(QuartzSolid);


  if(SegRadDamageFlag){

    cout << "Setting segmentation!" << endl;
    
    G4int nCells = OpticalParameters->CellMaterial.size();
    G4String CellName;
    G4double CelldX, CelldY, CellX, CellY;

    G4Colour  grey      ( 127/255., 127/255., 127/255.);
    G4VisAttributes* CellVisAtt = new G4VisAttributes(grey);
    CellVisAtt->SetVisibility(true);
    CellVisAtt->SetForceWireframe(true);
    
    for(int n = 0; n < nCells; n++){

      CellX = OpticalParameters->QAbs_X[n];
      CelldX = OpticalParameters->QAbs_dX[n];
      CellY = OpticalParameters->QAbs_Y[n];
      CelldY = OpticalParameters->QAbs_dY[n];
      G4Material* mat = OpticalParameters->CellMaterial[n];
      
      CellName =  Name + Form("_Solid_Cell_%d",n+1);
      G4Box *cell = new G4Box(CellName,CelldX,CelldY,FullLengthZ/2);
      
      CellName =  Name + Form("_Logical_Cell_%d",n+1);
      G4LogicalVolume* cellLog = new G4LogicalVolume(cell, mat, CellName,0,0,0);
      cellLog->SetVisAttributes(CellVisAtt);

      CellName =  Name + Form("_Physical_Cell_%d",n+1);
      G4ThreeVector cellPos(CellX,CellY,0);
      new G4PVPlacement(0, cellPos, CellName, cellLog,
			QuartzPhysical, false, n+1);
    }
  }

}


void MOLLEROptDetectorScintillator::GetQuartzLimits(G4double *vals)
{

  G4ThreeVector trans =  QuartzPhysical->GetTranslation();

  vals[0] = -FullLengthX/2+trans.x();
  vals[1] = FullLengthX/2+trans.x(); 
  vals[2] = FullLengthX/2+trans.x();
  vals[3] = -FullLengthX/2+trans.x(); 
  vals[4] = -FullLengthY/2+trans.y();
  vals[5] = FullLengthY/2+trans.y(); 
  vals[6] = FullLengthY/2+trans.y();
  vals[7] = -FullLengthY/2+trans.y();

 
}
