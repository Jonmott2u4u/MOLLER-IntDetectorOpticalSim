#include "MOLLEROptInsensitiveAlPlate.hh"

MOLLEROptInsensitiveAlPlate::MOLLEROptInsensitiveAlPlate(G4String name, MOLLEROptMaterial* mat)
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

MOLLEROptInsensitiveAlPlate::~MOLLEROptInsensitiveAlPlate()
{
  
}


void MOLLEROptInsensitiveAlPlate::Initialize()
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


  PlateSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);
  
  PlateLogical = new G4LogicalVolume(PlateSolid,PlateMaterial,Name+"_Logical");      
  
  G4OpticalSurface* PlateSurface = new G4OpticalSurface(Name+"_Surface");
  
  const G4double pol = 0.70;//Chosen arbitrarily
  PlateSurface->SetModel(unified);
  PlateSurface->SetFinish(polished);
  PlateSurface->SetType(dielectric_dielectric);
  PlateSurface->SetPolish(pol);

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

void MOLLEROptInsensitiveAlPlate::Construct(G4VPhysicalVolume* Mother)
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

void MOLLEROptInsensitiveAlPlate::SetMaterial(G4String materialName)
{

}


void MOLLEROptInsensitiveAlPlate::SetRotX(G4double rot)
{

  RotationX = rot;
  Rotation->rotateX(rot);
  cout << "PositionZ = " << PositionZ << " delta = " <<  TMath::Tan(rot)*FullLengthY/2 << endl;  
  PlatePhysical->SetRotation(Rotation);
    
}
void MOLLEROptInsensitiveAlPlate::SetRotZ(G4double rot)
{

  RotationZ = rot;
  Rotation->rotateZ(rot);
  PlatePhysical->SetRotation(Rotation);
}

void MOLLEROptInsensitiveAlPlate::SetCenterPositionInX(G4double xPos)
{
    PositionX =xPos;	 
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}

void MOLLEROptInsensitiveAlPlate::SetCenterPositionInY(G4double yPos)
{
    PositionY = yPos;
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}

void MOLLEROptInsensitiveAlPlate::SetCenterPositionInZ(G4double zPos)
{
    PositionZ = zPos;
    PlatePhysical->SetTranslation(G4ThreeVector(PositionX,PositionY,PositionZ));
}


void MOLLEROptInsensitiveAlPlate::ClearVolumes()
{
  if(PlatePhysical) delete PlatePhysical;
  if(PlateLogical) delete PlateLogical;
}


void MOLLEROptInsensitiveAlPlate::UpdateGeometry()
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

  PlateSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);

  PlateLogical->SetSolid(PlateSolid);

}


void MOLLEROptInsensitiveAlPlate::GetPlateLimits(G4double *vals, G4ThreeVector pos)
{

  G4ThreeVector trans = pos;

  vals[0] = -FullLengthX/2+trans.x();
  vals[1] = FullLengthX/2+trans.x(); 
  vals[2] = FullLengthX/2+trans.x();
  vals[3] = -FullLengthX/2+trans.x(); 
  vals[4] = -FullLengthY/2+trans.y();
  vals[5] = FullLengthY/2+trans.y(); 
  vals[6] = FullLengthY/2+trans.y();
  vals[7] = -FullLengthY/2+trans.y();
 
}
