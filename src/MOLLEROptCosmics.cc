#include "MOLLEROptCosmics.hh"

MOLLEROptCosmics::MOLLEROptCosmics(MOLLEROptTrackingReadout* trRO)
{
    TrackingReadout = trRO;
    NCosmicPar = 100;
    CosmicPar = new CosmicParam(NCosmicPar);
    SetCosmicParameters();
}

MOLLEROptCosmics::~MOLLEROptCosmics()
{

}

void MOLLEROptCosmics::SetCosmicParameters()
{
    ifstream CosmicsFile("data/cosmics.txt");
    if(!CosmicsFile.is_open()){
        G4cout << "The file cannot be read!!" << endl;
    }
    else{
        G4cout << "Reading Cosmics file." << endl;
        G4cout << "This file contains the possible energies of cosmic muons in the simulation." << endl;
        
        int n = 0;
        Int_t var[2];// Weighted energy of cosmic muons and when they occur in the flux (not actual flux rates)

        while(!CosmicsFile.eof()){
            CosmicsFile >> var[0]
            >> var[1];
            CosmicPar->EMuon[n] = var[0]*MeV;
            CosmicPar->RateMuon[n] = var[1];
            //G4cout << CosmicPar->EMuon[n] << G4endl;
            //G4cout << CosmicPar->RateMuon[n] << G4endl;
            n++;
        }
    }
    TrackingReadout->SetCosmicParameters(CosmicPar);

}
