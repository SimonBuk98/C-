#include "particle_system.h"
#include <cmath>
#include <vector>

ParticleSystem::ParticleSystem(float _dt, int h, int w) : dt(_dt)
{
    canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
}

Matrix ParticleSystem::calcForce(Particle p1, particle p2)
{
    Matrix dp = p2 - p1;
    float r = sqrt(pow((p2(1, 1) - p2(1, 1)), 2) + pow((p2(2, 1) - p1(2, 1)), 2));
    Matrix f = dp*((p2.m*p1.m)/pow(r,2));

    return f;
}

void ParticleSystem::addParticle(Particle p){
    particels.push_back(p);
} 