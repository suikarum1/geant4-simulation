//T4EventAction.cc

#include "T4EventAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4String.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "g4root.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



T4EventAction::T4EventAction(T4RunAction* run)
  : Energy_0(0.),
    Energy_1(0.),
    Energy_2(0.),
    Energy_3(0.),
    Total(0.),
    T4Run(run),
    DeltaElectron_Count(0),
    Primary_Count(0),
    PhotoElectron_Count(0),
    Gamma_Count(0),
    NeutronInelastic(0),
    ProtonInelastic(0),
    HadronElastic(0),
    Others(0)
{
  // TrackListT4.clear();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
T4EventAction::~T4EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4EventAction::BeginOfEventAction(const G4Event* evt)
{
  Energy_0=0.;
  Energy_1=0.;
  Energy_2=0.;
  Energy_3=0.;
  Total = 0.;
  DeltaElectron_Count = 0;
  Primary_Count = 0;
  PhotoElectron_Count = 0;
  Gamma_Count = 0;
  NeutronInelastic = 0;
  ProtonInelastic = 0;
  HadronElastic = 0;
  Others = 0;
  // TrackListT4.clear();
    //   printf("Press Enter key to continue...");
    // fgetc(stdin);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4EventAction::EndOfEventAction(const G4Event* evt)
{

  auto analysisManager = G4AnalysisManager::Instance();
  G4double upper_limit_e = 15.0; //能量沉积能谱上限
  G4double lower_limit_e = 0.0001; //能量沉积能谱下限
  
  G4double TE = evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
  //G4cout<<TE<<G4endl;

    //填充能量沉积能谱
    analysisManager -> FillH1(0, Energy_0);
    analysisManager -> FillH1(1, Energy_1);
    analysisManager -> FillH1(2, Energy_2);
    analysisManager -> FillH1(3, Energy_3);
    analysisManager -> FillH1(4, Total);

    //填充TNtuple
     T4Run->AddToTotalCounts();
  if((Energy_0+Energy_1+Energy_2+Energy_3)>lower_limit_e){
    // printf("Press Enter key to continue...");
    // fgetc(stdin);
    T4Run->AddToDetected();
    if(TE-(Energy_0+Energy_1+Energy_2+Energy_3)<lower_limit_e){
      T4Run->AddToFullEnergy();
    }
    if((Energy_0+Energy_1+Energy_2+Energy_3)<upper_limit_e){
      T4Run->AddToInRange();
      // G4cout<<"ring"<<G4endl;
    }
  }
  
  
  if(
    ((Energy_0>lower_limit_e)&&(Energy_0<upper_limit_e))||
    ((Energy_1>lower_limit_e)&&(Energy_1<upper_limit_e))||
    ((Energy_2>lower_limit_e)&&(Energy_2<upper_limit_e))||
    ((Energy_3>lower_limit_e)&&(Energy_3<upper_limit_e))||
    ((Total>lower_limit_e)&&(Total<upper_limit_e))
  ){
    if(Primary_Count != 0){
      T4Run->AddToProcess(0);
    //       printf("Press Enter key to continue...");
    // fgetc(stdin);
    }
    else if(DeltaElectron_Count != 0){ //对于电子需要把这一项和上一项合并
      T4Run->AddToProcess(1);
    }
    else if(PhotoElectron_Count+Gamma_Count != 0){ //二者并作一项"Gamma Involved"
      T4Run->AddToProcess(2);
    }
    else if(NeutronInelastic != 0){
      T4Run->AddToProcess(3);
    }
    else if(ProtonInelastic != 0){
      T4Run->AddToProcess(4);
    }
    else if(HadronElastic != 0){
      T4Run->AddToProcess(5);
    }
    else if(Others != 0){
      T4Run->AddToProcess(6);
    }
  }
  // if((Total>0.003)&&(Total<0.12)){
  //   printf("Press Enter key to continue...");
  //   fgetc(stdin);
  // }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T4EventAction::AddEnergyToCrystal(G4double de, G4int i)
{
  Total += de;
  switch (i)
  {
  case 0:
    Energy_0 += de;
    break;

  case 1:
    Energy_1 += de;
    break;
  
  case 2:
    Energy_2 += de;
    break;
  
  case 3:
    Energy_3 += de;
    break;
  
  default:
    break;
  }
}

void T4EventAction::AddToProcessCatalog(G4String name, G4String particle)
{
  //粒子来源：初级粒子
  if(name == "primary"){
    Primary_Count ++ ;
  }

  //粒子来源：带电强子电离或电子电离，粒子种类：e-
  else if(((name == "hIoni")||(name == "eIoni"))&&(particle == "e-")){
    DeltaElectron_Count ++ ;
  }

  //由光电效应、康普顿效应、电子对效应产生的e-和e+，说明有光子参与其中
  else if(((name == "phot")||(name == "compt")||(name == "conv"))&&((particle == "e-")||(particle == "e+"))){
    PhotoElectron_Count ++ ;
  }

  //原子退激的能量截断的能损会计算为光子的能损
  else if(particle == "gamma"){
    Gamma_Count ++ ;
  }

  //核反应过程的能损
  else if(name == "neutronInelastic"){
    NeutronInelastic ++ ;
  }
  else if(name == "protonInelastic"){
    ProtonInelastic ++ ;
  }
  else if(name == "hadElastic"){
    HadronElastic ++ ;
  }

  //其他项，总是少数情况
  else{
    Others ++ ;
  }
}
// void T4EventAction::AppendTrackList(const G4Track* trk)
// {
//   TrackListT4.push_back(*trk);
// }
