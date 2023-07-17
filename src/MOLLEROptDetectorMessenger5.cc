#include "MOLLEROptDetectorMessenger5.hh"
MOLLEROptDetectorMessenger5::MOLLEROptDetectorMessenger5(MOLLEROptDetector5* theDet5)
  :Det5(theDet5)
{ 

  Dir = new G4UIdirectory("/Det5/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/SetCenterPositionInZ",this);
  DetZPositionCmd5->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd5->SetParameterName("Size",true);
  DetZPositionCmd5->SetUnitCategory("Length");
  DetZPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/SetCenterPositionInY",this);
  DetYPositionCmd5->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd5->SetParameterName("Size",true);
  DetYPositionCmd5->SetUnitCategory("Length");
  DetYPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/SetCenterPositionInX",this);
  DetXPositionCmd5->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd5->SetParameterName("Size",true);
  DetXPositionCmd5->SetUnitCategory("Length");
  DetXPositionCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd5 = new G4UIcmdWithAString("/Det5/SetMaterial",this);
  DetMatCmd5->SetGuidance("Select Material of the Detetector.");
  DetMatCmd5->SetParameterName("choice",false);
  DetMatCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd5->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd5->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd5->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd5->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd5->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd5->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd5->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd5->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd5->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd5->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd5->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd5->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd5->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd5->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd5->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd5->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd5->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd5->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd5->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd5->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd5->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd5->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd5->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd5->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd5->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd5->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd5->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd5->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd5->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd5->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd5->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd5->SetParameterName("Size",true);
  LightGuideOffsetZCmd5->SetUnitCategory("Length");
  LightGuideOffsetZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd5->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd5->SetParameterName("Size",true);
  LightGuideOffsetYCmd5->SetUnitCategory("Length");
  LightGuideOffsetYCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd5->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd5->SetParameterName("Size",true);
  LightGuideOffsetXCmd5->SetUnitCategory("Length");
  LightGuideOffsetXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/QuartzSizeZ",this);
  QuartzSizeZCmd5->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd5->SetParameterName("Size",true);
  QuartzSizeZCmd5->SetUnitCategory("Length");
  QuartzSizeZCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/QuartzSizeY",this);
  QuartzSizeYCmd5->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd5->SetParameterName("Size",true);
  QuartzSizeYCmd5->SetUnitCategory("Length");
  QuartzSizeYCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/QuartzSizeX",this);
  QuartzSizeXCmd5->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd5->SetParameterName("Size",true);
  QuartzSizeXCmd5->SetUnitCategory("Length");
  QuartzSizeXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/QuartzRotX",this);
  QuartzRotXCmd5->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd5->SetParameterName("Angle",true);
  QuartzRotXCmd5->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd5->SetDefaultUnit("deg");
  QuartzRotXCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/PolarRotation",this);
  PolarRotationCmd5->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd5->SetParameterName("Angle",true);
  PolarRotationCmd5->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd5->SetDefaultUnit("deg");
  PolarRotationCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd5 = new G4UIcmdWithoutParameter("/Det5/UpdateGeometry",this);
  UpdateGeometryCmd5->SetGuidance("Update the geometry");
  UpdateGeometryCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd5 = new G4UIcmdWithoutParameter("/Det5/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd5->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd5 =  new G4UIcmdWithADoubleAndUnit("/Det5/QuartzBevelSize",this);
  QuartzBevelCmd5->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd5->SetParameterName("Bevel",true);
  QuartzBevelCmd5->SetUnitCategory("Length");
  QuartzBevelCmd5->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger5::~MOLLEROptDetectorMessenger5()
{

  if (DetXPositionCmd5)      delete DetXPositionCmd5;
  if (DetYPositionCmd5)      delete DetYPositionCmd5;
  if (DetZPositionCmd5)      delete DetZPositionCmd5;

  if(LightGuideUpperInterfaceCmd5          ) delete LightGuideUpperInterfaceCmd5;          
  if(LightGuideMiddleBoxCmd5               ) delete LightGuideMiddleBoxCmd5;
  if(LightGuideLowerInterfaceCmd5          ) delete LightGuideLowerInterfaceCmd5;          
  if(LightGuideLowerConeFrontAngleCmd5     ) delete LightGuideLowerConeFrontAngleCmd5;     
  if(LightGuideLowerConeBackAngleCmd5      ) delete LightGuideLowerConeBackAngleCmd5;      
  if(LightGuideLowerConeSideAngleCmd5      ) delete LightGuideLowerConeSideAngleCmd5;      
  if(LightGuideQuartzInterfaceOpeningXCmd5 ) delete LightGuideQuartzInterfaceOpeningXCmd5; 
  if(LightGuideQuartzInterfaceOpeningZCmd5 ) delete LightGuideQuartzInterfaceOpeningZCmd5; 
  if(LightGuidePMTInterfaceOpeningXCmd5    ) delete LightGuidePMTInterfaceOpeningXCmd5;    
  if(LightGuidePMTInterfaceOpeningZCmd5    ) delete LightGuidePMTInterfaceOpeningZCmd5;    
  if(LightGuideQuartzToPMTOffsetCmd5       ) delete LightGuideQuartzToPMTOffsetCmd5;       
  if(LightGuideOffsetXCmd5                 ) delete LightGuideOffsetXCmd5;                 
  if(LightGuideOffsetYCmd5                 ) delete LightGuideOffsetYCmd5;                 
  if(LightGuideOffsetZCmd5                 ) delete LightGuideOffsetZCmd5;

  if(UpdateGeometryCmd5                    ) delete UpdateGeometryCmd5;
  if(SegRadDamageCmd5                      ) delete SegRadDamageCmd5;
  
  if(QuartzSizeXCmd5                       ) delete QuartzSizeXCmd5;                       
  if(QuartzSizeYCmd5                       ) delete QuartzSizeYCmd5;                       
  if(QuartzSizeZCmd5                       ) delete QuartzSizeZCmd5;                       
  if(QuartzBevelCmd5                       ) delete QuartzBevelCmd5;                       
  if(QuartzRotXCmd5                        ) delete QuartzRotXCmd5;                       
  if(PolarRotationCmd5                     ) delete PolarRotationCmd5;                       
  
  if (DetMatCmd5)                            delete DetMatCmd5;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger5::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd5 ) Det5->SetCenterPositionInX(DetXPositionCmd5->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd5 ) Det5->SetCenterPositionInY(DetYPositionCmd5->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd5 ) Det5->SetCenterPositionInZ(DetZPositionCmd5->GetNewDoubleValue(newValue));
  if( command == DetMatCmd5 ) Det5->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd5 )         { Det5->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd5 )              { Det5->SetMiddleBoxHeight(LightGuideMiddleBoxCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd5 )         { Det5->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd5 )    { Det5->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd5 )     {Det5->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd5 )     { Det5->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd5 ){ Det5->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd5 ){ Det5->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd5 )   { Det5->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd5 )   { Det5->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd5 )      { Det5->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd5 )                { Det5->SetLightGuideOffsetInX(LightGuideOffsetXCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd5 )                { Det5->SetLightGuideOffsetInY(LightGuideOffsetYCmd5->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd5 )                { Det5->SetLightGuideOffsetInZ(LightGuideOffsetZCmd5->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd5 )                   { Det5->UpdateThisGeometry();}
  if( command == SegRadDamageCmd5)                      { Det5->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd5 )                      { Det5->SetQuartzSizeX(QuartzSizeXCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd5 )                      { Det5->SetQuartzSizeY(QuartzSizeYCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd5 )                      { Det5->SetQuartzSizeZ(QuartzSizeZCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd5 )                      { Det5->SetQuartzBevel(QuartzBevelCmd5->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd5 )                       { Det5->SetQuartzRotX(QuartzRotXCmd5->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd5 )                    { Det5->SetPolarRotationAngle(PolarRotationCmd5->GetNewDoubleValue(newValue));}

}
	
