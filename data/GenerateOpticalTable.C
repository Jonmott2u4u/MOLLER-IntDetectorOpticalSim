#include "TProfile.h"
#include "TGraph.h"
#include "TMath.h"
#include "TFile.h"
#include "TCanvas.h"

double PhotonEnergy[58] = {1.55,1.58,1.61,1.64,1.67,1.70,1.73,1.76,1.79,1.82,1.85,
			   1.88, 1.91, 1.94, 1.97, 2.00, 2.03, 2.07, 2.10, 2.14, 2.18, 
			   2.21, 2.25, 2.30, 2.34, 2.38, 2.43, 2.48, 2.53, 2.58, 2.64, 
			   2.70, 2.76, 2.82, 2.88, 2.95, 3.02, 3.10, 3.18, 3.26, 3.35, 
			   3.44, 3.54, 3.65, 3.76, 3.87, 4.00, 4.13, 4.28, 4.43, 4.59, 
			   4.77, 4.96, 5.17, 5.39, 5.64, 5.90, 6.20};

//PMT profiles
TProfile *PMTQE = new TProfile("PMTQE","",100,1.38,6.21,0,1.0);
TProfile *QRefl = new TProfile("QRefl","",100,1.38,6.21,0,1.0);
TProfile *CathIndR = new TProfile("CathIndR","",100,1.38,6.21,0,4.0);
TProfile *CathIndI = new TProfile("CathIndI","",100,1.38,6.21,0,4.0);

//LG material reflectivity profiles
//------Mylar------//
TProfile *LG30MylarRefl = new TProfile("LG30MylarRefl","",100,1.38,6.21,0,1.0);
TProfile *LG45MylarRefl = new TProfile("LG45MylarRefl","",100,1.38,6.21,0,1.0);
TProfile *LG60MylarRefl = new TProfile("LG60MylarRefl","",100,1.38,6.21,0,1.0);
TProfile *LG90MylarRefl = new TProfile("LG90MylarRefl","",100,1.38,6.21,0,1.0);

TProfile *LG30MylarReflwv = new TProfile("LG30MylarReflwv","",750,150,900,0,1.0);
TProfile *LG45MylarReflwv = new TProfile("LG45MylarReflwv","",750,150,900,0,1.0);
TProfile *LG60MylarReflwv = new TProfile("LG60MylarReflwv","",750,150,900,0,1.0);
TProfile *LG90MylarReflwv = new TProfile("LG90MylarReflwv","",750,150,900,0,1.0);

//------MiroIV------//
TProfile *LG30MiroIVRefl = new TProfile("LG30MiroIVRefl","",100,1.38,6.21,0,1.0);
TProfile *LG45MiroIVRefl = new TProfile("LG45MiroIVRefl","",100,1.38,6.21,0,1.0);
TProfile *LG60MiroIVRefl = new TProfile("LG60MiroIVRefl","",100,1.38,6.21,0,1.0);
TProfile *LG90MiroIVRefl = new TProfile("LG90MiroIVRefl","",100,1.38,6.21,0,1.0);

TProfile *LG30MiroIVReflwv = new TProfile("LG30MiroIVReflwv","",750,150,900,0,1.0);
TProfile *LG45MiroIVReflwv = new TProfile("LG45MiroIVReflwv","",750,150,900,0,1.0);
TProfile *LG60MiroIVReflwv = new TProfile("LG60MiroIVReflwv","",750,150,900,0,1.0);
TProfile *LG90MiroIVReflwv = new TProfile("LG90MiroIVReflwv","",750,150,900,0,1.0);

//Quantum absorption profiles 
TProfile *QAbsorption  = new TProfile("QAbsorption","",60,1.38,6.21,0,250.0);
TProfile *QAbsorption70  = new TProfile("QAbsorption70","",60,1.38,6.21,0,250.0);
TProfile *QAbsorption170  = new TProfile("QAbsorption170","",60,1.38,6.21,0,250.0);

