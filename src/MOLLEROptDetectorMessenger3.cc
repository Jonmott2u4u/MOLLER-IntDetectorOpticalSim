#include "MOLLEROptDetectorMessenger3.hh"
MOLLEROptDetectorMessenger3::MOLLEROptDetectorMessenger3(MOLLEROptDetector3* theDet3)
  :Det3(theDet3)
{ 

  Dir = new G4UIdirectory("/Det3/");
  Dir -> SetGuidance("Detector control.");


  DetZPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/SetCenterPositionInZ",this);
  DetZPositionCmd3->SetGuidance("Set the Z position of the Detector container center"); 
  DetZPositionCmd3->SetParameterName("Size",true);
  DetZPositionCmd3->SetUnitCategory("Length");
  DetZPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/SetCenterPositionInY",this);
  DetYPositionCmd3->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd3->SetParameterName("Size",true);
  DetYPositionCmd3->SetUnitCategory("Length");
  DetYPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/SetCenterPositionInX",this);
  DetXPositionCmd3->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd3->SetParameterName("Size",true);
  DetXPositionCmd3->SetUnitCategory("Length");
  DetXPositionCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd3 = new G4UIcmdWithAString("/Det3/SetMaterial",this);
  DetMatCmd3->SetGuidance("Select Material of the Detetector.");
  DetMatCmd3->SetParameterName("choice",false);
  DetMatCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideUpperInterface",this); 
  LightGuideUpperInterfaceCmd3->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd3->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd3->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideMiddleBox",this); 
  LightGuideMiddleBoxCmd3->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd3->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd3->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideLowerInterface",this); 
  LightGuideLowerInterfaceCmd3->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd3->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd3->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideLowerConeFrontAngle",this);   
  LightGuideLowerConeFrontAngleCmd3->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideLowerConeBackAngle",this);   
  LightGuideLowerConeBackAngleCmd3->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideLowerConeSideAngle",this);   
  LightGuideLowerConeSideAngleCmd3->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd3->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd3->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd3->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideQuartzInterfaceOpeningX",this); 
  LightGuideQuartzInterfaceOpeningXCmd3->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd3->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd3->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideQuartzInterfaceOpeningZ",this); 
  LightGuideQuartzInterfaceOpeningZCmd3->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd3->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd3->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningXCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuidePMTInterfaceOpeningX",this); 
  LightGuidePMTInterfaceOpeningXCmd3->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd3->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd3->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuidePMTInterfaceOpeningZ",this); 
  LightGuidePMTInterfaceOpeningZCmd3->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd3->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd3->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideQuartzToPMTOffsetCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideQuartzToPMTOffset",this);      
  LightGuideQuartzToPMTOffsetCmd3->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd3->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd3->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                            
  
  LightGuideOffsetZCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideToQuartzOverallOffsetInZ",this);
  LightGuideOffsetZCmd3->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd3->SetParameterName("Size",true);
  LightGuideOffsetZCmd3->SetUnitCategory("Length");
  LightGuideOffsetZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideToQuartzOverallOffsetInY",this);
  LightGuideOffsetYCmd3->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd3->SetParameterName("Size",true);
  LightGuideOffsetYCmd3->SetUnitCategory("Length");
  LightGuideOffsetYCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/LightGuideToQuartzOverallOffsetInX",this);
  LightGuideOffsetXCmd3->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd3->SetParameterName("Size",true);
  LightGuideOffsetXCmd3->SetUnitCategory("Length");
  LightGuideOffsetXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeZCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/QuartzSizeZ",this);
  QuartzSizeZCmd3->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd3->SetParameterName("Size",true);
  QuartzSizeZCmd3->SetUnitCategory("Length");
  QuartzSizeZCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/QuartzSizeY",this);
  QuartzSizeYCmd3->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd3->SetParameterName("Size",true);
  QuartzSizeYCmd3->SetUnitCategory("Length");
  QuartzSizeYCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/QuartzSizeX",this);
  QuartzSizeXCmd3->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd3->SetParameterName("Size",true);
  QuartzSizeXCmd3->SetUnitCategory("Length");
  QuartzSizeXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/QuartzRotX",this);
  QuartzRotXCmd3->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd3->SetParameterName("Angle",true);
  QuartzRotXCmd3->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd3->SetDefaultUnit("deg");
  QuartzRotXCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/PolarRotation",this);
  PolarRotationCmd3->SetGuidance("Set the rotation angle of the enitre detector around X"); 
  PolarRotationCmd3->SetParameterName("Angle",true);
  PolarRotationCmd3->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd3->SetDefaultUnit("deg");
  PolarRotationCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd3 = new G4UIcmdWithoutParameter("/Det3/UpdateGeometry",this);
  UpdateGeometryCmd3->SetGuidance("Update the geometry");
  UpdateGeometryCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  SegRadDamageCmd3 = new G4UIcmdWithoutParameter("/Det3/SetSegmentedRadDamageFlag",this);
  SegRadDamageCmd3->SetGuidance("Implement segmented radiation damage simulation");
  SegRadDamageCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd3 =  new G4UIcmdWithADoubleAndUnit("/Det3/QuartzBevelSize",this);
  QuartzBevelCmd3->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd3->SetParameterName("Bevel",true);
  QuartzBevelCmd3->SetUnitCategory("Length");
  QuartzBevelCmd3->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  
}

