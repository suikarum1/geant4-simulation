#include "globals.hh"

#include "T4PhysicsList.hh"

#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"

#include "G4OpWLS.hh"

#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4LossTableManager.hh"
#include "G4EmSaturation.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

#include "G4OpticalPhoton.hh"

#include "G4SystemOfUnits.hh"




T4PhysicsList::T4PhysicsList() : QBBC()
{
    void ConstructParticle();
    void ConstructProcess();
}

void T4PhysicsList::ConstructParticle()
{
    QBBC::ConstructParticle();
    G4OpticalPhoton::OpticalPhotonDefinition();   
}

void T4PhysicsList::ConstructProcess()
{
    QBBC::ConstructProcess(); //QBBC默认Standard Em Opt0
    ConstructOp(); //T4中没有用到光学模拟，这部分没用，可注释掉
}

void T4PhysicsList::ConstructOp()
{
    //AbsorptionOn = G4bool(false);
    theCerenkovProcess = new G4Cerenkov("Cerenkov");
    theScintillationProcess = new G4Scintillation("Scintillation");
    //theBoundaryProcess = new G4OpBoundaryProcess();

    theCerenkovProcess -> SetVerboseLevel(0);
    theScintillationProcess -> SetVerboseLevel(0);
    //theBoundaryProcess ->SetVerboseLevel(0);

    theCerenkovProcess->SetMaxNumPhotonsPerStep(300);
    theCerenkovProcess->SetMaxBetaChangePerStep(10.0);
    theCerenkovProcess->SetTrackSecondariesFirst(true);

    theScintillationProcess->SetTrackSecondariesFirst(true);
    theScintillationProcess->SetScintillationYieldFactor(1.0);
    //theScintillationProcess->SetScintillationExcitationRatio(0.0);
    //theScintillationProcess->SetFiniteRiseTime(true);

    G4ParticleTable::G4PTblDicIterator* theParticleIterator = GetParticleIterator();
    theParticleIterator->reset();
    while((*theParticleIterator)()){
        G4ParticleDefinition* particle = theParticleIterator->value();
        G4ProcessManager* pmanager = particle->GetProcessManager();
        G4String particleName = particle->GetParticleName();
        if(theCerenkovProcess->IsApplicable(*particle)){
            pmanager->AddProcess(theCerenkovProcess);
            pmanager->SetProcessOrdering(theCerenkovProcess, idxPostStep);
        }
        if(theScintillationProcess->IsApplicable(*particle)){
            pmanager->AddProcess(theScintillationProcess);
            pmanager->SetProcessOrderingToLast(theScintillationProcess, idxAtRest);
            pmanager->SetProcessOrderingToLast(theScintillationProcess, idxPostStep);
        }
    }

}