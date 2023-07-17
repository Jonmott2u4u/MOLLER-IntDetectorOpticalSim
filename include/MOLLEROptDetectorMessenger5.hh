#ifndef MOLLEROptDetectorMessenger5_h
#define MOLLEROptDetectorMessenger5_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector5.hh"

class MOLLEROptDetector5;

class MOLLEROptDetectorMessenger5: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger5(MOLLEROptDetector5*);
    ~MOLLEROptDetectorMessenger5();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector5*         Det5;
  G4UIdirectory*             Dir;
  G4UIcmdWithAString*        DetMatCmd5;
  G4UIcmdWithAString*        DetMatCmd2;

  G4UIcmdWithADoubleAndUnit* DetXPositionCmd5;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd5;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd5;

  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd5;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd5;
    
  G4UIcmdWithoutParameter*   UpdateGeometryCmd5;
  G4UIcmdWithoutParameter*   SegRadDamageCmd5;

  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd5;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd5;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd5;                       
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd5;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd5;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd5;
};

#endif
