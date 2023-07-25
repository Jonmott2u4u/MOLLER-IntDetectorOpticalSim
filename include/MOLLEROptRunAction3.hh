#ifndef MOLLEROptRunAction3_h
#define MOLLEROptRunAction3_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis3.hh"
#include "MOLLEROptRunActionMessenger3.hh"

class MOLLEROptRunActionMessenger3;
class MOLLEROptAnalysis3;

class MOLLEROptRunAction3 : public G4UserRunAction
{
public:
  MOLLEROptRunAction3(MOLLEROptAnalysis3* AN, MOLLEROptTrackingReadout3* TrRO3);
  ~MOLLEROptRunAction3();

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
  MOLLEROptAnalysis3* analysis3;
  MOLLEROptTrackingReadout3* TrackingReadout3;
  MOLLEROptRunActionMessenger3 *RunActionMessenger3;

};

#endif
