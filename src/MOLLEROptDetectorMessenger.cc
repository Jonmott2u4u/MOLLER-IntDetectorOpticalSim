#include "MOLLEROptDetectorMessenger.hh"

MOLLEROptDetectorMessenger::MOLLEROptDetectorMessenger(MOLLEROptDetector* theDet, G4String name)
  :Det(theDet)
{ 

  DetType = name;
  G4cout << "This is the directory name: " + DetType << G4endl;
  Dir = new G4UIdirectory(Form("/%s/",name.data()));
  Dir -> SetGuidance(Form("Ring %s control.",name.data()));
  
  //Commands
  DetZPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInZ",name.data()),this);
  DetZPositionCmd->SetGuidance("Set the Z position of the Detetect container center"); 
  DetZPositionCmd->SetParameterName("Size",true);
  DetZPositionCmd->SetUnitCategory("Length");
  DetZPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetYPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInY",name.data()),this);
  DetYPositionCmd->SetGuidance("Set the Y position of the Detector container center"); 
  DetYPositionCmd->SetParameterName("Size",true);
  DetYPositionCmd->SetUnitCategory("Length");
  DetYPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetXPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInX",name.data()),this);
  DetXPositionCmd->SetGuidance("Set the X position of the Detector container center"); 
  DetXPositionCmd->SetParameterName("Size",true);
  DetXPositionCmd->SetUnitCategory("Length");
  DetXPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideUpperInterfaceCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideUpperInterface",name.data()),this); 
  LightGuideUpperInterfaceCmd->SetGuidance("Set the light guide to PMT interface Y location.") ;         
  LightGuideUpperInterfaceCmd->SetParameterName("Size",true);                   
  LightGuideUpperInterfaceCmd->SetUnitCategory("Length");                       
  LightGuideUpperInterfaceCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                      
  
  LightGuideMiddleBoxCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideMiddleBox",name.data()),this); 
  LightGuideMiddleBoxCmd->SetGuidance("Set the light guide straight middle box height.") ;         
  LightGuideMiddleBoxCmd->SetParameterName("Size",true);                   
  LightGuideMiddleBoxCmd->SetUnitCategory("Length");                       
  LightGuideMiddleBoxCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideLowerInterfaceCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideLowerInterface",name.data()),this); 
  LightGuideLowerInterfaceCmd->SetGuidance("Set the light guide to Quartz interface Y location.") ;         
  LightGuideLowerInterfaceCmd->SetParameterName("Size",true);                   
  LightGuideLowerInterfaceCmd->SetUnitCategory("Length");                       
  LightGuideLowerInterfaceCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                      

  LightGuideLowerConeFrontAngleCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideLowerConeFrontAngle",name.data()),this);   
  LightGuideLowerConeFrontAngleCmd->SetGuidance("Set the upstream face angle of the lower cone wrt. the Y axis (up)");      
  LightGuideLowerConeFrontAngleCmd->SetParameterName("Angle",true);                                            
  LightGuideLowerConeFrontAngleCmd->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeFrontAngleCmd->SetDefaultUnit("deg");
  LightGuideLowerConeFrontAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeBackAngleCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideLowerConeBackAngle",name.data()),this);   
  LightGuideLowerConeBackAngleCmd->SetGuidance("Set the downstream face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeBackAngleCmd->SetParameterName("Angle",true);                                            
  LightGuideLowerConeBackAngleCmd->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeBackAngleCmd->SetDefaultUnit("deg");
  LightGuideLowerConeBackAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideLowerConeSideAngleCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideLowerConeSideAngle",name.data()),this);   
  LightGuideLowerConeSideAngleCmd->SetGuidance("Set the side face angle of the lower cone wrt. the Y axis");      
  LightGuideLowerConeSideAngleCmd->SetParameterName("Angle",true);                                            
  LightGuideLowerConeSideAngleCmd->SetRange("Angle>=0. && Angle<=45.");
  LightGuideLowerConeSideAngleCmd->SetDefaultUnit("deg");
  LightGuideLowerConeSideAngleCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                         

  LightGuideQuartzInterfaceOpeningXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideQuartzInterfaceOpeningX",name.data()),this); 
  LightGuideQuartzInterfaceOpeningXCmd->SetGuidance("Set the light guide to Quartz interface beam-left/right opening.") ;    
  LightGuideQuartzInterfaceOpeningXCmd->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningXCmd->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuideQuartzInterfaceOpeningZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideQuartzInterfaceOpeningZ",name.data()),this); 
  LightGuideQuartzInterfaceOpeningZCmd->SetGuidance("Set the light guide to Quartz interface beam direction opening.") ;    
  LightGuideQuartzInterfaceOpeningZCmd->SetParameterName("Size",true);                                          
  LightGuideQuartzInterfaceOpeningZCmd->SetUnitCategory("Length");                                              
  LightGuideQuartzInterfaceOpeningZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  QuartzSizeZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/QuartzSizeZ",name.data()),this);
  QuartzSizeZCmd->SetGuidance("Set the size of the quartz in Z"); 
  QuartzSizeZCmd->SetParameterName("Size",true);
  QuartzSizeZCmd->SetUnitCategory("Length");
  QuartzSizeZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  QuartzSizeYCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/QuartzSizeY",name.data()),this);
  QuartzSizeYCmd->SetGuidance("Set the size of the quartz in Y"); 
  QuartzSizeYCmd->SetParameterName("Size",true);
  QuartzSizeYCmd->SetUnitCategory("Length");
  QuartzSizeYCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzSizeXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/QuartzSizeX",name.data()),this);
  QuartzSizeXCmd->SetGuidance("Set the size of the quartz in X"); 
  QuartzSizeXCmd->SetParameterName("Size",true);
  QuartzSizeXCmd->SetUnitCategory("Length");
  QuartzSizeXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideQuartzToPMTOffsetCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideQuartzToPMTOffset",name.data()),this);      
  LightGuideQuartzToPMTOffsetCmd->SetGuidance("Set the offset between the quartz and PMT light guide openings in the beam direction.") ;         
  LightGuideQuartzToPMTOffsetCmd->SetParameterName("Size",true);                                               
  LightGuideQuartzToPMTOffsetCmd->SetUnitCategory("Length");                                                   
  LightGuideQuartzToPMTOffsetCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  //General objects
  LightGuidePMTInterfaceOpeningXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuidePMTInterfaceOpeningX",name.data()),this); 
  LightGuidePMTInterfaceOpeningXCmd->SetGuidance("Set the light guide to PMT interface beam-left/right opening.") ;    
  LightGuidePMTInterfaceOpeningXCmd->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningXCmd->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                       

  LightGuidePMTInterfaceOpeningZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuidePMTInterfaceOpeningZ",name.data()),this); 
  LightGuidePMTInterfaceOpeningZCmd->SetGuidance("Set the light guide to PMT interface beam direction opening.") ;    
  LightGuidePMTInterfaceOpeningZCmd->SetParameterName("Size",true);                                          
  LightGuidePMTInterfaceOpeningZCmd->SetUnitCategory("Length");                                              
  LightGuidePMTInterfaceOpeningZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  LightGuideOffsetZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideToQuartzOverallOffsetInZ",name.data()),this);
  LightGuideOffsetZCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetZCmd->SetParameterName("Size",true);
  LightGuideOffsetZCmd->SetUnitCategory("Length");
  LightGuideOffsetZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  LightGuideOffsetYCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideToQuartzOverallOffsetInY",name.data()),this);
  LightGuideOffsetYCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetYCmd->SetParameterName("Size",true);
  LightGuideOffsetYCmd->SetUnitCategory("Length");
  LightGuideOffsetYCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  LightGuideOffsetXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/LightGuideToQuartzOverallOffsetInX",name.data()),this);
  LightGuideOffsetXCmd->SetGuidance("Set the offset of the entire light guide w.r.t the quartz"); 
  LightGuideOffsetXCmd->SetParameterName("Size",true);
  LightGuideOffsetXCmd->SetUnitCategory("Length");
  LightGuideOffsetXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzRotXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/QuartzRotX",name.data()),this);
  QuartzRotXCmd->SetGuidance("Set the rotation angle of the quartz around X"); 
  QuartzRotXCmd->SetParameterName("Angle",true);
  QuartzRotXCmd->SetRange("Angle>=-90. && Angle<=90.");
  QuartzRotXCmd->SetDefaultUnit("deg");
  QuartzRotXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/PolarRotation",name.data()),this);
  PolarRotationCmd->SetGuidance("Set the rotation angle of the detector around X"); 
  PolarRotationCmd->SetParameterName("Angle",true);
  PolarRotationCmd->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd->SetDefaultUnit("deg");
  PolarRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AzimuthalRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/AzimuthalRotation",name.data()),this);
  AzimuthalRotationCmd->SetGuidance("Set the rotation angle of the detector around Z"); 
  AzimuthalRotationCmd->SetParameterName("Angle",true);
  AzimuthalRotationCmd->SetRange("Angle>=-360. && Angle<=360.");
  AzimuthalRotationCmd->SetDefaultUnit("deg");
  AzimuthalRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  YawRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/YawRotation",name.data()),this);
  YawRotationCmd->SetGuidance("Set the rotation angle of the detector around Y"); 
  YawRotationCmd->SetParameterName("Angle",true);
  YawRotationCmd->SetRange("Angle>=-90. && Angle<=90.");
  YawRotationCmd->SetDefaultUnit("deg");
  YawRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd = new G4UIcmdWithoutParameter(Form("/%s/UpdateGeometry",name.data()),this);
  UpdateGeometryCmd->SetGuidance("Update the geometry");
  UpdateGeometryCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  QuartzBevelCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/QuartzBevelSize",name.data()),this);
  QuartzBevelCmd->SetGuidance("Set the size of the quartz edge bevel"); 
  QuartzBevelCmd->SetParameterName("Bevel",true);
  QuartzBevelCmd->SetUnitCategory("Length");
  QuartzBevelCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  DetMatCmd = new G4UIcmdWithAString(Form("/%s/SetMaterial",name.data()),this);
  DetMatCmd->SetGuidance("Select Material of the Detetector.");
  DetMatCmd->SetParameterName("choice",false);
  DetMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
}

MOLLEROptDetectorMessenger::~MOLLEROptDetectorMessenger()
{
  if(DetXPositionCmd			                ) delete DetXPositionCmd;
  if(DetYPositionCmd		             	    ) delete DetYPositionCmd;
  if(DetZPositionCmd			                ) delete DetZPositionCmd;
  if(QuartzRotXCmd                        ) delete QuartzRotXCmd;      
  if(QuartzSizeXCmd                       ) delete QuartzSizeXCmd;                       
  if(QuartzSizeYCmd                       ) delete QuartzSizeYCmd;                       
  if(QuartzSizeZCmd                       ) delete QuartzSizeZCmd;
  if(LightGuideUpperInterfaceCmd          ) delete LightGuideUpperInterfaceCmd;          
  if(LightGuideMiddleBoxCmd               ) delete LightGuideMiddleBoxCmd;
  if(LightGuideLowerInterfaceCmd          ) delete LightGuideLowerInterfaceCmd;          
  if(LightGuideLowerConeFrontAngleCmd     ) delete LightGuideLowerConeFrontAngleCmd;     
  if(LightGuideLowerConeBackAngleCmd      ) delete LightGuideLowerConeBackAngleCmd;      
  if(LightGuideLowerConeSideAngleCmd      ) delete LightGuideLowerConeSideAngleCmd;      
  if(LightGuideQuartzInterfaceOpeningXCmd ) delete LightGuideQuartzInterfaceOpeningXCmd; 
  if(LightGuideQuartzInterfaceOpeningZCmd ) delete LightGuideQuartzInterfaceOpeningZCmd; 
  if(LightGuideQuartzToPMTOffsetCmd       ) delete LightGuideQuartzToPMTOffsetCmd;  

  if(LightGuideOffsetXCmd                 ) delete LightGuideOffsetXCmd;                 
  if(LightGuideOffsetYCmd                 ) delete LightGuideOffsetYCmd;                 
  if(LightGuideOffsetZCmd                 ) delete LightGuideOffsetZCmd;
  if(LightGuidePMTInterfaceOpeningXCmd    ) delete LightGuidePMTInterfaceOpeningXCmd;    
  if(LightGuidePMTInterfaceOpeningZCmd    ) delete LightGuidePMTInterfaceOpeningZCmd;
  if(QuartzBevelCmd                       ) delete QuartzBevelCmd;                                           
  if(PolarRotationCmd                     ) delete PolarRotationCmd; 
  if(AzimuthalRotationCmd                 ) delete AzimuthalRotationCmd; 
  if(YawRotationCmd                       ) delete YawRotationCmd; 
  
  if(UpdateGeometryCmd                    ) delete UpdateGeometryCmd;
  if(DetMatCmd                            ) delete DetMatCmd;
  if(Dir                                  ) delete Dir;
}

void MOLLEROptDetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == DetXPositionCmd ) 		               	 { Det->SetCenterPositionInX(DetXPositionCmd->GetNewDoubleValue(newValue));}
  if( command == DetYPositionCmd ) 		               	 { Det->SetCenterPositionInY(DetYPositionCmd->GetNewDoubleValue(newValue));}
  if( command == DetZPositionCmd ) 		               	 { Det->SetCenterPositionInZ(DetZPositionCmd->GetNewDoubleValue(newValue));}
  if( command == QuartzRotXCmd )                       { Det->SetQuartzRotX(QuartzRotXCmd->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeXCmd )                      { Det->SetQuartzSizeX(QuartzSizeXCmd->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeYCmd )                      { Det->SetQuartzSizeY(QuartzSizeYCmd->GetNewDoubleValue(newValue));}
  if( command == QuartzSizeZCmd )                      { Det->SetQuartzSizeZ(QuartzSizeZCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideUpperInterfaceCmd )         { Det->SetUpperInterfacePlane(LightGuideUpperInterfaceCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideMiddleBoxCmd )              { Det->SetMiddleBoxHeight(LightGuideMiddleBoxCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerInterfaceCmd )         { Det->SetLowerInterfacePlane(LightGuideLowerInterfaceCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeFrontAngleCmd )    { Det->SetLowerConeFrontFaceAngle(LightGuideLowerConeFrontAngleCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeBackAngleCmd )     { Det->SetLowerConeBackFaceAngle(LightGuideLowerConeBackAngleCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideLowerConeSideAngleCmd )     { Det->SetLowerConeSideFaceAngle(LightGuideLowerConeSideAngleCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningXCmd ){ Det->SetQuartzInterfaceOpeningX(LightGuideQuartzInterfaceOpeningXCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzInterfaceOpeningZCmd ){ Det->SetQuartzInterfaceOpeningZ(LightGuideQuartzInterfaceOpeningZCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideQuartzToPMTOffsetCmd )      { Det->SetQuartzToPMTOffsetInZ(LightGuideQuartzToPMTOffsetCmd->GetNewDoubleValue(newValue));}

  if( command == UpdateGeometryCmd )                   { Det->UpdateThisGeometry();}
  if( command == LightGuidePMTInterfaceOpeningXCmd )   { Det->SetPMTInterfaceOpeningX(LightGuidePMTInterfaceOpeningXCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuidePMTInterfaceOpeningZCmd )   { Det->SetPMTInterfaceOpeningZ(LightGuidePMTInterfaceOpeningZCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetXCmd )                { Det->SetLightGuideOffsetInX(LightGuideOffsetXCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetYCmd )                { Det->SetLightGuideOffsetInY(LightGuideOffsetYCmd->GetNewDoubleValue(newValue));}
  if( command == LightGuideOffsetZCmd )                { Det->SetLightGuideOffsetInZ(LightGuideOffsetZCmd->GetNewDoubleValue(newValue));}
  if( command == DetMatCmd ) 			                     { Det->SetMaterial(newValue);}
  if( command == QuartzBevelCmd )                      { Det->SetQuartzBevel(QuartzBevelCmd->GetNewDoubleValue(newValue));}
  if( command == YawRotationCmd )                      { Det->SetYawRotationAngle(YawRotationCmd->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd )                    { Det->SetPolarRotationAngle(PolarRotationCmd->GetNewDoubleValue(newValue));}
  if( command == AzimuthalRotationCmd )                { Det->SetAzimuthalRotationAngle(AzimuthalRotationCmd->GetNewDoubleValue(newValue));}

}
