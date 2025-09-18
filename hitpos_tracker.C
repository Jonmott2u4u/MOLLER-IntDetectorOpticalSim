void hitpos_tracker()
{

int entries = 357;
int det = 1;
float h_pos[entries],v_pos[entries],mean[entries],rms[entries],mp_langau[entries],gsigma_langau[entries],rms_mean[entries],res_langau[entries],weight[entries],scale[entries];

char run_type[] = "";
char weighted[] = ""; //"_w" for weighted runs, "" for no weight

ifstream infile;
infile.open(Form("r%i%s.txt",det,weighted));

//Loading simulation results
// i_max = quartz radial length + bevel radial length + 20mm (10 above bevel, 10 below butt of tile)
// for LG signals, set i_max = entries
for (int i=0; i<entries; i++)
{
infile>>h_pos[i]>>v_pos[i]>>mean[i]>>rms[i]>>mp_langau[i]>>gsigma_langau[i]>>rms_mean[i]>>res_langau[i]>>weight[i]>>scale[i];
//cout << h_pos[i] << endl;
}
float x_step = 5.0, y_step = 5.0;
float x_start = h_pos[0], x_stop = h_pos[entries-1], x_bins = (x_stop - x_start)/x_step + 1;
float y_start = v_pos[0], y_stop = v_pos[entries-1], y_bins = (y_stop - y_start)/y_step + 1;



//..................Mean PE yield plot.................................//
TCanvas *c1 = new TCanvas();

TProfile2D *mean_pes = new TProfile2D("mean_pes",Form("Mean PE yield of R%i per tile hit position",det),x_bins,x_start,x_stop,y_bins,y_start,y_stop);
for(int i=0; i<entries; i++){
    mean_pes->Fill(h_pos[i],v_pos[i],mean[i],1);
}
mean_pes->GetXaxis()->SetTitle("Azimuthal Position [mm]");
mean_pes->GetYaxis()->SetTitle("Radial Position [mm]");
mean_pes->Draw("colz");



//..................Langau PE yield plot.................................//
TCanvas *c2 = new TCanvas();

TProfile2D *langau_pes = new TProfile2D("langau_pes",Form("Langau PE yield of R%i per tile hit position",det),x_bins,x_start,x_stop,y_bins,y_start,y_stop);
for(int i=0; i<entries; i++){
    langau_pes->Fill(h_pos[i],v_pos[i],mp_langau[i],1);
}
langau_pes->GetXaxis()->SetTitle("Azimuthal Position [mm]");
langau_pes->GetYaxis()->SetTitle("Radial Position [mm]");
langau_pes->Draw("colz");



//..................RMS/Mean plot.................................//
TCanvas *c3 = new TCanvas();

TProfile2D *RMS_Mean = new TProfile2D("RMS_Mean",Form("RMS/Mean of R%i per tile hit position",det),x_bins,x_start,x_stop,y_bins,y_start,y_stop);
for(int i=0; i<entries; i++){
    RMS_Mean->Fill(h_pos[i],v_pos[i],rms_mean[i],1);
}
RMS_Mean->GetXaxis()->SetTitle("Azimuthal Position [mm]");
RMS_Mean->GetYaxis()->SetTitle("Radial Position [mm]");
RMS_Mean->Draw("colz");



//..................Resolution plot.................................//
TCanvas *c4 = new TCanvas();

TProfile2D *RES = new TProfile2D("RES",Form("Resolution of R%i per tile hit position",det),x_bins,x_start,x_stop,y_bins,y_start,y_stop);
for(int i=0; i<entries; i++){
    RES->Fill(h_pos[i],v_pos[i],res_langau[i],1);
}
RES->GetXaxis()->SetTitle("Azimuthal Position [mm]");
RES->GetYaxis()->SetTitle("Radial Position [mm]");
RES->Draw("colz");



//..................Printing the plots.................................//
c1->Print(Form("plots/r%i_mean_PE_yield%s.root",det,weighted));
c2->Print(Form("plots/r%i_langau_PE_yield%s.root",det,weighted));
c3->Print(Form("plots/r%i_rms_mean_yield%s.root",det,weighted));
c4->Print(Form("plots/r%i_res_yield%s.root",det,weighted));


}
