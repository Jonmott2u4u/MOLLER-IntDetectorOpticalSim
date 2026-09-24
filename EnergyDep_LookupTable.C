#include <string>  
using namespace std;

void EnergyDep_LookupTable()
{

int entries = 500;
int det = 5;
int angle = 0; //This is the angle from which the mean, rms, etc will be displayed from in the lookup table.
double Eshift = 0.511;

float energy[entries],mean[entries],rms[entries],mp_langau[entries],gsigma_langau[entries],rms_mean[entries],res_langau[entries],weight[entries];

//Loading simulation data from MOLLEROptical txtfiles
ifstream infile;
//ofstream EnergyDepTable;

infile.open(Form("txtfiles/weighted_r%i_%ideg_thetaY_x25y15_EnergyScan.txt",det,angle));
//EnergyDepTable.open(Form("csvfiles/mean/r%i_EnergyDepTable.csv",det));
//EnergyDepTable<<"Energy [MeV],"<<"Scaling Factor"<<"\n";

//Loading simulation results
for (int i=0; i<entries; i++)
{
infile>>energy[i]>>mean[i]>>rms[i]>>mp_langau[i]>>gsigma_langau[i]>>rms_mean[i]>>res_langau[i]>>weight[i];
//cout << energy[i] << endl;
}
double weight_fix = 1/weight[entries-1]; //Accounts for a bug in R1 where events fail to interact with the tile.

TCanvas *c1 = new TCanvas();
TGraph *mean_pes = new TGraph();
mean_pes->GetXaxis()->SetTitle("Energy [MeV]");
mean_pes->GetYaxis()->SetTitle("Scaling Factor");
mean_pes->SetTitle(Form(" R%i Scaling Factor vs. Electron Energy near tile edge",det));
mean_pes->GetXaxis()->SetRangeUser(0,1000);
mean_pes->GetYaxis()->SetRangeUser(0,1); 
//mean_pes->GetYaxis()->SetRangeUser(0,40);
mean_pes->SetMarkerStyle(21);

for (int entry=0; entry<entries; entry++){

    //mean_pes->SetPoint(entry,energy[entry],mean[entry]/mean[entries-1]); //With weight (based on 1000 MeV value)
    //mean_pes->SetPoint(entry,energy[entry],mean[entry]); //Without weight (based on 1000 MeV value)
    //mean_pes->SetPoint(entry,energy[entry],mean[entry]*weight[entry]/mean[entries-1]); //With 1000 MeV based weight and event based weight
    //mean_pes->SetPoint(entry,energy[entry],mean[entry]*weight[entry]); //With only event based weight

    if (det == 1){
        mean_pes->SetPoint(entry,energy[entry],mean[entry]*weight[entry]*weight_fix/mean[entries-1]);
        //EnergyDepTable<<energy[entry]+Eshift<<","<<mean[entry]*weight[entry]*weight_fix/mean[entries-1]<<"\n";
    }
    
    if (det != 1){
        mean_pes->SetPoint(entry,energy[entry],mean[entry]*weight[entry]/mean[entries-1]);
        //EnergyDepTable<<energy[entry]+Eshift<<","<<mean[entry]*weight[entry]/mean[entries-1]<<"\n";
    }

}

//TF1 *fit = new TF1("fit", "[0]*x + [1]*x*x", 2, 1000);
//fit->SetParameter(0,0);
//fit->SetParameter(0,-.1);
//fit->SetParameter(1,0);
//fit->SetParameter(2,0);
//mean_pes->Fit("fit","Q");

//TF1 *fit = new TF1("fit","(TMath::Erf((x-[0])/[1]) + 1)/2",0,1000);
//TF1 *fit = new TF1("fit","TMath::Log10([0]*x + [2]) + [1]",0,1000);
//fit->SetParameter(0,1);
//fit->SetParameter(1,2);
//fit->SetParameter(2,0);
//mean_pes->Fit("fit","Q");

mean_pes->Draw();
c1->Modified();
c1->Update();
c1->Print(Form("energy_dependence/weight/png/event_weight_r%i_%ideg_x25y15.png",det,angle));
mean_pes->SaveAs(Form("energy_dependence/weight/event_weight_r%i_%ideg_x25y15.root",det,angle));
c1->Close();
mean_pes->Delete();
//fit->Delete();

}