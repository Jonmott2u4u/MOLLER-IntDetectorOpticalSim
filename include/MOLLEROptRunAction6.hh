#ifndef MOLLEROptRunAction6_h
#define MOLLEROptRunAction6_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis6.hh"
#include "MOLLEROptRunActionMessenger6.hh"

class MOLLEROptRunActionMessenger6;
class MOLLEROptAnalysis6;

class MOLLEROptRunAction6 : public G4UserRunAction
{
public:
  MOLLEROptRunAction6(MOLLEROptAnalysis6* AN, MOLLEROptTrackingReadout6* TrRO6);
  ~MOLLEROptRunAction6();

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
  MOLLEROptAnalysis6* analysis6;
  MOLLEROptTrackingReadout6* TrackingReadout6;
  MOLLEROptRunActionMessenger6 *RunActionMessenger6;

};

#endif
