#ifndef MOLLEROptRunAction2_h
#define MOLLEROptRunAction2_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis2.hh"
#include "MOLLEROptRunActionMessenger2.hh"

class MOLLEROptRunActionMessenger2;
class MOLLEROptAnalysis2;

class MOLLEROptRunAction2 : public G4UserRunAction
{
public:
  MOLLEROptRunAction2(MOLLEROptAnalysis2* AN, MOLLEROptTrackingReadout2* TrRO2);
  ~MOLLEROptRunAction2();

public:
  void BeginOfRunAction(const G4Run*);
  void EndOfRunAction(const G4Run*);
  G4int  getRunID();
  void SetMyRunID(G4int id) {MyRunID = id;};
  void SetROOTFileFlag(G4int flag) {ROOTFileFlag = flag;};
  void SetROOTFileName(G4String name1) {ROOTFileName = name1;};
  
private:

  G4int runID;
  G4int MyRunID;
  G4int ROOTFileFlag;
  G4String ROOTFileName;
  MOLLEROptAnalysis2* analysis2;
  MOLLEROptTrackingReadout2* TrackingReadout2;
  MOLLEROptRunActionMessenger2 *RunActionMessenger2;

};

#endif
