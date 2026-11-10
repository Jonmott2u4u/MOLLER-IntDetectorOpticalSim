#include <iostream>
#include <TString.h>
#include <math.h>

namespace fs = std::filesystem;

void pes()
{
    std::ofstream analysis;
    analysis.open ("analyzed_files.txt");
    std::string str;
    TFile *file;
    file = TFile::Open("rootfiles/MOLLEROpt_0002.root");
    TH1D *hst, *tmp;

    //PE spectrum of the detector
    tmp = (TH1D*)file->Get("Ring_CathodeEventsDistrHist");
    hst = (TH1D*)tmp->Clone("pes");
    hst->SetTitle("Photoelectron Distribution");
    hst->GetXaxis()->SetTitle("Photoelectrons");
    hst->GetYaxis()->SetTitle("Events");
    hst->GetXaxis()->SetRangeUser(1,100);
    hst->SetDirectory(0);
    str = "plots/nofit_PEs.root";
    hst->SaveAs(str.data());
    analysis << str << "\n"; 
    file->Close("R");

    analysis.close();
}

void multi_extract()
{
    //This function extracts the PE yield from a position-based rootfiles
    //Two datfiles are saved per rootfile: One with the raw pe yield, and another cutting 0-pe events.
    //Similar to LangauFitter_XYgrid.C, but without the fitting procedure.

    fs::create_directories(Form("datfiles/r%i/Gamma", ring));
    cout << "File path files are located in txtfiles/; Data files are located in datfiles/" << endl;

    std::ofstream ring_dat;       //Opens a dat file where info like mean PE's is stored. Was added to create data formatted for a specific script
    std::ofstream ring_dat2;       //Opens a dat file where info like mean PE's is stored. Was added to create data formatted for a specific script

    int ring = 5, angle = 0, energy = 100; //The ring being analyzed with hits at some angle and energy
    ring_dat.open (Form("datfiles/r%i/Gamma/Energy_%iMeV_ThetaY_%ideg.dat", ring, energy, angle));     //Change the name to match the ring being analyzed, otherwise files will be overwritten
    ring_dat2.open (Form("datfiles/r%i/Gamma/No0_Energy_%iMeV_ThetaY_%ideg.dat", ring, energy, angle));     //Change the name to match the ring being analyzed, otherwise files will be overwritten

    std::ifstream rfiles(Form("txtfiles/r%i/Gamma/Energy_%iMeV_ThetaY_%ideg.txt", ring, energy, angle)); //Opens a txt file where the root file paths to scan over are stored
    std::string line;
    TFile *file;

    Double_t paramx_start=-40.0, paramy_start=0.5; //Start positions of tile
    Double_t paramx_step=5.0, paramy_step=5.0; //Increment for the horizontal axis
    Double_t limity=160.5;

    TH1D *hst, *tmp;
    Double_t paramx_run, paramy_run, counterx, countery;

    float mean;

    counterx=0, countery=0; 
    paramx_run = paramx_start;
    while(std::getline(rfiles, line)){

       file = TFile::Open(line.data()); 
       cout << line.data() << endl;
      
       paramy_run = paramy_start + countery*paramy_step;
       countery = countery + 1.0;
 
       tmp = (TH1D*)file->Get("Ring_CathodeEventsDistrHist");  //Loads a histogram associated with a ring of the user's choice
       hst = (TH1D*)tmp->Clone("PEs");
       hst->SetDirectory(0);
       hst->SetTitle("Photoelectron Distribution");
       hst->GetXaxis()->SetTitle("Photoelectrons");

       //Filling the datfile that considers all events
       hst->GetXaxis()->SetRangeUser(0,100);
       mean = hst->GetMean();
       ring_dat<<paramx_run<<" "<<paramy_run<<" "<<mean<<" "<<rms<<" "<<mp<<" "<<gsigma<<" "<<rms_mean<<" "<<res<<" "<<1.0<<"\n";

       //Filling the datfile that only considers non-zero events
       hst->GetXaxis()->SetRangeUser(1,100);
       mean = hst->GetMean();
       ring_dat2<<paramx_run<<" "<<paramy_run<<" "<<mean<<" "<<rms<<" "<<mp<<" "<<gsigma<<" "<<rms_mean<<" "<<res<<" "<<1.0<<"\n";

       file->Close("R");    

       if (paramy_run == limity){
          counterx = counterx + 1.0;
          paramx_run = paramx_start + counterx*paramx_step;
          countery = 0.0;
       }
    }
    ring_dat.close();
    ring_dat2.close();
    rfiles.close();
}

