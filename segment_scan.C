void segment_scan()
{

int entries = 5301;

float h_pos_r6[entries],v_pos_r6[entries],mean_r6[entries],rms_r6[entries],mp_langau_r6[entries],gsigma_langau_r6[entries],rms_mean_r6[entries],res_langau_r6[entries],weight_r6[entries],scale_r6[entries];
float h_pos_r5ff[entries],v_pos_r5ff[entries],mean_r5ff[entries],rms_r5ff[entries],mp_langau_r5ff[entries],gsigma_langau_r5ff[entries],rms_mean_r5ff[entries],res_langau_r5ff[entries],weight_r5ff[entries],scale_r5ff[entries];
float h_pos_r4[entries],v_pos_r4[entries],mean_r4[entries],rms_r4[entries],mp_langau_r4[entries],gsigma_langau_r4[entries],rms_mean_r4[entries],res_langau_r4[entries],weight_r4[entries],scale_r4[entries];
float h_pos_r3[entries],v_pos_r3[entries],mean_r3[entries],rms_r3[entries],mp_langau_r3[entries],gsigma_langau_r3[entries],rms_mean_r3[entries],res_langau_r3[entries],weight_r3[entries],scale_r3[entries];
float h_pos_r2[entries],v_pos_r2[entries],mean_r2[entries],rms_r2[entries],mp_langau_r2[entries],gsigma_langau_r2[entries],rms_mean_r2[entries],res_langau_r2[entries],weight_r2[entries],scale_r2[entries];
float h_pos_r1[entries],v_pos_r1[entries],mean_r1[entries],rms_r1[entries],mp_langau_r1[entries],gsigma_langau_r1[entries],rms_mean_r1[entries],res_langau_r1[entries],weight_r1[entries],scale_r1[entries];

char run_type[] = "";
char weight[] = "_w"; //"_w" for weighted runs, "" for no weight

ifstream infile_r6, infile_r5ff, infile_r4, infile_r3, infile_r2, infile_r1;
infile_r6.open(Form("txt_files/r6%s.txt",weight));
infile_r5ff.open(Form("txt_files/r5%s.txt",weight));
infile_r4.open(Form("txt_files/r4%s.txt",weight));
infile_r3.open(Form("txt_files/r3%s.txt",weight));
infile_r2.open(Form("txt_files/r2%s.txt",weight));
infile_r1.open(Form("txt_files/r1%s.txt",weight));

//Loading simulation results
// i_max = quartz radial length + bevel radial length + 20mm (10 above bevel, 10 below butt of tile)
// for LG signals, set i_max = entries
for (int i=0; i<entries; i++)
{
infile_r6>>h_pos_r6[i]>>v_pos_r6[i]>>mean_r6[i]>>rms_r6[i]>>mp_langau_r6[i]>>gsigma_langau_r6[i]>>rms_mean_r6[i]>>res_langau_r6[i]>>weight_r6[i]>>scale_r6[i];
//cout << " ring 6 " << v_pos_r6[i] << " pe " << mp_langau_r6[i] << endl;
}
for (int i=0; i<entries; i++)
{
infile_r5ff>>h_pos_r5ff[i]>>v_pos_r5ff[i]>>mean_r5ff[i]>>rms_r5ff[i]>>mp_langau_r5ff[i]>>gsigma_langau_r5ff[i]>>rms_mean_r5ff[i]>>res_langau_r5ff[i]>>weight_r5ff[i]>>scale_r5ff[i];
}
for (int i=0; i<entries; i++)
{
infile_r4>>h_pos_r4[i]>>v_pos_r4[i]>>mean_r4[i]>>rms_r4[i]>>mp_langau_r4[i]>>gsigma_langau_r4[i]>>rms_mean_r4[i]>>res_langau_r4[i]>>weight_r4[i]>>scale_r4[i];
}
for (int i=0; i<entries; i++)
{
infile_r3>>h_pos_r3[i]>>v_pos_r3[i]>>mean_r3[i]>>rms_r3[i]>>mp_langau_r3[i]>>gsigma_langau_r3[i]>>rms_mean_r3[i]>>res_langau_r3[i]>>weight_r3[i]>>scale_r3[i];
}
for (int i=0; i<entries; i++)
{
infile_r2>>h_pos_r2[i]>>v_pos_r2[i]>>mean_r2[i]>>rms_r2[i]>>mp_langau_r2[i]>>gsigma_langau_r2[i]>>rms_mean_r2[i]>>res_langau_r2[i]>>weight_r2[i]>>scale_r2[i];
}
for (int i=0; i<entries; i++)
{
infile_r1>>h_pos_r1[i]>>v_pos_r1[i]>>mean_r1[i]>>rms_r1[i]>>mp_langau_r1[i]>>gsigma_langau_r1[i]>>rms_mean_r1[i]>>res_langau_r1[i]>>weight_r1[i]>>scale_r1[i];
}


//..................Mean PE yield plots .................................//
TCanvas *c1 = new TCanvas();
TMultiGraph *mean_pes = new TMultiGraph();

TGraph *mean_pes_r6 = new TGraph (entries,v_pos_r6,mean_r6);
mean_pes_r6->SetMarkerStyle(8);
mean_pes_r6->SetMarkerColor(kBlue);
mean_pes_r6->SetMarkerSize(1.5);

TGraph *mean_pes_r5ff = new TGraph (entries,v_pos_r5ff,mean_r5ff);
mean_pes_r5ff->SetMarkerStyle(8);
mean_pes_r5ff->SetMarkerColor(kRed);
mean_pes_r5ff->SetMarkerSize(1.5);

TGraph *mean_pes_r4 = new TGraph (entries,v_pos_r4,mean_r4);
mean_pes_r4->SetMarkerStyle(8);
mean_pes_r4->SetMarkerColor(kGreen+3);
mean_pes_r4->SetMarkerSize(1.5);

TGraph *mean_pes_r3 = new TGraph (entries,v_pos_r3,mean_r3);
mean_pes_r3->SetMarkerStyle(8);
mean_pes_r3->SetMarkerColor(kOrange);
mean_pes_r3->SetMarkerSize(1.5);

TGraph *mean_pes_r2 = new TGraph (entries,v_pos_r2,mean_r2);
mean_pes_r2->SetMarkerStyle(8);
mean_pes_r2->SetMarkerColor(kMagenta);
mean_pes_r2->SetMarkerSize(1.5);

TGraph *mean_pes_r1 = new TGraph (entries,v_pos_r1,mean_r1);
mean_pes_r1->SetMarkerStyle(8);
mean_pes_r1->SetMarkerColor(7);
mean_pes_r1->SetMarkerSize(1.5);

mean_pes->Add(mean_pes_r6,"p");
mean_pes->Add(mean_pes_r5ff,"p");
mean_pes->Add(mean_pes_r4,"p");
mean_pes->Add(mean_pes_r3,"p");
mean_pes->Add(mean_pes_r2,"p");
mean_pes->Add(mean_pes_r1,"p");
mean_pes->GetXaxis()->SetTitle("Beam Position [mm]");
mean_pes->GetYaxis()->SetTitle("PE yield (mean)");
mean_pes->SetTitle("Mean PEs vs. Beam Position");
mean_pes->GetXaxis()->SetLimits(-10,580);
mean_pes->GetYaxis()->SetRangeUser(0,40);
mean_pes->Draw("A");
//Generating a Legend
auto legend_mean_pes = new TLegend(0.6,0.7,0.9,0.9);
legend_mean_pes->SetHeader("Detector","C"); // option "C" allows to center the header
legend_mean_pes->AddEntry(mean_pes_r1,"R1","lep");
legend_mean_pes->AddEntry(mean_pes_r2,"R2","lep");
legend_mean_pes->AddEntry(mean_pes_r3,"R3","lep");
legend_mean_pes->AddEntry(mean_pes_r4,"R4","lep");
legend_mean_pes->AddEntry(mean_pes_r5ff,"R5","lep");
legend_mean_pes->AddEntry(mean_pes_r6,"R6","lep");
legend_mean_pes->Draw();
c1->SetGridx();
c1->SetGridy();

//..................Langau PE yield plots .................................//
TCanvas *c2 = new TCanvas();
TMultiGraph *langau_pes = new TMultiGraph();

TGraph *langau_pes_r6 = new TGraph (entries,v_pos_r6,mp_langau_r6);
langau_pes_r6->SetMarkerStyle(8);
langau_pes_r6->SetMarkerColor(kBlue);
langau_pes_r6->SetMarkerSize(1.5);

TGraph *langau_pes_r5ff = new TGraph (entries,v_pos_r5ff,mp_langau_r5ff);
langau_pes_r5ff->SetMarkerStyle(8);
langau_pes_r5ff->SetMarkerColor(kRed);
langau_pes_r5ff->SetMarkerSize(1.5);

TGraph *langau_pes_r4 = new TGraph (entries,v_pos_r4,mp_langau_r4);
langau_pes_r4->SetMarkerStyle(8);
langau_pes_r4->SetMarkerColor(kGreen+3);
langau_pes_r4->SetMarkerSize(1.5);

TGraph *langau_pes_r3 = new TGraph (entries,v_pos_r3,mp_langau_r3);
langau_pes_r3->SetMarkerStyle(8);
langau_pes_r3->SetMarkerColor(kOrange);
langau_pes_r3->SetMarkerSize(1.5);

TGraph *langau_pes_r2 = new TGraph (entries,v_pos_r2,mp_langau_r2);
langau_pes_r2->SetMarkerStyle(8);
langau_pes_r2->SetMarkerColor(kMagenta);
langau_pes_r2->SetMarkerSize(1.5);

TGraph *langau_pes_r1 = new TGraph (entries,v_pos_r1,mp_langau_r1);
langau_pes_r1->SetMarkerStyle(8);
langau_pes_r1->SetMarkerColor(7);
langau_pes_r1->SetMarkerSize(1.5);

langau_pes->Add(langau_pes_r6,"p");
langau_pes->Add(langau_pes_r5ff,"p");
langau_pes->Add(langau_pes_r4,"p");
langau_pes->Add(langau_pes_r3,"p");
langau_pes->Add(langau_pes_r2,"p");
langau_pes->Add(langau_pes_r1,"p");
langau_pes->GetXaxis()->SetTitle("Beam Positiom [mm]");
langau_pes->GetYaxis()->SetTitle("PE yield (langau)");
langau_pes->SetTitle("Langau PEs vs. Beam Position");
langau_pes->GetXaxis()->SetLimits(-10,580);
langau_pes->GetYaxis()->SetRangeUser(0,40);
langau_pes->Draw("A");
//Generating a Legend
auto legend_langau_pes = new TLegend(0.6,0.7,0.9,0.9);
legend_langau_pes->SetHeader("Detector","C"); // option "C" allows to center the header
legend_langau_pes->AddEntry(langau_pes_r1,"R1","lep");
legend_langau_pes->AddEntry(langau_pes_r2,"R2","lep");
legend_langau_pes->AddEntry(langau_pes_r3,"R3","lep");
legend_langau_pes->AddEntry(langau_pes_r4,"R4","lep");
legend_langau_pes->AddEntry(langau_pes_r5ff,"R5","lep");
legend_langau_pes->AddEntry(langau_pes_r6,"R6","lep");
legend_langau_pes->Draw();
c2->SetGridx();
c2->SetGridy();
/*TF1 *f1 = new TF1("f1","[0]",410.5,510.5);
f1->SetParameter(0,40);
langau_pes->Fit("f1","R");
//f1->SetLineColor(kBlue);
f1->Draw("lsame");*/

//..................RMS/Mean plots.................................//
TCanvas *c3 = new TCanvas();
TMultiGraph *RMS_mean = new TMultiGraph();

TGraph *RMS_mean_r6 = new TGraph (entries,v_pos_r6,rms_mean_r6);
RMS_mean_r6->SetMarkerStyle(8);
RMS_mean_r6->SetMarkerColor(kBlue);
RMS_mean_r6->SetMarkerSize(1.5);

TGraph *RMS_mean_r5ff = new TGraph (entries,v_pos_r5ff,rms_mean_r5ff);
RMS_mean_r5ff->SetMarkerStyle(8);
RMS_mean_r5ff->SetMarkerColor(kRed);
RMS_mean_r5ff->SetMarkerSize(1.5);

TGraph *RMS_mean_r4 = new TGraph (entries,v_pos_r4,rms_mean_r4);
RMS_mean_r4->SetMarkerStyle(8);
RMS_mean_r4->SetMarkerColor(kGreen+3);
RMS_mean_r4->SetMarkerSize(1.5);

TGraph *RMS_mean_r3 = new TGraph (entries,v_pos_r3,rms_mean_r3);
RMS_mean_r3->SetMarkerStyle(8);
RMS_mean_r3->SetMarkerColor(kOrange);
RMS_mean_r3->SetMarkerSize(1.5);

TGraph *RMS_mean_r2 = new TGraph (entries,v_pos_r2,rms_mean_r2);
RMS_mean_r2->SetMarkerStyle(8);
RMS_mean_r2->SetMarkerColor(kMagenta);
RMS_mean_r2->SetMarkerSize(1.5);

TGraph *RMS_mean_r1 = new TGraph (entries,v_pos_r1,rms_mean_r1);
RMS_mean_r1->SetMarkerStyle(8);
RMS_mean_r1->SetMarkerColor(7);
RMS_mean_r1->SetMarkerSize(1.5);

RMS_mean->Add(RMS_mean_r6,"p");
RMS_mean->Add(RMS_mean_r5ff,"p");
RMS_mean->Add(RMS_mean_r4,"p");
RMS_mean->Add(RMS_mean_r3,"p");
RMS_mean->Add(RMS_mean_r2,"p");
RMS_mean->Add(RMS_mean_r1,"p");
RMS_mean->GetXaxis()->SetTitle("Beam Position [mm]");
RMS_mean->GetYaxis()->SetTitle("RMS/Mean");
RMS_mean->SetTitle("RMS/Mean vs. Beam Position");
RMS_mean->GetXaxis()->SetLimits(-10,580);
RMS_mean->GetYaxis()->SetRangeUser(0,50);
RMS_mean->Draw("A");
//Generating a Legend
auto legend_RMS_mean = new TLegend(0.6,0.7,0.9,0.9);
legend_RMS_mean->SetHeader("Detector","C"); // option "C" allows to center the header
legend_RMS_mean->AddEntry(RMS_mean_r1,"R1","lep");
legend_RMS_mean->AddEntry(RMS_mean_r2,"R2","lep");
legend_RMS_mean->AddEntry(RMS_mean_r3,"R3","lep");
legend_RMS_mean->AddEntry(RMS_mean_r4,"R4","lep");
legend_RMS_mean->AddEntry(RMS_mean_r5ff,"R5","lep");
legend_RMS_mean->AddEntry(RMS_mean_r6,"R6","lep");
legend_RMS_mean->Draw();
c3->SetGridx();
c3->SetGridy();

//..................Resolution plots.................................//
TCanvas *c4 = new TCanvas();
TMultiGraph *RES_langau = new TMultiGraph();

TGraph *RES_langau_r6 = new TGraph (entries,v_pos_r6,res_langau_r6);
RES_langau_r6->SetMarkerStyle(8);
RES_langau_r6->SetMarkerColor(kBlue);
RES_langau_r6->SetMarkerSize(1.5);

TGraph *RES_langau_r5ff = new TGraph (entries,v_pos_r5ff,res_langau_r5ff);
RES_langau_r5ff->SetMarkerStyle(8);
RES_langau_r5ff->SetMarkerColor(kRed);
RES_langau_r5ff->SetMarkerSize(1.5);

TGraph *RES_langau_r4 = new TGraph (entries,v_pos_r4,res_langau_r4);
RES_langau_r4->SetMarkerStyle(8);
RES_langau_r4->SetMarkerColor(kGreen+3);
RES_langau_r4->SetMarkerSize(1.5);

TGraph *RES_langau_r3 = new TGraph (entries,v_pos_r3,res_langau_r3);
RES_langau_r3->SetMarkerStyle(8);
RES_langau_r3->SetMarkerColor(kOrange);
RES_langau_r3->SetMarkerSize(1.5);

TGraph *RES_langau_r2 = new TGraph (entries,v_pos_r2,res_langau_r2);
RES_langau_r2->SetMarkerStyle(8);
RES_langau_r2->SetMarkerColor(kMagenta);
RES_langau_r2->SetMarkerSize(1.5);

TGraph *RES_langau_r1 = new TGraph (entries,v_pos_r1,res_langau_r1);
RES_langau_r1->SetMarkerStyle(8);
RES_langau_r1->SetMarkerColor(7);
RES_langau_r1->SetMarkerSize(1.5);

RES_langau->Add(RES_langau_r6,"p");
RES_langau->Add(RES_langau_r5ff,"p");
RES_langau->Add(RES_langau_r4,"p");
RES_langau->Add(RES_langau_r3,"p");
RES_langau->Add(RES_langau_r2,"p");
RES_langau->Add(RES_langau_r1,"p");
RES_langau->GetXaxis()->SetTitle("Beam Position [mm]");
RES_langau->GetYaxis()->SetTitle("Resolution (langau)");
RES_langau->SetTitle("Resolution vs. Beam Position");
RES_langau->GetXaxis()->SetLimits(-10,580);
RES_langau->GetYaxis()->SetRangeUser(0,50);
RES_langau->Draw("A");
//Generating a Legend
auto legend_RES_langau = new TLegend(0.6,0.7,0.9,0.9);
legend_RES_langau->SetHeader("Detector","C"); // option "C" allows to center the header
legend_RES_langau->AddEntry(RES_langau_r1,"R1","lep");
legend_RES_langau->AddEntry(RES_langau_r2,"R2","lep");
legend_RES_langau->AddEntry(RES_langau_r3,"R3","lep");
legend_RES_langau->AddEntry(RES_langau_r4,"R4","lep");
legend_RES_langau->AddEntry(RES_langau_r5ff,"R5","lep");
legend_RES_langau->AddEntry(RES_langau_r6,"R6","lep");
legend_RES_langau->Draw();
c4->SetGridx();
c4->SetGridy();

//..................Weight plots.................................//
//The current weight is non-zero entries / all entries
TCanvas *c5 = new TCanvas();
TMultiGraph *Weight = new TMultiGraph();

TGraph *Weight_r6 = new TGraph (entries,v_pos_r6,weight_r6);
Weight_r6->SetMarkerStyle(8);
Weight_r6->SetMarkerColor(kBlue);
Weight_r6->SetMarkerSize(1.5);

TGraph *Weight_r5ff = new TGraph (entries,v_pos_r5ff,weight_r5ff);
Weight_r5ff->SetMarkerStyle(8);
Weight_r5ff->SetMarkerColor(kRed);
Weight_r5ff->SetMarkerSize(1.5);

TGraph *Weight_r4 = new TGraph (entries,v_pos_r4,weight_r4);
Weight_r4->SetMarkerStyle(8);
Weight_r4->SetMarkerColor(kGreen+3);
Weight_r4->SetMarkerSize(1.5);

TGraph *Weight_r3 = new TGraph (entries,v_pos_r3,weight_r3);
Weight_r3->SetMarkerStyle(8);
Weight_r3->SetMarkerColor(kOrange);
Weight_r3->SetMarkerSize(1.5);

TGraph *Weight_r2 = new TGraph (entries,v_pos_r2,weight_r2);
Weight_r2->SetMarkerStyle(8);
Weight_r2->SetMarkerColor(kMagenta);
Weight_r2->SetMarkerSize(1.5);

TGraph *Weight_r1 = new TGraph (entries,v_pos_r1,weight_r1);
Weight_r1->SetMarkerStyle(8);
Weight_r1->SetMarkerColor(7);
Weight_r1->SetMarkerSize(1.5);

Weight->Add(Weight_r6,"p");
Weight->Add(Weight_r5ff,"p");
Weight->Add(Weight_r4,"p");
Weight->Add(Weight_r3,"p");
Weight->Add(Weight_r2,"p");
Weight->Add(Weight_r1,"p");
Weight->GetXaxis()->SetTitle("Beam Position [mm]");
Weight->GetYaxis()->SetTitle("Scaling Factor (nonzero entries/all entries)");
Weight->SetTitle("Scaling Factor vs. Beam Position");
Weight->GetXaxis()->SetLimits(-10,580);
Weight->GetYaxis()->SetRangeUser(0,1.5);
Weight->Draw("A");
//Generating a Legend
auto legend_Weight = new TLegend(0.6,0.7,0.9,0.9);
legend_Weight->SetHeader("Detector","C"); // option "C" allows to center the header
legend_Weight->AddEntry(Weight_r1,"R1","lep");
legend_Weight->AddEntry(Weight_r2,"R2","lep");
legend_Weight->AddEntry(Weight_r3,"R3","lep");
legend_Weight->AddEntry(Weight_r4,"R4","lep");
legend_Weight->AddEntry(Weight_r5ff,"R5","lep");
legend_Weight->AddEntry(Weight_r6,"R6","lep");
legend_Weight->Draw();
c5->SetGridx();
c5->SetGridy();

//..................Scaling plots.................................//
TCanvas *c6 = new TCanvas();
TMultiGraph *Scale = new TMultiGraph();

TGraph *Scale_r6 = new TGraph (entries,v_pos_r6,scale_r6);
Scale_r6->SetMarkerStyle(8);
Scale_r6->SetMarkerColor(kBlue);
Scale_r6->SetMarkerSize(1.5);

TGraph *Scale_r5ff = new TGraph (entries,v_pos_r5ff,scale_r5ff);
Scale_r5ff->SetMarkerStyle(8);
Scale_r5ff->SetMarkerColor(kRed);
Scale_r5ff->SetMarkerSize(1.5);

TGraph *Scale_r4 = new TGraph (entries,v_pos_r4,scale_r4);
Scale_r4->SetMarkerStyle(8);
Scale_r4->SetMarkerColor(kGreen+3);
Scale_r4->SetMarkerSize(1.5);

TGraph *Scale_r3 = new TGraph (entries,v_pos_r3,scale_r3);
Scale_r3->SetMarkerStyle(8);
Scale_r3->SetMarkerColor(kOrange);
Scale_r3->SetMarkerSize(1.5);

TGraph *Scale_r2 = new TGraph (entries,v_pos_r2,scale_r2);
Scale_r2->SetMarkerStyle(8);
Scale_r2->SetMarkerColor(kMagenta);
Scale_r2->SetMarkerSize(1.5);

TGraph *Scale_r1 = new TGraph (entries,v_pos_r1,scale_r1);
Scale_r1->SetMarkerStyle(8);
Scale_r1->SetMarkerColor(7);
Scale_r1->SetMarkerSize(1.5);

//Scale->Add(Scale_r6,"p");
Scale->Add(Scale_r5ff,"p");
//Scale->Add(Scale_r4,"p");
//Scale->Add(Scale_r3,"p");
//Scale->Add(Scale_r2,"p");
//Scale->Add(Scale_r1,"p");
Scale->GetXaxis()->SetTitle("Beam Position [mm]");
Scale->GetYaxis()->SetTitle("Signal ratio");
Scale->SetTitle("Ratio of signal size in DS Ring vs. US");
Scale->GetXaxis()->SetLimits(-10,580);
Scale->GetYaxis()->SetRangeUser(0,4);
//Scale->Draw("A");
c6->SetGridx();
c6->SetGridy();

TF1 *f1 = new TF1("f1","(TMath::Erf((x-[0])/[1]) + 1)/2",400,420);
f1->SetParameter(0,409.5);
f1->SetParameter(1,2);
Scale->Fit("f1");
Scale->Draw("A");
f1->Draw("lsame");

//Adding Mainz data to the Scaling plot
/*TGraph *Scale_mainz_r1 = new TGraph (11,v_pos_mainz_r1,scale_mainz_r1);
Scale_mainz_r1->SetMarkerStyle(8);
Scale_mainz_r1->SetMarkerColor(kBlue);
Scale_mainz_r1->SetMarkerSize(1.5);
Scale->Add(Scale_mainz_r1,"p");

TGraph *Scale_mainz_r2 = new TGraph (11,v_pos_mainz_r2,scale_mainz_r2);
Scale_mainz_r2->SetMarkerStyle(8);
Scale_mainz_r2->SetMarkerColor(kBlue);
Scale_mainz_r2->SetMarkerSize(1.5);
//Scale->Add(Scale_mainz_r2,"p");

TGraph *Scale_mainz_r3 = new TGraph (9,v_pos_mainz_r3,scale_mainz_r3);
Scale_mainz_r3->SetMarkerStyle(8);
Scale_mainz_r3->SetMarkerColor(kBlue);
Scale_mainz_r3->SetMarkerSize(1.5);
Scale->Add(Scale_mainz_r3,"p");

TGraph *Scale_mainz_r4 = new TGraph (8,v_pos_mainz_r4,scale_mainz_r4);
Scale_mainz_r4->SetMarkerStyle(8);
Scale_mainz_r4->SetMarkerColor(kBlue);
Scale_mainz_r4->SetMarkerSize(1.5);
Scale->Add(Scale_mainz_r4,"p");*/

//Generating a legend - Used when comparing sims to Mainz data
auto legend_Scale = new TLegend(0.6,0.7,0.9,0.9);
legend_Scale->SetHeader("Tile Edge Search","C");
legend_Scale->AddEntry(Scale_r5ff,"R6/R5","lep");
//legend->AddEntry(Scale_mainz_r5,"Mainz data","lep");
legend_Scale->Draw();

//..................Printing the plots.................................//
c1->Print(Form("plots/mean_PE_yield%s.root",weight));
c2->Print(Form("plots/langau_PE_yield%s.root",weight));
c3->Print(Form("plots/rms_mean%s.root",weight));
c4->Print(Form("plots/langau_res%s.root",weight));
c5->Print(Form("plots/weight%s.root",weight));
c6->Print(Form("plots/scale%s_R6_R5.root",weight));

}
