//T4RunAction.hh

#ifndef T4RunAction_h
#define T4RunAction_h

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "Rtypes.h"

class TNtuple;
class TFile;

class G4Run;



class T4RunAction : public G4UserRunAction
{
    public:
    T4RunAction();
    ~T4RunAction();

    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);
    void AddToTotalCounts();
    void AddToDetected();
    void AddToFullEnergy();
    void AddToProcess(G4int);
    void AddToInRange();

    private:
    int Total_Counts;
    int Detected;
    int Full_Energy;
    int idx;
    double Detected_Efficiency;
    double Full_Energy_Efficiency;
    TFile ResultFile;
    TTree Efficiency_Results;

    int Primary_Count;
    int DeltaElectron_Count;
    int GammaInvolved_Count;
    int NeutronInelastic_Count;
    int ProtonInelastic_Count;
    int HadronElastic_Count;
    int Others;
    int InRange;
};

inline void T4RunAction::AddToTotalCounts(){ //统计参与统计的事例总数
    Total_Counts++;
}

inline void T4RunAction::AddToDetected(){ //统计探测到的事例数
    Detected++;
}
inline void T4RunAction::AddToFullEnergy(){ //统计全能量沉积的事例数（针对光子）
    Full_Energy++;
}
inline void T4RunAction::AddToInRange(){ //统计能量沉积在上下限之间的事例数（Event 数，不是Track 数）
    InRange++;
}

#endif