//This object performs cuts over the quartz in the x-direction
void quartz_divider(){

    std::ifstream rfiles("files.dat");
    std::string line;
    TFile *file;
    TH1D *hst, *tmp;
    int pos, file_open = 0;

    while(std::getline(rfiles, line)){
        file = TFile::Open(line.data());
        file_open++;
        for(int det=4; det<5; det++){
            pos = -11;
            while(pos <= 1){
                pos++;
		        pos++;
                TTree *tree = (TTree*)file->Get("MOLLEROptTree");
                TCanvas *canvas_pes = new TCanvas("canvas_pes","canvas_pes");
                tree->Draw(Form("MOLLEROptData.MOLLERGeneralEvent.R%iSoloPEs",det),Form("(MOLLEROptData.MOLLERGeneralEvent.R%iTileHitY <= %i) && (MOLLEROptData.MOLLERGeneralEvent.R%iTileHitY > %i-2)",det,pos,det,pos));
                canvas_pes->SaveAs(Form("plots/nofit/r%i/file%i_pes_pos_%i.root",det,file_open,pos));

                /*TCanvas *canvas_pos = new TCanvas("canvas_pos","canvas_pos");
                tree->Draw(Form("MOLLEROptData.MOLLERGeneralEvent.R%iTileHitY:MOLLEROptData.MOLLERGeneralEvent.R%iTileHitX",det,det),Form("(MOLLEROptData.MOLLERGeneralEvent.R%iTileHitY <= %i) && (MOLLEROptData.MOLLERGeneralEvent.R%iTileHitY > %i-2)",det,pos,det,pos),"colz");
                canvas_pos->SaveAs(Form("plots/nofit/r%i/file%i_quartz_pos_%i.root",det,file_open,pos));*/

            }
        }
        file->Close("R");
    }
}

void quartz_hit_pos(){

    std::ifstream rfiles("files.dat");
    std::string line;
    TString tmpStr;
    string location = "MOLLEROptData.MOLLERGeneralEvent.";
    TFile *file;
    TH1D *hst, *tmp;
    int det = 5;

    while(std::getline(rfiles, line)){
        /*tmpStr = line.data();
        tmpStr = tmpStr.ReplaceAll(".root",""); */
        file = TFile::Open(line.data());
        TTree *tree = (TTree*)file->Get("MOLLEROptTree");

        TCanvas *canvas1 = new TCanvas("canvas1","canvas1");
        tree->Draw(Form("%sR%iTileHitY:%sR%iTileHitX",location.data(),det,location.data(),det),Form("%sScint1TrackHit==1 && %sScint2TrackHit==1",location.data(),location.data()),"colz");
        canvas1->SaveAs(Form("plots/R%i_quartz_hit_pos.root",det));

        TCanvas *canvas2 = new TCanvas("canvas2","canvas2");
        tree->Draw(Form("%sR%iTileHitY:%sR%iTileHitX",location.data(),det,location.data(),det),Form("%sScint1TrackHit==1 && %sScint2TrackHit==1 && %sR%iAdjacentCutQuartzTrackHit==1",location.data(),location.data(),location.data(),det),"colz");
        canvas2->SaveAs(Form("plots/R%i_adjacency_quartz_hit_pos.root",det));

        TCanvas *canvas3 = new TCanvas("canvas3","canvas3");
        tree->Draw(Form("%sR%iTileHitY:%sR%iTileHitX",location.data(),det,location.data(),det),Form("%sScint1TrackHit==1 && %sScint2TrackHit==1 && %sR%iSoloCutQuartzTrackHit==1",location.data(),location.data(),location.data(),det),"colz");
        canvas3->SaveAs(Form("plots/R%i_solo_quartz_hit_pos.root",det));

    }
}