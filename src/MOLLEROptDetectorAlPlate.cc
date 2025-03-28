#include "MOLLEROptDetectorAlPlate.hh"

MOLLEROptDetectorAlPlate::MOLLEROptDetectorAlPlate(G4String name, MOLLEROptMaterial* mat)
{
  Name = name+"_AlPlate";
  
  Materials = mat;
  PlateMaterial = Materials->GetMaterial("Aluminum");  

  PlateLogical  = NULL;
  PlatePhysical = NULL;
  PlateSolid = NULL;

  Rotation       = NULL;

  OpticalParameters = Materials->GetOpticalParametersTable();

  RotationX = 0;
  RotationZ = 0;
  
  Vertices.resize(8);

}

MOLLEROptDetectorAlPlate::~MOLLEROptDetectorAlPlate()
{
  
}


void MOLLEROptDetectorAlPlate::Initialize()
{
  //Plate backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Plate frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);


  G4GenericTrap *temp1Solid = new G4GenericTrap(Name+"_Solid_tmp1",FullLengthZ/2, Vertices);

  G4Box* box1 = new G4Box(Name+"_Solid_box1",(FullLengthX+FullLengthZ)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ)/(2*sqrt(2)));
  G4Box* box2 = new G4Box(Name+"_Solid_box2",(FullLengthX+FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ  + 1.0*cm)/(2*sqrt(2)));

  G4Box* box3 = new G4Box(Name+"_Solid_box3",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ)/(2*sqrt(2)),(FullLengthY+2*FullLengthZ)/(2*sqrt(2)));
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
  
  PlateSolid = new G4SubtractionSolid(Name+"_Solid",temp2Solid,box6,rot2,trans);

  // PlateSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);
  
  PlateLogical = new G4LogicalVolume(PlateSolid,PlateMaterial,Name+"_Logical");      
  
  G4OpticalSurface* PlateSurface = new G4OpticalSurface(Name+"_Surface");
  
  const G4double pol = 0.70;//Chosen arbitrarily
  PlateSurface->SetModel(unified);
  PlateSurface->SetFinish(polished);
  PlateSurface->SetType(dielectric_dielectric);
  PlateSurface->SetPolish(pol);

  //reposition the Plate to lign up with the bottom of the mother volume
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
  
  new G4LogicalSkinSurface("PlateSurface", PlateLogical, PlateSurface);

  G4Colour  green    ( 0/255., 255/255.,   0/255.);
  G4VisAttributes* VisAtt = new G4VisAttributes(green);
  VisAtt->SetVisibility(true);
  VisAtt->SetForceWireframe(true);
  PlateLogical->SetVisAttributes(VisAtt);

}

void MOLLEROptDetectorAlPlate::Construct(G4VPhysicalVolume* Mother)
{

  MotherVolume = Mother;

  
  PlatePhysical = new G4PVPlacement(Rotation,  
				     Position, 
				     Name+"_Physical", 
				     PlateLogical,
				     MotherVolume, 
				     false, 
				     2);
} 

void MOLLEROptDetectorAlPlate::SetMaterial(G4String materialName)
{

}


void MOLLEROptDetectorAlPlate::SetPlateRotX(G4double rot)
{

  RotationX = rot;
  Rotation->rotateX(rot);
  cout << "PositionZ = " << PositionZ << " delta = " <<  TMath::Tan(rot)*FullLengthY/2 << endl;  
  PlatePhysical->SetRotation(Rotation);
    
}
void MOLLEROptDetectorAlPlate::SetPlateRotZ(G4double rot)
{

  RotationZ = rot;
  Rotation->rotateZ(rot);
  PlatePhysical->SetRotation(Rotation);
}

void MOLLEROptDetectorAlPlate::SetCenterPositionInX(G4double xPos)
{
    PositionX =xPos;	 
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}

void MOLLEROptDetectorAlPlate::SetCenterPositionInY(G4double yPos)
{
    PositionY = yPos;
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}

void MOLLEROptDetectorAlPlate::SetCenterPositionInZ(G4double zPos)
{
    PositionZ = zPos;
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}


void MOLLEROptDetectorAlPlate::ClearVolumes()
{
  if(PlatePhysical) delete PlatePhysical;
  if(PlateLogical) delete PlateLogical;
}


void MOLLEROptDetectorAlPlate::UpdateGeometry()
{

  G4SolidStore::GetInstance()->DeRegister(PlateSolid);
  
  delete PlateSolid;

  //Plate backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Plate frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);

  G4GenericTrap *temp1Solid = new G4GenericTrap(Name+"_Solid_tmp1",FullLengthZ/2, Vertices);

  G4Box* box1 = new G4Box(Name+"_Solid_box1",(FullLengthX+FullLengthZ)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ)/(2*sqrt(2)));
  G4Box* box2 = new G4Box(Name+"_Solid_box2",(FullLengthX+FullLengthZ + 1.0*cm)/(2*sqrt(2)),(FullLengthY/2.0+FullLengthZ+4.0*mm),(FullLengthX+FullLengthZ  + 1.0*cm)/(2*sqrt(2)));

  G4Box* box3 = new G4Box(Name+"_Solid_box3",FullLengthX/2.0+4.0*mm,(FullLengthY+2*FullLengthZ)/(2*sqrt(2)),(FullLengthY+2*FullLengthZ)/(2*sqrt(2)));
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
  
  PlateSolid = new G4SubtractionSolid(Name+"_Solid",temp2Solid,box6,rot2,trans);

  PlateLogical->SetSolid(PlateSolid);

}


void MOLLEROptDetectorAlPlate::GetPlateLimits(G4double *vals)
{

  G4ThreeVector trans =  PlatePhysical->GetTranslation();

  vals[0] = -FullLengthX/2+trans.x();
  vals[1] = FullLengthX/2+trans.x(); 
  vals[2] = FullLengthX/2+trans.x();
  vals[3] = -FullLengthX/2+trans.x(); 
  vals[4] = -FullLengthY/2+trans.y();
  vals[5] = FullLengthY/2+trans.y(); 
  vals[6] = FullLengthY/2+trans.y();
  vals[7] = -FullLengthY/2+trans.y();
 
}
