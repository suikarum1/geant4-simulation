#include "T4PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"

#include "TMath.h"
#include "Randomize.hh"

T4PrimaryGeneratorAction::T4PrimaryGeneratorAction()
{
    T4GPS = new G4GeneralParticleSource();

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "gamma";
    T4GPS->SetParticleDefinition(particleTable->FindParticle(particleName));
}

T4PrimaryGeneratorAction::~T4PrimaryGeneratorAction()
{
    delete T4GPS;
}

void T4PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    T4GPS->GeneratePrimaryVertex(anEvent);
}