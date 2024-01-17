#include "MOLLEROptDetector.hh"

MOLLEROptDetector::MOLLEROptDetector(MOLLEROptTrackingReadout *TrRO, G4String type1, G4String type2, G4String type3, G4String type4, G4String type5, G4String type6, G4String type7, G4String type8, G4String type9, MOLLEROptMaterial* mat)
{	    	    
  TrackingReadout = TrRO;
  DetType1 = type1;
  DetType2 = type2;
  DetType3 = type3;
  DetType4 = type4;
  DetType5 = type5;
  DetType6 = type6;
  DetType7 = type7;
  DetType8 = type8;
  DetType9 = type9;
  Materials = mat;
  DetMaterial = Materials->GetMaterial("Air");  

  Quartz1 = new  MOLLEROptDetectorQuartz(TrackingReadout,type1,Materials);
  LightGuide1 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type1,Materials);
  PMT1 = new  MOLLEROptDetectorPMT(TrackingReadout,type1,Materials,LightGuide1);

  Quartz2 = new  MOLLEROptDetectorQuartz2(TrackingReadout,type2,Materials);
  LightGuide2 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type2,Materials);
  PMT2 = new  MOLLEROptDetectorPMT(TrackingReadout,type2,Materials,LightGuide2);

  Quartz3 = new  MOLLEROptDetectorQuartz3(TrackingReadout,type3,Materials);
  LightGuide3 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type3,Materials);
  PMT3 = new  MOLLEROptDetectorPMT(TrackingReadout,type3,Materials,LightGuide3);

  Quartz4 = new  MOLLEROptDetectorQuartz4(TrackingReadout,type4,Materials);
  LightGuide4 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type4,Materials);
  PMT4 = new  MOLLEROptDetectorPMT(TrackingReadout,type4,Materials,LightGuide4);

  Quartz5 = new  MOLLEROptDetectorQuartz5(TrackingReadout,type5,Materials);
  LightGuide5 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type5,Materials);
  PMT5 = new  MOLLEROptDetectorPMT(TrackingReadout,type5,Materials,LightGuide5);

  Quartz6 = new  MOLLEROptDetectorQuartz6(TrackingReadout,type6,Materials);
  LightGuide6 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type6,Materials);
  PMT6 = new  MOLLEROptDetectorPMT(TrackingReadout,type6,Materials,LightGuide6);

  Quartz7 = new  MOLLEROptDetectorQuartz7(TrackingReadout,type7,Materials);
  LightGuide7 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type7,Materials);
  PMT7 = new  MOLLEROptDetectorPMT(TrackingReadout,type7,Materials,LightGuide7);

  Quartz8 = new  MOLLEROptDetectorQuartz8(TrackingReadout,type8,Materials);
  LightGuide8 = new  MOLLEROptDetectorLightGuide(TrackingReadout,type8,Materials);
  PMT8 = new  MOLLEROptDetectorPMT(TrackingReadout,type8,Materials,LightGuide8);

  Scintillator = new  MOLLEROptDetectorScintillator(TrackingReadout,type9,Materials);

  detMessenger = NULL;

  MotherVolume = NULL;
  
  DetLogical  = NULL;
  DetPhysical = NULL;
  DetSolid = NULL;

  RotationDet = NULL;

  fReadFile ="../data/December2021/GDML/Ring5/R5-Module-Al.gdml";
  fWriteFile="wtest.gdml";
  // fStepFile ="mbb";


}

MOLLEROptDetector::~MOLLEROptDetector()
{
  delete Quartz1;
  delete LightGuide1;
  delete PMT1;

  delete Quartz2;
  delete LightGuide2;
  delete PMT2;

  delete Quartz3;
  delete LightGuide3;
  delete PMT3;

  delete Quartz4;
  delete LightGuide4;
  delete PMT4;

  delete Quartz5;
  delete LightGuide5;
  delete PMT5;

  delete Quartz6;
  delete LightGuide6;
  delete PMT6;

  delete Quartz7;
  delete LightGuide7;
  delete PMT7;

  delete Quartz8;
  delete LightGuide8;
  delete PMT8;

  delete Scintillator;

}

//General Ring objects

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
  if(PMT1)
    PMT1->SetCathodeThickness(val);
  if(PMT2)
    PMT2->SetCathodeThickness(val);
  if(PMT3)
    PMT3->SetCathodeThickness(val);
  if(PMT4)
    PMT4->SetCathodeThickness(val);
  if(PMT5)
    PMT5->SetCathodeThickness(val);
  if(PMT6)
    PMT6->SetCathodeThickness(val);
  if(PMT7)
    PMT7->SetCathodeThickness(val);
  if(PMT8)
    PMT8->SetCathodeThickness(val);
}

void MOLLEROptDetector::SetPMTCathodeRadius(G4double val)
{
  if(PMT1)
    PMT1->SetCathodeRadius(val);
  if(LightGuide1)
    LightGuide1->SetPMTOpeningRadius(val);
  if(PMT2)
    PMT2->SetCathodeRadius(val);
  if(LightGuide2)
    LightGuide2->SetPMTOpeningRadius(val);
  if(PMT3)
    PMT3->SetCathodeRadius(val);
  if(LightGuide3)
    LightGuide3->SetPMTOpeningRadius(val);
  if(PMT4)
    PMT4->SetCathodeRadius(val);
  if(LightGuide4)
    LightGuide4->SetPMTOpeningRadius(val);
  if(PMT5)
    PMT5->SetCathodeRadius(val);
  if(LightGuide5)
    LightGuide5->SetPMTOpeningRadius(val);
  if(PMT6)
    PMT6->SetCathodeRadius(val);
  if(LightGuide6)
    LightGuide6->SetPMTOpeningRadius(val);
  if(PMT7)
    PMT7->SetCathodeRadius(val);
  if(LightGuide7)
    LightGuide7->SetPMTOpeningRadius(val);
  if(PMT8)
    PMT8->SetCathodeRadius(val);
  if(LightGuide8)
    LightGuide8->SetPMTOpeningRadius(val);
}

