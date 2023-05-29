#include "particle.h"

Particle::Particle(float _m, Matrix _p, Matrix _v) : m(_m), p(_p), v(_v),f(Matrix (2,1)) {}

Matrix Particle::getPosition(){
    return p;
}

Matrix Particle::getVelocity(){
    return v;
}

float Particle::getMass(){
    return m;
}

void Particle::setPosition(Matrix _p){
    this->p = _p;
}

void Particle::setForce(Matrix _f){
    this->f = _f;
}

void Particle::setVelocity(Matrix _v){
    this->v = _v;
}

void Particle::print(){
    std::cout << m << std::endl;
    p.print();
    v.print();
}

void Particle::update(float dt){
    p = p + v*dt;
    v = v + f*(1.0/m);
    
}

