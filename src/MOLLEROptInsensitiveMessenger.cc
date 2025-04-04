#include "MOLLEROptInsensitiveMessenger.hh"

MOLLEROptInsensitiveMessenger::MOLLEROptInsensitiveMessenger(MOLLEROptInsensitive* theIns, G4String name)
  :Ins(theIns)
{ 

  InsType = name;
  Dir = new G4UIdirectory(Form("/%s/",name.data()));
  Dir -> SetGuidance(Form("Insensitive %s control.",name.data()));
  
  //Commands
  InsZPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInZ",name.data()),this);
  InsZPositionCmd->SetGuidance("Set the Z position of the Insensitive container center"); 
  InsZPositionCmd->SetParameterName("Size",true);
  InsZPositionCmd->SetUnitCategory("Length");
  InsZPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  InsYPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInY",name.data()),this);
  InsYPositionCmd->SetGuidance("Set the Y position of the Insensitive container center"); 
  InsYPositionCmd->SetParameterName("Size",true);
  InsYPositionCmd->SetUnitCategory("Length");
  InsYPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  InsXPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInX",name.data()),this);
  InsXPositionCmd->SetGuidance("Set the X position of the Insensitive container center"); 
  InsXPositionCmd->SetParameterName("Size",true);
  InsXPositionCmd->SetUnitCategory("Length");
  InsXPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                                   

  SizeZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeZ",name.data()),this);
  SizeZCmd->SetGuidance("Set the size of the object in Z"); 
  SizeZCmd->SetParameterName("Size",true);
  SizeZCmd->SetUnitCategory("Length");
  SizeZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  SizeYCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeY",name.data()),this);
  SizeYCmd->SetGuidance("Set the size of the object in Y"); 
  SizeYCmd->SetParameterName("Size",true);
  SizeYCmd->SetUnitCategory("Length");
  SizeYCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  SizeXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeX",name.data()),this);
  SizeXCmd->SetGuidance("Set the size of the object in X"); 
  SizeXCmd->SetParameterName("Size",true);
  SizeXCmd->SetUnitCategory("Length");
  SizeXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/PolarRotation",name.data()),this);
  PolarRotationCmd->SetGuidance("Set the rotation angle of the enitre Insensitive around X"); 
  PolarRotationCmd->SetParameterName("Angle",true);
  PolarRotationCmd->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd->SetDefaultUnit("deg");
  PolarRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AzimuthalRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/AzimuthalRotation",name.data()),this);
  AzimuthalRotationCmd->SetGuidance("Set the rotation angle of the enitre Insensitive around X"); 
  AzimuthalRotationCmd->SetParameterName("Angle",true);
  AzimuthalRotationCmd->SetRange("Angle>=-360. && Angle<=360.");
  AzimuthalRotationCmd->SetDefaultUnit("deg");
  AzimuthalRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd = new G4UIcmdWithoutParameter(Form("/%s/UpdateGeometry",name.data()),this);
  UpdateGeometryCmd->SetGuidance("Update the geometry");
  UpdateGeometryCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  InsMatCmd = new G4UIcmdWithAString(Form("/%s/SetMaterial",name.data()),this);
  InsMatCmd->SetGuidance("Select material of the Insensitive volume.");
  InsMatCmd->SetParameterName("choice",false);
  InsMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
}

MOLLEROptInsensitiveMessenger::~MOLLEROptInsensitiveMessenger()
{
  if(InsXPositionCmd			          ) delete InsXPositionCmd;
  if(InsYPositionCmd			          ) delete InsYPositionCmd;
  if(InsZPositionCmd			          ) delete InsZPositionCmd;
  if(SizeXCmd                       ) delete SizeXCmd;                       
  if(SizeYCmd                       ) delete SizeYCmd;                       
  if(SizeZCmd                       ) delete SizeZCmd;                   
  if(PolarRotationCmd               ) delete PolarRotationCmd;      
  if(AzimuthalRotationCmd           ) delete AzimuthalRotationCmd;              
  
  if(UpdateGeometryCmd              ) delete UpdateGeometryCmd;
  if(InsMatCmd                      ) delete InsMatCmd;
  if(Dir                            ) delete Dir;
}

void MOLLEROptInsensitiveMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == InsXPositionCmd ) 			{ Ins->SetCenterPositionInX(InsXPositionCmd->GetNewDoubleValue(newValue));}
  if( command == InsYPositionCmd ) 			{ Ins->SetCenterPositionInY(InsYPositionCmd->GetNewDoubleValue(newValue));}
  if( command == InsZPositionCmd ) 			{ Ins->SetCenterPositionInZ(InsZPositionCmd->GetNewDoubleValue(newValue));}
  if( command == SizeXCmd )             { Ins->SetSizeX(SizeXCmd->GetNewDoubleValue(newValue));}
  if( command == SizeYCmd )             { Ins->SetSizeY(SizeYCmd->GetNewDoubleValue(newValue));}
  if( command == SizeZCmd )             { Ins->SetSizeZ(SizeZCmd->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd )     { Ins->SetPolarRotationAngle(PolarRotationCmd->GetNewDoubleValue(newValue));}
  if( command == AzimuthalRotationCmd ) { Ins->SetAzimuthalRotationAngle(AzimuthalRotationCmd->GetNewDoubleValue(newValue));}

  if( command == UpdateGeometryCmd )    { Ins->UpdateThisGeometry();}
  if( command == InsMatCmd ) 			      { Ins->SetMaterial(newValue);}

}
