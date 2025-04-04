#include "MOLLEROptInsensitive.hh"

MOLLEROptInsensitive::MOLLEROptInsensitive(G4String name, MOLLEROptMaterial* mat)
{	    	    
  InsType = name; // name should be set in construction.cc to distinguish SD's
  Materials = mat;
  VolMaterial = Materials->GetMaterial("Air");  

  AlPlate = new MOLLEROptInsensitiveAlPlate(name,Materials);

  InsMessenger = NULL;

  MotherVolume = NULL;
  
  InsLogical  = NULL;
  InsPhysical = NULL;
  InsSolid = NULL;

  RotationIns = NULL;

}

MOLLEROptInsensitive::~MOLLEROptInsensitive()
{
  delete AlPlate;
}

void MOLLEROptInsensitive::SetAzimuthalRotationAngle(G4double val)
{
  AzimuAngle = val; //About z axis
}
void MOLLEROptInsensitive::SetPolarRotationAngle(G4double val)
{
  PolarAngle = val; //About x axis
}
void MOLLEROptInsensitive::SetSizeX(G4double x)
{
  if(AlPlate) AlPlate->SetSizeX(x);
}
void MOLLEROptInsensitive::SetSizeY(G4double y)
{
  if(AlPlate) AlPlate->SetSizeY(y);
}				       
void MOLLEROptInsensitive::SetSizeZ(G4double z)
{
  if(AlPlate) AlPlate->SetSizeZ(z);
}				       


void MOLLEROptInsensitive::UpdateThisGeometry()
{
  G4LogicalVolume *mLog;

  G4GeometryManager::GetInstance()->OpenGeometry();
  
  delete InsPhysical;
  RotationIns->rotateZ(AzimuAngle);
  RotationIns->rotateX(PolarAngle);
  AlPlate->UpdateGeometry();
  CalculateDimensions();
  InsSolid = new G4Box(InsType+"_Solid",
		        InsFullLengthX, 
		        InsFullLengthY,
		        InsFullLengthZ);
  InsLogical = new G4LogicalVolume(InsSolid, VolMaterial, InsType+"_Logical");
  InsLogical->SetSolid(InsSolid);
  ResetCenterLocation();
  ConstructInsensitive(MotherVolume);
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
   
}

void MOLLEROptInsensitive::CalculateDimensions()
{
  
    InsFullLengthX = AlPlate->GetSizeX();
    InsFullLengthY = AlPlate->GetSizeY();
    InsFullLengthZ = AlPlate->GetSizeZ();

}

void MOLLEROptInsensitive::ResetCenterLocation()
{

  /*PositionIns.setX(PositionInsX);
  PositionIns.setY(PositionInsY);
  PositionIns.setZ(PositionInsZ);*/

}

void MOLLEROptInsensitive::Initialize()
{
  //let these objects setup their default solids and logical volumes
  AzimuAngle = 0; 
  PolarAngle = 0;
  AlPlate->Initialize();
  
  CalculateDimensions();
  ResetCenterLocation();

  RotationIns = new G4RotationMatrix;

  InsSolid = new G4Box(InsType+"_Solid",
		        InsFullLengthX, 
		        InsFullLengthY,
		        InsFullLengthZ);
  InsLogical = new G4LogicalVolume( InsSolid, VolMaterial, InsType+"_Logical");
}

G4VPhysicalVolume* MOLLEROptInsensitive::ConstructInsensitive(G4VPhysicalVolume* Mother)
{
  if(!Mother) return 0;
  
  if(!MotherVolume){
    MotherVolume = Mother;
  }

  InsPhysical = new G4PVPlacement(RotationIns,
				  PositionIns,   
				  InsType+"_Physical",
				  InsLogical,
				  MotherVolume,false,1);

  G4double AlPlateRot = AlPlate->GetRotationX();
     
  AlPlate->Construct(InsPhysical);
  /*AlPlate->SetCenterPositionInX(PositionInsX);
  AlPlate->SetCenterPositionInZ(0.5*InsFullLengthX*(TMath::Sin(AlPlateRot)) + PositionInsZ);
  AlPlate->SetCenterPositionInY(0.5*InsFullLengthY*(1.0-TMath::Cos(AlPlateRot)) + 0.5*InsFullLengthZ*fabs(TMath::Sin(AlPlateRot)) + 5*mm + PositionInsY);*/
  AlPlate->SetCenterPositionInX(PositionInsX);
  AlPlate->SetCenterPositionInY(PositionInsY);
  AlPlate->SetCenterPositionInZ(PositionInsZ);
  
  //-----------------------------------------------------//

  G4Colour  grey      ( 127/255., 127/255., 127/255.);
  G4VisAttributes *att = new G4VisAttributes(grey);
  att->SetVisibility(false);
  att->SetForceWireframe(true);
  InsLogical->SetVisAttributes(att);

  if(!InsMessenger)
    InsMessenger = new MOLLEROptInsensitiveMessenger(this,InsType);  
  //G4cout << "An insensitive messenger has been made" << G4endl;


  return InsPhysical;
} 


//Ring objects
void MOLLEROptInsensitive::SetCenterPositionInX(G4double xPos)
{
    PositionInsX = xPos;

    InsPhysical->SetTranslation(G4ThreeVector(PositionInsX,
					      PositionInsY, 
					      PositionInsZ));
}

void MOLLEROptInsensitive::SetCenterPositionInY(G4double yPos)
{
    PositionInsY = yPos;

    InsPhysical->SetTranslation(G4ThreeVector(PositionInsX,
					      PositionInsY, 
					      PositionInsZ));
}

void MOLLEROptInsensitive::SetCenterPositionInZ(G4double zPos)
{
    PositionInsZ = zPos;

    InsPhysical->SetTranslation(G4ThreeVector(PositionInsX,
					      PositionInsY, 
					      PositionInsZ));
}

void MOLLEROptInsensitive::GetPlateLimits(G4double *vals)
{
  AlPlate->GetPlateLimits(vals);
}

void MOLLEROptInsensitive::SetMaterial(G4String materialName)
{
  VolMaterial = Materials->GetMaterial(materialName);
}

