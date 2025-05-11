//T4RunAction.cc
 
#include "T4RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "g4root.hh"
#include "TString.h"
#include <string>


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
// G4double upper_limit_r = 15.0;
// G4double lower_limit = 0.0001;

T4RunAction::T4RunAction():
    Total_Counts(0),
    Detected(0),
    Full_Energy(0),
    idx(0),
    Detected_Efficiency(0.),
    Full_Energy_Efficiency(0.),
    ResultFile("Efficiency_Results_NTuple_proton_iso.root","RECREATE"), //初始化TNtuple输出文件
    Efficiency_Results("Efficiency_Results","Efficiency_Results"), //初始化TNtuple
    Primary_Count(0),
    DeltaElectron_Count(0),
    GammaInvolved_Count(0),
    NeutronInelastic_Count(0),
    ProtonInelastic_Count(0),
    HadronElastic_Count(0),
    Others(0),
    InRange(0)
{

G4double upper_limit_r = 15.0;
G4double lower_limit_r = 0.0001;
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFirstHistoId(0);
  
  analysisManager->CreateH1("T4H0","T4H0",100,0.003,upper_limit_r*MeV,"MeV");
  analysisManager->CreateH1("T4H1","T4H1",100,0.003,upper_limit_r*MeV,"MeV");
  analysisManager->CreateH1("T4H2","T4H2",100,0.003,upper_limit_r*MeV,"MeV");
  analysisManager->CreateH1("T4H3","T4H3",100,0.003,upper_limit_r*MeV,"MeV");
  analysisManager->CreateH1("Total","Total",100,0.003,upper_limit_r*MeV,"MeV");

  Efficiency_Results.Branch("idx",&idx, "idx/I");
  Efficiency_Results.Branch("Total_Counts",&Total_Counts, "Total_Counts/I");
  Efficiency_Results.Branch("Detected",&Detected, "Detected/I");
  Efficiency_Results.Branch("Full_Energy",&Full_Energy, "Full_Energy/I");
  Efficiency_Results.Branch("Detected_Efficiency",&Detected_Efficiency, "Detected_Efficiency/D");
  Efficiency_Results.Branch("Full_Energy_Efficiency",&Full_Energy_Efficiency, "Full_Energy_Efficiency/D");
  Efficiency_Results.Branch("Primary_Count",&Primary_Count, "Primary_Count/I");
  Efficiency_Results.Branch("DeltaElectron_Count",&DeltaElectron_Count, "DeltaElectron_Count/I");
  Efficiency_Results.Branch("GammaInvolved_Count",&GammaInvolved_Count, "GammaInvolved_Count/I");
  Efficiency_Results.Branch("NeutronInelastic_Count",&NeutronInelastic_Count, "NeutronInelastic_Count/I");
  Efficiency_Results.Branch("ProtonInelastic_Count",&ProtonInelastic_Count, "ProtonInelastic_Count/I");
  Efficiency_Results.Branch("HadronElastic_Count",&HadronElastic_Count, "HadronElastic_Count/I");
  Efficiency_Results.Branch("Others",&Others, "Others/I");
  Efficiency_Results.Branch("InRange",&InRange, "InRange/I");
  
  // G4String fileName = "Solar_xray_back";
  analysisManager->OpenFile(); //初始化能谱文件，文件名定义可以通过前面一行定义：OpenFile(fileName)，也可以在macro中定义
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
T4RunAction::~T4RunAction()
{
  //把数据写入TNtuple文件并关闭，如果需要的话通过以下注释的代码写入能谱文件并关闭
  // auto analysisManager = G4AnalysisManager::Instance();
  // analysisManager->Write();
  // analysisManager->CloseFile();
  Efficiency_Results.Write();
  ResultFile.Close();

  delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4RunAction::BeginOfRunAction(const G4Run* aRun)
{
  //在每个run开始时，初始化计数器，初始化能谱文件
  auto analysisManager = G4AnalysisManager::Instance();

  Total_Counts = 0;
  Detected = 0;
  Full_Energy = 0;

  Primary_Count = 0;
  DeltaElectron_Count = 0;
  GammaInvolved_Count = 0;
  NeutronInelastic_Count = 0;
  ProtonInelastic_Count = 0;
  HadronElastic_Count = 0;
  Others = 0;
  InRange = 0;

  // G4String fileName = "T4log";
  analysisManager->OpenFile();
  G4cout<<"cccccccccccccccccccccccccccccccccccccccccccccccccccBegin Running ..." << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void T4RunAction::EndOfRunAction(const G4Run* aRun)
{
  //在每个run结束时，将统计结果写入文件
  G4cout<<"End Running ..."<<G4endl;
  auto analysisManager = G4AnalysisManager::Instance();
  // analysisManager -> SetH1Plotting(0,true);
  // analysisManager -> SetH1Plotting(1,true);
  // analysisManager -> SetH1Plotting(2,true);
  // analysisManager -> SetH1Plotting(3,true);
  // analysisManager -> SetH1Plotting(4,true);

  analysisManager->Write();
  analysisManager->CloseFile();

  double Detected_d = double(Detected), Total_d = double(Total_Counts), Full_d = double(Full_Energy);
  Detected_Efficiency = Detected_d/Total_d;
  Full_Energy_Efficiency = Full_d/Total_d;
  // G4cout<<Detected_Efficiency<<G4endl;
  // G4cout<<Full_Energy_Efficiency<<G4endl;
  Efficiency_Results.Fill();
  idx++;
}

void T4RunAction::AddToProcess(G4int i){
  switch (i)
  {
  case 0:
    Primary_Count ++ ;
    break;

  case 1:
    DeltaElectron_Count ++ ;
    break;
  
  case 2:
    GammaInvolved_Count ++ ;
    break;
  
  case 3:
    NeutronInelastic_Count ++ ;
    break;
  
  case 4:
    ProtonInelastic_Count ++ ;
    break;

  case 5:
    HadronElastic_Count ++ ;
    break;
  
  case 6:
    Others ++ ;
    break;

  default:
    break;
  
  }
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
