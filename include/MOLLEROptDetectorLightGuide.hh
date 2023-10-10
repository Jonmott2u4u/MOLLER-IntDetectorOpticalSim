#ifndef MOLLEROptDetectorLightGuide_h
#define MOLLEROptDetectorLightGuide_h 

#include "G4QuadrangularFacet.hh"
#include "G4TriangularFacet.hh"
#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"
#include "G4VisExtent.hh"

#include "MOLLEROptLightGuideSD.hh"

#include "MOLLEROptMaterial.hh"
#include "MOLLEROptTrackingReadout.hh"

class MOLLEROptDetectorLightGuide 
{
public:
  MOLLEROptDetectorLightGuide(MOLLEROptTrackingReadout*, G4String name, MOLLEROptMaterial*);
  ~MOLLEROptDetectorLightGuide();

  void Initialize();
  void Construct(G4VPhysicalVolume* MotherVolume);
  void SetMaterial(G4String materialName);

  G4LogicalVolume*   GetLogicalVolume()    {return GuideLogical;} 
  G4VPhysicalVolume* GetPhysicalVolume()   {return GuidePhysical;}
  G4VPhysicalVolume* GetCorePhysicalVolume() {return GuideCorePhysical;}
  
  void ClearVolumes();
  void DefineGeometry();
  void UpdateGeometry();
  void ExportGeometrySTL();
  void WriteSTLFacet(G4ThreeVector *vertices);
  
  void SetLowerInterfacePlane(G4double LowerPlane)   {LowerInterfacePlane = LowerPlane;};
  void SetUpperInterfacePlane(G4double UpperPlane)   {UpperInterfacePlane = UpperPlane; GuideTotalLength = UpperPlane;};
  void SetMiddleBoxHeight(G4double MiddlePlane)      {MiddleBoxHeight = MiddlePlane;};
  void SetLowerConeFrontFaceAngle(G4double angle)    {LowerConeFrontFaceAngle = angle;};
  void SetLowerConeBackFaceAngle(G4double angle)     {LowerConeBackFaceAngle = angle;};
  void SetLowerConeSideFaceAngle(G4double angle)     {LowerConeSideFaceAngle = angle;};
  void SetQuartzInterfaceOpeningZ(G4double size)     {QuartzInterfaceOpeningZ = size;};
  void SetQuartzInterfaceOpeningX(G4double size)     {QuartzInterfaceOpeningX = size;};
  void SetQuartzToPMTOffsetInZ(G4double val)         {QuartzToPMTOffsetInZ = val;};
  void SetCenterPositionInX(G4double xPos);
  void SetCenterPositionInY(G4double yPos);
  void SetCenterPositionInZ(G4double zPos);
  void SetPMTInterfaceOpeningZ(G4double size)        {PMTInterfaceOpeningZ = size;};
  void SetPMTInterfaceOpeningX(G4double size)        {PMTInterfaceOpeningX = size;};
  void SetPMTOpeningRadius(G4double val)             {PMTOpeningRadius = val;};
  G4double GetCurrentLowerInterfacePlane()     {return LowerInterfacePlane;};
  G4double GetCurrentUpperInterfacePlane()     {return UpperInterfacePlane;};
  G4double GetCurrentMiddleBoxHeight()         {return MiddleBoxHeight;};
  G4double GetCurrentLowerConeFrontFaceAngle() {return LowerConeFrontFaceAngle;};
  G4double GetCurrentLowerConeBackFaceAngle()  {return LowerConeBackFaceAngle;};
  G4double GetCurrentLowerConeSideFaceAngle()  {return LowerConeSideFaceAngle;};
  G4double GetCurrentPMTInterfaceOpeningY()    {return PMTInterfaceOpeningZ;};
  G4double GetCurrentPMTInterfaceOpeningX()    {return PMTInterfaceOpeningX;};
  G4double GetCurrentQuartzToPMTOffsetInZ()    {return QuartzToPMTOffsetInZ;};
  G4double GetCurrentCenterPositionInX()       {return GuidePhysical->GetTranslation().x();}//PositionX;};
  G4double GetCurrentCenterPositionInY()       {return GuidePhysical->GetTranslation().y();}//PositionY;};
  G4double GetCurrentCenterPositionInZ()       {return GuidePhysical->GetTranslation().z();}//PositionZ;};
  G4ThreeVector GetCurrentCenterPosition()     {return GuidePhysical->GetTranslation();};
  G4double GetLightGuideLength()               {return GuideTotalLength;};
  G4double GetLightGuideWidth()                {return GuideTotalWidth;};
  G4double GetLightGuideDepth()                {return GuideTotalDepth;};

  void GetLightGuideLimits(G4double *vals);
  void GetLightGuideLowerConeSideVertices(std::vector<G4TwoVector> *Vertices);

private:

  // void DefineOpticalProperties();
  void CreateOpticalSurface(G4LogicalVolume *logV);
  
