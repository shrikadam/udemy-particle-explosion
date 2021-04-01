#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace cst{

class Swarm{
private:
    Particle* m_pParticles;
public:
    const static int NPARTICLES = 5000;
    int lastTime;
public:
    Swarm();
    virtual ~Swarm();
    const Particle* const getParticles(){return m_pParticles;}
    void update(int elapsed);
};

}

#endif