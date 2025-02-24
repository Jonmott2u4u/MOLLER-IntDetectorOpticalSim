#ifndef MOLLEROptCosmics_H
#define MOLLEROptCosmics_H 1

#include "cpp_include.h"
#include "Geant4_include.hh" 
#include "Root_include.h"
#include "MOLLEROptTrackingReadout.hh"

class CosmicParam{

public:

    CosmicParam(int n){
        npar = n;
        EMuon = new Int_t[npar];
        RateMuon = new Int_t[npar];
    };

    ~CosmicParam(){
        delete EMuon;
        delete RateMuon;
    };

    Int_t *EMuon;
    Int_t *RateMuon;
    Int_t npar;
    Int_t GetNPar() {return npar;};

};

class MOLLEROptCosmics
{
public:
    MOLLEROptCosmics(MOLLEROptTrackingReadout*);
    ~ MOLLEROptCosmics();

public:
    void SetCosmicParameters();
    CosmicParam* GetCosmicParametersTable(){return CosmicPar;};

private:
    CosmicParam *CosmicPar;
    Int_t NCosmicPar;
    MOLLEROptTrackingReadout* TrackingReadout;

};

#endif
