#ifndef T4TrackingAction_h
#define T4TrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "globals.hh"
#include "T4EventAction.hh"

class G4Track;
class T4EventAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......




class T4TrackingAction : public G4UserTrackingAction
{
  public:
    T4TrackingAction(T4EventAction*);
   ~T4TrackingAction();

  public:
    void PreUserTrackingAction(const G4Track*);
    void PostUserTrackingAction(const G4Track*);
    void AddEnergy(G4double);

  private:
    T4EventAction* T4Event;
    G4double Energy;
};

inline void T4TrackingAction::AddEnergy(G4double de)
{
  Energy += de;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
