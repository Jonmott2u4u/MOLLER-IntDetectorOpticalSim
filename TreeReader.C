// This script uses a TTreeReader to access data within MOLLEROptical's tree
// Thanks to Sudip Bhattarai for showing me how to use TTreeReaders. So easy
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include <iostream>
#include <cmath>

using namespace std;

void plot_r5_pes_vs_pos() {
    // Open ROOT file
    TFile *f = TFile::Open("rootfiles/cosmics.root");
    if (!f || f->IsZombie()) {
        cerr << "Error: Cannot open ROOT file!" << endl;
        return;
    }

    TTree *MOLLEROptTree = nullptr;
    f->GetObject("MOLLEROptTree", MOLLEROptTree);
    if (!MOLLEROptTree) {
        cerr << "Error: Cannot load MOLLEROptTree" << endl;
        return;
    }

    // Setup TTreeReader //
    //These readers are used to store the number of entries per position bin (w/ cuts included)
    TTreeReader reader_entries(MOLLEROptTree);
    TTreeReaderArray<float> R5TileHitX_ent(reader_entries, "MOLLERGeneralEvent.R5TileHitX");
    TTreeReaderArray<float> R5TileHitY_ent(reader_entries, "MOLLERGeneralEvent.R5TileHitY");
    TTreeReaderArray<int> Scint1TrackHit_ent(reader_entries, "MOLLERGeneralEvent.Scint1TrackHit");
    TTreeReaderArray<int> Scint2TrackHit_ent(reader_entries, "MOLLERGeneralEvent.Scint2TrackHit");
    TTreeReaderArray<int> R5AdjacentCutQuartzTrackHit_ent(reader_entries, "MOLLERGeneralEvent.R5AdjacentCutQuartzTrackHit");
    TTreeReaderArray<int> R5SoloCutQuartzTrackHit_ent(reader_entries, "MOLLERGeneralEvent.R5SoloCutQuartzTrackHit");
    //These readers are used for the "xy" histograms.
    TTreeReader reader_main(MOLLEROptTree);
    TTreeReaderArray<float> R5TileHitX(reader_main, "MOLLERGeneralEvent.R5TileHitX");
    TTreeReaderArray<float> R5TileHitY(reader_main, "MOLLERGeneralEvent.R5TileHitY");
    TTreeReaderArray<int> Scint1TrackHit(reader_main, "MOLLERGeneralEvent.Scint1TrackHit");
    TTreeReaderArray<int> Scint2TrackHit(reader_main, "MOLLERGeneralEvent.Scint2TrackHit");
    TTreeReaderArray<int> R5AdjacentCutQuartzTrackHit(reader_main, "MOLLERGeneralEvent.R5AdjacentCutQuartzTrackHit");
    TTreeReaderArray<int> R5SoloCutQuartzTrackHit(reader_main, "MOLLERGeneralEvent.R5SoloCutQuartzTrackHit");
    TTreeReaderArray<int> R5PEs(reader_main, "MOLLERGeneralEvent.R5PEs");

    // Prepare 2D histograms //
    //The "entry" plots store the number of hits per bin
    TH2F *h_entries = new TH2F("h_entries", "Entries per tile hit position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_entries_adj = new TH2F("h_entries", "Entries per tile hit position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_entries_solo = new TH2F("h_entries", "Entries per tile hit position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    //The "xy" plots store the average pe yield per bin
    TH2F *h_xy = new TH2F("h_xy", "R5TileHitY vs R5TileHitX w/ scint cut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_xy_adj = new TH2F("h_xy_adj", "R5TileHitY vs R5TileHitX w/ adjacency cut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_xy_solo = new TH2F("h_xy_solo", "R5TileHitY vs R5TileHitX w/ solocut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning

    Long64_t event_count = 0;

    //Set the shift so that (shift + the x/y start bin above) = 1
    float x_shift = 5, y_shift = -17;


    // Loop over entries
    while (reader_entries.Next()) {
        event_count++;

        //Loops over the events once to create the weight factor per bin. Weight factor is = events per bin
        for (size_t i = 0; i < R5TileHitX_ent.GetSize(); ++i) {
            int scint1 = Scint1TrackHit_ent[i];
            int scint2 = Scint2TrackHit_ent[i];
            int adj = R5AdjacentCutQuartzTrackHit_ent[i];
            int solo = R5SoloCutQuartzTrackHit_ent[i];
            if (scint1 && scint2) {
                float x = R5TileHitX_ent[i];
                float y = R5TileHitY_ent[i];
                h_entries->Fill(x, y, 1);
                if (adj) h_entries_adj->Fill(x, y, 1);
                if (solo) h_entries_solo->Fill(x, y, 1);
                // cout << x << " " << y << " " << PEweight << endl;
            }
        }
    }

    while (reader_main.Next()) {
        //Loops over the events again to find the average pe yield per bin. Uses the weight factor defined above (h_entries*)
        for (size_t i = 0; i < R5TileHitX.GetSize(); ++i) {
            int scint1 = Scint1TrackHit[i];
            int scint2 = Scint2TrackHit[i];
            int adj = R5AdjacentCutQuartzTrackHit[i];
            int solo = R5SoloCutQuartzTrackHit[i];
            if (scint1 && scint2) {
                float x = R5TileHitX[i];
                float y = R5TileHitY[i];
                int PE = R5PEs[i];
                float weight = 1./h_entries->GetBinContent(x+x_shift,y+y_shift);
                h_xy->Fill(x, y, PE*weight);
                //cout << "x: " << x << "      y: " << y << endl;
                //cout << "PEs: " << PE << "      weight: " << weight << "        BinContent: " << h_xy->GetBinContent(x+x_shift,y+y_shift) << endl;
                if (adj) h_xy_adj->Fill(x, y, PE/h_entries_adj->GetBinContent(x+x_shift,y+y_shift));
                if (solo) h_xy_solo->Fill(x, y, PE/h_entries_solo->GetBinContent(x+x_shift,y+y_shift));
                // cout << x << " " << y << " " << PEweight << endl;
            }
        }
    }

    cout << "Total processed events: " << event_count << endl;

    //Sets the z-axis range for the histograms. Edit as needed
    float min = h_xy->GetMinimum();
    float max = h_xy_solo->GetMaximum();

    // Draw and save histograms
    TCanvas *c1 = new TCanvas("c1", "R5 Tile Hit Map w/ scint cut", 900, 700);
    h_xy->Draw("COLZ");
    h_xy->GetZaxis()->SetRangeUser(min,max);
    c1->SaveAs("plots/ScintCut_R5TileHitXY_PE_heatmap.root");
    c1->SaveAs("plots/ScintCut_R5TileHitXY_PE_heatmap.png");
    c1->Close();

    TCanvas *c2 = new TCanvas("c2", "R5 Tile Hit Map w/ adjacency cut", 900, 700);
    h_xy_adj->Draw("COLZ");
    h_xy_adj->GetZaxis()->SetRangeUser(min,max);
    c2->SaveAs("plots/AdjCut_R5TileHitXY_PE_heatmap.root");
    c2->SaveAs("plots/AdjCut_R5TileHitXY_PE_heatmap.png");
    c2->Close();

    TCanvas *c3 = new TCanvas("c3", "R5 Tile Hit Map w/ solo cut", 900, 700);
    h_xy_solo->Draw("COLZ");
    h_xy_solo->GetZaxis()->SetRangeUser(min,max);
    c3->SaveAs("plots/SoloCut_R5TileHitXY_PE_heatmap.root");
    c3->SaveAs("plots/SoloCut_R5TileHitXY_PE_heatmap.png");
    c3->Close();
}

void pes_vs_angle() {

    // Open ROOT file
    TFile *f = TFile::Open("rootfiles/r6_cosmics.root");
    if (!f || f->IsZombie()) {
        cerr << "Error: Cannot open ROOT file!" << endl;
        return;
    }

    TTree *MOLLEROptTree = nullptr;
    f->GetObject("MOLLEROptTree", MOLLEROptTree);
    if (!MOLLEROptTree) {
        cerr << "Error: Cannot load MOLLEROptTree" << endl;
        return;
    }

    // Setup TTreeReader //
    //These readers are for the pe yield, angle of incidence, and muon energy
    TTreeReader reader_main(MOLLEROptTree);
    TTreeReaderArray<int> RingPEs(reader_main, "MOLLERGeneralEvent.RingPEs");
    TTreeReaderArray<float> InitialBeamAngle(reader_main, "MOLLERGeneralEvent.InitialBeamAngle");
    TTreeReaderArray<float> InitialBeamEnergy(reader_main, "MOLLERGeneralEvent.InitialBeamEnergy");
    //These readers are for the Gem hit positions
    TTreeReaderArray<float> Gem1HitX(reader_main, "MOLLERGeneralEvent.Gem1HitX");
    TTreeReaderArray<float> Gem1HitY(reader_main, "MOLLERGeneralEvent.Gem1HitY");
    TTreeReaderArray<float> Gem1HitZ(reader_main, "MOLLERGeneralEvent.Gem1HitZ");
    TTreeReaderArray<float> Gem3HitX(reader_main, "MOLLERGeneralEvent.Gem3HitX");
    TTreeReaderArray<float> Gem3HitY(reader_main, "MOLLERGeneralEvent.Gem3HitY");
    TTreeReaderArray<float> Gem3HitZ(reader_main, "MOLLERGeneralEvent.Gem3HitZ");

    //Defining angle for cuts
    double angle = 10.0; //Cuts are +- 0.1 about this value ----- or 1.0 degrees for Sayaks binning

    //Creating histograms for storing PE yield with cuts
    //TH1D *normal_pes = new TH1D("normal_pes", "R6 PE yield for normal incidence muons (+- 1 degree); PEs", 101, 0, 100);
    //TH1D *ThetaX_pes = new TH1D("ThetaX_pes", Form("R6 PE yield for ThetaX normal & ThetaY %.1f (+- 0.1 degree), E_muon > 300 MeV; PEs",angle), 101, 0, 100);
    //TH1D *ThetaY_pes = new TH1D("ThetaY_pes", Form("R6 PE yield for ThetaY normal & ThetaX %.1f (+- 0.1 degree), E_muon > 300 MeV; PEs",angle), 101, 0, 100);
    //TH1D *ThetaX_pes = new TH1D("ThetaX_pes", Form("R6 PE yield for ThetaX unrestrained & ThetaY %.1f (+- 0.1 degree), E_muon > 300 MeV; PEs",angle), 101, 0, 100);
    //TH1D *ThetaY_pes = new TH1D("ThetaY_pes", Form("R6 PE yield for ThetaY unrestrained & ThetaX %.1f (+- 0.1 degree), E_muon > 300 MeV; PEs",angle), 101, 0, 100);
    TH1D *ThetaX_pes = new TH1D("ThetaX_pes", Form("PE yield for ThetaX unrestrained & ThetaY %.1f (+- 1.0 degree), E_muon > 300 MeV; PEs",angle), 100, 0, 100);
    TH1D *ThetaY_pes = new TH1D("ThetaY_pes", Form("PE yield for ThetaY unrestrained & ThetaX %.1f (+- 1.0 degree), E_muon > 300 MeV; PEs",angle), 100, 0, 100);


    //Defining constants
    float pi = 3.14159265358979323846;

    while (reader_main.Next()) {
        //Loops over all entries that hit the final gem
        for (size_t i = 0; i < RingPEs.GetSize(); ++i) {
            int PE = RingPEs[i];
            float InitEnergy = InitialBeamEnergy[i];
            float AngleOfInc = InitialBeamAngle[i];
            float ThetaX = atan(abs(Gem3HitX[i] - Gem1HitX[i])/abs(Gem3HitZ[i] - Gem1HitZ[i]))*(180.0/pi);
            float ThetaY = atan(abs(Gem3HitY[i] - Gem1HitY[i])/abs(Gem3HitZ[i] - Gem1HitZ[i]))*(180.0/pi);
            //I do not remember why this is here. Did we want this?
                /*if (AngleOfInc <= 1) {
                    normal_pes->AddBinContent(PE);
                }*/
            //These 2 statements require thetaX/Y compenents be normal (one at a time)
            /*if ((ThetaX <= 1) && ((angle-0.1) <= ThetaY) && ((angle+0.1) >= ThetaY) && (InitEnergy > 0.3)) {
            ThetaX_pes->AddBinContent(PE);
            }
            if ((ThetaY <= 1) && ((angle-0.1) <= ThetaX) && ((angle+0.1) >= ThetaX) && (InitEnergy > 0.3)) {
                    ThetaY_pes->AddBinContent(PE);
                }*/
            //These 2 statements do not require thetaX/Y compenents be normal
            /*if (((angle-0.1) <= ThetaY) && ((angle+0.1) >= ThetaY) && (InitEnergy > 0.3)) {
                    ThetaX_pes->AddBinContent(PE);
            }
            if (((angle-0.1) <= ThetaX) && ((angle+0.1) >= ThetaX) && (InitEnergy > 0.3)) {
                ThetaY_pes->AddBinContent(PE);
            }*/
           //The following statements use Sayak's +-1 angle binning (and are unrestrained as well)
            if (((angle-1.0) <= ThetaY) && ((angle+1.0) >= ThetaY) && (InitEnergy > 0.3)) {
                    ThetaX_pes->AddBinContent(PE);
            }
            if (((angle-1.0) <= ThetaX) && ((angle+1.0) >= ThetaX) && (InitEnergy > 0.3)) {
                ThetaY_pes->AddBinContent(PE);
            }
        }
    }
    
    // Draw and save histograms
    //normal_pes->SaveAs(Form("plots/R6_normal_%.1f_deg.root",angle));
    //ThetaX_pes->SaveAs(Form("plots/300MeV_Greater_cut/R6_ThetaX_normal_ThetaY_%.1f_deg.root",angle)); //ThetaX plot has ThetaX held normal
    //ThetaY_pes->SaveAs(Form("plots/300MeV_Greater_cut/R6_ThetaY_normal_ThetaX_%.1f_deg.root",angle)); //ThetaY plot has ThetaY held normal
    ThetaX_pes->SaveAs(Form("plots/300MeV_Greater_cut/Sayaks_R6_ThetaX_unrestrained_ThetaY_%.1f_deg.root",angle));
    ThetaY_pes->SaveAs(Form("plots/300MeV_Greater_cut/Sayaks_R6_ThetaY_unrestrained_ThetaX_%.1f_deg.root",angle));

    TCanvas *c1 = new TCanvas("c1","Plots", 900, 700);
    c1->Divide(2);
    c1->cd(1);
    ThetaX_pes->Draw();
    c1->cd(2);
    ThetaY_pes->Draw();
    

}
