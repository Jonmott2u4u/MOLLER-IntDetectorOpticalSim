#include <string>  
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;


void MainDet_Performance_LookupTable()
{

float yshift = -0.5;
int binsize = 5;
int entries = 0;
int det = 1;
int angle_def = 4; //This is the angle from which the mean, rms, etc will be displayed from in the lookup table

if (det == 1){
    entries = 315;
}
else if (det == 2){
    entries = 629;
}
else if (det == 3){
    entries = 663;
}
else if (det == 4){
    entries = 1305;
}
else if (det == 5){
    entries = 561;
}
else if (det == 6){
    entries = 1325;
}
int total_entries = entries*9;

float h_pos[total_entries],v_pos[total_entries],mean[total_entries],rms[total_entries],mp_langau[total_entries],gsigma_langau[total_entries],rms_mean[total_entries],res_langau[total_entries],weight[total_entries];

char run_type[] = "";
char direction[] = "thetaY";

//Creating directories to store results
fs::create_directories(Form("plots/theta_dependence/r%i",det));
fs::create_directories(Form("csvfiles/mean",det));
cout << "Angle dependency data is store in plots/theta_dependence/; LookupTables are stored in csvfiles/" << endl

//Loading simulation data from MOLLEROptical txtfiles
ifstream infile;
infile.open(Form("datfiles/composite/r%i_Scan%s.dat",det,direction));

//Creating the lookup table
//Certain position bins need to be manually changed after creation. The list is below:
//R1: h_pos = -85/85   -> -84.5/84.5
//R2: h_pos = -90/90   -> -89.5/89.5
//R4: h_pos = -110/110 -> -106.5/106.5
//R5: v_pos =  160     ->  157
ofstream LookupTable;
LookupTable.open(Form("csvfiles/mean/r%i_LookupTable.csv",det));
LookupTable<<"Horizontal Bin Start [mm],"<<"Horizontal Bin End [mm],"<<"Vertical Bin Start [mm],"<<"Vertical Bin End [mm],"<<"Mean PEs,"<<"Langau PEs,"<<"RMS Over Mean,"<<"Resolution,"<<" Theta Fit Param p0,"<<"Theta Fit Param p1,"<<"Theta Fit param p2,"<<"Theta Fit param p3,"<<"Theta Fit param p4,"<<"\n";

//Loading simulation results
for (int i=0; i<total_entries; i++)
{
infile>>h_pos[i]>>v_pos[i]>>mean[i]>>rms[i]>>mp_langau[i]>>gsigma_langau[i]>>rms_mean[i]>>res_langau[i]>>weight[i];
//cout << h_pos[i] << endl;
}

for (int entry=0; entry<entries; entry++){

    //..................Langau PE yield plot.................................//
    TGraph *mean_pes = new TGraph();
    mean_pes->GetXaxis()->SetTitle("Angle of Incidence [deg]");
    mean_pes->GetYaxis()->SetTitle("Mean PE Yield");
    mean_pes->SetTitle(Form("Mean PE Yield vs. Angle of Incidence for R%i at Xbin=%.1f & Ybin=%.1f",det,h_pos[entry],v_pos[entry]));
    for(int i=0; i<9; i++){
        mean_pes->SetPoint(i,i-4,mean[entry + entries*i]);
    }
    mean_pes->GetXaxis()->SetRangeUser(-5,5);
    mean_pes->GetYaxis()->SetRangeUser(0,40);
    mean_pes->SetMarkerStyle(21);

    TF1 *fit = new TF1("fit", "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x", -2, 2);
    fit->SetParameter(0,mean[entry + entries*angle_def]);
    fit->SetParameter(1,-.1);
    fit->SetParameter(2,0);
    fit->SetParameter(3,0);
    fit->SetParameter(4,0);
    /*TF1 *fit = new TF1("fit", "[0]*exp((x-[1])*([1]-x)*[2]) + [3]*pow(x,[4])", -2, 2);
    fit->SetParameter(0,mean[entry]);
    fit->SetParameter(1,0);
    fit->SetParameter(2,0);
    fit->SetParameter(3,0);
    fit->SetParameter(4,0);*/
    mean_pes->Fit("fit","Q");
    mean_pes->SaveAs(Form("theta_dependence/r%i/small_New%s_Xpos%.1f_Ypos%.1f.root",det,direction,h_pos[entry],v_pos[entry]));

    /*if (mp_langau[entry] == 0){
        fit->SetParameter(0,mean[entry]);
        fit->SetParameter(1,0);
        fit->SetParameter(2,0);
        fit->SetParameter(3,0);
    }*/

    if ((h_pos[entry] != h_pos[entries-1]) && v_pos[entry] != v_pos[entries-1]){
        LookupTable<<h_pos[entry]<<","<<h_pos[entry]+binsize<<","<<v_pos[entry]+yshift<<","<<v_pos[entry]+yshift+binsize<<","<<mean[entry + entries*angle_def]<<","<<mp_langau[entry + entries*angle_def]<<","<<rms_mean[entry + entries*angle_def]<<","<<res_langau[entry + entries*angle_def]<<","<<fit->GetParameter(0)<<","<<fit->GetParameter(1)<<","<<fit->GetParameter(2)<<","<<fit->GetParameter(3)<<","<<fit->GetParameter(4)<<"\n";    }
    

    mean_pes->Delete();
    fit->Delete();
}

}