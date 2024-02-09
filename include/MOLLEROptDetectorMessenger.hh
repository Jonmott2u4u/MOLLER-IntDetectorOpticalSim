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
    MOLLEROptDetectorMessenger(MOLLEROptDetector*);
   ~MOLLEROptDetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
private:
  
  MOLLEROptDetector*         Det;
  G4UIdirectory*             Dir;
  G4UIdirectory*             Dir1;
  G4UIdirectory*             Dir2;
  G4UIdirectory*             Dir3;
  G4UIdirectory*             Dir4;
  G4UIdirectory*             Dir5;
  G4UIdirectory*             Dir6;
  G4UIdirectory*             Dir7;
  G4UIdirectory*             Dir8;
  G4UIdirectory*             Dir9;
  G4UIdirectory*             Dir10;
  G4UIdirectory*             Dir11;
  G4UIcmdWithAString*        DetMatCmd;
  
  //Ring 1 objects
  G4UIcmdWithADoubleAndUnit* DetXPositionCmd1;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmd1;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideUpperInterfaceCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideMiddleBoxCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerInterfaceCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeFrontAngleCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeBackAngleCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideLowerConeSideAngleCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningXCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzInterfaceOpeningZCmd1;
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd1;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd1;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd1;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd1;

  //Ring 2 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd2;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd2;

  //Ring 3 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd3;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd3;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd3;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd3;

  //Ring 4 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd4;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd4;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd4;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd4;

  //Ring 5 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd5;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd5;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd5;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd5;

  //Ring 6 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd6;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd6;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd6;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd6;

  //Ring 7 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd7;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd7;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd7;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd7;

  //Ring 8 objects
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
  G4UIcmdWithADoubleAndUnit* LightGuideQuartzToPMTOffsetCmd8;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmd8;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmd8;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmd8;

  //Scintillator commands
  G4UIcmdWithADoubleAndUnit* DetXPositionCmdScint;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmdScint;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmdScint;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmdScint;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmdScint;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmdScint;

  //GEM Scintillator 1 commands
  G4UIcmdWithADoubleAndUnit* DetXPositionCmdGEMScint1;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmdGEMScint1;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmdGEMScint1;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmdGEMScint1;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmdGEMScint1;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmdGEMScint1;

  //GEM Scintillator 2 commands
  G4UIcmdWithADoubleAndUnit* DetXPositionCmdGEMScint2;
  G4UIcmdWithADoubleAndUnit* DetYPositionCmdGEMScint2;
  G4UIcmdWithADoubleAndUnit* DetZPositionCmdGEMScint2;
  G4UIcmdWithADoubleAndUnit* QuartzSizeXCmdGEMScint2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeYCmdGEMScint2;       
  G4UIcmdWithADoubleAndUnit* QuartzSizeZCmdGEMScint2;

  //General commands
  G4UIcmdWithADoubleAndUnit* QuartzBevelCmd;                       
  G4UIcmdWithADoubleAndUnit* QuartzRotXCmd;
  G4UIcmdWithADoubleAndUnit* PolarRotationCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuidePMTInterfaceOpeningZCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetXCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetYCmd;
  G4UIcmdWithADoubleAndUnit* LightGuideOffsetZCmd;

  G4UIcmdWithoutParameter*   UpdateGeometryCmd;
  G4UIcmdWithoutParameter*   SegRadDamageCmd;

};

#endif
