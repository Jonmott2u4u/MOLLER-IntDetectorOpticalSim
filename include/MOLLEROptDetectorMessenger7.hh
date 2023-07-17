#ifndef MOLLEROptDetectorMessenger7_h
#define MOLLEROptDetectorMessenger7_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector7.hh"

class MOLLEROptDetector7;

class MOLLEROptDetectorMessenger7: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger7(MOLLEROptDetector7*);
    ~MOLLEROptDetectorMessenger7();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector7*         Det7;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd7;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd7;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd7;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd7;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd7;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd7;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd7;
  G4UIcmdWithoutParameter*   SegRadDamageCmd7;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd7;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd7;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd7;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd7;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd7;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd7;
};

#endif
