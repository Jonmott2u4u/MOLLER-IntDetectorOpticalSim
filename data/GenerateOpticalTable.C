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
//------UVC------//
TProfile *LG30UVCRefl = new TProfile("LG30UVCRefl","",100,1.38,6.21,0,1.0);
TProfile *LG45UVCRefl = new TProfile("LG45UVCRefl","",100,1.38,6.21,0,1.0);
TProfile *LG60UVCRefl = new TProfile("LG60UVCRefl","",100,1.38,6.21,0,1.0);
TProfile *LG90UVCRefl = new TProfile("LG90UVCRefl","",100,1.38,6.21,0,1.0);

TProfile *LG30UVCReflwv = new TProfile("LG30UVCReflwv","",750,150,900,0,1.0);
TProfile *LG45UVCReflwv = new TProfile("LG45UVCReflwv","",750,150,900,0,1.0);
TProfile *LG60UVCReflwv = new TProfile("LG60UVCReflwv","",750,150,900,0,1.0);
TProfile *LG90UVCReflwv = new TProfile("LG90UVCReflwv","",750,150,900,0,1.0);

//------UVS------//
TProfile *LG30UVSRefl = new TProfile("LG30UVSRefl","",100,1.38,6.21,0,1.0);
TProfile *LG45UVSRefl = new TProfile("LG45UVSRefl","",100,1.38,6.21,0,1.0);
TProfile *LG60UVSRefl = new TProfile("LG60UVSRefl","",100,1.38,6.21,0,1.0);
TProfile *LG90UVSRefl = new TProfile("LG90UVSRefl","",100,1.38,6.21,0,1.0);

TProfile *LG30UVSReflwv = new TProfile("LG30UVSReflwv","",750,150,900,0,1.0);
TProfile *LG45UVSReflwv = new TProfile("LG45UVSReflwv","",750,150,900,0,1.0);
TProfile *LG60UVSReflwv = new TProfile("LG60UVSReflwv","",750,150,900,0,1.0);
TProfile *LG90UVSReflwv = new TProfile("LG90UVSReflwv","",750,150,900,0,1.0);

//Quantum absorption profiles 
TProfile *QAbsorption  = new TProfile("QAbsorption","",60,1.38,6.21,0,250.0);
TProfile *QAbsorption70  = new TProfile("QAbsorption70","",60,1.38,6.21,0,250.0);
TProfile *QAbsorption170  = new TProfile("QAbsorption170","",60,1.38,6.21,0,250.0);

