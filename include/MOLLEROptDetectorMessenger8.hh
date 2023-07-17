#ifndef MOLLEROptDetectorMessenger8_h
#define MOLLEROptDetectorMessenger8_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector8.hh"

class MOLLEROptDetector8;

class MOLLEROptDetectorMessenger8: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger8(MOLLEROptDetector8*);
    ~MOLLEROptDetectorMessenger8();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector8*         Det8;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd8;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd8;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd8;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd8;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd8;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd8;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd8;
  G4UIcmdWithoutParameter*   SegRadDamageCmd8;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd8;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd8;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd8;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd8;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd8;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd8;
};

#endif