MOLLEROptDetectorMessenger3::~MOLLEROptDetectorMessenger3()
{

  if (DetXPositionCmd3)      delete DetXPositionCmd3;
  if (DetYPositionCmd3)      delete DetYPositionCmd3;
  if (DetZPositionCmd3)      delete DetZPositionCmd3;

  if(LightGuideUpperInterfaceCmd3          ) delete LightGuideUpperInterfaceCmd3;          
  if(LightGuideMiddleBoxCmd3               ) delete LightGuideMiddleBoxCmd3;
  if(LightGuideLowerInterfaceCmd3          ) delete LightGuideLowerInterfaceCmd3;          
  if(LightGuideLowerConeFrontAngleCmd3     ) delete LightGuideLowerConeFrontAngleCmd3;     
  if(LightGuideLowerConeBackAngleCmd3      ) delete LightGuideLowerConeBackAngleCmd3;      
  if(LightGuideLowerConeSideAngleCmd3      ) delete LightGuideLowerConeSideAngleCmd3;      
  if(LightGuideQuartzInterfaceOpeningXCmd3 ) delete LightGuideQuartzInterfaceOpeningXCmd3; 
  if(LightGuideQuartzInterfaceOpeningZCmd3 ) delete LightGuideQuartzInterfaceOpeningZCmd3; 
  if(LightGuidePMTInterfaceOpeningXCmd3    ) delete LightGuidePMTInterfaceOpeningXCmd3;    
  if(LightGuidePMTInterfaceOpeningZCmd3    ) delete LightGuidePMTInterfaceOpeningZCmd3;    
  if(LightGuideQuartzToPMTOffsetCmd3       ) delete LightGuideQuartzToPMTOffsetCmd3;       
  if(LightGuideOffsetXCmd3                 ) delete LightGuideOffsetXCmd3;                 
  if(LightGuideOffsetYCmd3                 ) delete LightGuideOffsetYCmd3;                 
  if(LightGuideOffsetZCmd3                 ) delete LightGuideOffsetZCmd3;

  if(UpdateGeometryCmd3                    ) delete UpdateGeometryCmd3;
  if(SegRadDamageCmd3                      ) delete SegRadDamageCmd3;
  
  if(QuartzSizeXCmd3                       ) delete QuartzSizeXCmd3;                       
  if(QuartzSizeYCmd3                       ) delete QuartzSizeYCmd3;                       
  if(QuartzSizeZCmd3                       ) delete QuartzSizeZCmd3;                       
  if(QuartzBevelCmd3                       ) delete QuartzBevelCmd3;                       
  if(QuartzRotXCmd3                        ) delete QuartzRotXCmd3;                       
  if(PolarRotationCmd3                     ) delete PolarRotationCmd3;                       
  
  if (DetMatCmd3)                            delete DetMatCmd3;
  
  if (Dir)                                  delete Dir;
}

void MOLLEROptDetectorMessenger3::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  
  if( command == DetXPositionCmd3 ) Det3->SetCenterPositionInX(DetXPositionCmd3->GetNewDoubleValue(newValue));
  if( command == DetYPositionCmd3 ) Det3->SetCenterPositionInY(DetYPositionCmd3->GetNewDoubleValue(newValue));
  if( command == DetZPositionCmd3 ) Det3->SetCenterPositionInZ(DetZPositionCmd3->GetNewDoubleValue(newValue));
  if( command == DetMatCmd3 ) Det3->SetMaterial(newValue);

  if( command == LightGuideUpperInterfaceCmd3 )         { Det3->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd3 )              { Det3->SetMiddleBoxHeight(LightGuideMiddleBoxCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd3 )         { Det3->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd3 )    { Det3->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd3 )     {Det3->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd3 )     { Det3->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd3 ){ Det3->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd3 ){ Det3->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningXCmd3 )   { Det3->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd3 )   { Det3->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd3 )      { Det3->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd3 )                { Det3->SetLightGuideOffsetInX(LightGuideOffsetXCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd3 )                { Det3->SetLightGuideOffsetInY(LightGuideOffsetYCmd3->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd3 )                { Det3->SetLightGuideOffsetInZ(LightGuideOffsetZCmd3->GetNewDoubleValue(newValue));}
  
  if( command == UpdateGeometryCmd3 )                   { Det3->UpdateThisGeometry();}
  if( command == SegRadDamageCmd3)                      { Det3->SetSegRadDamageFlag();}
  
  if( command == QuartzSizeXCmd3 )                      { Det3->SetQuartzSizeX(QuartzSizeXCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd3 )                      { Det3->SetQuartzSizeY(QuartzSizeYCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd3 )                      { Det3->SetQuartzSizeZ(QuartzSizeZCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzBevelCmd3 )                      { Det3->SetQuartzBevel(QuartzBevelCmd3->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd3 )                       { Det3->SetQuartzRotX(QuartzRotXCmd3->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd3 )                    { Det3->SetPolarRotationAngle(PolarRotationCmd3->GetNewDoubleValue(newValue));}

}
	
