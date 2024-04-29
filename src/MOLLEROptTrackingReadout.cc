#include "MOLLEROptTrackingReadout.hh"

MOLLEROptTrackingReadout::MOLLEROptTrackingReadout()
{
  Initialize();
  QAbsProf.clear();
  QAbsProf.resize(0);
}

MOLLEROptTrackingReadout::~MOLLEROptTrackingReadout()
{
  
}

void MOLLEROptTrackingReadout::AddTrackData(Int_t id, Int_t type, Int_t StepL, Int_t QEFlag, Int_t PMTHit, Int_t Volume, Int_t Proc, Float_t eng, Float_t wvl, Float_t Ang)
{
  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;

  if(tr == -1) return;

  if(Volume == myQuartz){
    Tracks[tr]->QLength += StepL;  
    Tracks[tr]->QSteps++;  
  }
  if(Volume == myLightGuide){
    Tracks[tr]->LGLength += StepL;  
    Tracks[tr]->LGSteps++;
    Tracks[tr]->LGHitFlag = 1;
  }

  Tracks[tr]->Length += StepL;  
  
  Tracks[tr]->NSteps++;
  if(Tracks[tr]->QExitFlag == 0)
    Tracks[tr]->QExitFlag = QEFlag;
  
  if(Tracks[tr]->PMTHitFlag == 0)
    Tracks[tr]->PMTHitFlag = PMTHit;

  Tracks[tr]->StepLength.push_back(StepL);
  Tracks[tr]->StepAngle.push_back(Ang);
  Tracks[tr]->StepVolume.push_back(Volume);
  Tracks[tr]->StepDefProc.push_back(Proc);
  Tracks[tr]->StepEnergy.push_back(eng);
  Tracks[tr]->StepWavelength.push_back(wvl);
}

void MOLLEROptTrackingReadout::AddStepNCherenkovs(Int_t id, Int_t nsec)
{ 
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id){
      Tracks[n]->StepNChPhotons.push_back(nsec);
    }
}

void MOLLEROptTrackingReadout::IncrementEventCathodeDetection(Int_t id)
{
  //int ticker = 1;
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id){
      //Tracks[n]->Detected = 1;
      if(Tracks[n]->PMTHitZ/cm > 120 /*&& ticker == 1*/){
        R1_CathodeDetections++;
        Tracks[n]->R1_Detected = 1;
        //ticker++;
      }
      if(100 < Tracks[n]->PMTHitZ/cm && 120 > Tracks[n]->PMTHitZ/cm){
        R2_CathodeDetections++;
        Tracks[n]->R2_Detected = 1;
      }
      if(70 < Tracks[n]->PMTHitZ/cm && 90 > Tracks[n]->PMTHitZ/cm){
        R3_CathodeDetections++;
        Tracks[n]->R3_Detected = 1;
      }
      if(45 < Tracks[n]->PMTHitZ/cm && 70 > Tracks[n]->PMTHitZ/cm){
        R4_CathodeDetections++;
        Tracks[n]->R4_Detected = 1;
      }
      if(5 < Tracks[n]->PMTHitZ/cm && 15> Tracks[n]->PMTHitZ/cm){
        R5_CathodeDetections++;
        Tracks[n]->R5_Detected = 1;
      }
      if((15 < Tracks[n]->PMTHitZ/cm) && (35 > Tracks[n]->PMTHitZ/cm) && (Tracks[n]->PMTHitX/cm < 0)){
        R6_CathodeDetections++;
        Tracks[n]->R6_Detected = 1;
      }
      if((15 < Tracks[n]->PMTHitZ/cm) && (35 > Tracks[n]->PMTHitZ/cm) && (Tracks[n]->PMTHitX/cm > 0)){
        R7_CathodeDetections++;
        Tracks[n]->R7_Detected = 1;
      }
      if(Tracks[n]->PMTHitZ/cm < 5){
        R8_CathodeDetections++;
        Tracks[n]->R8_Detected = 1;
      }
    }
  
  //CathodeDetections++;
};


