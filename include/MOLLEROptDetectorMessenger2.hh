#ifndef MOLLEROptDetectorMessenger2_h
#define MOLLEROptDetectorMessenger2_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector2.hh"

class MOLLEROptDetector2;

class MOLLEROptDetectorMessenger2: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger2(MOLLEROptDetector2*);
    ~MOLLEROptDetectorMessenger2();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector2*        Det2;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd;
  G4UIcmdWithAString*        DetMatCmd2;

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
