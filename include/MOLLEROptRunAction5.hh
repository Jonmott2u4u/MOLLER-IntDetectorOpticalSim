#ifndef MOLLEROptRunAction5_h
#define MOLLEROptRunAction5_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis5.hh"
#include "MOLLEROptRunActionMessenger5.hh"

class MOLLEROptRunActionMessenger5;
class MOLLEROptAnalysis5;

class MOLLEROptRunAction5 : public G4UserRunAction
{
public:
  MOLLEROptRunAction5(MOLLEROptAnalysis5* AN, MOLLEROptTrackingReadout5* TrRO5);
  ~MOLLEROptRunAction5();

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
  MOLLEROptAnalysis5* analysis5;
  MOLLEROptTrackingReadout5* TrackingReadout5;
  MOLLEROptRunActionMessenger5 *RunActionMessenger5;

};

#endif