TGraph *PMTQEout = new TGraph(); 
TGraph *QReflout = new TGraph(); 
TGraph *LGR30Mylarout = new TGraph(); 
TGraph *LGR45Mylarout = new TGraph(); 
TGraph *LGR60Mylarout = new TGraph(); 
TGraph *LGR90Mylarout = new TGraph(); 
TGraph *LGR30MiroIVout = new TGraph(); 
TGraph *LGR45MiroIVout = new TGraph(); 
TGraph *LGR60MiroIVout = new TGraph(); 
TGraph *LGR90MiroIVout = new TGraph();
TGraph *Absout = new TGraph();   
TGraph *Abs70out = new TGraph(); 
TGraph *Abs170out = new TGraph();

  //*****************The parameters below correspond to polynomical coefficients that were
  //*****************extacted from a corresponding fit to the transmission data taken by Kathrin Imai at Mainz.
  //*****************One could just use the raw data, but it has wild fluctuations that are not physics, but rather
  //*****************that are introduced by technicalities of the measuement setup, and that could introduce 
  //*****************unrealistic results in the simulations.
  
  /*
    Abs length for no rad damage, vs wavelength:

     p0                        =      5.51192   +/-   31.3108     
     p1                        =    -0.927701   +/-   0.304146    
     p2                        =   0.00843522   +/-   0.0010346   
     p3                        = -1.63346e-05   +/-   1.47298e-06 
     p4                        =  9.42376e-09   +/-   7.47174e-10

     Abs length for 70MRad damage, vs wavelength:

     p0                        =     -4573.71   +/-   484.992     
     p1                        =      87.5729   +/-   8.59834     
     p2                        =    -0.679699   +/-   0.0629346   
     p3                        =   0.00276121   +/-   0.000246572 
     p4                        =   -6.337e-06   +/-   5.59084e-07 
     p5                        =  8.27786e-09   +/-   7.34974e-10 
     p6                        = -5.74483e-12   +/-   5.19849e-13 
     p7                        =  1.64533e-15   +/-   1.52978e-16
 
p0                        =     -8690.53   +/-   1147.42     
p1                        =      154.777   +/-   23.5441     
p2                        =     -1.10488   +/-   0.204527    
p3                        =   0.00403245   +/-   0.00098221  
p4                        = -7.87987e-06   +/-   2.85331e-06 
p5                        =  7.50861e-09   +/-   5.1399e-09  
p6                        = -1.48863e-12   +/-   5.61546e-12 
p7                        = -2.70735e-15   +/-   3.408e-15   
p8                        =  1.50621e-18   +/-   8.81312e-19

     Abs length for 170MRad damage, vs wavelength
     p0                        =      19533.9   +/-   3199.49     
     p1                        =     -503.678   +/-   73.5471     
     p2                        =      5.51869   +/-   0.730127    
     p3                        =   -0.0336632   +/-   0.00410804  
     p4                        =  0.000125901   +/-   1.44412e-05 
     p5                        = -2.99726e-07   +/-   3.29149e-08 
     p6                        =  4.55565e-10   +/-   4.86896e-11 
     p7                        = -4.27978e-13   +/-   4.51303e-14 
     p8                        =  2.26419e-16   +/-   2.38163e-17 
     p9                        = -5.15942e-20   +/-   5.45962e-21
  */

