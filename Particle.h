#ifndef PARTICLE_H
#define PARTICLE_H
#define _USE_MATH_DEFINES

namespace cst{

struct Particle{
    double m_x;
    double m_y;
    double m_speed;
    double m_direction;
    
    Particle();
    void init();
    void update(int interval);
    virtual ~Particle();
};

}

#endif
