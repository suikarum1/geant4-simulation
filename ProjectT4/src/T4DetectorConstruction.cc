#include "T4DetectorConstruction.hh"


T4DetectorConstruction::T4DetectorConstruction()
    :   G4VUserDetectorConstruction(),
        T4crystal_0(nullptr),
        T4crystal_1(nullptr),
        T4crystal_2(nullptr),
        T4crystal_3(nullptr)
{
}

T4DetectorConstruction::~T4DetectorConstruction()
{
}

G4VPhysicalVolume* T4DetectorConstruction::Construct()
{
    G4GDMLParser parser;
    parser.Read("./satellite_whole_mesh.gdml"); //读取GDML文件
    G4VPhysicalVolume* W = parser.GetWorldVolume(); //返回world volume
    W->GetLogicalVolume()->SetVisAttributes(G4VisAttributes::Invisible);

    G4PhysicalVolumeStore* PVStore = G4PhysicalVolumeStore::GetInstance();
    T4crystal_0 = PVStore->GetVolume("crystal_0_PV",true); //从GDML模型中提取crystal 0 的定义
    T4crystal_1 = PVStore->GetVolume("crystal_1_PV",true); //从GDML模型中提取crystal 1 的定义
    T4crystal_2 = PVStore->GetVolume("crystal_2_PV",true); //从GDML模型中提取crystal 2 的定义
    T4crystal_3 = PVStore->GetVolume("crystal_3_PV",true); //从GDML模型中提取crystal 3 的定义



    return W;

}

const G4VPhysicalVolume* T4DetectorConstruction::GetCrystal(G4int i) const {
    switch (i)
    {
    case 0:
        return T4crystal_0;
        break;
    
    case 1:
        return T4crystal_1;
        break;
    
    case 2:
        return T4crystal_2;
        break;
    
    case 3:
        return T4crystal_3;
        break;
    
    default:
        break;
    }

}
