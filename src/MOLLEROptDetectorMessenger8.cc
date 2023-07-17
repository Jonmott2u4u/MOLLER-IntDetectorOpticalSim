#include "MOLLEROptDetectorMessenger8.hh"
MOLLEROptDetectorMessenger8::MOLLEROptDetectorMessenger8(MOLLEROptDetector8* theDet8)
  :Det8(theDet8)
{ 

  Dir = new G4UIdirectory("/Det8/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/SetCenterPositionInZ",this);
  DetZPositionCmd8->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd8->SetParameterName("Size",true);
  DetZPositionCmd8->SetUnitCategory("Length");
  DetZPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/SetCenterPositionInY",this);
  DetYPositionCmd8->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd8->SetParameterName("Size",true);
  DetYPositionCmd8->SetUnitCategory("Length");
  DetYPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/SetCenterPositionInX",this);
  DetXPositionCmd8->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd8->SetParameterName("Size",true);
  DetXPositionCmd8->SetUnitCategory("Length");
  DetXPositionCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd8 = new G4UIcmdWithAString("/Det8/SetMaterial",this);
  DetMatCmd8->SetGuidance("Select Material of the Detetector.");
  DetMatCmd8->SetParameterName("choice",false);
  DetMatCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd8->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd8->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd8->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd8->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd8->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd8->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd8->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd8->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd8->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd8->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd8->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd8->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd8->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd8->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd8->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd8->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd8->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd8->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd8->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd8->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd8->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd8->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd8->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd8->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd8->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd8->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd8->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd8->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd8->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd8->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd8->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd8->SetParameterName("Size",true);
  LightGuideOffsetZCmd8->SetUnitCategory("Length");
  LightGuideOffsetZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd8->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd8->SetParameterName("Size",true);
  LightGuideOffsetYCmd8->SetUnitCategory("Length");
  LightGuideOffsetYCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd8->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd8->SetParameterName("Size",true);
  LightGuideOffsetXCmd8->SetUnitCategory("Length");
  LightGuideOffsetXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/QuartzSizeZ",this);
  QuartzSizeZCmd8->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd8->SetParameterName("Size",true);
  QuartzSizeZCmd8->SetUnitCategory("Length");
  QuartzSizeZCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/QuartzSizeY",this);
  QuartzSizeYCmd8->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd8->SetParameterName("Size",true);
  QuartzSizeYCmd8->SetUnitCategory("Length");
  QuartzSizeYCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/QuartzSizeX",this);
  QuartzSizeXCmd8->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd8->SetParameterName("Size",true);
  QuartzSizeXCmd8->SetUnitCategory("Length");
  QuartzSizeXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/QuartzRotX",this);
  QuartzRotXCmd8->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd8->SetParameterName("Angle",true);
  QuartzRotXCmd8->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd8->SetDefaultUnit("deg");
  QuartzRotXCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/PolarRotation",this);
  PolarRotationCmd8->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd8->SetParameterName("Angle",true);
  PolarRotationCmd8->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd8->SetDefaultUnit("deg");
  PolarRotationCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd8 = new G4UIcmdWithoutParameter("/Det8/UpdateGeometry",this);
  UpdateGeometryCmd8->SetGuidance("Update the geometry");
  UpdateGeometryCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd8 = new G4UIcmdWithoutParameter("/Det8/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd8->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd8 =  new G4UIcmdWithADoubleAndUnit("/Det8/QuartzBevelSize",this);
  QuartzBevelCmd8->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd8->SetParameterName("Bevel",true);
  QuartzBevelCmd8->SetUnitCategory("Length");
  QuartzBevelCmd8->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger8::~MOLLEROptDetectorMessenger8()
{

  if (DetXPositionCmd8)      delete DetXPositionCmd8;
  if (DetYPositionCmd8)      delete DetYPositionCmd8;
  if (DetZPositionCmd8)      delete DetZPositionCmd8;

  if(LightGuideUpperInterfaceCmd8          ) delete LightGuideUpperInterfaceCmd8;          
  if(LightGuideMiddleBoxCmd8               ) delete LightGuideMiddleBoxCmd8;
  if(LightGuideLowerInterfaceCmd8          ) delete LightGuideLowerInterfaceCmd8;          
  if(LightGuideLowerConeFrontAngleCmd8     ) delete LightGuideLowerConeFrontAngleCmd8;     
  if(LightGuideLowerConeBackAngleCmd8      ) delete LightGuideLowerConeBackAngleCmd8;      
  if(LightGuideLowerConeSideAngleCmd8      ) delete LightGuideLowerConeSideAngleCmd8;      
  if(LightGuideQuartzInterfaceOpeningXCmd8 ) delete LightGuideQuartzInterfaceOpeningXCmd8; 
  if(LightGuideQuartzInterfaceOpeningZCmd8 ) delete LightGuideQuartzInterfaceOpeningZCmd8; 
  if(LightGuidePMTInterfaceOpeningXCmd8    ) delete LightGuidePMTInterfaceOpeningXCmd8;    
  if(LightGuidePMTInterfaceOpeningZCmd8    ) delete LightGuidePMTInterfaceOpeningZCmd8;    
  if(LightGuideQuartzToPMTOffsetCmd8       ) delete LightGuideQuartzToPMTOffsetCmd8;       
  if(LightGuideOffsetXCmd8                 ) delete LightGuideOffsetXCmd8;                 
  if(LightGuideOffsetYCmd8                 ) delete LightGuideOffsetYCmd8;                 
  if(LightGuideOffsetZCmd8                 ) delete LightGuideOffsetZCmd8;

  if(UpdateGeometryCmd8                    ) delete UpdateGeometryCmd8;
  if(SegRadDamageCmd8                      ) delete SegRadDamageCmd8;
  
  if(QuartzSizeXCmd8                       ) delete QuartzSizeXCmd8;                       
  if(QuartzSizeYCmd8                       ) delete QuartzSizeYCmd8;                       
  if(QuartzSizeZCmd8                       ) delete QuartzSizeZCmd8;                       
  if(QuartzBevelCmd8                       ) delete QuartzBevelCmd8;                       
  if(QuartzRotXCmd8                        ) delete QuartzRotXCmd8;                       
  if(PolarRotationCmd8                     ) delete PolarRotationCmd8;                       
  
  if (DetMatCmd8)                            delete DetMatCmd8;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger8::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd8 ) Det8->SetCenterPositionInX(DetXPositionCmd8->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd8 ) Det8->SetCenterPositionInY(DetYPositionCmd8->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd8 ) Det8->SetCenterPositionInZ(DetZPositionCmd8->GetNewDoubleValue(newValue));
  if( command == DetMatCmd8 ) Det8->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd8 )         { Det8->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd8 )              { Det8->SetMiddleBoxHeight(LightGuideMiddleBoxCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd8 )         { Det8->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd8 )    { Det8->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd8 )     {Det8->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd8 )     { Det8->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd8 ){ Det8->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd8 ){ Det8->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd8 )   { Det8->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd8 )   { Det8->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd8 )      { Det8->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd8 )                { Det8->SetLightGuideOffsetInX(LightGuideOffsetXCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd8 )                { Det8->SetLightGuideOffsetInY(LightGuideOffsetYCmd8->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd8 )                { Det8->SetLightGuideOffsetInZ(LightGuideOffsetZCmd8->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd8 )                   { Det8->UpdateThisGeometry();}
  if( command == SegRadDamageCmd8)                      { Det8->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd8 )                      { Det8->SetQuartzSizeX(QuartzSizeXCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd8 )                      { Det8->SetQuartzSizeY(QuartzSizeYCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd8 )                      { Det8->SetQuartzSizeZ(QuartzSizeZCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd8 )                      { Det8->SetQuartzBevel(QuartzBevelCmd8->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd8 )                       { Det8->SetQuartzRotX(QuartzRotXCmd8->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd8 )                    { Det8->SetPolarRotationAngle(PolarRotationCmd8->GetNewDoubleValue(newValue));}

}
	