//The first AbsLPre is for the Tosoh fused quartz using absorption coefficient fits generated by Justin Gahley
//TF1 *AbsLPre = new TF1("AbsLPre","(5.51192 -0.927701*1242.0/x + 0.00843522*pow(1242.0/x,2) - 1.63346e-05*pow(1242.0/x,3) + 9.42376e-09*pow(1242.0/x,4))*(-.323221 + 3.156390e-03*1242.0/x - 9.479939e-06*pow(1242.0/x,2) + 1.205580e-08*pow(1242.0/x,3) - 5.547618e-12*pow(1242.0/x,4))/(.6164423*exp(-pow((1242.0/x)-210.7322,2)/(2*pow(9.025008,2))) + .2673906*exp(-pow((1242.0/x)-242.1276,2)/(2*pow(9.303257,2))) - 9.347873e-05*1242.0/x + .1079881)",0,900);
//The second AbsLPre is for the Heraeus fused silica
TF1 *AbsLPre = new TF1("AbsLPre","5.51192 -0.927701*1242.0/x + 0.00843522*pow(1242.0/x,2) - 1.63346e-05*pow(1242.0/x,3) + 9.42376e-09*pow(1242.0/x,4)",0,900);
TF1 *AbsL70  = new TF1("AbsL70","-4573.71 + 87.5729*1242.0/x - 0.679699*pow(1242.0/x,2) + 0.00276121*pow(1242.0/x,3) - 6.337e-06*pow(1242.0/x,4) + 8.27786e-09*pow(1242.0/x,5) - 5.74483e-12*pow(1242.0/x,6) + 1.64533e-15*pow(1242.0/x,7)",0,900);
// TF1 *AbsL170 = new TF1("AbsL170","19533.9 - 503.678*1242.0/x + 5.51869*pow(1242.0/x,2) - 0.0336632*pow(1242.0/x,3) + 0.000125901*pow(1242.0/x,4) - 2.99726e-07*pow(1242.0/x,5) + 4.55565e-10*pow(1242.0/x,6) - 4.27978e-13*pow(1242.0/x,7) + 2.26419e-16*pow(1242.0/x,8) - 5.15942e-20*pow(1242.0/x,9)",0,900);
TF1 *AbsL170 = new TF1("AbsL170","-8690.53 + 154.777*1242.0/x - 1.10488*pow(1242.0/x,2) + 0.00403245*pow(1242.0/x,3) - 7.87987e-06*pow(1242.0/x,4) + 7.50861e-09*pow(1242.0/x,5) - 1.48863e-12*pow(1242.0/x,6) - 2.70735e-15*pow(1242.0/x,7) + 1.50621e-18*pow(1242.0/x,8)",0,900);



void FillQAbs()
{


  //From the Mainz Radiation Tests
  
  ifstream iFile1("Absorption.txt");
  ifstream iFile2("Absorption70MRad.txt");
  ifstream iFile3("Absorption170MRad.txt");


  Float_t x,y;
  Int_t n = 0, bin;

  double wvl, eng;
  
  while(!iFile1.eof()){

    iFile1 >> x >> y;
    wvl = x;
    eng = 1242.0/wvl;
    QAbsorption->Fill(eng,y,1);

  }

  iFile1.close();

  while(!iFile2.eof()){
    
    iFile2 >> x >> y;
    wvl = x;
    eng = 1242.0/wvl;
    QAbsorption70->Fill(eng,y,1);
    
  }

  iFile2.close();

  while(!iFile3.eof()){
    
    iFile3 >> x >> y;
    
    wvl = x;

    eng = 1242.0/wvl;
    QAbsorption170->Fill(eng,y,1);

  }

  iFile3.close();

}

