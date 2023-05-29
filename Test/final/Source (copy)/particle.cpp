#include "particle.h"

Particle::Particle(float _m, Matrix _p = Matrix(2,1), Matrix _v = Matrix(2,1)){
    m = _m;
    p = _p;
    v = _v;
    f = Matrix(2,1);
}

Matrix Particle::getPosition(){
    return p;
}

Matrix Particle::getVelocity(){
    return v;
}

float Particle::getMass(){
    return m;
}

void Particle::setPosition(Matrix p){
    this->p = p;
}

void Particle::setForce(Matrix f){
    this->f = f;
}

void Particle::setVelocity(){
    this->v = v;
}

void print(){
    std::cout << "Massen er:" << getMass() << "Positionen er:" << getPosition() << "Hastigheden er:" << getVelocity() << std::endl;
}

void Particle::update(float dt){
    v = v + f*(1.0/m);
    
    p = p + v*dt;
}

