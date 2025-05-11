#ifndef T4EventAction_h
#define T4EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "T4RunAction.hh"
#include "T4TrackingAction.hh"
#include<iostream>
#include<list>

class G4Event;
class G4Track;

using  namespace std;





class T4EventAction : public G4UserEventAction
{
  public:
    T4EventAction(T4RunAction*);
   ~T4EventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    void AddEnergyToCrystal(G4double, G4int);
    void AddToProcessCatalog(G4String,G4String);
    // void AppendTrackList(const G4Track*);

  private:
    G4double Energy_0; //能量沉积统计
    G4double Energy_1;
    G4double Energy_2;
    G4double Energy_3;
    G4double Total;
    G4int DeltaElectron_Count; //物理过程统计
    G4int Primary_Count;
    G4int PhotoElectron_Count;
    G4int Gamma_Count;
    G4int NeutronInelastic;
    G4int ProtonInelastic;
    G4int HadronElastic;
    G4int Others;
    T4RunAction* T4Run; //统计结果传递至T4RunAction
    // list<G4Track> TrackListT4;

};

#endif