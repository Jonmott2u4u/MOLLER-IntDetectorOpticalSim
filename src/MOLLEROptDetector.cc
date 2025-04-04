#include "MOLLEROptDetector.hh"

MOLLEROptDetector::MOLLEROptDetector(MOLLEROptTrackingReadout *TrRO, G4String name, MOLLEROptMaterial* mat, G4String lgmat)
{	    	    
  TrackingReadout = TrRO;
  DetType = name; // name should be set in construction.cc to distinguish SD's in the individual parts files (quartz, pmt, etc)
  Materials = mat;
  LightGuideMat = lgmat;
  VolMaterial = Materials->GetMaterial("Air");  

  Quartz = new MOLLEROptDetectorQuartz(TrackingReadout,name,Materials);
  LightGuide = new MOLLEROptDetectorLightGuide(TrackingReadout,name,Materials);
  PMT = new MOLLEROptDetectorPMT(TrackingReadout,name,Materials,LightGuide);

  detMessenger = NULL;

  MotherVolume = NULL;
  
  DetLogical  = NULL;
  DetPhysical = NULL;
  DetSolid = NULL;

  RotationDet = NULL;

}

MOLLEROptDetector::~MOLLEROptDetector()
{
  delete Quartz;
  delete LightGuide;
  delete PMT;
}

void MOLLEROptDetector::SetAzimuthalRotationAngle(G4double val)
{
  AzimuAngle = val; 
}
void MOLLEROptDetector::SetPolarRotationAngle(G4double val)
{
  PolarAngle = val;
}
void MOLLEROptDetector::SetPMTCathodeThickness(G4double val)
{
  if(PMT) PMT->SetCathodeThickness(val);
}
void MOLLEROptDetector::SetPMTCathodeRadius(G4double val)
{
  if(PMT) PMT->SetCathodeRadius(val);
  if(LightGuide) LightGuide->SetPMTOpeningRadius(val);
}
void MOLLEROptDetector::SetPMTInterfaceOpeningZ(G4double size)
{
  if(LightGuide) LightGuide->SetPMTInterfaceOpeningZ(size);
  if(PMT) PMT->SetLGInterfaceOpeningZ(size);
}
void MOLLEROptDetector::SetPMTInterfaceOpeningX(G4double size)
{
  if(LightGuide) LightGuide->SetPMTInterfaceOpeningX(size);
  if(PMT) PMT->SetLGInterfaceOpeningX(size);
}
void MOLLEROptDetector::SetQuartzRotX(G4double rX)
{
  if(Quartz) Quartz->SetQuartzRotX(rX);
}
void MOLLEROptDetector::SetQuartzSizeX(G4double x)
{
  if(Quartz) Quartz->SetQuartzSizeX(x);
}
void MOLLEROptDetector::SetQuartzSizeY(G4double y)
{
  if(Quartz) Quartz->SetQuartzSizeY(y);
}				       
void MOLLEROptDetector::SetQuartzSizeZ(G4double z)
{
  if(Quartz) Quartz->SetQuartzSizeZ(z);
}				       
void MOLLEROptDetector::SetLowerInterfacePlane(G4double LowerPlane)
{
  if(LightGuide) LightGuide->SetLowerInterfacePlane(LowerPlane);
}
void MOLLEROptDetector::SetMiddleBoxHeight(G4double MiddlePlane)
{
  if(LightGuide) LightGuide->SetMiddleBoxHeight(MiddlePlane);
}
void MOLLEROptDetector::SetUpperInterfacePlane(G4double UpperPlane)
{
  if(LightGuide) LightGuide->SetUpperInterfacePlane(UpperPlane); 
}
void MOLLEROptDetector::SetLowerConeFrontFaceAngle(G4double angle)
{
  if(LightGuide) LightGuide->SetLowerConeFrontFaceAngle(angle);
}
void MOLLEROptDetector::SetLowerConeBackFaceAngle(G4double angle)
{
  if(LightGuide) LightGuide->SetLowerConeBackFaceAngle(angle);
}
void MOLLEROptDetector::SetLowerConeSideFaceAngle(G4double angle)
{  
  if(LightGuide) LightGuide->SetLowerConeSideFaceAngle(angle);
}
void MOLLEROptDetector::SetQuartzInterfaceOpeningZ(G4double size)
{
  if(LightGuide) LightGuide->SetQuartzInterfaceOpeningZ(size);
}
void MOLLEROptDetector::SetQuartzInterfaceOpeningX(G4double size)
{
  if(LightGuide) LightGuide->SetQuartzInterfaceOpeningX(size);
}
void MOLLEROptDetector::SetQuartzToPMTOffsetInZ(G4double val)
{
  PMTToQuartzOffset = val;
  if(LightGuide) LightGuide->SetQuartzToPMTOffsetInZ(val);
  if(PMT) PMT->SetCenterPositionInZ(val);
}


