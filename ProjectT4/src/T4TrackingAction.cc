//T4TrackingAction.cc

#include "T4TrackingAction.hh"

#include "G4Event.hh"
#include "G4Track.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "G4VProcess.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 



T4TrackingAction::T4TrackingAction(T4EventAction* evt):T4Event(evt)
{
    Energy = 0;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
T4TrackingAction::~T4TrackingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4TrackingAction::PreUserTrackingAction(const G4Track* trk)
{
    Energy = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4TrackingAction::PostUserTrackingAction(const G4Track* trk)
{
    // T4Event->AppendTrackList(trk);
    // G4cout<<trk->GetTrackID()<<G4endl;

    //设定感兴趣的能量范围
    G4double upper_limit_t = 15.0;
    G4double lower_limit_t = 0.0001;

    if((Energy<upper_limit_t)&&(Energy>lower_limit_t)){ //判断这个track在晶体中能量沉积是否在感兴趣的范围内
        G4String particle = trk->GetParticleDefinition()->GetParticleName(); //看看这个粒子是什么
        if(trk->GetParentID()!=0){ //如果这个粒子不是初级粒子
            G4String name = trk->GetCreatorProcess()->GetProcessName(); //产生这个粒子的物理过程
            // G4String particle = trk->GetParticleDefinition()->GetParticleName();
            // G4cout<<Energy<<G4endl;
            // G4cout<<trk->GetTrackID()<<G4endl;
            // G4cout<<particle<<G4endl;
            // G4cout<<name<<G4endl;
            T4Event->AddToProcessCatalog(name, particle); //把这个粒子的物理过错信息传递给Event action
        }
        else
        {
            T4Event->AddToProcessCatalog("primary",particle); //如果是初级粒子的话
        }
    
    }
    
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
