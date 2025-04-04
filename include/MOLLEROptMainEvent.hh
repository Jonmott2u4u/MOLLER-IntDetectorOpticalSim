#ifndef MOLLEROptMainEvent_h
#define MOLLEROptMainEvent_h

#include "cpp_include.h"
#include "Root_include.h"

// user includes
#include "MOLLEROptPrimaryEvent.hh"
#include "MOLLEROptGeneralEvent.hh"   

class MOLLEROptPrimaryEvent;   
class MOLLEROptGeneralEvent;  

class MOLLEROptMainEvent : public TObject
{

private:

public:
    
  MOLLEROptPrimaryEvent          MOLLERPrimEvent;
  MOLLEROptGeneralEvent          MOLLERGeneralEvent;

public:

  MOLLEROptMainEvent();

  virtual ~MOLLEROptMainEvent();
  
  ClassDef(MOLLEROptMainEvent,1)

};

#endif 