void FillGuideReflectivity()
{

  //From the Idaho reflectivity measurements
  //These files were generated from the original Idaho data
  //files with the script "mat_analysis.C"
  /*ifstream iFile("bogdanMylar_30.txt");
  ifstream iFile2("bogdanMylar_45.txt");
  ifstream iFile3("bogdanMylar_60.txt");
  ifstream iFile4("bogdanMylar.txt");*/
  //Mylar files
  ifstream iFile("bogdanMylar_30.txt");
  ifstream iFile2("bogdanMylar_45.txt");
  ifstream iFile3("bogdanMylar_60.txt");
  ifstream iFile4("bogdanMylar.txt");
  ///MiroIV files
  ifstream iFile5("miroIV_30.txt");
  ifstream iFile6("miroIV_45.txt");
  ifstream iFile7("miroIV_60.txt");
  ifstream iFile8("miroIV_90.txt");

  Float_t x,y,e;
  Int_t n = 0, bin;
  double wvl, eng, scale;
  
  while(!iFile.eof()){
    iFile >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG30MylarRefl->Fill(eng,scale*y,1);
    LG30MylarReflwv->Fill(x,scale*y,1);
  }
  iFile.close();

  while(!iFile2.eof()){
    iFile2 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG45MylarRefl->Fill(eng,scale*y,1);
    LG45MylarReflwv->Fill(x,scale*y,1);
  }
  iFile2.close();

  while(!iFile3.eof()){
    iFile3 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG60MylarRefl->Fill(eng,scale*y,1);
    LG60MylarReflwv->Fill(x,scale*y,1);
  }
  iFile3.close();

  while(!iFile4.eof()){
    iFile4 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG90MylarRefl->Fill(eng,scale*y,1);
    LG90MylarReflwv->Fill(x,scale*y,1);
  }
  iFile4.close();

  while(!iFile5.eof()){
    iFile5 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG30MiroIVRefl->Fill(eng,scale*y,1);
    LG30MiroIVReflwv->Fill(x,scale*y,1);
  }
  iFile5.close();

  while(!iFile6.eof()){
    iFile6 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG45MiroIVRefl->Fill(eng,scale*y,1);
    LG45MiroIVReflwv->Fill(x,scale*y,1);
  }
  iFile6.close();

  while(!iFile7.eof()){
    iFile7 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG60MiroIVRefl->Fill(eng,scale*y,1);
    LG60MiroIVReflwv->Fill(x,scale*y,1);
  }
  iFile7.close();

  while(!iFile8.eof()){
    iFile8 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG90MiroIVRefl->Fill(eng,scale*y,1);
    LG90MiroIVReflwv->Fill(x,scale*y,1);
  }
  iFile8.close();
}


void FillPMTQE()
{

  ifstream iFile("PMTQuartzQE.txt");

  Float_t x,y,r,g,b;
  Int_t n = 0, bin;

  double reflval[58];
  double wvlval[58];

 
  double wvl, eng;
  

  while(!iFile.eof()){

    iFile >> x >> y >> r >> g >> b;

    wvl = 100+(x-1)*800/1006;

    eng = 1242.0/wvl;

    if(r < 200 && g < 200 && b < 200){

      PMTQE->Fill(eng,y*0.3/697.0,1);

    }
    
  }

  iFile.close();

}

void FillQRefl()
{

  ifstream iFile("FusedSilicaReflectance.txt");

  Float_t x,y;
  Int_t n = 0, bin;
 
  double wvl, eng;
  

  while(!iFile.eof()){

    iFile >> x >> y;

    wvl = x;

    eng = 1242.0/wvl;

    QRefl->Fill(eng,y/100,1);
    
  }

  iFile.close();

  double val = 0;
  double lbin = 0;
  for(int n = 100; n >= 1; n--){

    val = QRefl->GetBinContent(n-1);
    
    if(!val){
      val = QRefl->GetBinContent(n)*0.999;
      QRefl->SetBinContent(n-1,val);
      QRefl->SetBinEntries(n-1,1);      
    }
  }

}

void FillCathodeIndexOfRefraction()
{

  ifstream iFileR("BialkaliCathodeRefrInd_Real.txt");
  ifstream iFileI("BialkaliCathodeRefrInd_Imaginary.txt");

  Float_t x,y;
  Int_t n = 0, bin;
 
  double wvl, eng;
  

  while(!iFileR.eof()){

    iFileR >> x >> y;

    wvl = x;

    eng = 1242.0/wvl;

    CathIndR->Fill(eng,y,1);
    
  }

  iFileR.close();

  while(!iFileI.eof()){

    iFileI >> x >> y;

    wvl = x;

    eng = 1242.0/wvl;

    CathIndI->Fill(eng,y,1);
    
  }

  iFileI.close();

}