void MOLLEROptTrackingReadout::AddSecPhoton(Int_t id, Float_t ang, Float_t wvl)
{

  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;

  if(tr == -1) return;

  Tracks[tr]->SecPhotonAngle.push_back(ang);
  Tracks[tr]->SecPhotonWavelength.push_back(wvl);
}

void MOLLEROptTrackingReadout::SetPMTHitLocation(Int_t id, G4ThreeVector loc, Float_t angle)
{

  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;

  if(tr == -1) return;
  if(!Tracks[tr]->PMTHitFlag) Tracks[tr]->PMTHitFlag = 1;
  
  Tracks[tr]->PMTHitX = loc.x();
  Tracks[tr]->PMTHitY = loc.y();
  Tracks[tr]->PMTHitZ = loc.z();

  Tracks[tr]->PMTWinRefl = angle;

  
}

void MOLLEROptTrackingReadout::SetQuartzHitLocation(Int_t id, G4ThreeVector loc, G4String quartz)
{
  /*G4cout << "Setting Quartz Hit Location" << G4endl;*/
  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;
  //G4cout << "Track:" << tr << G4endl;
  //G4cout << loc.z() << G4endl;
  //G4cout << Tracks[tr]->ScintHitFlag << G4endl;
  if(tr == -1) return;
  if((Tracks[tr]->R1QuartzHitFlag == 0) & (quartz == "QuartzHitCollection")){ 
    Tracks[tr]->R1QuartzHitFlag = 1;
    Tracks[tr]->R1QuartzHitX = loc.x();
    Tracks[tr]->R1QuartzHitY = loc.y();
    Tracks[tr]->R1QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R2QuartzHitFlag == 0) & (quartz == "QuartzHitCollection2")){ 
    Tracks[tr]->R2QuartzHitFlag = 1;
    Tracks[tr]->R2QuartzHitX = loc.x();
    Tracks[tr]->R2QuartzHitY = loc.y();
    Tracks[tr]->R2QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R3QuartzHitFlag == 0) & (quartz == "QuartzHitCollection3")){ 
    Tracks[tr]->R3QuartzHitFlag = 1;
    Tracks[tr]->R3QuartzHitX = loc.x();
    Tracks[tr]->R3QuartzHitY = loc.y();
    Tracks[tr]->R3QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R4QuartzHitFlag == 0) & (quartz == "QuartzHitCollection4")){ 
    Tracks[tr]->R4QuartzHitFlag = 1;
    Tracks[tr]->R4QuartzHitX = loc.x();
    Tracks[tr]->R4QuartzHitY = loc.y();
    Tracks[tr]->R4QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R5QuartzHitFlag == 0) & (quartz == "QuartzHitCollection5")){ 
    Tracks[tr]->R5QuartzHitFlag = 1;
    Tracks[tr]->R5QuartzHitX = loc.x();
    Tracks[tr]->R5QuartzHitY = loc.y();
    Tracks[tr]->R5QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R6QuartzHitFlag == 0) & (quartz == "QuartzHitCollection6")){
    Tracks[tr]->R6QuartzHitFlag = 1;
    Tracks[tr]->R6QuartzHitX = loc.x();
    Tracks[tr]->R6QuartzHitY = loc.y();
    Tracks[tr]->R6QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R7QuartzHitFlag == 0) & (quartz == "QuartzHitCollection7")){
    Tracks[tr]->R7QuartzHitFlag = 1;
    Tracks[tr]->R7QuartzHitX = loc.x();
    Tracks[tr]->R7QuartzHitY = loc.y();
    Tracks[tr]->R7QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->R8QuartzHitFlag == 0) & (quartz == "QuartzHitCollection8")){ 
    Tracks[tr]->R8QuartzHitFlag = 1;
    Tracks[tr]->R8QuartzHitX = loc.x();
    Tracks[tr]->R8QuartzHitY = loc.y();
    Tracks[tr]->R8QuartzHitZ = loc.z();
  }
  if((Tracks[tr]->Scint1HitFlag == 0) & (quartz ==  "Scint1HitCollection")){ 
    Tracks[tr]->Scint1HitFlag = 1;
    Tracks[tr]->Scint1HitX = loc.x();
    Tracks[tr]->Scint1HitY = loc.y();
    Tracks[tr]->Scint1HitZ = loc.z();
  }
  if((Tracks[tr]->Scint2HitFlag == 0) & (quartz == "Scint2HitCollection")){ 
    Tracks[tr]->Scint2HitFlag = 1;
    Tracks[tr]->Scint2HitX = loc.x();
    Tracks[tr]->Scint2HitY = loc.y();
    Tracks[tr]->Scint2HitZ = loc.z();
  }
  if((Tracks[tr]->Scint3HitFlag == 0) & (quartz == "Scint3HitCollection")){ 
    Tracks[tr]->Scint3HitFlag = 1;
    Tracks[tr]->Scint3HitX = loc.x();
    Tracks[tr]->Scint3HitY = loc.y();
    Tracks[tr]->Scint3HitZ = loc.z();
  }
  if((Tracks[tr]->Scint4HitFlag == 0) & (quartz == "Scint4HitCollection")){ 
    Tracks[tr]->Scint4HitFlag = 1;
    Tracks[tr]->Scint4HitX = loc.x();
    Tracks[tr]->Scint4HitY = loc.y();
    Tracks[tr]->Scint4HitZ = loc.z();
  }
}


