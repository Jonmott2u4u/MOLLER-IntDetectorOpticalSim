#ifndef MOLLEROptDetectorMessenger4_h
#define MOLLEROptDetectorMessenger4_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector4.hh"

class MOLLEROptDetector4;

class MOLLEROptDetectorMessenger4: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger4(MOLLEROptDetector4*);
    ~MOLLEROptDetectorMessenger4();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector4*         Det4;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd4;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd4;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd4;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd4;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd4;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd4;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd4;
  G4UIcmdWithoutParameter*   SegRadDamageCmd4;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd4;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd4;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd4;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd4;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd4;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd4;
};

#endif