void MOLLEROptDetector::UpdateThisGeometry()
{
  G4LogicalVolume *mLog;

  G4GeometryManager::GetInstance()->OpenGeometry();
  
  delete DetPhysical;
  RotationDet->rotateZ(AzimuAngle);
  RotationDet->rotateX(PolarAngle);
  PMT->UpdateGeometry();
  Quartz->UpdateGeometry();
  LightGuide->UpdateGeometry();
  CalculateDimensions();
  DetSolid = new G4Box(DetType+"_Solid",
		        DetFullLengthX, 
		        DetFullLengthY,
		        DetFullLengthZ);
  DetLogical = new G4LogicalVolume(DetSolid, VolMaterial, DetType+"_Logical");
  DetLogical->SetSolid(DetSolid);
  ResetCenterLocation();
  ConstructDetector(MotherVolume);
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
   
}

void MOLLEROptDetector::CalculateDimensions()
{
  if(LightGuide->GetLightGuideWidth() > 2*PMT->GetRadius())
    DetFullLengthX = LightGuide->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX = 2*PMT->GetRadius() +1.0*cm;
  
  if(LightGuide->GetLightGuideDepth() > 2*PMT->GetRadius())
    DetFullLengthZ = LightGuide->GetLightGuideDepth() + 2*PMTToQuartzOffset + 4.0*cm;
  else
    DetFullLengthZ = 2*PMT->GetRadius() + 2*PMTToQuartzOffset + 4.0*cm;
  
  DetFullLengthY = Quartz->GetQuartzSizeY()+LightGuide->GetLightGuideLength()+PMT->GetPMTLength()+1.0*cm+LightGuide->GetCurrentMiddleBoxHeight();
}

void MOLLEROptDetector::ResetCenterLocation()
{

  /*PositionDet.setX(0.0*cm);
  PositionDet.setY(0.0*cm);
  PositionDet.setZ(0.0*cm);*/

}

void MOLLEROptDetector::Initialize()
{
  //let these objects setup their default solids and logical volumes
  PMTToQuartzOffset = 0;
  AzimuAngle = 0; 
  PolarAngle = 0;
  Quartz->Initialize();
  LightGuide->Initialize(LightGuideMat);
  PMT->Initialize();
  
  CalculateDimensions();
  ResetCenterLocation();

  RotationDet = new G4RotationMatrix;

  DetSolid = new G4Box(DetType+"_Solid",
		        DetFullLengthX, 
		        DetFullLengthY,
		        DetFullLengthZ);
  DetLogical = new G4LogicalVolume(DetSolid, VolMaterial, DetType+"_Logical");
}

