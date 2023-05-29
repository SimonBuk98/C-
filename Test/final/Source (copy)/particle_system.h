#include "particle.h"
#include "matrix.h"


class ParticleSystem{
private:
    Matrix calcForce(Particle p1, Particle p2);
    cv::Mat canvas;
    float dt;
    std::vector<Particle> particles;

public:
    ParticleSystem(float dt, int h, int w);
    void addParticle(Particle p);
    void update();
    void draw();
    void simulate(int fps);
};