  //void ConstructLightFace(LGFace face, double UL, double UR, double LR, double LL);
 
  G4String thisName;

  MOLLEROptTrackingReadout *TrackingReadout;

  //MOLLEROptLightGuideMessenger *Messenger;

  MOLLEROptMaterial*  Materials;

  G4VPhysicalVolume* Mother;

  G4Box*              GuideMiddleBoxSolid; //Box to be added between upper and lower LG cones
  G4Box*              GuideMiddleBoxSolid_out; //Outer skin of the box. Same purpose as LowerCone_out and UpperCone_out
  G4UnionSolid*	      IntermediateInnerSolid; //Same purpose as G4UnionSolid *InnerSolid and OuterSolid;
  G4UnionSolid*	      IntermediateOuterSolid; //

  G4Tubs*             GuideTopCutoutSolid;
  G4Box*              GuideTopBoxSolid;
  G4SubtractionSolid* GuideTopSolid;
  G4LogicalVolume*    GuideTopLogical; 
  G4VPhysicalVolume*  GuideTopPhysical; 

  G4LogicalVolume*    GuideLogical;
  G4VPhysicalVolume*  GuidePhysical; 
  G4Material*         GuideMaterial;
  G4OpticalSurface*   GuideOptSurface;
  G4LogicalSkinSurface* GuideLogicalSkinSurface;
  G4MaterialPropertiesTable* GuideMatPropTable;

  //tessellated solid variables 
  G4double targetSize;
  G4double panelDepth;
  
  G4TessellatedSolid  *panel1;
  G4QuadrangularFacet *facet11;
  G4QuadrangularFacet *facet12;
  G4QuadrangularFacet *facet13;
  G4QuadrangularFacet *facet14;
  G4QuadrangularFacet *facet15;
  G4QuadrangularFacet *facet16;

  G4TessellatedSolid  *panel2;
  G4QuadrangularFacet *facet21;
  G4QuadrangularFacet *facet22;
  G4QuadrangularFacet *facet23;
  G4QuadrangularFacet *facet24;
  G4QuadrangularFacet *facet25;
  G4QuadrangularFacet *facet26;

  G4TessellatedSolid  *panel3;
  G4QuadrangularFacet *facet31;
  G4QuadrangularFacet *facet32;
  G4QuadrangularFacet *facet33;
  G4QuadrangularFacet *facet34;
  G4QuadrangularFacet *facet35;
  G4QuadrangularFacet *facet36;

  G4TessellatedSolid  *panel4;
  G4QuadrangularFacet *facet41;
  G4QuadrangularFacet *facet42;
  G4QuadrangularFacet *facet43;
  G4QuadrangularFacet *facet44;
  G4QuadrangularFacet *facet45;
  G4QuadrangularFacet *facet46;

  G4TessellatedSolid  *panel5;
  G4QuadrangularFacet *facet51;
  G4QuadrangularFacet *facet52;
  G4QuadrangularFacet *facet53;
  G4QuadrangularFacet *facet54;
  G4QuadrangularFacet *facet55;
  G4QuadrangularFacet *facet56;

  G4TessellatedSolid  *panel6;
  G4QuadrangularFacet *facet61;
  G4QuadrangularFacet *facet62;
  G4QuadrangularFacet *facet63;
  G4QuadrangularFacet *facet64;
  G4QuadrangularFacet *facet65;
  G4QuadrangularFacet *facet66;

  G4TessellatedSolid  *panel7;
  G4QuadrangularFacet *facet71;
  G4QuadrangularFacet *facet72;
  G4QuadrangularFacet *facet73;
  G4QuadrangularFacet *facet74;
  G4QuadrangularFacet *facet75;
  G4QuadrangularFacet *facet76;

  G4TessellatedSolid  *panel8;
  G4QuadrangularFacet *facet81;
  G4QuadrangularFacet *facet82;
  G4QuadrangularFacet *facet83;
  G4QuadrangularFacet *facet84;
  G4QuadrangularFacet *facet85;
  G4QuadrangularFacet *facet86;

  G4TessellatedSolid  *panel9;
  G4QuadrangularFacet *facet91;
  G4QuadrangularFacet *facet92;
  G4QuadrangularFacet *facet93;
  G4QuadrangularFacet *facet94;
  G4QuadrangularFacet *facet95;
  G4QuadrangularFacet *facet96;

  G4TessellatedSolid  *panel10;
  G4QuadrangularFacet *facet101;
  G4QuadrangularFacet *facet102;
  G4QuadrangularFacet *facet103;
  G4QuadrangularFacet *facet104;
  G4QuadrangularFacet *facet105;
  G4QuadrangularFacet *facet106;

  G4TessellatedSolid  *panel11;
  G4QuadrangularFacet *facet111;
  G4QuadrangularFacet *facet112;
  G4QuadrangularFacet *facet113;
  G4QuadrangularFacet *facet114;
  G4QuadrangularFacet *facet115;
  G4QuadrangularFacet *facet116;

