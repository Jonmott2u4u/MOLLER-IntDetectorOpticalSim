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

void MOLLEROptTrackingReadout::AddTrackData(Int_t id, Int_t type, Int_t StepL, Int_t EFlag, Int_t PMTHit, G4String name, Int_t Volume, Int_t Proc, Float_t eng, Float_t wvl, Float_t Ang)
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
  if(Volume == myScint){
    Tracks[tr]->SLength += StepL;  
    Tracks[tr]->SSteps++;
  }
  if(Volume == myPMT){
  
  }

  Tracks[tr]->Length += StepL;  
  
  Tracks[tr]->NSteps++;
  if(Tracks[tr]->QExitFlag == 0) Tracks[tr]->QExitFlag = EFlag;
  //if(Tracks[tr]->SExitFlag == 0) Tracks[tr]->SExitFlag = EFlag;

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
  for(int n = 0; n < Tracks.size(); n++)
    if(Tracks[n]->ID == id){
      if(Tracks[n]->RingPMTHitFlag == 1){
        Ring_CathodeDetections++;
        Tracks[n]->Ring_Detected = 1;
      }
    }
  /*if(R2_CathodeDetections == 1){
    G4cout << "New electron" << G4endl;
  }*/
  //G4cout << R2_CathodeDetections << G4endl;
};


void MOLLEROptTrackingReadout::AddSecPhoton(Int_t id, Float_t ang, Float_t wvl)
{

  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++) {
    if(Tracks[n]->ID == id) tr = n;
  }
  if(tr == -1) return;

  Tracks[tr]->SecPhotonAngle.push_back(ang);
  Tracks[tr]->SecPhotonWavelength.push_back(wvl);
}

void MOLLEROptTrackingReadout::SetPMTHitLocation(Int_t id, G4ThreeVector loc, G4String pmt, Float_t angle)
{

  Int_t tr = -1;

  for(int n = 0; n < Tracks.size(); n++) {
    if(Tracks[n]->ID == id) tr = n;
  }
  if(tr == -1) return;
  if(!Tracks[tr]->PMTHitFlag) Tracks[tr]->PMTHitFlag = 1;
  if((!Tracks[tr]->RingPMTHitFlag) & (pmt == "PMTHitCollection")) Tracks[tr]->RingPMTHitFlag = 1;
  
  Tracks[tr]->PMTHitX = loc.x();
  Tracks[tr]->PMTHitY = loc.y();
  Tracks[tr]->PMTHitZ = loc.z();

  Tracks[tr]->PMTWinRefl = angle; 
}

void MOLLEROptTrackingReadout::SetQuartzHitLocation(Int_t id, G4ThreeVector loc, G4String quartz)
{
  Int_t tr = -1;
  
  for(int n = 0; n < Tracks.size(); n++) if(Tracks[n]->ID == id) tr = n;
  if(tr == -1) return;

  //G4cout << quartz << G4endl;
  if((Tracks[tr]->RingQuartzHitFlag == 0) & (quartz == "QuartzHitCollection")){ 
    Tracks[tr]->RingQuartzHitFlag = 1;
    Tracks[tr]->RingQuartzHitX = loc.x();
    Tracks[tr]->RingQuartzHitY = loc.y();
    Tracks[tr]->RingQuartzHitZ = loc.z();
  }
}

void MOLLEROptTrackingReadout::SetScintHitLocation(Int_t id, G4ThreeVector loc, G4String scint)
{
  Int_t tr = -1;
  //G4cout << "Setting Scint Location" << G4endl;
  for(int n = 0; n < Tracks.size(); n++) if(Tracks[n]->ID == id) tr = n;
  if(tr == -1) return;

  //cout << scint << endl;
  if((Tracks[tr]->Scint1HitFlag == 0) & (scint ==  "ScintHitCollection1")){ 
    Tracks[tr]->Scint1HitFlag = 1;
    Tracks[tr]->Scint1HitX = loc.x();
    Tracks[tr]->Scint1HitY = loc.y();
    Tracks[tr]->Scint1HitZ = loc.z();
  }

  if((Tracks[tr]->Scint2HitFlag == 0) & (scint ==  "ScintHitCollection2")){ 
    Tracks[tr]->Scint2HitFlag = 1;
    Tracks[tr]->Scint2HitX = loc.x();
    Tracks[tr]->Scint2HitY = loc.y();
    Tracks[tr]->Scint2HitZ = loc.z();
  }

  if((Tracks[tr]->Scint3HitFlag == 0) & (scint ==  "ScintHitCollection3")){ 
    Tracks[tr]->Scint3HitFlag = 1;
    Tracks[tr]->Scint3HitX = loc.x();
    Tracks[tr]->Scint3HitY = loc.y();
    Tracks[tr]->Scint3HitZ = loc.z();
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

void MOLLEROptTrackingReadout::StoreGuideOpticalPlots(TH1D* rl30uvc,TH1D* rl45uvc,TH1D* rl60uvc,TH1D* rl90uvc,TH1D* rl30uvs,TH1D* rl45uvs,TH1D* rl60uvs,TH1D* rl90uvs)
{
  if(rl30uvc)  {LGRefl30UVC = (TH1D*)rl30uvc->Clone();}
  if(rl45uvc)  {LGRefl45UVC = (TH1D*)rl45uvc->Clone();}
  if(rl60uvc)  {LGRefl60UVC = (TH1D*)rl60uvc->Clone();}
  if(rl90uvc)  {LGRefl90UVC = (TH1D*)rl90uvc->Clone();}
  if(rl30uvs)  {LGRefl30UVS = (TH1D*)rl30uvs->Clone();}
  if(rl45uvs)  {LGRefl45UVS = (TH1D*)rl45uvs->Clone();}
  if(rl60uvs)  {LGRefl60UVS = (TH1D*)rl60uvs->Clone();}
  if(rl90uvs)  {LGRefl90UVS = (TH1D*)rl90uvs->Clone();}
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

  if(LGRefl30UVC){LGRefl30UVC->Write();};
  if(LGRefl45UVC){LGRefl45UVC->Write();};
  if(LGRefl60UVC){LGRefl60UVC->Write();};
  if(LGRefl90UVC){LGRefl90UVC->Write();};
  if(LGRefl30UVS){LGRefl30UVS->Write();};
  if(LGRefl45UVS){LGRefl45UVS->Write();};
  if(LGRefl60UVS){LGRefl60UVS->Write();};
  if(LGRefl90UVS){LGRefl90UVS->Write();};
  
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
  Ring_CathodeDetections = 0;
}