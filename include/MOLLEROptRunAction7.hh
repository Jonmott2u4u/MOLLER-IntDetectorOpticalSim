#ifndef MOLLEROptRunAction7_h
#define MOLLEROptRunAction7_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis7.hh"
#include "MOLLEROptRunActionMessenger7.hh"

class MOLLEROptRunActionMessenger7;
class MOLLEROptAnalysis7;

class MOLLEROptRunAction7 : public G4UserRunAction
{
public:
  MOLLEROptRunAction7(MOLLEROptAnalysis7* AN, MOLLEROptTrackingReadout7* TrRO7);
  ~MOLLEROptRunAction7();

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
  MOLLEROptAnalysis7* analysis7;
  MOLLEROptTrackingReadout7* TrackingReadout7;
  MOLLEROptRunActionMessenger7 *RunActionMessenger7;

};

#endif