void MakeTable()
{
  PMTQEout->SetName("PMTQEout"); 
  QReflout->SetName("QReflout");  
  LGR30Mylarout->SetName("LGR30Mylarout");  
  LGR45Mylarout->SetName("LGR45Mylarout");  
  LGR60Mylarout->SetName("LGR60Mylarout");  
  LGR90Mylarout->SetName("LGR90Mylarout"); 
  LGR30MiroIVout->SetName("LGR30MiroIVout");  
  LGR45MiroIVout->SetName("LGR45MiroIVout");  
  LGR60MiroIVout->SetName("LGR60MiroIVout");  
  LGR90MiroIVout->SetName("LGR90MiroIVout"); 
  Absout->SetName("Absout");    
  Abs70out->SetName("Abs70out");  
  Abs170out->SetName("Abs170out");

  TCanvas *c1 = new TCanvas("","",600,400);
  c1->cd();
  FillGuideReflectivity();
  LG90MylarRefl->Draw();
  LG60MylarRefl->Draw("same");
  LG45MylarRefl->Draw("same");
  LG30MylarRefl->Draw("same");

  TCanvas *c2 = new TCanvas("","",600,400);
  c2->cd();
  LG90MiroIVRefl->Draw();
  LG60MiroIVRefl->Draw("same");
  LG45MiroIVRefl->Draw("same");
  LG30MiroIVRefl->Draw("same");

  FillPMTQE();
  PMTQE->Draw("same");

  FillQRefl();
  QRefl->Draw("same");
  
  FillQAbs();
  
  TCanvas *c3 = new TCanvas("","",600,400);
  c3->cd();
  LG90MylarReflwv->Draw();
  LG60MylarReflwv->Draw("same");
  LG45MylarReflwv->Draw("same");
  LG30MylarReflwv->Draw("same");

  TCanvas *c4 = new TCanvas("","",600,400);
  c4->cd();
  LG90MiroIVReflwv->Draw();
  LG60MiroIVReflwv->Draw("same");
  LG45MiroIVReflwv->Draw("same");
  LG30MiroIVReflwv->Draw("same");

  TCanvas *c5 = new TCanvas("","",600,400);
  c5->cd();
  QAbsorption->Draw();
  QAbsorption70->Draw("same");
  QAbsorption170->Draw("same");  

  FillCathodeIndexOfRefraction();
  TCanvas *c6 = new TCanvas("","",600,400);
  c6->cd();
  CathIndR->Draw();
  CathIndI->Draw("same");
  
  ofstream oFile("OpticalPropertiesInputData.txt");

  oFile << "E_ph " << "QE " << "QRefl " << "LGRefl30_Mylar " << "LGRefl45_Mylar " << "LGRefl60_Mylar " << "LGRefl90_Mylar " << "LGRefl30_MiroIV " << "LGRefl45_MiroIV " << "LGRefl60_MiroIV " << "LGRefl90_MiroIV " << "QAbs " << "QAbs(70 MRad) " <<  "QAbs(170 MRad) " << "CathIndR " << "CathIndI " << '\n';

  for(int n = 0; n < 58; n++){


    PMTQEout->SetPoint(n,PhotonEnergy[n],PMTQE->GetBinContent(PMTQE->FindBin(PhotonEnergy[n])));
    QReflout->SetPoint(n,PhotonEnergy[n],QRefl->GetBinContent(QRefl->FindBin(PhotonEnergy[n])));
    //Mylar reflectivity
    LGR30Mylarout->SetPoint(n,PhotonEnergy[n],LG30MylarRefl->GetBinContent(LG30MylarRefl->FindBin(PhotonEnergy[n])));
    LGR45Mylarout->SetPoint(n,PhotonEnergy[n],LG45MylarRefl->GetBinContent(LG45MylarRefl->FindBin(PhotonEnergy[n])));
    LGR60Mylarout->SetPoint(n,PhotonEnergy[n],LG60MylarRefl->GetBinContent(LG60MylarRefl->FindBin(PhotonEnergy[n])));
    LGR90Mylarout->SetPoint(n,PhotonEnergy[n],LG90MylarRefl->GetBinContent(LG90MylarRefl->FindBin(PhotonEnergy[n])));
    //MiroIV reflectivity
    LGR30MiroIVout->SetPoint(n,PhotonEnergy[n],LG30MiroIVRefl->GetBinContent(LG30MiroIVRefl->FindBin(PhotonEnergy[n])));
    LGR45MiroIVout->SetPoint(n,PhotonEnergy[n],LG45MiroIVRefl->GetBinContent(LG45MiroIVRefl->FindBin(PhotonEnergy[n])));
    LGR60MiroIVout->SetPoint(n,PhotonEnergy[n],LG60MiroIVRefl->GetBinContent(LG60MiroIVRefl->FindBin(PhotonEnergy[n])));
    LGR90MiroIVout->SetPoint(n,PhotonEnergy[n],LG90MiroIVRefl->GetBinContent(LG90MiroIVRefl->FindBin(PhotonEnergy[n])));
    Absout->SetPoint(n,PhotonEnergy[n],QAbsorption->GetBinContent(QAbsorption->FindBin(PhotonEnergy[n])));
    Abs70out->SetPoint(n,PhotonEnergy[n],QAbsorption70->GetBinContent(QAbsorption70->FindBin(PhotonEnergy[n])));
    Abs170out->SetPoint(n,PhotonEnergy[n],QAbsorption170->GetBinContent(QAbsorption170->FindBin(PhotonEnergy[n])));


    oFile << PhotonEnergy[n] << ' '
	  << PMTQE->GetBinContent(PMTQE->FindBin(PhotonEnergy[n])) << ' '
	  << QRefl->GetBinContent(QRefl->FindBin(PhotonEnergy[n])) << ' '
    //Mylar reflectivity
	  << LG30MylarRefl->GetBinContent(LG30MylarRefl->FindBin(PhotonEnergy[n])) << ' '    
    << LG45MylarRefl->GetBinContent(LG45MylarRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG60MylarRefl->GetBinContent(LG60MylarRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG90MylarRefl->GetBinContent(LG90MylarRefl->FindBin(PhotonEnergy[n])) << ' '   
    ///MiroIV reflectivity  
    << LG30MiroIVRefl->GetBinContent(LG30MiroIVRefl->FindBin(PhotonEnergy[n])) << ' '    
    << LG45MiroIVRefl->GetBinContent(LG45MiroIVRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG60MiroIVRefl->GetBinContent(LG60MiroIVRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG90MiroIVRefl->GetBinContent(LG90MiroIVRefl->FindBin(PhotonEnergy[n])) << ' '     
	  // << QAbsorption->GetBinContent(QAbsorption->FindBin(PhotonEnergy[n])) << ' '     
	  << AbsLPre->Eval(PhotonEnergy[n]) << ' '
	  << QAbsorption70->GetBinContent(QAbsorption70->FindBin(PhotonEnergy[n])) << ' ' 
    << QAbsorption170->GetBinContent(QAbsorption170->FindBin(PhotonEnergy[n]))  << ' '
	  << CathIndR->GetBinContent(CathIndR->FindBin(PhotonEnergy[n])) << ' '
	  << CathIndI->GetBinContent(CathIndI->FindBin(PhotonEnergy[n])) << '\n';
  }
  oFile.close();

  TCanvas *c7 = new TCanvas("","",600,400);
  c7->cd();
  PMTQEout->Draw("ap");

  TCanvas *c8 = new TCanvas("","",600,400);
  c8->cd();
  QReflout->Draw("ap");

  TCanvas *c9 = new TCanvas("","",600,400);
  c9->cd();
  LGR30Mylarout->Draw("ap");
  LGR45Mylarout->Draw("samep");
  LGR60Mylarout->Draw("samep");
  LGR90Mylarout->Draw("AP");

  TCanvas *c10 = new TCanvas("","",600,400);
  c10->cd();
  LGR30MiroIVout->Draw("ap");
  LGR45MiroIVout->Draw("samep");
  LGR60MiroIVout->Draw("samep");
  LGR90MiroIVout->Draw("AP");

  TCanvas *c11 = new TCanvas("","",600,400);
  c11->cd();
  Absout->Draw("ap");
  Abs70out->Draw("samep");
  Abs170out->Draw("samep");  
  AbsLPre->Draw("lsame");
  AbsL70->Draw("lsame");
  AbsL170->Draw("lsame");

}