TGraph *PMTQEout = new TGraph(); 
TGraph *QReflout = new TGraph(); 
TGraph *LGR30UVCout = new TGraph(); 
TGraph *LGR45UVCout = new TGraph(); 
TGraph *LGR60UVCout = new TGraph(); 
TGraph *LGR90UVCout = new TGraph(); 
TGraph *LGR30UVSout = new TGraph(); 
TGraph *LGR45UVSout = new TGraph(); 
TGraph *LGR60UVSout = new TGraph(); 
TGraph *LGR90UVSout = new TGraph();
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
  //UVC files
  ifstream iFile("filtered_UVC32deg.txt");
  ifstream iFile2("filtered_UVC45deg.txt");
  ifstream iFile3("filtered_UVC62deg.txt");
  ifstream iFile4("filtered_UVC90deg.txt");
  ///UVS files
  ifstream iFile5("uvs30.txt");
  ifstream iFile6("uvs45.txt");
  ifstream iFile7("uvs60.txt");
  ifstream iFile8("uvs.txt");

  Float_t x,y,e;
  Int_t n = 0, bin;
  double wvl, eng, scale;
  
  while(!iFile.eof()){
    iFile >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG30UVCRefl->Fill(eng,scale*y,1);
    LG30UVCReflwv->Fill(x,scale*y,1);
  }
  iFile.close();

  while(!iFile2.eof()){
    iFile2 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG45UVCRefl->Fill(eng,scale*y,1);
    LG45UVCReflwv->Fill(x,scale*y,1);
  }
  iFile2.close();

  while(!iFile3.eof()){
    iFile3 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG60UVCRefl->Fill(eng,scale*y,1);
    LG60UVCReflwv->Fill(x,scale*y,1);
  }
  iFile3.close();

  while(!iFile4.eof()){
    iFile4 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG90UVCRefl->Fill(eng,scale*y,1);
    LG90UVCReflwv->Fill(x,scale*y,1);
  }
  iFile4.close();

  while(!iFile5.eof()){
    iFile5 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG30UVSRefl->Fill(eng,scale*y,1);
    LG30UVSReflwv->Fill(x,scale*y,1);
  }
  iFile5.close();

  while(!iFile6.eof()){
    iFile6 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG45UVSRefl->Fill(eng,scale*y,1);
    LG45UVSReflwv->Fill(x,scale*y,1);
  }
  iFile6.close();

  while(!iFile7.eof()){
    iFile7 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG60UVSRefl->Fill(eng,scale*y,1);
    LG60UVSReflwv->Fill(x,scale*y,1);
  }
  iFile7.close();

  while(!iFile8.eof()){
    iFile8 >> x >> y >> e;
    wvl = x;
    eng = 1242.0/wvl;
    //scale = 0.95;
    scale = 1.;
    LG90UVSRefl->Fill(eng,scale*y,1);
    LG90UVSReflwv->Fill(x,scale*y,1);
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
  LGR30UVCout->SetName("LGR30UVCout");  
  LGR45UVCout->SetName("LGR45UVCout");  
  LGR60UVCout->SetName("LGR60UVCout");  
  LGR90UVCout->SetName("LGR90UVCout"); 
  LGR30UVSout->SetName("LGR30UVSout");  
  LGR45UVSout->SetName("LGR45UVSout");  
  LGR60UVSout->SetName("LGR60UVSout");  
  LGR90UVSout->SetName("LGR90UVSout"); 
  Absout->SetName("Absout");    
  Abs70out->SetName("Abs70out");  
  Abs170out->SetName("Abs170out");

  TCanvas *c1 = new TCanvas("","",600,400);
  c1->cd();
  FillGuideReflectivity();
  LG90UVCRefl->Draw();
  LG60UVCRefl->Draw("same");
  LG45UVCRefl->Draw("same");
  LG30UVCRefl->Draw("same");

  TCanvas *c2 = new TCanvas("","",600,400);
  c2->cd();
  LG90UVSRefl->Draw();
  LG60UVSRefl->Draw("same");
  LG45UVSRefl->Draw("same");
  LG30UVSRefl->Draw("same");

  FillPMTQE();
  PMTQE->Draw("same");

  FillQRefl();
  QRefl->Draw("same");
  
  FillQAbs();
  
  TCanvas *c3 = new TCanvas("","",600,400);
  c3->cd();
  LG90UVCReflwv->Draw();
  LG60UVCReflwv->Draw("same");
  LG45UVCReflwv->Draw("same");
  LG30UVCReflwv->Draw("same");

  TCanvas *c4 = new TCanvas("","",600,400);
  c4->cd();
  LG90UVSReflwv->Draw();
  LG60UVSReflwv->Draw("same");
  LG45UVSReflwv->Draw("same");
  LG30UVSReflwv->Draw("same");

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

  oFile << "E_ph " << "QE " << "QRefl " << "LGRefl30_UVC " << "LGRefl45_UVC " << "LGRefl60_UVC " << "LGRefl90_UVC " << "LGRefl30_UVS " << "LGRefl45_UVS " << "LGRefl60_UVS " << "LGRefl90_UVS " << "QAbs " << "QAbs(70 MRad) " <<  "QAbs(170 MRad) " << "CathIndR " << "CathIndI " << '\n';

  for(int n = 0; n < 58; n++){


    PMTQEout->SetPoint(n,PhotonEnergy[n],PMTQE->GetBinContent(PMTQE->FindBin(PhotonEnergy[n])));
    QReflout->SetPoint(n,PhotonEnergy[n],QRefl->GetBinContent(QRefl->FindBin(PhotonEnergy[n])));
    //UVC reflectivity
    LGR30UVCout->SetPoint(n,PhotonEnergy[n],LG30UVCRefl->GetBinContent(LG30UVCRefl->FindBin(PhotonEnergy[n])));
    LGR45UVCout->SetPoint(n,PhotonEnergy[n],LG45UVCRefl->GetBinContent(LG45UVCRefl->FindBin(PhotonEnergy[n])));
    LGR60UVCout->SetPoint(n,PhotonEnergy[n],LG60UVCRefl->GetBinContent(LG60UVCRefl->FindBin(PhotonEnergy[n])));
    LGR90UVCout->SetPoint(n,PhotonEnergy[n],LG90UVCRefl->GetBinContent(LG90UVCRefl->FindBin(PhotonEnergy[n])));
    //UVS reflectivity
    LGR30UVSout->SetPoint(n,PhotonEnergy[n],LG30UVSRefl->GetBinContent(LG30UVSRefl->FindBin(PhotonEnergy[n])));
    LGR45UVSout->SetPoint(n,PhotonEnergy[n],LG45UVSRefl->GetBinContent(LG45UVSRefl->FindBin(PhotonEnergy[n])));
    LGR60UVSout->SetPoint(n,PhotonEnergy[n],LG60UVSRefl->GetBinContent(LG60UVSRefl->FindBin(PhotonEnergy[n])));
    LGR90UVSout->SetPoint(n,PhotonEnergy[n],LG90UVSRefl->GetBinContent(LG90UVSRefl->FindBin(PhotonEnergy[n])));
    Absout->SetPoint(n,PhotonEnergy[n],QAbsorption->GetBinContent(QAbsorption->FindBin(PhotonEnergy[n])));
    Abs70out->SetPoint(n,PhotonEnergy[n],QAbsorption70->GetBinContent(QAbsorption70->FindBin(PhotonEnergy[n])));
    Abs170out->SetPoint(n,PhotonEnergy[n],QAbsorption170->GetBinContent(QAbsorption170->FindBin(PhotonEnergy[n])));


    oFile << PhotonEnergy[n] << ' '
	  << PMTQE->GetBinContent(PMTQE->FindBin(PhotonEnergy[n])) << ' '
	  << QRefl->GetBinContent(QRefl->FindBin(PhotonEnergy[n])) << ' '
    //UVC reflectivity
	  << LG30UVCRefl->GetBinContent(LG30UVCRefl->FindBin(PhotonEnergy[n])) << ' '    
    << LG45UVCRefl->GetBinContent(LG45UVCRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG60UVCRefl->GetBinContent(LG60UVCRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG90UVCRefl->GetBinContent(LG90UVCRefl->FindBin(PhotonEnergy[n])) << ' '   
    ///UVS reflectivity  
    << LG30UVSRefl->GetBinContent(LG30UVSRefl->FindBin(PhotonEnergy[n])) << ' '    
    << LG45UVSRefl->GetBinContent(LG45UVSRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG60UVSRefl->GetBinContent(LG60UVSRefl->FindBin(PhotonEnergy[n])) << ' '     
	  << LG90UVSRefl->GetBinContent(LG90UVSRefl->FindBin(PhotonEnergy[n])) << ' '     
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
  LGR30UVCout->Draw("ap");
  LGR45UVCout->Draw("samep");
  LGR60UVCout->Draw("samep");
  LGR90UVCout->Draw("AP");

  TCanvas *c10 = new TCanvas("","",600,400);
  c10->cd();
  LGR30UVSout->Draw("ap");
  LGR45UVSout->Draw("samep");
  LGR60UVSout->Draw("samep");
  LGR90UVSout->Draw("AP");

  TCanvas *c11 = new TCanvas("","",600,400);
  c11->cd();
  Absout->Draw("ap");
  Abs70out->Draw("samep");
  Abs170out->Draw("samep");  
  AbsLPre->Draw("lsame");
  AbsL70->Draw("lsame");
  AbsL170->Draw("lsame");

}

