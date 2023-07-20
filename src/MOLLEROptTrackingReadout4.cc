#include "MOLLEROptTrackingReadout4.hh"

MOLLEROptTrackingReadout4::MOLLEROptTrackingReadout4()
{
  Initialize();
  QAbsProf.clear();
  QAbsProf.resize(0);
}

MOLLEROptTrackingReadout4::~MOLLEROptTrackingReadout4()
{
  
}

void MOLLEROptTrackingReadout4::AddTrackData(Int_t id, Int_t type, Int_t StepL, Int_t QEFlag, Int_t PMTHit, Int_t Volume, Int_t Proc, Float_t eng, Float_t wvl, Float_t Ang)
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

void MOLLEROptTrackingReadout4::AddStepNCherenkovs(Int_t id, Int_t nsec)
{ 
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id){
      Tracks[n]->StepNChPhotons.push_back(nsec);
    }
}

void MOLLEROptTrackingReadout4::IncrementEventCathodeDetection(Int_t id)
{

  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id){
      Tracks[n]->Detected = 1;
    }
  
  CathodeDetections++;
};


void MOLLEROptTrackingReadout4::AddSecPhoton(Int_t id, Float_t ang, Float_t wvl)
{

  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;

  if(tr == -1) return;

  Tracks[tr]->SecPhotonAngle.push_back(ang);
  Tracks[tr]->SecPhotonWavelength.push_back(wvl);
}

void MOLLEROptTrackingReadout4::SetPMTHitLocation(Int_t id, G4ThreeVector loc, Float_t angle)
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

void MOLLEROptTrackingReadout4::SetQuartzHitLocation(Int_t id, G4ThreeVector loc)
{

  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) tr = n;

  if(tr == -1) return;
  if(!Tracks[tr]->QuartzHitFlag) Tracks[tr]->QuartzHitFlag = 1;
  
  Tracks[tr]->QuartzHitX = loc.x();
  Tracks[tr]->QuartzHitY = loc.y();
  Tracks[tr]->QuartzHitZ = loc.z();

}


void MOLLEROptTrackingReadout4::AddNewTrack(TrackData4 *track)
{

  Tracks.push_back(track);
  
  if(track->Particle == myPhoton)
    PhotonTracks++;
  if(track->Particle == myElectron)
    ElectronTracks++;

}

Bool_t MOLLEROptTrackingReadout4::TrackExists(Int_t id)
{
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id) return true;

  return false;
}

Int_t MOLLEROptTrackingReadout4::GetStepInQuartz(Int_t TID)
{
  for(int n = 0; n < Tracks.size(); n++){
    if(Tracks[n]->ID == TID){
      return Tracks[n]->NSteps;
    }
  }
  return -1;
}

void MOLLEROptTrackingReadout4::StoreQuartzOpticalPlots(TProfile* tr35, TProfile* tr70, TProfile* tr170, TProfile* refl, TH1D* Qeff)
{
  if(tr35 )  {Transm35     = (TProfile*)tr35->Clone(); }
  if(tr70 )  {Transm70     = (TProfile*)tr70->Clone(); }
  if(tr170)  {Transm170    = (TProfile*)tr170->Clone();}
  if(refl )  {Reflectivity = (TProfile*)refl->Clone(); }
  if(Qeff )  {QEfficiency  = (TH1D*)Qeff->Clone(); }
}

void MOLLEROptTrackingReadout4::StoreGuideOpticalPlots(TH1D* rl30,TH1D* rl45,TH1D* rl60,TH1D* rl90)
{
  if(rl30)  {LGRefl30 = (TH1D*)rl30->Clone(); }
  if(rl45)  {LGRefl45 = (TH1D*)rl45->Clone(); }
  if(rl60)  {LGRefl60 = (TH1D*)rl60->Clone();}
  if(rl90)  {LGRefl90 = (TH1D*)rl90->Clone(); }
}

void MOLLEROptTrackingReadout4::StoreCathodeOpticalPlots(TH1D* CIndR, TH1D* CIndI)
{
  if(CIndR)  {CathIndR = (TH1D*)CIndR->Clone();}
  if(CIndI)  {CathIndI = (TH1D*)CIndI->Clone();}
}


void MOLLEROptTrackingReadout4:: SetRadiationDamageHistograms(TH2 *hst, TH2 *hst2, TH2 *hst3, TH2 *hst4)
{
  
  if(hst)  { DetectorRateGlobal             = (TH2D*)hst->Clone();   DetectorRateGlobal->SetDirectory(0);            }
  if(hst2) { DetectorRateGlobalRotated      = (TH2D*)hst2->Clone();  DetectorRateGlobalRotated->SetDirectory(0);     }
  if(hst3) { DetectorRateLocalRotated       = (TH2D*)hst3->Clone();  DetectorRateLocalRotated->SetDirectory(0);      }
  if(hst3) { DetectorRateLocalRotatedCoarse = (TH2D*)hst4->Clone();  DetectorRateLocalRotatedCoarse->SetDirectory(0);}

}

void MOLLEROptTrackingReadout4::SetNewQAbsorptionProfile(TProfile* abs)
{
  QAbsProf.push_back(abs);
}

void MOLLEROptTrackingReadout4::WriteAbsProfiles()
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

void MOLLEROptTrackingReadout4::Initialize()
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
  CathodeDetections = 0;
}

 




 