void MOLLEROptTrackingReadout::AddNewTrack(TrackData *track)
{

  Tracks.push_back(track);
  
  if(track->Particle == myPhoton)
    PhotonTracks++;
  if(track->Particle == myBeam)
    ElectronTracks++;

}

Bool_t MOLLEROptTrackingReadout::TrackExists(Int_t id)
{
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) return true;

  return false;
}

Int_t MOLLEROptTrackingReadout::GetStepInQuartz(Int_t TID)
{
  for(int n = 0; n < Tracks.size(); n++){
    if(Tracks[n]->ID == TID){
      return Tracks[n]->NSteps;
    }
  }
  return -1;
}

void MOLLEROptTrackingReadout::StoreQuartzOpticalPlots(TProfile* tr35, TProfile* tr70, TProfile* tr170, TProfile* refl, TH1D* Qeff)
{
  if(tr35 )  {Transm35     = (TProfile*)tr35->Clone(); }
  if(tr70 )  {Transm70     = (TProfile*)tr70->Clone(); }
  if(tr170)  {Transm170    = (TProfile*)tr170->Clone();}
  if(refl )  {Reflectivity = (TProfile*)refl->Clone(); }
  if(Qeff )  {QEfficiency  = (TH1D*)Qeff->Clone(); }
}

void MOLLEROptTrackingReadout::StoreGuideOpticalPlots(TH1D* rl30,TH1D* rl45,TH1D* rl60,TH1D* rl90)
{
  if(rl30)  {LGRefl30 = (TH1D*)rl30->Clone(); }
  if(rl45)  {LGRefl45 = (TH1D*)rl45->Clone(); }
  if(rl60)  {LGRefl60 = (TH1D*)rl60->Clone();}
  if(rl90)  {LGRefl90 = (TH1D*)rl90->Clone(); }
}

void MOLLEROptTrackingReadout::StoreCathodeOpticalPlots(TH1D* CIndR, TH1D* CIndI)
{
  if(CIndR)  {CathIndR = (TH1D*)CIndR->Clone();}
  if(CIndI)  {CathIndI = (TH1D*)CIndI->Clone();}
}


