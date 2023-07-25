#ifndef MOLLEROptRunAction4_h
#define MOLLEROptRunAction4_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis4.hh"
#include "MOLLEROptRunActionMessenger4.hh"

class MOLLEROptRunActionMessenger4;
class MOLLEROptAnalysis4;

class MOLLEROptRunAction4 : public G4UserRunAction
{
public:
  MOLLEROptRunAction4(MOLLEROptAnalysis4* AN, MOLLEROptTrackingReadout4* TrRO4);
  ~MOLLEROptRunAction4();

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
  MOLLEROptAnalysis4* analysis4;
  MOLLEROptTrackingReadout4* TrackingReadout4;
  MOLLEROptRunActionMessenger4 *RunActionMessenger4;

};

#endif
