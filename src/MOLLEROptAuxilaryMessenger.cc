#include "MOLLEROptAuxilaryMessenger.hh"

MOLLEROptAuxilaryMessenger::MOLLEROptAuxilaryMessenger(MOLLEROptAuxilary* theAux, G4String name)
  :Aux(theAux)
{ 

  AuxType = name;
  Dir = new G4UIdirectory(Form("/%s/",name.data()));
  Dir -> SetGuidance(Form("Scint %s control.",name.data()));
  
  //Commands
  AuxZPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInZ",name.data()),this);
  AuxZPositionCmd->SetGuidance("Set the Z position of the Auxilary container center"); 
  AuxZPositionCmd->SetParameterName("Size",true);
  AuxZPositionCmd->SetUnitCategory("Length");
  AuxZPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AuxYPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInY",name.data()),this);
  AuxYPositionCmd->SetGuidance("Set the Y position of the Auxilary container center"); 
  AuxYPositionCmd->SetParameterName("Size",true);
  AuxYPositionCmd->SetUnitCategory("Length");
  AuxYPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AuxXPositionCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SetCenterPositionInX",name.data()),this);
  AuxXPositionCmd->SetGuidance("Set the X position of the Auxilary container center"); 
  AuxXPositionCmd->SetParameterName("Size",true);
  AuxXPositionCmd->SetUnitCategory("Length");
  AuxXPositionCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                                   

  SizeZCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeZ",name.data()),this);
  SizeZCmd->SetGuidance("Set the size of the quartz in Z"); 
  SizeZCmd->SetParameterName("Size",true);
  SizeZCmd->SetUnitCategory("Length");
  SizeZCmd->AvailableForStates(G4State_PreInit,G4State_Idle);                  

  SizeYCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeY",name.data()),this);
  SizeYCmd->SetGuidance("Set the size of the quartz in Y"); 
  SizeYCmd->SetParameterName("Size",true);
  SizeYCmd->SetUnitCategory("Length");
  SizeYCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  SizeXCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/SizeX",name.data()),this);
  SizeXCmd->SetGuidance("Set the size of the quartz in X"); 
  SizeXCmd->SetParameterName("Size",true);
  SizeXCmd->SetUnitCategory("Length");
  SizeXCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  PolarRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/PolarRotation",name.data()),this);
  PolarRotationCmd->SetGuidance("Set the rotation angle of the enitre Auxilary around X"); 
  PolarRotationCmd->SetParameterName("Angle",true);
  PolarRotationCmd->SetRange("Angle>=-90. && Angle<=90.");
  PolarRotationCmd->SetDefaultUnit("deg");
  PolarRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AzimuthalRotationCmd =  new G4UIcmdWithADoubleAndUnit(Form("/%s/AzimuthalRotation",name.data()),this);
  AzimuthalRotationCmd->SetGuidance("Set the rotation angle of the enitre Auxilary around X"); 
  AzimuthalRotationCmd->SetParameterName("Angle",true);
  AzimuthalRotationCmd->SetRange("Angle>=-360. && Angle<=360.");
  AzimuthalRotationCmd->SetDefaultUnit("deg");
  AzimuthalRotationCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  UpdateGeometryCmd = new G4UIcmdWithoutParameter(Form("/%s/UpdateGeometry",name.data()),this);
  UpdateGeometryCmd->SetGuidance("Update the geometry");
  UpdateGeometryCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  AuxMatCmd = new G4UIcmdWithAString(Form("/%s/SetMaterial",name.data()),this);
  AuxMatCmd->SetGuidance("Select material of the auxilary volume.");
  AuxMatCmd->SetParameterName("choice",false);
  AuxMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
}

MOLLEROptAuxilaryMessenger::~MOLLEROptAuxilaryMessenger()
{
  if(AuxXPositionCmd			          ) delete AuxXPositionCmd;
  if(AuxYPositionCmd			          ) delete AuxYPositionCmd;
  if(AuxZPositionCmd			          ) delete AuxZPositionCmd;
  if(SizeXCmd                       ) delete SizeXCmd;                       
  if(SizeYCmd                       ) delete SizeYCmd;                       
  if(SizeZCmd                       ) delete SizeZCmd;                   
  if(PolarRotationCmd               ) delete PolarRotationCmd;      
  if(AzimuthalRotationCmd           ) delete AzimuthalRotationCmd;              
  
  if(UpdateGeometryCmd              ) delete UpdateGeometryCmd;
  if(AuxMatCmd                      ) delete AuxMatCmd;
  if(Dir                            ) delete Dir;
}

void MOLLEROptAuxilaryMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == AuxXPositionCmd ) 		  	{ Aux->SetCenterPositionInX(AuxXPositionCmd->GetNewDoubleValue(newValue));}
  if( command == AuxYPositionCmd ) 		  	{ Aux->SetCenterPositionInY(AuxYPositionCmd->GetNewDoubleValue(newValue));}
  if( command == AuxZPositionCmd ) 		  	{ Aux->SetCenterPositionInZ(AuxZPositionCmd->GetNewDoubleValue(newValue));}
  if( command == SizeXCmd )               { Aux->SetSizeX(SizeXCmd->GetNewDoubleValue(newValue));}
  if( command == SizeYCmd )               { Aux->SetSizeY(SizeYCmd->GetNewDoubleValue(newValue));}
  if( command == SizeZCmd )               { Aux->SetSizeZ(SizeZCmd->GetNewDoubleValue(newValue));}
  if( command == PolarRotationCmd )       { Aux->SetPolarRotationAngle(PolarRotationCmd->GetNewDoubleValue(newValue));}
  if( command == AzimuthalRotationCmd )   { Aux->SetAzimuthalRotationAngle(AzimuthalRotationCmd->GetNewDoubleValue(newValue));}

  if( command == UpdateGeometryCmd )      { Aux->UpdateThisGeometry();}
  if( command == AuxMatCmd ) 			        { Aux->SetMaterial(newValue);}

}
