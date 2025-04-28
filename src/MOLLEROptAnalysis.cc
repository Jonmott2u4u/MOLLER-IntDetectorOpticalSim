#include "MOLLEROptAnalysis.hh"

MOLLEROptAnalysis::MOLLEROptAnalysis()
{	
    // Initialize 

    MOLLERMainEvent    = NULL;
    MOLLEROptMainBranch   = NULL;

    MOLLEROptNtuple         = NULL;
    MOLLEROptFile           = NULL;
    NumberOfPrimaries     = new TVectorD(1);
    NumberOfPrimaries[0]  = 0;
    ROOTFileFlag = 1;
    ROOTFileName = "MOLLEROpt";

    PMTOptPhotonDistrHist = new TProfile("PMTOptPhotonDistrHist","",800,100,900);
    QuartzOptPhotonDistrHist = new TProfile("QuartzOptPhotonDistrHist","",800,100,900);
    LightGuideOptPhotonDistrHist = new TProfile("LightGuideOptPhotonDistrHist","",800,100,900);

    //--------BF segment histograms--------//
    R1_CathodeEventsDistrHist = new TH1D("R1_CathodeEventsDistrHist","",100,0,100);
    R2_CathodeEventsDistrHist = new TH1D("R2_CathodeEventsDistrHist","",100,0,100);
    R3_CathodeEventsDistrHist = new TH1D("R3_CathodeEventsDistrHist","",100,0,100);
    R4_CathodeEventsDistrHist = new TH1D("R4_CathodeEventsDistrHist","",100,0,100);
    R5_CathodeEventsDistrHist = new TH1D("R5_CathodeEventsDistrHist","",100,0,100);
    R6_CathodeEventsDistrHist = new TH1D("R6_CathodeEventsDistrHist","",100,0,100);
    R7_CathodeEventsDistrHist = new TH1D("R7_CathodeEventsDistrHist","",100,0,100);
    R8_CathodeEventsDistrHist = new TH1D("R8_CathodeEventsDistrHist","",100,0,100);
    R1Only_CathodeEventsDistrHist = new TH1D("R1Only_CathodeEventsDistrHist","",100,0,100);
    R2Only_CathodeEventsDistrHist = new TH1D("R2Only_CathodeEventsDistrHist","",100,0,100);
    R3Only_CathodeEventsDistrHist = new TH1D("R3Only_CathodeEventsDistrHist","",100,0,100);
    R4Only_CathodeEventsDistrHist = new TH1D("R4Only_CathodeEventsDistrHist","",100,0,100);
    R5Only_CathodeEventsDistrHist = new TH1D("R5Only_CathodeEventsDistrHist","",100,0,100);
    R6Only_CathodeEventsDistrHist = new TH1D("R6Only_CathodeEventsDistrHist","",100,0,100);
    R7Only_CathodeEventsDistrHist = new TH1D("R7Only_CathodeEventsDistrHist","",100,0,100);
    R8Only_CathodeEventsDistrHist = new TH1D("R8Only_CathodeEventsDistrHist","",100,0,100);
    R1Adjacent_CathodeEventsDistrHist = new TH1D("R1Adjacent_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_CathodeEventsDistrHist = new TH1D("R2Adjacent_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_CathodeEventsDistrHist = new TH1D("R3Adjacent_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_CathodeEventsDistrHist = new TH1D("R4Adjacent_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_CathodeEventsDistrHist = new TH1D("R5Adjacent_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_CathodeEventsDistrHist = new TH1D("R6Adjacent_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_CathodeEventsDistrHist = new TH1D("R7Adjacent_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_CathodeEventsDistrHist = new TH1D("R8Adjacent_CathodeEventsDistrHist","",100,0,100);

    //These histograms are specific to each scintillator combination
    R1_Scint13_CathodeEventsDistrHist = new TH1D("R1_Scint13_CathodeEventsDistrHist","",100,0,100);
    R2_Scint13_CathodeEventsDistrHist = new TH1D("R2_Scint13_CathodeEventsDistrHist","",100,0,100);
    R3_Scint13_CathodeEventsDistrHist = new TH1D("R3_Scint13_CathodeEventsDistrHist","",100,0,100);
    R4_Scint13_CathodeEventsDistrHist = new TH1D("R4_Scint13_CathodeEventsDistrHist","",100,0,100);
    R5_Scint13_CathodeEventsDistrHist = new TH1D("R5_Scint13_CathodeEventsDistrHist","",100,0,100);
    R6_Scint13_CathodeEventsDistrHist = new TH1D("R6_Scint13_CathodeEventsDistrHist","",100,0,100);
    R7_Scint13_CathodeEventsDistrHist = new TH1D("R7_Scint13_CathodeEventsDistrHist","",100,0,100);
    R8_Scint13_CathodeEventsDistrHist = new TH1D("R8_Scint13_CathodeEventsDistrHist","",100,0,100);
    R1Only_Scint13_CathodeEventsDistrHist = new TH1D("R1Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R2Only_Scint13_CathodeEventsDistrHist = new TH1D("R2Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R3Only_Scint13_CathodeEventsDistrHist = new TH1D("R3Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R4Only_Scint13_CathodeEventsDistrHist = new TH1D("R4Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R5Only_Scint13_CathodeEventsDistrHist = new TH1D("R5Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R6Only_Scint13_CathodeEventsDistrHist = new TH1D("R6Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R7Only_Scint13_CathodeEventsDistrHist = new TH1D("R7Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R8Only_Scint13_CathodeEventsDistrHist = new TH1D("R8Only_Scint13_CathodeEventsDistrHist","",100,0,100);
    R1Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R1Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R2Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R3Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R4Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R5Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R6Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R7Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_Scint13_CathodeEventsDistrHist = new TH1D("R8Adjacent_Scint13_CathodeEventsDistrHist","",100,0,100);

    R1_Scint14_CathodeEventsDistrHist = new TH1D("R1_Scint14_CathodeEventsDistrHist","",100,0,100);
    R2_Scint14_CathodeEventsDistrHist = new TH1D("R2_Scint14_CathodeEventsDistrHist","",100,0,100);
    R3_Scint14_CathodeEventsDistrHist = new TH1D("R3_Scint14_CathodeEventsDistrHist","",100,0,100);
    R4_Scint14_CathodeEventsDistrHist = new TH1D("R4_Scint14_CathodeEventsDistrHist","",100,0,100);
    R5_Scint14_CathodeEventsDistrHist = new TH1D("R5_Scint14_CathodeEventsDistrHist","",100,0,100);
    R6_Scint14_CathodeEventsDistrHist = new TH1D("R6_Scint14_CathodeEventsDistrHist","",100,0,100);
    R7_Scint14_CathodeEventsDistrHist = new TH1D("R7_Scint14_CathodeEventsDistrHist","",100,0,100);
    R8_Scint14_CathodeEventsDistrHist = new TH1D("R8_Scint14_CathodeEventsDistrHist","",100,0,100);
    R1Only_Scint14_CathodeEventsDistrHist = new TH1D("R1Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R2Only_Scint14_CathodeEventsDistrHist = new TH1D("R2Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R3Only_Scint14_CathodeEventsDistrHist = new TH1D("R3Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R4Only_Scint14_CathodeEventsDistrHist = new TH1D("R4Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R5Only_Scint14_CathodeEventsDistrHist = new TH1D("R5Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R6Only_Scint14_CathodeEventsDistrHist = new TH1D("R6Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R7Only_Scint14_CathodeEventsDistrHist = new TH1D("R7Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R8Only_Scint14_CathodeEventsDistrHist = new TH1D("R8Only_Scint14_CathodeEventsDistrHist","",100,0,100);
    R1Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R1Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R2Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R3Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R4Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R5Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R6Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R7Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_Scint14_CathodeEventsDistrHist = new TH1D("R8Adjacent_Scint14_CathodeEventsDistrHist","",100,0,100);

    R1_Scint23_CathodeEventsDistrHist = new TH1D("R1_Scint23_CathodeEventsDistrHist","",100,0,100);
    R2_Scint23_CathodeEventsDistrHist = new TH1D("R2_Scint23_CathodeEventsDistrHist","",100,0,100);
    R3_Scint23_CathodeEventsDistrHist = new TH1D("R3_Scint23_CathodeEventsDistrHist","",100,0,100);
    R4_Scint23_CathodeEventsDistrHist = new TH1D("R4_Scint23_CathodeEventsDistrHist","",100,0,100);
    R5_Scint23_CathodeEventsDistrHist = new TH1D("R5_Scint23_CathodeEventsDistrHist","",100,0,100);
    R6_Scint23_CathodeEventsDistrHist = new TH1D("R6_Scint23_CathodeEventsDistrHist","",100,0,100);
    R7_Scint23_CathodeEventsDistrHist = new TH1D("R7_Scint23_CathodeEventsDistrHist","",100,0,100);
    R8_Scint23_CathodeEventsDistrHist = new TH1D("R8_Scint23_CathodeEventsDistrHist","",100,0,100);
    R1Only_Scint23_CathodeEventsDistrHist = new TH1D("R1Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R2Only_Scint23_CathodeEventsDistrHist = new TH1D("R2Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R3Only_Scint23_CathodeEventsDistrHist = new TH1D("R3Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R4Only_Scint23_CathodeEventsDistrHist = new TH1D("R4Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R5Only_Scint23_CathodeEventsDistrHist = new TH1D("R5Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R6Only_Scint23_CathodeEventsDistrHist = new TH1D("R6Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R7Only_Scint23_CathodeEventsDistrHist = new TH1D("R7Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R8Only_Scint23_CathodeEventsDistrHist = new TH1D("R8Only_Scint23_CathodeEventsDistrHist","",100,0,100);
    R1Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R1Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R2Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R3Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R4Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R5Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R6Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R7Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_Scint23_CathodeEventsDistrHist = new TH1D("R8Adjacent_Scint23_CathodeEventsDistrHist","",100,0,100);

    R1_Scint24_CathodeEventsDistrHist = new TH1D("R1_Scint24_CathodeEventsDistrHist","",100,0,100);
    R2_Scint24_CathodeEventsDistrHist = new TH1D("R2_Scint24_CathodeEventsDistrHist","",100,0,100);
    R3_Scint24_CathodeEventsDistrHist = new TH1D("R3_Scint24_CathodeEventsDistrHist","",100,0,100);
    R4_Scint24_CathodeEventsDistrHist = new TH1D("R4_Scint24_CathodeEventsDistrHist","",100,0,100);
    R5_Scint24_CathodeEventsDistrHist = new TH1D("R5_Scint24_CathodeEventsDistrHist","",100,0,100);
    R6_Scint24_CathodeEventsDistrHist = new TH1D("R6_Scint24_CathodeEventsDistrHist","",100,0,100);
    R7_Scint24_CathodeEventsDistrHist = new TH1D("R7_Scint24_CathodeEventsDistrHist","",100,0,100);
    R8_Scint24_CathodeEventsDistrHist = new TH1D("R8_Scint24_CathodeEventsDistrHist","",100,0,100);
    R1Only_Scint24_CathodeEventsDistrHist = new TH1D("R1Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R2Only_Scint24_CathodeEventsDistrHist = new TH1D("R2Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R3Only_Scint24_CathodeEventsDistrHist = new TH1D("R3Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R4Only_Scint24_CathodeEventsDistrHist = new TH1D("R4Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R5Only_Scint24_CathodeEventsDistrHist = new TH1D("R5Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R6Only_Scint24_CathodeEventsDistrHist = new TH1D("R6Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R7Only_Scint24_CathodeEventsDistrHist = new TH1D("R7Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R8Only_Scint24_CathodeEventsDistrHist = new TH1D("R8Only_Scint24_CathodeEventsDistrHist","",100,0,100);
    R1Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R1Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R2Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R2Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R3Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R3Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R4Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R4Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R5Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R5Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R6Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R6Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R7Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R7Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);
    R8Adjacent_Scint24_CathodeEventsDistrHist = new TH1D("R8Adjacent_Scint24_CathodeEventsDistrHist","",100,0,100);

    //--------FF segment histograms--------//
    R9_CathodeEventsDistrHist = new TH1D("R9_CathodeEventsDistrHist","",100,0,100);
    R10_CathodeEventsDistrHist = new TH1D("R10_CathodeEventsDistrHist","",100,0,100);
    R11_CathodeEventsDistrHist = new TH1D("R11_CathodeEventsDistrHist","",100,0,100);
    R12_CathodeEventsDistrHist = new TH1D("R12_CathodeEventsDistrHist","",100,0,100);
    R13_CathodeEventsDistrHist = new TH1D("R13_CathodeEventsDistrHist","",100,0,100);
    R14_CathodeEventsDistrHist = new TH1D("R14_CathodeEventsDistrHist","",100,0,100);
    R15_CathodeEventsDistrHist = new TH1D("R15_CathodeEventsDistrHist","",100,0,100);
    R16_CathodeEventsDistrHist = new TH1D("R16_CathodeEventsDistrHist","",100,0,100);
    R9Only_CathodeEventsDistrHist = new TH1D("R9Only_CathodeEventsDistrHist","",100,0,100);
    R10Only_CathodeEventsDistrHist = new TH1D("R10Only_CathodeEventsDistrHist","",100,0,100);
    R11Only_CathodeEventsDistrHist = new TH1D("R11Only_CathodeEventsDistrHist","",100,0,100);
    R12Only_CathodeEventsDistrHist = new TH1D("R12Only_CathodeEventsDistrHist","",100,0,100);
    R13Only_CathodeEventsDistrHist = new TH1D("R13Only_CathodeEventsDistrHist","",100,0,100);
    R14Only_CathodeEventsDistrHist = new TH1D("R14Only_CathodeEventsDistrHist","",100,0,100);
    R15Only_CathodeEventsDistrHist = new TH1D("R15Only_CathodeEventsDistrHist","",100,0,100);
    R16Only_CathodeEventsDistrHist = new TH1D("R16Only_CathodeEventsDistrHist","",100,0,100);
    R9Adjacent_CathodeEventsDistrHist = new TH1D("R9Adjacent_CathodeEventsDistrHist","",100,0,100);
    R10Adjacent_CathodeEventsDistrHist = new TH1D("R10Adjacent_CathodeEventsDistrHist","",100,0,100);
    R11Adjacent_CathodeEventsDistrHist = new TH1D("R11Adjacent_CathodeEventsDistrHist","",100,0,100);
    R12Adjacent_CathodeEventsDistrHist = new TH1D("R12Adjacent_CathodeEventsDistrHist","",100,0,100);
    R13Adjacent_CathodeEventsDistrHist = new TH1D("R13Adjacent_CathodeEventsDistrHist","",100,0,100);
    R14Adjacent_CathodeEventsDistrHist = new TH1D("R14Adjacent_CathodeEventsDistrHist","",100,0,100);
    R15Adjacent_CathodeEventsDistrHist = new TH1D("R15Adjacent_CathodeEventsDistrHist","",100,0,100);
    R16Adjacent_CathodeEventsDistrHist = new TH1D("R16Adjacent_CathodeEventsDistrHist","",100,0,100);

    //These histograms are specific to each scintillator combination
    R9_Scint57_CathodeEventsDistrHist = new TH1D("R9_Scint57_CathodeEventsDistrHist","",100,0,100);
    R10_Scint57_CathodeEventsDistrHist = new TH1D("R10_Scint57_CathodeEventsDistrHist","",100,0,100);
    R11_Scint57_CathodeEventsDistrHist = new TH1D("R11_Scint57_CathodeEventsDistrHist","",100,0,100);
    R12_Scint57_CathodeEventsDistrHist = new TH1D("R12_Scint57_CathodeEventsDistrHist","",100,0,100);
    R13_Scint57_CathodeEventsDistrHist = new TH1D("R13_Scint57_CathodeEventsDistrHist","",100,0,100);
    R14_Scint57_CathodeEventsDistrHist = new TH1D("R14_Scint57_CathodeEventsDistrHist","",100,0,100);
    R15_Scint57_CathodeEventsDistrHist = new TH1D("R15_Scint57_CathodeEventsDistrHist","",100,0,100);
    R16_Scint57_CathodeEventsDistrHist = new TH1D("R16_Scint57_CathodeEventsDistrHist","",100,0,100);
    R9Only_Scint57_CathodeEventsDistrHist = new TH1D("R9Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R10Only_Scint57_CathodeEventsDistrHist = new TH1D("R10Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R11Only_Scint57_CathodeEventsDistrHist = new TH1D("R11Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R12Only_Scint57_CathodeEventsDistrHist = new TH1D("R12Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R13Only_Scint57_CathodeEventsDistrHist = new TH1D("R13Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R14Only_Scint57_CathodeEventsDistrHist = new TH1D("R14Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R15Only_Scint57_CathodeEventsDistrHist = new TH1D("R15Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R16Only_Scint57_CathodeEventsDistrHist = new TH1D("R16Only_Scint57_CathodeEventsDistrHist","",100,0,100);
    R9Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R9Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R10Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R10Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R11Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R11Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R12Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R12Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R13Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R13Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R14Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R14Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R15Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R15Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);
    R16Adjacent_Scint57_CathodeEventsDistrHist = new TH1D("R16Adjacent_Scint57_CathodeEventsDistrHist","",100,0,100);

    R9_Scint58_CathodeEventsDistrHist = new TH1D("R9_Scint58_CathodeEventsDistrHist","",100,0,100);
    R10_Scint58_CathodeEventsDistrHist = new TH1D("R10_Scint58_CathodeEventsDistrHist","",100,0,100);
    R11_Scint58_CathodeEventsDistrHist = new TH1D("R11_Scint58_CathodeEventsDistrHist","",100,0,100);
    R12_Scint58_CathodeEventsDistrHist = new TH1D("R12_Scint58_CathodeEventsDistrHist","",100,0,100);
    R13_Scint58_CathodeEventsDistrHist = new TH1D("R13_Scint58_CathodeEventsDistrHist","",100,0,100);
    R14_Scint58_CathodeEventsDistrHist = new TH1D("R14_Scint58_CathodeEventsDistrHist","",100,0,100);
    R15_Scint58_CathodeEventsDistrHist = new TH1D("R15_Scint58_CathodeEventsDistrHist","",100,0,100);
    R16_Scint58_CathodeEventsDistrHist = new TH1D("R16_Scint58_CathodeEventsDistrHist","",100,0,100);
    R9Only_Scint58_CathodeEventsDistrHist = new TH1D("R9Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R10Only_Scint58_CathodeEventsDistrHist = new TH1D("R10Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R11Only_Scint58_CathodeEventsDistrHist = new TH1D("R11Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R12Only_Scint58_CathodeEventsDistrHist = new TH1D("R12Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R13Only_Scint58_CathodeEventsDistrHist = new TH1D("R13Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R14Only_Scint58_CathodeEventsDistrHist = new TH1D("R14Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R15Only_Scint58_CathodeEventsDistrHist = new TH1D("R15Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R16Only_Scint58_CathodeEventsDistrHist = new TH1D("R16Only_Scint58_CathodeEventsDistrHist","",100,0,100);
    R9Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R9Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R10Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R10Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R11Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R11Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R12Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R12Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R13Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R13Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R14Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R14Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R15Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R15Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);
    R16Adjacent_Scint58_CathodeEventsDistrHist = new TH1D("R16Adjacent_Scint58_CathodeEventsDistrHist","",100,0,100);

    R9_Scint67_CathodeEventsDistrHist = new TH1D("R9_Scint67_CathodeEventsDistrHist","",100,0,100);
    R10_Scint67_CathodeEventsDistrHist = new TH1D("R10_Scint67_CathodeEventsDistrHist","",100,0,100);
    R11_Scint67_CathodeEventsDistrHist = new TH1D("R11_Scint67_CathodeEventsDistrHist","",100,0,100);
    R12_Scint67_CathodeEventsDistrHist = new TH1D("R12_Scint67_CathodeEventsDistrHist","",100,0,100);
    R13_Scint67_CathodeEventsDistrHist = new TH1D("R13_Scint67_CathodeEventsDistrHist","",100,0,100);
    R14_Scint67_CathodeEventsDistrHist = new TH1D("R14_Scint67_CathodeEventsDistrHist","",100,0,100);
    R15_Scint67_CathodeEventsDistrHist = new TH1D("R15_Scint67_CathodeEventsDistrHist","",100,0,100);
    R16_Scint67_CathodeEventsDistrHist = new TH1D("R16_Scint67_CathodeEventsDistrHist","",100,0,100);
    R9Only_Scint67_CathodeEventsDistrHist = new TH1D("R9Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R10Only_Scint67_CathodeEventsDistrHist = new TH1D("R10Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R11Only_Scint67_CathodeEventsDistrHist = new TH1D("R11Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R12Only_Scint67_CathodeEventsDistrHist = new TH1D("R12Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R13Only_Scint67_CathodeEventsDistrHist = new TH1D("R13Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R14Only_Scint67_CathodeEventsDistrHist = new TH1D("R14Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R15Only_Scint67_CathodeEventsDistrHist = new TH1D("R15Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R16Only_Scint67_CathodeEventsDistrHist = new TH1D("R16Only_Scint67_CathodeEventsDistrHist","",100,0,100);
    R9Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R9Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R10Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R10Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R11Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R11Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R12Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R12Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R13Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R13Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R14Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R14Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R15Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R15Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);
    R16Adjacent_Scint67_CathodeEventsDistrHist = new TH1D("R16Adjacent_Scint67_CathodeEventsDistrHist","",100,0,100);

    R9_Scint68_CathodeEventsDistrHist = new TH1D("R9_Scint68_CathodeEventsDistrHist","",100,0,100);
    R10_Scint68_CathodeEventsDistrHist = new TH1D("R10_Scint68_CathodeEventsDistrHist","",100,0,100);
    R11_Scint68_CathodeEventsDistrHist = new TH1D("R11_Scint68_CathodeEventsDistrHist","",100,0,100);
    R12_Scint68_CathodeEventsDistrHist = new TH1D("R12_Scint68_CathodeEventsDistrHist","",100,0,100);
    R13_Scint68_CathodeEventsDistrHist = new TH1D("R13_Scint68_CathodeEventsDistrHist","",100,0,100);
    R14_Scint68_CathodeEventsDistrHist = new TH1D("R14_Scint68_CathodeEventsDistrHist","",100,0,100);
    R15_Scint68_CathodeEventsDistrHist = new TH1D("R15_Scint68_CathodeEventsDistrHist","",100,0,100);
    R16_Scint68_CathodeEventsDistrHist = new TH1D("R16_Scint68_CathodeEventsDistrHist","",100,0,100);
    R9Only_Scint68_CathodeEventsDistrHist = new TH1D("R9Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R10Only_Scint68_CathodeEventsDistrHist = new TH1D("R10Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R11Only_Scint68_CathodeEventsDistrHist = new TH1D("R11Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R12Only_Scint68_CathodeEventsDistrHist = new TH1D("R12Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R13Only_Scint68_CathodeEventsDistrHist = new TH1D("R13Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R14Only_Scint68_CathodeEventsDistrHist = new TH1D("R14Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R15Only_Scint68_CathodeEventsDistrHist = new TH1D("R15Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R16Only_Scint68_CathodeEventsDistrHist = new TH1D("R16Only_Scint68_CathodeEventsDistrHist","",100,0,100);
    R9Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R9Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R10Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R10Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R11Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R11Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R12Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R12Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R13Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R13Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R14Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R14Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R15Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R15Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    R16Adjacent_Scint68_CathodeEventsDistrHist = new TH1D("R16Adjacent_Scint68_CathodeEventsDistrHist","",100,0,100);
    
    EventCnt = 0;
}

MOLLEROptAnalysis::~MOLLEROptAnalysis() 
{
  Finish();
  delete[] NumberOfPrimaries;
}

void MOLLEROptAnalysis::Init()
{;}


void MOLLEROptAnalysis::Finish()
{
  if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLEROptMainBranch)     delete MOLLEROptMainBranch;
  if (MOLLEROptNtuple)         {MOLLEROptNtuple->Delete();}
  if (MOLLEROptFile)           delete MOLLEROptFile;
}   

void MOLLEROptAnalysis::BeginOfRun(G4int runID, G4String name1, MOLLEROptTrackingReadout *TrRO) 
{   

  if(ROOTFileFlag){

    MOLLEROptFile = new TFile(Form("%s_%04d.root",name1.c_str(),runID),"RECREATE","MOLLEROpt ROOT file");
  }
  TrackingReadout = TrRO;
    
  ConstructRootNtuple();
}

void MOLLEROptAnalysis::EndOfRun() 
{
  if(ROOTFileFlag){
    NumberOfPrimaries->Write("NumberOfPrimaries");
    //FillOptPhotonDistrHist();
    PMTOptPhotonDistrHist->Write();
    QuartzOptPhotonDistrHist->Write();
    LightGuideOptPhotonDistrHist->Write();

    //--------BF segment histograms--------//
    R1_CathodeEventsDistrHist->Write();
    R2_CathodeEventsDistrHist->Write();
    R3_CathodeEventsDistrHist->Write();
    R4_CathodeEventsDistrHist->Write();
    R5_CathodeEventsDistrHist->Write();
    R6_CathodeEventsDistrHist->Write();
    R7_CathodeEventsDistrHist->Write();
    R8_CathodeEventsDistrHist->Write();
    R1Only_CathodeEventsDistrHist->Write();
    R2Only_CathodeEventsDistrHist->Write();
    R3Only_CathodeEventsDistrHist->Write();
    R4Only_CathodeEventsDistrHist->Write();
    R5Only_CathodeEventsDistrHist->Write();
    R6Only_CathodeEventsDistrHist->Write();
    R7Only_CathodeEventsDistrHist->Write();
    R8Only_CathodeEventsDistrHist->Write();
    R1Adjacent_CathodeEventsDistrHist->Write();
    R2Adjacent_CathodeEventsDistrHist->Write();
    R3Adjacent_CathodeEventsDistrHist->Write();
    R4Adjacent_CathodeEventsDistrHist->Write();
    R5Adjacent_CathodeEventsDistrHist->Write();
    R6Adjacent_CathodeEventsDistrHist->Write();
    R7Adjacent_CathodeEventsDistrHist->Write();
    R8Adjacent_CathodeEventsDistrHist->Write();

    R1_Scint13_CathodeEventsDistrHist->Write();
    R2_Scint13_CathodeEventsDistrHist->Write();
    R3_Scint13_CathodeEventsDistrHist->Write();
    R4_Scint13_CathodeEventsDistrHist->Write();
    R5_Scint13_CathodeEventsDistrHist->Write();
    R6_Scint13_CathodeEventsDistrHist->Write();
    R7_Scint13_CathodeEventsDistrHist->Write();
    R8_Scint13_CathodeEventsDistrHist->Write();
    R1Only_Scint13_CathodeEventsDistrHist->Write();
    R2Only_Scint13_CathodeEventsDistrHist->Write();
    R3Only_Scint13_CathodeEventsDistrHist->Write();
    R4Only_Scint13_CathodeEventsDistrHist->Write();
    R5Only_Scint13_CathodeEventsDistrHist->Write();
    R6Only_Scint13_CathodeEventsDistrHist->Write();
    R7Only_Scint13_CathodeEventsDistrHist->Write();
    R8Only_Scint13_CathodeEventsDistrHist->Write();
    R1Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R2Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R3Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R4Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R5Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R6Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R7Adjacent_Scint13_CathodeEventsDistrHist->Write();
    R8Adjacent_Scint13_CathodeEventsDistrHist->Write();

    R1_Scint14_CathodeEventsDistrHist->Write();
    R2_Scint14_CathodeEventsDistrHist->Write();
    R3_Scint14_CathodeEventsDistrHist->Write();
    R4_Scint14_CathodeEventsDistrHist->Write();
    R5_Scint14_CathodeEventsDistrHist->Write();
    R6_Scint14_CathodeEventsDistrHist->Write();
    R7_Scint14_CathodeEventsDistrHist->Write();
    R8_Scint14_CathodeEventsDistrHist->Write();
    R1Only_Scint14_CathodeEventsDistrHist->Write();
    R2Only_Scint14_CathodeEventsDistrHist->Write();
    R3Only_Scint14_CathodeEventsDistrHist->Write();
    R4Only_Scint14_CathodeEventsDistrHist->Write();
    R5Only_Scint14_CathodeEventsDistrHist->Write();
    R6Only_Scint14_CathodeEventsDistrHist->Write();
    R7Only_Scint14_CathodeEventsDistrHist->Write();
    R8Only_Scint14_CathodeEventsDistrHist->Write();
    R1Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R2Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R3Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R4Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R5Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R6Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R7Adjacent_Scint14_CathodeEventsDistrHist->Write();
    R8Adjacent_Scint14_CathodeEventsDistrHist->Write();

    R1_Scint23_CathodeEventsDistrHist->Write();
    R2_Scint23_CathodeEventsDistrHist->Write();
    R3_Scint23_CathodeEventsDistrHist->Write();
    R4_Scint23_CathodeEventsDistrHist->Write();
    R5_Scint23_CathodeEventsDistrHist->Write();
    R6_Scint23_CathodeEventsDistrHist->Write();
    R7_Scint23_CathodeEventsDistrHist->Write();
    R8_Scint23_CathodeEventsDistrHist->Write();
    R1Only_Scint23_CathodeEventsDistrHist->Write();
    R2Only_Scint23_CathodeEventsDistrHist->Write();
    R3Only_Scint23_CathodeEventsDistrHist->Write();
    R4Only_Scint23_CathodeEventsDistrHist->Write();
    R5Only_Scint23_CathodeEventsDistrHist->Write();
    R6Only_Scint23_CathodeEventsDistrHist->Write();
    R7Only_Scint23_CathodeEventsDistrHist->Write();
    R8Only_Scint23_CathodeEventsDistrHist->Write();
    R1Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R2Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R3Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R4Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R5Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R6Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R7Adjacent_Scint23_CathodeEventsDistrHist->Write();
    R8Adjacent_Scint23_CathodeEventsDistrHist->Write();

    R1_Scint24_CathodeEventsDistrHist->Write();
    R2_Scint24_CathodeEventsDistrHist->Write();
    R3_Scint24_CathodeEventsDistrHist->Write();
    R4_Scint24_CathodeEventsDistrHist->Write();
    R5_Scint24_CathodeEventsDistrHist->Write();
    R6_Scint24_CathodeEventsDistrHist->Write();
    R7_Scint24_CathodeEventsDistrHist->Write();
    R8_Scint24_CathodeEventsDistrHist->Write();
    R1Only_Scint24_CathodeEventsDistrHist->Write();
    R2Only_Scint24_CathodeEventsDistrHist->Write();
    R3Only_Scint24_CathodeEventsDistrHist->Write();
    R4Only_Scint24_CathodeEventsDistrHist->Write();
    R5Only_Scint24_CathodeEventsDistrHist->Write();
    R6Only_Scint24_CathodeEventsDistrHist->Write();
    R7Only_Scint24_CathodeEventsDistrHist->Write();
    R8Only_Scint24_CathodeEventsDistrHist->Write();
    R1Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R2Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R3Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R4Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R5Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R6Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R7Adjacent_Scint24_CathodeEventsDistrHist->Write();
    R8Adjacent_Scint24_CathodeEventsDistrHist->Write();

    //--------BF segment histograms--------//
    R9_CathodeEventsDistrHist->Write();
    R10_CathodeEventsDistrHist->Write();
    R11_CathodeEventsDistrHist->Write();
    R12_CathodeEventsDistrHist->Write();
    R13_CathodeEventsDistrHist->Write();
    R14_CathodeEventsDistrHist->Write();
    R15_CathodeEventsDistrHist->Write();
    R16_CathodeEventsDistrHist->Write();
    R9Only_CathodeEventsDistrHist->Write();
    R10Only_CathodeEventsDistrHist->Write();
    R11Only_CathodeEventsDistrHist->Write();
    R12Only_CathodeEventsDistrHist->Write();
    R13Only_CathodeEventsDistrHist->Write();
    R14Only_CathodeEventsDistrHist->Write();
    R15Only_CathodeEventsDistrHist->Write();
    R16Only_CathodeEventsDistrHist->Write();
    R9Adjacent_CathodeEventsDistrHist->Write();
    R10Adjacent_CathodeEventsDistrHist->Write();
    R11Adjacent_CathodeEventsDistrHist->Write();
    R12Adjacent_CathodeEventsDistrHist->Write();
    R13Adjacent_CathodeEventsDistrHist->Write();
    R14Adjacent_CathodeEventsDistrHist->Write();
    R15Adjacent_CathodeEventsDistrHist->Write();
    R16Adjacent_CathodeEventsDistrHist->Write();
    
    R9_Scint57_CathodeEventsDistrHist->Write();
    R10_Scint57_CathodeEventsDistrHist->Write();
    R11_Scint57_CathodeEventsDistrHist->Write();
    R12_Scint57_CathodeEventsDistrHist->Write();
    R13_Scint57_CathodeEventsDistrHist->Write();
    R14_Scint57_CathodeEventsDistrHist->Write();
    R15_Scint57_CathodeEventsDistrHist->Write();
    R16_Scint57_CathodeEventsDistrHist->Write();
    R9Only_Scint57_CathodeEventsDistrHist->Write();
    R10Only_Scint57_CathodeEventsDistrHist->Write();
    R11Only_Scint57_CathodeEventsDistrHist->Write();
    R12Only_Scint57_CathodeEventsDistrHist->Write();
    R13Only_Scint57_CathodeEventsDistrHist->Write();
    R14Only_Scint57_CathodeEventsDistrHist->Write();
    R15Only_Scint57_CathodeEventsDistrHist->Write();
    R16Only_Scint57_CathodeEventsDistrHist->Write();
    R9Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R10Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R11Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R12Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R13Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R14Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R15Adjacent_Scint57_CathodeEventsDistrHist->Write();
    R16Adjacent_Scint57_CathodeEventsDistrHist->Write();

    R9_Scint58_CathodeEventsDistrHist->Write();
    R10_Scint58_CathodeEventsDistrHist->Write();
    R11_Scint58_CathodeEventsDistrHist->Write();
    R12_Scint58_CathodeEventsDistrHist->Write();
    R13_Scint58_CathodeEventsDistrHist->Write();
    R14_Scint58_CathodeEventsDistrHist->Write();
    R15_Scint58_CathodeEventsDistrHist->Write();
    R16_Scint58_CathodeEventsDistrHist->Write();
    R9Only_Scint58_CathodeEventsDistrHist->Write();
    R10Only_Scint58_CathodeEventsDistrHist->Write();
    R11Only_Scint58_CathodeEventsDistrHist->Write();
    R12Only_Scint58_CathodeEventsDistrHist->Write();
    R13Only_Scint58_CathodeEventsDistrHist->Write();
    R14Only_Scint58_CathodeEventsDistrHist->Write();
    R15Only_Scint58_CathodeEventsDistrHist->Write();
    R16Only_Scint58_CathodeEventsDistrHist->Write();
    R9Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R10Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R11Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R12Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R13Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R14Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R15Adjacent_Scint58_CathodeEventsDistrHist->Write();
    R16Adjacent_Scint58_CathodeEventsDistrHist->Write();

    R9_Scint67_CathodeEventsDistrHist->Write();
    R10_Scint67_CathodeEventsDistrHist->Write();
    R11_Scint67_CathodeEventsDistrHist->Write();
    R12_Scint67_CathodeEventsDistrHist->Write();
    R13_Scint67_CathodeEventsDistrHist->Write();
    R14_Scint67_CathodeEventsDistrHist->Write();
    R15_Scint67_CathodeEventsDistrHist->Write();
    R16_Scint67_CathodeEventsDistrHist->Write();
    R9Only_Scint67_CathodeEventsDistrHist->Write();
    R10Only_Scint67_CathodeEventsDistrHist->Write();
    R11Only_Scint67_CathodeEventsDistrHist->Write();
    R12Only_Scint67_CathodeEventsDistrHist->Write();
    R13Only_Scint67_CathodeEventsDistrHist->Write();
    R14Only_Scint67_CathodeEventsDistrHist->Write();
    R15Only_Scint67_CathodeEventsDistrHist->Write();
    R16Only_Scint67_CathodeEventsDistrHist->Write();
    R9Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R10Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R11Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R12Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R13Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R14Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R15Adjacent_Scint67_CathodeEventsDistrHist->Write();
    R16Adjacent_Scint67_CathodeEventsDistrHist->Write();

    R9_Scint68_CathodeEventsDistrHist->Write();
    R10_Scint68_CathodeEventsDistrHist->Write();
    R11_Scint68_CathodeEventsDistrHist->Write();
    R12_Scint68_CathodeEventsDistrHist->Write();
    R13_Scint68_CathodeEventsDistrHist->Write();
    R14_Scint68_CathodeEventsDistrHist->Write();
    R15_Scint68_CathodeEventsDistrHist->Write();
    R16_Scint68_CathodeEventsDistrHist->Write();
    R9Only_Scint68_CathodeEventsDistrHist->Write();
    R10Only_Scint68_CathodeEventsDistrHist->Write();
    R11Only_Scint68_CathodeEventsDistrHist->Write();
    R12Only_Scint68_CathodeEventsDistrHist->Write();
    R13Only_Scint68_CathodeEventsDistrHist->Write();
    R14Only_Scint68_CathodeEventsDistrHist->Write();
    R15Only_Scint68_CathodeEventsDistrHist->Write();
    R16Only_Scint68_CathodeEventsDistrHist->Write();
    R9Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R10Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R11Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R12Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R13Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R14Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R15Adjacent_Scint68_CathodeEventsDistrHist->Write();
    R16Adjacent_Scint68_CathodeEventsDistrHist->Write();

    TrackingReadout->WriteAbsProfiles();
    MOLLEROptFile->Write("",TObject::kOverwrite); // Writing the data to the ROOT file
    
    MOLLEROptNtuple->Reset(); //This needs to be here, so that the file size doesn't keep growing for new files.
                            //Apparently things are kept in the background, from the previous tree, and then 
                            //written to the new tree, without it being visible or accessible in the new file.
                            //This is only happening or a concern if multiple ROOT files are written in the same
                            //execution of the simulation, but it is a collossally stupid attribute of ROOT.

    MOLLEROptFile->Close();
  }

  if (MOLLERMainEvent)         delete MOLLERMainEvent;
  if (MOLLEROptFile)           delete MOLLEROptFile;
  
}

void MOLLEROptAnalysis::EndOfEvent(G4int flag) 
{
  if(!flag) return;
}

void MOLLEROptAnalysis::ConstructRootNtuple() 
{
  MOLLERMainEvent   = new MOLLEROptMainEvent();

  if(ROOTFileFlag) {
    MOLLEROptNtuple = new TTree("MOLLEROptTree","MOLLEROptTree");
    MOLLEROptMainBranch  = MOLLEROptNtuple->Branch("MOLLEROptData", "MOLLEROptMainEvent", &MOLLERMainEvent, 64000, 10);
  }
}

void MOLLEROptAnalysis::AutoSaveRootNtuple() 
{
    // save the current ntuple:
    // In case your program crashes before closing the file holding this tree,
    // the file will be automatically recovered when you will connect the file
    // in UPDATE mode.
    // The Tree will be recovered at the status corresponding to the last AutoSave.
    //
    // if option contains "SaveSelf", gDirectory->SaveSelf() is called.
    // This allows another process to analyze the Tree while the Tree is being filled.
    //
    // see http://root.cern.ch/root/html/TTree.html#TTree:AutoSave

    //MOLLEROptG4_RootNtuple -> AutoSave("SaveSelf");
  if(ROOTFileFlag) MOLLEROptNtuple->AutoSave();

}
