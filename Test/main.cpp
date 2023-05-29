#include "matrix.h"
#include "particle.h"
#include "particle_system.h"

int main(){
    int height = 600;
    int width = 800;
    float dt = .001;

    ParticleSystem sys(dt, height, width);

    float m1=7, m2=3, m3=5;
    Matrix p1(2,1), p2(2,1), p3(2,1);
    Matrix v1(2,1), v2(2,1), v3(2,1);
    p1(0,0) = 430;
    p1(1,0) = 460;
    p2(0,0) = 330;
    p2(1,0) = 400;
    p3(0,0) = 490;
    p3(1,0) = 380;

    v1(0,0) = -5;
    v1(1,0) = 0;
    v2(0,0) = 20;
    v2(1,0) = 10;
    v3(0,0) = -10;
    v3(1,0) = -10;


    sys.addParticle(Particle(m1,p1,v1));
    sys.addParticle(Particle(m2,p2,v2));
    sys.addParticle(Particle(m3,p3,v3));

    sys.simulate(25);


    return 0;
}