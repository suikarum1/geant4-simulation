#ifndef T4DetectorConstruction_h
#define T4DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4PhysicalConstants.hh"
#include "G4String.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "TMath.h"
#include "G4GDMLParser.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class T4DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        T4DetectorConstruction();
        ~T4DetectorConstruction();
        const G4VPhysicalVolume* GetCrystal(G4int) const; //访问crystal i (i = 0,1,2,3) 的 physical volume 的接口函数

        G4VPhysicalVolume* Construct();
    
    private:
        G4VPhysicalVolume* T4crystal_0; //访问crystal 0 的 physical volume 的接口
        G4VPhysicalVolume* T4crystal_1; //访问crystal 1 的 physical volume 的接口
        G4VPhysicalVolume* T4crystal_2; //访问crystal 2 的 physical volume 的接口
        G4VPhysicalVolume* T4crystal_3; //访问crystal 3 的 physical volume 的接口
};


#endif