#ifndef T4PrimaryGeneratorAction_h
#define T4PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;
class G4Event;

class T4PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
private:
    G4GeneralParticleSource* T4GPS;
public:
    T4PrimaryGeneratorAction();
    ~T4PrimaryGeneratorAction();
    void GeneratePrimaries(G4Event* anEvent);

};

#endif