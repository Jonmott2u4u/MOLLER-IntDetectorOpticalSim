#include "MOLLEROptDetectorMessenger6.hh"
MOLLEROptDetectorMessenger6::MOLLEROptDetectorMessenger6(MOLLEROptDetector6* theDet6)
  :Det6(theDet6)
{ 

  Dir = new G4UIdirectory("/Det6/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/SetCenterPositionInZ",this);
  DetZPositionCmd6->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd6->SetParameterName("Size",true);
  DetZPositionCmd6->SetUnitCategory("Length");
  DetZPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/SetCenterPositionInY",this);
  DetYPositionCmd6->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd6->SetParameterName("Size",true);
  DetYPositionCmd6->SetUnitCategory("Length");
  DetYPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/SetCenterPositionInX",this);
  DetXPositionCmd6->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd6->SetParameterName("Size",true);
  DetXPositionCmd6->SetUnitCategory("Length");
  DetXPositionCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd6 = new G4UIcmdWithAString("/Det6/SetMaterial",this);
  DetMatCmd6->SetGuidance("Select Material of the Detetector.");
  DetMatCmd6->SetParameterName("choice",false);
  DetMatCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd6->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd6->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd6->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd6->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd6->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd6->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd6->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd6->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd6->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd6->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd6->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd6->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd6->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd6->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd6->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd6->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd6->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd6->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd6->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd6->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd6->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd6->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd6->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd6->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd6->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd6->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd6->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd6->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd6->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd6->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd6->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd6->SetParameterName("Size",true);
  LightGuideOffsetZCmd6->SetUnitCategory("Length");
  LightGuideOffsetZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd6->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd6->SetParameterName("Size",true);
  LightGuideOffsetYCmd6->SetUnitCategory("Length");
  LightGuideOffsetYCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd6->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd6->SetParameterName("Size",true);
  LightGuideOffsetXCmd6->SetUnitCategory("Length");
  LightGuideOffsetXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/QuartzSizeZ",this);
  QuartzSizeZCmd6->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd6->SetParameterName("Size",true);
  QuartzSizeZCmd6->SetUnitCategory("Length");
  QuartzSizeZCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/QuartzSizeY",this);
  QuartzSizeYCmd6->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd6->SetParameterName("Size",true);
  QuartzSizeYCmd6->SetUnitCategory("Length");
  QuartzSizeYCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/QuartzSizeX",this);
  QuartzSizeXCmd6->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd6->SetParameterName("Size",true);
  QuartzSizeXCmd6->SetUnitCategory("Length");
  QuartzSizeXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/QuartzRotX",this);
  QuartzRotXCmd6->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd6->SetParameterName("Angle",true);
  QuartzRotXCmd6->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd6->SetDefaultUnit("deg");
  QuartzRotXCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/PolarRotation",this);
  PolarRotationCmd6->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd6->SetParameterName("Angle",true);
  PolarRotationCmd6->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd6->SetDefaultUnit("deg");
  PolarRotationCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd6 = new G4UIcmdWithoutParameter("/Det6/UpdateGeometry",this);
  UpdateGeometryCmd6->SetGuidance("Update the geometry");
  UpdateGeometryCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd6 = new G4UIcmdWithoutParameter("/Det6/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd6->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd6 =  new G4UIcmdWithADoubleAndUnit("/Det6/QuartzBevelSize",this);
  QuartzBevelCmd6->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd6->SetParameterName("Bevel",true);
  QuartzBevelCmd6->SetUnitCategory("Length");
  QuartzBevelCmd6->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger6::~MOLLEROptDetectorMessenger6()
{

  if (DetXPositionCmd6)      delete DetXPositionCmd6;
  if (DetYPositionCmd6)      delete DetYPositionCmd6;
  if (DetZPositionCmd6)      delete DetZPositionCmd6;

  if(LightGuideUpperInterfaceCmd6          ) delete LightGuideUpperInterfaceCmd6;          
  if(LightGuideMiddleBoxCmd6               ) delete LightGuideMiddleBoxCmd6;
  if(LightGuideLowerInterfaceCmd6          ) delete LightGuideLowerInterfaceCmd6;          
  if(LightGuideLowerConeFrontAngleCmd6     ) delete LightGuideLowerConeFrontAngleCmd6;     
  if(LightGuideLowerConeBackAngleCmd6      ) delete LightGuideLowerConeBackAngleCmd6;      
  if(LightGuideLowerConeSideAngleCmd6      ) delete LightGuideLowerConeSideAngleCmd6;      
  if(LightGuideQuartzInterfaceOpeningXCmd6 ) delete LightGuideQuartzInterfaceOpeningXCmd6; 
  if(LightGuideQuartzInterfaceOpeningZCmd6 ) delete LightGuideQuartzInterfaceOpeningZCmd6; 
  if(LightGuidePMTInterfaceOpeningXCmd6    ) delete LightGuidePMTInterfaceOpeningXCmd6;    
  if(LightGuidePMTInterfaceOpeningZCmd6    ) delete LightGuidePMTInterfaceOpeningZCmd6;    
  if(LightGuideQuartzToPMTOffsetCmd6       ) delete LightGuideQuartzToPMTOffsetCmd6;       
  if(LightGuideOffsetXCmd6                 ) delete LightGuideOffsetXCmd6;                 
  if(LightGuideOffsetYCmd6                 ) delete LightGuideOffsetYCmd6;                 
  if(LightGuideOffsetZCmd6                 ) delete LightGuideOffsetZCmd6;

  if(UpdateGeometryCmd6                    ) delete UpdateGeometryCmd6;
  if(SegRadDamageCmd6                      ) delete SegRadDamageCmd6;
  
  if(QuartzSizeXCmd6                       ) delete QuartzSizeXCmd6;                       
  if(QuartzSizeYCmd6                       ) delete QuartzSizeYCmd6;                       
  if(QuartzSizeZCmd6                       ) delete QuartzSizeZCmd6;                       
  if(QuartzBevelCmd6                       ) delete QuartzBevelCmd6;                       
  if(QuartzRotXCmd6                        ) delete QuartzRotXCmd6;                       
  if(PolarRotationCmd6                     ) delete PolarRotationCmd6;                       
  
  if (DetMatCmd6)                            delete DetMatCmd6;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger6::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd6 ) Det6->SetCenterPositionInX(DetXPositionCmd6->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd6 ) Det6->SetCenterPositionInY(DetYPositionCmd6->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd6 ) Det6->SetCenterPositionInZ(DetZPositionCmd6->GetNewDoubleValue(newValue));
  if( command == DetMatCmd6 ) Det6->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd6 )         { Det6->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd6 )              { Det6->SetMiddleBoxHeight(LightGuideMiddleBoxCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd6 )         { Det6->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd6 )    { Det6->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd6 )     {Det6->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd6 )     { Det6->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd6 ){ Det6->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd6 ){ Det6->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd6 )   { Det6->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd6 )   { Det6->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd6 )      { Det6->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd6 )                { Det6->SetLightGuideOffsetInX(LightGuideOffsetXCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd6 )                { Det6->SetLightGuideOffsetInY(LightGuideOffsetYCmd6->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd6 )                { Det6->SetLightGuideOffsetInZ(LightGuideOffsetZCmd6->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd6 )                   { Det6->UpdateThisGeometry();}
  if( command == SegRadDamageCmd6)                      { Det6->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd6 )                      { Det6->SetQuartzSizeX(QuartzSizeXCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd6 )                      { Det6->SetQuartzSizeY(QuartzSizeYCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd6 )                      { Det6->SetQuartzSizeZ(QuartzSizeZCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd6 )                      { Det6->SetQuartzBevel(QuartzBevelCmd6->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd6 )                       { Det6->SetQuartzRotX(QuartzRotXCmd6->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd6 )                    { Det6->SetPolarRotationAngle(PolarRotationCmd6->GetNewDoubleValue(newValue));}

}
	
