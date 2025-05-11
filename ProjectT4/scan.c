void scan()
{
    TFile Efficiency_File("Efficiency_Results_NTuple_Solar_xray_front.root");
    TTree* Handle;
    Efficiency_File.GetObject("Efficiency_Results",Handle);
    Handle->Scan("idx:Total_Counts:Detected:Full_Energy:Detected_Efficiency:Full_Energy_Efficiency:Primary_Count:DeltaElectron_Count:GammaInvolved_Count:NeutronInelastic_Count:ProtonInelastic_Count:HadronElastic_Count:Others:InRange");

}