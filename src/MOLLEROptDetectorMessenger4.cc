#include "MOLLEROptDetectorMessenger4.hh"
MOLLEROptDetectorMessenger4::MOLLEROptDetectorMessenger4(MOLLEROptDetector4* theDet4)
  :Det4(theDet4)
{ 

  Dir = new G4UIdirectory("/Det4/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/SetCenterPositionInZ",this);
  DetZPositionCmd4->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd4->SetParameterName("Size",true);
  DetZPositionCmd4->SetUnitCategory("Length");
  DetZPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/SetCenterPositionInY",this);
  DetYPositionCmd4->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd4->SetParameterName("Size",true);
  DetYPositionCmd4->SetUnitCategory("Length");
  DetYPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/SetCenterPositionInX",this);
  DetXPositionCmd4->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd4->SetParameterName("Size",true);
  DetXPositionCmd4->SetUnitCategory("Length");
  DetXPositionCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd4 = new G4UIcmdWithAString("/Det4/SetMaterial",this);
  DetMatCmd4->SetGuidance("Select Material of the Detetector.");
  DetMatCmd4->SetParameterName("choice",false);
  DetMatCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd4->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd4->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd4->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd4->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd4->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd4->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd4->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd4->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd4->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd4->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd4->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd4->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd4->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd4->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd4->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd4->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd4->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd4->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd4->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd4->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd4->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd4->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd4->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd4->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd4->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd4->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd4->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd4->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd4->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd4->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd4->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd4->SetParameterName("Size",true);
  LightGuideOffsetZCmd4->SetUnitCategory("Length");
  LightGuideOffsetZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd4->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd4->SetParameterName("Size",true);
  LightGuideOffsetYCmd4->SetUnitCategory("Length");
  LightGuideOffsetYCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd4->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd4->SetParameterName("Size",true);
  LightGuideOffsetXCmd4->SetUnitCategory("Length");
  LightGuideOffsetXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/QuartzSizeZ",this);
  QuartzSizeZCmd4->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd4->SetParameterName("Size",true);
  QuartzSizeZCmd4->SetUnitCategory("Length");
  QuartzSizeZCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/QuartzSizeY",this);
  QuartzSizeYCmd4->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd4->SetParameterName("Size",true);
  QuartzSizeYCmd4->SetUnitCategory("Length");
  QuartzSizeYCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/QuartzSizeX",this);
  QuartzSizeXCmd4->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd4->SetParameterName("Size",true);
  QuartzSizeXCmd4->SetUnitCategory("Length");
  QuartzSizeXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/QuartzRotX",this);
  QuartzRotXCmd4->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd4->SetParameterName("Angle",true);
  QuartzRotXCmd4->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd4->SetDefaultUnit("deg");
  QuartzRotXCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/PolarRotation",this);
  PolarRotationCmd4->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd4->SetParameterName("Angle",true);
  PolarRotationCmd4->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd4->SetDefaultUnit("deg");
  PolarRotationCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd4 = new G4UIcmdWithoutParameter("/Det4/UpdateGeometry",this);
  UpdateGeometryCmd4->SetGuidance("Update the geometry");
  UpdateGeometryCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd4 = new G4UIcmdWithoutParameter("/Det4/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd4->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd4 =  new G4UIcmdWithADoubleAndUnit("/Det4/QuartzBevelSize",this);
  QuartzBevelCmd4->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd4->SetParameterName("Bevel",true);
  QuartzBevelCmd4->SetUnitCategory("Length");
  QuartzBevelCmd4->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger4::~MOLLEROptDetectorMessenger4()
{

  if (DetXPositionCmd4)      delete DetXPositionCmd4;
  if (DetYPositionCmd4)      delete DetYPositionCmd4;
  if (DetZPositionCmd4)      delete DetZPositionCmd4;

  if(LightGuideUpperInterfaceCmd4          ) delete LightGuideUpperInterfaceCmd4;          
  if(LightGuideMiddleBoxCmd4               ) delete LightGuideMiddleBoxCmd4;
  if(LightGuideLowerInterfaceCmd4          ) delete LightGuideLowerInterfaceCmd4;          
  if(LightGuideLowerConeFrontAngleCmd4     ) delete LightGuideLowerConeFrontAngleCmd4;     
  if(LightGuideLowerConeBackAngleCmd4      ) delete LightGuideLowerConeBackAngleCmd4;      
  if(LightGuideLowerConeSideAngleCmd4      ) delete LightGuideLowerConeSideAngleCmd4;      
  if(LightGuideQuartzInterfaceOpeningXCmd4 ) delete LightGuideQuartzInterfaceOpeningXCmd4; 
  if(LightGuideQuartzInterfaceOpeningZCmd4 ) delete LightGuideQuartzInterfaceOpeningZCmd4; 
  if(LightGuidePMTInterfaceOpeningXCmd4    ) delete LightGuidePMTInterfaceOpeningXCmd4;    
  if(LightGuidePMTInterfaceOpeningZCmd4    ) delete LightGuidePMTInterfaceOpeningZCmd4;    
  if(LightGuideQuartzToPMTOffsetCmd4       ) delete LightGuideQuartzToPMTOffsetCmd4;       
  if(LightGuideOffsetXCmd4                 ) delete LightGuideOffsetXCmd4;                 
  if(LightGuideOffsetYCmd4                 ) delete LightGuideOffsetYCmd4;                 
  if(LightGuideOffsetZCmd4                 ) delete LightGuideOffsetZCmd4;

  if(UpdateGeometryCmd4                    ) delete UpdateGeometryCmd4;
  if(SegRadDamageCmd4                      ) delete SegRadDamageCmd4;
  
  if(QuartzSizeXCmd4                       ) delete QuartzSizeXCmd4;                       
  if(QuartzSizeYCmd4                       ) delete QuartzSizeYCmd4;                       
  if(QuartzSizeZCmd4                       ) delete QuartzSizeZCmd4;                       
  if(QuartzBevelCmd4                       ) delete QuartzBevelCmd4;                       
  if(QuartzRotXCmd4                        ) delete QuartzRotXCmd4;                       
  if(PolarRotationCmd4                     ) delete PolarRotationCmd4;                       
  
  if (DetMatCmd4)                            delete DetMatCmd4;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger4::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd4 ) Det4->SetCenterPositionInX(DetXPositionCmd4->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd4 ) Det4->SetCenterPositionInY(DetYPositionCmd4->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd4 ) Det4->SetCenterPositionInZ(DetZPositionCmd4->GetNewDoubleValue(newValue));
  if( command == DetMatCmd4 ) Det4->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd4 )         { Det4->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd4 )              { Det4->SetMiddleBoxHeight(LightGuideMiddleBoxCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd4 )         { Det4->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd4 )    { Det4->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd4 )     {Det4->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd4 )     { Det4->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd4 ){ Det4->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd4 ){ Det4->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd4 )   { Det4->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd4 )   { Det4->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd4 )      { Det4->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd4 )                { Det4->SetLightGuideOffsetInX(LightGuideOffsetXCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd4 )                { Det4->SetLightGuideOffsetInY(LightGuideOffsetYCmd4->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd4 )                { Det4->SetLightGuideOffsetInZ(LightGuideOffsetZCmd4->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd4 )                   { Det4->UpdateThisGeometry();}
  if( command == SegRadDamageCmd4)                      { Det4->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd4 )                      { Det4->SetQuartzSizeX(QuartzSizeXCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd4 )                      { Det4->SetQuartzSizeY(QuartzSizeYCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd4 )                      { Det4->SetQuartzSizeZ(QuartzSizeZCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd4 )                      { Det4->SetQuartzBevel(QuartzBevelCmd4->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd4 )                       { Det4->SetQuartzRotX(QuartzRotXCmd4->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd4 )                    { Det4->SetPolarRotationAngle(PolarRotationCmd4->GetNewDoubleValue(newValue));}

}
	
