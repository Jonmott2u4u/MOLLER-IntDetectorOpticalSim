#ifndef MOLLEROptDetectorMessenger6_h
#define MOLLEROptDetectorMessenger6_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector6.hh"

class MOLLEROptDetector6;

class MOLLEROptDetectorMessenger6: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger6(MOLLEROptDetector6*);
    ~MOLLEROptDetectorMessenger6();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector6*         Det6;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd6;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd6;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd6;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd6;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd6;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd6;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd6;
  G4UIcmdWithoutParameter*   SegRadDamageCmd6;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd6;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd6;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd6;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd6;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd6;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd6;
};

#endif
