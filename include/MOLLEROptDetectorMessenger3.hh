#ifndef MOLLEROptDetectorMessenger3_h
#define MOLLEROptDetectorMessenger3_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector3.hh"

class MOLLEROptDetector3;

class MOLLEROptDetectorMessenger3: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger3(MOLLEROptDetector3*);
    ~MOLLEROptDetectorMessenger3();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector3*         Det3;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd3;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd3;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd3;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd3;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd3;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd3;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd3;
  G4UIcmdWithoutParameter*   SegRadDamageCmd3;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd3;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd3;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd3;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd3;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd3;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd3;
};

#endif
