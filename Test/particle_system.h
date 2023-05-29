#pragma once
#include "particle.h"
#include "matrix.h"


// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

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
