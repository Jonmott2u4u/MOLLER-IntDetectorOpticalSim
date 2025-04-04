#include "MOLLEROptAuxilaryScint.hh"

MOLLEROptAuxilaryScint::MOLLEROptAuxilaryScint(MOLLEROptTrackingReadout *TrRO, G4String name, MOLLEROptMaterial* mat)
{
  Name = name+"_Scint";
  
  TrackingReadout = TrRO;
  Materials = mat;
  ScintMaterial = Materials->GetMaterial("Scintillator");  

  ScintLogical  = NULL;
  ScintPhysical = NULL;
  ScintSolid    = NULL;

  Rotation      = NULL;
  ScintSD       = NULL;

  OpticalParameters = Materials->GetOpticalParametersTable();

  RotationX = 0;
  RotationZ = 0;
  
  Vertices.resize(8);

}

MOLLEROptAuxilaryScint::~MOLLEROptAuxilaryScint()
{
  
}


void MOLLEROptAuxilaryScint::Initialize()
{
  //Scint backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Scint frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);


  ScintSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);
  
  ScintLogical = new G4LogicalVolume(ScintSolid,ScintMaterial,Name+"_Logical");      
  
  G4OpticalSurface* ScintSurface = new G4OpticalSurface(Name+"_Surface");
  
  const G4double pol = 0.99;
  ScintSurface->SetModel(unified);
  ScintSurface->SetFinish(polished);
  ScintSurface->SetType(dielectric_dielectric); //Not accurate, but doesn't matter for my purposes. Update at some point
  ScintSurface->SetPolish(pol);

  PositionX = 0.0*cm;
  PositionY = 0.0*cm;//motherYmin+FullLengthY/2.0; 
  PositionZ = 0.0*cm; 
  
  Position  = G4ThreeVector(PositionX,
			    PositionY,
			    PositionZ);
  
  Rotation = new G4RotationMatrix;
  Rotation->rotateY(0.0*degree);
  
  new G4LogicalSkinSurface("ScintSurface", ScintLogical, ScintSurface);

  SDman = G4SDManager::GetSDMpointer();
  if (Name.contains("Scint1")) ScintSD = new MOLLEROptScintSD("/Scint1",TrackingReadout);
  else if (Name.contains("Scint2")) ScintSD = new MOLLEROptScintSD("/Scint2",TrackingReadout);
  else if (Name.contains("Scint3")) ScintSD = new MOLLEROptScintSD("/Scint3",TrackingReadout);
  else if (Name.contains("Scint4")) ScintSD = new MOLLEROptScintSD("/Scint4",TrackingReadout);
  else ScintSD = new MOLLEROptScintSD("/Scint1",TrackingReadout);
  SDman->AddNewDetector(ScintSD);  
  ScintLogical->SetSensitiveDetector(ScintSD);

  G4Colour  blue    ( 0/255., 0/255.,   255/255.);
  G4VisAttributes* VisAtt = new G4VisAttributes(blue);
  VisAtt->SetVisibility(true);
  VisAtt->SetForceWireframe(true);
  ScintLogical->SetVisAttributes(VisAtt);

}

void MOLLEROptAuxilaryScint::Construct(G4VPhysicalVolume* Mother)
{

  MotherVolume = Mother;

  
  ScintPhysical = new G4PVPlacement(Rotation,  
				     Position, 
				     Name+"_Physical", 
				     ScintLogical,
				     MotherVolume, 
				     false, 
				     2);
} 

void MOLLEROptAuxilaryScint::SetMaterial(G4String materialName)
{

}


void MOLLEROptAuxilaryScint::SetRotX(G4double rot)
{

  RotationX = rot;
  Rotation->rotateX(rot);

  cout << "PositionZ = " << PositionZ << " delta = " <<  TMath::Tan(rot)*FullLengthY/2 << endl; 
  ScintPhysical->SetRotation(Rotation);
    
}
void MOLLEROptAuxilaryScint::SetRotZ(G4double rot)
{

  RotationZ = rot;
  Rotation->rotateZ(rot);
  ScintPhysical->SetRotation(Rotation);
}

void MOLLEROptAuxilaryScint::SetCenterPositionInX(G4double xPos)
{
    PositionX =xPos;	 

    ScintPhysical->SetTranslation(G4ThreeVector(PositionX,
						 PositionY, 
						 PositionZ));
}

void MOLLEROptAuxilaryScint::SetCenterPositionInY(G4double yPos)
{
    PositionY = yPos;

    ScintPhysical->SetTranslation(G4ThreeVector(PositionX,
					      PositionY, 
					      PositionZ));
}

void MOLLEROptAuxilaryScint::SetCenterPositionInZ(G4double zPos)
{
    PositionZ = zPos;

    ScintPhysical->SetTranslation(G4ThreeVector(PositionX,
					      PositionY, 
					      PositionZ));
}


void MOLLEROptAuxilaryScint::ClearVolumes()
{
  //SDman->Activate("/Auxilary",false);
  if(ScintSD)       delete ScintSD;
  if(ScintPhysical) delete ScintPhysical;
  if(ScintLogical)  delete ScintLogical;
}


void MOLLEROptAuxilaryScint::UpdateGeometry()
{
  
  G4SolidStore::GetInstance()->DeRegister(ScintSolid);//Fails to be deregistered. Maybe it doesn't exist?
  delete ScintSolid;
  //delete ScintPhysical;

  //Scint backface at +FullLengthZ/2
  Vertices[0]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[1]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[2]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[3]=G4TwoVector(FullLengthX/2,-FullLengthY/2);
  
  //Scint frontface at -FullLengthZ/2
  Vertices[4]=G4TwoVector(-FullLengthX/2,-FullLengthY/2);
  Vertices[5]=G4TwoVector(-FullLengthX/2,FullLengthY/2);
  Vertices[6]=G4TwoVector(FullLengthX/2,FullLengthY/2);
  Vertices[7]=G4TwoVector(FullLengthX/2,-FullLengthY/2);


  ScintSolid = new G4GenericTrap(Name+"_Solid",FullLengthZ/2, Vertices);

  ScintLogical->SetSolid(ScintSolid);

}


void MOLLEROptAuxilaryScint::GetScintLimits(G4double *vals)
{

  G4ThreeVector trans =  ScintPhysical->GetTranslation();

  vals[0] = -FullLengthX/2+trans.x();
  vals[1] = FullLengthX/2+trans.x(); 
  vals[2] = FullLengthX/2+trans.x();
  vals[3] = -FullLengthX/2+trans.x(); 
  vals[4] = -FullLengthY/2+trans.y();
  vals[5] = FullLengthY/2+trans.y(); 
  vals[6] = FullLengthY/2+trans.y();
  vals[7] = -FullLengthY/2+trans.y();

 
}
