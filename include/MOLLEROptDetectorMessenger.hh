#ifndef MOLLEROptDetectorMessenger_h
#define MOLLEROptDetectorMessenger_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptDetector.hh"

class MOLLEROptDetector;

class MOLLEROptDetectorMessenger: public G4UImessenger
{
  public:
    MOLLEROptDetectorMessenger(MOLLEROptDetector*, G4String);
   ~MOLLEROptDetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  G4String                   DetType;
  MOLLEROptDetector*         Det;
  G4UIdirectory*             Dir;

  G4UIcmdWithAString*        DetMatCmd;
  
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd;
  G4UIcmdWithADoubleAndUnit* TungstenSizeXCmd;
  G4UIcmdWithADoubleAndUnit* TungstenSizeYCmd;
  G4UIcmdWithADoubleAndUnit* TungstenSizeZCmd;

  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd;    
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd;
  G4UIcmdWithADoubleAndUnit* YawRotationCmd;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd;
  G4UIcmdWithADoubleAndUnit* AzimuthalRotationCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd;

  G4UIcmdWithoutParameter*   UpdateGeometryCmd;

};

#endif
