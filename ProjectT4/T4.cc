#include "T4DetectorConstruction.hh"
#include "T4PhysicsList.hh"
#include "T4RunAction.hh"
#include "T4EventAction.hh"
#include "T4TrackingAction.hh"
#include "T4SteppingAction.hh"
#include "T4PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#define G4VIS_USE
#define G4UI_USE

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "Randomize.hh"

int main(int argc, char** argv)
{
    G4RunManager* T4RunManager = new G4RunManager;

    T4DetectorConstruction* T4DetCons = new T4DetectorConstruction();
    T4RunManager -> SetUserInitialization(T4DetCons);
    T4RunManager -> SetUserInitialization(new T4PhysicsList());

    T4RunManager -> SetUserAction(new T4PrimaryGeneratorAction());
    T4RunAction* T4Run = new T4RunAction();
    T4RunManager -> SetUserAction(T4Run);
    T4EventAction* T4Event = new T4EventAction(T4Run);
    T4RunManager -> SetUserAction(T4Event);
    T4TrackingAction* T4Track = new T4TrackingAction(T4Event);
    T4RunManager -> SetUserAction(T4Track);
	T4RunManager -> SetUserAction(new T4SteppingAction(T4DetCons,T4Event,T4Track));

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/run/verbose 0");
    UImanager->ApplyCommand("/event/verbose 0");
    UImanager->ApplyCommand("/tracking/verbose 0");
    UImanager->ApplyCommand("/process/em/fluo true");
    UImanager->ApplyCommand("/process/em/auger true");
    UImanager->ApplyCommand("/process/em/augerCascade true");
    UImanager->ApplyCommand("/process/em/pixe true");

    T4RunManager -> Initialize();

    #ifdef G4VIS_USE
    G4VisManager* T4Vis = new G4VisExecutive;
    T4Vis -> Initialize();
    #endif

    if (argc != 1){
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager -> ApplyCommand(command+fileName);
    }
    else {
        #ifdef G4UI_USE
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        #ifdef G4VIS_USE
        //UImanager -> ApplyCommand("/control/execute gps_def_03.mac");
        UImanager -> ApplyCommand("/control/execute init_vis.mac");
        #endif
        ui -> SessionStart();
        delete ui;
        #endif
    }

    #ifdef G4VIS_USE
    delete T4Vis;
    #endif
    
    delete T4RunManager;
    return 0;
}