void MOLLEROptDetector::SetPMTInterfaceOpeningZ(G4double size)
{
  if(LightGuide1)
    LightGuide1->SetPMTInterfaceOpeningZ(size);
  if(PMT1)
    PMT1->SetLGInterfaceOpeningZ(size);
  if(LightGuide2)
    LightGuide2->SetPMTInterfaceOpeningZ(size);
  if(PMT2)
    PMT2->SetLGInterfaceOpeningZ(size);
  if(LightGuide3)
    LightGuide3->SetPMTInterfaceOpeningZ(size);
  if(PMT3)
    PMT3->SetLGInterfaceOpeningZ(size);
  if(LightGuide4)
    LightGuide4->SetPMTInterfaceOpeningZ(size);
  if(PMT4)
    PMT4->SetLGInterfaceOpeningZ(size);
  if(LightGuide5)
    LightGuide5->SetPMTInterfaceOpeningZ(size);
  if(PMT5)
    PMT5->SetLGInterfaceOpeningZ(size);
  if(LightGuide6)
    LightGuide6->SetPMTInterfaceOpeningZ(size);
  if(PMT6)
    PMT6->SetLGInterfaceOpeningZ(size);
  if(LightGuide7)
    LightGuide7->SetPMTInterfaceOpeningZ(size);
  if(PMT7)
    PMT7->SetLGInterfaceOpeningZ(size);
  if(LightGuide8)
    LightGuide8->SetPMTInterfaceOpeningZ(size);
  if(PMT8)
    PMT8->SetLGInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetPMTInterfaceOpeningX(G4double size)
{
  if(LightGuide1)
    LightGuide1->SetPMTInterfaceOpeningX(size);
  if(PMT1)
    PMT1->SetLGInterfaceOpeningX(size);
  if(LightGuide2)
    LightGuide2->SetPMTInterfaceOpeningX(size);
  if(PMT2)
    PMT2->SetLGInterfaceOpeningX(size);
  if(LightGuide3)
    LightGuide3->SetPMTInterfaceOpeningX(size);
  if(PMT3)
    PMT3->SetLGInterfaceOpeningX(size);
  if(LightGuide4)
    LightGuide4->SetPMTInterfaceOpeningX(size);
  if(PMT4)
    PMT4->SetLGInterfaceOpeningX(size);
  if(LightGuide5)
    LightGuide5->SetPMTInterfaceOpeningX(size);
  if(PMT5)
    PMT5->SetLGInterfaceOpeningX(size);
  if(LightGuide6)
    LightGuide6->SetPMTInterfaceOpeningX(size);
  if(PMT6)
    PMT6->SetLGInterfaceOpeningX(size);
  if(LightGuide7)
    LightGuide7->SetPMTInterfaceOpeningX(size);
  if(PMT7)
    PMT7->SetLGInterfaceOpeningX(size);
  if(LightGuide8)
    LightGuide8->SetPMTInterfaceOpeningX(size);
  if(PMT8)
    PMT8->SetLGInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzRotX(G4double rX)
{
  if(Quartz1)
    Quartz1->SetQuartzRotX(rX);
  if(Quartz2)
    Quartz2->SetQuartzRotX(rX);
  if(Quartz3)
    Quartz3->SetQuartzRotX(rX);
  if(Quartz4)
    Quartz4->SetQuartzRotX(rX);
  if(Quartz5)
    Quartz5->SetQuartzRotX(rX);
  if(Quartz6)
    Quartz6->SetQuartzRotX(rX);
  if(Quartz7)
    Quartz7->SetQuartzRotX(rX);
  if(Quartz8)
    Quartz8->SetQuartzRotX(rX);
}


//Ring 1 objects


void MOLLEROptDetector::SetQuartzSizeX1(G4double x)
{
  if(Quartz1)
    Quartz1->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY1(G4double y)
{
  if(Quartz1)
    Quartz1->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ1(G4double z)
{
  if(Quartz1)
    Quartz1->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane1(G4double LowerPlane)
{
  if(LightGuide1)
    LightGuide1->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight1(G4double MiddlePlane)
{
  if(LightGuide1)
    LightGuide1->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane1(G4double UpperPlane)
{
  if(LightGuide1)
    LightGuide1->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle1(G4double angle)
{
  if(LightGuide1)
    LightGuide1->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle1(G4double angle)
{
  if(LightGuide1)
    LightGuide1->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle1(G4double angle)
{  
  if(LightGuide1)
    LightGuide1->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ1(G4double size)
{
  if(LightGuide1)
    LightGuide1->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX1(G4double size)
{
  if(LightGuide1)
    LightGuide1->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ1(G4double val)
{
  PMTToQuartzOffset1 = val;
  if(LightGuide1)
    LightGuide1->SetQuartzToPMTOffsetInZ(val);
  if(PMT1)
    PMT1->SetCenterPositionInZ(val);
}


//Ring 2 objects


void MOLLEROptDetector::SetQuartzSizeX2(G4double x)
{
  if(Quartz2)
    Quartz2->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY2(G4double y)
{
  if(Quartz2)
    Quartz2->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ2(G4double z)
{
  if(Quartz2)
    Quartz2->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane2(G4double LowerPlane)
{
  if(LightGuide2)
    LightGuide2->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight2(G4double MiddlePlane)
{
  if(LightGuide2)
    LightGuide2->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane2(G4double UpperPlane)
{
  if(LightGuide2)
    LightGuide2->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle2(G4double angle)
{
  if(LightGuide2)
    LightGuide2->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle2(G4double angle)
{
  if(LightGuide2)
    LightGuide2->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle2(G4double angle)
{  
  if(LightGuide2)
    LightGuide2->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ2(G4double size)
{
  if(LightGuide2)
    LightGuide2->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX2(G4double size)
{
  if(LightGuide2)
    LightGuide2->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ2(G4double val)
{
  PMTToQuartzOffset2 = val;
  if(LightGuide2)
    LightGuide2->SetQuartzToPMTOffsetInZ(val);
  if(PMT2)
    PMT2->SetCenterPositionInZ(val);
}


//Ring 3 objects


void MOLLEROptDetector::SetQuartzSizeX3(G4double x)
{
  if(Quartz3)
    Quartz3->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY3(G4double y)
{
  if(Quartz3)
    Quartz3->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ3(G4double z)
{
  if(Quartz3)
    Quartz3->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane3(G4double LowerPlane)
{
  if(LightGuide3)
    LightGuide3->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight3(G4double MiddlePlane)
{
  if(LightGuide3)
    LightGuide3->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane3(G4double UpperPlane)
{
  if(LightGuide3)
    LightGuide3->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle3(G4double angle)
{
  if(LightGuide3)
    LightGuide3->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle3(G4double angle)
{
  if(LightGuide3)
    LightGuide3->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle3(G4double angle)
{  
  if(LightGuide3)
    LightGuide3->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ3(G4double size)
{
  if(LightGuide3)
    LightGuide3->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX3(G4double size)
{
  if(LightGuide3)
    LightGuide3->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ3(G4double val)
{
  PMTToQuartzOffset3 = val;
  if(LightGuide3)
    LightGuide3->SetQuartzToPMTOffsetInZ(val);
  if(PMT3)
    PMT3->SetCenterPositionInZ(val);
}

//Ring 4 objects


void MOLLEROptDetector::SetQuartzSizeX4(G4double x)
{
  if(Quartz4)
    Quartz4->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY4(G4double y)
{
  if(Quartz4)
    Quartz4->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ4(G4double z)
{
  if(Quartz4)
    Quartz4->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane4(G4double LowerPlane)
{
  if(LightGuide4)
    LightGuide4->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight4(G4double MiddlePlane)
{
  if(LightGuide4)
    LightGuide4->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane4(G4double UpperPlane)
{
  if(LightGuide4)
    LightGuide4->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle4(G4double angle)
{
  if(LightGuide4)
    LightGuide4->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle4(G4double angle)
{
  if(LightGuide4)
    LightGuide4->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle4(G4double angle)
{  
  if(LightGuide4)
    LightGuide4->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ4(G4double size)
{
  if(LightGuide4)
    LightGuide4->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX4(G4double size)
{
  if(LightGuide4)
    LightGuide4->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ4(G4double val)
{
  PMTToQuartzOffset4 = val;
  if(LightGuide4)
    LightGuide4->SetQuartzToPMTOffsetInZ(val);
  if(PMT4)
    PMT4->SetCenterPositionInZ(val);
}

//Ring 5 objects


void MOLLEROptDetector::SetQuartzSizeX5(G4double x)
{
  if(Quartz5)
    Quartz5->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY5(G4double y)
{
  if(Quartz5)
    Quartz5->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ5(G4double z)
{
  if(Quartz5)
    Quartz5->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane5(G4double LowerPlane)
{
  if(LightGuide5)
    LightGuide5->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight5(G4double MiddlePlane)
{
  if(LightGuide5)
    LightGuide5->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane5(G4double UpperPlane)
{
  if(LightGuide5)
    LightGuide5->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle5(G4double angle)
{
  if(LightGuide5)
    LightGuide5->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle5(G4double angle)
{
  if(LightGuide5)
    LightGuide5->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle5(G4double angle)
{  
  if(LightGuide5)
    LightGuide5->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ5(G4double size)
{
  if(LightGuide5)
    LightGuide5->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX5(G4double size)
{
  if(LightGuide5)
    LightGuide5->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ5(G4double val)
{
  PMTToQuartzOffset5 = val;
  if(LightGuide5)
    LightGuide5->SetQuartzToPMTOffsetInZ(val);
  if(PMT5)
    PMT5->SetCenterPositionInZ(val);
}


//Ring 6 objects


void MOLLEROptDetector::SetQuartzSizeX6(G4double x)
{
  if(Quartz6)
    Quartz6->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY6(G4double y)
{
  if(Quartz6)
    Quartz6->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ6(G4double z)
{
  if(Quartz6)
    Quartz6->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane6(G4double LowerPlane)
{
  if(LightGuide6)
    LightGuide6->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight6(G4double MiddlePlane)
{
  if(LightGuide6)
    LightGuide6->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane6(G4double UpperPlane)
{
  if(LightGuide6)
    LightGuide6->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle6(G4double angle)
{
  if(LightGuide6)
    LightGuide6->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle6(G4double angle)
{
  if(LightGuide6)
    LightGuide6->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle6(G4double angle)
{  
  if(LightGuide6)
    LightGuide6->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ6(G4double size)
{
  if(LightGuide6)
    LightGuide6->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX6(G4double size)
{
  if(LightGuide6)
    LightGuide6->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ6(G4double val)
{
  PMTToQuartzOffset6 = val;
  if(LightGuide6)
    LightGuide6->SetQuartzToPMTOffsetInZ(val);
  if(PMT6)
    PMT6->SetCenterPositionInZ(val);
}

//Ring 7 objects


void MOLLEROptDetector::SetQuartzSizeX7(G4double x)
{
  if(Quartz7)
    Quartz7->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY7(G4double y)
{
  if(Quartz7)
    Quartz7->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ7(G4double z)
{
  if(Quartz7)
    Quartz7->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane7(G4double LowerPlane)
{
  if(LightGuide7)
    LightGuide7->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight7(G4double MiddlePlane)
{
  if(LightGuide7)
    LightGuide7->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane7(G4double UpperPlane)
{
  if(LightGuide7)
    LightGuide7->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle7(G4double angle)
{
  if(LightGuide7)
    LightGuide7->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle7(G4double angle)
{
  if(LightGuide7)
    LightGuide7->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle7(G4double angle)
{  
  if(LightGuide7)
    LightGuide7->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ7(G4double size)
{
  if(LightGuide7)
    LightGuide7->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX7(G4double size)
{
  if(LightGuide7)
    LightGuide7->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ7(G4double val)
{
  PMTToQuartzOffset7 = val;
  if(LightGuide7)
    LightGuide7->SetQuartzToPMTOffsetInZ(val);
  if(PMT7)
    PMT7->SetCenterPositionInZ(val);
}


//Ring 8 objects


void MOLLEROptDetector::SetQuartzSizeX8(G4double x)
{
  if(Quartz8)
    Quartz8->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetQuartzSizeY8(G4double y)
{
  if(Quartz8)
    Quartz8->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetQuartzSizeZ8(G4double z)
{
  if(Quartz8)
    Quartz8->SetQuartzSizeZ(z);
}
				       
void MOLLEROptDetector::SetLowerInterfacePlane8(G4double LowerPlane)
{
  if(LightGuide8)
    LightGuide8->SetLowerInterfacePlane(LowerPlane);
}

void MOLLEROptDetector::SetMiddleBoxHeight8(G4double MiddlePlane)
{
  if(LightGuide8)
    LightGuide8->SetMiddleBoxHeight(MiddlePlane);
}

void MOLLEROptDetector::SetUpperInterfacePlane8(G4double UpperPlane)
{
  if(LightGuide8)
    LightGuide8->SetUpperInterfacePlane(UpperPlane); 
}

void MOLLEROptDetector::SetLowerConeFrontFaceAngle8(G4double angle)
{
  if(LightGuide8)
    LightGuide8->SetLowerConeFrontFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeBackFaceAngle8(G4double angle)
{
  if(LightGuide8)
    LightGuide8->SetLowerConeBackFaceAngle(angle);
}

void MOLLEROptDetector::SetLowerConeSideFaceAngle8(G4double angle)
{  
  if(LightGuide8)
    LightGuide8->SetLowerConeSideFaceAngle(angle);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningZ8(G4double size)
{
  if(LightGuide8)
    LightGuide8->SetQuartzInterfaceOpeningZ(size);
}

void MOLLEROptDetector::SetQuartzInterfaceOpeningX8(G4double size)
{
  if(LightGuide8)
    LightGuide8->SetQuartzInterfaceOpeningX(size);
}

void MOLLEROptDetector::SetQuartzToPMTOffsetInZ8(G4double val)
{
  PMTToQuartzOffset8 = val;
  if(LightGuide8)
    LightGuide8->SetQuartzToPMTOffsetInZ(val);
  if(PMT8)
    PMT8->SetCenterPositionInZ(val);
}

//Scintillator objects


void MOLLEROptDetector::SetScintillatorSizeX(G4double x)
{
  if(Scintillator)
    Scintillator->SetQuartzSizeX(x);
}

void MOLLEROptDetector::SetScintillatorSizeY(G4double y)
{
  if(Scintillator)
    Scintillator->SetQuartzSizeY(y);
}
				       
void MOLLEROptDetector::SetScintillatorSizeZ(G4double z)
{
  if(Scintillator)
    Scintillator->SetQuartzSizeZ(z);
}


void MOLLEROptDetector::UpdateThisGeometry()
{
  G4LogicalVolume *mLog;

  G4GeometryManager::GetInstance()->OpenGeometry();
  
  delete DetPhysical;
  RotationDet->rotateX(PolarAngle);  
  PMT1->UpdateGeometry();
  Quartz1->UpdateGeometry();
  LightGuide1->UpdateGeometry();
  PMT2->UpdateGeometry();
  Quartz2->UpdateGeometry();
  LightGuide2->UpdateGeometry();
  PMT3->UpdateGeometry();
  Quartz3->UpdateGeometry();
  LightGuide3->UpdateGeometry();
  PMT4->UpdateGeometry();
  Quartz4->UpdateGeometry();
  LightGuide4->UpdateGeometry();
  PMT5->UpdateGeometry();
  Quartz5->UpdateGeometry();
  LightGuide5->UpdateGeometry();
  PMT6->UpdateGeometry();
  Quartz6->UpdateGeometry();
  LightGuide6->UpdateGeometry();
  PMT7->UpdateGeometry();
  Quartz7->UpdateGeometry();
  LightGuide7->UpdateGeometry();
  PMT8->UpdateGeometry();
  Quartz8->UpdateGeometry();
  LightGuide8->UpdateGeometry();
  Scintillator->UpdateGeometry();
  CalculateDimensions();
  DetSolid = new G4Box(DetType1+"_Solid",
		       10* DetFullLengthX1, 
		       10* DetFullLengthY1,
		       20* DetFullLengthZ1);
  DetLogical = new G4LogicalVolume( DetSolid, DetMaterial, DetType1+"_Logical");
  DetLogical->SetSolid(DetSolid);
  ResetCenterLocation();
  ConstructDetector(MotherVolume);
  G4RunManager::GetRunManager()->GeometryHasBeenModified();
   
}

void MOLLEROptDetector::CalculateDimensions()
{
  //Ring 1 
  if(LightGuide1->GetLightGuideWidth() > 2*PMT1->GetRadius())
    DetFullLengthX1 = LightGuide1->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX1 = 2*PMT1->GetRadius() +1.0*cm;
  
  if(LightGuide1->GetLightGuideDepth() > 2*PMT1->GetRadius())
    DetFullLengthZ1 = LightGuide1->GetLightGuideDepth() + 2*PMTToQuartzOffset1 + 4.0*cm;
  else
    DetFullLengthZ1 = 2*PMT1->GetRadius() + 2*PMTToQuartzOffset1 + 4.0*cm;
  
  //Ring 2
  if(LightGuide2->GetLightGuideWidth() > 2*PMT2->GetRadius())
    DetFullLengthX2 = LightGuide2->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX2 = 2*PMT2->GetRadius() +1.0*cm;
  
  if(LightGuide2->GetLightGuideDepth() > 2*PMT2->GetRadius())
    DetFullLengthZ2 = LightGuide2->GetLightGuideDepth() + 2*PMTToQuartzOffset2 + 4.0*cm;
  else
    DetFullLengthZ2 = 2*PMT2->GetRadius() + 2*PMTToQuartzOffset2 + 4.0*cm;
  
  //Ring 3 
  if(LightGuide3->GetLightGuideWidth() > 2*PMT3->GetRadius())
    DetFullLengthX3 = LightGuide3->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX3 = 2*PMT3->GetRadius() +1.0*cm;
  
  if(LightGuide3->GetLightGuideDepth() > 2*PMT3->GetRadius())
    DetFullLengthZ3 = LightGuide3->GetLightGuideDepth() + 2*PMTToQuartzOffset3 + 4.0*cm;
  else
    DetFullLengthZ3 = 2*PMT3->GetRadius() + 2*PMTToQuartzOffset3 + 4.0*cm;
  
  //Ring 4 
  if(LightGuide4->GetLightGuideWidth() > 2*PMT4->GetRadius())
    DetFullLengthX4 = LightGuide4->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX4 = 2*PMT4->GetRadius() +1.0*cm;
  
  if(LightGuide4->GetLightGuideDepth() > 2*PMT4->GetRadius())
    DetFullLengthZ4 = LightGuide4->GetLightGuideDepth() + 2*PMTToQuartzOffset4 + 4.0*cm;
  else
    DetFullLengthZ4 = 2*PMT4->GetRadius() + 2*PMTToQuartzOffset4 + 4.0*cm;
  
  //Ring 5 
  if(LightGuide5->GetLightGuideWidth() > 2*PMT5->GetRadius())
    DetFullLengthX5 = LightGuide5->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX5 = 2*PMT5->GetRadius() +1.0*cm;
  
  if(LightGuide5->GetLightGuideDepth() > 2*PMT5->GetRadius())
    DetFullLengthZ5 = LightGuide5->GetLightGuideDepth() + 2*PMTToQuartzOffset5 + 4.0*cm;
  else
    DetFullLengthZ5 = 2*PMT5->GetRadius() + 2*PMTToQuartzOffset5 + 4.0*cm;
  
  //Ring 6 
  if(LightGuide6->GetLightGuideWidth() > 2*PMT6->GetRadius())
    DetFullLengthX6 = LightGuide6->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX6 = 2*PMT6->GetRadius() +1.0*cm;
  
  if(LightGuide6->GetLightGuideDepth() > 2*PMT6->GetRadius())
    DetFullLengthZ6 = LightGuide6->GetLightGuideDepth() + 2*PMTToQuartzOffset6 + 4.0*cm;
  else
    DetFullLengthZ6 = 2*PMT6->GetRadius() + 2*PMTToQuartzOffset6 + 4.0*cm;
  
  //Ring 7 
  if(LightGuide7->GetLightGuideWidth() > 2*PMT7->GetRadius())
    DetFullLengthX7 = LightGuide7->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX7 = 2*PMT7->GetRadius() +1.0*cm;
  
  if(LightGuide7->GetLightGuideDepth() > 2*PMT7->GetRadius())
    DetFullLengthZ7 = LightGuide7->GetLightGuideDepth() + 2*PMTToQuartzOffset7 + 4.0*cm;
  else
    DetFullLengthZ7 = 2*PMT7->GetRadius() + 2*PMTToQuartzOffset7 + 4.0*cm;

  //Ring 8 
  if(LightGuide8->GetLightGuideWidth() > 2*PMT8->GetRadius())
    DetFullLengthX8 = LightGuide8->GetLightGuideWidth() + 1.0*cm;
  else
    DetFullLengthX8 = 2*PMT8->GetRadius() +1.0*cm;
  
  if(LightGuide8->GetLightGuideDepth() > 2*PMT8->GetRadius())
    DetFullLengthZ8 = LightGuide8->GetLightGuideDepth() + 2*PMTToQuartzOffset8 + 4.0*cm;
  else
    DetFullLengthZ8 = 2*PMT8->GetRadius() + 2*PMTToQuartzOffset8 + 4.0*cm;
  
  DetFullLengthY1 = Quartz1->GetQuartzSizeY()+LightGuide1->GetLightGuideLength()+PMT1->GetPMTLength()+1.0*cm+LightGuide1->GetCurrentMiddleBoxHeight();
  DetFullLengthY2 = Quartz2->GetQuartzSizeY()+LightGuide2->GetLightGuideLength()+PMT2->GetPMTLength()+1.0*cm+LightGuide2->GetCurrentMiddleBoxHeight();
  DetFullLengthY3 = Quartz3->GetQuartzSizeY()+LightGuide3->GetLightGuideLength()+PMT3->GetPMTLength()+1.0*cm+LightGuide3->GetCurrentMiddleBoxHeight();
  DetFullLengthY4 = Quartz4->GetQuartzSizeY()+LightGuide4->GetLightGuideLength()+PMT4->GetPMTLength()+1.0*cm+LightGuide4->GetCurrentMiddleBoxHeight();
  DetFullLengthY5 = Quartz5->GetQuartzSizeY()+LightGuide5->GetLightGuideLength()+PMT5->GetPMTLength()+1.0*cm+LightGuide5->GetCurrentMiddleBoxHeight();
  DetFullLengthY6 = Quartz6->GetQuartzSizeY()+LightGuide6->GetLightGuideLength()+PMT6->GetPMTLength()+1.0*cm+LightGuide6->GetCurrentMiddleBoxHeight();
  DetFullLengthY7 = Quartz7->GetQuartzSizeY()+LightGuide7->GetLightGuideLength()+PMT7->GetPMTLength()+1.0*cm+LightGuide7->GetCurrentMiddleBoxHeight();
  DetFullLengthY8 = Quartz8->GetQuartzSizeY()+LightGuide8->GetLightGuideLength()+PMT8->GetPMTLength()+1.0*cm+LightGuide8->GetCurrentMiddleBoxHeight();
  DetFullLengthYscint = Scintillator->GetQuartzSizeY();
}

void MOLLEROptDetector::ResetCenterLocation()
{
  /*PositionDetX1 = 0.0*cm;
  PositionDetY1 = 0.0*cm;//DetFullLengthY/2 - Quartz->GetQuartzSizeY()/2;
  PositionDetZ1 = 0.0*cm;

  PositionDet1.setX(PositionDetX1);
  PositionDet1.setY(PositionDetY1);
  PositionDet1.setZ(PositionDetZ1);*/  

}

void MOLLEROptDetector::Initialize()
{
  //let these objects setup their default solids and logical volumes
  PMTToQuartzOffset1 = 0;
  PMTToQuartzOffset2 = 0;
  PMTToQuartzOffset3 = 0;
  PMTToQuartzOffset4 = 0;
  PMTToQuartzOffset5 = 0;
  PMTToQuartzOffset6 = 0;
  PMTToQuartzOffset7 = 0;
  PMTToQuartzOffset8 = 0;
  AzimuAngle = 0; 
  PolarAngle = 0;
  Quartz1->Initialize();
  LightGuide1->Initialize();
  PMT1->Initialize();
  Quartz2->Initialize();
  LightGuide2->Initialize();
  PMT2->Initialize();
  Quartz3->Initialize();
  LightGuide3->Initialize();
  PMT3->Initialize();
  Quartz4->Initialize();
  LightGuide4->Initialize();
  PMT4->Initialize();
  Quartz5->Initialize();
  LightGuide5->Initialize();
  PMT5->Initialize();
  Quartz6->Initialize();
  LightGuide6->Initialize();
  PMT6->Initialize();
  Quartz7->Initialize();
  LightGuide7->Initialize();
  PMT7->Initialize();
  Quartz8->Initialize();
  LightGuide8->Initialize();
  PMT8->Initialize();
  Scintillator->Initialize();

  //Scintillator->SetPolarRotationAngle(PolarAngle);
  
  CalculateDimensions();
  ResetCenterLocation();

  RotationDet = new G4RotationMatrix;

  DetSolid = new G4Box(DetType1+"_Solid",
		       20* DetFullLengthX1, 
		       5* DetFullLengthY1,
		       20* DetFullLengthZ1);
  
  DetLogical = new G4LogicalVolume( DetSolid, DetMaterial, DetType1+"_Logical");
}

G4VPhysicalVolume* MOLLEROptDetector::ConstructDetector(G4VPhysicalVolume* Mother)
{
  if(!Mother) return 0;
  
  if(!MotherVolume){
    MotherVolume = Mother;
  }

  DetPhysical = new G4PVPlacement(RotationDet,
				  PositionDet1,   
				  DetType1+"_Physical",
				  DetLogical,
				  MotherVolume,false,1);    
  
  G4double quartzY1 = Quartz1->GetQuartzSizeY();
  G4double quartzZ1 = Quartz1->GetQuartzSizeZ();  
  G4double lguideY1 = LightGuide1->GetCurrentUpperInterfacePlane();
  G4double Offset1  = LightGuide1->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY2 = Quartz2->GetQuartzSizeY();
  G4double quartzZ2 = Quartz2->GetQuartzSizeZ();
  G4double lguideY2 = LightGuide2->GetCurrentUpperInterfacePlane();
  G4double Offset2  = LightGuide2->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY3 = Quartz3->GetQuartzSizeY();
  G4double quartzZ3 = Quartz3->GetQuartzSizeZ();
  G4double lguideY3 = LightGuide3->GetCurrentUpperInterfacePlane();
  G4double Offset3  = LightGuide3->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY4 = Quartz4->GetQuartzSizeY();
  G4double quartzZ4 = Quartz4->GetQuartzSizeZ();
  G4double lguideY4 = LightGuide4->GetCurrentUpperInterfacePlane();
  G4double Offset4  = LightGuide4->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY5 = Quartz5->GetQuartzSizeY();
  G4double quartzZ5 = Quartz5->GetQuartzSizeZ();
  G4double lguideY5 = LightGuide5->GetCurrentUpperInterfacePlane();
  G4double Offset5  = LightGuide5->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY6 = Quartz6->GetQuartzSizeY();
  G4double quartzZ6 = Quartz6->GetQuartzSizeZ();
  G4double lguideY6 = LightGuide6->GetCurrentUpperInterfacePlane();
  G4double Offset6  = LightGuide6->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY7 = Quartz7->GetQuartzSizeY();
  G4double quartzZ7 = Quartz7->GetQuartzSizeZ();
  G4double lguideY7 = LightGuide7->GetCurrentUpperInterfacePlane();
  G4double Offset7  = LightGuide7->GetCurrentQuartzToPMTOffsetInZ();
  G4double quartzY8 = Quartz8->GetQuartzSizeY();
  G4double quartzZ8 = Quartz8->GetQuartzSizeZ();
  G4double lguideY8 = LightGuide8->GetCurrentUpperInterfacePlane();
  G4double Offset8  = LightGuide8->GetCurrentQuartzToPMTOffsetInZ();

  G4double scinty = Scintillator->GetQuartzSizeY();
  G4double scintz = Scintillator->GetQuartzSizeZ();

  G4double Qrot = Quartz1->GetQuartzRotationX();
     
  //Ring 1
  Quartz1->Construct(DetPhysical);
  Quartz1->SetCenterPositionInX(PositionDetX1);
  Quartz1->SetCenterPositionInZ(0.5*quartzY1*(TMath::Sin(Qrot)) + PositionDetZ1);
  Quartz1->SetCenterPositionInY(-0.5*DetFullLengthY1 + 0.5*quartzY1 + 0.5*quartzY1*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ1*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY1);
  LightGuide1->Construct(DetPhysical);
  LightGuide1->SetCenterPositionInX(PositionDetX1);
  LightGuide1->SetCenterPositionInZ(PositionDetZ1);  
  LightGuide1->SetCenterPositionInY(-0.5*DetFullLengthY1+quartzY1 + 5*mm + PositionDetY1);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT1->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT1->SetCenterPositionInX(PositionDetX1);
  PMT1->SetCenterPositionInZ(PositionDetZ1+Offset1);    
  PMT1->SetCenterPositionInY(-0.5*DetFullLengthY1+quartzY1+lguideY1+PMT1->GetPMTLength()/2.0 + 5.0*mm + LightGuide1->GetCurrentMiddleBoxHeight() + PositionDetY1);

  //Ring 2
  //Quartz2->Construct(DetPhysical2);
  Quartz2->Construct(DetPhysical);
  Quartz2->SetCenterPositionInX(PositionDetX2);
  Quartz2->SetCenterPositionInZ(0.5*quartzY2*(TMath::Sin(Qrot)) + PositionDetZ2);
  Quartz2->SetCenterPositionInY(-0.5*DetFullLengthY2 + 0.5*quartzY2 + 0.5*quartzY2*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ2*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY2);
  //LightGuide2->Construct(DetPhysical2);
  LightGuide2->Construct(DetPhysical);
  LightGuide2->SetCenterPositionInX(PositionDetX2);
  LightGuide2->SetCenterPositionInZ(PositionDetZ2);
  LightGuide2->SetCenterPositionInY(-0.5*DetFullLengthY2+quartzY2 + 5*mm + PositionDetY2);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  //PMT2->Construct(DetPhysical2);
  PMT2->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT2->SetCenterPositionInX(PositionDetX2);
  PMT2->SetCenterPositionInZ(PositionDetZ2+Offset2);  
  PMT2->SetCenterPositionInY(-0.5*DetFullLengthY2+quartzY2+lguideY2+PMT2->GetPMTLength()/2.0 + 5.0*mm + LightGuide2->GetCurrentMiddleBoxHeight() + PositionDetY2);

  //Ring 3
  Quartz3->Construct(DetPhysical);
  Quartz3->SetCenterPositionInX(PositionDetX3);
  Quartz3->SetCenterPositionInZ(0.5*quartzY3*(TMath::Sin(Qrot)) + PositionDetZ3);
  Quartz3->SetCenterPositionInY(-0.5*DetFullLengthY3 + 0.5*quartzY3 + 0.5*quartzY3*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ3*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY3);
  LightGuide3->Construct(DetPhysical);
  LightGuide3->SetCenterPositionInX(PositionDetX3);
  LightGuide3->SetCenterPositionInZ(PositionDetZ3);  
  LightGuide3->SetCenterPositionInY(-0.5*DetFullLengthY3+quartzY3 + 5*mm + PositionDetY3);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT3->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT3->SetCenterPositionInX(PositionDetX3);
  PMT3->SetCenterPositionInZ(PositionDetZ3+Offset3);    
  PMT3->SetCenterPositionInY(-0.5*DetFullLengthY3+quartzY3+lguideY3+PMT3->GetPMTLength()/2.0 + 5.0*mm + LightGuide3->GetCurrentMiddleBoxHeight() + PositionDetY3);

  //Ring 4
  Quartz4->Construct(DetPhysical);
  Quartz4->SetCenterPositionInX(PositionDetX4);
  Quartz4->SetCenterPositionInZ(0.5*quartzY4*(TMath::Sin(Qrot)) + PositionDetZ4);
  Quartz4->SetCenterPositionInY(-0.5*DetFullLengthY4 + 0.5*quartzY4 + 0.5*quartzY4*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ4*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY4);
  LightGuide4->Construct(DetPhysical);
  LightGuide4->SetCenterPositionInX(PositionDetX4);
  LightGuide4->SetCenterPositionInZ(PositionDetZ4);  
  LightGuide4->SetCenterPositionInY(-0.5*DetFullLengthY4+quartzY4 + 5*mm + PositionDetY4);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT4->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT4->SetCenterPositionInX(PositionDetX4);
  PMT4->SetCenterPositionInZ(PositionDetZ4+Offset4);    
  PMT4->SetCenterPositionInY(-0.5*DetFullLengthY4+quartzY4+lguideY4+PMT4->GetPMTLength()/2.0 + 5.0*mm + LightGuide4->GetCurrentMiddleBoxHeight() + PositionDetY4);

  //Ring 5
  Quartz5->Construct(DetPhysical);
  Quartz5->SetCenterPositionInX(PositionDetX5);
  Quartz5->SetCenterPositionInZ(0.5*quartzY5*(TMath::Sin(Qrot)) + PositionDetZ5);
  Quartz5->SetCenterPositionInY(-0.5*DetFullLengthY5 + 0.5*quartzY5 + 0.5*quartzY5*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ5*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY5);
  LightGuide5->Construct(DetPhysical);
  LightGuide5->SetCenterPositionInX(PositionDetX5);
  LightGuide5->SetCenterPositionInZ(PositionDetZ5);  
  LightGuide5->SetCenterPositionInY(-0.5*DetFullLengthY5+quartzY5 + 5*mm + PositionDetY5);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT5->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT5->SetCenterPositionInX(PositionDetX5);
  PMT5->SetCenterPositionInZ(PositionDetZ5+Offset5);    
  PMT5->SetCenterPositionInY(-0.5*DetFullLengthY5+quartzY5+lguideY5+PMT5->GetPMTLength()/2.0 + 5.0*mm + LightGuide5->GetCurrentMiddleBoxHeight() + PositionDetY5);

  //Ring 6 (R5 backflush 1)
  Quartz6->Construct(DetPhysical);
  Quartz6->SetCenterPositionInX(PositionDetX6);
  Quartz6->SetCenterPositionInZ(0.5*quartzY6*(TMath::Sin(Qrot)) + PositionDetZ6);
  Quartz6->SetCenterPositionInY(-0.5*DetFullLengthY6 + 0.5*quartzY6 + 0.5*quartzY6*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ6*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY6);
  LightGuide6->Construct(DetPhysical);
  LightGuide6->SetCenterPositionInX(PositionDetX6);
  LightGuide6->SetCenterPositionInZ(PositionDetZ6);  
  LightGuide6->SetCenterPositionInY(-0.5*DetFullLengthY6+quartzY6 + 5*mm + PositionDetY6);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT6->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT6->SetCenterPositionInX(PositionDetX6);
  PMT6->SetCenterPositionInZ(PositionDetZ6+Offset6);    
  PMT6->SetCenterPositionInY(-0.5*DetFullLengthY6+quartzY6+lguideY6+PMT6->GetPMTLength()/2.0 + 5.0*mm + LightGuide6->GetCurrentMiddleBoxHeight() + PositionDetY6);

  //Ring 7 (R5 backflush 2)
  Quartz7->Construct(DetPhysical);
  Quartz7->SetCenterPositionInX(PositionDetX7);
  Quartz7->SetCenterPositionInZ(0.5*quartzY7*(TMath::Sin(Qrot)) + PositionDetZ7);
  Quartz7->SetCenterPositionInY(-0.5*DetFullLengthY7 + 0.5*quartzY7 + 0.5*quartzY7*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ7*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY7);
  LightGuide7->Construct(DetPhysical);
  LightGuide7->SetCenterPositionInX(PositionDetX7);
  LightGuide7->SetCenterPositionInZ(PositionDetZ7);  
  LightGuide7->SetCenterPositionInY(-0.5*DetFullLengthY7+quartzY7 + 5*mm + PositionDetY7);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT7->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT7->SetCenterPositionInX(PositionDetX7);
  PMT7->SetCenterPositionInZ(PositionDetZ7+Offset7);    
  PMT7->SetCenterPositionInY(-0.5*DetFullLengthY7+quartzY7+lguideY7+PMT7->GetPMTLength()/2.0 + 5.0*mm + LightGuide7->GetCurrentMiddleBoxHeight() + PositionDetY7);

  //Ring 8 (R6)
  Quartz8->Construct(DetPhysical);
  Quartz8->SetCenterPositionInX(PositionDetX8);
  Quartz8->SetCenterPositionInZ(0.5*quartzY8*(TMath::Sin(Qrot)) + PositionDetZ8);
  Quartz8->SetCenterPositionInY(-0.5*DetFullLengthY8 + 0.5*quartzY8 + 0.5*quartzY8*(1.0-TMath::Cos(Qrot)) + 0.5*quartzZ8*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetY8);
  LightGuide8->Construct(DetPhysical);
  LightGuide8->SetCenterPositionInX(PositionDetX8);
  LightGuide8->SetCenterPositionInZ(PositionDetZ8);  
  LightGuide8->SetCenterPositionInY(-0.5*DetFullLengthY8+quartzY8 + 5*mm + PositionDetY8);// + 0.5*LightGuide->GetCurrentQuartzInterfaceOpeningY()*TMath::Sin(Qrot));
  PMT8->Construct(DetPhysical);
  // We have to let the PMT extend into the light guide lsig
  PMT8->SetCenterPositionInX(PositionDetX8);
  PMT8->SetCenterPositionInZ(PositionDetZ8+Offset8);    
  PMT8->SetCenterPositionInY(-0.5*DetFullLengthY8+quartzY8+lguideY8+PMT8->GetPMTLength()/2.0 + 5.0*mm + LightGuide8->GetCurrentMiddleBoxHeight() + PositionDetY8);

  //Scintillator
  Scintillator->Construct(DetPhysical);
  Scintillator->SetCenterPositionInX(PositionDetXscint);
  Scintillator->SetCenterPositionInZ(0.5*scinty*(TMath::Sin(Qrot)) + PositionDetZscint);
  Scintillator->SetCenterPositionInY(-0.5*DetFullLengthYscint + 0.5*scinty + 0.5*scinty*(1.0-TMath::Cos(Qrot)) + 0.5*scintz*fabs(TMath::Sin(Qrot)) + 5*mm + PositionDetYscint);
  Scintillator->SetQuartzRotX(-1.5*degree); //Used to counteract rotation caused by improper implementation of polar angle for multiple detectors


  G4Colour  grey      ( 127/255., 127/255., 127/255.);
  G4VisAttributes *att = new G4VisAttributes(grey);
  att->SetVisibility(true);
  att->SetForceWireframe(true);
  DetLogical->SetVisAttributes(att);

  if(!detMessenger)
    detMessenger = new MOLLEROptDetectorMessenger(this);  


  return DetPhysical;
} 

void MOLLEROptDetector::ConstructMountingStructure(G4VPhysicalVolume* Mother)
{
  gdmlParser.Read(fReadFile);

  G4LogicalVolume *logV = gdmlParser.GetVolume("R5-Module-Aluminum");

  if(logV){

    G4RotationMatrix  *Rot1 = new G4RotationMatrix;
   Rot1->rotateZ(180*degree);
  G4double quartzY1 = Quartz1->GetQuartzSizeY();
  G4double quartzY2 = Quartz2->GetQuartzSizeY();
  G4double quartzY3 = Quartz3->GetQuartzSizeY();
  G4double quartzY4 = Quartz4->GetQuartzSizeY();
  G4double quartzY5 = Quartz5->GetQuartzSizeY();
  G4double quartzY6 = Quartz6->GetQuartzSizeY();
  G4double quartzY7 = Quartz7->GetQuartzSizeY();
  G4double quartzY8 = Quartz8->GetQuartzSizeY();
  
  G4ThreeVector Qpos1 = Quartz1->GetCurrentCenterPosition();
  G4ThreeVector Qpos2 = Quartz2->GetCurrentCenterPosition();
  G4ThreeVector Qpos3 = Quartz3->GetCurrentCenterPosition();
  G4ThreeVector Qpos4 = Quartz4->GetCurrentCenterPosition();
  G4ThreeVector Qpos5 = Quartz5->GetCurrentCenterPosition();
  G4ThreeVector Qpos6 = Quartz6->GetCurrentCenterPosition();
  G4ThreeVector Qpos7 = Quartz7->GetCurrentCenterPosition();
  G4ThreeVector Qpos8 = Quartz8->GetCurrentCenterPosition();
  
  G4double dz1 = 2*fabs(Qpos1.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy1 = 2*fabs(Qpos1.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz2 = 2*fabs(Qpos2.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy2 = 2*fabs(Qpos2.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz3 = 2*fabs(Qpos3.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy3 = 2*fabs(Qpos3.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz4 = 2*fabs(Qpos4.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy4 = 2*fabs(Qpos4.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz5 = 2*fabs(Qpos5.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy5 = 2*fabs(Qpos5.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz6 = 2*fabs(Qpos6.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy6 = 2*fabs(Qpos6.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz7 = 2*fabs(Qpos7.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy7 = 2*fabs(Qpos7.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  G4double dz8 = 2*fabs(Qpos8.y())*TMath::Sin(PolarAngle/2)*TMath::Cos(PolarAngle/2);
  G4double dy8 = 2*fabs(Qpos8.y())*TMath::Sin(PolarAngle/2)*TMath::Sin(PolarAngle/2);
  
  G4ThreeVector Trans1 = G4ThreeVector(Qpos1.x(),Qpos1.y()+dy1,Qpos1.z()+dz1);
  G4ThreeVector Trans2 = G4ThreeVector(Qpos2.x(),Qpos2.y()+dy2,Qpos2.z()+dz2);
  G4ThreeVector Trans3 = G4ThreeVector(Qpos3.x(),Qpos3.y()+dy3,Qpos3.z()+dz3);
  G4ThreeVector Trans4 = G4ThreeVector(Qpos4.x(),Qpos4.y()+dy4,Qpos4.z()+dz4);
  G4ThreeVector Trans5 = G4ThreeVector(Qpos5.x(),Qpos5.y()+dy5,Qpos5.z()+dz5);
  G4ThreeVector Trans6 = G4ThreeVector(Qpos6.x(),Qpos6.y()+dy6,Qpos6.z()+dz6);
  G4ThreeVector Trans7 = G4ThreeVector(Qpos7.x(),Qpos7.y()+dy7,Qpos7.z()+dz7);
  G4ThreeVector Trans8 = G4ThreeVector(Qpos8.x(),Qpos8.y()+dy8,Qpos8.z()+dz8);
  
  G4ThreeVector LGpos1 = LightGuide1->GetCurrentCenterPosition();
  G4ThreeVector LGpos2 = LightGuide2->GetCurrentCenterPosition();
  G4ThreeVector LGpos3 = LightGuide3->GetCurrentCenterPosition();
  G4ThreeVector LGpos4 = LightGuide4->GetCurrentCenterPosition();
  G4ThreeVector LGpos5 = LightGuide5->GetCurrentCenterPosition();
  G4ThreeVector LGpos6 = LightGuide6->GetCurrentCenterPosition();
  G4ThreeVector LGpos7 = LightGuide7->GetCurrentCenterPosition();
  G4ThreeVector LGpos8 = LightGuide8->GetCurrentCenterPosition();
    
  G4VPhysicalVolume* MPhys1 = new G4PVPlacement(Rot1,
					       Trans1,   
					       DetType1+"_logV",
					       logV ,
					       Mother,false,1); 
  G4VPhysicalVolume* MPhys2 = new G4PVPlacement(Rot1,
					       Trans2,   
					       DetType2+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys3 = new G4PVPlacement(Rot1,
					       Trans3,   
					       DetType3+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys4 = new G4PVPlacement(Rot1,
					       Trans4,   
					       DetType4+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys5 = new G4PVPlacement(Rot1,
					       Trans5,   
					       DetType5+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys6 = new G4PVPlacement(Rot1,
					       Trans6,   
					       DetType6+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys7 = new G4PVPlacement(Rot1,
					       Trans7,   
					       DetType7+"_logV",
					       logV ,
					       Mother,false,1);
  G4VPhysicalVolume* MPhys8 = new G4PVPlacement(Rot1,
					       Trans8,   
					       DetType8+"_logV",
					       logV ,
					       Mother,false,1);

    G4Colour green    (   0/255., 255/255.,   0/255.);
    G4VisAttributes *att2 = new G4VisAttributes(green);
    att2->SetVisibility(true);
    //att2->SetForceWireframe(true);
    logV->SetVisAttributes(att2);

    G4ThreeVector MPos1 = MPhys1->GetTranslation();
    G4ThreeVector MPos2 = MPhys2->GetTranslation();
    G4ThreeVector MPos3 = MPhys3->GetTranslation();
    G4ThreeVector MPos4 = MPhys4->GetTranslation();
    G4ThreeVector MPos5 = MPhys5->GetTranslation();
    G4ThreeVector MPos6 = MPhys6->GetTranslation();
    G4ThreeVector MPos7 = MPhys7->GetTranslation();
    G4ThreeVector MPos8 = MPhys8->GetTranslation();

    
  }  
}


//Ring 1 objects
void MOLLEROptDetector::SetCenterPositionInX1(G4double xPos)
{
    PositionDetX1 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX1,
					      PositionDetY1, 
					      PositionDetZ1));
}

void MOLLEROptDetector::SetCenterPositionInY1(G4double yPos)
{
    PositionDetY1 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX1,
					      PositionDetY1, 
					      PositionDetZ1));
}

void MOLLEROptDetector::SetCenterPositionInZ1(G4double zPos)
{
    PositionDetZ1 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX1,
					      PositionDetY1, 
					      PositionDetZ1));
}

//Ring 2 objects
void MOLLEROptDetector::SetCenterPositionInX2(G4double xPos)
{
    PositionDetX2 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX2,
					      PositionDetY2, 
					      PositionDetZ2));
}

void MOLLEROptDetector::SetCenterPositionInY2(G4double yPos)
{
    PositionDetY2 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX2,
					      PositionDetY2, 
					      PositionDetZ2));
}

void MOLLEROptDetector::SetCenterPositionInZ2(G4double zPos)
{
    PositionDetZ2 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX2,
					      PositionDetY2, 
					      PositionDetZ2));
}

//Ring 3 objects
void MOLLEROptDetector::SetCenterPositionInX3(G4double xPos)
{
    PositionDetX3 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX3,
					      PositionDetY3, 
					      PositionDetZ3));
}

void MOLLEROptDetector::SetCenterPositionInY3(G4double yPos)
{
    PositionDetY3 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX3,
					      PositionDetY3, 
					      PositionDetZ3));
}

void MOLLEROptDetector::SetCenterPositionInZ3(G4double zPos)
{
    PositionDetZ3 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX3,
					      PositionDetY3, 
					      PositionDetZ3));
}

//Ring 4 objects
void MOLLEROptDetector::SetCenterPositionInX4(G4double xPos)
{
    PositionDetX4 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX4,
					      PositionDetY4, 
					      PositionDetZ4));
}

void MOLLEROptDetector::SetCenterPositionInY4(G4double yPos)
{
    PositionDetY4 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX4,
					      PositionDetY4, 
					      PositionDetZ4));
}

void MOLLEROptDetector::SetCenterPositionInZ4(G4double zPos)
{
    PositionDetZ4 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX4,
					      PositionDetY4, 
					      PositionDetZ4));
}

//Ring 5 objects
void MOLLEROptDetector::SetCenterPositionInX5(G4double xPos)
{
    PositionDetX5 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX5,
					      PositionDetY5, 
					      PositionDetZ5));
}

void MOLLEROptDetector::SetCenterPositionInY5(G4double yPos)
{
    PositionDetY5 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX5,
					      PositionDetY5, 
					      PositionDetZ5));
}

void MOLLEROptDetector::SetCenterPositionInZ5(G4double zPos)
{
    PositionDetZ5 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX5,
					      PositionDetY5, 
					      PositionDetZ5));
}

//Ring 6 objects
void MOLLEROptDetector::SetCenterPositionInX6(G4double xPos)
{
    PositionDetX6 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX6,
					      PositionDetY6, 
					      PositionDetZ6));
}

void MOLLEROptDetector::SetCenterPositionInY6(G4double yPos)
{
    PositionDetY6 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX6,
					      PositionDetY6, 
					      PositionDetZ6));
}

void MOLLEROptDetector::SetCenterPositionInZ6(G4double zPos)
{
    PositionDetZ6 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX6,
					      PositionDetY6, 
					      PositionDetZ6));
}

//Ring 7 objects
void MOLLEROptDetector::SetCenterPositionInX7(G4double xPos)
{
    PositionDetX7 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX7,
					      PositionDetY7, 
					      PositionDetZ7));
}

void MOLLEROptDetector::SetCenterPositionInY7(G4double yPos)
{
    PositionDetY7 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX7,
					      PositionDetY7, 
					      PositionDetZ7));
}

void MOLLEROptDetector::SetCenterPositionInZ7(G4double zPos)
{
    PositionDetZ7 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX7,
					      PositionDetY7, 
					      PositionDetZ7));
}

//Ring 8 objects
void MOLLEROptDetector::SetCenterPositionInX8(G4double xPos)
{
    PositionDetX8 = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX8,
					      PositionDetY8, 
					      PositionDetZ8));
}

void MOLLEROptDetector::SetCenterPositionInY8(G4double yPos)
{
    PositionDetY8 = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX8,
					      PositionDetY8, 
					      PositionDetZ8));
}

void MOLLEROptDetector::SetCenterPositionInZ8(G4double zPos)
{
    PositionDetZ8 = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetX8,
					      PositionDetY8, 
					      PositionDetZ8));
}

//Scintillator objects
void MOLLEROptDetector::SetCenterPositionInXscint(G4double xPos)
{
    PositionDetXscint = xPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetXscint,
					      PositionDetYscint, 
					      PositionDetZscint));
}

void MOLLEROptDetector::SetCenterPositionInYscint(G4double yPos)
{
    PositionDetYscint = yPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetXscint,
					      PositionDetYscint, 
					      PositionDetZscint));
}

void MOLLEROptDetector::SetCenterPositionInZscint(G4double zPos)
{
    PositionDetZscint = zPos;

    DetPhysical->SetTranslation(G4ThreeVector(PositionDetXscint,
					      PositionDetYscint, 
					      PositionDetZscint));
}

//General objects (with edits)
void MOLLEROptDetector::SetLightGuideOffsetInX(G4double x)
{
  G4double cX1;
  G4double cX2;
  G4double cX3;
  G4double cX4;
  G4double cX5;
  G4double cX6;
  G4double cX7;
  G4double cX8;

  if(LightGuide1 &&  PMT1){
    cX1 = LightGuide1->GetCurrentCenterPositionInX() + x*cm;
    LightGuide1->SetCenterPositionInX(cX1);
    cX1 = PMT1->GetCurrentCenterPositionInX() + x*cm;
    PMT1->SetCenterPositionInX(cX1);
  }

  if(LightGuide2 &&  PMT2){
    cX2 = LightGuide2->GetCurrentCenterPositionInX() + x*cm;
    LightGuide2->SetCenterPositionInX(cX2);
    cX2 = PMT2->GetCurrentCenterPositionInX() + x*cm;
    PMT2->SetCenterPositionInX(cX2);
  }
  
  if(LightGuide3 &&  PMT3){
    cX3 = LightGuide3->GetCurrentCenterPositionInX() + x*cm;
    LightGuide3->SetCenterPositionInX(cX3);
    cX3 = PMT3->GetCurrentCenterPositionInX() + x*cm;
    PMT3->SetCenterPositionInX(cX3);
  }

  if(LightGuide4 &&  PMT4){
    cX4 = LightGuide4->GetCurrentCenterPositionInX() + x*cm;
    LightGuide4->SetCenterPositionInX(cX4);
    cX4 = PMT4->GetCurrentCenterPositionInX() + x*cm;
    PMT4->SetCenterPositionInX(cX4);
  }

  if(LightGuide5 &&  PMT5){
    cX5 = LightGuide5->GetCurrentCenterPositionInX() + x*cm;
    LightGuide5->SetCenterPositionInX(cX5);
    cX5 = PMT5->GetCurrentCenterPositionInX() + x*cm;
    PMT5->SetCenterPositionInX(cX5);
  }
  
  if(LightGuide6 &&  PMT6){
    cX6 = LightGuide6->GetCurrentCenterPositionInX() + x*cm;
    LightGuide6->SetCenterPositionInX(cX6);
    cX6 = PMT6->GetCurrentCenterPositionInX() + x*cm;
    PMT6->SetCenterPositionInX(cX6);
  }

  if(LightGuide7 &&  PMT7){
    cX7 = LightGuide7->GetCurrentCenterPositionInX() + x*cm;
    LightGuide7->SetCenterPositionInX(cX7);
    cX7 = PMT7->GetCurrentCenterPositionInX() + x*cm;
    PMT7->SetCenterPositionInX(cX7);
  }

  if(LightGuide8 &&  PMT8){
    cX8 = LightGuide8->GetCurrentCenterPositionInX() + x*cm;
    LightGuide8->SetCenterPositionInX(cX8);
    cX8 = PMT8->GetCurrentCenterPositionInX() + x*cm;
    PMT8->SetCenterPositionInX(cX8);
  }
}

void MOLLEROptDetector::SetLightGuideOffsetInY(G4double y)
{
  G4double cY1;
  G4double cY2;
  G4double cY3;
  G4double cY4;
  G4double cY5;
  G4double cY6;
  G4double cY7;
  G4double cY8;
  
  if(LightGuide1 &&  PMT1){
    cY1 = LightGuide1->GetCurrentCenterPositionInY() + y*cm;
    LightGuide1->SetCenterPositionInY(cY1);
    cY1 = PMT1->GetCurrentCenterPositionInY() + y*cm;
    PMT1->SetCenterPositionInY(cY1);
  }
  if(LightGuide2 &&  PMT2){
    cY2 = LightGuide2->GetCurrentCenterPositionInY() + y*cm;
    LightGuide2->SetCenterPositionInY(cY2);
    cY2 = PMT2->GetCurrentCenterPositionInY() + y*cm;
    PMT2->SetCenterPositionInY(cY2);
  }

  if(LightGuide3 &&  PMT3){
    cY3 = LightGuide3->GetCurrentCenterPositionInY() + y*cm;
    LightGuide3->SetCenterPositionInY(cY3);
    cY3 = PMT3->GetCurrentCenterPositionInY() + y*cm;
    PMT3->SetCenterPositionInY(cY3);
  }

  if(LightGuide4 &&  PMT4){
    cY4 = LightGuide4->GetCurrentCenterPositionInY() + y*cm;
    LightGuide4->SetCenterPositionInY(cY4);
    cY4 = PMT4->GetCurrentCenterPositionInY() + y*cm;
    PMT4->SetCenterPositionInY(cY4);
  }

  if(LightGuide5 &&  PMT5){
    cY5 = LightGuide5->GetCurrentCenterPositionInY() + y*cm;
    LightGuide5->SetCenterPositionInY(cY5);
    cY5 = PMT5->GetCurrentCenterPositionInY() + y*cm;
    PMT5->SetCenterPositionInY(cY5);
  }
  
  if(LightGuide6 &&  PMT6){
    cY6 = LightGuide6->GetCurrentCenterPositionInY() + y*cm;
    LightGuide6->SetCenterPositionInY(cY6);
    cY6 = PMT6->GetCurrentCenterPositionInY() + y*cm;
    PMT6->SetCenterPositionInY(cY6);
  }

  if(LightGuide7 &&  PMT7){
    cY7 = LightGuide7->GetCurrentCenterPositionInY() + y*cm;
    LightGuide7->SetCenterPositionInY(cY7);
    cY7 = PMT7->GetCurrentCenterPositionInY() + y*cm;
    PMT7->SetCenterPositionInY(cY7);
  }

  if(LightGuide8 &&  PMT8){
    cY8 = LightGuide8->GetCurrentCenterPositionInY() + y*cm;
    LightGuide8->SetCenterPositionInY(cY8);
    cY8 = PMT8->GetCurrentCenterPositionInY() + y*cm;
    PMT8->SetCenterPositionInY(cY8);
  }
}

void MOLLEROptDetector::SetLightGuideOffsetInZ(G4double z)
{
  G4double cZ1;
  G4double cZ2;
  G4double cZ3;
  G4double cZ4;
  G4double cZ5;
  G4double cZ6;
  G4double cZ7;
  G4double cZ8;
  
  if(LightGuide1 &&  PMT1){
    cZ1 = LightGuide1->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide1->SetCenterPositionInZ(cZ1);
    cZ1 = PMT1->GetCurrentCenterPositionInZ() + z*cm;
    PMT1->SetCenterPositionInZ(cZ1);
  }
  if(LightGuide2 &&  PMT2){
    cZ2 = LightGuide2->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide2->SetCenterPositionInZ(cZ2);
    cZ2 = PMT2->GetCurrentCenterPositionInZ() + z*cm;
    PMT2->SetCenterPositionInZ(cZ2);
  }

  if(LightGuide3 &&  PMT3){
    cZ3 = LightGuide3->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide3->SetCenterPositionInZ(cZ3);
    cZ3 = PMT3->GetCurrentCenterPositionInZ() + z*cm;
    PMT3->SetCenterPositionInZ(cZ3);
  }

  if(LightGuide4 &&  PMT4){
    cZ4 = LightGuide4->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide4->SetCenterPositionInZ(cZ4);
    cZ4 = PMT4->GetCurrentCenterPositionInZ() + z*cm;
    PMT4->SetCenterPositionInZ(cZ4);
  }

  if(LightGuide5 &&  PMT5){
    cZ5 = LightGuide5->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide5->SetCenterPositionInZ(cZ5);
    cZ5 = PMT5->GetCurrentCenterPositionInZ() + z*cm;
    PMT5->SetCenterPositionInZ(cZ5);
  }
  
  if(LightGuide6 &&  PMT6){
    cZ6 = LightGuide6->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide6->SetCenterPositionInZ(cZ6);
    cZ6 = PMT6->GetCurrentCenterPositionInZ() + z*cm;
    PMT6->SetCenterPositionInZ(cZ6);
  }

  if(LightGuide7 &&  PMT7){
    cZ7 = LightGuide7->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide7->SetCenterPositionInZ(cZ7);
    cZ7 = PMT7->GetCurrentCenterPositionInZ() + z*cm;
    PMT7->SetCenterPositionInZ(cZ7);
  }

  if(LightGuide8 &&  PMT8){
    cZ8 = LightGuide8->GetCurrentCenterPositionInZ() + z*cm;
    LightGuide8->SetCenterPositionInZ(cZ8);
    cZ8 = PMT8->GetCurrentCenterPositionInZ() + z*cm;
    PMT8->SetCenterPositionInZ(cZ8);
  }
}

void MOLLEROptDetector::GetQuartz1Limits(G4double *vals)
{
  Quartz1->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz2Limits(G4double *vals)
{
  Quartz2->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz3Limits(G4double *vals)
{
  Quartz3->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz4Limits(G4double *vals)
{
  Quartz4->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz5Limits(G4double *vals)
{
  Quartz5->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz6Limits(G4double *vals)
{
  Quartz6->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz7Limits(G4double *vals)
{
  Quartz7->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetQuartz8Limits(G4double *vals)
{
  Quartz8->GetQuartzLimits(vals);
}
void MOLLEROptDetector::GetScintillatorLimits(G4double *vals)
{
  Scintillator->GetQuartzLimits(vals);
}

void MOLLEROptDetector::GetLightGuide1Limits(G4double *vals)
{
  LightGuide1->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide2Limits(G4double *vals)
{
  LightGuide2->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide3Limits(G4double *vals)
{
  LightGuide3->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide4Limits(G4double *vals)
{
  LightGuide4->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide5Limits(G4double *vals)
{
  LightGuide5->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide6Limits(G4double *vals)
{
  LightGuide6->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide7Limits(G4double *vals)
{
  LightGuide7->GetLightGuideLimits(vals);
}
void MOLLEROptDetector::GetLightGuide8Limits(G4double *vals)
{
  LightGuide8->GetLightGuideLimits(vals);
}

void MOLLEROptDetector::SetMaterial(G4String materialName)
{
  DetMaterial = Materials->GetMaterial(materialName);
}

