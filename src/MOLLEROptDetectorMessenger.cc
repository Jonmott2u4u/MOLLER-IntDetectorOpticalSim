#include "MOLLEROptDetectorMessenger.hh"

MOLLEROptDetectorMessenger::MOLLEROptDetectorMessenger(MOLLEROptDetector* theDet)
  :Det(theDet)
{ 

  Dir = new G4UIdirectory("/Det/");
  Dir1 = new G4UIdirectory("/R1/");
  Dir2 = new G4UIdirectory("/R2/");
  Dir3 = new G4UIdirectory("/R3/");
  Dir4 = new G4UIdirectory("/R4/");
  Dir5 = new G4UIdirectory("/R5/");
  Dir6 = new G4UIdirectory("/R6/");
  Dir7 = new G4UIdirectory("/R7/");
  Dir8 = new G4UIdirectory("/R8/");
  Dir9 = new G4UIdirectory("/Scint1/");
  Dir10 = new G4UIdirectory("/Scint2/");
  Dir11 = new G4UIdirectory("/Scint3/");
  Dir12 = new G4UIdirectory("/Scint4/");
  Dir -> SetGuidance("General ring control.");
  Dir1 -> SetGuidance("R1 control.");
  Dir2 -> SetGuidance("R2 control.");
  Dir3 -> SetGuidance("R3 control.");
  Dir4 -> SetGuidance("R4 control.");
  Dir5 -> SetGuidance("R5 control.");
  Dir6 -> SetGuidance("R6 control.");
  Dir7 -> SetGuidance("R7 control.");
  Dir8 -> SetGuidance("R8 control.");
  Dir9 -> SetGuidance("Scint1 control.");
  Dir10 -> SetGuidance("Scint2 control.");
  Dir11 -> SetGuidance("Scint3 control.");
  Dir12 -> SetGuidance("Scint4 control.");
  
  //Ring 1 commands
  DetZPositionCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/SetCenterPositionInZ",this);
  DetZPositionCmd1->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd1->SetParameterName("Size",true);
  DetZPositionCmd1->SetUnitCategory("Length");
  DetZPositionCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/SetCenterPositionInY",this);
  DetYPositionCmd1->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd1->SetParameterName("Size",true);
  DetYPositionCmd1->SetUnitCategory("Length");
  DetYPositionCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/SetCenterPositionInX",this);
  DetXPositionCmd1->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd1->SetParameterName("Size",true);
  DetXPositionCmd1->SetUnitCategory("Length");
  DetXPositionCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd1->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd1->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd1->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd1->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd1->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd1->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd1->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd1->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd1->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd1->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd1->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd1->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd1->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd1->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd1->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd1->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd1->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd1->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd1->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd1->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd1->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd1->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd1->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd1->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd1->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd1->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd1->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/QuartzSizeZ",this);
  QuartzSizeZCmd1->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd1->SetParameterName("Size",true);
  QuartzSizeZCmd1->SetUnitCategory("Length");
  QuartzSizeZCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/QuartzSizeY",this);
  QuartzSizeYCmd1->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd1->SetParameterName("Size",true);
  QuartzSizeYCmd1->SetUnitCategory("Length");
  QuartzSizeYCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/QuartzSizeX",this);
  QuartzSizeXCmd1->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd1->SetParameterName("Size",true);
  QuartzSizeXCmd1->SetUnitCategory("Length");
  QuartzSizeXCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd1 =  new G4UIcmdWithADoubleAndUnit("/R1/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd1->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd1->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd1->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd1->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 2 objects
  DetZPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/SetCenterPositionInZ",this);
  DetZPositionCmd2->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd2->SetParameterName("Size",true);
  DetZPositionCmd2->SetUnitCategory("Length");
  DetZPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/SetCenterPositionInY",this);
  DetYPositionCmd2->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd2->SetParameterName("Size",true);
  DetYPositionCmd2->SetUnitCategory("Length");
  DetYPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/SetCenterPositionInX",this);
  DetXPositionCmd2->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd2->SetParameterName("Size",true);
  DetXPositionCmd2->SetUnitCategory("Length");
  DetXPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd2->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd2->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd2->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd2->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd2->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd2->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd2->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd2->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd2->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd2->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");
  LightGuideLowerConeFrontAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd2->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd2->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd2->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd2->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd2->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd2->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd2->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd2->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/QuartzSizeZ",this);
  QuartzSizeZCmd2->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd2->SetParameterName("Size",true);
  QuartzSizeZCmd2->SetUnitCategory("Length");
  QuartzSizeZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/QuartzSizeY",this);
  QuartzSizeYCmd2->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd2->SetParameterName("Size",true);
  QuartzSizeYCmd2->SetUnitCategory("Length");
  QuartzSizeYCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/QuartzSizeX",this);
  QuartzSizeXCmd2->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd2->SetParameterName("Size",true);
  QuartzSizeXCmd2->SetUnitCategory("Length");
  QuartzSizeXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd2 =  new G4UIcmdWithADoubleAndUnit("/R2/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd2->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd2->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd2->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  //Ring 3 commands
  DetZPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/SetCenterPositionInZ",this);
  DetZPositionCmd3->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd3->SetParameterName("Size",true);
  DetZPositionCmd3->SetUnitCategory("Length");
  DetZPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/SetCenterPositionInY",this);
  DetYPositionCmd3->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd3->SetParameterName("Size",true);
  DetYPositionCmd3->SetUnitCategory("Length");
  DetYPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/SetCenterPositionInX",this);
  DetXPositionCmd3->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd3->SetParameterName("Size",true);
  DetXPositionCmd3->SetUnitCategory("Length");
  DetXPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd3->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd3->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd3->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd3->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd3->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd3->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd3->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd3->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd3->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd3->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd3->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd3->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd3->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd3->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd3->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd3->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd3->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd3->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/QuartzSizeZ",this);
  QuartzSizeZCmd3->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd3->SetParameterName("Size",true);
  QuartzSizeZCmd3->SetUnitCategory("Length");
  QuartzSizeZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/QuartzSizeY",this);
  QuartzSizeYCmd3->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd3->SetParameterName("Size",true);
  QuartzSizeYCmd3->SetUnitCategory("Length");
  QuartzSizeYCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/QuartzSizeX",this);
  QuartzSizeXCmd3->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd3->SetParameterName("Size",true);
  QuartzSizeXCmd3->SetUnitCategory("Length");
  QuartzSizeXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd3 =  new G4UIcmdWithADoubleAndUnit("/R3/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd3->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd3->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd3->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 4 commands
  DetZPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/SetCenterPositionInZ",this);
  DetZPositionCmd4->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd4->SetParameterName("Size",true);
  DetZPositionCmd4->SetUnitCategory("Length");
  DetZPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/SetCenterPositionInY",this);
  DetYPositionCmd4->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd4->SetParameterName("Size",true);
  DetYPositionCmd4->SetUnitCategory("Length");
  DetYPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/SetCenterPositionInX",this);
  DetXPositionCmd4->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd4->SetParameterName("Size",true);
  DetXPositionCmd4->SetUnitCategory("Length");
  DetXPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd4->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd4->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd4->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd4->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd4->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd4->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd4->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd4->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd4->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd4->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd4->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd4->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd4->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd4->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd4->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd4->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd4->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd4->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/QuartzSizeZ",this);
  QuartzSizeZCmd4->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd4->SetParameterName("Size",true);
  QuartzSizeZCmd4->SetUnitCategory("Length");
  QuartzSizeZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/QuartzSizeY",this);
  QuartzSizeYCmd4->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd4->SetParameterName("Size",true);
  QuartzSizeYCmd4->SetUnitCategory("Length");
  QuartzSizeYCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/QuartzSizeX",this);
  QuartzSizeXCmd4->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd4->SetParameterName("Size",true);
  QuartzSizeXCmd4->SetUnitCategory("Length");
  QuartzSizeXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd4 =  new G4UIcmdWithADoubleAndUnit("/R4/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd4->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd4->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd4->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 5 commands
  DetZPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/SetCenterPositionInZ",this);
  DetZPositionCmd5->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd5->SetParameterName("Size",true);
  DetZPositionCmd5->SetUnitCategory("Length");
  DetZPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/SetCenterPositionInY",this);
  DetYPositionCmd5->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd5->SetParameterName("Size",true);
  DetYPositionCmd5->SetUnitCategory("Length");
  DetYPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/SetCenterPositionInX",this);
  DetXPositionCmd5->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd5->SetParameterName("Size",true);
  DetXPositionCmd5->SetUnitCategory("Length");
  DetXPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd5->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd5->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd5->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd5->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd5->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd5->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd5->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd5->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd5->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd5->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd5->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd5->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd5->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd5->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd5->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd5->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd5->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd5->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/QuartzSizeZ",this);
  QuartzSizeZCmd5->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd5->SetParameterName("Size",true);
  QuartzSizeZCmd5->SetUnitCategory("Length");
  QuartzSizeZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/QuartzSizeY",this);
  QuartzSizeYCmd5->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd5->SetParameterName("Size",true);
  QuartzSizeYCmd5->SetUnitCategory("Length");
  QuartzSizeYCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/QuartzSizeX",this);
  QuartzSizeXCmd5->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd5->SetParameterName("Size",true);
  QuartzSizeXCmd5->SetUnitCategory("Length");
  QuartzSizeXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd5 =  new G4UIcmdWithADoubleAndUnit("/R5/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd5->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd5->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd5->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 6 commands
  DetZPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/SetCenterPositionInZ",this);
  DetZPositionCmd6->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd6->SetParameterName("Size",true);
  DetZPositionCmd6->SetUnitCategory("Length");
  DetZPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/SetCenterPositionInY",this);
  DetYPositionCmd6->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd6->SetParameterName("Size",true);
  DetYPositionCmd6->SetUnitCategory("Length");
  DetYPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/SetCenterPositionInX",this);
  DetXPositionCmd6->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd6->SetParameterName("Size",true);
  DetXPositionCmd6->SetUnitCategory("Length");
  DetXPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd6->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd6->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd6->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd6->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd6->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd6->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd6->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd6->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd6->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd6->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd6->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd6->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd6->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd6->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd6->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd6->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd6->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd6->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/QuartzSizeZ",this);
  QuartzSizeZCmd6->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd6->SetParameterName("Size",true);
  QuartzSizeZCmd6->SetUnitCategory("Length");
  QuartzSizeZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/QuartzSizeY",this);
  QuartzSizeYCmd6->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd6->SetParameterName("Size",true);
  QuartzSizeYCmd6->SetUnitCategory("Length");
  QuartzSizeYCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/QuartzSizeX",this);
  QuartzSizeXCmd6->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd6->SetParameterName("Size",true);
  QuartzSizeXCmd6->SetUnitCategory("Length");
  QuartzSizeXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd6 =  new G4UIcmdWithADoubleAndUnit("/R6/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd6->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd6->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd6->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 7 commands
  DetZPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/SetCenterPositionInZ",this);
  DetZPositionCmd7->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd7->SetParameterName("Size",true);
  DetZPositionCmd7->SetUnitCategory("Length");
  DetZPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/SetCenterPositionInY",this);
  DetYPositionCmd7->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd7->SetParameterName("Size",true);
  DetYPositionCmd7->SetUnitCategory("Length");
  DetYPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/SetCenterPositionInX",this);
  DetXPositionCmd7->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd7->SetParameterName("Size",true);
  DetXPositionCmd7->SetUnitCategory("Length");
  DetXPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd7->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd7->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd7->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd7->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd7->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd7->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd7->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd7->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd7->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd7->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd7->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd7->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd7->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd7->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd7->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd7->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd7->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd7->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/QuartzSizeZ",this);
  QuartzSizeZCmd7->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd7->SetParameterName("Size",true);
  QuartzSizeZCmd7->SetUnitCategory("Length");
  QuartzSizeZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/QuartzSizeY",this);
  QuartzSizeYCmd7->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd7->SetParameterName("Size",true);
  QuartzSizeYCmd7->SetUnitCategory("Length");
  QuartzSizeYCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/QuartzSizeX",this);
  QuartzSizeXCmd7->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd7->SetParameterName("Size",true);
  QuartzSizeXCmd7->SetUnitCategory("Length");
  QuartzSizeXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd7 =  new G4UIcmdWithADoubleAndUnit("/R7/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd7->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd7->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd7->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //Ring 8 commands
  DetZPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/SetCenterPositionInZ",this);
  DetZPositionCmd8->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd8->SetParameterName("Size",true);
  DetZPositionCmd8->SetUnitCategory("Length");
  DetZPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/SetCenterPositionInY",this);
  DetYPositionCmd8->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd8->SetParameterName("Size",true);
  DetYPositionCmd8->SetUnitCategory("Length");
  DetYPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/SetCenterPositionInX",this);
  DetXPositionCmd8->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd8->SetParameterName("Size",true);
  DetXPositionCmd8->SetUnitCategory("Length");
  DetXPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd8->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd8->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd8->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd8->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd8->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd8->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd8->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd8->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd8->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd8->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd8->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd8->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd8->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd8->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd8->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd8->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd8->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd8->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/QuartzSizeZ",this);
  QuartzSizeZCmd8->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd8->SetParameterName("Size",true);
  QuartzSizeZCmd8->SetUnitCategory("Length");
  QuartzSizeZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/QuartzSizeY",this);
  QuartzSizeYCmd8->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd8->SetParameterName("Size",true);
  QuartzSizeYCmd8->SetUnitCategory("Length");
  QuartzSizeYCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/QuartzSizeX",this);
  QuartzSizeXCmd8->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd8->SetParameterName("Size",true);
  QuartzSizeXCmd8->SetUnitCategory("Length");
  QuartzSizeXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd8 =  new G4UIcmdWithADoubleAndUnit("/R8/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd8->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd8->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd8->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  //Scint1 objects
  DetZPositionCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/SetCenterPositionInZ",this);
  DetZPositionCmdScint1->SetGuidance("Set the Z position of the Scintillator"); 
  DetZPositionCmdScint1->SetParameterName("Size",true);
  DetZPositionCmdScint1->SetUnitCategory("Length");
  DetZPositionCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/SetCenterPositionInY",this);
  DetYPositionCmdScint1->SetGuidance("Set the Y position of the Scint1illator"); 
  DetYPositionCmdScint1->SetParameterName("Size",true);
  DetYPositionCmdScint1->SetUnitCategory("Length");
  DetYPositionCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/SetCenterPositionInX",this);
  DetXPositionCmdScint1->SetGuidance("Set the X position of the Scint1illator"); 
  DetXPositionCmdScint1->SetParameterName("Size",true);
  DetXPositionCmdScint1->SetUnitCategory("Length");
  DetXPositionCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/QuartzSizeZ",this);
  QuartzSizeZCmdScint1->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmdScint1->SetParameterName("Size",true);
  QuartzSizeZCmdScint1->SetUnitCategory("Length");
  QuartzSizeZCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/QuartzSizeY",this);
  QuartzSizeYCmdScint1->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmdScint1->SetParameterName("Size",true);
  QuartzSizeYCmdScint1->SetUnitCategory("Length");
  QuartzSizeYCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmdScint1 =  new G4UIcmdWithADoubleAndUnit("/Scint1/QuartzSizeX",this);
  QuartzSizeXCmdScint1->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmdScint1->SetParameterName("Size",true);
  QuartzSizeXCmdScint1->SetUnitCategory("Length");
  QuartzSizeXCmdScint1->AvailableForStates(G4State_PreInit,G4State_Idle);

  //Scint2 objects
  DetZPositionCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/SetCenterPositionInZ",this);
  DetZPositionCmdScint2->SetGuidance("Set the Z position of the Scintillator"); 
  DetZPositionCmdScint2->SetParameterName("Size",true);
  DetZPositionCmdScint2->SetUnitCategory("Length");
  DetZPositionCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/SetCenterPositionInY",this);
  DetYPositionCmdScint2->SetGuidance("Set the Y position of the Scintillator"); 
  DetYPositionCmdScint2->SetParameterName("Size",true);
  DetYPositionCmdScint2->SetUnitCategory("Length");
  DetYPositionCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/SetCenterPositionInX",this);
  DetXPositionCmdScint2->SetGuidance("Set the X position of the Scintillator"); 
  DetXPositionCmdScint2->SetParameterName("Size",true);
  DetXPositionCmdScint2->SetUnitCategory("Length");
  DetXPositionCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/QuartzSizeZ",this);
  QuartzSizeZCmdScint2->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmdScint2->SetParameterName("Size",true);
  QuartzSizeZCmdScint2->SetUnitCategory("Length");
  QuartzSizeZCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/QuartzSizeY",this);
  QuartzSizeYCmdScint2->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmdScint2->SetParameterName("Size",true);
  QuartzSizeYCmdScint2->SetUnitCategory("Length");
  QuartzSizeYCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmdScint2 =  new G4UIcmdWithADoubleAndUnit("/Scint2/QuartzSizeX",this);
  QuartzSizeXCmdScint2->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmdScint2->SetParameterName("Size",true);
  QuartzSizeXCmdScint2->SetUnitCategory("Length");
  QuartzSizeXCmdScint2->AvailableForStates(G4State_PreInit,G4State_Idle);

  //Scint3 objects
  DetZPositionCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/SetCenterPositionInZ",this);
  DetZPositionCmdScint3->SetGuidance("Set the Z position of the Scintillator"); 
  DetZPositionCmdScint3->SetParameterName("Size",true);
  DetZPositionCmdScint3->SetUnitCategory("Length");
  DetZPositionCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/SetCenterPositionInY",this);
  DetYPositionCmdScint3->SetGuidance("Set the Y position of the Scintillator"); 
  DetYPositionCmdScint3->SetParameterName("Size",true);
  DetYPositionCmdScint3->SetUnitCategory("Length");
  DetYPositionCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/SetCenterPositionInX",this);
  DetXPositionCmdScint3->SetGuidance("Set the X position of the Scintillator"); 
  DetXPositionCmdScint3->SetParameterName("Size",true);
  DetXPositionCmdScint3->SetUnitCategory("Length");
  DetXPositionCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/QuartzSizeZ",this);
  QuartzSizeZCmdScint3->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmdScint3->SetParameterName("Size",true);
  QuartzSizeZCmdScint3->SetUnitCategory("Length");
  QuartzSizeZCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/QuartzSizeY",this);
  QuartzSizeYCmdScint3->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmdScint3->SetParameterName("Size",true);
  QuartzSizeYCmdScint3->SetUnitCategory("Length");
  QuartzSizeYCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmdScint3 =  new G4UIcmdWithADoubleAndUnit("/Scint3/QuartzSizeX",this);
  QuartzSizeXCmdScint3->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmdScint3->SetParameterName("Size",true);
  QuartzSizeXCmdScint3->SetUnitCategory("Length");
  QuartzSizeXCmdScint3->AvailableForStates(G4State_PreInit,G4State_Idle);

  //Scint4 objects
  DetZPositionCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/SetCenterPositionInZ",this);
  DetZPositionCmdScint4->SetGuidance("Set the Z position of the Scintillator"); 
  DetZPositionCmdScint4->SetParameterName("Size",true);
  DetZPositionCmdScint4->SetUnitCategory("Length");
  DetZPositionCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/SetCenterPositionInY",this);
  DetYPositionCmdScint4->SetGuidance("Set the Y position of the Scintillator"); 
  DetYPositionCmdScint4->SetParameterName("Size",true);
  DetYPositionCmdScint4->SetUnitCategory("Length");
  DetYPositionCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/SetCenterPositionInX",this);
  DetXPositionCmdScint4->SetGuidance("Set the X position of the Scintillator"); 
  DetXPositionCmdScint4->SetParameterName("Size",true);
  DetXPositionCmdScint4->SetUnitCategory("Length");
  DetXPositionCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/QuartzSizeZ",this);
  QuartzSizeZCmdScint4->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmdScint4->SetParameterName("Size",true);
  QuartzSizeZCmdScint4->SetUnitCategory("Length");
  QuartzSizeZCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/QuartzSizeY",this);
  QuartzSizeYCmdScint4->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmdScint4->SetParameterName("Size",true);
  QuartzSizeYCmdScint4->SetUnitCategory("Length");
  QuartzSizeYCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmdScint4 =  new G4UIcmdWithADoubleAndUnit("/Scint4/QuartzSizeX",this);
  QuartzSizeXCmdScint4->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmdScint4->SetParameterName("Size",true);
  QuartzSizeXCmdScint4->SetUnitCategory("Length");
  QuartzSizeXCmdScint4->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //General objects
  LightGuidePMTInterfaceOpeningXCmd =  new G4UIcmdWithADoubleAndUnit("/Det/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd =  new G4UIcmdWithADoubleAndUnit("/Det/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideOffsetZCmd =  new G4UIcmdWithADoubleAndUnit("/Det/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd->SetParameterName("Size",true);
  LightGuideOffsetZCmd->SetUnitCategory("Length");
  LightGuideOffsetZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd =  new G4UIcmdWithADoubleAndUnit("/Det/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd->SetParameterName("Size",true);
  LightGuideOffsetYCmd->SetUnitCategory("Length");
  LightGuideOffsetYCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd =  new G4UIcmdWithADoubleAndUnit("/Det/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd->SetParameterName("Size",true);
  LightGuideOffsetXCmd->SetUnitCategory("Length");
  LightGuideOffsetXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd =  new G4UIcmdWithADoubleAndUnit("/Det/QuartzRotX",this);
  QuartzRotXCmd->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd->SetParameterName("Angle",true);
  QuartzRotXCmd->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd->SetDefaultUnit("deg");
  QuartzRotXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd =  new G4UIcmdWithADoubleAndUnit("/Det/PolarRotation",this);
  PolarRotationCmd->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd->SetParameterName("Angle",true);
  PolarRotationCmd->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd->SetDefaultUnit("deg");
  PolarRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd = new G4UIcmdWithoutParameter("/Det/UpdateGeometry",this);
  UpdateGeometryCmd->SetGuidance("Update the geometry");
  UpdateGeometryCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd = new G4UIcmdWithoutParameter("/Det/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd =  new G4UIcmdWithADoubleAndUnit("/Det/QuartzBevelSize",this);
  QuartzBevelCmd->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd->SetParameterName("Bevel",true);
  QuartzBevelCmd->SetUnitCategory("Length");
  QuartzBevelCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd = new G4UIcmdWithAString("/Det/SetMaterial",this);
  DetMatCmd->SetGuidance("Select Material of the Detetector.");
  DetMatCmd->SetParameterName("choice",false);
  DetMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
}

MOLLEROptDetectorMessenger::~MOLLEROptDetectorMessenger()
{
  //Ring 1 objects
  if(DetXPositionCmd1			   ) delete DetXPositionCmd1;
  if(DetYPositionCmd1			   ) delete DetYPositionCmd1;
  if(DetZPositionCmd1			   ) delete DetZPositionCmd1;
  if(QuartzSizeXCmd1                       ) delete QuartzSizeXCmd1;                       
  if(QuartzSizeYCmd1                       ) delete QuartzSizeYCmd1;                       
  if(QuartzSizeZCmd1                       ) delete QuartzSizeZCmd1;
  if(LightGuideUpperInterfaceCmd1          ) delete LightGuideUpperInterfaceCmd1;          
  if(LightGuideMiddleBoxCmd1               ) delete LightGuideMiddleBoxCmd1;
  if(LightGuideLowerInterfaceCmd1          ) delete LightGuideLowerInterfaceCmd1;          
  if(LightGuideLowerConeFrontAngleCmd1     ) delete LightGuideLowerConeFrontAngleCmd1;     
  if(LightGuideLowerConeBackAngleCmd1      ) delete LightGuideLowerConeBackAngleCmd1;      
  if(LightGuideLowerConeSideAngleCmd1      ) delete LightGuideLowerConeSideAngleCmd1;      
  if(LightGuideQuartzInterfaceOpeningXCmd1 ) delete LightGuideQuartzInterfaceOpeningXCmd1; 
  if(LightGuideQuartzInterfaceOpeningZCmd1 ) delete LightGuideQuartzInterfaceOpeningZCmd1; 
  if(LightGuideQuartzToPMTOffsetCmd1       ) delete LightGuideQuartzToPMTOffsetCmd1;  

  //Ring 2 objects
  if(DetXPositionCmd2			   ) delete DetXPositionCmd2;
  if(DetYPositionCmd2			   ) delete DetYPositionCmd2;
  if(DetZPositionCmd2			   ) delete DetZPositionCmd2;
  if(QuartzSizeXCmd2                       ) delete QuartzSizeXCmd2;                       
  if(QuartzSizeYCmd2                       ) delete QuartzSizeYCmd2;                       
  if(QuartzSizeZCmd2                       ) delete QuartzSizeZCmd2;
  if(LightGuideUpperInterfaceCmd2          ) delete LightGuideUpperInterfaceCmd2;          
  if(LightGuideMiddleBoxCmd2               ) delete LightGuideMiddleBoxCmd2;
  if(LightGuideLowerInterfaceCmd2          ) delete LightGuideLowerInterfaceCmd2;          
  if(LightGuideLowerConeFrontAngleCmd2     ) delete LightGuideLowerConeFrontAngleCmd2;     
  if(LightGuideLowerConeBackAngleCmd2      ) delete LightGuideLowerConeBackAngleCmd2;      
  if(LightGuideLowerConeSideAngleCmd2      ) delete LightGuideLowerConeSideAngleCmd2;      
  if(LightGuideQuartzInterfaceOpeningXCmd2 ) delete LightGuideQuartzInterfaceOpeningXCmd2; 
  if(LightGuideQuartzInterfaceOpeningZCmd2 ) delete LightGuideQuartzInterfaceOpeningZCmd2; 
  if(LightGuideQuartzToPMTOffsetCmd2       ) delete LightGuideQuartzToPMTOffsetCmd2;

  //Ring 3 objects
  if(DetXPositionCmd3			   ) delete DetXPositionCmd3;
  if(DetYPositionCmd3			   ) delete DetYPositionCmd3;
  if(DetZPositionCmd3			   ) delete DetZPositionCmd3;
  if(QuartzSizeXCmd3                       ) delete QuartzSizeXCmd3;                       
  if(QuartzSizeYCmd3                       ) delete QuartzSizeYCmd3;                       
  if(QuartzSizeZCmd3                       ) delete QuartzSizeZCmd3;
  if(LightGuideUpperInterfaceCmd3          ) delete LightGuideUpperInterfaceCmd3;          
  if(LightGuideMiddleBoxCmd3               ) delete LightGuideMiddleBoxCmd3;
  if(LightGuideLowerInterfaceCmd3          ) delete LightGuideLowerInterfaceCmd3;          
  if(LightGuideLowerConeFrontAngleCmd3     ) delete LightGuideLowerConeFrontAngleCmd3;     
  if(LightGuideLowerConeBackAngleCmd3      ) delete LightGuideLowerConeBackAngleCmd3;      
  if(LightGuideLowerConeSideAngleCmd3      ) delete LightGuideLowerConeSideAngleCmd3;      
  if(LightGuideQuartzInterfaceOpeningXCmd3 ) delete LightGuideQuartzInterfaceOpeningXCmd3; 
  if(LightGuideQuartzInterfaceOpeningZCmd3 ) delete LightGuideQuartzInterfaceOpeningZCmd3; 
  if(LightGuideQuartzToPMTOffsetCmd3       ) delete LightGuideQuartzToPMTOffsetCmd3;  

  //Ring 4 objects
  if(DetXPositionCmd4			   ) delete DetXPositionCmd4;
  if(DetYPositionCmd4			   ) delete DetYPositionCmd4;
  if(DetZPositionCmd4			   ) delete DetZPositionCmd4;
  if(QuartzSizeXCmd4                       ) delete QuartzSizeXCmd4;                       
  if(QuartzSizeYCmd4                       ) delete QuartzSizeYCmd4;                       
  if(QuartzSizeZCmd4                       ) delete QuartzSizeZCmd4;
  if(LightGuideUpperInterfaceCmd4          ) delete LightGuideUpperInterfaceCmd4;          
  if(LightGuideMiddleBoxCmd4               ) delete LightGuideMiddleBoxCmd4;
  if(LightGuideLowerInterfaceCmd4          ) delete LightGuideLowerInterfaceCmd4;          
  if(LightGuideLowerConeFrontAngleCmd4     ) delete LightGuideLowerConeFrontAngleCmd4;     
  if(LightGuideLowerConeBackAngleCmd4      ) delete LightGuideLowerConeBackAngleCmd4;      
  if(LightGuideLowerConeSideAngleCmd4      ) delete LightGuideLowerConeSideAngleCmd4;      
  if(LightGuideQuartzInterfaceOpeningXCmd4 ) delete LightGuideQuartzInterfaceOpeningXCmd4; 
  if(LightGuideQuartzInterfaceOpeningZCmd4 ) delete LightGuideQuartzInterfaceOpeningZCmd4; 
  if(LightGuideQuartzToPMTOffsetCmd4       ) delete LightGuideQuartzToPMTOffsetCmd4;  

  //Ring 5 objects
  if(DetXPositionCmd5			   ) delete DetXPositionCmd5;
  if(DetYPositionCmd5			   ) delete DetYPositionCmd5;
  if(DetZPositionCmd5			   ) delete DetZPositionCmd5;
  if(QuartzSizeXCmd5                       ) delete QuartzSizeXCmd5;                       
  if(QuartzSizeYCmd5                       ) delete QuartzSizeYCmd5;                       
  if(QuartzSizeZCmd5                       ) delete QuartzSizeZCmd5;
  if(LightGuideUpperInterfaceCmd5          ) delete LightGuideUpperInterfaceCmd5;          
  if(LightGuideMiddleBoxCmd5               ) delete LightGuideMiddleBoxCmd5;
  if(LightGuideLowerInterfaceCmd5          ) delete LightGuideLowerInterfaceCmd5;          
  if(LightGuideLowerConeFrontAngleCmd5     ) delete LightGuideLowerConeFrontAngleCmd5;     
  if(LightGuideLowerConeBackAngleCmd5      ) delete LightGuideLowerConeBackAngleCmd5;      
  if(LightGuideLowerConeSideAngleCmd5      ) delete LightGuideLowerConeSideAngleCmd5;      
  if(LightGuideQuartzInterfaceOpeningXCmd5 ) delete LightGuideQuartzInterfaceOpeningXCmd5; 
  if(LightGuideQuartzInterfaceOpeningZCmd5 ) delete LightGuideQuartzInterfaceOpeningZCmd5; 
  if(LightGuideQuartzToPMTOffsetCmd5       ) delete LightGuideQuartzToPMTOffsetCmd5;  

  //Ring 6 objects
  if(DetXPositionCmd6			   ) delete DetXPositionCmd6;
  if(DetYPositionCmd6			   ) delete DetYPositionCmd6;
  if(DetZPositionCmd6			   ) delete DetZPositionCmd6;
  if(QuartzSizeXCmd6                       ) delete QuartzSizeXCmd6;                       
  if(QuartzSizeYCmd6                       ) delete QuartzSizeYCmd6;                       
  if(QuartzSizeZCmd6                       ) delete QuartzSizeZCmd6;
  if(LightGuideUpperInterfaceCmd6          ) delete LightGuideUpperInterfaceCmd6;          
  if(LightGuideMiddleBoxCmd6               ) delete LightGuideMiddleBoxCmd6;
  if(LightGuideLowerInterfaceCmd6          ) delete LightGuideLowerInterfaceCmd6;          
  if(LightGuideLowerConeFrontAngleCmd6     ) delete LightGuideLowerConeFrontAngleCmd6;     
  if(LightGuideLowerConeBackAngleCmd6      ) delete LightGuideLowerConeBackAngleCmd6;      
  if(LightGuideLowerConeSideAngleCmd6      ) delete LightGuideLowerConeSideAngleCmd6;      
  if(LightGuideQuartzInterfaceOpeningXCmd6 ) delete LightGuideQuartzInterfaceOpeningXCmd6; 
  if(LightGuideQuartzInterfaceOpeningZCmd6 ) delete LightGuideQuartzInterfaceOpeningZCmd6; 
  if(LightGuideQuartzToPMTOffsetCmd6       ) delete LightGuideQuartzToPMTOffsetCmd6;  

  //Ring 7 objects
  if(DetXPositionCmd7			   ) delete DetXPositionCmd7;
  if(DetYPositionCmd7			   ) delete DetYPositionCmd7;
  if(DetZPositionCmd7			   ) delete DetZPositionCmd7;
  if(QuartzSizeXCmd7                       ) delete QuartzSizeXCmd7;                       
  if(QuartzSizeYCmd7                       ) delete QuartzSizeYCmd7;                       
  if(QuartzSizeZCmd7                       ) delete QuartzSizeZCmd7;
  if(LightGuideUpperInterfaceCmd7          ) delete LightGuideUpperInterfaceCmd7;          
  if(LightGuideMiddleBoxCmd7               ) delete LightGuideMiddleBoxCmd7;
  if(LightGuideLowerInterfaceCmd7          ) delete LightGuideLowerInterfaceCmd7;          
  if(LightGuideLowerConeFrontAngleCmd7     ) delete LightGuideLowerConeFrontAngleCmd7;     
  if(LightGuideLowerConeBackAngleCmd7      ) delete LightGuideLowerConeBackAngleCmd7;      
  if(LightGuideLowerConeSideAngleCmd7      ) delete LightGuideLowerConeSideAngleCmd7;      
  if(LightGuideQuartzInterfaceOpeningXCmd7 ) delete LightGuideQuartzInterfaceOpeningXCmd7; 
  if(LightGuideQuartzInterfaceOpeningZCmd7 ) delete LightGuideQuartzInterfaceOpeningZCmd7; 
  if(LightGuideQuartzToPMTOffsetCmd7       ) delete LightGuideQuartzToPMTOffsetCmd7;  

  //Ring 8 objects
  if(DetXPositionCmd8			   ) delete DetXPositionCmd8;
  if(DetYPositionCmd8			   ) delete DetYPositionCmd8;
  if(DetZPositionCmd8			   ) delete DetZPositionCmd8;
  if(QuartzSizeXCmd8                       ) delete QuartzSizeXCmd8;                       
  if(QuartzSizeYCmd8                       ) delete QuartzSizeYCmd8;                       
  if(QuartzSizeZCmd8                       ) delete QuartzSizeZCmd8;
  if(LightGuideUpperInterfaceCmd8          ) delete LightGuideUpperInterfaceCmd8;          
  if(LightGuideMiddleBoxCmd8               ) delete LightGuideMiddleBoxCmd8;
  if(LightGuideLowerInterfaceCmd8          ) delete LightGuideLowerInterfaceCmd8;          
  if(LightGuideLowerConeFrontAngleCmd8     ) delete LightGuideLowerConeFrontAngleCmd8;     
  if(LightGuideLowerConeBackAngleCmd8      ) delete LightGuideLowerConeBackAngleCmd8;      
  if(LightGuideLowerConeSideAngleCmd8      ) delete LightGuideLowerConeSideAngleCmd8;      
  if(LightGuideQuartzInterfaceOpeningXCmd8 ) delete LightGuideQuartzInterfaceOpeningXCmd8; 
  if(LightGuideQuartzInterfaceOpeningZCmd8 ) delete LightGuideQuartzInterfaceOpeningZCmd8; 
  if(LightGuideQuartzToPMTOffsetCmd8       ) delete LightGuideQuartzToPMTOffsetCmd8;  

  //Scint1 objects
  if(DetXPositionCmdScint1			             ) delete DetXPositionCmdScint1;
  if(DetYPositionCmdScint1			             ) delete DetYPositionCmdScint1;
  if(DetZPositionCmdScint1			             ) delete DetZPositionCmdScint1;
  if(QuartzSizeXCmdScint1                   ) delete QuartzSizeXCmdScint1;                       
  if(QuartzSizeYCmdScint1                   ) delete QuartzSizeYCmdScint1;                       
  if(QuartzSizeZCmdScint1                   ) delete QuartzSizeZCmdScint1;

  //Scint2 objects
  if(DetXPositionCmdScint2			             ) delete DetXPositionCmdScint2;
  if(DetYPositionCmdScint2			             ) delete DetYPositionCmdScint2;
  if(DetZPositionCmdScint2			             ) delete DetZPositionCmdScint2;
  if(QuartzSizeXCmdScint2                   ) delete QuartzSizeXCmdScint2;                       
  if(QuartzSizeYCmdScint2                   ) delete QuartzSizeYCmdScint2;                       
  if(QuartzSizeZCmdScint2                   ) delete QuartzSizeZCmdScint2;

  //Scint3 objects
  if(DetXPositionCmdScint3			             ) delete DetXPositionCmdScint3;
  if(DetYPositionCmdScint3			             ) delete DetYPositionCmdScint3;
  if(DetZPositionCmdScint3			             ) delete DetZPositionCmdScint3;
  if(QuartzSizeXCmdScint3                   ) delete QuartzSizeXCmdScint3;                       
  if(QuartzSizeYCmdScint3                   ) delete QuartzSizeYCmdScint3;                       
  if(QuartzSizeZCmdScint3                   ) delete QuartzSizeZCmdScint3;

  //Scint4 objects
  if(DetXPositionCmdScint4			             ) delete DetXPositionCmdScint4;
  if(DetYPositionCmdScint4			             ) delete DetYPositionCmdScint4;
  if(DetZPositionCmdScint4			             ) delete DetZPositionCmdScint4;
  if(QuartzSizeXCmdScint4                   ) delete QuartzSizeXCmdScint4;                       
  if(QuartzSizeYCmdScint4                   ) delete QuartzSizeYCmdScint4;                       
  if(QuartzSizeZCmdScint4                   ) delete QuartzSizeZCmdScint4;

  //General objects
  if(LightGuideOffsetXCmd                  ) delete LightGuideOffsetXCmd;                 
  if(LightGuideOffsetYCmd                  ) delete LightGuideOffsetYCmd;                 
  if(LightGuideOffsetZCmd                  ) delete LightGuideOffsetZCmd;
  if(LightGuidePMTInterfaceOpeningXCmd     ) delete LightGuidePMTInterfaceOpeningXCmd;    
  if(LightGuidePMTInterfaceOpeningZCmd     ) delete LightGuidePMTInterfaceOpeningZCmd;
  if(QuartzBevelCmd                        ) delete QuartzBevelCmd;                       
  if(QuartzRotXCmd                         ) delete QuartzRotXCmd;                       
  if(PolarRotationCmd                      ) delete PolarRotationCmd;                       
  
  if(UpdateGeometryCmd                     ) delete UpdateGeometryCmd;
  if(SegRadDamageCmd                       ) delete SegRadDamageCmd;
  if(DetMatCmd)                             delete DetMatCmd;
  if(Dir)                                   delete Dir;
}

void MOLLEROptDetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  //Ring 1 objects
  if( command == DetXPositionCmd1 ) 			{ Det->SetCenterPositionInX1(DetXPositionCmd1->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd1 ) 			{ Det->SetCenterPositionInY1(DetYPositionCmd1->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd1 ) 			{ Det->SetCenterPositionInZ1(DetZPositionCmd1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd1 )                      { Det->SetQuartzSizeX1(QuartzSizeXCmd1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd1 )                      { Det->SetQuartzSizeY1(QuartzSizeYCmd1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd1 )                      { Det->SetQuartzSizeZ1(QuartzSizeZCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd1 )         { Det->SetUpperInterfacePlane1(LightGuideUpperInterfaceCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd1 )              { Det->SetMiddleBoxHeight1(LightGuideMiddleBoxCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd1 )         { Det->SetLowerInterfacePlane1(LightGuideLowerInterfaceCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd1 )    { Det->SetLowerConeFrontFaceAngle1(LightGuideLowerConeFrontAngleCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd1 )     { Det->SetLowerConeBackFaceAngle1(LightGuideLowerConeBackAngleCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd1 )     { Det->SetLowerConeSideFaceAngle1(LightGuideLowerConeSideAngleCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd1 ){ Det->SetQuartzInterfaceOpeningX1(LightGuideQuartzInterfaceOpeningXCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd1 ){ Det->SetQuartzInterfaceOpeningZ1(LightGuideQuartzInterfaceOpeningZCmd1->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd1 )      { Det->SetQuartzToPMTOffsetInZ1(LightGuideQuartzToPMTOffsetCmd1->GetNewDoubleValue(newValue));}

  //Ring 2 objects
  if( command == DetXPositionCmd2 ) 			{ Det->SetCenterPositionInX2(DetXPositionCmd2->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd2 ) 			{ Det->SetCenterPositionInY2(DetYPositionCmd2->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd2 ) 			{ Det->SetCenterPositionInZ2(DetZPositionCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd2 )                      { Det->SetQuartzSizeX2(QuartzSizeXCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd2 )                      { Det->SetQuartzSizeY2(QuartzSizeYCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd2 )                      { Det->SetQuartzSizeZ2(QuartzSizeZCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd2 )         { Det->SetUpperInterfacePlane2(LightGuideUpperInterfaceCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd2 )              { Det->SetMiddleBoxHeight2(LightGuideMiddleBoxCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd2 )         { Det->SetLowerInterfacePlane2(LightGuideLowerInterfaceCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd2 )    { Det->SetLowerConeFrontFaceAngle2(LightGuideLowerConeFrontAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd2 )     { Det->SetLowerConeBackFaceAngle2(LightGuideLowerConeBackAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd2 )     { Det->SetLowerConeSideFaceAngle2(LightGuideLowerConeSideAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd2 ){ Det->SetQuartzInterfaceOpeningX2(LightGuideQuartzInterfaceOpeningXCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd2 ){ Det->SetQuartzInterfaceOpeningZ2(LightGuideQuartzInterfaceOpeningZCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd2 )      { Det->SetQuartzToPMTOffsetInZ2(LightGuideQuartzToPMTOffsetCmd2->GetNewDoubleValue(newValue));}
  
  //Ring 3 objects
  if( command == DetXPositionCmd3 ) 			{ Det->SetCenterPositionInX3(DetXPositionCmd3->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd3 ) 			{ Det->SetCenterPositionInY3(DetYPositionCmd3->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd3 ) 			{ Det->SetCenterPositionInZ3(DetZPositionCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd3 )                      { Det->SetQuartzSizeX3(QuartzSizeXCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd3 )                      { Det->SetQuartzSizeY3(QuartzSizeYCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd3 )                      { Det->SetQuartzSizeZ3(QuartzSizeZCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd3 )         { Det->SetUpperInterfacePlane3(LightGuideUpperInterfaceCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd3 )              { Det->SetMiddleBoxHeight3(LightGuideMiddleBoxCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd3 )         { Det->SetLowerInterfacePlane3(LightGuideLowerInterfaceCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd3 )    { Det->SetLowerConeFrontFaceAngle3(LightGuideLowerConeFrontAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd3 )     { Det->SetLowerConeBackFaceAngle3(LightGuideLowerConeBackAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd3 )     { Det->SetLowerConeSideFaceAngle3(LightGuideLowerConeSideAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd3 ){ Det->SetQuartzInterfaceOpeningX3(LightGuideQuartzInterfaceOpeningXCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd3 ){ Det->SetQuartzInterfaceOpeningZ3(LightGuideQuartzInterfaceOpeningZCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd3 )      { Det->SetQuartzToPMTOffsetInZ3(LightGuideQuartzToPMTOffsetCmd3->GetNewDoubleValue(newValue));}

  //Ring 4 objects
  if( command == DetXPositionCmd4 ) 			{ Det->SetCenterPositionInX4(DetXPositionCmd4->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd4 ) 			{ Det->SetCenterPositionInY4(DetYPositionCmd4->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd4 ) 			{ Det->SetCenterPositionInZ4(DetZPositionCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd4 )                      { Det->SetQuartzSizeX4(QuartzSizeXCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd4 )                      { Det->SetQuartzSizeY4(QuartzSizeYCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd4 )                      { Det->SetQuartzSizeZ4(QuartzSizeZCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd4 )         { Det->SetUpperInterfacePlane4(LightGuideUpperInterfaceCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd4 )              { Det->SetMiddleBoxHeight4(LightGuideMiddleBoxCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd4 )         { Det->SetLowerInterfacePlane4(LightGuideLowerInterfaceCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd4 )    { Det->SetLowerConeFrontFaceAngle4(LightGuideLowerConeFrontAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd4 )     { Det->SetLowerConeBackFaceAngle4(LightGuideLowerConeBackAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd4 )     { Det->SetLowerConeSideFaceAngle4(LightGuideLowerConeSideAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd4 ){ Det->SetQuartzInterfaceOpeningX4(LightGuideQuartzInterfaceOpeningXCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd4 ){ Det->SetQuartzInterfaceOpeningZ4(LightGuideQuartzInterfaceOpeningZCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd4 )      { Det->SetQuartzToPMTOffsetInZ4(LightGuideQuartzToPMTOffsetCmd4->GetNewDoubleValue(newValue));}

  //Ring 5 objects
  if( command == DetXPositionCmd5 ) 			{ Det->SetCenterPositionInX5(DetXPositionCmd5->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd5 ) 			{ Det->SetCenterPositionInY5(DetYPositionCmd5->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd5 ) 			{ Det->SetCenterPositionInZ5(DetZPositionCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd5 )                      { Det->SetQuartzSizeX5(QuartzSizeXCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd5 )                      { Det->SetQuartzSizeY5(QuartzSizeYCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd5 )                      { Det->SetQuartzSizeZ5(QuartzSizeZCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd5 )         { Det->SetUpperInterfacePlane5(LightGuideUpperInterfaceCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd5 )              { Det->SetMiddleBoxHeight5(LightGuideMiddleBoxCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd5 )         { Det->SetLowerInterfacePlane5(LightGuideLowerInterfaceCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd5 )    { Det->SetLowerConeFrontFaceAngle5(LightGuideLowerConeFrontAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd5 )     { Det->SetLowerConeBackFaceAngle5(LightGuideLowerConeBackAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd5 )     { Det->SetLowerConeSideFaceAngle5(LightGuideLowerConeSideAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd5 ){ Det->SetQuartzInterfaceOpeningX5(LightGuideQuartzInterfaceOpeningXCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd5 ){ Det->SetQuartzInterfaceOpeningZ5(LightGuideQuartzInterfaceOpeningZCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd5 )      { Det->SetQuartzToPMTOffsetInZ5(LightGuideQuartzToPMTOffsetCmd5->GetNewDoubleValue(newValue));}

  //Ring 6 objects
  if( command == DetXPositionCmd6 ) 			{ Det->SetCenterPositionInX6(DetXPositionCmd6->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd6 ) 			{ Det->SetCenterPositionInY6(DetYPositionCmd6->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd6 ) 			{ Det->SetCenterPositionInZ6(DetZPositionCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd6 )                      { Det->SetQuartzSizeX6(QuartzSizeXCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd6 )                      { Det->SetQuartzSizeY6(QuartzSizeYCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd6 )                      { Det->SetQuartzSizeZ6(QuartzSizeZCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd6 )         { Det->SetUpperInterfacePlane6(LightGuideUpperInterfaceCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd6 )              { Det->SetMiddleBoxHeight6(LightGuideMiddleBoxCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd6 )         { Det->SetLowerInterfacePlane6(LightGuideLowerInterfaceCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd6 )    { Det->SetLowerConeFrontFaceAngle6(LightGuideLowerConeFrontAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd6 )     { Det->SetLowerConeBackFaceAngle6(LightGuideLowerConeBackAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd6 )     { Det->SetLowerConeSideFaceAngle6(LightGuideLowerConeSideAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd6 ){ Det->SetQuartzInterfaceOpeningX6(LightGuideQuartzInterfaceOpeningXCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd6 ){ Det->SetQuartzInterfaceOpeningZ6(LightGuideQuartzInterfaceOpeningZCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd6 )      { Det->SetQuartzToPMTOffsetInZ6(LightGuideQuartzToPMTOffsetCmd6->GetNewDoubleValue(newValue));}

  //Ring 7 objects
  if( command == DetXPositionCmd7 ) 			{ Det->SetCenterPositionInX7(DetXPositionCmd7->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd7 ) 			{ Det->SetCenterPositionInY7(DetYPositionCmd7->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd7 ) 			{ Det->SetCenterPositionInZ7(DetZPositionCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd7 )                      { Det->SetQuartzSizeX7(QuartzSizeXCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd7 )                      { Det->SetQuartzSizeY7(QuartzSizeYCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd7 )                      { Det->SetQuartzSizeZ7(QuartzSizeZCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd7 )         { Det->SetUpperInterfacePlane7(LightGuideUpperInterfaceCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd7 )              { Det->SetMiddleBoxHeight7(LightGuideMiddleBoxCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd7 )         { Det->SetLowerInterfacePlane7(LightGuideLowerInterfaceCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd7 )    { Det->SetLowerConeFrontFaceAngle7(LightGuideLowerConeFrontAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd7 )     { Det->SetLowerConeBackFaceAngle7(LightGuideLowerConeBackAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd7 )     { Det->SetLowerConeSideFaceAngle7(LightGuideLowerConeSideAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd7 ){ Det->SetQuartzInterfaceOpeningX7(LightGuideQuartzInterfaceOpeningXCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd7 ){ Det->SetQuartzInterfaceOpeningZ7(LightGuideQuartzInterfaceOpeningZCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd7 )      { Det->SetQuartzToPMTOffsetInZ7(LightGuideQuartzToPMTOffsetCmd7->GetNewDoubleValue(newValue));}

  //Ring 8 objects
  if( command == DetXPositionCmd8 ) 			{ Det->SetCenterPositionInX8(DetXPositionCmd8->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd8 ) 			{ Det->SetCenterPositionInY8(DetYPositionCmd8->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd8 ) 			{ Det->SetCenterPositionInZ8(DetZPositionCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd8 )                      { Det->SetQuartzSizeX8(QuartzSizeXCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd8 )                      { Det->SetQuartzSizeY8(QuartzSizeYCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd8 )                      { Det->SetQuartzSizeZ8(QuartzSizeZCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd8 )         { Det->SetUpperInterfacePlane8(LightGuideUpperInterfaceCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd8 )              { Det->SetMiddleBoxHeight8(LightGuideMiddleBoxCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd8 )         { Det->SetLowerInterfacePlane8(LightGuideLowerInterfaceCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd8 )    { Det->SetLowerConeFrontFaceAngle8(LightGuideLowerConeFrontAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd8 )     { Det->SetLowerConeBackFaceAngle8(LightGuideLowerConeBackAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd8 )     { Det->SetLowerConeSideFaceAngle8(LightGuideLowerConeSideAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd8 ){ Det->SetQuartzInterfaceOpeningX8(LightGuideQuartzInterfaceOpeningXCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd8 ){ Det->SetQuartzInterfaceOpeningZ8(LightGuideQuartzInterfaceOpeningZCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd8 )      { Det->SetQuartzToPMTOffsetInZ8(LightGuideQuartzToPMTOffsetCmd8->GetNewDoubleValue(newValue));}

  //Scint1 objects
  if( command == DetXPositionCmdScint1 ) 			{ Det->SetCenterPositionInXScint1(DetXPositionCmdScint1->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmdScint1 ) 			{ Det->SetCenterPositionInYScint1(DetYPositionCmdScint1->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmdScint1 ) 			{ Det->SetCenterPositionInZScint1(DetZPositionCmdScint1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmdScint1 )                      { Det->SetScint1SizeX(QuartzSizeXCmdScint1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmdScint1 )                      { Det->SetScint1SizeY(QuartzSizeYCmdScint1->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmdScint1 )                      { Det->SetScint1SizeZ(QuartzSizeZCmdScint1->GetNewDoubleValue(newValue));}

  //Scint2 objects
  if( command == DetXPositionCmdScint2 ) 			{ Det->SetCenterPositionInXScint2(DetXPositionCmdScint2->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmdScint2 ) 			{ Det->SetCenterPositionInYScint2(DetYPositionCmdScint2->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmdScint2 ) 			{ Det->SetCenterPositionInZScint2(DetZPositionCmdScint2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmdScint2 )                      { Det->SetScint2SizeX(QuartzSizeXCmdScint2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmdScint2 )                      { Det->SetScint2SizeY(QuartzSizeYCmdScint2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmdScint2 )                      { Det->SetScint2SizeZ(QuartzSizeZCmdScint2->GetNewDoubleValue(newValue));}

  //Scint3 objects
  if( command == DetXPositionCmdScint3 ) 			{ Det->SetCenterPositionInXScint3(DetXPositionCmdScint3->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmdScint3 ) 			{ Det->SetCenterPositionInYScint3(DetYPositionCmdScint3->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmdScint3 ) 			{ Det->SetCenterPositionInZScint3(DetZPositionCmdScint3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmdScint3 )                      { Det->SetScint3SizeX(QuartzSizeXCmdScint3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmdScint3 )                      { Det->SetScint3SizeY(QuartzSizeYCmdScint3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmdScint3 )                      { Det->SetScint3SizeZ(QuartzSizeZCmdScint3->GetNewDoubleValue(newValue));}

  //Scint4 objects
  if( command == DetXPositionCmdScint4 ) 			{ Det->SetCenterPositionInXScint4(DetXPositionCmdScint4->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmdScint4 ) 			{ Det->SetCenterPositionInYScint4(DetYPositionCmdScint4->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmdScint4 ) 			{ Det->SetCenterPositionInZScint4(DetZPositionCmdScint4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmdScint4 )                      { Det->SetScint4SizeX(QuartzSizeXCmdScint4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmdScint4 )                      { Det->SetScint4SizeY(QuartzSizeYCmdScint4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmdScint4 )                      { Det->SetScint4SizeZ(QuartzSizeZCmdScint4->GetNewDoubleValue(newValue));}

  //General objects
  if( command == UpdateGeometryCmd )                    { Det->UpdateThisGeometry();}
  if( command == SegRadDamageCmd)                       { Det->SetSegRadDamageFlag();}
  if( command == LightGuidePMTInterfaceOpeningXCmd )    { Det->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd )    { Det->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd )                 { Det->SetLightGuideOffsetInX(LightGuideOffsetXCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd )                 { Det->SetLightGuideOffsetInY(LightGuideOffsetYCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd )                 { Det->SetLightGuideOffsetInZ(LightGuideOffsetZCmd->GetNewDoubleValue(newValue));}
  if( command == DetMatCmd ) 			                      { Det->SetMaterial(newValue);}
  if( command == QuartzBevelCmd )                       { Det->SetQuartzBevel(QuartzBevelCmd->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd )                        { Det->SetQuartzRotX(QuartzRotXCmd->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd )                     { Det->SetPolarRotationAngle(PolarRotationCmd->GetNewDoubleValue(newValue));}

  
}
