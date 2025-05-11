// T4SteppingAction.hh

#ifndef T4SteppingAction_h
#define T4SteppingAction_h 1

#include "G4UserSteppingAction.hh"

#include "G4Types.hh"

class T4DetectorConstruction;
class T4EventAction;
class T4TrackingAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class T4SteppingAction : public G4UserSteppingAction
{
  public:
    T4SteppingAction(T4DetectorConstruction*, T4EventAction*, T4TrackingAction*);
   ~T4SteppingAction(){};

    void UserSteppingAction(const G4Step*);

  private:
    T4DetectorConstruction* T4DetCons;
    T4EventAction*      T4Event;
    T4TrackingAction* T4Track;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