void MOLLEROptTrackingReadout:: SetRadiationDamageHistograms(TH2 *hst, TH2 *hst2, TH2 *hst3, TH2 *hst4)
{
  
  if(hst)  { DetectorRateGlobal             = (TH2D*)hst->Clone();   DetectorRateGlobal->SetDirectory(0);            }
  if(hst2) { DetectorRateGlobalRotated      = (TH2D*)hst2->Clone();  DetectorRateGlobalRotated->SetDirectory(0);     }
  if(hst3) { DetectorRateLocalRotated       = (TH2D*)hst3->Clone();  DetectorRateLocalRotated->SetDirectory(0);      }
  if(hst3) { DetectorRateLocalRotatedCoarse = (TH2D*)hst4->Clone();  DetectorRateLocalRotatedCoarse->SetDirectory(0);}

}

void MOLLEROptTrackingReadout::SetNewQAbsorptionProfile(TProfile* abs)
{
  QAbsProf.push_back(abs);
}

void MOLLEROptTrackingReadout::WriteAbsProfiles()
{
  
  if(DetectorRateGlobal           ) {  DetectorRateGlobal->Write();            }
  if(DetectorRateGlobalRotated    ) {  DetectorRateGlobalRotated->Write();     }
  if(DetectorRateLocalRotated     ) {  DetectorRateLocalRotated->Write();      }
  if(DetectorRateLocalRotatedCoarse) {  DetectorRateLocalRotatedCoarse->Write();}
  
  for(int n = 0; n < QAbsProf.size(); n++){
    if(QAbsProf[n]){ QAbsProf[n]->Write(); /*cout << "Writing QAbsProf: " << n+1 << endl;*/}
  }

  if(Transm35    )  {Transm35->Write(); }
  if(Transm70    )  {Transm70->Write(); }
  if(Transm170   )  {Transm170->Write();}
  if(Reflectivity)  {Reflectivity->Write();}
  if(QEfficiency )  {QEfficiency->Write();}

  if(LGRefl30){LGRefl30->Write();};
  if(LGRefl45){LGRefl45->Write();};
  if(LGRefl60){LGRefl60->Write();};
  if(LGRefl90){LGRefl90->Write();};
  
  if(CathIndR)  {CathIndR->Write();}
  if(CathIndI)  {CathIndI->Write();}

}

void MOLLEROptTrackingReadout::Initialize()
{
  
  for(int n = 0; n < Tracks.size(); n++){
    Tracks[n]->StepLength.clear();
    Tracks[n]->StepLength.resize(0);
    Tracks[n]->StepVolume.clear();
    Tracks[n]->StepVolume.resize(0);
    Tracks[n]->StepAngle.clear();
    Tracks[n]->StepAngle.resize(0);
    Tracks[n]->SecPhotonWavelength.clear();
    Tracks[n]->SecPhotonWavelength.resize(0);
    Tracks[n]->SecPhotonAngle.clear();
    Tracks[n]->SecPhotonAngle.resize(0);
    Tracks[n]->StepDefProc.clear();
    Tracks[n]->StepDefProc.resize(0);    
    Tracks[n]->StepEnergy.clear();
    Tracks[n]->StepEnergy.resize(0);    
    Tracks[n]->StepWavelength.clear();
    Tracks[n]->StepWavelength.resize(0);
    Tracks[n]->StepNChPhotons.clear();
    Tracks[n]->StepNChPhotons.resize(0);
    
    delete Tracks[n];
  }
  Tracks.clear();
  Tracks.resize(0);

  
  ElectronTracks = 0;
  PhotonTracks = 0;
  //CathodeDetections = 0;
  R1_CathodeDetections = 0;
  R2_CathodeDetections = 0;
  R3_CathodeDetections = 0;
  R4_CathodeDetections = 0;
  R5_CathodeDetections = 0;
  R6_CathodeDetections = 0;
  R7_CathodeDetections = 0;
  R8_CathodeDetections = 0;
}

 




 