  G4TessellatedSolid  *panel12;
  G4QuadrangularFacet *facet121;
  G4QuadrangularFacet *facet122;
  G4QuadrangularFacet *facet123;
  G4QuadrangularFacet *facet124;
  G4QuadrangularFacet *facet125;
  G4QuadrangularFacet *facet126;


  G4LogicalVolume*    GuideCoreLogical;
  G4VPhysicalVolume*  GuideCorePhysical; 
  G4Material*         GuideCoreMaterial;
  G4SubtractionSolid* GuideCoreSolid;
  G4Box*              GuideCoreBottomCutoutSolid;
  
  G4double Anolux_UVS_PhotonEnergy[9];
  G4double Anolux_UVS_Reflectivity[9];
  
 
  G4ThreeVector     PositionLG;
  G4ThreeVector     PositionTP;
  G4RotationMatrix* RotationLG;  

  std::vector<G4TwoVector> LowerConeVertices;
  std::vector<G4TwoVector> UpperConeVertices;

  std::vector<G4TwoVector> LowerConeVertices_out;
  std::vector<G4TwoVector> UpperConeVertices_out;

  
  G4GenericTrap *LowerCone;
  G4GenericTrap *UpperCone;
  G4UnionSolid *InnerSolid;
  
  G4GenericTrap *LowerCone_out;
  G4GenericTrap *UpperCone_out;
  G4UnionSolid *OuterSolid;
  G4UnionSolid *GuideSolidTarget;

  //PanelAssembly objects
  G4UnionSolid *PanelAssembly1;
  G4UnionSolid *PanelAssembly2;
  G4UnionSolid *PanelAssembly3;
  G4UnionSolid *PanelAssembly4;
  G4UnionSolid *PanelAssembly5;
  G4UnionSolid *PanelAssembly6;
  G4UnionSolid *PanelAssembly7;
  G4UnionSolid *PanelAssembly8;
  G4UnionSolid *PanelAssembly9;
  G4UnionSolid *PanelAssembly10;
  G4UnionSolid *PanelAssembly11;

  // G4UnionSolid *GuideSolid;
  G4SubtractionSolid *GuideSolid;

  G4ThreeVector LowerConeBottom[5];
  G4ThreeVector LowerConeFront[5];
  G4ThreeVector LowerConeBack[5];
  G4ThreeVector LowerConeSide1[5];
  G4ThreeVector LowerConeSide2[5];

  G4ThreeVector MiddleBoxBottom[5];
  G4ThreeVector MiddleBoxFront[5];
  G4ThreeVector MiddleBoxBack[5];
  G4ThreeVector MiddleBoxSide1[5];
  G4ThreeVector MiddleBoxSide2[5];
         
  G4ThreeVector UpperConeFront[5];
  G4ThreeVector UpperConeBack[5];
  G4ThreeVector UpperConeSide1[5];
  G4ThreeVector UpperConeSide2[5];
  G4ThreeVector UpperConeTop[5];

  G4double LowerInterfacePlane; //See function SetInterfacePlanes(..) for explanation 
  G4double MiddleBoxHeight;     //Box between the upper and lower cones
  G4double UpperInterfacePlane;

  G4double LowerConeFrontFaceAngle; //Front meaning beam upstream and the angle (theta)
                                    //is measured w.r.t. the local positive z axis (up)
                                    //here standard spherical phi = 3pi/2 

  G4double LowerConeBackFaceAngle;  //Back meaning beam downstream (phi = pi/2)

  G4double LowerConeSideFaceAngle;  //The side faces may have an angle w.r.t to the positive
                                    //z-axis
  
  G4double QuartzInterfaceOpeningZ; //Size of the bottom opening of the guide, in the 
                                    //beam direction (along the local y direction)

  G4double QuartzInterfaceOpeningX; //Size of the bottom opening of the guide, in the 
                                    //beam left-right direction (along the local x direction)

  G4double PMTInterfaceOpeningZ; //Size of the top opening of the guide, in the 
                                 //beam direction (along the local y direction)

  G4double PMTInterfaceOpeningX; //Size of the top opening of the guide, in the 
                                 //beam left-right direction (along the local x direction)

  G4double QuartzToPMTOffsetInZ; //There will possibly be a location offset between the quartz
                                //and the PMT opening centers in the local y-direction.
                                //The center of the quartz interface opening is located at y = 0;

  G4double PMTOpeningRadius;
  G4double TopPlateThickness;

  G4double CenterPositionX;
  G4double CenterPositionZ;
  G4double CenterPositionY;

  G4double GuideTotalLength; //radial
  G4double GuideTotalWidth;  //beam left-right
  G4double GuideTotalDepth;  //beam direction
  
  ofstream STLFile;
  
  G4VSensitiveDetector* LightGuideSD;
  
};
#endif
