#include "particle.h"

Particle::Particle(float _m, Matrix _p, Matrix _v) : m(_m), p(_p), v(_v) {}

Matrix Particle::getPosition()
{
    return p;
}

Matrix Particle::getVelocity()
{
    return v;
}

float Particle::getMass()
{
    return m;
}

void Particle::setPosition(Matrix _p)
{
    p = _p;
}

void Particle::setVelocity(Matrix _v)
{
    v = _v;
}

void Particle::setForce(Matrix _f)
{
    f = _f;
}
void Particle::update(float dt){
    p = p + v*dt;
    v = v*f(1.0/m);
}


void Particle::print(){
    std::cout << "Masse: " << m << std::endl;
    std::cout << "Position: " << p << std::endl;
    std::cout << "Hastighed: " << v << std::endl;
}
