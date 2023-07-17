#include "MOLLEROptDetectorMessenger7.hh"
MOLLEROptDetectorMessenger7::MOLLEROptDetectorMessenger7(MOLLEROptDetector7* theDet7)
  :Det7(theDet7)
{ 

  Dir = new G4UIdirectory("/Det7/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/SetCenterPositionInZ",this);
  DetZPositionCmd7->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd7->SetParameterName("Size",true);
  DetZPositionCmd7->SetUnitCategory("Length");
  DetZPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/SetCenterPositionInY",this);
  DetYPositionCmd7->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd7->SetParameterName("Size",true);
  DetYPositionCmd7->SetUnitCategory("Length");
  DetYPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/SetCenterPositionInX",this);
  DetXPositionCmd7->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd7->SetParameterName("Size",true);
  DetXPositionCmd7->SetUnitCategory("Length");
  DetXPositionCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd7 = new G4UIcmdWithAString("/Det7/SetMaterial",this);
  DetMatCmd7->SetGuidance("Select Material of the Detetector.");
  DetMatCmd7->SetParameterName("choice",false);
  DetMatCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd7->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd7->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd7->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd7->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd7->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd7->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd7->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd7->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd7->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd7->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd7->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd7->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd7->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd7->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd7->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd7->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd7->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd7->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd7->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd7->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd7->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd7->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd7->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd7->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd7->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd7->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd7->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd7->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd7->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd7->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd7->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd7->SetParameterName("Size",true);
  LightGuideOffsetZCmd7->SetUnitCategory("Length");
  LightGuideOffsetZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd7->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd7->SetParameterName("Size",true);
  LightGuideOffsetYCmd7->SetUnitCategory("Length");
  LightGuideOffsetYCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd7->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd7->SetParameterName("Size",true);
  LightGuideOffsetXCmd7->SetUnitCategory("Length");
  LightGuideOffsetXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/QuartzSizeZ",this);
  QuartzSizeZCmd7->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd7->SetParameterName("Size",true);
  QuartzSizeZCmd7->SetUnitCategory("Length");
  QuartzSizeZCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/QuartzSizeY",this);
  QuartzSizeYCmd7->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd7->SetParameterName("Size",true);
  QuartzSizeYCmd7->SetUnitCategory("Length");
  QuartzSizeYCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/QuartzSizeX",this);
  QuartzSizeXCmd7->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd7->SetParameterName("Size",true);
  QuartzSizeXCmd7->SetUnitCategory("Length");
  QuartzSizeXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/QuartzRotX",this);
  QuartzRotXCmd7->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd7->SetParameterName("Angle",true);
  QuartzRotXCmd7->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd7->SetDefaultUnit("deg");
  QuartzRotXCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/PolarRotation",this);
  PolarRotationCmd7->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd7->SetParameterName("Angle",true);
  PolarRotationCmd7->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd7->SetDefaultUnit("deg");
  PolarRotationCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd7 = new G4UIcmdWithoutParameter("/Det7/UpdateGeometry",this);
  UpdateGeometryCmd7->SetGuidance("Update the geometry");
  UpdateGeometryCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd7 = new G4UIcmdWithoutParameter("/Det7/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd7->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd7 =  new G4UIcmdWithADoubleAndUnit("/Det7/QuartzBevelSize",this);
  QuartzBevelCmd7->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd7->SetParameterName("Bevel",true);
  QuartzBevelCmd7->SetUnitCategory("Length");
  QuartzBevelCmd7->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger7::~MOLLEROptDetectorMessenger7()
{

  if (DetXPositionCmd7)      delete DetXPositionCmd7;
  if (DetYPositionCmd7)      delete DetYPositionCmd7;
  if (DetZPositionCmd7)      delete DetZPositionCmd7;

  if(LightGuideUpperInterfaceCmd7          ) delete LightGuideUpperInterfaceCmd7;          
  if(LightGuideMiddleBoxCmd7               ) delete LightGuideMiddleBoxCmd7;
  if(LightGuideLowerInterfaceCmd7          ) delete LightGuideLowerInterfaceCmd7;          
  if(LightGuideLowerConeFrontAngleCmd7     ) delete LightGuideLowerConeFrontAngleCmd7;     
  if(LightGuideLowerConeBackAngleCmd7      ) delete LightGuideLowerConeBackAngleCmd7;      
  if(LightGuideLowerConeSideAngleCmd7      ) delete LightGuideLowerConeSideAngleCmd7;      
  if(LightGuideQuartzInterfaceOpeningXCmd7 ) delete LightGuideQuartzInterfaceOpeningXCmd7; 
  if(LightGuideQuartzInterfaceOpeningZCmd7 ) delete LightGuideQuartzInterfaceOpeningZCmd7; 
  if(LightGuidePMTInterfaceOpeningXCmd7    ) delete LightGuidePMTInterfaceOpeningXCmd7;    
  if(LightGuidePMTInterfaceOpeningZCmd7    ) delete LightGuidePMTInterfaceOpeningZCmd7;    
  if(LightGuideQuartzToPMTOffsetCmd7       ) delete LightGuideQuartzToPMTOffsetCmd7;       
  if(LightGuideOffsetXCmd7                 ) delete LightGuideOffsetXCmd7;                 
  if(LightGuideOffsetYCmd7                 ) delete LightGuideOffsetYCmd7;                 
  if(LightGuideOffsetZCmd7                 ) delete LightGuideOffsetZCmd7;

  if(UpdateGeometryCmd7                    ) delete UpdateGeometryCmd7;
  if(SegRadDamageCmd7                      ) delete SegRadDamageCmd7;
  
  if(QuartzSizeXCmd7                       ) delete QuartzSizeXCmd7;                       
  if(QuartzSizeYCmd7                       ) delete QuartzSizeYCmd7;                       
  if(QuartzSizeZCmd7                       ) delete QuartzSizeZCmd7;                       
  if(QuartzBevelCmd7                       ) delete QuartzBevelCmd7;                       
  if(QuartzRotXCmd7                        ) delete QuartzRotXCmd7;                       
  if(PolarRotationCmd7                     ) delete PolarRotationCmd7;                       
  
  if (DetMatCmd7)                            delete DetMatCmd7;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger7::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd7 ) Det7->SetCenterPositionInX(DetXPositionCmd7->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd7 ) Det7->SetCenterPositionInY(DetYPositionCmd7->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd7 ) Det7->SetCenterPositionInZ(DetZPositionCmd7->GetNewDoubleValue(newValue));
  if( command == DetMatCmd7 ) Det7->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd7 )         { Det7->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd7 )              { Det7->SetMiddleBoxHeight(LightGuideMiddleBoxCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd7 )         { Det7->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd7 )    { Det7->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd7 )     {Det7->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd7 )     { Det7->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd7 ){ Det7->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd7 ){ Det7->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd7 )   { Det7->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd7 )   { Det7->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd7 )      { Det7->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd7 )                { Det7->SetLightGuideOffsetInX(LightGuideOffsetXCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd7 )                { Det7->SetLightGuideOffsetInY(LightGuideOffsetYCmd7->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd7 )                { Det7->SetLightGuideOffsetInZ(LightGuideOffsetZCmd7->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd7 )                   { Det7->UpdateThisGeometry();}
  if( command == SegRadDamageCmd7)                      { Det7->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd7 )                      { Det7->SetQuartzSizeX(QuartzSizeXCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd7 )                      { Det7->SetQuartzSizeY(QuartzSizeYCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd7 )                      { Det7->SetQuartzSizeZ(QuartzSizeZCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd7 )                      { Det7->SetQuartzBevel(QuartzBevelCmd7->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd7 )                       { Det7->SetQuartzRotX(QuartzRotXCmd7->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd7 )                    { Det7->SetPolarRotationAngle(PolarRotationCmd7->GetNewDoubleValue(newValue));}

}
	
