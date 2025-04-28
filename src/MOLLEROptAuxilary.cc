#include "MOLLEROptAuxilary.hh"

MOLLEROptAuxilary::MOLLEROptAuxilary(MOLLEROptTrackingReadout *TrRO, G4String name, MOLLEROptMaterial* mat)
{	    	    
  TrackingReadout = TrRO;
  AuxType = name; // name should be set in construction.cc to distinguish SD's
  Materials = mat;
  VolMaterial = Materials->GetMaterial("Air");  

  Scint = new MOLLEROptAuxilaryScint(TrackingReadout,name,Materials);

  AuxMessenger = NULL;

  MotherVolume = NULL;
  
  AuxLogical  = NULL;
  AuxPhysical = NULL;
  AuxSolid = NULL;

  RotationAux = NULL;

}

MOLLEROptAuxilary::~MOLLEROptAuxilary()
{
  delete Scint;
}

void MOLLEROptAuxilary::SetAzimuthalRotationAngle(G4double val)
{
  AzimuAngle = val; //About z axis
}
void MOLLEROptAuxilary::SetPolarRotationAngle(G4double val)
{
  PolarAngle = val; //About x axis
}
void MOLLEROptAuxilary::SetSizeX(G4double x)
{
  if(Scint) Scint->SetSizeX(x);
}
void MOLLEROptAuxilary::SetSizeY(G4double y)
{
  if(Scint) Scint->SetSizeY(y);
}				       
void MOLLEROptAuxilary::SetSizeZ(G4double z)
{
  if(Scint) Scint->SetSizeZ(z);
}				       


void MOLLEROptAuxilary::UpdateThisGeometry()
{
  
  G4LogicalVolume *mLog;
  G4GeometryManager::GetInstance()->OpenGeometry();
  delete AuxPhysical;
  RotationAux->rotateZ(AzimuAngle);
  RotationAux->rotateX(PolarAngle);
  Scint->UpdateGeometry();
  CalculateDimensions();
  AuxSolid = new G4Box(AuxType+"_Solid",
		        AuxFullLengthX/2, 
		        AuxFullLengthY/2,
		        AuxFullLengthZ/2);
  AuxLogical = new G4LogicalVolume(AuxSolid, VolMaterial, AuxType+"_Logical");
  AuxLogical->SetSolid(AuxSolid);
  ResetCenterLocation();
  ConstructAuxilary(MotherVolume);
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
   
}

void MOLLEROptAuxilary::CalculateDimensions()
{
  
    AuxFullLengthX = Scint->GetSizeX();
    AuxFullLengthY = Scint->GetSizeY();
    AuxFullLengthZ = Scint->GetSizeZ();

}

void MOLLEROptAuxilary::ResetCenterLocation()
{

  PositionAux.setX(PositionAuxX);
  PositionAux.setY(PositionAuxY);
  PositionAux.setZ(PositionAuxZ);

}

void MOLLEROptAuxilary::Initialize()
{
  //let these objects setup their default solids and logical volumes
  AzimuAngle = 0; 
  PolarAngle = 0;
  Scint->Initialize();
  
  CalculateDimensions();
  ResetCenterLocation();

  RotationAux = new G4RotationMatrix;

  AuxSolid = new G4Box(AuxType+"_Solid",
		        AuxFullLengthX/2, 
		        AuxFullLengthY/2,
		        AuxFullLengthZ/2);
  AuxLogical = new G4LogicalVolume( AuxSolid, VolMaterial, AuxType+"_Logical");
}

G4VPhysicalVolume* MOLLEROptAuxilary::ConstructAuxilary(G4VPhysicalVolume* Mother)
{
  if(!Mother) return 0;
  
  if(!MotherVolume){
    MotherVolume = Mother;
  }

  AuxPhysical = new G4PVPlacement(RotationAux,
				  PositionAux,   
				  AuxType+"_Physical",
				  AuxLogical,
				  MotherVolume,false,1);

  G4double ScintRot = Scint->GetRotationX();
     
  Scint->Construct(AuxPhysical);
  /*Scint->SetCenterPositionInX(PositionAuxX);
  Scint->SetCenterPositionInZ(0.5*AuxFullLengthX*(TMath::Sin(ScintRot)) + PositionAuxZ);
  Scint->SetCenterPositionInY(0.5*AuxFullLengthY*(1.0-TMath::Cos(ScintRot)) + 0.5*AuxFullLengthZ*fabs(TMath::Sin(ScintRot)) + 5*mm + PositionAuxY);*/
  Scint->SetCenterPositionInX(0);
  Scint->SetCenterPositionInY(0);
  Scint->SetCenterPositionInZ(0);
  
  //-----------------------------------------------------//

  G4Colour  grey      ( 127/255., 127/255., 127/255.);
  G4VisAttributes *att = new G4VisAttributes(grey);
  att->SetVisibility(false);
  att->SetForceWireframe(true);
  AuxLogical->SetVisAttributes(att);

  if(!AuxMessenger)
    AuxMessenger = new MOLLEROptAuxilaryMessenger(this,AuxType);  
  //G4cout << "An auxilary messenger has been made" << G4endl;


  return AuxPhysical;
} 


//Ring objects
void MOLLEROptAuxilary::SetCenterPositionInX(G4double xPos)
{
    PositionAuxX = xPos;

    AuxPhysical->SetTranslation(G4ThreeVector(PositionAuxX,
					      PositionAuxY, 
					      PositionAuxZ));
}

void MOLLEROptAuxilary::SetCenterPositionInY(G4double yPos)
{
    PositionAuxY = yPos;

    AuxPhysical->SetTranslation(G4ThreeVector(PositionAuxX,
					      PositionAuxY, 
					      PositionAuxZ));
}

void MOLLEROptAuxilary::SetCenterPositionInZ(G4double zPos)
{
    PositionAuxZ = zPos;

    AuxPhysical->SetTranslation(G4ThreeVector(PositionAuxX,
					      PositionAuxY, 
					      PositionAuxZ));
}

void MOLLEROptAuxilary::GetScintLimits(G4double *vals)
{
  ScintPos.setX(PositionAuxX);
  ScintPos.setY(PositionAuxY);
  ScintPos.setZ(PositionAuxZ);
  Scint->GetScintLimits(vals,ScintPos);
}

void MOLLEROptAuxilary::SetMaterial(G4String materialName)
{
  VolMaterial = Materials->GetMaterial(materialName);
}

