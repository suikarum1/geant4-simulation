// T4SteppingAction.cc


#include "T4SteppingAction.hh"

#include "T4DetectorConstruction.hh"
#include "T4EventAction.hh"
#include "T4TrackingAction.hh"
#include "G4String.hh"
#include "G4Track.hh"
#include "G4SteppingManager.hh"

#include "G4ThreeVector.hh"
#include "G4Step.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T4SteppingAction::T4SteppingAction(T4DetectorConstruction* det,
				     T4EventAction* evt, T4TrackingAction* trk)
:T4DetCons(det),T4Event(evt),T4Track(trk)
{ }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T4SteppingAction::UserSteppingAction(const G4Step* aStep)
{ 

  auto volume = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(); //获得指向定义晶体的physical volume的指针
  //G4cout<<volume<<G4endl;
  
  auto edep = aStep->GetTotalEnergyDeposit(); //获得当前step中粒子损失能量
  //G4cout<<edep<<G4endl;
  for(int i=0; i<4; i++){
    //G4cout<<T4DetCons->GetCrystal(i)<<G4endl;
    if (volume == T4DetCons->GetCrystal(i)){ //判断这个step中的粒子是否在晶体体积内
      G4String name = aStep->GetTrack()->GetParticleDefinition()->GetParticleName(); //看看这个粒子是什么
      // G4cout<<name<<G4endl;
      if((name == "proton")||(name == "alpha")||(name == "C12")||(name == "O16")){ //当这个step追踪的粒子是重带电离子时，考虑到晶体对不同粒子的光产额不同，需要折合一个因子。
        // edep = edep * 0.25; //对空间环境中多种辐射来源进行综合模拟时，需要解除这个注释
      }
      T4Event->AddEnergyToCrystal(edep,i); //传递给event action，需要把每个step的能损相加
      T4Track->AddEnergy(edep); //传递给track action用来判断是否要追踪这个粒子的物理过程
      //G4cout<<"True"<<G4endl;
    }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