G4VPhysicalVolume* MOLLEROptDetector::ConstructDetector(G4VPhysicalVolume* Mother)
{
  if(!Mother) return 0;
  
  if(!MotherVolume){
    MotherVolume = Mother;
  }

  DetPhysical = new G4PVPlacement(RotationDet,
				  PositionDet,   
				  DetType+"_Physical",
				  DetLogical,
				  MotherVolume,false,1);
  
  G4double quartzY = Quartz->GetQuartzSizeY();
  G4double quartzZ = Quartz->GetQuartzSizeZ();  
  G4double lguideY = LightGuide->GetCurrentUpperInterfacePlane();
  G4double Offset  = LightGuide->GetCurrentQuartzToPMTOffsetInZ();

  G4double Qrot = Quartz->GetQuartzRotationX();
     
  //Ring
  Quartz->Construct(DetPhysical);
  Quartz->SetCenterPositionInX(PositionDetX);
  Quartz->SetCenterPositionInZ(0.5*quartzY*(TMath::Sin(Qrot)) + PositionDetZ);
  Quartz->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + PositionDetY);
  LightGuide->Construct(DetPhysical);
  LightGuide->SetCenterPositionInX(PositionDetX);
  LightGuide->SetCenterPositionInZ(PositionDetZ);  
  LightGuide->SetCenterPositionInY(-0.5*DetFullLengthY+quartzY + PositionDetY);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT->SetCenterPositionInX(PositionDetX);
  PMT->SetCenterPositionInZ(PositionDetZ+Offset);    
  PMT->SetCenterPositionInY(-0.5*DetFullLengthY+quartzY+lguideY+PMT->GetPMTLength()/2.0 + LightGuide->GetCurrentMiddleBoxHeight() + PositionDetY);

  //-----------------------------------------------------//

  G4Colour  grey      ( 127/255., 127/255., 127/255.);
  G4VisAttributes *att = new G4VisAttributes(grey);
  att->SetVisibility(false);
  att->SetForceWireframe(true);
  DetLogical->SetVisAttributes(att);

  if(!detMessenger)
    detMessenger = new MOLLEROptDetectorMessenger(this,DetType); 
  //G4cout << "A detector messenger has been made" << G4endl;


  return DetPhysical;
} 


//Ring objects
void MOLLEROptDetector::SetCenterPositionInX(G4double xPos)
{
    PositionDetX = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX,
					      PositionDetY, 
					      PositionDetZ));
}

void MOLLEROptDetector::SetCenterPositionInY(G4double yPos)
{
    PositionDetY = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX,
					      PositionDetY, 
					      PositionDetZ));
}

void MOLLEROptDetector::SetCenterPositionInZ(G4double zPos)
{
    PositionDetZ = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX,
					      PositionDetY, 
					      PositionDetZ));
}

//General objects (with edits)
void MOLLEROptDetector::SetLightGuideOffsetInX(G4double x)
{
  G4double cX;

  if(LightGuide &&  PMT){
    cX = LightGuide->GetCurrentCenterPositionInX() + x*cm;
    LightGuide->SetCenterPositionInX(cX);
    cX = PMT->GetCurrentCenterPositionInX() + x*cm;
    PMT->SetCenterPositionInX(cX);
  }
}

void MOLLEROptDetector::SetLightGuideOffsetInY(G4double y)
{
  G4double cY;
  
  if(LightGuide &&  PMT){
    cY = LightGuide->GetCurrentCenterPositionInY() + y*cm;
    LightGuide->SetCenterPositionInY(cY);
    cY = PMT->GetCurrentCenterPositionInY() + y*cm;
    PMT->SetCenterPositionInY(cY);
  }
}

void MOLLEROptDetector::SetLightGuideOffsetInZ(G4double z)
{
  G4double cZ;
  
  if(LightGuide &&  PMT){
    cZ = LightGuide->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide->SetCenterPositionInZ(cZ);
    cZ = PMT->GetCurrentCenterPositionInZ() + z*cm;
    PMT->SetCenterPositionInZ(cZ);
  }
}

void MOLLEROptDetector::GetQuartzLimits(G4double *vals)
{
  Quartz->GetQuartzLimits(vals);
}

void MOLLEROptDetector::GetLightGuideLimits(G4double *vals)
{
  LightGuide->GetLightGuideLimits(vals);
}

void MOLLEROptDetector::SetMaterial(G4String materialName)
{
  VolMaterial = Materials->GetMaterial(materialName);
}

