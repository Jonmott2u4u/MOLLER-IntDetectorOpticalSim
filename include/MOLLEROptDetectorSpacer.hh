#ifndef MOLLEROptDetectorSpacer_h
#define MOLLEROptDetectorSpacer_h

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh"
#include "G4VisExtent.hh"

#include "MOLLEROptMaterial.hh"

class MOLLEROptDetectorSpacer 
{
public:
    MOLLEROptDetectorSpacer(G4String name, MOLLEROptMaterial* mat);
    ~MOLLEROptDetectorSpacer();

    G4LogicalVolume*   GetLogicalVolume()    {return SpacerLogical;}
    G4VPhysicalVolume* GetPhysicalVolume()   {return SpacerPhysical;}

    void Initialize(string mat_flag);
    void Construct(G4VPhysicalVolume* MotherVolume);
    void ClearVolumes();
    void UpdateGeometry();

    void SetCenterPositionInX(G4double x);
    void SetCenterPositionInY(G4double y);
    void SetCenterPositionInZ(G4double z);
    void SetSizeX(G4double x) {SpacerWidth = x;};
    void SetSizeY(G4double y) {SpacerHeight = y;};
    void SetSizeZ(G4double z) {SpacerThickness = z;};
    
    G4double GetCurrentCenterPositionInX()   {return SpacerPhysical->GetTranslation().x();};
    G4double GetCurrentCenterPositionInY()   {return SpacerPhysical->GetTranslation().y();};
    G4double GetCurrentCenterPositionInZ()   {return SpacerPhysical->GetTranslation().z();};

    G4double GetSizeX() {return SpacerWidth;};
    G4double GetSizeY() {return SpacerHeight;};
    G4double GetSizeZ() {return SpacerThickness;};

private:
    void CreateOpticalSurface(G4LogicalVolume *logV, string mat_flag);

    G4String Name;
    MOLLEROptMaterial* Materials;
    
    G4Box* SpacerSolid;
    G4VPhysicalVolume* Mother;
    G4VPhysicalVolume* SpacerPhysical;
    G4LogicalVolume*   SpacerLogical;
    G4OpticalSurface* SpacerOptSurface;
    G4LogicalSkinSurface* SpacerLogicalSkinSurface;
    G4MaterialPropertiesTable* SpacerMatPropTable;

    G4double SpacerWidth;
    G4double SpacerHeight;
    G4double SpacerThickness;
    G4double CenterPositionX;
    G4double CenterPositionZ;
    G4double CenterPositionY;
    G4ThreeVector PositionSpacer;
    G4RotationMatrix* RotationSpacer;

    OptParam* Optpar;
    G4Material* SpacerMaterial;


};
#endif