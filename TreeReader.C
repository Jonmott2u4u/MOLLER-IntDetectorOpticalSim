// This script uses a TTreeReader to access data within MOLLEROptical's tree
// Thanks to Sudip Bhattarai for showing me how to use TTreeReaders. So easy

#include "TFile.h"
#include "TH2.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include <iostream>

using namespace std;

void plot_r5_pes_vs_pos() {
    // Open ROOT file
    TFile *f = TFile::Open("MOLLEROpt_0002.root");
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

    // Setup TTreeReader
    TTreeReader reader(MOLLEROptTree);
    TTreeReaderArray<float> R5TileHitX(reader, "MOLLERGeneralEvent.R5TileHitX");
    TTreeReaderArray<float> R5TileHitY(reader, "MOLLERGeneralEvent.R5TileHitY");
    TTreeReaderArray<int> Scint1TrackHit(reader, "MOLLERGeneralEvent.Scint1TrackHit");
    TTreeReaderArray<int> Scint2TrackHit(reader, "MOLLERGeneralEvent.Scint2TrackHit");
    TTreeReaderArray<int> R5AdjacentCutQuartzTrackHit(reader, "MOLLERGeneralEvent.R5AdjacentCutQuartzTrackHit");
    TTreeReaderArray<int> R5SoloCutQuartzTrackHit(reader, "MOLLERGeneralEvent.R5SoloCutQuartzTrackHit");
    TTreeReaderArray<int> R5PEs(reader, "MOLLERGeneralEvent.R5PEs");

    // Prepare 2D histograms
    TH2F *h_xy = new TH2F("h_xy", "R5TileHitY vs R5TileHitX w/ scint cut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_xy_adjacent = new TH2F("h_xy_adjacent", "R5TileHitY vs R5TileHitX w/ adjacency cut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning
    TH2F *h_xy_solo = new TH2F("h_xy_solo", "R5TileHitY vs R5TileHitX w/ solocut;X position;Y position",
                        8, -4, 4,  // X-axis binning
                        16, 18, 34);   // Y-axis binning

    Long64_t event_count = 0;

    // Loop over entries
    while (reader.Next()) {
        event_count++;

        for (size_t i = 0; i < R5TileHitX.GetSize(); ++i) {
            int scint1 = Scint1TrackHit[i];
            int scint2 = Scint2TrackHit[i];
            int adj = R5AdjacentCutQuartzTrackHit[i];
            int solo = R5SoloCutQuartzTrackHit[i];
            if (scint1 && scint2) {
                float x = R5TileHitX[i];
                float y = R5TileHitY[i];
                int PEweight = R5PEs[i];
                h_xy->Fill(x, y, PEweight);
                if (adj) h_xy_adjacent->Fill(x, y, PEweight);
                if (solo) h_xy_solo->Fill(x, y, PEweight);
                // cout << x << " " << y << " " << PEweight << endl;
            }
        }
    }

    cout << "Total processed events: " << event_count << endl;

    // Draw and save histograms
    TCanvas *c1 = new TCanvas("c1", "R5 Tile Hit Map w/ scint cut", 900, 700);
    h_xy->Draw("COLZ");
    c1->SaveAs("plots/ScintCut_R5TileHitXY_PE_heatmap.root");
    c1->SaveAs("plots/ScintCut_R5TileHitXY_PE_heatmap.png");
    c1->Close();

    TCanvas *c2 = new TCanvas("c2", "R5 Tile Hit Map w/ adjacency cut", 900, 700);
    h_xy_adjacent->Draw("COLZ");
    c2->SaveAs("plots/AdjCut_R5TileHitXY_PE_heatmap.root");
    c2->SaveAs("plots/AdjCut_R5TileHitXY_PE_heatmap.png");
    c2->Close();

    TCanvas *c3 = new TCanvas("c3", "R5 Tile Hit Map w/ solo cut", 900, 700);
    h_xy_solo->Draw("COLZ");
    c3->SaveAs("plots/SoloCut_R5TileHitXY_PE_heatmap.root");
    c3->SaveAs("plots/SoloCut_R5TileHitXY_PE_heatmap.png");
    c3->Close();
}