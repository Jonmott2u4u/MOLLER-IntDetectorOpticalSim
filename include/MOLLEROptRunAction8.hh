#ifndef MOLLEROptRunAction8_h
#define MOLLEROptRunAction8_h 1

#include "cpp_include.h"
#include "Root_include.h"
#include "Geant4_include.hh" 

#include "MOLLEROptAnalysis8.hh"
#include "MOLLEROptRunActionMessenger8.hh"

class MOLLEROptRunActionMessenger8;
class MOLLEROptAnalysis8;

class MOLLEROptRunAction8 : public G4UserRunAction
{
public:
  MOLLEROptRunAction8(MOLLEROptAnalysis8* AN, MOLLEROptTrackingReadout8* TrRO8);
  ~MOLLEROptRunAction8();

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
  MOLLEROptAnalysis8* analysis8;
  MOLLEROptTrackingReadout8* TrackingReadout8;
  MOLLEROptRunActionMessenger8 *RunActionMessenger8;

};

#endif
