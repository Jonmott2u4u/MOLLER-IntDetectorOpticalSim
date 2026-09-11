# include "MOLLEROptDetectorSpacer.hh"
#include "G4Version.hh"


MOLLEROptDetectorSpacer::MOLLEROptDetectorSpacer(G4String name, MOLLEROptMaterial* mat)
{
  Name = name+"_Spacer";

  SpacerWidth       = 265*mm;
  SpacerHeight      = 160*mm;
  SpacerThickness   = 0.870*mm;

  Materials = mat;
  SpacerMaterial = Materials->GetMaterial("Aluminum");

  SpacerSolid = NULL;
  SpacerLogical = NULL;
  SpacerPhysical = NULL;

  RotationSpacer = NULL;

}

MOLLEROptDetectorSpacer::~MOLLEROptDetectorSpacer()
{

}

void MOLLEROptDetectorSpacer::ClearVolumes()
{
  if(SpacerOptSurface) delete SpacerOptSurface;
  if(SpacerLogicalSkinSurface) delete SpacerLogicalSkinSurface;
  if(SpacerLogical) delete SpacerLogical;
  if(SpacerPhysical) delete SpacerPhysical;

}

void MOLLEROptDetectorSpacer::Construct(G4VPhysicalVolume* MotherVolume)
{
  Mother = MotherVolume;
  
  SpacerPhysical   = new G4PVPlacement(RotationSpacer,PositionSpacer,Name+"_Physical",SpacerLogical,Mother,false,0);

  SpacerPhysical->CheckOverlaps();

}

void MOLLEROptDetectorSpacer::CreateOpticalSurface(G4LogicalVolume *logV, string mat_flag)
{
  OptParam* Optpar = Materials->GetOpticalParametersTable();
  SpacerOptSurface = new G4OpticalSurface(Name+"_OpSurface",glisur,polished,dielectric_metal);

  #if G4VERSION_NUMBER >= 1100
  G4MaterialPropertiesTable *SpacerMatPropTable = new G4MaterialPropertiesTable();
  if (mat_flag == "Mylar") {
    /*SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE00", Optpar->EPhoton, Optpar->LGRefl90, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl60, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl30, Optpar->GetNPar(), true);*/
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE90", Optpar->EPhoton, Optpar->LGRefl90Mylar, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl60Mylar, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45Mylar, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl30Mylar, Optpar->GetNPar(), true);
  }
  else if (mat_flag == "MiroIV") {
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE90", Optpar->EPhoton, Optpar->LGRefl90MiroIV, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl60MiroIV, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45MiroIV, Optpar->GetNPar(), true);
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl30MiroIV, Optpar->GetNPar(), true);
  }
  #else
  G4MaterialPropertiesTable *SpacerMatPropTable = new G4MaterialPropertiesTable();
  if (mat_flag == Mylar) {
    /*SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE00", Optpar->EPhoton, Optpar->LGRefl90, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl60, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl30, Optpar->GetNPar());*/
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE90", Optpar->EPhoton, Optpar->LGRefl90Mylar, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl60Mylar, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45Mylar, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl30Mylar, Optpar->GetNPar());
  }
  else if (mat_flag == MiroIV) {
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE90", Optpar->EPhoton, Optpar->LGRefl90MiroIV, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE60", Optpar->EPhoton, Optpar->LGRefl60MiroIV, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE45", Optpar->EPhoton, Optpar->LGRefl45MiroIV, Optpar->GetNPar());
    SpacerMatPropTable->AddProperty ( "ANGLEREFLECTANCE30", Optpar->EPhoton, Optpar->LGRefl30MiroIV, Optpar->GetNPar());
  }
  #endif

  SpacerOptSurface->SetMaterialPropertiesTable(SpacerMatPropTable);
  SpacerLogicalSkinSurface = new G4LogicalSkinSurface(Name+"_SkinSurface",logV,SpacerOptSurface);

}

void MOLLEROptDetectorSpacer::SetCenterPositionInX(G4double x)
{
  CenterPositionX = x;
  SpacerPhysical->SetTranslation(G4ThreeVector(CenterPositionX,CenterPositionY,CenterPositionZ));
}
void MOLLEROptDetectorSpacer::SetCenterPositionInY(G4double y)
{
  CenterPositionY = y;
  SpacerPhysical->SetTranslation(G4ThreeVector(CenterPositionX,CenterPositionY,CenterPositionZ));
}
void MOLLEROptDetectorSpacer::SetCenterPositionInZ(G4double z)
{
  CenterPositionZ = z;
  SpacerPhysical->SetTranslation(G4ThreeVector(CenterPositionX,CenterPositionY,CenterPositionZ));
}

void MOLLEROptDetectorSpacer::Initialize(string mat_flag)
{
    SpacerSolid = new G4Box(Name+"_Solid",SpacerWidth/2,SpacerHeight/2,SpacerThickness/2);
    SpacerLogical = new G4LogicalVolume(SpacerSolid,SpacerMaterial,Name+"_Logical");
    
    CreateOpticalSurface(SpacerLogical, mat_flag);
    
    PositionSpacer  = G4ThreeVector(CenterPositionX,CenterPositionY,CenterPositionZ);
    RotationSpacer = new G4RotationMatrix;
    //RotationSpacer->rotateX(0.0*degree);

    G4Colour blue ( 0.0, 0.0, 1.0);
    G4VisAttributes* VisAtt = new G4VisAttributes(blue);
    VisAtt->SetVisibility(true);
    VisAtt->SetForceWireframe(true);
    SpacerLogical->SetVisAttributes(VisAtt);
  
}

void MOLLEROptDetectorSpacer::UpdateGeometry()
{
    G4SolidStore::GetInstance()->DeRegister(SpacerSolid);

    delete SpacerSolid;

    SpacerSolid = new G4Box(Name+"_Solid",SpacerWidth/2,SpacerHeight/2,SpacerThickness/2);
    SpacerLogical->SetSolid(SpacerSolid);
}