#include <iostream>
#include <TString.h>
#include <math.h>

void pes()
{
    std::ofstream analysis;
    analysis.open ("analyzed_files.dat");
    std::string str;
    TFile *file;
    file = TFile::Open("MOLLEROpt_0002.root");
    TH1D *hst, *tmp;

    //PE spectrum of the detector
    tmp = (TH1D*)file->Get("Ring_CathodeEventsDistrHist");
    hst = (TH1D*)tmp->Clone("pes");
    hst->SetTitle("Photoelectron Distribution");
    hst->GetXaxis()->SetTitle("Photoelectrons");
    hst->GetYaxis()->SetTitle("Events");
    hst->GetXaxis()->SetRangeUser(0,100);
    hst->SetDirectory(0);
    str = "plots/nofit_PEs.root";
    hst->SaveAs(str.data());
    analysis << str << "\n"; 
    file->Close("R");

    analysis.close();
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