#include "MOLLEROptDetector.hh"

MOLLEROptDetector::MOLLEROptDetector(MOLLEROptTrackingReadout *TrRO, G4String name, MOLLEROptMaterial* mat, G4String lgmat)
{	    	    
  TrackingReadout = TrRO;
  DetType = name; // name should be set in construction.cc to distinguish SD's in the individual parts files (quartz, pmt, etc)
  Materials = mat;
  LightGuideMat = lgmat;
  VolMaterial = Materials->GetMaterial("Air");  

  Quartz1 = new MOLLEROptDetectorQuartz(TrackingReadout,name,Materials);
  Quartz2 = new MOLLEROptDetectorQuartz(TrackingReadout,name,Materials);
  Quartz3 = new MOLLEROptDetectorQuartz(TrackingReadout,name,Materials);
  Quartz4 = new MOLLEROptDetectorQuartz(TrackingReadout,name,Materials);
  Tungsten1 = new MOLLEROptDetectorTungsten(name,Materials);
  Tungsten2 = new MOLLEROptDetectorTungsten(name,Materials);
  Tungsten3 = new MOLLEROptDetectorTungsten(name,Materials);
  Tungsten4 = new MOLLEROptDetectorTungsten(name,Materials);
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
  delete Quartz1;
  delete Quartz2;
  delete Quartz3;
  delete Quartz4;
  delete Tungsten1;
  delete Tungsten2;
  delete Tungsten3;
  delete Tungsten4;
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
void MOLLEROptDetector::SetYawRotationAngle(G4double val)
{
  YawAngle = val;
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
  if(Quartz1) Quartz1->SetQuartzRotX(rX);
  if(Quartz2) Quartz2->SetQuartzRotX(rX);
  if(Quartz3) Quartz3->SetQuartzRotX(rX);
  if(Quartz4) Quartz4->SetQuartzRotX(rX);
}
void MOLLEROptDetector::SetQuartzSizeX(G4double x)
{
  if(Quartz1) Quartz1->SetQuartzSizeX(x);
  if(Quartz2) Quartz2->SetQuartzSizeX(x);
  if(Quartz3) Quartz3->SetQuartzSizeX(x);
  if(Quartz4) Quartz4->SetQuartzSizeX(x);
}
void MOLLEROptDetector::SetQuartzSizeY(G4double y)
{
  if(Quartz1) Quartz1->SetQuartzSizeY(y);
  if(Quartz2) Quartz2->SetQuartzSizeY(y);
  if(Quartz3) Quartz3->SetQuartzSizeY(y);
  if(Quartz4) Quartz4->SetQuartzSizeY(y);
}				       
void MOLLEROptDetector::SetQuartzSizeZ(G4double z)
{
  if(Quartz1) Quartz1->SetQuartzSizeZ(z);
  if(Quartz2) Quartz2->SetQuartzSizeZ(z);
  if(Quartz3) Quartz3->SetQuartzSizeZ(z);
  if(Quartz4) Quartz4->SetQuartzSizeZ(z);
}
void MOLLEROptDetector::SetTungstenSizeX(G4double x)
{
  if(Tungsten1) Tungsten1->SetSizeX(x);
  if(Tungsten2) Tungsten2->SetSizeX(x);
  if(Tungsten3) Tungsten3->SetSizeX(x);
  if(Tungsten4) Tungsten4->SetSizeX(x);
}void MOLLEROptDetector::SetTungstenSizeY(G4double y)
{
  if(Tungsten1) Tungsten1->SetSizeY(y);
  if(Tungsten2) Tungsten2->SetSizeY(y);
  if(Tungsten3) Tungsten3->SetSizeY(y);
  if(Tungsten4) Tungsten4->SetSizeY(y);
}
void MOLLEROptDetector::SetTungstenSizeZ(G4double z)
{
  if(Tungsten1) Tungsten1->SetSizeZ(z);
  if(Tungsten2) Tungsten2->SetSizeZ(z);
  if(Tungsten3) Tungsten3->SetSizeZ(z);
  if(Tungsten4) Tungsten4->SetSizeZ(z);
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
  RotationDet->rotateY(YawAngle);

  Quartz1->UpdateGeometry("DS");
  Quartz2->UpdateGeometry("US");
  Quartz3->UpdateGeometry("DS");
  Quartz4->UpdateGeometry("US");
  Tungsten1->UpdateGeometry();
  Tungsten2->UpdateGeometry();
  Tungsten3->UpdateGeometry();
  Tungsten4->UpdateGeometry();
  LightGuide->UpdateGeometry();
  PMT->UpdateGeometry();

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
    DetFullLengthX = LightGuide->GetLightGuideWidth() - 4*cm;
  else
    DetFullLengthX = 2*PMT->GetRadius() - 4.0*cm;
  
  if(LightGuide->GetLightGuideDepth() > 2*PMT->GetRadius())
    DetFullLengthZ = LightGuide->GetLightGuideDepth() + 2*PMTToQuartzOffset - 1.0*cm;
  else
    DetFullLengthZ = 2*PMT->GetRadius() + 2*PMTToQuartzOffset - 1.0*cm;
  
  DetFullLengthY = Quartz1->GetQuartzSizeY()+LightGuide->GetLightGuideLength()+PMT->GetPMTLength()+1.0*cm+LightGuide->GetCurrentMiddleBoxHeight();
}

void MOLLEROptDetector::ResetCenterLocation()
{

  PositionDet.setX(PositionDetX);
  PositionDet.setY(PositionDetY);
  PositionDet.setZ(PositionDetZ);

}

void MOLLEROptDetector::Initialize()
{
  //let these objects setup their default solids and logical volumes
  PMTToQuartzOffset = 0;
  AzimuAngle = 0; 
  PolarAngle = 0;
  YawAngle = 0;

  Quartz1->Initialize("DS");
  Quartz2->Initialize("US");
  Quartz3->Initialize("DS");
  Quartz4->Initialize("US");

  Tungsten1->Initialize();
  Tungsten2->Initialize();
  Tungsten3->Initialize();
  Tungsten4->Initialize();

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
  
  G4double quartzY = Quartz1->GetQuartzSizeY();
  G4double quartzZ = Quartz1->GetQuartzSizeZ();
  G4double Qrot = Quartz1->GetQuartzRotationX();
  G4double tungstenY = Tungsten1->GetSizeY();
  G4double tungstenZ = Tungsten1->GetSizeZ();
  G4double lguideY = LightGuide->GetCurrentUpperInterfacePlane();
  G4double Offset  = LightGuide->GetCurrentQuartzToPMTOffsetInZ();
  G4double lguideOpeningZ = LightGuide->GetCurrentLightGuideQuartzInterfaceOpeningZ();
  G4double lguideThickness = 1.0*mm;
  G4double WrapperThickness = 0.870*mm;
  G4double Qgap = quartzZ + 2.0*WrapperThickness + tungstenZ;
     
  //Detector positioning
  Quartz1->Construct(DetPhysical);
  Quartz1->SetCenterPositionInX(0);
  Quartz1->SetCenterPositionInZ(0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)));
  Quartz1->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)));
  Quartz2->Construct(DetPhysical);
  Quartz2->SetCenterPositionInX(0);
  Quartz2->SetCenterPositionInZ(0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + Qgap*(TMath::Cos(Qrot)));
  Quartz2->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + Qgap*(TMath::Sin(Qrot)));
  Quartz3->Construct(DetPhysical);
  Quartz3->SetCenterPositionInX(0);
  Quartz3->SetCenterPositionInZ(0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + 2*Qgap*(TMath::Cos(Qrot)));
  Quartz3->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + 2*Qgap*(TMath::Sin(Qrot)));
  Quartz4->Construct(DetPhysical);
  Quartz4->SetCenterPositionInX(0);
  Quartz4->SetCenterPositionInZ(0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + 3*Qgap*(TMath::Cos(Qrot)));
  Quartz4->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + 3*Qgap*(TMath::Sin(Qrot)));

  Tungsten1->Construct(DetPhysical);
  Tungsten1->SetCenterPositionInX(0);
  Tungsten1->SetCenterPositionInZ(0.5*tungstenY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ + Qgap - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)));
  Tungsten1->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*tungstenY + 0.5*tungstenY*(1.0-TMath::Cos(Qrot)) + 0.5*tungstenZ*fabs(TMath::Sin(Qrot)));
  Tungsten2->Construct(DetPhysical);
  Tungsten2->SetCenterPositionInX(0);
  Tungsten2->SetCenterPositionInZ(0.5*tungstenY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ + Qgap - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + Qgap*(TMath::Cos(Qrot)));
  Tungsten2->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*tungstenY + 0.5*tungstenY*(1.0-TMath::Cos(Qrot)) + 0.5*tungstenZ*fabs(TMath::Sin(Qrot)) + Qgap*(TMath::Sin(Qrot)));
  Tungsten3->Construct(DetPhysical);
  Tungsten3->SetCenterPositionInX(0);
  Tungsten3->SetCenterPositionInZ(0.5*tungstenY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ + Qgap - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + 2*Qgap*(TMath::Cos(Qrot)));
  Tungsten3->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*tungstenY + 0.5*tungstenY*(1.0-TMath::Cos(Qrot)) + 0.5*tungstenZ*fabs(TMath::Sin(Qrot)) + 2*Qgap*(TMath::Sin(Qrot)));
  Tungsten4->Construct(DetPhysical);
  Tungsten4->SetCenterPositionInX(0);
  Tungsten4->SetCenterPositionInZ(0.5*tungstenY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ + Qgap - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)) + 3*Qgap*(TMath::Cos(Qrot)));
  Tungsten4->SetCenterPositionInY(-0.5*DetFullLengthY + 0.5*tungstenY + 0.5*tungstenY*(1.0-TMath::Cos(Qrot)) + 0.5*tungstenZ*fabs(TMath::Sin(Qrot)) + 3*Qgap*(TMath::Sin(Qrot)));


  LightGuide->Construct(DetPhysical);
  LightGuide->SetCenterPositionInX(0);
  LightGuide->SetCenterPositionInZ(0);  
  LightGuide->SetCenterPositionInY(-0.5*DetFullLengthY + quartzY + Quartz1->GetQuartzSizeZ() + 4.24*mm);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT->SetCenterPositionInX(0);
  PMT->SetCenterPositionInZ(Offset);    
  PMT->SetCenterPositionInY(-0.5*DetFullLengthY+quartzY+lguideY+PMT->GetPMTLength()/2.0 + LightGuide->GetCurrentMiddleBoxHeight() + Quartz1->GetQuartzSizeZ() + 4.24* mm + 1.495*mm);

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
  //G4double quartzX = Quartz1->GetQuartzSizeX();
  G4double quartzY = Quartz1->GetQuartzSizeY();
  G4double quartzZ = Quartz1->GetQuartzSizeZ();
  G4double Qrot = Quartz1->GetQuartzRotationX();
  G4double tungstenY = Tungsten1->GetSizeY();
  G4double tungstenZ = Tungsten1->GetSizeZ();
  G4double QPol = PolarAngle;
  G4double lguideOpeningZ = LightGuide->GetCurrentLightGuideQuartzInterfaceOpeningZ();
  G4double lguideThickness = 1.0*mm;
  G4double WrapperThickness = 0.870*mm;
  G4double Qgap = quartzZ + 2.0*WrapperThickness + tungstenZ;
  //G4double QYaw = YawAngle; //Not accounted for in QuartzPos.setX or setZ. Should be, but not important currently
  //G4double QAzi = AzimuAngle;

  //Factor is from the rotation of the quartz about the x-axis independent of the detector
  G4double yRotFactor = 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot));

  Quartz1Pos.setX(PositionDetX);
  Quartz1Pos.setY(PositionDetY - 0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)));
  Quartz1Pos.setZ(PositionDetZ + 0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ - lguideThickness)*(1-TMath::Sin(Qrot)));//This is missing factors, but is not currently used
  /*Quartz2Pos.setX(PositionDetX);
  Quartz2Pos.setY(PositionDetY - 0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + Qgap*(TMath::Sin(Qrot)));
  Quartz2Pos.setZ(PositionDetZ + 0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ)*(1-TMath::Sin(Qrot)) + Qgap*(TMath::Cos(Qrot)));//This is missing factors, but is not currently used
  Quartz3Pos.setX(PositionDetX);
  Quartz3Pos.setY(PositionDetY - 0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + 2*Qgap*(TMath::Sin(Qrot)));
  Quartz3Pos.setZ(PositionDetZ + 0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ)*(1-TMath::Sin(Qrot)) + 2*Qgap*(TMath::Cos(Qrot)));//This is missing factors, but is not currently used
  Quartz4Pos.setX(PositionDetX);
  Quartz4Pos.setY(PositionDetY - 0.5*DetFullLengthY + 0.5*quartzY + 0.5*quartzY*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ*fabs(TMath::Sin(Qrot)) + 3*Qgap*(TMath::Sin(Qrot)));
  Quartz4Pos.setZ(PositionDetZ + 0.5*quartzY*(TMath::Sin(Qrot)) - 0.5*(lguideOpeningZ - quartzZ)*(1-TMath::Sin(Qrot)) + 3*Qgap*(TMath::Cos(Qrot)));//This is missing factors, but is not currently used
  */
  
  Quartz1->GetQuartzLimits(vals,Quartz1Pos);
  /*Quartz2->GetQuartzLimits(vals,Quartz2Pos);
  Quartz3->GetQuartzLimits(vals,Quartz3Pos);
  Quartz4->GetQuartzLimits(vals,Quartz4Pos);
  */
}

void MOLLEROptDetector::GetLightGuideLimits(G4double *vals)
{
  LightGuide->GetLightGuideLimits(vals);
}

void MOLLEROptDetector::SetMaterial(G4String materialName)
{
  VolMaterial = Materials->GetMaterial(materialName);
}

