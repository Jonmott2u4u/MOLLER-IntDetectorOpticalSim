#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"

#include "QGSP_BERT_HP.hh"
#include "FTFP_BERT.hh"
#include "G4PhysListFactory.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"

#include "MOLLEROptAnalysis.hh"
#include "MOLLEROptAnalysis2.hh"
#include "MOLLEROptAnalysis3.hh"
#include "MOLLEROptAnalysis4.hh"
#include "MOLLEROptAnalysis5.hh"
#include "MOLLEROptAnalysis6.hh"
#include "MOLLEROptAnalysis7.hh"
#include "MOLLEROptAnalysis8.hh"

#include "MOLLEROptPhysicsList.hh"
#include "MOLLEROptPrimaryGeneratorAction.hh"
#include "MOLLEROptConstruction.hh"

#include "MOLLEROptEventAction.hh"
#include "MOLLEROptEventAction2.hh"
#include "MOLLEROptEventAction3.hh"
#include "MOLLEROptEventAction4.hh"
#include "MOLLEROptEventAction5.hh"
#include "MOLLEROptEventAction6.hh"
#include "MOLLEROptEventAction7.hh"
#include "MOLLEROptEventAction8.hh"

#include "MOLLEROptRunAction.hh"
#include "MOLLEROptRunAction2.hh"
#include "MOLLEROptRunAction3.hh"
#include "MOLLEROptRunAction4.hh"
#include "MOLLEROptRunAction5.hh"
#include "MOLLEROptRunAction6.hh"
#include "MOLLEROptRunAction7.hh"
#include "MOLLEROptRunAction8.hh"

#include "MOLLEROptSteppingAction.hh"
#include "MOLLEROptTrackingAction.hh"

#include "MOLLEROptTrackingReadout.hh"
#include "MOLLEROptTrackingReadout2.hh"
#include "MOLLEROptTrackingReadout3.hh"
#include "MOLLEROptTrackingReadout4.hh"
#include "MOLLEROptTrackingReadout5.hh"
#include "MOLLEROptTrackingReadout6.hh"
#include "MOLLEROptTrackingReadout7.hh"
#include "MOLLEROptTrackingReadout8.hh"

#include "MOLLEROptMaterial.hh"
// #include "MOLLEROptTrackingReadout.hh"


#include "G4RunManager.hh"

#include "G4VUserPhysicsList.hh"

#include <G4UImanager.hh>
#include <G4UIExecutive.hh>
#include <G4UIterminal.hh>
//#include <UVA_VisAction.hh>
#include "G4VisExecutive.hh"


#ifdef G4UI_USE_QT
#include "G4UIQt.hh"
#endif

#ifdef G4UI_USE_XM
#include "G4UIXm.hh"
#endif

#ifdef G4UI_USE_TCSH
#include "G4UItcsh.hh"
#endif

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif


int main(int argc,char** argv) {


  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine());
  
  // Run manager
  G4RunManager * runManager = new G4RunManager();

  // UserInitialization classes (mandatory)
  MOLLEROptTrackingReadout*       thisMOLLEROptTrackingReadout  = new MOLLEROptTrackingReadout();
  MOLLEROptTrackingReadout2* 	  thisMOLLEROptTrackingReadout2 = new MOLLEROptTrackingReadout2();
  MOLLEROptTrackingReadout3* 	  thisMOLLEROptTrackingReadout3 = new MOLLEROptTrackingReadout3();
  MOLLEROptTrackingReadout4* 	  thisMOLLEROptTrackingReadout4 = new MOLLEROptTrackingReadout4();
  MOLLEROptTrackingReadout5* 	  thisMOLLEROptTrackingReadout5 = new MOLLEROptTrackingReadout5();
  MOLLEROptTrackingReadout6* 	  thisMOLLEROptTrackingReadout6 = new MOLLEROptTrackingReadout6();
  MOLLEROptTrackingReadout7* 	  thisMOLLEROptTrackingReadout7 = new MOLLEROptTrackingReadout7();
  MOLLEROptTrackingReadout8* 	  thisMOLLEROptTrackingReadout8 = new MOLLEROptTrackingReadout8();

  MOLLEROptMaterial *Materials = new MOLLEROptMaterial(thisMOLLEROptTrackingReadout);
  Materials->DefineMaterials();
  MOLLEROptConstruction*          thisMOLLEROptExperiment       = new MOLLEROptConstruction(thisMOLLEROptTrackingReadout,thisMOLLEROptTrackingReadout2,thisMOLLEROptTrackingReadout3,thisMOLLEROptTrackingReadout4,thisMOLLEROptTrackingReadout5,thisMOLLEROptTrackingReadout6,thisMOLLEROptTrackingReadout7,thisMOLLEROptTrackingReadout8,Materials);
  
  MOLLEROptAnalysis*               thisMOLLEROptAnalysis          = new MOLLEROptAnalysis();
  MOLLEROptAnalysis2*              thisMOLLEROptAnalysis2         = new MOLLEROptAnalysis2();
  MOLLEROptAnalysis3*              thisMOLLEROptAnalysis3         = new MOLLEROptAnalysis3();
  MOLLEROptAnalysis4*              thisMOLLEROptAnalysis4         = new MOLLEROptAnalysis4();
  MOLLEROptAnalysis5*              thisMOLLEROptAnalysis5         = new MOLLEROptAnalysis5();
  MOLLEROptAnalysis6*              thisMOLLEROptAnalysis6         = new MOLLEROptAnalysis6();
  MOLLEROptAnalysis7*              thisMOLLEROptAnalysis7         = new MOLLEROptAnalysis7();
  MOLLEROptAnalysis8*              thisMOLLEROptAnalysis8         = new MOLLEROptAnalysis8();
  
  runManager->SetUserInitialization(thisMOLLEROptExperiment);

  G4int verbose = 3;

  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  opticalPhysics->SetWLSTimeProfile("delta");
  
  opticalPhysics->SetScintillationYieldFactor(1.0);
  opticalPhysics->SetScintillationExcitationRatio(0.0);
  
  opticalPhysics->SetMaxNumPhotonsPerStep(100);
  opticalPhysics->SetMaxBetaChangePerStep(10.0);
  
  opticalPhysics->SetTrackSecondariesFirst(kCerenkov, true);
  opticalPhysics->SetTrackSecondariesFirst(kScintillation, true);
  
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  
  // G4PhysListFactory factory;
  // G4VModularPhysicsList* physlist = factory.GetReferencePhysList("FTFP_BERT");//FTFP_BERT
  // physlist->RegisterPhysics(new G4StepLimiterPhysics());
  // physlist->SetVerboseLevel(verbose);
  // runManager->SetUserInitialization(physlist);
  // physlist->RegisterPhysics( new MOLLEROptPhysicsList() );
  // UserAction classes
  
  runManager->SetUserAction( new MOLLEROptPrimaryGeneratorAction(thisMOLLEROptExperiment) );
  
  runManager->SetUserAction( new MOLLEROptRunAction(thisMOLLEROptAnalysis, thisMOLLEROptTrackingReadout ) );  
  runManager->SetUserAction( new MOLLEROptRunAction2(thisMOLLEROptAnalysis2, thisMOLLEROptTrackingReadout2 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction3(thisMOLLEROptAnalysis3, thisMOLLEROptTrackingReadout3 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction4(thisMOLLEROptAnalysis4, thisMOLLEROptTrackingReadout4 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction5(thisMOLLEROptAnalysis5, thisMOLLEROptTrackingReadout5 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction6(thisMOLLEROptAnalysis6, thisMOLLEROptTrackingReadout6 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction7(thisMOLLEROptAnalysis7, thisMOLLEROptTrackingReadout7 ) );  
  runManager->SetUserAction( new MOLLEROptRunAction8(thisMOLLEROptAnalysis8, thisMOLLEROptTrackingReadout8 ) );  
  
  runManager->SetUserAction( new MOLLEROptEventAction(thisMOLLEROptAnalysis, thisMOLLEROptTrackingReadout) );
  runManager->SetUserAction( new MOLLEROptEventAction2(thisMOLLEROptAnalysis2, thisMOLLEROptTrackingReadout2) );
  runManager->SetUserAction( new MOLLEROptEventAction3(thisMOLLEROptAnalysis3, thisMOLLEROptTrackingReadout3) );
  runManager->SetUserAction( new MOLLEROptEventAction4(thisMOLLEROptAnalysis4, thisMOLLEROptTrackingReadout4) );
  runManager->SetUserAction( new MOLLEROptEventAction5(thisMOLLEROptAnalysis5, thisMOLLEROptTrackingReadout5) );
  runManager->SetUserAction( new MOLLEROptEventAction6(thisMOLLEROptAnalysis6, thisMOLLEROptTrackingReadout6) );
  runManager->SetUserAction( new MOLLEROptEventAction7(thisMOLLEROptAnalysis7, thisMOLLEROptTrackingReadout7) );
  runManager->SetUserAction( new MOLLEROptEventAction8(thisMOLLEROptAnalysis8, thisMOLLEROptTrackingReadout8) );
  
  runManager->SetUserAction( new MOLLEROptSteppingAction(thisMOLLEROptTrackingReadout) );
  runManager->SetUserAction( new MOLLEROptTrackingAction(thisMOLLEROptTrackingReadout) );

  //Initialize G4 kernel
  runManager->Initialize();

  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }
  
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  
  G4UImanager * UIManager = G4UImanager::GetUIpointer();  
  
  if ( ! ui ) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UIManager->ApplyCommand(command+fileName);
  }
  else {
    // interactive mode
    UIManager->ApplyCommand("/control/execute macros/gui.mac");
    ui->SessionStart();
    delete ui;
  }


  delete visManager;
  delete runManager;
  
  return 0;
}

