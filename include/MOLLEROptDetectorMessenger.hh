#ifndef MOLLEROptDetectorMessenger_h
#define MOLLEROptDetectorMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector.hh"

class MOLLEROptDetector;
class MOLLEROptDetector_Copy;

class MOLLEROptDetectorMessenger: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger(MOLLEROptDetector*);
    MOLLEROptDetectorMessenger(MOLLEROptDetector_Copy*);
    ~MOLLEROptDetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector*         Det;
  MOLLEROptDetector_Copy*    Det_Copy;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd;
  G4UIcmdWithoutParameter*   SegRadDamageCmd;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd;

  //Det_Copy commands

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd2;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd2;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd2;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd2;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd2;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd2;
  G4UIcmdWithoutParameter*   SegRadDamageCmd2;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd2;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd2;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd2;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd2;
};

#endif
