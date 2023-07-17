#include "MOLLEROptDetectorMessenger2.hh"
MOLLEROptDetectorMessenger2::MOLLEROptDetectorMessenger2(MOLLEROptDetector2* theDet2)
  :Det2(theDet2)
{ 

  Dir = new G4UIdirectory("/Det2/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/SetCenterPositionInZ",this);
  DetZPositionCmd2->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd2->SetParameterName("Size",true);
  DetZPositionCmd2->SetUnitCategory("Length");
  DetZPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/SetCenterPositionInY",this);
  DetYPositionCmd2->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd2->SetParameterName("Size",true);
  DetYPositionCmd2->SetUnitCategory("Length");
  DetYPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/SetCenterPositionInX",this);
  DetXPositionCmd2->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd2->SetParameterName("Size",true);
  DetXPositionCmd2->SetUnitCategory("Length");
  DetXPositionCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd2 = new G4UIcmdWithAString("/Det2/SetMaterial",this);
  DetMatCmd2->SetGuidance("Select Material of the Detetector.");
  DetMatCmd2->SetParameterName("choice",false);
  DetMatCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd2->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd2->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd2->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd2->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd2->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd2->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd2->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd2->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd2->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd2->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd2->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd2->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd2->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd2->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd2->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd2->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd2->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd2->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd2->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd2->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd2->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd2->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd2->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd2->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd2->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd2->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd2->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd2->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd2->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd2->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd2->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd2->SetParameterName("Size",true);
  LightGuideOffsetZCmd2->SetUnitCategory("Length");
  LightGuideOffsetZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd2->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd2->SetParameterName("Size",true);
  LightGuideOffsetYCmd2->SetUnitCategory("Length");
  LightGuideOffsetYCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd2->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd2->SetParameterName("Size",true);
  LightGuideOffsetXCmd2->SetUnitCategory("Length");
  LightGuideOffsetXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/QuartzSizeZ",this);
  QuartzSizeZCmd2->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd2->SetParameterName("Size",true);
  QuartzSizeZCmd2->SetUnitCategory("Length");
  QuartzSizeZCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/QuartzSizeY",this);
  QuartzSizeYCmd2->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd2->SetParameterName("Size",true);
  QuartzSizeYCmd2->SetUnitCategory("Length");
  QuartzSizeYCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/QuartzSizeX",this);
  QuartzSizeXCmd2->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd2->SetParameterName("Size",true);
  QuartzSizeXCmd2->SetUnitCategory("Length");
  QuartzSizeXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/QuartzRotX",this);
  QuartzRotXCmd2->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd2->SetParameterName("Angle",true);
  QuartzRotXCmd2->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd2->SetDefaultUnit("deg");
  QuartzRotXCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/PolarRotation",this);
  PolarRotationCmd2->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd2->SetParameterName("Angle",true);
  PolarRotationCmd2->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd2->SetDefaultUnit("deg");
  PolarRotationCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd2 = new G4UIcmdWithoutParameter("/Det2/UpdateGeometry",this);
  UpdateGeometryCmd2->SetGuidance("Update the geometry");
  UpdateGeometryCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd2 = new G4UIcmdWithoutParameter("/Det2/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd2->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd2 =  new G4UIcmdWithADoubleAndUnit("/Det2/QuartzBevelSize",this);
  QuartzBevelCmd2->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd2->SetParameterName("Bevel",true);
  QuartzBevelCmd2->SetUnitCategory("Length");
  QuartzBevelCmd2->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger2::~MOLLEROptDetectorMessenger2()
{

  if (DetXPositionCmd2)      delete DetXPositionCmd2;
  if (DetYPositionCmd2)      delete DetYPositionCmd2;
  if (DetZPositionCmd2)      delete DetZPositionCmd2;

  if(LightGuideUpperInterfaceCmd2          ) delete LightGuideUpperInterfaceCmd2;          
  if(LightGuideMiddleBoxCmd2               ) delete LightGuideMiddleBoxCmd2;
  if(LightGuideLowerInterfaceCmd2          ) delete LightGuideLowerInterfaceCmd2;          
  if(LightGuideLowerConeFrontAngleCmd2     ) delete LightGuideLowerConeFrontAngleCmd2;     
  if(LightGuideLowerConeBackAngleCmd2      ) delete LightGuideLowerConeBackAngleCmd2;      
  if(LightGuideLowerConeSideAngleCmd2      ) delete LightGuideLowerConeSideAngleCmd2;      
  if(LightGuideQuartzInterfaceOpeningXCmd2 ) delete LightGuideQuartzInterfaceOpeningXCmd2; 
  if(LightGuideQuartzInterfaceOpeningZCmd2 ) delete LightGuideQuartzInterfaceOpeningZCmd2; 
  if(LightGuidePMTInterfaceOpeningXCmd2    ) delete LightGuidePMTInterfaceOpeningXCmd2;    
  if(LightGuidePMTInterfaceOpeningZCmd2    ) delete LightGuidePMTInterfaceOpeningZCmd2;    
  if(LightGuideQuartzToPMTOffsetCmd2       ) delete LightGuideQuartzToPMTOffsetCmd2;       
  if(LightGuideOffsetXCmd2                 ) delete LightGuideOffsetXCmd2;                 
  if(LightGuideOffsetYCmd2                 ) delete LightGuideOffsetYCmd2;                 
  if(LightGuideOffsetZCmd2                 ) delete LightGuideOffsetZCmd2;

  if(UpdateGeometryCmd2                    ) delete UpdateGeometryCmd2;
  if(SegRadDamageCmd2                      ) delete SegRadDamageCmd2;
  
  if(QuartzSizeXCmd2                       ) delete QuartzSizeXCmd2;                       
  if(QuartzSizeYCmd2                       ) delete QuartzSizeYCmd2;                       
  if(QuartzSizeZCmd2                       ) delete QuartzSizeZCmd2;                       
  if(QuartzBevelCmd2                       ) delete QuartzBevelCmd2;                       
  if(QuartzRotXCmd2                        ) delete QuartzRotXCmd2;                       
  if(PolarRotationCmd2                     ) delete PolarRotationCmd2;                       
  
  if (DetMatCmd2)                            delete DetMatCmd2;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger2::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd2 ) Det2->SetCenterPositionInX(DetXPositionCmd2->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd2 ) Det2->SetCenterPositionInY(DetYPositionCmd2->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd2 ) Det2->SetCenterPositionInZ(DetZPositionCmd2->GetNewDoubleValue(newValue));
  if( command == DetMatCmd2 ) Det2->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd2 )         { Det2->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd2 )              { Det2->SetMiddleBoxHeight(LightGuideMiddleBoxCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd2 )         { Det2->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd2 )    { Det2->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd2 )     {Det2->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd2 )     { Det2->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd2 ){ Det2->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd2 ){ Det2->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd2 )   { Det2->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd2 )   { Det2->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd2 )      { Det2->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd2 )                { Det2->SetLightGuideOffsetInX(LightGuideOffsetXCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd2 )                { Det2->SetLightGuideOffsetInY(LightGuideOffsetYCmd2->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd2 )                { Det2->SetLightGuideOffsetInZ(LightGuideOffsetZCmd2->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd2 )                   { Det2->UpdateThisGeometry();}
  if( command == SegRadDamageCmd2)                      { Det2->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd2 )                      { Det2->SetQuartzSizeX(QuartzSizeXCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd2 )                      { Det2->SetQuartzSizeY(QuartzSizeYCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd2 )                      { Det2->SetQuartzSizeZ(QuartzSizeZCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd2 )                      { Det2->SetQuartzBevel(QuartzBevelCmd2->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd2 )                       { Det2->SetQuartzRotX(QuartzRotXCmd2->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd2 )                    { Det2->SetPolarRotationAngle(PolarRotationCmd2->GetNewDoubleValue(newValue));}

}
	
